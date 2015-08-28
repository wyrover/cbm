#include "stdafx.h"
#include "MineGasPredictInputDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasPredictInputDialog::MineGasPredictInputDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_gas_predict_input" ), bModal )
{
}

MineGasPredictInputDialog::~MineGasPredictInputDialog()
{
}

void MineGasPredictInputDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineGasPredictInputDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_WsQrEdit = FindChildByName2<SEdit>( L"ws_qr" );
    m_WsAEdit = FindChildByName2<SEdit>( L"ws_A" );
    m_TwsQrEdit = FindChildByName2<SEdit>( L"tws_qr" );
    m_WsCombox = FindChildByName2<SComboBox>( L"ws" );
    m_TwsCombox = FindChildByName2<SComboBox>( L"tws" );
    return 0;
}


void MineGasPredictInputDialog::OnSaveButtonClick()
{
}

void MineGasPredictInputDialog::OnWsComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;

    // do something
}

void MineGasPredictInputDialog::OnTwsComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;

    // do something
}
