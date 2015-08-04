#include "stdafx.h"
#include "WorkSurf.h"
#include "Tunnel.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

WorkSurf::WorkSurf()
{
	work_surf_id = 0;
	a = 0.0;
	q_r = 0.0;
	q_a = 0.0;
	ws_l = 0.0;
	ws_layerable = 0;
	ws_k1 = 0.0;
	ws_k2 = 0.0;
	ws_k3 = 0.0;
	ws_kf = 0.0;
	ws_h = 0.0;
	ws_method = 0;
	last_t = 0.0;
	comment = "NULL";
}

WorkSurf::WorkSurf(long id)
{
	work_surf_id = id;
	a = 0.0;
	q_r = 0.0;
	q_a = 0.0;
	ws_l = 0.0;
	ws_layerable = 0;
	ws_k1 = 0.0;
	ws_k2 = 0.0;
	ws_k3 = 0.0;
	ws_kf = 0.0;
	ws_h = 0.0;
	ws_method = 0;
	last_t = 0.0;
	comment = "NULL";
}

WorkSurf::WorkSurf(soci::row &rs)
{
	work_surf_id = rs.get<long>(0);
	long tunnel_id = rs.get<long>(1);
	if(tunnel_id > -1) {
		tunnel = TunnelPtr(new Tunnel(tunnel_id));
	}
	long coal_id = rs.get<long>(2);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	a = rs.get<double>(3);
	q_r = rs.get<double>(4);
	q_a = rs.get<double>(5);
	ws_l = rs.get<double>(6);
	ws_layerable = rs.get<long>(7);
	ws_k1 = rs.get<double>(8);
	ws_k2 = rs.get<double>(9);
	ws_k3 = rs.get<double>(10);
	ws_kf = rs.get<double>(11);
	ws_h = rs.get<double>(12);
	ws_method = rs.get<long>(13);
	last_t = rs.get<double>(14);
	comment = rs.get<std::string>(15);
}

std::string WorkSurf::getTableName() const
{
	return "cbm_work_surf";
}

std::string WorkSurf::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_work_surf values("
		<<"NULL"<<","
		<<tunnel->getId()<<","
		<<coal->getId()<<","
		<<a<<","
		<<q_r<<","
		<<q_a<<","
		<<ws_l<<","
		<<ws_layerable<<","
		<<ws_k1<<","
		<<ws_k2<<","
		<<ws_k3<<","
		<<ws_kf<<","
		<<ws_h<<","
		<<ws_method<<","
		<<last_t<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string WorkSurf::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_work_surf set"
		<<" tunnel_id="<<tunnel->getId()<<","
		<<" coal_id="<<coal->getId()<<","
		<<" a="<<a<<","
		<<" q_r="<<q_r<<","
		<<" q_a="<<q_a<<","
		<<" ws_l="<<ws_l<<","
		<<" ws_layerable="<<ws_layerable<<","
		<<" ws_k1="<<ws_k1<<","
		<<" ws_k2="<<ws_k2<<","
		<<" ws_k3="<<ws_k3<<","
		<<" ws_kf="<<ws_kf<<","
		<<" ws_h="<<ws_h<<","
		<<" ws_method="<<ws_method<<","
		<<" last_t="<<last_t<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where work_surf_id="<<work_surf_id
		<<" ;";
	return sql.str();
}

std::string WorkSurf::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_work_surf"
		<<" where work_surf_id="<<work_surf_id
		<<" ;";
	return sql.str();
}

long WorkSurf::getId() const
{
	return work_surf_id;
}

void WorkSurf::setId(const long& value)
{
	this->work_surf_id = value;
}

TunnelPtr WorkSurf::getTunnel() const
{
	return tunnel;
}

void WorkSurf::setTunnel(const TunnelPtr& value)
{
	this->tunnel = value;
}

CoalPtr WorkSurf::getCoal() const
{
	return coal;
}

void WorkSurf::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

double WorkSurf::getA() const
{
	return a;
}

void WorkSurf::setA(const double& value)
{
	this->a = value;
}

double WorkSurf::getQR() const
{
	return q_r;
}

void WorkSurf::setQR(const double& value)
{
	this->q_r = value;
}

double WorkSurf::getQA() const
{
	return q_a;
}

void WorkSurf::setQA(const double& value)
{
	this->q_a = value;
}

double WorkSurf::getWsL() const
{
	return ws_l;
}

void WorkSurf::setWsL(const double& value)
{
	this->ws_l = value;
}

long WorkSurf::getWsLayerable() const
{
	return ws_layerable;
}

void WorkSurf::setWsLayerable(const long& value)
{
	this->ws_layerable = value;
}

double WorkSurf::getWsK1() const
{
	return ws_k1;
}

void WorkSurf::setWsK1(const double& value)
{
	this->ws_k1 = value;
}

double WorkSurf::getWsK2() const
{
	return ws_k2;
}

void WorkSurf::setWsK2(const double& value)
{
	this->ws_k2 = value;
}

double WorkSurf::getWsK3() const
{
	return ws_k3;
}

void WorkSurf::setWsK3(const double& value)
{
	this->ws_k3 = value;
}

double WorkSurf::getWsKf() const
{
	return ws_kf;
}

void WorkSurf::setWsKf(const double& value)
{
	this->ws_kf = value;
}

double WorkSurf::getWsH() const
{
	return ws_h;
}

void WorkSurf::setWsH(const double& value)
{
	this->ws_h = value;
}

long WorkSurf::getWsMethod() const
{
	return ws_method;
}

void WorkSurf::setWsMethod(const long& value)
{
	this->ws_method = value;
}

double WorkSurf::getLastT() const
{
	return last_t;
}

void WorkSurf::setLastT(const double& value)
{
	this->last_t = value;
}

std::string WorkSurf::getComment() const
{
	return comment;
}

void WorkSurf::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
