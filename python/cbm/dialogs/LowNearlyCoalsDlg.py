# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_low_nearly_coals_dlg import *

class LowNearlyCoalsDlg(BaseDialog):
	def __init__(self, parent=None):
		super(LowNearlyCoalsDlg, self).__init__(parent)
		self.ui = Ui_low_nearly_coals_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		# self.ui.tecl_table.resizeColumnsToContents() 
		# self.ui.tecl_table.resizeRowsToContents()
		self.ui.tecl_table.setColumnWidth(2,86)
		self.ui.tecl_table.setColumnWidth(1,310)
		self.ui.tecl_table.setColumnWidth(0,100)
		self.ui.tecl_table.setSpan(2,0,2,1)
		self.ui.tecl_table.setSelectionBehavior(Qt.QAbstractItemView.SelectRows); 
		# self.ui.tecl_table.setRowHeight(3,60)
		self.setTitle(u"低渗近距离煤层群上保护层开采条件井下规模化抽采技术模式")
		self.setFixedSize(self.width(), self.height())