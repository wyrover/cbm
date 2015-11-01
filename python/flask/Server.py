#-*- coding:utf-8 -*-
#!/usr/bin/env python

import sys, glob
sys.path.append('gen-py')
# sys.path.insert(0, glob.glob('../../lib/py/build/lib.*')[0])

import logging

import ControlServiceHelper
import CbmServiceHelper
import ServerHelper

if __name__ == '__main__':
    # 采用log默认的基本配置
    logging.basicConfig()

    # 创建control服务器
    ctrlHandler, ctrlServer = ControlServiceHelper.create_server('localhost', 9090)

    # 创建service服务器
    handler, server = CbmServiceHelper.create_server('localhost', 9100)

    # 注册service服务器到控制服务接口
    ctrlHandler.register(server)

    # 单开一个线程给service服务器用
    print '启动service服务器(端口:9100)...'
    t1 = ServerHelper.run_rpc_server(server, runThread=True)

    # 启动控制服务器,监听shutdown消息(会阻塞主线程)
    print '启动control服务器(端口:9090)...'
    ServerHelper.run_rpc_server(ctrlServer, runThread=False)
    