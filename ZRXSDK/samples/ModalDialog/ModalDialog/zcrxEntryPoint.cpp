#include "StdAfx.h"
#include "ZwDialog.h"

// ZRX Application Entry Point
class CModalDialogApp  : public ZcRxZrxApp 
{
public:
	CModalDialogApp () : ZcRxZrxApp() 
	{
	}

	virtual ZcRx::AppRetCode On_kInitAppMsg(void *pkt) 
	{

		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kInitAppMsg(pkt) ;
		
		// TODO: Add your initialization code here		

		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kUnloadAppMsg(void *pkt)
	{

		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kUnloadAppMsg(pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () 
	{
		// Add your code for register server components
	}

public:

	static void ModalDialog_CreateDialog(void)
	{
		// Add your code for command ModalDialog._CreateDialog here
		CZwDialog dlg;
		dlg.DoModal();
	}


} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ZRX_ENTRYPOINT(CModalDialogApp)

ZCED_ZRXCOMMAND_ENTRY_AUTO(CModalDialogApp, ModalDialog, _CreateDialog, CreateDialog, ZCRX_CMD_TRANSPARENT, NULL)
