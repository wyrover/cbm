# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\login_dlg.ui'
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

class Ui_login_dlg(object):
    def setupUi(self, login_dlg):
        login_dlg.setObjectName(_fromUtf8("login_dlg"))
        login_dlg.setWindowModality(QtCore.Qt.NonModal)
        login_dlg.resize(381, 282)
        font = QtGui.QFont()
        font.setPointSize(12)
        login_dlg.setFont(font)
        self.widget_title = QtGui.QWidget(login_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 381, 31))
        self.widget_title.setObjectName(_fromUtf8("widget_title"))
        self.lab_Ico = QtGui.QLabel(self.widget_title)
        self.lab_Ico.setGeometry(QtCore.QRect(0, 0, 31, 31))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lab_Ico.sizePolicy().hasHeightForWidth())
        self.lab_Ico.setSizePolicy(sizePolicy)
        self.lab_Ico.setMinimumSize(QtCore.QSize(30, 0))
        self.lab_Ico.setAlignment(QtCore.Qt.AlignCenter)
        self.lab_Ico.setObjectName(_fromUtf8("lab_Ico"))
        self.lab_Title = QtGui.QLabel(self.widget_title)
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 291, 31))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lab_Title.sizePolicy().hasHeightForWidth())
        self.lab_Title.setSizePolicy(sizePolicy)
        self.lab_Title.setStyleSheet(_fromUtf8("font: 10pt \"微软雅黑\";"))
        self.lab_Title.setText(_fromUtf8(""))
        self.lab_Title.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.lab_Title.setObjectName(_fromUtf8("lab_Title"))
        self.btnMenu_Close = QtGui.QPushButton(self.widget_title)
        self.btnMenu_Close.setGeometry(QtCore.QRect(340, 0, 41, 31))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btnMenu_Close.sizePolicy().hasHeightForWidth())
        self.btnMenu_Close.setSizePolicy(sizePolicy)
        self.btnMenu_Close.setMinimumSize(QtCore.QSize(40, 0))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.btnMenu_Close.setFont(font)
        self.btnMenu_Close.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.btnMenu_Close.setFocusPolicy(QtCore.Qt.NoFocus)
        self.btnMenu_Close.setText(_fromUtf8(""))
        self.btnMenu_Close.setIconSize(QtCore.QSize(32, 32))
        self.btnMenu_Close.setFlat(True)
        self.btnMenu_Close.setObjectName(_fromUtf8("btnMenu_Close"))
        self.widget_main = QtGui.QWidget(login_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 381, 251))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.reg = QtGui.QPushButton(self.widget_main)
        self.reg.setGeometry(QtCore.QRect(220, 200, 71, 31))
        self.reg.setObjectName(_fromUtf8("reg"))
        self.groupBox = QtGui.QGroupBox(self.widget_main)
        self.groupBox.setGeometry(QtCore.QRect(30, 30, 321, 141))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.username = QtGui.QLineEdit(self.groupBox)
        self.username.setGeometry(QtCore.QRect(140, 40, 151, 31))
        self.username.setObjectName(_fromUtf8("username"))
        self.password = QtGui.QLineEdit(self.groupBox)
        self.password.setGeometry(QtCore.QRect(140, 90, 151, 31))
        self.password.setEchoMode(QtGui.QLineEdit.Password)
        self.password.setObjectName(_fromUtf8("password"))
        self.label_2 = QtGui.QLabel(self.groupBox)
        self.label_2.setGeometry(QtCore.QRect(60, 90, 71, 31))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.label = QtGui.QLabel(self.groupBox)
        self.label.setGeometry(QtCore.QRect(60, 40, 71, 31))
        self.label.setObjectName(_fromUtf8("label"))
        self.login = QtGui.QPushButton(self.widget_main)
        self.login.setGeometry(QtCore.QRect(90, 200, 71, 31))
        self.login.setObjectName(_fromUtf8("login"))

        self.retranslateUi(login_dlg)
        QtCore.QMetaObject.connectSlotsByName(login_dlg)
        login_dlg.setTabOrder(self.username, self.password)
        login_dlg.setTabOrder(self.password, self.login)
        login_dlg.setTabOrder(self.login, self.reg)

    def retranslateUi(self, login_dlg):
        login_dlg.setWindowTitle(_translate("login_dlg", "Form", None))
        self.lab_Ico.setText(_translate("login_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))
        self.reg.setText(_translate("login_dlg", "注 册", None))
        self.groupBox.setTitle(_translate("login_dlg", "登录验证", None))
        self.username.setWhatsThis(_translate("login_dlg", "<html><head/><body><p><br/></p></body></html>", None))
        self.username.setPlaceholderText(_translate("login_dlg", "已注册用户名", None))
        self.password.setPlaceholderText(_translate("login_dlg", "用户密码", None))
        self.label_2.setText(_translate("login_dlg", "密  码：", None))
        self.label.setText(_translate("login_dlg", "用户名：", None))
        self.login.setText(_translate("login_dlg", "登 录", None))

