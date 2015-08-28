#include "stdafx.h"
#include "MineGasContent1Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineGasContent1Dialog::MineGasContent1Dialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_gas_content1" ), bModal )
{
}

MineGasContent1Dialog::~MineGasContent1Dialog()
{
}

void MineGasContent1Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineGasContent1Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_ReserveGasEdit = FindChildByName2<SEdit>( L"reserve_gas" );
    m_ReserveW1Edit = FindChildByName2<SEdit>( L"reserve_w1" );
    m_ReserveW2Edit = FindChildByName2<SEdit>( L"reserve_w2" );
    m_ReserveW3Edit = FindChildByName2<SEdit>( L"reserve_w3" );
    return 0;
}


void MineGasContent1Dialog::OnSaveButtonClick()
{
}
