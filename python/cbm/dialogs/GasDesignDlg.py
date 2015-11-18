# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_gas_design_dlg import *

from GasDesignP11Dlg import *
from GasDesignP12Dlg import *
from GasDesignP21Dlg import *
from GasDesignP23Dlg import *

import UiHelper
import DataHelper

class GasDesignDlg(BaseDialog):
	def __init__(self, mine_id=-1, parent=None):
		super(GasDesignDlg, self).__init__(parent)
		self.ui = Ui_gas_design_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui)
		self.setTitle(u"煤层气抽采技术辅助设计")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.go.clicked.connect(self.onGo)
		# 待设计的矿井
		self.mine_id = mine_id
		# 该变量从外部读进来(设计的不是太好,滥用了全局变量了)
		self.mine_region = DataHelper.GAS_DESIGN_TYPE
		# 初始化
		self.init()

	def init(self):
		# 初始化列表框
		self.initListItem()

	def initListItem(self):
		item = []
		if self.mine_region == 1:
			item = [u'底板岩巷密集穿层钻孔抽采煤巷条带瓦斯',u'顺层钻孔条带掩护巷道掘进抽采法']
		elif self.mine_region == 2:
			item = [u'底板岩巷大面积穿层钻孔抽采工作面瓦斯',u'顺层平行钻孔抽采工作面瓦斯']
		listItem = []
		for lst in item:
			listItem.append(QtGui.QListWidgetItem(lst))
		for i in range(len(listItem)):
			self.ui.technology.insertItem(i+1,listItem[i])

	def onSave(self):
		#做保存操作
		self.accept()

	def onGo(self):
		currentRow = self.ui.technology.currentRow()
		if currentRow < 0:
			UiHelper.MessageBox(u"请选择相应的抽采技术！")
			return
		func = ''
		if self.mine_region == 1:
			func = 'twsDesign%d' % currentRow
		elif self.mine_region == 2:
			func = 'wsDesign%d' % currentRow
		getattr(self,func)()

	def onTwsDesign0(self):
		dlg = GasDesignP11Dlg()
		dlg.exec_()

	def onTwsDesign1(self):
		dlg = GasDesignP12Dlg()
		dlg.exec_()

	def onWsDesign0(self):
		dlg = GasDesignP21Dlg()
		dlg.exec_()

	def onWsDesign1(self):
		dlg = GasDesignP23Dlg()
		dlg.exec_()
