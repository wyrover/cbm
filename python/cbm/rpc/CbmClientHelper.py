#-*- coding:utf-8 -*-

from time import ctime,sleep

from cbm.ttypes import *
from cbm import CbmService
from RpcClient import RpcClient, HOST, PORT1, PORT2
import CbmUtil

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

def GetMineRegionsOfBase(baseName):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetMineRegionsOfBase(baseName)
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

def GetSampleMineOfRegion(regionName):
	ret = Mine()
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetSampleMineOfRegion(regionName)
		service_client.close()
	except Exception, e:
		print e
		ret.id = -1
	return ret

def GetSampleCoalOfRegion(regionName):
	ret = Coal()
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetSampleCoalOfRegion(regionName)
		service_client.close()
	except Exception, e:
		print e
		ret.id = -1
	return ret

def GetCoalNamesOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetCoalNamesOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetCoalIdsOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetCoalIdsOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetWorkAreasOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkAreasOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetWorkSurfsOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkSurfsOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetDrillingSurfsOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetDrillingSurfsOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetWorkAreaIdsOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkAreaIdsOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetWorkSurfIdsOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetWorkSurfIdsOfMine(mine_id)
		service_client.close()
	except Exception, e:
		print e
		ret = []
	return ret

def GetDrillingSurfIdsOfMine(mine_id):
	ret = []
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		ret = service_client.get().GetDrillingSurfIdsOfMine(mine_id)
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

def SendCommandToCAD(cmd):
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		service_client.get().SendCommandToCAD(cmd)
		service_client.close()
	except Exception, e:
		print e

def GetJsonDatasFromCAD(data_type, wait_seconds=2):
	if wait_seconds < 1:wait_seconds = 2
	if wait_seconds > 10:wait_seconds = 10
	ret = "{}"
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		# 需要一些cad的数据，向rpc请求,rpc分配一个密钥
		secret_key = service_client.get().RequestJsonDatasFromCAD(data_type)
		print u'客户端:得到密钥:%s' % secret_key
		# 等待几秒钟
		sleep(wait_seconds)
		print u'客户端:等待%s秒' % wait_seconds
		# 从rpc缓存中提取数据
		ret = service_client.get().GetJsonDatasFromRpcCache(secret_key)
		service_client.close()
		print u'客户端:从rpc缓存中提取数据:%s' % ret
		
	except Exception, e:
		print e
		ret = "{}"
	return ret

def PostJsonDatasFromCAD(data_type, secret_key, json_datas):
	try:
		service_client = RpcClient(CbmService, host=HOST, port=PORT2)
		service_client.start()
		service_client.get().PostJsonDatasFromCAD(data_type, secret_key, json_datas)
		service_client.close()
	except Exception, e:
		print e