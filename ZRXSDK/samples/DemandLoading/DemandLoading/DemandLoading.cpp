// DemandLoading.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>
#include "SignEntity.h"
#include "CustomDblClickEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE DemandLoadingDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("SimpleLine.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(DemandLoadingDLL, hInstance))
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

		new CDynLinkLibrary(DemandLoadingDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("DemandLoading.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(DemandLoadingDLL);
	}
	return 1;   // ok
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

void cmdPrintInfomation()
{
	zcutPrintf("\n The test for demand loading on command invocation");
}

void cmdCreateCustomEntity()
{
	zcutPrintf("\n The test for demand loading on detection of custom objects");
	SignEntity* pEnt = new SignEntity();
	ZcDbObjectId objId;
	if (false == addEntityToDb(objId, pEnt))
	{
		delete pEnt;
	}
	pEnt->close();
}

void cmdDemandLoadRegister()
{
	ZcadAppInfo thisAppInfo;
	thisAppInfo.setAppName(_T("DemandLoadingApp"));
	thisAppInfo.setModuleName(zcedGetAppName());
	thisAppInfo.setAppDesc(_T("DemandLoadingApp2011"));
	thisAppInfo.setLoadReason(ZcadApp::LoadReasons(ZcadApp::kOnProxyDetection 
		| ZcadApp::kOnCommandInvocation | ZcadApp::kOnLoadRequest));	
	thisAppInfo.writeToRegistry(false,true);	
	thisAppInfo.writeGroupNameToRegistry(_T("DLOAD_CMD_GROUP"));
	thisAppInfo.writeCommandNameToRegistry(_T("PrintInfo"),_T("PrintInfo"));
}

void initApp()
{
	//register a command with the ZwCAD command mechanism
	zcedRegCmds->addCommand("DLOAD_CMD_GROUP","PrintInfo","PrintInfo",ZCRX_CMD_TRANSPARENT,cmdPrintInfomation);
	zcedRegCmds->addCommand("DLOAD_CMD_GROUP","CrtCustEnt","CrtCustEnt",ZCRX_CMD_TRANSPARENT,cmdCreateCustomEntity);
	zcedRegCmds->addCommand("DLOAD_CMD_GROUP","RegLoadInfo","RegLoadInfo",ZCRX_CMD_TRANSPARENT,cmdDemandLoadRegister);
	SignEntity::rxInit();
	CustomDblClickEdit* pCustEntDblEdit = new CustomDblClickEdit;
	SignEntity::desc()->addX(ZcDbDoubleClickEdit::desc(), pCustEntDblEdit);

}

void unloadApp()
{
	//remove a command goup
	zcedRegCmds->removeGroup("DLOAD_CMD_GROUP");
	SignEntity::desc()->delX(ZcDbDoubleClickEdit::desc());
	deleteZcRxClass(SignEntity::desc());
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