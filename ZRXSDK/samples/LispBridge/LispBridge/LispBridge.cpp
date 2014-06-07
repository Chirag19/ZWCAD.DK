// LispBridge.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


static AFX_EXTENSION_MODULE LispBridgeDLL = { NULL, NULL };


//If you want to call this function, you need to declare like this.
extern int zcedQueueExpr(ZCHAR * lisp_expr);

static int EntLastXX();
static int EntGetXX();


CString g_strLispAppPath;

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("SimpleLine.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(LispBridgeDLL, hInstance))
			return 0;

		new CDynLinkLibrary(LispBridgeDLL);

		TCHAR strCurrentPath[MAX_PATH];
		GetModuleFileName(hInstance, strCurrentPath, MAX_PATH);
		g_strLispAppPath = strCurrentPath;
		int intPos = g_strLispAppPath.ReverseFind('\\');
		g_strLispAppPath = g_strLispAppPath.Left(intPos);
		intPos = g_strLispAppPath.ReverseFind('\\');
		g_strLispAppPath = g_strLispAppPath.Left(intPos);
		g_strLispAppPath += "\\LispBridge\\drawline.lsp";

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("LispBridge.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(LispBridgeDLL);
	}
	return 1;   // ok
}


CString GetLoadCmdStr(CString& strInput)
{
	CString strReturn(strInput);
	CString strLoad(_T("load"));
	strReturn.Replace(_T("\\"), _T("\\\\"));
	strReturn = _T("(") + strLoad + _T('\x20') + _T('\"') + strReturn + _T('\"') + _T(")");
	return strReturn;
}

void cmdInvokeLispFun()
{
	CString strCmdLisp = "drawline";
	zcedQueueExpr((ZCHAR*)strCmdLisp.GetBuffer());
}

void initApp()
{
	//register a command with the ZwCAD command mechanism
	zcedRegCmds->addCommand("LISPBRIDGE_CMD_GROUP","InvkLsp","InvkLsp",ZCRX_CMD_TRANSPARENT,cmdInvokeLispFun);

	// define and register external lisp functions
	zcedDefun("EntLastXX",	1);

#ifndef _USING_INVKSUBRMSG
	zcedRegFunc(EntLastXX,	1);
#endif //_USING_INVKSUBRMSG

	zcedDefun("EntGetXX",	2);

#ifndef _USING_INVKSUBRMSG
	zcedRegFunc(EntGetXX,	2);
#endif //_USING_INVKSUBRMSG

	//load the lisp app file : drawline.lsp
	CString strCmdLine = GetLoadCmdStr(g_strLispAppPath) + _T(" ");
	zcedQueueExpr((ZCHAR*)strCmdLine.GetBuffer());
}

void unloadApp()
{
	//remove a command goup
	zcedRegCmds->removeGroup("LISPBRIDGE_CMD_GROUP");
	// undefine external lisp functions
	zcedUndef("EntLastXX",	1);
	zcedUndef("EntGetXX",	2);


}

#ifdef _USING_INVKSUBRMSG

void doFun(int intCode)
{
	switch (intCode)
	{
	case 1:
		EntLastXX();
		break;
	case 2:
		EntGetXX();
		break;
	default:
		break;
	}
}

#endif//_USING_INVKSUBRMSG

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
#ifdef _USING_INVKSUBRMSG		
	case ZcRx::kInvkSubrMsg:
		doFun(zcedGetFunCode());
		break;
#endif//_USING_INVKSUBRMSG
	case ZcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;

	}

	return ZcRx::kRetOK;
}


static int EntLastXX()
{
	zds_name ename;
	zcdbEntLast(ename);	
	zcedRetName(ename, RTENAME);

	return RTNORM;
}

static int EntGetXX()
{
	zds_name ename;
	struct resbuf* pRbArgs = NULL;
	pRbArgs = zcedGetArgs();
	if (pRbArgs == NULL)
	{
		return RTERROR;
	}

	if (pRbArgs->restype != RTENAME)
	{
		zcutRelRb(pRbArgs);
		return RTERROR;
	}

	zds_name_set(pRbArgs->resval.rlname, ename);
	zcutRelRb(pRbArgs);
	resbuf* pRbEnt = NULL;
	pRbEnt = zcdbEntGet(ename);
	int nRes = zcedRetList(pRbEnt);	
	zcutRelRb(pRbEnt);

	return RTNORM;
}



