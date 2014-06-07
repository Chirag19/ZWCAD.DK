#ifndef _ARXPORT_AD_IMGDEF_H_
#define _ARXPORT_AD_IMGDEF_H_ 1

#include "dbmain.h"
#include "acgi.h"
#include "gept2dar.h"
#include "gemat2d.h"
#include "AdAChar.h"

class  RasterImageDefImp;
class  ZcDbImpRasterImageDefReactor;
             
typedef  ZcDbImpRasterImageDefReactor		AcDbImpRasterImageDefReactor;

#include "..\inc\zimgdef.h"


typedef ZcDbRasterImageDef					AcDbRasterImageDef;
typedef ZcDbRasterImageDefReactor			AcDbRasterImageDefReactor;
typedef ZcDbRasterImageDefTransReactor		AcDbRasterImageDefTransReactor;
typedef ZcDbRasterImageDefFileAccessReactor	AcDbRasterImageDefFileAccessReactor;

#endif