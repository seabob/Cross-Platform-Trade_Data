#ifndef __WS_CONNECTION_ROUTE_H__
#define __WS_CONNECTION_ROUTE_H__

#include "../ConnectionRoute.h"
#include "../common/SimpleEvent.h"
#include "../impl/ConnectionEvent.h"

#include <queue>
#include <hash_map>

using namespace std;

namespace TradeApi{

class WsConnectionRoute{
    private:
        //SimpleEvent     *m_pCmdSignal;
        //SimpleEvent     *m_pResponseSignal;
        //queue<TradeApi::CommandEvent *> m_qCmdQueue;
        hash_map<int, TradeApi::ConnectionAbstract *> m_mConnectMap;

    public:
        WsConnectionRoute();
        ~WsConnectionRoute();

        virtual bool createServer();
        virtual bool serverRecv();
        virtual bool serverSend();
        virtual bool distroyServer();




};
}

#endif