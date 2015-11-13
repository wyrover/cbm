# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\mine_gas_flow_predict_dlg.ui'
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

class Ui_mine_gas_flow_predict_dlg(object):
    def setupUi(self, mine_gas_flow_predict_dlg):
        mine_gas_flow_predict_dlg.setObjectName(_fromUtf8("mine_gas_flow_predict_dlg"))
        mine_gas_flow_predict_dlg.resize(306, 291)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_gas_flow_predict_dlg.setWindowIcon(icon)
        self.label = QtGui.QLabel(mine_gas_flow_predict_dlg)
        self.label.setGeometry(QtCore.QRect(10, 10, 171, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.K1_gas = QtGui.QLineEdit(mine_gas_flow_predict_dlg)
        self.K1_gas.setGeometry(QtCore.QRect(180, 10, 51, 20))
        self.K1_gas.setObjectName(_fromUtf8("K1_gas"))
        self.k1_help = QtGui.QPushButton(mine_gas_flow_predict_dlg)
        self.k1_help.setGeometry(QtCore.QRect(240, 10, 51, 21))
        self.k1_help.setObjectName(_fromUtf8("k1_help"))
        self.label_2 = QtGui.QLabel(mine_gas_flow_predict_dlg)
        self.label_2.setGeometry(QtCore.QRect(10, 40, 171, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.k2_help = QtGui.QPushButton(mine_gas_flow_predict_dlg)
        self.k2_help.setGeometry(QtCore.QRect(240, 40, 51, 21))
        self.k2_help.setObjectName(_fromUtf8("k2_help"))
        self.K2_gas = QtGui.QLineEdit(mine_gas_flow_predict_dlg)
        self.K2_gas.setGeometry(QtCore.QRect(180, 40, 51, 20))
        self.K2_gas.setObjectName(_fromUtf8("K2_gas"))
        self.groupBox = QtGui.QGroupBox(mine_gas_flow_predict_dlg)
        self.groupBox.setGeometry(QtCore.QRect(10, 80, 281, 141))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.work_area_cacl = QtGui.QPushButton(self.groupBox)
        self.work_area_cacl.setGeometry(QtCore.QRect(200, 110, 51, 21))
        self.work_area_cacl.setObjectName(_fromUtf8("work_area_cacl"))
        self.assign = QtGui.QPushButton(self.groupBox)
        self.assign.setGeometry(QtCore.QRect(200, 50, 51, 21))
        self.assign.setObjectName(_fromUtf8("assign"))
        self.label_4 = QtGui.QLabel(self.groupBox)
        self.label_4.setGeometry(QtCore.QRect(30, 50, 51, 21))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.coal = QtGui.QComboBox(self.groupBox)
        self.coal.setGeometry(QtCore.QRect(90, 50, 101, 22))
        self.coal.setObjectName(_fromUtf8("coal"))
        self.label_5 = QtGui.QLabel(self.groupBox)
        self.label_5.setGeometry(QtCore.QRect(30, 80, 61, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.work_area = QtGui.QComboBox(self.groupBox)
        self.work_area.setGeometry(QtCore.QRect(90, 20, 101, 22))
        self.work_area.setObjectName(_fromUtf8("work_area"))
        self.work_area_qr = QtGui.QLineEdit(self.groupBox)
        self.work_area_qr.setGeometry(QtCore.QRect(120, 110, 51, 20))
        self.work_area_qr.setObjectName(_fromUtf8("work_area_qr"))
        self.design_work_area = QtGui.QPushButton(self.groupBox)
        self.design_work_area.setGeometry(QtCore.QRect(200, 20, 51, 21))
        self.design_work_area.setObjectName(_fromUtf8("design_work_area"))
        self.work_area_A = QtGui.QLineEdit(self.groupBox)
        self.work_area_A.setGeometry(QtCore.QRect(100, 80, 91, 20))
        self.work_area_A.setObjectName(_fromUtf8("work_area_A"))
        self.label_3 = QtGui.QLabel(self.groupBox)
        self.label_3.setGeometry(QtCore.QRect(30, 20, 51, 21))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.label_6 = QtGui.QLabel(self.groupBox)
        self.label_6.setGeometry(QtCore.QRect(30, 110, 91, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.groupBox_2 = QtGui.QGroupBox(mine_gas_flow_predict_dlg)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 230, 181, 51))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.cacl = QtGui.QPushButton(self.groupBox_2)
        self.cacl.setGeometry(QtCore.QRect(120, 20, 51, 21))
        self.cacl.setObjectName(_fromUtf8("cacl"))
        self.qr = QtGui.QLineEdit(self.groupBox_2)
        self.qr.setGeometry(QtCore.QRect(10, 20, 101, 20))
        self.qr.setObjectName(_fromUtf8("qr"))
        self.save = QtGui.QPushButton(mine_gas_flow_predict_dlg)
        self.save.setGeometry(QtCore.QRect(200, 230, 81, 51))
        self.save.setObjectName(_fromUtf8("save"))

        self.retranslateUi(mine_gas_flow_predict_dlg)
        QtCore.QMetaObject.connectSlotsByName(mine_gas_flow_predict_dlg)

    def retranslateUi(self, mine_gas_flow_predict_dlg):
        mine_gas_flow_predict_dlg.setWindowTitle(_translate("mine_gas_flow_predict_dlg", "矿井相对瓦斯涌出量预测", None))
        self.label.setText(_translate("mine_gas_flow_predict_dlg", "生产采区采空区瓦斯涌出系数K\'", None))
        self.k1_help.setText(_translate("mine_gas_flow_predict_dlg", "帮 助", None))
        self.label_2.setText(_translate("mine_gas_flow_predict_dlg", "已采采区采空区瓦斯涌出系数K\'\'", None))
        self.k2_help.setText(_translate("mine_gas_flow_predict_dlg", "帮 助", None))
        self.groupBox.setTitle(_translate("mine_gas_flow_predict_dlg", ">>生产采区参数", None))
        self.work_area_cacl.setText(_translate("mine_gas_flow_predict_dlg", "计 算", None))
        self.assign.setText(_translate("mine_gas_flow_predict_dlg", "布 置", None))
        self.label_4.setText(_translate("mine_gas_flow_predict_dlg", "开采煤层", None))
        self.label_5.setText(_translate("mine_gas_flow_predict_dlg", "平均日产量", None))
        self.design_work_area.setText(_translate("mine_gas_flow_predict_dlg", "设 计", None))
        self.label_3.setText(_translate("mine_gas_flow_predict_dlg", "生产采区", None))
        self.label_6.setText(_translate("mine_gas_flow_predict_dlg", "相对瓦斯涌出量", None))
        self.groupBox_2.setTitle(_translate("mine_gas_flow_predict_dlg", ">>矿井相对瓦斯涌出量预测结果", None))
        self.cacl.setText(_translate("mine_gas_flow_predict_dlg", "预 测", None))
        self.save.setText(_translate("mine_gas_flow_predict_dlg", "保 存", None))

import usecad_rc
