#ifndef CBM_RES_ABUNDANCE_H
#define CBM_RES_ABUNDANCE_H

#include "common.h"
#include <row.h>

namespace cbm {

class ResAbundance
{
public:
	ResAbundance();
	ResAbundance(long id);
	ResAbundance(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	std::string getType() const;
	void setType(const std::string& value);
	double getMinAbundance() const;
	void setMinAbundance(const double& value);
	double getMaxAbundance() const;
	void setMaxAbundance(const double& value);

private:
	long res_abundance_id;
	std::string type;
	double min_abundance;
	double max_abundance;

}; // class ResAbundance

} // namespace cbm

#endif // CBM_RES_ABUNDANCE_H
