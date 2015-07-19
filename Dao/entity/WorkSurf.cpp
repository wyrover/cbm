#include "WorkSurf.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

WorkSurf::WorkSurf()
{
}

WorkSurf::WorkSurf(long id)
{
	this->work_surf_id = id;
}

WorkSurf::WorkSurf(soci::row &rs)
{
	work_surf_id = rs.get<long>(0);
	long coal_id = rs.get<long>(1);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	a = rs.get<double>(2);
	q_r = rs.get<double>(3);
	q_a = rs.get<double>(4);
	ws_l = rs.get<double>(5);
	ws_layer = rs.get<long>(6);
	ws_k1 = rs.get<double>(7);
	ws_k2 = rs.get<double>(8);
	ws_k3 = rs.get<double>(9);
	ws_kf = rs.get<double>(10);
	cross_l = rs.get<double>(11);
	cross_v = rs.get<double>(12);
	last_t = rs.get<double>(13);
}

std::string WorkSurf::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_work_surf values("
		<<"NULL"<<","
		<<coal->getId()<<","
		<<a<<","
		<<q_r<<","
		<<q_a<<","
		<<ws_l<<","
		<<ws_layer<<","
		<<ws_k1<<","
		<<ws_k2<<","
		<<ws_k3<<","
		<<ws_kf<<","
		<<cross_l<<","
		<<cross_v<<","
		<<last_t<<");";
	return sql.str();
}

std::string WorkSurf::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_work_surf set"
		<<" coal_id="<<coal->getId()<<","
		<<" a="<<a<<","
		<<" q_r="<<q_r<<","
		<<" q_a="<<q_a<<","
		<<" ws_l="<<ws_l<<","
		<<" ws_layer="<<ws_layer<<","
		<<" ws_k1="<<ws_k1<<","
		<<" ws_k2="<<ws_k2<<","
		<<" ws_k3="<<ws_k3<<","
		<<" ws_kf="<<ws_kf<<","
		<<" cross_l="<<cross_l<<","
		<<" cross_v="<<cross_v<<","
		<<" last_t="<<last_t
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

long WorkSurf::getWsLayer() const
{
	return ws_layer;
}

void WorkSurf::setWsLayer(const long& value)
{
	this->ws_layer = value;
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

double WorkSurf::getCrossL() const
{
	return cross_l;
}

void WorkSurf::setCrossL(const double& value)
{
	this->cross_l = value;
}

double WorkSurf::getCrossV() const
{
	return cross_v;
}

void WorkSurf::setCrossV(const double& value)
{
	this->cross_v = value;
}

double WorkSurf::getLastT() const
{
	return last_t;
}

void WorkSurf::setLastT(const double& value)
{
	this->last_t = value;
}

} // namespace cbm
