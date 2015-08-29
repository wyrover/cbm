#include "stdafx.h"
#include "HighDrillingSiteDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

HighDrillingSiteDialog::HighDrillingSiteDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:high_drilling_site" ), bModal )
{
    ws_id = 0;
}

HighDrillingSiteDialog::~HighDrillingSiteDialog()
{
}

void HighDrillingSiteDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT HighDrillingSiteDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_HnEdit = FindChildByName2<SEdit>( L"hn" );
    m_HsEdit = FindChildByName2<SEdit>( L"hs" );
    m_ThetaEdit = FindChildByName2<SEdit>( L"theta" );
    m_RtnEdit = FindChildByName2<SEdit>( L"Rtn" );
    m_QEdit = FindChildByName2<SEdit>( L"q" );

    initDatas();
    fillDatas();

    return 0;
}


void HighDrillingSiteDialog::OnSaveButtonClick()
{
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    HighDrillingSiteParamPtr hdsp = FIND_ONE( HighDrillingSiteParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdsp == 0 )
    {
        hdsp.reset( new HighDrillingSiteParam );
        hdsp->work_surf = work_surf;
    }

    Utils::cstring_to_double( ( LPCTSTR )m_HnEdit->GetWindowText(), hdsp->hn );
    Utils::cstring_to_double( ( LPCTSTR )m_HsEdit->GetWindowText(), hdsp->hs );
    Utils::cstring_to_double( ( LPCTSTR )m_ThetaEdit->GetWindowText(), hdsp->theta );
    Utils::cstring_to_double( ( LPCTSTR )m_RtnEdit->GetWindowText(), hdsp->rtn );
    Utils::cstring_to_double( ( LPCTSTR )m_QEdit->GetWindowText(), hdsp->q );

    //保存到数据库
    if( hdsp->save() )
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

void HighDrillingSiteDialog::initDatas()
{
    m_HnEdit->SetWindowText( NULL );
    m_HsEdit->SetWindowText( NULL );
    m_ThetaEdit->SetWindowText( NULL );
    m_RtnEdit->SetWindowText( NULL );
    m_QEdit->SetWindowText( NULL );
}

void HighDrillingSiteDialog::fillDatas()
{
    WorkSurfPtr work_surf = FIND_BY_ID( WorkSurf, ws_id );
    if( work_surf == 0 ) return;

    HighDrillingSiteParamPtr hdsp = FIND_ONE( HighDrillingSiteParam, FKEY( WorkSurf ), work_surf->getStringID() );
    if( hdsp == 0 ) return;

    m_HnEdit->SetWindowText( Utils::double_to_cstring( hdsp->hn ) );
    m_HsEdit->SetWindowText( Utils::double_to_cstring( hdsp->hs ) );
    m_ThetaEdit->SetWindowText( Utils::double_to_cstring( hdsp->theta ) );
    m_RtnEdit->SetWindowText( Utils::double_to_cstring( hdsp->rtn ) );
    m_QEdit->SetWindowText( Utils::double_to_cstring( hdsp->q ) );
}
