#include "stdafx.h"
#include "RtfViewerDialog.h"

#include <ArxHelper/HelperClass.h>
#include <Dao/DaoHelper.h>
#include <Dao/Entity.h>
using namespace orm;
using namespace cbm;

#include <controls.extend/reole/richeditole.h>

RtfViewerDialog::RtfViewerDialog(BOOL bModal) : AcadSouiDialog(_T("layout:rtf_viewer"), bModal)
{
	m_use_res = true;
}

RtfViewerDialog::~RtfViewerDialog()
{
}

void RtfViewerDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

//class CSmileySource2 : public CSmileySource
//{
//public:
//	CSmileySource2(){}
//
//protected:
//	//获对ID对应的图片路径
//	virtual SStringW ImageID2Path(UINT nID)
//	{
//		return SStringW().Format(L"./gif/%d.gif",nID);
//	}
//};

//ole资源(包括图片、表格、excel、ppt等)回调函数。
ISmileySource * CreateSource2()
{
	//普通的rtf支持的ole对象
	return  new CSmileySource();
	//CSmileySource2额外支持表情符号(微信、QQ聊天用的那种)
	//return  new CSmileySource2();
}

LRESULT RtfViewerDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_RtfViewerRichedit = FindChildByName2<SRichEdit>(L"rtf_viewer");
	if(m_RtfViewerRichedit != 0)
	{
		//必须要设置ole回调,否则rtf文件中图片、表格等内容无法显示
		SetSRicheditOleCallback(m_RtfViewerRichedit,CreateSource2);

		if(this->m_use_res)
		{
			//修改richedit的rtf属性
			CString rtf;
			rtf.Format(_T("rtf:%s"), this->m_rtf_res);
			m_RtfViewerRichedit->SetAttribute(L"rtf", (LPCTSTR)rtf);
		}
		else
		{
			m_RtfViewerRichedit->LoadRtf(m_rtf_file);
		}
	}
	return 0;
}

void RtfViewerDialog::setRtfRes(const CString& rtf_res)
{
	m_rtf_res = rtf_res;
	m_use_res = true;
}

void RtfViewerDialog::setRtfFile(const CString& rtf_file)
{
	m_rtf_file = rtf_file;
	m_use_res = false;
}
