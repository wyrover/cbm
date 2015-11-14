# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\pore_size_dlg.ui'
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

class Ui_pore_size_dlg(object):
    def setupUi(self, pore_size_dlg):
        pore_size_dlg.setObjectName(_fromUtf8("pore_size_dlg"))
        pore_size_dlg.resize(290, 269)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_size_dlg.setWindowIcon(icon)
        self.groupBox = QtGui.QGroupBox(pore_size_dlg)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 271, 141))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.hint = QtGui.QPushButton(self.groupBox)
        self.hint.setGeometry(QtCore.QRect(200, 20, 61, 21))
        self.hint.setObjectName(_fromUtf8("hint"))
        self.sigma = QtGui.QLineEdit(self.groupBox)
        self.sigma.setGeometry(QtCore.QRect(80, 110, 51, 20))
        self.sigma.setObjectName(_fromUtf8("sigma"))
        self.mineName_label_11 = QtGui.QLabel(self.groupBox)
        self.mineName_label_11.setGeometry(QtCore.QRect(20, 80, 111, 21))
        self.mineName_label_11.setObjectName(_fromUtf8("mineName_label_11"))
        self.mineName_label_12 = QtGui.QLabel(self.groupBox)
        self.mineName_label_12.setGeometry(QtCore.QRect(20, 20, 121, 21))
        self.mineName_label_12.setObjectName(_fromUtf8("mineName_label_12"))
        self.mineName_label_10 = QtGui.QLabel(self.groupBox)
        self.mineName_label_10.setGeometry(QtCore.QRect(20, 110, 61, 21))
        self.mineName_label_10.setObjectName(_fromUtf8("mineName_label_10"))
        self.mineName_label_13 = QtGui.QLabel(self.groupBox)
        self.mineName_label_13.setGeometry(QtCore.QRect(20, 50, 61, 21))
        self.mineName_label_13.setObjectName(_fromUtf8("mineName_label_13"))
        self.mineName_label_9 = QtGui.QLabel(self.groupBox)
        self.mineName_label_9.setGeometry(QtCore.QRect(140, 50, 111, 21))
        self.mineName_label_9.setObjectName(_fromUtf8("mineName_label_9"))
        self.P = QtGui.QLineEdit(self.groupBox)
        self.P.setGeometry(QtCore.QRect(130, 80, 51, 20))
        self.P.setObjectName(_fromUtf8("P"))
        self.Q = QtGui.QLineEdit(self.groupBox)
        self.Q.setGeometry(QtCore.QRect(140, 20, 51, 20))
        self.Q.setObjectName(_fromUtf8("Q"))
        self.V = QtGui.QLineEdit(self.groupBox)
        self.V.setGeometry(QtCore.QRect(80, 50, 51, 20))
        self.V.setObjectName(_fromUtf8("V"))
        self.hint2 = QtGui.QPushButton(self.groupBox)
        self.hint2.setGeometry(QtCore.QRect(140, 110, 61, 21))
        self.hint2.setObjectName(_fromUtf8("hint2"))
        self.groupBox_2 = QtGui.QGroupBox(pore_size_dlg)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 160, 271, 51))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.D = QtGui.QLineEdit(self.groupBox_2)
        self.D.setGeometry(QtCore.QRect(70, 20, 51, 20))
        self.D.setObjectName(_fromUtf8("D"))
        self.mineName_label_8 = QtGui.QLabel(self.groupBox_2)
        self.mineName_label_8.setGeometry(QtCore.QRect(10, 20, 61, 21))
        self.mineName_label_8.setObjectName(_fromUtf8("mineName_label_8"))
        self.delta = QtGui.QLineEdit(self.groupBox_2)
        self.delta.setGeometry(QtCore.QRect(210, 20, 51, 20))
        self.delta.setObjectName(_fromUtf8("delta"))
        self.mineName_label_7 = QtGui.QLabel(self.groupBox_2)
        self.mineName_label_7.setGeometry(QtCore.QRect(150, 20, 61, 21))
        self.mineName_label_7.setObjectName(_fromUtf8("mineName_label_7"))
        self.save = QtGui.QPushButton(pore_size_dlg)
        self.save.setGeometry(QtCore.QRect(160, 230, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))
        self.cacl = QtGui.QPushButton(pore_size_dlg)
        self.cacl.setGeometry(QtCore.QRect(40, 230, 81, 31))
        self.cacl.setObjectName(_fromUtf8("cacl"))

        self.retranslateUi(pore_size_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_size_dlg)
        pore_size_dlg.setTabOrder(self.Q, self.hint)
        pore_size_dlg.setTabOrder(self.hint, self.V)
        pore_size_dlg.setTabOrder(self.V, self.P)
        pore_size_dlg.setTabOrder(self.P, self.sigma)
        pore_size_dlg.setTabOrder(self.sigma, self.hint2)
        pore_size_dlg.setTabOrder(self.hint2, self.D)
        pore_size_dlg.setTabOrder(self.D, self.delta)
        pore_size_dlg.setTabOrder(self.delta, self.cacl)
        pore_size_dlg.setTabOrder(self.cacl, self.save)

    def retranslateUi(self, pore_size_dlg):
        pore_size_dlg.setWindowTitle(_translate("pore_size_dlg", "抽采管径大小辅助计算", None))
        self.groupBox.setTitle(_translate("pore_size_dlg", ">>管路参数", None))
        self.hint.setText(_translate("pore_size_dlg", "提 示", None))
        self.mineName_label_11.setText(_translate("pore_size_dlg", "管路最大工作压力P", None))
        self.mineName_label_12.setText(_translate("pore_size_dlg", "管路内混合瓦斯流量Q", None))
        self.mineName_label_10.setText(_translate("pore_size_dlg", "容许压力σ", None))
        self.mineName_label_13.setText(_translate("pore_size_dlg", "经济流速V", None))
        self.mineName_label_9.setText(_translate("pore_size_dlg", "(注：可取5～12m/s)", None))
        self.hint2.setText(_translate("pore_size_dlg", "提 示", None))
        self.groupBox_2.setTitle(_translate("pore_size_dlg", ">>计算结果", None))
        self.mineName_label_8.setText(_translate("pore_size_dlg", "管路内径D", None))
        self.mineName_label_7.setText(_translate("pore_size_dlg", "管路壁厚δ", None))
        self.save.setText(_translate("pore_size_dlg", "保 存", None))
        self.cacl.setText(_translate("pore_size_dlg", "计 算", None))

import usecad_rc
