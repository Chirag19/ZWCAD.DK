// SimpleLine.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE SimpleLineDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("SimpleLine.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(SimpleLineDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(SimpleLineDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("SimpleLine.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(SimpleLineDLL);
	}
	return 1;   // ok
}


void initApp();
void unloadApp();
void drawSimpleLine();


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

void initApp()
{
	// register a command with the ZwCAD command mechanism
	zcedRegCmds->addCommand("SIMPLINE_CMDS",
		"DrawLine",
		"DrawLine",
		ZCRX_CMD_TRANSPARENT,
		drawSimpleLine);
}

void unloadApp()
{
	zcedRegCmds->removeGroup("SIMPLINE_CMDS");
}

bool addEntityToDb(ZcDbObjectId& entId, ZcDbEntity * pEnt)
{
	ZcDbDatabase * pDb = zcdbHostApplicationServices()->workingDatabase();

	if (!pDb) return false;

	ZcDbBlockTable* pTbl = NULL;
	if (Zcad::eOk != pDb->getBlockTable(pTbl, ZcDb::kForRead) )
		return false;

	ZcDbBlockTableRecord* pTblRec = NULL;
	if (Zcad::eOk != pTbl->getAt(ZCDB_MODEL_SPACE, pTblRec, ZcDb::kForWrite))
	{
		pTbl->close();
		return false;
	}

	pTbl->close();

	if (Zcad::eOk != pTblRec->appendZcDbEntity(entId, pEnt))
	{
		pTblRec->close();
		return false;
	}

	pTblRec->close();

	return true;
}

void drawSimpleLine()
{

	ZcGePoint3d pntStart;
	ZcGePoint3d pntEnd;

	if (RTNORM != zcedGetPoint( NULL, "\n Input the start point:", asDblArray(pntStart)))
		return;

	if (RTNORM != zcedGetPoint( asDblArray(pntStart), "\n Input the end point:", asDblArray(pntEnd) ))
		return;

	ZcDbLine* pLine = new ZcDbLine(pntStart, pntEnd);

	ZcDbObjectId eId;
	addEntityToDb(eId, pLine);

	pLine->close();

}