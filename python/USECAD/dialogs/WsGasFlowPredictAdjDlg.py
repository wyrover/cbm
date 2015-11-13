#coding:utf-8

import sys
from uipy.ui_ws_gas_flow_predict_adj_dlg import *
from NameDlg import *

class WsGasFlowPredictAdjDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_ws_gas_flow_predict_adj_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.add_adj_layer.clicked.connect(self.add_adj_layer)
        self.ui.del_adj_layer.clicked.connect(self.del_adj_layer)
        self.ui.eta_cacl.clicked.connect(self.eta_cacl)

    def save(self):
    	#做保存操作
        self.accept()

    def add_adj_layer(self):
        AddNewName(self.ui.adj_layer,u"新增邻近层")

    def del_adj_layer(self):
    	pass

    def eta_cacl(self):
        pass