#include "stdafx.h"
#include "GasDesignQuestionDialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

GasDesignQuestionDialog::GasDesignQuestionDialog(BOOL bModal) : AcadSouiDialog(_T("layout:gas_design_question"), bModal)
{
	region = 0;
	tech = 0;
}

GasDesignQuestionDialog::~GasDesignQuestionDialog()
{
}

void GasDesignQuestionDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT GasDesignQuestionDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TechnologyListbox = FindChildByName2<SListBox>(L"technology");

	m_TechnologyListbox->DeleteAll();
	//掘进抽采设计
	if(region == 1)
	{
		m_TechnologyListbox->AddString(_T("底板岩巷密集穿层钻孔抽采煤巷条带瓦斯"));
		m_TechnologyListbox->AddString(_T("顺层钻孔条带掩护巷道掘进抽采法"));
		m_TechnologyListbox->AddString(_T("单巷、双巷或多巷循环迈步式抽采技术"));
	}
	//回采面抽采设计
	else if(region == 2)
	{
		m_TechnologyListbox->AddString(_T("底板岩巷大面积穿层钻孔抽采工作面瓦斯"));
		m_TechnologyListbox->AddString(_T("顺层钻孔递进式掩护抽采工作面瓦斯法"));
		m_TechnologyListbox->AddString(_T("顺层平行钻孔抽采工作面瓦斯"));
		m_TechnologyListbox->AddString(_T("顺层交叉钻孔抽采工作面瓦斯"));
		m_TechnologyListbox->AddString(_T("千米钻机定向长钻孔抽采法"));

	}
	//采空区抽采设计
	else
	{
		m_TechnologyListbox->AddString(_T("高抽巷卸压瓦斯抽采法"));
		m_TechnologyListbox->AddString(_T("顶板高位走向钻孔瓦斯抽采法"));
		m_TechnologyListbox->AddString(_T("沿空留巷穿层钻孔抽采"));
		m_TechnologyListbox->AddString(_T("采空区埋管瓦斯抽采方法"));
	}
	m_TechnologyListbox->SetCurSel(0);

	return 0;
}


void GasDesignQuestionDialog::OnTechnologyListboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventLBSelChanged* pEvtOfLB = (EventLBSelChanged*)pEvt;
	if(pEvtOfLB == 0) return;
	int nCurSel = pEvtOfLB->nNewSel;
	if(nCurSel == -1) return;

	// do something
}

void GasDesignQuestionDialog::OnGoButtonClick()
{
	if(m_TechnologyListbox->GetCurSel() == -1)
	{
		SMessageBox( GetSafeHwnd(), _T( "请选择一项抽采技术进行设计!" ), _T( "友情提示" ), MB_OK );
	}
	else
	{
		//返回用户选择
		tech = m_TechnologyListbox->GetCurSel()+1;
		AcadSouiDialog::OnOK();
	}
}
