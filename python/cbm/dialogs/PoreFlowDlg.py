#coding:utf-8

from BaseDialog import *
from uipy.ui_pore_flow_dlg import *

from PoreFlowKDlg import *
from PoreFlowbDlg import *
from PoreFlowDeltaPDlg import *
from PoreFlowDeltaTDlg import *

class PoreFlowDlg(BaseDialog):
	def __init__(self, mine_id=-1, parent=None):
		super(PoreFlowDlg, self).__init__(parent)
		self.ui = Ui_pore_flow_dlg()
		self.ui.setupUi(self)
		self.initUi(self.ui) # 美化ui
		self.setTitle(u"孔板流量计算")
		self.setFixedSize(self.width(), self.height())
		self.ui.save.clicked.connect(self.onSave)
		self.ui.cacl.clicked.connect(self.onCacl)
		self.ui.K_cacl.clicked.connect(self.onKCacl)
		self.ui.b_cacl.clicked.connect(self.onBCacl)
		self.ui.delta_p_cacl.clicked.connect(self.onDeltaPCacl)
		self.ui.delta_t_cacl.clicked.connect(self.onDeltaTCacl)
		# 待设计的矿井
		self.mine_id = mine_id
		
	def onSave(self):
		#做保存操作
		self.accept()

	def onCacl(self):
		pass

	def onKCacl(self):
		dlg = PoreFlowKDlg()
		dlg.exec_()

	def onBCacl(self):
		dlg = PoreFlowbDlg()
		dlg.exec_()

	def onDeltaPCacl(self):
		dlg = PoreFlowDeltaPDlg()
		dlg.exec_()

	def onDeltaTCacl(self):
		dlg = PoreFlowDeltaTDlg()
		dlg.exec_()