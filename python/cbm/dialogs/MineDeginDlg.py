#coding:utf-8

from uipy.ui_mine_degin_dlg import *
from NameDlg import *
from CoalDeginDlg import *

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
		# 待设计的矿井
		self.mine_id = mine_id

	# def showNameDlg(self,title):
	# 	dlg = NameDlg()
	# 	dlg.setTitle(title)
	# 	name = ''
	# 	if dlg.exec_():
	# 		name = dlg.name
	# 	return name

	# def addNewName(self,combo,name):
	# 	if name == '':
	# 		QtGui.QMessageBox.information(self, u"提示",u"请输入有效的名称！")
	# 	else:
	# 		pos = combo.findText(name)
	# 		if pos != -1:
	# 			QtGui.QMessageBox.information(self, u"提示",u"所输入的名称已存在！")
	# 		else:
	# 			combo.addItem(name)
	# 			pos = combo.count()-1
	# 		combo.setCurrentIndex(pos)

	def onAddCoal(self):
		AddNewName(self.ui.coal,u"新增煤层")
		# name = self.showNameDlg(u"新增煤层")
		# self.addNewName(self.ui.coal,name)

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
