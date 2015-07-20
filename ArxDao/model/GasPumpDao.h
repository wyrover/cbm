#ifndef CBM_GAS_PUMP_DAO_H
#define CBM_GAS_PUMP_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/GasPump.h"

namespace cbm {

class GasPumpDao : public ModelDao
{
public:
	GasPumpDao();
	~GasPumpDao();
	long insert(GasPump& obj);;
	bool update(GasPump& obj);
	bool remove(GasPump& obj);
	GasPumpPtr getGasPumpById(long id);
	GasPumpList getGasPumpList();

}; // class GasPumpDao

} // namespace cbm

#endif // CBM_GAS_PUMP_DAO_H
