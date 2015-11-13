#coding:utf-8

import sys
from uipy.ui_mine_gas_flow_predict_design_dlg import *

class MineGasFlowPredictDesignDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_mine_gas_flow_predict_design_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)

    def save(self):
    	#做保存操作
        self.accept()
