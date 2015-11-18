# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_gas_drilling_analyse_dlg import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import DataHelper
import UiHelper

from math import sqrt, exp, pow, sin, cos, tan, radians, pi, asin

class GasDrillingAnalyseDlg(BaseDialog):
	def __init__(self, mine_id=-1, parent=None):
		super(GasDrillingAnalyseDlg, self).__init__(parent)
		self.ui = Ui_gas_drilling_analyse_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"瓦斯抽采半径计算")
		self.setFixedSize(self.width(), self.height())
		# self.ui.save.clicked.connect(self.onSave)
		# self.ui.cacl.clicked.connect(self.onCacl)
		# self.connect(self.ui.coal, QtCore.SIGNAL('currentIndexChanged(int)'), self.onCoalChanged)
		# 待设计的矿井
		self.mine_id = mine_id
		# 初始化
		self.init()
		
	def init(self):
		# 填充煤层列表
		# self.fillCoalCombox()
		pass
