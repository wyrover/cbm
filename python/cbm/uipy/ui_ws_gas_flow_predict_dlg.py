# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\ws_gas_flow_predict_dlg.ui'
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

class Ui_ws_gas_flow_predict_dlg(object):
    def setupUi(self, ws_gas_flow_predict_dlg):
        ws_gas_flow_predict_dlg.setObjectName(_fromUtf8("ws_gas_flow_predict_dlg"))
        ws_gas_flow_predict_dlg.resize(326, 309)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        ws_gas_flow_predict_dlg.setWindowIcon(icon)
        self.label_8 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_8.setGeometry(QtCore.QRect(10, 10, 61, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.ws = QtGui.QComboBox(ws_gas_flow_predict_dlg)
        self.ws.setGeometry(QtCore.QRect(80, 10, 231, 22))
        self.ws.setObjectName(_fromUtf8("ws"))
        self.groupBox = QtGui.QGroupBox(ws_gas_flow_predict_dlg)
        self.groupBox.setGeometry(QtCore.QRect(10, 50, 301, 51))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.method_thick = QtGui.QRadioButton(self.groupBox)
        self.method_thick.setGeometry(QtCore.QRect(180, 20, 121, 21))
        self.method_thick.setObjectName(_fromUtf8("method_thick"))
        self.method_thin = QtGui.QRadioButton(self.groupBox)
        self.method_thin.setGeometry(QtCore.QRect(10, 20, 171, 21))
        self.method_thin.setChecked(True)
        self.method_thin.setObjectName(_fromUtf8("method_thin"))
        self.thick = QtGui.QLineEdit(ws_gas_flow_predict_dlg)
        self.thick.setGeometry(QtCore.QRect(90, 110, 61, 20))
        self.thick.setObjectName(_fromUtf8("thick"))
        self.label_7 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_7.setGeometry(QtCore.QRect(20, 140, 61, 21))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.label_5 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_5.setGeometry(QtCore.QRect(20, 110, 51, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.label_6 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_6.setGeometry(QtCore.QRect(180, 110, 61, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.label_9 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_9.setGeometry(QtCore.QRect(180, 140, 61, 21))
        self.label_9.setObjectName(_fromUtf8("label_9"))
        self.L = QtGui.QLineEdit(ws_gas_flow_predict_dlg)
        self.L.setGeometry(QtCore.QRect(90, 140, 61, 20))
        self.L.setObjectName(_fromUtf8("L"))
        self.ws_thick = QtGui.QLineEdit(ws_gas_flow_predict_dlg)
        self.ws_thick.setGeometry(QtCore.QRect(250, 110, 61, 20))
        self.ws_thick.setObjectName(_fromUtf8("ws_thick"))
        self.hw = QtGui.QLineEdit(ws_gas_flow_predict_dlg)
        self.hw.setGeometry(QtCore.QRect(250, 140, 61, 20))
        self.hw.setObjectName(_fromUtf8("hw"))
        self.label_10 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_10.setGeometry(QtCore.QRect(20, 210, 141, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.qr1 = QtGui.QLineEdit(ws_gas_flow_predict_dlg)
        self.qr1.setGeometry(QtCore.QRect(160, 180, 61, 20))
        self.qr1.setObjectName(_fromUtf8("qr1"))
        self.qr2 = QtGui.QLineEdit(ws_gas_flow_predict_dlg)
        self.qr2.setGeometry(QtCore.QRect(160, 210, 61, 20))
        self.qr2.setObjectName(_fromUtf8("qr2"))
        self.label_11 = QtGui.QLabel(ws_gas_flow_predict_dlg)
        self.label_11.setGeometry(QtCore.QRect(20, 180, 141, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.qr1_cacl = QtGui.QPushButton(ws_gas_flow_predict_dlg)
        self.qr1_cacl.setGeometry(QtCore.QRect(250, 180, 61, 21))
        self.qr1_cacl.setObjectName(_fromUtf8("qr1_cacl"))
        self.qr2_cacl = QtGui.QPushButton(ws_gas_flow_predict_dlg)
        self.qr2_cacl.setGeometry(QtCore.QRect(250, 210, 61, 21))
        self.qr2_cacl.setObjectName(_fromUtf8("qr2_cacl"))
        self.groupBox_2 = QtGui.QGroupBox(ws_gas_flow_predict_dlg)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 250, 221, 51))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.qr_cacl = QtGui.QPushButton(self.groupBox_2)
        self.qr_cacl.setGeometry(QtCore.QRect(120, 20, 61, 21))
        self.qr_cacl.setObjectName(_fromUtf8("qr_cacl"))
        self.qr = QtGui.QLineEdit(self.groupBox_2)
        self.qr.setGeometry(QtCore.QRect(10, 20, 101, 20))
        self.qr.setObjectName(_fromUtf8("qr"))
        self.save = QtGui.QPushButton(ws_gas_flow_predict_dlg)
        self.save.setGeometry(QtCore.QRect(240, 250, 71, 51))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(ws_gas_flow_predict_dlg)
        QtCore.QMetaObject.connectSlotsByName(ws_gas_flow_predict_dlg)

    def retranslateUi(self, ws_gas_flow_predict_dlg):
        ws_gas_flow_predict_dlg.setWindowTitle(_translate("ws_gas_flow_predict_dlg", "回采工作面瓦斯涌出量预测", None))
        self.label_8.setText(_translate("ws_gas_flow_predict_dlg", "工作面列表", None))
        self.groupBox.setTitle(_translate("ws_gas_flow_predict_dlg", "开采分层情况", None))
        self.method_thick.setText(_translate("ws_gas_flow_predict_dlg", "分层开采(厚煤层)", None))
        self.method_thin.setText(_translate("ws_gas_flow_predict_dlg", "不分层开采(薄及中厚煤层)", None))
        self.label_7.setText(_translate("ws_gas_flow_predict_dlg", "工作面长度", None))
        self.label_5.setText(_translate("ws_gas_flow_predict_dlg", "煤层厚度", None))
        self.label_6.setText(_translate("ws_gas_flow_predict_dlg", "开采层厚度", None))
        self.label_9.setText(_translate("ws_gas_flow_predict_dlg", "工作面采高", None))
        self.label_10.setText(_translate("ws_gas_flow_predict_dlg", "邻近层相对瓦斯涌出量q2", None))
        self.label_11.setText(_translate("ws_gas_flow_predict_dlg", "开采层相对瓦斯涌出量q1", None))
        self.qr1_cacl.setText(_translate("ws_gas_flow_predict_dlg", "计 算", None))
        self.qr2_cacl.setText(_translate("ws_gas_flow_predict_dlg", "计 算", None))
        self.groupBox_2.setTitle(_translate("ws_gas_flow_predict_dlg", ">>回采工作面相对瓦斯涌出量预测结果", None))
        self.qr_cacl.setText(_translate("ws_gas_flow_predict_dlg", "计 算", None))
        self.save.setText(_translate("ws_gas_flow_predict_dlg", "保 存", None))

import usecad_rc
