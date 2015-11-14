# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\ws_gas_flow_predict_adj_dlg.ui'
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

class Ui_ws_gas_flow_predict_adj_dlg(object):
    def setupUi(self, ws_gas_flow_predict_adj_dlg):
        ws_gas_flow_predict_adj_dlg.setObjectName(_fromUtf8("ws_gas_flow_predict_adj_dlg"))
        ws_gas_flow_predict_adj_dlg.resize(285, 300)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        ws_gas_flow_predict_adj_dlg.setWindowIcon(icon)
        self.add_adj_layer = QtGui.QPushButton(ws_gas_flow_predict_adj_dlg)
        self.add_adj_layer.setGeometry(QtCore.QRect(160, 10, 51, 23))
        self.add_adj_layer.setObjectName(_fromUtf8("add_adj_layer"))
        self.del_adj_layer = QtGui.QPushButton(ws_gas_flow_predict_adj_dlg)
        self.del_adj_layer.setGeometry(QtCore.QRect(220, 10, 51, 23))
        self.del_adj_layer.setObjectName(_fromUtf8("del_adj_layer"))
        self.adj_layer = QtGui.QComboBox(ws_gas_flow_predict_adj_dlg)
        self.adj_layer.setGeometry(QtCore.QRect(80, 10, 71, 22))
        self.adj_layer.setObjectName(_fromUtf8("adj_layer"))
        self.label_8 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_8.setGeometry(QtCore.QRect(10, 10, 61, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.thick = QtGui.QLineEdit(ws_gas_flow_predict_adj_dlg)
        self.thick.setGeometry(QtCore.QRect(70, 50, 61, 20))
        self.thick.setObjectName(_fromUtf8("thick"))
        self.label_5 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_5.setGeometry(QtCore.QRect(10, 50, 51, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.n_cz = QtGui.QCheckBox(ws_gas_flow_predict_adj_dlg)
        self.n_cz.setGeometry(QtCore.QRect(160, 50, 91, 21))
        self.n_cz.setObjectName(_fromUtf8("n_cz"))
        self.label_11 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_11.setGeometry(QtCore.QRect(10, 90, 71, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.gas_eta = QtGui.QLineEdit(ws_gas_flow_predict_adj_dlg)
        self.gas_eta.setGeometry(QtCore.QRect(90, 90, 61, 20))
        self.gas_eta.setObjectName(_fromUtf8("gas_eta"))
        self.eta_cacl = QtGui.QPushButton(ws_gas_flow_predict_adj_dlg)
        self.eta_cacl.setGeometry(QtCore.QRect(180, 90, 61, 21))
        self.eta_cacl.setObjectName(_fromUtf8("eta_cacl"))
        self.h = QtGui.QLineEdit(ws_gas_flow_predict_adj_dlg)
        self.h.setGeometry(QtCore.QRect(130, 130, 61, 20))
        self.h.setObjectName(_fromUtf8("h"))
        self.label_7 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_7.setGeometry(QtCore.QRect(10, 160, 101, 21))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.hp = QtGui.QLineEdit(ws_gas_flow_predict_adj_dlg)
        self.hp.setGeometry(QtCore.QRect(130, 160, 61, 20))
        self.hp.setObjectName(_fromUtf8("hp"))
        self.label_6 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_6.setGeometry(QtCore.QRect(10, 130, 111, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.gas_W0 = QtGui.QLineEdit(ws_gas_flow_predict_adj_dlg)
        self.gas_W0.setGeometry(QtCore.QRect(130, 190, 61, 20))
        self.gas_W0.setObjectName(_fromUtf8("gas_W0"))
        self.label_9 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_9.setGeometry(QtCore.QRect(10, 220, 111, 21))
        self.label_9.setObjectName(_fromUtf8("label_9"))
        self.gas_Wc2 = QtGui.QLineEdit(ws_gas_flow_predict_adj_dlg)
        self.gas_Wc2.setGeometry(QtCore.QRect(130, 220, 61, 20))
        self.gas_Wc2.setObjectName(_fromUtf8("gas_Wc2"))
        self.label_10 = QtGui.QLabel(ws_gas_flow_predict_adj_dlg)
        self.label_10.setGeometry(QtCore.QRect(10, 190, 111, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.save = QtGui.QPushButton(ws_gas_flow_predict_adj_dlg)
        self.save.setGeometry(QtCore.QRect(100, 260, 71, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(ws_gas_flow_predict_adj_dlg)
        QtCore.QMetaObject.connectSlotsByName(ws_gas_flow_predict_adj_dlg)

    def retranslateUi(self, ws_gas_flow_predict_adj_dlg):
        ws_gas_flow_predict_adj_dlg.setWindowTitle(_translate("ws_gas_flow_predict_adj_dlg", "邻近层相对瓦斯涌出量q2计算", None))
        self.add_adj_layer.setText(_translate("ws_gas_flow_predict_adj_dlg", "增加", None))
        self.del_adj_layer.setText(_translate("ws_gas_flow_predict_adj_dlg", "删除", None))
        self.label_8.setText(_translate("ws_gas_flow_predict_adj_dlg", "邻近层列表", None))
        self.label_5.setText(_translate("ws_gas_flow_predict_adj_dlg", "煤层厚度", None))
        self.n_cz.setText(_translate("ws_gas_flow_predict_adj_dlg", "位于冒落带内", None))
        self.label_11.setText(_translate("ws_gas_flow_predict_adj_dlg", "瓦斯排放率η", None))
        self.eta_cacl.setText(_translate("ws_gas_flow_predict_adj_dlg", "计 算", None))
        self.label_7.setText(_translate("ws_gas_flow_predict_adj_dlg", "岩层破坏范围hp", None))
        self.label_6.setText(_translate("ws_gas_flow_predict_adj_dlg", "与开采层垂直距离h", None))
        self.label_9.setText(_translate("ws_gas_flow_predict_adj_dlg", "煤层残存瓦斯含量Wc", None))
        self.label_10.setText(_translate("ws_gas_flow_predict_adj_dlg", "煤层原始瓦斯含量W0", None))
        self.save.setText(_translate("ws_gas_flow_predict_adj_dlg", "保 存", None))

import usecad_rc
