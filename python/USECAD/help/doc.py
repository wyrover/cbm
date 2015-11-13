#coding:utf-8
import subprocess
import webbrowser

def OpenPDFFile(fileName):
	if type(fileName).__name__ != "unicode":
		fileName = fileName.decode('utf-8')
	fName = 'pdf.exe %s' % fileName
	subprocess.Popen(fName.encode('gb2312'))

def OpenNet(webName):
	webbrowser.open(webName)
