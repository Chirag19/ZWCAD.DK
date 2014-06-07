// MenuToolbar.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>
#include "IcadTLB.h"
#include "Icad_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE MenuToolbarDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("MenuToolbar.DLL Initializing!\n");

		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(MenuToolbarDLL, hInstance))
			return 0;

		new CDynLinkLibrary(MenuToolbarDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("MenuToolbar.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(MenuToolbarDLL);
	}
	return 1;   // ok
}

void CustomMenu()
{
	IIcadApplication* pZwcad = NULL;
	IIcadMenuBar* pMenuBar = NULL;
	IIcadMenuGroups* pMenuGroups = NULL;
	IIcadMenuGroup* pMenuGroup = NULL;
	IIcadPopupMenus* pPopupMenus = NULL;
	IIcadPopupMenu* pPopupMenu = NULL;
	IIcadPopupMenuItem* pPopupMenuItem = NULL;

	HRESULT hr = NOERROR;
	LPDISPATCH pZwcadDisp = zcedGetZcadWinApp()->GetIDispatch(TRUE);
	if (pZwcadDisp == NULL)	return;

	hr = pZwcadDisp->QueryInterface(IID_IIcadApplication, (void**)&pZwcad);
	pZwcadDisp->Release();
	if (FAILED(hr)) return;

	pZwcad->get_MenuBar(&pMenuBar);
	pZwcad->get_MenuGroups(&pMenuGroups);
	pZwcad->Release();

	VARIANT index;
	VariantInit(&index);

	V_VT(&index) = VT_I4;
	V_I4(&index) = 0;

	if (pMenuBar)
	{
		pMenuBar->Item(index, &pPopupMenu);
		if (pPopupMenu)
		{
			IIcadPopupMenu* pSubMenu = NULL;
			pPopupMenu->AddSubMenu(index,L"Pop Menu",&pSubMenu);
			if (pSubMenu)
			{
				pSubMenu->AddMenuItem(index,L"Circle",L"Circle", &pPopupMenuItem);
				if (pPopupMenuItem)
				{
					pPopupMenuItem->Release();
					pPopupMenuItem = NULL;
				}
				pSubMenu->Release();
				pSubMenu = NULL;
			}

			pPopupMenu->Release();
			pSubMenu = NULL;
		}
		pMenuBar->Release();
		pMenuBar = NULL;
	}


	pMenuGroups->Item(index,&pMenuGroup);
	pMenuGroups->Release();

	if(pMenuGroup)
	{
		pMenuGroup->get_Menus(&pPopupMenus);
		pMenuGroup->Release();

		if(pPopupMenus)
		{
			pPopupMenus->Add(L"New Menu",&pPopupMenu);
			if(pPopupMenu)
			{
				pPopupMenu->AddMenuItem(index,L"Hello",L"Hello",&pPopupMenuItem);
				if(pPopupMenuItem)
				{
					pPopupMenuItem->Release();
					pPopupMenuItem = NULL;
				}

				pPopupMenu->AddMenuItem(index, L"Line", L"LINE",&pPopupMenuItem);
				if (pPopupMenuItem)
				{
					pPopupMenuItem->Release();
					pPopupMenuItem = NULL;
				}

				pPopupMenu->InsertInMenuBar(index);
				pPopupMenu->Release();
				pPopupMenu = NULL;
			}
			pPopupMenus->Release();
		}
	}
}

void CustomToolbar()
{
	IIcadApplication* pZwcad = NULL;
	IIcadMenuGroups* pMenuGroups = NULL;
	IIcadMenuGroup* pMenuGroup = NULL;
	IIcadToolbars* pToolBars = NULL;
	IIcadToolbar* pToolBar = NULL;
	IIcadToolbarItem* pToolBarItem = NULL;

	HRESULT hr = NOERROR;
	LPDISPATCH pZwcadDisp = zcedGetZcadWinApp()->GetIDispatch(TRUE);
	if (pZwcadDisp == NULL)	return;

	hr = pZwcadDisp->QueryInterface(IID_IIcadApplication, (void**)&pZwcad);
	pZwcadDisp->Release();
	if (FAILED(hr)) return;

	VARIANT index;
	VariantInit(&index);
	V_VT(&index) = VT_I4;
	V_I4(&index) = 0;

	pZwcad->get_MenuGroups(&pMenuGroups);
	pZwcad->Release();

	pMenuGroups->Item(index,&pMenuGroup);
	pMenuGroups->Release();

	if (pMenuGroup)
	{
		pMenuGroup->get_Toolbars(&pToolBars);
		if (pToolBars)
		{
			VARIANT FlyoutButton;
			VariantInit(&FlyoutButton);

			V_VT(&FlyoutButton) = VT_BOOL;
			V_I4(&FlyoutButton) = VARIANT_FALSE;

			pToolBars->Add(L"ComToolBar",&pToolBar);
			if (pToolBar)
			{
				pToolBar->AddToolbarButton(index,L"Line",L"Draw Line",L"Line",FlyoutButton,&pToolBarItem);
				if(pToolBarItem)
				{
					//hr = pToolBarItem->SetBitmaps(L"small.ico",L"big.ico");
					pToolBarItem->Release();
					pToolBarItem = NULL;
				}
				pToolBar->Release();
				pToolBar = NULL;
			}

			pToolBars->Add(L"Toolbar2",&pToolBar);
			if (pToolBar)
			{
				V_I4(&FlyoutButton) = VARIANT_TRUE;
				pToolBar->AddToolbarButton(index,L"Line",L"Draw Line",L"Line",FlyoutButton,&pToolBarItem);

				if (pToolBarItem)
				{
					pToolBarItem->AttachToolbarToFlyout(L"ZWCAD",L"Standard");
					pToolBarItem->Release();
				}
				pToolBar->Release();
				pToolBar = NULL;
			}

			pToolBars->Release();
			pToolBars = NULL;
		}
		pMenuGroup->Release();
		pMenuGroup = NULL;
	}
}

void initApp()
{
	//register a command with the ZwCAD command mechanism

	zcedRegCmds->addCommand("CUSTMENU_CMD_GROUP","CustMenu","CustMenu",ZCRX_CMD_TRANSPARENT,CustomMenu);
	zcedRegCmds->addCommand("CUSTMENU_CMD_GROUP","CustToolbar","CustToolbar",ZCRX_CMD_TRANSPARENT,CustomToolbar);
}

void unloadApp()
{
	//remove a command goup

	zcedRegCmds->removeGroup("CUSTMENU_CMD_GROUP");
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