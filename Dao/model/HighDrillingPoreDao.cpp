#include "HighDrillingPoreDao.h"

namespace cbm {

HighDrillingPoreDao::HighDrillingPoreDao() : ModelDao()
{
}

HighDrillingPoreDao::~HighDrillingPoreDao()
{
}

long HighDrillingPoreDao::insert(HighDrillingPore& obj)
{
	return dao->insert(obj);
}

bool HighDrillingPoreDao::update(HighDrillingPore& obj)
{
	return dao->update(obj);
}

bool HighDrillingPoreDao::remove(HighDrillingPore& obj)
{
	return dao->remove(obj);
}

HighDrillingPorePtr HighDrillingPoreDao::getHighDrillingPoreById(long id)
{
	HighDrillingPoreList list = dao->select<HighDrillingPore>("cbm_high_drilling_pore", "*", "where id="+to_string(id));
	HighDrillingPorePtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

HighDrillingPoreList HighDrillingPoreDao::getHighDrillingPoreList()
{
	return dao->select<HighDrillingPore>("cbm_high_drilling_pore", "*", "order by HighDrillingPore_id desc");
}

} // namespace cbm
