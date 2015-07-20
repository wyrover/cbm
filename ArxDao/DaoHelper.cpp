#include "StdAfx.h"
#include "DaoHelper.h"

#include "../ArxHelper/HelperClass.h"
#include "../Dao/entity/entities.h"
#include "../Dao/model/models.h"

using namespace cbm;

void DaoHelper::ConfigureDao(const string& url, const string& user, const string& password, const string& dataBase)
{
	Dao::Configure(url, user, password, dataBase);
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
