
#ifndef _ARXPORT_AD_DBUNDERLAYHOST_H_
#define _ARXPORT_AD_DBUNDERLAYHOST_H_ 1

#include "dbmain.h"
#include "acstring.h"

class ZcImpUnderlayLayer;

typedef ZcImpUnderlayLayer AcImpUnderlayLayer ;
#include "..\inc\zdbunderlayhost.h"

typedef ZcUnderlayLayer					AcUnderlayLayer;
typedef ZcDbUnderlayDrawContext			AcDbUnderlayDrawContext;
typedef ZcDbUnderlayItem				AcDbUnderlayItem;
typedef ZcDbDgnUnderlayItem				AcDbDgnUnderlayItem;
typedef ZcDbUnderlayFile				AcDbUnderlayFile;
typedef ZcDbUnderlayHost				AcDbUnderlayHost;

#define ItemVersionNumber		zItemVersionNumber
#define acdbGetCurrentDwfHost	zcdbGetCurrentDwfHost
#define acdbSetCurrentDwfHost	zcdbSetCurrentDwfHost
#define acdbGetCurrentDgnHost	zcdbGetCurrentDgnHost
#define acdbSetCurrentDgnHost	zcdbSetCurrentDgnHost
#define acdbGetCurrentDgnDocHost	zcdbGetCurrentDgnDocHost
#define acdbSetCurrentDgnDocHost	zcdbSetCurrentDgnDocHost
#define acdbConvertRgbToHsl			zcdbConvertRgbToHsl
#define acdbConvertHslToRgb			zcdbConvertHslToRgb
#endif