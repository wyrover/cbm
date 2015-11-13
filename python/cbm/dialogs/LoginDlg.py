# -*- coding: utf-8 -*-  
from PyQt4 import QtGui,QtCore  
from RegDialog import *
import ctypes
#import usecad_rc

class LoginDialog(QtGui.QDialog):  
	def __init__(self, parent=None):  
		QtGui.QDialog.__init__(self, parent)  
		self.setWindowTitle(u'登录')  
		self.resize(300,150)  
   
		self.nameEdit =QtGui.QLineEdit(self)  
		self.nameEdit.setPlaceholderText(u'用户名')  
   
		self.passwordEdit =QtGui.QLineEdit(self)  
		self.passwordEdit.setEchoMode(QtGui.QLineEdit.Password)  
		self.passwordEdit.setPlaceholderText(u'密码')  
		   
		self.loginBtn =QtGui.QPushButton(u'登录',self)  
		self.regBtn =QtGui.QPushButton(u'注册',self)  
		   
		self.loginBtn.clicked.connect(self.login)  
		self.regBtn.clicked.connect(self.reg)  
   
		layout =QtGui.QVBoxLayout()  
		layout.addWidget(self.nameEdit)  
		layout.addWidget(self.passwordEdit)  
		   
		# 放一个间隔对象美化布局  
		spacerItem =QtGui.QSpacerItem(20,48,QtGui.QSizePolicy.Minimum,QtGui.QSizePolicy.Expanding)  
		layout.addItem(spacerItem)  
		   
		# 按钮布局  
		buttonLayout =QtGui.QHBoxLayout()  
		# 左侧放一个间隔  
		spancerItem2 =QtGui.QSpacerItem(40,20,QtGui.QSizePolicy.Expanding,QtGui.QSizePolicy.Minimum)  
		buttonLayout.addItem(spancerItem2)  
		buttonLayout.addWidget(self.loginBtn)  
		buttonLayout.addWidget(self.regBtn)  
		   
		layout.addLayout(buttonLayout)  
		   
		self.setLayout(layout)  
		self.setWindowIcon(QtGui.QIcon(':/images/cbm.ico'))
		#任务栏图标
		ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID("myappid")
		self.setFixedSize(self.width(), self.height())
   
	def login(self):  
		if self.nameEdit.text()=='admin' and self.passwordEdit.text() =='123':  
			self.accept()# 关闭对话框并返回1  
		else:  
			QtGui.QMessageBox.critical(self, u'错误', u'用户名密码不匹配')  
   
   	def reg(self):
		regDlg = RegDiaolog()  
		if regDlg.exec_():
			self.nameEdit.setText(regDlg.username)
