#include "StdAfx.h"
#include "DaoHelper.h"

#include "../Dao/entity/entities.h"
#include "../Dao/model/models.h"

using namespace cbm;

void DaoHelper::ConfigureDao(const string& url, const string& user, const string& password, const string& dataBase)
{
	DaoPrt dao = Dao::getInstance(url, user, password, dataBase);
}

void DaoHelper::TestDao()
{
	Mine mine;
	mine.setUsername("dlj");
	mine.setPassword("123");
	mine.setMineName("½úÃº");

	MineDao dao;
	dao.insert(mine);
}
