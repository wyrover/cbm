#include "MineDao.h"

namespace cbm {

MineDao::MineDao() : ModelDao()
{
}

MineDao::~MineDao()
{
}

long MineDao::insert(Mine& obj)
{
	return dao->insert(obj);
}

bool MineDao::update(Mine& obj)
{
	return dao->update(obj);
}

bool MineDao::remove(Mine& obj)
{
	return dao->remove(obj);
}

MinePtr MineDao::getMineById(long id)
{
	MineList list = dao->select<Mine>("cbm_mine", "*", "where id="+to_string(id));
	MinePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

MineList MineDao::getMineList()
{
	return dao->select<Mine>("cbm_mine", "*", "order by Mine_id desc");
}

} // namespace cbm
