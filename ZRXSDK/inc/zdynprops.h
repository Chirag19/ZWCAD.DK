

#ifndef _ZDYNPROPS_H
#define _ZDYNPROPS_H

#include "ZdZChar.h"


#define S_NOTIFYCMD MAKE_HRESULT(0,0,0x02)

interface IZPropertyManager;
interface IZDynamicProperty;
interface IZPropertyManager2;
interface IZDynamicProperty2;
interface IZPropertySource;

class ZOPMPerInstancePropertySources : public ZcRxObject  
{
public:
    ZCRX_DECLARE_MEMBERS(ZOPMPerInstancePropertySources);
    virtual ~ZOPMPerInstancePropertySources(){}
    

    virtual bool SetPropertySourceAt(const BSTR* pName, IZPropertySource* pSource) = 0;

    virtual IZPropertySource* GetPropertySourceAt(const BSTR* pName) = 0;

    virtual bool RemovePropertySourceAt(const BSTR* pName) = 0;

    virtual bool GetPropertySourceNames(VARIANT* pNames) = 0;
    
};


class ZOPMPerInstancePropertyExtension : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZOPMPerInstancePropertyExtension);
    virtual ~ZOPMPerInstancePropertyExtension() {};

    virtual bool AddObjectPropertySourceName(const BSTR* pName) = 0;

    virtual bool RemoveObjectPropertySourceName(const BSTR* pName) = 0;

    virtual bool GetObjectPropertySourceNames(VARIANT* pNames) = 0;
};


class ZOPMPerInstancePropertyExtensionFactory : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZOPMPerInstancePropertyExtensionFactory);
    virtual ~ZOPMPerInstancePropertyExtensionFactory(){};

    virtual ZOPMPerInstancePropertyExtension* CreateOPMPerInstancePropertyExtension(ZcRxClass* pClass) = 0;
};


#define GET_OPM_PERINSTANCE_CREATE_PROTOCOL() \
ZOPMPerInstancePropertyExtensionFactory::cast(ZcDbDatabase::desc()->queryX(ZOPMPerInstancePropertyExtensionFactory::desc()))


#define GET_OPM_PERINSTANCE_PROPERTY_SOURCES() \
ZOPMPerInstancePropertySources::cast(ZcDbDatabase::desc()->queryX(ZOPMPerInstancePropertySources::desc()))


#define GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(pZcRxClass) \
GET_OPM_PERINSTANCE_CREATE_PROTOCOL()->CreateOPMPerInstancePropertyExtension(pZcRxClass)


class ZOPMPropertyExtension : public ZcRxObject  
{
public:
    ZCRX_DECLARE_MEMBERS(ZOPMPropertyExtension);
    virtual ~ZOPMPropertyExtension(){}

    virtual IZPropertyManager* GetPropertyManager() = 0;

    virtual void SetPropertyManager(IZPropertyManager* pPropManager) = 0;
};



class ZOPMPropertyExtensionFactory: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZOPMPropertyExtensionFactory);
    virtual ~ZOPMPropertyExtensionFactory(){}


    virtual ZOPMPropertyExtension* CreateOPMObjectProtocol(ZcRxClass* pClass, 
                                                             LONG lReserved = NULL) = 0;
    
    virtual ZOPMPropertyExtension* CreateOPMCommandProtocol(const ZCHAR * pGlobalCommand, 
                                                             LONG lReserved = NULL) = 0;
    

    virtual BOOL GetOPMManager(const ZCHAR * pGlobalCommand, IZPropertyManager** pManager) = 0;

    virtual BOOL GetPropertyCount(ZcRxClass* pClass, LONG* pPropCount) = 0;

    virtual LONG GetPropertyClassArray(ZcRxClass* pClass, 
                                       IZDynamicProperty**  pPropertyArray) = 0; 

    virtual BOOL GetPropertyCountEx(ZcRxClass* pClass, LONG* pPropCount) = 0;

    virtual LONG GetPropertyClassArray(ZcRxClass* pClass, 
                                       IUnknown**  pPropertyArray) = 0; 
};

#define GET_OPMEXTENSION_CREATE_PROTOCOL() \
ZOPMPropertyExtensionFactory::cast(ZcDbDatabase::desc()->queryX(ZOPMPropertyExtensionFactory::desc()))


#define GET_OPMPROPERTY_MANAGER(pZcRxClass) \
GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(pZcRxClass)->GetPropertyManager() 


#define GET_OPM_COMMAND_PROPERTY_MANAGER(pCommandName) \
GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(pCommandName)->GetPropertyManager() 

typedef BOOL (*OPMDIALOGPROC)(void);

const int ZMAX_OPMSTRLEN = 256;

DEFINE_GUID(IID_IZDynamicPropertyNotify, 0x8B384028, 0xACA8, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACA8-11d1-A2B4-080009DC639A")
IZDynamicPropertyNotify : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(OnChanged)(THIS_ IZDynamicProperty* pDynamicProperty) PURE;

    STDMETHOD(GetCurrentSelectionSet)(THIS_ VARIANT* pSelection) PURE;
};

typedef IZDynamicPropertyNotify FAR* LPZDYNAMICPROPERTYNOTIFY;

DEFINE_GUID(IID_IZDynamicPropertyNotify2, 0x975112b5, 0x5403, 0x4197, 0xaf, 0xb8, 0x90, 0xc6, 0xca, 0x73, 0xb9, 0xe1);

interface DECLSPEC_UUID("975112B5-5403-4197-AFB8-90C6CA73B9E1")
IZDynamicPropertyNotify2 : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(OnChanged)(THIS_ IUnknown* pDynamicProperty) PURE;

    STDMETHOD(GetCurrentSelectionSet)(THIS_ VARIANT* pSelection) PURE;
};

typedef IZDynamicPropertyNotify2 FAR* LPZDYNAMICPROPERTYNOTIFY2;


DEFINE_GUID(IID_IZDynamicProperty, 0x8B384028, 0xACA9, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACA9-11d1-A2B4-080009DC639A")
IZDynamicProperty : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(GetGUID)(THIS_ GUID* propGUID) PURE;

    STDMETHOD(GetDisplayName)(THIS_ BSTR* bstrName) PURE;

    STDMETHOD(IsPropertyEnabled)(THIS_ LONG_PTR objectID,
                                      BOOL* pbEnabled) PURE;

    STDMETHOD(IsPropertyReadOnly)(THIS_ BOOL* pbReadonly) PURE;

    STDMETHOD(GetDescription)(THIS_ BSTR* bstrName) PURE;
    

    STDMETHOD(GetCurrentValueName)(THIS_ BSTR* pbstrName) PURE;

    STDMETHOD(GetCurrentValueType)(THIS_ VARTYPE* pVarType) PURE;

    STDMETHOD(GetCurrentValueData)(THIS_ LONG_PTR objectID, 
                                      VARIANT* pvarData) PURE;

    STDMETHOD(SetCurrentValueData)(THIS_ LONG_PTR objectID, 
                                         const VARIANT varData) PURE;


    STDMETHOD(Connect)(THIS_ IZDynamicPropertyNotify* pSink) PURE;
    STDMETHOD(Disconnect)(THIS_ ) PURE;
};

typedef IZDynamicProperty FAR* LPZDYNAMICPROPERTY;


DEFINE_GUID(IID_IZDynamicProperty2, 0x9caf41c2, 0xca86, 0x4ffb, 0xb0, 0x5a, 0xac, 0x43, 0xc4, 0x24, 0xd0, 0x76);

interface DECLSPEC_UUID("9CAF41C2-CA86-4ffb-B05A-AC43C424D076")
IZDynamicProperty2 : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(GetGUID)(THIS_ GUID* propGUID) PURE;

    STDMETHOD(GetDisplayName)(THIS_ BSTR* bstrName) PURE;

    STDMETHOD(IsPropertyEnabled)(THIS_ IUnknown *pUnk,
                                      BOOL* pbEnabled) PURE;

    STDMETHOD(IsPropertyReadOnly)(THIS_ BOOL* pbReadonly) PURE;

    STDMETHOD(GetDescription)(THIS_ BSTR* bstrName) PURE;
    

    STDMETHOD(GetCurrentValueName)(THIS_ BSTR* pbstrName) PURE;

    STDMETHOD(GetCurrentValueType)(THIS_ VARTYPE* pVarType) PURE;

    STDMETHOD(GetCurrentValueData)(THIS_ IUnknown *pUnk, 
                                     VARIANT* pvarData) PURE;

    STDMETHOD(SetCurrentValueData)(THIS_ IUnknown *pUnk, 
                                         const VARIANT varData) PURE;


    STDMETHOD(Connect)(THIS_ IZDynamicPropertyNotify2* pSink) PURE;
    STDMETHOD(Disconnect)(THIS_ ) PURE;
};

typedef IZDynamicProperty2 FAR* LPZDYNAMICPROPERTY2;

const int ZDISPID_DYNAMIC = -23; 


DEFINE_GUID(IID_IZDynamicEnumProperty, 0x8B384028, 0xACB1, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACB1-11d1-A2B4-080009DC639A")
IZDynamicEnumProperty : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(GetNumPropertyValues)(THIS_ LONG* numValues) PURE;

    STDMETHOD(GetPropValueName)(THIS_ LONG index, 
                                   BSTR* valueName) PURE;

    STDMETHOD(GetPropValueData)(THIS_ LONG index, 
                                   VARIANT* valueName) PURE;
};

typedef IZDynamicEnumProperty FAR* LPZDYNAMICENUMPROPERTY;


DEFINE_GUID(IID_IZDynamicDialogProperty, 0x8B384028, 0xACB2, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACB2-11d1-A2B4-080009DC639A")
IZDynamicDialogProperty : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(GetCustomDialogProc)(THIS_ OPMDIALOGPROC* pDialogProc) PURE;

    STDMETHOD(GetMacroName)(THIS_ BSTR* bstrName) PURE;

};

typedef IZDynamicDialogProperty FAR* LPZDYNAMICDIALOGPROPERTY;


DEFINE_GUID(IID_IZPropertyManager, 0x8B384028, 0xACA9, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACA9-11d1-A2B4-080009DC639A")
IZPropertyManager : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(AddProperty)(THIS_ IZDynamicProperty FAR* pProperty) PURE;
    STDMETHOD(RemoveProperty)(THIS_ IZDynamicProperty FAR* pProperty) PURE;
    STDMETHOD(GetDynamicProperty)(THIS_ LONG index,
                                     IZDynamicProperty ** pProperty) PURE;
    STDMETHOD(GetDynamicPropertyByName)(THIS_ BSTR propName,
                                           IZDynamicProperty ** pProperty) PURE;
    STDMETHOD(GetDynamicPropertyCount)(THIS_ LONG* count) PURE;

    STDMETHOD(GetDynamicClassInfo)(THIS_ IUnknown* pObj,
                                        ITypeInfo** pptiDynamic,
                                        DWORD* dwCookie) PURE;
};

typedef IZPropertyManager FAR* LPZPROPERTYMANAGER;


DEFINE_GUID(IID_IZPropertyManager2, 0xfabc1c70, 0x1044, 0x4aa0, 0xbf, 0x8d, 0x91, 0xff, 0xf9, 0x5, 0x27, 0x15);

interface DECLSPEC_UUID("FABC1C70-1044-4aa0-BF8D-91FFF9052715")
IZPropertyManager2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(AddProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
    STDMETHOD(RemoveProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
    STDMETHOD(GetDynamicProperty)(THIS_ LONG index,
                                     IUnknown ** pDynPropObj) PURE;
    STDMETHOD(GetDynamicPropertyByName)(THIS_ BSTR propName,
                                           IUnknown ** pDynPropObj) PURE;
    STDMETHOD(GetDynamicPropertyCountEx)(THIS_ LONG* count) PURE;

    STDMETHOD(GetDynamicClassInfo)(THIS_ IUnknown* pObj,
                                        ITypeInfo** pptiDynamic,
                                        DWORD* dwCookie) PURE;
};

typedef IZPropertyManager2 FAR* LPZPROPERTYMANAGER2;


DEFINE_GUID(IID_IZPropertySource, 0x61d0a8e3, 0xc792, 0x4956, 0x8e, 0x96, 0x59, 0x43, 0x15, 0xb9, 0x59, 0x2);

interface DECLSPEC_UUID("61D0A8E3-C792-4956-8E96-594315B95902")
IZPropertySource : public IUnknown
{
    BEGIN_INTERFACE


    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;


    STDMETHOD(get_Name)(THIS_ BSTR* pName) PURE;

    STDMETHOD(GetProperties)(THIS_ IUnknown* pObject, VARIANT *pPropertyArray) PURE;
};

typedef IZPropertySource FAR* LPZPROPERTYSOURCE;
#endif 
