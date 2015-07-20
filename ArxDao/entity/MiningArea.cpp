#include "stdafx.h"
#include "MiningArea.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

MiningArea::MiningArea()
{
	mining_area_id = 0;
	area_mode = 0;
	area_k = 0.0;
	a = 0.0;
	q_r = 0.0;
}

MiningArea::MiningArea(long id)
{
	mining_area_id = id;
	area_mode = 0;
	area_k = 0.0;
	a = 0.0;
	q_r = 0.0;
}

MiningArea::MiningArea(soci::row &rs)
{
	mining_area_id = rs.get<long>(0);
	long coal_id = rs.get<long>(1);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	area_mode = rs.get<long>(2);
	area_k = rs.get<double>(3);
	a = rs.get<double>(4);
	q_r = rs.get<double>(5);
}

std::string MiningArea::getTableName() const
{
	return "cbm_mining_area";
}

std::string MiningArea::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_mining_area values("
		<<"NULL"<<","
		<<coal->getId()<<","
		<<area_mode<<","
		<<area_k<<","
		<<a<<","
		<<q_r<<");";
	return sql.str();
}

std::string MiningArea::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_mining_area set"
		<<" coal_id="<<coal->getId()<<","
		<<" area_mode="<<area_mode<<","
		<<" area_k="<<area_k<<","
		<<" a="<<a<<","
		<<" q_r="<<q_r
		<<" where mining_area_id="<<mining_area_id
		<<" ;";
	return sql.str();
}

std::string MiningArea::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_mining_area"
		<<" where mining_area_id="<<mining_area_id
		<<" ;";
	return sql.str();
}

long MiningArea::getId() const
{
	return mining_area_id;
}

void MiningArea::setId(const long& value)
{
	this->mining_area_id = value;
}

CoalPtr MiningArea::getCoal() const
{
	return coal;
}

void MiningArea::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

long MiningArea::getAreaMode() const
{
	return area_mode;
}

void MiningArea::setAreaMode(const long& value)
{
	this->area_mode = value;
}

double MiningArea::getAreaK() const
{
	return area_k;
}

void MiningArea::setAreaK(const double& value)
{
	this->area_k = value;
}

double MiningArea::getA() const
{
	return a;
}

void MiningArea::setA(const double& value)
{
	this->a = value;
}

double MiningArea::getQR() const
{
	return q_r;
}

void MiningArea::setQR(const double& value)
{
	this->q_r = value;
}

} // namespace cbm
