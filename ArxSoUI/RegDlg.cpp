#include "stdafx.h"
#include "RegDlg.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

RegDlg::RegDlg(BOOL bModal) 
	: AcadSouiDialog(_T("layout:reg"), bModal)
{
}

RegDlg::~RegDlg(void)
{
}

void RegDlg::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//	//nID==6对应menu_test定义的菜单的exit项。
		//	PostMessage(WM_CLOSE);
		//}
		//else if(nID==54)
		//{
		//	//about SOUI
		//	STabCtrl *pTabCtrl = FindChildByName2<STabCtrl>(L"tab_main");
		//	if(pTabCtrl) pTabCtrl->SetCurSel(_T("about"));
		//}
	}
}

LRESULT RegDlg::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	SComboBox* baseCombox = FindChildByName2<SComboBox>(L"base");

	//查找所有的煤炭基地
	StringArray bases;
	DaoHelper::GetAllMineBases(bases);

	//清空所有的煤炭基地列表
	baseCombox->ResetContent();
	for(int i=0;i<bases.size();i++)
	{
		baseCombox->InsertItem(i, bases[i], 0, 0);
	}
	//SetCurSel会触发EVT_CB_SELCHANGE消息
	baseCombox->SetCurSel(0);

	SetMsgHandled(FALSE);
	return 0;
}

void RegDlg::OnReg()
{
	CString user = FindChildByName2<SEdit>(L"username")->GetWindowText();
	CString pwd = FindChildByName2<SEdit>(L"password")->GetWindowText();
	CString name = FindChildByName2<SEdit>(L"name")->GetWindowText();
	CString region = FindChildByName2<SComboBox>(L"region")->GetWindowText();
	//CString base = FindChildByName2<SComboBox>(L"base")->GetWindowText();
	CString province = FindChildByName2<SEdit>(L"province")->GetWindowText();
	CString city = FindChildByName2<SEdit>(L"city")->GetWindowText();
	CString coal_nums = FindChildByName2<SEdit>(L"coal_nums")->GetWindowText();
	CString coal_count = FindChildByName2<SEdit>(L"coal_count")->GetWindowText();

	//注册矿井账户
	int ret = DaoHelper::VerifyMineAccount(user, pwd);
	if(ret != 0)
	{
		SMessageBox(m_hWnd,_T("用户名已存在!"),_T("友情提示"),MB_OK);
	}
	else
	{
		MinePtr mine(new Mine);
		mine->username = user;
		mine->password = pwd;
		mine->name = name;
		mine->province = province;
		mine->city = city;

		QueryPtr query(Query::from<Region>());
		mine->region = query->where(FIELD(name), region)->find_one<Region>();
		//增加到数据库并返回新增行的id值
		if(mine->save())
		{
			SMessageBox(m_hWnd,_T("注册矿井账户成功!"),_T("友情提示"),MB_OK);
			AcadSouiDialog::OnOK();
		}
		else
		{
			SMessageBox(m_hWnd,_T("注册矿井账户失败!"),_T("友情提示"),MB_OK);
		}
	}
}

void RegDlg::OnSelChanged( EventArgs *pEvt )
{
	SComboBox* baseCombox = FindChildByName2<SComboBox>(L"base");
	SComboBox* regionCombox = FindChildByName2<SComboBox>(L"region");
	if(baseCombox == 0 || regionCombox == 0) return;

	EventCBSelChange* pEvtOfCB = (EventCBSelChange*)pEvt;
	if(pEvtOfCB != 0)
	{
		//查找当前煤炭基地对应的所有矿区
		StringArray regions;
		CString base = baseCombox->GetLBText(pEvtOfCB->nCurSel);
		DaoHelper::GetAllMineRegions(base, regions);

		//清空矿区下拉列表
		regionCombox->ResetContent();
		for(int i=0;i<regions.size();i++)
		{
			regionCombox->InsertItem(i, regions[i], 0, 0);
		}
		regionCombox->SetCurSel(0);      
	}
}