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
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	TunnelPtr getTunnel() const;
	void setTunnel(const TunnelPtr& value);
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
	long getWsLayerable() const;
	void setWsLayerable(const long& value);
	double getWsK1() const;
	void setWsK1(const double& value);
	double getWsK2() const;
	void setWsK2(const double& value);
	double getWsK3() const;
	void setWsK3(const double& value);
	double getWsKf() const;
	void setWsKf(const double& value);
	double getWsH() const;
	void setWsH(const double& value);
	long getWsMethod() const;
	void setWsMethod(const long& value);
	double getLastT() const;
	void setLastT(const double& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long work_surf_id;
	TunnelPtr tunnel;
	CoalPtr coal;
	double a;
	double q_r;
	double q_a;
	double ws_l;
	long ws_layerable;
	double ws_k1;
	double ws_k2;
	double ws_k3;
	double ws_kf;
	double ws_h;
	long ws_method;
	double last_t;
	std::string comment;

}; // class WorkSurf

} // namespace cbm

#endif // CBM_WORK_SURF_H
