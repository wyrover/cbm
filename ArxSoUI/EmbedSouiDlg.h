#pragma once

#include "DockBarChildDlg.h"
#include "LoginDlg.h"
#include "resource.h"

/**
* soui窗口嵌入到mfc窗口或对话框中的技术要点:
  (1) soui的xml布局文件中translucent必须要等于0(切记!!!)
  例如：
  <SOUI trCtx="dlg_login" title="登录" width="350" height="190" margin="5,5,5,5" translucent="0" alpha="255">
  (2)按键消息的处理和转发
  问题: soui窗口作为mfc子窗口,当我们按一个键的时候,PreTranslateMessage函数会过滤掉WM_CHAR消息,
        导致soui接收不到WM_CHAR消息,使得soui的edit无法输入文字
  参考: 对话框的按键处理 PreTranslateMessage、OnKeyDown和OnChar
         http://blog.csdn.net/wang_cong0214/article/details/8280324
  解决方法: 重载PreTranslateMessage函数,转发WM_CHAR消息给soui窗口
*/
class EmbedSouiDlg : public DockBarChildDlg
{
	DECLARE_DYNAMIC(EmbedSouiDlg)

public:
	EmbedSouiDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EmbedSouiDlg();

// 对话框数据
	enum { IDD = IDD_SOUI_EMBED_DLG };

	//子对话框(soui)
public:
	LoginDlg login_dlg;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnCancel();
	virtual void PostNcDestroy();
	//鼠标移动消息
	afx_msg void OnMouseMove(UINT nFlags, ::CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseHover(UINT nFlags, ::CPoint point);

	//参考:http://www.cnblogs.com/greatverve/archive/2013/02/06/TRACKMOUSEEVENT.html
	BOOL m_mouseInWindow;
	BOOL m_bTracking;
	virtual BOOL keepFocus();
};
