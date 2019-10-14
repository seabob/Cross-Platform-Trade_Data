#ifndef TAP_TAPI_ERROR_H
#define TAP_TAPI_ERROR_H

//=============================================================================
/**
 *	\addtogroup G_ERR_INNER_API		TapAPI�ڲ����صĴ����붨�塣
 *	@{
 */
//=============================================================================
//! �ɹ�
namespace ITapTrade
{

    //=============================================================================
    //��¼����ִ�д���
	const int			TAPIERROR_LOGIN = 10001;
    //��¼�û�������
	const int			TAPIERROR_LOGIN_USER = 10002;
    //��Ҫ���ж�̬��֤
	const int			TAPIERROR_LOGIN_DDA = 10003;
    //��¼�û�δ��Ȩ
	const int			TAPIERROR_LOGIN_LICENSE = 10004;
    //��¼ģ�鲻��ȷ
	const int			TAPIERROR_LOGIN_MODULE = 10005;
    //��Ҫǿ���޸�����
	const int			TAPIERROR_LOGIN_FORCE = 10006;
    //��¼״̬��ֹ��½
	const int			TAPIERROR_LOGIN_STATE = 10007;
    //��¼���벻��ȷ
	const int			TAPIERROR_LOGIN_PASS = 10008;
    //û�и�ģ���¼Ȩ��
	const int			TAPIERROR_LOGIN_RIGHT = 10009;
    //��¼��������
	const int			TAPIERROR_LOGIN_COUNT = 10010;
    //��¼�û����ڷ�������ʶ�¿ɵ�¼�û��б���
	const int			TAPIERROR_LOGIN_NOTIN_SERVERFLAGUSRES = 10011;
    //=============================================================================
    //���ݿ�����ʧ��
	const int			TAPIERROR_CONN_DATABASE = 11000;
    //���ݿ����ʧ��
	const int			TAPIERROR_OPER_DATABASE = 11001;
    //������һ�Զ�
	const int			TAPIERROR_NEED_ONETOONE = 11002;
    //ɾ��ʧ��-���ڹ�����Ϣ��
	const int			TAPIERROR_EXIST_RELATEINFO = 11003;

    //��¼�û������޸�ʧ��-ԭʼ�������
	const int			TAPIERROR_USERPASSWORD_MOD_SOURCE = 12001;
    //��¼�û������޸�ʧ��-������ǰn��������ͬ
	const int			TAPIERROR_USERPASSWORD_MOD_SAME = 12002;
    //��¼�û������޸�ʧ��-�����벻�������븴�Ӷ�Ҫ��
	const int          TAPIERROR_USERPASSWORD_MOD_COMPLEXITY = 12003;

    //һ��������ֻ������һ������
	const int			TAPIERROR_CURRENCY_ONLY_ONEBASE = 13001;
    //����ֻ������Ԫ��۱�
	const int			TAPIERROR_CURRENCY_ONLY_USDHKD = 13002;

    //----------------���׷��������붨��----------------------------------------------
    //�ʽ��˺Ų�����
	const int			TAPIERROR_ORDERINSERT_ACCOUNT = 60001;
    //�ʽ��˺�״̬����ȷ
	const int			TAPIERROR_ORDERINSERT_ACCOUNT_STATE = 60002;

    //�µ���Ч�ĺ�Լ
	const int			TAPIERROR_ORDERINSERT_CONTRACT = 60011;
    //LMEδ׼������
	const int			TAPIERROR_ORDERINSERT_LME_NOTREADY = 60012;

    //�ͻ�Ȩ�޽�ֹ����
	const int			TAPIERROR_ORDER_NOTRADE_ACCOUNT = 60021;
    //�ͻ�Ʒ�ַ����ֹ����
	const int			TAPIERROR_ORDER_NOTRADE_COM_GROUP = 60022;
    //�ͻ���Լ�����ֹ����
	const int			TAPIERROR_ORDER_NOTRADE_ACC_CONTRACT = 60023;
    //ϵͳȨ�޽�ֹ����
	const int			TAPIERROR_ORDER_NOTRADE_SYSTEM = 60024;
    //�ͻ�Ȩ��ֻ��ƽ��
	const int			TAPIERROR_ORDER_CLOSE_ACCOUNT = 60025;
    //�ͻ���Լ����ֻ��ƽ��
	const int			TAPIERROR_ORDER_CLOSE_ACC_CONTRACT = 60026;
    //ϵͳȨ��ֻ��ƽ��
	const int			TAPIERROR_ORDER_CLOSE_SYSTEM = 60027;


    //�ֲ��������������
	const int			TAPIERROR_ORDERINSERT_POSITIONMAX = 60031;
    //�µ��������������
	const int			TAPIERROR_ORDERINSERT_ONCEMAX = 60032;
    //�µ���Լ�޽���·��
	const int			TAPIERROR_ORDERINSERT_TRADEROUTE = 60033;

    //δ��¼����
	const int          TAPIERROR_UPPERCHANNEL_NOT_LOGIN = 60041;

    //�µ��ʽ���
	const int			TAPIERROR_ORDERINSERT_NOTENOUGHFUND = 60051;
    //�����Ѳ�������
	const int			TAPIERROR_ORDERINSERT_FEE = 60052;
    //��֤���������
	const int			TAPIERROR_ORDERINSERT_MARGIN = 60053;
    //�ܻ����ʽ���
	const int			TAPIERROR_ORDERINSERT_BASENOFUND = 60054;

    //�����޴�ϵͳ��
	const int          TAPIERROR_ORDERDELETE_NOT_SYSNO = 60061;
    //��״̬��������
	const int          TAPIERROR_ORDERDELETE_NOT_STATE = 60062;

    //��״̬������ĵ�
	const int			TAPIERROR_ORDERMODIFY_NOT_STATE = 60071;
    //�˹���������ĵ�
	const int			TAPIERROR_ORDERMODIFY_BACK_INPUT = 60072;

    //��ɾ����������ת��
	const int			TAPIERROR_ORDERINPUT_CANNOTMOVE = 60081;

    //¼���ظ�
	const int			TAPIERROR_ORDERINPUT_REPEAT = 60091;

    //----------------���ش�����붨��-----------------------------------------------
    //����δ������δ��������
	const int			TAPIERROR_GW_NOT_READY = 80001;
    //Ʒ�ִ���
	const int			TAPIERROR_GW_INVALID_COMMODITY = 80002;
    //��Լ����
	const int			TAPIERROR_GW_INVALID_CONTRACT = 80003;
    //�����ֶ�����
	const int			TAPIERROR_GW_INVALID_FIELD = 80004;
    //�۸񲻺Ϸ�
	const int		    TAPIERROR_GW_INVALID_PRICE = 80005;
    //�������Ϸ�
	const int			TAPIERROR_GW_INVALID_VOLUME = 80006;
    //�������Ͳ��Ϸ�
	const int			TAPIERROR_GW_INVALID_TYPE = 80007;
    //ί��ģʽ���Ϸ�
	const int			TAPIERROR_GW_INVALID_MODE = 80008;
    //ί�в����ڣ��ĵ���������
	const int			TAPIERROR_GW_ORDER_NOT_EXIST = 80009;
    //���ͱ���ʧ��
	const int			TAPIERROR_GW_SEND_FAIL = 80010;
    //�����־ܾ�
	const int			TAPIERROR_GW_REJ_BYUPPER = 80011;


    //----------------����ǰ�ô�����붨��-----------------------------------------------
    //ǰ�ò������ģ���¼
	const int			TAPIERROR_TRADEFRONT_MODULETYPEERR = 90001;
    //һ������̫������
	const int			TAPIERROR_TRADEFRONT_TOOMANYDATA = 90002;
    //ǰ��û����Ҫ����
	const int			TAPIERROR_TRADEFRONT_NODATA = 90003;

    //ǰ���뽻�׶Ͽ�
	const int			TAPIERROR_TRADEFRONT_DISCONNECT_TRADE = 90011;
    //ǰ�������Ͽ�
	const int			TAPIERROR_TRADEFRONT_DISCONNECT_MANAGE = 90012;

    //�����ʽ��˺Ų�����
	const int			TAPIERROR_TRADEFRONT_ACCOUNT = 90021;
    
    
    
    const int TAPIERROR_SUCCEED                                            = 0;
    //! ���ӷ���ʧ��
    const int TAPIERROR_ConnectFail                                        = -1;
    //! ��·��֤ʧ��
    const int TAPIERROR_LinkAuthFail                                       = -2;
    //! ������ַ������
    const int TAPIERROR_HostUnavailable                                    = -3;
    //! �������ݴ���
    const int TAPIERROR_SendDataError                                      = -4;
    //! ���Ա�Ų��Ϸ�
    const int TAPIERROR_TestIDError                                        = -5;
    //! û׼���ò�������
    const int TAPIERROR_NotReadyTestNetwork                                = -6;
    //! ��ǰ������Ի�û����
    const int TAPIERROR_CurTestNotOver                                     = -7;
    //! û�ÿ��õĽ���ǰ��
    const int TAPIERROR_NOFrontAvailable                                   = -8;
    //! ����·��������
    const int TAPIERROR_DataPathAvaiable                                   = -9;
    //! �ظ���¼
    const int TAPIERROR_RepeatLogin                                        = -10;
    //! �ڲ�����	
    const int TAPIERROR_InnerError                                         = -11;
    //! ��һ������û�н���	
    const int TAPIERROR_LastReqNotFinish                                   = -12;
    //! ��������Ƿ�	
    const int TAPIERROR_InputValueError                                    = -13;
    //! ��Ȩ�벻�Ϸ�	
    const int TAPIERROR_AuthCode_Invalid                                   = -14;
    //! ��Ȩ�볬��	
    const int TAPIERROR_AuthCode_Expired                                   = -15;
    //! ��Ȩ�����Ͳ�ƥ��	
    const int TAPIERROR_AuthCode_TypeNotMatch                              = -16;
    //! API��û��׼����
    const int TAPIERROR_API_NotReady                                       = -17;
    //! UDP�˿ڼ���ʧ��
    const int TAPIERROR_UDP_LISTEN_FAILED                                  = -18;
    //! UDP���ڼ���
    const int TAPIERROR_UDP_LISTENING                                      = -19;
    //! �ӿ�δʵ��
    const int TAPIERROR_NotImplemented                                     = -20;
    //! ÿ�ε�½ֻ�������һ��
    const int TAPIERROR_CallOneTimeOnly                                    = -21;
	//�����µ�Ƶ�ʡ�
	const int TAPIERROR_ORDER_FREQUENCY										= -22;
	//��ѯƵ��̫�졣
	const int TAPIERROR_RENTQRY_TOOFAST										= -23;

    /** @}*/


    //=============================================================================
    /**
     *	\addtogroup G_ERR_INPUT_CHECK		�������������
     *	@{
     */
    //=============================================================================
    //! ��������ΪNULL
    const int TAPIERROR_INPUTERROR_NULL                                    = -10000;
    //! ��������:TAPIYNFLAG
    const int TAPIERROR_INPUTERROR_TAPIYNFLAG                              = -10001;
    //! ��������:TAPILOGLEVEL
    const int TAPIERROR_INPUTERROR_TAPILOGLEVEL                            = -10002;
    //! ��������:TAPICommodityType
    const int TAPIERROR_INPUTERROR_TAPICommodityType                       = -10003;
    //! ��������:TAPICallOrPutFlagType
    const int TAPIERROR_INPUTERROR_TAPICallOrPutFlagType                   = -10004;
    //! ��������:TAPIBucketDateFlag
    const int TAPIERROR_INPUTERROR_TAPIBucketDateFlag                      = -11001;
    //! ��������:TAPIHisQuoteType
    const int TAPIERROR_INPUTERROR_TAPIHisQuoteType                        = -11002;
    //! ��������:TAPIAccountType
    const int TAPIERROR_INPUTERROR_TAPIAccountType                         = -12001;
    //! ��������:TAPIUserTypeType
    const int TAPIERROR_INPUTERROR_TAPIUserTypeType                        = -12002;
    //! ��������:TAPIAccountState
    const int TAPIERROR_INPUTERROR_TAPIAccountState                        = -12003;
    //! ��������:TAPIAccountFamilyType
    const int TAPIERROR_INPUTERROR_TAPIAccountFamilyType                   = -12004;
    //! ��������:TAPIOrderTypeType
    const int TAPIERROR_INPUTERROR_TAPIOrderTypeType                       = -12005;
    //! ��������:TAPIOrderSourceType
    const int TAPIERROR_INPUTERROR_TAPIOrderSourceType                     = -12006;
    //! ��������:TAPITimeInForceType
    const int TAPIERROR_INPUTERROR_TAPITimeInForceType                     = -12007;
    //! ��������:TAPISideType
    const int TAPIERROR_INPUTERROR_TAPISideType                            = -12008;
    //! ��������:TAPIPositionEffectType
    const int TAPIERROR_INPUTERROR_TAPIPositionEffectType                  = -12009;
    //! ��������:TAPIHedgeFlagType
    const int TAPIERROR_INPUTERROR_TAPIHedgeFlagType                       = -12010;
    //! ��������:TAPIOrderStateType
    const int TAPIERROR_INPUTERROR_TAPIOrderStateType                      = -12011;
    //! ��������:TAPICalculateModeType
    const int TAPIERROR_INPUTERROR_TAPICalculateModeType                   = -12012;
    //! ��������:TAPIMatchSourceType
    const int TAPIERROR_INPUTERROR_TAPIMatchSourceType                     = -12013;
    //! ��������:TAPIOpenCloseModeType
    const int TAPIERROR_INPUTERROR_TAPIOpenCloseModeType                   = -12014;
    //! ��������:TAPIFutureAlgType
    const int TAPIERROR_INPUTERROR_TAPIFutureAlgType                       = -12015;
    //! ��������:TAPIOptionAlgType
    const int TAPIERROR_INPUTERROR_TAPIOptionAlgType                       = -12016;
    //! ��������:TAPIBankAccountLWFlagType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountLWFlagType               = -12017;
    //! ��������:TAPIBankAccountStateType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountStateType                = -12018;
    //! ��������:TAPIBankAccountSwapStateType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountSwapStateType            = -12019;
    //! ��������:TAPIBankAccountTransferStateType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountTransferStateType        = -12020;
    //! ��������:TAPIMarginCalculateModeType
    const int TAPIERROR_INPUTERROR_TAPIMarginCalculateModeType             = -12021;
    //! ��������:TAPIOptionMarginCalculateModeType
    const int TAPIERROR_INPUTERROR_TAPIOptionMarginCalculateModeType       = -12022;
    //! ��������:TAPICmbDirectType
    const int TAPIERROR_INPUTERROR_TAPICmbDirectType                       = -12023;
    //! ��������:TAPIDeliveryModeType
    const int TAPIERROR_INPUTERROR_TAPIDeliveryModeType                    = -12024;
    //! ��������:TAPIContractTypeType
    const int TAPIERROR_INPUTERROR_TAPIContractTypeType                    = -12025;
    //! ��������:TAPIPartyTypeType
    const int TAPIERROR_INPUTERROR_TAPIPartyTypeType                       = -12026;
    //! ��������:TAPIPartyCertificateTypeType
    const int TAPIERROR_INPUTERROR_TAPIPartyCertificateTypeType            = -12027;
    //! ��������:TAPIMsgReceiverType
    const int TAPIERROR_INPUTERROR_TAPIMsgReceiverType                     = -12028;
    //! ��������:TAPIMsgTypeType
    const int TAPIERROR_INPUTERROR_TAPIMsgTypeType                         = -12029;
    //! ��������:TAPIMsgLevelType
    const int TAPIERROR_INPUTERROR_TAPIMsgLevelType                        = -12030;
    //! ��������:TAPITransferDirectType
    const int TAPIERROR_INPUTERROR_TAPITransferDirectType                  = -12031;
    //! ��������:TAPITransferStateType
    const int TAPIERROR_INPUTERROR_TAPITransferStateType                   = -12032;
    //! ��������:TAPITransferTypeType
    const int TAPIERROR_INPUTERROR_TAPITransferTypeType                    = -12033;
    //! ��������:TAPITransferDeviceIDType
    const int TAPIERROR_INPUTERROR_TAPITransferDeviceIDType                = -12034;
    //! ��������:TAPITacticsTypeType
    const int TAPIERROR_INPUTERROR_TAPITacticsTypeType                     = -12035;
    //! ��������:TAPIORDERACT
    const int TAPIERROR_INPUTERROR_TAPIORDERACT                            = -12036;
    //! ��������:TAPIBillTypeType
    const int TAPIERROR_INPUTERROR_TAPIBillTypeType                        = -12037;
    //! ��������:TAPIBillFileTypeType
    const int TAPIERROR_INPUTERROR_TAPIBillFileTypeType                    = -12038;
    //! ��������:TAPIOFFFlagType
    const int TAPIERROR_INPUTERROR_TAPIOFFFlagType                         = -12039;
    //! ��������:TAPICashAdjustTypeType
    const int TAPIERROR_INPUTERROR_TAPICashAdjustTypeType                  = -12040;
    //! ��������:TAPITriggerConditionType
    const int TAPIERROR_INPUTERROR_TAPITriggerConditionType                = -12041;
    //! ��������:TAPITriggerPriceTypeType
    const int TAPIERROR_INPUTERROR_TAPITriggerPriceTypeType                = -12042;
    //! ��������:TAPITradingStateType 
    const int TAPIERROR_INPUTERROR_TAPITradingStateType                    = -12043;
    //! ��������:TAPIMarketLevelType 
    const int TAPIERROR_INPUTERROR_TAPIMarketLevelType                     = -12044;
    //! ��������:TAPIOrderQryTypeType 
    const int TAPIERROR_INPUTERROR_TAPIOrderQryTypeType                    = -12045;

    //! ��ʷ�����ѯ�������Ϸ�
    const int TAPIERROR_INPUTERROR_QryHisQuoteParam                        = -13001;

    /** @}*/

    //=============================================================================
    /**
     *	\addtogroup G_ERR_DISCONNECT_REASON	����Ͽ�������붨��
     *	@{
     */
    //=============================================================================
    //! �����Ͽ�
    const int TAPIERROR_DISCONNECT_CLOSE_INIT                              = 1;
    //! �����Ͽ�
    const int TAPIERROR_DISCONNECT_CLOSE_PASS                              = 2;
    //! ������
    const int TAPIERROR_DISCONNECT_READ_ERROR                              = 3;
    //! д����
    const int TAPIERROR_DISCONNECT_WRITE_ERROR                             = 4;
    //! ��������
    const int TAPIERROR_DISCONNECT_BUF_FULL                                = 5;
    //! �첽��������
    const int TAPIERROR_DISCONNECT_IOCP_ERROR                              = 6;
    //! �������ݴ���
    const int TAPIERROR_DISCONNECT_PARSE_ERROR                             = 7;
    //! ���ӳ�ʱ
    const int TAPIERROR_DISCONNECT_CONNECT_TIMEOUT                         = 8;
    //! ��ʼ��ʧ��
    const int TAPIERROR_DISCONNECT_INIT_ERROR                              = 9;
    //! �Ѿ�����
    const int TAPIERROR_DISCONNECT_HAS_CONNECTED                           = 10;
    //! �����߳��ѽ���
    const int TAPIERROR_DISCONNECT_HAS_EXIT                                = 11;
    //! �������ڽ��У����Ժ�����
    const int TAPIERROR_DISCONNECT_TRY_LATER                               = 12;

    /** @}*/
}
#endif //! TAP_API_ERROR_H
