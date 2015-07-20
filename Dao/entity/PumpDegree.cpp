#include "PumpDegree.h"
#include "Coal.h"

#include <sstream>
#include "../dao/util.h"

namespace cbm {

PumpDegree::PumpDegree()
{
	pump_degree_id = 0;
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
}

PumpDegree::PumpDegree(long id)
{
	pump_degree_id = id;
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
}

PumpDegree::PumpDegree(soci::row &rs)
{
	pump_degree_id = rs.get<long>(0);
	long coal_id = rs.get<long>(1);
	if(coal_id > -1) {
		coal = CoalPtr(new Coal(coal_id));
	}
	eval_method = rs.get<long>(2);
	q0_alpha = rs.get<double>(3);
	qt_alpha = rs.get<double>(4);
	t_alpha = rs.get<double>(5);
	q_lambda = rs.get<double>(6);
	r_lambda = rs.get<double>(7);
	p0_lambda = rs.get<double>(8);
	p1_lambda = rs.get<double>(9);
	t_lambda = rs.get<double>(10);
	a_lambda = rs.get<double>(11);
	p1_k = rs.get<double>(12);
	p2_k = rs.get<double>(13);
	gas_q = rs.get<double>(14);
	core_height = rs.get<double>(15);
	core_area = rs.get<double>(16);
	gas_viscosity = rs.get<double>(17);
	decay_alpha = rs.get<double>(18);
	permeability_lambda = rs.get<double>(19);
	permeability_k = rs.get<double>(20);
	eval_difficult = rs.get<long>(21);
}

std::string PumpDegree::getTableName() const
{
	return "cbm_pump_degree";
}

std::string PumpDegree::getSqlInsert() const
{
	std::stringstream sql;
	sql <<"insert into cbm_pump_degree values("
		<<"NULL"<<","
		<<coal->getId()<<","
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
		<<eval_difficult<<");";
	return sql.str();
}

std::string PumpDegree::getSqlUpdate() const
{
	std::stringstream sql;
	sql <<"update cbm_pump_degree set"
		<<" coal_id="<<coal->getId()<<","
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
		<<" eval_difficult="<<eval_difficult
		<<" where pump_degree_id="<<pump_degree_id
		<<" ;";
	return sql.str();
}

std::string PumpDegree::getSqlDelete() const
{
	std::stringstream sql;
	sql <<"delete from cbm_pump_degree"
		<<" where pump_degree_id="<<pump_degree_id
		<<" ;";
	return sql.str();
}

long PumpDegree::getId() const
{
	return pump_degree_id;
}

void PumpDegree::setId(const long& value)
{
	this->pump_degree_id = value;
}

CoalPtr PumpDegree::getCoal() const
{
	return coal;
}

void PumpDegree::setCoal(const CoalPtr& value)
{
	this->coal = value;
}

long PumpDegree::getEvalMethod() const
{
	return eval_method;
}

void PumpDegree::setEvalMethod(const long& value)
{
	this->eval_method = value;
}

double PumpDegree::getQ0Alpha() const
{
	return q0_alpha;
}

void PumpDegree::setQ0Alpha(const double& value)
{
	this->q0_alpha = value;
}

double PumpDegree::getQtAlpha() const
{
	return qt_alpha;
}

void PumpDegree::setQtAlpha(const double& value)
{
	this->qt_alpha = value;
}

double PumpDegree::getTAlpha() const
{
	return t_alpha;
}

void PumpDegree::setTAlpha(const double& value)
{
	this->t_alpha = value;
}

double PumpDegree::getQLambda() const
{
	return q_lambda;
}

void PumpDegree::setQLambda(const double& value)
{
	this->q_lambda = value;
}

double PumpDegree::getRLambda() const
{
	return r_lambda;
}

void PumpDegree::setRLambda(const double& value)
{
	this->r_lambda = value;
}

double PumpDegree::getP0Lambda() const
{
	return p0_lambda;
}

void PumpDegree::setP0Lambda(const double& value)
{
	this->p0_lambda = value;
}

double PumpDegree::getP1Lambda() const
{
	return p1_lambda;
}

void PumpDegree::setP1Lambda(const double& value)
{
	this->p1_lambda = value;
}

double PumpDegree::getTLambda() const
{
	return t_lambda;
}

void PumpDegree::setTLambda(const double& value)
{
	this->t_lambda = value;
}

double PumpDegree::getALambda() const
{
	return a_lambda;
}

void PumpDegree::setALambda(const double& value)
{
	this->a_lambda = value;
}

double PumpDegree::getP1K() const
{
	return p1_k;
}

void PumpDegree::setP1K(const double& value)
{
	this->p1_k = value;
}

double PumpDegree::getP2K() const
{
	return p2_k;
}

void PumpDegree::setP2K(const double& value)
{
	this->p2_k = value;
}

double PumpDegree::getGasQ() const
{
	return gas_q;
}

void PumpDegree::setGasQ(const double& value)
{
	this->gas_q = value;
}

double PumpDegree::getCoreHeight() const
{
	return core_height;
}

void PumpDegree::setCoreHeight(const double& value)
{
	this->core_height = value;
}

double PumpDegree::getCoreArea() const
{
	return core_area;
}

void PumpDegree::setCoreArea(const double& value)
{
	this->core_area = value;
}

double PumpDegree::getGasViscosity() const
{
	return gas_viscosity;
}

void PumpDegree::setGasViscosity(const double& value)
{
	this->gas_viscosity = value;
}

double PumpDegree::getDecayAlpha() const
{
	return decay_alpha;
}

void PumpDegree::setDecayAlpha(const double& value)
{
	this->decay_alpha = value;
}

double PumpDegree::getPermeabilityLambda() const
{
	return permeability_lambda;
}

void PumpDegree::setPermeabilityLambda(const double& value)
{
	this->permeability_lambda = value;
}

double PumpDegree::getPermeabilityK() const
{
	return permeability_k;
}

void PumpDegree::setPermeabilityK(const double& value)
{
	this->permeability_k = value;
}

long PumpDegree::getEvalDifficult() const
{
	return eval_difficult;
}

void PumpDegree::setEvalDifficult(const long& value)
{
	this->eval_difficult = value;
}

} // namespace cbm
