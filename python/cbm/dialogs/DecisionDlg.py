# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_decision_dlg import *

class DecisionDlg(BaseDialog):
	def __init__(self,parent=None):
		super(DecisionDlg, self).__init__(parent)
		self.ui = Ui_decision_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"依据示范矿区智能决策")
		self.setFixedSize(self.width(), self.height())