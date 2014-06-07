#ifndef ZGEOMENT_DBBODY_H
#define ZGEOMENT_DBBODY_H


#include "zdbmain.h"
#include "zdbsubeid.h"

#pragma pack (push, 8)

class ZcDbBody: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBody);
             ZcDbBody();
    virtual ~ZcDbBody();

    virtual Zdesk::Boolean    isNull       () const;
    virtual void              list         () const;

    virtual void*             body         () const;                   
    virtual Zcad::ErrorStatus setBody      (const void* modelerBody);  

    virtual ZcDbSubentId    internalSubentId (void*) const;                   
    virtual void*           internalSubentPtr(const ZcDbSubentId& id) const;  

    static  Zcad::ErrorStatus acisOut      (const ZCHAR* fileName,
                                            const ZcDbVoidPtrArray&);
    static  Zcad::ErrorStatus acisIn       (const ZCHAR* fileName,
                                            ZcDbVoidPtrArray&);

 
    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                ZcDb::SubentType type,
                                Zdesk::GsMarker gsMark,
                                const ZcGePoint3d& pickPoint,
                                const ZcGeMatrix3d& viewXform,
                                int& numPaths,
                                ZcDbFullSubentPath*& subentPaths,
                                int numInserts = 0,
                                ZcDbObjectId* entAndInsertStack = NULL) const;

    virtual Zcad::ErrorStatus getGsMarkersAtSubentPath(
                                const ZcDbFullSubentPath& subPath,
                                ZcArray<Zdesk::GsMarker>& gsMarkers) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
 
    virtual Zdesk::UInt32 numChanges() const;

    void invalidateCachedBodySubentIds(); 

 
	virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* filer) const;
	

    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);

	 virtual Zdesk::Boolean      worldDraw(ZcGiWorldDraw* mode);
	 virtual void  viewportDraw(ZcGiViewportDraw* mode);

};

#pragma pack (pop)

#endif
