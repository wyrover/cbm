#include "stdafx.h"
#include "KeyParamDialog.h"
#include "DifficultEvalDialog.h"
#include "ReservesPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

KeyParamDialog::KeyParamDialog(BOOL bModal) : AcadSouiDialog(_T("layout:key_param"), bModal)
{
}

KeyParamDialog::~KeyParamDialog()
{
}

void KeyParamDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT KeyParamDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}


void KeyParamDialog::OnKP1ButtonClick()
{
	DifficultEvalDialog dlg(TRUE);
	dlg.Run(this->m_hWnd);
}

void KeyParamDialog::OnKP2ButtonClick()
{
	ReservesPredictDialog dlg(TRUE);
	dlg.Run(this->m_hWnd);
}

void KeyParamDialog::OnKP3ButtonClick()
{
}

void KeyParamDialog::OnKP4ButtonClick()
{
}

void KeyParamDialog::OnKP6ButtonClick()
{
}

void KeyParamDialog::OnKP7ButtonClick()
{
}

void KeyParamDialog::OnKP8ButtonClick()
{
}

void KeyParamDialog::OnKP9ButtonClick()
{
}

void KeyParamDialog::OnKP10ButtonClick()
{
}

void KeyParamDialog::OnKP11ButtonClick()
{
}

void KeyParamDialog::OnKP5ButtonClick()
{
}
