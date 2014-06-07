//-----------------------------------------------------------------------------
//----- CmdEditReactor.cpp : Implementation of CmdEditReactor
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "CmdEditReactor.h"

//-----------------------------------------------------------------------------
ZCRX_CONS_DEFINE_MEMBERS(CmdEditReactor, ZcEditorReactor, 1)

//-----------------------------------------------------------------------------
CmdEditReactor::CmdEditReactor () : ZcEditorReactor() 
{
}

//-----------------------------------------------------------------------------
CmdEditReactor::~CmdEditReactor ()
{
}

//-----------------------------------------------------------------------------

void CmdEditReactor::commandWillStart(const char* cmdStr)
{
    if (strcmp(cmdStr, "CREATESIGN") == 0)
	{
		zcutPrintf("\n CREATESIGN is Will Start");
	}
}

void CmdEditReactor::commandEnded(const char* cmdStr)
{
	if (strcmp(cmdStr, "CREATESIGN") == 0)
	{
        zcutPrintf("\n CREATESIGN is Ended");
	}
}
