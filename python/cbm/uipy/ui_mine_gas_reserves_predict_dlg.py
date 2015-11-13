# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\mine_gas_reserves_predict_dlg.ui'
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

class Ui_mine_gas_reserves_predict_dlg(object):
    def setupUi(self, mine_gas_reserves_predict_dlg):
        mine_gas_reserves_predict_dlg.setObjectName(_fromUtf8("mine_gas_reserves_predict_dlg"))
        mine_gas_reserves_predict_dlg.resize(322, 104)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_reserves_predict_dlg.setWindowIcon(icon)
        self.label = QtGui.QLabel(mine_gas_reserves_predict_dlg)
        self.label.setGeometry(QtCore.QRect(20, 10, 71, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.reserve_gas = QtGui.QLineEdit(mine_gas_reserves_predict_dlg)
        self.reserve_gas.setGeometry(QtCore.QRect(122, 10, 91, 20))
        self.reserve_gas.setObjectName(_fromUtf8("reserve_gas"))
        self.gas_cacl = QtGui.QPushButton(mine_gas_reserves_predict_dlg)
        self.gas_cacl.setGeometry(QtCore.QRect(230, 10, 75, 23))
        self.gas_cacl.setObjectName(_fromUtf8("gas_cacl"))
        self.pump_wc_cacl = QtGui.QPushButton(mine_gas_reserves_predict_dlg)
        self.pump_wc_cacl.setGeometry(QtCore.QRect(230, 40, 75, 23))
        self.pump_wc_cacl.setObjectName(_fromUtf8("pump_wc_cacl"))
        self.label_2 = QtGui.QLabel(mine_gas_reserves_predict_dlg)
        self.label_2.setGeometry(QtCore.QRect(20, 40, 91, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.pump_Wc = QtGui.QLineEdit(mine_gas_reserves_predict_dlg)
        self.pump_Wc.setGeometry(QtCore.QRect(122, 40, 91, 20))
        self.pump_Wc.setObjectName(_fromUtf8("pump_Wc"))
        self.ok = QtGui.QPushButton(mine_gas_reserves_predict_dlg)
        self.ok.setGeometry(QtCore.QRect(130, 70, 71, 31))
        self.ok.setObjectName(_fromUtf8("ok"))

        self.retranslateUi(mine_gas_reserves_predict_dlg)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_reserves_predict_dlg)

    def retranslateUi(self, mine_gas_reserves_predict_dlg):
        mine_gas_reserves_predict_dlg.setWindowTitle(_translate("mine_gas_reserves_predict_dlg", "矿井瓦斯储量及可抽量预测", None))
        self.label.setText(_translate("mine_gas_reserves_predict_dlg", "矿井瓦斯储量", None))
        self.gas_cacl.setText(_translate("mine_gas_reserves_predict_dlg", "计 算", None))
        self.pump_wc_cacl.setText(_translate("mine_gas_reserves_predict_dlg", "计 算", None))
        self.label_2.setText(_translate("mine_gas_reserves_predict_dlg", "矿井可抽瓦斯量", None))
        self.ok.setText(_translate("mine_gas_reserves_predict_dlg", "确 定", None))

import usecad_rc
