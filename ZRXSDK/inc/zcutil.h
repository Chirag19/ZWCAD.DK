
#ifndef _ZCUTIL_H
#define _ZCUTIL_H

#include <stddef.h>
#include "zcadstrc.h"

#pragma pack (push, 8)

bool              zcutSplitString(
                      size_t &      numLeftBytes,
                      const ZCHAR *& pRight,
                      const ZCHAR  * source,
                      unsigned int  delimiter);

void              zcutTrimWhiteSpace(ZCHAR * pStr);

bool              zcutWcMatchEx(
                      const ZCHAR * string,
                      const ZCHAR * pattern,
                      bool         ignoreCase);

size_t            zcutXStrLength(const ZCHAR * str);

Zcad::ErrorStatus zcutXStrNormalize(
                      ZCHAR *& pStr,
                      bool preserveCase);

inline Zcad::ErrorStatus
zcutXStrUppercase(ZCHAR *& pStr)
{ return zcutXStrNormalize(pStr, false); }

#pragma pack (pop)
#endif 
