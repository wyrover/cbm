# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_pore_size_dlg import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import DataHelper
import UiHelper

from math import sqrt, pow, sin, cos, tan, radians

class PoreSizeDlg(BaseDialog):
	def __init__(self, mine_id=-1, parent=None):
		super(PoreSizeDlg, self).__init__(parent)
		self.ui = Ui_pore_size_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"抽采管径大小辅助计算")
		self.setFixedSize(self.width(),self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.cacl.clicked.connect(self.onCacl)
		self.ui.hint.clicked.connect(self.onHint)
		self.ui.hint2.clicked.connect(self.onHint2)
		# 待设计的矿井
		self.mine_id = mine_id
		# 初始化
		self.init()

	def init(self):
		# 获取抽采半径对象
		pore_size = self.getPoreSize()
		if pore_size.id  <= 0:return

		# 读取数据到界面
		self.ui.q.setText(u'%.1f' % pore_size.q)
		self.ui.v.setText(u'%.1f' % pore_size.v)
		self.ui.p.setText(u'%.1f' % pore_size.p)
		self.ui.theta.setText(u'%.1f' % pore_size.theta)
		self.ui.d.setText(u'%.1f' % pore_size.d)
		self.ui.sigma.setText(u'%.1f' % pore_size.sigma)

	def getPoreSize(self):
		# 查找所有的抽采管径对象
		pore_size_lists = SQLClientHelper.GetPoreSizeList()
		if len(pore_size_lists) == 0:
			pore_size = PoreSize()
			pore_size.id = -1
			return pore_size
		else:
			# 目前只使用第1个数据
			return pore_size_lists[0]

	def onSave(self):
		# 获取抽采半径对象
		pore_size = self.getPoreSize()
		if pore_size.id  <= 0:return

		# 读取数据到界面
		self.ui.q.setText(u'%.1f' % pore_size.q)
		self.ui.v.setText(u'%.1f' % pore_size.v)
		self.ui.p.setText(u'%.1f' % pore_size.p)
		self.ui.theta.setText(u'%.1f' % pore_size.theta)
		self.ui.d.setText(u'%.1f' % pore_size.d)
		self.ui.sigma.setText(u'%.1f' % pore_size.sigma)
		
		# 关闭对话框并返回1
		# self.accept()

	def onCacl(self):
		pass

	def onHint(self):
		pass

	def onHint2(self):
		pass