#include "stdafx.h"
#include "HydrGeo.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

HydrGeo::HydrGeo()
{
	hydr_geo_id = 0;
	type = "NULL";
	x1 = 0;
	x2 = 0.0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = "NULL";
}

HydrGeo::HydrGeo(long id)
{
	hydr_geo_id = id;
	type = "NULL";
	x1 = 0;
	x2 = 0.0;
	x3 = 0;
	x4 = 0.0;
	x5 = 0.0;
	x6 = 0.0;
	x7 = 0.0;
	x8 = "NULL";
}

HydrGeo::HydrGeo(soci::row &rs)
{
	hydr_geo_id = rs.get<long>(0);
	type = rs.get<std::string>(1);
	x1 = rs.get<long>(2);
	x2 = rs.get<double>(3);
	x3 = rs.get<long>(4);
	x4 = rs.get<double>(5);
	x5 = rs.get<double>(6);
	x6 = rs.get<double>(7);
	x7 = rs.get<double>(8);
	x8 = rs.get<std::string>(9);
}

std::string HydrGeo::getTableName() const
{
	return "cbm_hydr_geo";
}

std::string HydrGeo::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_hydr_geo values("
		<<"NULL"<<","
		<<"'"<<type<<"'"<<","
		<<x1<<","
		<<x2<<","
		<<x3<<","
		<<x4<<","
		<<x5<<","
		<<x6<<","
		<<x7<<","
		<<"'"<<x8<<"'"<<");";
	return sql.str();
}

std::string HydrGeo::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_hydr_geo set"
		<<" type="<<"'"<<type<<"'"<<","
		<<" x1="<<x1<<","
		<<" x2="<<x2<<","
		<<" x3="<<x3<<","
		<<" x4="<<x4<<","
		<<" x5="<<x5<<","
		<<" x6="<<x6<<","
		<<" x7="<<x7<<","
		<<" x8="<<"'"<<x8<<"'"
		<<" where hydr_geo_id="<<hydr_geo_id
		<<" ;";
	return sql.str();
}

std::string HydrGeo::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_hydr_geo"
		<<" where hydr_geo_id="<<hydr_geo_id
		<<" ;";
	return sql.str();
}

long HydrGeo::getId() const
{
	return hydr_geo_id;
}

void HydrGeo::setId(const long& value)
{
	this->hydr_geo_id = value;
}

std::string HydrGeo::getType() const
{
	return type;
}

void HydrGeo::setType(const std::string& value)
{
	this->type = value;
}

long HydrGeo::getX1() const
{
	return x1;
}

void HydrGeo::setX1(const long& value)
{
	this->x1 = value;
}

double HydrGeo::getX2() const
{
	return x2;
}

void HydrGeo::setX2(const double& value)
{
	this->x2 = value;
}

long HydrGeo::getX3() const
{
	return x3;
}

void HydrGeo::setX3(const long& value)
{
	this->x3 = value;
}

double HydrGeo::getX4() const
{
	return x4;
}

void HydrGeo::setX4(const double& value)
{
	this->x4 = value;
}

double HydrGeo::getX5() const
{
	return x5;
}

void HydrGeo::setX5(const double& value)
{
	this->x5 = value;
}

double HydrGeo::getX6() const
{
	return x6;
}

void HydrGeo::setX6(const double& value)
{
	this->x6 = value;
}

double HydrGeo::getX7() const
{
	return x7;
}

void HydrGeo::setX7(const double& value)
{
	this->x7 = value;
}

std::string HydrGeo::getX8() const
{
	return x8;
}

void HydrGeo::setX8(const std::string& value)
{
	this->x8 = value;
}

} // namespace cbm
