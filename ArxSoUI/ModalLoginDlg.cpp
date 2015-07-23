#include "stdafx.h"
#include "ModalLoginDlg.h"
using namespace SOUI;

//启用Aero效果
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")

ModalLoginDlg::ModalLoginDlg(void) : SHostDialog(_T("layout:dlg_login")), m_bLayoutInited(false)
{
}

ModalLoginDlg::~ModalLoginDlg(void)
{
}

int ModalLoginDlg::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	//启用Aero效果
	//MARGINS mar = {5,5,30,5};
	//DwmExtendFrameIntoClientArea ( m_hWnd, &mar );

	SetMsgHandled(FALSE);
	return 0;
}

void ModalLoginDlg::OnShowWindow( BOOL bShow, UINT nStatus )
{
	if(bShow)
	{
		//该行代码是实现窗口的动画启动效果（从小变大的过程）
		AnimateHostWindow(200,AW_CENTER);
	}
}

void ModalLoginDlg::OnDestory()
{
	//do something
	SetMsgHandled(FALSE); 
}

void ModalLoginDlg::OnSize(UINT nType, SOUI::CSize size)
{
	SetMsgHandled(FALSE);   //这一行很重要，保证消息继续传递给SHostDialog处理，当然也可以用SHostDialog::OnSize(nType,size);代替，但是这里使用的方法更简单，通用
	if(!m_bLayoutInited) return;

	/**
	 *这个if语句用于处理最大化和还原的时候,标题栏上2个按钮的显示状态
	 该方法要求标题栏的4个按钮用数字id号命名
		<imgbtn id="1" skin="_skin.sys.btn.close"    pos="-45,0" tip="close" animate="1"/>
		<imgbtn id="2" skin="_skin.sys.btn.maximize"  pos="-83,0" animate="1" />
		<imgbtn id="3" skin="_skin.sys.btn.restore"  pos="-83,0" show="0" animate="1" />
		<imgbtn id="5" skin="_skin.sys.btn.minimize" pos="-121,0" animate="1" />
	*/
	if(nType==SIZE_MAXIMIZED)
	{
		FindChildByID(3)->SetVisible(TRUE);
		FindChildByID(2)->SetVisible(FALSE);
	}
	else if(nType==SIZE_RESTORED)
	{
		FindChildByID(3)->SetVisible(FALSE);
		FindChildByID(2)->SetVisible(TRUE);
	}
}

void ModalLoginDlg::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//	//nID==6对应menu_test定义的菜单的exit项。
		//	PostMessage(WM_CLOSE);
		//}
		//else if(nID==54)
		//{
		//	//about SOUI
		//	STabCtrl *pTabCtrl = FindChildByName2<STabCtrl>(L"tab_main");
		//	if(pTabCtrl) pTabCtrl->SetCurSel(_T("about"));
		//}
	}
}

void ModalLoginDlg::OnMaximize()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE);
}
void ModalLoginDlg::OnRestore()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_RESTORE);
}
void ModalLoginDlg::OnMinimize()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_MINIMIZE);
}

void ModalLoginDlg::OnClose()
{
	AnimateHostWindow(200,AW_CENTER|AW_HIDE);
	//::SendMessage(::GetParent(m_hWnd), WM_CLOSE, NULL, NULL);
	PostMessage(WM_QUIT);
	//SHostDialog::OnCancel();
}

//LRESULT ModalLoginDlg::OnNcHitTest(::CPoint point)
//{
//	SetMsgHandled(TRUE);
//	return HTCLIENT;
//}

LRESULT ModalLoginDlg::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	m_bLayoutInited = true;
	//其它控件初始化代码,类似mfc的CDialog
	//...

	return 0;
}

void ModalLoginDlg::OnLogin()
{
	CString msg;
	msg.Format(_T("用户成功登录"));
	SMessageBox(m_hWnd,msg,_T("测试"),MB_OK);
    SEdit *pEdit = FindChildByName2<SEdit>(L"user");
    pEdit->SetWindowText(_T("dlj"));
	//SHostDialog::OnOK();
}

void ModalLoginDlg::OnReg()
{
	SMessageBox(m_hWnd,_T("注册矿井信息"),_T("测试"),MB_OK);
}
