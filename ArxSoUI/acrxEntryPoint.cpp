#include "StdAfx.h"
#include "resource.h"
#include "CmdHelper.h"

#include <ArxHelper/HelperClass.h>

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

		//导入字段、字体、线型等数据
		CmdHelper::InitAllData();

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

        //关闭log4cplus日志系统
        log_uinit();

        return ( retCode ) ;
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg( void* pkt )
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg ( pkt );

        acutPrintf( _T( "\nArxSoUI::On_kLoadDwgMsg\n" ) );

        ArxDataTool::RegAppName( acdbHostApplicationServices()->workingDatabase(), _T( "扩展数据" ) );

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

	static void JL_xxx()
	{
		//UIHelper::testdlg();
		CmdHelper::xxx();
	}

	static void JL_PostJsonDatas()
	{
		CmdHelper::PostJsonDatasToRpc();
	}

	static void JL_DrawOccurrenceGraph()
	{
		CmdHelper::DrawOccurrenceGraph();
	}

	static void JL_DrawPlaneGraph11()
	{
		CmdHelper::DrawPlaneGraph11();
	}

	static void JL_DrawHeadGraph11()
	{
		CmdHelper::DrawHeadGraph11();
	}

	static void JL_DrawDipGraph11()
	{
		CmdHelper::DrawDipGraph11();
	}

	static void JL_DrawPlaneGraph12()
	{
		CmdHelper::DrawPlaneGraph12();
	}

	static void JL_DrawHeadGraph12()
	{
		CmdHelper::DrawHeadGraph12();
	}

	static void JL_DrawDipGraph12()
	{
		CmdHelper::DrawDipGraph12();
	}

	static void JL_DrawPlaneGraph21()
	{
		CmdHelper::DrawPlaneGraph21();
	}

	static void JL_DrawHeadGraph21()
	{
		CmdHelper::DrawHeadGraph21();
	}

	static void JL_DrawDipGraph21()
	{
		CmdHelper::DrawDipGraph21();
	}

	static void JL_DrawPlaneGraph23()
	{
		CmdHelper::DrawPlaneGraph23();
	}

	static void JL_DrawHeadGraph23()
	{
		CmdHelper::DrawHeadGraph23();
	}

	static void JL_DrawDipGraph23()
	{
		CmdHelper::DrawDipGraph23();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT( CArxSoUIApp )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _xxx, xxx, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _PostJsonDatas, PostJsonDatas, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawOccurrenceGraph, DrawOccurrenceGraph, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawPlaneGraph11, DrawPlaneGraph11, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawHeadGraph11, DrawHeadGraph11, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawDipGraph11, DrawDipGraph11, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawPlaneGraph12, DrawPlaneGraph12, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawHeadGraph12, DrawHeadGraph12, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawDipGraph12, DrawDipGraph12, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawPlaneGraph21, DrawPlaneGraph21, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawHeadGraph21, DrawHeadGraph21, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawDipGraph21, DrawDipGraph21, ACRX_CMD_TRANSPARENT, NULL )

ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawPlaneGraph23, DrawPlaneGraph23, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawHeadGraph23, DrawHeadGraph23, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _DrawDipGraph23, DrawDipGraph23, ACRX_CMD_TRANSPARENT, NULL )
