#include "stdafx.h"
#include "DecisionDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DecisionDialog::DecisionDialog(BOOL bModal) : AcadSouiDialog(_T("layout:decision"), bModal)
{
	mine_id = 0;
}

DecisionDialog::~DecisionDialog()
{
}

void DecisionDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DecisionDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_TechModeLabel = FindChildByName2<SStatic>(L"tech_mode");
	m_TechModeLabel->SetWindowText(NULL);
	return 0;
}


void DecisionDialog::OnGraphButtonClick()
{
	SMessageBox(GetSafeHwnd(),_T("如何查看煤层赋存图???"),_T("友情提示"),MB_OK);
}

void DecisionDialog::OnTechnologyButtonClick()
{
	MinePtr mine = FIND_BY_ID(Mine, mine_id);
	if(mine == 0) return;

	StringArray coal_names;
	IntArray coal_ids;
	DaoHelper::GetCoalIds(mine->getID(), coal_ids);
	DaoHelper::GetCoalNames(mine->getID(), coal_names);

	CString msg;
	msg.Format(_T("矿井:%s,所属矿区:%s\\n"), mine->name, mine->region->get(FIELD(name)));
	msg.AppendFormat(_T("煤层个数:%d\\n"), coal_names.size());
	msg.AppendFormat(_T("煤层编号(或名称):"));
	for(int i=0;i<coal_names.size();i++)
	{
		msg.AppendFormat(_T("  %s"), coal_names[i]);
	}
	msg.AppendFormat(_T("\\n"));
	msg.AppendFormat(_T("如何决策尚不明确???"));
	SMessageBox(GetSafeHwnd(),msg,_T("友情提示"),MB_OK);
}
