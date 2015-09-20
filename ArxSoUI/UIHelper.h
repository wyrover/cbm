#pragma once

class UIHelper
{
public:
	static void InitAllData();
	static void ShowModelessDemo();
	static void ShowModalDemo();
	static void TestRtfViewer();
	static void TestPicViewer();

	static void Login();
	static void Logout();
	static void SampleManage();
	static void GasTechModeDecision();
	static void KeyParamCacl();
	static void PolicyHelp();
	static void Main();

	static void InitSouiEnviroment();
	static void UnInitSouiEnviroment();
	static void ShowImgView(const CString& bstrFileName);
};