
#ifndef _ARXPORT_ACED_H_
#define _ARXPORT_ACED_H_ 1

#include "adesk.h"
#include "rxnames.h"
#include "rxevent.h"
#include "accmd.h"
#include "dbjig.h"

struct ZcEdCommandStruc;
class ZcString;

typedef ZcString									AcString;
typedef struct ZcEdCommandStruct					AcEdCommandStruct;

#include "..\inc\zced.h"

#define AcadContextMenuMode							ZcadContextMenuMode
#define acedCmdLookup								zcedCmdLookup
#define acedCmdLookup2								zcedCmdLookup2
#define acedCmdUndefine								zcedCmdUndefine
#define acedPopCommandDirectory						zcedPopCommandDirectory
#define acedGetCommandForDocument					zcedGetCommandForDocument
#define acedSetOLELock								zcedSetOLELock
#define acedClearOLELock							zcedClearOLELock
#define acedPostCommandPrompt						zcedPostCommandPrompt
#define acedSyncFileOpen							zcedSyncFileOpen
#define acedSetColorDialog							zcedSetColorDialog
#define acedSetColorDialogTrueColor					zcedSetColorDialogTrueColor
#define AcEdColorDialogCallbackFunction				ZcEdColorDialogCallbackFunction
#define acedSetColorDialogTrueColorWithCallback		zcedSetColorDialogTrueColorWithCallback
#define acedSetColorPrompt							zcedSetColorPrompt
#define acedIsMenuGroupLoaded						zcedIsMenuGroupLoaded
#define acedSendModelessOperationStart				zcedSendModelessOperationStart
#define acedSendModelessOperationEnded				zcedSendModelessOperationEnded
#define acedUpdateDisplay							zcedUpdateDisplay
#define acedUpdateDisplayPause						zcedUpdateDisplayPause
#define acedIsUpdateDisplayPaused					zcedIsUpdateDisplayPaused
#define acedDisableDefaultARXExceptionHandler		zcedDisableDefaultZRXExceptionHandler
#define acedVportTableRecords2Vports				zcedVportTableRecords2Vports
#define acedVports2VportTableRecords				zcedVports2VportTableRecords
#define acedVPLayer									zcedVPLayer
#define acedServices								zcedServices
#define newAcEdCommand								newZcEdCommand
#define acedAddObjectContextMenu					zcedAddObjectContextMenu
#define acedRemoveObjectContextMenu					zcedRemoveObjectContextMenu
#define acedAddDefaultContextMenu					zcedAddDefaultContextMenu
#define acedRemoveDefaultContextMenu				zcedRemoveDefaultContextMenu
#define acedSetCMBaseAlias							zcedSetCMBaseAlias
#define acedGetCMBaseAlias							zcedGetCMBaseAlias
#define acedMspace									zcedMspace
#define acedPspace									zcedPspace
#define acedSetCurrentVPort							zcedSetCurrentVPort
#define acedSetCurrentVPort							zcedSetCurrentVPort
#define acedIsDragging								zcedIsDragging
#define acedSetCurrentView							zcedSetCurrentView
#define acedRestoreCurrentView						zcedRestoreCurrentView
#define acedSetCurrentUCS							zcedSetCurrentUCS
#define acedGetCurrentUCS							zcedGetCurrentUCS
#define acedRestorePreviousUCS						zcedRestorePreviousUCS
#define acedEditToleranceInteractive				zcedEditToleranceInteractive
#define acedEditMTextInteractive					zcedEditMTextInteractive
#define acedGetRGB									zcedGetRGB
#define acedGetCurrentSelectionSet					zcedGetCurrentSelectionSet
#define acedGetFullSubentPathsForCurrentSelection	zcedGetFullSubentPathsForCurrentSelection
#define acedGetIDispatch							zcedGetIDispatch
#define acedActiveViewportId						zcedActiveViewportId
#define acedViewportIdFromNumber					zcedViewportIdFromNumber
#define acedNumberOfViewports						zcedNumberOfViewports
#define acedGetCurViewportObjectId					zcedGetCurViewportObjectId
#define acedConvertEntityToHatch					zcedConvertEntityToHatch
#define AcEdDrawOrderCmdType						ZcEdDrawOrderCmdType
#define acedDrawOrderInherit						zcedDrawOrderInherit
#define acedCreateViewportByView					zcedCreateViewportByView
#define acedCreateEnhancedViewportOnDrop			zcedCreateEnhancedViewportOnDrop
#define acedCreateEnhancedViewportOnDropDWG			zcedCreateEnhancedViewportOnDropDWG
#define acedGetUnitsValueString						zcedGetUnitsValueString
#define acdbCanonicalToSystemRange					zcdbCanonicalToSystemRange
#define acdbSystemRangeToCanonical					zcdbSystemRangeToCanonical

#define acedEditor									zcedEditor
#define acedInitDialog								zcedInitDialog
typedef ZcEdServices								AcEdServices;
typedef ZcEditorReactor								AcEditorReactor;
typedef ZcEditorReactor2							AcEditorReactor2;
typedef ZcEditor									AcEditor;
typedef ZcEdUIContext								AcEdUIContext;

#endif
