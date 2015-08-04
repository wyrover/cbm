#include "stdafx.h"
#include "TechnologyDao.h"

namespace cbm {

TechnologyDao::TechnologyDao() : ModelDao()
{
}

TechnologyDao::~TechnologyDao()
{
}

long TechnologyDao::insert(Technology& obj)
{
	return dao->insert(obj);
}

bool TechnologyDao::update(Technology& obj)
{
	return dao->update(obj);
}

bool TechnologyDao::remove(Technology& obj)
{
	return dao->remove(obj);
}

TechnologyPtr TechnologyDao::getTechnologyById(long id)
{
	TechnologyList list = dao->select<Technology>("cbm_technology", "*", "where id="+to_string(id));
	TechnologyPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

TechnologyList TechnologyDao::getTechnologyList()
{
	return dao->select<Technology>("cbm_technology", "*", "order by Technology_id desc");
}

} // namespace cbm
