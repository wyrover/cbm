#include "stdafx.h"
#include "DrillingSurfDao.h"

namespace cbm {

DrillingSurfDao::DrillingSurfDao() : ModelDao()
{
}

DrillingSurfDao::~DrillingSurfDao()
{
}

long DrillingSurfDao::insert(DrillingSurf& obj)
{
	return dao->insert(obj);
}

bool DrillingSurfDao::update(DrillingSurf& obj)
{
	return dao->update(obj);
}

bool DrillingSurfDao::remove(DrillingSurf& obj)
{
	return dao->remove(obj);
}

DrillingSurfPtr DrillingSurfDao::getDrillingSurfById(long id)
{
	DrillingSurfList list = dao->select<DrillingSurf>("cbm_drilling_surf", "*", "where id="+to_string(id));
	DrillingSurfPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

DrillingSurfList DrillingSurfDao::getDrillingSurfList()
{
	return dao->select<DrillingSurf>("cbm_drilling_surf", "*", "order by DrillingSurf_id desc");
}

} // namespace cbm
