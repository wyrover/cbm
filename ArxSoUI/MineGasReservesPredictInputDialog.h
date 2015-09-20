#pragma once
#include "AcadSouiDialog.h"

class MineGasReservesPredictInputDialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    MineGasReservesPredictInputDialog( BOOL bModal = FALSE );
    ~MineGasReservesPredictInputDialog( void );

    /** 控件消息处理 */
protected:
    void OnCoalComboxSelChanged( SOUI::EventArgs* pEvt );
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
    EVENT_NAME_COMMAND( _T( "save" ), OnSaveButtonClick )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

//HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( MineGasReservesPredictInputDialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

public:
    int mine_id;

protected:
    SEdit* m_ResA1Edit;
    SEdit* m_GasX1Edit;
    SComboBox* m_CoalCombox;

public:
    int type; // 是否可采煤层(默认为1-可采)

protected:
    virtual void OnDestroyWindow();

private:
    void fillCoalCombox();
    void initCoalDatas();
    cbm::CoalPtr getCurSelCoal();
};
