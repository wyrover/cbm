#pragma once

using namespace SOUI;

#include "Singleton.h"

//参考demo例子中的main函数soui加载过程
//用类的形式进行封装,试图简化代码~
class SoUILoader : public Singleton<SoUILoader>
{
public:
	SoUILoader(HINSTANCE _hInstance);
	virtual ~SoUILoader();
	bool init();
	SApplication* getApp();
	CString getResName() const;

protected:
	//设置uires文件夹的所在路径
	virtual LPCTSTR getSkinDir() const;
	virtual bool initRender();
	virtual bool initApp();
	virtual bool initResource();
	virtual bool initScripts();
	virtual bool initExtendControls();
	virtual bool initSysResource();
	virtual bool initRealWnd();
	virtual bool initGlobalStyle();
	SComMgr* getComMrg();
protected:
	HINSTANCE hInstance;                                //当前模块(exe、dll的句柄)
	SComMgr comMgrObj;                                  // 组件加载管理器
	CAutoRefPtr<IImgDecoderFactory> pImgDecoderFactory; //图片解码器
	CAutoRefPtr<IRenderFactory> pRenderFactory;         //UI渲染模块,由render-gdi.dll或render-skia.dll提供
	//CAutoRefPtr<ITranslatorMgr> trans;                //多语言翻译模块,由translator.dll提供
	CAutoRefPtr<IScriptFactory> pScriptLua;             //lua脚本模块,由scriptmodule-lua.dll提供
	SApplication* pSouiApp;
};
