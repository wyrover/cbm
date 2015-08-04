#ifndef CBM_HELP_H
#define CBM_HELP_H

#include "common.h"
#include <row.h>

namespace cbm {

class Help
{
public:
	Help();
	Help(long id);
	Help(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	std::string getHelpField() const;
	void setHelpField(const std::string& value);
	long getHelpType() const;
	void setHelpType(const long& value);
	std::string getHelpValue() const;
	void setHelpValue(const std::string& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long help_id;
	std::string help_field;
	long help_type;
	std::string help_value;
	std::string comment;

}; // class Help

} // namespace cbm

#endif // CBM_HELP_H
