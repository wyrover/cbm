#ifndef CBM_MINE_H
#define CBM_MINE_H

#include "common.h"
#include <row.h>

namespace cbm {

class Mine
{
public:
	Mine();
	Mine(long id);
	Mine(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MineRegionPtr getMineRegion() const;
	void setMineRegion(const MineRegionPtr& value);
	std::string getUsername() const;
	void setUsername(const std::string& value);
	std::string getPassword() const;
	void setPassword(const std::string& value);
	std::string getMineName() const;
	void setMineName(const std::string& value);
	std::string getMineAddress() const;
	void setMineAddress(const std::string& value);
	double getCoalCapacity() const;
	void setCoalCapacity(const double& value);
	long getTopoGeo() const;
	void setTopoGeo(const long& value);
	long getHydrGeo() const;
	void setHydrGeo(const long& value);
	long getGroundCondition() const;
	void setGroundCondition(const long& value);
	double getQR() const;
	void setQR(const double& value);
	std::string getStereoSchemDiagram() const;
	void setStereoSchemDiagram(const std::string& value);
	double getKGas() const;
	void setKGas(const double& value);
	double getReserveW1() const;
	void setReserveW1(const double& value);
	double getReserveW2() const;
	void setReserveW2(const double& value);
	double getReserveW3() const;
	void setReserveW3(const double& value);
	double getReserveGas() const;
	void setReserveGas(const double& value);
	double getPumpKd() const;
	void setPumpKd(const double& value);
	double getPumpK1() const;
	void setPumpK1(const double& value);
	double getPumpK2() const;
	void setPumpK2(const double& value);
	double getPumpK3() const;
	void setPumpK3(const double& value);
	double getPumpK4() const;
	void setPumpK4(const double& value);
	double getPumpWc() const;
	void setPumpWc(const double& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long mine_id;
	MineRegionPtr mine_region;
	std::string username;
	std::string password;
	std::string mine_name;
	std::string mine_address;
	double coal_capacity;
	long topo_geo;
	long hydr_geo;
	long ground_condition;
	double q_r;
	std::string stereo_schem_diagram;
	double k_gas;
	double reserve_w1;
	double reserve_w2;
	double reserve_w3;
	double reserve_gas;
	double pump_kd;
	double pump_k1;
	double pump_k2;
	double pump_k3;
	double pump_k4;
	double pump_wc;
	std::string comment;

}; // class Mine

} // namespace cbm

#endif // CBM_MINE_H
