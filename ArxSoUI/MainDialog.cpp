#include "stdafx.h"
#include "MainDialog.h"
#include "MineDesignDialog.h"
#include "MineDialog.h"
#include "KeyParamDialog.h"
#include "PolicyDialog.h"
#include "DesignDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
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
    MineDialog* dlg = new MineDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF2ButtonClick()
{
    KeyParamDialog* dlg = new KeyParamDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF3ButtonClick()
{
    DesignDialog* dlg = new DesignDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF0ButtonClick()
{
    MineDesignDialog* dlg = new MineDesignDialog( FALSE );
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void MainDialog::OnF4ButtonClick()
{
    PolicyDialog* dlg = new PolicyDialog( FALSE );
    //dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}
