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

# 导入sqlalchemy模块
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
# from sqlalchemy.ext.declarative import declarative_base
import sql

import threading

#服务器控制接口处理类
class ServerControlHandler:
    def __init__(self):
        self.server_list = []
    def register(self, server):
        self.server_list.append(server)
    def shutdown(self):
        print '服务器个数:',len(self.server_list)
        for server in self.server_list:
            print '关闭服务器(尚未实现,直接强制退出进程)...'
            # python的thrift框架没有实现stop()函数
            # server.stop()
            #直接强制退出
            sys.exit()

#service接口处理类
class CbmServiceHandler:
  def __init__(self, Session):
    self.session = Session()

  def VerifyMineAccount(self, username, pwd):
    print '验证用户名:%s   密码:%s是否匹配' % (username, pwd)
    query = self.session.query(sql.Account)
    # print query.statement # 同上
    return 0

  def GetAllMineBases(self):
    print '获取所有的煤炭基地名称,返回一个列表'
    return []

#初始化sqlalchemy，连接mysql数据库
def init_sqlalchemy():
    #连接mysql数据并创建session会话
    engine = create_engine("mysql+pymysql://root:@localhost/cbm?charset=utf8")
    Session = sessionmaker()
    Session.configure(bind=engine)
    return Session

def make_rpc_server(processor, host='localhost', port=9090):
    transport = TSocket.TServerSocket(host=host, port=port)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()
    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)
    
    # You could do one of these for a multithreaded server
    # server = TServer.TThreadedServer(processor, transport, tfactory, pfactory)
    
    # server = TServer.TThreadPoolServer(processor, transport, tfactory, pfactory)
    # server.daemon = True #enable ctrl+c to exit the server
    # server.setNumThreads(10);
    return server

def run_rpc_server(server):
    print '启动rpc服务器(python)...\n'
    server.serve()

# 关闭服务器的思路:
# http://grokbase.com/t/thrift/user/11541vwzj4/stop-the-thrift-server
if __name__ == '__main__':
    # 服务器控制消息处理接口
    ctrlHandler = ServerControlHandler()
    # 创建控制服务器
    ctrlServer = make_rpc_server(ServerControl.Processor(ctrlHandler), port=9090)
    # 注册服务器到控制服务接口
    ctrlHandler.register(ctrlServer)

    # sqlalchemy连接mysql数据库
    Session = init_sqlalchemy()
    # 构造rpc消息处理接口
    handler = CbmServiceHandler(Session)
    processor = CbmService.Processor(handler)
    # 创建thrift rpc服务器
    server = make_rpc_server(processor, port=9100)

    # 注册服务器到控制服务接口
    ctrlHandler.register(server)

    # 启动线程，在线程中做rpc服务
    t1 = threading.Thread(target=run_rpc_server,args=(server,))
    t1.setDaemon(True)
    t1.start()

    # 启动控制服务器(会阻塞主线程)
    run_rpc_server(ctrlServer)
    