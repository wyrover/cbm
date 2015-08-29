#include "stdafx.h"
#include "DifficultEvalDialog.h"
#include "SouiListHelper.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

static CString PermeabilityString( double permeability_k )
{
    if( permeability_k < 5 )
        return _T( "低渗煤层" );
    else if( permeability_k < 20 )
        return _T( "中渗煤层" );
    else
        return _T( "高渗煤层" );
}

static int DifficultEval1( double decay_alpha )
{
    if( decay_alpha < 0.003 )
        return 1;
    else if( decay_alpha < 0.05 )
        return 2;
    else
        return 3;
}

static int DifficultEval2( double permeability_lambda )
{
    if( permeability_lambda > 10 )
        return 1;
    else if( permeability_lambda > 0.1 )
        return 2;
    else
        return 3;
}

static CString DifficultEvalString( int eval )
{
    static CString ret[] =
    {
        _T( "容易抽采" ),               // 1
        _T( "可以抽采" ),               // 2
        _T( "较难抽采" ),               // 3
        _T( "容易抽采~可以抽采" ),     // 4
        _T( "容易抽采~较难抽采" ),     // 5
        _T( "可以抽采~较难抽采" )      // 6
    };
    if( eval < 1 || eval > 6 ) return _T( "NULL" );
    return ret[eval - 1];
}

static int DifficultEval( int k1, int k2 )
{
    static int ret[] = { 1, 4, 5, 4, 2, 6, 5, 6, 3 };
    if( k1 < 1 || k1 > 3 || k2 < 1 || k2 > 3 ) return 0;
    return ret[k1 * 3 + k2 - 4];
}

DifficultEvalDialog::DifficultEvalDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:difficult_eval" ), bModal )
{
    mine_id = 0;
}

DifficultEvalDialog::~DifficultEvalDialog()
{
}

void DifficultEvalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT DifficultEvalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_PermeabilityKEdit = FindChildByName2<SEdit>( L"permeability_k" );
    m_DecayAlphaEdit = FindChildByName2<SEdit>( L"decay_alpha" );
    m_PermeabilityLambdaEdit = FindChildByName2<SEdit>( L"permeability_lambda" );
    m_EvalDifficultCombox = FindChildByName2<SComboBox>( L"eval_difficult" );
    m_CoalCombox = FindChildByName2<SComboBox>( L"coal" );

    initCoalDatas();
    fillCoalCombox();

    return 0;
}


void DifficultEvalDialog::OnCancelButtonClick()
{
    AcadSouiDialog::OnCancel();
}

void DifficultEvalDialog::OnEvalButtonClick()
{
    ItemData* pData = ( ItemData* )m_CoalCombox->GetItemData( m_CoalCombox->GetCurSel() );
    if( pData == 0 ) return;
    CoalPtr coal = FIND_BY_ID( Coal, pData->id );
    if( coal == 0 ) return;

    //从界面提取数据
    double permeability_k = 0, permeability_lambda = 0, decay_alpha = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_PermeabilityKEdit->GetWindowText(), permeability_k );
    Utils::cstring_to_double( ( LPCTSTR )m_PermeabilityLambdaEdit->GetWindowText(), permeability_lambda );
    Utils::cstring_to_double( ( LPCTSTR )m_DecayAlphaEdit->GetWindowText(), decay_alpha );

    //进行评价
    //根据钻孔流量衰减系数 和 煤层透气性系数进行评价
    int k1 = DifficultEval1( decay_alpha );
    int k2 = DifficultEval1( permeability_lambda );
    int eval = DifficultEval( k1, k2 );
    //保存到界面
    m_EvalDifficultCombox->SetCurSel( eval - 1 );

    if( eval != 0 )
    {
        //保存到数据库
        coal->permeability_k = permeability_k;
        coal->permeability_lambda = permeability_lambda;
        coal->decay_alpha = decay_alpha;
        coal->eval_difficult = m_EvalDifficultCombox->GetCurSel() + 1;
        if( coal->save() )
        {
            CString msg;
            msg.Format( _T( "该煤层属于:%s\\n" ), PermeabilityString( permeability_k ) );
            msg.AppendFormat( _T( "瓦斯抽采难易程度:%s" ), DifficultEvalString( eval ) );
            SMessageBox( GetSafeHwnd(), msg, _T( "友情提示" ), MB_OK );
        }
    }
}

void DifficultEvalDialog::OnEvalProofButtonClick()
{

}

void DifficultEvalDialog::OnEvalDifficultComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void DifficultEvalDialog::OnCoalComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
    initCoalDatas();
    int coal_id = SComboBoxHelper::GetItemID( m_CoalCombox, nCurSel );
    if( coal_id == 0 ) return;
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    m_DecayAlphaEdit->SetWindowText( Utils::double_to_cstring( coal->decay_alpha ) );
    m_PermeabilityLambdaEdit->SetWindowText( Utils::double_to_cstring( coal->permeability_lambda ) );
    m_PermeabilityKEdit->SetWindowText( Utils::double_to_cstring( coal->permeability_k ) );
    m_EvalDifficultCombox->SetCurSel( coal->eval_difficult - 1 );
}

void DifficultEvalDialog::OnPermeabilityKEditSetFocus( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;

    //从界面提取"透气性系数"
    double permeability_k = 0;
    double permeability_lambda = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_PermeabilityLambdaEdit->GetWindowText(), permeability_lambda );
    permeability_k = 0.025 * permeability_lambda;
    //更新到界面
    m_PermeabilityKEdit->SetWindowText( Utils::double_to_cstring( permeability_k, 3 ) );
}

void DifficultEvalDialog::OnPermeabilityLambdaEditSetFocus( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;

    //从界面提取"渗透率"
    double permeability_k = 0;
    double permeability_lambda = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_PermeabilityKEdit->GetWindowText(), permeability_k );
    permeability_lambda = permeability_k / 0.025;
    //更新到界面
    m_PermeabilityLambdaEdit->SetWindowText( Utils::double_to_cstring( permeability_lambda ) );
}

void DifficultEvalDialog::OnDestroyWindow()
{
    //删除所有的附加数据
    SComboBoxHelper::Clear( m_CoalCombox );
    AcadSouiDialog::OnDestroyWindow();
}

void DifficultEvalDialog::initCoalDatas()
{
    m_DecayAlphaEdit->SetWindowText( NULL );
    m_PermeabilityKEdit->SetWindowText( NULL );
    m_PermeabilityLambdaEdit->SetWindowText( NULL );
    m_EvalDifficultCombox->SetCurSel( -1 );
}

void DifficultEvalDialog::fillCoalCombox()
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