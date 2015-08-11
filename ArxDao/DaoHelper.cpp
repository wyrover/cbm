#include "StdAfx.h"
#include "DaoHelper.h"

#include "Db.h"
using namespace orm;

#include "Entity.h"
using namespace cbm;

#include <ArxHelper/HelperClass.h>

void DaoHelper::ConfigureDao(const CString& user, const CString& password, const CString& database, const CString& host/*=_T("localhost")*/, const CString& port/*=_T("3306")*/)
{
	if(!Db::Instance()->config(user, password, database, host, port))
	{
		AfxMessageBox(_T("连接MySQL数据库失败，请联系技术人员!!!"));
	}
}

void DaoHelper::TestDao()
{
	MinePtr mine(new Mine);
	mine->username = _T("dlj");
	mine->password = _T("123");
	mine->mine_name = _T("晋煤集团");
	mine->mine_region = Query::find<MineRegion>(1);
	mine->set(_T("mine_name"), _T("xxx煤集团公司"));
	mine->mine_region->set(_T("name"), _T("华北地区"));
	mine->mine_region->set(PRIMARY_KEY_ID, _T("2"));
	mine->mine_region->fetch();
	mine->save();

	//acutPrintf(_T("矿区名称:%s"), mine->mine_region->name);
}

int DaoHelper::VerifyMineAccount(const CString& username, const CString& pwd)
{
	//CString options;
	//options.Format(_T("where username='%s'"), username);
	//MinePtr mine = Mine::findOne(options);
	//if(mine == 0) return 0;
	//if(mine->getPassword() != pwd) return 1;
	//return 2;
	return 0;
}

void DaoHelper::GetAllMineBases(StringArray& bases)
{
	//MineBaseList list = MineBase::findMany();
	//for(int i=0;i<list->size();i++)
	//{
	//	bases.push_back(list->at(i)->getName());
	//}
}

void DaoHelper::GetAllMineRegions(const CString& baseName, StringArray& regions)
{
	//CString options;
	//options.Format(_T("where name='%s'"), baseName);
	//MineBasePtr base = MineBase::findOne(options);
	//if(base == 0) return;

	//options.Format(_T("where cbm_mine_base_id=%d"), base->getId());
	//MineRegionList list = MineRegion::findMany(options);
	//for(int i=0;i<list->size();i++)
	//{
	//	regions.push_back(list->at(i)->getName());
	//}
}
