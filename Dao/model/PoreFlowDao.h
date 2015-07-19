#ifndef CBM_PORE_FLOW_DAO_H
#define CBM_PORE_FLOW_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/PoreFlow.h"

namespace cbm {

class PoreFlowDao : public ModelDao
{
public:
	PoreFlowDao();
	~PoreFlowDao();
	long insert(PoreFlow& obj);;
	bool update(PoreFlow& obj);
	bool remove(PoreFlow& obj);
	PoreFlowPtr getPoreFlowById(long id);
	PoreFlowList getPoreFlowList();

}; // class PoreFlowDao

} // namespace cbm

#endif // CBM_PORE_FLOW_DAO_H
