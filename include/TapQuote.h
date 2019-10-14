#ifndef __TAP_QUOTE_H__
#define __TAP_QUOTE_H__

#include "../include/json/json.h"
#include "../include/json/writer.h"
#include "TapQuote/TapQuoteAPI.h"
#include "Connection.h"

class TapQuote:public ITapQuoteAPINotify{
    public:
        TapQuote();
        ~TapQuote();

    public:
        virtual void TAP_CDECL OnRspLogin(TAPIINT32 errorCode, const TapAPIQuotLoginRspInfo *info);
        virtual void TAP_CDECL OnAPIReady();
        virtual void TAP_CDECL OnDisconnect(TAPIINT32 reasonCode);
        virtual void TAP_CDECL OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteCommodityInfo *info);
        virtual void TAP_CDECL OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteContractInfo *info);
        virtual void TAP_CDECL OnRspSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteWhole *info);
        virtual void TAP_CDECL OnRspUnSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIContract *info);
        virtual void TAP_CDECL OnRtnQuote(const TapAPIQuoteWhole *info);

    private:
        ITapQuoteAPI* m_pAPI;
	    TAPIUINT32	m_uiSessionID;
	    SimpleEvent m_Event;
	    bool		m_bIsAPIReady;
        TradeApi::ConnectionAbstract *m_pConnect;
        Json::StreamWriterBuilder m_jsonBuilder;

        void ProcessTapQuoteWhole(Json::Value &data, TapAPIQuoteWhole *info);
        void ProcessTapQuoteCommodity(Json::Value &data, TapAPIQuoteCommodityInfo *info);
        void ProcessTapQuoteContract(Json::Value &data, TapAPIQuoteContractInfo *info);
    
    public:
        void setApi(ITapQuoteAPI *pApi);
        void setConnection(TradeApi::ConnectionAbstract *pConnect);
};

#endif