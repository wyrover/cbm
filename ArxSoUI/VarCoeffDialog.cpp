#include "stdafx.h"
#include "VarCoeffDialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

VarCoeffDialog::VarCoeffDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:var_coeff" ), bModal )
{
}

VarCoeffDialog::~VarCoeffDialog()
{
}

void VarCoeffDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT VarCoeffDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_DatasRichedit = FindChildByName2<SRichEdit>( L"datas" );
    return 0;
}


void VarCoeffDialog::OnSaveButtonClick()
{
    datas = m_DatasRichedit->GetWindowText();
    datas.Trim();
    AcadSouiDialog::OnOK();
}
