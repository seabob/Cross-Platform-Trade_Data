#ifndef TAP_TRADE_API_H
#define TAP_TRADE_API_H
//#include <string.h>
#include "iTapTradeAPIDataType.h"
//#include "TapProtocol.h"

#if defined WIN32 || defined WIN64
#define TAP_CDECL __cdecl
#define TAP_DLLEXPORT __declspec(dllexport)
#else
#define TAP_CDECL
#define TAP_DLLEXPORT
#endif
//TapTradeAPI.h
//�ļ�������TapTradeAPI�ṩ�������ߵĶ���ӿڡ������ͻص��ӿڡ�

//TapTradeAPI �Ļص�֪ͨ�ӿڡ�
namespace ITapTrade
{
	class ITapTradeAPINotify
	{
	public:
		/**
		* @brief ���ӳɹ��ص�֪ͨ
		* @ingroup G_T_Login
		*/
		virtual void TAP_CDECL OnConnect() = 0;
		/**
		* @brief	ϵͳ��¼���̻ص���
		* @details	�˺���ΪLogin()��¼�����Ļص�������Login()�ɹ���������·���ӣ�Ȼ��API������������͵�¼��֤��Ϣ��
		*			��¼�ڼ�����ݷ�������͵�¼�Ļ�����Ϣ���ݵ��˻ص������С�
		* @param[in] errorCode ���ش�����,0��ʾ�ɹ���
		* @param[in] loginRspInfo ��½Ӧ����Ϣ�����errorCode!=0����loginRspInfo=NULL��
		* @attention	�ûص����سɹ���˵���û���¼�ɹ������ǲ�����API׼����ϡ�
		* @ingroup G_T_Login
		*/
		virtual void TAP_CDECL OnRspLogin(ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPITradeLoginRspInfo *loginRspInfo) = 0;

		/**
		* @brief	API�������ѻص�
		* @details	�˺���ΪLogin()��¼�ɹ�������������뵱ǰ����С��30�죬����лص����ѡ�
		* @param[in] date ����API��Ȩ�����ա�
		* @param[in] days ���ػ��м�����Ȩ���ڡ�
		* @attention	�ú����ص�����˵����Ȩ��һ����֮�ڵ��ڡ����򲻲����ûص���
		* @ingroup G_T_Login
		*/
		virtual void TAP_CDECL OnExpriationDate(ITapTrade::TAPIDATE date, int days) = 0;

		/**
		* @brief	֪ͨ�û�API׼��������
		* @details	ֻ���û��ص��յ��˾���֪ͨʱ���ܽ��к����ĸ����������ݲ�ѯ������\n
		*			�˻ص�������API�ܷ����������ı�־��
		* @attention ������ſ��Խ��к�����������
		* @ingroup G_T_Login
		*/
		virtual void TAP_CDECL OnAPIReady() = 0;
		/**
		* @brief	API�ͷ���ʧȥ���ӵĻص�
		* @details	��APIʹ�ù������������߱��������������ʧȥ���Ӻ󶼻ᴥ���˻ص�֪ͨ�û���������������Ѿ��Ͽ���
		* @param[in] reasonCode �Ͽ�ԭ����롣
		* @ingroup G_T_Disconnect
		*/
		virtual void TAP_CDECL OnDisconnect(ITapTrade::TAPIINT32 reasonCode) = 0;
		/**
		* @brief ֪ͨ�û������޸Ľ��
		* @param[in] sessionID �޸�����ĻỰID,��ChangePassword���صĻỰID��Ӧ��
		* @param[in] errorCode ���ش����룬0��ʾ�ɹ���
		* @ingroup G_T_UserInfo
		*/
		virtual void TAP_CDECL OnRspChangePassword(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode) = 0;
		/**
		* @brief �����û�Ԥ����Ϣ����
		* @param[in] sessionID �����û�Ԥ����Ϣ�ĻỰID
		* @param[in] errorCode ���ش����룬0��ʾ�ɹ���
		* @param[in] info ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @note �ýӿ���δʵ��
		* @ingroup G_T_UserInfo
		*/
		virtual void TAP_CDECL OnRspSetReservedInfo(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TAPISTR_50 info) = 0;
		/**
		* @brief	�����û���Ϣ
		* @details	�˻ص��ӿ����û����ز�ѯ���ʽ��˺ŵ���ϸ��Ϣ���û��б�Ҫ���õ����˺ű�ű���������Ȼ���ں����ĺ���������ʹ�á�
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast ��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_AccountInfo
		*/
		virtual void TAP_CDECL OnRspQryAccount(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIUINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountInfo *info) = 0;
		/**
		* @brief �����ʽ��˻����ʽ���Ϣ
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_AccountDetails
		*/
		virtual void TAP_CDECL OnRspQryFund(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIFundData *info) = 0;
		/**
		* @brief	�û��ʽ�仯֪ͨ
		* @details	�û���ί�гɽ���������ʽ����ݵı仯�������Ҫ���û�ʵʱ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @note �������ע�������ݣ������趨Loginʱ��NoticeIgnoreFlag�����Ρ�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_AccountDetails
		*/
		virtual void TAP_CDECL OnRtnFund(const ITapTrade::TapAPIFundData *info) = 0;
		/**
		* @brief ����ϵͳ�еĽ�������Ϣ
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeSystem
		*/
		virtual void TAP_CDECL OnRspQryExchange(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIExchangeInfo *info) = 0;
		/**
		* @brief	����ϵͳ��Ʒ����Ϣ
		* @details	�˻ص��ӿ��������û����صõ�������Ʒ����Ϣ��
		* @param[in] sessionID ����ĻỰID����GetAllCommodities()�������ض�Ӧ��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_Commodity
		*/
		virtual void TAP_CDECL OnRspQryCommodity(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICommodityInfo *info) = 0;
		/**
		* @brief ����ϵͳ�к�Լ��Ϣ
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_Contract
		*/
		virtual void TAP_CDECL OnRspQryContract(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPITradeContractInfo *info) = 0;
		/**
		* @brief	����������Լ��Ϣ
		* @details	���û������µĺ�Լ����Ҫ���������ڽ���ʱ����з������������º�Լʱ�����û����������Լ����Ϣ��
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_Contract
		*/
		virtual void TAP_CDECL OnRtnContract(const ITapTrade::TapAPITradeContractInfo *info) = 0;
		/**
		* @brief ������ί�С����µĻ��������ط��µ����͹����ġ�
		* @details	���������յ��ͻ��µ�ί�����ݺ�ͻᱣ�������ȴ�������ͬʱ���û�����һ��
		*			��ί����Ϣ˵����������ȷ�������û������󣬷��ص���Ϣ�а�����ȫ����ί����Ϣ��
		*			ͬʱ��һ��������ʾ��ί�е�ί�кš�
		* @param[in] info ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @note �������ע�������ݣ������趨Loginʱ��NoticeIgnoreFlag�����Ρ�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeActions
		*/
		virtual void TAP_CDECL OnRtnOrder(const ITapTrade::TapAPIOrderInfoNotice *info) = 0;
		/**
		* @brief	���ضԱ����������������
		* @details	���µ��������Ȳ����Ľ����
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] info �����ľ�����Ϣ����errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @note �ýӿ�Ŀǰû���õ������в������ͨ��OnRtnOrder����
		* @ingroup G_T_TradeActions
		*/
		virtual void TAP_CDECL OnRspOrderAction(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIUINT32 errorCode, const ITapTrade::TapAPIOrderActionRsp *info) = 0;
		/**
		* @brief	���ز�ѯ��ί����Ϣ
		* @details	�����û���ѯ��ί�еľ�����Ϣ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast ��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeInfo
		*/
		virtual void TAP_CDECL OnRspQryOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIOrderInfo *info) = 0;
		/**
		* @brief ���ز�ѯ��ί�б仯������Ϣ
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����룬��errorCode==0ʱ��infoָ�򷵻ص�ί�б仯���̽ṹ�壬��ȻΪNULL��
		* @param[in] isLast ��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info ���ص�ί�б仯����ָ�롣
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeInfo
		*/
		virtual void TAP_CDECL OnRspQryOrderProcess(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIOrderInfo *info) = 0;
		/**
		* @brief ���ز�ѯ�ĳɽ���Ϣ
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeInfo
		*/
		virtual void TAP_CDECL OnRspQryFill(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIFillInfo *info) = 0;
		/**
		* @brief	�������ĳɽ���Ϣ
		* @details	�û���ί�гɽ������û����ͳɽ���Ϣ��
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @note �������ע�������ݣ������趨Loginʱ��NoticeIgnoreFlag�����Ρ�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeActions
		*/
		virtual void TAP_CDECL OnRtnFill(const ITapTrade::TapAPIFillInfo *info) = 0;
		/**
		* @brief ���ز�ѯ�ĳֲ�
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeInfo
		*/
		virtual void TAP_CDECL OnRspQryPosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIPositionInfo *info) = 0;
		/**
		* @brief �ֱֲ仯����֪ͨ
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @note �������ע�������ݣ������趨Loginʱ��NoticeIgnoreFlag�����Ρ�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeActions
		*/
		virtual void TAP_CDECL OnRtnPosition(const ITapTrade::TapAPIPositionInfo *info) = 0;
		/**
		* @brief ���ز�ѯ��ƽ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeInfo
		*/
		virtual void TAP_CDECL OnRspQryClose(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICloseInfo *info) = 0;
		/**
		* @brief ƽ�����ݱ仯����
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @note �������ע�������ݣ������趨Loginʱ��NoticeIgnoreFlag�����Ρ�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeActions
		*/
		virtual void TAP_CDECL OnRtnClose(const ITapTrade::TapAPICloseInfo *info) = 0;
		/**
		* @brief �ֲ�ӯ��֪ͨ
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @note �������ע�������ݣ������趨Loginʱ��NoticeIgnoreFlag�����Ρ�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeActions
		*/
		virtual void TAP_CDECL OnRtnPositionProfit(const ITapTrade::TapAPIPositionProfitNotice *info) = 0;


		/**
		* @brief ����ϵͳ�еı�����Ϣ
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_TradeSystem
		*/
		virtual void TAP_CDECL OnRspQryCurrency(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICurrencyInfo *info) = 0;

		/**
		* @brief	������Ϣ֪ͨ
		* @details	���ز�ѯ���û��ʽ�״̬��Ϣ����Ϣ˵�����û����ʽ�״̬���û���Ҫ��ϸ�鿴��Щ��Ϣ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ�����ݣ�
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_AccountDetails
		*/
		virtual void TAP_CDECL OnRspQryTradeMessage(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPITradeMessage *info) = 0;
		/**
		* @brief	������Ϣ֪ͨ
		* @details	�û��ڽ��׹����п�����Ϊ�ʽ𡢳ֲ֡�ƽ�ֵ�״̬�䶯ʹ�˻�����ĳЩΣ��״̬������ĳЩ��Ҫ����Ϣ��Ҫ���û�֪ͨ��
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_AccountDetails
		*/
		virtual void TAP_CDECL OnRtnTradeMessage(const ITapTrade::TapAPITradeMessage *info) = 0;
		/**
		* @brief ��ʷί�в�ѯӦ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_HisInfo
		*/
		virtual void TAP_CDECL OnRspQryHisOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisOrderQryRsp *info) = 0;
		/**
		* @brief ��ʷί�����̲�ѯӦ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_HisInfo
		*/
		virtual void TAP_CDECL OnRspQryHisOrderProcess(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisOrderProcessQryRsp *info) = 0;
		/**
		* @brief ��ʷ�ɽ���ѯӦ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_HisInfo
		*/
		virtual void TAP_CDECL OnRspQryHisMatch(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisMatchQryRsp *info) = 0;
		/**
		* @brief ��ʷ�ֲֲ�ѯӦ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_HisInfo
		*/
		virtual void TAP_CDECL OnRspQryHisPosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisPositionQryRsp *info) = 0;
		/**
		* @brief ��ʷ�����ѯӦ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_HisInfo
		*/
		virtual void TAP_CDECL OnRspQryHisDelivery(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisDeliveryQryRsp *info) = 0;
		/**
		* @brief �ʽ������ѯӦ��
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] isLast 	��ʾ�Ƿ������һ������
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_HisInfo
		*/
		virtual void TAP_CDECL OnRspQryAccountCashAdjust(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountCashAdjustQryRsp *info) = 0;
		/**
		* @brief ��ѯ�û��˵�Ӧ�� Add:2013.12.11
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_Bill
		*/
		virtual void TAP_CDECL OnRspQryBill(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIBillQryRsp *info) = 0;
		/**
		* @brief ��ѯ�˻������Ѽ������ Add:2017.01.14
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_Rent
		*/
		virtual void TAP_CDECL OnRspQryAccountFeeRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountFeeRentQryRsp *info) = 0;
		/**
		* @brief ��ѯ�˻���֤�������� Add:2017.01.14
		* @param[in] sessionID ����ĻỰID��
		* @param[in] errorCode �����롣0 ��ʾ�ɹ���
		* @param[in] info		ָ�򷵻ص���Ϣ�ṹ�塣��errorCode��Ϊ0ʱ��infoΪ�ա�
		* @attention ��Ҫ�޸ĺ�ɾ��info��ָʾ�����ݣ��������ý���������������Ч��
		* @ingroup G_T_Rent
		*/
		virtual void TAP_CDECL OnRspQryAccountMarginRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountMarginRentQryRsp *info) = 0;


	};



	//TapTradeAPI ���⹦�ܽӿڡ��������û����Ե��õĹ��ܺ�����
	class ITapTradeAPI
	{
	public:
		/**
		* @brief	����API�Ļص��ӿڶ���
		* @details	ϵͳ��API��֪ͨ��ͨ�����õĻص�����֪ͨ��ʹ���ߡ�
		*			ITapTradeAPINotify��API�Ļص��ӿڣ��û���Ҫ�̳�ʵ�ִ˽ӿ������������û���Ҫ�Ĺ��ܡ�
		*			����û�û�����ûص��ӿڣ���API�������û������κ����õ���Ϣ��\n
		*			ITapTradeAPINotify�����ϸ������鿴TapTradeAPI.h �ļ���
		* @param[in] apiNotify ʵ����ITapTradeAPINotify�ӿڵĶ���ָ�롣
		* @operationtype ͬ������
		* @ingroup G_T_Login
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL SetAPINotify(ITapTrade::ITapTradeAPINotify *pSpi) = 0;
		/**
		* @brief ���÷�������IP��ַ�Ͷ˿ڡ�
		* @param[in] IP   IP��ַ
		* @param[in] port �˿ں�
		* @operationtype ͬ������
		* @ingroup G_T_Login
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL SetHostAddress(const ITapTrade::TAPICHAR *IP, ITapTrade::TAPIUINT16 port) = 0;
		/**
		* @brief	�����¼����API�������ӷ��񣬽�����·�������¼��֤��
		* @details	��ʹ�ú���ǰ�û���Ҫ��ɷ�����������SetHostAddress()�����Ҵ���TapAPITradeLoginAuth���͵��û���Ϣ��
		*			������Ҫ���úûص��ӿڡ�\n
		*			��¼�����н������ӵķ�����Ϣͨ���ص�OnConnect���ظ��û���\n
		*			���ӽ�������û���֤������Ϣͨ���ص�OnLogin()���ظ��û���\n
		*			��¼�ɹ���API���Զ�����API�ĳ�ʼ����API�����������������ݣ���ѯ���Ժ��ͨ���ص�OnAPIReady()
		*			ָʾ�û�API��ʼ����ɣ����Խ��к����Ĳ����ˡ�
		* @param[in] loginAuth ��¼��֤��Ϣ�ṹָ�롣������¼��Ҫ����֤��Ϣ��
		* @retval 0 ��¼�ɹ���API��ʼ׼����̨����
		* @retval ��0 ������
		* @operationtype �첽����
		* @note TapAPITradeLoginAuth�е�NoticeIgnoreFlag���ڱ���Ƿ�����ض���֪ͨ�ص���\n
		*       ���磺����Ҫ����OnRtnFund��OnRtnPositionProfit,������ô�趨��\n
		*       NoticeIgnoreFlag = TAPI_NOTICE_IGNORE_FUND | TAPI_NOTICE_IGNORE_POSITIONPROFIT;
		* @attention Login()�������óɹ�ֻ�Ǵ����ڷ�������������·���ӣ�ֻ�лص�OnLogin()�ķ�����ָʾ�û��Ƿ�ɹ���¼�ˡ�
		* @ingroup G_T_Login
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL Login(const ITapTrade::TapAPITradeLoginAuth *loginAuth) = 0;
		/**
		* @brief	�Ͽ��ͷ���������·���ӡ�
		* @details	���ú�����API���ǳ����Ͽ�������������ӡ�
		* @operationtype ͬ������
		* @ingroup G_T_Disconnect
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL Disconnect() = 0;
		/**
		* @brief	�޸����롣
		* @details	�ɹ����û����뽫�����ó�newPassword��
		* @param[out]	sessionID ���ش˴��޸�����ĻỰID;
		* @param[in]	req �����޸�����Ľṹ��ָ��
		* @retval 0 �ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_UserInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL ChangePassword(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIChangePasswordReq *req) = 0;
		/**
		* @brief	�жϵ�¼�û��Ƿ����ĳȨ�ޡ�
		* @details	�û���Ȩ�����û���¼ʱ�Ѿ����ݸ�API�����Դ˺���ִ�е��Ǳ��صĲ�ѯ��
		* @param[in] rightID Ȩ��ID��
		* @retval 0 ������Ȩ��
		* @retval ��0 ����Ȩ��
		* @operationtype ͬ������
		* @ingroup G_T_UserRight
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL HaveCertainRight(ITapTrade::TAPIRightIDType rightID) = 0;
		/**
		* @brief	�����û�Ԥ����Ϣ��
		* @details	�û���������һ������Ϊ50���ڵ��ַ���Ϣ���´ε�¼����Եõ������Ϣ��
		*			���������Ҫ���������û�ȷ�����Լ����˺ţ���Ҫ���������з�α��
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in] info	Ԥ����Ϣ�ַ���ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @note �ýӿ���δʵ��
		* @ingroup G_T_UserInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL SetReservedInfo(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TAPISTR_50 info) = 0;
		/**
		* @brief ��ѯ�û��������ʽ��˺�
		* @details	TapAPIAccQryReq�ǰ����ʽ��˺Žṹ�Ľṹ�壬�û���Ҫʵ�����˽ṹ�壬
		*			���ǲ���Ҫ��д������ṹ����Ҫ�����������û������ʽ��˺ţ��ʽ��˺�
		*			�ں����ĺ��������кܶຯ������Ҫʹ�õ���
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in]	qryReq ��ѯ�û��������ʽ��˺ŵĽṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_AccountInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryAccount(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIAccQryReq *qryReq) = 0;
		/**
		* @brief	��ѯ�ͻ��ʽ�
		* @details	TapAPIFundReq��ҪQryAccount()��ȡ���ʽ��˺š�
		*			�����Ļص��������ʽ��˺ŵ��ʽ���Ϣ��\n
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq	��ѯ�ͻ��ʽ�����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_AccountDetails
		* @attention ÿ�ε�½���ýӿ�ֻ�ܽ���һ�ε��á������ʼ��ʱ����һ�Σ�������֪ͨͨ��OnRtnFundȡ�á�
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryFund(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIFundReq *qryReq) = 0;
		/**
		* @brief ��ѯ����ϵͳ��������Ϣ
		* @param[out] sessionID ��������ĻỰID;
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeSystem
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryExchange(ITapTrade::TAPIUINT32 *sessionID) = 0;
		/**
		* @brief	��ѯϵͳƷ����Ϣ
		* @details	���������ȡ���е�Ʒ����Ϣ��
		* @param[out] sessionID ��������ĻỰID;
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_Commodity
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryCommodity(ITapTrade::TAPIUINT32 *sessionID) = 0;
		/**
		* @brief	��ѯϵͳ��ָ��Ʒ�ֵĺ�Լ��Ϣ
		* @details	ʹ�ô˺���ǰ��Ҫ��Qrycommodity()ȡ��Ʒ����Ϣ��
		*			Ȼ��ѡ����Ҫ��Ʒ�ֽ���Ϣ����TapAPICommodity�ṹ������ɲ�ѯ����
		*			����TapAPICommodity����򷵻�������Ϣ��
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq ��ѯϵͳ��ָ��Ʒ�ֵĺ�Լ��Ϣ����Ľṹ��ָ��;\n
		*				    �ò������ֶ�Ϊ��ѡ�ֶΣ����������·�����ѯ��\n
		*					1.ȫ�����գ������к�Լ\n
		*					2.��������������Ч����ý�����������Ʒ�ֵĺ�Լ\n
		*					3.�����������Ʒ��������Ч����ý�������ָ��Ʒ�����͵ĺ�Լ\n
		*					4.���������롢Ʒ�����ͺ�Ʒ�ֱ��붼��Ч�����Ʒ���µ����к�Լ
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_Contract
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryContract(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPICommodity *qryReq) = 0;
		/**
		* @brief	�µ�
		* @details	�û��µ��Ĳ���������
		*			�û����µ�����������û����ʽ𡢳ֲ֡�ƽ�֡��ʽ𡢷�ر�ǵȶ������ݵı仯�������û��µĵ��ɽ���
		*			���ж���ص�֪ͨ�����û�չʾ���ݵı仯��
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in]	order �µ�ί��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeActions
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL InsertOrder(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPINewOrder *order) = 0;
		/**
		* @brief	����
		* @details	�û�ί��û����ȫ�ɽ�֮ǰ����ʣ���ί�С�
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in]	order ������ί��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeActions
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL CancelOrder(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIOrderCancelReq *order) = 0;
		/**
		* @brief	��ѯί����Ϣ
		* @details	���ص�ǰ��ί����Ϣ�����Բ�ѯ����ί�У�Ҳ���Բ�ѯ����δ������ί�С�\n
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeInfo
		* @attention ÿ�ε�½���ýӿ�ֻ�ܽ���һ�ε��á������ʼ��ʱ����һ�Σ�������֪ͨͨ��OnRtnOrderȡ�á�
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryOrder(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIOrderQryReq *qryReq) = 0;
		/**
		* @brief	��ѯί�б仯����
		* @details	��ѯ�û���ί�еı仯���̣���ѯ������ί�е�ÿһ�εı仯��
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq ί�����̲�ѯ��Ϣ�ṹ��ָ�롣
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryOrderProcess(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIOrderProcessQryReq *qryReq) = 0;
		/**
		* @brief ��ѯ�ɽ���Ϣ
		* @details	��ѯϵͳ�гɽ�����Ϣ��
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq �ɽ���ѯ��Ϣ�ṹ��ָ�롣
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeInfo
		* @attention ÿ�ε�½���ýӿ�ֻ�ܽ���һ�ε��á������ʼ��ʱ����һ�Σ�������֪ͨͨ��OnRtnFillȡ�á�
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryFill(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIFillQryReq *qryReq) = 0;
		/**
		* @brief	��ѯ�û��ֲ�
		* @details	��ѯ�û������гֲ���Ϣ��
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq	��ѯ�û��ֲ�����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeInfo
		* @attention ÿ�ε�½���ýӿ�ֻ�ܽ���һ�ε��á������ʼ��ʱ����һ�Σ�������֪ͨͨ��OnRtnPositionȡ�á�
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryPosition(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIPositionQryReq *qryReq) = 0;
		/**
		* @brief ��ѯƽ�ּ�¼
		* @details	��ѯ�û����е�ƽ�ּ�¼��
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq	��ѯƽ�ּ�¼����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeInfo
		* @attention ÿ�ε�½���ýӿ�ֻ�ܽ���һ�ε��á������ʼ��ʱ����һ�Σ�������֪ͨͨ��OnRtnCloseȡ�á�
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryClose(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPICloseQryReq *qryReq) = 0;

		/**
		* @brief	�ĵ�
		* @details	�û���ί��û����ȫ�ɽ�֮ǰ���Խ��иĵ��������޸�ʣ���δ�ɽ���ί�С�\n
		*			�û���д�µ�ί�����޸�ԭ����δ�ɽ��Ĳ��֡��������޸Ļ�Ա��Ѿ��ɽ��Ĳ������۳��ɽ����֡�
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in]	order �޸ĵ�ί��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeActions
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL AmendOrder(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIAmendOrder *order) = 0;

		/**
		* @brief ��ȡ�������ñ��ֵ���Ϣ
		* @param[out] sessionID ��������ĻỰID;
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_TradeSystem
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryCurrency(ITapTrade::TAPIUINT32 *sessionID) = 0;
		/**
		* @brief �ͻ��ʽ������ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	�ͻ��ʽ������ѯ����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_HisInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryAccountCashAdjust(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIAccountCashAdjustQryReq *qryReq) = 0;
		/**
		* @brief	��ȡ���׻�����Ϣ
		* @details	�˺�������������ȡ�˺ŵĽ��׻��߷����Ϣ�����׻��߷����Ϣ������ʶ�˺ŵ�״̬��
		* @param[out] sessionID ��������ĻỰID;
		* @param[in] qryReq ��ȡ���׻�����Ϣ����Ľṹ��ָ��;
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		˵������ʢ�����ӿ�
		* @ingroup G_T_AccountDetails
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryTradeMessage(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPITradeMessageReq *qryReq) = 0;
		/**
		* @brief ��ѯ�û��˵�
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in]	qryReq	��ѯ�ʵ�����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_Bill
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryBill(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIBillQryReq *qryReq) = 0;
		/**
		* @brief ��ʷί�в�ѯ����
		* @param[out]	sessionID ��������ĻỰID;
		* @param[in]	Req	��ʷί�в�ѯ����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_HisInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryHisOrder(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIHisOrderQryReq *qryReq) = 0;
		/**
		* @brief ��ʷί�����̲�ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	��ʷί�����̲�ѯ����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_HisInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryHisOrderProcess(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIHisOrderProcessQryReq *qryReq) = 0;
		/**
		* @brief ��ʷ�ɽ���ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	��ʷ�ɽ���ѯ����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_HisInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryHisMatch(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIHisMatchQryReq *qryReq) = 0;
		/**
		* @brief ��ʷ�ֲֲ�ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	��ʷ�ֲֲ�ѯ����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_HisInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryHisPosition(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIHisPositionQryReq *qryReq) = 0;
		/**
		* @brief ��ʷ�����ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	��ʷ�����ѯ����Ľṹ��ָ��
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_HisInfo
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryHisDelivery(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIHisDeliveryQryReq *qryReq) = 0;

		/**
		* @brief �ͻ������Ѽ��������ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	�ͻ������Ѽ��������ѯ����ṹ
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_Rent
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryAccountFeeRent(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIAccountFeeRentQryReq *qryReq) = 0;
		/**
		* @brief �ͻ���֤����������ѯ����
		* @param[out] sessionID ��������ĻỰID;
		* @param[in]	Req	�ͻ���֤����������ѯ����ṹ
		* @retval 0 ����ɹ�
		* @retval ��0 ������
		* @operationtype �첽����
		* @ingroup G_T_Rent
		*/
		virtual ITapTrade::TAPIINT32 TAP_CDECL QryAccountMarginRent(ITapTrade::TAPIUINT32 *sessionID, const ITapTrade::TapAPIAccountMarginRentQryReq *qryReq) = 0;
	};
};

    //-----------------------------TapTradeAPI��������------------------------------------


    #ifdef __cplusplus
    extern "C" {
    #endif // __cplusplus

    /**
    * @brief	����TapTradeAPI�Ľӿڶ���
    * @details	������������API�Ľӿ�
    * @param[in] appInfo Ӧ�ó��������Ϣ��
    * @param[in] iResult �����ӿڵĴ����롣
    * @retval NULL	����ʧ�ܣ�����ԭ���ͨ���������iResult�жϡ�
    * @retval !NULL	ʵ����ITapTradeAPI�ӿڵĶ���ָ�롣
    * @ingroup G_T_API
    */
		TAP_DLLEXPORT ITapTrade::ITapTradeAPI *TAP_CDECL CreateITapTradeAPI(const ITapTrade::TapAPIApplicationInfo *appInfo, ITapTrade::TAPIINT32 &iResult);
    /**
    * @brief	����ͨ��CreateTapTradeAPI����������ITapTradeAPI����
    * @param[in] apiObj ITapTradeAPI����ָ�롣
    * @ingroup G_T_API
    */
		TAP_DLLEXPORT void TAP_CDECL FreeITapTradeAPI(ITapTrade::ITapTradeAPI *apiObj);
    /**
    * @brief	��ȡTapTradeAPI�İ汾��Ϣ
    * @ingroup G_T_API
    */
		TAP_DLLEXPORT const ITapTrade::TAPICHAR *TAP_CDECL GetITapTradeAPIVersion();
    /**
    * @brief	����API������������Ŀ¼
    * @details	���ú�����ͬʱ����path������Ŀ¼�´��������գ���ʽTapTradeAPI[YYYYMMDD].log)�������ļ���\n
    *			û�д��ļ�������»���ͼ�������ļ���\n
    *			�ļ��б��������ΪAPI���յ�����Ҫ���ݺ�API��ʹ�úʹ�����־��
    * @param[in] path Ŀ¼��������ã�Ŀ¼����Window��Ϊ��\\�����ߡ�/��, Linux��Ϊ��/����
    * @retval 0 �ɹ�
    * @retval ��0 ������
    * @operationtype ͬ������
    * @ingroup G_T_LogConfig
    */
		TAP_DLLEXPORT ITapTrade::TAPIINT32 TAP_CDECL SetITapTradeAPIDataPath(const ITapTrade::TAPICHAR *path);
    /**
    * @brief	����API����־����
    * @details	�趨��־���������ֻ�е�ʵ����־������˴��趨�ļ�����ͬ�����ʱ���ŻὫ��־д��SetTapTradeAPIDataPath()�����򿪵���־�ļ���\n
    * @param[in]	level ��־����\n
    *					APILOGLEVEL_NONE	������¼��־\n
    *					APILOGLEVEL_ERROR	����¼Error��־\n
    *					APILOGLEVEL_WARNING	����¼Error��Warning��־\n
    *					APILOGLEVEL_DEBUG	����¼Error��Warning��Debug��־\n
    * @retval 0 �趨�ɹ�
    * @retval ��0 ������
    * @operationtype ͬ������
    * @ingroup G_T_LogConfig
    */
		TAP_DLLEXPORT ITapTrade::TAPIINT32 TAP_CDECL SetITapTradeAPILogLevel(ITapTrade::TAPILOGLEVEL level);

    #ifdef __cplusplus
    }
    #endif // __cplusplus


#endif // TAP_TRADE_API_H