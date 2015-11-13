#coding:utf-8

import sys
from uipy.ui_ws_gas_flow_predict_dlg import *
from WsGasFlowPredictWorkDlg import *
from WsGasFlowPredictAdjDlg import *

class WsGasFlowPredictDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_ws_gas_flow_predict_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.qr1_cacl.clicked.connect(self.qr1_cacl)
        self.ui.qr2_cacl.clicked.connect(self.qr2_cacl)
        self.ui.qr_cacl.clicked.connect(self.qr_cacl)

    def save(self):
    	#做保存操作
        self.accept()

    def qr1_cacl(self):
    	dlg = WsGasFlowPredictWorkDlg()
        dlg.exec_()

    def qr2_cacl(self):
    	dlg = WsGasFlowPredictAdjDlg()
        dlg.exec_()

    def qr_cacl(self):
        pass