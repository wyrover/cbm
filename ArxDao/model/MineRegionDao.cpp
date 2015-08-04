#include "stdafx.h"
#include "MineRegionDao.h"

namespace cbm {

MineRegionDao::MineRegionDao() : ModelDao()
{
}

MineRegionDao::~MineRegionDao()
{
}

long MineRegionDao::insert(MineRegion& obj)
{
	return dao->insert(obj);
}

bool MineRegionDao::update(MineRegion& obj)
{
	return dao->update(obj);
}

bool MineRegionDao::remove(MineRegion& obj)
{
	return dao->remove(obj);
}

MineRegionPtr MineRegionDao::getMineRegionById(long id)
{
	MineRegionList list = dao->select<MineRegion>("cmb_mine_region", "*", "where id="+to_string(id));
	MineRegionPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

MineRegionList MineRegionDao::getMineRegionList()
{
	return dao->select<MineRegion>("cmb_mine_region", "*", "order by MineRegion_id desc");
}

} // namespace cbm
