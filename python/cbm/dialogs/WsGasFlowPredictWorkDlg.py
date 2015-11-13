#coding:utf-8

import sys
from uipy.ui_ws_gas_flow_predict_work_dlg import *

class WsGasFlowPredictWorkDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_ws_gas_flow_predict_work_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.k3_cacl.clicked.connect(self.k3_cacl)
        self.ui.kf_cacl.clicked.connect(self.kf_cacl)

    def save(self):
    	#做保存操作
        self.accept()

    def k3_cacl(self):
    	pass

    def kf_cacl(self):
    	pass