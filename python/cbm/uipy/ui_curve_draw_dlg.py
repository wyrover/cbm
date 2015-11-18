# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\curve_draw_dlg.ui'
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

class Ui_curve_draw_dlg(object):
    def setupUi(self, curve_draw_dlg):
        curve_draw_dlg.setObjectName(_fromUtf8("curve_draw_dlg"))
        curve_draw_dlg.resize(341, 184)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        curve_draw_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(curve_draw_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 341, 151))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.draw_curve = QtGui.QPushButton(self.widget_main)
        self.draw_curve.setGeometry(QtCore.QRect(100, 100, 131, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.draw_curve.setFont(font)
        self.draw_curve.setObjectName(_fromUtf8("draw_curve"))
        self.mineName_label_14 = QtGui.QLabel(self.widget_main)
        self.mineName_label_14.setGeometry(QtCore.QRect(260, 20, 71, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_14.setFont(font)
        self.mineName_label_14.setObjectName(_fromUtf8("mineName_label_14"))
        self.mineName_label_13 = QtGui.QLabel(self.widget_main)
        self.mineName_label_13.setGeometry(QtCore.QRect(20, 60, 151, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_13.setFont(font)
        self.mineName_label_13.setObjectName(_fromUtf8("mineName_label_13"))
        self.alpha = QtGui.QLineEdit(self.widget_main)
        self.alpha.setGeometry(QtCore.QRect(190, 60, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.alpha.setFont(font)
        self.alpha.setObjectName(_fromUtf8("alpha"))
        self.mineName_label_12 = QtGui.QLabel(self.widget_main)
        self.mineName_label_12.setGeometry(QtCore.QRect(20, 20, 171, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.mineName_label_12.setFont(font)
        self.mineName_label_12.setObjectName(_fromUtf8("mineName_label_12"))
        self.q0 = QtGui.QLineEdit(self.widget_main)
        self.q0.setGeometry(QtCore.QRect(190, 20, 61, 25))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.q0.setFont(font)
        self.q0.setObjectName(_fromUtf8("q0"))
        self.widget_title = QtGui.QWidget(curve_draw_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 341, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 241, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(300, 0, 41, 31))
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

        self.retranslateUi(curve_draw_dlg)
        QtCore.QMetaObject.connectSlotsByName(curve_draw_dlg)
        curve_draw_dlg.setTabOrder(self.q0, self.alpha)
        curve_draw_dlg.setTabOrder(self.alpha, self.draw_curve)

    def retranslateUi(self, curve_draw_dlg):
        curve_draw_dlg.setWindowTitle(_translate("curve_draw_dlg", "抽采管径大小辅助计算", None))
        self.draw_curve.setText(_translate("curve_draw_dlg", "绘制曲线", None))
        self.mineName_label_14.setText(_translate("curve_draw_dlg", "<html><head/><body><p>(m<span style=\" vertical-align:super;\">3</span>/min)</p></body></html>", None))
        self.mineName_label_13.setText(_translate("curve_draw_dlg", "衰   减    系    数   α", None))
        self.mineName_label_12.setText(_translate("curve_draw_dlg", "<html><head/><body><p>钻孔初始瓦斯涌出量q<span style=\" vertical-align:sub;\">0</span></p></body></html>", None))
        self.lab_Ico.setText(_translate("curve_draw_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
