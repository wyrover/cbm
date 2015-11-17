# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\high_drilling_design_dlg.ui'
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

class Ui_high_drilling_design_dlg(object):
    def setupUi(self, high_drilling_design_dlg):
        high_drilling_design_dlg.setObjectName(_fromUtf8("high_drilling_design_dlg"))
        high_drilling_design_dlg.resize(634, 346)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        high_drilling_design_dlg.setWindowIcon(icon)
        self.work_surf = QtGui.QComboBox(high_drilling_design_dlg)
        self.work_surf.setGeometry(QtCore.QRect(80, 11, 111, 31))
        self.work_surf.setObjectName(_fromUtf8("work_surf"))
        self.label_8 = QtGui.QLabel(high_drilling_design_dlg)
        self.label_8.setGeometry(QtCore.QRect(10, 20, 61, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.drill_pore = QtGui.QPushButton(high_drilling_design_dlg)
        self.drill_pore.setGeometry(QtCore.QRect(380, 10, 91, 31))
        self.drill_pore.setObjectName(_fromUtf8("drill_pore"))
        self.drill_site = QtGui.QPushButton(high_drilling_design_dlg)
        self.drill_site.setGeometry(QtCore.QRect(240, 10, 91, 31))
        self.drill_site.setObjectName(_fromUtf8("drill_site"))
        self.save = QtGui.QPushButton(high_drilling_design_dlg)
        self.save.setGeometry(QtCore.QRect(530, 10, 91, 31))
        self.save.setObjectName(_fromUtf8("save"))
        self.groupBox = QtGui.QGroupBox(high_drilling_design_dlg)
        self.groupBox.setGeometry(QtCore.QRect(10, 60, 611, 51))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.label_12 = QtGui.QLabel(self.groupBox)
        self.label_12.setGeometry(QtCore.QRect(430, 30, 91, 21))
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.label_10 = QtGui.QLabel(self.groupBox)
        self.label_10.setGeometry(QtCore.QRect(20, 30, 111, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.l2 = QtGui.QLineEdit(self.groupBox)
        self.l2.setGeometry(QtCore.QRect(340, 30, 61, 20))
        self.l2.setObjectName(_fromUtf8("l2"))
        self.lg = QtGui.QLineEdit(self.groupBox)
        self.lg.setGeometry(QtCore.QRect(530, 30, 61, 20))
        self.lg.setObjectName(_fromUtf8("lg"))
        self.l1 = QtGui.QLineEdit(self.groupBox)
        self.l1.setGeometry(QtCore.QRect(140, 30, 61, 20))
        self.l1.setObjectName(_fromUtf8("l1"))
        self.label_11 = QtGui.QLabel(self.groupBox)
        self.label_11.setGeometry(QtCore.QRect(220, 30, 111, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.label_13 = QtGui.QLabel(high_drilling_design_dlg)
        self.label_13.setGeometry(QtCore.QRect(20, 140, 111, 21))
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.label_14 = QtGui.QLabel(high_drilling_design_dlg)
        self.label_14.setGeometry(QtCore.QRect(320, 140, 111, 21))
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.abc = QtGui.QTableWidget(high_drilling_design_dlg)
        self.abc.setGeometry(QtCore.QRect(10, 160, 301, 171))
        self.abc.setShowGrid(False)
        self.abc.setObjectName(_fromUtf8("abc"))
        self.abc.setColumnCount(3)
        self.abc.setRowCount(0)
        item = QtGui.QTableWidgetItem()
        self.abc.setHorizontalHeaderItem(0, item)
        item = QtGui.QTableWidgetItem()
        self.abc.setHorizontalHeaderItem(1, item)
        item = QtGui.QTableWidgetItem()
        self.abc.setHorizontalHeaderItem(2, item)
        self.bcd = QtGui.QTableWidget(high_drilling_design_dlg)
        self.bcd.setGeometry(QtCore.QRect(320, 160, 301, 171))
        self.bcd.setObjectName(_fromUtf8("bcd"))
        self.bcd.setColumnCount(3)
        self.bcd.setRowCount(0)
        item = QtGui.QTableWidgetItem()
        self.bcd.setHorizontalHeaderItem(0, item)
        item = QtGui.QTableWidgetItem()
        self.bcd.setHorizontalHeaderItem(1, item)
        item = QtGui.QTableWidgetItem()
        self.bcd.setHorizontalHeaderItem(2, item)
        self.label = QtGui.QLabel(high_drilling_design_dlg)
        self.label.setGeometry(QtCore.QRect(20, 120, 91, 16))
        self.label.setObjectName(_fromUtf8("label"))

        self.retranslateUi(high_drilling_design_dlg)
        QtCore.QMetaObject.connectSlotsByName(high_drilling_design_dlg)
        high_drilling_design_dlg.setTabOrder(self.work_surf, self.l1)
        high_drilling_design_dlg.setTabOrder(self.l1, self.l2)
        high_drilling_design_dlg.setTabOrder(self.l2, self.lg)
        high_drilling_design_dlg.setTabOrder(self.lg, self.abc)
        high_drilling_design_dlg.setTabOrder(self.abc, self.bcd)
        high_drilling_design_dlg.setTabOrder(self.bcd, self.drill_site)
        high_drilling_design_dlg.setTabOrder(self.drill_site, self.drill_pore)
        high_drilling_design_dlg.setTabOrder(self.drill_pore, self.save)

    def retranslateUi(self, high_drilling_design_dlg):
        high_drilling_design_dlg.setWindowTitle(_translate("high_drilling_design_dlg", "高位抽采钻场钻孔设计", None))
        self.label_8.setText(_translate("high_drilling_design_dlg", "工作面列表", None))
        self.drill_pore.setText(_translate("high_drilling_design_dlg", "钻 孔 设 计", None))
        self.drill_site.setText(_translate("high_drilling_design_dlg", "钻 场 设 计", None))
        self.save.setText(_translate("high_drilling_design_dlg", "保 存", None))
        self.groupBox.setTitle(_translate("high_drilling_design_dlg", "钻场布设范围", None))
        self.label_12.setText(_translate("high_drilling_design_dlg", "各钻场的间距Lg", None))
        self.label_10.setText(_translate("high_drilling_design_dlg", "初次垮落循环步距L1", None))
        self.label_11.setText(_translate("high_drilling_design_dlg", "周期垮落循环步距L2", None))
        self.label_13.setText(_translate("high_drilling_design_dlg", "ABC范围内钻孔参数", None))
        self.label_14.setText(_translate("high_drilling_design_dlg", "BCD范围内钻孔参数", None))
        item = self.abc.horizontalHeaderItem(0)
        item.setText(_translate("high_drilling_design_dlg", "编号", None))
        item = self.abc.horizontalHeaderItem(1)
        item.setText(_translate("high_drilling_design_dlg", "长度", None))
        item = self.abc.horizontalHeaderItem(2)
        item.setText(_translate("high_drilling_design_dlg", "控制角", None))
        item = self.bcd.horizontalHeaderItem(0)
        item.setText(_translate("high_drilling_design_dlg", "编号", None))
        item = self.bcd.horizontalHeaderItem(1)
        item.setText(_translate("high_drilling_design_dlg", "长度", None))
        item = self.bcd.horizontalHeaderItem(2)
        item.setText(_translate("high_drilling_design_dlg", "控制角", None))
        self.label.setText(_translate("high_drilling_design_dlg", "钻孔布设范围", None))

import usecad_rc
