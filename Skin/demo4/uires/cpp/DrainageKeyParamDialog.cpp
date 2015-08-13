#include "stdafx.h"
#include "DrainageKeyParamDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DrainageKeyParamDialog::DrainageKeyParamDialog(BOOL bModal) : AcadSouiDialog(_T("layout:drainage_key_param"), bModal)
{
}

DrainageKeyParamDialog::~DrainageKeyParamDialog()
{
}

void DrainageKeyParamDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DrainageKeyParamDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}


void DrainageKeyParamDialog::OnKP1ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP2ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP3ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP4ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP6ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP7ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP8ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP9ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP10ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP11ButtonClick()
{
}

void DrainageKeyParamDialog::OnKP5ButtonClick()
{
}
