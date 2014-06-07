
#ifndef _ARXPORT_AD_DBGRIP_H_
#define _ARXPORT_AD_DBGRIP_H_ 1

#include "acdb.h"
#include "acarray.h"
#include "dbDimData.h"


class ZcGiViewport;
class ZcDbEntity;
class ZcDbGripData;
class ZcGiWorldDraw;
class ZcGiViewportDraw;
class ZcDbCustomOsnapMode;



typedef ZcGiViewport              AcGiViewport;
typedef ZcDbEntity                AcDbEntity;
typedef ZcDbGripData              AcDbGripData;
typedef ZcGiWorldDraw             AcGiWorldDraw;
typedef ZcGiViewportDraw          AcGiViewportDraw;
typedef ZcDbCustomOsnapMode       AcDbCustomOsnapMode;

#include "..\inc\zdbgrip.h"


namespace AcDbGripOperations {
    enum ReturnValue {
        eOk         = 0,
        eFailure,
        eNoRedrawGrip,
        eGripHotToWarm,
        eGetNewGripPoints
    };

    enum DrawType {
        kWarmGrip  = 0,
        kHoverGrip,
        kHotGrip,
        kDragImageGrip
    };

    enum GripStatus {
        kGripStart = 0,
        kGripEnd,
        kGripAbort,
        kStretch,
        kMove,
        kRotate,
        kScale,
        kMirror,
        kDimFocusChanged,
        kPopUpMenu
    };

    enum GripFlags {
        kSkipWhenShared           = 0x1,
        kDisableRubberBandLine    = 0x2,
        kDisableModeKeywords      = 0x4,
        kDrawAtDragImageGripPoint = 0x8,
        kTriggerGrip              = 0x10,
        kTurnOnForcedPick         = 0x20,
        kMapGripHotToRtClk        = 0x40,
        kGizmosEnabled            = 0x80,
        kGripIsPerViewport        = 0x100,
        kGripEditTip              = 0x200,
    };

    enum GripContextFlags {
        kSharedGrip    = 0x1,
        kMultiHotGrip  = 0x2
    };

    enum GetGripPointsFlags {
        kGripPointsOnly = 0x1,
        kCyclableGripsOnly = 0x02,
        kDynamicDimMode = 0x04
    };

    enum MoveGripPointsFlags {
        kOsnapped                = 0x1,
        kPolar                   = 0x2,
        kOtrack                  = 0x4,
        kZdir                    = 0x8,
        kKeyboard                = 0x10
    };

};


#define AcDbGripDataPtrArray   ZcDbGripDataPtrArray
#define AcDbGripDataArray      ZcDbGripDataArray

typedef ZcDbGripData			AcDbGripData;

#define appDataAcRxClass		appDataZcRxClass
#define setAppDataAcRxClass		setAppDataZcRxClass

#endif
