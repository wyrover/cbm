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
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MiningAreaPtr getMiningArea() const;
	void setMiningArea(const MiningAreaPtr& value);
	TunnelPtr getTunnel() const;
	void setTunnel(const TunnelPtr& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long ready_tunnel_id;
	MiningAreaPtr mining_area;
	TunnelPtr tunnel;
	std::string comment;

}; // class ReadyTunnel

} // namespace cbm

#endif // CBM_READY_TUNNEL_H
