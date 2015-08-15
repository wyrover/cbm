#include "stdafx.h"
#include "WsGasPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

WsGasPredictDialog::WsGasPredictDialog(BOOL bModal) : AcadSouiDialog(_T("layout:ws_gas_predict"), bModal)
{
}

WsGasPredictDialog::~WsGasPredictDialog()
{
}

void WsGasPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT WsGasPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_Qr1Edit = FindChildByName2<SEdit>(L"qr1");
	m_Qr2Edit = FindChildByName2<SEdit>(L"qr2");
	m_QrEdit = FindChildByName2<SEdit>(L"qr");
	m_Radio68 = FindChildByName2<SRadioBox>(L"radio68");
	m_Radio69 = FindChildByName2<SRadioBox>(L"radio69");
	return 0;
}


void WsGasPredictDialog::OnWorkCaclButtonClick()
{
}

void WsGasPredictDialog::OnAdjCaclButtonClick()
{
}

void WsGasPredictDialog::OnSaveButtonClick()
{
}
