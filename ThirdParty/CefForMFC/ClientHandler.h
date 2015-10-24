#ifndef __CEFSimpleSample__ClientHandler__  
#define __CEFSimpleSample__ClientHandler__  

#include "include/cef_render_process_handler.h"  
#include "include/cef_client.h"  
#include "include/cef_v8.h"  
#include "include/cef_browser.h"  

class ClientHandler : 
	public CefClient, 
	public CefLifeSpanHandler {  
public:  
	ClientHandler();  

	CefRefPtr<CefBrowser> GetBrowser()  
	{  
		return m_Browser;  
	}  

	CefWindowHandle GetBrowserHwnd()  
	{  
		return m_BrowserHwnd;  
	}  

	// CefClient methods  
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE  
	{  
		return this;  
	}  

	// Virutal on CefLifeSpanHandler  
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;  
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;  
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;  

protected:  
	// The child browser window  
	CefRefPtr<CefBrowser> m_Browser;  

	// The child browser window handle  
	CefWindowHandle m_BrowserHwnd;  

	IMPLEMENT_REFCOUNTING(ClientHandler);  
};  

#endif /* defined(__CEFSimpleSample__ClientHandler__) */