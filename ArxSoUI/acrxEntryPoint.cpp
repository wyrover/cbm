#include "StdAfx.h"
#include "resource.h"
#include "UIHelper.h"

#include <ArxHelper/HelperClass.h>
#include <Util/HelperClass.h>
#include <ArxDao/Entity.h>
using namespace cbm;

// 定义注册服务名称
#ifndef ARX_SOUI_SERVICE_NAME
#define ARX_SOUI_SERVICE_NAME _T("ARXSOUI_SERVICE_NAME")
#endif

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CArxSoUIApp : public AcRxArxApp {

public:
	CArxSoUIApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		acrxRegisterService( ARX_SOUI_SERVICE_NAME );

		acutPrintf( _T( "\nArxSoUI::On_kInitAppMsg\n" ) );
		LOG_TRACE( _T( "ArxSoUI::On_kInitAppMsg" ) );

		AfxEnableControlContainer();
		AfxInitRichEdit2();

		UIHelper::InitSouiEnviroment();

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		delete acrxServiceDictionary->remove( ARX_SOUI_SERVICE_NAME );

		acutPrintf( _T( "\nArxSoUI::On_kUnloadAppMsg\n" ) );
		LOG_TRACE( _T( "ArxSoUI::On_kUnloadAppMsg" ) );

		//UIHelper::DestroyTestDockBar();
		UIHelper::UnInitSouiEnviroment();

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kLoadDwgMsg( void* pkt )
	{
		AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg ( pkt );

		acutPrintf( _T( "\nArxSoUI::On_kLoadDwgMsg\n" ) );

		return retCode;
	}

	virtual AcRx::AppRetCode On_kUnloadDwgMsg( void* pkt )
	{
		AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadDwgMsg( pkt ) ;

		acutPrintf( _T( "\nArxSoUI::On_kUnloadDwgMsg\n" ) );

		return retCode;
	}

	virtual void RegisterServerComponents () {
	}

	static void JL_ShowSouiModeless()
	{
		UIHelper::ShowSoUIModeless();
	}

	static void JL_ShowSoUIModal()
	{
		UIHelper::ShowSoUIModal();
	}

	static void JL_Login()
	{
		UIHelper::Login();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxSoUIApp)
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _ShowSouiModeless, sm1, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _ShowSoUIModal, sm2, ACRX_CMD_TRANSPARENT, NULL )
ACED_ARXCOMMAND_ENTRY_AUTO( CArxSoUIApp, JL, _Login, login, ACRX_CMD_TRANSPARENT, NULL )
