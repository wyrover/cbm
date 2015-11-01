#-*- coding:utf-8 -*-
#!/usr/bin/env python

import sys, glob
sys.path.append('gen-py')
# sys.path.insert(0, glob.glob('../../lib/py/build/lib.*')[0])

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

from cbm import CbmService
from cbm.ttypes import *
from ctrl import ControlService

#客户端封装类
class RpcClient:
  def __init__(self, Service, host='localhost', port=9090):
    self.protocol = None
    self.transport = None
    self.client = None
    self.host = host
    self.port = port
    self.Service = Service
  
  def start(self):
    # Make socket
    self.transport = TSocket.TSocket(self.host, self.port)
    # Buffering is critical. Raw sockets are very slow
    self.transport = TTransport.TBufferedTransport(self.transport)
    # Wrap in a protocol
    self.protocol = TBinaryProtocol.TBinaryProtocol(self.transport)
    # 构造客户端对象
    self.client = self.Service.Client(self.protocol)
    # Connect!
    self.transport.open()

  def get(self):
      return self.client

  def close(self):
    if self.transport is not None:
      self.transport.close()

#测试1
def QuitServer():
  ctrl_client = RpcClient(ControlService, port=9090)
  ctrl_client.start()
  ctrl_client.get().shutdown()
  ctrl_client.close()

#测试2
def VerifyMineAccount(client):
  username = raw_input('请输入用户名:')
  pwd = raw_input('请输入密码:')
  ret = client.VerifyMineAccount(username, pwd)
  if ret == 0:
    print '用户名不存在'
  elif ret == -1:
    print '密码错误'
  elif ret == 1:
    print '用户名和密码正确'
  else:
    print '未知错误'

#测试3
def GetAllMineBases(client):
  mine_bases = client.GetAllMineBases()
  print '煤炭基地列表:'
  for base in mine_bases:
    print '\t',base

def GetAllMineRegions(client):
  baseName = raw_input('请输入煤炭基地名称:')
  mine_regions = client.GetAllMineRegions(baseName)
  print '%s的矿区:' % (baseName)
  for region in mine_regions:
    print '\t',region

def GetBaseByRegion(client):
  regionName = raw_input('请输入矿区的名称:')
  baseName = client.GetBaseByRegion(regionName)
  print '%s的基地:%s' % (regionName, baseName)

def GetSampleMine(client):
  regionName = raw_input('请输入矿区的名称:')
  mine = client.GetSampleMine(regionName)
  print '示范矿区:%s的虚拟矿井:%s' % (regionName, mine)

def GetSampleCoal(client):
  regionName = raw_input('请输入矿区的名称:')
  coal = client.GetSampleCoal(regionName)
  print '示范矿区:%s的虚拟煤层:%s' % (regionName, coal)

def GetCoalNames(client):
  mine_id = int(input('请输入矿井id:'))
  coal_names = client.GetCoalNames(mine_id)
  print '矿井id=%d的煤层列表:' % mine_id
  for name in coal_names:
    print name

def GetCoalIds(client):
  mine_id = int(input('请输入矿井id:'))
  coal_ids = client.GetCoalIds(mine_id)
  print '矿井id=%d的煤层列表:' % mine_id
  for coal_id in coal_ids:
    print coal_id

def GetOnlineAccountId(client):
  account_id = client.GetOnlineAccountId()
  print '当前登录用户的id:%d' % account_id

def GetOnlineMine(client):
  mine = client.GetOnlineMine()
  print '当前登录用户对应的矿井:',mine

def GetWorkAreas(client):
  mine_id = int(input('请输入矿井id:'))
  work_areas = client.GetWorkAreas(mine_id)
  print '矿井id=%d的采区列表:' % mine_id
  for work_area in work_areas:
    print work_area.id, work_area.name

def GetWorkSurfs(client):
  mine_id = int(input('请输入矿井id:'))
  work_surfs = client.GetWorkSurfs(mine_id)
  print '矿井id=%d的回采工作面列表:' % mine_id
  for work_surf in work_surfs:
    print work_surf.id, work_surf.name

def GetDrillingSurfs(client):
  mine_id = int(input('请输入矿井id:'))
  drilling_surfs = client.GetDrillingSurfs(mine_id)
  print '矿井id=%d的掘进工作面列表:' % mine_id
  for drilling_surf in drilling_surfs:
    print drilling_surf.id, drilling_surf.name

def InitSampleRegion(client):
  print '创建超级管理员账户和密码'
  client.InitSampleRegion()

# 注册所有的测试函数
all_cmds = {
  '1': VerifyMineAccount,
  '2': GetAllMineBases,
  '3': GetAllMineRegions,
  '4': GetBaseByRegion,
  '5': GetSampleMine,
  '6': GetSampleCoal,
  '7': GetCoalNames,
  '8': GetCoalIds,
  '9': GetOnlineAccountId,
  '10': GetOnlineMine,
  '11': GetWorkAreas,
  '12': GetWorkSurfs,
  '13': GetDrillingSurfs,
  '14': InitSampleRegion,
  'q': QuitServer
}

def main():
  try:
    
    service_client = RpcClient(CbmService, port=9100)
    service_client.start()

    while True:
      cmd = raw_input('请输入命令:')
      if cmd == 'q' or cmd == 'Q':
        break
      if cmd in all_cmds:
        all_cmds[cmd](service_client.get())
        print '\n'
      else:
        print '命令%s未实现!!!' % cmd
    service_client.close()

    # 关闭rpc服务器
    QuitServer()

  except Thrift.TException, tx:
    print '%s' % (tx.message)

if __name__ == '__main__':
  main()