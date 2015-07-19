#ifndef CBM_WORK_SURF_H
#define CBM_WORK_SURF_H

#include "common.h"
#include <row.h>

namespace cbm {

class WorkSurf
{
public:
	WorkSurf();
	WorkSurf(long id);
	WorkSurf(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	double getA() const;
	void setA(const double& value);
	double getQR() const;
	void setQR(const double& value);
	double getQA() const;
	void setQA(const double& value);
	double getWsL() const;
	void setWsL(const double& value);
	long getWsLayer() const;
	void setWsLayer(const long& value);
	double getWsK1() const;
	void setWsK1(const double& value);
	double getWsK2() const;
	void setWsK2(const double& value);
	double getWsK3() const;
	void setWsK3(const double& value);
	double getWsKf() const;
	void setWsKf(const double& value);
	double getCrossL() const;
	void setCrossL(const double& value);
	double getCrossV() const;
	void setCrossV(const double& value);
	double getLastT() const;
	void setLastT(const double& value);

private:
	long work_surf_id;
	CoalPtr coal;
	double a;
	double q_r;
	double q_a;
	double ws_l;
	long ws_layer;
	double ws_k1;
	double ws_k2;
	double ws_k3;
	double ws_kf;
	double cross_l;
	double cross_v;
	double last_t;

}; // class WorkSurf

} // namespace cbm

#endif // CBM_WORK_SURF_H
