#include "stdafx.h"
#include "PictureDialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>
#include <Dao/Entity.h>
using namespace orm;
using namespace cbm;

PictureDialog::PictureDialog(BOOL bModal) : AcadSouiDialog(_T("layout:picture"), bModal)
{
}

PictureDialog::~PictureDialog()
{
}

void PictureDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PictureDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_PicImg = FindChildByName2<SImageWnd>(L"pic");
	ISkinObj* skin = GETSKIN((LPCTSTR)pic_skin);
	if(skin != 0)
	{
		//更新图片
		m_PicImg->SetSkin(skin);

		//设置窗口大小是可调整的
		//this->SetAttribute(_T("resizable"), _T("1"));
		//获取皮肤资源的大小
		SIZE size = skin->GetSkinSize();

		//下面的代码无效,无论是用SetAttribute()还是用Move()
		////自适应调整窗口大小
		//SOUI::CRect rect1, rect2;
		//SWindow::GetWindowRect(&rect1);
		//m_PicImg->GetClientRect(&rect2);
		////this->SetAttribute(_T("width"), rect2.Width()+size.cx);
		////this->SetAttribute(_T("height"), rect2.Height()+size.cy);
		//rect1.right = rect1.left + size.cx + rect1.Width() - rect2.Width();
		//rect1.bottom = rect1.top + size.cy + rect1.Height() - rect2.Height();
		//this->Move(&rect1);

		////自适应调整图片框大小
		//m_PicImg->Move(&rect2);
		////m_PicImg->SetAttribute(_T("width"), size.cx);
		////m_PicImg->SetAttribute(_T("height"), size.cy);
	}
	return 0;
}

