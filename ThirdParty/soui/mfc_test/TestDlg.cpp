#include "stdafx.h"
#include "TestDlg.h"
using namespace SOUI;

#include "SoUILoader.h"

TestDlg::TestDlg(BOOL bModal) : SouiDialog(SoUILoader::getSingletonPtr()->getResName(), bModal)
{
}

TestDlg::~TestDlg(void)
{
}

LRESULT TestDlg::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	SouiDialog::OnInitDialog(hWnd, lParam);
	return 0;
}
