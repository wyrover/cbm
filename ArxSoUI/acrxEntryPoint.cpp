#include "StdAfx.h"
#include "resource.h"
#include "UIHelper.h"
#include "CmdHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Util/HelperClass.h>
//#include <ArxDao/Entity.h>
//using namespace cbm;

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
        LOG_TRACE( _T( "ArxSoUI::On_kInitAppMsg" ) );

        AfxEnableControlContainer();
        AfxInitRichEdit2();

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
        UIHelper::Logout();
        UIHelper::UnInitSouiEnviroment();

        return ( retCode ) ;
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg( void* pkt )
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg ( pkt );

        acutPrintf( _T( "\nArxSoUI::On_kLoadDwgMsg\n" ) );

		ArxDataTool::RegAppName( acdbHostApplicationServices()->workingDatabase(), _T("扩展数据") );

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

    static void JL_Login()
    {
        UIHelper::Login();
    }

    static void JL_Logout()
    {
        UIHelper::Logout();
    }

    static void JL_SampleManage()
    {
        UIHelper::SampleManage();
    }

    static void JL_GasTechModeDecision()
    {
        UIHelper::GasTechModeDecision();
    }

    static void JL_KeyParamCacl()
    {
        UIHelper::KeyParamCacl();
    }

    static void JL_PolicyHelp()
    {
        UIHelper::PolicyHelp();
    }

    static void JL_Main()
    {
        UIHelper::Main();
    }

	static void JL_DrawTunnel()
	{
		CmdHelper::DrawTunnel();
	}

	static void JL_TestTunnel()
	{
		CmdHelper::TestTunnel();
	}

	static void JL_DrawCoalSurf()
	{
		CmdHelper::DrawCoalSurf();
	}

	static void JL_TestCoalSurf()
	{
		CmdHelper::TestCoalSurf();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT( CArxSoUIApp )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _ShowModelessDemo, sd1, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _ShowModalDemo, sd2, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Login, login, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Logout, logout, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _SampleManage, sm, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _GasTechModeDecision, gtmd, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _KeyParamCacl, kpc, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _PolicyHelp, phelp, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Main, main, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawTunnel, tunnel, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _TestTunnel, tt, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawCoalSurf, coal, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _TestCoalSurf, tc, ACRX_CMD_TRANSPARENT, NULL )