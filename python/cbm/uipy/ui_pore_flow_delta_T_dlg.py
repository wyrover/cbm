# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\pore_flow_delta_T_dlg.ui'
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

class Ui_pore_flow_delta_T_dlg(object):
    def setupUi(self, pore_flow_delta_T_dlg):
        pore_flow_delta_T_dlg.setObjectName(_fromUtf8("pore_flow_delta_T_dlg"))
        pore_flow_delta_T_dlg.resize(206, 110)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_delta_T_dlg.setWindowIcon(icon)
        self.mineName_label_16 = QtGui.QLabel(pore_flow_delta_T_dlg)
        self.mineName_label_16.setGeometry(QtCore.QRect(20, 40, 131, 21))
        self.mineName_label_16.setObjectName(_fromUtf8("mineName_label_16"))
        self.t = QtGui.QLineEdit(pore_flow_delta_T_dlg)
        self.t.setGeometry(QtCore.QRect(130, 10, 61, 20))
        self.t.setObjectName(_fromUtf8("t"))
        self.delta_t = QtGui.QLineEdit(pore_flow_delta_T_dlg)
        self.delta_t.setGeometry(QtCore.QRect(130, 40, 61, 20))
        self.delta_t.setObjectName(_fromUtf8("delta_t"))
        self.mineName_label_10 = QtGui.QLabel(pore_flow_delta_T_dlg)
        self.mineName_label_10.setGeometry(QtCore.QRect(20, 10, 111, 21))
        self.mineName_label_10.setObjectName(_fromUtf8("mineName_label_10"))
        self.save = QtGui.QPushButton(pore_flow_delta_T_dlg)
        self.save.setGeometry(QtCore.QRect(60, 70, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(pore_flow_delta_T_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_delta_T_dlg)

    def retranslateUi(self, pore_flow_delta_T_dlg):
        pore_flow_delta_T_dlg.setWindowTitle(_translate("pore_flow_delta_T_dlg", "温度校正系数计算", None))
        self.mineName_label_16.setText(_translate("pore_flow_delta_T_dlg", "温度校正系数δT", None))
        self.mineName_label_10.setText(_translate("pore_flow_delta_T_dlg", "瓦斯管内测点温度t", None))
        self.save.setText(_translate("pore_flow_delta_T_dlg", "保 存", None))

import usecad_rc
