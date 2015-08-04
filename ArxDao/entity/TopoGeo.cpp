#include "stdafx.h"
#include "TopoGeo.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

TopoGeo::TopoGeo()
{
	topo_geo_id = 0;
	type = "NULL";
	feature = "NULL";
	comment = "NULL";
}

TopoGeo::TopoGeo(long id)
{
	topo_geo_id = id;
	type = "NULL";
	feature = "NULL";
	comment = "NULL";
}

TopoGeo::TopoGeo(soci::row &rs)
{
	topo_geo_id = rs.get<long>(0);
	type = rs.get<std::string>(1);
	feature = rs.get<std::string>(2);
	comment = rs.get<std::string>(3);
}

std::string TopoGeo::getTableName() const
{
	return "cbm_topo_geo";
}

std::string TopoGeo::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_topo_geo values("
		<<"NULL"<<","
		<<"'"<<type<<"'"<<","
		<<"'"<<feature<<"'"<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string TopoGeo::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_topo_geo set"
		<<" type="<<"'"<<type<<"'"<<","
		<<" feature="<<"'"<<feature<<"'"<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where topo_geo_id="<<topo_geo_id
		<<" ;";
	return sql.str();
}

std::string TopoGeo::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_topo_geo"
		<<" where topo_geo_id="<<topo_geo_id
		<<" ;";
	return sql.str();
}

long TopoGeo::getId() const
{
	return topo_geo_id;
}

void TopoGeo::setId(const long& value)
{
	this->topo_geo_id = value;
}

std::string TopoGeo::getType() const
{
	return type;
}

void TopoGeo::setType(const std::string& value)
{
	this->type = value;
}

std::string TopoGeo::getFeature() const
{
	return feature;
}

void TopoGeo::setFeature(const std::string& value)
{
	this->feature = value;
}

std::string TopoGeo::getComment() const
{
	return comment;
}

void TopoGeo::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
