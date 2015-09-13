#pragma once
#include "AcadSouiDialog.h"

class RtfViewerDialog : public AcadSouiDialog
{

	/** 构造和析构函数 */
public:
	RtfViewerDialog(BOOL bModal = FALSE);
	~RtfViewerDialog(void);

	/** 控件消息处理 */
protected:

	/** 菜单消息 */
protected:
	//处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	/** 窗口消息 */
protected:
	//对话框初始化过程
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);

	//控件消息映射表
	EVENT_MAP_BEGIN()
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST消息(WINDOWS消息)映射表
	BEGIN_MSG_MAP_EX(RtfViewerDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SRichEdit* m_RtfViewerRichedit;

public:
	void setRtfRes(const CString& rtf_res);
	void setRtfFile(const CString& rtf_file);

private:
	CString m_rtf_res; // rtf资源(外部指定)
	CString m_rtf_file; // rtf文件
	bool m_use_res;     // 使用资源还是加载rtf文件(默认使用资源)
};
