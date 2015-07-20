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
	double getQR() const;
	void setQR(const double& value);
	double getQA() const;
	void setQA(const double& value);
	double getTwD() const;
	void setTwD(const double& value);
	double getTwV() const;
	void setTwV(const double& value);
	double getTwL() const;
	void setTwL(const double& value);
	double getTwS() const;
	void setTwS(const double& value);
	double getTwQ3() const;
	void setTwQ3(const double& value);
	double getTwQ4() const;
	void setTwQ4(const double& value);

private:
	long drilling_surf_id;
	CoalPtr coal;
	double q_r;
	double q_a;
	double tw_d;
	double tw_v;
	double tw_l;
	double tw_s;
	double tw_q3;
	double tw_q4;

}; // class DrillingSurf

} // namespace cbm

#endif // CBM_DRILLING_SURF_H
