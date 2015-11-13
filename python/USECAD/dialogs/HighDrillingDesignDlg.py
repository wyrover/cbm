#coding:utf-8

import sys
from uipy.ui_high_drilling_design_dlg import *
from HighDrillingSiteDlg import *
from HighDrillingPoreDlg import *

class HighDrillingDesignDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_high_drilling_design_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.drill_site.clicked.connect(self.drill_site)
        self.ui.drill_pore.clicked.connect(self.drill_pore)

    def save(self):
    	#做保存操作
        self.accept()

    def drill_site(self):
        dlg = HighDrillingSiteDlg()
        dlg.exec_()

    def drill_pore(self):
        dlg = HighDrillingPoreDlg()
        dlg.exec_()