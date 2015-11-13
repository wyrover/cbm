#coding:utf-8

import sys
from uipy.ui_pore_flow_delta_p_dlg import *

class PoreFlowDeltaPDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_pore_flow_delta_p_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)

    def save(self):
    	#做保存操作
        self.accept()
