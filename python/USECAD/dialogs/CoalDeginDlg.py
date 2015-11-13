#coding:utf-8

import sys
from uipy.ui_coal_design_dlg import *

class CoalDeginDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_coal_design_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cancel.clicked.connect(self.cancel)

    def cancel(self):
        self.accept()

    def save(self):
        #做保存操作
        self.accept()