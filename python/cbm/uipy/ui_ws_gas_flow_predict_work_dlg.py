# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\ws_gas_flow_predict_work_dlg.ui'
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

class Ui_ws_gas_flow_predict_work_dlg(object):
    def setupUi(self, ws_gas_flow_predict_work_dlg):
        ws_gas_flow_predict_work_dlg.setObjectName(_fromUtf8("ws_gas_flow_predict_work_dlg"))
        ws_gas_flow_predict_work_dlg.resize(324, 300)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        ws_gas_flow_predict_work_dlg.setWindowIcon(icon)
        self.k1 = QtGui.QLineEdit(ws_gas_flow_predict_work_dlg)
        self.k1.setGeometry(QtCore.QRect(180, 10, 61, 20))
        self.k1.setObjectName(_fromUtf8("k1"))
        self.label_7 = QtGui.QLabel(ws_gas_flow_predict_work_dlg)
        self.label_7.setGeometry(QtCore.QRect(20, 40, 151, 21))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.k3_cacl = QtGui.QPushButton(ws_gas_flow_predict_work_dlg)
        self.k3_cacl.setGeometry(QtCore.QRect(110, 100, 91, 21))
        self.k3_cacl.setObjectName(_fromUtf8("k3_cacl"))
        self.k2 = QtGui.QLineEdit(ws_gas_flow_predict_work_dlg)
        self.k2.setGeometry(QtCore.QRect(180, 40, 61, 20))
        self.k2.setObjectName(_fromUtf8("k2"))
        self.label_5 = QtGui.QLabel(ws_gas_flow_predict_work_dlg)
        self.label_5.setGeometry(QtCore.QRect(20, 10, 151, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.label = QtGui.QLabel(ws_gas_flow_predict_work_dlg)
        self.label.setGeometry(QtCore.QRect(20, 70, 291, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.k3 = QtGui.QLineEdit(ws_gas_flow_predict_work_dlg)
        self.k3.setGeometry(QtCore.QRect(20, 100, 71, 20))
        self.k3.setObjectName(_fromUtf8("k3"))
        self.kf = QtGui.QLineEdit(ws_gas_flow_predict_work_dlg)
        self.kf.setGeometry(QtCore.QRect(20, 160, 71, 20))
        self.kf.setObjectName(_fromUtf8("kf"))
        self.label_2 = QtGui.QLabel(ws_gas_flow_predict_work_dlg)
        self.label_2.setGeometry(QtCore.QRect(20, 130, 291, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.kf_cacl = QtGui.QPushButton(ws_gas_flow_predict_work_dlg)
        self.kf_cacl.setGeometry(QtCore.QRect(110, 160, 91, 21))
        self.kf_cacl.setObjectName(_fromUtf8("kf_cacl"))
        self.gas_wc2 = QtGui.QLineEdit(ws_gas_flow_predict_work_dlg)
        self.gas_wc2.setGeometry(QtCore.QRect(190, 230, 61, 20))
        self.gas_wc2.setObjectName(_fromUtf8("gas_wc2"))
        self.label_8 = QtGui.QLabel(ws_gas_flow_predict_work_dlg)
        self.label_8.setGeometry(QtCore.QRect(20, 230, 171, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.gas_w0 = QtGui.QLineEdit(ws_gas_flow_predict_work_dlg)
        self.gas_w0.setGeometry(QtCore.QRect(190, 200, 61, 20))
        self.gas_w0.setObjectName(_fromUtf8("gas_w0"))
        self.label_6 = QtGui.QLabel(ws_gas_flow_predict_work_dlg)
        self.label_6.setGeometry(QtCore.QRect(20, 200, 111, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.save = QtGui.QPushButton(ws_gas_flow_predict_work_dlg)
        self.save.setGeometry(QtCore.QRect(110, 260, 101, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(ws_gas_flow_predict_work_dlg)
        QtCore.QMetaObject.connectSlotsByName(ws_gas_flow_predict_work_dlg)

    def retranslateUi(self, ws_gas_flow_predict_work_dlg):
        ws_gas_flow_predict_work_dlg.setWindowTitle(_translate("ws_gas_flow_predict_work_dlg", "开采层相对瓦斯涌出量q1计算", None))
        self.label_7.setText(_translate("ws_gas_flow_predict_work_dlg", "工作面丢煤瓦斯涌出系数K2", None))
        self.k3_cacl.setText(_translate("ws_gas_flow_predict_work_dlg", "参 考 取 值", None))
        self.label_5.setText(_translate("ws_gas_flow_predict_work_dlg", "工作面围岩瓦斯涌出系数K1", None))
        self.label.setText(_translate("ws_gas_flow_predict_work_dlg", "采区内准备巷道预排瓦斯对开采层瓦斯涌出影响系数K3", None))
        self.label_2.setText(_translate("ws_gas_flow_predict_work_dlg", "取决于煤层分层数量和顺序的分层瓦斯涌出系数Kf", None))
        self.kf_cacl.setText(_translate("ws_gas_flow_predict_work_dlg", "参 考 取 值", None))
        self.label_8.setText(_translate("ws_gas_flow_predict_work_dlg", "运出矿井后煤的残存瓦斯含量Wc", None))
        self.label_6.setText(_translate("ws_gas_flow_predict_work_dlg", "煤层原始瓦斯含量W0", None))
        self.save.setText(_translate("ws_gas_flow_predict_work_dlg", "保 存", None))

import usecad_rc
