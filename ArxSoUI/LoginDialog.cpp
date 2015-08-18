#include "stdafx.h"
#include "LoginDialog.h"
#include "RegDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

LoginDialog::LoginDialog(BOOL bModal) : AcadSouiDialog(_T("layout:login"), bModal)
{
}

LoginDialog::~LoginDialog()
{
}

void LoginDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT LoginDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);

	m_UsernameEdit = FindChildByName2<SEdit>(L"username");
	m_PasswordEdit = FindChildByName2<SEdit>(L"password");

	return 0;
}

void LoginDialog::OnRegButtonClick()
{
	RegDialog dlg(TRUE);
	dlg.Run(this->m_hWnd);
	//SMessageBox(m_hWnd,_T("注册矿井信息"),_T("测试"),MB_OK);
}

void LoginDialog::OnLoginButtonClick()
{
	CString user = m_UsernameEdit->GetWindowText();
	CString pwd = m_PasswordEdit->GetWindowText();

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
		int account_id = DaoHelper::GetOnlineAccountId();
		if(account_id == 0)
		{
			//设置当前登录用户
			SysInfoPtr sys_info(new SysInfo);
			sys_info->account = FIND_ONE(Account, FIELD(username), user);
			sys_info->save();
			SMessageBox(m_hWnd,_T("登录成功!"),_T("友情提示"),MB_OK);
			AcadSouiDialog::OnOK();
		}
		else
		{
			//根据id查找用户
			AccountPtr account = FIND_BY_ID(Account, account_id);
			if(account == 0)
			{
				SMessageBox(m_hWnd,_T("登录失败!"),_T("友情提示"),MB_OK);
			}
			else if(account->username == user)
			{
				SMessageBox(m_hWnd,_T("当前用户已登录!"),_T("友情提示"),MB_OK);
			}
			else
			{
				CString msg;
				msg.Format(_T("是否注销当前用户%s并切换到用户%s???"), account->username, user);
				if(IDYES == SMessageBox(m_hWnd,msg,_T("友情提示"),MB_YESNO))
				{
					//设置当前登录用户
					SysInfoPtr sys_info = FIND_FIRST(SysInfo);
					sys_info->account = FIND_ONE(Account, FIELD(username), user);
					sys_info->save();
					msg.Format(_T("成功切换到用户:%s"), user);
					SMessageBox(m_hWnd,msg,_T("友情提示"),MB_OK);
					AcadSouiDialog::OnOK();
				}
			}
		}
	}
}
