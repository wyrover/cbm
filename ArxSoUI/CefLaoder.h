#pragma once

#include <Util/Singleton.h>
#include "simple_app.h"
#include "simple_handler.h"

/**
参考资料:
《在mfc中使用cef实现webkit的浏览器》
http://www.heycode.com/a13693.html
http://www.heycode.com/a13694.html
http://www.heycode.com/a13695.html
http://www.heycode.com/a13696.html
*/
class CefLaoder : public Singleton<CefLaoder>
{
public:
	CefLaoder(HINSTANCE _hInstance);
	virtual ~CefLaoder(void);

	void createWindow(HWND hParent, const ::CRect& windowRect);
	CefRefPtr<SimpleApp> getApp();
	//CefRefPtr<CefBrowser> getBrowser();
protected:
	HINSTANCE hInstance;                                //当前模块(exe、dll的句柄)
	CefRefPtr<SimpleApp> app;
	//CefRefPtr<CefBrowser> browser;
	CefRefPtr<SimpleHandler> handler;
};
