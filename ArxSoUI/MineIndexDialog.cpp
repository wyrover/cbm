#include "stdafx.h"
#include "MineIndexDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

MineIndexDialog::MineIndexDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:mine_index" ), bModal )
{
    m = n = 0;
}

MineIndexDialog::~MineIndexDialog()
{
}

void MineIndexDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT MineIndexDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_MEdit = FindChildByName2<SEdit>( L"m" );
    m_NEdit = FindChildByName2<SEdit>( L"n" );
    return 0;
}


void MineIndexDialog::OnSaveButtonClick()
{
    //提取界面数据
    Utils::cstring_to_int( ( LPCTSTR )m_MEdit->GetWindowText(), m );
    Utils::cstring_to_int( ( LPCTSTR )m_NEdit->GetWindowText(), n );
    AcadSouiDialog::OnOK();
}
