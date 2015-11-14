# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\high_drilling_site_dlg.ui'
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

class Ui_high_drilling_site_dlg(object):
    def setupUi(self, high_drilling_site_dlg):
        high_drilling_site_dlg.setObjectName(_fromUtf8("high_drilling_site_dlg"))
        high_drilling_site_dlg.resize(336, 246)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        high_drilling_site_dlg.setWindowIcon(icon)
        self.label_10 = QtGui.QLabel(high_drilling_site_dlg)
        self.label_10.setGeometry(QtCore.QRect(20, 10, 261, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.hn = QtGui.QLineEdit(high_drilling_site_dlg)
        self.hn.setGeometry(QtCore.QRect(20, 30, 71, 20))
        self.hn.setObjectName(_fromUtf8("hn"))
        self.theta = QtGui.QLineEdit(high_drilling_site_dlg)
        self.theta.setGeometry(QtCore.QRect(20, 80, 71, 20))
        self.theta.setObjectName(_fromUtf8("theta"))
        self.label_11 = QtGui.QLabel(high_drilling_site_dlg)
        self.label_11.setGeometry(QtCore.QRect(20, 60, 221, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.q = QtGui.QLineEdit(high_drilling_site_dlg)
        self.q.setGeometry(QtCore.QRect(20, 130, 71, 20))
        self.q.setObjectName(_fromUtf8("q"))
        self.label_12 = QtGui.QLabel(high_drilling_site_dlg)
        self.label_12.setGeometry(QtCore.QRect(20, 110, 141, 21))
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.hs = QtGui.QLineEdit(high_drilling_site_dlg)
        self.hs.setGeometry(QtCore.QRect(20, 180, 71, 20))
        self.hs.setObjectName(_fromUtf8("hs"))
        self.label_13 = QtGui.QLabel(high_drilling_site_dlg)
        self.label_13.setGeometry(QtCore.QRect(20, 160, 261, 21))
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.L1_5 = QtGui.QLineEdit(high_drilling_site_dlg)
        self.L1_5.setGeometry(QtCore.QRect(180, 130, 71, 20))
        self.L1_5.setObjectName(_fromUtf8("L1_5"))
        self.Rtn = QtGui.QLabel(high_drilling_site_dlg)
        self.Rtn.setGeometry(QtCore.QRect(180, 110, 151, 21))
        self.Rtn.setObjectName(_fromUtf8("Rtn"))
        self.save = QtGui.QPushButton(high_drilling_site_dlg)
        self.save.setGeometry(QtCore.QRect(120, 210, 91, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(high_drilling_site_dlg)
        QtCore.QMetaObject.connectSlotsByName(high_drilling_site_dlg)
        high_drilling_site_dlg.setTabOrder(self.hn, self.theta)
        high_drilling_site_dlg.setTabOrder(self.theta, self.q)
        high_drilling_site_dlg.setTabOrder(self.q, self.L1_5)
        high_drilling_site_dlg.setTabOrder(self.L1_5, self.hs)
        high_drilling_site_dlg.setTabOrder(self.hs, self.save)

    def retranslateUi(self, high_drilling_site_dlg):
        high_drilling_site_dlg.setWindowTitle(_translate("high_drilling_site_dlg", "高位抽采钻场范围计算", None))
        self.label_10.setText(_translate("high_drilling_site_dlg", "垮落带范围内自上而下最上一个关键层n的厚度hn", None))
        self.label_11.setText(_translate("high_drilling_site_dlg", "∑h范围内顶板岩层断裂面与层面的夹角θ", None))
        self.label_12.setText(_translate("high_drilling_site_dlg", "第n个关键层的作用载荷q", None))
        self.label_13.setText(_translate("high_drilling_site_dlg", "自煤层到第n个关键层之间的岩层累计厚度∑hi", None))
        self.Rtn.setText(_translate("high_drilling_site_dlg", "第n个关键层的抗拉强度Rtn", None))
        self.save.setText(_translate("high_drilling_site_dlg", "保 存", None))

import usecad_rc
