#ifndef CBM_READY_TUNNEL_DAO_H
#define CBM_READY_TUNNEL_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/ReadyTunnel.h"

namespace cbm {

class ReadyTunnelDao : public ModelDao
{
public:
	ReadyTunnelDao();
	~ReadyTunnelDao();
	long insert(ReadyTunnel& obj);;
	bool update(ReadyTunnel& obj);
	bool remove(ReadyTunnel& obj);
	ReadyTunnelPtr getReadyTunnelById(long id);
	ReadyTunnelList getReadyTunnelList();

}; // class ReadyTunnelDao

} // namespace cbm

#endif // CBM_READY_TUNNEL_DAO_H
