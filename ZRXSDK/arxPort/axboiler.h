
#ifndef _ARXPORT_AD_AXBOILER_H_
#define _ARXPORT_AD_AXBOILER_H_ 1


#include "axobjref.h"
#include "adesk.h" 
#include "..\inc\zaxboiler.h"

#define IAcadBaseObject	IZcadBaseObject

typedef LPZCADBASEOBJECT		LPACADBASEOBJECT;
typedef IZcadBaseObject			IAcadBaseObject;
typedef IZcadBaseObject2		IAcadBaseObject2;
typedef LPZCADBASEOBJECT2		LPACADBASEOBJECT2;
typedef IZcadBaseDatabase		IAcadBaseDatabase;
typedef LPZCADBASEDATABASE		LPACADBASEDATABASE;

#define IAcadZcCmColorAccess	IZcadZcCmColorAccess

typedef IZcadZcCmColorAccess	IAcadZcCmColorAccess;
typedef LPZCADZCCMCOLORACCESS	LPACADZCCMCOLORACCESS;
typedef IZcadBaseSubEntity		IAcadBaseSubEntity;
typedef LPZCADSUBENTITY			LPACADSUBENTITY;

#define AcAxErase				ZcAxErase
#define AcAxSetXData			ZcAxSetXData
#define AcAxGetXData			ZcAxGetXData
#define AcAxGetObjectName		ZcAxGetObjectName
#define AcAxGetHandle			ZcAxGetHandle
#define AcAxGetColor			ZcAxGetColor
#define AcAxPutColor			ZcAxPutColor
#define AcAxGetTrueColor		ZcAxGetTrueColor
#define AcAxPutTrueColor		ZcAxPutTrueColor
#define AcAxGetLayer			ZcAxGetLayer
#define AcAxPutLayer			ZcAxPutLayer
#define AcAxGetLinetype			ZcAxGetLinetype
#define AcAxPutLinetype			ZcAxPutLinetype
#define AcAxGetShadowDisplay	ZcAxGetShadowDisplay
#define AcAxPutShadowDisplay	ZcAxPutShadowDisplay
#define AcAxEnableShadowDisplay	ZcAxEnableShadowDisplay
#define AcAxGetMaterial			ZcAxGetMaterial
#define AcAxPutMaterial			ZcAxPutMaterial
#define AcAxGetLinetypeScale	ZcAxGetLinetypeScale
#define AcAxPutLinetypeScale	ZcAxPutLinetypeScale
#define AcAxGetVisible			ZcAxGetVisible
#define AcAxPutVisible			ZcAxPutVisible
#define AcAxArrayPolar			ZcAxArrayPolar
#define AcAxArrayRectangular	ZcAxArrayRectangular
#define AcAxHighlight			ZcAxHighlight
#define AcAxCopy				ZcAxCopy
#define AcAxMove				ZcAxMove
#define AcAxRotate				ZcAxRotate
#define AcAxRotate3D			ZcAxRotate3D
#define AcAxMirror				ZcAxMirror
#define AcAxMirror3D			ZcAxMirror3D
#define AcAxScaleEntity			ZcAxScaleEntity
#define AcAxTransformBy			ZcAxTransformBy
#define AcAxUpdate				ZcAxUpdate
#define AcAxGetBoundingBox		ZcAxGetBoundingBox
#define AcAxIntersectWith		ZcAxIntersectWith
#define AcAxGetPlotStyleName	ZcAxGetPlotStyleName
#define AcAxPutPlotStyleName	ZcAxPutPlotStyleName
#define AcAxGetLineWeight		ZcAxGetLineWeight
#define AcAxPutLineWeight		ZcAxPutLineWeight
#define AcAxGetHyperlinks		ZcAxGetHyperlinks
#define AcAxHasExtensionDictionary	ZcAxHasExtensionDictionary
#define AcAxGetExtensionDictionary	ZcAxGetExtensionDictionary
#define AcAxGetDatabase			ZcAxGetDatabase
#define AcAxGetOwnerId			ZcAxGetOwnerId
#ifdef _WIN64
#define AcAxGetObjectId32		ZcAxGetObjectId32
#define AcAxGetObjectId64		ZcAxGetObjectId64
#endif
#define RaiseAcAXException		RaiseZcAXException
#define RaiseArxException		RaiseZrxException
#define AcAxGetIUnknownOfObject	ZcAxGetIUnknownOfObject
#define AcAxErase				ZcAxErase
//#define AcAxSetXData			ZcAxSetXData
//#define AcAxGetXData			ZcAxGetXData
//#define AcAxGetObjectName		ZcAxGetObjectName
//#define AcAxGetHandle			ZcAxGetHandle
//#define AcAxGetColor			ZcAxGetColor
//#define AcAxPutColor			ZcAxPutColor
//#define AcAxGetTrueColor		ZcAxGetTrueColor
//#define AcAxPutTrueColor		ZcAxPutTrueColor
//#define AcAxGetLayer			ZcAxGetLayer
//#define AcAxPutLayer			ZcAxPutLayer
//#define AcAxGetLinetype			ZcAxGetLinetype
//#define AcAxPutLinetype			ZcAxPutLinetype
//#define AcAxGetMaterial			ZcAxGetMaterial
//#define AcAxPutMaterial			ZcAxPutMaterial
//#define AcAxGetLinetypeScale	ZcAxGetLinetypeScale
//#define AcAxPutLinetypeScale	ZcAxPutLinetypeScale
//#define AcAxGetShadowDisplay	ZcAxGetShadowDisplay
//#define AcAxPutShadowDisplay	ZcAxPutShadowDisplay
//#define AcAxEnableShadowDisplay	ZcAxEnableShadowDisplay
//#define AcAxGetVisible			ZcAxGetVisible
//#define AcAxPutVisible			ZcAxPutVisible
//#define AcAxArrayPolar			ZcAxArrayPolar
//#define AcAxArrayRectangular	ZcAxArrayRectangular
//#define AcAxHighlight			ZcAxHighlight
//#define AcAxCopy				ZcAxCopy
//#define AcAxMove				ZcAxMove
//#define AcAxRotate				ZcAxRotate
//#define AcAxRotate3D			ZcAxRotate3D
//#define AcAxMirror				ZcAxMirror
//#define AcAxMirror3D			ZcAxMirror3D
//#define AcAxScaleEntity			ZcAxScaleEntity
//#define AcAxTransformBy			ZcAxTransformBy
//#define AcAxUpdate				ZcAxUpdate
//#define AcAxGetBoundingBox		ZcAxGetBoundingBox
//#define AcAxIntersectWith		ZcAxIntersectWith
//#define AcAxGetPlotStyleName	ZcAxGetPlotStyleName
//#define AcAxPutPlotStyleName	ZcAxPutPlotStyleName
//#define AcAxGetLineWeight		ZcAxGetLineWeight
//#define AcAxPutLineWeight		ZcAxPutLineWeight
//#define AcAxGetHyperlinks		ZcAxGetHyperlinks
//#define AcAxHasExtensionDictionary	ZcAxHasExtensionDictionary
//#define AcAxGetExtensionDictionary	ZcAxGetExtensionDictionary
//#define AcAxGetOwnerId			ZcAxGetOwnerId

#endif
