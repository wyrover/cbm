#ifndef CBM_WORK_SURF_DAO_H
#define CBM_WORK_SURF_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/WorkSurf.h"

namespace cbm {

class WorkSurfDao : public ModelDao
{
public:
	WorkSurfDao();
	~WorkSurfDao();
	long insert(WorkSurf& obj);;
	bool update(WorkSurf& obj);
	bool remove(WorkSurf& obj);
	WorkSurfPtr getWorkSurfById(long id);
	WorkSurfList getWorkSurfList();

}; // class WorkSurfDao

} // namespace cbm

#endif // CBM_WORK_SURF_DAO_H
