# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_pore_flow_delta_T_dlg import *

class PoreFlowDeltaTDlg(BaseDialog):
	def __init__(self,parent=None):
		super(PoreFlowDeltaTDlg, self).__init__(parent)
		self.ui = Ui_pore_flow_delta_T_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"温度校正系数计算")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)

	def onSave(self):
		#做保存操作
		self.accept()
