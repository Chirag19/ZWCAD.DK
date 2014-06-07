// ZwIntePldm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Shlwapi.h"
#include "ZwIntePldm.h"
#include "..\ZwInteBase\ZwInteBase_i.h"
#include "..\ZwInteBase\ZwInteBase_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// 唯一的应用程序对象

CWinApp theApp;

namespace ZwInte
{
	enum Operation
	{
		kForeRead = 0,
		kForeWrite,
	};
}


bool InvokeComInterface(CString inputXml, ZwInte::Operation eOpera);

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;


	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("Error: MFC Initializted is failure\n"));
		nRetCode = 0;
	
	}
	else
	{
		// 1.Parse command line parameters

		/* Example(1): ZwIntePldm.exe /w d:\input.xml
		   Example(2): ZwIntePldm.exe /r d:\input.xml*/		

		CString strInputXml;
		strInputXml = argv[1];
		CString strParameter;
		strParameter = argv[2];
		ZwInte::Operation eOperation;
		if (strParameter.CompareNoCase("/r") == 0 )
		{
			eOperation = ZwInte::kForeRead;
		}
		else if (strParameter.CompareNoCase("/w") == 0 )
		{
			eOperation = ZwInte::kForeWrite;
		}


		//2. Invoke the com interface method

		nRetCode = InvokeComInterface(strInputXml, eOperation);
	}

	return nRetCode;
}

bool InvokeComInterface(CString inputXml, ZwInte::Operation eOpera)
{
	if (!PathFileExists(inputXml)) return false;

	::CoInitialize(NULL);

	HRESULT hr;
	LPCLASSFACTORY pLocalClassFact = NULL;
	IZwInteCom *pInterfaceObj = NULL;

	hr = CoGetClassObject(CLSID_ZwInteCom, CLSCTX_LOCAL_SERVER, NULL,IID_IClassFactory, (void**)&pLocalClassFact);
	if(SUCCEEDED(hr))
	{
		hr = pLocalClassFact->CreateInstance(NULL, IID_IZwInteCom, (void**)&pInterfaceObj);
		if (SUCCEEDED(hr))
		{
			switch (eOpera)
			{
			case ZwInte::kForeRead:
				hr = pInterfaceObj->ReadTbDataX(inputXml.AllocSysString());
				break;
			case ZwInte::kForeWrite:
				hr = pInterfaceObj->WriteTbDataX(inputXml.AllocSysString());
				break;
			default:
				break;
			}
		}
	}

	if(NULL != pLocalClassFact) hr = pLocalClassFact->Release();
	if(NULL != pInterfaceObj) hr = pInterfaceObj->Release();

	::CoUninitialize();

	if (SUCCEEDED(hr)) 	return true;

	return false;
}

