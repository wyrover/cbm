# -*- coding: utf-8 -*-

from BaseDialog import *
from uipy.ui_gas_design_p3_2_dlg import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import UiHelper
import DataHelper
import doc

class GasDesignP32Dlg(BaseDialog):
	def __init__(self, coal_id=-1, design_id=-1, parent=None):
		super(GasDesignP32Dlg, self).__init__(parent)
		self.ui = Ui_gas_design_p3_2_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"顶板高位走向钻孔瓦斯抽采法")
		self.setFixedSize(self.width(),self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.plane_graph.clicked.connect(self.plane_graph)
		self.ui.head_graph.clicked.connect(self.head_graph)
		self.ui.dip_graph.clicked.connect(self.dip_graph)
		self.ui.create_report.clicked.connect(self.onCreatReport)
		self.ui.pore.horizontalHeader().resizeSection(0,75); # 设置第一列宽
		self.ui.pore.horizontalHeader().resizeSection(1,158); # 设置第二列宽
		self.ui.pore.horizontalHeader().resizeSection(2,166); # 设置第三列宽
		self.ui.pore.horizontalHeader().setResizeMode(QtGui.QHeaderView.Fixed) #列表不能移动
		self.ui.plus.clicked.connect(self.onPlusPore)
		self.ui.minus.clicked.connect(self.onMinusPore)
		self.ui.up.clicked.connect(self.onUpPore)
		self.ui.down.clicked.connect(self.onDownPore)
		# 待设计的煤层以及关联的技术
		self.coal_id = coal_id
		self.design_id = design_id
		# 初始化
		self.init()

	def init(self):
		# 填充数据
		self.fillDatas()

	def fillDatas(self):
		# 查找煤层
		coal = SQLClientHelper.GetCoalById(self.coal_id)
		if coal.id <= 0:return
		# 查找掘进面的抽采技术
		goaf_tech = SQLClientHelper.GetDesignGoafTechnologyById(self.design_id)
		if goaf_tech.id <= 0:return

		# 填充煤层数据
		self.ui.thick.setText(u'%.1f' % coal.thick)
		self.ui.dip_angle.setText(u'%.1f' % coal.dip_angle)

		# 填充抽采技术参数
		self.ui.l1.setText(u'%.1f' % goaf_tech.l1)
		self.ui.l2.setText(u'%.1f' % goaf_tech.l2)
		self.ui.w.setText(u'%.1f' % goaf_tech.w)
		self.ui.h.setText(u'%.1f' % goaf_tech.h)
		self.ui.dp.setText(u'%.1f' % goaf_tech.dp)
		self.ui.gp.setText(u'%.1f' % goaf_tech.gp)
		self.ui.pore_stubble.setText(u'%.1f' % goaf_tech.pore_stubble)
		self.ui.close_length.setText(u'%.1f' % goaf_tech.close_length)

		# 填空终孔参数列表
		self.ui.pore.clearContents()
		# 从数据库中提取钻孔参数数据
		pore_lists = SQLClientHelper.GetDesignGoafPoreListByForeignKey('design_goaf_technology_id', goaf_tech.id)
		if len(pore_lists) == 0:return

		# 保存到终孔列表
		n1 = len(pore_lists)
		self.ui.pore.setRowCount(n1)
		for i,pore in enumerate(pore_lists):
			# 添加到表格中
			self.ui.pore.setItem(i, 0, QtGui.QTableWidgetItem(pore.name.decode('utf-8')))
			self.ui.pore.setItem(i, 1, QtGui.QTableWidgetItem(u'%.1f' % pore.h_offset))
			self.ui.abc.setItem(i, 2, QtGui.QTableWidgetItem(u'%.1f' % pore.v_offset))

	def onSave(self):
		coal = SQLClientHelper.GetCoalById(self.coal_id)
		if coal.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:140)')
			return

		# 查找掘进面的抽采技术
		goaf_tech = SQLClientHelper.GetDesignGoafTechnologyById(self.design_id)
		if goaf_tech.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:141)')
			return
		
		# 保存煤层数据到数据库
		coal.thick, ok = self.ui.thick.text().toDouble()
		coal.dip_angle, ok = self.ui.dip_angle.text().toDouble()
		if not SQLClientHelper.UpdateCoal(coal):
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:142)')
			return

		# 保存抽采技术参数到数据库
		goaf_tech.l1, ok = self.ui.l1.text().toDouble()
		goaf_tech.l2, ok = self.ui.l2.text().toDouble()
		goaf_tech.w, ok = self.ui.w.text().toDouble()
		goaf_tech.h, ok = self.ui.h.text().toDouble()
		goaf_tech.dp, ok = self.ui.dp.text().toDouble()
		goaf_tech.gp, ok = self.ui.gp.text().toDouble()
		goaf_tech.pore_stubble, ok = self.ui.pore_stubble.text().toDouble()
		goaf_tech.pore_angle, ok = self.ui.pore_angle.text().toDouble()
		goaf_tech.close_length, ok = self.ui.close_length.text().toDouble()

		# 保存终孔参数
		
		# 保存到数据库
		if not SQLClientHelper.UpdateDesignGoafTechnology(goaf_tech):
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:143)')
		else:
			UiHelper.MessageBox(u'恭喜您,保存数据成功!')
		#做保存操作
		# self.accept()

	def plane_graph(self):
		coal = SQLClientHelper.GetCoalById(self.coal_id)
		if coal.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:144)')
			return
		# 查找掘进面的抽采技术
		goaf_tech = SQLClientHelper.GetDesignGoafTechnologyById(self.design_id)
		if goaf_tech.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:145)')
			return
		# 向cad发送命令请求绘图
		ret = CbmClientHelper.SendCommandToCAD("JL.DrawPlaneGraph32 %d %d" % (coal.id, goaf_tech.id), True)
		if not ret:
			UiHelper.MessageBox(u'启动AutoCAD失败')

	def head_graph(self):
		coal = SQLClientHelper.GetCoalById(self.coal_id)
		if coal.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:144)')
			return
		# 查找掘进面的抽采技术
		goaf_tech = SQLClientHelper.GetDesignGoafTechnologyById(self.design_id)
		if goaf_tech.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:145)')
			return
		# 向cad发送命令请求绘图
		ret = CbmClientHelper.SendCommandToCAD("JL.DrawHeadGraph32 %d %d" % (coal.id, goaf_tech.id), True)
		if not ret:
			UiHelper.MessageBox(u'启动AutoCAD失败')

	def dip_graph(self):
		coal = SQLClientHelper.GetCoalById(self.coal_id)
		if coal.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:144)')
			return
		# 查找掘进面的抽采技术
		goaf_tech = SQLClientHelper.GetDesignGoafTechnologyById(self.design_id)
		if goaf_tech.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:145)')
			return
		# 向cad发送命令请求绘图
		ret = CbmClientHelper.SendCommandToCAD("JL.DrawDipGraph32 %d %d" % (coal.id, goaf_tech.id), True)
		if not ret:
			UiHelper.MessageBox(u'启动AutoCAD失败')

	def onCreatReport(self):
		coal = SQLClientHelper.GetCoalById(self.coal_id)
		if coal.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:144)')
			return
		# 查找掘进面的抽采技术
		goaf_tech = SQLClientHelper.GetDesignGoafTechnologyById(self.design_id)
		if goaf_tech.id <= 0:
			UiHelper.MessageBox(u'sorry,出了点问题,请联系技术人员(错误码:145)')
			return

		# 向cad发送命令请求生成钻孔数据
		ret = CbmClientHelper.SendCommandToCAD("JL.GeneratePore32 %d %d" % (coal.id, goaf_tech.id), True)
		if ret:
			# 显示钻孔报表
			DataHelper.show_report32(coal, goaf_tech)
		else:
			UiHelper.MessageBox(u'启动AutoCAD失败!!!')

		# json文件路径(使用绝对路径,避免出错!!!)
		# json_file = os.path.abspath('.\\help\\json\\reportP21.json')
		# 生成json文件
		# self.make_json(coal.id, tgoaf_tech.id, json_file)
		# 生成word报单
		# doc.CreatReport(json_file)

	def onPlusPore(self):
		print 'call onPlusPore()...'

	def onMinusPore(self):
		print 'call onMinusPore()...'

	def onUpPore(self):
		print 'call onUpPore()...'

	def onDownPore(self):
		print 'call onDownPore()...'