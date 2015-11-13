#coding:utf-8

import sys
from uipy.ui_coal_param_dlg import *
from DecisionDlg import *

class CoalParamDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_coal_param_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cancel.clicked.connect(self.cancel)
        self.ui.next.clicked.connect(self.next)

    def cancel(self):
        self.accept()

    def save(self):
        #做保存操作
        pass

    def next(self):
        dlg = DecisionDlg()
        dlg.exec_()