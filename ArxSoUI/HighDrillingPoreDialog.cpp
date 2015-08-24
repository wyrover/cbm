#include "stdafx.h"
#include "HighDrillingPoreDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

#include <cmath>
#define PI 3.1415926535897932384626433832795

HighDrillingPoreDialog::HighDrillingPoreDialog(BOOL bModal) : AcadSouiDialog(_T("layout:high_drilling_pore"), bModal)
{
	ws_id = 0;
	Lg = 0.0;
}

HighDrillingPoreDialog::~HighDrillingPoreDialog()
{
}

void HighDrillingPoreDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT HighDrillingPoreDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_LkEdit = FindChildByName2<SEdit>(L"Lk");
	m_LcEdit = FindChildByName2<SEdit>(L"Lc");
	m_LwEdit = FindChildByName2<SEdit>(L"Lw");
	m_N2Edit = FindChildByName2<SEdit>(L"n2");
	m_BetaEdit = FindChildByName2<SEdit>(L"beta");
	m_LdEdit = FindChildByName2<SEdit>(L"Ld");
	m_N1Edit = FindChildByName2<SEdit>(L"n1");

	initDatas();
	fillDatas();

	return 0;
}


void HighDrillingPoreDialog::OnSaveButtonClick()
{
	WorkSurfPtr work_surf = FIND_BY_ID(WorkSurf, ws_id);
	if(work_surf == 0) return;

	HighDrillingPoreParamPtr hdpp = FIND_ONE(HighDrillingPoreParam, FKEY(WorkSurf), work_surf->getStringID());
	if(hdpp == 0)
	{
		hdpp.reset(new HighDrillingPoreParam);
		hdpp->work_surf = work_surf;
	}

	Utils::cstring_to_double((LPCTSTR)m_LkEdit->GetWindowText(), hdpp->lk);
	Utils::cstring_to_double((LPCTSTR)m_LcEdit->GetWindowText(), hdpp->lc);
	Utils::cstring_to_double((LPCTSTR)m_LwEdit->GetWindowText(), hdpp->lw);
	Utils::cstring_to_double((LPCTSTR)m_BetaEdit->GetWindowText(), hdpp->lk);
	Utils::cstring_to_double((LPCTSTR)m_LdEdit->GetWindowText(), hdpp->ld);
	Utils::cstring_to_int((LPCTSTR)m_N1Edit->GetWindowText(), hdpp->n1);
	Utils::cstring_to_int((LPCTSTR)m_N2Edit->GetWindowText(), hdpp->n2);
	//保存到数据库
	if(hdpp->save())
	{
		SMessageBox(GetSafeWnd(), _T("保存数据成功!!!"), _T("友情提示"), MB_OK);
		AcadSouiDialog::OnOK();
	}
	else
	{
		SMessageBox(GetSafeWnd(), _T("保存数据失败!!!"), _T("友情提示"), MB_OK);
		AcadSouiDialog::OnCancel();
	}
}

void HighDrillingPoreDialog::OnCaclButtonClick()
{
	//从界面提取数据
	double Lc = 0, Ld = 0;
	Utils::cstring_to_double((LPCTSTR)m_LcEdit->GetWindowText(), Lc);
	Utils::cstring_to_double((LPCTSTR)m_LdEdit->GetWindowText(), Ld);

	//计算
	double Lk = Lc + Lg;
	double beta = atan(Ld/Lc)*180/PI;

	//更新到界面
	m_LkEdit->SetWindowText(Utils::double_to_cstring(Lk));
	m_BetaEdit->SetWindowText(Utils::double_to_cstring(beta));
}

void HighDrillingPoreDialog::initDatas()
{
	m_LkEdit->SetWindowText(NULL);
	m_LcEdit->SetWindowText(NULL);
	m_LwEdit->SetWindowText(NULL);
	m_N2Edit->SetWindowText(NULL);
	m_BetaEdit->SetWindowText(NULL);
	m_LdEdit->SetWindowText(NULL);
	m_N1Edit->SetWindowText(NULL);
}

void HighDrillingPoreDialog::fillDatas()
{
	WorkSurfPtr work_surf = FIND_BY_ID(WorkSurf, ws_id);
	if(work_surf == 0) return;

	HighDrillingPoreParamPtr hdpp = FIND_ONE(HighDrillingPoreParam, FKEY(WorkSurf), work_surf->getStringID());
	if(hdpp == 0) return;

	m_LkEdit->SetWindowText(Utils::double_to_cstring(hdpp->lk));
	m_LcEdit->SetWindowText(Utils::double_to_cstring(hdpp->lc));
	m_LwEdit->SetWindowText(Utils::double_to_cstring(hdpp->lw));
	m_BetaEdit->SetWindowText(Utils::double_to_cstring(hdpp->beta));
	m_LdEdit->SetWindowText(Utils::double_to_cstring(hdpp->ld));
	m_N1Edit->SetWindowText(Utils::int_to_cstring(hdpp->n1));
	m_N2Edit->SetWindowText(Utils::int_to_cstring(hdpp->n2));
}
