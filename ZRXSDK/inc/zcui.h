#ifndef _zcui_h
#define _zcui_h

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifdef  _ZCUI_BUILD
#  define   ZCUI_PORT  __declspec(dllexport)
#else
#  define   ZCUI_PORT  __declspec(dllimport)
#endif

ZCUI_PORT void InitZcUiDLL();

ZCUI_PORT HINSTANCE ZcUiAppResourceInstance ();
ZCUI_PORT LPCTSTR ZcUiContextHelpFileName();
ZCUI_PORT BOOL ZcUiEnableToolTips ();
ZCUI_PORT BOOL ZcUiFindContextHelpFullPath (
    LPCTSTR fileName, CString& fullPath
);
ZCUI_PORT BOOL ZcUiIsInputPending ();
ZCUI_PORT CWnd * ZcUiMainWindow ();
ZCUI_PORT void ZcUiRootKey (CString& rootKey);

#include "zcuiButton.h"
#include "zcuiDialogWorksheet.h"
#include "zcuiDialog.h"
#include "zcuiTabCtrl.h"

typedef CZdUiRegistryAccess         CZcUiRegistryAccess;
typedef CZdUiRegistryDeleteAccess   CZcUiRegistryDeleteAccess;
typedef CZdUiRegistryWriteAccess    CZcUiRegistryWriteAccess;
typedef CZcUiTabChildDialog         CZcUiTabExtension;


#include "zced.h"

#include "zcuiDock.h"
#include "zcuiEdit.h"
#include "zcuiHeaderCtrl.h"
#include "zcuiListBox.h"
#include "zcuiListCtrl.h"

#include "zcuiComboBox.h"

#include "zcuiString.h"

#include "zcuiPathname.h"

#include "zcuiNavDialog.h"

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif

//////////////////////////////////////////////////////////////////////////////
