#ifndef CBM_MINE_BASE_H
#define CBM_MINE_BASE_H

#include "common.h"
#include <row.h>

namespace cbm {

class MineBase
{
public:
	MineBase();
	MineBase(long id);
	MineBase(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	std::string getBaseName() const;
	void setBaseName(const std::string& value);
	std::string getBaseMine() const;
	void setBaseMine(const std::string& value);

private:
	long mine_base_id;
	std::string base_name;
	std::string base_mine;

}; // class MineBase

} // namespace cbm

#endif // CBM_MINE_BASE_H
