#include "stdafx.h"
#include "PoreFlowKDialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

#include <cmath>

PoreFlowKDialog::PoreFlowKDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:pore_flow_K" ), bModal )
{
    pore_flow_id = 0;
}

PoreFlowKDialog::~PoreFlowKDialog()
{
}

void PoreFlowKDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT PoreFlowKDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_A0Edit = FindChildByName2<SEdit>( L"a0" );
    m_DEdit = FindChildByName2<SEdit>( L"D" );
    m_D1Edit = FindChildByName2<SEdit>( L"d1" );
    m_KEdit = FindChildByName2<SEdit>( L"K" );

    initDatas();
    fillDatas();

    return 0;
}

void PoreFlowKDialog::OnSaveButtonClick()
{
    double a0 = 0, d1 = 0, D = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_A0Edit->GetWindowText(), a0 );
    Utils::cstring_to_double( ( LPCTSTR )m_D1Edit->GetWindowText(), d1 );
    Utils::cstring_to_double( ( LPCTSTR )m_DEdit->GetWindowText(), D );

    double m = ( d1 / D ) * ( d1 / D );
    double K = 189.76 * a0 * m * D * D;

    //更新到界面
    m_KEdit->SetWindowText( Utils::double_to_cstring( K ) );

    PoreFlowPtr pore_flow = FIND_BY_ID( PoreFlow, pore_flow_id );
    if( pore_flow == 0 ) return;
    //保存到数据库
    pore_flow->a0 = a0;
    pore_flow->d1 = d1;
    pore_flow->d = D;
    pore_flow->k = K;
    if( pore_flow->save() )
    {
        SMessageBox( GetSafeHwnd(), _T( "保存数据成功!!!" ), _T( "友情提示" ), MB_OK );
        AcadSouiDialog::OnOK();
    }
    else
    {
        SMessageBox( GetSafeHwnd(), _T( "保存数据失败!!!" ), _T( "友情提示" ), MB_OK );
        AcadSouiDialog::OnCancel();
    }
}

void PoreFlowKDialog::initDatas()
{
    m_A0Edit->SetWindowText( NULL );
    m_DEdit->SetWindowText( NULL );
    m_D1Edit->SetWindowText( NULL );
    m_KEdit->SetWindowText( NULL );
}

void PoreFlowKDialog::fillDatas()
{
    PoreFlowPtr pore_flow = FIND_BY_ID( PoreFlow, pore_flow_id );
    if( pore_flow == 0 ) return;

    m_A0Edit->SetWindowText( Utils::double_to_cstring( pore_flow->a0 ) );
    m_DEdit->SetWindowText( Utils::double_to_cstring( pore_flow->d ) );
    m_D1Edit->SetWindowText( Utils::double_to_cstring( pore_flow->d1 ) );
    m_KEdit->SetWindowText( Utils::double_to_cstring( pore_flow->k ) );
}
