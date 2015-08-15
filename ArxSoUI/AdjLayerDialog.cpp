#include "stdafx.h"
#include "AdjLayerDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

AdjLayerDialog::AdjLayerDialog(BOOL bModal) : AcadSouiDialog(_T("layout:adj_layer"), bModal)
{
}

AdjLayerDialog::~AdjLayerDialog()
{
}

void AdjLayerDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT AdjLayerDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HEdit = FindChildByName2<SEdit>(L"h");
	m_SumHEdit = FindChildByName2<SEdit>(L"sum_h");
	m_ThetaEdit = FindChildByName2<SEdit>(L"theta");
	m_RtEdit = FindChildByName2<SEdit>(L"Rt");
	m_QEdit = FindChildByName2<SEdit>(L"q");
	return 0;
}


void AdjLayerDialog::OnSaveButtonClick()
{
}
