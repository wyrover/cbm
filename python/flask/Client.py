#-*- coding:utf-8 -*-
#!/usr/bin/env python

import sys, glob
sys.path.append('gen-py')
# sys.path.insert(0, glob.glob('../../lib/py/build/lib.*')[0])

import CbmClientTest
import SQLClientTest

if __name__ == '__main__':
	if True:
		CbmClientTest.main()
	else:
		SQLClientTest.main()