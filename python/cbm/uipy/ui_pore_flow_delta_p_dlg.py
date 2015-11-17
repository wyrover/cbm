# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\pore_flow_delta_p_dlg.ui'
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

class Ui_pore_flow_delta_p_dlg(object):
    def setupUi(self, pore_flow_delta_p_dlg):
        pore_flow_delta_p_dlg.setObjectName(_fromUtf8("pore_flow_delta_p_dlg"))
        pore_flow_delta_p_dlg.resize(320, 220)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        pore_flow_delta_p_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(pore_flow_delta_p_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 321, 191))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.mineName_label_11 = QtGui.QLabel(self.widget_main)
        self.mineName_label_11.setGeometry(QtCore.QRect(20, 50, 131, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_11.setFont(font)
        self.mineName_label_11.setObjectName(_fromUtf8("mineName_label_11"))
        self.delta_p = QtGui.QLineEdit(self.widget_main)
        self.delta_p.setGeometry(QtCore.QRect(240, 110, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.delta_p.setFont(font)
        self.delta_p.setObjectName(_fromUtf8("delta_p"))
        self.p_cur = QtGui.QLineEdit(self.widget_main)
        self.p_cur.setGeometry(QtCore.QRect(240, 50, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.p_cur.setFont(font)
        self.p_cur.setObjectName(_fromUtf8("p_cur"))
        self.p_test = QtGui.QLineEdit(self.widget_main)
        self.p_test.setGeometry(QtCore.QRect(240, 20, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.p_test.setFont(font)
        self.p_test.setObjectName(_fromUtf8("p_test"))
        self.mineName_label_10 = QtGui.QLabel(self.widget_main)
        self.mineName_label_10.setGeometry(QtCore.QRect(20, 20, 171, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_10.setFont(font)
        self.mineName_label_10.setObjectName(_fromUtf8("mineName_label_10"))
        self.save = QtGui.QPushButton(self.widget_main)
        self.save.setGeometry(QtCore.QRect(120, 150, 81, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.save.setFont(font)
        self.save.setObjectName(_fromUtf8("save"))
        self.pt = QtGui.QLineEdit(self.widget_main)
        self.pt.setGeometry(QtCore.QRect(240, 80, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.pt.setFont(font)
        self.pt.setObjectName(_fromUtf8("pt"))
        self.mineName_label_12 = QtGui.QLabel(self.widget_main)
        self.mineName_label_12.setGeometry(QtCore.QRect(20, 80, 221, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_12.setFont(font)
        self.mineName_label_12.setObjectName(_fromUtf8("mineName_label_12"))
        self.mineName_label_15 = QtGui.QLabel(self.widget_main)
        self.mineName_label_15.setGeometry(QtCore.QRect(20, 110, 141, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_15.setFont(font)
        self.mineName_label_15.setObjectName(_fromUtf8("mineName_label_15"))
        self.widget_title = QtGui.QWidget(pore_flow_delta_p_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 321, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 231, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(280, 0, 41, 31))
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

        self.retranslateUi(pore_flow_delta_p_dlg)
        QtCore.QMetaObject.connectSlotsByName(pore_flow_delta_p_dlg)
        pore_flow_delta_p_dlg.setTabOrder(self.p_test, self.p_cur)
        pore_flow_delta_p_dlg.setTabOrder(self.p_cur, self.pt)
        pore_flow_delta_p_dlg.setTabOrder(self.pt, self.delta_p)
        pore_flow_delta_p_dlg.setTabOrder(self.delta_p, self.save)

    def retranslateUi(self, pore_flow_delta_p_dlg):
        pore_flow_delta_p_dlg.setWindowTitle(_translate("pore_flow_delta_p_dlg", "气压校正系数计算", None))
        self.mineName_label_11.setText(_translate("pore_flow_delta_p_dlg", "<html><head/><body><p>测定当地压力P<span style=\" vertical-align:sub;\">当</span></p></body></html>", None))
        self.mineName_label_10.setText(_translate("pore_flow_delta_p_dlg", "<html><head/><body><p>测点管内正压或负压P<span style=\" vertical-align:sub;\">测</span></p></body></html>", None))
        self.save.setText(_translate("pore_flow_delta_p_dlg", "保 存", None))
        self.mineName_label_12.setText(_translate("pore_flow_delta_p_dlg", "孔板上风端测得的绝对压力PT", None))
        self.mineName_label_15.setText(_translate("pore_flow_delta_p_dlg", "气压校正系数δp", None))
        self.lab_Ico.setText(_translate("pore_flow_delta_p_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
