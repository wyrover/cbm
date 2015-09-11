#include "stdafx.h"
#include "MainDialog.h"
#include "MineDesignDialog.h"
#include "MineDialog.h"
#include "KeyParamDialog.h"
#include "PolicyDialog.h"
#include "GasDesignDialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

MainDialog::MainDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:main" ), bModal )
{
    mine_id = 0;
}

MainDialog::~MainDialog()
{
}

void MainDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MainDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    return 0;
}

void MainDialog::OnF1ButtonClick()
{
	AcadSouiDialog::OnOK();
    MineDialog* dlg = new MineDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF2ButtonClick()
{
	AcadSouiDialog::OnOK();
    KeyParamDialog* dlg = new KeyParamDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF3ButtonClick()
{
	AcadSouiDialog::OnOK();
    GasDesignDialog* dlg = new GasDesignDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF0ButtonClick()
{
	AcadSouiDialog::OnOK();
    MineDesignDialog* dlg = new MineDesignDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF4ButtonClick()
{
	AcadSouiDialog::OnOK();
    PolicyDialog* dlg = new PolicyDialog( FALSE );
    //dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}
