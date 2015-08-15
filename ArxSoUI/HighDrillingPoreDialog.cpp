#include "stdafx.h"
#include "HighDrillingPoreDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

HighDrillingPoreDialog::HighDrillingPoreDialog(BOOL bModal) : AcadSouiDialog(_T("layout:high_drilling_pore"), bModal)
{
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
	m_LgEdit = FindChildByName2<SEdit>(L"Lg");
	m_LwEdit = FindChildByName2<SEdit>(L"Lw");
	m_NEdit = FindChildByName2<SEdit>(L"n");
	m_BetaEdit = FindChildByName2<SEdit>(L"beta");
	m_LdEdit = FindChildByName2<SEdit>(L"Ld");
	m_LziEdit = FindChildByName2<SEdit>(L"Lzi");
	m_LzjEdit = FindChildByName2<SEdit>(L"Lzj");
	return 0;
}


void HighDrillingPoreDialog::OnSaveButtonClick()
{
}
