# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\decision_dlg.ui'
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

class Ui_decision_dlg(object):
    def setupUi(self, decision_dlg):
        decision_dlg.setObjectName(_fromUtf8("decision_dlg"))
        decision_dlg.resize(243, 191)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        decision_dlg.setWindowIcon(icon)
        self.label = QtGui.QLabel(decision_dlg)
        self.label.setGeometry(QtCore.QRect(90, 10, 81, 31))
        self.label.setObjectName(_fromUtf8("label"))
        self.tech_mode = QtGui.QLabel(decision_dlg)
        self.tech_mode.setGeometry(QtCore.QRect(20, 50, 191, 21))
        self.tech_mode.setObjectName(_fromUtf8("tech_mode"))
        self.technology = QtGui.QPushButton(decision_dlg)
        self.technology.setGeometry(QtCore.QRect(10, 90, 221, 41))
        self.technology.setObjectName(_fromUtf8("technology"))
        self.graph = QtGui.QPushButton(decision_dlg)
        self.graph.setGeometry(QtCore.QRect(10, 140, 221, 41))
        self.graph.setObjectName(_fromUtf8("graph"))

        self.retranslateUi(decision_dlg)
        QtCore.QMetaObject.connectSlotsByName(decision_dlg)

    def retranslateUi(self, decision_dlg):
        decision_dlg.setWindowTitle(_translate("decision_dlg", "依据示范矿区智能决策", None))
        self.label.setText(_translate("decision_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#020202;\">推荐采用</span></p></body></html>", None))
        self.tech_mode.setText(_translate("decision_dlg", "xxx技术模式", None))
        self.technology.setText(_translate("decision_dlg", "相 关 推 荐 技 术", None))
        self.graph.setText(_translate("decision_dlg", "查 看 煤 层 赋 存 立 体 示 意 图", None))

import usecad_rc
