#include "stdafx.h"
#include "ReadyTunnel.h"
#include "MiningArea.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

ReadyTunnel::ReadyTunnel()
{
	ready_tunnel_id = 0;
	rt_l = 0.0;
	rt_method = 0;
	rt_b = 0.0;
	rt_wh = 0.0;
}

ReadyTunnel::ReadyTunnel(long id)
{
	ready_tunnel_id = id;
	rt_l = 0.0;
	rt_method = 0;
	rt_b = 0.0;
	rt_wh = 0.0;
}

ReadyTunnel::ReadyTunnel(soci::row &rs)
{
	ready_tunnel_id = rs.get<long>(0);
	long mining_area_id = rs.get<long>(1);
	if(mining_area_id > -1) {
		mining_area = MiningAreaPtr(new MiningArea(mining_area_id));
	}
	rt_l = rs.get<double>(2);
	rt_method = rs.get<long>(3);
	rt_b = rs.get<double>(4);
	rt_wh = rs.get<double>(5);
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
		<<rt_l<<","
		<<rt_method<<","
		<<rt_b<<","
		<<rt_wh<<");";
	return sql.str();
}

std::string ReadyTunnel::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_ready_tunnel set"
		<<" mining_area_id="<<mining_area->getId()<<","
		<<" rt_l="<<rt_l<<","
		<<" rt_method="<<rt_method<<","
		<<" rt_b="<<rt_b<<","
		<<" rt_wh="<<rt_wh
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

double ReadyTunnel::getRtL() const
{
	return rt_l;
}

void ReadyTunnel::setRtL(const double& value)
{
	this->rt_l = value;
}

long ReadyTunnel::getRtMethod() const
{
	return rt_method;
}

void ReadyTunnel::setRtMethod(const long& value)
{
	this->rt_method = value;
}

double ReadyTunnel::getRtB() const
{
	return rt_b;
}

void ReadyTunnel::setRtB(const double& value)
{
	this->rt_b = value;
}

double ReadyTunnel::getRtWh() const
{
	return rt_wh;
}

void ReadyTunnel::setRtWh(const double& value)
{
	this->rt_wh = value;
}

} // namespace cbm
