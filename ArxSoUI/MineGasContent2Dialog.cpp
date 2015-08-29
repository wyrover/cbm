#include "stdafx.h"
#include "MineGasContent2Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasContent2Dialog::MineGasContent2Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_gas_content2" ), bModal )
{
}

MineGasContent2Dialog::~MineGasContent2Dialog()
{
}

void MineGasContent2Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineGasContent2Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_PumpWcEdit = FindChildByName2<SEdit>( L"pump_Wc" );
    m_PumpKdEdit = FindChildByName2<SEdit>( L"pump_Kd" );
    m_PumpK1Edit = FindChildByName2<SEdit>( L"pump_K1" );
    m_PumpK2Edit = FindChildByName2<SEdit>( L"pump_K2" );
    m_PumpK4Edit = FindChildByName2<SEdit>( L"pump_K4" );
    m_PumpK3Edit = FindChildByName2<SEdit>( L"pump_K3" );
    m_PumpMyEdit = FindChildByName2<SEdit>( L"pump_My" );
    m_PumpMcEdit = FindChildByName2<SEdit>( L"pump_Mc" );
    return 0;
}


void MineGasContent2Dialog::OnSaveButtonClick()
{
}
