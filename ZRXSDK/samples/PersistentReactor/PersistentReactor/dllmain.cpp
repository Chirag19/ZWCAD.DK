// dllmain.cpp : 

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE PersistentReactorDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{

	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("PersistentReactor.DLL is initializing!\n");
		

		if (!AfxInitExtensionModule(PersistentReactorDLL, hInstance))
			return 0;


		new CDynLinkLibrary(PersistentReactorDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("PersistentReactor.DLL is aborting!\n");


		AfxTermExtensionModule(PersistentReactorDLL);
	}
	return 1;  
}


