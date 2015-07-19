#ifndef CBM_READY_TUNNEL_H
#define CBM_READY_TUNNEL_H

#include "common.h"
#include <row.h>

namespace cbm {

class ReadyTunnel
{
public:
	ReadyTunnel();
	ReadyTunnel(long id);
	ReadyTunnel(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MiningAreaPtr getMiningArea() const;
	void setMiningArea(const MiningAreaPtr& value);
	double getRtL() const;
	void setRtL(const double& value);
	long getRtMethod() const;
	void setRtMethod(const long& value);
	double getRtB() const;
	void setRtB(const double& value);
	double getRtWh() const;
	void setRtWh(const double& value);

private:
	long ready_tunnel_id;
	MiningAreaPtr mining_area;
	double rt_l;
	long rt_method;
	double rt_b;
	double rt_wh;

}; // class ReadyTunnel

} // namespace cbm

#endif // CBM_READY_TUNNEL_H
