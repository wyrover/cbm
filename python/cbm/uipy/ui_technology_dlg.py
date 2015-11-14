# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\technology_dlg.ui'
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

class Ui_technologyDlg(object):
    def setupUi(self, technologyDlg):
        technologyDlg.setObjectName(_fromUtf8("technologyDlg"))
        technologyDlg.resize(381, 300)
        technologyDlg.setMinimumSize(QtCore.QSize(381, 300))
        technologyDlg.setMaximumSize(QtCore.QSize(381, 300))
        technologyDlg.setSizeIncrement(QtCore.QSize(381, 300))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/images/cbm.ico")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        technologyDlg.setWindowIcon(icon)
        self.region = QtGui.QLabel(technologyDlg)
        self.region.setGeometry(QtCore.QRect(20, 10, 121, 16))
        self.region.setObjectName(_fromUtf8("region"))
        self.is_key = QtGui.QCheckBox(technologyDlg)
        self.is_key.setGeometry(QtCore.QRect(180, 10, 71, 16))
        self.is_key.setObjectName(_fromUtf8("is_key"))
        self.save = QtGui.QPushButton(technologyDlg)
        self.save.setGeometry(QtCore.QRect(290, 10, 75, 23))
        self.save.setObjectName(_fromUtf8("save"))
        self.technology_listWidget = QtGui.QListWidget(technologyDlg)
        self.technology_listWidget.setGeometry(QtCore.QRect(10, 40, 361, 171))
        self.technology_listWidget.setObjectName(_fromUtf8("technology_listWidget"))
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        item = QtGui.QListWidgetItem()
        self.technology_listWidget.addItem(item)
        self.label = QtGui.QLabel(technologyDlg)
        self.label.setGeometry(QtCore.QRect(10, 230, 51, 16))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_2 = QtGui.QLabel(technologyDlg)
        self.label_2.setGeometry(QtCore.QRect(10, 260, 51, 16))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.doc = QtGui.QLineEdit(technologyDlg)
        self.doc.setGeometry(QtCore.QRect(70, 230, 181, 20))
        self.doc.setObjectName(_fromUtf8("doc"))
        self.video = QtGui.QLineEdit(technologyDlg)
        self.video.setGeometry(QtCore.QRect(70, 260, 181, 20))
        self.video.setObjectName(_fromUtf8("video"))
        self.doc_select = QtGui.QPushButton(technologyDlg)
        self.doc_select.setGeometry(QtCore.QRect(260, 230, 51, 23))
        self.doc_select.setObjectName(_fromUtf8("doc_select"))
        self.video_select = QtGui.QPushButton(technologyDlg)
        self.video_select.setGeometry(QtCore.QRect(260, 260, 51, 23))
        self.video_select.setObjectName(_fromUtf8("video_select"))
        self.doc_read = QtGui.QPushButton(technologyDlg)
        self.doc_read.setGeometry(QtCore.QRect(320, 230, 51, 23))
        self.doc_read.setObjectName(_fromUtf8("doc_read"))
        self.video_play = QtGui.QPushButton(technologyDlg)
        self.video_play.setGeometry(QtCore.QRect(320, 260, 51, 23))
        self.video_play.setObjectName(_fromUtf8("video_play"))

        self.retranslateUi(technologyDlg)
        QtCore.QMetaObject.connectSlotsByName(technologyDlg)

    def retranslateUi(self, technologyDlg):
        technologyDlg.setWindowTitle(_translate("technologyDlg", "推荐煤层气（瓦斯）抽采技术", None))
        self.region.setText(_translate("technologyDlg", ">>xx矿区推荐抽采技术", None))
        self.is_key.setText(_translate("technologyDlg", "关键技术", None))
        self.save.setText(_translate("technologyDlg", "保存", None))
        __sortingEnabled = self.technology_listWidget.isSortingEnabled()
        self.technology_listWidget.setSortingEnabled(False)
        item = self.technology_listWidget.item(0)
        item.setText(_translate("technologyDlg", "专用瓦斯抽采巷穿层钻孔预抽煤层气技术", None))
        item = self.technology_listWidget.item(1)
        item.setText(_translate("technologyDlg", "本煤层顺层钻孔抽采煤层气技术", None))
        item = self.technology_listWidget.item(2)
        item.setText(_translate("technologyDlg", "专用瓦斯抽采巷穿层抽采卸压煤层气技术", None))
        item = self.technology_listWidget.item(3)
        item.setText(_translate("technologyDlg", "石门揭煤穿层钻孔压裂高效抽采技术", None))
        item = self.technology_listWidget.item(4)
        item.setText(_translate("technologyDlg", "采空区煤层气抽采技术", None))
        item = self.technology_listWidget.item(5)
        item.setText(_translate("technologyDlg", "高压水力压裂增透抽采技术", None))
        item = self.technology_listWidget.item(6)
        item.setText(_translate("technologyDlg", "松软突出煤层顺层孔连续套管护孔技术", None))
        item = self.technology_listWidget.item(7)
        item.setText(_translate("technologyDlg", "高压水力压裂增透抽采技术", None))
        item = self.technology_listWidget.item(8)
        item.setText(_translate("technologyDlg", "松软突出煤层顺层孔连续套管护孔技术", None))
        self.technology_listWidget.setSortingEnabled(__sortingEnabled)
        self.label.setText(_translate("technologyDlg", "技术文档", None))
        self.label_2.setText(_translate("technologyDlg", "技术视频", None))
        self.doc_select.setText(_translate("technologyDlg", "选择", None))
        self.video_select.setText(_translate("technologyDlg", "选择", None))
        self.doc_read.setText(_translate("technologyDlg", "查看", None))
        self.video_play.setText(_translate("technologyDlg", "播放", None))

import usecad_rc
