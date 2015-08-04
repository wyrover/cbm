#ifndef CBM_HIGH_DRILLING_PORE_H
#define CBM_HIGH_DRILLING_PORE_H

#include "common.h"
#include <row.h>

namespace cbm {

class HighDrillingPore
{
public:
	HighDrillingPore();
	HighDrillingPore(long id);
	HighDrillingPore(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	double getHdpL1() const;
	void setHdpL1(const double& value);
	double getHdpL2() const;
	void setHdpL2(const double& value);
	double getHdpLg() const;
	void setHdpLg(const double& value);
	double getHdpHz() const;
	void setHdpHz(const double& value);
	double getHdpLk() const;
	void setHdpLk(const double& value);
	double getHdpLc() const;
	void setHdpLc(const double& value);
	double getHdpLw() const;
	void setHdpLw(const double& value);
	double getHdpN() const;
	void setHdpN(const double& value);
	double getHdpBeta() const;
	void setHdpBeta(const double& value);
	double getHdpLd() const;
	void setHdpLd(const double& value);
	double getHdpLzi() const;
	void setHdpLzi(const double& value);
	double getHdpLzj() const;
	void setHdpLzj(const double& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long high_drilling_pore_id;
	WorkSurfPtr work_surf;
	double hdp_l1;
	double hdp_l2;
	double hdp_lg;
	double hdp_hz;
	double hdp_lk;
	double hdp_lc;
	double hdp_lw;
	double hdp_n;
	double hdp_beta;
	double hdp_ld;
	double hdp_lzi;
	double hdp_lzj;
	std::string comment;

}; // class HighDrillingPore

} // namespace cbm

#endif // CBM_HIGH_DRILLING_PORE_H
