#ifndef __CONNECTION_EVENT_H__
#define __CONNECTION_EVENT_H__

#include "TypeDefine.h"
#include "Connection.h"
#include <string>

using namespace std;

namespace TradeApi{

    class CommandEvent{
        private:
            TradeApi::RequestCommand m_Cmd;
            TradeApi::ConnectionAbstract *m_pConnect;

        public:
            CommandEvent(TradeApi::ConnectionAbstract *pConnect, TradeApi::RequestCommand cmd);
            ~CommandEvent();

            virtual void setRequestCommand(TradeApi::RequestCommand cmd);
            virtual TradeApi::RequestCommand getRequestCommand();
            virtual TradeApi::ConnectionAbstract * getConnection();
            virtual void setConnection(TradeApi::ConnectionAbstract *pConnect);
    };

    class ResponseEvent{
        private:
            std::string m_JonStr;
            TradeApi::ConnectionAbstract *m_pConnect;

        public:
            ResponseEvent(TradeApi::ConnectionAbstract *pConnect);
            ResponseEvent(TradeApi::ConnectionAbstract *pConnect, std::string jsonStr);
            ~ResponseEvent();

            virtual void setResponseJsonStr(std::string jsonStr);
            virtual std::string getResponseJsonStr();
            virtual TradeApi::ConnectionAbstract * getConnection();
            virtual void setConnection(TradeApi::ConnectionAbstract* pConnect);
    };
    
}

#endif