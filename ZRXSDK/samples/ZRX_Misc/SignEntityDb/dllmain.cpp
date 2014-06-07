// dllmain.cpp : 
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE SignEntityDbDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("SignEntityDb.DLL is initializing!\n");
		
		if (!AfxInitExtensionModule(SignEntityDbDLL, hInstance))
			return 0;


		new CDynLinkLibrary(SignEntityDbDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("SignEntityDb.DLL is aborting! \n");

		AfxTermExtensionModule(SignEntityDbDLL);
	}
	return 1;   // OK
}
