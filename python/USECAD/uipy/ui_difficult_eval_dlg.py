# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\difficult_eval_dlg.ui'
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
        difficult_eval_dlg.resize(314, 206)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        difficult_eval_dlg.setWindowIcon(icon)
        self.coal = QtGui.QComboBox(difficult_eval_dlg)
        self.coal.setGeometry(QtCore.QRect(70, 10, 111, 22))
        self.coal.setObjectName(_fromUtf8("coal"))
        self.label = QtGui.QLabel(difficult_eval_dlg)
        self.label.setGeometry(QtCore.QRect(10, 10, 51, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_14 = QtGui.QLabel(difficult_eval_dlg)
        self.label_14.setGeometry(QtCore.QRect(10, 50, 41, 16))
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.gas_penetration = QtGui.QLineEdit(difficult_eval_dlg)
        self.gas_penetration.setGeometry(QtCore.QRect(50, 50, 61, 20))
        self.gas_penetration.setObjectName(_fromUtf8("gas_penetration"))
        self.permeability_lambda = QtGui.QLineEdit(difficult_eval_dlg)
        self.permeability_lambda.setGeometry(QtCore.QRect(200, 50, 71, 20))
        self.permeability_lambda.setObjectName(_fromUtf8("permeability_lambda"))
        self.label_15 = QtGui.QLabel(difficult_eval_dlg)
        self.label_15.setGeometry(QtCore.QRect(130, 50, 61, 20))
        self.label_15.setObjectName(_fromUtf8("label_15"))
        self.decay_alpha = QtGui.QLineEdit(difficult_eval_dlg)
        self.decay_alpha.setGeometry(QtCore.QRect(120, 80, 71, 20))
        self.decay_alpha.setObjectName(_fromUtf8("decay_alpha"))
        self.label_16 = QtGui.QLabel(difficult_eval_dlg)
        self.label_16.setGeometry(QtCore.QRect(10, 80, 101, 21))
        self.label_16.setObjectName(_fromUtf8("label_16"))
        self.eval_proof = QtGui.QPushButton(difficult_eval_dlg)
        self.eval_proof.setGeometry(QtCore.QRect(220, 80, 81, 23))
        self.eval_proof.setObjectName(_fromUtf8("eval_proof"))
        self.label_2 = QtGui.QLabel(difficult_eval_dlg)
        self.label_2.setGeometry(QtCore.QRect(10, 110, 161, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.eval_difficult_value = QtGui.QComboBox(difficult_eval_dlg)
        self.eval_difficult_value.setGeometry(QtCore.QRect(170, 110, 131, 22))
        self.eval_difficult_value.setObjectName(_fromUtf8("eval_difficult_value"))
        self.eval_difficult_value.addItem(_fromUtf8(""))
        self.eval_difficult_value.addItem(_fromUtf8(""))
        self.eval_difficult_value.addItem(_fromUtf8(""))
        self.eval_difficult_value.addItem(_fromUtf8(""))
        self.eval_difficult_value.addItem(_fromUtf8(""))
        self.eval_difficult_value.addItem(_fromUtf8(""))
        self.eval = QtGui.QPushButton(difficult_eval_dlg)
        self.eval.setGeometry(QtCore.QRect(30, 160, 101, 41))
        self.eval.setObjectName(_fromUtf8("eval"))
        self.cancel = QtGui.QPushButton(difficult_eval_dlg)
        self.cancel.setGeometry(QtCore.QRect(180, 160, 111, 41))
        self.cancel.setObjectName(_fromUtf8("cancel"))

        self.retranslateUi(difficult_eval_dlg)
        QtCore.QMetaObject.connectSlotsByName(difficult_eval_dlg)

    def retranslateUi(self, difficult_eval_dlg):
        difficult_eval_dlg.setWindowTitle(_translate("difficult_eval_dlg", "煤层气抽采难易程度评价", None))
        self.label.setText(_translate("difficult_eval_dlg", "煤层列表", None))
        self.label_14.setText(_translate("difficult_eval_dlg", "<html><head/><body><p>渗透率</p></body></html>", None))
        self.label_15.setText(_translate("difficult_eval_dlg", "<html><head/><body><p>透气性系数</p></body></html>", None))
        self.label_16.setText(_translate("difficult_eval_dlg", "<html><head/><body><p>钻孔流量衰减系数</p></body></html>", None))
        self.eval_proof.setText(_translate("difficult_eval_dlg", "评价依据", None))
        self.label_2.setText(_translate("difficult_eval_dlg", "煤层气抽采难易程度评价结果", None))
        self.eval_difficult_value.setItemText(0, _translate("difficult_eval_dlg", "容易抽采~较难抽采", None))
        self.eval_difficult_value.setItemText(1, _translate("difficult_eval_dlg", "可以抽采~较难抽采", None))
        self.eval_difficult_value.setItemText(2, _translate("difficult_eval_dlg", "容易抽采~可以抽采", None))
        self.eval_difficult_value.setItemText(3, _translate("difficult_eval_dlg", "较难抽采", None))
        self.eval_difficult_value.setItemText(4, _translate("difficult_eval_dlg", "可以抽采", None))
        self.eval_difficult_value.setItemText(5, _translate("difficult_eval_dlg", "容易抽采", None))
        self.eval.setText(_translate("difficult_eval_dlg", "评 价 && 保 存", None))
        self.cancel.setText(_translate("difficult_eval_dlg", "取 消", None))

import usecad_rc
