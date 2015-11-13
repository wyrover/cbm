#coding:utf-8

import sys
from uipy.ui_tech_mode_dlg import *

class TechModeDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_tech_mode_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())        
    	#self.ui.reg.clicked.connect(self.reg) 

