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

def CreatReport(jsonName):
	if type(jsonName).__name__ != "unicode":
		jsonName = jsonName.decode('utf-8')
	fName = 'tool\\report.exe %s' % jsonName
	# 增加异常处理
	try:
		subprocess.Popen(fName.encode('gb2312'))
	except Exception, e:
		print e

