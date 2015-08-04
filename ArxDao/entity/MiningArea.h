#ifndef CBM_MINING_AREA_H
#define CBM_MINING_AREA_H

#include "common.h"
#include <row.h>

namespace cbm {

class MiningArea
{
public:
	MiningArea();
	MiningArea(long id);
	MiningArea(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	long getAreaMode() const;
	void setAreaMode(const long& value);
	double getAreaK() const;
	void setAreaK(const double& value);
	double getA() const;
	void setA(const double& value);
	double getQR() const;
	void setQR(const double& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long mining_area_id;
	CoalPtr coal;
	long area_mode;
	double area_k;
	double a;
	double q_r;
	std::string comment;

}; // class MiningArea

} // namespace cbm

#endif // CBM_MINING_AREA_H
