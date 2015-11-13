# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\mine_gas_flow_predict_design_dlg.ui'
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

class Ui_mine_gas_flow_predict_design_dlg(object):
    def setupUi(self, mine_gas_flow_predict_design_dlg):
        mine_gas_flow_predict_design_dlg.setObjectName(_fromUtf8("mine_gas_flow_predict_design_dlg"))
        mine_gas_flow_predict_design_dlg.resize(227, 275)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_flow_predict_design_dlg.setWindowIcon(icon)
        self.groupBox = QtGui.QGroupBox(mine_gas_flow_predict_design_dlg)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 201, 111))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.label_6 = QtGui.QLabel(self.groupBox)
        self.label_6.setGeometry(QtCore.QRect(20, 80, 91, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.label_5 = QtGui.QLabel(self.groupBox)
        self.label_5.setGeometry(QtCore.QRect(20, 50, 61, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.work_area_A = QtGui.QLineEdit(self.groupBox)
        self.work_area_A.setGeometry(QtCore.QRect(90, 50, 91, 20))
        self.work_area_A.setObjectName(_fromUtf8("work_area_A"))
        self.work_area_qr = QtGui.QLineEdit(self.groupBox)
        self.work_area_qr.setGeometry(QtCore.QRect(110, 80, 71, 20))
        self.work_area_qr.setObjectName(_fromUtf8("work_area_qr"))
        self.ws = QtGui.QComboBox(self.groupBox)
        self.ws.setGeometry(QtCore.QRect(90, 20, 91, 22))
        self.ws.setObjectName(_fromUtf8("ws"))
        self.label_4 = QtGui.QLabel(self.groupBox)
        self.label_4.setGeometry(QtCore.QRect(20, 20, 61, 21))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.groupBox_2 = QtGui.QGroupBox(mine_gas_flow_predict_design_dlg)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 140, 201, 91))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.label_8 = QtGui.QLabel(self.groupBox_2)
        self.label_8.setGeometry(QtCore.QRect(20, 30, 61, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.tws_qa = QtGui.QLineEdit(self.groupBox_2)
        self.tws_qa.setGeometry(QtCore.QRect(110, 60, 71, 20))
        self.tws_qa.setObjectName(_fromUtf8("tws_qa"))
        self.label_7 = QtGui.QLabel(self.groupBox_2)
        self.label_7.setGeometry(QtCore.QRect(20, 60, 91, 21))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.tws = QtGui.QComboBox(self.groupBox_2)
        self.tws.setGeometry(QtCore.QRect(90, 30, 91, 22))
        self.tws.setObjectName(_fromUtf8("tws"))
        self.save = QtGui.QPushButton(mine_gas_flow_predict_design_dlg)
        self.save.setGeometry(QtCore.QRect(80, 240, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(mine_gas_flow_predict_design_dlg)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_flow_predict_design_dlg)

    def retranslateUi(self, mine_gas_flow_predict_design_dlg):
        mine_gas_flow_predict_design_dlg.setWindowTitle(_translate("mine_gas_flow_predict_design_dlg", "工作面和掘进面瓦斯涌出量相关参数及设计", None))
        self.groupBox.setTitle(_translate("mine_gas_flow_predict_design_dlg", ">>工作面瓦斯参数", None))
        self.label_6.setText(_translate("mine_gas_flow_predict_design_dlg", "相对瓦斯涌出量", None))
        self.label_5.setText(_translate("mine_gas_flow_predict_design_dlg", "平均日产量", None))
        self.label_4.setText(_translate("mine_gas_flow_predict_design_dlg", "工作面列表", None))
        self.groupBox_2.setTitle(_translate("mine_gas_flow_predict_design_dlg", ">>掘进面瓦斯参数", None))
        self.label_8.setText(_translate("mine_gas_flow_predict_design_dlg", "掘进面列表", None))
        self.label_7.setText(_translate("mine_gas_flow_predict_design_dlg", "绝对瓦斯涌出量", None))
        self.save.setText(_translate("mine_gas_flow_predict_design_dlg", "保 存", None))

import usecad_rc
