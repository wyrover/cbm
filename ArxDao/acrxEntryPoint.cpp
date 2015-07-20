#include "StdAfx.h"
#include "resource.h"
#include "DaoHelper.h"

// 定义注册服务名称
#ifndef ARXDAO_SERVICE_NAME
#define ARXDAO_SERVICE_NAME _T("ARXDAO_SERVICE_NAME")
#endif

//----- ObjectARX EntryPoint
class CArxDaoApp : public AcRxArxApp {

public:
	CArxDaoApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		acrxRegisterService( ARXDAO_SERVICE_NAME );
		acutPrintf( _T( "\nArxDao::On_kInitAppMsg\n" ) );

		//初始化数据库连接
		DaoHelper::ConfigureDao("localhost", "root", "", "cbm");

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		delete acrxServiceDictionary->remove( ARXDAO_SERVICE_NAME );

		acutPrintf( _T( "\nArxDao::On_kUnloadAppMsg\n" ) );
		//LOG_TRACE( _T( "ArxDao::On_kUnloadAppMsg" ) );

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kLoadDwgMsg( void* pkt )
	{
		AcRx::AppRetCode retCode = AcRxArxApp::On_kLoadDwgMsg ( pkt );

		acutPrintf( _T( "\nArxDao::On_kLoadDwgMsg\n" ) );

		return retCode;
	}

	virtual AcRx::AppRetCode On_kUnloadDwgMsg( void* pkt )
	{
		AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadDwgMsg( pkt ) ;

		acutPrintf( _T( "\nArxDao::On_kUnloadDwgMsg\n" ) );

		return retCode;
	}

	virtual void RegisterServerComponents () {
	}

	static void JL_TestDao()
	{
		DaoHelper::TestDao();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxDaoApp)

ACED_ARXCOMMAND_ENTRY_AUTO( CArxDaoApp, JL, _TestDao, TestDao, ACRX_CMD_TRANSPARENT, NULL )
