# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\tech_mode_dlg.ui'
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

class Ui_tech_mode_dlg(object):
    def setupUi(self, tech_mode_dlg):
        tech_mode_dlg.setObjectName(_fromUtf8("tech_mode_dlg"))
        tech_mode_dlg.resize(291, 362)
        tech_mode_dlg.setSizeIncrement(QtCore.QSize(291, 362))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        tech_mode_dlg.setWindowIcon(icon)
        self.region = QtGui.QGroupBox(tech_mode_dlg)
        self.region.setGeometry(QtCore.QRect(10, 10, 271, 71))
        self.region.setObjectName(_fromUtf8("region"))
        self.tech_mode = QtGui.QComboBox(self.region)
        self.tech_mode.setGeometry(QtCore.QRect(10, 30, 251, 21))
        self.tech_mode.setObjectName(_fromUtf8("tech_mode"))
        self.groupBox = QtGui.QGroupBox(tech_mode_dlg)
        self.groupBox.setGeometry(QtCore.QRect(10, 100, 271, 191))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.groupBox_2 = QtGui.QGroupBox(self.groupBox)
        self.groupBox_2.setGeometry(QtCore.QRect(0, 20, 271, 51))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.c1_yes = QtGui.QRadioButton(self.groupBox_2)
        self.c1_yes.setGeometry(QtCore.QRect(30, 20, 89, 16))
        self.c1_yes.setAutoRepeatDelay(300)
        self.c1_yes.setObjectName(_fromUtf8("c1_yes"))
        self.c1_no = QtGui.QRadioButton(self.groupBox_2)
        self.c1_no.setGeometry(QtCore.QRect(140, 20, 89, 16))
        self.c1_no.setChecked(True)
        self.c1_no.setObjectName(_fromUtf8("c1_no"))
        self.groupBox_3 = QtGui.QGroupBox(self.groupBox)
        self.groupBox_3.setGeometry(QtCore.QRect(0, 80, 271, 51))
        self.groupBox_3.setObjectName(_fromUtf8("groupBox_3"))
        self.c2_no = QtGui.QRadioButton(self.groupBox_3)
        self.c2_no.setGeometry(QtCore.QRect(140, 20, 89, 16))
        self.c2_no.setChecked(True)
        self.c2_no.setObjectName(_fromUtf8("c2_no"))
        self.c2_yes = QtGui.QRadioButton(self.groupBox_3)
        self.c2_yes.setGeometry(QtCore.QRect(30, 20, 89, 16))
        self.c2_yes.setObjectName(_fromUtf8("c2_yes"))
        self.groupBox_4 = QtGui.QGroupBox(self.groupBox)
        self.groupBox_4.setGeometry(QtCore.QRect(0, 140, 271, 51))
        self.groupBox_4.setObjectName(_fromUtf8("groupBox_4"))
        self.c3_yes = QtGui.QRadioButton(self.groupBox_4)
        self.c3_yes.setGeometry(QtCore.QRect(30, 20, 89, 16))
        self.c3_yes.setObjectName(_fromUtf8("c3_yes"))
        self.c3_no = QtGui.QRadioButton(self.groupBox_4)
        self.c3_no.setGeometry(QtCore.QRect(140, 20, 89, 16))
        self.c3_no.setChecked(True)
        self.c3_no.setObjectName(_fromUtf8("c3_no"))
        self.save = QtGui.QPushButton(tech_mode_dlg)
        self.save.setGeometry(QtCore.QRect(70, 310, 141, 51))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(tech_mode_dlg)
        QtCore.QMetaObject.connectSlotsByName(tech_mode_dlg)

    def retranslateUi(self, tech_mode_dlg):
        tech_mode_dlg.setWindowTitle(_translate("tech_mode_dlg", "煤层气（瓦斯）抽采技术模式参数", None))
        self.region.setTitle(_translate("tech_mode_dlg", ">>xx矿区抽采技术模式", None))
        self.groupBox.setTitle(_translate("tech_mode_dlg", ">> 适用条件", None))
        self.groupBox_2.setTitle(_translate("tech_mode_dlg", "渗透率", None))
        self.c1_yes.setText(_translate("tech_mode_dlg", "中高渗>5mD", None))
        self.c1_no.setText(_translate("tech_mode_dlg", "低渗<=5mD", None))
        self.groupBox_3.setTitle(_translate("tech_mode_dlg", "是否具体有保护层开采条件", None))
        self.c2_no.setText(_translate("tech_mode_dlg", "不具备", None))
        self.c2_yes.setText(_translate("tech_mode_dlg", "具备", None))
        self.groupBox_4.setTitle(_translate("tech_mode_dlg", "是否近距离煤层群", None))
        self.c3_yes.setText(_translate("tech_mode_dlg", "近距离煤层群", None))
        self.c3_no.setText(_translate("tech_mode_dlg", "中远距离煤层群", None))
        self.save.setText(_translate("tech_mode_dlg", "保存", None))

import usecad_rc
