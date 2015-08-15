#include "stdafx.h"
#include "PoreSizeDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

PoreSizeDialog::PoreSizeDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_size"), bModal)
{
}

PoreSizeDialog::~PoreSizeDialog()
{
}

void PoreSizeDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreSizeDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_QEdit = FindChildByName2<SEdit>(L"Q");
	m_DeltaEdit = FindChildByName2<SEdit>(L"delta");
	m_VEdit = FindChildByName2<SEdit>(L"V");
	m_SigmaEdit = FindChildByName2<SEdit>(L"sigma");
	m_PEdit = FindChildByName2<SEdit>(L"P");
	m_DEdit = FindChildByName2<SEdit>(L"D");
	return 0;
}


void PoreSizeDialog::OnSaveButtonClick()
{
}
