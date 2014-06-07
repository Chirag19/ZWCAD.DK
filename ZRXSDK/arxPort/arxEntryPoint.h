#ifndef _ARXPORT_AD_ARXENTRYPOINT_H_
#define _ARXPORT_AD_ARXENTRYPOINT_H_ 1


#include "dbxEntryPoint.h"
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

#include "..\inc\zrxEntryPoint.h"

typedef _ZRXCOMMAND_ENTRY		_ARXCOMMAND_ENTRY;
typedef _ZDSSYMBOL_ENTRY		_ADSSYMBOL_ENTRY;
typedef ZcRxZrxApp				AcRxArxApp;

#define ACED_ARXCOMMAND_ENTRY_PRAGMA		ZCED_ZRXCOMMAND_ENTRY_PRAGMA
#define ACED_ARXCOMMAND_ENTRY_AUTO			ZCED_ZRXCOMMAND_ENTRY_AUTO
#define ACED_ARXCOMMAND_ENTRYBYID_AUTO		ZCED_ZRXCOMMAND_ENTRYBYID_AUTO
#define ACED_ADSSYMBOL_ENTRY_PRAGMA			ZCED_ZDSSYMBOL_ENTRY_PRAGMA
#define ACED_ADSSYMBOL_ENTRY_AUTO			ZCED_ZDSSYMBOL_ENTRY_AUTO
#define ACED_ADSCOMMAND_ENTRY_AUTO			ZCED_ZDSCOMMAND_ENTRY_AUTO
#define ACED_ADSSYMBOL_ENTRYBYID_AUTO		ZCED_ZDSSYMBOL_ENTRYBYID_AUTO
#define ACED_ADSCOMMAND_ENTRYBYID_AUTO		ZCED_ZDSCOMMAND_ENTRYBYID_AUTO

#define __pArxCmdMapEntryFirst				__pZrxCmdMapEntryFirst
#define __pArxCmdMapEntryLast				__pZrxCmdMapEntryLast
#define __pAdsSymbolMapEntryFirst			__pZdsSymbolMapEntryFirst
#define __pAdsSymbolMapEntryLast			__pZdsSymbolMapEntryLast


#endif