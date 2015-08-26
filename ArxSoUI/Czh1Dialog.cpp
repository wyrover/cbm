#include "stdafx.h"
#include "Czh1Dialog.h"

#include <ArxHelper/HelperClass.h>
#include <ArxDao/DaoHelper.h>
#include <ArxDao/Entity.h>
using namespace orm;
using namespace cbm;

#define PI 3.1415926535897932384626433832795

Czh1Dialog::Czh1Dialog(BOOL bModal) : AcadSouiDialog(_T("layout:czh_1"), bModal)
{
	coal_id = 0;
}

Czh1Dialog::~Czh1Dialog()
{
}

void Czh1Dialog::OnCommand( UINT uNotifyCode, int nID, HWND wndCtl )
{
	if(uNotifyCode==0)
	{
		//if(nID==6)
		//{
		//}
	}
}

LRESULT Czh1Dialog::OnInitDialog( HWND hWnd, LPARAM lParam )
{
	AcadSouiDialog::OnInitDialog(hWnd, lParam);
	//do something
	m_HwEdit = FindChildByName2<SEdit>(L"hw");
	m_DipAngleEdit = FindChildByName2<SEdit>(L"dip_angle");
	m_CzkEdit = FindChildByName2<SEdit>(L"czk");
	m_CavingZoneHeightEdit = FindChildByName2<SEdit>(L"caving_zone_height");

	initDatas();

	return 0;
}


void Czh1Dialog::OnSaveButtonClick()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	//读取数据
	Utils::cstring_to_double((LPCTSTR)m_HwEdit->GetWindowText(), coal->hw);
	Utils::cstring_to_double((LPCTSTR)m_DipAngleEdit->GetWindowText(), coal->dip_angle);
	Utils::cstring_to_double((LPCTSTR)m_CzkEdit->GetWindowText(), coal->czk);

	//计算
	double M = coal->hw;
	double K = coal->czk;
	double alpha = coal->dip_angle*PI/180;

	if(K<=1)
	{
		SMessageBox(GetSafeHwnd(),_T("冒落岩石碎胀系数必须满足: K>1"),_T("友情提示"),MB_YESNO);
	}
	else
	{
		double Hm = M/((K-1)*cos(alpha));
		//更新到界面
		m_CavingZoneHeightEdit->SetWindowText(Utils::double_to_cstring(Hm));
		coal->czh = Hm;
		coal->save(); // 保存到数据库
	}
	//AcadSouiDialog::OnOK();
}

void Czh1Dialog::initDatas()
{
	CoalPtr coal = FIND_BY_ID(Coal, coal_id);
	if(coal == 0) return;

	m_HwEdit->SetWindowText(Utils::double_to_cstring(coal->hw));
	m_DipAngleEdit->SetWindowText(Utils::double_to_cstring(coal->dip_angle));
	m_CzkEdit->SetWindowText(Utils::double_to_cstring(coal->czk));
	m_CavingZoneHeightEdit->SetWindowText(NULL);
}
