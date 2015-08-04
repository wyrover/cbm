#include "stdafx.h"
#include "HydrGeoDao.h"

namespace cbm {

HydrGeoDao::HydrGeoDao() : ModelDao()
{
}

HydrGeoDao::~HydrGeoDao()
{
}

long HydrGeoDao::insert(HydrGeo& obj)
{
	return dao->insert(obj);
}

bool HydrGeoDao::update(HydrGeo& obj)
{
	return dao->update(obj);
}

bool HydrGeoDao::remove(HydrGeo& obj)
{
	return dao->remove(obj);
}

HydrGeoPtr HydrGeoDao::getHydrGeoById(long id)
{
	HydrGeoList list = dao->select<HydrGeo>("cbm_hydr_geo", "*", "where id="+to_string(id));
	HydrGeoPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

HydrGeoList HydrGeoDao::getHydrGeoList()
{
	return dao->select<HydrGeo>("cbm_hydr_geo", "*", "order by HydrGeo_id desc");
}

} // namespace cbm
