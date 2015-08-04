#include "stdafx.h"
#include "CoalLayer.h"
#include "WorkSurf.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

CoalLayer::CoalLayer()
{
	coal_layer_id = 0;
	layer_num = 0;
	layer_h = 0.0;
	layer_hp = 0.0;
	layer_cave_zone = 0;
	comment = "NULL";
}

CoalLayer::CoalLayer(long id)
{
	coal_layer_id = id;
	layer_num = 0;
	layer_h = 0.0;
	layer_hp = 0.0;
	layer_cave_zone = 0;
	comment = "NULL";
}

CoalLayer::CoalLayer(soci::row &rs)
{
	coal_layer_id = rs.get<long>(0);
	long work_surf_id = rs.get<long>(1);
	if(work_surf_id > -1) {
		work_surf = WorkSurfPtr(new WorkSurf(work_surf_id));
	}
	long coal_id = rs.get<long>(2);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	layer_num = rs.get<long>(3);
	layer_h = rs.get<double>(4);
	layer_hp = rs.get<double>(5);
	layer_cave_zone = rs.get<long>(6);
	comment = rs.get<std::string>(7);
}

std::string CoalLayer::getTableName() const
{
	return "cbm_coal_layer";
}

std::string CoalLayer::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_coal_layer values("
		<<"NULL"<<","
		<<work_surf->getId()<<","
		<<coal->getId()<<","
		<<layer_num<<","
		<<layer_h<<","
		<<layer_hp<<","
		<<layer_cave_zone<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string CoalLayer::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_coal_layer set"
		<<" work_surf_id="<<work_surf->getId()<<","
		<<" coal_id="<<coal->getId()<<","
		<<" layer_num="<<layer_num<<","
		<<" layer_h="<<layer_h<<","
		<<" layer_hp="<<layer_hp<<","
		<<" layer_cave_zone="<<layer_cave_zone<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where coal_layer_id="<<coal_layer_id
		<<" ;";
	return sql.str();
}

std::string CoalLayer::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_coal_layer"
		<<" where coal_layer_id="<<coal_layer_id
		<<" ;";
	return sql.str();
}

long CoalLayer::getId() const
{
	return coal_layer_id;
}

void CoalLayer::setId(const long& value)
{
	this->coal_layer_id = value;
}

WorkSurfPtr CoalLayer::getWorkSurf() const
{
	return work_surf;
}

void CoalLayer::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

CoalPtr CoalLayer::getCoal() const
{
	return coal;
}

void CoalLayer::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

long CoalLayer::getLayerNum() const
{
	return layer_num;
}

void CoalLayer::setLayerNum(const long& value)
{
	this->layer_num = value;
}

double CoalLayer::getLayerH() const
{
	return layer_h;
}

void CoalLayer::setLayerH(const double& value)
{
	this->layer_h = value;
}

double CoalLayer::getLayerHp() const
{
	return layer_hp;
}

void CoalLayer::setLayerHp(const double& value)
{
	this->layer_hp = value;
}

long CoalLayer::getLayerCaveZone() const
{
	return layer_cave_zone;
}

void CoalLayer::setLayerCaveZone(const long& value)
{
	this->layer_cave_zone = value;
}

std::string CoalLayer::getComment() const
{
	return comment;
}

void CoalLayer::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
