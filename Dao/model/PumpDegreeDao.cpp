#include "PumpDegreeDao.h"

namespace cbm {

PumpDegreeDao::PumpDegreeDao() : ModelDao()
{
}

PumpDegreeDao::~PumpDegreeDao()
{
}

long PumpDegreeDao::insert(PumpDegree& obj)
{
	return dao->insert(obj);
}

bool PumpDegreeDao::update(PumpDegree& obj)
{
	return dao->update(obj);
}

bool PumpDegreeDao::remove(PumpDegree& obj)
{
	return dao->remove(obj);
}

PumpDegreePtr PumpDegreeDao::getPumpDegreeById(long id)
{
	PumpDegreeList list = dao->select<PumpDegree>("cbm_pump_degree", "*", "where id="+to_string(id));
	PumpDegreePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

PumpDegreeList PumpDegreeDao::getPumpDegreeList()
{
	return dao->select<PumpDegree>("cbm_pump_degree", "*", "order by PumpDegree_id desc");
}

} // namespace cbm
