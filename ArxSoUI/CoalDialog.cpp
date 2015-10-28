#include "stdafx.h"
#include "CoalDialog.h"
#include "DecisionDialog.h"
#include "SouiListHelper.h"
#include "NameDialog.h"
#include "MineIndexDialog.h"
#include "VarCoeffDialog.h"
#include "Czh1Dialog.h"
#include "Czh2Dialog.h"
#include "Czh3Dialog.h"
#include "Czh4Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>

using namespace orm;
using namespace cbm;

//简单统计分析(平均值和均方差)
static void DataStats( const std::vector<double>& dvalues, double& mean, double& var )
{
    size_t n = dvalues.size();

    // 1、平均值
    double a = 0;
    for( size_t i = 0; i < n; i++ )
    {
        a += abs( dvalues[i] );
    }
    mean = a / n;

    // 2、均方差
    double s = 0;
    for( size_t i = 0; i < n; i++ )
    {
        double v = abs( dvalues[i] );
        s += ( mean - v ) * ( mean - v );
    }
    var = sqrt( s / n - 1 );
}

static int CoalThick( double h )
{
    if( h <= 0 )
        return 0;
    else if( h < 1.3 ) // 薄煤层
        return 1;
    else if( h < 3.5 ) // 中厚煤层
        return 2;
    else             // 候煤层
        return 3;
}

static int  CoalStability1( double Km, double gama )
{
    if( Km > 0.95 )
        return 1;
    else if( Km > 0.8 )
        return 2;
    else if( Km > 0.6 )
        return 3;
    else if( Km >= 0 )
        return 4;
    else
        return 0;
}

static int CoalStability2( double Km, double gama )
{
    if( gama <= 0 )
        return 0;
    else if( gama <= 0.25 )
        return 1;
    else if( gama <= 0.4 )
        return 2;
    else if( gama <= 0.65 )
        return 3;
    else
        return 4;
}

static int CoalStability3( double Km, double gama )
{
    if( gama <= 0 )
        return 0;
    else if( gama <= 0.3 )
        return 1;
    else if( gama <= 0.5 )
        return 2;
    else if( gama <= 0.75 )
        return 3;
    else
        return 4;
}

static int DipAngle( double angle )
{
    if( angle <= 35 ) // 缓倾斜(0~35)
        return 1;
    else if( angle <= 54 ) // 中倾斜(36~54)
        return 2;
    else                  // 急倾斜(55~90)
        return 3;
}

CoalDialog::CoalDialog( BOOL bModal ) : AcadSouiDialog( _T( "layout:coal" ), bModal )
{
    mine_id = 0;
}

CoalDialog::~CoalDialog()
{
}

void CoalDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
    if( uNotifyCode == 0 )
    {
        //if(nID==6)
        //{
        //}
    }
}

LRESULT CoalDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    AcadSouiDialog::OnInitDialog( hWnd, lParam );
    //do something
    m_FValueEdit = FindChildByName2<SEdit>( L"f_value" );
    m_ThickEdit = FindChildByName2<SEdit>( L"thick" );
    m_RankCombox = FindChildByName2<SComboBox>( L"rank" );
    m_PressureEdit = FindChildByName2<SEdit>( L"pressure" );
    m_GasContentEdit = FindChildByName2<SEdit>( L"gas_content" );
    m_GasPenetrationEdit = FindChildByName2<SEdit>( L"gas_penetration" );
    m_ConstComplexityCombox = FindChildByName2<SComboBox>( L"const_complexity" );
    m_VarCoeffEdit = FindChildByName2<SEdit>( L"var_coeff" );
    m_DipAngleEdit = FindChildByName2<SEdit>( L"dip_angle" );
    m_CavingZoneHeightEdit = FindChildByName2<SEdit>( L"caving_zone_height" );
    m_ResAbundanceCombox = FindChildByName2<SComboBox>( L"res_abundance" );
    m_LayerGapEdit = FindChildByName2<SEdit>( L"layer_gap" );
    m_InfluenceFactorEdit = FindChildByName2<SEdit>( L"influence_factor" );
    m_MineIndexEdit = FindChildByName2<SEdit>( L"mine_index" );
    m_StabilityCombox = FindChildByName2<SComboBox>( L"stability" );
    m_CoalCombox = FindChildByName2<SComboBox>( L"coal" );
    m_MinableCheck = FindChildByName2<SCheckBox>( L"minable" );
    m_HwEdit = FindChildByName2<SEdit>( L"hw" );

    initCoalDatas();
    fillCoalCombox();

    return 0;
}


void CoalDialog::OnNextButtonClick()
{
    AcadSouiDialog::OnOK();
    DecisionDialog* dlg = new DecisionDialog( FALSE );
	dlg->SetWindowTitle(_T("依据示范矿区技术库智能决策"));
    dlg->mine_id = mine_id;
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void CoalDialog::OnCancelButtonClick()
{
    AcadSouiDialog::OnCancel();
}

void CoalDialog::OnSaveButtonClick()
{
    int coal_id = SComboBoxHelper::GetCurSelItemID( m_CoalCombox );
    if( coal_id == 0 ) return;
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    Utils::cstring_to_double( ( LPCTSTR )m_ThickEdit->GetWindowText(), coal->thick ); // 煤厚
    coal->rank = m_RankCombox->GetCurSel() + 1; // 煤阶
    Utils::cstring_to_double( ( LPCTSTR )m_PressureEdit->GetWindowText(), coal->pressure ); // 储层压力
    Utils::cstring_to_double( ( LPCTSTR )m_GasContentEdit->GetWindowText(), coal->gas_content ); // 含气量
    Utils::cstring_to_double( ( LPCTSTR )m_GasPenetrationEdit->GetWindowText(), coal->gas_penetration ); // 渗透率
    Utils::cstring_to_double( ( LPCTSTR )m_FValueEdit->GetWindowText(), coal->f_value ); // f值
    coal->res_abundance = m_ResAbundanceCombox->GetCurSel() + 1; // 煤层气储量丰度
    coal->complexity = m_ConstComplexityCombox->GetCurSel() + 1; // 构造复杂程度
    Utils::cstring_to_double( ( LPCTSTR )m_MineIndexEdit->GetWindowText(), coal->mine_index ); // 可采性指数
    Utils::cstring_to_double( ( LPCTSTR )m_VarCoeffEdit->GetWindowText(), coal->var_coeff ); // 变异系数
    coal->stability = m_StabilityCombox->GetCurSel() + 1; // 煤层稳定性
    Utils::cstring_to_double( ( LPCTSTR )m_DipAngleEdit->GetWindowText(), coal->dip_angle ); // 煤层倾角
	Utils::cstring_to_double( ( LPCTSTR )m_HwEdit->GetWindowText(), coal->hw ); // 采高
    Utils::cstring_to_double( ( LPCTSTR )m_CavingZoneHeightEdit->GetWindowText(), coal->czh ); // 冒落带高度
    coal->minable = m_MinableCheck->IsChecked(); // 是否可采煤层
	//上覆煤层间距
	Utils::cstring_to_double( (LPCTSTR)m_LayerGapEdit->GetWindowText(), coal->layer_gap);
	//采动影响倍数
	Utils::cstring_to_double( (LPCTSTR)m_InfluenceFactorEdit->GetWindowText(), coal->influence_factor);
    if( coal->save() )
    {
        SMessageBox( GetSafeHwnd(), _T( "更新成功!" ), _T( "友情提示" ), MB_OK );
    }
    else
    {
        SMessageBox( GetSafeHwnd(), _T( "更新失败!" ), _T( "友情提示" ), MB_OK );
    }
}

void CoalDialog::OnRankComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void CoalDialog::OnConstComplexityComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void CoalDialog::OnResAbundanceComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void CoalDialog::OnStabilityComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
}

void CoalDialog::OnCoalComboxSelChanged( SOUI::EventArgs* pEvt )
{
    if( !isLayoutInited() ) return;
    EventCBSelChange* pEvtOfCB = ( EventCBSelChange* )pEvt;
    if( pEvtOfCB == 0 ) return;
    int nCurSel = pEvtOfCB->nCurSel;
    if( nCurSel == -1 ) return;

    // do something
    int coal_id = SComboBoxHelper::GetCurSelItemID( m_CoalCombox );
    if( coal_id == 0 ) return;
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    if( coal == 0 ) return;

    m_ThickEdit->SetWindowText( Utils::double_to_cstring( coal->thick ) );
	m_HwEdit->SetWindowText(Utils::double_to_cstring(coal->hw));
    m_RankCombox->SetCurSel( coal->rank - 1 );
    m_PressureEdit->SetWindowText( Utils::double_to_cstring( coal->pressure ) );
    m_GasContentEdit->SetWindowText( Utils::double_to_cstring( coal->gas_content ) );
    m_GasPenetrationEdit->SetWindowText( Utils::double_to_cstring( coal->gas_penetration ) );
    m_FValueEdit->SetWindowText( Utils::double_to_cstring( coal->f_value ) );
    m_ResAbundanceCombox->SetCurSel( coal->res_abundance - 1 );
    m_ConstComplexityCombox->SetCurSel( coal->complexity - 1 );
    m_MineIndexEdit->SetWindowText( Utils::double_to_cstring( coal->mine_index ) );
    m_VarCoeffEdit->SetWindowText( Utils::double_to_cstring( coal->var_coeff ) );
    m_StabilityCombox->SetCurSel( coal->stability - 1 );
    m_DipAngleEdit->SetWindowText( Utils::double_to_cstring( coal->dip_angle ) );
    m_CavingZoneHeightEdit->SetWindowText( Utils::double_to_cstring( coal->czh ) );
    m_MinableCheck->SetCheck( BOOL_2_INT( coal->minable != 0 ) );
	m_LayerGapEdit->SetWindowText(Utils::double_to_cstring(coal->layer_gap));
	m_InfluenceFactorEdit->SetWindowText(Utils::double_to_cstring(coal->influence_factor));
}

void CoalDialog::OnMineIndexCaclButtonClick()
{
    MineIndexDialog dlg( TRUE );
	dlg.SetWindowTitle(_T("可采性指数计算"));
    if( IDOK != dlg.Run( GetSafeHwnd() ) ) return;

    //取出数据
    int m = dlg.m, n = dlg.n;
    if( n == 0 ) return;

    //计算可采性指数并更新到界面
    m_MineIndexEdit->SetWindowText( Utils::double_to_cstring( m * 1.0 / n ) );
}

void CoalDialog::OnVarCoeffCaclButtonClick()
{
    VarCoeffDialog dlg( TRUE );
	dlg.SetWindowTitle(_T("煤厚变异系数计算"));
    if( IDOK != dlg.Run( GetSafeHwnd() ) ) return;

    //取出数据
    CString str = dlg.datas;

    //拆分数据(空格、制表符、换行)
    StringArray str_datas;
    Utils::cstring_explode( str, _T( " \t\n," ), str_datas );

    //得到浮点型的数据
    typedef std::vector<double> DoubleArray;
    DoubleArray datas;
    for( int i = 0; i < str_datas.size(); i++ )
    {
        double d = 0;
        if( !Utils::cstring_to_double( str_datas[i], d ) ) continue;
        datas.push_back( d );
    }
    if( datas.empty() ) return;

    //简单的统计分析(平均值和均方差)
    double M = 0, S = 0;
    DataStats( datas, M, S );

    //计算煤厚变异系数并更新到界面
    m_VarCoeffEdit->SetWindowText( Utils::double_to_cstring( 1.0 * M / S ) );
}

void CoalDialog::OnStabilityCaclButtonClick()
{
    //煤层稳定性定量评定
    //薄煤层以煤层可采性指数为主，煤厚变异系数γ为辅；中厚及厚煤层以煤厚变异系数为主，可采性指数为辅
    //提取数据
    double Km = 0, gama = 0, h = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_MineIndexEdit->GetWindowText(), Km );
    Utils::cstring_to_double( ( LPCTSTR )m_VarCoeffEdit->GetWindowText(), gama );
    Utils::cstring_to_double( ( LPCTSTR )m_ThickEdit->GetWindowText(), h ); // 煤厚
    //计算
    int t = CoalThick( h );
    int stability = 0;
    if( t == 1 )
    {
        stability = CoalStability1( Km, gama );
    }
    else if( t == 2 )
    {
        stability = CoalStability2( Km, gama );
    }
    else if( t == 3 )
    {
        stability = CoalStability3( Km, gama );
    }
    m_StabilityCombox->SetCurSel( stability - 1 );
}

void CoalDialog::OnCzhCaclButtonClick()
{
    int coal_id = SComboBoxHelper::GetCurSelItemID( m_CoalCombox );
    if( coal_id == 0 ) return;

    //提取煤层倾角和采高数据
    double angle = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_DipAngleEdit->GetWindowText(), angle );
    int k = DipAngle( angle );
    if( k == 1 || k == 2 ) // 缓倾斜、中倾斜煤层
    {
        if( IDYES == SMessageBox( GetSafeHwnd(), _T( "煤层顶板覆盖为“极坚硬岩层”?" ), _T( "友情提示" ), MB_YESNO ) )
        {
            Czh1Dialog dlg( TRUE );
			dlg.SetWindowTitle(_T("冒落带高度计算"));
            dlg.coal_id = coal_id;
            dlg.Run( GetSafeHwnd() );
        }
        else
        {
            if( IDYES == SMessageBox( GetSafeHwnd(), _T( "厚煤层分层开采?" ), _T( "友情提示" ), MB_YESNO ) )
            {
                Czh3Dialog dlg( TRUE );
				dlg.SetWindowTitle(_T("冒落带高度计算"));
                dlg.coal_id = coal_id;
                dlg.Run( GetSafeHwnd() );
            }
            else
            {
                Czh2Dialog dlg( TRUE );
				dlg.SetWindowTitle(_T("冒落带高度计算"));
                dlg.coal_id = coal_id;
                dlg.Run( GetSafeHwnd() );
            }
        }
    }
    else
    {
        Czh4Dialog dlg( TRUE );
		dlg.SetWindowTitle(_T("冒落带高度计算"));
        dlg.coal_id = coal_id;
        dlg.Run( GetSafeHwnd() );
    }
    //更新到界面
    CoalPtr coal = FIND_BY_ID( Coal, coal_id );
    m_CavingZoneHeightEdit->SetWindowText( Utils::double_to_cstring( coal->czh ) );
}

void CoalDialog::OnInfluenceFactorCaclButtonClick()
{
    //提取界面数据
    double H = 0, M = 0;
    Utils::cstring_to_double( ( LPCTSTR )m_LayerGapEdit->GetWindowText(), H );
    Utils::cstring_to_double( ( LPCTSTR )m_HwEdit->GetWindowText(), M );
    if( M == 0 )
    {
        SMessageBox( GetSafeHwnd(), _T( "采高必须大于0" ), _T( "友情提示" ), MB_YESNO );
    }
    else
    {
        //计算并更新到界面
        m_InfluenceFactorEdit->SetWindowText( Utils::double_to_cstring( 1.0 * H / M ) );
    }
}

void CoalDialog::OnDestroyWindow()
{
    //删除所有的附加数据
    SComboBoxHelper::Clear( m_CoalCombox );
    AcadSouiDialog::OnDestroyWindow();
}

void CoalDialog::initCoalDatas()
{
    //m_CoalCombox->SetCurSel(-1);
    m_RankCombox->SetCurSel( -1 );
    m_ThickEdit->SetWindowText( NULL );
    m_PressureEdit->SetWindowText( NULL );
    m_GasContentEdit->SetWindowText( NULL );
    m_GasPenetrationEdit->SetWindowText( NULL );
    m_FValueEdit->SetWindowText( NULL );
    m_ResAbundanceCombox->SetCurSel( -1 );
    m_ConstComplexityCombox->SetCurSel( -1 );
    m_MineIndexEdit->SetWindowText( NULL );
    m_VarCoeffEdit->SetWindowText( NULL );
    m_StabilityCombox->SetCurSel( -1 );
    m_DipAngleEdit->SetWindowText( NULL );
    m_CavingZoneHeightEdit->SetWindowText( NULL );
    m_MinableCheck->SetCheck( FALSE );
    m_HwEdit->SetWindowText( NULL );
	m_LayerGapEdit->SetWindowText(NULL);
	m_InfluenceFactorEdit->SetWindowText(NULL);
}

void CoalDialog::fillCoalCombox()
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

CoalPtr CoalDialog::getCurSelCoal()
{
    int coal_id = SComboBoxHelper::GetCurSelItemID( m_CoalCombox );
    if( coal_id == 0 ) return CoalPtr();
    return FIND_BY_ID( Coal, coal_id );
}
