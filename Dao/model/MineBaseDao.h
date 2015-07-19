#ifndef CBM_MINE_BASE_DAO_H
#define CBM_MINE_BASE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/MineBase.h"

namespace cbm {

class MineBaseDao : public ModelDao
{
public:
	MineBaseDao();
	~MineBaseDao();
	long insert(MineBase& obj);;
	bool update(MineBase& obj);
	bool remove(MineBase& obj);
	MineBasePtr getMineBaseById(long id);
	MineBaseList getMineBaseList();

}; // class MineBaseDao

} // namespace cbm

#endif // CBM_MINE_BASE_DAO_H
