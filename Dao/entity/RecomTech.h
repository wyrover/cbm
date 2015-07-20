#ifndef CBM_RECOM_TECH_H
#define CBM_RECOM_TECH_H

#include "common.h"
#include <row.h>

namespace cbm {

class RecomTech
{
public:
	RecomTech();
	RecomTech(long id);
	RecomTech(soci::row& rs);
	std::string getTableName() const;
	std::string getSqlInsert() const;
	std::string getSqlUpdate() const;
	std::string getSqlDelete() const;
	long getId() const;
	void setId(const long& value);
	MinePtr getMine() const;
	void setMine(const MinePtr& value);
	std::string getName() const;
	void setName(const std::string& value);
	long getIsKey() const;
	void setIsKey(const long& value);
	std::string getDoc() const;
	void setDoc(const std::string& value);
	std::string getVideo() const;
	void setVideo(const std::string& value);

private:
	long recom_tech_id;
	MinePtr mine;
	std::string name;
	long is_key;
	std::string doc;
	std::string video;

}; // class RecomTech

} // namespace cbm

#endif // CBM_RECOM_TECH_H
