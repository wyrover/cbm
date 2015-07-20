#include "stdafx.h"
#include "GasReserveDao.h"

namespace cbm {

GasReserveDao::GasReserveDao() : ModelDao()
{
}

GasReserveDao::~GasReserveDao()
{
}

long GasReserveDao::insert(GasReserve& obj)
{
	return dao->insert(obj);
}

bool GasReserveDao::update(GasReserve& obj)
{
	return dao->update(obj);
}

bool GasReserveDao::remove(GasReserve& obj)
{
	return dao->remove(obj);
}

GasReservePtr GasReserveDao::getGasReserveById(long id)
{
	GasReserveList list = dao->select<GasReserve>("cbm_gas_reserve", "*", "where id="+to_string(id));
	GasReservePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

GasReserveList GasReserveDao::getGasReserveList()
{
	return dao->select<GasReserve>("cbm_gas_reserve", "*", "order by GasReserve_id desc");
}

} // namespace cbm
