#include "stdafx.h"
#include "DifficultEvalDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DifficultEvalDialog::DifficultEvalDialog(BOOL bModal) : AcadSouiDialog(_T("layout:difficult_eval"), bModal)
{
}

DifficultEvalDialog::~DifficultEvalDialog()
{
}

void DifficultEvalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DifficultEvalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_PermeabilityKEdit = FindChildByName2<SEdit>(L"permeability_k");
	m_DecayAlphaEdit = FindChildByName2<SEdit>(L"decay_alpha");
	m_PermeabilityLambdaEdit = FindChildByName2<SEdit>(L"permeability_lambda");
	return 0;
}


void DifficultEvalDialog::OnCancelButtonClick()
{
}

void DifficultEvalDialog::OnEvalButtonClick()
{
}

void DifficultEvalDialog::OnEvalProofButtonClick()
{
}
