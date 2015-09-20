#pragma once

#include "dlimexp.h"

// 系统精度设置器
// 用于点坐标、向量的相等判断
class ARXHELPER_DLLIMPEXP ArxTolSetter
{
public:
    ArxTolSetter( double eq )
    {
        m_originEq = AcGeContext::gTol.equalPoint();
        setEq( eq );
    }

    void setEq( double eq )
    {
        AcGeContext::gTol.setEqualPoint( eq );
    }

    ~ArxTolSetter()
    {
        AcGeContext::gTol.setEqualPoint( m_originEq );
    }

private:
    double m_originEq;
};

/*
使用方法:
ArxTolSetter ts(0.001); // 对象析构的时候自动还原系统误差

等价于:
// 备份系统误差
double ep = AcGeContext::gTol.equalPoint();
// 设置误差
AcGeContext::gTol.setEqualPoint(0.001); // 10-3

// do something
// ...

// 还原系统误差
AcGeContext::gTol.setEqualPoint(ep);
*/

//非模态下文档锁定切换
class ArxDocLockSwitch
{
public:
    ArxDocLockSwitch()
    {
        acDocManager->lockDocument( curDoc() );
    }
    ~ArxDocLockSwitch()
    {
        acDocManager->unlockDocument( curDoc() );
    }
};

//切换controlbar显示
class ArxCtrlBarShowSwitch
{
public:
    //构造函数隐藏controlbar
    ArxCtrlBarShowSwitch( CWnd* _dlg ) : dlg( _dlg )
    {
        ShowParentControlBar( dlg, FALSE );
    }
    //析构函数显示controlbar
    ~ArxCtrlBarShowSwitch()
    {
        ShowParentControlBar( dlg, TRUE );
    }

private:
    static void ShowParentControlBar( CWnd* pWnd, BOOL bShow )
    {
        CAcModuleResourceOverride myResources;
        CControlBar* pBar = reinterpret_cast<CControlBar*>( pWnd->GetParent() );
        if( pBar == 0 ) return;

        CMDIFrameWnd* pAcadFrame = acedGetAcadFrame();
        if( pAcadFrame == 0 ) return;

        pAcadFrame->ShowControlBar( pBar, bShow, FALSE );
    }
    CWnd* dlg;
};

//切换窗口显示/隐藏
class ArxDialogShowSwitch
{
public:
    //构造函数隐藏
    ArxDialogShowSwitch( CWnd* _dlg ) : dlg( _dlg )
    {
        dlg->ShowWindow( SW_HIDE );
        ////当隐藏之后整个CAD窗口失去焦点
        //dlg->SetFocus();
    }
    //析构函数显示
    ~ArxDialogShowSwitch()
    {
        dlg->ShowWindow( SW_SHOW );
    }
    CWnd* dlg;
};