#include "StdAfx.h"
#include "resource.h"


// Application Entry Point
class SignEntityApp : public ZcRxDbxApp
{

public:
	SignEntityApp() : ZcRxDbxApp() {}

	virtual ZcRx::AppRetCode On_kInitAppMsg(void *pkt) 
	{

		ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kInitAppMsg(pkt) ;

		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kUnloadAppMsg(void *pkt) 
	{

		ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kUnloadAppMsg(pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents() 
	{
		DllRegisterServer();
	}

} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ZRX_ENTRYPOINT(SignEntityApp)

