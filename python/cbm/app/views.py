#-*- coding:utf-8 -*-

from flask import render_template, flash, redirect, session, url_for, request, \
    g, jsonify
from flask.ext.login import login_user, logout_user, current_user, login_required, UserMixin
from flask.ext.sqlalchemy import get_debug_queries
from flask.ext.babel import gettext
from datetime import datetime
from guess_language import guessLanguage
from app import app, db, login_manager, babel
from .forms import LoginForm, RegForm, EditForm, PostForm
from .models import User, Post
from .emails import follower_notification
from config import POSTS_PER_PAGE, LANGUAGES, DATABASE_QUERY_TIMEOUT

from rpc import CbmClientHelper, SQLClientHelper

class User(UserMixin):
    def __init__(self, cbm_user):
        self.cbm_user = cbm_user
        self.id = self.cbm_user.id
        self.last_seen = None

# flask-login扩展要求实现的回调函数
# 必须提供一个 user_loader 回调。这个回调用于从会话中存储的用户 ID 重新加载用户对象
@login_manager.user_loader
def load_user(id):
    return User(SQLClientHelper.GetAccountById(int(id)))

@babel.localeselector
def get_locale():
    return request.accept_languages.best_match(LANGUAGES.keys())


@app.before_request
def before_request():
    g.user = current_user
    if g.user.is_authenticated:
        g.user.last_seen = datetime.utcnow()
    g.locale = get_locale()


@app.after_request
def after_request(response):
    for query in get_debug_queries():
        if query.duration >= DATABASE_QUERY_TIMEOUT:
            app.logger.warning(
                "SLOW QUERY: %s\nParameters: %s\nDuration: %fs\nContext: %s\n" %
                (query.statement, query.parameters, query.duration,
                 query.context))
    return response


@app.errorhandler(404)
def not_found_error(error):
    return render_template('404.html'), 404


@app.errorhandler(500)
def internal_error(error):
    db.session.rollback()
    return render_template('500.html'), 500


# 主页
@app.route('/', methods=['GET', 'POST'])
@app.route('/index', methods=['GET', 'POST'])
def index():
    return render_template('index.html', title='Home')


# 登录
@app.route('/login', methods=['GET', 'POST'])
def login():
    # 用户已登录
    if g.user is not None and g.user.is_authenticated:
        return redirect(url_for('index'))
    form = LoginForm()
    # 表单验证通过(必须用POST发送表单数据)
    if form.validate_on_submit():
        # 验证用户名和密码是否正确
        # 验证通过
        if CbmClientHelper.VerifyMineAccount(form.username.data, form.password.data) == 1:
            # 构造注册用户
            cbm_user = SQLClientHelper.GetAccountByField1('username', form.username.data)
            if cbm_user.id > -1:
                # 尝试登录(针对flask-login扩展而言,login_user内部会记录当前用户,也就是current_user)
                user = User(cbm_user)
                login_user(user)
                return redirect(url_for('design'))
    return render_template('login.html', form=form)

# 注销
@app.route('/logout', methods=['GET', 'POST'])
def logout():
    logout_user()
    return redirect(url_for('index'))

# 注册
@app.route('/reg', methods=['GET', 'POST'])
def reg():
    form = RegForm()
    return render_template('reg.html', form=form)

# 矿井设计
@app.route('/design', methods=['GET', 'POST'])
@login_required
def design():
    return render_template('design.html')

# 原来的代码(作为参考学习用)
@app.route('/user/<nickname>')
@app.route('/user/<nickname>/<int:page>')
@login_required
def user(nickname, page=1):
    user = User.query.filter_by(nickname=nickname).first()
    if user is None:
        flash(gettext('User %(nickname)s not found.', nickname=nickname))
        return redirect(url_for('index'))
    posts = user.posts.paginate(page, POSTS_PER_PAGE, False)
    return render_template('user.html',
                           user=user,
                           posts=posts)

# 原来的代码(作为参考学习用)
@app.route('/delete/<int:id>')
@login_required
def delete(id):
    post = Post.query.get(id)
    if post is None:
        flash('Post not found.')
        return redirect(url_for('index'))
    if post.author.id != g.user.id:
        flash('You cannot delete this post.')
        return redirect(url_for('index'))
    db.session.delete(post)
    db.session.commit()
    flash('Your post has been deleted.')
    return redirect(url_for('index'))
