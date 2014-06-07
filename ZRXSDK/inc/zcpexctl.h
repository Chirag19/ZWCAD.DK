#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef ___ZcPEXCtl_h__
#define ___ZcPEXCtl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IZcPeNumericEditor_FWD_DEFINED__
#define __IZcPeNumericEditor_FWD_DEFINED__
typedef interface IZcPeNumericEditor IZcPeNumericEditor;
#endif 	/* __IZcPeNumericEditor_FWD_DEFINED__ */


#ifndef __IZcPeVariantCtrl_FWD_DEFINED__
#define __IZcPeVariantCtrl_FWD_DEFINED__
typedef interface IZcPeVariantCtrl IZcPeVariantCtrl;
#endif 	/* __IZcPeVariantCtrl_FWD_DEFINED__ */


#ifndef __IZcPeColorCtrl_FWD_DEFINED__
#define __IZcPeColorCtrl_FWD_DEFINED__
typedef interface IZcPeColorCtrl IZcPeColorCtrl;
#endif 	/* __IZcPeColorCtrl_FWD_DEFINED__ */


#ifndef __IZcPeSpinCtrl_FWD_DEFINED__
#define __IZcPeSpinCtrl_FWD_DEFINED__
typedef interface IZcPeSpinCtrl IZcPeSpinCtrl;
#endif 	/* __IZcPeSpinCtrl_FWD_DEFINED__ */


#ifndef __IZcPeNoPickVariantRW_FWD_DEFINED__
#define __IZcPeNoPickVariantRW_FWD_DEFINED__
typedef interface IZcPeNoPickVariantRW IZcPeNoPickVariantRW;
#endif 	/* __IZcPeNoPickVariantRW_FWD_DEFINED__ */


#ifndef __IZcPeButtonEditCtrl_FWD_DEFINED__
#define __IZcPeButtonEditCtrl_FWD_DEFINED__
typedef interface IZcPeButtonEditCtrl IZcPeButtonEditCtrl;
#endif 	/* __IZcPeButtonEditCtrl_FWD_DEFINED__ */


#ifndef __IZcPeButtonPicture_FWD_DEFINED__
#define __IZcPeButtonPicture_FWD_DEFINED__
typedef interface IZcPeButtonPicture IZcPeButtonPicture;
#endif 	/* __IZcPeButtonPicture_FWD_DEFINED__ */


#ifndef __IZcPePick2PointsCtrl_FWD_DEFINED__
#define __IZcPePick2PointsCtrl_FWD_DEFINED__
typedef interface IZcPePick2PointsCtrl IZcPePick2PointsCtrl;
#endif 	/* __IZcPePick2PointsCtrl_FWD_DEFINED__ */


#ifndef __IZcPeCalculatorCtrl_FWD_DEFINED__
#define __IZcPeCalculatorCtrl_FWD_DEFINED__
typedef interface IZcPeCalculatorCtrl IZcPeCalculatorCtrl;
#endif 	/* __IZcPeCalculatorCtrl_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorText_FWD_DEFINED__
#define __ZcPePropertyEditorText_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorText ZcPePropertyEditorText;
#else
typedef struct ZcPePropertyEditorText ZcPePropertyEditorText;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorText_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorLWeight_FWD_DEFINED__
#define __ZcPePropertyEditorLWeight_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorLWeight ZcPePropertyEditorLWeight;
#else
typedef struct ZcPePropertyEditorLWeight ZcPePropertyEditorLWeight;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorLWeight_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorLayer_FWD_DEFINED__
#define __ZcPePropertyEditorLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorLayer ZcPePropertyEditorLayer;
#else
typedef struct ZcPePropertyEditorLayer ZcPePropertyEditorLayer;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorLayer_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorMaterial_FWD_DEFINED__
#define __ZcPePropertyEditorMaterial_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorMaterial ZcPePropertyEditorMaterial;
#else
typedef struct ZcPePropertyEditorMaterial ZcPePropertyEditorMaterial;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorMaterial_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorColor_FWD_DEFINED__
#define __ZcPePropertyEditorColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorColor ZcPePropertyEditorColor;
#else
typedef struct ZcPePropertyEditorColor ZcPePropertyEditorColor;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorColor_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorLType_FWD_DEFINED__
#define __ZcPePropertyEditorLType_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorLType ZcPePropertyEditorLType;
#else
typedef struct ZcPePropertyEditorLType ZcPePropertyEditorLType;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorLType_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorNumeric_FWD_DEFINED__
#define __ZcPePropertyEditorNumeric_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorNumeric ZcPePropertyEditorNumeric;
#else
typedef struct ZcPePropertyEditorNumeric ZcPePropertyEditorNumeric;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorNumeric_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorBool_FWD_DEFINED__
#define __ZcPePropertyEditorBool_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorBool ZcPePropertyEditorBool;
#else
typedef struct ZcPePropertyEditorBool ZcPePropertyEditorBool;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorBool_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorZCADNumeric_FWD_DEFINED__
#define __ZcPePropertyEditorZCADNumeric_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorZCADNumeric ZcPePropertyEditorZCADNumeric;
#else
typedef struct ZcPePropertyEditorZCADNumeric ZcPePropertyEditorZCADNumeric;
#endif /* __cplusplus */

#endif 


#ifndef __ZcPePick2PointsCtrl_FWD_DEFINED__
#define __ZcPePick2PointsCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePick2PointsCtrl ZcPePick2PointsCtrl;
#else
typedef struct ZcPePick2PointsCtrl ZcPePick2PointsCtrl;
#endif /* __cplusplus */

#endif 	/* __ZcPePick2PointsCtrl_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorNumericArea_FWD_DEFINED__
#define __ZcPePropertyEditorNumericArea_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorNumericArea ZcPePropertyEditorNumericArea;
#else
typedef struct ZcPePropertyEditorNumericArea ZcPePropertyEditorNumericArea;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorNumericArea_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorEllipses_FWD_DEFINED__
#define __ZcPePropertyEditorEllipses_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorEllipses ZcPePropertyEditorEllipses;
#else
typedef struct ZcPePropertyEditorEllipses ZcPePropertyEditorEllipses;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorEllipses_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorEditButton_FWD_DEFINED__
#define __ZcPePropertyEditorEditButton_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorEditButton ZcPePropertyEditorEditButton;
#else
typedef struct ZcPePropertyEditorEditButton ZcPePropertyEditorEditButton;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorEditButton_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorEnum_FWD_DEFINED__
#define __ZcPePropertyEditorEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorEnum ZcPePropertyEditorEnum;
#else
typedef struct ZcPePropertyEditorEnum ZcPePropertyEditorEnum;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorEnum_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorHatchEnum_FWD_DEFINED__
#define __ZcPePropertyEditorHatchEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorHatchEnum ZcPePropertyEditorHatchEnum;
#else
typedef struct ZcPePropertyEditorHatchEnum ZcPePropertyEditorHatchEnum;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorHatchEnum_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorMTextDir_FWD_DEFINED__
#define __ZcPePropertyEditorMTextDir_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorMTextDir ZcPePropertyEditorMTextDir;
#else
typedef struct ZcPePropertyEditorMTextDir ZcPePropertyEditorMTextDir;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorMTextDir_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorHatchISOPenWidth_FWD_DEFINED__
#define __ZcPePropertyEditorHatchISOPenWidth_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorHatchISOPenWidth ZcPePropertyEditorHatchISOPenWidth;
#else
typedef struct ZcPePropertyEditorHatchISOPenWidth ZcPePropertyEditorHatchISOPenWidth;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorHatchISOPenWidth_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorHatchPatternName_FWD_DEFINED__
#define __ZcPePropertyEditorHatchPatternName_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorHatchPatternName ZcPePropertyEditorHatchPatternName;
#else
typedef struct ZcPePropertyEditorHatchPatternName ZcPePropertyEditorHatchPatternName;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorHatchPatternName_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorEllipsisHatchPatternType_FWD_DEFINED__
#define __ZcPePropertyEditorEllipsisHatchPatternType_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorEllipsisHatchPatternType ZcPePropertyEditorEllipsisHatchPatternType;
#else
typedef struct ZcPePropertyEditorEllipsisHatchPatternType ZcPePropertyEditorEllipsisHatchPatternType;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorEllipsisHatchPatternType_FWD_DEFINED__ */


#ifndef __ZcPeDlgLaunchCtrl_FWD_DEFINED__
#define __ZcPeDlgLaunchCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPeDlgLaunchCtrl ZcPeDlgLaunchCtrl;
#else
typedef struct ZcPeDlgLaunchCtrl ZcPeDlgLaunchCtrl;
#endif /* __cplusplus */

#endif 	/* __ZcPeDlgLaunchCtrl_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorVariant_FWD_DEFINED__
#define __ZcPePropertyEditorVariant_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorVariant ZcPePropertyEditorVariant;
#else
typedef struct ZcPePropertyEditorVariant ZcPePropertyEditorVariant;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorVariant_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorEllipsesHyperlinks_FWD_DEFINED__
#define __ZcPePropertyEditorEllipsesHyperlinks_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorEllipsesHyperlinks ZcPePropertyEditorEllipsesHyperlinks;
#else
typedef struct ZcPePropertyEditorEllipsesHyperlinks ZcPePropertyEditorEllipsesHyperlinks;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorEllipsesHyperlinks_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorSpin_FWD_DEFINED__
#define __ZcPePropertyEditorSpin_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorSpin ZcPePropertyEditorSpin;
#else
typedef struct ZcPePropertyEditorSpin ZcPePropertyEditorSpin;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorSpin_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorDimArrowHead_FWD_DEFINED__
#define __ZcPePropertyEditorDimArrowHead_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorDimArrowHead ZcPePropertyEditorDimArrowHead;
#else
typedef struct ZcPePropertyEditorDimArrowHead ZcPePropertyEditorDimArrowHead;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorDimArrowHead_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorGradientPattern_FWD_DEFINED__
#define __ZcPePropertyEditorGradientPattern_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorGradientPattern ZcPePropertyEditorGradientPattern;
#else
typedef struct ZcPePropertyEditorGradientPattern ZcPePropertyEditorGradientPattern;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorGradientPattern_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorPlotStyleName_FWD_DEFINED__
#define __ZcPePropertyEditorPlotStyleName_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorPlotStyleName ZcPePropertyEditorPlotStyleName;
#else
typedef struct ZcPePropertyEditorPlotStyleName ZcPePropertyEditorPlotStyleName;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorPlotStyleName_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorPlotStyleTable_FWD_DEFINED__
#define __ZcPePropertyEditorPlotStyleTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorPlotStyleTable ZcPePropertyEditorPlotStyleTable;
#else
typedef struct ZcPePropertyEditorPlotStyleTable ZcPePropertyEditorPlotStyleTable;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorPlotStyleTable_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorNoPickVariant_FWD_DEFINED__
#define __ZcPePropertyEditorNoPickVariant_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorNoPickVariant ZcPePropertyEditorNoPickVariant;
#else
typedef struct ZcPePropertyEditorNoPickVariant ZcPePropertyEditorNoPickVariant;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorNoPickVariant_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorRasterImageHeight_FWD_DEFINED__
#define __ZcPePropertyEditorRasterImageHeight_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorRasterImageHeight ZcPePropertyEditorRasterImageHeight;
#else
typedef struct ZcPePropertyEditorRasterImageHeight ZcPePropertyEditorRasterImageHeight;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorRasterImageHeight_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorRasterImageWidth_FWD_DEFINED__
#define __ZcPePropertyEditorRasterImageWidth_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorRasterImageWidth ZcPePropertyEditorRasterImageWidth;
#else
typedef struct ZcPePropertyEditorRasterImageWidth ZcPePropertyEditorRasterImageWidth;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorRasterImageWidth_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorTextJustify_FWD_DEFINED__
#define __ZcPePropertyEditorTextJustify_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorTextJustify ZcPePropertyEditorTextJustify;
#else
typedef struct ZcPePropertyEditorTextJustify ZcPePropertyEditorTextJustify;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorTextJustify_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorEllipseEndAngle_FWD_DEFINED__
#define __ZcPePropertyEditorEllipseEndAngle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorEllipseEndAngle ZcPePropertyEditorEllipseEndAngle;
#else
typedef struct ZcPePropertyEditorEllipseEndAngle ZcPePropertyEditorEllipseEndAngle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorEllipseEndAngle_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorDimStyle_FWD_DEFINED__
#define __ZcPePropertyEditorDimStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorDimStyle ZcPePropertyEditorDimStyle;
#else
typedef struct ZcPePropertyEditorDimStyle ZcPePropertyEditorDimStyle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorDimStyle_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorTextStyle_FWD_DEFINED__
#define __ZcPePropertyEditorTextStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorTextStyle ZcPePropertyEditorTextStyle;
#else
typedef struct ZcPePropertyEditorTextStyle ZcPePropertyEditorTextStyle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorTextStyle_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorMTextStyle_FWD_DEFINED__
#define __ZcPePropertyEditorMTextStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorMTextStyle ZcPePropertyEditorMTextStyle;
#else
typedef struct ZcPePropertyEditorMTextStyle ZcPePropertyEditorMTextStyle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorMTextStyle_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorCustomColor_FWD_DEFINED__
#define __ZcPePropertyEditorCustomColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorCustomColor ZcPePropertyEditorCustomColor;
#else
typedef struct ZcPePropertyEditorCustomColor ZcPePropertyEditorCustomColor;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorCustomColor_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorPwdText_FWD_DEFINED__
#define __ZcPePropertyEditorPwdText_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorPwdText ZcPePropertyEditorPwdText;
#else
typedef struct ZcPePropertyEditorPwdText ZcPePropertyEditorPwdText;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorPwdText_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorTextEx_FWD_DEFINED__
#define __ZcPePropertyEditorTextEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorTextEx ZcPePropertyEditorTextEx;
#else
typedef struct ZcPePropertyEditorTextEx ZcPePropertyEditorTextEx;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorTextEx_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorVisualStyle_FWD_DEFINED__
#define __ZcPePropertyEditorVisualStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorVisualStyle ZcPePropertyEditorVisualStyle;
#else
typedef struct ZcPePropertyEditorVisualStyle ZcPePropertyEditorVisualStyle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorVisualStyle_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorLightLampColor_FWD_DEFINED__
#define __ZcPePropertyEditorLightLampColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorLightLampColor ZcPePropertyEditorLightLampColor;
#else
typedef struct ZcPePropertyEditorLightLampColor ZcPePropertyEditorLightLampColor;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorLightLampColor_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorLightWebPreview_FWD_DEFINED__
#define __ZcPePropertyEditorLightWebPreview_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorLightWebPreview ZcPePropertyEditorLightWebPreview;
#else
typedef struct ZcPePropertyEditorLightWebPreview ZcPePropertyEditorLightWebPreview;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorLightWebPreview_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorLightIntensity_FWD_DEFINED__
#define __ZcPePropertyEditorLightIntensity_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorLightIntensity ZcPePropertyEditorLightIntensity;
#else
typedef struct ZcPePropertyEditorLightIntensity ZcPePropertyEditorLightIntensity;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorLightIntensity_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorTableStyle_FWD_DEFINED__
#define __ZcPePropertyEditorTableStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorTableStyle ZcPePropertyEditorTableStyle;
#else
typedef struct ZcPePropertyEditorTableStyle ZcPePropertyEditorTableStyle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorTableStyle_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorAttributeValue_FWD_DEFINED__
#define __ZcPePropertyEditorAttributeValue_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorAttributeValue ZcPePropertyEditorAttributeValue;
#else
typedef struct ZcPePropertyEditorAttributeValue ZcPePropertyEditorAttributeValue;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorAttributeValue_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorPredefBlock_FWD_DEFINED__
#define __ZcPePropertyEditorPredefBlock_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorPredefBlock ZcPePropertyEditorPredefBlock;
#else
typedef struct ZcPePropertyEditorPredefBlock ZcPePropertyEditorPredefBlock;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorPredefBlock_FWD_DEFINED__ */


#ifndef __ZcPePropertyEditorMLeaderStyle_FWD_DEFINED__
#define __ZcPePropertyEditorMLeaderStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPePropertyEditorMLeaderStyle ZcPePropertyEditorMLeaderStyle;
#else
typedef struct ZcPePropertyEditorMLeaderStyle ZcPePropertyEditorMLeaderStyle;
#endif /* __cplusplus */

#endif 	/* __ZcPePropertyEditorMLeaderStyle_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "zcpi.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_ZcPEXCtl_0000 */
/* [local] */ 

#define DISPID_BTNEDIT_DEF_PIC 1
#define DISPID_BTNEDIT_DIS_PIC 2
#define DISPID_BTNPIC_DEF_PIC 1
#define DISPID_BTNPIC_DIS_PIC 2


extern RPC_IF_HANDLE __MIDL_itf_ZcPEXCtl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPEXCtl_0000_v0_0_s_ifspec;


#ifndef __ZCPEXCTLLib_LIBRARY_DEFINED__
#define __ZCPEXCTLLib_LIBRARY_DEFINED__

/* library ACPEXCTLLib */
/* [custom][helpstring][version][uuid] */ 

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("70AFDEB0-099C-494e-A493-5E0ECD614004") 
enum ZcPeNumericType
    {	PE_ZCAD_DISTANCE	= 0,
	PE_ZCAD_ANGLE	= 0x1,
	PE_ZCAD_NOUNITS	= 0x2,
	PE_ZCAD_OTHER	= 0x3,
	PE_ZCAD_ANGLEPLUS360	= 0x4,
	PE_ZCAD_RELATIVE_ANGLE	= 0x5,
	PE_ZCAD_RAW_ANGLE	= 0x6
    } 	ZcPeNumericType;

#define CLSID_PropertyEditorText CLSID_ZcPePropertyEditorText
#define CLSID_PropertyEditorLWeight CLSID_ZcPePropertyEditorLWeight
#define CLSID_PropertyEditorLayer CLSID_ZcPePropertyEditorLayer
#define CLSID_PropertyEditorMaterial CLSID_ZcPePropertyEditorMaterial
#define CLSID_PropertyEditorColor CLSID_ZcPePropertyEditorColor
#define CLSID_PropertyEditorLType CLSID_ZcPePropertyEditorLType
#define CLSID_PropertyEditorNumeric CLSID_ZcPePropertyEditorNumeric
#define CLSID_PropertyEditorBool CLSID_ZcPePropertyEditorBool
#define CLSID_PropertyEditorZCADNumeric CLSID_ZcPePropertyEditorZCADNumeric
#define CLSID_PropertyEditorNumericArea CLSID_ZcPePropertyEditorNumericArea
#define CLSID_PropertyEditorEllipses CLSID_ZcPePropertyEditorEllipses
#define CLSID_PropertyEditorEditButton CLSID_ZcPePropertyEditorEditButton
#define CLSID_PropertyEditorEnum CLSID_ZcPePropertyEditorEnum
#define CLSID_PropertyEditorHatchEnum CLSID_ZcPePropertyEditorHatchEnum
#define CLSID_PropertyEditorMTextDir CLSID_ZcPePropertyEditorMTextDir
#define CLSID_PropertyEditorHatchISOPenWidth CLSID_ZcPePropertyEditorHatchISOPenWidth
#define CLSID_PropertyEditorHatchPatternName CLSID_ZcPePropertyEditorHatchPatternName
#define CLSID_PropertyEditorEllipsisHatchPatternType CLSID_ZcPePropertyEditorEllipsisHatchPatternType
#define CLSID_PropertyEditorVariant CLSID_ZcPePropertyEditorVariant
#define CLSID_PropertyEditorEllipsesHyperlinks CLSID_ZcPePropertyEditorEllipsesHyperlinks
#define CLSID_PropertyEditorSpin CLSID_ZcPePropertyEditorSpin
#define CLSID_PropertyEditorDimArrowHead CLSID_ZcPePropertyEditorDimArrowHead
#define CLSID_PropertyEditorGradientPattern CLSID_ZcPePropertyEditorGradientPattern
#define CLSID_PropertyEditorPlotStyleName CLSID_ZcPePropertyEditorPlotStyleName
#define CLSID_PropertyEditorPlotStyleTable CLSID_ZcPePropertyEditorPlotStyleTable
#define CLSID_PropertyEditorNoPickVariant CLSID_ZcPePropertyEditorNoPickVariant
#define CLSID_PropertyEditorRasterImageHeight CLSID_ZcPePropertyEditorRasterImageHeight
#define CLSID_PropertyEditorRasterImageWidth CLSID_ZcPePropertyEditorRasterImageWidth
#define CLSID_PropertyEditorTextJustify CLSID_ZcPePropertyEditorTextJustify
#define CLSID_PropertyEditorEllipseEndAngle CLSID_ZcPePropertyEditorEllipseEndAngle
#define CLSID_PropertyEditorDimStyle CLSID_ZcPePropertyEditorDimStyle
#define CLSID_PropertyEditorTextStyle CLSID_ZcPePropertyEditorTextStyle
#define CLSID_PropertyEditorMTextStyle CLSID_ZcPePropertyEditorMTextStyle
#define CLSID_PropertyEditorPwdText CLSID_ZcPePropertyEditorPwdText
#define CLSID_PropertyEditorVisualStyle CLSID_ZcPePropertyEditorVisualStyle
#define CLSID_PropertyEditorLightLampColor CLSID_ZcPePropertyEditorLightLampColor
#define CLSID_PropertyEditorLightWebPreview CLSID_ZcPePropertyEditorLightWebPreview
#define CLSID_PropertyEditorLightIntensity CLSID_ZcPePropertyEditorLightIntensity
#define CLSID_PropertyEditorTableStyle CLSID_ZcPePropertyEditorTableStyle
#define CLSID_PropertyEditorAttributeValue CLSID_ZcPePropertyEditorAttributeValue
#define CLSID_PropertyEditorPredefBlock CLSID_ZcPePropertyEditorPredefBlock
#define CLSID_PropertyEditorMLeaderStyle CLSID_ZcPePropertyEditorMLeaderStyle

EXTERN_C const IID LIBID_ACPEXCTLLib;

#ifndef __IZcPeNumericEditor_INTERFACE_DEFINED__
#define __IZcPeNumericEditor_INTERFACE_DEFINED__

/* interface IZcPeNumericEditor */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeNumericEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD52023A-9B0D-44c8-AD8A-B28250858222")
    IZcPeNumericEditor : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNumericDataType( 
            /* [in] */ enum ZcPeNumericType dataType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeNumericEditorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeNumericEditor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeNumericEditor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeNumericEditor * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNumericDataType )( 
            IZcPeNumericEditor * This,
            /* [in] */ enum ZcPeNumericType dataType);
        
        END_INTERFACE
    } IZcPeNumericEditorVtbl;

    interface IZcPeNumericEditor
    {
        CONST_VTBL struct IZcPeNumericEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeNumericEditor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeNumericEditor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeNumericEditor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeNumericEditor_SetNumericDataType(This,dataType)	\
    (This)->lpVtbl -> SetNumericDataType(This,dataType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeNumericEditor_SetNumericDataType_Proxy( 
    IZcPeNumericEditor * This,
    /* [in] */ enum ZcPeNumericType dataType);


void __RPC_STUB IZcPeNumericEditor_SetNumericDataType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeNumericEditor_INTERFACE_DEFINED__ */


#ifndef __IZcPeVariantCtrl_INTERFACE_DEFINED__
#define __IZcPeVariantCtrl_INTERFACE_DEFINED__

/* interface IZcPeVariantCtrl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeVariantCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A5B57E5-7B4F-4fee-B36B-FF636468ED91")
    IZcPeVariantCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDwCookies( 
            /* [in] */ VARIANT cookieArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGroupOffset( 
            /* [in] */ DWORD dwOffset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetElementCount( 
            /* [in] */ DWORD elemCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeVariantCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeVariantCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeVariantCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeVariantCtrl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDwCookies )( 
            IZcPeVariantCtrl * This,
            /* [in] */ VARIANT cookieArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGroupOffset )( 
            IZcPeVariantCtrl * This,
            /* [in] */ DWORD dwOffset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetElementCount )( 
            IZcPeVariantCtrl * This,
            /* [in] */ DWORD elemCount);
        
        END_INTERFACE
    } IZcPeVariantCtrlVtbl;

    interface IZcPeVariantCtrl
    {
        CONST_VTBL struct IZcPeVariantCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeVariantCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeVariantCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeVariantCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeVariantCtrl_SetDwCookies(This,cookieArray)	\
    (This)->lpVtbl -> SetDwCookies(This,cookieArray)

#define IZcPeVariantCtrl_SetGroupOffset(This,dwOffset)	\
    (This)->lpVtbl -> SetGroupOffset(This,dwOffset)

#define IZcPeVariantCtrl_SetElementCount(This,elemCount)	\
    (This)->lpVtbl -> SetElementCount(This,elemCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeVariantCtrl_SetDwCookies_Proxy( 
    IZcPeVariantCtrl * This,
    /* [in] */ VARIANT cookieArray);


void __RPC_STUB IZcPeVariantCtrl_SetDwCookies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeVariantCtrl_SetGroupOffset_Proxy( 
    IZcPeVariantCtrl * This,
    /* [in] */ DWORD dwOffset);


void __RPC_STUB IZcPeVariantCtrl_SetGroupOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeVariantCtrl_SetElementCount_Proxy( 
    IZcPeVariantCtrl * This,
    /* [in] */ DWORD elemCount);


void __RPC_STUB IZcPeVariantCtrl_SetElementCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeVariantCtrl_INTERFACE_DEFINED__ */


#ifndef __IZcPeColorCtrl_INTERFACE_DEFINED__
#define __IZcPeColorCtrl_INTERFACE_DEFINED__

/* interface IZcPeColorCtrl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeColorCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C308511-9949-46F3-93A5-76D23A633E11")
    IZcPeColorCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNoMetaColor( 
            /* [in] */ VARIANT_BOOL bNoMetaColors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeColorCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeColorCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeColorCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeColorCtrl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNoMetaColor )( 
            IZcPeColorCtrl * This,
            /* [in] */ VARIANT_BOOL bNoMetaColors);
        
        END_INTERFACE
    } IZcPeColorCtrlVtbl;

    interface IZcPeColorCtrl
    {
        CONST_VTBL struct IZcPeColorCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeColorCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeColorCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeColorCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeColorCtrl_SetNoMetaColor(This,bNoMetaColors)	\
    (This)->lpVtbl -> SetNoMetaColor(This,bNoMetaColors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeColorCtrl_SetNoMetaColor_Proxy( 
    IZcPeColorCtrl * This,
    /* [in] */ VARIANT_BOOL bNoMetaColors);


void __RPC_STUB IZcPeColorCtrl_SetNoMetaColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeColorCtrl_INTERFACE_DEFINED__ */


#ifndef __IZcPeSpinCtrl_INTERFACE_DEFINED__
#define __IZcPeSpinCtrl_INTERFACE_DEFINED__

/* interface IZcPeSpinCtrl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeSpinCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4132B288-9018-4690-BDFD-58A0EB2F3D27")
    IZcPeSpinCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetControls( 
            /* [in] */ VARIANT varControlsIUnkArray) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeSpinCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeSpinCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeSpinCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeSpinCtrl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetControls )( 
            IZcPeSpinCtrl * This,
            /* [in] */ VARIANT varControlsIUnkArray);
        
        END_INTERFACE
    } IZcPeSpinCtrlVtbl;

    interface IZcPeSpinCtrl
    {
        CONST_VTBL struct IZcPeSpinCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeSpinCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeSpinCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeSpinCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeSpinCtrl_SetControls(This,varControlsIUnkArray)	\
    (This)->lpVtbl -> SetControls(This,varControlsIUnkArray)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeSpinCtrl_SetControls_Proxy( 
    IZcPeSpinCtrl * This,
    /* [in] */ VARIANT varControlsIUnkArray);


void __RPC_STUB IZcPeSpinCtrl_SetControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeSpinCtrl_INTERFACE_DEFINED__ */


#ifndef __IZcPeNoPickVariantRW_INTERFACE_DEFINED__
#define __IZcPeNoPickVariantRW_INTERFACE_DEFINED__

/* interface IZcPeNoPickVariantRW */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeNoPickVariantRW;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FFDC513D-B298-4d51-ACA7-8384F1196650")
    IZcPeNoPickVariantRW : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAlwaysRW( 
            /* [in] */ VARIANT_BOOL bIsAlwaysRW) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeNoPickVariantRWVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeNoPickVariantRW * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeNoPickVariantRW * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeNoPickVariantRW * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAlwaysRW )( 
            IZcPeNoPickVariantRW * This,
            /* [in] */ VARIANT_BOOL bIsAlwaysRW);
        
        END_INTERFACE
    } IZcPeNoPickVariantRWVtbl;

    interface IZcPeNoPickVariantRW
    {
        CONST_VTBL struct IZcPeNoPickVariantRWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeNoPickVariantRW_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeNoPickVariantRW_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeNoPickVariantRW_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeNoPickVariantRW_SetAlwaysRW(This,bIsAlwaysRW)	\
    (This)->lpVtbl -> SetAlwaysRW(This,bIsAlwaysRW)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeNoPickVariantRW_SetAlwaysRW_Proxy( 
    IZcPeNoPickVariantRW * This,
    /* [in] */ VARIANT_BOOL bIsAlwaysRW);


void __RPC_STUB IZcPeNoPickVariantRW_SetAlwaysRW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeNoPickVariantRW_INTERFACE_DEFINED__ */


#ifndef __IZcPeButtonEditCtrl_INTERFACE_DEFINED__
#define __IZcPeButtonEditCtrl_INTERFACE_DEFINED__

/* interface IZcPeButtonEditCtrl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeButtonEditCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5295B0C4-94A0-4167-BA90-1C61A868E269")
    IZcPeButtonEditCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
        virtual /* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DisabledPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DisabledPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeButtonEditCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeButtonEditCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeButtonEditCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeButtonEditCtrl * This);
        
        /* [helpstring][id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPicture )( 
            IZcPeButtonEditCtrl * This,
            /* [in] */ IUnknown *pIPicture);
        
        /* [helpstring][id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPicture )( 
            IZcPeButtonEditCtrl * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        /* [helpstring][id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisabledPicture )( 
            IZcPeButtonEditCtrl * This,
            /* [in] */ IUnknown *pIPicture);
        
        /* [helpstring][id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisabledPicture )( 
            IZcPeButtonEditCtrl * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        END_INTERFACE
    } IZcPeButtonEditCtrlVtbl;

    interface IZcPeButtonEditCtrl
    {
        CONST_VTBL struct IZcPeButtonEditCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeButtonEditCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeButtonEditCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeButtonEditCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeButtonEditCtrl_put_DefaultPicture(This,pIPicture)	\
    (This)->lpVtbl -> put_DefaultPicture(This,pIPicture)

#define IZcPeButtonEditCtrl_get_DefaultPicture(This,pIPicture)	\
    (This)->lpVtbl -> get_DefaultPicture(This,pIPicture)

#define IZcPeButtonEditCtrl_put_DisabledPicture(This,pIPicture)	\
    (This)->lpVtbl -> put_DisabledPicture(This,pIPicture)

#define IZcPeButtonEditCtrl_get_DisabledPicture(This,pIPicture)	\
    (This)->lpVtbl -> get_DisabledPicture(This,pIPicture)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPeButtonEditCtrl_put_DefaultPicture_Proxy( 
    IZcPeButtonEditCtrl * This,
    /* [in] */ IUnknown *pIPicture);


void __RPC_STUB IZcPeButtonEditCtrl_put_DefaultPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPeButtonEditCtrl_get_DefaultPicture_Proxy( 
    IZcPeButtonEditCtrl * This,
    /* [retval][out] */ IUnknown **pIPicture);


void __RPC_STUB IZcPeButtonEditCtrl_get_DefaultPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPeButtonEditCtrl_put_DisabledPicture_Proxy( 
    IZcPeButtonEditCtrl * This,
    /* [in] */ IUnknown *pIPicture);


void __RPC_STUB IZcPeButtonEditCtrl_put_DisabledPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPeButtonEditCtrl_get_DisabledPicture_Proxy( 
    IZcPeButtonEditCtrl * This,
    /* [retval][out] */ IUnknown **pIPicture);


void __RPC_STUB IZcPeButtonEditCtrl_get_DisabledPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeButtonEditCtrl_INTERFACE_DEFINED__ */


#ifndef __IZcPeButtonPicture_INTERFACE_DEFINED__
#define __IZcPeButtonPicture_INTERFACE_DEFINED__

/* interface IZcPeButtonPicture */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeButtonPicture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6395B0C4-94A0-4167-BA90-1C61A868E269")
    IZcPeButtonPicture : public IUnknown
    {
    public:
        virtual /* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
        virtual /* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DisabledPicture( 
            /* [in] */ IUnknown *pIPicture) = 0;
        
        virtual /* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DisabledPicture( 
            /* [retval][out] */ IUnknown **pIPicture) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeButtonPictureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeButtonPicture * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeButtonPicture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeButtonPicture * This);
        
        /* [helpstring][id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPicture )( 
            IZcPeButtonPicture * This,
            /* [in] */ IUnknown *pIPicture);
        
        /* [helpstring][id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPicture )( 
            IZcPeButtonPicture * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        /* [helpstring][id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisabledPicture )( 
            IZcPeButtonPicture * This,
            /* [in] */ IUnknown *pIPicture);
        
        /* [helpstring][id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisabledPicture )( 
            IZcPeButtonPicture * This,
            /* [retval][out] */ IUnknown **pIPicture);
        
        END_INTERFACE
    } IZcPeButtonPictureVtbl;

    interface IZcPeButtonPicture
    {
        CONST_VTBL struct IZcPeButtonPictureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeButtonPicture_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeButtonPicture_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeButtonPicture_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeButtonPicture_put_DefaultPicture(This,pIPicture)	\
    (This)->lpVtbl -> put_DefaultPicture(This,pIPicture)

#define IZcPeButtonPicture_get_DefaultPicture(This,pIPicture)	\
    (This)->lpVtbl -> get_DefaultPicture(This,pIPicture)

#define IZcPeButtonPicture_put_DisabledPicture(This,pIPicture)	\
    (This)->lpVtbl -> put_DisabledPicture(This,pIPicture)

#define IZcPeButtonPicture_get_DisabledPicture(This,pIPicture)	\
    (This)->lpVtbl -> get_DisabledPicture(This,pIPicture)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPeButtonPicture_put_DefaultPicture_Proxy( 
    IZcPeButtonPicture * This,
    /* [in] */ IUnknown *pIPicture);


void __RPC_STUB IZcPeButtonPicture_put_DefaultPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPeButtonPicture_get_DefaultPicture_Proxy( 
    IZcPeButtonPicture * This,
    /* [retval][out] */ IUnknown **pIPicture);


void __RPC_STUB IZcPeButtonPicture_get_DefaultPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IZcPeButtonPicture_put_DisabledPicture_Proxy( 
    IZcPeButtonPicture * This,
    /* [in] */ IUnknown *pIPicture);


void __RPC_STUB IZcPeButtonPicture_put_DisabledPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IZcPeButtonPicture_get_DisabledPicture_Proxy( 
    IZcPeButtonPicture * This,
    /* [retval][out] */ IUnknown **pIPicture);


void __RPC_STUB IZcPeButtonPicture_get_DisabledPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeButtonPicture_INTERFACE_DEFINED__ */


#ifndef __IZcPePick2PointsCtrl_INTERFACE_DEFINED__
#define __IZcPePick2PointsCtrl_INTERFACE_DEFINED__

/* interface IZcPePick2PointsCtrl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPePick2PointsCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01500220-9289-41be-9A2E-F300A84598B0")
    IZcPePick2PointsCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrompts( 
            /* [in] */ BSTR prompt1,
            /* [in] */ BSTR prompt2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPePick2PointsCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPePick2PointsCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPePick2PointsCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPePick2PointsCtrl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPrompts )( 
            IZcPePick2PointsCtrl * This,
            /* [in] */ BSTR prompt1,
            /* [in] */ BSTR prompt2);
        
        END_INTERFACE
    } IZcPePick2PointsCtrlVtbl;

    interface IZcPePick2PointsCtrl
    {
        CONST_VTBL struct IZcPePick2PointsCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPePick2PointsCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPePick2PointsCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPePick2PointsCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPePick2PointsCtrl_SetPrompts(This,prompt1,prompt2)	\
    (This)->lpVtbl -> SetPrompts(This,prompt1,prompt2)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPePick2PointsCtrl_SetPrompts_Proxy( 
    IZcPePick2PointsCtrl * This,
    /* [in] */ BSTR prompt1,
    /* [in] */ BSTR prompt2);


void __RPC_STUB IZcPePick2PointsCtrl_SetPrompts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPePick2PointsCtrl_INTERFACE_DEFINED__ */


#ifndef __IZcPeCalculatorCtrl_INTERFACE_DEFINED__
#define __IZcPeCalculatorCtrl_INTERFACE_DEFINED__

/* interface IZcPeCalculatorCtrl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IZcPeCalculatorCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AED2050-3838-4c85-A816-BA5CC5604999")
    IZcPeCalculatorCtrl : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCalculatorMode( 
            /* [in] */ VARIANT_BOOL mode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZcPeCalculatorCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPeCalculatorCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPeCalculatorCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPeCalculatorCtrl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCalculatorMode )( 
            IZcPeCalculatorCtrl * This,
            /* [in] */ VARIANT_BOOL mode);
        
        END_INTERFACE
    } IZcPeCalculatorCtrlVtbl;

    interface IZcPeCalculatorCtrl
    {
        CONST_VTBL struct IZcPeCalculatorCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcPeCalculatorCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZcPeCalculatorCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZcPeCalculatorCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZcPeCalculatorCtrl_SetCalculatorMode(This,mode)	\
    (This)->lpVtbl -> SetCalculatorMode(This,mode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZcPeCalculatorCtrl_SetCalculatorMode_Proxy( 
    IZcPeCalculatorCtrl * This,
    /* [in] */ VARIANT_BOOL mode);


void __RPC_STUB IZcPeCalculatorCtrl_SetCalculatorMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZcPeCalculatorCtrl_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ZcPePropertyEditorText;

#ifdef __cplusplus

class DECLSPEC_UUID("E631D337-7F88-44C8-B63F-C9031292FB4E")
ZcPePropertyEditorText;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorLWeight;

#ifdef __cplusplus

class DECLSPEC_UUID("7C21FF74-D9D0-4C6B-9C25-1D41B58F4776")
ZcPePropertyEditorLWeight;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("7FFD8B60-5083-4c30-A642-AE08CD6B75E7")
ZcPePropertyEditorLayer;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorMaterial;

#ifdef __cplusplus

class DECLSPEC_UUID("A8DBF45D-5F3F-497C-8DC3-84BD8A078A1B")
ZcPePropertyEditorMaterial;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorColor;

#ifdef __cplusplus

class DECLSPEC_UUID("5149A9AC-E7E5-43C7-A78F-A80A53783A8D")
ZcPePropertyEditorColor;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorLType;

#ifdef __cplusplus

class DECLSPEC_UUID("615F2CF0-C283-4ff9-B839-FAB43A957885")
ZcPePropertyEditorLType;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorNumeric;

#ifdef __cplusplus

class DECLSPEC_UUID("50446CFC-B0CF-432a-BA08-5D1CBDF090C8")
ZcPePropertyEditorNumeric;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorBool;

#ifdef __cplusplus

class DECLSPEC_UUID("6C2269DC-77B6-4908-8D0C-4E3CF1036FA7")
ZcPePropertyEditorBool;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorZCADNumeric;

#ifdef __cplusplus

class DECLSPEC_UUID("D621630B-0BFA-480e-94EF-2EEA1BD58D51")
ZcPePropertyEditorZCADNumeric;
#endif

EXTERN_C const CLSID CLSID_ZcPePick2PointsCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("15CC9D07-16B4-11d6-A4C1-001083782B8E")
ZcPePick2PointsCtrl;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorNumericArea;

#ifdef __cplusplus

class DECLSPEC_UUID("7E7D8243-4A38-42f5-A152-0629315D7B2B")
ZcPePropertyEditorNumericArea;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorEllipses;

#ifdef __cplusplus

class DECLSPEC_UUID("DDE306CA-B5C1-4c92-AFAB-2B37D01A717F")
ZcPePropertyEditorEllipses;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorEditButton;

#ifdef __cplusplus

class DECLSPEC_UUID("C504B291-944A-4828-9CFC-D3727B651AC7")
ZcPePropertyEditorEditButton;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("4DE4AD7B-6F4A-441e-98EE-8B1DF0F8BDC4")
ZcPePropertyEditorEnum;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorHatchEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("8221CC89-8C65-4c50-85FE-53005DE1B3B0")
ZcPePropertyEditorHatchEnum;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorMTextDir;

#ifdef __cplusplus

class DECLSPEC_UUID("E2E8A2A9-935D-4bb5-9347-717DDAEB327F")
ZcPePropertyEditorMTextDir;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorHatchISOPenWidth;

#ifdef __cplusplus

class DECLSPEC_UUID("EF5A02F6-7908-407f-A945-2BCB2AE589AB")
ZcPePropertyEditorHatchISOPenWidth;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorHatchPatternName;

#ifdef __cplusplus

class DECLSPEC_UUID("CD5C7ABB-9A0C-4c3a-B0C7-73296AFF7EC1")
ZcPePropertyEditorHatchPatternName;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorEllipsisHatchPatternType;

#ifdef __cplusplus

class DECLSPEC_UUID("04D47EE2-EA15-41bd-A1E7-990331C7CECD")
ZcPePropertyEditorEllipsisHatchPatternType;
#endif

EXTERN_C const CLSID CLSID_ZcPeDlgLaunchCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("C6CB13D4-3E36-4ab8-80D2-FC202CBB0ACD")
ZcPeDlgLaunchCtrl;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorVariant;

#ifdef __cplusplus

class DECLSPEC_UUID("C14AD0AE-7C2D-48e7-B8FC-2D48AD9149D1")
ZcPePropertyEditorVariant;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorEllipsesHyperlinks;

#ifdef __cplusplus

class DECLSPEC_UUID("45D4C0E8-5896-420d-A27C-6A9793497065")
ZcPePropertyEditorEllipsesHyperlinks;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorSpin;

#ifdef __cplusplus

class DECLSPEC_UUID("2AF455A6-9012-4d01-9E02-A8E5680E1E7E")
ZcPePropertyEditorSpin;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorDimArrowHead;

#ifdef __cplusplus

class DECLSPEC_UUID("AA055959-C7F1-4cfd-A2D1-8881D547E79C")
ZcPePropertyEditorDimArrowHead;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorGradientPattern;

#ifdef __cplusplus

class DECLSPEC_UUID("94684377-17FE-452E-9A51-7AABFFFE40BA")
ZcPePropertyEditorGradientPattern;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorPlotStyleName;

#ifdef __cplusplus

class DECLSPEC_UUID("55CF0D68-EBD0-4d54-B138-98CCF7BCCB20")
ZcPePropertyEditorPlotStyleName;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorPlotStyleTable;

#ifdef __cplusplus

class DECLSPEC_UUID("98EEC9A9-7F09-48e0-B615-984801A634CB")
ZcPePropertyEditorPlotStyleTable;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorNoPickVariant;

#ifdef __cplusplus

class DECLSPEC_UUID("C64EA053-7634-4466-89CF-AFDAB92C8F1B")
ZcPePropertyEditorNoPickVariant;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorRasterImageHeight;

#ifdef __cplusplus

class DECLSPEC_UUID("ED2490B2-06E6-4b7e-80D7-1ADAD6363694")
ZcPePropertyEditorRasterImageHeight;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorRasterImageWidth;

#ifdef __cplusplus

class DECLSPEC_UUID("99CD9966-D002-425d-AB7A-04E500546DB6")
ZcPePropertyEditorRasterImageWidth;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorTextJustify;

#ifdef __cplusplus

class DECLSPEC_UUID("CC7F3967-6919-42e6-A2ED-6FFA0697AFBB")
ZcPePropertyEditorTextJustify;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorEllipseEndAngle;

#ifdef __cplusplus

class DECLSPEC_UUID("7C672133-53DB-4fbf-BA5C-E017F83D866B")
ZcPePropertyEditorEllipseEndAngle;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorDimStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("4D0BBBEF-B91D-46ac-A3C0-BEBB947FADE6")
ZcPePropertyEditorDimStyle;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("E4A55764-4C3D-405e-BCCB-8C81AB6DBCFC")
ZcPePropertyEditorTextStyle;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorMTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("151E6750-4079-4609-9FD3-AD68B60F8B65")
ZcPePropertyEditorMTextStyle;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorCustomColor;

#ifdef __cplusplus

class DECLSPEC_UUID("43FD41DE-D16A-44ad-847F-70C08743BDDB")
ZcPePropertyEditorCustomColor;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorPwdText;

#ifdef __cplusplus

class DECLSPEC_UUID("39AB6541-F2E3-46b1-ACEE-EDDC2BD8A26A")
ZcPePropertyEditorPwdText;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorTextEx;

#ifdef __cplusplus

class DECLSPEC_UUID("8355614D-DC16-4a84-AF66-758E4CA4FE14")
ZcPePropertyEditorTextEx;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorVisualStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("6CADB719-36E3-4E22-BDF1-65B394DADCDF")
ZcPePropertyEditorVisualStyle;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorLightLampColor;

#ifdef __cplusplus

class DECLSPEC_UUID("BB069CBE-6B99-4dac-873C-0CB60DCF144D")
ZcPePropertyEditorLightLampColor;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorLightWebPreview;

#ifdef __cplusplus

class DECLSPEC_UUID("05F84868-29A5-44bb-BC2B-4F00DCE3F694")
ZcPePropertyEditorLightWebPreview;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorLightIntensity;

#ifdef __cplusplus

class DECLSPEC_UUID("124268F0-4F78-4434-8E45-87A72CAB0AFA")
ZcPePropertyEditorLightIntensity;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorTableStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("1BCAFFC4-3397-486a-80D0-4CBA3C186678")
ZcPePropertyEditorTableStyle;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorAttributeValue;

#ifdef __cplusplus

class DECLSPEC_UUID("64117059-A80B-4ea4-86ED-BB45CC6148A7")
ZcPePropertyEditorAttributeValue;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorPredefBlock;

#ifdef __cplusplus

class DECLSPEC_UUID("6326A3CE-62D5-4080-B682-CD152D507D0B")
ZcPePropertyEditorPredefBlock;
#endif

EXTERN_C const CLSID CLSID_ZcPePropertyEditorMLeaderStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("0480A986-4ECA-40ab-A1C7-8DCEA0082B0A")
ZcPePropertyEditorMLeaderStyle;
#endif
#endif /* __ACPEXCTLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


