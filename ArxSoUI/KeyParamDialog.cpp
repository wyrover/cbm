#include "stdafx.h"
#include "KeyParamDialog.h"
#include "DifficultEvalDialog.h"
#include "MineGasReservesPredictDialog.h"
#include "MineGasFlowPredictDialog.h"
#include "TwsGasFlowPredictDialog.h"
#include "WsGasFlowPredictDialog.h"
#include "HighDrillingTunnelDialog.h"
#include "HighDrillingDesignDialog.h"
#include "DrillingRadiusDesignDialog.h"
#include "PoreSizeDialog.h"
#include "PoreFlowDialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

KeyParamDialog::KeyParamDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:key_param" ), bModal )
{
    mine_id = 0;
}

KeyParamDialog::~KeyParamDialog()
{
}

void KeyParamDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT KeyParamDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    return 0;
}


void KeyParamDialog::OnKP1ButtonClick()
{
    DifficultEvalDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP2ButtonClick()
{
    MineGasReservesPredictDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP3ButtonClick()
{
    MineGasFlowPredictDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP4ButtonClick()
{
    TwsGasFlowPredictDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP5ButtonClick()
{
    WsGasFlowPredictDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP6ButtonClick()
{
    HighDrillingTunnelDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP7ButtonClick()
{
    HighDrillingDesignDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP8ButtonClick()
{
    DrillingRadiusDesignDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP9ButtonClick()
{
    PoreSizeDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP10ButtonClick()
{
    PoreFlowDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );
}

void KeyParamDialog::OnKP11ButtonClick()
{
}

