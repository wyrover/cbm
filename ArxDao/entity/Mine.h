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
	std::string getUsername() const;
	void setUsername(const std::string& value);
	std::string getPassword() const;
	void setPassword(const std::string& value);
	std::string getMineName() const;
	void setMineName(const std::string& value);
	std::string getMineRegion() const;
	void setMineRegion(const std::string& value);
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

private:
	long mine_id;
	std::string username;
	std::string password;
	std::string mine_name;
	std::string mine_region;
	std::string mine_address;
	double coal_capacity;
	long topo_geo;
	long hydr_geo;
	long ground_condition;
	double q_r;
	std::string stereo_schem_diagram;
	double k_gas;

}; // class Mine

} // namespace cbm

#endif // CBM_MINE_H
