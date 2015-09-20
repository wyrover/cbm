#pragma once

class UIHelper
{
public:
    static void InitAllData();
    static void InitSouiEnviroment();
    static void UnInitSouiEnviroment();
    static void ShowModelessDemo();
    static void ShowModalDemo();
    static void TestRtfViewer();
    static void TestPicViewer();
    static void ShowImgView( const CString& bstrFileName );

    //登录
    static void Login();
    //注册
    static void RegMine();
    //注销
    static void Logout();
    //示范矿区技术库管理
    static void SampleManage();
    //辅助决策
    static void GasTechModeDecision();
    //矿井设计
    static void MineDesign();
    //关键参数计算面板
    static void KeyParamCacl();
    //帮助文档面板
    static void PolicyHelp();
    //主界面(测试用)
    static void Main();
    //关键参数计算-煤层气抽采难易程度评价
    static void KP1();
    //关键参数计算-矿井煤层气储量及可抽量预测
    static void KP2();
    //关键参数计算-矿井瓦斯涌出量预测
    static void KP3();
    //关键参数计算-掘进工作面瓦斯涌出量预测
    static void KP4();
    //关键参数计算-回采工作面瓦斯涌出量预测
    static void KP5();
    //关键参数计算-高抽巷合理布设层位计算
    static void KP6();
    //关键参数计算-高位抽采钻孔有效布设范围计算
    static void KP7();
    //关键参数计算-煤层瓦斯抽采半径计算
    static void KP8();
    //关键参数计算-抽采管径大小辅助计算
    static void KP9();
    //关键参数计算-孔板流量计算
    static void KP10();
    //关键参数计算-评价单元划分计算
    static void KP11();

    //煤层气抽采设计
    static void GasDesign();
};