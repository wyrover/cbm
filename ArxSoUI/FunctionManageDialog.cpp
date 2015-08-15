#include "stdafx.h"
#include "FunctionManageDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

FunctionManageDialog::FunctionManageDialog(BOOL bModal) : AcadSouiDialog(_T("layout:function_manage"), bModal)
{
}

FunctionManageDialog::~FunctionManageDialog()
{
}

void FunctionManageDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT FunctionManageDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}


void FunctionManageDialog::OnF1ButtonClick()
{
}

void FunctionManageDialog::OnF2ButtonClick()
{
}

void FunctionManageDialog::OnF3ButtonClick()
{
}
