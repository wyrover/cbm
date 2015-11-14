#coding:utf-8

import sys
from uipy.ui_mine_base_param_dlg import *
from CoalParamDlg import *

class MineBaseParamDlg(QtGui.QDialog):  
    def __init__(self, mine_id=-1, parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_mine_base_param_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cancel.clicked.connect(self.cancel)
        self.ui.next.clicked.connect(self.next)
        # 待设计的矿井
        self.mine_id = mine_id
        
    def cancel(self):
        self.accept()

    def save(self):
        #做保存操作
        pass

    def next(self):
        dlg = CoalParamDlg()
        dlg.exec_()