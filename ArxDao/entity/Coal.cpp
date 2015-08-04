#include "stdafx.h"
#include "Coal.h"
#include "Mine.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

Coal::Coal()
{
	coal_name = "NULL";
	coal_id = 0;
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
	gas_wc2 = 0.0;
	gas_eta = 0.0;
	q_r = 0.0;
	q0 = 0.0;
	eval_method = 0;
	q0_alpha = 0.0;
	qt_alpha = 0.0;
	t_alpha = 0.0;
	q_lambda = 0.0;
	r_lambda = 0.0;
	p0_lambda = 0.0;
	p1_lambda = 0.0;
	t_lambda = 0.0;
	a_lambda = 0.0;
	p1_k = 0.0;
	p2_k = 0.0;
	gas_q = 0.0;
	core_height = 0.0;
	core_area = 0.0;
	gas_viscosity = 0.0;
	decay_alpha = 0.0;
	permeability_lambda = 0.0;
	permeability_k = 0.0;
	eval_difficult = 0;
	comment = "NULL";
}

Coal::Coal(long id)
{
	coal_name = "NULL";
	coal_id = id;
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
	gas_wc2 = 0.0;
	gas_eta = 0.0;
	q_r = 0.0;
	q0 = 0.0;
	eval_method = 0;
	q0_alpha = 0.0;
	qt_alpha = 0.0;
	t_alpha = 0.0;
	q_lambda = 0.0;
	r_lambda = 0.0;
	p0_lambda = 0.0;
	p1_lambda = 0.0;
	t_lambda = 0.0;
	a_lambda = 0.0;
	p1_k = 0.0;
	p2_k = 0.0;
	gas_q = 0.0;
	core_height = 0.0;
	core_area = 0.0;
	gas_viscosity = 0.0;
	decay_alpha = 0.0;
	permeability_lambda = 0.0;
	permeability_k = 0.0;
	eval_difficult = 0;
	comment = "NULL";
}

Coal::Coal(soci::row &rs)
{
	coal_name = rs.get<std::string>(0);
	coal_id = rs.get<long>(1);
	long mine_id = rs.get<long>(2);
	if(mine_id > -1) {
		mine = MinePtr(new Mine(mine_id));
	}
	coal_minable = rs.get<long>(3);
	coal_thick = rs.get<double>(4);
	coal_rank = rs.get<long>(5);
	coal_quality = rs.get<long>(6);
	layer_pressure = rs.get<double>(7);
	gas_content = rs.get<double>(8);
	gas_penetration = rs.get<double>(9);
	f_value = rs.get<double>(10);
	res_abundance = rs.get<long>(11);
	const_complexity = rs.get<long>(12);
	mine_index = rs.get<long>(13);
	var_coeff = rs.get<double>(14);
	coal_stability = rs.get<double>(15);
	dip_angle = rs.get<double>(16);
	caving_zone_height = rs.get<double>(17);
	layer_gap = rs.get<double>(18);
	influence_factor = rs.get<double>(19);
	res_a1 = rs.get<double>(20);
	gas_x1 = rs.get<double>(21);
	res_a2 = rs.get<double>(22);
	gas_x2 = rs.get<double>(23);
	gas_wc = rs.get<double>(24);
	coal_r = rs.get<double>(25);
	coal_vr = rs.get<double>(26);
	gas_w0 = rs.get<double>(27);
	gas_wc2 = rs.get<double>(28);
	gas_eta = rs.get<double>(29);
	q_r = rs.get<double>(30);
	q0 = rs.get<double>(31);
	eval_method = rs.get<long>(32);
	q0_alpha = rs.get<double>(33);
	qt_alpha = rs.get<double>(34);
	t_alpha = rs.get<double>(35);
	q_lambda = rs.get<double>(36);
	r_lambda = rs.get<double>(37);
	p0_lambda = rs.get<double>(38);
	p1_lambda = rs.get<double>(39);
	t_lambda = rs.get<double>(40);
	a_lambda = rs.get<double>(41);
	p1_k = rs.get<double>(42);
	p2_k = rs.get<double>(43);
	gas_q = rs.get<double>(44);
	core_height = rs.get<double>(45);
	core_area = rs.get<double>(46);
	gas_viscosity = rs.get<double>(47);
	decay_alpha = rs.get<double>(48);
	permeability_lambda = rs.get<double>(49);
	permeability_k = rs.get<double>(50);
	eval_difficult = rs.get<long>(51);
	comment = rs.get<std::string>(52);
}

std::string Coal::getTableName() const
{
	return "cbm_coal";
}

std::string Coal::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_coal values("
		<<"'"<<coal_name<<"'"<<","
		<<"NULL"<<","
		<<mine->getId()<<","
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
		<<gas_wc2<<","
		<<gas_eta<<","
		<<q_r<<","
		<<q0<<","
		<<eval_method<<","
		<<q0_alpha<<","
		<<qt_alpha<<","
		<<t_alpha<<","
		<<q_lambda<<","
		<<r_lambda<<","
		<<p0_lambda<<","
		<<p1_lambda<<","
		<<t_lambda<<","
		<<a_lambda<<","
		<<p1_k<<","
		<<p2_k<<","
		<<gas_q<<","
		<<core_height<<","
		<<core_area<<","
		<<gas_viscosity<<","
		<<decay_alpha<<","
		<<permeability_lambda<<","
		<<permeability_k<<","
		<<eval_difficult<<","
		<<"'"<<comment<<"'"<<");";
	return sql.str();
}

std::string Coal::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_coal set"
		<<" coal_name="<<"'"<<coal_name<<"'"<<","
		<<" mine_id="<<mine->getId()<<","
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
		<<" gas_wc2="<<gas_wc2<<","
		<<" gas_eta="<<gas_eta<<","
		<<" q_r="<<q_r<<","
		<<" q0="<<q0<<","
		<<" eval_method="<<eval_method<<","
		<<" q0_alpha="<<q0_alpha<<","
		<<" qt_alpha="<<qt_alpha<<","
		<<" t_alpha="<<t_alpha<<","
		<<" q_lambda="<<q_lambda<<","
		<<" r_lambda="<<r_lambda<<","
		<<" p0_lambda="<<p0_lambda<<","
		<<" p1_lambda="<<p1_lambda<<","
		<<" t_lambda="<<t_lambda<<","
		<<" a_lambda="<<a_lambda<<","
		<<" p1_k="<<p1_k<<","
		<<" p2_k="<<p2_k<<","
		<<" gas_q="<<gas_q<<","
		<<" core_height="<<core_height<<","
		<<" core_area="<<core_area<<","
		<<" gas_viscosity="<<gas_viscosity<<","
		<<" decay_alpha="<<decay_alpha<<","
		<<" permeability_lambda="<<permeability_lambda<<","
		<<" permeability_k="<<permeability_k<<","
		<<" eval_difficult="<<eval_difficult<<","
		<<" comment="<<"'"<<comment<<"'"
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

std::string Coal::getCoalName() const
{
	return coal_name;
}

void Coal::setCoalName(const std::string& value)
{
	this->coal_name = value;
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

double Coal::getGasWc2() const
{
	return gas_wc2;
}

void Coal::setGasWc2(const double& value)
{
	this->gas_wc2 = value;
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

long Coal::getEvalMethod() const
{
	return eval_method;
}

void Coal::setEvalMethod(const long& value)
{
	this->eval_method = value;
}

double Coal::getQ0Alpha() const
{
	return q0_alpha;
}

void Coal::setQ0Alpha(const double& value)
{
	this->q0_alpha = value;
}

double Coal::getQtAlpha() const
{
	return qt_alpha;
}

void Coal::setQtAlpha(const double& value)
{
	this->qt_alpha = value;
}

double Coal::getTAlpha() const
{
	return t_alpha;
}

void Coal::setTAlpha(const double& value)
{
	this->t_alpha = value;
}

double Coal::getQLambda() const
{
	return q_lambda;
}

void Coal::setQLambda(const double& value)
{
	this->q_lambda = value;
}

double Coal::getRLambda() const
{
	return r_lambda;
}

void Coal::setRLambda(const double& value)
{
	this->r_lambda = value;
}

double Coal::getP0Lambda() const
{
	return p0_lambda;
}

void Coal::setP0Lambda(const double& value)
{
	this->p0_lambda = value;
}

double Coal::getP1Lambda() const
{
	return p1_lambda;
}

void Coal::setP1Lambda(const double& value)
{
	this->p1_lambda = value;
}

double Coal::getTLambda() const
{
	return t_lambda;
}

void Coal::setTLambda(const double& value)
{
	this->t_lambda = value;
}

double Coal::getALambda() const
{
	return a_lambda;
}

void Coal::setALambda(const double& value)
{
	this->a_lambda = value;
}

double Coal::getP1K() const
{
	return p1_k;
}

void Coal::setP1K(const double& value)
{
	this->p1_k = value;
}

double Coal::getP2K() const
{
	return p2_k;
}

void Coal::setP2K(const double& value)
{
	this->p2_k = value;
}

double Coal::getGasQ() const
{
	return gas_q;
}

void Coal::setGasQ(const double& value)
{
	this->gas_q = value;
}

double Coal::getCoreHeight() const
{
	return core_height;
}

void Coal::setCoreHeight(const double& value)
{
	this->core_height = value;
}

double Coal::getCoreArea() const
{
	return core_area;
}

void Coal::setCoreArea(const double& value)
{
	this->core_area = value;
}

double Coal::getGasViscosity() const
{
	return gas_viscosity;
}

void Coal::setGasViscosity(const double& value)
{
	this->gas_viscosity = value;
}

double Coal::getDecayAlpha() const
{
	return decay_alpha;
}

void Coal::setDecayAlpha(const double& value)
{
	this->decay_alpha = value;
}

double Coal::getPermeabilityLambda() const
{
	return permeability_lambda;
}

void Coal::setPermeabilityLambda(const double& value)
{
	this->permeability_lambda = value;
}

double Coal::getPermeabilityK() const
{
	return permeability_k;
}

void Coal::setPermeabilityK(const double& value)
{
	this->permeability_k = value;
}

long Coal::getEvalDifficult() const
{
	return eval_difficult;
}

void Coal::setEvalDifficult(const long& value)
{
	this->eval_difficult = value;
}

std::string Coal::getComment() const
{
	return comment;
}

void Coal::setComment(const std::string& value)
{
	this->comment = value;
}

} // namespace cbm
