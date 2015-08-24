#include "stdafx.h"
#include "PoreSizeDialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

#include <cmath>

PoreSizeDialog::PoreSizeDialog(BOOL bModal) : AcadSouiDialog(_T("layout:pore_size"), bModal)
{
	mine_id = 0;
	pore_size_id = 0;
}

PoreSizeDialog::~PoreSizeDialog()
{
}

void PoreSizeDialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT PoreSizeDialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_QEdit = FindChildByName2<SEdit>(L"Q");
	m_DeltaEdit = FindChildByName2<SEdit>(L"delta");
	m_VEdit = FindChildByName2<SEdit>(L"V");
	m_SigmaEdit = FindChildByName2<SEdit>(L"sigma");
	m_PEdit = FindChildByName2<SEdit>(L"P");
	m_DEdit = FindChildByName2<SEdit>(L"D");

	initDatas();

	return 0;
}


void PoreSizeDialog::OnSaveButtonClick()
{
	PoreSizePtr pore_size = FIND_BY_ID(PoreSize, pore_size_id);
	if(pore_size == 0) return;

	Utils::cstring_to_double((LPCTSTR)m_QEdit->GetWindowText(), pore_size->q);
	Utils::cstring_to_double((LPCTSTR)m_VEdit->GetWindowText(), pore_size->v);
	Utils::cstring_to_double((LPCTSTR)m_DEdit->GetWindowText(), pore_size->d);
	Utils::cstring_to_double((LPCTSTR)m_PEdit->GetWindowText(), pore_size->p);
	Utils::cstring_to_double((LPCTSTR)m_SigmaEdit->GetWindowText(), pore_size->sigma);
	Utils::cstring_to_double((LPCTSTR)m_DeltaEdit->GetWindowText(), pore_size->delta);
	//保存到数据库
	if(pore_size->save())
	{
		SMessageBox(GetSafeWnd(), _T("保存数据成功!!!"), _T("友情提示"), MB_OK);
	}
	else
	{
		SMessageBox(GetSafeWnd(), _T("保存数据失败!!!"), _T("友情提示"), MB_OK);
	}
}

void PoreSizeDialog::OnHintButtonClick()
{
	SMessageBox(GetSafeWnd(), _T("注：各类管路的流量应按照其使用年限或服务区域内的最大值确定\\n并应有1.2~1.8的富余系数!!!"), _T("友情提示"), MB_OK);
}

void PoreSizeDialog::OnCaclButtonClick()
{
	//提取界面数据
	double Q = 0, V = 0, D = 0, P = 0, sigma = 0, delta = 0;
	Utils::cstring_to_double((LPCTSTR)m_QEdit->GetWindowText(), Q);
	Utils::cstring_to_double((LPCTSTR)m_VEdit->GetWindowText(), V);
	//Utils::cstring_to_double((LPCTSTR)m_DEdit->GetWindowText(), D);
	Utils::cstring_to_double((LPCTSTR)m_PEdit->GetWindowText(), P);
	Utils::cstring_to_double((LPCTSTR)m_SigmaEdit->GetWindowText(), sigma);
	//Utils::cstring_to_double((LPCTSTR)m_DeltaEdit->GetWindowText(), delta);

	if(sigma == 0 || V == 0)
	{
		SMessageBox(GetSafeWnd(), _T("经济流速或容许压力取值不能为0!!!"), _T("友情提示"), MB_OK);
		return;
	}

	D = 0.1457*sqrt(Q/V);
	delta = 0.5*P*D/sigma;

	//更新到界面
	m_DEdit->SetWindowText(Utils::double_to_cstring(D));
	m_DeltaEdit->SetWindowText(Utils::double_to_cstring(delta));
}

void PoreSizeDialog::OnHint2ButtonClick()
{
	SMessageBox(GetSafeWnd(), _T("注:可取屈服极限强度的60%；缺少此值时:\\n铸铁管可取20MPa\\n焊接钢管可取60MPa\\n无缝钢管可取80MPa"), _T("友情提示"), MB_OK);
}

void PoreSizeDialog::OnDestroyWindow()
{
	if(pore_size_id != 0)
	{
		PoreSizePtr pore_size = FIND_BY_ID(PoreSize, pore_size_id);
		if(pore_size_id != 0)
		{
			pore_size->remove();
		}
	}
	AcadSouiDialog::OnDestroyWindow();
}

void PoreSizeDialog::initDatas()
{
	m_QEdit->SetWindowText(NULL);
	m_DeltaEdit->SetWindowText(NULL);
	m_VEdit->SetWindowText(NULL);
	m_SigmaEdit->SetWindowText(NULL);
	m_PEdit->SetWindowText(NULL);
	m_DEdit->SetWindowText(NULL);

	pore_size_id = 0;
	PoreSizePtr pore_size(new PoreSize);
	pore_size->name = _T("");
	if(pore_size->save())
	{
		pore_size_id = pore_size->getID();
	}
}
