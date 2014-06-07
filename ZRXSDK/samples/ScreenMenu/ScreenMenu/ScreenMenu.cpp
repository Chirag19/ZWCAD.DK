#include "stdafx.h"
#include <afxdllx.h>
#include "zrxobject.h"
#include "SCRMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE ScreenMenuDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("ScreenMenu.DLL Initializing!\n");
		
		if (!AfxInitExtensionModule(ScreenMenuDLL, hInstance)) 
			return 0;

		new CDynLinkLibrary(ScreenMenuDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("ScreenMenu.DLL terminating!\n");

		AfxTermExtensionModule(ScreenMenuDLL);
	}
	return 1;
}


static CSCRMenu m_SCRMenu;	// Screen Menu object

UINT CreateScreenMenu(LPVOID pParam)
{
	if(pParam)
	{
		return ((CSCRMenu*)pParam)->ScreenMenu();
	}

	return -1;
}

UINT ShowEntityInfo(LPVOID pParam)
{
	if (!m_SCRMenu.m_hWnd || !pParam)
	{
		return -1;
	}

	long* pNames = (long*)pParam;

	for (int i=0; i<3; i++)
	{
		const char* pName = (const char*)pNames[i];
		m_SCRMenu.m_EntityInfoList.SetItemText(i, 1, pName);
	}

	return 0;
}

void CreatSCRMenu()
{
	zdsw_executeUICommand(CreateScreenMenu, &m_SCRMenu);
}

void GetObjInfo()
{
	zds_name en;
	zds_point pt;

	if (zcedEntSel("Select Entity\n", en, pt) != RTNORM)
	{
		zcutPrintf("Nothing Selected\n");
		return;
	}

	ZcDbObjectId EntId;
	zcdbGetObjectId(EntId, en);
	ZcDbEntity *pEnt;
	if (zcdbOpenObject(pEnt, EntId, ZcDb::kForWrite) != Zcad::eOk)
	{
		zcutPrintf("\nError opening the entity");		
		return;
	}

	const ZCHAR* pName = pEnt->isA()->name();
	const ZCHAR* pLayerName = pEnt->layer();

	ZcDbHandle entHandle;
	ZCHAR strHandle[17];
	pEnt->getZcDbHandle(entHandle);
	pEnt->close();
	entHandle.getIntoAsciiBuffer(strHandle);
	
	long param[3];
	param[0] = (long)pName;
	param[1] = (long)pLayerName;
	param[2] = (long)strHandle;

	zdsw_executeUICommand(ShowEntityInfo, param);

}


void initApp();
void unloadApp();

extern "C" ZcRx::AppRetCode
zcrxEntryPoint(ZcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case ZcRx::kInitAppMsg:
		zcrxDynamicLinker->unlockApplication(pkt);
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

void initApp()
{
	zcedRegCmds->addCommand("SCRMENUGRP",
		"ScrMenu", 
		"ScrMenu",
		ZCRX_CMD_TRANSPARENT,
		CreatSCRMenu);

	zcedRegCmds->addCommand("SCRMENUGRP",
		"ObjInfo", 
		"ObjInfo",
		ZCRX_CMD_TRANSPARENT,
		GetObjInfo);
}

void unloadApp()
{
	zcedRegCmds->removeGroup("SCRMENUGRP");
}
