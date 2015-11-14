#coding:utf-8

import sys
from uipy.ui_sample_manage import *
from TechModeDlg import *
from TechnologyDlg import *

class SampleManageDlg(QtGui.QDialog):
    def __init__(self, mine_id=-1, parent=None):
        QtGui.QDialog.__init__(self,parent)
        self.ui = Ui_sample_manage()
        self.ui.setupUi(self)
        self.setFixedSize( self.width(),self.height())      
    	self.ui.tech_mode.clicked.connect(self.onTechModeClick)
    	self.ui.technology.clicked.connect(self.onTechnologyClick)
        # 待设计的矿井
        self.mine_id = mine_id

    def onTechModeClick(self):
    	dlg = TechModeDlg()
        dlg.exec_()

    def onTechnologyClick(self):
    	dlg = TechnologyDlg()
        dlg.exec_()
