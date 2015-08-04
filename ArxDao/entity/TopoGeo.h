#ifndef CBM_TOPO_GEO_H
#define CBM_TOPO_GEO_H

#include "common.h"
#include <row.h>

namespace cbm {

class TopoGeo
{
public:
	TopoGeo();
	TopoGeo(long id);
	TopoGeo(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	std::string getType() const;
	void setType(const std::string& value);
	std::string getFeature() const;
	void setFeature(const std::string& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long topo_geo_id;
	std::string type;
	std::string feature;
	std::string comment;

}; // class TopoGeo

} // namespace cbm

#endif // CBM_TOPO_GEO_H
