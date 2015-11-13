#coding:utf-8
import subprocess
import webbrowser

def OpenPDFFile(fileName):
	if type(fileName).__name__ != "unicode":
		fileName = fileName.decode('utf-8')
	fName = 'tool\\pdf.exe %s' % fileName
	# 增加异常处理
	try:
		subprocess.Popen(fName.encode('gb2312'))
	except Exception, e:
		print e

def OpenNet(webName):
	webbrowser.open(webName)
