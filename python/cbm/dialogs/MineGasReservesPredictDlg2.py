#coding:utf-8

import sys
from uipy.ui_mine_gas_reserves_predict_dlg2 import *

class MineGasReservesPredictDlg2(QtGui.QDialog):  
    def __init__(self,parent=None):
        super(MineGasReservesPredictDlg2, self).__init__(parent)
        self.ui = Ui_mine_gas_reserves_predict_dlg2()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.cacl.clicked.connect(self.cacl)        
        self.ui.ok.clicked.connect(self.ok)

    def ok(self):
        self.accept()

    def cacl(self):
        pass