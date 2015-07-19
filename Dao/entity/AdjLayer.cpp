#include "AdjLayer.h"
#include "WorkSurf.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

AdjLayer::AdjLayer()
{
}

AdjLayer::AdjLayer(long id)
{
	this->adj_layer_id = id;
}

AdjLayer::AdjLayer(soci::row &rs)
{
	adj_layer_id = rs.get<long>(0);
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
}

std::string AdjLayer::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_adj_layer values("
		<<"NULL"<<","
		<<work_surf->getId()<<","
		<<coal->getId()<<","
		<<layer_num<<","
		<<layer_h<<","
		<<layer_hp<<","
		<<layer_cave_zone<<");";
	return sql.str();
}

std::string AdjLayer::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_adj_layer set"
		<<" work_surf_id="<<work_surf->getId()<<","
		<<" coal_id="<<coal->getId()<<","
		<<" layer_num="<<layer_num<<","
		<<" layer_h="<<layer_h<<","
		<<" layer_hp="<<layer_hp<<","
		<<" layer_cave_zone="<<layer_cave_zone
		<<" where adj_layer_id="<<adj_layer_id
		<<" ;";
	return sql.str();
}

std::string AdjLayer::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_adj_layer"
		<<" where adj_layer_id="<<adj_layer_id
		<<" ;";
	return sql.str();
}

long AdjLayer::getId() const
{
	return adj_layer_id;
}

void AdjLayer::setId(const long& value)
{
	this->adj_layer_id = value;
}

WorkSurfPtr AdjLayer::getWorkSurf() const
{
	return work_surf;
}

void AdjLayer::setWorkSurf(const WorkSurfPtr& value)
{
	this->work_surf = value;
}

CoalPtr AdjLayer::getCoal() const
{
	return coal;
}

void AdjLayer::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

long AdjLayer::getLayerNum() const
{
	return layer_num;
}

void AdjLayer::setLayerNum(const long& value)
{
	this->layer_num = value;
}

double AdjLayer::getLayerH() const
{
	return layer_h;
}

void AdjLayer::setLayerH(const double& value)
{
	this->layer_h = value;
}

double AdjLayer::getLayerHp() const
{
	return layer_hp;
}

void AdjLayer::setLayerHp(const double& value)
{
	this->layer_hp = value;
}

long AdjLayer::getLayerCaveZone() const
{
	return layer_cave_zone;
}

void AdjLayer::setLayerCaveZone(const long& value)
{
	this->layer_cave_zone = value;
}

} // namespace cbm
