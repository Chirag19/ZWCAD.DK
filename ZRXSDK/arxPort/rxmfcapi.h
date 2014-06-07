#ifndef _ARXPORT_AD_RXMFCAPI_H_
#define _ARXPORT_AD_RXMFCAPI_H_ 1


#include "AdAChar.h"
#include "AcStatusBar.h"

class ZcDbDatabase;
class ZcApStatusBar;

typedef ZcDbDatabase		AcDbDatabase;
typedef ZcApStatusBar		AcApStatusBar;

#ifdef _ARX_CUSTOM_DRAG_N_DROP_
#undef _ZRX_CUSTOM_DRAG_N_DROP_
#define _ZRX_CUSTOM_DRAG_N_DROP_
#endif

#include "..\inc\zrxmfcapi.h"

#ifndef WM_ACAD_KEEPFOCUS
#define WM_ACAD_KEEPFOCUS  WM_ZCAD_KEEPFOCUS
#endif 


typedef ZcColorSettings				AcColorSettings;
typedef ZcColorSettingsEx			AcColorSettingsEx;
typedef ZcChildFrmSettings			AcChildFrmSettings;
typedef zcedDwgPoint				acedDwgPoint;

#define acedGetAcadWinApp					zcedGetZcadWinApp
#define acedGetAcadDoc						zcedGetZcadDoc
#define acedGetAcadDwgView					zcedGetZcadDwgView
#define acedGetAcadFrame					zcedGetZcadFrame
#define acedGetAcadDockCmdLine				zcedGetZcadDockCmdLine
#define acedGetAcadTextCmdLine				zcedGetZcadTextCmdLine
#define acedGetAcadResourceInstance			zcedGetZcadResourceInstance
#define acedCoordFromPixelToWorld			zcedCoordFromPixelToWorld
#define acedCoordFromPixelToWorld			zcedCoordFromPixelToWorld
#define acedCoordFromWorldToPixel			zcedCoordFromWorldToPixel
#define acedGetWinNum						zcedGetWinNum
#define acedSetStatusBarProgressMeter		zcedSetStatusBarProgressMeter
#define acedSetStatusBarProgressMeterPos	zcedSetStatusBarProgressMeterPos
#define acedRestoreStatusBar				zcedRestoreStatusBar
#define acedRegisterFilterWinMsg			zcedRegisterFilterWinMsg
#define acedRemoveFilterWinMsg				zcedRemoveFilterWinMsg
#define acedRegisterWatchWinMsg				zcedRegisterWatchWinMsg
#define acedRemoveWatchWinMsg				zcedRemoveWatchWinMsg
#define acedRegisterOnIdleWinMsg			zcedRegisterOnIdleWinMsg
#define acedRemoveOnIdleWinMsg				zcedRemoveOnIdleWinMsg
#define acedGetCurrentColors				zcedGetCurrentColors
#define acedSetCurrentColors				zcedSetCurrentColors
#define acedGetSystemColors					zcedGetSystemColors
#define acedGetChildFrameSettings			zcedGetChildFrameSettings
#define acedSetChildFrameSettings			zcedSetChildFrameSettings
#define acedRegisterCustomDropTarget		zcedRegisterCustomDropTarget
#define acedStartOverrideDropTarget			zcedStartOverrideDropTarget
#define acedRevokeCustomDropTarget			zcedRevokeCustomDropTarget
#define acedEndOverrideDropTarget			zcedEndOverrideDropTarget
#define acedAddDropTarget					zcedAddDropTarget
#define acedRemoveDropTarget				zcedRemoveDropTarget
#define AcApGetDatabase						ZcApGetDatabase
#define acedGetRegistryCompany				zcedGetRegistryCompany
#define acedRegisterExtendedTab				zcedRegisterExtendedTab
#define acedGetMenu							zcedGetMenu
#define acedIsInputPending					zcedIsInputPending
#define acedSetIUnknownForCurrentCommand	zcedSetIUnknownForCurrentCommand
#define acedGetIUnknownForCurrentCommand	zcedGetIUnknownForCurrentCommand
#define acedGetApplicationStatusBar			zcedGetApplicationStatusBar
#define acedShowDrawingStatusBars			zcedShowDrawingStatusBars
#define acedDrawingStatusBarsVisible		zcedDrawingStatusBarsVisible
#define acedRegisterStatusBarMenuItem		zcedRegisterStatusBarMenuItem
#define acedUnregisterStatusBarMenuItem		zcedUnregisterStatusBarMenuItem
#define acedSetStatusBarPaneID				zcedSetStatusBarPaneID
#define acedGetCurrentColorsEx				zcedGetCurrentColorsEx
#define acedSetCurrentColorsEx				zcedSetCurrentColorsEx
#define acedGetSystemColorsEx				zcedGetSystemColorsEx
typedef void (* AcedWatchWinMsgFn)(const MSG*);
typedef BOOL (* AcedFilterWinMsgFn)(MSG*);
typedef void (* AcedOnIdleMsgFn) ();
#endif