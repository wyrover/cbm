# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\difficult_eval_dlg.ui'
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

class Ui_difficult_eval_dlg(object):
    def setupUi(self, difficult_eval_dlg):
        difficult_eval_dlg.setObjectName(_fromUtf8("difficult_eval_dlg"))
        difficult_eval_dlg.resize(470, 261)
        font = QtGui.QFont()
        font.setPointSize(12)
        difficult_eval_dlg.setFont(font)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        difficult_eval_dlg.setWindowIcon(icon)
        self.widget_main = QtGui.QWidget(difficult_eval_dlg)
        self.widget_main.setGeometry(QtCore.QRect(0, 30, 471, 231))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.cancel = QtGui.QPushButton(self.widget_main)
        self.cancel.setGeometry(QtCore.QRect(260, 180, 121, 41))
        self.cancel.setObjectName(_fromUtf8("cancel"))
        self.permeability_lambda = QtGui.QLineEdit(self.widget_main)
        self.permeability_lambda.setGeometry(QtCore.QRect(400, 70, 61, 31))
        self.permeability_lambda.setObjectName(_fromUtf8("permeability_lambda"))
        self.label_2 = QtGui.QLabel(self.widget_main)
        self.label_2.setGeometry(QtCore.QRect(10, 120, 221, 31))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.label_14 = QtGui.QLabel(self.widget_main)
        self.label_14.setGeometry(QtCore.QRect(290, 20, 51, 31))
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.label_16 = QtGui.QLabel(self.widget_main)
        self.label_16.setGeometry(QtCore.QRect(10, 70, 141, 31))
        self.label_16.setObjectName(_fromUtf8("label_16"))
        self.eval_proof = QtGui.QPushButton(self.widget_main)
        self.eval_proof.setGeometry(QtCore.QRect(220, 70, 81, 31))
        self.eval_proof.setObjectName(_fromUtf8("eval_proof"))
        self.permeability_k = QtGui.QLineEdit(self.widget_main)
        self.permeability_k.setGeometry(QtCore.QRect(350, 20, 61, 31))
        self.permeability_k.setObjectName(_fromUtf8("permeability_k"))
        self.eval = QtGui.QPushButton(self.widget_main)
        self.eval.setGeometry(QtCore.QRect(100, 180, 121, 41))
        self.eval.setObjectName(_fromUtf8("eval"))
        self.decay_alpha = QtGui.QLineEdit(self.widget_main)
        self.decay_alpha.setGeometry(QtCore.QRect(150, 70, 61, 31))
        self.decay_alpha.setObjectName(_fromUtf8("decay_alpha"))
        self.eval_difficult = QtGui.QComboBox(self.widget_main)
        self.eval_difficult.setGeometry(QtCore.QRect(230, 120, 231, 31))
        self.eval_difficult.setObjectName(_fromUtf8("eval_difficult"))
        self.eval_difficult.addItem(_fromUtf8(""))
        self.eval_difficult.addItem(_fromUtf8(""))
        self.eval_difficult.addItem(_fromUtf8(""))
        self.eval_difficult.addItem(_fromUtf8(""))
        self.eval_difficult.addItem(_fromUtf8(""))
        self.eval_difficult.addItem(_fromUtf8(""))
        self.coal = QtGui.QComboBox(self.widget_main)
        self.coal.setGeometry(QtCore.QRect(80, 20, 201, 31))
        self.coal.setObjectName(_fromUtf8("coal"))
        self.label_15 = QtGui.QLabel(self.widget_main)
        self.label_15.setGeometry(QtCore.QRect(310, 70, 91, 31))
        self.label_15.setObjectName(_fromUtf8("label_15"))
        self.label = QtGui.QLabel(self.widget_main)
        self.label.setGeometry(QtCore.QRect(10, 20, 81, 31))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_3 = QtGui.QLabel(self.widget_main)
        self.label_3.setGeometry(QtCore.QRect(420, 20, 41, 31))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.widget_title = QtGui.QWidget(difficult_eval_dlg)
        self.widget_title.setGeometry(QtCore.QRect(0, 0, 471, 31))
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
        self.lab_Title.setGeometry(QtCore.QRect(40, 0, 381, 31))
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
        self.btnMenu_Close.setGeometry(QtCore.QRect(430, 0, 41, 31))
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

        self.retranslateUi(difficult_eval_dlg)
        QtCore.QMetaObject.connectSlotsByName(difficult_eval_dlg)

    def retranslateUi(self, difficult_eval_dlg):
        difficult_eval_dlg.setWindowTitle(_translate("difficult_eval_dlg", "煤层气抽采难易程度评价", None))
        self.cancel.setText(_translate("difficult_eval_dlg", "取 消", None))
        self.label_2.setText(_translate("difficult_eval_dlg", "煤层气抽采难易程度评价结果", None))
        self.label_14.setText(_translate("difficult_eval_dlg", "<html><head/><body><p>渗透率</p></body></html>", None))
        self.label_16.setText(_translate("difficult_eval_dlg", "<html><head/><body><p>钻孔流量衰减系数</p></body></html>", None))
        self.eval_proof.setText(_translate("difficult_eval_dlg", "评价依据", None))
        self.eval.setText(_translate("difficult_eval_dlg", "评 价 && 保 存", None))
        self.eval_difficult.setItemText(0, _translate("difficult_eval_dlg", "容易抽采~较难抽采", None))
        self.eval_difficult.setItemText(1, _translate("difficult_eval_dlg", "可以抽采~较难抽采", None))
        self.eval_difficult.setItemText(2, _translate("difficult_eval_dlg", "容易抽采~可以抽采", None))
        self.eval_difficult.setItemText(3, _translate("difficult_eval_dlg", "较难抽采", None))
        self.eval_difficult.setItemText(4, _translate("difficult_eval_dlg", "可以抽采", None))
        self.eval_difficult.setItemText(5, _translate("difficult_eval_dlg", "容易抽采", None))
        self.label_15.setText(_translate("difficult_eval_dlg", "<html><head/><body><p>透气性系数</p></body></html>", None))
        self.label.setText(_translate("difficult_eval_dlg", "煤层列表", None))
        self.label_3.setText(_translate("difficult_eval_dlg", "(mD)", None))
        self.lab_Ico.setText(_translate("difficult_eval_dlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", None))

import usecad_rc
