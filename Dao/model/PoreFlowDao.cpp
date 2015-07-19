#include "PoreFlowDao.h"

namespace cbm {

PoreFlowDao::PoreFlowDao() : ModelDao()
{
}

PoreFlowDao::~PoreFlowDao()
{
}

long PoreFlowDao::insert(PoreFlow& obj)
{
	return dao->insert(obj);
}

bool PoreFlowDao::update(PoreFlow& obj)
{
	return dao->update(obj);
}

bool PoreFlowDao::remove(PoreFlow& obj)
{
	return dao->remove(obj);
}

PoreFlowPtr PoreFlowDao::getPoreFlowById(long id)
{
	PoreFlowList list = dao->select<PoreFlow>("cbm_pore_flow", "*", "where id="+to_string(id));
	PoreFlowPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

PoreFlowList PoreFlowDao::getPoreFlowList()
{
	return dao->select<PoreFlow>("cbm_pore_flow", "*", "order by PoreFlow_id desc");
}

} // namespace cbm
