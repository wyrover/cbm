#coding:utf-8

from uipy.ui_regdialog import *

from rpc import CbmUtil, SQLClientHelper, CbmClientHelper
from cbm.ttypes import *

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

class RegDiaolog(QtGui.QDialog):  
    def __init__(self,parent=None):
        super(RegDiaolog, self).__init__(parent)
        self.ui = Ui_RegDialog()
        self.ui.setupUi(self)
        self.ui.password.setEchoMode(QtGui.QLineEdit.Password)
    	self.ui.reg.clicked.connect(self.onReg)
        self.setFixedSize(self.width(),self.height())
        # 煤炭基地切换 事件处理
        self.connect(self.ui.base, QtCore.SIGNAL('currentIndexChanged(int)'), self.onMineBaseChanged)
        # 初始化煤炭基地和矿区列表
        self.init()
        # 外部传递的一个变量
        self.reg_user_name = ''

    def init(self):
        # 查询所有的煤炭基地
        mine_base_list = SQLClientHelper.GetMineBaseList()
        if len(mine_base_list) == 0:return
        # 填充煤炭基地列表
        for mine_base in mine_base_list:
            self.ui.base.addItem(mine_base.name.decode('utf-8'), mine_base.id)
        # 默认选中第1个
        self.ui.base.setCurrentIndex(0)

    def onMineBaseChanged(self, index):
        # 清空矿区列表
        self.ui.region.clear()
        # 查询煤炭基地对应的矿区
        mine_base_id, ok = self.ui.base.itemData(index).toInt()
        if not ok:return

        # 查询煤炭基地辖制的矿区
        mine_region_list = SQLClientHelper.GetMineRegionListByField1('mine_base_id', str(mine_base_id))
        if len(mine_region_list) == 0:return
        # 填充矿区列表
        for mine_region in mine_region_list:
            # 从数据库中提取的字符串是utf-8编码的
            self.ui.region.addItem(mine_region.name.decode('utf-8'), mine_region.id)
        # 默认选中第1个
        self.ui.region.setCurrentIndex(0)

    def onReg(self):
        uname = unicode(self.ui.username.text()).encode('utf-8')
        pwd = unicode(self.ui.password.text()).encode('utf-8')
        # 检查用户名是否已注册
        if sql_check_user(uname, pwd):
            QtGui.QMessageBox.information(self, u"提示",'用户名已经被注册了,换一个吧!')
        else:
            # 注册新用户
            account_id = sql_create_user(uname, pwd)
            if account_id < 0:
                QtGui.QMessageBox.information(self, u"提示",'抱歉，注册失败\n请联系技术人员(错误码:A1)!')
                return

            # 从界面中读取数据
            mine_name = unicode(self.ui.name.text()).encode('utf-8')
            mine_province = unicode(self.ui.province.text()).encode('utf-8')
            mine_city = unicode(self.ui.city.text()).encode('utf-8')
            mine_region = unicode(self.ui.region.currentText()).encode('utf-8')
            # 注册新矿井
            mine_id = sql_create_mine(mine_name, mine_province, mine_city, mine_region, account_id)
            # 注册新矿井失败
            if mine_id < 0:
                # 删除新注册用户
                SQLClientHelper.DeleteAccount(account_id)
                QtGui.QMessageBox.information(self, u"提示",'抱歉，注册失败\n请联系技术人员(错误码:A2)!')
                return

            # 分解煤层编号(空格分隔)
            mine_coal_names = unicode(self.ui.coal_nums.text()).encode('utf-8')
            # 分解成字符串列表
            mine_coal_names = mine_coal_names.strip().split()
            # 去除重复编号名称
            mine_coal_names = list(set(mine_coal_names))

            # 新建煤层(逐个添加到数据)
            coal_ids = []
            for name in mine_coal_names:
                coal_ids.append(sql_create_coal(name, mine_id))
            # 增加煤层失败,删除添加的所有煤层
            if -1 in coal_ids:
                # 删除已增加的所有煤层
                SQLClientHelper.DeleteMoreCoal(coal_ids)
                # 删除已注册的矿井
                SQLClientHelper.DeleteMine(mine_id)
                # 删除已注册的用户
                SQLClientHelper.DeleteAccount(account_id)
                QtGui.QMessageBox.information(self, u"提示",'抱歉，注册失败\n请联系技术人员(错误码:A3)!')
            else:
                QtGui.QMessageBox.information(self, u"提示",'恭喜您，注册成功啦!')
                # 记录注册成功的用户(用于外部调用)
                self.reg_user_name = uname
                # 关闭对话框,并返回1
                self.accept()
