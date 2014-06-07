// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ZwInteBase_i.h"
#include "dllmain.h"
#include "ZwInteAPI.h"

CZwInteBaseModule _AtlModule;

class CZwInteBaseApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CZwInteBaseApp, CWinApp)
END_MESSAGE_MAP()

CZwInteBaseApp theApp;
CString g_strSysPath;

BOOL CZwInteBaseApp::InitInstance()
{
	char strModulePathName[MAX_PATH];
	GetModuleFileName(m_hInstance, strModulePathName, MAX_PATH);
	g_strSysPath = strModulePathName;
	int nPos = g_strSysPath.ReverseFind('\\');
	g_strSysPath = g_strSysPath.Left(nPos);
	nPos = g_strSysPath.ReverseFind('\\');
	g_strSysPath = g_strSysPath.Left(nPos);
	g_strSysPath += "\\ZwInteBase\\";

	return CWinApp::InitInstance();
}

int CZwInteBaseApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

void ComInit()
{
	HRESULT hr;
	hr = _AtlModule.RegisterServer(TRUE);
	assert(SUCCEEDED(hr));	
	hr = _AtlModule.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE);
	assert(SUCCEEDED(hr));
	return ;
}

void ComUnInit()
{
	HRESULT hr;
	hr = _AtlModule.UnregisterServer(TRUE);
	assert(SUCCEEDED(hr));
	hr = _AtlModule.RevokeClassObjects();
	assert(SUCCEEDED(hr));
	return ;
}

void TestCmdFunc()
{

}

void initApp()
{
	//register a command with the ZwCAD command mechanism
	zcedRegCmds->addCommand("TEST_CMD_GROUP","TestCmd","TestCmd",ZCRX_CMD_TRANSPARENT,TestCmdFunc);
	ComInit();
}

void unloadApp()
{
	//remove a command goup
	zcedRegCmds->removeGroup("TEST_CMD_GROUP");
	ComUnInit();
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



