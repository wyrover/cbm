#-*- coding:utf-8 -*-

from RpcClient import *
from ctrl import ControlService

def QuitServer():
  ctrl_client = RpcClient(ControlService, host=HOST, port=PORT1)
  ctrl_client.start()
  ctrl_client.get().ShutDown()
  ctrl_client.close()