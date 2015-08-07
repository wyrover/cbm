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

int DaoHelper::VerifyMineAccount(const CString& username, const CString& pwd)
{
	CString options;
	options.Format(_T("where username='%s'"), username);
	MinePtr mine = Mine::findOne(options);
	if(mine == 0) return 0;
	if(mine->getPassword() != pwd) return 1;
	return 2;
}

void DaoHelper::GetAllMineBases(StringArray& bases)
{
	MineBaseList list = MineBase::findMany();
	for(int i=0;i<list->size();i++)
	{
		bases.push_back(list->at(i)->getName());
	}
}

void DaoHelper::GetAllMineRegions(const CString& baseName, StringArray& regions)
{
	CString options;
	options.Format(_T("where name='%s'"), baseName);
	MineBasePtr base = MineBase::findOne(options);
	if(base == 0) return;

	options.Format(_T("where cbm_mine_base_id=%d"), base->getId());
	MineRegionList list = MineRegion::findMany(options);
	for(int i=0;i<list->size();i++)
	{
		regions.push_back(list->at(i)->getName());
	}
}
