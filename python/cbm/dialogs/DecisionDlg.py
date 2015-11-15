#coding:utf-8

import sys
from uipy.ui_decision_dlg import *

class DecisionDlg(QtGui.QDialog):  
    def __init__(self,parent=None):
        super(DecisionDlg, self).__init__(parent)
        self.ui = Ui_decision_dlg()
        self.ui.setupUi(self)
        self.setFixedSize( self.width(),self.height())