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

from cbm import CbmService, ServerControl
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
def quit(client):
  # 关闭服务器
  client.shutdown()

#测试2
def test_service(client):
  print '验证结果:',client.VerifyMineAccount('dlj', '123')
  mine_bases = client.GetAllMineBases()
  print mine_bases

def main():
  try:
    
    server_client = RpcClient(CbmService, port=9100)
    server_client.start()
    test_service(server_client.get())
    server_client.close()

    ctrl_client = RpcClient(ServerControl, port=9090)
    ctrl_client.start()
    quit(ctrl_client.get())
    ctrl_client.close()

  except Thrift.TException, tx:
    print '%s' % (tx.message)

if __name__ == '__main__':
  main()