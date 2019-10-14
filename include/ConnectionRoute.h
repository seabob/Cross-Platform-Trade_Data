#ifndef __CONNECTION_ROUTE_H__
#define __CONNECTION_ROUTE_H__

#include "impl/ConnectionEvent.h"

namespace TradeApi{
//解析和转发
class ConnectionRouteAbstract{
    //private:
    //map<int,ConnectionAbstract*> connections;
    //queue<>
    public:
        virtual bool createServer() = 0;
        virtual bool serverRecv() = 0;
        virtual bool serverSend(TradeApi::ResponseEvent *pResponseEvent) = 0;
        virtual bool distroyServer() = 0;
};

}
#endif