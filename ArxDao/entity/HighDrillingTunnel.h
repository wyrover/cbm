#ifndef CBM_HIGH_DRILLING_TUNNEL_H
#define CBM_HIGH_DRILLING_TUNNEL_H

#include "common.h"
#include <row.h>

namespace cbm {

class HighDrillingTunnel
{
public:
	HighDrillingTunnel();
	HighDrillingTunnel(long id);
	HighDrillingTunnel(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	WorkSurfPtr getWorkSurf() const;
	void setWorkSurf(const WorkSurfPtr& value);
	double getHdtK() const;
	void setHdtK(const double& value);
	long getHdtRock() const;
	void setHdtRock(const long& value);
	double getHdtHzMin() const;
	void setHdtHzMin(const double& value);
	double getHdtHzMax() const;
	void setHdtHzMax(const double& value);

private:
	long high_drilling_tunnel_id;
	WorkSurfPtr work_surf;
	double hdt_k;
	long hdt_rock;
	double hdt_hz_min;
	double hdt_hz_max;

}; // class HighDrillingTunnel

} // namespace cbm

#endif // CBM_HIGH_DRILLING_TUNNEL_H
