# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\mine_degin_dlg.ui'
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

class Ui_mine_degin_dlg(object):
    def setupUi(self, mine_degin_dlg):
        mine_degin_dlg.setObjectName(_fromUtf8("mine_degin_dlg"))
        mine_degin_dlg.resize(385, 350)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        mine_degin_dlg.setWindowIcon(icon)
        self.mineName_label_6 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_6.setGeometry(QtCore.QRect(310, 50, 61, 16))
        self.mineName_label_6.setObjectName(_fromUtf8("mineName_label_6"))
        self.mineName_label_5 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_5.setGeometry(QtCore.QRect(240, 50, 21, 16))
        self.mineName_label_5.setObjectName(_fromUtf8("mineName_label_5"))
        self.region = QtGui.QComboBox(mine_degin_dlg)
        self.region.setGeometry(QtCore.QRect(260, 90, 111, 22))
        self.region.setObjectName(_fromUtf8("region"))
        self.base = QtGui.QComboBox(mine_degin_dlg)
        self.base.setGeometry(QtCore.QRect(70, 90, 111, 22))
        self.base.setObjectName(_fromUtf8("base"))
        self.province = QtGui.QLineEdit(mine_degin_dlg)
        self.province.setGeometry(QtCore.QRect(190, 50, 41, 20))
        self.province.setObjectName(_fromUtf8("province"))
        self.city = QtGui.QLineEdit(mine_degin_dlg)
        self.city.setGeometry(QtCore.QRect(260, 50, 41, 20))
        self.city.setObjectName(_fromUtf8("city"))
        self.mineName_label_4 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_4.setGeometry(QtCore.QRect(150, 50, 54, 16))
        self.mineName_label_4.setObjectName(_fromUtf8("mineName_label_4"))
        self.mineName_label_3 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_3.setGeometry(QtCore.QRect(200, 90, 54, 16))
        self.mineName_label_3.setObjectName(_fromUtf8("mineName_label_3"))
        self.mineName_label = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label.setGeometry(QtCore.QRect(11, 10, 54, 16))
        self.mineName_label.setObjectName(_fromUtf8("mineName_label"))
        self.mineName_label_2 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_2.setGeometry(QtCore.QRect(10, 90, 54, 16))
        self.mineName_label_2.setObjectName(_fromUtf8("mineName_label_2"))
        self.name = QtGui.QLineEdit(mine_degin_dlg)
        self.name.setGeometry(QtCore.QRect(70, 10, 211, 20))
        self.name.setObjectName(_fromUtf8("name"))
        self.save = QtGui.QPushButton(mine_degin_dlg)
        self.save.setGeometry(QtCore.QRect(290, 10, 75, 23))
        self.save.setObjectName(_fromUtf8("save"))
        self.label_4 = QtGui.QLabel(mine_degin_dlg)
        self.label_4.setGeometry(QtCore.QRect(190, 130, 81, 21))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.label_3 = QtGui.QLabel(mine_degin_dlg)
        self.label_3.setGeometry(QtCore.QRect(10, 130, 71, 21))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.hydr_geo = QtGui.QComboBox(mine_degin_dlg)
        self.hydr_geo.setGeometry(QtCore.QRect(270, 130, 101, 20))
        self.hydr_geo.setObjectName(_fromUtf8("hydr_geo"))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.hydr_geo.addItem(_fromUtf8(""))
        self.topo_geo = QtGui.QComboBox(mine_degin_dlg)
        self.topo_geo.setGeometry(QtCore.QRect(90, 130, 81, 20))
        self.topo_geo.setObjectName(_fromUtf8("topo_geo"))
        self.topo_geo.addItem(_fromUtf8(""))
        self.topo_geo.addItem(_fromUtf8(""))
        self.topo_geo.addItem(_fromUtf8(""))
        self.capacity = QtGui.QLineEdit(mine_degin_dlg)
        self.capacity.setGeometry(QtCore.QRect(70, 50, 41, 20))
        self.capacity.setObjectName(_fromUtf8("capacity"))
        self.mineName_label_7 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_7.setGeometry(QtCore.QRect(10, 50, 51, 21))
        self.mineName_label_7.setObjectName(_fromUtf8("mineName_label_7"))
        self.mineName_label_8 = QtGui.QLabel(mine_degin_dlg)
        self.mineName_label_8.setGeometry(QtCore.QRect(120, 50, 31, 21))
        self.mineName_label_8.setObjectName(_fromUtf8("mineName_label_8"))
        self.ground_cond = QtGui.QCheckBox(mine_degin_dlg)
        self.ground_cond.setGeometry(QtCore.QRect(10, 170, 161, 16))
        self.ground_cond.setObjectName(_fromUtf8("ground_cond"))
        self.label = QtGui.QLabel(mine_degin_dlg)
        self.label.setGeometry(QtCore.QRect(10, 200, 51, 21))
        self.label.setObjectName(_fromUtf8("label"))
        self.coal = QtGui.QComboBox(mine_degin_dlg)
        self.coal.setGeometry(QtCore.QRect(80, 200, 111, 22))
        self.coal.setObjectName(_fromUtf8("coal"))
        self.add_coal = QtGui.QPushButton(mine_degin_dlg)
        self.add_coal.setGeometry(QtCore.QRect(200, 200, 51, 23))
        self.add_coal.setObjectName(_fromUtf8("add_coal"))
        self.del_coal = QtGui.QPushButton(mine_degin_dlg)
        self.del_coal.setGeometry(QtCore.QRect(260, 200, 51, 23))
        self.del_coal.setObjectName(_fromUtf8("del_coal"))
        self.more_coal = QtGui.QPushButton(mine_degin_dlg)
        self.more_coal.setGeometry(QtCore.QRect(320, 200, 61, 23))
        self.more_coal.setObjectName(_fromUtf8("more_coal"))
        self.work_area = QtGui.QComboBox(mine_degin_dlg)
        self.work_area.setGeometry(QtCore.QRect(80, 240, 111, 22))
        self.work_area.setObjectName(_fromUtf8("work_area"))
        self.label_2 = QtGui.QLabel(mine_degin_dlg)
        self.label_2.setGeometry(QtCore.QRect(10, 240, 51, 21))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.more_work_area = QtGui.QPushButton(mine_degin_dlg)
        self.more_work_area.setGeometry(QtCore.QRect(320, 240, 61, 23))
        self.more_work_area.setObjectName(_fromUtf8("more_work_area"))
        self.del_work_area = QtGui.QPushButton(mine_degin_dlg)
        self.del_work_area.setGeometry(QtCore.QRect(260, 240, 51, 23))
        self.del_work_area.setObjectName(_fromUtf8("del_work_area"))
        self.add_work_area = QtGui.QPushButton(mine_degin_dlg)
        self.add_work_area.setGeometry(QtCore.QRect(200, 240, 51, 23))
        self.add_work_area.setObjectName(_fromUtf8("add_work_area"))
        self.work_surf = QtGui.QComboBox(mine_degin_dlg)
        self.work_surf.setGeometry(QtCore.QRect(80, 280, 111, 22))
        self.work_surf.setObjectName(_fromUtf8("work_surf"))
        self.label_5 = QtGui.QLabel(mine_degin_dlg)
        self.label_5.setGeometry(QtCore.QRect(10, 280, 61, 21))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.more_work_surf = QtGui.QPushButton(mine_degin_dlg)
        self.more_work_surf.setGeometry(QtCore.QRect(320, 280, 61, 23))
        self.more_work_surf.setObjectName(_fromUtf8("more_work_surf"))
        self.del_work_surf = QtGui.QPushButton(mine_degin_dlg)
        self.del_work_surf.setGeometry(QtCore.QRect(260, 280, 51, 23))
        self.del_work_surf.setObjectName(_fromUtf8("del_work_surf"))
        self.add_work_surf = QtGui.QPushButton(mine_degin_dlg)
        self.add_work_surf.setGeometry(QtCore.QRect(200, 280, 51, 23))
        self.add_work_surf.setObjectName(_fromUtf8("add_work_surf"))
        self.drilling_surf = QtGui.QComboBox(mine_degin_dlg)
        self.drilling_surf.setGeometry(QtCore.QRect(80, 320, 111, 22))
        self.drilling_surf.setObjectName(_fromUtf8("drilling_surf"))
        self.label_6 = QtGui.QLabel(mine_degin_dlg)
        self.label_6.setGeometry(QtCore.QRect(10, 320, 61, 21))
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.more_rilling_surf = QtGui.QPushButton(mine_degin_dlg)
        self.more_rilling_surf.setGeometry(QtCore.QRect(320, 320, 61, 23))
        self.more_rilling_surf.setObjectName(_fromUtf8("more_rilling_surf"))
        self.del_rilling_surf = QtGui.QPushButton(mine_degin_dlg)
        self.del_rilling_surf.setGeometry(QtCore.QRect(260, 320, 51, 23))
        self.del_rilling_surf.setObjectName(_fromUtf8("del_rilling_surf"))
        self.add_drilling_surf = QtGui.QPushButton(mine_degin_dlg)
        self.add_drilling_surf.setGeometry(QtCore.QRect(200, 320, 51, 23))
        self.add_drilling_surf.setObjectName(_fromUtf8("add_drilling_surf"))

        self.retranslateUi(mine_degin_dlg)
        QtCore.QMetaObject.connectSlotsByName(mine_degin_dlg)

    def retranslateUi(self, mine_degin_dlg):
        mine_degin_dlg.setWindowTitle(_translate("mine_degin_dlg", "矿井设计", None))
        self.mineName_label_6.setText(_translate("mine_degin_dlg", "市（地区）", None))
        self.mineName_label_5.setText(_translate("mine_degin_dlg", "省", None))
        self.mineName_label_4.setText(_translate("mine_degin_dlg", "所在地", None))
        self.mineName_label_3.setText(_translate("mine_degin_dlg", "所在矿区", None))
        self.mineName_label.setText(_translate("mine_degin_dlg", "矿井名称", None))
        self.mineName_label_2.setText(_translate("mine_degin_dlg", "煤炭基地", None))
        self.name.setToolTip(_translate("mine_degin_dlg", "<html><head/><body><p>输入矿井名称</p></body></html>", None))
        self.name.setWhatsThis(_translate("mine_degin_dlg", "<html><head/><body><p>用户名</p></body></html>", None))
        self.save.setText(_translate("mine_degin_dlg", "保存", None))
        self.label_4.setText(_translate("mine_degin_dlg", "水文地质条件", None))
        self.label_3.setText(_translate("mine_degin_dlg", "地形地貌特征", None))
        self.hydr_geo.setItemText(0, _translate("mine_degin_dlg", "简单", None))
        self.hydr_geo.setItemText(1, _translate("mine_degin_dlg", "中等", None))
        self.hydr_geo.setItemText(2, _translate("mine_degin_dlg", "复杂", None))
        self.hydr_geo.setItemText(3, _translate("mine_degin_dlg", "极复杂", None))
        self.topo_geo.setItemText(0, _translate("mine_degin_dlg", "简单", None))
        self.topo_geo.setItemText(1, _translate("mine_degin_dlg", "中等", None))
        self.topo_geo.setItemText(2, _translate("mine_degin_dlg", "复杂", None))
        self.mineName_label_7.setText(_translate("mine_degin_dlg", "矿井产能", None))
        self.mineName_label_8.setText(_translate("mine_degin_dlg", "Mt/a", None))
        self.ground_cond.setText(_translate("mine_degin_dlg", "是否具备地面井开发条件", None))
        self.label.setText(_translate("mine_degin_dlg", "煤层列表", None))
        self.add_coal.setText(_translate("mine_degin_dlg", "增加", None))
        self.del_coal.setText(_translate("mine_degin_dlg", "删除", None))
        self.more_coal.setText(_translate("mine_degin_dlg", "详细设计", None))
        self.label_2.setText(_translate("mine_degin_dlg", "生产采区", None))
        self.more_work_area.setText(_translate("mine_degin_dlg", "详细设计", None))
        self.del_work_area.setText(_translate("mine_degin_dlg", "删除", None))
        self.add_work_area.setText(_translate("mine_degin_dlg", "增加", None))
        self.label_5.setText(_translate("mine_degin_dlg", "回采工作面", None))
        self.more_work_surf.setText(_translate("mine_degin_dlg", "详细设计", None))
        self.del_work_surf.setText(_translate("mine_degin_dlg", "删除", None))
        self.add_work_surf.setText(_translate("mine_degin_dlg", "增加", None))
        self.label_6.setText(_translate("mine_degin_dlg", "掘进工作面", None))
        self.more_rilling_surf.setText(_translate("mine_degin_dlg", "详细设计", None))
        self.del_rilling_surf.setText(_translate("mine_degin_dlg", "删除", None))
        self.add_drilling_surf.setText(_translate("mine_degin_dlg", "增加", None))

import usecad_rc
