#pragma once
#include "AcadSouiDialog.h"

class MainDialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    MainDialog( BOOL bModal = FALSE );
    ~MainDialog( void );

    /** 控件消息处理 */
protected:
    void OnF1ButtonClick();
    void OnF2ButtonClick();
    void OnF3ButtonClick();
    void OnF0ButtonClick();
    void OnF4ButtonClick();

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
    EVENT_NAME_COMMAND( _T( "f1" ), OnF1ButtonClick )
    EVENT_NAME_COMMAND( _T( "f2" ), OnF2ButtonClick )
    EVENT_NAME_COMMAND( _T( "f3" ), OnF3ButtonClick )
    EVENT_NAME_COMMAND( _T( "f0" ), OnF0ButtonClick )
    EVENT_NAME_COMMAND( _T( "f4" ), OnF4ButtonClick )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

//HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( MainDialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

public:
    int mine_id;
};
