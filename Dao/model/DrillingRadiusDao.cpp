#include "DrillingRadiusDao.h"

namespace cbm {

DrillingRadiusDao::DrillingRadiusDao() : ModelDao()
{
}

DrillingRadiusDao::~DrillingRadiusDao()
{
}

long DrillingRadiusDao::insert(DrillingRadius& obj)
{
	return dao->insert(obj);
}

bool DrillingRadiusDao::update(DrillingRadius& obj)
{
	return dao->update(obj);
}

bool DrillingRadiusDao::remove(DrillingRadius& obj)
{
	return dao->remove(obj);
}

DrillingRadiusPtr DrillingRadiusDao::getDrillingRadiusById(long id)
{
	DrillingRadiusList list = dao->select<DrillingRadius>("cbm_drilling_radius", "*", "where id="+to_string(id));
	DrillingRadiusPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

DrillingRadiusList DrillingRadiusDao::getDrillingRadiusList()
{
	return dao->select<DrillingRadius>("cbm_drilling_radius", "*", "order by DrillingRadius_id desc");
}

} // namespace cbm
