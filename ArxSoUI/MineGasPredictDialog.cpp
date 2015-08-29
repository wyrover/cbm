#include "stdafx.h"
#include "MineGasPredictDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasPredictDialog::MineGasPredictDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_gas_predict" ), bModal )
{
}

MineGasPredictDialog::~MineGasPredictDialog()
{
}

void MineGasPredictDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineGasPredictDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_WorkAreaAEdit = FindChildByName2<SEdit>( L"work_area_A" );
    m_K1GasEdit = FindChildByName2<SEdit>( L"K1_gas" );
    m_QrEdit = FindChildByName2<SEdit>( L"qr" );
    m_K2GasEdit = FindChildByName2<SEdit>( L"K2_gas" );
    m_WorkAreaCombox = FindChildByName2<SComboBox>( L"work_area" );
    m_WorkAreaQrEdit = FindChildByName2<SEdit>( L"work_area_qr" );
    return 0;
}


void MineGasPredictDialog::OnK1HelpButtonClick()
{
}

void MineGasPredictDialog::OnSaveButtonClick()
{
}

void MineGasPredictDialog::OnK2HelpButtonClick()
{
}

void MineGasPredictDialog::OnWorkAreaComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;

    // do something
}

void MineGasPredictDialog::OnInputButtonClick()
{
}
