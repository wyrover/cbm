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

from cbm import CbmService, ControlService
from cbm.ttypes import *

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
  usename, pwd = 'dlj', '123'
  ret = client.VerifyMineAccount(usename, pwd)
  print '==>用户名:%s 密码:%s 验证结果%d' % (usename, pwd, ret)

#测试3
def GetAllMineBases(client):
  mine_bases = client.GetAllMineBases()
  print '煤炭基地列表:',mine_bases[1]

# 注册所有的测试函数
all_cmds = {
  '1': VerifyMineAccount,
  '2': GetAllMineBases,
  'q': QuitServer
}

def main():
  try:
    
    cbm_client = RpcClient(CbmService, port=9100)
    cbm_client.start()

    while True:
      cmd = raw_input('请输入一个命令:')
      if cmd == 'q' or cmd == 'Q':
        break
      if cmd in all_cmds:
        all_cmds[cmd](cbm_client.get())
        print '\n'
      else:
        print '命令%s未实现!!!' % cmd
    cbm_client.close()

    # 关闭rpc服务器
    QuitServer()

  except Thrift.TException, tx:
    print '%s' % (tx.message)

if __name__ == '__main__':
  main()