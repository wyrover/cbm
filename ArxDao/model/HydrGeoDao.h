#ifndef CBM_HYDR_GEO_DAO_H
#define CBM_HYDR_GEO_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/HydrGeo.h"

namespace cbm {

class HydrGeoDao : public ModelDao
{
public:
	HydrGeoDao();
	~HydrGeoDao();
	long insert(HydrGeo& obj);;
	bool update(HydrGeo& obj);
	bool remove(HydrGeo& obj);
	HydrGeoPtr getHydrGeoById(long id);
	HydrGeoList getHydrGeoList();

}; // class HydrGeoDao

} // namespace cbm

#endif // CBM_HYDR_GEO_DAO_H
