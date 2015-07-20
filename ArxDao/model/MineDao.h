#ifndef CBM_MINE_DAO_H
#define CBM_MINE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/Mine.h"

namespace cbm {

class MineDao : public ModelDao
{
public:
	MineDao();
	~MineDao();
	long insert(Mine& obj);;
	bool update(Mine& obj);
	bool remove(Mine& obj);
	MinePtr getMineById(long id);
	MineList getMineList();

}; // class MineDao

} // namespace cbm

#endif // CBM_MINE_DAO_H
