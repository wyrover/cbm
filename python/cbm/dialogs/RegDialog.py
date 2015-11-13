#coding:utf-8

import sys
from uipy.ui_regdialog import *

def validate(uname,pwd):
	if 'admin' == uname and '123' == pwd:
		return True
	else:
		return False

class RegDiaolog(QtGui.QDialog):  
    def __init__(self,parent=None):  
        QtGui.QDialog.__init__(self,parent)  
        self.ui = Ui_RegDialog()  
        self.ui.setupUi(self)  
        self.ui.password.setEchoMode(QtGui.QLineEdit.Password)
    	self.ui.reg.clicked.connect(self.reg) 
    	self.username = self.ui.username 
        self.setFixedSize( self.width(),self.height())

    def reg(self):
    	if validate(self.ui.username.text(),self.ui.password.text()):
    		self.username = self.ui.username.text()
    		self.accept()
    	else:
			QtGui.QMessageBox.critical(self, u'错误', u'注册出错')  

