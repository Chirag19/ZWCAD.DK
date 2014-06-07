
#ifndef _ZCEDINPT_H
#define _ZCEDINPT_H

#include "zrxobject.h"
#include "zdbmain.h"

#pragma pack (push, 8)

#pragma warning (disable: 4786)

class ZcEdInputPointFilter;
class ZcEdInputPointMonitor;
class ZcApDocument;
class ZcEdInputContextReactor;
class ZcDbCustomOsnapMode;
class ZcEdSubSelectFilter;


class ZcEdInputPointManager
{
  public:

    virtual Zcad::ErrorStatus     registerPointFilter(ZcEdInputPointFilter* pFilter) = 0;

    
    virtual Zcad::ErrorStatus     revokePointFilter() = 0;

    
    virtual ZcEdInputPointFilter* currentPointFilter() const = 0;

    
    virtual Zcad::ErrorStatus addPointMonitor(ZcEdInputPointMonitor* pMonitor) = 0;

    
    virtual Zcad::ErrorStatus removePointMonitor(ZcEdInputPointMonitor* pMonitor) = 0;

    
    virtual Zcad::ErrorStatus addInputContextReactor(ZcEdInputContextReactor* pReactor) = 0;

    
    virtual Zcad::ErrorStatus removeInputContextReactor(ZcEdInputContextReactor* pReact) = 0;

 
    
    virtual Zcad::ErrorStatus disableSystemCursorGraphics() = 0;

    
    virtual Zcad::ErrorStatus enableSystemCursorGraphics() = 0;

    
    virtual int systemCursorDisableCount() const = 0;

    
    virtual Zcad::ErrorStatus turnOnForcedPick() = 0;

    
    virtual Zcad::ErrorStatus turnOffForcedPick() = 0;

    
    virtual int forcedPickCount() const = 0;

    virtual int mouseHasMoved() const = 0;

    virtual Zcad::ErrorStatus turnOnSubentityWindowSelection() = 0;
    virtual Zcad::ErrorStatus turnOffSubentityWindowSelection() = 0;

    
    virtual Zcad::ErrorStatus addSubSelectFilter(
            ZcEdSubSelectFilter* pSSSubFilter) = 0;

    
    virtual Zcad::ErrorStatus removeSubSelectFilter(
            ZcEdSubSelectFilter* pSSSubFilter) = 0;

};




class ZcEdInputPointFilter : public ZcRxObject
{

  public:
    ZCRX_DECLARE_MEMBERS(ZcEdInputPointFilter);
   
    virtual Zcad::ErrorStatus processInputPoint(
          
          bool&                        changedPoint,
          ZcGePoint3d&                 newPoint,
          bool&                        displayOsnapGlyph,

          
          bool&                        changedTooltipStr,
          ZCHAR*&                       newTooltipString,

          
          bool&                        retry,

          
          ZcGiViewportDraw*           drawContext,

          
          ZcApDocument*              document,

          
          bool                       pointComputed,

          
          int                        history,

          
          const ZcGePoint3d&               lastPoint,

          
          const ZcGePoint3d&               rawPoint,

          
          const ZcGePoint3d&               grippedPoint,

          
          const ZcGePoint3d&               cartesianSnappedPoint,

             
          const ZcGePoint3d&               osnappedPoint,
          ZcDb::OsnapMask                  osnapMask,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapModes,

          
          ZcDb::OsnapMask                  osnapOverrides,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapOverrides,

                       
          const ZcArray<ZcDbObjectId>&     pickedEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                                           nestedPickedEntities,
          const ZcArray<Zdesk::GsMarker>&  gsSelectionMark,

          const ZcArray<ZcDbObjectId>&     keyPointEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                                           nestedKeyPointEntities,
          const ZcArray<Zdesk::GsMarker>&  keyPointGsSelectionMark,

          const ZcArray<ZcGeCurve3d*>&       alignmentPaths,

          

          const ZcGePoint3d&               computedPoint,

          
          const ZCHAR*                      tooltipString) = 0;


    
    virtual ZcEdInputPointFilter* revokeInputFilter
        (ZcEdInputPointFilter* revokedFilter);
};



class ZcEdInputPointMonitor : public ZcRxObject
{
    public:
    ZCRX_DECLARE_MEMBERS(ZcEdInputPointMonitor);
    
    virtual Zcad::ErrorStatus monitorInputPoint(
 
          
          bool&                             appendToTooltipStr,
          ZCHAR*&                            additionalTooltipString,

          
          ZcGiViewportDraw*                   drawContext,

          
          ZcApDocument*                       document,
          bool                                pointComputed,
          int                                 history,
          const ZcGePoint3d&                  lastPoint,
          const ZcGePoint3d&                  rawPoint,
          const ZcGePoint3d&                  grippedPoint,
          const ZcGePoint3d&                  cartesianSnappedPoint,
          const ZcGePoint3d&                  osnappedPoint,
          ZcDb::OsnapMask                     osnapMask,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapModes,
          ZcDb::OsnapMask                     osnapOverrides,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapOverrides,
          const ZcArray<ZcDbObjectId>&        apertureEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >& 
                                              nestedApertureEntities,
          const ZcArray<Zdesk::GsMarker>&     gsSelectionMark,
          const ZcArray<ZcDbObjectId>&        keyPointEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                                              nestedKeyPointEntities,
          const ZcArray<Zdesk::GsMarker>&     keyPointGsSelectionMark,
          const ZcArray<ZcGeCurve3d*>&        alignmentPaths,
          const ZcGePoint3d&                  computedPoint,
          const ZCHAR*                         tooltipString) = 0;

    virtual bool
        excludeFromOsnapCalculation (const ZcArray<ZcDbObjectId>& nestedEntity,
                                     Zdesk::GsMarker gsSelectionMark);
	void* m_pImplMonitor;
	~ZcEdInputPointMonitor();
protected:
	ZcEdInputPointMonitor();

};

class ZcEdInputContextReactor
{



public:
    virtual void beginGetPoint(const ZcGePoint3d* pointIn,
                               const ZCHAR* promptString,
                               int   initGetFlags,
                               const ZCHAR* pKeywords) { }

    virtual void endGetPoint(Zcad::PromptStatus returnStatus,
                             const ZcGePoint3d& pointOut,
                             const ZCHAR*& pKeyword) { }

    virtual void beginGetAngle(const ZcGePoint3d* pointIn,
                               const ZCHAR* promptString,
                               int   initGetFlags,
                               const ZCHAR* pKeywords) { }

    virtual void endGetAngle(Zcad::PromptStatus returnStatus,
                             double& angle,
                             const ZCHAR*& pKeyword) { }

    virtual void beginGetDistance(const ZcGePoint3d* pointIn,
                                  const ZCHAR* promptString,
                                  int   initGetFlags,
                                  const ZCHAR* pKeywords) { }

    virtual void endGetDistance(Zcad::PromptStatus returnStatus,
                                double& distance,
                                const ZCHAR*& pKeyword) { }

    virtual void beginGetOrientation(const ZcGePoint3d* pointIn,
                                     const ZCHAR* promptString,
                                     int   initGetFlags,
                                     const ZCHAR* pKeywords) { }

    virtual void endGetOrientation(Zcad::PromptStatus returnStatus,
                                   double& angle,
                                   const ZCHAR*& pKeyword) { }

    virtual void beginGetCorner(const ZcGePoint3d* firstCorner,
                                const ZCHAR* promptString,
                                int   initGetFlags,
                                const ZCHAR* pKeywords) { }
    
    virtual void endGetCorner(Zcad::PromptStatus returnStatus,
                              ZcGePoint3d& secondCorner,
                              const ZCHAR*& pKeyword) { }

    
    virtual void beginGetScaleFactor(const ZcGePoint3d* pointIn,
                                     const ZCHAR* promptString,
                                     int   initGetFlags,
                                     const ZCHAR* pKeywords) { }

    virtual void endGetScaleFactor(Zcad::PromptStatus returnStatus,
                                   double& distance,
                                   const ZCHAR*& pKeyword) { }

    
    virtual void beginGetString(const ZCHAR* promptString,
                                int   initGetFlags) { }

    virtual void endGetString (Zcad::PromptStatus returnStatus,
                               ZCHAR* pString) { }

    virtual void beginGetKeyword(const ZCHAR* promptString,
                                 int   initGetFlags,
                                 const ZCHAR* pKeywords) { }

    virtual void endGetKeyword (Zcad::PromptStatus returnStatus,
                                const ZCHAR*& pKeyword) { }



    virtual void beginGetInteger(const int* dfault, 
                                const ZCHAR* promptString,
                                int   initGetFlags,
                                const ZCHAR* pKeywords) { }

    virtual void endGetInteger(Zcad::PromptStatus returnStatus,
                               int& retValue,
                               const ZCHAR*& pKeyword) { }

    
    virtual void beginGetColor(const int* dfault, 
                               const ZCHAR* promptString,
                               int   initGetFlags,
                               const ZCHAR* pKeywords) { }

    virtual void endGetColor(Zcad::PromptStatus returnStatus,
                             int& retValue,
                             const ZCHAR*& pKeyword) { }

    virtual void beginGetReal(const double* dfault, 
                              const ZCHAR* promptString,
                              int   initGetFlags,
                              const ZCHAR* pKeywords) { }

    virtual void endGetReal(Zcad::PromptStatus returnStatus,
                            double& returnValue,
                            const ZCHAR*& pKeyword) { }

    virtual void beginEntsel(const ZCHAR* promptString,
                             int   initGetFlags,
                             const ZCHAR* pKeywords) { }

    virtual void endEntsel(Zcad::PromptStatus returnStatus,
                           ZcDbObjectId& entPicked,
                           ZcGePoint3d& pickPoint,
                           const ZCHAR* pKeyword) { }

    
    virtual void beginNentsel(const ZCHAR*    promptString,
                              Zdesk::Boolean pickFlag,
                              int            initGetFlags,
                              const ZCHAR*    pKeywords) { }

    virtual void endNentsel(Zcad::PromptStatus returnStatus,
                            ZcDbObjectId entPicked,
                            const ZcGePoint3d&  pickPoint,
                            const ZcGeMatrix3d& xform,
                            const resbuf* referenceStack,
                            const ZCHAR*   pKeyword) { }

    virtual void beginSSGet(const ZCHAR*  pPrompt,
                            int          initGetFlags,
                            const ZCHAR*  pKeywords,
                            const ZCHAR*  pSSControls, 
                            const ZcArray<ZcGePoint3d>& points,
                            const resbuf*               entMask) { }

    virtual void endSSGet(Zcad::PromptStatus returnStatus,
                          const ZcArray<ZcDbObjectId>& ss) { }
                    
    
    virtual void beginDragSequence(const ZCHAR*  promptString) { }

    virtual void endDragSequence(Zcad::PromptStatus returnStatus,
                                 ZcGePoint3d&  pickPoint,
                                 ZcGeVector3d& vec) { }

    
    virtual void beginQuiescentState() { }

    virtual void endQuiescentState() { }
};


class ZcEdAppGripService
{
public:
    virtual Zcad::ErrorStatus appGetGripPoints(const ZcDbEntity* pEnt,
        ZcDbGripDataPtrArray& grips, const double curViewUnitSize,
        const int gripSize, const ZcGeVector3d& curViewDir, const int bitflags);
    
    virtual Zcad::ErrorStatus appGetGripPoints(const ZcDbEntity* pEnt,
        ZcGePoint3dArray &pnts, ZcDbIntArray& osmodes, ZcDbIntArray& ids);
    
    virtual Zcad::ErrorStatus appMoveGripPointsAt(ZcDbEntity *pEnt,
        const ZcDbIntArray& pIndices, const ZcGeVector3d& pOffset);
    
    virtual Zcad::ErrorStatus appMoveGripPointsAt(ZcDbEntity *pEnt,
        const ZcDbVoidPtrArray& gripAppData, const ZcGeVector3d& offset,
        const int bitflags);
    
    virtual Zcad::ErrorStatus getGripPointsAtSubentPath(const ZcDbEntity *pEnt,
        const ZcDbFullSubentPath& path, ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags);
    
    virtual Zcad::ErrorStatus moveGripPointsAtSubentPaths(ZcDbEntity *pEnt,
        const ZcDbFullSubentPathArray& paths,
        const ZcDbVoidPtrArray& gripAppData, const ZcGeVector3d& offset,
        const int bitflags);
    

    virtual Zcad::ErrorStatus appGripStatus(const ZcDbEntity *pEnt,
        const ZcDb::GripStat status);
    
};

Zcad::ErrorStatus
zcedRegisterGripService(ZcApDocument *pDoc, ZcEdAppGripService *pSvc);
Zcad::ErrorStatus
zcedRemoveGripService(ZcApDocument *pDoc, ZcEdAppGripService *pSvc);

#pragma pack (pop)
#endif  
