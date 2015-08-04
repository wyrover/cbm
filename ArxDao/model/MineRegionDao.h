#ifndef CMB_MINE_REGION_DAO_H
#define CMB_MINE_REGION_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/MineRegion.h"

namespace cbm {

class MineRegionDao : public ModelDao
{
public:
	MineRegionDao();
	~MineRegionDao();
	long insert(MineRegion& obj);;
	bool update(MineRegion& obj);
	bool remove(MineRegion& obj);
	MineRegionPtr getMineRegionById(long id);
	MineRegionList getMineRegionList();

}; // class MineRegionDao

} // namespace cbm

#endif // CMB_MINE_REGION_DAO_H
