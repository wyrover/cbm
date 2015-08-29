#include "stdafx.h"
#include "MineGasReservesPredictDialog.h"
#include "MineGasReservesPredict1Dialog.h"
#include "MineGasReservesPredict2Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasReservesPredictDialog::MineGasReservesPredictDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_gas_reserves_predict" ), bModal )
{
    mine_id = 0;
}

MineGasReservesPredictDialog::~MineGasReservesPredictDialog()
{
}

void MineGasReservesPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineGasReservesPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_ReserveGasEdit = FindChildByName2<SEdit>( L"reserve_gas" );
    m_PumpWcEdit = FindChildByName2<SEdit>( L"pump_Wc" );

    fillMineDatas();

    return 0;
}

void MineGasReservesPredictDialog::OnSaveButtonClick()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    Utils::cstring_to_double( ( LPCTSTR )m_ReserveGasEdit->GetWindowText(), mine->reserve_gas );
    Utils::cstring_to_double( ( LPCTSTR )m_PumpWcEdit->GetWindowText(), mine->pump_wc );

    if( mine->save() )
    {
        SMessageBox( GetSafeHwnd(), _T( "更新数据成功!" ), _T( "友情提示" ), MB_OK );
    }
    else
    {
        SMessageBox( GetSafeHwnd(), _T( "更新数据失败!" ), _T( "友情提示" ), MB_OK );
    }
}

void MineGasReservesPredictDialog::OnGasCaclButtonClick()
{
    //重新计算结果
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    MineGasReservesPredict1Dialog dlg( TRUE );
    dlg.mine_id = mine->getID();
    dlg.Run( GetSafeHwnd() );

    //更新界面
    mine = FIND_BY_ID( Mine, mine->getID() );
    m_ReserveGasEdit->SetWindowText( Utils::double_to_cstring( mine->reserve_gas ) );
}

void MineGasReservesPredictDialog::OnPumpWcCaclButtonClick()
{
    //重新计算结果
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    MineGasReservesPredict2Dialog dlg( TRUE );
    double W = 0; // 矿井瓦斯储量
    Utils::cstring_to_double( ( LPCTSTR )m_ReserveGasEdit->GetWindowText(), W );
    dlg.W = W; // 传入矿井瓦斯储量数据
    dlg.mine_id = mine->getID();
    dlg.Run( GetSafeHwnd() );

    //更新界面
    mine = FIND_BY_ID( Mine, mine->getID() );
    m_PumpWcEdit->SetWindowText( Utils::double_to_cstring( mine->pump_wc ) );
}

void MineGasReservesPredictDialog::fillMineDatas()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    m_ReserveGasEdit->SetWindowText( Utils::double_to_cstring( mine->reserve_gas ) );
    m_PumpWcEdit->SetWindowText( Utils::double_to_cstring( mine->pump_wc ) );
}