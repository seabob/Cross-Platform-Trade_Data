#ifndef __TAP_CONNECTION_H__
#define __TAP_CONNECTION_H__

#include "../Connection.h"
#include "ConnectionEvent.h"
#include "../common/SimpleEvent.h"
#include "../ConnectionRoute.h"

#include <queue>
#include <thread>

using namespace std;

namespace TradeApi{

    class TapConnection:public ConnectionAbstract{
        private:
            queue<CommandEvent*> m_qCommandQueue;
            queue<ResponseEvent*> m_qResponseQueue;
            SimpleEvent         *m_pCommandSignal;
            SimpleEvent         *m_pResponseSignal;
            ConnectionRouteAbstract *m_pRoute;
            std::thread         m_tCommandThread;
            std::thread         m_tResponseThread;

        public:
            TapConnection(TradeApi::ConnectionRouteAbstract *pRoute);
            ~TapConnection();

            virtual SimpleEvent * getCommandSignal();
            virtual SimpleEvent * getResponseSignal();

            virtual bool connectMarket();

            virtual void pushCommandEvent(TradeApi::CommandEvent *pCmdEvent);
            virtual TradeApi::CommandEvent *frontCommandEvent();
            virtual void popCommandEvent();

            virtual void pushResponseEvent(TradeApi::ResponseEvent *pResponseEvent);
            virtual TradeApi::ResponseEvent * frontResponseEvent();
            virtual void popResponseEvent();

            virtual bool doCommand(int code);
            virtual bool doResponse(int code);
    };
}

#endif