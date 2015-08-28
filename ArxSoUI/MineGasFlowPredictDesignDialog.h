#pragma once
#include "AcadSouiDialog.h"

class MineGasFlowPredictDesignDialog : public AcadSouiDialog
{

	/** ������������� */
public:
	MineGasFlowPredictDesignDialog(BOOL bModal = FALSE);
	~MineGasFlowPredictDesignDialog(void);

	/** �ؼ���Ϣ���� */
protected:
	void OnSaveButtonClick();
	void OnWsComboxSelChanged(SOUI::EventArgs *pEvt);
	void OnTwsComboxSelChanged(SOUI::EventArgs *pEvt);

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
		EVENT_NAME_COMMAND(_T("save"), OnSaveButtonClick)
		EVENT_NAME_HANDLER(_T("ws"), EVT_CB_SELCHANGE, OnWsComboxSelChanged)
		EVENT_NAME_HANDLER(_T("tws"), EVT_CB_SELCHANGE, OnTwsComboxSelChanged)
		CHAIN_EVENT_MAP(AcadSouiDialog)
	EVENT_MAP_END()
	
//HOST��Ϣ(WINDOWS��Ϣ)ӳ���
	BEGIN_MSG_MAP_EX(MineGasFlowPredictDesignDialog)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(AcadSouiDialog)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	SEdit* m_WsQrEdit;
	SEdit* m_WsAEdit;
	SEdit* m_TwsQaEdit;
	SComboBox* m_WsCombox;
	SComboBox* m_TwsCombox;

public:
	int work_area_id;

protected:
	virtual void OnDestroyWindow();

private:
	void initWsDatas();
	void initTwsDatas();
	void fillWsCombox();
	void fillTwsCombox();
	WorkSurfPtr getCurSelWs();
	DrillingSurfPtr getCurSelTws();
};