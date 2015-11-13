#coding:utf-8

from uipy.ui_mainwin import *
from dialogs.LoginDlg import *
from dialogs.SampleManageDlg import *
from dialogs.MineDeginDlg import *
from dialogs.MineBaseParamDlg import *
from dialogs.DifficultEvalDlg import *
from dialogs.MineGasReservesPredictDlg import *
from dialogs.MineGasFlowPredictDlg import *
from dialogs.TwsGasFlowPredictDlg import *
from dialogs.WsGasFlowPredictDlg import *
from dialogs.HighDrillingTunnelDlg import *
from dialogs.HighDrillingDesignDlg import *
from dialogs.DrillingRadiusDlg import *
from dialogs.PoreSizeDlg import *
from dialogs.PoreFlowDlg import *
from dialogs.GasDesignDlg import *
import doc

class MainWindow(QtGui.QMainWindow):  
	def __init__(self,parent=None):
		super(MainWindow, self).__init__(parent)
		self.ui = Ui_MainWindow()
		self.ui.setupUi(self)
		self.init()
		ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID("myappid")

	def init(self):
		self.myActions = []
		self.loginAction = None
		self.logoutAction = None
		self.setAttribute(QtCore.Qt.WA_DeleteOnClose)
		self.createActions()
		self.createMenusToolBars()
		self.createStatusBar()
		self.setWindowTitle(u"井下煤层气规模化抽采计算机辅助设计（CAD）系统——数据录入模块")
		self.setWindowIcon(QtGui.QIcon(':/images/cbm.ico'))
		palette1 = QtGui.QPalette()
		#palette1.setColor(self.backgroundRole(), QColor(192,253,123))#设置背景颜色
		palette1.setBrush(self.backgroundRole(), QtGui.QBrush(QtGui.QPixmap(':/images/bg.png')))
		self.setPalette(palette1)
	
	def closeEvent(self, event):
		reply = QtGui.QMessageBox.question(
			self, u'确认', u'确定退出本系统?', QtGui.QMessageBox.Yes, QtGui.QMessageBox.No)
		if reply == QtGui.QMessageBox.Yes:
			# 注销
			self.logout()

			event.accept()
		else:
			event.ignore()

	def login(self):
		"""返回True或False"""  
		dialog = LoginDialog()  
		if dialog.exec_():  
			self.loginAction.setEnabled(False)
			self.logoutAction.setEnabled(True)
			return True  
		else:  
			return False 

	def logout(self):  
		# 注销(清空sys_info表)
		print '--->',SQLClientHelper.GetSysInfoIds(),'\n'
		SQLClientHelper.DeleteMoreSysInfo(SQLClientHelper.GetSysInfoIds())
		# 设置菜单激活状态
		self.loginAction.setEnabled(True)
		self.logoutAction.setEnabled(False)

	def sampleManage(self):
		dlg = SampleManageDlg()
		dlg.exec_() 
		
	def deginMine(self):
		dlg = MineDeginDlg()
		dlg.exec_() 

	def dragTec(self):
		dlg = MineBaseParamDlg()
		dlg.exec_()

	def difficultEval(self):
		dlg = DifficultEvalDlg()
		dlg.exec_()

	def mineGasReservesPredict(self):
		dlg = MineGasReservesPredictDlg()
		dlg.exec_()

	def mineGasFlowPredict(self):
		dlg = MineGasFlowPredictDlg()
		dlg.exec_()

	def twsGasFlowPredict(self):
		dlg = TwsGasFlowPredictDlg()
		dlg.exec_()

	def wsGasFlowPredict(self):
		dlg = WsGasFlowPredictDlg()
		dlg.exec_()

	def highDrillingTunnel(self):
		dlg = HighDrillingTunnelDlg()
		dlg.exec_()

	def highDrillingPore(self):
		dlg = HighDrillingDesignDlg()
		dlg.exec_()

	def drillingRadius(self):
		dlg = DrillingRadiusDlg()
		dlg.exec_()

	def poreSize(self):
		dlg = PoreSizeDlg()
		dlg.exec_()

	def poreFlow(self):
		dlg = PoreFlowDlg()
		dlg.exec_()

	def evaluationUnitDivision(self):
		pass

	def wsGasDesign(self):
		dlg = GasDesignDlg(2)
		dlg.exec_()

	def twsGasDesign(self):
		dlg = GasDesignDlg(1)
		dlg.exec_()

	def goafGasDesign(self):
		pass

	def openOfficeNet(self):
		doc.OpenNet('http://www.ccri.com.cn/')

	#查看《煤层气资源勘察技术规范》文档
	def investigationOfCBMResources(self):
		doc.OpenPDFFile(u'help\\pdf\\煤层气资源勘察技术规范.pdf')

	#查看《保护层开采技术规范》文档
	def protectiveLayerMining(self):
		doc.OpenPDFFile('help\\pdf\\保护层开采技术规范.pdf')

	#查看《煤矿瓦斯抽放规范》文档
	def coalMineGasDrainage(self):
		doc.OpenPDFFile(u'help\\pdf\\煤矿瓦斯抽放规范.pdf')

	#查看《煤矿瓦斯抽放技术规范》文档
	def technicalSpecificationCoalMineGasDrainage(self):
		doc.OpenPDFFile(u'help\\pdf\\煤矿瓦斯抽放技术规范.pdf')

	#查看《煤矿瓦斯抽采工程设计规范》文档
	def coalMineGasDrainageEngineeringDesign(self):
		doc.OpenPDFFile(u'help\\pdf\\煤矿瓦斯抽采工程设计规范.pdf')

	#查看《煤矿瓦斯抽采达标暂行规定》文档
	def standardInterimProvisions(self):
		doc.OpenPDFFile(u'help\\pdf\\煤矿瓦斯抽采达标暂行规定.pdf')

	#查看《煤层气(煤矿瓦斯)开发利用十二五规划》文档
	def coalGasDevelopment(self):
		doc.OpenPDFFile(u'help\\pdf\\煤层气(煤矿瓦斯)开发利用十二五规划.pdf')

	#查看《煤矿瓦斯抽采基本指标》文档
	def basicCoalMineGasIndex(self):
		doc.OpenPDFFile(u'help\\pdf\\煤矿瓦斯抽采基本指标.pdf')


	def buildAction(self,name,tip,trigger):
		return QtGui.QAction(name, self, statusTip=tip, triggered=trigger)

	def regAction(self,menu,name,tip,trigger):
		return self.myActions.append([menu,name,tip,trigger])

	def createActions(self):
		self.regAction(u"账户管理", u"登录", u"用户登录", self.login)
		self.regAction(u"账户管理", u"注销", u"注销用户", self.logout)		
		self.regAction(u"设计模块", u"示范矿区技术管理", u"对示范矿区进行技术管理", self.sampleManage)
		self.regAction(u"设计模块", u"矿井设计", u"设计本矿井", self.deginMine)
		self.regAction(u"辅助决策", u"抽采技术模式", u"抽采技术模式辅助决策", self.dragTec)
		self.regAction(u"辅助计算", u"煤层气抽采难易程度评价", u"煤层气抽采难易程度评价辅助计算", self.difficultEval)
		self.regAction(u"辅助计算", u"矿井煤层气储量及可抽量预测", u"矿井煤层气储量及可抽量预测辅助计算", self.mineGasReservesPredict)
		self.regAction(u"辅助计算", u"矿井瓦斯涌出量预测", u"矿井瓦斯涌出量预测辅助计算", self.mineGasFlowPredict)
		self.regAction(u"辅助计算", u"掘进面瓦斯涌出量预测", u"掘进面瓦斯涌出量预测辅助计算", self.twsGasFlowPredict)
		self.regAction(u"辅助计算", u"回采面瓦斯涌出量预测", u"回采面瓦斯涌出量预测辅助计算", self.wsGasFlowPredict)
		self.regAction(u"辅助计算", u"高抽巷合理布设层位", u"高抽巷合理布设层位辅助计算", self.highDrillingTunnel)
		self.regAction(u"辅助计算", u"高位抽采钻孔有效布设范围", u"高位抽采钻孔有效布设范围辅助计算", self.highDrillingPore)
		self.regAction(u"辅助计算", u"煤层瓦斯抽采半径", u"煤层瓦斯抽采半径辅助计算", self.drillingRadius)
		self.regAction(u"辅助计算", u"抽采管径大小", u"抽采管径大小辅助计算", self.poreSize)
		self.regAction(u"辅助计算", u"孔板流量", u"孔板流量辅助计算", self.poreFlow)
		self.regAction(u"辅助计算", u"评价单元划分", u"评价单元划分辅助计算", self.evaluationUnitDivision)
		self.regAction(u"抽采设计", u"工作面", u"工作面瓦斯抽采辅助设计", self.wsGasDesign)
		self.regAction(u"抽采设计", u"掘进面", u"掘进面瓦斯抽采辅助设计", self.twsGasDesign)
		self.regAction(u"抽采设计", u"采空区", u"采空区瓦斯抽采辅助设计", self.goafGasDesign)
		self.regAction(u"帮助文档", u"官网", u"打开官网", self.openOfficeNet)
		self.regAction(u"帮助文档", u"煤层气资源勘察技术规范", u"查看《煤层气资源勘察技术规范》文档", self.investigationOfCBMResources)
		self.regAction(u"帮助文档", u"保护层开采技术规范", u"查看《保护层开采技术规范》文档", self.protectiveLayerMining)
		self.regAction(u"帮助文档", u"煤矿瓦斯抽放规范", u"查看《煤矿瓦斯抽放规范》文档", self.coalMineGasDrainage)
		self.regAction(u"帮助文档", u"煤矿瓦斯抽放技术规范", u"查看《煤矿瓦斯抽放技术规范》文档", self.technicalSpecificationCoalMineGasDrainage)
		self.regAction(u"帮助文档", u"煤矿瓦斯抽采工程设计规范", u"查看《煤矿瓦斯抽采工程设计规范》文档", self.coalMineGasDrainageEngineeringDesign)
		self.regAction(u"帮助文档", u"煤矿瓦斯抽采达标暂行规定", u"查看《煤矿瓦斯抽采达标暂行规定》文档", self.standardInterimProvisions)
		self.regAction(u"帮助文档", u"煤层气(煤矿瓦斯)开发利用十二五规划", u"查看《煤层气(煤矿瓦斯)开发利用十二五规划》文档", self.coalGasDevelopment)
		self.regAction(u"帮助文档", u"煤矿瓦斯抽采基本指标", u"查看《煤矿瓦斯抽采基本指标》文档", self.basicCoalMineGasIndex)

	def createMenusToolBars(self):
		menus = {}
		toolBars = {}
		for menu,name,tip,trigger in self.myActions:
			action = self.buildAction(name,tip,trigger)
			if name == u"登录":
				self.loginAction = action
				self.loginAction.setEnabled(False)
			if name == u"注销":
				self.logoutAction = action
			if menu not in menus:
				menus[menu] = self.menuBar().addMenu(menu)
				# toolBars[menu] = self.addToolBar(menu)
			menus[menu].addAction(action)
			# 增加工具栏
			# toolBars[menu].addAction(action)

	def createStatusBar(self):
		self.statusBar().showMessage(u"欢迎使用\"井下煤层气规模化抽采计算机辅助设计（CAD）系统——数据录入模块\"")


def loginFirst():  
	"""返回True或False"""  
	dialog = LoginDialog()  
	if dialog.exec_():
		return True  
	else:  
		return False  

def run():
	import sys
	app =QtGui.QApplication(sys.argv)
	QtCore.QTextCodec.setCodecForCStrings(QtCore.QTextCodec.codecForName("UTF-8"))
	if loginFirst():
		mw = MainWindow()
		mw.show()
		app.exec_()