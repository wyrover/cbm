#ifndef CBM_TECHNOLOGY_H
#define CBM_TECHNOLOGY_H

#include "common.h"
#include <row.h>

namespace cbm {

class Technology
{
public:
	Technology();
	Technology(long id);
	Technology(soci::row& rs);
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
	long getIskey() const;
	void setIskey(const long& value);
	std::string getDoc() const;
	void setDoc(const std::string& value);
	std::string getVideo() const;
	void setVideo(const std::string& value);
	std::string getComment() const;
	void setComment(const std::string& value);

private:
	long technology_id;
	MineRegionPtr mine_region;
	std::string name;
	long iskey;
	std::string doc;
	std::string video;
	std::string comment;

}; // class Technology

} // namespace cbm

#endif // CBM_TECHNOLOGY_H
