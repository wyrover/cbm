import win32com
from win32com.client import Dispatch, constants

w = win32com.client.Dispatch('Word.Application')
# 或者使用下面的方法，使用启动独立的进程：
# w = win32com.client.DispatchEx('Word.Application')

# 后台运行，不显示，不警告
w.Visible = 0
w.DisplayAlerts = 0

# 打开新的文件
doc = w.Documents.Open( FileName = filenamein )
# worddoc = w.Documents.Add() # 创建新的文档

# 插入文字
myRange = doc.Range(0,0)
myRange.InsertBefore('Hello from Python!')

# 使用样式
wordSel = myRange.Select()
wordSel.Style = constants.wdStyleHeading1

# 正文文字替换
w.Selection.Find.ClearFormatting()
w.Selection.Find.Replacement.ClearFormatting()
w.Selection.Find.Execute(OldStr, False, False, False, False, False, True, 1, True, NewStr, 2)