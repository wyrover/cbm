#include "stdafx.h"
#include "WsGasPredictAdjDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

WsGasPredictAdjDialog::WsGasPredictAdjDialog(BOOL bModal) : AcadSouiDialog(_T("layout:ws_gas_predict_adj"), bModal)
{
}

WsGasPredictAdjDialog::~WsGasPredictAdjDialog()
{
}

void WsGasPredictAdjDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT WsGasPredictAdjDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_GasW0Edit = FindChildByName2<SEdit>(L"gas_W0");
	m_ThickEdit = FindChildByName2<SEdit>(L"thick");
	m_GasEtaEdit = FindChildByName2<SEdit>(L"gas_eta");
	m_GasWc2Edit = FindChildByName2<SEdit>(L"gas_Wc2");
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_Qr2Edit = FindChildByName2<SEdit>(L"qr2");
	return 0;
}


void WsGasPredictAdjDialog::OnSaveButtonClick()
{
}
