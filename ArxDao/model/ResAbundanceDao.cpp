#include "stdafx.h"
#include "ResAbundanceDao.h"

namespace cbm {

ResAbundanceDao::ResAbundanceDao() : ModelDao()
{
}

ResAbundanceDao::~ResAbundanceDao()
{
}

long ResAbundanceDao::insert(ResAbundance& obj)
{
	return dao->insert(obj);
}

bool ResAbundanceDao::update(ResAbundance& obj)
{
	return dao->update(obj);
}

bool ResAbundanceDao::remove(ResAbundance& obj)
{
	return dao->remove(obj);
}

ResAbundancePtr ResAbundanceDao::getResAbundanceById(long id)
{
	ResAbundanceList list = dao->select<ResAbundance>("cbm_res_abundance", "*", "where id="+to_string(id));
	ResAbundancePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

ResAbundanceList ResAbundanceDao::getResAbundanceList()
{
	return dao->select<ResAbundance>("cbm_res_abundance", "*", "order by ResAbundance_id desc");
}

} // namespace cbm
