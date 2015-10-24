#include "stdafx.h"  
#include "ClientApp.h"  

#include "ClientHandler.h"  
#include "ClientV8ExtensionHandler.h"  

ClientApp::ClientApp()  
{  
}  

void ClientApp::OnWebKitInitialized()  
{  
	/*std::string app_code = 
	"var app;" 
	"if (!app)" 
	"    app = {};" 
	"(function() {" 
	"    app.ChangeTextInJS = function(text) {" 
	"        native function ChangeTextInJS();" 
	"        return ChangeTextInJS(text);" 
	"    };" 
	"})();;"; 

	CefRegisterExtension( "v8/app", app_code, new ClientV8ExtensionHandler(this) );*/  
}