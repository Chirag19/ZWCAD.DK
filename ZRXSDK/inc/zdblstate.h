#ifndef ZCDB_LSTATE_H
#define ZCDB_LSTATE_H

#include "zdbmain.h"
#include "zcarray.h"
#include "zcstring.h"

#pragma pack(push, 8)

class ZcDbImpLayerStateManager;
class ZcDbLayerStateManagerReactor;

class ZcDbLayerStateManager: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLayerStateManager);
    ZcDbLayerStateManager();
    ZcDbLayerStateManager(ZcDbDatabase *pHostDb);
    virtual ~ZcDbLayerStateManager();

    enum LayerStateMask {
        kNone           = 0x0000,
        kOn             = 0x0001,
        kFrozen         = 0x0002,
        kLocked         = 0x0004,
        kPlot           = 0x0008,
        kNewViewport    = 0x0010,
        kColor          = 0x0020,
        kLineType       = 0x0040,
        kLineWeight     = 0x0080,
        kPlotStyle      = 0x0100,
        kCurrentViewport = 0x0200,
        kAll            = kOn | kFrozen | kLocked | kPlot | kNewViewport |
                          kColor | kLineType | kLineWeight | kPlotStyle |
                          kCurrentViewport,
        kStateIsHidden  = 0x8000,        
        kLastRestored   = 0x10000,        
        kDecomposition  = kAll | 0x20000
    };

    enum {
        kUndefDoNothing = 0,
        kUndefTurnOff = 1,
        kUndefFreeze = 2,
        kRestoreAsOverrides = 4
    };

    bool                addReactor(ZcDbLayerStateManagerReactor * pReactor);
    bool                removeReactor(ZcDbLayerStateManagerReactor * pReactor);

    ZcDbObjectId        layerStatesDictionaryId(bool bCreateIfNotPresent=false);
    bool                hasLayerState(const ZCHAR *sName);
    Zcad::ErrorStatus   saveLayerState(const ZCHAR *sName, LayerStateMask mask);
    Zcad::ErrorStatus   restoreLayerState(const ZCHAR *sName);
    Zcad::ErrorStatus   setLayerStateMask(const ZCHAR *sName, 
                                          LayerStateMask mask);
    Zcad::ErrorStatus   getLayerStateMask(const ZCHAR *sName,
                                          LayerStateMask &returnMask);
    Zcad::ErrorStatus   deleteLayerState(const ZCHAR *sName);
    Zcad::ErrorStatus   renameLayerState(const ZCHAR *sName,
                                         const ZCHAR *sNewName);
    Zcad::ErrorStatus   importLayerState(const ZCHAR *sFilename);
    Zcad::ErrorStatus   importLayerState(const ZCHAR *sFilename, ZcString & sName);

    Zcad::ErrorStatus   exportLayerState(const ZCHAR *sNameToExport,
                                         const ZCHAR *sFilename);

    Zcad::ErrorStatus   saveLayerState(const ZCHAR *sName, LayerStateMask mask, const ZcDbObjectId& idVp);
    Zcad::ErrorStatus   restoreLayerState(const ZCHAR *sName, const ZcDbObjectId& idVp, int nRestoreFlags = 0, const LayerStateMask* pClientMask = NULL);

    Zcad::ErrorStatus   setLayerStateDescription(const ZCHAR* sName,
                                                 const ZCHAR* sDesc);
    Zcad::ErrorStatus   getLayerStateDescription(const ZCHAR* sName, ZCHAR*& sDesc);
    bool                layerStateHasViewportData(const ZCHAR* sName);
    Zcad::ErrorStatus   importLayerStateFromDb(const ZCHAR *pStateName, ZcDbDatabase* pDb);
    Zcad::ErrorStatus   getLayerStateNames(ZcStringArray& lsArray, bool bIncludeHidden = true, bool bIncludeXref = true);
    Zcad::ErrorStatus   getLastRestoredLayerState(ZcString & sName, ZcDbObjectId &restoredLSId);
    Zcad::ErrorStatus   getLayerStateLayers(ZcStringArray& layerArray, const ZCHAR* sName, bool bInvert = false);
    bool                compareLayerStateToDb(const ZCHAR* sName, const ZcDbObjectId& idVp);
    Zcad::ErrorStatus   addLayerStateLayers(const ZCHAR *sName, const ZcDbObjectIdArray& layerIds);
    Zcad::ErrorStatus   removeLayerStateLayers(const ZCHAR *sName, const ZcStringArray& layerNames);
    bool                isDependentLayerState(const ZCHAR *sName);
    ZcDbDatabase *      getDatabase() const;

private:
    friend class ZcDbImpDatabase;
    ZcDbImpLayerStateManager *mpImpLSM;
};

class ZcDbLayerStateManagerReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLayerStateManagerReactor);

    virtual void layerStateCreated(const ZCHAR * layerStateName,
                                   const ZcDbObjectId& layerStateId);
    virtual void layerStateCompareFailed(const ZCHAR * layerStateName,
                                         const ZcDbObjectId& layerStateId);

    virtual void layerStateToBeRestored(const ZCHAR * layerStateName,
                                        const ZcDbObjectId& layerStateId);
    virtual void layerStateRestored(const ZCHAR * layerStateName,
                                    const ZcDbObjectId& layerStateId);
    virtual void abortLayerStateRestore(const ZCHAR * layerStateName,
                                        const ZcDbObjectId& layerStateId);


    virtual void layerStateToBeDeleted(const ZCHAR * layerStateName,
                                       const ZcDbObjectId& layerStateId);
    virtual void layerStateDeleted(const ZCHAR * layerStateName);
    virtual void abortLayerStateDelete(const ZCHAR * layerStateName,
                                       const ZcDbObjectId& layerStateId);

    virtual void layerStateToBeRenamed(const ZCHAR * oldLayerStateName,
                                       const ZCHAR * newLayerStateName);
    virtual void layerStateRenamed(const ZCHAR * oldLayerStateName,
                                   const ZCHAR * newLayerStateName);
    virtual void abortLayerStateRename(const ZCHAR * oldLayerStateName,
                                       const ZCHAR * newLayerStateName);
};

#pragma pack(pop)

#endif