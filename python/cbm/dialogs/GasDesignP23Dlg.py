# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_gas_design_p2_3_dlg import *

class GasDesignP23Dlg(BaseDialog):
	def __init__(self,parent=None):
		super(GasDesignP23Dlg, self).__init__(parent)
		self.ui = Ui_gas_design_p2_3_dlg()
		self.ui.setupUi(self)
		self.ui.initUi(self) # 美化ui
		self.setTitle(u"顺层平行钻孔抽采工作面瓦斯")
		self.setFixedSize(self.width(),self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.plane_graph.clicked.connect(self.plane_graph)
		self.ui.head_graph.clicked.connect(self.head_graph)
		self.ui.dip_graph.clicked.connect(self.dip_graph)

	def onSave(self):
		#做保存操作
		self.accept()

	def plane_graph(self):
		pass

	def head_graph(self):
		pass

	def dip_graph(self):
		pass