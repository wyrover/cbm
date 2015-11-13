#-*- coding:utf-8 -*-
#!flask/bin/python

import subprocess

def main():
	from app import app
	app.run(debug=True)

if __name__ == '__main__':
	main()