#coding:utf-8

import sys
from uipy.ui_mine_gas_flow_predict_dlg import *
from MineGasFlowPredictDesignDlg import *

class MineGasFlowPredictDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_mine_gas_flow_predict_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.k1_help.clicked.connect(self.k1_help)
        self.ui.k2_help.clicked.connect(self.k2_help)
        self.ui.design_work_area.clicked.connect(self.design_work_area)        
        self.ui.save.clicked.connect(self.save)
        self.ui.assign.clicked.connect(self.assign)
        self.ui.work_area_cacl.clicked.connect(self.work_area_cacl)
        self.ui.cacl.clicked.connect(self.cacl)

    def save(self):
        #做保存操作
        self.accept()

    def k1_help(self):
        pass

    def k2_help(self):
        pass

    def design_work_area(self):
        dlg = MineGasFlowPredictDesignDlg()
        dlg.exec_()

    def assign(self):
        pass

    def work_area_cacl(self):
        pass

    def cacl(self):
        pass