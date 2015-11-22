# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_decision_dlg import *

from HighCoalDlg import *
from HighCoalsDlg import *
from LowNearlyCoalsDlg import *
from LowFarCoalsDlg import *
from LowCoalDlg import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import UiHelper
import DataHelper

class DecisionDlg(BaseDialog):
	def __init__(self, mine_id=-1, parent=None):
		super(DecisionDlg, self).__init__(parent)
		self.ui = Ui_decision_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		# 设置表格样式
		UiHelper.InitTableStyle(self.ui.permeability_k_table)
		UiHelper.InitTableStyle(self.ui.protect_layer_table)
		UiHelper.InitTableStyle(self.ui.coal_population_table)
		self.ui.permeability_k_table.setColumnWidth(0,100)
		self.ui.permeability_k_table.setColumnWidth(1,100)
		self.ui.permeability_k_table.setColumnWidth(2,100)
		self.ui.permeability_k_table.setColumnWidth(3,190)
		self.ui.protect_layer_table.setColumnWidth(0,100)
		self.ui.protect_layer_table.setColumnWidth(1,100)
		self.ui.protect_layer_table.setColumnWidth(2,100)
		self.ui.protect_layer_table.setColumnWidth(3,100)
		self.ui.coal_population_table.setColumnWidth(0,100)
		self.ui.coal_population_table.setColumnWidth(1,100)
		self.ui.coal_population_table.setColumnWidth(2,125)
		self.ui.coal_population_table.setColumnWidth(3,100)
		self.ui.coal_population_table.setColumnWidth(4,100)

		# 使得table不可编辑
		# self.ui.permeability_k_table.setFocusPolicy(Qt.Qt.NoFocus)
		# self.ui.protect_layer_table.setFocusPolicy(Qt.Qt.NoFocus)
		# self.ui.coal_population_table.setFocusPolicy(Qt.Qt.NoFocus)

		self.setTitle(u"煤层气抽采技术模式决策依据")
		self.setFixedSize(self.width(), self.height())
		self.ui.graph.clicked.connect(self.onGraph)
		self.ui.decision.clicked.connect(self.onDecision)
		# 待决策的矿井
		self.mine_id = mine_id
		#初始化
		self.init()

	def init(self):
		# 渗透条件表
		self.fillPermeabilityKTable()
		# 保护层开采条件表
		self.fillProtectLayerTable()
		# 煤层群条件表
		self.fillCoalPopulationTable()
		
		# 渗透率条件(1-中高渗  0-低渗)
		# c1 = self.getPermeabilityKType()
	
	def fillPermeabilityKTable(self):
		# 清空
		self.ui.permeability_k_table.clearContents()
		# 查找矿井辖属的煤层
		coal_lists = SQLClientHelper.GetCoalListByForeignKey('mine_id', self.mine_id)
		self.ui.permeability_k_table.setRowCount(len(coal_lists))
		for i, coal in enumerate(coal_lists):
			self.ui.permeability_k_table.setItem(i, 0, QtGui.QTableWidgetItem(u'%d' % (i+1)))
			self.ui.permeability_k_table.setItem(i, 1, QtGui.QTableWidgetItem(u'%s' % coal.name.decode('utf-8')))
			self.ui.permeability_k_table.setItem(i, 2, QtGui.QTableWidgetItem(u'%.2f' % coal.permeability_k))
			item = QtGui.QTableWidgetItem()
			item.setFlags(QtCore.Qt.ItemIsEnabled)  # 不这么设置，用户点击时，图片被选的状态不美观
			if coal.permeability_k > 5:
				item.setIcon(QtGui.QIcon(':/images/yes.png'))
			else:
				item.setIcon(QtGui.QIcon(':/images/no.png'))
			self.ui.permeability_k_table.setItem(i, 3, item)

	def fillProtectLayerTable(self):
		# 清空
		self.ui.protect_layer_table.clearContents()
		# 查找矿井辖属的煤层
		coal_lists = SQLClientHelper.GetCoalListByForeignKey('mine_id', self.mine_id)
		self.ui.protect_layer_table.setRowCount(len(coal_lists))
		for i, coal in enumerate(coal_lists):
			self.ui.protect_layer_table.setItem(i, 0, QtGui.QTableWidgetItem(u'%d' % (i+1)))
			self.ui.protect_layer_table.setItem(i, 1, QtGui.QTableWidgetItem(u'%s' % coal.name.decode('utf-8')))
			self.ui.protect_layer_table.setItem(i, 2, QtGui.QTableWidgetItem(u'%.1f' % coal.dip_angle))
			item = QtGui.QTableWidgetItem()
			item.setFlags(QtCore.Qt.ItemIsEnabled)  # 不这么设置，用户点击时，图片被选的状态不美观
			# if coal.permeability_k > 5:
			if True:
				item.setIcon(QtGui.QIcon(':/images/yes.png'))
			else:
				item.setIcon(QtGui.QIcon(':/images/no.png'))
			self.ui.protect_layer_table.setItem(i, 3, item)

	def fillCoalPopulationTable(self):
		# 清空
		self.ui.coal_population_table.clearContents()
		# 查找矿井辖属的煤层
		coal_lists = SQLClientHelper.GetCoalListByForeignKey('mine_id', self.mine_id)
		self.ui.coal_population_table.setRowCount(len(coal_lists))
		for i, coal in enumerate(coal_lists):
			self.ui.coal_population_table.setItem(i, 0, QtGui.QTableWidgetItem(u'%d' % (i+1)))
			self.ui.coal_population_table.setItem(i, 1, QtGui.QTableWidgetItem(u'%s' % coal.name.decode('utf-8')))
			self.ui.coal_population_table.setItem(i, 2, QtGui.QTableWidgetItem(u'%.1f' % coal.layer_gap))
			self.ui.coal_population_table.setItem(i, 3, QtGui.QTableWidgetItem(u'%.1f' % coal.czh))
			self.ui.coal_population_table.setItem(i, 4, QtGui.QTableWidgetItem(u'%.1f' % coal.influence_factor))	

	# 获取煤层渗透率类型
	def getPermeabilityKType(self):
		# 所有煤层渗透率均大于等于5mD时，判定该煤层为中高渗条件；否则，判定该煤层为低渗条件
		# 查找矿井辖属的煤层
		coal_lists = SQLClientHelper.GetCoalListByForeignKey('mine_id', self.mine_id)
		n = sum([int(float(coal.permeability_k) > 5) for coal in coal_lists])
		return int(n == len(coal_lists))

	def runResultDlg(self, idx):
		if idx == 1:
			dlg = HighCoalDlg()
			dlg.exec_()
		elif idx == 2:
			dlg = HighCoalsDlg()
			dlg.exec_()
		elif idx == 3:
			dlg = LowNearlyCoalsDlg()
			dlg.exec_()
		elif idx == 4:
			dlg = LowFarCoalsDlg()
			dlg.exec_()
		elif idx == 5:
			dlg = LowCoalDlg()
			dlg.exec_()

	def onDecision(self):
		# 根据决策结果弹出相应的对话框
		idx = 3
		self.runResultDlg(idx)

	def onGraph(self):
		# 给cad发送命令绘制煤层赋存图
		CbmClientHelper.SendCommandToCAD("JL.DrawOccurrenceGraph %d %.1f" % (self.mine_id, 0.5), True)