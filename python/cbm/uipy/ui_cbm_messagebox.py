# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'uifiles\cbm_messagebox.ui'
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

class Ui_cbm_messageBox(object):
    def setupUi(self, cbm_messageBox):
        cbm_messageBox.setObjectName(_fromUtf8("cbm_messageBox"))
        cbm_messageBox.resize(303, 156)
        self.verticalLayout = QtGui.QVBoxLayout(cbm_messageBox)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setSpacing(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.widget_title = QtGui.QWidget(cbm_messageBox)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.widget_title.sizePolicy().hasHeightForWidth())
        self.widget_title.setSizePolicy(sizePolicy)
        self.widget_title.setMinimumSize(QtCore.QSize(100, 28))
        self.widget_title.setObjectName(_fromUtf8("widget_title"))
        self.horizontalLayout_2 = QtGui.QHBoxLayout(self.widget_title)
        self.horizontalLayout_2.setMargin(0)
        self.horizontalLayout_2.setSpacing(0)
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.lab_Ico = QtGui.QLabel(self.widget_title)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lab_Ico.sizePolicy().hasHeightForWidth())
        self.lab_Ico.setSizePolicy(sizePolicy)
        self.lab_Ico.setMinimumSize(QtCore.QSize(31, 0))
        self.lab_Ico.setText(_fromUtf8(""))
        self.lab_Ico.setAlignment(QtCore.Qt.AlignCenter)
        self.lab_Ico.setObjectName(_fromUtf8("lab_Ico"))
        self.horizontalLayout_2.addWidget(self.lab_Ico)
        self.lab_Title = QtGui.QLabel(self.widget_title)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lab_Title.sizePolicy().hasHeightForWidth())
        self.lab_Title.setSizePolicy(sizePolicy)
        self.lab_Title.setStyleSheet(_fromUtf8("font: 10pt \"微软雅黑\";"))
        self.lab_Title.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.lab_Title.setObjectName(_fromUtf8("lab_Title"))
        self.horizontalLayout_2.addWidget(self.lab_Title)
        self.btnMenu_Close = QtGui.QPushButton(self.widget_title)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btnMenu_Close.sizePolicy().hasHeightForWidth())
        self.btnMenu_Close.setSizePolicy(sizePolicy)
        self.btnMenu_Close.setMinimumSize(QtCore.QSize(40, 0))
        self.btnMenu_Close.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.btnMenu_Close.setFocusPolicy(QtCore.Qt.NoFocus)
        self.btnMenu_Close.setText(_fromUtf8(""))
        self.btnMenu_Close.setFlat(True)
        self.btnMenu_Close.setObjectName(_fromUtf8("btnMenu_Close"))
        self.horizontalLayout_2.addWidget(self.btnMenu_Close)
        self.verticalLayout.addWidget(self.widget_title)
        self.widget_main = QtGui.QWidget(cbm_messageBox)
        self.widget_main.setStyleSheet(_fromUtf8("font: 11pt \"微软雅黑\";"))
        self.widget_main.setObjectName(_fromUtf8("widget_main"))
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.widget_main)
        self.verticalLayout_2.setMargin(5)
        self.verticalLayout_2.setSpacing(5)
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.groupBox = QtGui.QGroupBox(self.widget_main)
        self.groupBox.setTitle(_fromUtf8(""))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.labIcoMain = QtGui.QLabel(self.groupBox)
        self.labIcoMain.setGeometry(QtCore.QRect(10, 10, 45, 45))
        self.labIcoMain.setStyleSheet(_fromUtf8("border-image: url(:/images/info.png);"))
        self.labIcoMain.setText(_fromUtf8(""))
        self.labIcoMain.setScaledContents(True)
        self.labIcoMain.setObjectName(_fromUtf8("labIcoMain"))
        self.labInfo = QtGui.QLabel(self.groupBox)
        self.labInfo.setGeometry(QtCore.QRect(70, 10, 211, 41))
        self.labInfo.setScaledContents(False)
        self.labInfo.setWordWrap(True)
        self.labInfo.setObjectName(_fromUtf8("labInfo"))
        self.layoutWidget = QtGui.QWidget(self.groupBox)
        self.layoutWidget.setGeometry(QtCore.QRect(10, 60, 271, 51))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.horizontalLayout_3 = QtGui.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout_3.setObjectName(_fromUtf8("horizontalLayout_3"))
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem)
        self.btnOk = QtGui.QPushButton(self.layoutWidget)
        self.btnOk.setEnabled(True)
        self.btnOk.setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
        self.btnOk.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.btnOk.setStyleSheet(_fromUtf8(""))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/image/update.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.btnOk.setIcon(icon)
        self.btnOk.setIconSize(QtCore.QSize(20, 20))
        self.btnOk.setObjectName(_fromUtf8("btnOk"))
        self.horizontalLayout_3.addWidget(self.btnOk)
        self.btnCancel = QtGui.QPushButton(self.layoutWidget)
        self.btnCancel.setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
        self.btnCancel.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.btnCancel.setStyleSheet(_fromUtf8(""))
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(_fromUtf8(":/image/close.png")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.btnCancel.setIcon(icon1)
        self.btnCancel.setIconSize(QtCore.QSize(20, 20))
        self.btnCancel.setObjectName(_fromUtf8("btnCancel"))
        self.horizontalLayout_3.addWidget(self.btnCancel)
        self.verticalLayout_2.addWidget(self.groupBox)
        self.verticalLayout.addWidget(self.widget_main)

        self.retranslateUi(cbm_messageBox)
        QtCore.QMetaObject.connectSlotsByName(cbm_messageBox)

    def retranslateUi(self, cbm_messageBox):
        cbm_messageBox.setWindowTitle(_translate("cbm_messageBox", "提示", None))
        self.lab_Title.setText(_translate("cbm_messageBox", " 友情提示", None))
        self.btnMenu_Close.setToolTip(_translate("cbm_messageBox", "关闭", None))
        self.labInfo.setText(_translate("cbm_messageBox", "确定要删除吗?", None))
        self.btnOk.setText(_translate("cbm_messageBox", "确定(&O)", None))
        self.btnCancel.setText(_translate("cbm_messageBox", "取消(&C)", None))

import usecad_rc
