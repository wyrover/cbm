# -*- coding: utf-8 -*-  

from PyQt4 import QtGui,QtCore  
from RegDialog import *
import ctypes
import time
import datetime

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

LOGIN_MESSAGE = {
	-4:u"请输入有效的用户名！",
	-3:u"请输入密码！",
	-2:u"内部错误,请联系技术人员!",
	-1:u"密码不正确!",
	0:u"用户名不存在",
	1:u"恭喜您,登录成功!"
}

# 获取当前时间,格式: 2015-11-13 21:35:15
def current_time():
    now = datetime.datetime.now()
    return now.strftime('%Y-%m-%d %H:%M:%S')

def sql_login_user(account_id):
    # 设置当前登录用户(记录到sys_info表)
    sys_info = SysInfo()
    sys_info.account_id = account_id
    sys_info.last_login_time = current_time()
    SQLClientHelper.AddSysInfo(sys_info)

def sql_switch_user(account_id):
	sys_info = SQLClientHelper.GetSysInfoByFields({})
	sys_info.account_id = account_id
	sys_info.last_login_time = current_time()
	SQLClientHelper.UpdateSysInfo(sys_info)

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

	def verify_user(self, uname, pwd):
		ret = -2
		if uname == '':ret = -4
		elif pwd == '':ret = -3
		else:ret = CbmClientHelper.VerifyMineAccount(uname, pwd)
		# 弹出提示信息
		if ret != 1:
			QtGui.QMessageBox.information(self, u"提示",LOGIN_MESSAGE[ret])
		return ret

	def login_or_switch(self, uname, pwd):
		account_id = SQLClientHelper.GetAccountIdByField2('username', uname, 'password', pwd)
		# 查找已登录用户
		pre_account_id = CbmClientHelper.GetOnlineAccountId()
		# 当前没有用户登录
		if pre_account_id < 0:
			# 用户登陆(记录在sys_info表中)
			sql_login_user(account_id)
			QtGui.QMessageBox.information(self, u"提示",'恭喜您,登录成功!')
		# 当前已有用户登录
		elif pre_account_id == account_id:
			QtGui.QMessageBox.information(self, u"提示",'您已经登录过了!')
		else:
			reply = QtGui.QMessageBox.question(self, u"提示",'是否注销并切换到用户%s?' % uname, QtGui.QMessageBox.Yes, QtGui.QMessageBox.No)
			if reply == QtGui.QMessageBox.Yes:
				# 切换用户
				sql_switch_user(account_id)

	def login(self):
		uname = str(self.nameEdit.text())
		pwd = str(self.passwordEdit.text())
		#验证用户名和密码
		ret = self.verify_user(uname, pwd)
		# 验证通过
		if ret == 1:
			# 登录或切换用户
			self.login_or_switch(uname, pwd)
			# 关闭对话框并返回1
			self.accept()
		else:
			# 关闭对话框并返回0
			self.reject()
	
	def reg(self):
		regDlg = RegDiaolog()  
		if regDlg.exec_():
			self.nameEdit.setText(regDlg.username)
