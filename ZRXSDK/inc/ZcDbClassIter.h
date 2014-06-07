#pragma once
#include "zdbmain.h"

#pragma pack (push, 4)

class ZDESK_NO_VTABLE ZcDbClassIterator
{
  public:
    
    static ZcDbClassIterator * ZDESK_STDCALL newIterator();

    
    static void ZDESK_STDCALL deleteIterator(ZcDbClassIterator *pIter);

    
    enum { kAllClasses = 0x01,        
           kCustomClasses   = 0x02,   
           kProxyClasses    = 0x04 }; 

    
    virtual Zcad::ErrorStatus start(ZcDbDatabase *pDb, int nFlags) = 0;

    
    virtual bool next() = 0;

   
    virtual bool done() const = 0;

    
    virtual void detach() = 0;

    
    virtual const ZCHAR *name() const = 0;

    
    virtual const ZCHAR *appName() const = 0;

    
    virtual const ZCHAR *dxfName() const = 0;

    
    virtual Zdesk::UInt32 numInstances() const = 0;

    
    virtual bool isProxy() const = 0;

    
    virtual bool isEntity() const = 0;


  protected:
    
    ZcDbClassIterator();
    ~ZcDbClassIterator();
};

#pragma pack (pop)

