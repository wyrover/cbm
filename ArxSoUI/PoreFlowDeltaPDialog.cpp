#include "stdafx.h"
#include "PoreFlowDeltaPDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

#include <cmath>

PoreFlowDeltaPDialog::PoreFlowDeltaPDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow_delta_p"), bModal)
{
	pore_flow_id = 0;
}

PoreFlowDeltaPDialog::~PoreFlowDeltaPDialog()
{
}

void PoreFlowDeltaPDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreFlowDeltaPDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_PTestEdit = FindChildByName2<SEdit>(L"P_test");
	m_PCurEdit = FindChildByName2<SEdit>(L"P_cur");
	m_PTEdit = FindChildByName2<SEdit>(L"PT");
	m_DeltaPEdit = FindChildByName2<SEdit>(L"delta_p");

	initDatas();
	fillDatas();

	return 0;
}

void PoreFlowDeltaPDialog::OnSaveButtonClick()
{
	double P_cur = 0, P_test = 0;
	Utils::cstring_to_double((LPCTSTR)m_PTestEdit->GetWindowText(), P_test);
	Utils::cstring_to_double((LPCTSTR)m_PCurEdit->GetWindowText(), P_cur);

	double Pt = (P_cur + P_test) / 13.6;
	double delta_P = sqrt(Pt/760.0);
	//更新到界面
	m_PTEdit->SetWindowText(Utils::double_to_cstring(Pt));
	m_DeltaPEdit->SetWindowText(Utils::double_to_cstring(delta_P));

	PoreFlowPtr pore_flow = FIND_BY_ID(PoreFlow, pore_flow_id);
	if(pore_flow == 0) return;
	//保存到数据库
	pore_flow->p_test = P_test;
	pore_flow->p_cur = P_cur;
	pore_flow->pt = Pt;
	pore_flow->delta_p = delta_P;
	if(pore_flow->save())
	{
		SMessageBox(GetSafeHwnd(), _T("保存数据成功!!!"), _T("友情提示"), MB_OK);
		AcadSouiDialog::OnOK();
	}
	else
	{
		SMessageBox(GetSafeHwnd(), _T("保存数据失败!!!"), _T("友情提示"), MB_OK);
		AcadSouiDialog::OnCancel();
	}
}

void PoreFlowDeltaPDialog::initDatas()
{
	m_PTestEdit->SetWindowText(NULL);
	m_PCurEdit->SetWindowText(NULL);
	m_PTEdit->SetWindowText(NULL);
	m_DeltaPEdit->SetWindowText(NULL);
}

void PoreFlowDeltaPDialog::fillDatas()
{
	PoreFlowPtr pore_flow = FIND_BY_ID(PoreFlow, pore_flow_id);
	if(pore_flow == 0) return;

	m_PTestEdit->SetWindowText(Utils::double_to_cstring(pore_flow->p_test));
	m_PCurEdit->SetWindowText(Utils::double_to_cstring(pore_flow->p_cur));
	m_PTEdit->SetWindowText(Utils::double_to_cstring(pore_flow->pt));
	m_DeltaPEdit->SetWindowText(Utils::double_to_cstring(pore_flow->delta_p));
}
