#ifndef CMB_MINE_REGION_H
#define CMB_MINE_REGION_H

#include "common.h"
#include <row.h>

namespace cbm {

class MineRegion
{
public:
	MineRegion();
	MineRegion(long id);
	MineRegion(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MineBasePtr getMineBase() const;
	void setMineBase(const MineBasePtr& value);
	std::string getName() const;
	void setName(const std::string& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long mine_region_id;
	MineBasePtr mine_base;
	std::string name;
	std::string comment;

}; // class MineRegion

} // namespace cbm

#endif // CMB_MINE_REGION_H
