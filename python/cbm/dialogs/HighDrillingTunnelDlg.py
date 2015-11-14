#coding:utf-8

import sys
from uipy.ui_high_drilling_tunnel_dlg import *

class HighDrillingTunnelDlg(QtGui.QDialog):  
    def __init__(self, mine_id=-1, parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_high_drilling_tunnel_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.cacl.clicked.connect(self.cacl)
        # 待设计的矿井
        self.mine_id = mine_id
        
    def save(self):
    	#做保存操作
        self.accept()

    def cacl(self):
        pass