# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\pore_flow_delta_T_dlg.ui'
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

class Ui_pore_flow_delta_T_dlg(object):
    def setupUi(self, pore_flow_delta_T_dlg):
        pore_flow_delta_T_dlg.setObjectName(_fromUtf8("pore_flow_delta_T_dlg"))
        pore_flow_delta_T_dlg.resize(251, 161)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_delta_T_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(pore_flow_delta_T_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 251, 131))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.t = QtGui.QLineEdit(self.widget_main)
        self.t.setGeometry(QtCore.QRect(170, 20, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.t.setFont(font)
        self.t.setObjectName(_fromUtf8("t"))
        self.save = QtGui.QPushButton(self.widget_main)
        self.save.setGeometry(QtCore.QRect(80, 90, 81, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.save.setFont(font)
        self.save.setObjectName(_fromUtf8("save"))
        self.delta_t = QtGui.QLineEdit(self.widget_main)
        self.delta_t.setGeometry(QtCore.QRect(170, 50, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.delta_t.setFont(font)
        self.delta_t.setObjectName(_fromUtf8("delta_t"))
        self.mineName_label_10 = QtGui.QLabel(self.widget_main)
        self.mineName_label_10.setGeometry(QtCore.QRect(20, 20, 161, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_10.setFont(font)
        self.mineName_label_10.setObjectName(_fromUtf8("mineName_label_10"))
        self.mineName_label_16 = QtGui.QLabel(self.widget_main)
        self.mineName_label_16.setGeometry(QtCore.QRect(20, 50, 131, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_16.setFont(font)
        self.mineName_label_16.setObjectName(_fromUtf8("mineName_label_16"))
        self.widget_title = QtGui.QWidget(pore_flow_delta_T_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 251, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(30, 0, 171, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(210, 0, 41, 31))
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

        self.retranslateUi(pore_flow_delta_T_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_delta_T_dlg)
        pore_flow_delta_T_dlg.setTabOrder(self.t, self.delta_t)
        pore_flow_delta_T_dlg.setTabOrder(self.delta_t, self.save)

    def retranslateUi(self, pore_flow_delta_T_dlg):
        pore_flow_delta_T_dlg.setWindowTitle(_translate("pore_flow_delta_T_dlg", "温度校正系数计算", None))
        self.save.setText(_translate("pore_flow_delta_T_dlg", "保 存", None))
        self.mineName_label_10.setText(_translate("pore_flow_delta_T_dlg", "瓦斯管内测点温度t", None))
        self.mineName_label_16.setText(_translate("pore_flow_delta_T_dlg", "温度校正系数δT", None))
        self.lab_Ico.setText(_translate("pore_flow_delta_T_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
