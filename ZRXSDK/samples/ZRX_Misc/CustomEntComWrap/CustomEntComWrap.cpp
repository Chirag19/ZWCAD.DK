// CustomEntComWrap.cpp : DLL 

#include "stdafx.h"
#include "resource.h"
#include "CustomEntComWrap.h"

class CCustomEntComWrapModule : public CAtlDllModuleT< CCustomEntComWrapModule >
{
public :
	DECLARE_LIBID(LIBID_CustomEntComWrapLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CUSTOMENTCOMWRAP, "{C3509D67-4924-4B2B-A20B-767C6B0051B1}")
};

CCustomEntComWrapModule _AtlModule;

class CCustomEntComWrapApp : public CWinApp
{
public:

// Override
    virtual BOOL InitInstance();
    virtual int  ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCustomEntComWrapApp, CWinApp)
END_MESSAGE_MAP()

CCustomEntComWrapApp theApp;

BOOL CCustomEntComWrapApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CCustomEntComWrapApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}


// Use to check  if the dll unload by OLE
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
}


// Return a class factory to create the required type object
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Register the server
STDAPI DllRegisterServer(void)
{
    // Register the object, type library and all interface
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Unregister the server
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
