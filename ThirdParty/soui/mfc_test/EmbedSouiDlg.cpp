#include "stdafx.h"
#include "mfc_test.h"
#include "EmbedSouiDlg.h"


// EmbedSouiDlg �Ի���
IMPLEMENT_DYNAMIC(EmbedSouiDlg, CDialog)

EmbedSouiDlg::EmbedSouiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(EmbedSouiDlg::IDD, pParent)
{

}

EmbedSouiDlg::~EmbedSouiDlg()
{
}

void EmbedSouiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EmbedSouiDlg, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()


// EmbedSouiDlg ��Ϣ��������

BOOL EmbedSouiDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	login_dlg.Create(GetSafeHwnd(), WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, NULL, 0,0,0,0);
	login_dlg.SendMessage(WM_INITDIALOG);
	login_dlg.CenterWindow();
	login_dlg.ShowWindow(SW_SHOW);

	//::CRect rect;
	//::GetWindowRect(login_dlg.m_hWnd, &rect);
	//ScreenToClient(&rect);
	//::ScreenToClient(this->m_hWnd, &rect);
	MoveWindow(0,0,1150,760);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL EmbedSouiDlg::PreTranslateMessage(MSG* pMsg)
{
	//�Ի���İ������� PreTranslateMessage��OnKeyDown��OnChar
	//http://blog.csdn.net/wang_cong0214/article/details/8280324
	//soui������Ϊmfc���ڵ��Ӵ��ڵ�ʱ��,�����ǰ�һ������ʱ��
	//mfc�ڲ���PreTranslateMessage����˵�WM_CHAR��Ϣ,����soui���ղ���WM_CHAR��Ϣ,ʹ��edit�޷���������
	if(pMsg->message == WM_CHAR)
	{
		return login_dlg.SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
	}
	else
	{
		return CDialog::PreTranslateMessage(pMsg);
	}
}

void EmbedSouiDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialog::OnMouseMove(nFlags, point);
}

void EmbedSouiDlg::OnMouseLeave()
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialog::OnMouseLeave();
}

void EmbedSouiDlg::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialog::OnMouseHover(nFlags, point);
}