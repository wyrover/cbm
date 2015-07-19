#include "AdjLayerDao.h"

namespace cbm {

AdjLayerDao::AdjLayerDao() : ModelDao()
{
}

AdjLayerDao::~AdjLayerDao()
{
}

long AdjLayerDao::insert(AdjLayer& obj)
{
	return dao->insert(obj);
}

bool AdjLayerDao::update(AdjLayer& obj)
{
	return dao->update(obj);
}

bool AdjLayerDao::remove(AdjLayer& obj)
{
	return dao->remove(obj);
}

AdjLayerPtr AdjLayerDao::getAdjLayerById(long id)
{
	AdjLayerList list = dao->select<AdjLayer>("cbm_adj_layer", "*", "where id="+to_string(id));
	AdjLayerPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

AdjLayerList AdjLayerDao::getAdjLayerList()
{
	return dao->select<AdjLayer>("cbm_adj_layer", "*", "order by AdjLayer_id desc");
}

} // namespace cbm
