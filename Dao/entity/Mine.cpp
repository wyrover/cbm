#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Mine::Mine()
{
}

Mine::Mine(long id)
{
	this->mine_id = id;
}

Mine::Mine(soci::row &rs)
{
	mine_id = rs.get<long>(0);
	username = rs.get<std::string>(1);
	password = rs.get<std::string>(2);
	mine_name = rs.get<std::string>(3);
	mine_region = rs.get<std::string>(4);
	mine_address = rs.get<std::string>(5);
	coal_capacity = rs.get<double>(6);
	topo_geo = rs.get<long>(7);
	hydr_geo = rs.get<long>(8);
	ground_condition = rs.get<long>(9);
	q_r = rs.get<double>(10);
	stereo_schem_diagram = rs.get<std::string>(11);
	k_gas = rs.get<double>(12);
}

std::string Mine::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_mine values("
		<<"NULL"<<","
		<<"'"<<username<<"'"<<","
		<<"'"<<password<<"'"<<","
		<<"'"<<mine_name<<"'"<<","
		<<"'"<<mine_region<<"'"<<","
		<<"'"<<mine_address<<"'"<<","
		<<coal_capacity<<","
		<<topo_geo<<","
		<<hydr_geo<<","
		<<ground_condition<<","
		<<q_r<<","
		<<"'"<<stereo_schem_diagram<<"'"<<","
		<<k_gas<<");";
	return sql.str();
}

std::string Mine::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_mine set"
		<<" username="<<"'"<<username<<"'"<<","
		<<" password="<<"'"<<password<<"'"<<","
		<<" mine_name="<<"'"<<mine_name<<"'"<<","
		<<" mine_region="<<"'"<<mine_region<<"'"<<","
		<<" mine_address="<<"'"<<mine_address<<"'"<<","
		<<" coal_capacity="<<coal_capacity<<","
		<<" topo_geo="<<topo_geo<<","
		<<" hydr_geo="<<hydr_geo<<","
		<<" ground_condition="<<ground_condition<<","
		<<" q_r="<<q_r<<","
		<<" stereo_schem_diagram="<<"'"<<stereo_schem_diagram<<"'"<<","
		<<" k_gas="<<k_gas
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

std::string Mine::getMineRegion() const
{
	return mine_region;
}

void Mine::setMineRegion(const std::string& value)
{
	this->mine_region = value;
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

} // namespace cbm
