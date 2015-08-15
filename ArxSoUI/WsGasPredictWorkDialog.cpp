#include "stdafx.h"
#include "WsGasPredictWorkDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

WsGasPredictWorkDialog::WsGasPredictWorkDialog(BOOL bModal) : AcadSouiDialog(_T("layout:ws_gas_predict_work"), bModal)
{
}

WsGasPredictWorkDialog::~WsGasPredictWorkDialog()
{
}

void WsGasPredictWorkDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT WsGasPredictWorkDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ThickEdit = FindChildByName2<SEdit>(L"thick");
	m_K1Edit = FindChildByName2<SEdit>(L"K1");
	m_K2Edit = FindChildByName2<SEdit>(L"K2");
	m_K3Edit = FindChildByName2<SEdit>(L"K3");
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_GasW0Edit = FindChildByName2<SEdit>(L"gas_W0");
	m_GasWc2Edit = FindChildByName2<SEdit>(L"gas_Wc2");
	m_Qr1Edit = FindChildByName2<SEdit>(L"qr1");
	m_KfEdit = FindChildByName2<SEdit>(L"Kf");
	return 0;
}


void WsGasPredictWorkDialog::OnSaveButtonClick()
{
}

void WsGasPredictWorkDialog::OnK3CaclButtonClick()
{
}

void WsGasPredictWorkDialog::OnKfCaclButtonClick()
{
}
