#coding:utf-8

import sys
from uipy.ui_mine_gas_flow_predict_dlg import *
from MineGasFlowPredictDesignDlg import *

class MineGasFlowPredictDlg(QtGui.QDialog):
    def __init__(self, mine_id=-1, parent=None):
        super(MineGasFlowPredictDlg, self).__init__(parent)  
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
        # 待设计的矿井
        self.mine_id = mine_id
        
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