#ifndef ZD_DBSYMUTL_H
#define ZD_DBSYMUTL_H 1


#include <assert.h>
#include <stddef.h>
#include "zdbsymtb.h"

#pragma pack (push, 8)

#define ZCDBSYMUTIL_SERVICES_CURRENT_VERSION 106

namespace ZcDbSymbolUtilities
{

enum CompatibilityMode {
    kExtendedNames    = true,
    kPreExtendedNames = false
};

enum NameCaseMode {
    kPreserveCase     = true,
    kForceToUpper     = false
};

enum NewNameMode {
    kAsNewName        = true,
    kAsExistingName   = false
};

enum VerticalBarMode {
    kAllowVerticalBar = true,
    kNoVerticalBar    = false
};

class Services
{
public:
    enum { kCurrentVersion = ZCDBSYMUTIL_SERVICES_CURRENT_VERSION };
    virtual int version() const = 0;


    virtual bool isBlockLayoutName        (const ZCHAR * name) const = 0;
    virtual bool isBlockModelSpaceName    (const ZCHAR * name) const = 0;
    virtual bool isBlockPaperSpaceName    (const ZCHAR * name) const = 0;
    virtual bool isLayerDefpointsName     (const ZCHAR * name) const = 0;
    virtual bool isLayerZeroName          (const ZCHAR * name) const = 0;
    virtual bool isLinetypeByBlockName    (const ZCHAR * name) const = 0;
    virtual bool isLinetypeByLayerName    (const ZCHAR * name) const = 0;
    virtual bool isLinetypeContinuousName (const ZCHAR * name) const = 0;
    virtual bool isRegAppZcadName         (const ZCHAR * name) const = 0;
    virtual bool isTextStyleStandardName  (const ZCHAR * name) const = 0;
    virtual bool isViewportActiveName     (const ZCHAR * name) const = 0;

    virtual ZcDbObjectId blockModelSpaceId    (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId blockPaperSpaceId    (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId layerDefpointsId     (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId layerZeroId          (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId linetypeByBlockId    (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId linetypeByLayerId    (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId linetypeContinuousId (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId regAppZcadId         (ZcDbDatabase * pDb) const = 0;
    virtual ZcDbObjectId textStyleStandardId  (ZcDbDatabase * pDb) const = 0;

    virtual const ZCHAR * blockModelSpaceName    () const = 0;
    virtual const ZCHAR * blockPaperSpaceName    () const = 0;
    virtual const ZCHAR * layerDefpointsName     () const = 0;
    virtual const ZCHAR * layerZeroName          () const = 0;
    virtual const ZCHAR * linetypeByBlockName    () const = 0;
    virtual const ZCHAR * linetypeByLayerName    () const = 0;
    virtual const ZCHAR * linetypeContinuousName () const = 0;
    virtual const ZCHAR * regAppZcadName         () const = 0;
    virtual const ZCHAR * textStyleStandardName  () const = 0;
    virtual const ZCHAR * viewportActiveName     () const = 0;


    virtual int               compareSymbolName(
                                      const ZCHAR * thisName,
                                      const ZCHAR * otherName) const = 0;
    virtual bool              hasVerticalBar(
                                      const ZCHAR * name) const = 0;
    virtual Zcad::ErrorStatus makeDependentName(
                                      ZCHAR *&      pNewName,
                                      const ZCHAR * dwgName,
                                      const ZCHAR * symbolName) const = 0;
    virtual Zcad::ErrorStatus repairPreExtendedSymbolName(
                                      ZCHAR *&      pNewName,
                                      const ZCHAR * oldName,
                                      bool         allowVerticalBar) const = 0;
    virtual Zcad::ErrorStatus repairSymbolName(
                                      ZCHAR *&      pNewName,
                                      const ZCHAR * oldName,
                                      bool         allowVerticalBar) const = 0;
    virtual bool              splitDependentName(
                                      size_t &      numLeftBytes,
                                      const ZCHAR *& pRight,
                                      const ZCHAR *  symbolName) const = 0;
    virtual Zcad::ErrorStatus validatePreExtendedSymbolName(
                                      const ZCHAR * name,
                                      bool         allowVerticalBar) const = 0;
    virtual Zcad::ErrorStatus validateSymbolName(
                                      const ZCHAR * name,
                                      bool         allowVerticalBar) const = 0;


    virtual bool              compatibilityMode(
                                      ZcDbDatabase * pDb) const = 0;
    virtual Zcad::ErrorStatus getBlockNameFromInsertPathName(
                                      ZCHAR *&      pBlockName,
                                      const ZCHAR * pathName) const = 0;
    virtual Zcad::ErrorStatus getInsertPathNameFromBlockName(
                                      ZCHAR *&      pPathName,
                                      const ZCHAR * blockName) const = 0;
    virtual bool              getMaxSymbolNameLength(
                                      size_t &     maxLength,
                                      size_t &     maxSize,
                                      bool         isNewName,
                                      bool         compatibilityMode) const = 0;
    virtual Zcad::ErrorStatus getPathNameFromSymbolName(
                                      ZCHAR *&      pPathName,
                                      const ZCHAR * symbolName,
                                      const ZCHAR * extensions) const = 0;
    virtual Zcad::ErrorStatus getSymbolNameFromPathName(
                                      ZCHAR *&      pSymbolName,
                                      const ZCHAR * pathName,
                                      const ZCHAR * extensions) const = 0;
    virtual Zcad::ErrorStatus preValidateSymbolName(
                                      ZCHAR *&      pSymbolName,
                                      bool         preserveCase) const = 0;
    virtual Zcad::ErrorStatus validateCompatibleSymbolName(
                                      const ZCHAR * name,
                                      bool         isNewName,
                                      bool         allowVerticalBar,
                                      bool         compatibilityMode) const = 0;

}; 

inline Zcad::ErrorStatus
getSymbolName(
    ZCHAR      *&pName,
    ZcDbObjectId objId)
{
    ZcDbSymbolTableRecord *pRec = NULL;
    Zcad::ErrorStatus es = zcdbOpenObject(pRec, objId, ZcDb::kForRead);
    if (es == Zcad::eOk) {
        es = pRec->getName(pName);
        Zcad::ErrorStatus closeStatus = pRec->close();
        assert(closeStatus == Zcad::eOk);
    }
    return es;
}

#define ZCDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v) n ## v
#define ZCDBSYMUTIL_SERVICESNAME_WITH_VERSION(n,v) \
        ZCDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v)
#define ZCDBSYMUTIL_SERVICES_NAME \
        ZCDBSYMUTIL_SERVICESNAME_WITH_VERSION( \
            servicesPtr, \
            ZCDBSYMUTIL_SERVICES_CURRENT_VERSION)
extern const Services * ZCDBSYMUTIL_SERVICES_NAME();


inline const Services *
servicesPtr()
{
    const Services * pSymUtil = ZCDBSYMUTIL_SERVICES_NAME();
    assert(pSymUtil != NULL);
//    assert(pSymUtil->version() == Services::kCurrentVersion); //Removed by Chinaweal WangTao 2009/12/21_1 for ZCEDSYMUTIL_SERVICES_NAME()为空实现，返回NULL导致Debug版死机。
    return pSymUtil;
}



#define DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(T_TABLE) \
inline Zcad::ErrorStatus \
get ## T_TABLE ## Id( \
    ZcDbObjectId &objId, \
    const ZCHAR  *name, \
    ZcDbDatabase *pDb) \
{ \
    if (pDb == NULL) \
        return Zcad::eNullObjectPointer; \
    ZcDb ## T_TABLE ## Table *pTable = NULL; \
    Zcad::ErrorStatus es = pDb->getSymbolTable(pTable, ZcDb::kForRead); \
    if (es == Zcad::eOk) { \
        es = pTable->getAt(name, objId); \
        Zcad::ErrorStatus closeStatus = pTable->close(); \
        assert(closeStatus == Zcad::eOk); \
    } \
    return es; \
}
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Block)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(DimStyle)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Layer)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Linetype)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(RegApp)

inline Zcad::ErrorStatus
getTextStyleId(
    ZcDbObjectId &objId,
    const ZCHAR  *name,
    ZcDbDatabase *pDb)
{
    if (pDb == NULL)
        return Zcad::eNullObjectPointer;
    ZcDbTextStyleTable *pTable = NULL;
    Zcad::ErrorStatus es = pDb->getSymbolTable(pTable, ZcDb::kForRead);
    if (es == Zcad::eOk) {
        ZcDbTextStyleTableRecord *pRec = NULL;
        es = pTable->getAt(name, pRec, ZcDb::kForRead);
        if (es == Zcad::eOk) {
            if (pRec->isShapeFile())
                es = Zcad::eKeyNotFound;
            else
                objId = pRec->objectId();
            Zcad::ErrorStatus closeStatus = pRec->close();
            assert(closeStatus == Zcad::eOk);
        }
        Zcad::ErrorStatus closeStatus = pTable->close();
        assert(closeStatus == Zcad::eOk);
    }
    return es;
}

DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(UCS)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(View)
#undef DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION


#define DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(T_TABLE) \
inline bool \
has ## T_TABLE( \
    ZcDbObjectId  objId, \
    ZcDbDatabase *pDb) \
{ \
    if (pDb == NULL) \
        return false; \
    bool hasSymbol = false; \
    ZcDb ## T_TABLE ## Table *pTable = NULL; \
    Zcad::ErrorStatus es = pDb->getSymbolTable(pTable, ZcDb::kForRead); \
    if (es == Zcad::eOk) { \
        hasSymbol = !!pTable->has(objId); \
        Zcad::ErrorStatus closeStatus = pTable->close(); \
        assert(closeStatus == Zcad::eOk); \
    } \
    return hasSymbol; \
}
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Block)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(DimStyle)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Layer)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Linetype)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(RegApp)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(TextStyle)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(UCS)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(View)
DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Viewport)
#undef DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION

#define DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(T_TABLE) \
inline bool \
has ## T_TABLE( \
    const ZCHAR  *name, \
    ZcDbDatabase *pDb) \
{ \
    if (pDb == NULL) \
        return false; \
    bool hasSymbol = false; \
    ZcDb ## T_TABLE ## Table *pTable = NULL; \
    Zcad::ErrorStatus es = pDb->getSymbolTable(pTable, ZcDb::kForRead); \
    if (es == Zcad::eOk) { \
        hasSymbol = !!pTable->has(name); \
        Zcad::ErrorStatus closeStatus = pTable->close(); \
        assert(closeStatus == Zcad::eOk); \
    } \
    return hasSymbol; \
}
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Block)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(DimStyle)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Layer)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Linetype)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(RegApp)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(TextStyle)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(UCS)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(View)
DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Viewport)
#undef DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION

} 

namespace ZcDbSymUtil = ZcDbSymbolUtilities;

Zcad::ErrorStatus  getTableStyleNameFromDbById(const ZcDbObjectId& objId,
                                               ZCHAR*& pName);

typedef ZcDbSymbolUtilities::Services ZcDbSymUtilServices;

inline const ZcDbSymUtilServices *
zcdbSymUtil()
{
    return ZcDbSymbolUtilities::servicesPtr();
}

#pragma pack (pop)

#endif 
