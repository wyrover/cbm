#pragma once
#include "AcadSouiDialog.h"

class DecisionDialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    DecisionDialog( BOOL bModal = FALSE );
    ~DecisionDialog( void );

    /** 控件消息处理 */
protected:
    void OnGraphButtonClick();
    void OnTechnologyButtonClick();

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
    EVENT_NAME_COMMAND( _T( "graph" ), OnGraphButtonClick )
    EVENT_NAME_COMMAND( _T( "technology" ), OnTechnologyButtonClick )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

//HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( DecisionDialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

protected:
    SStatic* m_TechModeLabel;

public:
    int mine_id; // 外部传入(矿井id)

private:
	bool getPoint( AcGePoint3d& pt );
};
