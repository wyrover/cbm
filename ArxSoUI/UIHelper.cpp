#include "StdAfx.h"
#include "UIHelper.h"
#include "Path.h"

#include "MySoUiLoader.h"
#include "DemoDialog.h"
#include "LoginDialog.h"
#include "RegDialog.h"
#include "SampleManageDialog.h"
#include "MineDialog.h"
#include "KeyParamDialog.h"
#include "PolicyDialog.h"
#include "MainDialog.h"
#include "PicViewerDialog.h"
#include "RtfViewerDialog.h"
using namespace SOUI;

#include <ArxHelper/HelperClass.h>
#include <Util/HelperClass.h>

#include <Dao/DaoHelper.h>
using namespace orm;
using namespace cbm;

void UIHelper::InitAllData()
{
	//初始化必须数据(建立词典、扩展数据appname等)
	SystemHelper::Start();
	//读取字段
    CString appDir = ArxUtilHelper::GetAppPathDir( _hdllInstance );
    FieldHelper::InitDataField( ArxUtilHelper::BuildPath( appDir, _T( "Datas\\煤层气抽采-字段-图元属性.txt" ) ) );
	//加载线型
	acdbHostApplicationServices()->workingDatabase()->loadLineTypeFile(_T("JIS_02_0.7"), _T("acadiso.lin"));
}

void UIHelper::InitSouiEnviroment()
{
    LOG_TRACE( _T( "初始化soui环境..." ) );
    new MySoUiLoader( _hdllInstance );
    SoUILoader::getSingletonPtr()->init();
}

void UIHelper::UnInitSouiEnviroment()
{
    LOG_TRACE( _T( "退出soui环境..." ) );
    delete SoUILoader::getSingletonPtr();
}

void UIHelper::ShowModelessDemo()
{
    // 切换资源
    CAcModuleResourceOverride myResources;

    LOG_TRACE( _T( "启动soui非模态对话框" ) );
    DemoDialog* dlg = new DemoDialog( FALSE );
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void UIHelper::ShowModalDemo()
{
    CAcModuleResourceOverride myResources;

    LOG_TRACE( _T( "启动soui模态对话框" ) );
    DemoDialog dlg( TRUE );
	dlg.Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void UIHelper::TestRtfViewer()
{
	RtfViewerDialog dlg(TRUE);
	//直接指定rtf资源(无  rtf:  前缀)
	dlg.setRtfRes(_T("HELP1"));
	//或者直接一个rtf文件(最好是使用绝对路径)
	//dlg.setRtfFile(ArxUtilHelper::BuildPath(ArxUtilHelper::GetAppPathDir(_hdllInstance), _T("help2.rtf")));
	dlg.Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void UIHelper::TestPicViewer()
{
	PicViewerDialog dlg(TRUE);
	dlg.setPicSkin(_T("skin_eval_proof"));
	dlg.Run( acedGetAcadFrame()->GetSafeHwnd() );

	CString picFile = ArxUtilHelper::BuildPath(
		ArxUtilHelper::GetAppPathDir(_hdllInstance),
		_T("..\\..\\ArxSoUI\\uires\\image\\bk.png"));
	UIHelper::ShowImgView(picFile);
}

void UIHelper::Login()
{
    CAcModuleResourceOverride myResources;

    LoginDialog dlg( TRUE );
    dlg.Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void UIHelper::RegMine()
{
	CAcModuleResourceOverride myResources;

	RegDialog dlg( TRUE );
	dlg.Run( acedGetAcadFrame()->GetSafeHwnd() );
}

void UIHelper::Logout()
{
    //清空cbm_sys_info表
    RecordPtrListPtr lists = FIND_ALL( SysInfo );
    if( lists == 0 ) return;

    for( int i = 0; i < lists->size(); i++ )
    {
        lists->at( i )->remove();
    }
	AfxMessageBox(_T("成功注销并退出系统!"));
}

void UIHelper::SampleManage()
{
    //查找管理员帐户
    AccountPtr admin = FIND_ONE( Account, FIELD( username ), _T( "admin" ) );
    if( admin == 0 ) return;

    int account_id = DaoHelper::GetOnlineAccountId();
    if( account_id == 0 || account_id != admin->getID() )
    {
        SMessageBox( acedGetAcadFrame()->GetSafeHwnd(), _T( "请以管理员(admin)身份登录!" ), _T( "友情提示" ), MB_OK );
        //调用登录函数
        UIHelper::Login();
    }
    else
    {
        CAcModuleResourceOverride myResources;

        SampleManageDialog* dlg = new SampleManageDialog( FALSE );
        dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
    }
}

void UIHelper::GasTechModeDecision()
{
    int account_id = DaoHelper::GetOnlineAccountId();
    if( account_id == 0 )
    {
        SMessageBox( acedGetAcadFrame()->GetSafeHwnd(), _T( "请登录!" ), _T( "友情提示" ), MB_OK );
        //调用登录函数
        UIHelper::Login();
    }
    else
    {
        CAcModuleResourceOverride myResources;

        MineDialog* dlg = new MineDialog( FALSE );
        //查询账户关联的矿井
        MinePtr mine = FIND_ONE( Mine, FKEY( Account ), Utils::int_to_cstring( account_id ) );
        dlg->mine_id = mine->getID();
        dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
    }
}

void UIHelper::KeyParamCacl()
{
    int account_id = DaoHelper::GetOnlineAccountId();
    if( account_id == 0 )
    {
        SMessageBox( acedGetAcadFrame()->GetSafeHwnd(), _T( "请登录!" ), _T( "友情提示" ), MB_OK );
        //调用登录函数
        UIHelper::Login();
    }
    else
    {
        CAcModuleResourceOverride myResources;

        KeyParamDialog* dlg = new KeyParamDialog( FALSE );
        //查询账户关联的矿井
        MinePtr mine = FIND_ONE( Mine, FKEY( Account ), Utils::int_to_cstring( account_id ) );
        dlg->mine_id = mine->getID();
        dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
    }
}

void UIHelper::PolicyHelp()
{
    CAcModuleResourceOverride myResources;

    PolicyDialog* dlg = new PolicyDialog( FALSE );
    dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
}

static void test_ucs()
{
	AcGePoint3d pt(100,20,0);
	ArxUcsSwitch ucs_switch(pt, AcGeVector3d(1,1,0), AcGeVector3d(-1,1,0));

	AcDbObjectIdArray ents;
	//AcGePoint3d spt(0, 0, 0), ept(100,100,0);
	//spt = ArxUcsHelper::ucsToWcs(spt);
	//ept = ArxUcsHelper::ucsToWcs(ept);
	ents.append(ArxDrawHelper::DrawLine(AcGePoint3d(0, 0, 0), AcGePoint3d(100,100,0)));
	ents.append(ArxDrawHelper::DrawLine(AcGePoint3d(100, 100, 0), AcGePoint3d(100,0,0)));
	ents.append(ArxDrawHelper::DrawLine(AcGePoint3d(100, 0, 0), AcGePoint3d(0,100,0)));

	ArxUcsHelper::ucsToWcs(ents);
}

void UIHelper::Main()
{
    int account_id = DaoHelper::GetOnlineAccountId();
    if( account_id == 0 )
    {
        SMessageBox( acedGetAcadFrame()->GetSafeHwnd(), _T( "请登录!" ), _T( "友情提示" ), MB_OK );
        //调用登录函数
        UIHelper::Login();
    }
    else
    {
        CAcModuleResourceOverride myResources;

        MainDialog* dlg = new MainDialog( FALSE );
        //查询账户关联的矿井
        MinePtr mine = FIND_ONE( Mine, FKEY( Account ), Utils::int_to_cstring( account_id ) );
        dlg->mine_id = mine->getID();
        dlg->Run( acedGetAcadFrame()->GetSafeHwnd() );
    }
}

void UIHelper::ShowImgView(const CString& bstrFileName)
{
	//imgview.exe的路径
	CString strExeName = ArxUtilHelper::BuildPath(ArxUtilHelper::GetAppPathDir(_hdllInstance), _T("ImageView.exe"));
	
	//exe的参数
	CString strArg = _T("\"");
	strArg += bstrFileName;
	strArg += _T("\"");

	if (cbm::CPath::IsFileExist(strExeName))
	{
		HWND hWnd = ::FindWindow(_T("DUI_WINDOW"), _T("ImageView"));
		if (::IsWindow(hWnd))
			::SendMessage(hWnd, WM_CLOSE, 0, 0);
		::ShellExecute(NULL, NULL, strExeName, strArg, NULL, SW_SHOWNORMAL);
	}
	else
		::ShellExecute(NULL, _T("open"), bstrFileName, NULL, NULL, SW_SHOWNORMAL);
}
