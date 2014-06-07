#ifndef _ZCGIUTIL_H
#define _ZCGIUTIL_H 1

#include "zdbid.h"
#include "ZdZChar.h"
#include "zcgi.h"

#pragma pack (push, 8)

Zcad::ErrorStatus fromZcDbTextStyle(ZcGiTextStyle&,
                              const ZcDbObjectId& ZcDbStyleId);
Zcad::ErrorStatus fromZcDbTextStyle(ZcGiTextStyle&, const ZCHAR * ZcDbStyleName);

Zcad::ErrorStatus toZcDbTextStyle(ZcGiTextStyle&);

Zcad::ErrorStatus toZcDbTextStyle(ZcGiTextStyle&,
                                  ZcDbObjectId& ZcDbStyleId);


Zcad::ErrorStatus toZcDbTextStyle(const ZcDbObjectId ZcDbStyleId,
                                  ZcGiTextStyle&);

Zcad::ErrorStatus toZcDbTextStyle(ZcGiTextStyle&, const ZCHAR * ZcDbStyleName);


Zcad::ErrorStatus toZcDbTextStyle(ZcGiTextStyle&, const ZCHAR * ZcDbStyleName,
                                  ZcDbObjectId& ZcDbStyleId);


#pragma pack (pop)

#endif
