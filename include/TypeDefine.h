#ifndef __TYPE_DEFINE_H__
#define __TYPE_DEFINE_H__

namespace TradeApi{

enum QuoteCommand{
    QUOTE_LOGIN = 1,
    QUOTE_READY,
    QUOTE_COMMODITY,
    QUOTE_CONSTRACT,
    QUOTE_QUOTEWHOLE,
    QUOTE_SUBSCRIBE,
    QUOTE_UNSUBSCRIBE,
    QUOTE_DISCONNECTION,
    QUOTE_END,
}

enum TradeCommand{
    TRADE_CONNECT = 0,
    TRADE_LOGIN,
    TRADE_READY,
    TRADE_CHANGE_PSWD,
    TRADE_SET_RESERVED,
    TRADE_QRY_ACCOUNT,
    TRADE_QRY_FUND,
    TRADE_FUND,
    TRADE_QRY_EXCHANGE,
    TRADE_QRY_COMMODITY,
    TRADE_QRY_CONSTRACT,
    TRADR_ORDER,
    TRADE_ORDER_ACTION,
    TRADE_QRY_ORDER,
    TRADR_ORDER_PROCESS,
    TRADE_QRY_FILL,
    TRADE_FILL,
    TRADE_QRY_POSITION,
    TRADE_POSITION,
    TRADE_QRY_CLOSE,
    TRADE_CLOSE,
    TRADE_POSITION_PROFIT,
    TRADE_QRY_CURRENCY,
    TRADE_QRY_TRADE_MESSAGE,
    TRADE_TRADE_MESSAGE,
    TRADE_QRY_HISTORY_ORDER,
    TRADE_QRY_HISTORY_ORDER_PROCESS,
    TRADE_QRY_HISTORY_MATCH,
    TRADE_QRY_HISTORY_POSITION,
    TRADE_QRY_HISTORY_DELIVERY,
    TRADE_QRY_ACCOUNT_CASH_ADJUST,
    TRADE_QRY_BILL,
    TRADE_EXPRIATION_DATE,
    TRADE_QRY_ACCOUNT_FEE_RENT,
    TRADE_QRY_ACCOUNT_MARGIN_RENT,

    TRADE_DISCONNECTION,
    TRADE_END,
};

enum TapCommandType{
    TYPE_QUOTE = 0,
    TYPE_TRADE,
};

};

#endif