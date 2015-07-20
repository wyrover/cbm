#include "stdafx.h"
#include "DrillingSurf.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

DrillingSurf::DrillingSurf()
{
	drilling_surf_id = 0;
	q_r = 0.0;
	q_a = 0.0;
	tw_d = 0.0;
	tw_v = 0.0;
	tw_l = 0.0;
	tw_s = 0.0;
	tw_q3 = 0.0;
	tw_q4 = 0.0;
}

DrillingSurf::DrillingSurf(long id)
{
	drilling_surf_id = id;
	q_r = 0.0;
	q_a = 0.0;
	tw_d = 0.0;
	tw_v = 0.0;
	tw_l = 0.0;
	tw_s = 0.0;
	tw_q3 = 0.0;
	tw_q4 = 0.0;
}

DrillingSurf::DrillingSurf(soci::row &rs)
{
	drilling_surf_id = rs.get<long>(0);
	long coal_id = rs.get<long>(1);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	q_r = rs.get<double>(2);
	q_a = rs.get<double>(3);
	tw_d = rs.get<double>(4);
	tw_v = rs.get<double>(5);
	tw_l = rs.get<double>(6);
	tw_s = rs.get<double>(7);
	tw_q3 = rs.get<double>(8);
	tw_q4 = rs.get<double>(9);
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
		<<q_r<<","
		<<q_a<<","
		<<tw_d<<","
		<<tw_v<<","
		<<tw_l<<","
		<<tw_s<<","
		<<tw_q3<<","
		<<tw_q4<<");";
	return sql.str();
}

std::string DrillingSurf::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_drilling_surf set"
		<<" coal_id="<<coal->getId()<<","
		<<" q_r="<<q_r<<","
		<<" q_a="<<q_a<<","
		<<" tw_d="<<tw_d<<","
		<<" tw_v="<<tw_v<<","
		<<" tw_l="<<tw_l<<","
		<<" tw_s="<<tw_s<<","
		<<" tw_q3="<<tw_q3<<","
		<<" tw_q4="<<tw_q4
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

double DrillingSurf::getTwD() const
{
	return tw_d;
}

void DrillingSurf::setTwD(const double& value)
{
	this->tw_d = value;
}

double DrillingSurf::getTwV() const
{
	return tw_v;
}

void DrillingSurf::setTwV(const double& value)
{
	this->tw_v = value;
}

double DrillingSurf::getTwL() const
{
	return tw_l;
}

void DrillingSurf::setTwL(const double& value)
{
	this->tw_l = value;
}

double DrillingSurf::getTwS() const
{
	return tw_s;
}

void DrillingSurf::setTwS(const double& value)
{
	this->tw_s = value;
}

double DrillingSurf::getTwQ3() const
{
	return tw_q3;
}

void DrillingSurf::setTwQ3(const double& value)
{
	this->tw_q3 = value;
}

double DrillingSurf::getTwQ4() const
{
	return tw_q4;
}

void DrillingSurf::setTwQ4(const double& value)
{
	this->tw_q4 = value;
}

} // namespace cbm
