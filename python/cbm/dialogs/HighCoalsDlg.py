# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_high_coals_dlg import *

class HighCoalsDlg(BaseDialog):
	def __init__(self, parent=None):
		super(HighCoalsDlg, self).__init__(parent)
		self.ui = Ui_high_coals_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.ui.tecl_table.setColumnWidth(2,88)
		self.ui.tecl_table.setColumnWidth(1,310)
		self.ui.tecl_table.setColumnWidth(0,100)
		self.ui.tecl_table.setSpan(2,0,2,1)
		self.ui.tecl_table.setSelectionBehavior(Qt.QAbstractItemView.SelectRows)
		self.ui.tecl_table.setEditTriggers(Qt.QAbstractItemView.NoEditTriggers)
		self.setTitle(u"中高渗煤层群条件井下规模化抽采技术模式")
		self.setFixedSize(self.width(), self.height())