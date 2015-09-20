#pragma once
#include "AcadSouiDialog.h"

class WsGasFlowPredictDialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    WsGasFlowPredictDialog( BOOL bModal = FALSE );
    ~WsGasFlowPredictDialog( void );

    /** 控件消息处理 */
protected:
    void OnQr1CaclButtonClick();
    void OnQr2CaclButtonClick();
    void OnSaveButtonClick();
    void OnWsComboxSelChanged( SOUI::EventArgs* pEvt );
    void OnQrCaclButtonClick();
    void OnRadioGroup1Switch( int nID );

    /** 菜单消息 */
protected:
    //处理菜单消息(菜单在一个单独的xml文件中描述，每个菜单项都有一个id号)
    void OnCommand( UINT uNotifyCode, int nID, HWND wndCtl );

    /** 窗口消息 */
protected:
    //对话框初始化过程
    LRESULT OnInitDialog( HWND hWnd, LPARAM lParam );

    //控件消息映射表
    EVENT_MAP_BEGIN()
    EVENT_NAME_COMMAND( _T( "qr1_cacl" ), OnQr1CaclButtonClick )
    EVENT_NAME_COMMAND( _T( "qr2_cacl" ), OnQr2CaclButtonClick )
    EVENT_NAME_COMMAND( _T( "save" ), OnSaveButtonClick )
    EVENT_NAME_HANDLER( _T( "ws" ), EVT_CB_SELCHANGE, OnWsComboxSelChanged )
    EVENT_NAME_COMMAND( _T( "qr_cacl" ), OnQrCaclButtonClick )
    EVENT_ID_COMMAND_RANGE( 100, 101, OnRadioGroup1Switch )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

//HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( WsGasFlowPredictDialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

protected:
    SEdit* m_Qr1Edit;
    SEdit* m_Qr2Edit;
    SEdit* m_QrEdit;
    SRadioBox* m_MethodThinRadio;
    SRadioBox* m_MethodThickRadio;
    SComboBox* m_WsCombox;
    SEdit* m_ThickEdit;
    SEdit* m_HwEdit;
    SEdit* m_LEdit;
    SEdit* m_WsThickEdit;

public:
    int mine_id;

protected:
    virtual void OnDestroyWindow();

private:
    void initWsDatas();
    void fillWsCombox();
    cbm::WorkSurfPtr getCurSelWs();
};
