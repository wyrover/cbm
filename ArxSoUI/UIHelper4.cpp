#include "StdAfx.h"
#include "UIHelper.h"

#include "SoUILoader.h"

#include "../ArxHelper/HelperClass.h"
#include "../MineGE/HelperClass.h"
#include "../Util/HelperClass.h"

#include <controls.extend/SListCtrl2.h>
#include <controls.extend/SVscrollbar.h>
#include <controls.extend/SIPAddressCtrl.h>
#include <controls.extend/SChatEdit.h>
#include <controls.extend/SScrollText.h>
#include <controls.extend/SListCtrlEx.h>
#include <controls.extend/gif/SGifPlayer.h>
#include <controls.extend/gif/SSkinGif.h>

using namespace SOUI;

class MySoUiLoader4 : public SoUILoader
{
public:
	MySoUiLoader4(HINSTANCE hInstance) : SoUILoader(hInstance)
	{

	}

	~MySoUiLoader4() 
	{
		//退出GDI+环境
		SSkinGif::Gdiplus_Shutdown();
	}

	virtual LPCTSTR getSkinDir() const
	{
		return _T("\\..\\..\\Skin\\demo4");
	}

	virtual bool initExtendControls()
	{
		pSouiApp->RegisterWndFactory(TplSWindowFactory<SGifPlayer>());//注册GIFPlayer
		pSouiApp->RegisterSkinFactory(TplSkinFactory<SSkinGif>());//注册SkinGif
		//pSouiApp->RegisterSkinFactory(TplSkinFactory<SSkinAPNG>());//注册SSkinAPNG
		pSouiApp->RegisterSkinFactory(TplSkinFactory<SSkinVScrollbar>());//注册纵向滚动条皮肤

		pSouiApp->RegisterWndFactory(TplSWindowFactory<SIPAddressCtrl>());//注册IP控件
		pSouiApp->RegisterWndFactory(TplSWindowFactory<SChatEdit>());//注册ChatEdit
		pSouiApp->RegisterWndFactory(TplSWindowFactory<SScrollText>());//注册SScrollText
		pSouiApp->RegisterWndFactory(TplSWindowFactory<SListCtrlEx>());//注册SListCtrlEx
		pSouiApp->RegisterWndFactory(TplSWindowFactory<SListCtrl2>()); //注册SListCtrl2
		//if(SUCCEEDED(CUiAnimation::Init()))
		//{
		//	pSouiApp->RegisterWndFactory(TplSWindowFactory<SUiAnimationWnd>());//注册动画控件
		//}
		//pSouiApp->RegisterWndFactory(TplSWindowFactory<SFlyWnd>());//注册飞行动画控件
		//pSouiApp->RegisterWndFactory(TplSWindowFactory<SFadeFrame>());//注册渐显隐动画控件
		//pSouiApp->RegisterWndFactory(TplSWindowFactory<SRadioBox2>());//注册RadioBox2
		//pSouiApp->RegisterWndFactory(TplSWindowFactory<SCalendar2>());//注册SCalendar2

		//初始化GDI+环境
		SSkinGif::Gdiplus_Startup();
		return true;
	}

	virtual bool initRealWnd()
	{
		//设置真窗口处理接口
		//CSouiRealWndHandler * pRealWndHandler = new CSouiRealWndHandler();
		//pSouiApp->SetRealWndHandler(pRealWndHandler);
		//pRealWndHandler->Release();

		return SoUILoader::initRealWnd();
	}

	virtual bool initGlobalStyle()
	{
		//加载全局资源描述XML
		//初始化SOUI全局资源
		return (TRUE == pSouiApp->Init(_T("xml_init"), _T("uidef"))); 
	}
};

#include "LoginDlg.h"
#include "TestDlg.h"
void UIHelper::ShowSoUIDlg4()
{
	// 切换资源
	CAcModuleResourceOverride myResources;

	LOG_TRACE(_T("启动新的soui界面"));

	//加载soui相关的组建和资源
	MySoUiLoader4 suLoader(_hdllInstance);
	if(!suLoader.init()) return;

	//创建并显示使用SOUI布局应用程序窗口
	//LoginDlg dlg;
	//dlg.Create(GetActiveWindow(),0,0,0,0);
	//dlg.GetNative()->SendMessage(WM_INITDIALOG);
	//dlg.CenterWindow();
	//dlg.ShowWindow(SW_SHOWNORMAL);
	TestDlg dlg;
	dlg.DoModal();
	//suLoader.getApp()->Run(dlg.m_hWnd);
	//suLoader.getApp()->Run(GetActiveWindow());
}