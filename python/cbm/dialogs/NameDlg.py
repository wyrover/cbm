#coding:utf-8

import sys
from uipy.ui_name_dlg import *

class NameDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_name_dlg()  
        self.ui.setupUi(self)  
        self.name = None
        self.setFixedSize( self.width(),self.height())
        self.ui.ensure.clicked.connect(self.ensure) 

    def setTitle(self,title):
        self.setWindowTitle(title)

    def ensure(self):
        self.name = self.ui.name.text()
        self.accept()