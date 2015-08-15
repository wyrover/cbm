#include "stdafx.h"
#include "PolicyDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PolicyDialog::PolicyDialog(BOOL bModal) : AcadSouiDialog(_T("layout:policy"), bModal)
{
}

PolicyDialog::~PolicyDialog()
{
}

void PolicyDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PolicyDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}

