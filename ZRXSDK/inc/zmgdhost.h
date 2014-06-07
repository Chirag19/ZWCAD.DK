#include "ZdZChar.h"
#ifndef ZMGDHOST_H
#define ZMGDHOST_H 1
#pragma once

class ZcDbManagedHost
{
public:
    virtual int version() { return 1;}
    virtual Zcad::ErrorStatus load(const ZCHAR * fname)=0;
};

ZcDbManagedHost* ZDESK_STDCALL zcdbGetManagedHost();
Zcad::ErrorStatus ZDESK_STDCALL zcdbSetManagedHost(ZcDbManagedHost* pHost);
ZCDB_PORT HRESULT ZDESK_STDCALL zcdbInitializeManagedLayer();
ZCDB_PORT HRESULT ZDESK_STDCALL zcdbTerminateManagedLayer();


#endif 
