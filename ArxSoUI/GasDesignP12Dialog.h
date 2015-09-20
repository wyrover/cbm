#pragma once
#include "AcadSouiDialog.h"

class GasDesignP12Dialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    GasDesignP12Dialog( BOOL bModal = FALSE );
    ~GasDesignP12Dialog( void );

    /** 控件消息处理 */
protected:
    void OnHeadGraphButtonClick();
    void OnHelpButtonClick();
    void OnDipGraphButtonClick();
    void OnPlaneGraphButtonClick();
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
    EVENT_NAME_COMMAND( _T( "head_graph" ), OnHeadGraphButtonClick )
    EVENT_NAME_COMMAND( _T( "help" ), OnHelpButtonClick )
    EVENT_NAME_COMMAND( _T( "dip_graph" ), OnDipGraphButtonClick )
    EVENT_NAME_COMMAND( _T( "plane_graph" ), OnPlaneGraphButtonClick )
    EVENT_NAME_COMMAND( _T( "save" ), OnSaveButtonClick )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

//HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( GasDesignP12Dialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

protected:
    SEdit* m_ThickEdit;
    SEdit* m_DipAngleEdit;
    SEdit* m_LmEdit;
    SEdit* m_WEdit;
    SEdit* m_HEdit;
    SEdit* m_DpEdit;
    SEdit* m_GbpEdit;
    SEdit* m_LeftEdit;
    SEdit* m_RightEdit;
    SEdit* m_TopEdit;
    SEdit* m_BottomEdit;
    SEdit* m_LeadingDistEdit;
    SEdit* m_LStripeEdit;

public:
    int coal_id; // 外部传入
    int tech_id;

private:
    void initDatas();
    bool getPoint( AcGePoint3d& pt );

};
