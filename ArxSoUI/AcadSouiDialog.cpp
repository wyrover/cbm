#include "stdafx.h"
#include "AcadSouiDialog.h"

AcadSouiDialog::AcadSouiDialog( LPCTSTR pszXmlName, BOOL bModal )
    : SouiDialog( pszXmlName, bModal )
{
}

AcadSouiDialog::~AcadSouiDialog( void )
{
}

//- Needed for modeless dialogs to keep focus.
//- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT AcadSouiDialog::OnAcadKeepFocus( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    //非模态条件下,如果鼠标在窗口内(m_mouseInWindow=TRUE),则认为窗口应该获取焦点
    SetMsgHandled( TRUE );
    return SouiDialog::keepFocus();
}

