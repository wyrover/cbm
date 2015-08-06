#include "StdAfx.h"
#include "DaoHelper.h"

#include "Entity.h"
using namespace cbm;

#include <ArxHelper/HelperClass.h>

void DaoHelper::ConfigureDao(const CString&  url, const CString&  user, const CString&  password, const CString&  dataBase)
{
	if(!DaoManager::Configure(url, user, password, dataBase))
	{
		AfxMessageBox(_T("连接MySQL数据库失败，请联系技术人员!!!"));
	}
}

void DaoHelper::TestDao()
{
	MinePtr mine(new Mine);
	mine->setUsername(_T("dlj"));
	mine->setPassword(_T("123"));
	mine->setMineName(_T("test晋煤集团"));
	mine->setMineRegion(MineRegion::findOne(1));
	mine->insert();
	mine->remove();

	acutPrintf(_T("矿区名称:%s"), mine->getMineRegion()->getName());
}
