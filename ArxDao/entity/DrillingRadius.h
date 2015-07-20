#ifndef CBM_DRILLING_RADIUS_H
#define CBM_DRILLING_RADIUS_H

#include "common.h"
#include <row.h>

namespace cbm {

class DrillingRadius
{
public:
	DrillingRadius();
	DrillingRadius(long id);
	DrillingRadius(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	double getRadiusR() const;
	void setRadiusR(const double& value);
	double getRadiusL() const;
	void setRadiusL(const double& value);
	double getRadiusK1() const;
	void setRadiusK1(const double& value);
	double getRadiusRho() const;
	void setRadiusRho(const double& value);
	double getRadiusQ0() const;
	void setRadiusQ0(const double& value);
	double getRadiusA() const;
	void setRadiusA(const double& value);
	double getRadiusT() const;
	void setRadiusT(const double& value);
	double getRadiusQm1() const;
	void setRadiusQm1(const double& value);
	double getRadiusQm2() const;
	void setRadiusQm2(const double& value);
	double getRadiusQsum() const;
	void setRadiusQsum(const double& value);
	double getRadiusEta() const;
	void setRadiusEta(const double& value);

private:
	long drilling_radius_id;
	CoalPtr coal;
	double radius_r;
	double radius_l;
	double radius_k1;
	double radius_rho;
	double radius_q0;
	double radius_a;
	double radius_t;
	double radius_qm1;
	double radius_qm2;
	double radius_qsum;
	double radius_eta;

}; // class DrillingRadius

} // namespace cbm

#endif // CBM_DRILLING_RADIUS_H
