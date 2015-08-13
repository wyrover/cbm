#include "stdafx.h"
#include "ReservesPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

ReservesPredictDialog::ReservesPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:reserves_predict"), bModal)
{
}

ReservesPredictDialog::~ReservesPredictDialog()
{
}

void ReservesPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT ReservesPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ReserveGasEdit = FindChildByName2<SEdit>(L"reserve_gas");
	m_ReserveW1Edit = FindChildByName2<SEdit>(L"reserve_w1");
	m_ReserveW2Edit = FindChildByName2<SEdit>(L"reserve_w2");
	m_ReserveW3Edit = FindChildByName2<SEdit>(L"reserve_w3");
	return 0;
}

