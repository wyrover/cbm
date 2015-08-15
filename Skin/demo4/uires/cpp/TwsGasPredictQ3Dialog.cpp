#include "stdafx.h"
#include "TwsGasPredictQ3Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

TwsGasPredictQ3Dialog::TwsGasPredictQ3Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:tws_gas_predict_q3"), bModal)
{
}

TwsGasPredictQ3Dialog::~TwsGasPredictQ3Dialog()
{
}

void TwsGasPredictQ3Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT TwsGasPredictQ3Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_Q0Edit = FindChildByName2<SEdit>(L"q0");
	m_DEdit = FindChildByName2<SEdit>(L"D");
	m_VEdit = FindChildByName2<SEdit>(L"V");
	m_LEdit = FindChildByName2<SEdit>(L"L");
	m_TwQ3Edit = FindChildByName2<SEdit>(L"tw_q3");
	m_VrEdit = FindChildByName2<SEdit>(L"Vr");
	m_GasW0Edit = FindChildByName2<SEdit>(L"gas_W0");
	return 0;
}


void TwsGasPredictQ3Dialog::OnSaveButtonClick()
{
}
