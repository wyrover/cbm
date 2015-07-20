#ifndef CBM_PUMP_DEGREE_DAO_H
#define CBM_PUMP_DEGREE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/PumpDegree.h"

namespace cbm {

class PumpDegreeDao : public ModelDao
{
public:
	PumpDegreeDao();
	~PumpDegreeDao();
	long insert(PumpDegree& obj);;
	bool update(PumpDegree& obj);
	bool remove(PumpDegree& obj);
	PumpDegreePtr getPumpDegreeById(long id);
	PumpDegreeList getPumpDegreeList();

}; // class PumpDegreeDao

} // namespace cbm

#endif // CBM_PUMP_DEGREE_DAO_H
