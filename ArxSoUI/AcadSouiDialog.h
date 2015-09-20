#pragma once

#include "SouiDialog.h"

//扩展给arx使用的soui对话框基类
class AcadSouiDialog : public SouiDialog
{
public:
    AcadSouiDialog( LPCTSTR pszXmlName, BOOL bModal = FALSE );
    ~AcadSouiDialog( void );

    /** CAD焦点消息 */
protected:
    //CAD焦点消息处理
    LRESULT OnAcadKeepFocus( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );

    /** 控件消息映射表 */
    EVENT_MAP_BEGIN()
    CHAIN_EVENT_MAP( SouiDialog )
    EVENT_MAP_END()

    /** 窗口消息映射表 */
    BEGIN_MSG_MAP_EX( AcadSouiDialog )
    MESSAGE_HANDLER( WM_ACAD_KEEPFOCUS, OnAcadKeepFocus )
    CHAIN_MSG_MAP( SouiDialog )
    REFLECT_NOTIFICATIONS_EX()
    END_MSG_MAP()
};
