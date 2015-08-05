#include "stdafx.h"
#include "BaseDao.h"

BaseDao::~BaseDao()
{

}

BaseDao::BaseDao()
{
}

DaoManagerPrt BaseDao::Dao()
{
	return DaoManager::GetInstance();
}
