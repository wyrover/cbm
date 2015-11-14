#coding:utf-8

from uipy.ui_coal_design_dlg import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import UiHelper

class CoalDeginDlg(QtGui.QDialog):  
    def __init__(self, mine_id, parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_coal_design_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize(self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cancel.clicked.connect(self.cancel)
        self.mine_id = mine_id # 待设计矿井id

    def cancel(self):
        self.accept()

    def save(self):
        #做保存操作
        self.accept()