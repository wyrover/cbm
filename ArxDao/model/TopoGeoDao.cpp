#include "stdafx.h"
#include "TopoGeoDao.h"

namespace cbm {

TopoGeoDao::TopoGeoDao() : ModelDao()
{
}

TopoGeoDao::~TopoGeoDao()
{
}

long TopoGeoDao::insert(TopoGeo& obj)
{
	return dao->insert(obj);
}

bool TopoGeoDao::update(TopoGeo& obj)
{
	return dao->update(obj);
}

bool TopoGeoDao::remove(TopoGeo& obj)
{
	return dao->remove(obj);
}

TopoGeoPtr TopoGeoDao::getTopoGeoById(long id)
{
	TopoGeoList list = dao->select<TopoGeo>("cbm_topo_geo", "*", "where id="+to_string(id));
	TopoGeoPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

TopoGeoList TopoGeoDao::getTopoGeoList()
{
	return dao->select<TopoGeo>("cbm_topo_geo", "*", "order by TopoGeo_id desc");
}

} // namespace cbm
