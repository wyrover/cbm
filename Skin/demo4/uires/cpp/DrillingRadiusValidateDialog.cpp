#include "stdafx.h"
#include "DrillingRadiusValidateDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DrillingRadiusValidateDialog::DrillingRadiusValidateDialog(BOOL bModal) : AcadSouiDialog(_T("layout:drilling_radius_validate"), bModal)
{
}

DrillingRadiusValidateDialog::~DrillingRadiusValidateDialog()
{
}

void DrillingRadiusValidateDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DrillingRadiusValidateDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_QmEdit = FindChildByName2<SEdit>(L"Qm");
	m_GasW0Edit = FindChildByName2<SEdit>(L"gas_W0");
	m_QSumEdit = FindChildByName2<SEdit>(L"QSum");
	m_EtaEdit = FindChildByName2<SEdit>(L"eta");
	m_GasWc3Edit = FindChildByName2<SEdit>(L"gas_Wc3");
	return 0;
}


void DrillingRadiusValidateDialog::OnSaveButtonClick()
{
}
