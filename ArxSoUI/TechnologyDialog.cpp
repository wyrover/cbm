#include "stdafx.h"
#include "TechnologyDialog.h"

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

TechnologyDialog::TechnologyDialog(BOOL bModal) : AcadSouiDialog(_T("layout:technology"), bModal)
{
}

TechnologyDialog::~TechnologyDialog()
{
}

void TechnologyDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT TechnologyDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TechnologyListbox = FindChildByName2<SListBox>(L"technology");
	m_IsKeyCheck = FindChildByName2<SCheckBox>(L"is_key");
	m_DocEdit = FindChildByName2<SEdit>(L"doc");
	m_VideoEdit = FindChildByName2<SEdit>(L"video");
	m_RegionLabel = FindChildByName2<SStatic>(L"region");

	CString msg;
	msg.Format(_T(">>%s矿区推荐抽采技术"), regionName);
	m_RegionLabel->SetWindowText((LPCTSTR)msg);
	fillTechnologyListBox();

	return 0;
}


void TechnologyDialog::OnTechnologyListboxSelChanged(SOUI::EventArgs *pEvt)
{
	if(!isLayoutInited()) return;
	EventLBSelChanged* pEvtOfLB = (EventLBSelChanged*)pEvt;
	if(pEvtOfLB == 0) return;
	int nCurSel = pEvtOfLB->nNewSel;
	if(nCurSel == -1) return;

	// do something
	//根据技术模式的id查找相关参数
	ItemData* pData = (ItemData*)m_TechnologyListbox->GetItemData(nCurSel);
	if(pData == 0) return;
	TechnologyPtr technology = FIND_BY_ID(Technology, pData->id);
	if(technology == 0) return;

	m_DocEdit->SetWindowText(technology->doc);
	m_VideoEdit->SetWindowText(technology->video);
	m_IsKeyCheck->SetCheck(BOOL_2_INT(technology->iskey != 0));
}

void TechnologyDialog::OnDocReadButtonClick()
{
	SMessageBox(GetSafeWnd(), _T("启动文档阅读器(尚未实现!!)"), _T("友情提示"), MB_OK);
}

void TechnologyDialog::OnVideoPlayButtonClick()
{
	SMessageBox(GetSafeWnd(), _T("启动播放器(尚未实现!!)"), _T("友情提示"), MB_OK);
}

void TechnologyDialog::OnDocSelectButtonClick()
{
	SMessageBox(GetSafeWnd(), _T("选择文档(尚未实现!!)"), _T("友情提示"), MB_OK);
}

void TechnologyDialog::OnVideoSelectButtonClick()
{
	SMessageBox(GetSafeWnd(), _T("选择视频(尚未实现!!)"), _T("友情提示"), MB_OK);
}

void TechnologyDialog::OnSaveButtonClick()
{
	ItemData* pData2 = (ItemData*)m_TechnologyListbox->GetItemData(m_TechnologyListbox->GetCurSel());
	if(pData2 == 0) return;
	TechnologyPtr technology = FIND_BY_ID(Technology, pData2->id);
	if(technology == 0) return;

	//更新抽采技术的数据
	technology->iskey = m_IsKeyCheck->IsChecked();
	technology->doc = m_DocEdit->GetWindowText();
	technology->video = m_VideoEdit->GetWindowText();

	//保存到数据库
	if(technology->save())
	{
		SMessageBox(GetSafeWnd(), _T("更新抽采技术数据成功!!"), _T("友情提示"), MB_OK);
	}
}

void TechnologyDialog::OnDestroyWindow()
{
	//删除所有的附加数据并清空
	clearTechnologyListBox();
	AcadSouiDialog::OnDestroyWindow();
}

void TechnologyDialog::fillTechnologyListBox()
{
	RegionPtr region = FIND_ONE(Region, FIELD(name), regionName);
	if(region == 0) return;

	RecordPtrListPtr lists = FIND_MANY(Technology, FKEY(Region), region->getStringID());
	if(lists == 0) return;

	m_TechnologyListbox->DeleteAll();
	for(int i=0;i<lists->size();i++)
	{
		RecordPtr technology = lists->at(i);
		m_TechnologyListbox->AddString(technology->get(FIELD(name)));
		//附加数据
		ItemData* pData = new ItemData;
		pData->id = technology->getID();
		pData->nItem = i;
		m_TechnologyListbox->SetItemData(i, (LPARAM)pData);	
	}
	m_TechnologyListbox->SetCurSel(0);
}

void TechnologyDialog::clearTechnologyListBox()
{
	int n = m_TechnologyListbox->GetCount();
	for(int i=0;i<n;i++)
	{
		ItemData* pData = (ItemData*)m_TechnologyListbox->GetItemData(i);
		delete pData;
	}
	m_TechnologyListbox->DeleteAll();
}
