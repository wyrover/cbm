# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_pore_flow_delta_p_dlg import *

class PoreFlowDeltaPDlg(BaseDialog):
	def __init__(self,parent=None):
		super(PoreFlowDeltaPDlg, self).__init__(parent)
		self.ui = Ui_pore_flow_delta_p_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"气压校正系数计算")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)

	def onSave(self):
		#做保存操作
		self.accept()
