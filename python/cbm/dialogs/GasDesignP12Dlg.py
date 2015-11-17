# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_gas_design_p1_2_dlg import *

class GasDesignP12Dlg(BaseDialog):
	def __init__(self,parent=None):
		super(GasDesignP12Dlg, self).__init__(parent)
		self.ui = Ui_gas_design_p1_2_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"顺层钻孔条带掩护巷道掘进抽采法")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.help.clicked.connect(self.onHelp)
		self.ui.plane_graph.clicked.connect(self.plane_graph)
		self.ui.head_graph.clicked.connect(self.head_graph)
		self.ui.dip_graph.clicked.connect(self.dip_graph)

	def onSave(self):
		#做保存操作
		self.accept()

	def onHelp(self):
		pass

	def plane_graph(self):
		pass

	def head_graph(self):
		pass

	def dip_graph(self):
		pass