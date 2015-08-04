#ifndef CBM_TECH_MODE_H
#define CBM_TECH_MODE_H

#include "common.h"
#include <row.h>

namespace cbm {

class TechMode
{
public:
	TechMode();
	TechMode(long id);
	TechMode(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MineRegionPtr getMineRegion() const;
	void setMineRegion(const MineRegionPtr& value);
	std::string getName() const;
	void setName(const std::string& value);
	long getType() const;
	void setType(const long& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long tech_mode_id;
	MineRegionPtr mine_region;
	std::string name;
	long type;
	std::string comment;

}; // class TechMode

} // namespace cbm

#endif // CBM_TECH_MODE_H
