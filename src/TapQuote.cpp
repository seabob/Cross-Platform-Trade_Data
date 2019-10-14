#include "../include/TapQuote.h"
#include "../include/TapQuote/TapQuoteAPI.h"
#include "../include/TapQuote/TapAPIError.h"
#include "../include/Connection.h"
#include "../include/impl/ConnectionEvent.h"
#include "../include/json/json.h"
#include "../include/json/writer.h"
#include "../include/TypeDefine.h"

#include <iostream>

using namespace std;

TapQuote::TapQuote():m_pApi(NULL),m_bIsAPIReady(false),m_pConnect(NULL){}
TapQuote::TapQuote(TradeApi::ConnectionAbstract *pConnect):m_pApi(NULL),m_bIsAPIReady(false),m_pConnect(pConnect){}
TapQuote::~TapQuote(){}

TapQuote::setApi(ITapQuoteAPI *pApi){
    this->m_pAPI = pApi;
}

TapQuote::setConnection(TradeApi::ConnectionAbstract *pConnect){
    this->m_pConnect = pConnect;
}

void TAP_CDECL TapQuote::OnRspLogin(TAPIINT32 errorCode, const TapAPIQuotLoginRspInfo *info){
    Json::Value root;
    Json::Value data;
    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_LOGIN;

    if(TAPIERROR_SUCCEED == errorCode){
        cout << __FUNCTION__ << ": Login success" <<endl;
        this->m_bIsAPIReady = true;
    }else{
        cout <<__FUNCTION__ << ": Login failed :" << errorCode <<endl;
    }

    root["state"] = this->m_bIsAPIReady;
    
    if(this->m_bIsAPIReady){
        data["UserNo"] = info->UserNo;
        data["UserType"] = info->UserType;
        data["UserName"] = info->UserName;
        data["ReservedInfo"] = info->ReservedInfo;
        data["LastLoginIP"] = info->LastLoginIP;
        data["LastLoginProt"] = info->LastLoginProt;
        data["LastLoginTime"] = info->LastLoginTime;
        data["TradeDate"] = info->TradeDate;
        data["LastSettleTime"] = info->LastSettleTime;
        data["StartTime"] = info->StartTime;
        data["InitTime"] = info->InitTime;
    }

    root["data"] = data;

    TradeApi::ResponseEvent * rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder,root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL TapQuote::OnAPIReady(){
    cout << __FUNCTION__ <<endl;
//    this->m_Event.SignalEvent();
    Json::Value root;
    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_READY;
    root["state"] = true;
    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL TapQuote::OnDisconnect(TAPIINT32 reasonCode){
    cout << __FUNCTION__ << ": reasonCode" <<endl;
    Json::Value root;
    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_DISCONNECTION;
    root["code"] = reasonCode;
    root["state"] = true;
    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapQuote::ProcessQuoteCommodity(Json::Value &commodity, TapAPICommodity *info){
        Commodity["ExchangeNo"] = info->ExchangeNo;
        Commodity["CommodityType"] = info->CommodityType;
        Commodity["CommodityNo"] = info->CommodityNo;
}

void TAP_CDECL TapQuote::OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteCommodityInfo *info){
    cout <<__FUNCTION__<<endl;
    Json::Value root;
    Json::Value data;
    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_COMMODITY;
    root["isLast"] = isLast;
    //do something
    if(errorCode == 0) root["state"] = true;
    else root["state"] = false;

    if(errorCode == 0){
        Json::Value Commodity;
        Json::Value RelateCommodity1;
        Json::Value RepateCommodity2;

        ProcessQuoteCommodity(Commodity, &info->Commodity);
        data["Commodity"] = Commodity;

        data["CommodityName"] = info->CommodityName;
        data["CommodityEngName"] = info->CommodityEngName;
        data["ContractSize"] = info->ContractSize;
        data["CommodityTickSize"] = info->CommodityTickSize;
        data["CommodityDenominator"] = info->CommodityDenominator;
        data["CmbDirect"] = info->CmbDirect;
        data["CommodityContractLen"] = info->CommodityContractLen;
        data["IsDST"] = info->IsDST;

        ProcessQuoteCommodity(RelateCommodity1, &info->RelateCommodity1);
        data["RelateCommodity1"] = RelateCommodity1;

        ProcessQuoteCommodity(RelateCommodity2, &info->RelateCommodity2);
        data["RelateCommodity2"] = RelateCommodity2;
    }

    root["data"] = data;

    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapQuote::ProcessTapQuoteContract(Json::Value &Contract, TapAPIContract *info){
        Contract["ContractNo1"] = info->ContractNo1;
        Contract["StrikePrice1"] = info->StrikePrice1;
        Contract["CallOrPutFlag1"] = info->CallOrPutFlag1;
        Contract["ContractNo2"] = info->ContractNo2;
        Contract["StrikePrice2"] = info->StrikePrice2;
        Contract["CallOrPutFlag2"] = info->CallOrPutFlag2;
}

void TAP_CDECL TapQuote::OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteContractInfo *info){
    cout << __FUNCTION__ << endl;
    Json::Value root;
    Json::Value data;

    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_CONSTRACT;
    if(errorCode == 0) root["state"] = true;
    else root["state"] = false;

    root["errorCode"] = errorCode;
    root["isLast"] = isLast;
    if(errorCode == 0){
        Json::Value Commodity;
        Json::Value Contract;

        ProcessQuoteCommodity(Commodity,&info->Contract.Commodity);
        Contract["Commodity"] = Commodity;

        ProcessTapQuoteContract(Contract, &info->Contract);
        data["Contract"] = Contract;

        data["ContractType"] = info->ContractType;
        data["QuoteUnderlyingContract"] = info->QuoteUnderlyingContract;
        data["ContractName"] = info->ContractName;
        data["ContractExpDate"] = info->ContractExpDate;
        data["LastTradeDate"] = info->LastTradeDate;
        data["FirstNoticeDate"] = info->FirstNoticeDate;
    }
    root["data"] = data;

    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapQuote::ProcessTapQuoteWhole(Json::Value &data, const TapAPIQuoteWhole *info){
        int i = 0;
        Json::Value Contract;
        Json::Value Commodity;

        Json::Value QBidPrice;
        Json::Value QBidQty;
        Json::Value QAskPrice;
        Json::Value QAskQty;

        ProcessTapQuoteCommodity(Commodity,&info->Contract.Commodity);
        Contract["Commodity"] = Commodity;

        ProcessTapQuoteContract(Contract, &info->Contract);
        data["Contract"] = Contract;
        
        data["CurrencyNo"] = info->CurrencyNo;
        data["TradingState"] = info->TradingState;
        data["DataTimeStamp"] = info->DataTimeStamp;
        data["QPreClosingPrice"] = info->QPreClosingPrice;
        data["QPreSettlePrice"] = info->QPreSettlePrice;
        data["QPrePositionQty"] = info->QPrePositionQty;
        data["QOpeningPrice"] = info->QOpeningPrice;
        data["QLastPrice"] = info->QLastPrice;
        data["QHighPrice"] = info->QHighPrice;
        data["QLowPrice"] = info->QLowPrice;
        data["QHisHighPrice"] = info->QHisHighPrice;
        data["QHisLowPrice"] = info->QHisLowPrice;
        data["QLimitUpPrice"] = info->QLimitUpPrice;
        data["QLimitDownPrice"] = info->QLimitDownPrice;
        data["QTotalQty"] = info->QTotalQty;
        data["QTotalTurnover"] = info->QTotalTurnover;
        data["QPositionQty"] = info->QPositionQty;
        data["QAveragePrice"] = info->QAveragePrice;
        data["QClosingPrice"] = info->QClosingPrice;
        data["QSettlePrice"] = info->QSettlePrice;
        data["QLastQty"] = info->QLastQty;

        for(i = 0; i < 20; i++){
            QBidPrice.appen(info->QBidPrice[i]);
        }
        data["QBidPrice"] = QBidPrice;

        for(i = 0; i < 20; i++){
            QBidQty.append(info->QBidQty[i]);
        }
        data["QBidQty"] = QBidQty;

        for(i = 0; i < 20; i++){
            QAskPrice.append(info->QAskPrice[i]);
        }
        data["QAskPrice"] = QAskPrice;

        for(i = 0; i < 20; i++){
            QAskQty.append(info->QAskQty[i]);
        }
        data["QAskQty"] = QAskQty;

        data["QImpliedBidPrice"] = info->QImpliedBidPrice;
        data["QImpliedBidQty"] = info->QImpliedBidQty;
        data["QImpliedAskPrice"] = info->QImpliedAskPrice;
        data["QImpliedAskQty"] = info->QImpliedAskQty;
        data["QPreDelta"] = info->QPreDelta;
        data["QCurrDelta"] = info->QCurrDelta;
        data["QInsideQty"] = info->QInsideQty;
        data["QOutsideQty"] = info->QOutsideQty;
        data["QTurnoverRate"] = info->QTurnoverRate;
        data["Q5DAvgQty"] = info->Q5DAvgQty;
        data["QPERatio"] = info->QPERatio;
        data["QTotalValue"] = info->QTotalValue;
        data["QNegotiableValue"] = info->QNegotiableValue;
        data["QPositionTrend"] = info->QPositionTrend;
        data["QChangeSpeed"] = info->QChangeSpeed;
        data["QChangeRate"] = info->QChangeRate;
        data["QChangeValue"] = info->QChangeValue;
        data["QSwing"] = info->QSwing;
        data["QTotalBidQty"] = info->QTotalBidQty;
        data["QTotalAskQty"] = info->QTotalAskQty;
}

void TAP_CDECL TapQuote::OnRspSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteWhole *info){
    cout << __FUNCTION__ <<endl;
    Json::Value root;
    Json::Value data;
    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_SUBSCRIBE;
    if(errorCode == 0) root["state"] = true;
    else root[state] = false;

    root["errorCode"] = errorCode;

    if(errorCode == 0) ProcessTapQuoteWhole(data,info);
    root["data"] = data;

    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL TapQuote::OnRspUnSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIContract *info){
    cout << __FUNCTION__ << endl;
    Json::Value root;
    Json::Value data;
    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_UNSUBSCRIBE;
    if(errorCode == 0) root["state"] = true;
    else root["state"] = false;

    if(errorCode == 0){
        Json::Value Commodity;

        Commodity["ExchangeNo"] = info->Commodity.ExchangeNo;
        Commodity["CommodityType"] = info->Commodity.CommodityType;
        Commodity["CommodityNo"] = info->Commodity.CommodityNo;

        data["Commodity"] = Commodity;
        data["ContractNo1"] = info->ContractNo1;
        data["StrikePrice1"] = info->StrikePrice1;
        data["CallOrPutFlag1"] = info->CallOrPutFlag1;
        data["ContractNo2"] = info->ContractNo2;
        data["StrikePrice2"] = info->StrikePrice2;
        data["CallOrPutFlag2"] = info->CallOrPutFlag2;
    }
    root["data"] = data;

    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL TapQuote::OnRtnQuote(const TapAPIQuoteWhole *info){
    cout << __FUNCTION__ << endl;
    Json::Value root;
    Json::Value data;

    root["type"] = TradeApi::TYPE_QUOTE;
    root["event"] = TradeApi::QUOTE_QUOTEWHOLE;
    root["state"] = true;

    ProcessTapQuoteWhole(data, info);

    TradeApi::ResponseEvent *rspEvent = new ResponseEvent(this->m_pConnect, Json::writeString(this->m_jsonBuilder, root));
    this->m_pConnect->pushResponseEvent(rspEvent);
    this->m_pConnect->getResponseSignal()->SignalEvent();
}

