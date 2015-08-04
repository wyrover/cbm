#ifndef CBM_HYDR_GEO_H
#define CBM_HYDR_GEO_H

#include "common.h"
#include <row.h>

namespace cbm {

class HydrGeo
{
public:
	HydrGeo();
	HydrGeo(long id);
	HydrGeo(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	std::string getType() const;
	void setType(const std::string& value);
	long getX1() const;
	void setX1(const long& value);
	double getX2() const;
	void setX2(const double& value);
	long getX3() const;
	void setX3(const long& value);
	double getX4() const;
	void setX4(const double& value);
	double getX5() const;
	void setX5(const double& value);
	double getX6() const;
	void setX6(const double& value);
	double getX7() const;
	void setX7(const double& value);
	std::string getX8() const;
	void setX8(const std::string& value);

private:
	long hydr_geo_id;
	std::string type;
	long x1;
	double x2;
	long x3;
	double x4;
	double x5;
	double x6;
	double x7;
	std::string x8;

}; // class HydrGeo

} // namespace cbm

#endif // CBM_HYDR_GEO_H
