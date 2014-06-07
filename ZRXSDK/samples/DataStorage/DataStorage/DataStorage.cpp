// DataStorage : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>
#include "XDataAndXDict.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE DataStorageDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("SimpleLine.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(DataStorageDLL, hInstance))
			return 0;

		new CDynLinkLibrary(DataStorageDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("DataStorage.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(DataStorageDLL);
	}
	return 1;   // ok
}

void initApp();
void unloadApp();

void initApp()
{
	//register commands with the ZwCAD command mechanism
	zcedRegCmds->addCommand("DATA_STORAGE_CMD_GROUP", "_AttachXData",	"AttachXData",		ZCRX_CMD_TRANSPARENT, attachXDataToEntity);
	zcedRegCmds->addCommand("DATA_STORAGE_CMD_GROUP", "_AttachXRecord", "AttachXRecord",	ZCRX_CMD_TRANSPARENT, attachXRecordToEntity);
	zcedRegCmds->addCommand("DATA_STORAGE_CMD_GROUP", "_ListXData",		"ListXData",		ZCRX_CMD_TRANSPARENT, listXDataFromEntity);
	zcedRegCmds->addCommand("DATA_STORAGE_CMD_GROUP", "_ListXRecord",	"ListXRecord",		ZCRX_CMD_TRANSPARENT, listXRecordFromEntity);
}

void unloadApp()
{
	//remove a command goup
	zcedRegCmds->removeGroup("DATA_STORAGE_CMD_GROUP");
}

extern "C" ZcRx::AppRetCode
zcrxEntryPoint(ZcRx::AppMsgCode msg, void* pkt)
{ 

	switch (msg)
	{
	case ZcRx::kInitAppMsg:
		zcrxDynamicLinker->unlockApplication(pkt);
		zcrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case ZcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;

	}

	return ZcRx::kRetOK;
}