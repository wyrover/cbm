#-*- coding:utf-8 -*-
#!/usr/bin/env python

# 导入sqlalchemy模块
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from sqlalchemy.orm.exc import NoResultFound
from sqlalchemy.orm.exc import MultipleResultsFound
# from sqlalchemy.ext.declarative import declarative_base

from cbm import CbmService
from cbm.ttypes import *

import sql
import ServerHelper

#初始化sqlalchemy，连接mysql数据库
def init_sqlalchemy():
    #连接mysql数据并创建session会话
    # engine = create_engine("mysql+pymysql://root:@localhost/cbm?charset=utf-8")
    engine = create_engine("mysql+pymysql://root:@localhost/cbm")
    Session = sessionmaker()
    Session.configure(bind=engine)
    return Session

# 参考:处理多个service(http://blog.csdn.net/hivon/article/details/11681977)
# service接口处理类
class CbmServiceHandler:
  def __init__(self, Session):
    self.session = Session()
    # 解决mysql中文乱码问题
    self.session.execute("set names 'gbk';")

  def VerifyMineAccount(self, username, pwd):
    query = self.session.query(sql.Account).filter(sql.Account.username==username)
    if query.count() == 0:
        return 0  # 用户名不存在
    elif query.count() > 1:
        return -2 # 内部错误(用户名不唯一)
    else:
        accout = query.one()
        if accout.password != pwd:
            return -1  # 密码错误
        else:
            return 1  # 用户名和密码均匹配

  def GetAllMineBases(self):
    mine_bases = []
    try:
        query = self.session.query(sql.MineBase.name).all()
        mine_bases = [mine_base.name for mine_base in query]
    except NoResultFound, e:
        mine_bases = []
    return mine_bases

# 创建服务器
def create_server(host, port):
     # sqlalchemy连接mysql数据库
    Session = init_sqlalchemy()
    # 构造rpc消息处理接口
    handler = CbmServiceHandler(Session)
    processor = CbmService.Processor(handler)
    # 创建thrift rpc服务器
    server = ServerHelper.make_rpc_server(processor, host=host, port=port)
    return handler, server