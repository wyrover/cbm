#include "stdafx.h"
#include "LoginDialog.h"

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
	//do something
	m_UsernameEdit = FindChildByName2<SEdit>(L"username");
	m_PasswordEdit = FindChildByName2<SEdit>(L"password");
	return 0;
}


void LoginDialog::OnRegButtonClick()
{
}

void LoginDialog::OnLoginButtonClick()
{
}
