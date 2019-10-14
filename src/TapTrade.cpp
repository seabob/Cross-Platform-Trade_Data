#include "../include/TapTrade.h"
#include "../include/Connection.h"
#include "../include/TapTrade/iTapAPIError.h"
#include "../include/json/json.h"
#include "../include/json/writer.h"
#include "../include/impl/ConnectionEvent.h"
#include "../include/TypeDefine.h"

#include <iostream>
#include <string>

using namespace std;

TapTrade::TapTrade(TradeApi::ConnectionAbstract *pConnect):m_API(NULL),m_bIsAPIReady(false),m_pConnect(pConnect){}
TapTrade::TapTrade():m_API(NULL),m_bIsAPIReady(false),m_pConnect(NULL){}
TapTrade::~TapTrade(){}

TapTrade::setApi(ITapTrade::ITapTradeAPI *pApi){
    this->m_pAPI = pApi;
}

TapTrade::setConnect(TradeApi::ConnectionAbstract *pConnect){
    this->m_pConnect = pConnect;
}

void TAP_CDECL Trade::OnConnect()
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_CONNECT;
	root["state"] = true;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL Trade::OnRspLogin( TAPIINT32 errorCode, const TapAPITradeLoginRspInfo *info )
{
	if(TAPIERROR_SUCCEED == errorCode) {
		cout << "登录成功，等待API初始化..." << endl;

	} else {
		cout << "登录失败，错误码:" << errorCode << endl;
	//	m_Event.SignalEvent();	
	}
	Json::Value root;
	Json::Value data;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_LOGIN;
	if(errorCode == TAPIERROR_SUCCEED) root["state"] = true;
	else root["state"] = false;

    if(errorCode == TAPIERROR_SUCCEED){
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

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnAPIReady()
{
	cout << "API初始化完成" << endl;
	m_bIsAPIReady = true;
	Json::Value root;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_READY;
	root["state"] = true;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();

}

void TAP_CDECL Trade::OnDisconnect( TAPIINT32 reasonCode )
{
	cout << "API断开,断开原因:"<<reasonCode << endl;
	Json::Value root;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_DISCONNECTION;
	root["state"] = true;
	root["reasonCode"] = reasonCode;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspChangePassword( TAPIUINT32 sessionID, TAPIINT32 errorCode )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_CHANGE_PSWD;
	root["state"] = true;
	root["errorCode"] = errorCode;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspSetReservedInfo( TAPIUINT32 sessionID, TAPIINT32 errorCode, const TAPISTR_50 info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_SET_RESERVED;
	root["state"] = true;
	root["Reserved"] = info;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryAccount( TAPIUINT32 sessionID, TAPIUINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_ACCOUNT;
	if(errorCode  == 0) root["state"] = true;
	else rootp["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		data["AccountNo"] = info->AccountNo;
		data["AccountType"] = info->AccountType;
		data["AccountState"] = info->AccountState;
		data["AccountTradeRight"] = info->AccountTradeRight;
		data["CommodityGroupNo"] = info->CommodityGroupNo;
		data["AccountShortName"] = info->AccountShortName;
		data["AccountEnShortName"] = info->AccountEnShortName;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapTrade::ProcessTapAPIFundData(Json::Value &data, const TapAPIFundData *info){
		data["AccountNo"] = info->AccountNo;
		data["CurrencyGroupNo"] = info->CurrencyGroupNo;
		data["CurrencyNo"] = info->CurrencyNo;
		data["TradeRate"] = info->TradeRate;
		data["FutureAlg"] = info->FutureAlg;
		data["OptionAlg"] = info->OptionAlg;
		data["PreBalance"] = info->PreBalance;
		data["PreUnExpProfit"] = info->PreUnExpProfit;
		data["PreLMEPositionProfit"] = info->PreLMEPositionProfit;
		data["PreEquity"] = info->PreEquity;
		data["PreAvailable1"] = info->PreAvailable1;
		data["PreMarketEquity"] = info->PreMarketEquity;
		data["CashInValue"] = info->CaseInValue;
		data["CashOutValue"] = info->CashOutValue;
		data["CashAdjustValue"] = info->CashAdjustValue;
		data["CashPledged"] = info->CashPledged;
		data["FrozenFee"] = info->FrozenFee;
		data["FrozenDeposit"] = info->FrozenDeposit;
		data["AccountFee"] = info->AccountFee;
		data["ExchangeFee"] = info->ExchangeFee;
		data["AccountDeliveryFee"] = info->AccountDeliveryFee;
		data["PremiumIncome"] = info->PremiumIncome;
		data["PremiumPay"] = info->PremiumPay;
		data["CloseProfit"] = info->CloseProfit;
		data["DeliveryProfit"] = info->DeliveryProfit;
		data["UnExpProfit"] = info->UnExpProfit;
		data["ExpProfit"] = info->ExpProfit;
		data["PositionProfit"] = info->PositionProfit;
		data["LmePositionProfit"] = info->LmePositionProfit;
		data["OptionMarketValue"] = info->OptionMarketValue;
		data["AccountIntialMargin"] = info->AccountIntialMargin;
		data["AccountMaintenanceMargin"] = info->AccountMaintenanceMargin;
		data["UpperInitalMargin"] = info->UpperInitalMargin;
		data["UpperMaintenanceMargin"] = info->UpperMaintenanceMargin;
		data["Discount"] = info->Discount;
		data["Balance"] = info->Balance;
		data["Equity"] = info->Equity;
		data["Available"] = info->Available;
		data["CanDraw"] = info->CanDraw;
		data["MarketEquity"] = info->MarketEquity;
		data["AuthMoney"] = info->AuthMoney;
}

void TAP_CDECL Trade::OnRspQryFund( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFundData *info )
{
	cout << __FUNCTION__ << " is called." << endl;

	cout <<"errorcode ="<<errorCode<<endl;

	if(isLast=='Y') return;

	cout<<"币种:"<<info->CurrencyNo<<","
		<<"权益:"<<info->Balance<<","
		<<"可用:"<<info->Available<<","
		<<"非LME浮盈:"<<info->PositionProfit<<","
		<<"LME浮盈:"<<info->LmePositionProfit<<endl;
		Json::Value root;
		Json::Value data;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_FUND;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessTapAPIFundData(data,info);
	}
	root["data"] = data;
	
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL Trade::OnRtnFund( const TapAPIFundData *info )
{
	//cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_FUND;
	root["state"] = true;
	ProcessTapAPIFundData(data,info);
	root["data"] = data;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryExchange( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIExchangeInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_EXCHANGE;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;

	root["errorCode"] = errorCode;

	if(errorCode == 0){
		data["ExchangeNo"] = info->ExchangeNo;
		data["ExchangeName"] = info->ExchangeName;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}



void TAP_CDECL Trade::OnRspQryCommodity( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICommodityInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_COMMODITY;
	if(errorCode == 0)root["state"] = true;
	else root["root"] = false;

	root["errorCode"] = errorCode;

	if(errorCode == 0){
		data["ExchangeNo"] = info->ExchangeNo;
		data["CommodityType"] = info->CommodityType;
		data["CommodityNo"] = info->CommodityNo;
		data["CommodityName"] = info->CommodityName;
		data["CommodityEngName"] = info->CommodityEngName;
		data["RelateExchangeNo"] = info->RelateExchangeNo;
		data["RelateCommodityType"] = info->RelateCommodityType;
		data["RelateCommodityNo"] = info->RelateCommodityNo;
		data["RelateExchangeNo2"] = info->RelateExchangeNo2;
		data["RelateCommodityType2"] = info->RelateCommodityType2;
		data["RelateCommodityNo2"] = info->RelateCommodityNo2;
		data["CurrencyGroupNo"] = info->CurrencyGroupNo;
		data["TradeCurrency"] = info->TradeCurrency;
		data["ContractSize"] = info->ContractSize;
		data["OpenCloseMode"] = info->OpenCloseMode;
		data["StrikePriceTimes"] = info->StrikePriceTimes;
		data["CommodityTickSize"] = info->CommodityTickSize;
		data["CommodityDenominator"] = info->CommodityDenominator;
		data["CmbDirect"] = info->CmbDirect;
		data["DeliveryMode"] = info->DeliveryMode;
		data["DeliveryDays"] = info->DeliveryDays;
		data["AddOneTime"] = info->AddOneTime;
		data["CommodityTimeZone"] = info->CommodityTimeZone;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessTapAPIContractInfo(Json::Valuse &data, const TapAPITradeContractInfo *info){
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo1"] = info->ContractNo1;
	data["StrikePrice1"] = info->StrikePrice1;
	data["CallOrPutFlag1"] = info->CallOrPutFlag1;
	data["ContractNo2"] = info->ContractNo2;
	data["StrikePrice2"] = info->StrikePrice2;
	data["CallOrPutFlag2"] = info->CallOrPutFlag2;
	data["ContractType"] = info->ContractType;
	data["QuoteUnderlyingContract"] = info->QuoteUnderlyingContract;
	data["ContractName"] = info->ContractName;
	data["ContractExpDate"] = info->ContractExpDate;
	data["LastTradeDate"] = info->LastTradeDate;
	data["FirstNoticeDate"] = info->FirstNoticeDate;
}

void TAP_CDECL Trade::OnRspQryContract( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPITradeContractInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_CONSTRACT;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessTapAPIContractInfo(data,info);
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRtnContract( const TapAPITradeContractInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_CONSTRACT;
	root["state"] = true;
	ProcessTapAPIContractInfo(data,info);
	root["data"] = data;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessTapAPIOrderInfo(Json::Value &data, const TapApiOrderInfo *info){
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["ContractNo2"] = info->ContractNo2;
	data["StrikePrice2"] = info->StrikePrice2;
	data["CallOrPutFlag2"] = info->CallOrPutFlag2;
	data["OrderType"] = info->OrderType;
	data["OrderSource"] = info->OrderSource;
	data["TimeInForce"] = info->TimeInForce;
	data["ExpireTime"] = info->ExpireTime;
	data["IsRiskOrder"] = info->IsRiskOrder;
	data["OrderSide"] = info->OrderSide;
	data["PositionEffect"] = info->PositionEffect;
	data["PositionEffect2"] = info->PositionEffect2;
	data["InquiryNo"] = info->InquiryNo;
	data["HedgeFlag"] = info->HedgeFlag;
	data["OrderPrice"] = info->OrderPrice;
	data["OrderPrice2"] = info->OrderPrice2;
	data["StopPrice"] = info->StopPrice;
	data["OrderQty"] = info->OrderQty;
	data["OrderMinQty"] = info->OrderMinQty;
	data["RefInt"] = info->RefInt;
	data["RefDouble"] = info->RefDouble;
	data["RefString"] = info->RefString;
	data["MinClipSize"] = info->MinClipSize;
	data["MaxClipSize"] = info->MaxClipSize;
	data["LicenseNo"] = info->LicenseNo;
	data["ServerFlag"] = info->ServerFlag;
	data["OrderNo"] = info->OrderNo;
	data["ClientOrderNo"] = info->ClientOrderNo;
	data["ClientID"] = info->ClientID;
	data["TacticsType"] = info->TacticsType;
	data["TriggerCondition"] = info->TriggerCondition;
	data["TriggerPriceType"] = info->TriggerPriceType;
	data["AddOneIsValid"] = info->AddOneIsValid;
	data["ClientLocalIP"] = info->ClientLocalIP;
	data["ClientMac"] = info->ClientMac;
	data["ClientIP"] = info->ClientIP;
	data["OrderStreamID"] = info->OrderStreamID;
	data["UpperNo"] = info->UpperNo;
	data["UpperChannelNo"] = info->UpperChannelNo;
	data["OrderLocalNo"] = info->OrderLocalNo;
	data["UpperStreamID"] = info->UpperStreamID;
	data["OrderSystemNo"] = info->OrderSystemNo;
	data["OrderExchangeSystemNo"] = info->OrderExchangeSystemNo;
	data["OrderParentSystemNo"] = info->OrderParentSystemNo;
	data["OrderInsertUserNo"] = info->OrderInsertUserNo;
	data["OrderInsertTime"] = info->OrderInsertTime;
	data["OrderCommandUserNo"] = info->OrderCommandUserNo;
	data["OrderUpdateUserNo"] = info->OrderUpdateUserNo;
	data["OrderUpdateTime"] = info->OrderUpdateTime;
	data["OrderState"] = info->OrderState;
	data["OrderMatchPrice"] = info->OrderMatchPrice;
	data["OrderMatchPrice2"] = info->OrderMatchPrice2;
	data["OrderMatchQty"] = info->OrderMatchQty;
	data["OrderMatchQty2"] = info->OrderMatchQty2;
	data["ErrorCode"] = info->ErrorCode;
	data["ErrorText"] = info->ErrorText;
	data["IsBackInput"] = info->IsBackInput;
	data["IsDeleted"] = info->IsDeleted;
	data["IsAddOne"] = info->IsAddOne;
}

void TAP_CDECL Trade::OnRtnOrder( const TapAPIOrderInfoNotice *info )

{
	cout << __FUNCTION__ << " is called." << endl;

	if(NULL == info){
		return;
	}

	if (info->ErrorCode != 0) {
		cout << "服务器返回了一个关于委托信息的错误：" << info->ErrorCode << endl;
	} else {
		if (info->OrderInfo) {
			if (0!= info->OrderInfo->ErrorCode){
				cout << "报单失败，"
					<< "错误码:"<<info->OrderInfo->ErrorCode << ","
					<< "委托编号:"<<info->OrderInfo->OrderNo
					<<endl;
			} else{
				cout << "报单成功，"
					<< "品种:"<<info->OrderInfo->CommodityNo<< ","
					<<"合约:"<<info->OrderInfo->ContractNo<<","
					<< "状态:"<<info->OrderInfo->OrderState << ","
					<< "委托编号:"<<info->OrderInfo->OrderNo<< ","
					<<endl;
			}
		}
	}
	Json::Value root;
	Json::Value data;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_ORDER;
	if(errorCode == 0)root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;
	
	ProcessTapAPIOrderInfo(data,info->OrderInfo);
	root["OrderInfo"] = data;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL Trade::OnRspOrderAction( TAPIUINT32 sessionID, TAPIUINT32 errorCode, const TapAPIOrderActionRsp *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_ORDER_ACTION;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		Json::Value OrderInfo;
		data["ActionType"] = info->ActionType;
		ProcessTapAPIOrderInfo(OrderInfo, info->OrderInfo);
		data["OrderInfo"] = OrderInfo;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryOrder( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	Json::Value OrderInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_ORDER;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0) ProcessTapAPIOrderInfo(OrderInfo,info);
	data["OrderInfo"] = OrderInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryOrderProcess( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	Json::Value OrderInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_ORDER_PROCESS;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0) ProcessTapAPIOrderInfo(OrderInfo,info);
	data["OrderInfo"] = OrderInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessTapAPIFillInfo(Json::Value data, const TapAPIFillInfo *info){
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["MatchSource"] = info->MatchSource;
	data["MatchSide"] = info->MatchSide;
	data["PositionEffect"] = info->PositionEffect;
	data["ServerFlag"] =info->ServerFlag;
	data["OrderNo"] = info->OrderNo;
	data["OrderSystemNo"] = info->OrderSystemNo;
	data["MatchNo"] = info->MatchNo;
	data["UpperMatchNo"] = info->UpperMatchNo;
	data["ExchangeMatchNo"] = info->ExchangeMatchNo;
	data["MatchDateTime"] = info->MatchDateTime;
	data["UpperMatchDateTime"] = info->UpperMatchDateTime;
	data["UpperNo"] = info->UpperNo;
	data["MatchPrice"] = info->MatchPrice;
	data["MatchQty"] = info->MatchQty;
	data["IsDeleted"] = info->IsDeleted;
	data["IsAddOne"] = info->IsAddOne;
	data["FeeCurrencyGroup"] = info->FeeCurrencyGroup;
	data["FeeCurrency"] = info->FeeCurrency;
	data["FeeValue"] = info->FeeValue;
	data["IsManualFee"] = info->IsManualFee;
	data["ClosePrositionPrice"] = info->ClosePrositionPrice;
}

void TAP_CDECL Trade::OnRspQryFill( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFillInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	Json::Value FillInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_FILL;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false
	root["errorCode"] = errorCode;

	if(errorCode == 0) ProcessTapAPIFillInfo(FillInfo, info);
	data["FillInfo"] = FillInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL Trade::OnRtnFill( const TapAPIFillInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	cout<< "品种" <<info->CommodityNo << ","
		<< "合约" <<info->ContractNo << ","
		<< "成交价"<<info->MatchPrice << ","
		<< "成交量"<<info->MatchQty <<endl;
	Json::Value root;
	Json::Value data;
	Json::Value FillInfo;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_FILL;
	root["state"] = true;
	ProcessTapAPIFillInfo(FillInfo,info);
	data["FillInfo"] = FillInfo;
	root[data] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessTapAPIPositionInfo(Json::Value data, const TapAPIPositionInfo *info){
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["MatchSide"] = info->MatchSide;
	data["HedgeFlag"] = info->HedgeFlag;
	data["PositionNo"] = info->PositionNo;
	data["ServerFlag"] = info->ServerFlag;
	data["OrderNo"] = info->OrderNo;
	data["MatchNo"] = info->MatchNo;
	data["UpperNo"] = info->UpperNo;
	data["PositionPrice"] = info->PositionPrice;
	data["PositionQty"] = info->PositionQty;
	data["PositionStreamId"] = info->PositionStreamId;
	data["CommodityCurrencyGroup"] = info->CommodityCurrencyGroup;
	data["CommodityCurrency"] = info->CommodityCurrency;
	data["CalculatePrice"] = info->CalculatePrice;
	data["AccountInitialMargin"] = info->AccountInitialMargin;
	data["AccountMaintenanceMargin"] = info->AccountMaintenanceMargin;
	data["UpperInitialMargin"] = info->UpperInitialMargin;
	data["UpperMaintenanceMargin"] = info->UpperMaintenanceMargin;
	data["PositionProfit"] = info->PositionProfit;
	data["LMEPositionProfit"] = info->LMEPositionProfit;
	data["OptionMarketValue"] = info->OptionMarketValue;
}

void TAP_CDECL Trade::OnRspQryPosition( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIPositionInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;

	cout <<"errorcode ="<<errorCode<<endl;

	if(isLast=='Y') return;

	cout<< "品种" << info->CommodityNo <<","
	<< "合约" << info->ContractNo << ","
	<< "持仓量"<< info->PositionQty <<","
	<< "持仓价"<< info->PositionPrice<<endl;
	Json::Value root;
	Json::Value data;
	Json::Value PositionInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_POSITION;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0) ProcessTapAPIPositionInfo(PositionInfo,info);
	data["PositionInfo"] = PositionInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRtnPosition( const TapAPIPositionInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	cout<< "品种" << info->CommodityNo <<","
		<< "合约" << info->ContractNo << ","
		<< "持仓量"<< info->PositionQty <<","
		<< "持仓价"<< info->PositionPrice<<endl;
	Json::Value root;
	Json::Value data;
	Json::Value PositionInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_POSITION;
	root["state"] = true;

	ProcessTapAPIPositionInfo(PositionInfo,Info);
	data["PositionInfo"] = PositionInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessTapAPICloseInfo(Json::Value &data, const TapAPICloseInfo *info){
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["CloseSide"] = info->CloseSide;
	data["CloseQty"] = info->CloseQty;
	data["OpenPrice"] = info->OpenPrice;
	data["ClosePrice"] = info->ClosePrice;
	data["OpenMatchNo"] = info->OpenMatchNo;
	data["OpenMatchDateTime"] = info->OpenMatchDateTime;
	data["CloseMatchNo"] = info->CloseMatchNo;
	data["CloseMatchDateTime"] = info->CloseMatchDateTime;
	data["CloseStreamId"] = info->CloseStreamId;
	data["CommodityCurrencyGroup"] = info->CommodityCurrencyGroup;
	data["CommodityCurrency"] = info->CommodityCurrency;
	data["CloseProfit"] =info->CloseProfit;
}

void TAP_CDECL Trade::OnRspQryClose( TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICloseInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	Json::Value CloseInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_CLOSE;
	if(errorCode == 0) root["state"] = true;
	else root["state"] =  false;
	root["errorCode"] = errorCode;

	if(errorCode == 0) ProcessTapAPICloseInfo(CloseInfo, info);
	data["CloseInfo"] = CloseInfo;
	root["data"] = data;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRtnClose( const TapAPICloseInfo *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	Json::Value CloseInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_CLOSE;
	root["state"] = true;
	ProcessTapAPICloseInfo(CloseInfo, info);
	data["CloseInfo"] = CloseInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRtnPositionProfit( const TapAPIPositionProfitNotice *info )
{
	cout << __FUNCTION__ << " is called." << endl;
	Json::Value root;
	Json::Value data;
	Json::Value PositionProfit;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_POSITION_PROFIT;
	root["state"] = true;
	root["isLast"] = info->IsLast;

	PositionProfit["PositionNo"] = info->Data->CloseProfit;
	PositionProfit["PositionStreamId"] = info->Data->PositionStreamId;
	PositionProfit["PositionProfit"] = info->Data->PositionProfit;
	PositionProfit["LMEPositionProfit"] = info->Data->LMEPositionProfit;
	PositionProfit["OptionMarketValue"] = info->Data->OptionMarketValue;
	PositionProfit["CalculatePrice"] = info->Data->CalculatePrice;
	data["PositionProfit"] = PositionProfit;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}
void TAP_CDECL Trade::OnRspQryCurrency(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICurrencyInfo *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value CurrencyInfo;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_CURRENCY;
	if(errorCode == 0) root["state"] = true;
	else root["state"]  = false;
	root["isLast"] = isLast;

	CurrencyInfo["CurrencyNo"] = info->CurrencyNo;
	CurrencyInfo["CurrencyGroupNo"] = info->CurrencyGroupNo;
	CurrencyInfo["TradeRate"] = info->TradeRate;
	CurrencyInfo["TradeRate2"] = info->TradeRate2;
	CurrencyInfo["FutureAlg"] = info->FutureAlg;
	CurrencyInfo["OptionAlg"] = info->OptionAlg;
	data["CurrencyInfo"] = CurrencyInfo;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessTapAPITradeMessage(Json::Value &data,  constv TapAPITradeMessage *info){
	data["SerialID"] = info->SerialID;
	data["TMsgReceiverType"] = info->TMsgReceiverType;
	data["TMsgValidDateTime"] = info->TMsgValidDateTime;
	data["OperatorNo"] = info->OperatorNo;
	data["TMsgTitle"] = info->TMsgTitle;
	data["TMsgContent"] = info->TMsgContent;
	data["TMsgType"] = info->TMsgType;
	data["TMsgLevel"] = info->TMsgLevel;
	data["IsSendBySMS"] = info->IsSendBySMS;
	data["IsSendByEMail"] = info->IsSendByEMail;
	data["Sender"] = info->Sender;
	data["SendDateTime"] = info->SendDateTime;
}

void TAP_CDECL Trade::OnRspQryTradeMessage(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPITradeMessage *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value TradeMsg;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_TRADE_MESSAGE;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["isLast"] = isLast;

	if(errorCode == 0){
		ProcessTapAPITradeMessage(TradeMsg, info);
		data["TradeMessage"] = TradeMessage;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRtnTradeMessage(const TapAPITradeMessage *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value TradeMsg;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_TRADE_MESSAGE;
	root["state"] = true;
	ProcessTapAPITradeMessage(TradeMsg, info);
	data["TradeMessage"] = TradeMessage;
	root["data"] = data;
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapTrade::ProcessTapAPIHisOrderQryRsp(Json::Value &data, const TapApiHisOrderQryRsp *info){
	data["info"] = info->Date;
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["ContractNo2"] = info->ContractNo2;
	data["StrikePrice2"] = info->StrikePrice2;
	data["CallOrPutFlag2"] = info->CallOrPutFlag2;
	data["OrderType"] = info->OrderType;
	data["OrderSource"] = info->OrderSource;
	data["TimeInForce"] = info->TimeInForce;
	data["ExpireTime"] = info->ExpireTime;
	data["IsRiskOrder"] = info->IsRiskOrder;
	data["OrderSide"] = info->OrderSide;
	data["PositionEffect"] = info->PositionEffect;
	data["PositionEffect2"] = info->PositionEffect2;
	data["InquiryNo"] = info->InquiryNo;
	data["HedgeFlag"] = info->HedgeFlag;
	data["OrderPrice"] = info->OrderPrice;
	data["OrderPrice2"] = info->OrderPrice2;
	data["StopPrice"] = info->StopPrice;
	data["OrderQty"] = info->OrderQty;
	data["OrderMinQty"] = info->OrderMinQty;
	data["OrderCanceledQty"] = info->OrderCanceledQty;
	data["RefInt"] = info->RefInt;
	data["RefDouble"] = info->RefDouble;
	data["RefString"] = info->RefString;
	data["ServerFlag"] = info->ServerFlag;
	data["OrderNo"] = info->OrderNo;
	data["OrderStreamID"] = info->OrderStreamID;
	data["UpperNo"] = info->UpperNo;
	data["UpperChannelNo"] = info->UpperChannelNo;
	data["OrderLocalNo"] = info->OrderLocalNo;
	data["UpperStreamID"] = info->UpperStreamID;
	data["OrderSystemNo"] = info->OrderSystemNo;
	data["OrderExchangeSystemNo"] = info->OrderExchangeSystemNo;
	data["OrderParentSystemNo"] = info->OrderParentSystemNo;
	data["OrderInsertUserNo"] = info->OrderInsertUserNo;
	data["OrderInsertTime"] = info->OrderInsertTime;
	data["OrderCommandUserNo"] = info->OrderCommandUserNo;
	data["OrderUpdateUserNo"] = info->OrderUpdateUserNo;
	data["OrderUpdateTime"] = info->OrderUpdateTime;
	data["OrderState"] = info->OrderState;
	data["OrderMatchPrice"] = info->OrderMatchPrice;
	data["OrderMatchPrice2"] = info->OrderMatchPrice2;
	data["OrderMatchQty"] = info->OrderMatchQty;
	data["OrderMatchQty2"] = info->OrderMatchQty2;
	data["ErrorCode"] = info->ErrorCode;
	data["ErrorText"] = info->ErrorText;
	data["IsBackInput"] = info->IsBackInput;
	data["IsDeleted"] = info->IsDeleted;
	data["IsAddOne"] = info->IsAddOne;
	data["AddOneIsValid"] = info->AddOneIsValid;
	data["MinClipSize"] = info->MinClipSize;
	data["MaxClipSize"] = info->MaxClipSize;
	data["LicenseNo"] = info->LicenseNo;
	data["TacticsType"] = info->TacticsType;
	data["TriggerCondition"] = info->TriggerCondition;
	data["TriggerPriceType"] = info->TriggerPriceType;
}

void TAP_CDECL Trade::OnRspQryHisOrder(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIHisOrderQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value HisOrderQryRsp;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_HISTORY_ORDER;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessTapAPIHisOrderQryRsp(HisOrderQryRsp, info);
		data["HisOrderQryRsp"] = HisOrderQryRsp;
	}
	root["data"] = data;
	
	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryHisOrderProcess(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIHisOrderProcessQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value HisOrderQryRsp;
	TapAPIHisOrderProcessQryRsp *_info = info;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_HISTORY_ORDER_PROCESS;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		 ProcessTapAPIHisOrderQryRsp(HisOrderQryRsp,(TapAPIHisOrderQryRsp*)_info);
		data["HisOrderQryRsp"] = HisOrderQryRsp;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapTrade::ProcessHisMatch(Json::Value &data, const TapAPIHisMatchQryRsp *info){
	data["SettleDate"] = info->SettleDate;
	data["TraadeDate"] = info->TraadeDate;
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["MatchSource"] = info->MatchSource;
	data["MatchSide"] = info->MatchSide;
	data["PositionEffect"] = info->PositionEffect;
	data["HedgeFlag"] = info->HedgeFlag;
	data["MatchPrice"] = info->MatchPrice;
	data["MatchQty"] = info->MatchQty;
	data["OrderNo"] = info->OrderNo;
	data["MatchNo"] = info->MatchNo;
	data["MatchStreamID"] = info->MatchStreamID;
	data["UpperNo"] = info->UpperNo;
	data["MatchCmbNo"] = info->MatchCmbNo;
	data["ExchangeMatchNo"] = info->ExchangeMatchNo;
	data["MatchUpperStreamID"] = info->MatchUpperStreamID;
	data["CommodityCurrencyGroup"] =info->CommodityCurrencyGroup;
	data["CommodityCurrency"] = info->CommodityCurrency;
	data["Turnover"] = info->Turnover;
	data["PremiumIncome"] = info->PremiumIncome;
	data["PremiumPay"] = info->PremiumPay;
	data["AccountFee"] = info->AccountFee;
	data["AccountFeeCurrencyGroup"] = info->AccountFeeCurrencyGroup;
	data["AccountFeeCurrency"] = info->AccountFeeCurrency;
	data["IsManualFee"] = info->IsManualFee;
	data["AccountOtherFee"] = info->AccountOtherFee;
	data["UpperFee"] = info->UpperFee;
	data["UpperFeeCurrencyGroup"] =info->UpperFeeCurrencyGroup;
	data["UpperFeeCurrency"] = info->UpperFeeCurrency;
	data["IsUpperManualFee"] = info->IsUpperManualFee;
	data["UpperOtherFee"] = info->UpperOtherFee;
	data["MatchDateTime"] = info->MatchDateTime;
	data["UpperMatchDateTime"] = info->UpperMatchDateTime;
	data["CloseProfit"] = info->CloseProfit;
	data["ClosePrice"] = info->ClosePrice;
	data["CloseQty"] = info->CloseQty;
	data["SettleGroupNo"] = info->SettleGroupNo;
	data["OperatorNo"] = info->OperatorNo;
	data["OperateTime"] = info->OperateTime;
}

void TAP_CDECL Trade::OnRspQryHisMatch(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIHisMatchQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value HisMatch;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_HISTORY_MATCH;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessHisMatch(HisMatch, info);
		data["HisMatch"] = HisMatch;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TapTrade::ProcessHisPosition(Json::Value &data, const TapAPIHisPositionQryRsp *info){
	data["SettleDate"] = info->SettleDate;
	data["OpenDate"] = info->OpenDate;
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["MatchSide"] = info->MatchSide;
	data["HedgeFlag"] = info->HedgeFlag;
	data["PositionPrice"] = info->PositionPrice;
	data["PositionQty"] = info->PositionQty;
	data["OrderNo"] = info->OrderNo;
	data["PositionNo"] = info->PositionNo;
	data["UpperNo"] = info->UpperNo;
	data["CurrencyGroup"] = info->CurrencyGroup;
	data["Currency"] = info->Currency;
	data["PreSettlePrice"] = info->PreSettlePrice;
	data["SettlePrice"] = info->SettlePrice;
	data["PositionDProfit"] = info->PositionDProfit;
	data["LMEPositionProfit"] = info->LMEPositionProfit;
	data["OptionMarketValue"] = info->OptionMarketValue;
	data["AccountInitialMargin"] = info->AccountInitialMargin;
	data["AccountMaintenanceMargin"] = info->AccountMaintenanceMargin;
	data["UpperInitialMargin"] = info->UpperInitialMargin;
	data["UpperMaintenanceMargin"] = info->UpperMaintenanceMargin;
	data["SettleGroupNo"] = info->SettleGroupNo;
}

void TAP_CDECL Trade::OnRspQryHisPosition(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIHisPositionQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value HisPosition;
	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_HISTORY_POSITION;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessHisPosition(HisPosition, info);
		data["HisPosition"] = HisPosition;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessHisDelivery(Json::Value &data, const TapAPIHisDeliveryQryRsp *info){
	data["DeliveryDate"] = info->DeliveryDate;
	data["OpenDate"] = info->OpenDate;
	data["AccountNo"] = info->AccountNo;
	data["ExchangeNo"] = info->ExchangeNo;
	data["CommodityType"] = info->CommodityType;
	data["CommodityNo"] = info->CommodityNo;
	data["ContractNo"] = info->ContractNo;
	data["StrikePrice"] = info->StrikePrice;
	data["CallOrPutFlag"] = info->CallOrPutFlag;
	data["MatchSource"] = info->MatchSource;
	data["OpenSide"] = info->OpenSide;
	data["OpenPrice"] = info->OpenPrice;
	data["DeliveryPrice"] = info->DeliveryPrice;
	data["DeliveryQty"] = info->DeliveryQty;
	data["FrozenQty"] = info->FrozenQty;
	data["OpenNo"] = info->OpenNo;
	data["UpperNo"] = info->UpperNo;
	data["CommodityCurrencyGroupy"] = info->CommodityCurrencyGroupy;
	data["CommodityCurrency"] = info->CommodityCurrency;
	data["PreSettlePrice"] = info->PreSettlePrice;
	data["DeliveryProfit"] = info->DeliveryProfit;
	data["AccountFrozenInitialMargin"] = info->AccountFrozenInitialMargin;
	data["AccountFrozenMaintenanceMargin"] = info->AccountFrozenMaintenanceMargin;
	data["UpperFrozenInitialMargin"] = info->UpperFrozenInitialMargin;
	data["UpperFrozenMaintenanceMargin"] = info->UpperFrozenMaintenanceMargin;
	data["AccountFeeCurrencyGroup"] = info->AccountFeeCurrencyGroup;
	data["AccountFeeCurrency"] = info->AccountFeeCurrency;
	data["AccountDeliveryFee"] = info->AccountDeliveryFee;
	data["UpperFeeCurrencyGroup"] = info->UpperFeeCurrencyGroup;
	data["UpperFeeCurrency"] = info->UpperFeeCurrency;
	data["UpperDeliveryFee"] = info->UpperDeliveryFee;
	data["DeliveryMode"] = info->DeliveryMode;
	data["OperatorNo"] = info->OperatorNo;
	data["OperateTime"] = info->OperateTime;
	data["SettleGourpNo"] = info->SettleGourpNo;
}

void TAP_CDECL Trade::OnRspQryHisDelivery(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIHisDeliveryQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value HisDelivery;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_HISTORY_DELIVERY;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessHisDelivery(HisDelivery,info);
		data["HisDelivery"] = HisDelivery;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessAccountCashAdjust(Json::Value &data, const TapAPIAccountCashAdjustQryRsp *info){
	data["Date"] = info->Date;
	data["AccountNo"] = info->AccountNo;
	data["CashAdjustType"] = info->CashAdjustType;
	data["CurrencyGroupNo"] = info->CurrencyGroupNo;
	data["CurrencyNo"] = info->CurrencyNo;
	data["CashAdjustValue"] = info->CashAdjustValue;
	data["CashAdjustRemark"] = info->CashAdjustRemark;
	data["OperateTime"] = info->OperateTime;
	data["OperatorNo"] = info->OperatorNo;
	data["AccountBank"] = info->AccountBank;
	data["BankAccount"] = info->BankAccount;
	data["AccountLWFlag"] = info->AccountLWFlag;
	data["CompanyBank"] = info->CompanyBank;
	data["InternalBankAccount"] = info->InternalBankAccount;
	data["CompanyLWFlag"] = info->CompanyLWFlag;
}

void TAP_CDECL Trade::OnRspQryAccountCashAdjust(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountCashAdjustQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value AccountCashAdjust;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_ACCOUNT_CASH_ADJUST;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessAccountCashAdjust(AccountCashAdjust, info);
		data["AccountCashAdjust"] = AccountCashAdjust;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TapTrade::ProcessBillQryReq(Json::Value &data, TapAPIBillQryReq *info){
	data["UserNo"] = info->UserNo;
	data["BillType"] = info->BillType;
	data["BillDate"] = info->BillDate;
	data["BillFileType"] = info->BillFileType;
}

void TAP_CDECL Trade::OnRspQryBill(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIBillQryRsp *info)
{	
	Json::Value root;
	Json::Value data;
	Json::Value BillQryReq;
	Json::Value BillQryRsp;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_BILL;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;

	if(errorCode == 0){
		ProcessBillQryReq(BillQryReq,&info->Reqdata);
		BillQryRsp["ReqData"] = BillQryReq;
		BillQryRsp["BillLen"] = info->BillLen;
		BillQryRsp["BillText"] = info->BillText;
		data["BillQryRsp"] = BillQryRsp;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}

void TAP_CDECL Trade::OnExpriationDate(ITapTrade::TAPIDATE date, int days)
{
	Json::Value root;
	Json::Value data;
	Json::Value ExpriationDate;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_EXPRIATION_DATE;
	root["state"] = true;

	ExpriationDate["date"] = date;
	ExpriationDate["days"] = days;
	data["ExpriationDate"] = ExpriationDate;
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryAccountFeeRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountFeeRentQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value AccountFeeRent;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_ACCOUNT_FEE_RENT;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;
	root["isLast"] = isLast;

	if(errorCode == 0){
		AccountFeeRent["AccountNo"] = info->AccountNo;
		AccountFeeRent["ExchangeNo"] = info->ExchangeNo;
		AccountFeeRent["CommodityType"] = info->CommodityType;
		AccountFeeRent["CommodityNo"] = info->CommodityNo;
		AccountFeeRent["MatchSource"] = info->MatchSource;
		AccountFeeRent["CalculateMode"] = info->CalculateMode;
		AccountFeeRent["CurrencyGroupNo"] = info->CurrencyGroupNo;
		AccountFeeRent["CurrencyNo"] = info->CurrencyNo;
		AccountFeeRent["OpenCloseFee"] = info->OpenCloseFee;
		AccountFeeRent["CloseTodayFee"] = info->CloseTodayFee;
		data["AccountFeeRent"] = AccountFeeRent;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();


}

void TAP_CDECL Trade::OnRspQryAccountMarginRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountMarginRentQryRsp *info)
{
	Json::Value root;
	Json::Value data;
	Json::Value AccountMarginRent;

	root["type"] = TradeApi::TYPE_TRADE;
	root["event"] = TradeApi::TRADE_QRY_ACCOUNT_MARGIN_RENT;
	if(errorCode == 0) root["state"] = true;
	else root["state"] = false;
	root["errorCode"] = errorCode;
	root["isLast"] = isLast;

	if(errorCode == 0){
		AccountMarginRent["AccountNo"] = info->AccountNo;
		AccountMarginRent["ExchangeNo"] = info->ExchangeNo;
		AccountMarginRent["CommodityType"] = info->CommodityType;
		AccountMarginRent["CommodityNo"] = info->CommodityNo;
		AccountMarginRent["ContractNo"] = info->ContractNo;
		AccountMarginRent["StrikePrice"] = info->StrikePrice;
		AccountMarginRent["CallOrPutFlag"] = info->CallOrPutFlag;
		AccountMarginRent["CalculateMode"] = info->CalculateMode;
		AccountMarginRent["CurrencyGroupNo"] = info->CurrencyGroupNo;
		AccountMarginRent["CurrencyNo"] = info->CurrencyNo;
		AccountMarginRent["InitialMargin"] = info->InitialMargin;
		AccountMarginRent["MaintenanceMargin"] = info->MaintenanceMargin;
		AccountMarginRent["SellInitialMargin"] = info->SellInitialMargin;
		AccountMarginRent["SellMaintenanceMargin"] = info->SellMaintenanceMargin;
		AccountMarginRent["LockMargin"] = info->LockMargin;
		data["AccountMarginRent"] = AccountMarginRent;
	}
	root["data"] = data;

	TradeApi::ResponseEvent *rspEvent = new TradeApi::ResponseEvent(this->m_pConnect, Json::StreamWriterBuilder(this->m_jsonBuilder,root));
	this->m_pConnect->pushResponseEvent(rspEvent);
	this->m_pConnect->getResponseSignal()->SignalEvent();
}


