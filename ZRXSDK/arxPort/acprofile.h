
#ifndef _ARXPORT_AD_ACPROFILE_H_
#define _ARXPORT_AD_ACPROFILE_H_ 1

#include "acarray.h"
#include "AdAChar.h"

class ZcApProfileStorage;
typedef ZcApProfileStorage AcApProfileStorage;

#include "..\inc\zcprofile.h"

typedef ZcApProfileManagerReactor		AcApProfileManagerReactor;
typedef ZcApProfileNameArray			AcApProfileNameArray;
typedef ZcApProfileManager				AcApProfileManager;

#define acProfileManagerPtr			zcProfileManagerPtr
#define acProfileManager			zcProfileManager

typedef ZcApProfileStorage			AcApProfileStorage;
#endif