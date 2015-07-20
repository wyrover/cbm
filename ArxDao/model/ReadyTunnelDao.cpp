#include "stdafx.h"
#include "ReadyTunnelDao.h"

namespace cbm {

ReadyTunnelDao::ReadyTunnelDao() : ModelDao()
{
}

ReadyTunnelDao::~ReadyTunnelDao()
{
}

long ReadyTunnelDao::insert(ReadyTunnel& obj)
{
	return dao->insert(obj);
}

bool ReadyTunnelDao::update(ReadyTunnel& obj)
{
	return dao->update(obj);
}

bool ReadyTunnelDao::remove(ReadyTunnel& obj)
{
	return dao->remove(obj);
}

ReadyTunnelPtr ReadyTunnelDao::getReadyTunnelById(long id)
{
	ReadyTunnelList list = dao->select<ReadyTunnel>("cbm_ready_tunnel", "*", "where id="+to_string(id));
	ReadyTunnelPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

ReadyTunnelList ReadyTunnelDao::getReadyTunnelList()
{
	return dao->select<ReadyTunnel>("cbm_ready_tunnel", "*", "order by ReadyTunnel_id desc");
}

} // namespace cbm
