#include "stdafx.h"
#include "MineGasReservesPredictInputDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasReservesPredictInputDialog::MineGasReservesPredictInputDialog(BOOL bModal) : AcadSouiDialog(_T("layout:mine_gas_reserves_predict_input"), bModal)
{
}

MineGasReservesPredictInputDialog::~MineGasReservesPredictInputDialog()
{
}

void MineGasReservesPredictInputDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT MineGasReservesPredictInputDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_ResA1Edit = FindChildByName2<SEdit>(L"res_A1");
	m_GasX1Edit = FindChildByName2<SEdit>(L"gas_X1");
	m_CoalCombox = FindChildByName2<SComboBox>(L"coal");
	return 0;
}


void MineGasReservesPredictInputDialog::OnCoalComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void MineGasReservesPredictInputDialog::OnSaveButtonClick()
{
}
