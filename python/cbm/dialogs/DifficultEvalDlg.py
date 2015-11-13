#coding:utf-8

import sys
from uipy.ui_difficult_eval_dlg import *

class DifficultEvalDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_difficult_eval_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.eval.clicked.connect(self.eval)
        self.ui.cancel.clicked.connect(self.cancel)

    def cancel(self):
        self.accept()

    def eval(self):
        #做保存操作
        pass