//-----------------------------------------------------------------------------
//----- cmdEditorRezctor.h : Declaration of the cmdEditorRezctor
//-----------------------------------------------------------------------------
#pragma once

#ifdef SIGNENTITYUI_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
#include "zced.h"

//-----------------------------------------------------------------------------

class /*DLLIMPEXP*/ CmdEditReactor : public ZcEditorReactor 
{

public:
	ZCRX_DECLARE_MEMBERS(CmdEditReactor);


public:
	CmdEditReactor () ;
	virtual ~CmdEditReactor () ;

	virtual void commandWillStart(const char* cmdStr);
	virtual void commandEnded(const char* cmdStr);



};

#ifdef SIGNENTITYUI_MODULE
ZCDB_REGISTER_OBJECT_ENTRY_AUTO(CmdEditReactor)
#endif
