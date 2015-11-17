# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_pore_flow_b_dlg import *

class PoreFlowbDlg(BaseDialog):
	def __init__(self, pore_flow, parent=None):
		super(PoreFlowbDlg, self).__init__(parent)
		self.ui = Ui_pore_flow_b_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"瓦斯浓度校正系数计算")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)
		# 外部传入的对象
		self.pore_flow = pore_flow
		# 初始化
		self.init()

	def init(self):
		pass

	def onSave(self):
		#做保存操作
		self.accept()
