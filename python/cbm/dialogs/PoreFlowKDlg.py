#coding:utf-8

from BaseDialog import *
from uipy.ui_pore_flow_K_dlg import *

class PoreFlowKDlg(BaseDialog):
	def __init__(self,parent=None):
		super(PoreFlowKDlg, self).__init__(parent)
		self.ui = Ui_pore_flow_K_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"实际孔板流量特性系数计算")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)

	def onSave(self):
		#做保存操作
		self.accept()
