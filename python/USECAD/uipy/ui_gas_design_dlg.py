# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\gas_design_dlg.ui'
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

class Ui_gas_design_dlg(object):
    def setupUi(self, gas_design_dlg):
        gas_design_dlg.setObjectName(_fromUtf8("gas_design_dlg"))
        gas_design_dlg.resize(272, 332)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        gas_design_dlg.setWindowIcon(icon)
        self.coal = QtGui.QComboBox(gas_design_dlg)
        self.coal.setGeometry(QtCore.QRect(70, 10, 111, 22))
        self.coal.setObjectName(_fromUtf8("coal"))
        self.label = QtGui.QLabel(gas_design_dlg)
        self.label.setGeometry(QtCore.QRect(10, 10, 51, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_6 = QtGui.QLabel(gas_design_dlg)
        self.label_6.setGeometry(QtCore.QRect(10, 50, 51, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.label_7 = QtGui.QLabel(gas_design_dlg)
        self.label_7.setGeometry(QtCore.QRect(120, 50, 16, 16))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.dip_angle = QtGui.QLineEdit(gas_design_dlg)
        self.dip_angle.setGeometry(QtCore.QRect(200, 50, 41, 20))
        self.dip_angle.setObjectName(_fromUtf8("dip_angle"))
        self.label_10 = QtGui.QLabel(gas_design_dlg)
        self.label_10.setGeometry(QtCore.QRect(140, 50, 51, 21))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.label_9 = QtGui.QLabel(gas_design_dlg)
        self.label_9.setGeometry(QtCore.QRect(250, 50, 12, 14))
        self.label_9.setObjectName(_fromUtf8("label_9"))
        self.thick = QtGui.QLineEdit(gas_design_dlg)
        self.thick.setGeometry(QtCore.QRect(70, 50, 41, 20))
        self.thick.setObjectName(_fromUtf8("thick"))
        self.save = QtGui.QPushButton(gas_design_dlg)
        self.save.setGeometry(QtCore.QRect(190, 10, 71, 31))
        self.save.setObjectName(_fromUtf8("save"))
        self.label_8 = QtGui.QLabel(gas_design_dlg)
        self.label_8.setGeometry(QtCore.QRect(10, 80, 131, 21))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.technology = QtGui.QListWidget(gas_design_dlg)
        self.technology.setGeometry(QtCore.QRect(10, 100, 251, 121))
        self.technology.setObjectName(_fromUtf8("technology"))
        self.label_11 = QtGui.QLabel(gas_design_dlg)
        self.label_11.setGeometry(QtCore.QRect(10, 230, 131, 21))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.del_design = QtGui.QPushButton(gas_design_dlg)
        self.del_design.setGeometry(QtCore.QRect(210, 250, 51, 23))
        self.del_design.setObjectName(_fromUtf8("del_design"))
        self.design = QtGui.QComboBox(gas_design_dlg)
        self.design.setGeometry(QtCore.QRect(10, 250, 131, 22))
        self.design.setObjectName(_fromUtf8("design"))
        self.new_design = QtGui.QPushButton(gas_design_dlg)
        self.new_design.setGeometry(QtCore.QRect(150, 250, 51, 23))
        self.new_design.setObjectName(_fromUtf8("new_design"))
        self.go = QtGui.QPushButton(gas_design_dlg)
        self.go.setGeometry(QtCore.QRect(60, 290, 161, 41))
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/go.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.go.setIcon(icon1)
        self.go.setObjectName(_fromUtf8("go"))

        self.retranslateUi(gas_design_dlg)
        QtCore.QMetaObject.connectSlotsByName(gas_design_dlg)
        gas_design_dlg.setTabOrder(self.coal, self.thick)
        gas_design_dlg.setTabOrder(self.thick, self.dip_angle)
        gas_design_dlg.setTabOrder(self.dip_angle, self.technology)
        gas_design_dlg.setTabOrder(self.technology, self.design)
        gas_design_dlg.setTabOrder(self.design, self.new_design)
        gas_design_dlg.setTabOrder(self.new_design, self.del_design)
        gas_design_dlg.setTabOrder(self.del_design, self.go)
        gas_design_dlg.setTabOrder(self.go, self.save)

    def retranslateUi(self, gas_design_dlg):
        gas_design_dlg.setWindowTitle(_translate("gas_design_dlg", "煤层气抽采技术辅助设计", None))
        self.label.setText(_translate("gas_design_dlg", "煤层列表", None))
        self.label_6.setText(_translate("gas_design_dlg", "煤层厚度", None))
        self.label_7.setText(_translate("gas_design_dlg", "<html><head/><body><p>m</p></body></html>", None))
        self.label_10.setText(_translate("gas_design_dlg", "煤层倾角", None))
        self.label_9.setText(_translate("gas_design_dlg", "<html><head/><body><p>°</p></body></html>", None))
        self.save.setText(_translate("gas_design_dlg", "保  存", None))
        self.label_8.setText(_translate("gas_design_dlg", "请选择相应的抽采技术", None))
        self.label_11.setText(_translate("gas_design_dlg", "请选择已有的设计数据", None))
        self.del_design.setText(_translate("gas_design_dlg", "删除", None))
        self.new_design.setText(_translate("gas_design_dlg", "增加", None))
        self.go.setToolTip(_translate("gas_design_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))
        self.go.setText(_translate("gas_design_dlg", "开始设计—>Go!", None))

import usecad_rc
