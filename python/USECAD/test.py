#coding:utf-8
class TestClass:
	def __init__(self):
		self.a = 10
	
	def test(self):
		print self.a

	def a1(self):
		print 'a1'

	def a2(self):
		print 'a2'

tc = TestClass()

# x = input('序号:')

# func = 'a%d' % x

# getattr(tc,func)()
import subprocess

def TestCall():
	xpdf = u'中.pdf'
	fileName = 'pdf.exe %s' % xpdf
	print type(fileName)
	# fileName = u"pdf.exe 中.pdf".encode('gb2312')
	subprocess.Popen(fileName.encode('gb2312'))

TestCall()