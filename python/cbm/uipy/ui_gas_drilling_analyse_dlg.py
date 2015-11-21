# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\gas_drilling_analyse_dlg.ui'
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

class Ui_gas_drilling_analyse_dlg(object):
    def setupUi(self, gas_drilling_analyse_dlg):
        gas_drilling_analyse_dlg.setObjectName(_fromUtf8("gas_drilling_analyse_dlg"))
        gas_drilling_analyse_dlg.resize(439, 237)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        gas_drilling_analyse_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(gas_drilling_analyse_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 431, 201))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.save = QtGui.QPushButton(self.widget_main)
        self.save.setGeometry(QtCore.QRect(120, 140, 130, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.save.setFont(font)
        self.save.setObjectName(_fromUtf8("save"))
        self.groupBox_4 = QtGui.QGroupBox(self.widget_main)
        self.groupBox_4.setGeometry(QtCore.QRect(10, 10, 421, 111))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.groupBox_4.setFont(font)
        self.groupBox_4.setObjectName(_fromUtf8("groupBox_4"))
        self.data_type1 = QtGui.QRadioButton(self.groupBox_4)
        self.data_type1.setGeometry(QtCore.QRect(20, 30, 21, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.data_type1.setFont(font)
        self.data_type1.setText(_fromUtf8(""))
        self.data_type1.setChecked(True)
        self.data_type1.setObjectName(_fromUtf8("data_type1"))
        self.data_type2 = QtGui.QRadioButton(self.groupBox_4)
        self.data_type2.setGeometry(QtCore.QRect(20, 70, 21, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.data_type2.setFont(font)
        self.data_type2.setText(_fromUtf8(""))
        self.data_type2.setObjectName(_fromUtf8("data_type2"))
        self.label_26 = QtGui.QLabel(self.groupBox_4)
        self.label_26.setGeometry(QtCore.QRect(40, 30, 181, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_26.setFont(font)
        self.label_26.setObjectName(_fromUtf8("label_26"))
        self.label_27 = QtGui.QLabel(self.groupBox_4)
        self.label_27.setGeometry(QtCore.QRect(40, 70, 231, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_27.setFont(font)
        self.label_27.setObjectName(_fromUtf8("label_27"))
        self.widget_title = QtGui.QWidget(gas_drilling_analyse_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 431, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 391, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(390, 0, 41, 31))
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

        self.retranslateUi(gas_drilling_analyse_dlg)
        QtCore.QMetaObject.connectSlotsByName(gas_drilling_analyse_dlg)
        gas_drilling_analyse_dlg.setTabOrder(self.data_type1, self.data_type2)
        gas_drilling_analyse_dlg.setTabOrder(self.data_type2, self.save)

    def retranslateUi(self, gas_drilling_analyse_dlg):
        gas_drilling_analyse_dlg.setWindowTitle(_translate("gas_drilling_analyse_dlg", "抽采率优化分析", None))
        self.save.setText(_translate("gas_drilling_analyse_dlg", "分析", None))
        self.groupBox_4.setTitle(_translate("gas_drilling_analyse_dlg", "趋势分析", None))
        self.label_26.setText(_translate("gas_drilling_analyse_dlg", "<html><head/><body><p>抽采率η与R<span style=\" vertical-align:sub;\">0</span>/r<span style=\" vertical-align:sub;\">0</span>的关系</p></body></html>", None))
        self.label_27.setText(_translate("gas_drilling_analyse_dlg", "<html><head/><body><p>抽采率η与抽采时间T<span style=\" vertical-align:sub;\">0</span>的关系</p></body></html>", None))
        self.lab_Ico.setText(_translate("gas_drilling_analyse_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
