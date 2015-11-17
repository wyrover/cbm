# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_drilling_radius_dlg import *

class DrillingRadiusDlg(BaseDialog):
	def __init__(self, mine_id=-1, parent=None):
		super(DrillingRadiusDlg, self).__init__(parent)
		self.ui = Ui_drilling_radius_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"瓦斯抽采半径计算")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.cacl.clicked.connect(self.onCacl)
		# 待设计的矿井
		self.mine_id = mine_id
		
	def onSave(self):
		#做保存操作
		self.accept()

	def onCacl(self):
		pass