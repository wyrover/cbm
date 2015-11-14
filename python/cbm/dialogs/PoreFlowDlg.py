#coding:utf-8

import sys
from uipy.ui_pore_flow_dlg import *
from PoreFlowKDlg import *
from PoreFlowbDlg import *
from PoreFlowDeltaPDlg import *
from PoreFlowDeltaTDlg import *

class PoreFlowDlg(QtGui.QDialog):  
    def __init__(self, mine_id=-1, parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_pore_flow_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cacl.clicked.connect(self.cacl)
        self.ui.K_cacl.clicked.connect(self.K_cacl)
        self.ui.b_cacl.clicked.connect(self.b_cacl)
        self.ui.delta_p_cacl.clicked.connect(self.delta_p_cacl)
        self.ui.delta_T_cacl.clicked.connect(self.delta_T_cacl)
        # 待设计的矿井
        self.mine_id = mine_id
        
    def save(self):
    	#做保存操作
        self.accept()

    def cacl(self):
        pass

    def K_cacl(self):
        dlg = PoreFlowKDlg()
        dlg.exec_()

    def b_cacl(self):
        dlg = PoreFlowbDlg()
        dlg.exec_()

    def delta_p_cacl(self):
        dlg = PoreFlowDeltaPDlg()
        dlg.exec_()

    def delta_T_cacl(self):
        dlg = PoreFlowDeltaTDlg()
        dlg.exec_()