# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\pore_flow_delta_p_dlg.ui'
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

class Ui_pore_flow_delta_p_dlg(object):
    def setupUi(self, pore_flow_delta_p_dlg):
        pore_flow_delta_p_dlg.setObjectName(_fromUtf8("pore_flow_delta_p_dlg"))
        pore_flow_delta_p_dlg.resize(243, 167)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_delta_p_dlg.setWindowIcon(icon)
        self.mineName_label_15 = QtGui.QLabel(pore_flow_delta_p_dlg)
        self.mineName_label_15.setGeometry(QtCore.QRect(10, 100, 131, 21))
        self.mineName_label_15.setObjectName(_fromUtf8("mineName_label_15"))
        self.delta_p = QtGui.QLineEdit(pore_flow_delta_p_dlg)
        self.delta_p.setGeometry(QtCore.QRect(100, 100, 61, 20))
        self.delta_p.setObjectName(_fromUtf8("delta_p"))
        self.mineName_label_12 = QtGui.QLabel(pore_flow_delta_p_dlg)
        self.mineName_label_12.setGeometry(QtCore.QRect(10, 70, 161, 21))
        self.mineName_label_12.setObjectName(_fromUtf8("mineName_label_12"))
        self.P_cur = QtGui.QLineEdit(pore_flow_delta_p_dlg)
        self.P_cur.setGeometry(QtCore.QRect(110, 40, 61, 20))
        self.P_cur.setObjectName(_fromUtf8("P_cur"))
        self.P_test = QtGui.QLineEdit(pore_flow_delta_p_dlg)
        self.P_test.setGeometry(QtCore.QRect(140, 10, 61, 20))
        self.P_test.setObjectName(_fromUtf8("P_test"))
        self.mineName_label_10 = QtGui.QLabel(pore_flow_delta_p_dlg)
        self.mineName_label_10.setGeometry(QtCore.QRect(10, 10, 131, 21))
        self.mineName_label_10.setObjectName(_fromUtf8("mineName_label_10"))
        self.PT = QtGui.QLineEdit(pore_flow_delta_p_dlg)
        self.PT.setGeometry(QtCore.QRect(170, 70, 61, 20))
        self.PT.setObjectName(_fromUtf8("PT"))
        self.mineName_label_11 = QtGui.QLabel(pore_flow_delta_p_dlg)
        self.mineName_label_11.setGeometry(QtCore.QRect(10, 40, 91, 21))
        self.mineName_label_11.setObjectName(_fromUtf8("mineName_label_11"))
        self.save = QtGui.QPushButton(pore_flow_delta_p_dlg)
        self.save.setGeometry(QtCore.QRect(70, 130, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(pore_flow_delta_p_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_delta_p_dlg)
        pore_flow_delta_p_dlg.setTabOrder(self.P_test, self.P_cur)
        pore_flow_delta_p_dlg.setTabOrder(self.P_cur, self.PT)
        pore_flow_delta_p_dlg.setTabOrder(self.PT, self.delta_p)
        pore_flow_delta_p_dlg.setTabOrder(self.delta_p, self.save)

    def retranslateUi(self, pore_flow_delta_p_dlg):
        pore_flow_delta_p_dlg.setWindowTitle(_translate("pore_flow_delta_p_dlg", "气压校正系数计算", None))
        self.mineName_label_15.setText(_translate("pore_flow_delta_p_dlg", "气压校正系数δp", None))
        self.mineName_label_12.setText(_translate("pore_flow_delta_p_dlg", "孔板上风端测得的绝对压力PT", None))
        self.mineName_label_10.setText(_translate("pore_flow_delta_p_dlg", "<html><head/><body><p>测点管内正压或负压P<span style=\" vertical-align:sub;\">测</span></p></body></html>", None))
        self.mineName_label_11.setText(_translate("pore_flow_delta_p_dlg", "<html><head/><body><p>测定当地压力P<span style=\" vertical-align:sub;\">当</span></p></body></html>", None))
        self.save.setText(_translate("pore_flow_delta_p_dlg", "保 存", None))

import usecad_rc
