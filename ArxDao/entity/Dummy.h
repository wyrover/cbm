#ifndef CBM_DUMMY_H
#define CBM_DUMMY_H

#include "common.h"
#include <row.h>

namespace cbm {

class Dummy
{
public:
	Dummy();
	Dummy(long id);
	Dummy(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);

private:
	long id;

}; // class Dummy

} // namespace cbm

#endif // CBM_DUMMY_H
