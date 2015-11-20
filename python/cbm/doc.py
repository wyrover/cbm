#coding:utf-8
import subprocess
import webbrowser
import win32api

def OpenEXEFile(exeName,fileName=''):
	if type(fileName).__name__ != "unicode":
		fileName = fileName.decode('utf-8')
	fName = '%s %s' % (exeName, fileName)
	# 增加异常处理
	try:
		win32api.ShellExecute(0, 'open', exeName, fileName,'',1)
		# subprocess.Popen(fName.encode('gb2312'))
	except Exception, e:
		print e


def OpenPDFFile(pdfFile):
	OpenEXEFile('tool\\pdf.exe',pdfFile)

def OpenNet(url):
	webbrowser.open(url)

def CreatReport(jsonFile):
	OpenEXEFile('tool\\report.exe',jsonFile)

def RunCAD():
	OpenEXEFile('tool\\Launcher.exe')


