#ifndef CBM_TUNNEL_H
#define CBM_TUNNEL_H

#include "common.h"
#include <row.h>

namespace cbm {

class Tunnel
{
public:
	Tunnel();
	Tunnel(long id);
	Tunnel(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	double getB() const;
	void setB(const double& value);
	double getL() const;
	void setL(const double& value);
	double getS() const;
	void setS(const double& value);
	double getD() const;
	void setD(const double& value);
	double getWh() const;
	void setWh(const double& value);
	double getV() const;
	void setV(const double& value);
	double getQa() const;
	void setQa(const double& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long tunnel_id;
	double b;
	double l;
	double s;
	double d;
	double wh;
	double v;
	double qa;
	std::string comment;

}; // class Tunnel

} // namespace cbm

#endif // CBM_TUNNEL_H
