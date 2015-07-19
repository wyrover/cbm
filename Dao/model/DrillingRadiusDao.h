#ifndef CBM_DRILLING_RADIUS_DAO_H
#define CBM_DRILLING_RADIUS_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/DrillingRadius.h"

namespace cbm {

class DrillingRadiusDao : public ModelDao
{
public:
	DrillingRadiusDao();
	~DrillingRadiusDao();
	long insert(DrillingRadius& obj);;
	bool update(DrillingRadius& obj);
	bool remove(DrillingRadius& obj);
	DrillingRadiusPtr getDrillingRadiusById(long id);
	DrillingRadiusList getDrillingRadiusList();

}; // class DrillingRadiusDao

} // namespace cbm

#endif // CBM_DRILLING_RADIUS_DAO_H
