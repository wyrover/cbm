#ifndef CBM_PUMP_DEGREE_H
#define CBM_PUMP_DEGREE_H

#include "common.h"
#include <row.h>

namespace cbm {

class PumpDegree
{
public:
	PumpDegree();
	PumpDegree(long id);
	PumpDegree(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	CoalPtr getCoal() const;
	void setCoal(const CoalPtr& value);
	long getEvalMethod() const;
	void setEvalMethod(const long& value);
	double getQ0Alpha() const;
	void setQ0Alpha(const double& value);
	double getQtAlpha() const;
	void setQtAlpha(const double& value);
	double getTAlpha() const;
	void setTAlpha(const double& value);
	double getQLambda() const;
	void setQLambda(const double& value);
	double getRLambda() const;
	void setRLambda(const double& value);
	double getP0Lambda() const;
	void setP0Lambda(const double& value);
	double getP1Lambda() const;
	void setP1Lambda(const double& value);
	double getTLambda() const;
	void setTLambda(const double& value);
	double getALambda() const;
	void setALambda(const double& value);
	double getP1K() const;
	void setP1K(const double& value);
	double getP2K() const;
	void setP2K(const double& value);
	double getGasQ() const;
	void setGasQ(const double& value);
	double getCoreHeight() const;
	void setCoreHeight(const double& value);
	double getCoreArea() const;
	void setCoreArea(const double& value);
	double getGasViscosity() const;
	void setGasViscosity(const double& value);
	double getDecayAlpha() const;
	void setDecayAlpha(const double& value);
	double getPermeabilityLambda() const;
	void setPermeabilityLambda(const double& value);
	double getPermeabilityK() const;
	void setPermeabilityK(const double& value);
	long getEvalDifficult() const;
	void setEvalDifficult(const long& value);

private:
	long pump_degree_id;
	CoalPtr coal;
	long eval_method;
	double q0_alpha;
	double qt_alpha;
	double t_alpha;
	double q_lambda;
	double r_lambda;
	double p0_lambda;
	double p1_lambda;
	double t_lambda;
	double a_lambda;
	double p1_k;
	double p2_k;
	double gas_q;
	double core_height;
	double core_area;
	double gas_viscosity;
	double decay_alpha;
	double permeability_lambda;
	double permeability_k;
	long eval_difficult;

}; // class PumpDegree

} // namespace cbm

#endif // CBM_PUMP_DEGREE_H
