#include "stdafx.h"
#include "KeyLayerDao.h"

namespace cbm {

KeyLayerDao::KeyLayerDao() : ModelDao()
{
}

KeyLayerDao::~KeyLayerDao()
{
}

long KeyLayerDao::insert(KeyLayer& obj)
{
	return dao->insert(obj);
}

bool KeyLayerDao::update(KeyLayer& obj)
{
	return dao->update(obj);
}

bool KeyLayerDao::remove(KeyLayer& obj)
{
	return dao->remove(obj);
}

KeyLayerPtr KeyLayerDao::getKeyLayerById(long id)
{
	KeyLayerList list = dao->select<KeyLayer>("cbm_key_layer", "*", "where id="+to_string(id));
	KeyLayerPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

KeyLayerList KeyLayerDao::getKeyLayerList()
{
	return dao->select<KeyLayer>("cbm_key_layer", "*", "order by KeyLayer_id desc");
}

} // namespace cbm
