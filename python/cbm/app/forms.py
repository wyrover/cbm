#-*-  coding:utf-8 -*-

from flask.ext.wtf import Form
from flask.ext.babel import gettext
from wtforms import StringField, PasswordField, BooleanField, TextAreaField, SubmitField
from wtforms.validators import DataRequired, Length

class LoginForm(Form):
    username = StringField(u'用户名', validators=[DataRequired(), Length(3, 20)])
    password = PasswordField(u'密码', validators=[DataRequired()])
    login = SubmitField(u'登录')

class RegForm(Form):
    username = StringField(u'用户名', validators=[DataRequired(), Length(3, 20)])
    password = PasswordField(u'密码', validators=[DataRequired()])
    login = SubmitField(u'登录')

class EditForm(Form):
    nickname = StringField('nickname', validators=[DataRequired()])
    about_me = TextAreaField('about_me', validators=[Length(min=0, max=140)])

    def __init__(self, original_nickname, *args, **kwargs):
        Form.__init__(self, *args, **kwargs)
        self.original_nickname = original_nickname

    def validate(self):
        if not Form.validate(self):
            return False
        if self.nickname.data == self.original_nickname:
            return True
        if self.nickname.data != User.make_valid_nickname(self.nickname.data):
            self.nickname.errors.append(gettext(
                'This nickname has invalid characters. '
                'Please use letters, numbers, dots and underscores only.'))
            return False
        user = User.query.filter_by(nickname=self.nickname.data).first()
        if user is not None:
            self.nickname.errors.append(gettext(
                'This nickname is already in use. '
                'Please choose another one.'))
            return False
        return True


class PostForm(Form):
    post = StringField('post', validators=[DataRequired()])