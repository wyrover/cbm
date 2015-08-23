#include "StdAfx.h"
#include "UIHelper.h"

#include <ArxHelper/HelperClass.h>
#include <MineGE/HelperClass.h>
#include <Util/HelperClass.h>

#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

#include "MySoUiLoader.h"
#include "DemoDialog.h"
#include "LoginDialog.h"
#include "SampleManageDialog.h"
#include "MineDialog.h"
#include "KeyParamDialog.h"
#include "PolicyDialog.h"
using namespace SOUI;

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

void UIHelper::ShowModelessDemo()
{
	// 切换资源
	CAcModuleResourceOverride myResources;

	LOG_TRACE(_T("启动soui非模态对话框"));
	DemoDialog* dlg = new DemoDialog(FALSE);
	dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
}

void UIHelper::ShowModalDemo()
{
	CAcModuleResourceOverride myResources;

	LOG_TRACE(_T("启动soui模态对话框"));
	DemoDialog dlg(TRUE);
	dlg.Run(acedGetAcadFrame()->GetSafeHwnd());
}

void UIHelper::Login()
{
	CAcModuleResourceOverride myResources;

	LoginDialog dlg(TRUE);
	dlg.Run(acedGetAcadFrame()->GetSafeHwnd());
}

void UIHelper::Logout()
{
	//清空cbm_sys_info表
	RecordPtrListPtr lists = FIND_ALL(SysInfo);
	if(lists == 0) return;

	for(int i=0;i<lists->size();i++)
	{
		lists->at(i)->remove();
	}
}

void UIHelper::SampleManage()
{
	CAcModuleResourceOverride myResources;

	SampleManageDialog* dlg = new SampleManageDialog(FALSE);
	dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
}

void UIHelper::GasTechModeDecision()
{
	int account_id = DaoHelper::GetOnlineAccountId();
	if(account_id == 0)
	{
		SMessageBox(acedGetAcadFrame()->GetSafeHwnd(),_T("请登录!"),_T("友情提示"),MB_OK);
		//调用登录函数
		UIHelper::Login();
	}
	else
	{
		CAcModuleResourceOverride myResources;

		MineDialog* dlg = new MineDialog(FALSE);
		dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
	}
}

void UIHelper::KeyParamCacl()
{
	int account_id = DaoHelper::GetOnlineAccountId();
	if(account_id == 0)
	{
		SMessageBox(acedGetAcadFrame()->GetSafeHwnd(),_T("请登录!"),_T("友情提示"),MB_OK);
		//调用登录函数
		UIHelper::Login();
	}
	else
	{
		CAcModuleResourceOverride myResources;

		KeyParamDialog* dlg = new KeyParamDialog(FALSE);
		dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
	}
}

void UIHelper::PolicyHelp()
{
	CAcModuleResourceOverride myResources;

	PolicyDialog* dlg = new PolicyDialog(FALSE);
	dlg->Run(acedGetAcadFrame()->GetSafeHwnd());
}
