#include "stdafx.h"
#include "PoreFlowDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PoreFlowDialog::PoreFlowDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow"), bModal)
{
}

PoreFlowDialog::~PoreFlowDialog()
{
}

void PoreFlowDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreFlowDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_KEdit = FindChildByName2<SEdit>(L"K");
	m_BEdit = FindChildByName2<SEdit>(L"b");
	m_DeltaPEdit = FindChildByName2<SEdit>(L"delta_p");
	m_DeltaTEdit = FindChildByName2<SEdit>(L"delta_t");
	m_DhEdit = FindChildByName2<SEdit>(L"dh");
	m_XEdit = FindChildByName2<SEdit>(L"X");
	m_QHunEdit = FindChildByName2<SEdit>(L"Q_hun");
	m_QChunEdit = FindChildByName2<SEdit>(L"Q_chun");
	return 0;
}


void PoreFlowDialog::OnSaveButtonClick()
{
}

void PoreFlowDialog::OnKCaclButtonClick()
{
}

void PoreFlowDialog::OnBCaclButtonClick()
{
}

void PoreFlowDialog::OnDeltaPCaclButtonClick()
{
}

void PoreFlowDialog::OnDeltaTCaclButtonClick()
{
}
