#include "stdafx.h"
#include "Mine.h"
#include "MineRegion.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Mine::Mine()
{
	mine_id = 0;
	username = "NULL";
	password = "NULL";
	mine_name = "NULL";
	mine_address = "NULL";
	coal_capacity = 0.0;
	topo_geo = 0;
	hydr_geo = 0;
	ground_condition = 0;
	q_r = 0.0;
	stereo_schem_diagram = "NULL";
	k_gas = 0.0;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	reserve_gas = 0.0;
	pump_kd = 0.0;
	pump_k1 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_wc = 0.0;
	comment = "NULL";
}

Mine::Mine(long id)
{
	mine_id = id;
	username = "NULL";
	password = "NULL";
	mine_name = "NULL";
	mine_address = "NULL";
	coal_capacity = 0.0;
	topo_geo = 0;
	hydr_geo = 0;
	ground_condition = 0;
	q_r = 0.0;
	stereo_schem_diagram = "NULL";
	k_gas = 0.0;
	reserve_w1 = 0.0;
	reserve_w2 = 0.0;
	reserve_w3 = 0.0;
	reserve_gas = 0.0;
	pump_kd = 0.0;
	pump_k1 = 0.0;
	pump_k2 = 0.0;
	pump_k3 = 0.0;
	pump_k4 = 0.0;
	pump_wc = 0.0;
	comment = "NULL";
}

Mine::Mine(soci::row &rs)
{
	mine_id = rs.get<long>(0);
	long mine_region_id = rs.get<long>(1);
	if(mine_region_id > -1) {
		mine_region = MineRegionPtr(new MineRegion(mine_region_id));
	}
	username = rs.get<std::string>(2);
	password = rs.get<std::string>(3);
	mine_name = rs.get<std::string>(4);
	mine_address = rs.get<std::string>(5);
	coal_capacity = rs.get<double>(6);
	topo_geo = rs.get<long>(7);
	hydr_geo = rs.get<long>(8);
	ground_condition = rs.get<long>(9);
	q_r = rs.get<double>(10);
	stereo_schem_diagram = rs.get<std::string>(11);
	k_gas = rs.get<double>(12);
	reserve_w1 = rs.get<double>(13);
	reserve_w2 = rs.get<double>(14);
	reserve_w3 = rs.get<double>(15);
	reserve_gas = rs.get<double>(16);
	pump_kd = rs.get<double>(17);
	pump_k1 = rs.get<double>(18);
	pump_k2 = rs.get<double>(19);
	pump_k3 = rs.get<double>(20);
	pump_k4 = rs.get<double>(21);
	pump_wc = rs.get<double>(22);
	comment = rs.get<std::string>(23);
}

std::string Mine::getTableName() const
{
	return "cbm_mine";
}

std::string Mine::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_mine values("
		<<"NULL"<<","
		<<mine_region->getId()<<","
		<<"'"<<username<<"'"<<","
		<<"'"<<password<<"'"<<","
		<<"'"<<mine_name<<"'"<<","
		<<"'"<<mine_address<<"'"<<","
		<<coal_capacity<<","
		<<topo_geo<<","
		<<hydr_geo<<","
		<<ground_condition<<","
		<<q_r<<","
		<<"'"<<stereo_schem_diagram<<"'"<<","
		<<k_gas<<","
		<<reserve_w1<<","
		<<reserve_w2<<","
		<<reserve_w3<<","
		<<reserve_gas<<","
		<<pump_kd<<","
		<<pump_k1<<","
		<<pump_k2<<","
		<<pump_k3<<","
		<<pump_k4<<","
		<<pump_wc<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string Mine::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_mine set"
		<<" mine_region_id="<<mine_region->getId()<<","
		<<" username="<<"'"<<username<<"'"<<","
		<<" password="<<"'"<<password<<"'"<<","
		<<" mine_name="<<"'"<<mine_name<<"'"<<","
		<<" mine_address="<<"'"<<mine_address<<"'"<<","
		<<" coal_capacity="<<coal_capacity<<","
		<<" topo_geo="<<topo_geo<<","
		<<" hydr_geo="<<hydr_geo<<","
		<<" ground_condition="<<ground_condition<<","
		<<" q_r="<<q_r<<","
		<<" stereo_schem_diagram="<<"'"<<stereo_schem_diagram<<"'"<<","
		<<" k_gas="<<k_gas<<","
		<<" reserve_w1="<<reserve_w1<<","
		<<" reserve_w2="<<reserve_w2<<","
		<<" reserve_w3="<<reserve_w3<<","
		<<" reserve_gas="<<reserve_gas<<","
		<<" pump_kd="<<pump_kd<<","
		<<" pump_k1="<<pump_k1<<","
		<<" pump_k2="<<pump_k2<<","
		<<" pump_k3="<<pump_k3<<","
		<<" pump_k4="<<pump_k4<<","
		<<" pump_wc="<<pump_wc<<","
		<<" comment="<<"'"<<comment<<"'"
		<<" where mine_id="<<mine_id
		<<" ;";
	return sql.str();
}

std::string Mine::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_mine"
		<<" where mine_id="<<mine_id
		<<" ;";
	return sql.str();
}

long Mine::getId() const
{
	return mine_id;
}

void Mine::setId(const long& value)
{
	this->mine_id = value;
}

MineRegionPtr Mine::getMineRegion() const
{
	return mine_region;
}

void Mine::setMineRegion(const MineRegionPtr& value)
{
	this->mine_region = value;
}

std::string Mine::getUsername() const
{
	return username;
}

void Mine::setUsername(const std::string& value)
{
	this->username = value;
}

std::string Mine::getPassword() const
{
	return password;
}

void Mine::setPassword(const std::string& value)
{
	this->password = value;
}

std::string Mine::getMineName() const
{
	return mine_name;
}

void Mine::setMineName(const std::string& value)
{
	this->mine_name = value;
}

std::string Mine::getMineAddress() const
{
	return mine_address;
}

void Mine::setMineAddress(const std::string& value)
{
	this->mine_address = value;
}

double Mine::getCoalCapacity() const
{
	return coal_capacity;
}

void Mine::setCoalCapacity(const double& value)
{
	this->coal_capacity = value;
}

long Mine::getTopoGeo() const
{
	return topo_geo;
}

void Mine::setTopoGeo(const long& value)
{
	this->topo_geo = value;
}

long Mine::getHydrGeo() const
{
	return hydr_geo;
}

void Mine::setHydrGeo(const long& value)
{
	this->hydr_geo = value;
}

long Mine::getGroundCondition() const
{
	return ground_condition;
}

void Mine::setGroundCondition(const long& value)
{
	this->ground_condition = value;
}

double Mine::getQR() const
{
	return q_r;
}

void Mine::setQR(const double& value)
{
	this->q_r = value;
}

std::string Mine::getStereoSchemDiagram() const
{
	return stereo_schem_diagram;
}

void Mine::setStereoSchemDiagram(const std::string& value)
{
	this->stereo_schem_diagram = value;
}

double Mine::getKGas() const
{
	return k_gas;
}

void Mine::setKGas(const double& value)
{
	this->k_gas = value;
}

double Mine::getReserveW1() const
{
	return reserve_w1;
}

void Mine::setReserveW1(const double& value)
{
	this->reserve_w1 = value;
}

double Mine::getReserveW2() const
{
	return reserve_w2;
}

void Mine::setReserveW2(const double& value)
{
	this->reserve_w2 = value;
}

double Mine::getReserveW3() const
{
	return reserve_w3;
}

void Mine::setReserveW3(const double& value)
{
	this->reserve_w3 = value;
}

double Mine::getReserveGas() const
{
	return reserve_gas;
}

void Mine::setReserveGas(const double& value)
{
	this->reserve_gas = value;
}

double Mine::getPumpKd() const
{
	return pump_kd;
}

void Mine::setPumpKd(const double& value)
{
	this->pump_kd = value;
}

double Mine::getPumpK1() const
{
	return pump_k1;
}

void Mine::setPumpK1(const double& value)
{
	this->pump_k1 = value;
}

double Mine::getPumpK2() const
{
	return pump_k2;
}

void Mine::setPumpK2(const double& value)
{
	this->pump_k2 = value;
}

double Mine::getPumpK3() const
{
	return pump_k3;
}

void Mine::setPumpK3(const double& value)
{
	this->pump_k3 = value;
}

double Mine::getPumpK4() const
{
	return pump_k4;
}

void Mine::setPumpK4(const double& value)
{
	this->pump_k4 = value;
}

double Mine::getPumpWc() const
{
	return pump_wc;
}

void Mine::setPumpWc(const double& value)
{
	this->pump_wc = value;
}

std::string Mine::getComment() const
{
	return comment;
}

void Mine::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
