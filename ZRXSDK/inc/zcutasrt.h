#ifndef _ZCUTASRT_H
#define _ZCUTASRT_H

#include "ZdZChar.h"
#pragma pack (push, 8)

void zcutAssertMessage(
    const ZCHAR *condition,
    const ZCHAR *filename,
    int         lineNumber,
    const ZCHAR *status);

#pragma pack (pop)
#endif 
