#include "../include/impl/WsConnectionRoute.h"
#include "../include/impl/ConnectionEvent.h"
#include "../include/common/SimpleEvent.h"

WsConnectionRoute::WsConnectionRoute(){
    this->m_pCmdSignal = new SimpleEvent();
    this->m_pResponseSignal = new SimpleEvent();
}

WsConnectionRoute::~WsConnectionRoute(){
    delete this->m_pCmdSignal;
    delete this->m_pResponseSignal;
}

bool WsConnectionRoute::createServer(TradeApi::ConnectionAbstract *pConnect){
    //创建web socket
    //监听到新连接创建 ConnectionAbstract 并加入hash_map
    //创建数据接受线程
    //创建数据发送线程
    this->m_mConnectMap[pConnect->getConnectionHandler()] = pConnect;
}

bool WsConnectionRoute::createServer(){
    //创建web socket
    //监听到新连接创建 ConnectionAbstract 并加入hash_map
    //创建数据接受线程
    //创建数据发送线程
}

//异步接收线程处理函数
bool WsConnectionRoute::serverRecv(){
    //接收web socket 数据
    //根据handler转发数据
    TradeApi::ConnectionAbstract *pConnect = new TapConnection(this);
    CommandEvent *pEvent = new CommandEvent(pConnect,TradeApi::REQUEST_CONNECTION);
    pConnect->pushCommandEvent(pEvent);
    pConnect->getCommandSignal()->SignalEvent();
}

bool WsConnectionRoute::serverSend(){
    //发送web socket 数据
}

bool WsConnectionRoute::distroyServer(){
    //销毁连接管理
}
