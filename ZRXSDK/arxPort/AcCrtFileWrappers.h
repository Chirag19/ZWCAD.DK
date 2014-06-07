#ifndef _ARXPORT_AD_ACCRTFILEWRAPPERS_H_
#define _ARXPORT_AD_ACCRTFILEWRAPPERS_H_ 1

#include "stdio.h"      // for fopen, FILE, fprintf, etc
#include <malloc.h>     // for _alloca
#include "AdCharFmt.h"
#include "..\inc\ZcCrtFileWrappers.h"

#define AcFILE_Assert		ZcFILE_Assert

typedef ZcFILE				AcFILE;

#endif