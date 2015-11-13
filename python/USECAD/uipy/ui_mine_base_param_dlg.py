# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui\mine_base_param_dlg.ui'
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

class Ui_mine_base_param_dlg(object):
    def setupUi(self, mine_base_param_dlg):
        mine_base_param_dlg.setObjectName(_fromUtf8("mine_base_param_dlg"))
        mine_base_param_dlg.resize(384, 222)
        self.hydr_geo = QtGui.QComboBox(mine_base_param_dlg)
        self.hydr_geo.setGeometry(QtCore.QRect(270, 130, 101, 20))
        self.hydr_geo.setObjectName(_fromUtf8("hydr_geo"))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.mineName_label_7 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_7.setGeometry(QtCore.QRect(10, 50, 51, 21))
        self.mineName_label_7.setObjectName(_fromUtf8("mineName_label_7"))
        self.label_4 = QtGui.QLabel(mine_base_param_dlg)
        self.label_4.setGeometry(QtCore.QRect(190, 130, 81, 21))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.mineName_label = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label.setGeometry(QtCore.QRect(11, 10, 54, 16))
        self.mineName_label.setObjectName(_fromUtf8("mineName_label"))
        self.ground_cond = QtGui.QCheckBox(mine_base_param_dlg)
        self.ground_cond.setGeometry(QtCore.QRect(210, 10, 161, 16))
        self.ground_cond.setObjectName(_fromUtf8("ground_cond"))
        self.mineName_label_3 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_3.setGeometry(QtCore.QRect(200, 90, 54, 16))
        self.mineName_label_3.setObjectName(_fromUtf8("mineName_label_3"))
        self.base = QtGui.QComboBox(mine_base_param_dlg)
        self.base.setGeometry(QtCore.QRect(70, 90, 111, 22))
        self.base.setObjectName(_fromUtf8("base"))
        self.label_3 = QtGui.QLabel(mine_base_param_dlg)
        self.label_3.setGeometry(QtCore.QRect(10, 130, 71, 21))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.name = QtGui.QLineEdit(mine_base_param_dlg)
        self.name.setGeometry(QtCore.QRect(70, 10, 131, 20))
        self.name.setObjectName(_fromUtf8("name"))
        self.city = QtGui.QLineEdit(mine_base_param_dlg)
        self.city.setGeometry(QtCore.QRect(260, 50, 41, 20))
        self.city.setObjectName(_fromUtf8("city"))
        self.province = QtGui.QLineEdit(mine_base_param_dlg)
        self.province.setGeometry(QtCore.QRect(190, 50, 41, 20))
        self.province.setObjectName(_fromUtf8("province"))
        self.region = QtGui.QComboBox(mine_base_param_dlg)
        self.region.setGeometry(QtCore.QRect(260, 90, 111, 22))
        self.region.setObjectName(_fromUtf8("region"))
        self.mineName_label_4 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_4.setGeometry(QtCore.QRect(150, 50, 54, 16))
        self.mineName_label_4.setObjectName(_fromUtf8("mineName_label_4"))
        self.mineName_label_2 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_2.setGeometry(QtCore.QRect(10, 90, 54, 16))
        self.mineName_label_2.setObjectName(_fromUtf8("mineName_label_2"))
        self.mineName_label_8 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_8.setGeometry(QtCore.QRect(120, 50, 31, 21))
        self.mineName_label_8.setObjectName(_fromUtf8("mineName_label_8"))
        self.capacity = QtGui.QLineEdit(mine_base_param_dlg)
        self.capacity.setGeometry(QtCore.QRect(70, 50, 41, 20))
        self.capacity.setObjectName(_fromUtf8("capacity"))
        self.mineName_label_5 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_5.setGeometry(QtCore.QRect(240, 50, 21, 16))
        self.mineName_label_5.setObjectName(_fromUtf8("mineName_label_5"))
        self.topo_geo = QtGui.QComboBox(mine_base_param_dlg)
        self.topo_geo.setGeometry(QtCore.QRect(90, 130, 81, 20))
        self.topo_geo.setObjectName(_fromUtf8("topo_geo"))
        self.topo_geo.addItem(_fromUtf8(""))
        self.topo_geo.addItem(_fromUtf8(""))
        self.topo_geo.addItem(_fromUtf8(""))
        self.mineName_label_6 = QtGui.QLabel(mine_base_param_dlg)
        self.mineName_label_6.setGeometry(QtCore.QRect(310, 50, 61, 16))
        self.mineName_label_6.setObjectName(_fromUtf8("mineName_label_6"))
        self.save = QtGui.QPushButton(mine_base_param_dlg)
        self.save.setGeometry(QtCore.QRect(140, 170, 101, 41))
        self.save.setObjectName(_fromUtf8("save"))
        self.cancel = QtGui.QPushButton(mine_base_param_dlg)
        self.cancel.setGeometry(QtCore.QRect(270, 170, 101, 41))
        self.cancel.setObjectName(_fromUtf8("cancel"))
        self.next = QtGui.QPushButton(mine_base_param_dlg)
        self.next.setGeometry(QtCore.QRect(10, 170, 101, 41))
        self.next.setObjectName(_fromUtf8("next"))

        self.retranslateUi(mine_base_param_dlg)
        QtCore.QMetaObject.connectSlotsByName(mine_base_param_dlg)

    def retranslateUi(self, mine_base_param_dlg):
        mine_base_param_dlg.setWindowTitle(_translate("mine_base_param_dlg", "请输入目标矿井基本信息", None))
        self.hydr_geo.setItemText(0, _translate("mine_base_param_dlg", "复杂", None))
        self.hydr_geo.setItemText(1, _translate("mine_base_param_dlg", "极复杂", None))
        self.hydr_geo.setItemText(2, _translate("mine_base_param_dlg", "中等", None))
        self.hydr_geo.setItemText(3, _translate("mine_base_param_dlg", "简单", None))
        self.mineName_label_7.setText(_translate("mine_base_param_dlg", "矿井产能", None))
        self.label_4.setText(_translate("mine_base_param_dlg", "水文地质条件", None))
        self.mineName_label.setText(_translate("mine_base_param_dlg", "矿井名称", None))
        self.ground_cond.setText(_translate("mine_base_param_dlg", "是否具备地面井开发条件", None))
        self.mineName_label_3.setText(_translate("mine_base_param_dlg", "所在矿区", None))
        self.label_3.setText(_translate("mine_base_param_dlg", "地形地貌特征", None))
        self.name.setToolTip(_translate("mine_base_param_dlg", "<html><head/><body><p>输入矿井名称</p></body></html>", None))
        self.name.setWhatsThis(_translate("mine_base_param_dlg", "<html><head/><body><p>用户名</p></body></html>", None))
        self.mineName_label_4.setText(_translate("mine_base_param_dlg", "所在地", None))
        self.mineName_label_2.setText(_translate("mine_base_param_dlg", "煤炭基地", None))
        self.mineName_label_8.setText(_translate("mine_base_param_dlg", "Mt/a", None))
        self.mineName_label_5.setText(_translate("mine_base_param_dlg", "省", None))
        self.topo_geo.setItemText(0, _translate("mine_base_param_dlg", "复杂", None))
        self.topo_geo.setItemText(1, _translate("mine_base_param_dlg", "中等", None))
        self.topo_geo.setItemText(2, _translate("mine_base_param_dlg", "简单", None))
        self.mineName_label_6.setText(_translate("mine_base_param_dlg", "市（地区）", None))
        self.save.setText(_translate("mine_base_param_dlg", "保  存", None))
        self.cancel.setText(_translate("mine_base_param_dlg", "取  消", None))
        self.next.setText(_translate("mine_base_param_dlg", "下 一 步", None))

