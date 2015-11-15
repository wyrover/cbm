#coding:utf-8

import sys
from uipy.ui_mine_gas_reserves_predict_dlg1 import *

class MineGasReservesPredictDlg1(QtGui.QDialog):
    def __init__(self,parent=None):
        super(MineGasReservesPredictDlg1, self).__init__(parent)
        self.ui = Ui_mine_gas_reserves_predict_dlg1()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.w1_cacl.clicked.connect(self.w1_cacl)
        self.ui.w2_cacl.clicked.connect(self.w2_cacl)
        self.ui.cacl.clicked.connect(self.cacl)        
        self.ui.ok.clicked.connect(self.ok)

    def ok(self):
        self.accept()

    def w1_cacl(self):
        pass

    def w2_cacl(self):
        pass

    def cacl(self):
        pass