#include "StdAfx.h"
#include "UIHelper.h"

#include "../ArxHelper/HelperClass.h"
#include "../MineGE/HelperClass.h"
#include "../Util/HelperClass.h"

#include "MySoUiLoader.h"
#include "LoginDlg.h"

void UIHelper::InitSouiEnviroment()
{
	LOG_TRACE( _T( "初始化soui环境..." ) );
	new MySoUiLoader(_hdllInstance);
	SoUILoader::getSingletonPtr()->init();
}

void UIHelper::UnInitSouiEnviroment()
{
	LOG_TRACE( _T( "退出soui环境..." ) );
	delete SoUILoader::getSingletonPtr();
}

void UIHelper::ShowSoUIDlg1()
{
	// 切换资源
	CAcModuleResourceOverride myResources;

	LOG_TRACE(_T("启动新的soui非模态对话框"));
	LoginDlg* dlg = new LoginDlg(FALSE);
	dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
}

void UIHelper::ShowSoUIDlg2()
{
	CAcModuleResourceOverride myResources;

	LOG_TRACE(_T("启动新的soui模态对话框"));
	LoginDlg dlg(TRUE);
	dlg.Run(acedGetAcadFrame()->GetSafeHwnd());
}