#include "stdafx.h"
#include "ReadyTunnel.h"
#include "MiningArea.h"
#include "Tunnel.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

ReadyTunnel::ReadyTunnel()
{
	ready_tunnel_id = 0;
	comment = "NULL";
}

ReadyTunnel::ReadyTunnel(long id)
{
	ready_tunnel_id = id;
	comment = "NULL";
}

ReadyTunnel::ReadyTunnel(soci::row &rs)
{
	ready_tunnel_id = rs.get<long>(0);
	long mining_area_id = rs.get<long>(1);
	if(mining_area_id > -1) {
		mining_area = MiningAreaPtr(new MiningArea(mining_area_id));
	}
	long tunnel_id = rs.get<long>(2);
	if(tunnel_id > -1) {
		tunnel = TunnelPtr(new Tunnel(tunnel_id));
	}
	comment = rs.get<std::string>(3);
}

std::string ReadyTunnel::getTableName() const
{
	return "cbm_ready_tunnel";
}

std::string ReadyTunnel::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_ready_tunnel values("
		<<"NULL"<<","
		<<mining_area->getId()<<","
		<<tunnel->getId()<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string ReadyTunnel::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_ready_tunnel set"
		<<" mining_area_id="<<mining_area->getId()<<","
		<<" tunnel_id="<<tunnel->getId()<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where ready_tunnel_id="<<ready_tunnel_id
		<<" ;";
	return sql.str();
}

std::string ReadyTunnel::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_ready_tunnel"
		<<" where ready_tunnel_id="<<ready_tunnel_id
		<<" ;";
	return sql.str();
}

long ReadyTunnel::getId() const
{
	return ready_tunnel_id;
}

void ReadyTunnel::setId(const long& value)
{
	this->ready_tunnel_id = value;
}

MiningAreaPtr ReadyTunnel::getMiningArea() const
{
	return mining_area;
}

void ReadyTunnel::setMiningArea(const MiningAreaPtr& value)
{
	this->mining_area = value;
}

TunnelPtr ReadyTunnel::getTunnel() const
{
	return tunnel;
}

void ReadyTunnel::setTunnel(const TunnelPtr& value)
{
	this->tunnel = value;
}

std::string ReadyTunnel::getComment() const
{
	return comment;
}

void ReadyTunnel::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
