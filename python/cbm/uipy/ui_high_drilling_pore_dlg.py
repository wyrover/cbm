# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\high_drilling_pore_dlg.ui'
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

class Ui_high_drilling_pore_dlg(object):
    def setupUi(self, high_drilling_pore_dlg):
        high_drilling_pore_dlg.setObjectName(_fromUtf8("high_drilling_pore_dlg"))
        high_drilling_pore_dlg.resize(298, 300)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        high_drilling_pore_dlg.setWindowIcon(icon)
        self.label_10 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_10.setGeometry(QtCore.QRect(10, 10, 121, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.lw = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.lw.setGeometry(QtCore.QRect(140, 10, 61, 20))
        self.lw.setObjectName(_fromUtf8("lw"))
        self.label_11 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_11.setGeometry(QtCore.QRect(10, 40, 121, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.n1 = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.n1.setGeometry(QtCore.QRect(140, 40, 61, 20))
        self.n1.setObjectName(_fromUtf8("n1"))
        self.label_12 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_12.setGeometry(QtCore.QRect(10, 70, 121, 21))
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.n2 = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.n2.setGeometry(QtCore.QRect(140, 70, 61, 20))
        self.n2.setObjectName(_fromUtf8("n2"))
        self.lc = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.lc.setGeometry(QtCore.QRect(10, 120, 61, 20))
        self.lc.setObjectName(_fromUtf8("lc"))
        self.label_13 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_13.setGeometry(QtCore.QRect(10, 100, 291, 21))
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.ld = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.ld.setGeometry(QtCore.QRect(10, 170, 61, 20))
        self.ld.setObjectName(_fromUtf8("ld"))
        self.label_14 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_14.setGeometry(QtCore.QRect(10, 150, 191, 21))
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.lk = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.lk.setGeometry(QtCore.QRect(210, 200, 61, 20))
        self.lk.setObjectName(_fromUtf8("lk"))
        self.label_15 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_15.setGeometry(QtCore.QRect(10, 200, 201, 21))
        self.label_15.setObjectName(_fromUtf8("label_15"))
        self.beta = QtGui.QLineEdit(high_drilling_pore_dlg)
        self.beta.setGeometry(QtCore.QRect(210, 230, 61, 20))
        self.beta.setObjectName(_fromUtf8("beta"))
        self.label_16 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_16.setGeometry(QtCore.QRect(10, 230, 201, 21))
        self.label_16.setObjectName(_fromUtf8("label_16"))
        self.label_17 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_17.setGeometry(QtCore.QRect(80, 120, 181, 21))
        self.label_17.setObjectName(_fromUtf8("label_17"))
        self.label_18 = QtGui.QLabel(high_drilling_pore_dlg)
        self.label_18.setGeometry(QtCore.QRect(80, 170, 121, 21))
        self.label_18.setObjectName(_fromUtf8("label_18"))
        self.cacl = QtGui.QPushButton(high_drilling_pore_dlg)
        self.cacl.setGeometry(QtCore.QRect(50, 260, 81, 31))
        self.cacl.setObjectName(_fromUtf8("cacl"))
        self.save = QtGui.QPushButton(high_drilling_pore_dlg)
        self.save.setGeometry(QtCore.QRect(160, 260, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(high_drilling_pore_dlg)
        QtCore.QMetaObject.connectSlotsByName(high_drilling_pore_dlg)

    def retranslateUi(self, high_drilling_pore_dlg):
        high_drilling_pore_dlg.setWindowTitle(_translate("high_drilling_pore_dlg", "高位抽采钻孔有效布设范围计算", None))
        self.label_10.setText(_translate("high_drilling_pore_dlg", "工作面水平投影长度L", None))
        self.label_11.setText(_translate("high_drilling_pore_dlg", "ABC 范围内钻孔总数n1", None))
        self.label_12.setText(_translate("high_drilling_pore_dlg", "BCD 范围内钻孔总数n2", None))
        self.label_13.setText(_translate("high_drilling_pore_dlg", "重叠区长度,即钻孔沿工作面推进方向上的搭接长度Lc", None))
        self.label_14.setText(_translate("high_drilling_pore_dlg", "钻孔沿工作面方向水平投影长度Ld", None))
        self.label_15.setText(_translate("high_drilling_pore_dlg", "钻孔沿工作面推进方向的控制范围Lk", None))
        self.label_16.setText(_translate("high_drilling_pore_dlg", "ABCD 范围内抽放钻孔的范围控制角β", None))
        self.label_17.setText(_translate("high_drilling_pore_dlg", "(注：依据生产实际Lc不小于20m)", None))
        self.label_18.setText(_translate("high_drilling_pore_dlg", "(注：Ld=(2/3~3/4)L)", None))
        self.cacl.setText(_translate("high_drilling_pore_dlg", "计 算", None))
        self.save.setText(_translate("high_drilling_pore_dlg", "保 存", None))

import usecad_rc
