#ifndef CBM_TUNNEL_DAO_H
#define CBM_TUNNEL_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/Tunnel.h"

namespace cbm {

class TunnelDao : public ModelDao
{
public:
	TunnelDao();
	~TunnelDao();
	long insert(Tunnel& obj);;
	bool update(Tunnel& obj);
	bool remove(Tunnel& obj);
	TunnelPtr getTunnelById(long id);
	TunnelList getTunnelList();

}; // class TunnelDao

} // namespace cbm

#endif // CBM_TUNNEL_DAO_H
