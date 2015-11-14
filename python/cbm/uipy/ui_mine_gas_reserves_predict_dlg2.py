# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\mine_gas_reserves_predict_dlg2.ui'
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

class Ui_mine_gas_reserves_predict_dlg2(object):
    def setupUi(self, mine_gas_reserves_predict_dlg2):
        mine_gas_reserves_predict_dlg2.setObjectName(_fromUtf8("mine_gas_reserves_predict_dlg2"))
        mine_gas_reserves_predict_dlg2.resize(294, 264)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_reserves_predict_dlg2.setWindowIcon(icon)
        self.pump_K2 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.pump_K2.setGeometry(QtCore.QRect(180, 10, 101, 20))
        self.pump_K2.setObjectName(_fromUtf8("pump_K2"))
        self.label = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label.setGeometry(QtCore.QRect(10, 10, 111, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_2 = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label_2.setGeometry(QtCore.QRect(10, 40, 111, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.pump_K3 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.pump_K3.setGeometry(QtCore.QRect(180, 40, 101, 20))
        self.pump_K3.setObjectName(_fromUtf8("pump_K3"))
        self.label_3 = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label_3.setGeometry(QtCore.QRect(10, 70, 111, 21))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.pump_K4 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.pump_K4.setGeometry(QtCore.QRect(180, 70, 101, 20))
        self.pump_K4.setObjectName(_fromUtf8("pump_K4"))
        self.label_4 = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label_4.setGeometry(QtCore.QRect(10, 100, 111, 21))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.gas_W0 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.gas_W0.setGeometry(QtCore.QRect(180, 100, 101, 20))
        self.gas_W0.setObjectName(_fromUtf8("gas_W0"))
        self.label_5 = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label_5.setGeometry(QtCore.QRect(10, 130, 161, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.gas_Wc2 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.gas_Wc2.setGeometry(QtCore.QRect(180, 130, 101, 20))
        self.gas_Wc2.setObjectName(_fromUtf8("gas_Wc2"))
        self.label_6 = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label_6.setGeometry(QtCore.QRect(10, 160, 111, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.pump_Kd = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.pump_Kd.setGeometry(QtCore.QRect(180, 160, 101, 20))
        self.pump_Kd.setObjectName(_fromUtf8("pump_Kd"))
        self.label_7 = QtGui.QLabel(mine_gas_reserves_predict_dlg2)
        self.label_7.setGeometry(QtCore.QRect(10, 190, 111, 21))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.pump_K1 = QtGui.QLineEdit(mine_gas_reserves_predict_dlg2)
        self.pump_K1.setGeometry(QtCore.QRect(180, 190, 101, 20))
        self.pump_K1.setObjectName(_fromUtf8("pump_K1"))
        self.ok = QtGui.QPushButton(mine_gas_reserves_predict_dlg2)
        self.ok.setGeometry(QtCore.QRect(160, 220, 71, 31))
        self.ok.setObjectName(_fromUtf8("ok"))
        self.cacl = QtGui.QPushButton(mine_gas_reserves_predict_dlg2)
        self.cacl.setGeometry(QtCore.QRect(40, 220, 71, 31))
        self.cacl.setObjectName(_fromUtf8("cacl"))

        self.retranslateUi(mine_gas_reserves_predict_dlg2)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_reserves_predict_dlg2)

    def retranslateUi(self, mine_gas_reserves_predict_dlg2):
        mine_gas_reserves_predict_dlg2.setWindowTitle(_translate("mine_gas_reserves_predict_dlg2", "矿井可抽瓦斯量计算", None))
        self.label.setText(_translate("mine_gas_reserves_predict_dlg2", "负压抽采作用系数K2", None))
        self.label_2.setText(_translate("mine_gas_reserves_predict_dlg2", "矿井瓦斯抽采率K3", None))
        self.label_3.setText(_translate("mine_gas_reserves_predict_dlg2", "煤层瓦斯排放率K4", None))
        self.label_4.setText(_translate("mine_gas_reserves_predict_dlg2", "煤层原始瓦斯含量My", None))
        self.label_5.setText(_translate("mine_gas_reserves_predict_dlg2", "运到地面煤的残余瓦斯含量Mc", None))
        self.label_6.setText(_translate("mine_gas_reserves_predict_dlg2", "可抽系数K", None))
        self.label_7.setText(_translate("mine_gas_reserves_predict_dlg2", "瓦斯涌出程度系数K1", None))
        self.ok.setText(_translate("mine_gas_reserves_predict_dlg2", "确 定", None))
        self.cacl.setText(_translate("mine_gas_reserves_predict_dlg2", "计 算", None))

import usecad_rc
