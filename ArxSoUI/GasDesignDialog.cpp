#include "stdafx.h"
#include "GasDesignDialog.h"
#include "GasDesignP11Dialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

GasDesignDialog::GasDesignDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:gas_design" ), bModal )
{
    mine_id = 0;
}

GasDesignDialog::~GasDesignDialog()
{
}

void GasDesignDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT GasDesignDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_CoalCombox = FindChildByName2<SComboBox>( L"coal" );

    fillCoalCombox();

    return 0;
}


void GasDesignDialog::OnP11ButtonClick()
{
    int coal_id = SComboBoxHelper::GetCurSelItemID( m_CoalCombox );
    if( coal_id == 0 )
    {
        SMessageBox( GetSafeHwnd(), _T( "请选择一个【煤层】进行抽采设计!!!" ), _T( "友情提示" ), MB_OK );
        return;
    }

    AcadSouiDialog::OnOK();
    GasDesignP11Dialog* dlg = new GasDesignP11Dialog( FALSE );
    dlg->coal_id = coal_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void GasDesignDialog::OnP12ButtonClick()
{
}

void GasDesignDialog::OnP13ButtonClick()
{
}

void GasDesignDialog::OnP21ButtonClick()
{
}

void GasDesignDialog::OnP22ButtonClick()
{
}

void GasDesignDialog::OnP23ButtonClick()
{
}

void GasDesignDialog::OnP24ButtonClick()
{
}

void GasDesignDialog::OnP25ButtonClick()
{
}

void GasDesignDialog::OnP31ButtonClick()
{
}

void GasDesignDialog::OnP32ButtonClick()
{
}

void GasDesignDialog::OnP33ButtonClick()
{
}

void GasDesignDialog::OnP34ButtonClick()
{
}

void GasDesignDialog::OnCoalComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void GasDesignDialog::OnDestroyWindow()
{
    //删除所有的附加数据
    SComboBoxHelper::Clear( m_CoalCombox );
    AcadSouiDialog::OnDestroyWindow();
}

void GasDesignDialog::fillCoalCombox()
{
    MinePtr mine = FIND_BY_ID( Mine, mine_id );
    if( mine == 0 ) return;

    StringArray coal_names;
    IntArray coal_ids;
    DaoHelper::GetCoalIds( mine->getID(), coal_ids );
    DaoHelper::GetCoalNames( mine->getID(), coal_names );

    SComboBoxHelper::Clear( m_CoalCombox );
    SComboBoxHelper::Append( m_CoalCombox, coal_names, coal_ids );
    SComboBoxHelper::Select( m_CoalCombox, 0 );
}