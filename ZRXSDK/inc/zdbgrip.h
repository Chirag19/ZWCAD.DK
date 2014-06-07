#ifndef ZD_DBGRIP_H
#define ZD_DBGRIP_H

#include "zcdb.h"
#include "zcarray.h"
#include "zdbDimData.h"

class ZcGiViewport;
class ZcDbEntity;
class ZcDbGripData;
class ZcGiWorldDraw;
class ZcGiViewportDraw;
class ZcDbCustomOsnapMode;

namespace ZcDbGripOperations {
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

typedef ZcArray<ZcDbGripData*> ZcDbGripDataPtrArray;
typedef ZcArray<ZcDbGripData> ZcDbGripDataArray;

typedef ZcDbGripOperations::ReturnValue (*GripOperationPtr)(ZcDbGripData* pThis,
    const ZcDbObjectId& entId, int contextFlags);

typedef void (*ContextMenuItemIndexPtr)(unsigned int itemIndex);

typedef ZcDbGripOperations::ReturnValue (*GripRtClkHandler)(ZcDbGripDataArray& hotGrips,
    const ZcDbObjectIdArray& ents, ZCHAR *& menuName, HMENU& menu,
    ContextMenuItemIndexPtr& cb);

typedef bool (*GripWorldDrawPtr)(ZcDbGripData* pThis, ZcGiWorldDraw* pWd,
    const ZcDbObjectId& entId, ZcDbGripOperations::DrawType type,
    ZcGePoint3d* imageGripPoint, double dGripSize);

typedef void (*GripViewportDrawPtr)(ZcDbGripData* pThis, ZcGiViewportDraw* pWd,
    const ZcDbObjectId& entId, ZcDbGripOperations::DrawType type,
    ZcGePoint3d* imageGripPoint, int gripSize);

typedef void (*GripOpStatusPtr)(ZcDbGripData* pThis, const ZcDbObjectId& entId,
    ZcDbGripOperations::GripStatus stat);

typedef const ZCHAR * (*GripToolTipPtr)(ZcDbGripData* pThis);

typedef void (*GripDimensionPtr)(ZcDbGripData* pThis, const ZcDbObjectId& entId,
    double dimScale, ZcDbDimDataPtrArray& dimData); 

typedef ZcDbGripOperations::ReturnValue (*GripInputPointPtr)(
    ZcDbGripData* pThis, const ZcDbObjectId& entId, bool& changedPoint,
    ZcGePoint3d& newPoint, const ZcGiViewport& viewContext,
    const ZcDbObjectId& viewportId, bool pointComputed, int history,
    const ZcGePoint3d& lastPoint, const ZcGePoint3d& rawPoint,
    const ZcGePoint3d& grippedPoint, const ZcGePoint3d& cartesianSnappedPoint,
    const ZcGePoint3d& osnappedPoint, ZcDb::OsnapMask osnapMask,
    const ZcArray<ZcDbCustomOsnapMode*>& customOsnapModes,
    ZcDb::OsnapMask osnapOverrides,
    const ZcArray<ZcDbCustomOsnapMode*>& customOsnapOverrides,
    const ZcArray<ZcDbObjectId>& pickedEntities,
    const ZcArray< ZcDbObjectIdArray,
        ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >& nestedPickedEntities,
    const ZcArray<Zdesk::GsMarker>& gsSelectionMark,
    const ZcArray<ZcDbObjectId>& keyPointEntities,
    const ZcArray< ZcDbObjectIdArray,
        ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >& nestedKeyPointEntities,
    const ZcArray<Zdesk::GsMarker>& keyPointGsSelectionMark,
    const ZcArray<ZcGeCurve3d*>& alignmentPaths, const ZcGePoint3d& computedPoint); 

class ZcDbGripData {
public:
    ZcDbGripData();
    ZcDbGripData(const ZcGePoint3d&, void*, GripOperationPtr hotGrip = NULL,
        GripOperationPtr hoverGrip = NULL, GripRtClkHandler RtClk = NULL,
        GripWorldDrawPtr wd = NULL, GripViewportDrawPtr vd = NULL,
        GripOpStatusPtr stat = NULL, GripToolTipPtr tt = NULL,
        GripDimensionPtr hoverDim = NULL, GripDimensionPtr hotGripDim = NULL,
        unsigned int bitFlags = 0,
        ZcGePoint3d* altBasePt = NULL, GripInputPointPtr inputPointFunc = NULL);

    ZcDbGripData(const ZcGePoint3d&, void*, ZcRxClass*, 
        GripOperationPtr hotGrip = NULL,
        GripOperationPtr hoverGrip = NULL, GripRtClkHandler RtClk = NULL,
        GripWorldDrawPtr wd = NULL, GripViewportDrawPtr vd = NULL,
        GripOpStatusPtr stat = NULL, GripToolTipPtr tt = NULL,
        GripDimensionPtr hoverDim = NULL, GripDimensionPtr hotGripDim = NULL,
        unsigned int bitFlags = 0,
        ZcGePoint3d* altBasePt = NULL, GripInputPointPtr inputPointFunc = NULL);

    ~ZcDbGripData();

    ZcDbGripData(const ZcDbGripData&);

    ZcDbGripData&             operator = (const ZcDbGripData&);

    void                      setAllData(const ZcGePoint3d&, void*,
        GripOperationPtr hotGrip = NULL, GripOperationPtr hoverGrip = NULL,
        GripRtClkHandler RtClk = NULL, GripWorldDrawPtr wd = NULL,
        GripViewportDrawPtr vd = NULL, GripOpStatusPtr stat = NULL,
        GripToolTipPtr tt = NULL, GripDimensionPtr hoverDim = NULL,
        GripDimensionPtr hotGripDim = NULL,
        unsigned int bitFlags = 0, ZcGePoint3d* altBasePt = NULL,
        GripInputPointPtr inputPointFunc = NULL,
        ZcRxClass* appDataZcRxClass = NULL);

    const ZcGePoint3d&        gripPoint() const;
    void                      setGripPoint(const ZcGePoint3d& pt);

    void*                     appData() const;
    void                      setAppData(void* appData);

    ZcRxClass*                appDataZcRxClass() const;
    void                      setAppDataZcRxClass(ZcRxClass* pClass);

    GripOperationPtr          hotGripFunc() const;
    void                      setHotGripFunc(GripOperationPtr pFunc);

    GripOperationPtr          hoverFunc() const;
    void                      setHoverFunc(GripOperationPtr pFunc);
    
    GripRtClkHandler          rtClk() const;
    void                      setRtClk(GripRtClkHandler pFunc);
    
    GripWorldDrawPtr          worldDraw() const;
    void                      setWorldDraw(GripWorldDrawPtr pFunc);
    
    GripViewportDrawPtr       viewportDraw() const;
    void                      setViewportDraw(GripViewportDrawPtr pFunc);
    
    GripOpStatusPtr           gripOpStatFunc() const;
    void                      setGripOpStatFunc(GripOpStatusPtr pFunc);

    GripToolTipPtr            toolTipFunc() const;
    void                      setToolTipFunc(GripToolTipPtr pFunc);

    GripDimensionPtr          hoverDimensionFunc() const;
    void                      setHoverDimensionFunc(GripDimensionPtr pFunc);

    GripDimensionPtr          hotGripDimensionFunc() const;
    void                      setHotGripDimensionFunc(GripDimensionPtr pFunc);

    ZcGePoint3d*              alternateBasePoint() const;
    void                      setAlternateBasePoint(ZcGePoint3d* altBasePt);

    unsigned int              bitFlags() const;
    void                      setBitFlags(unsigned int flags);

    bool                      skipWhenShared() const;
    void                      setSkipWhenShared(bool skip);

    bool                      isRubberBandLineDisabled() const;
    void                      disableRubberBandLine(bool disable);

    bool                      areModeKeywordsDisabled() const;
    void                      disableModeKeywords(bool disable);

    bool                      drawAtDragImageGripPoint() const;
    void                      setDrawAtDragImageGripPoint(bool atDragPoint);

    bool                      triggerGrip() const;
    void                      setTriggerGrip(bool trigger);

    GripInputPointPtr        inputPointFunc() const;
    void                      setInputPointFunc(GripInputPointPtr pFunc);

    bool                      forcedPickOn() const;
    void                      setForcedPickOn(bool on);

    bool                      mapGripHotToRtClk() const;
    void                      setMapGripHotToRtClk(bool on);

    bool                      gizmosEnabled() const;
    void                      setGizmosEnabled(bool on);

    bool                      gripIsPerViewport() const;
    void                      setGripIsPerViewport(bool on);

private:
    ZcGePoint3d         m_gripPt;
    ZcGePoint3d*        m_pAltBasePt;
    void*               m_pAppData;
    GripOperationPtr    m_pHotGripFunc;
    GripOperationPtr    m_pHoverFunc;
    GripRtClkHandler    m_pRtClk;
    GripWorldDrawPtr    m_pWorldDraw;
    GripViewportDrawPtr m_pViewportDraw;
    GripOpStatusPtr     m_pGripOpStatFunc;
    GripToolTipPtr      m_pToolTipFunc;
    GripDimensionPtr    m_pHoverDimensionFunc;
    GripDimensionPtr    m_pHotGripDimensionFunc;
    unsigned int        m_bitFlags;
    GripInputPointPtr   m_pInputPointFunc;
    ZcRxClass*          m_pAppDataClass;
};


#endif // ZD_DBGRIP_H