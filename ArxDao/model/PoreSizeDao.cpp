#include "stdafx.h"
#include "PoreSizeDao.h"

namespace cbm {

PoreSizeDao::PoreSizeDao() : ModelDao()
{
}

PoreSizeDao::~PoreSizeDao()
{
}

long PoreSizeDao::insert(PoreSize& obj)
{
	return dao->insert(obj);
}

bool PoreSizeDao::update(PoreSize& obj)
{
	return dao->update(obj);
}

bool PoreSizeDao::remove(PoreSize& obj)
{
	return dao->remove(obj);
}

PoreSizePtr PoreSizeDao::getPoreSizeById(long id)
{
	PoreSizeList list = dao->select<PoreSize>("cbm_pore_size", "*", "where id="+to_string(id));
	PoreSizePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

PoreSizeList PoreSizeDao::getPoreSizeList()
{
	return dao->select<PoreSize>("cbm_pore_size", "*", "order by PoreSize_id desc");
}

} // namespace cbm
