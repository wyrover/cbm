#coding:utf-8

# import datetime
# from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
# from cbm.ttypes import *

from dialogs import NameDlg
from PyQt4 import QtCore, QtGui

def MessageBox(item_text, question=False):
    if not question:
        QtGui.QMessageBox.information(None, u"提示",item_text)
        return True
    else:
        reply = QtGui.QMessageBox.question(
        None, u'确认', item_text, QtGui.QMessageBox.Yes, QtGui.QMessageBox.No)
        return reply == QtGui.QMessageBox.Yes

def GetNameFromDlg(dlg_title):
    dlg = NameDlg.NameDlg()
    dlg.setTitle(dlg_title)
    name = u'null'
    if dlg.exec_():
        name = dlg.name
    return name

def AddItemToCombobox(combobox, item_text, item_data=None):
    pos = combobox.findText(item_text)
    if pos != -1:
        # 使用QMessageBox,第一个参数可以用None,没必要传递给它一个widget对象!
        QtGui.QMessageBox.information(None, u"提示",u"所输入的名称已存在！")
    else:
        combobox.addItem(item_text, item_data)
        pos = combobox.count()-1
    combobox.setCurrentIndex(pos)