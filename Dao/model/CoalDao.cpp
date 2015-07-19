#include "CoalDao.h"

namespace cbm {

CoalDao::CoalDao() : ModelDao()
{
}

CoalDao::~CoalDao()
{
}

long CoalDao::insert(Coal& obj)
{
	return dao->insert(obj);
}

bool CoalDao::update(Coal& obj)
{
	return dao->update(obj);
}

bool CoalDao::remove(Coal& obj)
{
	return dao->remove(obj);
}

CoalPtr CoalDao::getCoalById(long id)
{
	CoalList list = dao->select<Coal>("cbm_coal", "*", "where id="+to_string(id));
	CoalPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

CoalList CoalDao::getCoalList()
{
	return dao->select<Coal>("cbm_coal", "*", "order by Coal_id desc");
}

} // namespace cbm
