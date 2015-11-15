#coding:utf-8

import datetime

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

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
	if admin.id < 0:
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
	if admin.id < 0:
		return 0  # 内部错误(无管理员账户)
	else:
		# 查找当前登录账户
		account_id = CbmClientHelper.GetOnlineAccountId()
		if account_id < 0:
			return 2  # 没有用户登录
		elif account_id == admin.id:
			return 3  # 管理员已登录
		else:
			mine_id = SQLClientHelper.GetMineIdByForeignKey('account_id', account_id)
			if mine_id < 0: # 内部错误(用户没有关联的矿井)
				return -1
			else:           # 普通用户已登陆
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