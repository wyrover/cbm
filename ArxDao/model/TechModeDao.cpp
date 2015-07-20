#include "stdafx.h"
#include "TechModeDao.h"

namespace cbm {

TechModeDao::TechModeDao() : ModelDao()
{
}

TechModeDao::~TechModeDao()
{
}

long TechModeDao::insert(TechMode& obj)
{
	return dao->insert(obj);
}

bool TechModeDao::update(TechMode& obj)
{
	return dao->update(obj);
}

bool TechModeDao::remove(TechMode& obj)
{
	return dao->remove(obj);
}

TechModePtr TechModeDao::getTechModeById(long id)
{
	TechModeList list = dao->select<TechMode>("cbm_tech_mode", "*", "where id="+to_string(id));
	TechModePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

TechModeList TechModeDao::getTechModeList()
{
	return dao->select<TechMode>("cbm_tech_mode", "*", "order by TechMode_id desc");
}

} // namespace cbm
