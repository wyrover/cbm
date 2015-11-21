# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\gas_design_dlg.ui'
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
        gas_design_dlg.resize(401, 451)
        font = QtGui.QFont()
        font.setPointSize(12)
        gas_design_dlg.setFont(font)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        gas_design_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(gas_design_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 401, 421))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.label_9 = QtGui.QLabel(self.widget_main)
        self.label_9.setGeometry(QtCore.QRect(350, 60, 41, 25))
        self.label_9.setObjectName(_fromUtf8("label_9"))
        self.coal = QtGui.QComboBox(self.widget_main)
        self.coal.setGeometry(QtCore.QRect(100, 20, 131, 25))
        self.coal.setObjectName(_fromUtf8("coal"))
        self.label_11 = QtGui.QLabel(self.widget_main)
        self.label_11.setGeometry(QtCore.QRect(20, 280, 171, 25))
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.thick = QtGui.QLineEdit(self.widget_main)
        self.thick.setGeometry(QtCore.QRect(100, 60, 61, 25))
        self.thick.setObjectName(_fromUtf8("thick"))
        self.save = QtGui.QPushButton(self.widget_main)
        self.save.setGeometry(QtCore.QRect(290, 20, 91, 31))
        self.save.setObjectName(_fromUtf8("save"))
        self.technology = QtGui.QListWidget(self.widget_main)
        self.technology.setGeometry(QtCore.QRect(20, 130, 361, 131))
        self.technology.setObjectName(_fromUtf8("technology"))
        self.label_6 = QtGui.QLabel(self.widget_main)
        self.label_6.setGeometry(QtCore.QRect(20, 60, 71, 25))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.del_design = QtGui.QPushButton(self.widget_main)
        self.del_design.setGeometry(QtCore.QRect(220, 310, 51, 25))
        self.del_design.setObjectName(_fromUtf8("del_design"))
        self.label = QtGui.QLabel(self.widget_main)
        self.label.setGeometry(QtCore.QRect(20, 20, 71, 25))
        self.label.setObjectName(_fromUtf8("label"))
        self.add_design = QtGui.QPushButton(self.widget_main)
        self.add_design.setGeometry(QtCore.QRect(160, 310, 51, 25))
        self.add_design.setObjectName(_fromUtf8("add_design"))
        self.label_8 = QtGui.QLabel(self.widget_main)
        self.label_8.setGeometry(QtCore.QRect(20, 100, 171, 25))
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.label_7 = QtGui.QLabel(self.widget_main)
        self.label_7.setGeometry(QtCore.QRect(170, 60, 31, 25))
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.go = QtGui.QPushButton(self.widget_main)
        self.go.setGeometry(QtCore.QRect(110, 360, 181, 51))
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/go.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.go.setIcon(icon1)
        self.go.setObjectName(_fromUtf8("go"))
        self.dip_angle = QtGui.QLineEdit(self.widget_main)
        self.dip_angle.setGeometry(QtCore.QRect(280, 60, 61, 25))
        self.dip_angle.setObjectName(_fromUtf8("dip_angle"))
        self.label_10 = QtGui.QLabel(self.widget_main)
        self.label_10.setGeometry(QtCore.QRect(210, 60, 71, 25))
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.design = QtGui.QComboBox(self.widget_main)
        self.design.setGeometry(QtCore.QRect(20, 310, 131, 25))
        self.design.setObjectName(_fromUtf8("design"))
        self.widget_title = QtGui.QWidget(gas_design_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 401, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 311, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(360, 0, 41, 31))
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

        self.retranslateUi(gas_design_dlg)
        QtCore.QMetaObject.connectSlotsByName(gas_design_dlg)
        gas_design_dlg.setTabOrder(self.coal, self.thick)
        gas_design_dlg.setTabOrder(self.thick, self.dip_angle)
        gas_design_dlg.setTabOrder(self.dip_angle, self.technology)
        gas_design_dlg.setTabOrder(self.technology, self.design)
        gas_design_dlg.setTabOrder(self.design, self.add_design)
        gas_design_dlg.setTabOrder(self.add_design, self.del_design)
        gas_design_dlg.setTabOrder(self.del_design, self.go)
        gas_design_dlg.setTabOrder(self.go, self.save)

    def retranslateUi(self, gas_design_dlg):
        gas_design_dlg.setWindowTitle(_translate("gas_design_dlg", "煤层气抽采技术辅助设计", None))
        self.label_9.setText(_translate("gas_design_dlg", "<html><head/><body><p>(°)</p></body></html>", None))
        self.label_11.setText(_translate("gas_design_dlg", "请选择已有的设计方案", None))
        self.save.setText(_translate("gas_design_dlg", "保  存", None))
        self.label_6.setText(_translate("gas_design_dlg", "煤层厚度", None))
        self.del_design.setText(_translate("gas_design_dlg", "删除", None))
        self.label.setText(_translate("gas_design_dlg", "煤层列表", None))
        self.add_design.setText(_translate("gas_design_dlg", "增加", None))
        self.label_8.setText(_translate("gas_design_dlg", "请选择相应的抽采技术", None))
        self.label_7.setText(_translate("gas_design_dlg", "<html><head/><body><p>(m)</p></body></html>", None))
        self.go.setToolTip(_translate("gas_design_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))
        self.go.setText(_translate("gas_design_dlg", "开始设计—>Go!", None))
        self.label_10.setText(_translate("gas_design_dlg", "煤层倾角", None))
        self.lab_Ico.setText(_translate("gas_design_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
