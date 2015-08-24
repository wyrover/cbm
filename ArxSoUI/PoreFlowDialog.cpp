#include "stdafx.h"
#include "PoreFlowDialog.h"
#include "PoreFlowKDialog.h"
#include "PoreFlowDeltaPDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

#include <cmath>

PoreFlowDialog::PoreFlowDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_flow"), bModal)
{
	mine_id = 0;
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
	m_TEdit = FindChildByName2<SEdit>(L"t");

	initDatas();

	return 0;
}


void PoreFlowDialog::OnSaveButtonClick()
{
	PoreFlowPtr pore_flow = FIND_BY_ID(PoreFlow, pore_flow_id);
	if(pore_flow == 0) return;

	Utils::cstring_to_double((LPCTSTR)m_KEdit->GetWindowText(), pore_flow->k);
	Utils::cstring_to_double((LPCTSTR)m_BEdit->GetWindowText(), pore_flow->b);
	Utils::cstring_to_double((LPCTSTR)m_DeltaPEdit->GetWindowText(), pore_flow->delta_p);
	Utils::cstring_to_double((LPCTSTR)m_DeltaTEdit->GetWindowText(), pore_flow->delta_t);
	Utils::cstring_to_double((LPCTSTR)m_DhEdit->GetWindowText(), pore_flow->dh);
	Utils::cstring_to_double((LPCTSTR)m_XEdit->GetWindowText(), pore_flow->x);
	Utils::cstring_to_double((LPCTSTR)m_QHunEdit->GetWindowText(), pore_flow->q_hun);
	Utils::cstring_to_double((LPCTSTR)m_QChunEdit->GetWindowText(), pore_flow->q_chun);
	Utils::cstring_to_double((LPCTSTR)m_TEdit->GetWindowText(), pore_flow->t);

	//保存到数据库
	if(pore_flow->save())
	{
		SMessageBox(GetSafeWnd(), _T("保存数据成功!!!"), _T("友情提示"), MB_OK);
	}
	else
	{
		SMessageBox(GetSafeWnd(), _T("保存数据失败!!!"), _T("友情提示"), MB_OK);
	}
}

void PoreFlowDialog::OnKCaclButtonClick()
{
	PoreFlowKDialog dlg(TRUE);
	dlg.pore_flow_id = pore_flow_id;
	if(IDOK != dlg.Run(GetSafeWnd())) return;

	PoreFlowPtr pore_flow = FIND_BY_ID(PoreFlow, pore_flow_id);
	if(pore_flow == 0) return;

	//更新到界面
	m_KEdit->SetWindowText(Utils::double_to_cstring(pore_flow->k));
}

void PoreFlowDialog::OnBCaclButtonClick()
{
	double X = 0;
	Utils::cstring_to_double((LPCTSTR)m_XEdit->GetWindowText(), X);

	//计算b值
	double b = 1.0/sqrt(1-0.00446*X);
	//更新到界面
	m_BEdit->SetWindowText(Utils::double_to_cstring(b));
}

void PoreFlowDialog::OnDeltaPCaclButtonClick()
{
	PoreFlowDeltaPDialog dlg(TRUE);
	dlg.pore_flow_id = pore_flow_id;
	if(IDOK != dlg.Run(GetSafeWnd())) return;
}

void PoreFlowDialog::OnDeltaTCaclButtonClick()
{
	double t = 0;
	Utils::cstring_to_double((LPCTSTR)m_TEdit->GetWindowText(), t);
	double delta_T = 293.0/(273+t);
	//更新到界面
	m_DeltaTEdit->SetWindowText(Utils::double_to_cstring(delta_T));
}

void PoreFlowDialog::OnCaclButtonClick()
{
	//提取界面数据
	double K = 0, b = 0, delta_P = 0, delta_T = 0, dh = 0, X = 0;
	Utils::cstring_to_double((LPCTSTR)m_KEdit->GetWindowText(), K);
	Utils::cstring_to_double((LPCTSTR)m_BEdit->GetWindowText(), b);
	Utils::cstring_to_double((LPCTSTR)m_DeltaPEdit->GetWindowText(), delta_P);
	Utils::cstring_to_double((LPCTSTR)m_DeltaTEdit->GetWindowText(), delta_T);
	Utils::cstring_to_double((LPCTSTR)m_DhEdit->GetWindowText(), dh);
	Utils::cstring_to_double((LPCTSTR)m_XEdit->GetWindowText(), X);
	
	double Q_hun = K*b*sqrt(dh)*delta_P*delta_T;
	double Q_chun = Q_hun*X;

	//更新到界面
	m_QHunEdit->SetWindowText(Utils::double_to_cstring(Q_hun));
	m_QChunEdit->SetWindowText(Utils::double_to_cstring(Q_chun));
}

void PoreFlowDialog::OnDestroyWindow()
{
	if(pore_flow_id != 0)
	{
		PoreFlowPtr pore_flow = FIND_BY_ID(PoreFlow, pore_flow_id);
		if(pore_flow != 0)
		{
			pore_flow->remove();
		}
	}
	AcadSouiDialog::OnDestroyWindow();
}

void PoreFlowDialog::initDatas()
{
	m_KEdit->SetWindowText(NULL);
	m_BEdit->SetWindowText(NULL);
	m_DeltaPEdit->SetWindowText(NULL);
	m_DeltaTEdit->SetWindowText(NULL);
	m_DhEdit->SetWindowText(NULL);
	m_XEdit->SetWindowText(NULL);
	m_QHunEdit->SetWindowText(NULL);
	m_QChunEdit->SetWindowText(NULL);
	m_TEdit->SetWindowText(NULL);

	pore_flow_id = 0;
	PoreFlowPtr pore_flow(new PoreFlow);
	pore_flow->name = _T("");
	if(pore_flow->save())
	{
		pore_flow_id = pore_flow->getID();
	}
}
