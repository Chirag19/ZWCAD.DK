// dllmain.cpp : 

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE DocumentManagerDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{

	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("DocumentManager.DLL is initializing !\n");
		

		if (!AfxInitExtensionModule(DocumentManagerDLL, hInstance))
			return 0;



		new CDynLinkLibrary(DocumentManagerDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("DocumentManager.DLL is aborting !\n");


		AfxTermExtensionModule(DocumentManagerDLL);
	}
	return 1;   
}
