#ifndef _ARXPORT_AD_ACEDSUBSEL_H_
#define _ARXPORT_AD_ACEDSUBSEL_H_ 1


#include "acarray.h"
#include "acdb.h"
#include "adsdef.h"

class ZcDbFullSubentPath;
typedef ZcDbFullSubentPath		AcDbFullSubentPath;

#include "..\inc\zcedsubsel.h"

#define acedSSSubentLength		zcedSSSubentLength
#define acedSSSubentAdd			zcedSSSubentAdd
#define acedSSSubentDel			zcedSSSubentDel
#define acedSSSubentMemb		zcedSSSubentMemb
#define acedSSSubentName		zcedSSSubentName
#define acedSSSubentNameX		zcedSSSubentNameX
#define acedSSSetSubentTypes	zcedSSSetSubentTypes

#endif