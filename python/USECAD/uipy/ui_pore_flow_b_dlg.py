# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\pore_flow_b_dlg.ui'
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

class Ui_pore_flow_b_dlg(object):
    def setupUi(self, pore_flow_b_dlg):
        pore_flow_b_dlg.setObjectName(_fromUtf8("pore_flow_b_dlg"))
        pore_flow_b_dlg.resize(201, 110)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_b_dlg.setWindowIcon(icon)
        self.mineName_label_12 = QtGui.QLabel(pore_flow_b_dlg)
        self.mineName_label_12.setGeometry(QtCore.QRect(10, 10, 121, 21))
        self.mineName_label_12.setObjectName(_fromUtf8("mineName_label_12"))
        self.mineName_label_14 = QtGui.QLabel(pore_flow_b_dlg)
        self.mineName_label_14.setGeometry(QtCore.QRect(10, 40, 131, 21))
        self.mineName_label_14.setObjectName(_fromUtf8("mineName_label_14"))
        self.X = QtGui.QLineEdit(pore_flow_b_dlg)
        self.X.setGeometry(QtCore.QRect(130, 10, 61, 20))
        self.X.setObjectName(_fromUtf8("X"))
        self.b = QtGui.QLineEdit(pore_flow_b_dlg)
        self.b.setGeometry(QtCore.QRect(130, 40, 61, 20))
        self.b.setObjectName(_fromUtf8("b"))
        self.save = QtGui.QPushButton(pore_flow_b_dlg)
        self.save.setGeometry(QtCore.QRect(60, 70, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(pore_flow_b_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_b_dlg)

    def retranslateUi(self, pore_flow_b_dlg):
        pore_flow_b_dlg.setWindowTitle(_translate("pore_flow_b_dlg", "瓦斯浓度校正系数计算", None))
        self.mineName_label_12.setText(_translate("pore_flow_b_dlg", "混合气体中瓦斯浓度X", None))
        self.mineName_label_14.setText(_translate("pore_flow_b_dlg", "瓦斯浓度校正系数b", None))
        self.save.setText(_translate("pore_flow_b_dlg", "保 存", None))

import usecad_rc
