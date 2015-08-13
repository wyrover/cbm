#include "stdafx.h"
#include "DrainageDifficultEvalDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DrainageDifficultEvalDialog::DrainageDifficultEvalDialog(BOOL bModal) : AcadSouiDialog(_T("layout:drainage_difficult_eval"), bModal)
{
}

DrainageDifficultEvalDialog::~DrainageDifficultEvalDialog()
{
}

void DrainageDifficultEvalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DrainageDifficultEvalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}

