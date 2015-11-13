#coding:utf-8

import sys
from uipy.ui_drilling_radius_dlg import *

class DrillingRadiusDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_drilling_radius_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cacl.clicked.connect(self.cacl)

    def save(self):
    	#做保存操作
        self.accept()

    def cacl(self):
        pass