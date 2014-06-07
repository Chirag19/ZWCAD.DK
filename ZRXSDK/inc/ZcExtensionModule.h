

#ifndef _ZcExtensionModule_h
#define _ZcExtensionModule_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zcdocman.h"



class ZcExtensionModule {
public:
                ZcExtensionModule ();
                ~ZcExtensionModule ();

protected:
        BOOL    m_bAttached;
        HINSTANCE m_hDefaultResource;
        HINSTANCE m_hModuleResource;
        AFX_EXTENSION_MODULE m_module;

public:
        BOOL    Attached ();
        HINSTANCE DefaultResourceInstance ();
        HINSTANCE ModuleResourceInstance ();


        BOOL    AttachInstance (HINSTANCE hInst);


        void    DetachInstance ();
};

inline ZcExtensionModule::ZcExtensionModule () :
    m_bAttached(FALSE),
    m_hDefaultResource(NULL),
    m_hModuleResource(NULL)
{
    m_module.bInitialized = FALSE;
    m_module.hModule = NULL;
    m_module.hResource = NULL;
    m_module.pFirstSharedClass = NULL;
    m_module.pFirstSharedFactory = NULL;
}

inline ZcExtensionModule::~ZcExtensionModule ()
{
}

inline BOOL ZcExtensionModule::Attached ()
{
    return m_bAttached;
}

inline BOOL ZcExtensionModule::AttachInstance (HINSTANCE hInst)
{
    if (m_bAttached)
        return FALSE;
    m_bAttached = AfxInitExtensionModule(m_module, hInst);
    if (m_bAttached) {
        m_hDefaultResource = AfxGetResourceHandle();
        m_hModuleResource = hInst;
        new CDynLinkLibrary(m_module);
    }
    return m_bAttached;
}

inline HINSTANCE ZcExtensionModule::DefaultResourceInstance ()
{
    return m_hDefaultResource;
}

inline void ZcExtensionModule::DetachInstance ()
{
    if (m_bAttached) {
        AfxTermExtensionModule(m_module);
        m_bAttached = FALSE;
    }
}

inline HINSTANCE ZcExtensionModule::ModuleResourceInstance ()
{
    return m_hModuleResource;
}



class ZcModuleResourceOverride {
public:
                    ZcModuleResourceOverride ();
                    ZcModuleResourceOverride (HINSTANCE hInst);
                    ~ZcModuleResourceOverride ();

private:
static  ZcExtensionModule& m_extensionModule;
};

inline ZcModuleResourceOverride::ZcModuleResourceOverride ()
{
    zcDocManager->pushResourceHandle(m_extensionModule.ModuleResourceInstance());
}

inline ZcModuleResourceOverride::ZcModuleResourceOverride (HINSTANCE hInst)
{
    zcDocManager->pushResourceHandle(hInst ? hInst : 
                                     m_extensionModule.ModuleResourceInstance());
}

inline ZcModuleResourceOverride::~ZcModuleResourceOverride ()
{
    zcDocManager->popResourceHandle();
}



#define ZC_DECLARE_EXTENSION_MODULE(exm)        \
    extern ZcExtensionModule exm;

#define ZC_IMPLEMENT_EXTENSION_MODULE(exm)      \
    ZcExtensionModule exm;                     \
    ZcExtensionModule& ZcModuleResourceOverride::m_extensionModule = exm;

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
