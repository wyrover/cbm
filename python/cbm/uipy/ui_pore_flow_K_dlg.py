# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\pore_flow_K_dlg.ui'
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

class Ui_pore_flow_K_dlg(object):
    def setupUi(self, pore_flow_K_dlg):
        pore_flow_K_dlg.setObjectName(_fromUtf8("pore_flow_K_dlg"))
        pore_flow_K_dlg.resize(216, 166)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_K_dlg.setWindowIcon(icon)
        self.K = QtGui.QLineEdit(pore_flow_K_dlg)
        self.K.setGeometry(QtCore.QRect(140, 100, 61, 20))
        self.K.setObjectName(_fromUtf8("K"))
        self.mineName_label_13 = QtGui.QLabel(pore_flow_K_dlg)
        self.mineName_label_13.setGeometry(QtCore.QRect(10, 100, 131, 21))
        self.mineName_label_13.setObjectName(_fromUtf8("mineName_label_13"))
        self.a0 = QtGui.QLineEdit(pore_flow_K_dlg)
        self.a0.setGeometry(QtCore.QRect(140, 70, 61, 20))
        self.a0.setObjectName(_fromUtf8("a0"))
        self.mineName_label_14 = QtGui.QLabel(pore_flow_K_dlg)
        self.mineName_label_14.setGeometry(QtCore.QRect(10, 70, 111, 21))
        self.mineName_label_14.setObjectName(_fromUtf8("mineName_label_14"))
        self.d1 = QtGui.QLineEdit(pore_flow_K_dlg)
        self.d1.setGeometry(QtCore.QRect(80, 40, 61, 20))
        self.d1.setObjectName(_fromUtf8("d1"))
        self.mineName_label_15 = QtGui.QLabel(pore_flow_K_dlg)
        self.mineName_label_15.setGeometry(QtCore.QRect(10, 40, 71, 21))
        self.mineName_label_15.setObjectName(_fromUtf8("mineName_label_15"))
        self.D = QtGui.QLineEdit(pore_flow_K_dlg)
        self.D.setGeometry(QtCore.QRect(80, 10, 61, 20))
        self.D.setObjectName(_fromUtf8("D"))
        self.mineName_label_16 = QtGui.QLabel(pore_flow_K_dlg)
        self.mineName_label_16.setGeometry(QtCore.QRect(10, 10, 61, 21))
        self.mineName_label_16.setObjectName(_fromUtf8("mineName_label_16"))
        self.save = QtGui.QPushButton(pore_flow_K_dlg)
        self.save.setGeometry(QtCore.QRect(70, 130, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(pore_flow_K_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_K_dlg)
        pore_flow_K_dlg.setTabOrder(self.D, self.d1)
        pore_flow_K_dlg.setTabOrder(self.d1, self.a0)
        pore_flow_K_dlg.setTabOrder(self.a0, self.K)
        pore_flow_K_dlg.setTabOrder(self.K, self.save)

    def retranslateUi(self, pore_flow_K_dlg):
        pore_flow_K_dlg.setWindowTitle(_translate("pore_flow_K_dlg", "实际孔板流量特性系数计算", None))
        self.mineName_label_13.setText(_translate("pore_flow_K_dlg", "实际孔板流量特性系数K", None))
        self.mineName_label_14.setText(_translate("pore_flow_K_dlg", "标准孔板流量系数a0", None))
        self.mineName_label_15.setText(_translate("pore_flow_K_dlg", "孔板直径d1", None))
        self.mineName_label_16.setText(_translate("pore_flow_K_dlg", "管道直径D", None))
        self.save.setText(_translate("pore_flow_K_dlg", "保 存", None))

import usecad_rc
