#include "stdafx.h"
#include "Czh4Dialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

Czh4Dialog::Czh4Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_4"), bModal)
{
}

Czh4Dialog::~Czh4Dialog()
{
}

void Czh4Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh4Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_HEdit = FindChildByName2<SEdit>(L"h");
	m_CavingZoneHeightEdit = FindChildByName2<SEdit>(L"caving_zone_height");
	m_ToleranceEdit = FindChildByName2<SEdit>(L"tolerance");

	initDatas();

	return 0;
}


void Czh4Dialog::OnSaveButtonClick()
{
	int nCurSel = SComboBoxHelper::GetCurSel(m_RockCombox);
	if(nCurSel == -1)
	{
		SMessageBox(GetSafeWnd(),_T("请选择\"顶板覆岩岩性!!!\""),_T("友情提示"),MB_YESNO);
		return;
	}

	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	double M = 0, h = 0;
	//读取数据
	Utils::cstring_to_double((LPCTSTR)m_HwEdit->GetWindowText(), M);
	Utils::cstring_to_double((LPCTSTR)m_HEdit->GetWindowText(), h);

	//计算
	double Hm = 0, tol = 0;
	if(nCurSel == 0)
	{
		Hm = 100*M*h/(1.1*h+133);
		tol = 8.4;
	}
	else
	{
		Hm = 100*M/(7.5*M+293);
		tol = 7.3;
	}
	//Hm计算的是导水裂缝带的高度,按照公式还得乘以一个系数(0.4~0.5)，取0.5
	Hm = 0.5*Hm;

	//更新到界面
	m_ToleranceEdit->SetWindowText(Utils::double_to_cstring(tol));
	m_CavingZoneHeightEdit->SetWindowText(Utils::double_to_cstring(Hm));

	//保存到数据库
	coal->hhh = h;
	coal->hw = M;
	coal->czh = Hm;
	coal->rock = nCurSel+1;
	coal->save();
	//AcadSouiDialog::OnOK();
}

void Czh4Dialog::OnRockComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
}

void Czh4Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	m_HEdit->SetWindowText(Utils::double_to_cstring(coal->hhh));
	m_HwEdit->SetWindowText(Utils::double_to_cstring(coal->hw));
	m_CavingZoneHeightEdit->SetWindowText(NULL);
	m_ToleranceEdit->SetWindowText(NULL);
	m_RockCombox->SetCurSel(coal->rock-1);
}
