#pragma once
#include "AcadSouiDialog.h"

class GasDesignDialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    GasDesignDialog( BOOL bModal = FALSE );
    ~GasDesignDialog( void );

    /** 控件消息处理 */
protected:
    void OnCoalComboxSelChanged( SOUI::EventArgs* pEvt );
    void OnTwsDesignButtonClick();
    void OnWsDesignButtonClick();
    void OnGoafDesignButtonClick();
    void OnSaveButtonClick();

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
    EVENT_NAME_HANDLER( _T( "coal" ), EVT_CB_SELCHANGE, OnCoalComboxSelChanged )
    EVENT_NAME_COMMAND( _T( "tws_design" ), OnTwsDesignButtonClick )
    EVENT_NAME_COMMAND( _T( "ws_design" ), OnWsDesignButtonClick )
    EVENT_NAME_COMMAND( _T( "goaf_design" ), OnGoafDesignButtonClick )
    EVENT_NAME_COMMAND( _T( "save" ), OnSaveButtonClick )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

//HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( GasDesignDialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

protected:
    SComboBox* m_CoalCombox;
    SEdit* m_ThickEdit;
    SEdit* m_DipAngleEdit;

public:
    int mine_id;

protected:
    virtual void OnDestroyWindow();

private:
    void fillCoalCombox();
};
