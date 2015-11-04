#-*- coding:utf-8 -*-

from cbm.ttypes import *
import CbmUtil
from RpcClient import *

def InitSampleMine(region_id, account_id, name):
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().InitSampleMine(region_id, account_id, name)
		service_client.close()
	except Exception, e:
		print e

def InitSampleRegion():
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().InitSampleRegion()
		service_client.close()
	except Exception, e:
		print e

def GetOnlineAccountId():
	ret = -1
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetOnlineAccountId()
		service_client.close()
	except Exception, e:
		print e
		ret = -1
    return ret

def GetOnlineMine():
	ret = Mine()
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetOnlineMine()
		service_client.close()
	except Exception, e:
		print e
		ret.id = -1
    return ret

def VerifyMineAccount(username, pwd):
	ret = -2
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().VerifyMineAccount(username, pwd)
		service_client.close()
	except Exception, e:
		print e
		ret = -2
    return ret

def GetAllMineBases():
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetAllMineBases()
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetAllMineRegions(baseName):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetAllMineRegions(baseName)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetBaseByRegion(regionName):
	ret = ''
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetBaseByRegion(regionName)
		service_client.close()
	except Exception, e:
		print e
		ret = ''
    return ret

def GetSampleMine(regionName):
	ret = Mine()
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetSampleMine(regionName)
		service_client.close()
	except Exception, e:
		print e
		ret.id = -1
    return ret

def GetSampleCoal(regionName):
	ret = Coal()
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetSampleCoal(regionName)
		service_client.close()
	except Exception, e:
		print e
		ret.id = -1
    return ret

def GetCoalNames(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetCoalNames(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetCoalIds(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetCoalIds(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetWorkAreas(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkAreas(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetWorkSurfs(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkSurfs(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetDrillingSurfs(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetDrillingSurfs(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetWorkAreaIds(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkAreaIds(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetWorkSurfIds(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkSurfIds(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def GetDrillingSurfIds(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetDrillingSurfIds(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
    return ret

def DifficultEval(coal):
	ret = 0.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().DifficultEval(coal)
		service_client.close()
	except Exception, e:
		print e
		ret = 0.0
    return ret

def DifficultEvalString(coal):
	ret = ''
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().DifficultEvalString(coal)
		service_client.close()
	except Exception, e:
		print e
		ret = ''
    return ret

def MineGasReservesW1(mine_id):
	ret = 0.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().MineGasReservesW1(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = 0.0
    return ret

def MineGasReservesW2(mine_id):
	ret = 0.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().MineGasReservesW2(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = 0.0
    return ret

def WorkAreaGasFlow(work_area, K1):
	ret = -1.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().WorkAreaGasFlow(work_area, K1)
		service_client.close()
	except Exception, e:
		print e
		ret = -1.0
    return ret

def MineGasFlow(mine):
	ret = 0.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().MineGasFlow(mine)
		service_client.close()
	except Exception, e:
		print e
		ret = 0.0
    return ret

def WorkSurfGasFlow1(coal, work_area, work_surf):
	ret = 0.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().WorkSurfGasFlow1(coal, work_area, work_surf)
		service_client.close()
	except Exception, e:
		print e
		ret = 0.0
    return ret

def WorkSurfGasFlow2(coal, work_area, work_surf):
	ret = 0.0
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().WorkSurfGasFlow2(coal, work_area, work_surf)
		service_client.close()
	except Exception, e:
		print e
		ret = 0.0
    return ret

def DrillingSurfGasFlow(coal, drilling_surf, tunnel):
	ret = DrillingSurfGasFlowResult()
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().DrillingSurfGasFlow(coal, drilling_surf, tunnel)
		service_client.close()
	except Exception, e:
		print e
		ret.q0 = 0.0
		ret.q3 = 0.0
		ret.q4 = 0.0
		ret.qa = 0.0
    return ret
