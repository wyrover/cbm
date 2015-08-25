#include "stdafx.h"
#include "DesignDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

DesignDialog::DesignDialog(BOOL bModal) : AcadSouiDialog(_T("layout:design"), bModal)
{
	mine_id = 0;
}

DesignDialog::~DesignDialog()
{
}

void DesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT DesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	return 0;
}


void DesignDialog::OnP11ButtonClick()
{
}

void DesignDialog::OnP12ButtonClick()
{
}

void DesignDialog::OnP13ButtonClick()
{
}

void DesignDialog::OnP21ButtonClick()
{
}

void DesignDialog::OnP22ButtonClick()
{
}

void DesignDialog::OnP23ButtonClick()
{
}

void DesignDialog::OnP24ButtonClick()
{
}

void DesignDialog::OnP25ButtonClick()
{
}

void DesignDialog::OnP31ButtonClick()
{
}

void DesignDialog::OnP32ButtonClick()
{
}

void DesignDialog::OnP33ButtonClick()
{
}

void DesignDialog::OnP34ButtonClick()
{
}
