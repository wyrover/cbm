#-*- coding:utf-8 -*-
#!/usr/bin/env python

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from rpc.RpcClient import *

from cbm.ttypes import *
import rpc.SQL as SQL

def test_copy_obj():
	# sql_coal = SQLClientHelper.GetCoalById(5)
	# print sql_coal
	# coal = Coal()
	# print coal
	# print CbmUtil.CopyAttribsOfCbmType("Coal", sql_coal, coal)
	# print coal

	coal_lists = SQLClientHelper.GetCoalListByForeignKey("mine_id", 1)
	# coal_lists = SQLClientHelper.GetCoalListByField1("mine_id", '1')
	print coal_lists[0].name.decode('utf-8')
	# print SQLClientHelper.GetCoalByForeignKey('mine_id', '1')
	# print SQLClientHelper.GetCoalListByForeignKey('mine_id', '1')
	# print SQLClientHelper.GetCoalById('1')

def test_draw_coal_occurrence_graph():
	mine_id = 4
	CbmClientHelper.SendCommandToCAD("JL.DrawOccurrenceGraph %d" % (mine_id), True)

def test_draw_graph_11():
	coal_id, tech_id = 5, 1
	CbmClientHelper.SendCommandToCAD("JL.DrawPlaneGraph11 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawHeadGraph11 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawDipGraph11 %d %d" % (coal_id, tech_id), True)

def test_draw_graph_12():
	coal_id, tech_id = 5, 1
	CbmClientHelper.SendCommandToCAD("JL.DrawPlaneGraph12 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawHeadGraph12 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawDipGraph12 %d %d" % (coal_id, tech_id), True)

def test_draw_graph_21():
	coal_id, tech_id = 5, 1
	CbmClientHelper.SendCommandToCAD("JL.DrawPlaneGraph21 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawHeadGraph21 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawDipGraph21 %d %d" % (coal_id, tech_id), True)

def test_draw_graph_23():
	coal_id, tech_id = 5, 1
	CbmClientHelper.SendCommandToCAD("JL.DrawPlaneGraph23 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawHeadGraph23 %d %d" % (coal_id, tech_id), True)
	# CbmClientHelper.SendCommandToCAD("JL.DrawDipGraph23 %d %d" % (coal_id, tech_id), True)	

