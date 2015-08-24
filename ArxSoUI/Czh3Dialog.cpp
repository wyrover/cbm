#include "stdafx.h"
#include "Czh3Dialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

Czh3Dialog::Czh3Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_3"), bModal)
{
	coal_id = 0;
}

Czh3Dialog::~Czh3Dialog()
{
}

void Czh3Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh3Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_RockCombox = FindChildByName2<SComboBox>(L"rock");
	m_HwSumEdit = FindChildByName2<SEdit>(L"hw_sum");
	m_ToleranceEdit = FindChildByName2<SEdit>(L"tolerance");
	m_CavingZoneHeightEdit = FindChildByName2<SEdit>(L"caving_zone_height");

	initDatas();

	return 0;
}


void Czh3Dialog::OnSaveButtonClick()
{
	int nCurSel = SComboBoxHelper::GetCurSel(m_RockCombox);
	if(nCurSel == -1)
	{
		SMessageBox(GetSafeWnd(),_T("请选择\"顶板覆岩岩性!!!\""),_T("友情提示"),MB_YESNO);
		return;
	}

	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	//读取数据
	Utils::cstring_to_double((LPCTSTR)m_HwSumEdit->GetWindowText(), coal->hw_sum);

	//计算
	double M = coal->hw_sum;
	double Hm = 0, tol = 0;
	if(nCurSel == 0)
	{
		Hm = 100*M/(2.1*M+16);
		tol = 2.5;
	}
	else if(nCurSel == 1)
	{
		Hm = 100*M/(4.7*M+19);
		tol = 2.2;
	}
	else if(nCurSel == 2)
	{
		Hm = 100*M/(6.2*M+32);
		tol = 1.5;
	}
	else if(nCurSel == 3)
	{
		Hm = 100*M/(7.0*M+63);
		tol = 1.2;
	}
	
	//更新到界面
	m_ToleranceEdit->SetWindowText(Utils::double_to_cstring(tol));
	m_CavingZoneHeightEdit->SetWindowText(Utils::double_to_cstring(Hm));

	//保存到数据库
	coal->hw_sum = M;
	coal->czh = Hm;
	coal->rock = nCurSel+1;
	coal->save();
	//AcadSouiDialog::OnOK();
}

void Czh3Dialog::OnRockComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void Czh3Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	m_HwSumEdit->SetWindowText(Utils::double_to_cstring(coal->hw_sum));
	m_ToleranceEdit->SetWindowText(NULL);
	m_CavingZoneHeightEdit->SetWindowText(NULL);
}
