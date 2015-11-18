#coding:utf-8

# import datetime
# from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
# from cbm.ttypes import *

from dialogs import NameDlg, CbmMessageBox
from PyQt4 import QtCore, QtGui

# 显示或隐藏窗口
def ShowWidget(widget, bShow=True):
	if widget is not None and hasattr(widget, 'setVisible'):
		if bShow:
			widget.show()
		else:
			widget.hide()
		# widget.setVisible(bShow)

# 自定义消息对话框
def MessageBox(msg_text, question=False):
	msgbox = CbmMessageBox.CbmMessageBox()
	if not question:
		msgbox.setMessage(msg_text, CbmMessageBox.MsgBoxType.INFO)
		msgbox.exec_()
		return True
	else:
		msgbox.setMessage(msg_text, CbmMessageBox.MsgBoxType.QUESTION)
		return msgbox.exec_() == 1

# 弹出对话框，请求用户输入一个"名称""
def GetNameFromDlg(title):
	dlg = NameDlg.NameDlg()
	# 设置标题
	dlg.setTitle(title)
	name = u''
	if dlg.exec_():
		name = dlg.name
	return name

# 增加数据到组合框列表
def AddItemToCombobox(combobox, item_text, item_data=None):
	pos = combobox.findText(item_text)
	if pos != -1:
		# 使用QMessageBox,第一个参数可以用None,没必要传递给它一个widget对象!
		MessageBox(u"您输入的名称已存在！")
	else:
		combobox.addItem(item_text, item_data)
		pos = combobox.count()-1
	return pos

def AddObjectListToCombobox(combobox, obj_lists):
	for obj in obj_lists:
		if not hasattr(obj, 'name') or not hasattr(obj, 'id'):
			continue
		combobox.addItem(obj.name, obj.id)
	combobox.setCurrentIndex(0)