#ifndef CBM_DRILLING_SURF_H
#define CBM_DRILLING_SURF_H

#include "common.h"
#include <row.h>

namespace cbm {

class DrillingSurf
{
public:
	DrillingSurf();
	DrillingSurf(long id);
	DrillingSurf(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	TunnelPtr getTunnel() const;
	void setTunnel(const TunnelPtr& value);
	double getQR() const;
	void setQR(const double& value);
	double getQA() const;
	void setQA(const double& value);
	double getTwQ4() const;
	void setTwQ4(const double& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long drilling_surf_id;
	CoalPtr coal;
	TunnelPtr tunnel;
	double q_r;
	double q_a;
	double tw_q4;
	std::string comment;

}; // class DrillingSurf

} // namespace cbm

#endif // CBM_DRILLING_SURF_H
