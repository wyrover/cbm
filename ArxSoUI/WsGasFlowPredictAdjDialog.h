#pragma once
#include "AcadSouiDialog.h"

class WsGasFlowPredictAdjDialog : public AcadSouiDialog
{

    /** 构造和析构函数 */
public:
    WsGasFlowPredictAdjDialog( BOOL bModal = FALSE );
    ~WsGasFlowPredictAdjDialog( void );

    /** 控件消息处理 */
protected:
    void OnSaveButtonClick();
    void OnAdjLayerComboxSelChanged( SOUI::EventArgs* pEvt );
    void OnDelAdjLayerButtonClick();
    void OnAddAdjLayerButtonClick();
    void OnEtaCaclButtonClick();

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
    EVENT_NAME_COMMAND( _T( "save" ), OnSaveButtonClick )
    EVENT_NAME_HANDLER( _T( "adj_layer" ), EVT_CB_SELCHANGE, OnAdjLayerComboxSelChanged )
    EVENT_NAME_COMMAND( _T( "del_adj_layer" ), OnDelAdjLayerButtonClick )
    EVENT_NAME_COMMAND( _T( "add_adj_layer" ), OnAddAdjLayerButtonClick )
    EVENT_NAME_COMMAND( _T( "eta_cacl" ), OnEtaCaclButtonClick )
    CHAIN_EVENT_MAP( AcadSouiDialog )
    EVENT_MAP_END()

    //HOST消息(WINDOWS消息)映射表
    BEGIN_MSG_MAP_EX( WsGasFlowPredictAdjDialog )
    MSG_WM_INITDIALOG( OnInitDialog )
    MSG_WM_COMMAND( OnCommand )
    CHAIN_MSG_MAP( AcadSouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()

protected:
    SEdit* m_GasW0Edit;
    SEdit* m_ThickEdit;
    SEdit* m_GasEtaEdit;
    SEdit* m_GasWc2Edit;
    SComboBox* m_AdjLayerCombox;
    SEdit* m_HEdit;
    SEdit* m_HpEdit;
    SCheckBox* m_InCzCheck;

public:
    int ws_id; // 外部传入(工作面id)

protected:
    virtual void OnDestroyWindow();

private:
    void initAdjLayerDatas();
    void fillAdjLayerCombox();
    cbm::AdjLayerPtr getCurSelAdjLayer();
};
