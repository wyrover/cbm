#ifndef CBM_KEY_LAYER_DAO_H
#define CBM_KEY_LAYER_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/KeyLayer.h"

namespace cbm {

class KeyLayerDao : public ModelDao
{
public:
	KeyLayerDao();
	~KeyLayerDao();
	long insert(KeyLayer& obj);;
	bool update(KeyLayer& obj);
	bool remove(KeyLayer& obj);
	KeyLayerPtr getKeyLayerById(long id);
	KeyLayerList getKeyLayerList();

}; // class KeyLayerDao

} // namespace cbm

#endif // CBM_KEY_LAYER_DAO_H
