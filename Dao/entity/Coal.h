#ifndef CBM_COAL_H
#define CBM_COAL_H

#include "common.h"
#include <row.h>

namespace cbm {

class Coal
{
public:
	Coal();
	Coal(long id);
	Coal(soci::row& rs);
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MinePtr getMine() const;
	void setMine(const MinePtr& value);
	std::string getCoalName() const;
	void setCoalName(const std::string& value);
	long getCoalNumber() const;
	void setCoalNumber(const long& value);
	long getCoalMinable() const;
	void setCoalMinable(const long& value);
	double getCoalThick() const;
	void setCoalThick(const double& value);
	long getCoalRank() const;
	void setCoalRank(const long& value);
	long getCoalQuality() const;
	void setCoalQuality(const long& value);
	double getLayerPressure() const;
	void setLayerPressure(const double& value);
	double getGasContent() const;
	void setGasContent(const double& value);
	double getGasPenetration() const;
	void setGasPenetration(const double& value);
	double getFValue() const;
	void setFValue(const double& value);
	long getResAbundance() const;
	void setResAbundance(const long& value);
	long getConstComplexity() const;
	void setConstComplexity(const long& value);
	long getMineIndex() const;
	void setMineIndex(const long& value);
	double getVarCoeff() const;
	void setVarCoeff(const double& value);
	double getCoalStability() const;
	void setCoalStability(const double& value);
	double getDipAngle() const;
	void setDipAngle(const double& value);
	double getCavingZoneHeight() const;
	void setCavingZoneHeight(const double& value);
	double getLayerGap() const;
	void setLayerGap(const double& value);
	double getInfluenceFactor() const;
	void setInfluenceFactor(const double& value);
	double getResA1() const;
	void setResA1(const double& value);
	double getGasX1() const;
	void setGasX1(const double& value);
	double getResA2() const;
	void setResA2(const double& value);
	double getGasX2() const;
	void setGasX2(const double& value);
	double getGasWc() const;
	void setGasWc(const double& value);
	double getCoalR() const;
	void setCoalR(const double& value);
	double getCoalVr() const;
	void setCoalVr(const double& value);
	double getGasW0() const;
	void setGasW0(const double& value);
	double getGasEta() const;
	void setGasEta(const double& value);
	double getQR() const;
	void setQR(const double& value);
	double getQ0() const;
	void setQ0(const double& value);
	double getMineHeight() const;
	void setMineHeight(const double& value);

private:
	long coal_id;
	MinePtr mine;
	std::string coal_name;
	long coal_number;
	long coal_minable;
	double coal_thick;
	long coal_rank;
	long coal_quality;
	double layer_pressure;
	double gas_content;
	double gas_penetration;
	double f_value;
	long res_abundance;
	long const_complexity;
	long mine_index;
	double var_coeff;
	double coal_stability;
	double dip_angle;
	double caving_zone_height;
	double layer_gap;
	double influence_factor;
	double res_a1;
	double gas_x1;
	double res_a2;
	double gas_x2;
	double gas_wc;
	double coal_r;
	double coal_vr;
	double gas_w0;
	double gas_eta;
	double q_r;
	double q0;
	double mine_height;

}; // class Coal

} // namespace cbm

#endif // CBM_COAL_H
