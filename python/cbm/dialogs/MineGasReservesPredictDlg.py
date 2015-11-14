#coding:utf-8

import sys
from uipy.ui_mine_gas_reserves_predict_dlg import *
from CoalParamDlg import *
from MineGasReservesPredictDlg1 import *
from MineGasReservesPredictDlg2 import *

class MineGasReservesPredictDlg(QtGui.QDialog):  
    def __init__(self, mine_id=-1, parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_mine_gas_reserves_predict_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.gas_cacl.clicked.connect(self.gas_cacl)
        self.ui.pump_wc_cacl.clicked.connect(self.pump_wc_cacl)
        self.ui.ok.clicked.connect(self.ok)
        # 待设计的矿井
        self.mine_id = mine_id
        
    def ok(self):
        self.accept()

    def gas_cacl(self):
        dlg = MineGasReservesPredictDlg1()
        dlg.exec_()

    def pump_wc_cacl(self):
        dlg = MineGasReservesPredictDlg2()
        dlg.exec_()
