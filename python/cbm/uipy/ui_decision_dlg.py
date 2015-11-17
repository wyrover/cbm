# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\decision_dlg.ui'
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
        decision_dlg.resize(311, 252)
        font = QtGui.QFont()
        font.setPointSize(12)
        decision_dlg.setFont(font)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        decision_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(decision_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 311, 221))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.graph = QtGui.QPushButton(self.widget_main)
        self.graph.setGeometry(QtCore.QRect(20, 160, 271, 41))
        self.graph.setObjectName(_fromUtf8("graph"))
        self.technology = QtGui.QPushButton(self.widget_main)
        self.technology.setGeometry(QtCore.QRect(20, 100, 271, 41))
        self.technology.setObjectName(_fromUtf8("technology"))
        self.tech_mode = QtGui.QLabel(self.widget_main)
        self.tech_mode.setGeometry(QtCore.QRect(30, 50, 261, 31))
        self.tech_mode.setObjectName(_fromUtf8("tech_mode"))
        self.label = QtGui.QLabel(self.widget_main)
        self.label.setGeometry(QtCore.QRect(110, 10, 131, 31))
        self.label.setObjectName(_fromUtf8("label"))
        self.widget_title = QtGui.QWidget(decision_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 311, 31))
        self.widget_title.setObjectName(_fromUtf8("widget_title"))
        self.lab_Ico = QtGui.QLabel(self.widget_title)
        self.lab_Ico.setGeometry(QtCore.QRect(0, 0, 31, 31))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lab_Ico.sizePolicy().hasHeightForWidth())
        self.lab_Ico.setSizePolicy(sizePolicy)
        self.lab_Ico.setMinimumSize(QtCore.QSize(30, 0))
        self.lab_Ico.setAlignment(QtCore.Qt.AlignCenter)
        self.lab_Ico.setObjectName(_fromUtf8("lab_Ico"))
        self.lab_Title = QtGui.QLabel(self.widget_title)
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 221, 31))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lab_Title.sizePolicy().hasHeightForWidth())
        self.lab_Title.setSizePolicy(sizePolicy)
        self.lab_Title.setStyleSheet(_fromUtf8("font: 10pt \"微软雅黑\";"))
        self.lab_Title.setText(_fromUtf8(""))
        self.lab_Title.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.lab_Title.setObjectName(_fromUtf8("lab_Title"))
        self.btnMenu_Close = QtGui.QPushButton(self.widget_title)
        self.btnMenu_Close.setGeometry(QtCore.QRect(270, 0, 41, 31))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btnMenu_Close.sizePolicy().hasHeightForWidth())
        self.btnMenu_Close.setSizePolicy(sizePolicy)
        self.btnMenu_Close.setMinimumSize(QtCore.QSize(40, 0))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.btnMenu_Close.setFont(font)
        self.btnMenu_Close.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.btnMenu_Close.setFocusPolicy(QtCore.Qt.NoFocus)
        self.btnMenu_Close.setText(_fromUtf8(""))
        self.btnMenu_Close.setIconSize(QtCore.QSize(32, 32))
        self.btnMenu_Close.setFlat(True)
        self.btnMenu_Close.setObjectName(_fromUtf8("btnMenu_Close"))

        self.retranslateUi(decision_dlg)
        QtCore.QMetaObject.connectSlotsByName(decision_dlg)

    def retranslateUi(self, decision_dlg):
        decision_dlg.setWindowTitle(_translate("decision_dlg", "依据示范矿区智能决策", None))
        self.graph.setText(_translate("decision_dlg", "查 看 煤 层 赋 存 立 体 示 意 图", None))
        self.technology.setText(_translate("decision_dlg", "相 关 推 荐 技 术", None))
        self.tech_mode.setText(_translate("decision_dlg", "xxx技术模式", None))
        self.label.setText(_translate("decision_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#020202;\">推 荐 采 用</span></p></body></html>", None))
        self.lab_Ico.setText(_translate("decision_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
