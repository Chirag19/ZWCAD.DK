// dllmain.cpp : 

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE SignEntityUiDLL = { NULL, NULL };

CString g_strImageSource = NULL;

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{

	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("RasterImage.dll is initializing!\n");
		
		if (!AfxInitExtensionModule(SignEntityUiDLL, hInstance))
			return 0;


		new CDynLinkLibrary(SignEntityUiDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("RasterImage.dll is aborting!\n");

		AfxTermExtensionModule(SignEntityUiDLL);
	}

	// Set the path of the sample image file 
	char strImageFile[MAX_PATH];
	GetModuleFileName(hInstance, strImageFile, MAX_PATH);
	g_strImageSource = strImageFile;
	int nPos = g_strImageSource.ReverseFind('\\');
	g_strImageSource = g_strImageSource.Left(nPos);
	nPos = g_strImageSource.ReverseFind('\\');
	g_strImageSource = g_strImageSource.Left(nPos);
	g_strImageSource += "\\RasterImage\\Image.jpg";

	return 1;  
}
