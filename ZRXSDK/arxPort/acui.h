#ifndef _ARXPORT_ACUI_H_
#define _ARXPORT_ACUI_H_


#ifdef  _ZCUI_BUILD
#  define   ZCUI_PORT  __declspec(dllexport)
#else
#  define   ZCUI_PORT  __declspec(dllimport)
#endif

#include "acuiButton.h"
#include "acuiDialogWorksheet.h"
#include "acuiDialog.h"
#include "acuiTabCtrl.h"

#include "aced.h"
#include "acuiDock.h"
#include "acuiEdit.h"
#include "acuiHeaderCtrl.h"
#include "acuiListBox.h"
#include "acuiListCtrl.h"
#include "acuiComboBox.h"
#include "acuiString.h"
#include "acuiPathname.h"
#include "acuiNavDialog.h"
#include "..\inc\zcui.h"

#define InitAcUiDLL                       InitZcUiDLL
#define AcUiAppResourceInstance           ZcUiAppResourceInstance
#define AcUiContextHelpFileName           ZcUiContextHelpFileName
#define AcUiEnableToolTips                ZcUiEnableToolTips
#define AcUiFindContextHelpFullPath       ZcUiFindContextHelpFullPath
#define AcUiIsInputPending                ZcUiIsInputPending
#define AcUiMainWindow                    ZcUiMainWindow
#define AcUiRootKey                       ZcUiRootKey


typedef CZdUiRegistryAccess        CAdUiRegistryAccess;
typedef CZcUiRegistryAccess        CAcUiRegistryAccess;
typedef CZdUiRegistryDeleteAccess  CAdUiRegistryDeleteAccess;
typedef CZcUiRegistryDeleteAccess  CAcUiRegistryDeleteAccess;
typedef CZdUiRegistryWriteAccess   CAdUiRegistryWriteAccess;
typedef CZcUiRegistryWriteAccess   CAcUiRegistryWriteAccess;
//typedef CZcUiTabChildDialog        CAcUiTabChildDialog;

#endif


