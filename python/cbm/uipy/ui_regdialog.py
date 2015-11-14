# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\regdialog.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_RegDialog(object):
    def setupUi(self, RegDialog):
        RegDialog.setObjectName(_fromUtf8("RegDialog"))
        RegDialog.resize(388, 309)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Maximum, QtGui.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(RegDialog.sizePolicy().hasHeightForWidth())
        RegDialog.setSizePolicy(sizePolicy)
        RegDialog.setMinimumSize(QtCore.QSize(388, 309))
        RegDialog.setMaximumSize(QtCore.QSize(388, 309))
        RegDialog.setSizeIncrement(QtCore.QSize(388, 309))
        RegDialog.setBaseSize(QtCore.QSize(388, 309))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/reg.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        RegDialog.setWindowIcon(icon)
        self.user_label = QtGui.QLabel(RegDialog)
        self.user_label.setGeometry(QtCore.QRect(11, 10, 54, 16))
        self.user_label.setObjectName(_fromUtf8("user_label"))
        self.password_label = QtGui.QLabel(RegDialog)
        self.password_label.setGeometry(QtCore.QRect(11, 50, 54, 16))
        self.password_label.setObjectName(_fromUtf8("password_label"))
        self.mineName_label = QtGui.QLabel(RegDialog)
        self.mineName_label.setGeometry(QtCore.QRect(11, 90, 54, 16))
        self.mineName_label.setObjectName(_fromUtf8("mineName_label"))
        self.username = QtGui.QLineEdit(RegDialog)
        self.username.setGeometry(QtCore.QRect(70, 10, 301, 20))
        self.username.setObjectName(_fromUtf8("username"))
        self.password = QtGui.QLineEdit(RegDialog)
        self.password.setGeometry(QtCore.QRect(70, 50, 301, 20))
        self.password.setInputMethodHints(QtCore.Qt.ImhNone)
        self.password.setObjectName(_fromUtf8("password"))
        self.name = QtGui.QLineEdit(RegDialog)
        self.name.setGeometry(QtCore.QRect(70, 90, 301, 20))
        self.name.setObjectName(_fromUtf8("name"))
        self.mineName_label_2 = QtGui.QLabel(RegDialog)
        self.mineName_label_2.setGeometry(QtCore.QRect(10, 130, 54, 16))
        self.mineName_label_2.setObjectName(_fromUtf8("mineName_label_2"))
        self.base = QtGui.QComboBox(RegDialog)
        self.base.setGeometry(QtCore.QRect(70, 130, 111, 22))
        self.base.setObjectName(_fromUtf8("base"))
        self.mineName_label_3 = QtGui.QLabel(RegDialog)
        self.mineName_label_3.setGeometry(QtCore.QRect(200, 130, 54, 16))
        self.mineName_label_3.setObjectName(_fromUtf8("mineName_label_3"))
        self.region = QtGui.QComboBox(RegDialog)
        self.region.setGeometry(QtCore.QRect(260, 130, 111, 22))
        self.region.setObjectName(_fromUtf8("region"))
        self.mineName_label_4 = QtGui.QLabel(RegDialog)
        self.mineName_label_4.setGeometry(QtCore.QRect(10, 170, 54, 16))
        self.mineName_label_4.setObjectName(_fromUtf8("mineName_label_4"))
        self.mineName_label_5 = QtGui.QLabel(RegDialog)
        self.mineName_label_5.setGeometry(QtCore.QRect(160, 170, 21, 16))
        self.mineName_label_5.setObjectName(_fromUtf8("mineName_label_5"))
        self.province = QtGui.QLineEdit(RegDialog)
        self.province.setGeometry(QtCore.QRect(70, 170, 81, 20))
        self.province.setObjectName(_fromUtf8("province"))
        self.mineName_label_6 = QtGui.QLabel(RegDialog)
        self.mineName_label_6.setGeometry(QtCore.QRect(290, 170, 61, 16))
        self.mineName_label_6.setObjectName(_fromUtf8("mineName_label_6"))
        self.city = QtGui.QLineEdit(RegDialog)
        self.city.setGeometry(QtCore.QRect(200, 170, 81, 20))
        self.city.setObjectName(_fromUtf8("city"))
        self.coal_nums = QtGui.QLineEdit(RegDialog)
        self.coal_nums.setGeometry(QtCore.QRect(90, 210, 181, 20))
        self.coal_nums.setObjectName(_fromUtf8("coal_nums"))
        self.mineName_label_7 = QtGui.QLabel(RegDialog)
        self.mineName_label_7.setGeometry(QtCore.QRect(10, 210, 71, 16))
        self.mineName_label_7.setObjectName(_fromUtf8("mineName_label_7"))
        self.mineName_label_8 = QtGui.QLabel(RegDialog)
        self.mineName_label_8.setGeometry(QtCore.QRect(270, 210, 81, 16))
        self.mineName_label_8.setObjectName(_fromUtf8("mineName_label_8"))
        self.reg = QtGui.QPushButton(RegDialog)
        self.reg.setGeometry(QtCore.QRect(80, 250, 201, 51))
        self.reg.setObjectName(_fromUtf8("reg"))

        self.retranslateUi(RegDialog)
        QtCore.QMetaObject.connectSlotsByName(RegDialog)

    def retranslateUi(self, RegDialog):
        RegDialog.setWindowTitle(_translate("RegDialog", "注册新矿井", None))
        self.user_label.setText(_translate("RegDialog", "<html><head/><body><p>用户名</p></body></html>", None))
        self.password_label.setText(_translate("RegDialog", "<html><head/><body><p>密 码</p></body></html>", None))
        self.mineName_label.setText(_translate("RegDialog", "矿井名称", None))
        self.username.setToolTip(_translate("RegDialog", "<html><head/><body><p>输入用户名</p></body></html>", None))
        self.username.setWhatsThis(_translate("RegDialog", "<html><head/><body><p>用户名</p></body></html>", None))
        self.password.setToolTip(_translate("RegDialog", "<html><head/><body><p>输入用户密码</p></body></html>", None))
        self.password.setWhatsThis(_translate("RegDialog", "<html><head/><body><p>用户名</p></body></html>", None))
        self.name.setToolTip(_translate("RegDialog", "<html><head/><body><p>输入矿井名称</p></body></html>", None))
        self.name.setWhatsThis(_translate("RegDialog", "<html><head/><body><p>用户名</p></body></html>", None))
        self.mineName_label_2.setText(_translate("RegDialog", "煤炭基地", None))
        self.mineName_label_3.setText(_translate("RegDialog", "所在矿区", None))
        self.mineName_label_4.setText(_translate("RegDialog", "所在地", None))
        self.mineName_label_5.setText(_translate("RegDialog", "省", None))
        self.mineName_label_6.setText(_translate("RegDialog", "市（地区）", None))
        self.mineName_label_7.setText(_translate("RegDialog", "开采煤层编号", None))
        self.mineName_label_8.setText(_translate("RegDialog", "（用空格隔开）", None))
        self.reg.setText(_translate("RegDialog", "注册&&确认", None))

import usecad_rc
