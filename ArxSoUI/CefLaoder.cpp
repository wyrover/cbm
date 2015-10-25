#include "StdAfx.h"
#include "CefLaoder.h"

#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"

//初始化单例模式的静态成员变量
template<> CefLaoder* Singleton<CefLaoder>::ms_Singleton = 0;

CefLaoder::CefLaoder( HINSTANCE _hInstance ) : hInstance( _hInstance )
{
	void* sandbox_info = NULL;
	CefMainArgs main_args(hInstance);
	
	//CefRefPtr<SimpleApp> app(new SimpleApp);
	app = make_scoped_refptr(new SimpleApp);

	CefSettings settings;
	settings.no_sandbox = true;
	settings.multi_threaded_message_loop=true;
	CefInitialize(main_args, settings, app.get(), sandbox_info);
}

CefLaoder::~CefLaoder(void)
{
	hInstance = 0;
	CefShutdown();
}

void CefLaoder::createWindow(HWND hParent, const ::CRect& windowRect)
{
	// Information used when creating the native window.
	CefWindowInfo window_info;

#if defined(OS_WIN)
	// On Windows we need to specify certain flags that will be passed to
	// CreateWindowEx().
	//(1) 如果作为独立的窗口(popup)
	//window_info.SetAsPopup(NULL, "cefsimple");
	//(2) 如果作为子窗口(child)
	window_info.SetAsChild(hParent, windowRect);
#endif

	// SimpleHandler implements browser-level callbacks.
	handler = make_scoped_refptr(new SimpleHandler());
	//CefRefPtr<SimpleHandler> handler(new SimpleHandler());

	// Specify CEF browser settings here.
	CefBrowserSettings browser_settings;

	std::string url;

	// Check if a "--url=" value was provided via the command-line. If so, use
	// that instead of the default URL.
	//CefRefPtr<CefCommandLine> command_line = CefCommandLine::GetGlobalCommandLine();
	//url = command_line->GetSwitchValue("url");
	//if (url.empty())
		url = "http://www.baidu.com";

	// Create the first browser window.
	CefBrowserHost::CreateBrowser(window_info, handler.get(), url,browser_settings, NULL);
}

CefRefPtr<SimpleApp> CefLaoder::getApp()
{
	return app;
}

//CefRefPtr<CefBrowser> CefLaoder::getBrowser()
//{
//
//}
