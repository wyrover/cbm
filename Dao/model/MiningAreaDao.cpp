#include "MiningAreaDao.h"

namespace cbm {

MiningAreaDao::MiningAreaDao() : ModelDao()
{
}

MiningAreaDao::~MiningAreaDao()
{
}

long MiningAreaDao::insert(MiningArea& obj)
{
	return dao->insert(obj);
}

bool MiningAreaDao::update(MiningArea& obj)
{
	return dao->update(obj);
}

bool MiningAreaDao::remove(MiningArea& obj)
{
	return dao->remove(obj);
}

MiningAreaPtr MiningAreaDao::getMiningAreaById(long id)
{
	MiningAreaList list = dao->select<MiningArea>("cbm_mining_area", "*", "where id="+to_string(id));
	MiningAreaPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

MiningAreaList MiningAreaDao::getMiningAreaList()
{
	return dao->select<MiningArea>("cbm_mining_area", "*", "order by MiningArea_id desc");
}

} // namespace cbm
