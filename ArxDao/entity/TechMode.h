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
	MinePtr getMine() const;
	void setMine(const MinePtr& value);
	std::string getModeName() const;
	void setModeName(const std::string& value);
	long getModeType() const;
	void setModeType(const long& value);

private:
	long tech_mode_id;
	MinePtr mine;
	std::string mode_name;
	long mode_type;

}; // class TechMode

} // namespace cbm

#endif // CBM_TECH_MODE_H
