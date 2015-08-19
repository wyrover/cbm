#include "stdafx.h"
#include "TechModeDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

struct ItemData
{
	int id;
	int nItem;
};

TechModeDialog::TechModeDialog(BOOL bModal) : AcadSouiDialog(_T("layout:tech_mode"), bModal)
{
}

TechModeDialog::~TechModeDialog()
{
}

void TechModeDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT TechModeDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TechModeCombox = FindChildByName2<SComboBox>(L"tech_mode");
	m_C2YesRadio = FindChildByName2<SRadioBox>(L"c2_yes");
	m_C2NoRadio = FindChildByName2<SRadioBox>(L"c2_no");
	m_C3YesRadio = FindChildByName2<SRadioBox>(L"c3_yes");
	m_C3NoRadio = FindChildByName2<SRadioBox>(L"c3_no");
	m_RegionLabel = FindChildByName2<SStatic>(L"region");
	m_C1YesRadio = FindChildByName2<SRadioBox>(L"c1_yes");
	m_C1NoRadio = FindChildByName2<SRadioBox>(L"c1_no");

	m_RegionLabel->SetWindowText(regionName);
	fillTechModeCombox();

	return 0;
}


void TechModeDialog::OnTechModeComboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB == 0) return;
	int nCurSel = pEvtOfCB->nCurSel;
	if(nCurSel == -1) return;

	// do something
	//根据技术模式的id查找相关参数
	ItemData* pData = (ItemData*)m_TechModeCombox->GetItemData(nCurSel);
	if(pData == 0) return;
	TechModePtr tech_mode = FIND_BY_ID(TechMode, pData->id);
	if(tech_mode == 0) return;

	m_C1YesRadio->SetCheck(BOOL_2_INT(tech_mode->c1 != 0));
	m_C1NoRadio->SetCheck(BOOL_2_INT(tech_mode->c1 == 0));
	m_C2YesRadio->SetCheck(BOOL_2_INT(tech_mode->c2 != 0));
	m_C2NoRadio->SetCheck(BOOL_2_INT(tech_mode->c2 == 0));
	m_C3YesRadio->SetCheck(BOOL_2_INT(tech_mode->c3 != 0));
	m_C3NoRadio->SetCheck(BOOL_2_INT(tech_mode->c3 == 0));
}

void TechModeDialog::OnSaveButtonClick()
{
	//根据技术模式的id查找相关参数
	ItemData* pData = (ItemData*)m_TechModeCombox->GetItemData(m_TechModeCombox->GetCurSel());
	if(pData == 0) return;
	TechModePtr tech_mode = FIND_BY_ID(TechMode, pData->id);
	if(tech_mode == 0) return;

	tech_mode->set(FIELD(c1), 1000);
	tech_mode->set(FIELD(c2), 1000);

	//更新技术模式的数据
	tech_mode->c1 = m_C1YesRadio->IsChecked();
	tech_mode->c2 = m_C2YesRadio->IsChecked();
	tech_mode->c3 = m_C3YesRadio->IsChecked();

	//保存到数据库
	if(tech_mode->save())
	{
		SMessageBox(GetSafeWnd(), _T("更新抽采技术模式数据成功!!"), _T("友情提示"), MB_OK);
	}
}

void TechModeDialog::OnRadioGroup1Switch(int nID)
{
	if(!isLayoutInited()) return;
}

void TechModeDialog::OnRadioGroup2Switch(int nID)
{
	if(!isLayoutInited()) return;
}

void TechModeDialog::OnRadioGroup3Switch(int nID)
{
	if(!isLayoutInited()) return;
}


void TechModeDialog::OnDestroyWindow()
{
	//删除所有的附加数据并清空
	clearTechModeCombox();
	AcadSouiDialog::OnDestroyWindow();
}

void TechModeDialog::fillTechModeCombox()
{
	RegionPtr region = FIND_ONE(Region, FIELD(name), regionName);
	if(region == 0) return;

	RecordPtrListPtr lists = FIND_MANY(TechMode, FKEY(Region), region->getStringID());
	if(lists == 0) return;

	clearTechModeCombox();
	for(int i=0;i<lists->size();i++)
	{
		RecordPtr tech_mode = lists->at(i);
		m_TechModeCombox->InsertItem(i, tech_mode->get(FIELD(name)), 0, 0);
		//附加数据
		ItemData* pData = new ItemData;
		pData->id = tech_mode->getID();
		pData->nItem = i;
		m_TechModeCombox->SetItemData(i, (LPARAM)pData);	
	}
	m_TechModeCombox->SetCurSel(0);
}

void TechModeDialog::clearTechModeCombox()
{
	int n = m_TechModeCombox->GetCount();
	for(int i=0;i<n;i++)
	{
		ItemData* pData = (ItemData*)m_TechModeCombox->GetItemData(i);
		delete pData;
	}
	m_TechModeCombox->ResetContent();
}
