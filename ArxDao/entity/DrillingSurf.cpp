#include "stdafx.h"
#include "DrillingSurf.h"
#include "Coal.h"
#include "Tunnel.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

DrillingSurf::DrillingSurf()
{
	drilling_surf_id = 0;
	q_r = 0.0;
	q_a = 0.0;
	tw_q4 = 0.0;
	comment = "NULL";
}

DrillingSurf::DrillingSurf(long id)
{
	drilling_surf_id = id;
	q_r = 0.0;
	q_a = 0.0;
	tw_q4 = 0.0;
	comment = "NULL";
}

DrillingSurf::DrillingSurf(soci::row &rs)
{
	drilling_surf_id = rs.get<long>(0);
	long coal_id = rs.get<long>(1);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	long tunnel_id = rs.get<long>(2);
	if(tunnel_id > -1) {
		tunnel = TunnelPtr(new Tunnel(tunnel_id));
	}
	q_r = rs.get<double>(3);
	q_a = rs.get<double>(4);
	tw_q4 = rs.get<double>(5);
	comment = rs.get<std::string>(6);
}

std::string DrillingSurf::getTableName() const
{
	return "cbm_drilling_surf";
}

std::string DrillingSurf::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_drilling_surf values("
		<<"NULL"<<","
		<<coal->getId()<<","
		<<tunnel->getId()<<","
		<<q_r<<","
		<<q_a<<","
		<<tw_q4<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string DrillingSurf::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_drilling_surf set"
		<<" coal_id="<<coal->getId()<<","
		<<" tunnel_id="<<tunnel->getId()<<","
		<<" q_r="<<q_r<<","
		<<" q_a="<<q_a<<","
		<<" tw_q4="<<tw_q4<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where drilling_surf_id="<<drilling_surf_id
		<<" ;";
	return sql.str();
}

std::string DrillingSurf::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_drilling_surf"
		<<" where drilling_surf_id="<<drilling_surf_id
		<<" ;";
	return sql.str();
}

long DrillingSurf::getId() const
{
	return drilling_surf_id;
}

void DrillingSurf::setId(const long& value)
{
	this->drilling_surf_id = value;
}

CoalPtr DrillingSurf::getCoal() const
{
	return coal;
}

void DrillingSurf::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

TunnelPtr DrillingSurf::getTunnel() const
{
	return tunnel;
}

void DrillingSurf::setTunnel(const TunnelPtr& value)
{
	this->tunnel = value;
}

double DrillingSurf::getQR() const
{
	return q_r;
}

void DrillingSurf::setQR(const double& value)
{
	this->q_r = value;
}

double DrillingSurf::getQA() const
{
	return q_a;
}

void DrillingSurf::setQA(const double& value)
{
	this->q_a = value;
}

double DrillingSurf::getTwQ4() const
{
	return tw_q4;
}

void DrillingSurf::setTwQ4(const double& value)
{
	this->tw_q4 = value;
}

std::string DrillingSurf::getComment() const
{
	return comment;
}

void DrillingSurf::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
