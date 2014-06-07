

#ifndef __ZAXBOILER_H_
#define __ZAXBOILER_H_

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
    #define AXAUTOEXP __declspec(dllexport)
#else
    #define AXAUTOEXP __declspec(dllimport)
#endif
#endif

#include "zaxobjref.h"
#include "zdesk.h"

DEFINE_GUID(IID_IZcadBaseObject, 
0xd503d6e1, 0xefaa, 0x4184, 0xb8, 0x4c, 0x5b, 0x49, 0xbc, 0xf8, 0x6e, 0x50);


#undef INTERFACE
#define INTERFACE IZcadBaseObject

interface DECLSPEC_UUID("D503D6E1-EFAA-4184-B84C-5B49BCF86E50") 
IZcadBaseObject : public IUnknown
{
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(SetObjectId)(THIS_ ZcDbObjectId& objId, 
                           ZcDbObjectId ownerId = ZcDbObjectId::kNull, 
                           ZCHAR* keyName = NULL) PURE;
    STDMETHOD(GetObjectId)(THIS_ ZcDbObjectId* objId) PURE;
    STDMETHOD(Clone)(THIS_ ZcDbObjectId ownerId, LPUNKNOWN* pUnkClone) PURE;
    STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
    STDMETHOD(NullObjectId)(THIS) PURE;
    STDMETHOD(OnModified)(THIS) PURE;
};

typedef IZcadBaseObject* LPZCADBASEOBJECT;

DEFINE_GUID(IID_IZcadBaseObject2,
0x5712e04f, 0x68eb, 0x4d25, 0x8c, 0x97, 0xb5, 0x2d, 0xf1, 0xed, 0xf8, 0x7e);


interface DECLSPEC_UUID("5712E04F-68EB-4d25-8C97-B52DF1EDF87E") 
IZcadBaseObject2 : public IUnknown       
{
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(ForceDbResident)(THIS_ VARIANT_BOOL* forceDbResident) PURE;
    STDMETHOD(AddToDb)(THIS_ ZcDbObjectId& objId, 
                       ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                       ZCHAR* keyName = NULL) PURE;
    STDMETHOD(CreateObject)(THIS_ ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                            ZCHAR* keyName = NULL) PURE;
    STDMETHOD(ObjectExists)(THIS_ VARIANT_BOOL* objectExists) PURE;
    STDMETHOD(SetObject)(THIS_ ZcDbObject*& pObj) PURE;
    STDMETHOD(GetObject)(THIS_ ZcDbObject*& pObj) PURE;
    STDMETHOD(OnModified)(THIS_ DISPID = DISPID_UNKNOWN) PURE;
};

typedef IZcadBaseObject2* LPZCADBASEOBJECT2;

DEFINE_GUID(IID_IRetrieveApplication, 
0xab54975d, 0x465, 0x4ad1, 0xa1, 0xe1, 0x92, 0x4b, 0x8e, 0xd1, 0x48, 0x5a);

interface DECLSPEC_UUID("AB54975D-0465-4ad1-A1E1-924B8ED1485A") 
IRetrieveApplication : public IUnknown
{
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(SetApplicationObject)(THIS_ LPDISPATCH pAppDisp) PURE;
    STDMETHOD(GetApplicationObject)(THIS_ LPDISPATCH* pAppDisp) PURE;
};

typedef IRetrieveApplication* LPRETRIEVEAPPLICATION;

DEFINE_GUID(IID_IZcadBaseDatabase, 
0x52ee53bf, 0x2a2d, 0x4a3e, 0xbf, 0x52, 0xc, 0xff, 0x49, 0x2, 0x33, 0x1f);

interface DECLSPEC_UUID("52EE53BF-2A2D-4a3e-BF52-0CFF4902331F") 
IZcadBaseDatabase : public IUnknown
{
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(SetDatabase)(THIS_ ZcDbDatabase*& pDb) PURE;
    STDMETHOD(GetDatabase)(THIS_ ZcDbDatabase** pDb) PURE;
    STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
};

typedef IZcadBaseDatabase* LPZCADBASEDATABASE;

DEFINE_GUID(IID_IIMetaColorSuppressor, 
0x385b6d24, 0x50d4, 0x4aa3, 0x92, 0xf, 0xbf, 0xb2, 0x83, 0x50, 0xa4, 0x8c);

interface DECLSPEC_UUID("385B6D24-50D4-4aa3-920F-BFB28350A48C")
IMetaColorSuppressor : public IUnknown
{
    STDMETHOD(GetSuppressor)(THIS_ bool* val) PURE;
    STDMETHOD(SetSuppressor)(THIS_ bool val) PURE;
};

typedef IMetaColorSuppressor* LPMETACOLORSUPPRESSOR;

DEFINE_GUID(IID_IZcadZcCmColorAccess,
0xeaf9884d, 0xdc72, 0x496e, 0x9c, 0x3a, 0xe6, 0xb1, 0xe5, 0x82, 0xff, 0xf4);

#undef INTERFACE
#define INTERFACE IZcadZcCmColorAccess

interface DECLSPEC_UUID("EAF9884D-DC72-496e-9C3A-E6B1E582FFF4")
IZcadZcCmColorAccess : public IUnknown
{
    STDMETHOD(GetZcCmColor)(THIS_ ZcCmColor* clr) PURE;
    STDMETHOD(SetZcCmColor)(THIS_ ZcCmColor* clr) PURE;
};

typedef IZcadZcCmColorAccess* LPZCADZCCMCOLORACCESS;

DEFINE_GUID(IID_IZcadBaseSubEntity, 
0x2db155c8, 0xcc2b, 0x4f08, 0xa9, 0xd8, 0x12, 0xbe, 0x24, 0xac, 0xa4, 0x89);

#undef INTERFACE
#define INTERFACE IZcadBaseSubEntity

interface DECLSPEC_UUID("2DB155C8-CC2B-4f08-A9D8-12BE24ACA489") 
IZcadBaseSubEntity : public IUnknown
{
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(OnModified)() PURE;
    STDMETHOD(SetFullSubEntPath)(THIS_ ZcDbFullSubentPath& subentPath) PURE; 
    STDMETHOD(GetFullSubEntPath)(THIS_ ZcDbFullSubentPath* subentPath) PURE;
    STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
};

typedef IZcadBaseSubEntity* LPZCADSUBENTITY;


HRESULT AXAUTOEXP 
ZcAxErase(ZcDbObjectId& objId);

HRESULT AXAUTOEXP 
ZcAxSetXData(ZcDbObjectId& objId, VARIANT type, VARIANT data);

HRESULT AXAUTOEXP 
ZcAxGetXData(ZcDbObjectId& objId, BSTR bstrName, VARIANT* type, VARIANT* data);

HRESULT AXAUTOEXP 
ZcAxGetObjectName(ZcDbObjectId& objId, BSTR* pName);

HRESULT AXAUTOEXP 
ZcAxGetHandle(ZcDbObjectId& objId, BSTR* pHandle);

HRESULT AXAUTOEXP 
ZcAxGetColor(ZcDbObjectId& objId, ZcColor* pColor);

HRESULT AXAUTOEXP 
ZcAxPutColor(ZcDbObjectId& objId, ZcColor color);

HRESULT AXAUTOEXP
ZcAxGetTrueColor(ZcDbObjectId& objId, IZcadZcCmColor** pColor);

HRESULT AXAUTOEXP 
ZcAxPutTrueColor(ZcDbObjectId& objId, IZcadZcCmColor* color);

HRESULT AXAUTOEXP 
ZcAxGetLayer(ZcDbObjectId& objId, BSTR* pLayer);

HRESULT AXAUTOEXP 
ZcAxPutLayer(ZcDbObjectId& objId, BSTR layer);

HRESULT AXAUTOEXP 
ZcAxGetLinetype(ZcDbObjectId& objId, BSTR* pLinetype);

HRESULT AXAUTOEXP 
ZcAxPutLinetype(ZcDbObjectId& objId, BSTR linetype);

HRESULT AXAUTOEXP 
ZcAxGetShadowDisplay(ZcDbObjectId& objId, ZcShadowDisplayType* pShadowDisplay);

HRESULT AXAUTOEXP 
ZcAxPutShadowDisplay(ZcDbObjectId& objId, ZcShadowDisplayType shadowDisplay);

HRESULT AXAUTOEXP 
ZcAxEnableShadowDisplay(ZcDbObjectId& objId, bool* pEnabled);

HRESULT AXAUTOEXP 
ZcAxGetMaterial(ZcDbObjectId& objId, BSTR* pMaterial);

HRESULT AXAUTOEXP 
ZcAxPutMaterial(ZcDbObjectId& objId, BSTR material);

HRESULT AXAUTOEXP 
ZcAxGetLinetypeScale(ZcDbObjectId& objId, double* pLinetypeScale);

HRESULT AXAUTOEXP 
ZcAxPutLinetypeScale(ZcDbObjectId& objId, double linetypeScale);

HRESULT AXAUTOEXP 
ZcAxGetVisible(ZcDbObjectId& objId, VARIANT_BOOL* pVisible);

HRESULT AXAUTOEXP 
ZcAxPutVisible(ZcDbObjectId& objId, VARIANT_BOOL visible);

HRESULT AXAUTOEXP 
ZcAxArrayPolar(ZcDbObjectId& objId, LPDISPATCH pAppDisp, int numObjs, 
               double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);

HRESULT AXAUTOEXP 
ZcAxArrayRectangular(ZcDbObjectId& objId, LPDISPATCH pAppDisp, int numRows, 
                     int numCols, int numLvls, double disRows, double disCols,
                     double disLvls, VARIANT* pArrayObjs);

HRESULT AXAUTOEXP 
ZcAxHighlight(ZcDbObjectId& objId, VARIANT_BOOL bHighlight);

HRESULT AXAUTOEXP 
ZcAxCopy(ZcDbObjectId& objId, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj, 
         ZcDbObjectId ownerId = ZcDbObjectId::kNull);

HRESULT AXAUTOEXP 
ZcAxMove(ZcDbObjectId& objId, VARIANT fromPoint, VARIANT toPoint);

HRESULT AXAUTOEXP 
ZcAxRotate(ZcDbObjectId& objId, VARIANT basePoint, double rotationAngle);

HRESULT AXAUTOEXP 
ZcAxRotate3D(ZcDbObjectId& objId, VARIANT point1, VARIANT point2, 
             double rotationAngle);

HRESULT AXAUTOEXP 
ZcAxMirror(ZcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1, 
           VARIANT point2, LPDISPATCH* pMirrorObj);

HRESULT AXAUTOEXP 
ZcAxMirror3D(ZcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1, 
             VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);

HRESULT AXAUTOEXP 
ZcAxScaleEntity(ZcDbObjectId& objId, VARIANT basePoint, double scaleFactor);

HRESULT AXAUTOEXP 
ZcAxTransformBy(ZcDbObjectId& objId, VARIANT transMatrix);

HRESULT AXAUTOEXP 
ZcAxUpdate(ZcDbObjectId& objId);

HRESULT AXAUTOEXP 
ZcAxGetBoundingBox(ZcDbObjectId& objId, VARIANT* minPoint, VARIANT* maxPoint);

HRESULT AXAUTOEXP 
ZcAxIntersectWith(ZcDbObjectId& objId, LPDISPATCH pEntity, 
                  ZcExtendOption option, VARIANT* intPoints);

HRESULT AXAUTOEXP 
ZcAxGetPlotStyleName(ZcDbObjectId& objId, BSTR* plotStyleName);

HRESULT AXAUTOEXP 
ZcAxPutPlotStyleName(ZcDbObjectId& objId, BSTR plotStyleName);

HRESULT AXAUTOEXP 
ZcAxGetLineWeight(ZcDbObjectId& objId, ZCAD_LWEIGHT* lineWeight);

HRESULT AXAUTOEXP 
ZcAxPutLineWeight(ZcDbObjectId& objId, ZCAD_LWEIGHT lineWeight);

HRESULT AXAUTOEXP 
ZcAxGetHyperlinks(ZcDbObjectId& objId, LPDISPATCH pAppDisp, 
                  IZcadHyperlinks** pHyperlinks);

HRESULT AXAUTOEXP 
ZcAxHasExtensionDictionary(ZcDbObjectId& objId, VARIANT_BOOL* bHasDictionary);

HRESULT AXAUTOEXP 
ZcAxGetExtensionDictionary(ZcDbObjectId& objId, LPDISPATCH pAppDisp, 
                           IZcadDictionary** pExtDictionary);

HRESULT AXAUTOEXP 
ZcAxGetDatabase(ZcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);

HRESULT AXAUTOEXP
ZcAxGetOwnerId(ZcDbObjectId& objId, Zdesk::IntDbId * pOwnerId); 

#ifdef _WIN64
Zdesk::Int32 AXAUTOEXP
ZcAxGetObjectId32(const Zdesk::IntDbId& objId); 

Zdesk::IntDbId AXAUTOEXP
ZcAxGetObjectId64(const Zdesk::Int32& objId);  
#endif


HRESULT AXAUTOEXP
RaiseZcAXException(REFGUID iid, HRESULT hRes, DWORD dwException, ...);

HRESULT  AXAUTOEXP
RaiseZrxException(REFGUID iid, HRESULT hRes, Zcad::ErrorStatus es);

HRESULT AXAUTOEXP
ZcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, ZcDbObjectId& objId, LPDISPATCH pApp);

HRESULT AXAUTOEXP
ZcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, ZcDbObject* pObj, LPDISPATCH pApp);


HRESULT AXAUTOEXP 
ZcAxErase(ZcAxObjectRef& objRef);

HRESULT AXAUTOEXP 
ZcAxSetXData(ZcAxObjectRef& objRef, VARIANT type, VARIANT data);

HRESULT AXAUTOEXP 
ZcAxGetXData(ZcAxObjectRef& objRef, BSTR bstrName, VARIANT* type, VARIANT* data);

HRESULT AXAUTOEXP 
ZcAxGetObjectName(ZcAxObjectRef& objRef, BSTR* pName);

HRESULT AXAUTOEXP 
ZcAxGetHandle(ZcAxObjectRef& objRef, BSTR* pHandle);

HRESULT AXAUTOEXP 
ZcAxGetColor(ZcAxObjectRef& objRef, ZcColor* pColor);

HRESULT AXAUTOEXP 
ZcAxPutColor(ZcAxObjectRef& objRef, ZcColor color);

HRESULT AXAUTOEXP
ZcAxGetTrueColor(ZcAxObjectRef& objRef, IZcadZcCmColor** pColor); 
                                                                  
HRESULT AXAUTOEXP                                                 
ZcAxPutTrueColor(ZcAxObjectRef& objRef, IZcadZcCmColor* color);   

HRESULT AXAUTOEXP 
ZcAxGetLayer(ZcAxObjectRef& objRef, BSTR* pLayer);

HRESULT AXAUTOEXP 
ZcAxPutLayer(ZcAxObjectRef& objRef, BSTR layer);

HRESULT AXAUTOEXP 
ZcAxGetLinetype(ZcAxObjectRef& objRef, BSTR* pLinetype);

HRESULT AXAUTOEXP 
ZcAxPutLinetype(ZcAxObjectRef& objRef, BSTR linetype);

HRESULT AXAUTOEXP 
ZcAxGetMaterial(ZcAxObjectRef& objRef, BSTR* pMaterial);

HRESULT AXAUTOEXP 
ZcAxPutMaterial(ZcAxObjectRef& objRef, BSTR material);

HRESULT AXAUTOEXP 
ZcAxGetLinetypeScale(ZcAxObjectRef& objRef, double* pLinetypeScale);

HRESULT AXAUTOEXP 
ZcAxPutLinetypeScale(ZcAxObjectRef& objRef, double linetypeScale);

HRESULT AXAUTOEXP 
ZcAxGetShadowDisplay(ZcAxObjectRef& objRef, ZcShadowDisplayType* pShadowDisplay);

HRESULT AXAUTOEXP 
ZcAxPutShadowDisplay(ZcAxObjectRef& objRef, ZcShadowDisplayType shadowDisplay);

HRESULT AXAUTOEXP 
ZcAxEnableShadowDisplay(ZcAxObjectRef& objRef, bool* pEnabled);

HRESULT AXAUTOEXP 
ZcAxGetVisible(ZcAxObjectRef& objRef, VARIANT_BOOL* pVisible);

HRESULT AXAUTOEXP 
ZcAxPutVisible(ZcAxObjectRef& objRef, VARIANT_BOOL visible);

HRESULT AXAUTOEXP 
ZcAxArrayPolar(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numObjs, 
               double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);

HRESULT AXAUTOEXP 
ZcAxArrayRectangular(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numRows, 
                     int numCols, int numLvls, double disRows, double disCols,
                     double disLvls, VARIANT* pArrayObjs);

HRESULT AXAUTOEXP 
ZcAxHighlight(ZcAxObjectRef& objRef, VARIANT_BOOL bHighlight);

HRESULT AXAUTOEXP 
ZcAxCopy(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj, 
         ZcDbObjectId ownerId = ZcDbObjectId::kNull);
HRESULT AXAUTOEXP 
ZcAxMove(ZcAxObjectRef& objRef, VARIANT fromPoint, VARIANT toPoint);

HRESULT AXAUTOEXP 
ZcAxRotate(ZcAxObjectRef& objRef, VARIANT basePoint, double rotationAngle);

HRESULT AXAUTOEXP 
ZcAxRotate3D(ZcAxObjectRef& objRef, VARIANT point1, VARIANT point2, 
             double rotationAngle);

HRESULT AXAUTOEXP 
ZcAxMirror(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1, 
           VARIANT point2, LPDISPATCH* pMirrorObj);

HRESULT AXAUTOEXP 
ZcAxMirror3D(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1, 
             VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);

HRESULT AXAUTOEXP 
ZcAxScaleEntity(ZcAxObjectRef& objRef, VARIANT basePoint, double scaleFactor);

HRESULT AXAUTOEXP 
ZcAxTransformBy(ZcAxObjectRef& objRef, VARIANT transMatrix);

HRESULT AXAUTOEXP 
ZcAxUpdate(ZcAxObjectRef& objRef);

HRESULT AXAUTOEXP 
ZcAxGetBoundingBox(ZcAxObjectRef& objRef, VARIANT* minPoint, VARIANT* maxPoint);

HRESULT AXAUTOEXP 
ZcAxIntersectWith(ZcAxObjectRef& objRef, LPDISPATCH pEntity, 
                  ZcExtendOption option, VARIANT* intPoints);

HRESULT AXAUTOEXP 
ZcAxGetPlotStyleName(ZcAxObjectRef& objRef, BSTR* plotStyleName);

HRESULT AXAUTOEXP 
ZcAxPutPlotStyleName(ZcAxObjectRef& objRef, BSTR plotStyleName);

HRESULT AXAUTOEXP 
ZcAxGetLineWeight(ZcAxObjectRef& objRef, ZCAD_LWEIGHT* lineWeight);

HRESULT AXAUTOEXP 
ZcAxPutLineWeight(ZcAxObjectRef& objRef, ZCAD_LWEIGHT lineWeight);

HRESULT AXAUTOEXP 
ZcAxGetHyperlinks(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, 
                  IZcadHyperlinks** pHyperlinks);

HRESULT AXAUTOEXP 
ZcAxHasExtensionDictionary(ZcAxObjectRef& objRef, VARIANT_BOOL* bHasDictionary);

HRESULT AXAUTOEXP 
ZcAxGetExtensionDictionary(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, 
                           IZcadDictionary** pExtDictionary);
HRESULT AXAUTOEXP
ZcAxGetOwnerId(ZcAxObjectRef& objRef, Zdesk::IntDbId * pOwnerId); 

#endif
