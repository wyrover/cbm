#include "DrillingRadius.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

DrillingRadius::DrillingRadius()
{
	drilling_radius_id = 0;
	radius_r = 0.0;
	radius_l = 0.0;
	radius_k1 = 0.0;
	radius_rho = 0.0;
	radius_q0 = 0.0;
	radius_a = 0.0;
	radius_t = 0.0;
	radius_qm1 = 0.0;
	radius_qm2 = 0.0;
	radius_qsum = 0.0;
	radius_eta = 0.0;
}

DrillingRadius::DrillingRadius(long id)
{
	drilling_radius_id = id;
	radius_r = 0.0;
	radius_l = 0.0;
	radius_k1 = 0.0;
	radius_rho = 0.0;
	radius_q0 = 0.0;
	radius_a = 0.0;
	radius_t = 0.0;
	radius_qm1 = 0.0;
	radius_qm2 = 0.0;
	radius_qsum = 0.0;
	radius_eta = 0.0;
}

DrillingRadius::DrillingRadius(soci::row &rs)
{
	drilling_radius_id = rs.get<long>(0);
	long coal_id = rs.get<long>(1);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	radius_r = rs.get<double>(2);
	radius_l = rs.get<double>(3);
	radius_k1 = rs.get<double>(4);
	radius_rho = rs.get<double>(5);
	radius_q0 = rs.get<double>(6);
	radius_a = rs.get<double>(7);
	radius_t = rs.get<double>(8);
	radius_qm1 = rs.get<double>(9);
	radius_qm2 = rs.get<double>(10);
	radius_qsum = rs.get<double>(11);
	radius_eta = rs.get<double>(12);
}

std::string DrillingRadius::getTableName() const
{
	return "cbm_drilling_radius";
}

std::string DrillingRadius::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_drilling_radius values("
		<<"NULL"<<","
		<<coal->getId()<<","
		<<radius_r<<","
		<<radius_l<<","
		<<radius_k1<<","
		<<radius_rho<<","
		<<radius_q0<<","
		<<radius_a<<","
		<<radius_t<<","
		<<radius_qm1<<","
		<<radius_qm2<<","
		<<radius_qsum<<","
		<<radius_eta<<");";
	return sql.str();
}

std::string DrillingRadius::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_drilling_radius set"
		<<" coal_id="<<coal->getId()<<","
		<<" radius_r="<<radius_r<<","
		<<" radius_l="<<radius_l<<","
		<<" radius_k1="<<radius_k1<<","
		<<" radius_rho="<<radius_rho<<","
		<<" radius_q0="<<radius_q0<<","
		<<" radius_a="<<radius_a<<","
		<<" radius_t="<<radius_t<<","
		<<" radius_qm1="<<radius_qm1<<","
		<<" radius_qm2="<<radius_qm2<<","
		<<" radius_qsum="<<radius_qsum<<","
		<<" radius_eta="<<radius_eta
		<<" where drilling_radius_id="<<drilling_radius_id
		<<" ;";
	return sql.str();
}

std::string DrillingRadius::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_drilling_radius"
		<<" where drilling_radius_id="<<drilling_radius_id
		<<" ;";
	return sql.str();
}

long DrillingRadius::getId() const
{
	return drilling_radius_id;
}

void DrillingRadius::setId(const long& value)
{
	this->drilling_radius_id = value;
}

CoalPtr DrillingRadius::getCoal() const
{
	return coal;
}

void DrillingRadius::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

double DrillingRadius::getRadiusR() const
{
	return radius_r;
}

void DrillingRadius::setRadiusR(const double& value)
{
	this->radius_r = value;
}

double DrillingRadius::getRadiusL() const
{
	return radius_l;
}

void DrillingRadius::setRadiusL(const double& value)
{
	this->radius_l = value;
}

double DrillingRadius::getRadiusK1() const
{
	return radius_k1;
}

void DrillingRadius::setRadiusK1(const double& value)
{
	this->radius_k1 = value;
}

double DrillingRadius::getRadiusRho() const
{
	return radius_rho;
}

void DrillingRadius::setRadiusRho(const double& value)
{
	this->radius_rho = value;
}

double DrillingRadius::getRadiusQ0() const
{
	return radius_q0;
}

void DrillingRadius::setRadiusQ0(const double& value)
{
	this->radius_q0 = value;
}

double DrillingRadius::getRadiusA() const
{
	return radius_a;
}

void DrillingRadius::setRadiusA(const double& value)
{
	this->radius_a = value;
}

double DrillingRadius::getRadiusT() const
{
	return radius_t;
}

void DrillingRadius::setRadiusT(const double& value)
{
	this->radius_t = value;
}

double DrillingRadius::getRadiusQm1() const
{
	return radius_qm1;
}

void DrillingRadius::setRadiusQm1(const double& value)
{
	this->radius_qm1 = value;
}

double DrillingRadius::getRadiusQm2() const
{
	return radius_qm2;
}

void DrillingRadius::setRadiusQm2(const double& value)
{
	this->radius_qm2 = value;
}

double DrillingRadius::getRadiusQsum() const
{
	return radius_qsum;
}

void DrillingRadius::setRadiusQsum(const double& value)
{
	this->radius_qsum = value;
}

double DrillingRadius::getRadiusEta() const
{
	return radius_eta;
}

void DrillingRadius::setRadiusEta(const double& value)
{
	this->radius_eta = value;
}

} // namespace cbm
