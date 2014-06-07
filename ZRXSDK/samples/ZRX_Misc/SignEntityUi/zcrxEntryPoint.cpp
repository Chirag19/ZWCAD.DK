#include "StdAfx.h"
#include "resource.h"
#include "CommandFuncts.h"
#include "CmdEditReactor.h"


// Application Entry Point
class CmdEntryApp : public ZcRxZrxApp 
{
public:
	CmdEntryApp () : ZcRxZrxApp() 
	{
		m_pCmdRezct = NULL;
	}

	virtual ZcRx::AppRetCode On_kInitAppMsg(void *pkt) 
	{

		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kInitAppMsg(pkt) ;
		
		// TODO: Add your initialization code here		
		if (zcedEditor && !m_pCmdRezct)
		{
			m_pCmdRezct = new CmdEditReactor();
			zcedEditor->addReactor(m_pCmdRezct) ;
		}

		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kUnloadAppMsg(void *pkt)
	{

		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kUnloadAppMsg(pkt) ;

		// TODO: Unload dependencies here
		if (zcedEditor && m_pCmdRezct)
		{
			zcedEditor->removeReactor (m_pCmdRezct) ;
			m_pCmdRezct = NULL;
		}

		return (retCode) ;
	}

	virtual void RegisterServerComponents () 
	{
		// Add your code for register server components
	}

public:

	static void MiscCmdGroupCreateSign(void)
	{
		cmdCreateSign();
	}

private:
	CmdEditReactor* m_pCmdRezct;
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ZRX_ENTRYPOINT(CmdEntryApp)

ZCED_ZRXCOMMAND_ENTRY_AUTO(CmdEntryApp, MiscCmdGroup, CreateSign, CreateSign, ZCRX_CMD_TRANSPARENT, NULL)
