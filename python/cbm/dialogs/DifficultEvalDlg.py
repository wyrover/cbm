#coding:utf-8

import sys
from uipy.ui_difficult_eval_dlg import *

class DifficultEvalDlg(QtGui.QDialog):  
    def __init__(self, mine_id=-1, parent=None):
        super(DifficultEvalDlg, self).__init__(parent)
        self.ui = Ui_difficult_eval_dlg()
        self.ui.setupUi(self)
        self.setFixedSize( self.width(),self.height())
        self.ui.eval.clicked.connect(self.eval)
        self.ui.cancel.clicked.connect(self.cancel)
        # 待设计的矿井
        self.mine_id = mine_id

    def cancel(self):
        self.accept()

    def eval(self):
        #做保存操作
        pass