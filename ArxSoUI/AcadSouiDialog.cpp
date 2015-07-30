#include "stdafx.h"
#include "AcadSouiDialog.h"

using namespace SOUI;

//在OnCreate消息函数中启用Aero效果需要dwmapi的支持
//#include <dwmapi.h>
//#pragma comment(lib,"dwmapi.lib")

AcadSouiDialog::AcadSouiDialog(LPCTSTR pszXmlName, BOOL bModal) 
	: SHostDialog(pszXmlName), 
	  m_mouseInWindow(TRUE), 
	  m_bTracking(FALSE),
	  m_bLayoutInited(FALSE),
	  m_bModal(bModal)
{
}

AcadSouiDialog::~AcadSouiDialog(void)
{
}

INT_PTR AcadSouiDialog::Run(HWND hParent)
{
	if(m_bModal)
	{
		return this->DoModal(hParent);
	}
	else
	{
		Create(hParent,0,0,0,0);
		SendMessage(WM_INITDIALOG);
		//CenterWindow();
		return ShowWindow(SW_SHOWNORMAL);
	}
}

void AcadSouiDialog::OnOK()
{
	m_bTracking = FALSE;
	if(m_bModal)
	{
		SHostDialog::OnOK();
	}
	else
	{
		DestroyWindow();
	}
}

void AcadSouiDialog::OnCancel()
{
	m_bTracking = FALSE;
	if(m_bModal)
	{
		SHostDialog::OnCancel();
	}
	else
	{
		DestroyWindow();
	}
}

LRESULT AcadSouiDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	m_bLayoutInited = TRUE;
	return FALSE;
}

void AcadSouiDialog::OnFinalMessage( HWND hWnd )
{
	SHostDialog::OnFinalMessage(hWnd);
	if(!m_bModal)
	{
		//一般非模态的对话框都是new出来的,而模态则是局部变量
		delete this;
	}
	
}

static void SetVisible_Helper(SWindow* wnd, BOOL bVisible)
{
	if(wnd != 0)
	{
		wnd->SetVisible(bVisible);
	}
}

void AcadSouiDialog::OnSize(UINT nType, ::CSize size)
{
	SetMsgHandled(FALSE);   //这一行很重要，保证消息继续传递给AcadSouiDialog处理，当然也可以用AcadSouiDialog::OnSize(nType,size);代替，但是这里使用的方法更简单，通用
	if(!m_bLayoutInited) return;

	/**
	 *这个if语句用于处理最大化和还原的时候,标题栏上2个按钮的显示状态
	 该方法要求标题栏的4个按钮用规定的name名字命名
		<imgbtn name="btn_close" skin="_skin.sys.btn.close"    pos="-45,0" tip="close" animate="1"/>
		<imgbtn name="btn_max" skin="_skin.sys.btn.maximize"  pos="-83,0" animate="1" />
		<imgbtn name="btn_restore" skin="_skin.sys.btn.restore"  pos="-83,0" show="0" animate="1" />
		<imgbtn name="btn_min" skin="_skin.sys.btn.minimize" pos="-121,0" animate="1" />
	*/
	if(nType==SIZE_MAXIMIZED)
	{
		SetVisible_Helper(FindChildByName(_T("btn_restore")), TRUE);
		SetVisible_Helper(FindChildByName(_T("btn_max")), FALSE);
	}
	else if(nType==SIZE_RESTORED)
	{
		SetVisible_Helper(FindChildByName(_T("btn_restore")), FALSE);
		SetVisible_Helper(FindChildByName(_T("btn_max")), TRUE);
	}
}

void AcadSouiDialog::OnShowWindow( BOOL bShow, UINT nStatus )
{
	SetMsgHandled(FALSE);
	if(m_bModal && bShow)
	{
		//该行代码是实现窗口的动画启动效果（从小变大的过程）
		AnimateHostWindow(200, AW_CENTER);
	}
}

//int AcadSouiDialog::OnCreate( LPCREATESTRUCT lpCreateStruct )
//{
//	//启用Aero效果
//	//MARGINS mar = {5,5,30,5};
//	//DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
//
//	SetMsgHandled(FALSE);
//	return 0;
//}

void AcadSouiDialog::OnClose()
{
	m_bTracking = FALSE;
	AcadSouiDialog::OnCancel();
}

void AcadSouiDialog::OnMaximize()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE);
}

void AcadSouiDialog::OnRestore()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_RESTORE);
}

void AcadSouiDialog::OnMinimize()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_MINIMIZE);
}

//- Needed for modeless dialogs to keep focus.
//- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT AcadSouiDialog::OnAcadKeepFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	//非模态条件下,如果鼠标在窗口内(m_mouseInWindow=TRUE),则认为窗口应该获取焦点
	SetMsgHandled(TRUE);
	return m_bModal?TRUE:m_mouseInWindow;
}

void AcadSouiDialog::OnMouseMove(UINT nFlags, ::CPoint point)
{
	SetMsgHandled(FALSE);
	if(m_bModal) return;

	if (!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(TRACKMOUSEEVENT);
		tme.dwFlags = TME_LEAVE | TME_HOVER;//要触发的消息
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = 50;// 若不设此参数，则无法触发mouseHover

		if (::_TrackMouseEvent(&tme)) //MOUSELEAVE|MOUSEHOVER消息由此函数触发
		{
			m_bTracking = TRUE;   
		}
	}
}

void AcadSouiDialog::OnMouseLeave()
{
	SetMsgHandled(FALSE);
	if(m_bModal) return;

	m_bTracking = FALSE;
	m_mouseInWindow = FALSE;
}

void AcadSouiDialog::OnMouseHover(UINT nFlags, ::CPoint point)
{
	SetMsgHandled(FALSE);
	if(m_bModal) return;

	m_bTracking = FALSE;
	m_mouseInWindow = TRUE;
}
