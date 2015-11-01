#-*- coding:utf-8 -*-
#!/usr/bin/env python

import sys
import ServerHelper
from cbm import ControlService

# 关闭服务器的思路:
# http://grokbase.com/t/thrift/user/11541vwzj4/stop-the-thrift-server

#服务器控制接口处理类
class ControlServiceHandler:
    def __init__(self):
        self.server_list = []
    def register(self, server):
        self.server_list.append(server)
    def shutdown(self):
        print '服务器个数:',len(self.server_list)
        for server in self.server_list:
            print '关闭服务器(尚未实现,直接强制退出进程)...'
            # python的thrift框架没有实现stop()函数
            # 因此,直接强制退出(sys.eixt())
            # server.stop()
            sys.exit()

def create_server(host, port):
     # 服务器控制消息处理接口
    ctrlHandler = ControlServiceHandler()
    # 创建控制服务器
    ctrlServer = ServerHelper.make_rpc_server(ControlService.Processor(ctrlHandler), host = host, port=port)
    # 注册服务器到控制服务接口
    ctrlHandler.register(ctrlServer)
    return ctrlHandler, ctrlServer