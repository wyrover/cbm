#pragma once
#include "AcadSouiDialog.h"

class PicViewerDialog : public AcadSouiDialog
{

	/** ������������� */
public:
	PicViewerDialog(BOOL bModal = FALSE);
	~PicViewerDialog(void);

	/** �ؼ���Ϣ���� */
protected:

	/** �˵���Ϣ */
protected:
	//�����˵���Ϣ(�˵���һ��������xml�ļ���������ÿ���˵����һ��id��)
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	/** ������Ϣ */
protected:
	//�Ի����ʼ������
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);

	//�ؼ���Ϣӳ���
	EVENT_MAP_BEGIN()
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST��Ϣ(WINDOWS��Ϣ)ӳ���
	BEGIN_MSG_MAP_EX(PicViewerDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SImageWnd* m_PicImg;

public:
	void setPicSkin(const CString& pic_skin);
	void setPicFile(const CString& pic_file);

private:
	CString m_pic_skin; // ͼƬ��ԴƤ��
	CString m_pic_file; // ͼƬ�ļ�·��
	bool m_use_res;     // ʹ����Դ���Ǽ���rtf�ļ�(Ĭ��ʹ����Դ)
};