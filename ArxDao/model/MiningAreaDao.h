#ifndef CBM_MINING_AREA_DAO_H
#define CBM_MINING_AREA_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/MiningArea.h"

namespace cbm {

class MiningAreaDao : public ModelDao
{
public:
	MiningAreaDao();
	~MiningAreaDao();
	long insert(MiningArea& obj);;
	bool update(MiningArea& obj);
	bool remove(MiningArea& obj);
	MiningAreaPtr getMiningAreaById(long id);
	MiningAreaList getMiningAreaList();

}; // class MiningAreaDao

} // namespace cbm

#endif // CBM_MINING_AREA_DAO_H
