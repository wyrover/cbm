#include "stdafx.h"
#include "MineGasReservesPredict1Dialog.h"
#include "MineGasReservesPredictInputDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasReservesPredict1Dialog::MineGasReservesPredict1Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_gas_reserves_predict_1" ), bModal )
{
    mine_id = 0;
}

MineGasReservesPredict1Dialog::~MineGasReservesPredict1Dialog()
{
}

void MineGasReservesPredict1Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineGasReservesPredict1Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_ReserveW1Edit = FindChildByName2<SEdit>( L"reserve_w1" );
    m_ReserveW2Edit = FindChildByName2<SEdit>( L"reserve_w2" );
    m_ReserveW3Edit = FindChildByName2<SEdit>( L"reserve_w3" );
    m_RockGasK2Edit = FindChildByName2<SEdit>( L"rock_gas_K2" );

    //填充数据
    fillMineDatas();

    return 0;
}

void MineGasReservesPredict1Dialog::OnSaveButtonClick()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    double W1 = 0, W2 = 0, W3 = 0, K = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_ReserveW1Edit->GetWindowText(), W1 );
    Utils::cstring_to_double( ( LPCTSTR )m_ReserveW2Edit->GetWindowText(), W2 );
    Utils::cstring_to_double( ( LPCTSTR )m_ReserveW3Edit->GetWindowText(), W3 );
    Utils::cstring_to_double( ( LPCTSTR )m_RockGasK2Edit->GetWindowText(), K );

    //计算W
    double W = W1 + W2 + W3;
    mine->reserve_gas = W;
    mine->reserve_w1 = W1;
    mine->reserve_w2 = W2;
    mine->reserve_w3 = W3;
    mine->rock_gas_k2 = K;
    //保存到数据库
    if( mine->save() )
    {
        SMessageBox( GetSafeHwnd(), _T( "更新数据成功" ), _T( "友情提示" ), MB_OK );
    }
    else
    {
        SMessageBox( GetSafeHwnd(), _T( "更新数据失败" ), _T( "友情提示" ), MB_OK );
    }
}

void MineGasReservesPredict1Dialog::OnW1CaclButtonClick()
{
    //提取数据进行计算
    MineGasReservesPredictInputDialog dlg( TRUE );
    dlg.mine_id = mine_id;
    dlg.Run( GetSafeHwnd() );

    //查找所有的可采煤层
    RecordPtrListPtr lists = FIND_MANY2( Coal, FKEY( Mine ), Utils::int_to_cstring( mine_id ), FIELD( minable ), _T( "1" ) );
    if( lists == 0 ) return;
    //计算可采煤层的瓦斯储量
    double S = 0;
    for( int i = 0; i < lists->size(); i++ )
    {
        CoalPtr coal = DYNAMIC_POINTER_CAST( Coal, lists->at( i ) );
        S += coal->res_a1 * coal->gas_x1;
    }
    double W1 = S;

    //更新到界面
    m_ReserveW1Edit->SetWindowText( Utils::double_to_cstring( W1 ) );
}

void MineGasReservesPredict1Dialog::OnW2CaclButtonClick()
{
    SMessageBox( GetSafeHwnd(), _T( "请直接输入数据即可!!!" ), _T( "友情提示" ), MB_OK );

    ////提取数据进行计算
    //MineGasReservesPredictInputDialog dlg(TRUE);
    //dlg.mine_id = mine_id;
    //dlg.Run(GetSafeWnd());

    ////查找所有的不可采煤层
    //RecordPtrListPtr lists = FIND_MANY2(Coal, FKEY(Mine), Utils::int_to_cstring(mine_id), FIELD(minable), _T("0"));
    //if(lists == 0) return;
    ////计算不可采煤层的瓦斯储量
    //double S = 0;
    //for(int i=0;i<lists->size();i++)
    //{
    //	CoalPtr coal = DYNAMIC_POINTER_CAST(Coal, lists->at(i));
    //	S += coal->res_a1 * coal->gas_x1;
    //}
    //double W2 = S;

    ////更新到界面
    //m_ReserveW2Edit->SetWindowText(Utils::double_to_cstring(W2));
}

void MineGasReservesPredict1Dialog::OnCaclButtonClick()
{
    //提取数据计算W3
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    //提取界面的数据进行计算(不从数据库中提取数据)
    double W1 = 0, W2 = 0, K = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_ReserveW1Edit->GetWindowText(), W1 );
    Utils::cstring_to_double( ( LPCTSTR )m_ReserveW2Edit->GetWindowText(), W2 );
    Utils::cstring_to_double( ( LPCTSTR )m_RockGasK2Edit->GetWindowText(), K );
    double W3 = K * ( W1 + W2 );

    //更新到界面
    m_ReserveW3Edit->SetWindowText( Utils::double_to_cstring( W3 ) );
}

void MineGasReservesPredict1Dialog::fillMineDatas()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    m_ReserveW1Edit->SetWindowText( Utils::double_to_cstring( mine->reserve_w1 ) );
    m_ReserveW2Edit->SetWindowText( Utils::double_to_cstring( mine->reserve_w2 ) );
    m_ReserveW3Edit->SetWindowText( Utils::double_to_cstring( mine->reserve_w3 ) );
    m_RockGasK2Edit->SetWindowText( Utils::double_to_cstring( mine->rock_gas_k2 ) );
}