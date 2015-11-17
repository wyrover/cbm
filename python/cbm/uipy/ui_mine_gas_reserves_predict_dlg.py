# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\mine_gas_reserves_predict_dlg.ui'
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

class Ui_mine_gas_reserves_predict_dlg(object):
    def setupUi(self, mine_gas_reserves_predict_dlg):
        mine_gas_reserves_predict_dlg.setObjectName(_fromUtf8("mine_gas_reserves_predict_dlg"))
        mine_gas_reserves_predict_dlg.resize(360, 170)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_reserves_predict_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(mine_gas_reserves_predict_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 361, 141))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.label_2 = QtGui.QLabel(self.widget_main)
        self.label_2.setGeometry(QtCore.QRect(20, 60, 131, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.gas_cacl = QtGui.QPushButton(self.widget_main)
        self.gas_cacl.setGeometry(QtCore.QRect(260, 20, 75, 22))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.gas_cacl.setFont(font)
        self.gas_cacl.setObjectName(_fromUtf8("gas_cacl"))
        self.label = QtGui.QLabel(self.widget_main)
        self.label.setGeometry(QtCore.QRect(20, 20, 121, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))
        self.pump_wc = QtGui.QLineEdit(self.widget_main)
        self.pump_wc.setGeometry(QtCore.QRect(152, 60, 91, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.pump_wc.setFont(font)
        self.pump_wc.setObjectName(_fromUtf8("pump_wc"))
        self.ok = QtGui.QPushButton(self.widget_main)
        self.ok.setGeometry(QtCore.QRect(130, 100, 71, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.ok.setFont(font)
        self.ok.setObjectName(_fromUtf8("ok"))
        self.reserve_gas = QtGui.QLineEdit(self.widget_main)
        self.reserve_gas.setGeometry(QtCore.QRect(152, 20, 91, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.reserve_gas.setFont(font)
        self.reserve_gas.setObjectName(_fromUtf8("reserve_gas"))
        self.pump_wc_cacl = QtGui.QPushButton(self.widget_main)
        self.pump_wc_cacl.setGeometry(QtCore.QRect(260, 60, 75, 22))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.pump_wc_cacl.setFont(font)
        self.pump_wc_cacl.setObjectName(_fromUtf8("pump_wc_cacl"))
        self.widget_title = QtGui.QWidget(mine_gas_reserves_predict_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 361, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 271, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(320, 0, 41, 31))
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

        self.retranslateUi(mine_gas_reserves_predict_dlg)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_reserves_predict_dlg)

    def retranslateUi(self, mine_gas_reserves_predict_dlg):
        mine_gas_reserves_predict_dlg.setWindowTitle(_translate("mine_gas_reserves_predict_dlg", "矿井瓦斯储量及可抽量预测", None))
        self.label_2.setText(_translate("mine_gas_reserves_predict_dlg", "矿井可抽瓦斯量", None))
        self.gas_cacl.setText(_translate("mine_gas_reserves_predict_dlg", "计 算", None))
        self.label.setText(_translate("mine_gas_reserves_predict_dlg", "矿井瓦斯储量", None))
        self.ok.setText(_translate("mine_gas_reserves_predict_dlg", "确 定", None))
        self.pump_wc_cacl.setText(_translate("mine_gas_reserves_predict_dlg", "计 算", None))
        self.lab_Ico.setText(_translate("mine_gas_reserves_predict_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
