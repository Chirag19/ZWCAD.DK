
#ifndef   _ARXPORT_ACCMD_H_
#define   _ARXPORT_ACCMD_H_

#include "AdAChar.h"

#include "dbmain.h"
#include "rxobject.h"

class ZcEdCommand;
typedef ZcEdCommand AcEdCommand;

class ZcRxDictionary;
typedef ZcRxDictionary AcRxDictionary;

class ZcEdUIContext;
typedef ZcEdUIContext AcEdUIContext;

#include "..\inc\zccmd.h"

#define ACRX_CMD_MODAL                 ZCRX_CMD_MODAL
#define ACRX_CMD_TRANSPARENT           ZCRX_CMD_TRANSPARENT
#define ACRX_CMD_USEPICKSET            ZCRX_CMD_USEPICKSET  
#define ACRX_CMD_REDRAW                ZCRX_CMD_REDRAW
#define ACRX_CMD_NOPERSPECTIVE         ZCRX_CMD_NOPERSPECTIVE
                                                 
#define ACRX_CMD_NOMULTIPLE            ZCRX_CMD_NOMULTIPLE 
#define ACRX_CMD_NOTILEMODE            ZCRX_CMD_NOTILEMODE  
#define ACRX_CMD_NOPAPERSPACE          ZCRX_CMD_NOPAPERSPACE
#define ACRX_CMD_PLOTONLY              ZCRX_CMD_PLOTONLY 
#define ACRX_CMD_NOOEM                 ZCRX_CMD_NOOEM     
#define ACRX_CMD_UNDEFINED             ZCRX_CMD_UNDEFINED 
#define ACRX_CMD_INPROGRESS            ZCRX_CMD_INPROGRESS  
#define ACRX_CMD_DEFUN                 ZCRX_CMD_DEFUN       
#define ACRX_CMD_NONEWSTACK            ZCRX_CMD_NONEWSTACK
#define ACRX_CMD_NOINTERNALLOCK        ZCRX_CMD_NOINTERNALLOCK
#define ACRX_CMD_DOCREADLOCK           ZCRX_CMD_DOCREADLOCK      
#define ACRX_CMD_DOCEXCLUSIVELOCK      ZCRX_CMD_DOCEXCLUSIVELOCK
#define ACRX_CMD_SESSION               ZCRX_CMD_SESSION 
                                      
#define ACRX_CMD_INTERRUPTIBLE	       ZCRX_CMD_INTERRUPTIBLE
                                              
#define ACRX_CMD_NOHISTORY	           ZCRX_CMD_NOHISTORY
#define ACRX_CMD_NO_UNDO_MARKER        ZCRX_CMD_NO_UNDO_MARKER
#define ACRX_CMD_NOBEDIT               ZCRX_CMD_NOBEDIT

#define ACRX_CMD_MAINTHRD              ZCRX_CMD_MAINTHRD

#define ACRX_MAX_CMDNAME_LEN  	       ZCRX_MAX_CMDNAME_LEN


#define ACRX_COMMAND_DOCK    ZCRX_COMMAND_DOCK

typedef ZcRxFunctionPtr     AcRxFunctionPtr;                                                     


typedef ZcEdCommandStruc     AcEdCommandStruc;
typedef ZcEdCommand          AcEdCommand;
typedef ZcEdCommandIterator  AcEdCommandIterator;


#define acedRegCmds			zcedRegCmds
typedef ZcEdCommandStack	AcEdCommandStack;

#endif
