#include "stdafx.h"
#include "GasPumpDao.h"

namespace cbm {

GasPumpDao::GasPumpDao() : ModelDao()
{
}

GasPumpDao::~GasPumpDao()
{
}

long GasPumpDao::insert(GasPump& obj)
{
	return dao->insert(obj);
}

bool GasPumpDao::update(GasPump& obj)
{
	return dao->update(obj);
}

bool GasPumpDao::remove(GasPump& obj)
{
	return dao->remove(obj);
}

GasPumpPtr GasPumpDao::getGasPumpById(long id)
{
	GasPumpList list = dao->select<GasPump>("cbm_gas_pump", "*", "where id="+to_string(id));
	GasPumpPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

GasPumpList GasPumpDao::getGasPumpList()
{
	return dao->select<GasPump>("cbm_gas_pump", "*", "order by GasPump_id desc");
}

} // namespace cbm
