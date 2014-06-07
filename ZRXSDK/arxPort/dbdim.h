
#ifndef _ARXPORT_AD_DBDIM_H_
#define _ARXPORT_AD_DBDIM_H_ 1 

#include "dbmain.h"
#include "dbmtext.h"
#include "..\inc\zdbdim.h"

#define AcDmUtil		ZcDmUtil

typedef ZcDbDimension				AcDbDimension;
typedef ZcDbOrdinateDimension		AcDbOrdinateDimension;
typedef ZcDbAlignedDimension		AcDbAlignedDimension;
typedef ZcDbRotatedDimension		AcDbRotatedDimension;
typedef ZcDb3PointAngularDimension	AcDb3PointAngularDimension;
typedef ZcDb2LineAngularDimension	AcDb2LineAngularDimension;
typedef ZcDbRadialDimension			AcDbRadialDimension;
typedef ZcDbDiametricDimension		AcDbDiametricDimension;
typedef ZcDbArcDimension			AcDbArcDimension;
typedef ZcDbRadialDimensionLarge	AcDbRadialDimensionLarge;
#endif