#coding:utf-8

import sys
from uipy.ui_gas_design_p2_1_dlg import *

class GasDesignP21Dlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_gas_design_p2_1_dlg()  
        self.ui.setupUi(self)  
        self.setFixedSize( self.width(),self.height())
        self.ui.save.clicked.connect(self.save)
        self.ui.help.clicked.connect(self.help)
        self.ui.plane_graph.clicked.connect(self.plane_graph)
        self.ui.head_graph.clicked.connect(self.head_graph)
        self.ui.dip_graph.clicked.connect(self.dip_graph)

    def save(self):
    	#做保存操作
        self.accept()

    def help(self):
        pass

    def plane_graph(self):
    	pass

    def head_graph(self):
        pass

    def dip_graph(self):
        pass