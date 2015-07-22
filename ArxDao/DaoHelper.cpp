#include "StdAfx.h"
#include "DaoHelper.h"

#include "entity/entities.h"
#include "model/models.h"
using namespace cbm;

#include "../ArxHelper/HelperClass.h"

void DaoHelper::ConfigureDao(const string& url, const string& user, const string& password, const string& dataBase)
{
	if(!Dao::Configure(url, user, password, dataBase))
	{
		AfxMessageBox(_T("连接MySQL数据库失败，请联系技术人员!!!"));
	}
}

void DaoHelper::TestDao()
{
	Mine mine;
	mine.setUsername("dlj");
	mine.setPassword("123");
	//std::string xx = EncodeHelper::ANSIToUtf8("test晋煤集团");
	mine.setMineName(EncodeHelper::UnicodeToANSI(_T("test晋煤集团")));

	MineDao dao;
	dao.insert(mine);
}
