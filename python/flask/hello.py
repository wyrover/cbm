#-*- coding:utf-8 -*-

from flask import Flask, url_for, abort, redirect, request, render_template
app = Flask(__name__)

@app.route('/')
def index():
    # return '<h1>hello菜菜</h1>'
    return redirect(url_for('login'))

@app.route('/hello')
def hello():
    return '<h1>你好Flask</h1>'

@app.route('/about')
def about():
    return 'The about page'

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        # do_the_login()
        return '通过POST获取数据'
    else:
    	return '通过GET获取数据'
        # show_the_login_form()

@app.route('/hello2/')
@app.route('/hello2/<name>')
def hello2(name=None):
    return render_template('hello.html', name=name)

if __name__ == '__main__':
	# 开启调试选项有助于开发
	# 生产上线后一定要关掉
	app.debug = True
	app.run()