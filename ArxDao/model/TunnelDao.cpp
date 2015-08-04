#include "stdafx.h"
#include "TunnelDao.h"

namespace cbm {

TunnelDao::TunnelDao() : ModelDao()
{
}

TunnelDao::~TunnelDao()
{
}

long TunnelDao::insert(Tunnel& obj)
{
	return dao->insert(obj);
}

bool TunnelDao::update(Tunnel& obj)
{
	return dao->update(obj);
}

bool TunnelDao::remove(Tunnel& obj)
{
	return dao->remove(obj);
}

TunnelPtr TunnelDao::getTunnelById(long id)
{
	TunnelList list = dao->select<Tunnel>("cbm_tunnel", "*", "where id="+to_string(id));
	TunnelPtr obj;
	if(list->size() > 0) {
		obj = list->at(0);
	}
	return obj;
}

TunnelList TunnelDao::getTunnelList()
{
	return dao->select<Tunnel>("cbm_tunnel", "*", "order by Tunnel_id desc");
}

} // namespace cbm
