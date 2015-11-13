#coding:utf-8

import sys
from uipy.ui_technology_dlg import *

class TechnologyDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_technologyDlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())        
    	#self.ui.reg.clicked.connect(self.reg) 

