#include "../include/impl/TapConnection.h"
#include "../include/ConnectionRoute.h"
#include "../include/common/SimpleEvent.h"

#include <thread>
using namespace std;

TapConnection::TapConnection(TradeApi::ConnectionRouteAbstract *pRoute){
    this->m_pRoute = pRoute;
    this->m_pCommandSignal = new SimpleEvent();
    this->m_pResponseSignal = new SimpleEvent();
    this->m_tCommandThread = std::thread(&TapConnection::doCommand,this,0);
    this->m_tResponseThread = std::thread(&TapConnection::doResponse,this,0);
    

}

TapConnection::~TapConnection(){
    delete this->m_pCommandSignal;
    delete this->m_pResponseSignal;
    this->m_pRoute = NULL;
}

SimpleEvent * TapConnection::getCommandSignal(){
    return this->m_pCommandSignal;
}

SimpleEvent * TapConnection::getResponseSignal(){
    return this->m_pResponseSignal;
}

bool TapConnection::connectMarket(){
    return true;
}

void TapConnection::pushCommandEvent(TradeApi::CommandEvent *pCmdEvent){
    this->m_pCommandQueue.push_back(pCmdEvent);
}

TradeApi::CommandEvent * TapConnection::frontCommandEvent(){
    return this->m_pCommandQueue.front();
}

void TapConnection::popCommandEvent(){
    this->m_pCommandQueue.pop();
}


void TapConnection::pushResponseEvent(TradeApi::ResponseEvent *pResponseEvent){
    this->m_pResponseQueue.push_back(pResponseEvent);
}

TradeApi::ResponseEvent * TapConnection::frontResponseEvent(){
    return this->m_pResponseQueue.front();
}

void TapConnection::popResponseEvent(){
    this->m_pResponseQueue.pop();
}

void TapConnection::doResponse(int code){
    cout << __FUNCTION__ <<endl;

}

void TapConnection::doCommand(int code){
    cout << __FUNCTION__ <<endl;
    TradeApi::CommandEvent *pCmdEvent = NULL;

    while(true){
        this->getCommandSignal()->WaitSignal();
        pCmdEvent = this->frontCommandEvent();

        switch(pCmdEvent->getRequestCommand()){
            case: TradeApi::REQUEST_CONNECTION:
                cout << __FUNCTION__ << ": REQUEST_CONNECTION" <<endl;
                break;
            default:
                break;
        }
        this->popCommandEvent();
        delete(pCmdEvent);
    }
}