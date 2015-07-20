#ifndef CBM_DRILLING_SURF_DAO_H
#define CBM_DRILLING_SURF_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/DrillingSurf.h"

namespace cbm {

class DrillingSurfDao : public ModelDao
{
public:
	DrillingSurfDao();
	~DrillingSurfDao();
	long insert(DrillingSurf& obj);;
	bool update(DrillingSurf& obj);
	bool remove(DrillingSurf& obj);
	DrillingSurfPtr getDrillingSurfById(long id);
	DrillingSurfList getDrillingSurfList();

}; // class DrillingSurfDao

} // namespace cbm

#endif // CBM_DRILLING_SURF_DAO_H
