#include "stdafx.h"
#include "LoginDlg.h"
#include "RegDlg.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>

LoginDlg::LoginDlg(BOOL bModal) 
	: AcadSouiDialog(_T("layout:login"), bModal)
{
}

LoginDlg::~LoginDlg(void)
{
}

void LoginDlg::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//	//nID==6对应menu_test定义的菜单的exit项。
		//	PostMessage(WM_CLOSE);
		//}
		//else if(nID==54)
		//{
		//	//about SOUI
		//	STabCtrl *pTabCtrl = FindChildByName2<STabCtrl>(L"tab_main");
		//	if(pTabCtrl) pTabCtrl->SetCurSel(_T("about"));
		//}
	}
}

LRESULT LoginDlg::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	SetMsgHandled(FALSE);
	return 0;
}

void LoginDlg::OnLogin()
{
    CString user = FindChildByName2<SEdit>(L"username")->GetWindowText();
	CString pwd = FindChildByName2<SEdit>(L"password")->GetWindowText();
	int ret = DaoHelper::VerifyMineAccount(user, pwd);
	if(user.IsEmpty())
	{
		SMessageBox(m_hWnd,_T("请输入用户名!"),_T("友情提示"),MB_OK);
	}
	else if(pwd.IsEmpty())
	{
		SMessageBox(m_hWnd,_T("请输入密码!"),_T("友情提示"),MB_OK);
	}
	else if(ret == 0)
	{
		CString msg;
		msg.Format(_T("用户名:%s不存在,请注册!"), user);
		SMessageBox(m_hWnd,msg,_T("友情提示"),MB_OK);
	}
	else if(ret == 1)
	{
		SMessageBox(m_hWnd,_T("请输入正确的密码!"),_T("友情提示"),MB_OK);
	}
	else
	{
		SMessageBox(m_hWnd,_T("登录成功!"),_T("友情提示"),MB_OK);
		AcadSouiDialog::OnOK();
	}

    //pEdit->SetWindowText(_T("dlj"));
}

void LoginDlg::OnReg()
{
	RegDlg dlg(TRUE);
	dlg.Run(this->m_hWnd);
	//SMessageBox(m_hWnd,_T("注册矿井信息"),_T("测试"),MB_OK);
}
