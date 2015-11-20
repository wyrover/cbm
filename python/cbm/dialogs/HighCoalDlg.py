# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_high_coal_dlg import *

class HighCoalDlg(BaseDialog):
	def __init__(self, parent=None):
		super(HighCoalDlg, self).__init__(parent)
		self.ui = Ui_high_coal_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.ui.tecl_table.setColumnWidth(2,88)
		self.ui.tecl_table.setColumnWidth(1,310)
		self.ui.tecl_table.setColumnWidth(0,100)
		self.ui.tecl_table.setSpan(0,0,3,1)
		self.ui.tecl_table.setSpan(3,0,2,1)
		self.ui.tecl_table.setSpan(5,0,2,1)
		self.ui.tecl_table.setSelectionBehavior(Qt.QAbstractItemView.SelectRows); 
		self.setTitle(u"中高渗单一煤层条件井下规模化抽采技术模式")
		self.setFixedSize(self.width(), self.height())