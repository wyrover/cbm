#ifndef CBM_GAS_RESERVE_DAO_H
#define CBM_GAS_RESERVE_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/GasReserve.h"

namespace cbm {

class GasReserveDao : public ModelDao
{
public:
	GasReserveDao();
	~GasReserveDao();
	long insert(GasReserve& obj);;
	bool update(GasReserve& obj);
	bool remove(GasReserve& obj);
	GasReservePtr getGasReserveById(long id);
	GasReserveList getGasReserveList();

}; // class GasReserveDao

} // namespace cbm

#endif // CBM_GAS_RESERVE_DAO_H
