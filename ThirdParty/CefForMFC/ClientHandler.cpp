#include "stdafx.h"  
#include "ClientHandler.h"  

#include "include/cef_app.h"  
#include "include/cef_base.h"  
#include "include/cef_client.h"  
#include "include/cef_command_line.h"  
#include "include/cef_frame.h"  
#include "include/cef_runnable.h"  
#include "include/cef_web_plugin.h"  

ClientHandler::ClientHandler()  
{  
}  

bool ClientHandler::DoClose(CefRefPtr<CefBrowser> browser)  
{  
	return false;  
}  

void ClientHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)  
{  
	if ( !m_Browser.get() ) {  
		// We need to keep the main child window, but not popup windows  
		m_Browser     = browser;  
		m_BrowserHwnd = browser->GetHost()->GetWindowHandle();  
	}  
}  

void ClientHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)  
{  
	if ( m_BrowserHwnd == browser->GetHost()->GetWindowHandle() ) {  
		// Free the browser pointer so that the browser can be destroyed  
		m_Browser = NULL;  
	}  
}  