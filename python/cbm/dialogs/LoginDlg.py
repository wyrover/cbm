# -*- coding: utf-8 -*-  

from PyQt4 import QtGui,QtCore  
from RegDialog import *
# import ctypes

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import DataHelper
import UiHelper

LOGIN_MESSAGE = {
	-4:u"请输入有效的用户名！",
	-3:u"请输入密码！",
	-2:u"内部错误,请联系技术人员!",
	-1:u"密码不正确!",
	0:u"用户名不存在",
	1:u"恭喜您,登录成功!"
}

class LoginDialog(QtGui.QDialog):  
	def __init__(self, parent=None):
		super(LoginDialog, self).__init__(parent)
		self.setWindowTitle(u'登录')
		self.resize(300,150)
	
		self.nameEdit =QtGui.QLineEdit(self)  
		self.nameEdit.setPlaceholderText(u'用户名')  
	
		self.passwordEdit =QtGui.QLineEdit(self)  
		self.passwordEdit.setEchoMode(QtGui.QLineEdit.Password)  
		self.passwordEdit.setPlaceholderText(u'密码')  
			
		self.loginBtn =QtGui.QPushButton(u'登录',self)  
		self.regBtn =QtGui.QPushButton(u'注册',self)  
			
		self.loginBtn.clicked.connect(self.onLogin)  
		self.regBtn.clicked.connect(self.onReg)
	
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
		# ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID("myappid")
		self.setFixedSize(self.width(), self.height())

	def verify_user(self, uname, pwd):
		ret = -2
		if uname == '':ret = -4
		elif pwd == '':ret = -3
		else:ret = CbmClientHelper.VerifyMineAccount(uname, pwd)
		# 弹出提示信息
		if ret != 1:
			UiHelper.MessageBox(LOGIN_MESSAGE[ret])
		return ret

	def login_or_switch(self, uname, pwd):
		account_id = SQLClientHelper.GetAccountIdByField2('username', uname, 'password', pwd)
		# 查找已登录用户
		pre_account_id = CbmClientHelper.GetOnlineAccountId()
		# 当前没有用户登录
		if pre_account_id < 0:
			# 用户登陆(记录在sys_info表中)
			DataHelper.sql_login_user(account_id)
			UiHelper.MessageBox('恭喜您,登录成功!')
		# 当前已有用户登录
		elif pre_account_id == account_id:
			# UiHelper.MessageBox('您已经登录过了!')
			pass
		else:
			reply = UiHelper.MessageBox('是否注销并切换到用户%s?' % uname, True)
			if reply == True:
				# 切换用户
				DataHelper.sql_switch_user(account_id)

	def onLogin(self):
		uname = unicode(self.nameEdit.text()).encode('utf-8')
		pwd = unicode(self.passwordEdit.text()).encode('utf-8')
		#验证用户名和密码
		ret = self.verify_user(uname, pwd)
		# 验证通过
		if ret == 1:
			# 登录或切换用户
			self.login_or_switch(uname, pwd)
			# 关闭对话框并返回1
			self.accept()
		# else:
		# 	# 关闭对话框并返回0
		# 	self.reject()
	
	def onReg(self):
		regDlg = RegDiaolog()
		if regDlg.exec_():
			self.nameEdit.setText(regDlg.reg_user_name)
