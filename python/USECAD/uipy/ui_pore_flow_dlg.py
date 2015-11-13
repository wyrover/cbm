# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\pore_flow_dlg.ui'
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

class Ui_pore_flow_dlg(object):
    def setupUi(self, pore_flow_dlg):
        pore_flow_dlg.setObjectName(_fromUtf8("pore_flow_dlg"))
        pore_flow_dlg.resize(314, 328)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_dlg.setWindowIcon(icon)
        self.t = QtGui.QLineEdit(pore_flow_dlg)
        self.t.setGeometry(QtCore.QRect(160, 10, 61, 20))
        self.t.setObjectName(_fromUtf8("t"))
        self.mineName_label_10 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_10.setGeometry(QtCore.QRect(20, 10, 111, 21))
        self.mineName_label_10.setObjectName(_fromUtf8("mineName_label_10"))
        self.dh = QtGui.QLineEdit(pore_flow_dlg)
        self.dh.setGeometry(QtCore.QRect(160, 40, 61, 20))
        self.dh.setObjectName(_fromUtf8("dh"))
        self.mineName_label_11 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_11.setGeometry(QtCore.QRect(20, 40, 121, 21))
        self.mineName_label_11.setObjectName(_fromUtf8("mineName_label_11"))
        self.X = QtGui.QLineEdit(pore_flow_dlg)
        self.X.setGeometry(QtCore.QRect(160, 70, 61, 20))
        self.X.setObjectName(_fromUtf8("X"))
        self.mineName_label_12 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_12.setGeometry(QtCore.QRect(20, 70, 121, 21))
        self.mineName_label_12.setObjectName(_fromUtf8("mineName_label_12"))
        self.mineName_label_13 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_13.setGeometry(QtCore.QRect(20, 100, 131, 21))
        self.mineName_label_13.setObjectName(_fromUtf8("mineName_label_13"))
        self.K = QtGui.QLineEdit(pore_flow_dlg)
        self.K.setGeometry(QtCore.QRect(160, 100, 61, 20))
        self.K.setObjectName(_fromUtf8("K"))
        self.b = QtGui.QLineEdit(pore_flow_dlg)
        self.b.setGeometry(QtCore.QRect(160, 130, 61, 20))
        self.b.setObjectName(_fromUtf8("b"))
        self.mineName_label_14 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_14.setGeometry(QtCore.QRect(20, 130, 131, 21))
        self.mineName_label_14.setObjectName(_fromUtf8("mineName_label_14"))
        self.mineName_label_15 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_15.setGeometry(QtCore.QRect(20, 160, 131, 21))
        self.mineName_label_15.setObjectName(_fromUtf8("mineName_label_15"))
        self.delta_p = QtGui.QLineEdit(pore_flow_dlg)
        self.delta_p.setGeometry(QtCore.QRect(160, 160, 61, 20))
        self.delta_p.setObjectName(_fromUtf8("delta_p"))
        self.mineName_label_16 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_16.setGeometry(QtCore.QRect(20, 190, 131, 21))
        self.mineName_label_16.setObjectName(_fromUtf8("mineName_label_16"))
        self.delta_t = QtGui.QLineEdit(pore_flow_dlg)
        self.delta_t.setGeometry(QtCore.QRect(160, 190, 61, 20))
        self.delta_t.setObjectName(_fromUtf8("delta_t"))
        self.mineName_label_17 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_17.setGeometry(QtCore.QRect(20, 220, 131, 21))
        self.mineName_label_17.setObjectName(_fromUtf8("mineName_label_17"))
        self.Q_hun = QtGui.QLineEdit(pore_flow_dlg)
        self.Q_hun.setGeometry(QtCore.QRect(160, 220, 61, 20))
        self.Q_hun.setObjectName(_fromUtf8("Q_hun"))
        self.mineName_label_18 = QtGui.QLabel(pore_flow_dlg)
        self.mineName_label_18.setGeometry(QtCore.QRect(20, 250, 131, 21))
        self.mineName_label_18.setObjectName(_fromUtf8("mineName_label_18"))
        self.Q_chun = QtGui.QLineEdit(pore_flow_dlg)
        self.Q_chun.setGeometry(QtCore.QRect(160, 250, 61, 20))
        self.Q_chun.setObjectName(_fromUtf8("Q_chun"))
        self.save = QtGui.QPushButton(pore_flow_dlg)
        self.save.setGeometry(QtCore.QRect(180, 290, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))
        self.cacl = QtGui.QPushButton(pore_flow_dlg)
        self.cacl.setGeometry(QtCore.QRect(40, 290, 81, 31))
        self.cacl.setObjectName(_fromUtf8("cacl"))
        self.K_cacl = QtGui.QPushButton(pore_flow_dlg)
        self.K_cacl.setGeometry(QtCore.QRect(240, 100, 61, 21))
        self.K_cacl.setObjectName(_fromUtf8("K_cacl"))
        self.b_cacl = QtGui.QPushButton(pore_flow_dlg)
        self.b_cacl.setGeometry(QtCore.QRect(240, 130, 61, 21))
        self.b_cacl.setObjectName(_fromUtf8("b_cacl"))
        self.delta_p_cacl = QtGui.QPushButton(pore_flow_dlg)
        self.delta_p_cacl.setGeometry(QtCore.QRect(240, 160, 61, 21))
        self.delta_p_cacl.setObjectName(_fromUtf8("delta_p_cacl"))
        self.delta_T_cacl = QtGui.QPushButton(pore_flow_dlg)
        self.delta_T_cacl.setGeometry(QtCore.QRect(240, 190, 61, 21))
        self.delta_T_cacl.setObjectName(_fromUtf8("delta_T_cacl"))

        self.retranslateUi(pore_flow_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_dlg)

    def retranslateUi(self, pore_flow_dlg):
        pore_flow_dlg.setWindowTitle(_translate("pore_flow_dlg", "孔板流量计算", None))
        self.mineName_label_10.setText(_translate("pore_flow_dlg", "瓦斯管内测点温度t", None))
        self.mineName_label_11.setText(_translate("pore_flow_dlg", "孔板前后端所测压差Δh", None))
        self.mineName_label_12.setText(_translate("pore_flow_dlg", "混合气体中瓦斯浓度X", None))
        self.mineName_label_13.setText(_translate("pore_flow_dlg", "实际孔板流量特性系数K", None))
        self.mineName_label_14.setText(_translate("pore_flow_dlg", "瓦斯浓度校正系数b", None))
        self.mineName_label_15.setText(_translate("pore_flow_dlg", "气压校正系数δp", None))
        self.mineName_label_16.setText(_translate("pore_flow_dlg", "温度校正系数δT", None))
        self.mineName_label_17.setText(_translate("pore_flow_dlg", "<html><head/><body><p>抽放的瓦斯混合量Q<span style=\" vertical-align:sub;\">混</span></p></body></html>", None))
        self.mineName_label_18.setText(_translate("pore_flow_dlg", "<html><head/><body><p>抽放的瓦斯纯量Q<span style=\" vertical-align:sub;\">纯</span></p></body></html>", None))
        self.save.setText(_translate("pore_flow_dlg", "保 存", None))
        self.cacl.setText(_translate("pore_flow_dlg", "计 算", None))
        self.K_cacl.setText(_translate("pore_flow_dlg", "计 算", None))
        self.b_cacl.setText(_translate("pore_flow_dlg", "计 算", None))
        self.delta_p_cacl.setText(_translate("pore_flow_dlg", "计 算", None))
        self.delta_T_cacl.setText(_translate("pore_flow_dlg", "计 算", None))

import usecad_rc
