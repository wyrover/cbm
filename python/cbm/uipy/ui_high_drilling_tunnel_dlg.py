# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\high_drilling_tunnel_dlg.ui'
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

class Ui_high_drilling_tunnel_dlg(object):
    def setupUi(self, high_drilling_tunnel_dlg):
        high_drilling_tunnel_dlg.setObjectName(_fromUtf8("high_drilling_tunnel_dlg"))
        high_drilling_tunnel_dlg.resize(261, 207)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        high_drilling_tunnel_dlg.setWindowIcon(icon)
        self.ws = QtGui.QComboBox(high_drilling_tunnel_dlg)
        self.ws.setGeometry(QtCore.QRect(80, 10, 171, 22))
        self.ws.setObjectName(_fromUtf8("ws"))
        self.label_8 = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label_8.setGeometry(QtCore.QRect(10, 10, 61, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.hw = QtGui.QLineEdit(high_drilling_tunnel_dlg)
        self.hw.setGeometry(QtCore.QRect(50, 50, 61, 20))
        self.hw.setObjectName(_fromUtf8("hw"))
        self.label_9 = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label_9.setGeometry(QtCore.QRect(10, 50, 31, 21))
        self.label_9.setObjectName(_fromUtf8("label_9"))
        self.dip_angle = QtGui.QLineEdit(high_drilling_tunnel_dlg)
        self.dip_angle.setGeometry(QtCore.QRect(190, 50, 61, 20))
        self.dip_angle.setObjectName(_fromUtf8("dip_angle"))
        self.label_10 = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label_10.setGeometry(QtCore.QRect(130, 50, 61, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.czk = QtGui.QLineEdit(high_drilling_tunnel_dlg)
        self.czk.setGeometry(QtCore.QRect(160, 80, 61, 20))
        self.czk.setObjectName(_fromUtf8("czk"))
        self.label_11 = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label_11.setGeometry(QtCore.QRect(10, 80, 141, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.rock = QtGui.QComboBox(high_drilling_tunnel_dlg)
        self.rock.setGeometry(QtCore.QRect(60, 110, 161, 22))
        self.rock.setObjectName(_fromUtf8("rock"))
        self.rock.addItem(_fromUtf8(""))
        self.rock.addItem(_fromUtf8(""))
        self.rock.addItem(_fromUtf8(""))
        self.rock.addItem(_fromUtf8(""))
        self.label_12 = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label_12.setGeometry(QtCore.QRect(10, 110, 51, 21))
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.Hz_min = QtGui.QLineEdit(high_drilling_tunnel_dlg)
        self.Hz_min.setGeometry(QtCore.QRect(130, 140, 41, 20))
        self.Hz_min.setObjectName(_fromUtf8("Hz_min"))
        self.label_13 = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label_13.setGeometry(QtCore.QRect(10, 140, 121, 21))
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.Hz_max = QtGui.QLineEdit(high_drilling_tunnel_dlg)
        self.Hz_max.setGeometry(QtCore.QRect(180, 140, 41, 20))
        self.Hz_max.setObjectName(_fromUtf8("Hz_max"))
        self.label = QtGui.QLabel(high_drilling_tunnel_dlg)
        self.label.setGeometry(QtCore.QRect(170, 140, 16, 16))
        self.label.setObjectName(_fromUtf8("label"))
        self.cacl = QtGui.QPushButton(high_drilling_tunnel_dlg)
        self.cacl.setGeometry(QtCore.QRect(20, 170, 81, 31))
        self.cacl.setObjectName(_fromUtf8("cacl"))
        self.save = QtGui.QPushButton(high_drilling_tunnel_dlg)
        self.save.setGeometry(QtCore.QRect(130, 170, 81, 31))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(high_drilling_tunnel_dlg)
        QtCore.QMetaObject.connectSlotsByName(high_drilling_tunnel_dlg)

    def retranslateUi(self, high_drilling_tunnel_dlg):
        high_drilling_tunnel_dlg.setWindowTitle(_translate("high_drilling_tunnel_dlg", "高抽巷合理布设层位计算", None))
        self.label_8.setText(_translate("high_drilling_tunnel_dlg", "工作面列表", None))
        self.label_9.setText(_translate("high_drilling_tunnel_dlg", "采高h", None))
        self.label_10.setText(_translate("high_drilling_tunnel_dlg", "煤层倾角α", None))
        self.label_11.setText(_translate("high_drilling_tunnel_dlg", "冒落岩石的平均碎胀系数k", None))
        self.rock.setItemText(0, _translate("high_drilling_tunnel_dlg", "坚硬岩石", None))
        self.rock.setItemText(1, _translate("high_drilling_tunnel_dlg", "中硬岩石", None))
        self.rock.setItemText(2, _translate("high_drilling_tunnel_dlg", "软弱岩石", None))
        self.rock.setItemText(3, _translate("high_drilling_tunnel_dlg", "极软弱岩石", None))
        self.label_12.setText(_translate("high_drilling_tunnel_dlg", "岩性选择", None))
        self.label_13.setText(_translate("high_drilling_tunnel_dlg", "高抽巷层位高度Hz范围", None))
        self.label.setText(_translate("high_drilling_tunnel_dlg", "至", None))
        self.cacl.setText(_translate("high_drilling_tunnel_dlg", "计 算", None))
        self.save.setText(_translate("high_drilling_tunnel_dlg", "保 存", None))

import usecad_rc
