#coding:utf-8

import datetime
from math import sqrt, pow, exp, sin, cos, tan, radians

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
# from scipy import stats
# import statsmodels.api as sm
import matplotlib.pyplot as plt

#pandas给matplotlib提供了一种ggplot绘图的扩展主题(可以认为类似于windows的主题),效果更好看
pd.set_option('display.mpl_style', 'default') # Make the graphs a bit prettier

#解决matplotlib中文问题
#注意:要放在pd.set_option的后面,否则pd.set_option会覆盖之前的matplotlib设置
import matplotlib as mpl
mpl.rcParams['font.family']='sans-serif'
mpl.rcParams['font.sans-serif'] = ['SimHei']  #指定默认字体
mpl.rcParams['axes.unicode_minus'] = False	#解决保存图像是负号'-'显示为方块的问题

# 由于设计ui的时候,做了3个子菜单(回采面、掘进面、采空区)
# 但它们对应的都是连接一个slot函数,而现有的实现很难实现给slot函数传递参数的功能(可以做,但对本代码来说需要修改的就比较多了)
# 参见MainWindow中的wsGasDesign、twsGasDesign、goafGasDesign 这3个槽函数
GAS_DESIGN_TYPE = 1

# 枚举--登录限制
class Authority:
	ADMIN = 1  # 只允许管理员登录
	USER = 2   # 只允许普通用户登录
	BOTH = 3   # 两者都可以

# 获取当前时间,格式: 2015-11-13 21:35:15
def current_time():
	now = datetime.datetime.now()
	return now.strftime('%Y-%m-%d %H:%M:%S')

# 用户登录(操作数据库)
def sql_login_user(account_id):
	# 设置当前登录用户(记录到sys_info表)
	sys_info = SysInfo()
	sys_info.account_id = account_id
	sys_info.last_login_time = current_time()
	SQLClientHelper.AddSysInfo(sys_info)

# 用户切换(操作数据库)
def sql_switch_user(account_id):
	sys_info = SQLClientHelper.GetSysInfoByFields({})
	sys_info.account_id = account_id
	sys_info.last_login_time = current_time()
	SQLClientHelper.UpdateSysInfo(sys_info)

# 注销(清空sys_info表)
def sql_logout():
	SQLClientHelper.DeleteMoreSysInfo(SQLClientHelper.GetSysInfoIds())

# 检查用户名是否已注册(操作数据库)
def sql_check_user(uname, pwd):
	return CbmClientHelper.VerifyMineAccount(uname, pwd) == 1

# 新建账户
def sql_create_user(uname, pwd):
	account = Account()
	account.username = uname
	account.password = pwd
	return SQLClientHelper.AddAccount(account)

# 新建煤层
def sql_create_coal(name, mine_id):
	coal = Coal()
	coal.name = name
	coal.mine_id = mine_id
	return SQLClientHelper.AddCoal(coal)

# 新建矿井
def sql_create_mine(name, province, city, region, account_id):
	mine = Mine()
	mine.name = name
	mine.province = province
	mine.city = city
	mine.mine_region_id = SQLClientHelper.GetMineRegionIdByField1('name', region)
	mine.account_id = account_id
	return SQLClientHelper.AddMine(mine)

# 管理员是否登录了
def sql_is_admin_online():
	admin = SQLClientHelper.GetAccountByField1('username', 'admin')
	if admin.id <= 0:
		return False
	else:
		# 查找当前登录账户
		account_id = CbmClientHelper.GetOnlineAccountId()
		return account_id == admin.id

# 登录验证
def sql_login_authority(authority):
	ret = False
	if authority == Authority.ADMIN:
		if sql_is_admin_online():
			ret = True
	elif authority == Authority.USER:
		if not sql_is_admin_online():
			ret = True
	elif authority == Authority.BOTH:
		ret = True
	return ret

# 查看登录状态(哪个用户登录了)
def sql_login_status():
	# 查找管理员账户
	admin = SQLClientHelper.GetAccountByField1('username', 'admin')
	if admin.id <= 0:
		return 0  # 内部错误(无管理员账户)
	else:
		# 查找当前登录账户
		account_id = CbmClientHelper.GetOnlineAccountId()
		if account_id <= 0:
			return 2  # 没有用户登录
		elif account_id == admin.id:
			return 3  # 管理员已登录
		else:
			mine_id = SQLClientHelper.GetMineIdByForeignKey('account_id', account_id)
			if mine_id <= 0: # 内部错误(用户没有关联的矿井)
				return -1
			else:		   # 普通用户已登陆
				return 1

def sql_create_work_area(name, coal_id):
	work_area = WorkArea()
	work_area.name = name
	work_area.coal_id = coal_id
	return SQLClientHelper.AddWorkArea(work_area)

def sql_create_work_surf(name, work_area_id):
	work_surf = WorkSurf()
	work_surf.name = name
	work_surf.work_area_id = work_area_id
	return SQLClientHelper.AddWorkSurf(work_surf)

def sql_create_drilling_surf(name, work_area_id):
	drilling_surf = DrillingSurf()
	drilling_surf.name = name
	drilling_surf.work_area_id = work_area_id
	return SQLClientHelper.AddDrillingSurf(drilling_surf)	

def permeability_lambda_to_k(p_lambda):
	return 0.025*p_lambda

def permeability_k_to_lambda(p_k):
	return p_k / 0.025

def draw_curve(q0, alpha):
	T = np.arange(0, 60) # 时间
	# 新建一个figure
	fig = plt.figure(figsize=(8, 6))
	# 绘制曲线
	c = 1440*q0/alpha
	f = lambda t:c*(1- exp(-1*alpha*t))
	Q = [f(t) for t in T]
	Q0 = [c for t in T]
	k = [x/x0 for (x, x0) in zip(Q, Q0)]
	plt.subplot(211)
	plt.title(u'百米钻孔在不同时间t内可抽采的瓦斯总量$Q_t(q_0=%.1f, α=%.1f)$' % (q0, alpha))
	plt.xlabel(u'抽采时间$t(d)$')
	plt.ylabel(u'可抽瓦斯总量$Q_t(m^3)$')
	plt.grid(True)
	plt.plot(T, Q, label=u'$Q_t=1440q_0(1-e^{-αt})/α$')
	plt.plot(T, Q0, 'r--', label=u'$Q_0$= %.1f' % c)
	plt.legend(loc=0)

	plt.subplot(212)
	plt.title(u'钻孔抽采有效系数$k(q_0=%.1f, α=%.1f)$' % (q0, alpha))
	plt.xlabel(u'抽采时间$t(d)$')
	plt.ylabel(u'钻孔抽采有效系数$k(\%)$')
	plt.grid(True)
	plt.plot(T, k, 'g-', label=u'$k=(1-e^{-αt})*100\%$)')
	plt.legend(loc=0)
	# 显示图形
	plt.show()
	