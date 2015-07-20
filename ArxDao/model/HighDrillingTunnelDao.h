#ifndef CBM_HIGH_DRILLING_TUNNEL_DAO_H
#define CBM_HIGH_DRILLING_TUNNEL_DAO_H

#include "../dao/ModelDao.h"
#include "../entity/HighDrillingTunnel.h"

namespace cbm {

class HighDrillingTunnelDao : public ModelDao
{
public:
	HighDrillingTunnelDao();
	~HighDrillingTunnelDao();
	long insert(HighDrillingTunnel& obj);;
	bool update(HighDrillingTunnel& obj);
	bool remove(HighDrillingTunnel& obj);
	HighDrillingTunnelPtr getHighDrillingTunnelById(long id);
	HighDrillingTunnelList getHighDrillingTunnelList();

}; // class HighDrillingTunnelDao

} // namespace cbm

#endif // CBM_HIGH_DRILLING_TUNNEL_DAO_H
