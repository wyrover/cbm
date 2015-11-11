#include "StdAfx.h"
#include "resource.h"
#include "UIHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Util/HelperClass.h>
//#include <Dao/DaoHelper.h>

// 定义注册服务名称
#ifndef ARX_SOUI_SERVICE_NAME
#define ARX_SOUI_SERVICE_NAME _T("ARXSOUI_SERVICE_NAME")
#endif

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CArxSoUIApp : public AcRxArxApp
{

public:
    CArxSoUIApp () : AcRxArxApp () {}

    virtual AcRx::AppRetCode On_kInitAppMsg ( void* pkt )
    {
        // TODO: Load dependencies here

        // You *must* call On_kInitAppMsg here
        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg ( pkt ) ;

        acrxRegisterService( ARX_SOUI_SERVICE_NAME );

        acutPrintf( _T( "\nArxSoUI::On_kInitAppMsg\n" ) );

        AfxEnableControlContainer();
        AfxInitRichEdit2();

        //初始化log4cplus日志系统
        //为了保证日志功能正常使用，在加载所有模块之前初始化日志系统
        log_init( _T( ".\\log\\log4cplus.properties" ) );

        LOG_TRACE( _T( "ArxSoUI::On_kInitAppMsg" ) );

        //初始化数据库连接
        CString iniFile = ArxUtilHelper::BuildPath( ArxUtilHelper::GetAppPathDir( _hdllInstance ), _T( "config.ini" ) );
        //if( !DaoHelper::ConfigureFromFile( iniFile ) )
        //{
        //    AfxMessageBox( _T( "连接MySQL数据库失败，请联系技术人员!!!" ) );
        //    return AcRx::kRetError;
        //}
        //初始化示范矿区数据
        //DaoHelper::InitSampleRegion();
        //初始化soui环境
        UIHelper::InitSouiEnviroment();

        return ( retCode ) ;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg ( void* pkt )
    {
        // TODO: Add your code here

        // You *must* call On_kUnloadAppMsg here
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg ( pkt ) ;

        delete acrxServiceDictionary->remove( ARX_SOUI_SERVICE_NAME );

        acutPrintf( _T( "\nArxSoUI::On_kUnloadAppMsg\n" ) );
        LOG_TRACE( _T( "ArxSoUI::On_kUnloadAppMsg" ) );

        //退出登录状态
        //UIHelper::Logout();
        //退出soui环境
        UIHelper::UnInitSouiEnviroment();
        //关闭log4cplus日志系统
        log_uinit();

        return ( retCode ) ;
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg( void* pkt )
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg ( pkt );

        acutPrintf( _T( "\nArxSoUI::On_kLoadDwgMsg\n" ) );

        ArxDataTool::RegAppName( acdbHostApplicationServices()->workingDatabase(), _T( "扩展数据" ) );

        //初始化数据字段
        UIHelper::InitAllData();

        return retCode;
    }

    virtual AcRx::AppRetCode On_kUnloadDwgMsg( void* pkt )
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadDwgMsg( pkt ) ;

        acutPrintf( _T( "\nArxSoUI::On_kUnloadDwgMsg\n" ) );

        return retCode;
    }

    virtual void RegisterServerComponents ()
    {
    }

    static void JL_ShowModelessDemo()
    {
        UIHelper::ShowModelessDemo();
    }

    static void JL_ShowModalDemo()
    {
        UIHelper::ShowModalDemo();
    }

    static void JL_TestPicViewer()
    {
        UIHelper::TestPicViewer();
    }

    static void JL_TestRtfViewer()
    {
        UIHelper::TestRtfViewer();
    }

    static void JL_Login()
    {
        UIHelper::Login();
    }

    static void JL_RegMine()
    {
        UIHelper::RegMine();
    }

    static void JL_Logout()
    {
        UIHelper::Logout();
    }

    static void JL_SampleManage()
    {
        UIHelper::SampleManage();
    }

    static void JL_MineDesign()
    {
        UIHelper::MineDesign();
    }

    static void JL_GasTechModeDecision()
    {
        UIHelper::GasTechModeDecision();
    }

    static void JL_KeyParamCacl()
    {
        UIHelper::KeyParamCacl();
    }

    static void JL_KP1()
    {
        UIHelper::KP1();
    }

    static void JL_KP2()
    {
        UIHelper::KP2();
    }

    static void JL_KP3()
    {
        UIHelper::KP3();
    }

    static void JL_KP4()
    {
        UIHelper::KP4();
    }

    static void JL_KP5()
    {
        UIHelper::KP5();
    }

    static void JL_KP6()
    {
        UIHelper::KP6();
    }

    static void JL_KP7()
    {
        UIHelper::KP7();
    }

    static void JL_KP8()
    {
        UIHelper::KP8();
    }

    static void JL_KP9()
    {
        UIHelper::KP9();
    }

    static void JL_KP10()
    {
        UIHelper::KP10();
    }

    static void JL_KP11()
    {
        UIHelper::KP11();
    }

    static void JL_GasDesign()
    {
        UIHelper::GasDesign();
    }

    static void JL_PolicyHelp()
    {
        UIHelper::PolicyHelp();
    }

    static void JL_Main()
    {
        UIHelper::Main();
    }

	static void JL_xxx()
	{
		//UIHelper::testdlg();
		UIHelper::xxx();
	}

	static void JL_PostJsonDatas()
	{
		UIHelper::PostJsonDatasToRpc();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT( CArxSoUIApp )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _ShowModelessDemo, sd1, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _ShowModalDemo, sd2, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _TestPicViewer, tpv, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _TestRtfViewer, trv, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Login, login, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _RegMine, regMine, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Logout, logout, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _SampleManage, sm, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _MineDesign, mineDesign, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _GasTechModeDecision, gtmd, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KeyParamCacl, kpc, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP1, kp1, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP2, kp2, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP3, kp3, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP4, kp4, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP5, kp5, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP6, kp6, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP7, kp7, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP8, kp8, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP9, kp9, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP10, kp10, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KP11, kp11, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _GasDesign, gasDesign, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _PolicyHelp, phelp, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Main, main, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _xxx, xxx, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _PostJsonDatas, PostJsonDatas, ACRX_CMD_TRANSPARENT, NULL )
