#-*- coding:utf-8 -*-
#!flask/bin/python

import subprocess

def main():
	global rpc_process
	try:
		# 启动一个进程运行rpc服务器
		rpc_process = subprocess.Popen(["python","rpc_server.py"])
		if rpc_process is None:
			raise
		else:
			print("启动rpc后台进程")
			# 运行flask服务器
			from app import app
			app.run(debug=False)
	except Exception, e:
		print e
	finally:
		# 检查子进程状态
		if rpc_process.poll() is not None:
			# 关闭rpc服务器
			from rpc import CtrlClientHelper
			CtrlClientHelper.QuitServer()

			# 杀死rpc进程	
			rpc_process.kill()

if __name__ == '__main__':
	main()