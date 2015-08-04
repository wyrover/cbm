#include "stdafx.h"
#include "Tunnel.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Tunnel::Tunnel()
{
	tunnel_id = 0;
	b = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	qa = 0.0;
	comment = "NULL";
}

Tunnel::Tunnel(long id)
{
	tunnel_id = id;
	b = 0.0;
	l = 0.0;
	s = 0.0;
	d = 0.0;
	wh = 0.0;
	v = 0.0;
	qa = 0.0;
	comment = "NULL";
}

Tunnel::Tunnel(soci::row &rs)
{
	tunnel_id = rs.get<long>(0);
	b = rs.get<double>(1);
	l = rs.get<double>(2);
	s = rs.get<double>(3);
	d = rs.get<double>(4);
	wh = rs.get<double>(5);
	v = rs.get<double>(6);
	qa = rs.get<double>(7);
	comment = rs.get<std::string>(8);
}

std::string Tunnel::getTableName() const
{
	return "cbm_tunnel";
}

std::string Tunnel::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_tunnel values("
		<<"NULL"<<","
		<<b<<","
		<<l<<","
		<<s<<","
		<<d<<","
		<<wh<<","
		<<v<<","
		<<qa<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string Tunnel::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_tunnel set"
		<<" b="<<b<<","
		<<" l="<<l<<","
		<<" s="<<s<<","
		<<" d="<<d<<","
		<<" wh="<<wh<<","
		<<" v="<<v<<","
		<<" qa="<<qa<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where tunnel_id="<<tunnel_id
		<<" ;";
	return sql.str();
}

std::string Tunnel::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_tunnel"
		<<" where tunnel_id="<<tunnel_id
		<<" ;";
	return sql.str();
}

long Tunnel::getId() const
{
	return tunnel_id;
}

void Tunnel::setId(const long& value)
{
	this->tunnel_id = value;
}

double Tunnel::getB() const
{
	return b;
}

void Tunnel::setB(const double& value)
{
	this->b = value;
}

double Tunnel::getL() const
{
	return l;
}

void Tunnel::setL(const double& value)
{
	this->l = value;
}

double Tunnel::getS() const
{
	return s;
}

void Tunnel::setS(const double& value)
{
	this->s = value;
}

double Tunnel::getD() const
{
	return d;
}

void Tunnel::setD(const double& value)
{
	this->d = value;
}

double Tunnel::getWh() const
{
	return wh;
}

void Tunnel::setWh(const double& value)
{
	this->wh = value;
}

double Tunnel::getV() const
{
	return v;
}

void Tunnel::setV(const double& value)
{
	this->v = value;
}

double Tunnel::getQa() const
{
	return qa;
}

void Tunnel::setQa(const double& value)
{
	this->qa = value;
}

std::string Tunnel::getComment() const
{
	return comment;
}

void Tunnel::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
