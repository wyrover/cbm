#coding:utf-8

import sys
from uipy.ui_sample_manage import *
from TechModeDlg import *
from TechnologyDlg import *

class SampleManageDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_sample_manage()  
        self.ui.setupUi(self)
        self.setFixedSize( self.width(),self.height())        
    	self.ui.tech_mode.clicked.connect(self.techMode) 
    	self.ui.technology.clicked.connect(self.technology) 

    def techMode(self):
    	dlg = TechModeDlg()
        dlg.exec_() 

    def technology(self):
    	dlg = TechnologyDlg()
        dlg.exec_() 
