#include "RecomTechDao.h"

namespace cbm {

RecomTechDao::RecomTechDao() : ModelDao()
{
}

RecomTechDao::~RecomTechDao()
{
}

long RecomTechDao::insert(RecomTech& obj)
{
	return dao->insert(obj);
}

bool RecomTechDao::update(RecomTech& obj)
{
	return dao->update(obj);
}

bool RecomTechDao::remove(RecomTech& obj)
{
	return dao->remove(obj);
}

RecomTechPtr RecomTechDao::getRecomTechById(long id)
{
	RecomTechList list = dao->select<RecomTech>("cbm_recom_tech", "*", "where id="+to_string(id));
	RecomTechPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

RecomTechList RecomTechDao::getRecomTechList()
{
	return dao->select<RecomTech>("cbm_recom_tech", "*", "order by RecomTech_id desc");
}

} // namespace cbm
