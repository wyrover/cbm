#ifndef CBM_HELP_DAO_H
#define CBM_HELP_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/Help.h"

namespace cbm {

class HelpDao : public ModelDao
{
public:
	HelpDao();
	~HelpDao();
	long insert(Help& obj);;
	bool update(Help& obj);
	bool remove(Help& obj);
	HelpPtr getHelpById(long id);
	HelpList getHelpList();

}; // class HelpDao

} // namespace cbm

#endif // CBM_HELP_DAO_H
