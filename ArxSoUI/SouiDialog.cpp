#include "stdafx.h"
#include "SouiDialog.h"
using namespace SOUI;

//在OnCreate消息函数中启用Aero效果需要dwmapi的支持
//#include <dwmapi.h>
//#pragma comment(lib,"dwmapi.lib")

SouiDialog::SouiDialog(LPCTSTR pszXmlName, BOOL bModal) 
	: SHostDialog(pszXmlName), 
	  m_bLayoutInited(FALSE),
	  m_bModal(bModal),
	  m_mouseInWindow(TRUE), 
	  m_bTracking(FALSE)
{
}

SouiDialog::~SouiDialog(void)
{
}

INT_PTR SouiDialog::Run(HWND hParent)
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
HWND SouiDialog::GetSafeWnd() const
{
	return m_hWnd;
}

void SouiDialog::OnOK()
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

void SouiDialog::OnCancel()
{
	m_bTracking = FALSE;
	OnDestroyWindow();
	if(m_bModal)
	{
		SHostDialog::OnCancel();
	}
	else
	{
		DestroyWindow();
	}
}

LRESULT SouiDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	m_bLayoutInited = TRUE;
	//设置标题
	SStatic* titleLabel = FindChildByName2<SStatic>(L"wnd_title");
	if(titleLabel != 0 && !m_title.IsEmpty())
	{
		titleLabel->SetWindowText(m_title);
	}
	return FALSE;
}

void SouiDialog::OnFinalMessage( HWND hWnd )
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

void SouiDialog::OnSize(UINT nType, ::CSize size)
{
	SetMsgHandled(FALSE);   //这一行很重要，保证消息继续传递给SouiDialog处理，当然也可以用SouiDialog::OnSize(nType,size);代替，但是这里使用的方法更简单，通用
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

void SouiDialog::OnShowWindow( BOOL bShow, UINT nStatus )
{
	SetMsgHandled(FALSE);
	//if(m_bModal && bShow)
	//{
	//	//该行代码是实现窗口的动画启动效果（从小变大的过程）
	//	AnimateHostWindow(200, AW_CENTER);
	//}
}

//int SouiDialog::OnCreate( LPCREATESTRUCT lpCreateStruct )
//{
//	//启用Aero效果
//	//MARGINS mar = {5,5,30,5};
//	//DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
//
//	SetMsgHandled(FALSE);
//	return 0;
//}

void SouiDialog::OnClose()
{
	m_bTracking = FALSE;
	SouiDialog::OnCancel();
}

void SouiDialog::OnMaximize()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE);
}

void SouiDialog::OnRestore()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_RESTORE);
}

void SouiDialog::OnMinimize()
{
	GetNative()->SendMessage(WM_SYSCOMMAND,SC_MINIMIZE);
}

void SouiDialog::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_ESCAPE) 
	{
		SetMsgHandled(TRUE);
		OnClose();
	}
	else
	{
		SetMsgHandled(FALSE);
	}
}

BOOL SouiDialog::isLayoutInited() const
{
	return m_bLayoutInited;
}

BOOL SouiDialog::isModal() const
{
	return m_bModal;
}

BOOL SouiDialog::keepFocus() const
{
	return isModal()?TRUE:m_mouseInWindow;
}

void SouiDialog::OnMouseMove(UINT nFlags, ::CPoint point)
{
	SetMsgHandled(FALSE);
	if(isModal()) return;

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

void SouiDialog::OnMouseLeave()
{
	SetMsgHandled(FALSE);
	if(isModal()) return;

	m_bTracking = FALSE;
	m_mouseInWindow = FALSE;
}

void SouiDialog::OnMouseHover(UINT nFlags, ::CPoint point)
{
	SetMsgHandled(FALSE);
	if(isModal()) return;

	m_bTracking = FALSE;
	m_mouseInWindow = TRUE;
}

void SouiDialog::OnDestroyWindow()
{

}

void SouiDialog::SetWindowTitle(const CString& title)
{
	m_title = title;
}
