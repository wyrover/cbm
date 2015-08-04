#ifndef CBM_TOPO_GEO_DAO_H
#define CBM_TOPO_GEO_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/TopoGeo.h"

namespace cbm {

class TopoGeoDao : public ModelDao
{
public:
	TopoGeoDao();
	~TopoGeoDao();
	long insert(TopoGeo& obj);;
	bool update(TopoGeo& obj);
	bool remove(TopoGeo& obj);
	TopoGeoPtr getTopoGeoById(long id);
	TopoGeoList getTopoGeoList();

}; // class TopoGeoDao

} // namespace cbm

#endif // CBM_TOPO_GEO_DAO_H
