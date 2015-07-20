#include "Coal.h"
#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Coal::Coal()
{
	coal_id = 0;
	coal_name = "";
	coal_number = 0;
	coal_minable = 0;
	coal_thick = 0.0;
	coal_rank = 0;
	coal_quality = 0;
	layer_pressure = 0.0;
	gas_content = 0.0;
	gas_penetration = 0.0;
	f_value = 0.0;
	res_abundance = 0;
	const_complexity = 0;
	mine_index = 0;
	var_coeff = 0.0;
	coal_stability = 0.0;
	dip_angle = 0.0;
	caving_zone_height = 0.0;
	layer_gap = 0.0;
	influence_factor = 0.0;
	res_a1 = 0.0;
	gas_x1 = 0.0;
	res_a2 = 0.0;
	gas_x2 = 0.0;
	gas_wc = 0.0;
	coal_r = 0.0;
	coal_vr = 0.0;
	gas_w0 = 0.0;
	gas_eta = 0.0;
	q_r = 0.0;
	q0 = 0.0;
	mine_height = 0.0;
}

Coal::Coal(long id)
{
	coal_id = id;
	coal_name = "";
	coal_number = 0;
	coal_minable = 0;
	coal_thick = 0.0;
	coal_rank = 0;
	coal_quality = 0;
	layer_pressure = 0.0;
	gas_content = 0.0;
	gas_penetration = 0.0;
	f_value = 0.0;
	res_abundance = 0;
	const_complexity = 0;
	mine_index = 0;
	var_coeff = 0.0;
	coal_stability = 0.0;
	dip_angle = 0.0;
	caving_zone_height = 0.0;
	layer_gap = 0.0;
	influence_factor = 0.0;
	res_a1 = 0.0;
	gas_x1 = 0.0;
	res_a2 = 0.0;
	gas_x2 = 0.0;
	gas_wc = 0.0;
	coal_r = 0.0;
	coal_vr = 0.0;
	gas_w0 = 0.0;
	gas_eta = 0.0;
	q_r = 0.0;
	q0 = 0.0;
	mine_height = 0.0;
}

Coal::Coal(soci::row &rs)
{
	coal_id = rs.get<long>(0);
	long mine_id = rs.get<long>(1);
	if(mine_id > -1) {
		mine = MinePtr(new Mine(mine_id));
	}
	coal_name = rs.get<std::string>(2);
	coal_number = rs.get<long>(3);
	coal_minable = rs.get<long>(4);
	coal_thick = rs.get<double>(5);
	coal_rank = rs.get<long>(6);
	coal_quality = rs.get<long>(7);
	layer_pressure = rs.get<double>(8);
	gas_content = rs.get<double>(9);
	gas_penetration = rs.get<double>(10);
	f_value = rs.get<double>(11);
	res_abundance = rs.get<long>(12);
	const_complexity = rs.get<long>(13);
	mine_index = rs.get<long>(14);
	var_coeff = rs.get<double>(15);
	coal_stability = rs.get<double>(16);
	dip_angle = rs.get<double>(17);
	caving_zone_height = rs.get<double>(18);
	layer_gap = rs.get<double>(19);
	influence_factor = rs.get<double>(20);
	res_a1 = rs.get<double>(21);
	gas_x1 = rs.get<double>(22);
	res_a2 = rs.get<double>(23);
	gas_x2 = rs.get<double>(24);
	gas_wc = rs.get<double>(25);
	coal_r = rs.get<double>(26);
	coal_vr = rs.get<double>(27);
	gas_w0 = rs.get<double>(28);
	gas_eta = rs.get<double>(29);
	q_r = rs.get<double>(30);
	q0 = rs.get<double>(31);
	mine_height = rs.get<double>(32);
}

std::string Coal::getTableName() const
{
	return "cbm_coal";
}

std::string Coal::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_coal values("
		<<"NULL"<<","
		<<mine->getId()<<","
		<<"'"<<coal_name<<"'"<<","
		<<coal_number<<","
		<<coal_minable<<","
		<<coal_thick<<","
		<<coal_rank<<","
		<<coal_quality<<","
		<<layer_pressure<<","
		<<gas_content<<","
		<<gas_penetration<<","
		<<f_value<<","
		<<res_abundance<<","
		<<const_complexity<<","
		<<mine_index<<","
		<<var_coeff<<","
		<<coal_stability<<","
		<<dip_angle<<","
		<<caving_zone_height<<","
		<<layer_gap<<","
		<<influence_factor<<","
		<<res_a1<<","
		<<gas_x1<<","
		<<res_a2<<","
		<<gas_x2<<","
		<<gas_wc<<","
		<<coal_r<<","
		<<coal_vr<<","
		<<gas_w0<<","
		<<gas_eta<<","
		<<q_r<<","
		<<q0<<","
		<<mine_height<<");";
	return sql.str();
}

std::string Coal::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_coal set"
		<<" mine_id="<<mine->getId()<<","
		<<" coal_name="<<"'"<<coal_name<<"'"<<","
		<<" coal_number="<<coal_number<<","
		<<" coal_minable="<<coal_minable<<","
		<<" coal_thick="<<coal_thick<<","
		<<" coal_rank="<<coal_rank<<","
		<<" coal_quality="<<coal_quality<<","
		<<" layer_pressure="<<layer_pressure<<","
		<<" gas_content="<<gas_content<<","
		<<" gas_penetration="<<gas_penetration<<","
		<<" f_value="<<f_value<<","
		<<" res_abundance="<<res_abundance<<","
		<<" const_complexity="<<const_complexity<<","
		<<" mine_index="<<mine_index<<","
		<<" var_coeff="<<var_coeff<<","
		<<" coal_stability="<<coal_stability<<","
		<<" dip_angle="<<dip_angle<<","
		<<" caving_zone_height="<<caving_zone_height<<","
		<<" layer_gap="<<layer_gap<<","
		<<" influence_factor="<<influence_factor<<","
		<<" res_a1="<<res_a1<<","
		<<" gas_x1="<<gas_x1<<","
		<<" res_a2="<<res_a2<<","
		<<" gas_x2="<<gas_x2<<","
		<<" gas_wc="<<gas_wc<<","
		<<" coal_r="<<coal_r<<","
		<<" coal_vr="<<coal_vr<<","
		<<" gas_w0="<<gas_w0<<","
		<<" gas_eta="<<gas_eta<<","
		<<" q_r="<<q_r<<","
		<<" q0="<<q0<<","
		<<" mine_height="<<mine_height
		<<" where coal_id="<<coal_id
		<<" ;";
	return sql.str();
}

std::string Coal::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_coal"
		<<" where coal_id="<<coal_id
		<<" ;";
	return sql.str();
}

long Coal::getId() const
{
	return coal_id;
}

void Coal::setId(const long& value)
{
	this->coal_id = value;
}

MinePtr Coal::getMine() const
{
	return mine;
}

void Coal::setMine(const MinePtr& value)
{
	this->mine = value;
}

std::string Coal::getCoalName() const
{
	return coal_name;
}

void Coal::setCoalName(const std::string& value)
{
	this->coal_name = value;
}

long Coal::getCoalNumber() const
{
	return coal_number;
}

void Coal::setCoalNumber(const long& value)
{
	this->coal_number = value;
}

long Coal::getCoalMinable() const
{
	return coal_minable;
}

void Coal::setCoalMinable(const long& value)
{
	this->coal_minable = value;
}

double Coal::getCoalThick() const
{
	return coal_thick;
}

void Coal::setCoalThick(const double& value)
{
	this->coal_thick = value;
}

long Coal::getCoalRank() const
{
	return coal_rank;
}

void Coal::setCoalRank(const long& value)
{
	this->coal_rank = value;
}

long Coal::getCoalQuality() const
{
	return coal_quality;
}

void Coal::setCoalQuality(const long& value)
{
	this->coal_quality = value;
}

double Coal::getLayerPressure() const
{
	return layer_pressure;
}

void Coal::setLayerPressure(const double& value)
{
	this->layer_pressure = value;
}

double Coal::getGasContent() const
{
	return gas_content;
}

void Coal::setGasContent(const double& value)
{
	this->gas_content = value;
}

double Coal::getGasPenetration() const
{
	return gas_penetration;
}

void Coal::setGasPenetration(const double& value)
{
	this->gas_penetration = value;
}

double Coal::getFValue() const
{
	return f_value;
}

void Coal::setFValue(const double& value)
{
	this->f_value = value;
}

long Coal::getResAbundance() const
{
	return res_abundance;
}

void Coal::setResAbundance(const long& value)
{
	this->res_abundance = value;
}

long Coal::getConstComplexity() const
{
	return const_complexity;
}

void Coal::setConstComplexity(const long& value)
{
	this->const_complexity = value;
}

long Coal::getMineIndex() const
{
	return mine_index;
}

void Coal::setMineIndex(const long& value)
{
	this->mine_index = value;
}

double Coal::getVarCoeff() const
{
	return var_coeff;
}

void Coal::setVarCoeff(const double& value)
{
	this->var_coeff = value;
}

double Coal::getCoalStability() const
{
	return coal_stability;
}

void Coal::setCoalStability(const double& value)
{
	this->coal_stability = value;
}

double Coal::getDipAngle() const
{
	return dip_angle;
}

void Coal::setDipAngle(const double& value)
{
	this->dip_angle = value;
}

double Coal::getCavingZoneHeight() const
{
	return caving_zone_height;
}

void Coal::setCavingZoneHeight(const double& value)
{
	this->caving_zone_height = value;
}

double Coal::getLayerGap() const
{
	return layer_gap;
}

void Coal::setLayerGap(const double& value)
{
	this->layer_gap = value;
}

double Coal::getInfluenceFactor() const
{
	return influence_factor;
}

void Coal::setInfluenceFactor(const double& value)
{
	this->influence_factor = value;
}

double Coal::getResA1() const
{
	return res_a1;
}

void Coal::setResA1(const double& value)
{
	this->res_a1 = value;
}

double Coal::getGasX1() const
{
	return gas_x1;
}

void Coal::setGasX1(const double& value)
{
	this->gas_x1 = value;
}

double Coal::getResA2() const
{
	return res_a2;
}

void Coal::setResA2(const double& value)
{
	this->res_a2 = value;
}

double Coal::getGasX2() const
{
	return gas_x2;
}

void Coal::setGasX2(const double& value)
{
	this->gas_x2 = value;
}

double Coal::getGasWc() const
{
	return gas_wc;
}

void Coal::setGasWc(const double& value)
{
	this->gas_wc = value;
}

double Coal::getCoalR() const
{
	return coal_r;
}

void Coal::setCoalR(const double& value)
{
	this->coal_r = value;
}

double Coal::getCoalVr() const
{
	return coal_vr;
}

void Coal::setCoalVr(const double& value)
{
	this->coal_vr = value;
}

double Coal::getGasW0() const
{
	return gas_w0;
}

void Coal::setGasW0(const double& value)
{
	this->gas_w0 = value;
}

double Coal::getGasEta() const
{
	return gas_eta;
}

void Coal::setGasEta(const double& value)
{
	this->gas_eta = value;
}

double Coal::getQR() const
{
	return q_r;
}

void Coal::setQR(const double& value)
{
	this->q_r = value;
}

double Coal::getQ0() const
{
	return q0;
}

void Coal::setQ0(const double& value)
{
	this->q0 = value;
}

double Coal::getMineHeight() const
{
	return mine_height;
}

void Coal::setMineHeight(const double& value)
{
	this->mine_height = value;
}

} // namespace cbm
