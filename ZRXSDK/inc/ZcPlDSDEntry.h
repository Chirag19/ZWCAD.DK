#ifndef ZCPLDSDENTRY_H
#define ZCPLDSDENTRY_H


#pragma once

#include "ZcPl.h"
#include "ZcPlObject.h"


class ZcPlDSDEntry  : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlDSDEntry)
public:

    enum SheetType {
        kSingleDWF  = 0,
        kMultiDWF = 1,
        kOriginalDevice = 2
    };

    ZCPL_PORT ZcPlDSDEntry();

    ZCPL_PORT virtual ~ZcPlDSDEntry();

    ZCPL_PORT ZcPlDSDEntry(const ZcPlDSDEntry & src);

    ZCPL_PORT ZcPlDSDEntry& operator= (const ZcPlDSDEntry &src);

    ZCPL_PORT const ZCHAR *      dwgName() const;
    ZCPL_PORT void              setDwgName(const ZCHAR * pName);

    ZCPL_PORT const ZCHAR *      layout() const;
    ZCPL_PORT void              setLayout(const ZCHAR * pLayoutName);
    
    ZCPL_PORT const ZCHAR *      title() const;
    ZCPL_PORT void              setTitle(const ZCHAR * pTitle);
    
    ZCPL_PORT const ZCHAR *      NPS() const;
    ZCPL_PORT void              setNPS(const ZCHAR * pNPSName);
    
    ZCPL_PORT const ZCHAR *      NPSSourceDWG() const;
    ZCPL_PORT void              setNPSSourceDWG(const ZCHAR * pNPWDWGName);

    ZCPL_PORT bool               has3dDwfSetup() const;
    ZCPL_PORT void              setHas3dDwfSetup(bool b3dDwfSetup);
};

#endif 
