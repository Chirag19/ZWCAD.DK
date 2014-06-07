
#ifndef _ARXPORT_AD_DBXUTIL_H_
#define _ARXPORT_AD_DBXUTIL_H_ 1

#include "acadstrc.h"
#include "adesk.h"
#include "adsdef.h"
#include "dbidar.h"
#include "dbid.h"
#include "acutmem.h"

#include "windows.h"

class ZcGeMatrix3d;
class ZcDbObject;
class ZcDbOle2Frame;
class ZcCmColor;

typedef ZcGeMatrix3d AcGeMatrix3d ;
typedef ZcDbObject AcDbObject ;
typedef ZcDbOle2Frame AcDbOle2Frame ;
typedef ZcCmColor AcCmColor ;
#include "..\inc\zdbxutil.h"


#define acdbWcs2Ucs   zcdbWcs2Ucs
#define acdbWcs2Ecs   zcdbWcs2Ecs
#define acdbUcs2Wcs   zcdbUcs2Wcs
#define acdbUcs2Ecs   zcdbUcs2Ecs
#define acdbEcs2Wcs   zcdbEcs2Wcs
#define acdbEcs2Ucs   zcdbEcs2Ucs

#define acdbGetCurVportTableRecordId zcdbGetCurVportTableRecordId
#define acdbGetCurVportId			 zcdbGetCurVportId
#define acdbGetProxyInfo			 zcdbGetProxyInfo
#define acdbUcsMatrix				 zcdbUcsMatrix
#define acdbGetExtnames				 zcdbGetExtnames
#define acdbSetExtnames				 zcdbSetExtnames
#define acdbGetPreviewBitmapFromDwg  zcdbGetPreviewBitmapFromDwg
#define acdbGetReservedString		 zcdbGetReservedString
#define acdbXlateReservedString		 zcdbXlateReservedString
#define acdbIsReservedString		 zcdbIsReservedString
#define acdbGetUnitsConversion		 zcdbGetUnitsConversion
#define acdbDwkFileExists			 zcdbDwkFileExists
#define acdbQueueForRegen			 zcdbQueueForRegen
#define acdbGetDynDimStyleId		 zcdbGetDynDimStyleId
#define acdbCreateViewByViewport	 zcdbCreateViewByViewport
#define acdbOleHitTest				 zcdbOleHitTest
#define acdbOleGetRotationMatrix	 zcdbOleGetRotationMatrix
#define acdbOleGetOriginalWidthHeight	zcdbOleGetOriginalWidthHeight  
#define acdbOleSetOriginalWidthHeight	zcdbOleSetOriginalWidthHeight
#define acdbOleGetSelectedFontName		zcdbOleGetSelectedFontName
#define acdbOleSetSelectedFontName		zcdbOleSetSelectedFontName
#define acdbOleGetSelectedFontPointSize	zcdbOleGetSelectedFontPointSize
#define acdbOleSetSelectedFontPointSize	zcdbOleSetSelectedFontPointSize
#define acdbOleGetSelectedTextSizeInAcadUnits	zcdbOleGetSelectedTextSizeInZcadUnits
#define acdbOleSetSelectedTextSizeInAcadUnits	zcdbOleSetSelectedTextSizeInZcadUnits
#define acdbOleGetOriginalSelectedFontName		zcdbOleGetOriginalSelectedFontName
#define acdbOleSetOriginalSelectedFontName		zcdbOleSetOriginalSelectedFontName
#define acdbOleGetOriginalSelectedFontPointSize	zcdbOleGetOriginalSelectedFontPointSize
#define acdbOleSetOriginalSelectedFontPointSize	zcdbOleSetOriginalSelectedFontPointSize
#define acdbOleGetOriginalSelectedTextSizeInAcadUnits	zcdbOleGetOriginalSelectedTextSizeInZcadUnits
#define acdbOleSetOriginalSelectedTextSizeInAcadUnits	zcdbOleSetOriginalSelectedTextSizeInZcadUnits
#define acdbGetDimTextBackground		zcdbGetDimTextBackground
#define acdbSetDimTextBackground		zcdbSetDimTextBackground
#define acdbGetDimExtensionLength		zcdbGetDimExtensionLength
#define acdbSetDimExtensionLength		zcdbSetDimExtensionLength
#define acdbGetFixedLengthExtLineEnabled		zcdbGetFixedLengthExtLineEnabled
#define acdbSetFixedLengthExtLineEnabled		zcdbSetFixedLengthExtLineEnabled
#define acdbGetArcLengthSymbolPlacement			zcdbGetArcLengthSymbolPlacement
#define acdbGetArcLengthSymbolPlacement			zcdbGetArcLengthSymbolPlacement
#define acdbSetArcLengthSymbolPlacement			zcdbSetArcLengthSymbolPlacement
#define acdbGetDimLineLinetype			zcdbGetDimLineLinetype
#define acdbSetDimLineLinetype			zcdbSetDimLineLinetype
#define acdbGetDimExt1Linetype			zcdbGetDimExt1Linetype
#define acdbSetDimExt1Linetype			zcdbSetDimExt1Linetype
#define acdbGetDimExt2Linetype			zcdbGetDimExt2Linetype
#define acdbSetDimExt2Linetype			zcdbSetDimExt2Linetype
#define acdbGetLargeRadDimJogAngle		zcdbGetLargeRadDimJogAngle
#define acdbSetLargeRadDimJogAngle		zcdbSetLargeRadDimJogAngle
#define acdbGetDimFlipArrow				zcdbGetDimFlipArrow
#define acdbSetDimFlipArrow				zcdbSetDimFlipArrow
#define acdbGetDimFlipArrowWhich		zcdbGetDimFlipArrowWhich
#define acdbSetDimFlipArrowWhich		zcdbSetDimFlipArrowWhich
#define acdbGetExemptCheckFlag			zcdbGetExemptCheckFlag
#define acdbGetDimJogSymbolSize			zcdbGetDimJogSymbolSize
#define acdbSetDimJogSymbolSize			zcdbSetDimJogSymbolSize
#define acdbGetDimJogSymbolPosition		zcdbGetDimJogSymbolPosition
#define acdbSetDimJogSymbolPosition		zcdbSetDimJogSymbolPosition
#define acdbGetRadialExtensionAngles	zcdbGetRadialExtensionAngles
#define acdbSetRadialExtensionAngles	zcdbSetRadialExtensionAngles
#define acdbGetDimAngExtOn				zcdbGetDimAngExtOn
#define acdbSetDimAngExtOn				zcdbSetDimAngExtOn
#define acdbGetDimTolAlign				zcdbGetDimTolAlign
#define acdbSetDimTolAlign				zcdbSetDimTolAlign
#define acdbGetDimBreakSize				zcdbGetDimBreakSize
#define acdbSetDimBreakSize				zcdbSetDimBreakSize
#define acdbGetViewportVisualStyle		zcdbGetViewportVisualStyle
#define acdbSetViewportVisualStyle		zcdbSetViewportVisualStyle
#define acdbForceTextAdjust				zcdbForceTextAdjust
#define acdbIsInLongTransaction			zcdbIsInLongTransaction
#define acdbSetExemptCheckFlag			zcdbSetExemptCheckFlag

#endif


