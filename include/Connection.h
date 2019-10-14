#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "ConnectionEvent.h"
#include "ConnectionRoute.h"
#include "../include/common/SimpleEvent.h"

namespace TradeApi{
class ConnectionAbstract{
    //private:
    //    queue<TradeApi::ResponseEvent *> m_qResponseQueue; 
    //    SimpleEvent * m_sEvent;
    //    int handler;
    public:
        virtual SimpleEvent * getCommandSignal() = 0;
        virtual SimpleEvent * getResponseSignal() = 0;
        virtual bool connectMarket() = 0;
        virtual void pushCommandEvent(TradeApi::CommandEvent *pCmdEvent) = 0;
        virtual TradeApi::CommandEvent *frontCommandEvent() = 0;
        virtual void popCommandEvent() = 0;

        virtual void pushResponseEvent(TradeApi::ResponseEvent *pResponseEvent) = 0;
        virtual TradeApi::ResponseEvent * frontResponseEvent() = 0;
        virtual void popResponseEvent() = 0;

        virtual bool doCommand(int code) = 0;
        virtual bool doResponse(int code) = 0;

};

}
#endif