#include "stdafx.h"
#include "NameDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

NameDialog::NameDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:name" ), bModal )
{
}

NameDialog::~NameDialog()
{
}

void NameDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT NameDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_NameEdit = FindChildByName2<SEdit>( L"name" );
    return 0;
}


void NameDialog::OnOkButtonClick()
{
    name = m_NameEdit->GetWindowText();
    AcadSouiDialog::OnOK();
}
