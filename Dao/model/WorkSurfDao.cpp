#include "WorkSurfDao.h"

namespace cbm {

WorkSurfDao::WorkSurfDao() : ModelDao()
{
}

WorkSurfDao::~WorkSurfDao()
{
}

long WorkSurfDao::insert(WorkSurf& obj)
{
	return dao->insert(obj);
}

bool WorkSurfDao::update(WorkSurf& obj)
{
	return dao->update(obj);
}

bool WorkSurfDao::remove(WorkSurf& obj)
{
	return dao->remove(obj);
}

WorkSurfPtr WorkSurfDao::getWorkSurfById(long id)
{
	WorkSurfList list = dao->select<WorkSurf>("cbm_work_surf", "*", "where id="+to_string(id));
	WorkSurfPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

WorkSurfList WorkSurfDao::getWorkSurfList()
{
	return dao->select<WorkSurf>("cbm_work_surf", "*", "order by WorkSurf_id desc");
}

} // namespace cbm
