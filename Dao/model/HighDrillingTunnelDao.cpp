#include "HighDrillingTunnelDao.h"

namespace cbm {

HighDrillingTunnelDao::HighDrillingTunnelDao() : ModelDao()
{
}

HighDrillingTunnelDao::~HighDrillingTunnelDao()
{
}

long HighDrillingTunnelDao::insert(HighDrillingTunnel& obj)
{
	return dao->insert(obj);
}

bool HighDrillingTunnelDao::update(HighDrillingTunnel& obj)
{
	return dao->update(obj);
}

bool HighDrillingTunnelDao::remove(HighDrillingTunnel& obj)
{
	return dao->remove(obj);
}

HighDrillingTunnelPtr HighDrillingTunnelDao::getHighDrillingTunnelById(long id)
{
	HighDrillingTunnelList list = dao->select<HighDrillingTunnel>("cbm_high_drilling_tunnel", "*", "where id="+to_string(id));
	HighDrillingTunnelPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

HighDrillingTunnelList HighDrillingTunnelDao::getHighDrillingTunnelList()
{
	return dao->select<HighDrillingTunnel>("cbm_high_drilling_tunnel", "*", "order by HighDrillingTunnel_id desc");
}

} // namespace cbm
