#-*- coding:utf-8 -*-

from flask import Flask, url_for, abort, redirect, request, render_template
from flask.ext.bootstrap import Bootstrap
from flask.ext.wtf import Form
from wtforms import StringField, SubmitField
from wtforms.validators import Required

# WTForms支持的HTML标准字段
# StringField 文本字段
# TextAreaField 多行文本字段
# PasswordField 密码文本字段
# HiddenField 隐藏文本字段
# DateField 文本字段，值为datetime.date 格式
# DateTimeField 文本字段，值为datetime.datetime 格式
# IntegerField 文本字段，值为整数
# DecimalField 文本字段，值为decimal.Decimal
# FloatField 文本字段，值为浮点数
# BooleanField 复选框，值为True 和False
# RadioField 一组单选框
# SelectField 下拉列表
# SelectMultipleField 下拉列表，可选择多个值
# FileField 文件上传字段
# SubmitField 表单提交按钮
# FormField 把表单作为字段嵌入另一个表单
# FieldList 一组指定类型的字段

# WTForms验证函数
# Email 验证电子邮件地址
# EqualTo 比较两个字段的值；常用于要求输入两次密码进行确认的情况
# IPAddress 验证IPv4网络地址
# Length 验证输入字符串的长度
# NumberRange 验证输入的值在数字范围内
# Optional 无输入值时跳过其他验证函数
# Required 确保字段中有数据
# Regexp 使用正则表达式验证输入值
# URL 验证URL
# AnyOf 确保输入值在可选值列表中
# NoneOf 确保输入值不在可选值列表中

app = Flask(__name__)
# 设置密钥，实现CSRF保护(WTF需要)
app.config['SECRET_KEY'] = '{7CA47726-B4F6-4A8F-9F53-A69CE5C3F4AC}'
bootstrap = Bootstrap(app)

class NameForm(Form):
    name = StringField('What is your name?', validators=[Required()])
    submit = SubmitField('Submit')

@app.route('/', methods=['GET', 'POST']) 
def index():
    # return '<h1>hello菜菜</h1>'
    # return redirect(url_for('login'))
    # return '<p>your browser:%s</p>' % request.headers.get('User-Agent'), 400
    name = None 
    form = NameForm() 
    if form.validate_on_submit(): 
        name = form.name.data 
        form.name.data = '' 
    return render_template('index.html', form=form, name=name)

@app.route('/user/<name>')
def user(name):
    # return '<h1>hello %s</h1>' % name
    return render_template('user.html', name=name)

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

@app.errorhandler(404) 
def page_not_found(e): 
    return render_template('404.html'), 404 
 
@app.errorhandler(500) 
def internal_server_error(e): 
    return render_template('500.html'), 500

if __name__ == '__main__':
	# 开启调试选项有助于开发
	# 生产上线后一定要关掉
	app.run(debug = True)