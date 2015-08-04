#ifndef CBM_COAL_LAYER_DAO_H
#define CBM_COAL_LAYER_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/CoalLayer.h"

namespace cbm {

class CoalLayerDao : public ModelDao
{
public:
	CoalLayerDao();
	~CoalLayerDao();
	long insert(CoalLayer& obj);;
	bool update(CoalLayer& obj);
	bool remove(CoalLayer& obj);
	CoalLayerPtr getCoalLayerById(long id);
	CoalLayerList getCoalLayerList();

}; // class CoalLayerDao

} // namespace cbm

#endif // CBM_COAL_LAYER_DAO_H
