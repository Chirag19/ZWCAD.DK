// dllmain.cpp :
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE SignEntityUiDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{

	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("SignEntityUi.DLL is initializing!\n");
		

		if (!AfxInitExtensionModule(SignEntityUiDLL, hInstance))
			return 0;

		new CDynLinkLibrary(SignEntityUiDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("SignEntityUi.DLL is aborting !\n");

		AfxTermExtensionModule(SignEntityUiDLL);
	}
	return 1;   // OK
}
