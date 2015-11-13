# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\name_dlg.ui'
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

class Ui_name_dlg(object):
    def setupUi(self, name_dlg):
        name_dlg.setObjectName(_fromUtf8("name_dlg"))
        name_dlg.resize(301, 42)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        name_dlg.setWindowIcon(icon)
        self.label = QtGui.QLabel(name_dlg)
        self.label.setGeometry(QtCore.QRect(20, 10, 31, 16))
        self.label.setObjectName(_fromUtf8("label"))
        self.name = QtGui.QLineEdit(name_dlg)
        self.name.setGeometry(QtCore.QRect(60, 10, 113, 20))
        self.name.setObjectName(_fromUtf8("name"))
        self.ensure = QtGui.QPushButton(name_dlg)
        self.ensure.setGeometry(QtCore.QRect(200, 10, 75, 23))
        self.ensure.setObjectName(_fromUtf8("ensure"))

        self.retranslateUi(name_dlg)
        QtCore.QMetaObject.connectSlotsByName(name_dlg)

    def retranslateUi(self, name_dlg):
        name_dlg.setWindowTitle(_translate("name_dlg", "新增", None))
        self.label.setText(_translate("name_dlg", "名称", None))
        self.ensure.setText(_translate("name_dlg", "确  定", None))

import usecad_rc
