# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\mine_gas_reserves_predict_dlg1.ui'
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

class Ui_mine_gas_reserves_predict_dlg1(object):
    def setupUi(self, mine_gas_reserves_predict_dlg1):
        mine_gas_reserves_predict_dlg1.setObjectName(_fromUtf8("mine_gas_reserves_predict_dlg1"))
        mine_gas_reserves_predict_dlg1.resize(440, 261)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_reserves_predict_dlg1.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(mine_gas_reserves_predict_dlg1)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 441, 231))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.rock_gas_k2 = QtGui.QLineEdit(self.widget_main)
        self.rock_gas_k2.setGeometry(QtCore.QRect(290, 100, 101, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.rock_gas_k2.setFont(font)
        self.rock_gas_k2.setObjectName(_fromUtf8("rock_gas_k2"))
        self.reserve_w1 = QtGui.QLineEdit(self.widget_main)
        self.reserve_w1.setGeometry(QtCore.QRect(290, 20, 101, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.reserve_w1.setFont(font)
        self.reserve_w1.setObjectName(_fromUtf8("reserve_w1"))
        self.reserve_w2 = QtGui.QLineEdit(self.widget_main)
        self.reserve_w2.setGeometry(QtCore.QRect(290, 60, 101, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.reserve_w2.setFont(font)
        self.reserve_w2.setObjectName(_fromUtf8("reserve_w2"))
        self.reserve_w3 = QtGui.QLineEdit(self.widget_main)
        self.reserve_w3.setGeometry(QtCore.QRect(290, 140, 101, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.reserve_w3.setFont(font)
        self.reserve_w3.setObjectName(_fromUtf8("reserve_w3"))
        self.label_2 = QtGui.QLabel(self.widget_main)
        self.label_2.setGeometry(QtCore.QRect(20, 60, 271, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.label_4 = QtGui.QLabel(self.widget_main)
        self.label_4.setGeometry(QtCore.QRect(20, 140, 271, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_4.setFont(font)
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.label = QtGui.QLabel(self.widget_main)
        self.label.setGeometry(QtCore.QRect(20, 20, 181, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))
        self.label_3 = QtGui.QLabel(self.widget_main)
        self.label_3.setGeometry(QtCore.QRect(20, 100, 211, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_3.setFont(font)
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.ok = QtGui.QPushButton(self.widget_main)
        self.ok.setGeometry(QtCore.QRect(170, 190, 81, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.ok.setFont(font)
        self.ok.setObjectName(_fromUtf8("ok"))
        self.w1_cacl = QtGui.QPushButton(self.widget_main)
        self.w1_cacl.setGeometry(QtCore.QRect(400, 20, 25, 25))
        self.w1_cacl.setText(_fromUtf8(""))
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/udpate.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.w1_cacl.setIcon(icon1)
        self.w1_cacl.setFlat(True)
        self.w1_cacl.setObjectName(_fromUtf8("w1_cacl"))
        self.w2_cacl = QtGui.QPushButton(self.widget_main)
        self.w2_cacl.setGeometry(QtCore.QRect(400, 60, 25, 25))
        self.w2_cacl.setText(_fromUtf8(""))
        self.w2_cacl.setIcon(icon1)
        self.w2_cacl.setFlat(True)
        self.w2_cacl.setObjectName(_fromUtf8("w2_cacl"))
        self.w3_cacl = QtGui.QPushButton(self.widget_main)
        self.w3_cacl.setGeometry(QtCore.QRect(400, 140, 25, 25))
        self.w3_cacl.setText(_fromUtf8(""))
        self.w3_cacl.setIcon(icon1)
        self.w3_cacl.setFlat(True)
        self.w3_cacl.setObjectName(_fromUtf8("w3_cacl"))
        self.widget_title = QtGui.QWidget(mine_gas_reserves_predict_dlg1)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 441, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 351, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(400, 0, 41, 31))
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

        self.retranslateUi(mine_gas_reserves_predict_dlg1)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_reserves_predict_dlg1)

    def retranslateUi(self, mine_gas_reserves_predict_dlg1):
        mine_gas_reserves_predict_dlg1.setWindowTitle(_translate("mine_gas_reserves_predict_dlg1", "矿井瓦斯储量计算", None))
        self.label_2.setText(_translate("mine_gas_reserves_predict_dlg1", "受采动影响的不可采煤层瓦斯储量W2", None))
        self.label_4.setText(_translate("mine_gas_reserves_predict_dlg1", "受采动影响的矿井围岩瓦斯储量W3", None))
        self.label.setText(_translate("mine_gas_reserves_predict_dlg1", "可采煤层瓦斯储量W1", None))
        self.label_3.setText(_translate("mine_gas_reserves_predict_dlg1", "矿井围岩瓦斯储量系数K", None))
        self.ok.setText(_translate("mine_gas_reserves_predict_dlg1", "确 定", None))
        self.lab_Ico.setText(_translate("mine_gas_reserves_predict_dlg1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
