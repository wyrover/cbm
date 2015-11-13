# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\mine_gas_reserves_predict_dlg1.ui'
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

class Ui_mine_gas_reserves_predict_dlg1(object):
    def setupUi(self, mine_gas_reserves_predict_dlg1):
        mine_gas_reserves_predict_dlg1.setObjectName(_fromUtf8("mine_gas_reserves_predict_dlg1"))
        mine_gas_reserves_predict_dlg1.resize(420, 205)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_reserves_predict_dlg1.setWindowIcon(icon)
        self.label = QtGui.QLabel(mine_gas_reserves_predict_dlg1)
        self.label.setGeometry(QtCore.QRect(20, 10, 111, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.reserve_w1 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg1)
        self.reserve_w1.setGeometry(QtCore.QRect(220, 10, 101, 20))
        self.reserve_w1.setObjectName(_fromUtf8("reserve_w1"))
        self.w1_cacl = QtGui.QPushButton(mine_gas_reserves_predict_dlg1)
        self.w1_cacl.setGeometry(QtCore.QRect(330, 10, 75, 23))
        self.w1_cacl.setObjectName(_fromUtf8("w1_cacl"))
        self.reserve_w2 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg1)
        self.reserve_w2.setGeometry(QtCore.QRect(220, 50, 101, 20))
        self.reserve_w2.setObjectName(_fromUtf8("reserve_w2"))
        self.w2_cacl = QtGui.QPushButton(mine_gas_reserves_predict_dlg1)
        self.w2_cacl.setGeometry(QtCore.QRect(330, 50, 75, 23))
        self.w2_cacl.setObjectName(_fromUtf8("w2_cacl"))
        self.label_2 = QtGui.QLabel(mine_gas_reserves_predict_dlg1)
        self.label_2.setGeometry(QtCore.QRect(20, 50, 191, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.rock_gas_K2 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg1)
        self.rock_gas_K2.setGeometry(QtCore.QRect(220, 90, 101, 20))
        self.rock_gas_K2.setObjectName(_fromUtf8("rock_gas_K2"))
        self.label_3 = QtGui.QLabel(mine_gas_reserves_predict_dlg1)
        self.label_3.setGeometry(QtCore.QRect(20, 90, 131, 21))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.reserve_w3 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg1)
        self.reserve_w3.setGeometry(QtCore.QRect(220, 130, 101, 20))
        self.reserve_w3.setObjectName(_fromUtf8("reserve_w3"))
        self.cacl = QtGui.QPushButton(mine_gas_reserves_predict_dlg1)
        self.cacl.setGeometry(QtCore.QRect(330, 130, 75, 23))
        self.cacl.setObjectName(_fromUtf8("cacl"))
        self.label_4 = QtGui.QLabel(mine_gas_reserves_predict_dlg1)
        self.label_4.setGeometry(QtCore.QRect(20, 130, 181, 21))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.ok = QtGui.QPushButton(mine_gas_reserves_predict_dlg1)
        self.ok.setGeometry(QtCore.QRect(170, 170, 71, 31))
        self.ok.setObjectName(_fromUtf8("ok"))

        self.retranslateUi(mine_gas_reserves_predict_dlg1)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_reserves_predict_dlg1)

    def retranslateUi(self, mine_gas_reserves_predict_dlg1):
        mine_gas_reserves_predict_dlg1.setWindowTitle(_translate("mine_gas_reserves_predict_dlg1", "矿井瓦斯储量计算", None))
        self.label.setText(_translate("mine_gas_reserves_predict_dlg1", "可采煤层瓦斯储量W1", None))
        self.w1_cacl.setText(_translate("mine_gas_reserves_predict_dlg1", "计 算", None))
        self.w2_cacl.setText(_translate("mine_gas_reserves_predict_dlg1", "计 算", None))
        self.label_2.setText(_translate("mine_gas_reserves_predict_dlg1", "受采动影响的不可采煤层瓦斯储量W2", None))
        self.label_3.setText(_translate("mine_gas_reserves_predict_dlg1", "矿井围岩瓦斯储量系数K", None))
        self.cacl.setText(_translate("mine_gas_reserves_predict_dlg1", "计 算", None))
        self.label_4.setText(_translate("mine_gas_reserves_predict_dlg1", "受采动影响的矿井围岩瓦斯储量W3", None))
        self.ok.setText(_translate("mine_gas_reserves_predict_dlg1", "确 定", None))

import usecad_rc
