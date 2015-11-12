#-*- coding:utf-8 -*-
#!/usr/bin/env python

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from rpc.RpcClient import *

from cbm.ttypes import *
import rpc.SQL as SQL

def test_copy():
	sql_coal = SQLClientHelper.GetCoalById(5)
	print sql_coal
	coal = Coal()
	print coal
	print CbmUtil.CopyAttribsOfCbmType("Coal", sql_coal, coal)
	print coal

def DrawPlaneGraph11():
	coal_id, tech_id = 5, 1
	CbmClientHelper.SendCommandToCAD("JL.DrawPlaneGraph11 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawHeadGraph11 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawDipGraph11 %d %d" % (coal_id, tech_id), True)
	

