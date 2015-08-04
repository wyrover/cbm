#include "stdafx.h"
#include "CoalLayerDao.h"

namespace cbm {

CoalLayerDao::CoalLayerDao() : ModelDao()
{
}

CoalLayerDao::~CoalLayerDao()
{
}

long CoalLayerDao::insert(CoalLayer& obj)
{
	return dao->insert(obj);
}

bool CoalLayerDao::update(CoalLayer& obj)
{
	return dao->update(obj);
}

bool CoalLayerDao::remove(CoalLayer& obj)
{
	return dao->remove(obj);
}

CoalLayerPtr CoalLayerDao::getCoalLayerById(long id)
{
	CoalLayerList list = dao->select<CoalLayer>("cbm_coal_layer", "*", "where id="+to_string(id));
	CoalLayerPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

CoalLayerList CoalLayerDao::getCoalLayerList()
{
	return dao->select<CoalLayer>("cbm_coal_layer", "*", "order by CoalLayer_id desc");
}

} // namespace cbm
