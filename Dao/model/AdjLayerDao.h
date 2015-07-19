#ifndef CBM_ADJ_LAYER_DAO_H
#define CBM_ADJ_LAYER_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/AdjLayer.h"

namespace cbm {

class AdjLayerDao : public ModelDao
{
public:
	AdjLayerDao();
	~AdjLayerDao();
	long insert(AdjLayer& obj);;
	bool update(AdjLayer& obj);
	bool remove(AdjLayer& obj);
	AdjLayerPtr getAdjLayerById(long id);
	AdjLayerList getAdjLayerList();

}; // class AdjLayerDao

} // namespace cbm

#endif // CBM_ADJ_LAYER_DAO_H
