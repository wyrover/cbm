#coding:utf-8

import sys
from uipy.ui_name_dlg import *

class NameDlg(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_name_dlg()  
        self.ui.setupUi(self)  
        self.name = None
        self.setFixedSize( self.width(),self.height())
        self.ui.ensure.clicked.connect(self.ensure) 

    def setTitle(self,title):
        self.setWindowTitle(title)

    def ensure(self):
        self.name = self.ui.name.text()
        self.accept()

def showNameDlg(title):
    dlg = NameDlg()
    dlg.setTitle(title)
    name = ''
    if dlg.exec_():
        name = dlg.name
    return name

def AddNewName(combo,title):
    name = showNameDlg(title)
    if name == '':
        QtGui.QMessageBox.information(combo, u"提示",u"请输入有效的名称！")
    else:
        pos = combo.findText(name)
        if pos != -1:
            QtGui.QMessageBox.information(combo, u"提示",u"所输入的名称已存在！")
        else:
            combo.addItem(name)
            pos = combo.count()-1
        combo.setCurrentIndex(pos)
