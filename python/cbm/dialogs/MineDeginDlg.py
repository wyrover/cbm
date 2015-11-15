#coding:utf-8

from uipy.ui_mine_degin_dlg import *
from NameDlg import *
from CoalDeginDlg import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import UiHelper
import DataHelper

class MineDeginDlg(QtGui.QDialog):  
	def __init__(self, mine_id=-1, parent=None):
		super(MineDeginDlg, self).__init__(parent)
		self.ui = Ui_mine_degin_dlg()
		self.ui.setupUi(self)
		self.setFixedSize( self.width(),self.height())
		self.ui.add_coal.clicked.connect(self.onAddCoal)
		self.ui.add_work_area.clicked.connect(self.onAddWorkArea)
		self.ui.add_work_surf.clicked.connect(self.onAddWorkSurf)
		self.ui.add_drilling_surf.clicked.connect(self.onAddDrillingSurf)
		self.ui.more_coal.clicked.connect(self.onCoalDetail)
		# 煤炭基地切换 事件处理
		self.connect(self.ui.base, QtCore.SIGNAL('currentIndexChanged(int)'), self.onMineBaseChanged)
		# 待设计的矿井
		self.mine_id = mine_id
		# 初始化
		self.init()

	def init(self):
		# 填充煤炭基地列表
		self.fillBaseCombox()
		# 填充矿井数据
		self.fillMineDatas()
		# 填充煤层列表
		self.fillCoalCombox()

	def fillBaseCombox(self):
		# 查询所有的煤炭基地
		mine_base_list = SQLClientHelper.GetMineBaseList()
		if len(mine_base_list) == 0:return
		# 填充煤炭基地列表
		for mine_base in mine_base_list:
			self.ui.base.addItem(mine_base.name.decode('utf-8'), mine_base.id)
		# 默认选中第1个
		self.ui.base.setCurrentIndex(0)

	def fillMineDatas(self):
		# 数据库中查找id对应的矿井
		mine = SQLClientHelper.GetMineById(self.mine_id)
		if mine.id < 0:return

		# 填充数据
		name = mine.name.decode('utf-8')
		capacity = mine.capacity
		province = mine.province.decode('utf-8')
		city = mine.city.decode('utf-8')
		topo_geo = mine.topo_geo
		hydr_geo = mine.hydr_geo
		ground_condition = mine.ground_condition
		# 查找矿区
		mine_region = SQLClientHelper.GetMineRegionById(mine.mine_region_id)
		# combobox里的text好像不需要unicode,貌似不需要"编码"(encode)
		region_name = 'null' if mine_region.id < 0 else mine_region.name
		# 根据矿区名称反查煤炭基地
		base_name = CbmClientHelper.GetBaseByRegion(region_name)

		# 填充矿井数据		
		self.ui.name.setText(name)
		self.ui.capacity.setText(u'%.2f' % capacity)
		self.ui.province.setText(province)
		self.ui.city.setText(city)
		self.ui.topo_geo.setCurrentIndex(topo_geo-1)
		self.ui.hydr_geo.setCurrentIndex(hydr_geo-1)
		self.ui.ground_cond.setChecked(ground_condition != 0)
		self.ui.base.setCurrentIndex(self.ui.base.findText(base_name))
		self.ui.region.setCurrentIndex(self.ui.region.findText(region_name))

	def fillCoalCombox(self):
		# 清空煤层下拉列表
		self.ui.coal.clear()

		# 查找矿井辖属的煤层
		coal_lists = SQLClientHelper.GetCoalListByForeignKey('mine_id', self.mine_id)
		for coal in coal_lists:
			# 添加煤层名称到列表,并附加一个id数据(item data)
			self.ui.coal.addItem(coal.name, coal.id)
		self.ui.coal.setCurrentIndex(0)

	def onMineBaseChanged(self, index):
		# 清空矿区列表
		self.ui.region.clear()
		# 查询煤炭基地对应的矿区
		mine_base_id, ok = self.ui.base.itemData(index).toInt()
		if not ok:return

		# 查询煤炭基地辖制的矿区
		mine_region_list = SQLClientHelper.GetMineRegionListByField1('mine_base_id', str(mine_base_id))
		if len(mine_region_list) == 0:return
		# 填充矿区列表
		for mine_region in mine_region_list:
			# 从数据库中提取的字符串是utf-8编码的
			self.ui.region.addItem(mine_region.name.decode('utf-8'), mine_region.id)
		# 默认选中第1个
		self.ui.region.setCurrentIndex(0)

	def onAddCoal(self):
		name = UiHelper.GetNameFromDlg(u"新增煤层")
		if name == u'null':
			UiHelper.MessageBox(u"请输入有效的名称！")
		else:
			UiHelper.AddItemToCombobox(self.ui.coal, name)

	def onAddWorkSurf(self):
		AddNewName(self.ui.work_surf,u"新增回采工作面")
		# name = self.showNameDlg(u"新增回采工作面")
		# self.addNewName(self.ui.work_surf,name)

	def onAddWorkArea(self):
		AddNewName(self.ui.work_area,u"新增矿井采区")
		# name = self.showNameDlg(u"新增矿井采区")
		# self.addNewName(self.ui.work_area,name)

	def onAddDrillingSurf(self):
		AddNewName(self.ui.drilling_surf,u"新增掘进工作面")
		# name = self.showNameDlg(u"新增掘进工作面")
		# self.addNewName(self.ui.drilling_surf,name)

	def onCoalDetail(self):
		dlg = CoalDeginDlg()
		dlg.exec_()
