#include "stdafx.h"
#include "MineBaseDao.h"

namespace cbm {

MineBaseDao::MineBaseDao() : ModelDao()
{
}

MineBaseDao::~MineBaseDao()
{
}

long MineBaseDao::insert(MineBase& obj)
{
	return dao->insert(obj);
}

bool MineBaseDao::update(MineBase& obj)
{
	return dao->update(obj);
}

bool MineBaseDao::remove(MineBase& obj)
{
	return dao->remove(obj);
}

MineBasePtr MineBaseDao::getMineBaseById(long id)
{
	MineBaseList list = dao->select<MineBase>("cbm_mine_base", "*", "where id="+to_string(id));
	MineBasePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

MineBaseList MineBaseDao::getMineBaseList()
{
	return dao->select<MineBase>("cbm_mine_base", "*", "order by MineBase_id desc");
}

} // namespace cbm
