#ifndef _ARXPORT_AD_ACPEXCTL_H_
#define _ARXPORT_AD_ACPEXCTL_H_ 1


#include "oaidl.h"
#include "ocidl.h"
#include "acpi.h"
#include "..\inc\zcpexctl.h"

#if defined(__cplusplus) && !defined(CINTERFACE)

typedef IZcPeNumericEditor		IAcPeNumericEditor;
typedef IZcPeVariantCtrl		IAcPeVariantCtrl;
typedef IZcPeColorCtrl			IAcPeColorCtrl;
typedef IZcPeSpinCtrl			IAcPeSpinCtrl;
typedef IZcPeNoPickVariantRW	IAcPeNoPickVariantRW;
typedef IZcPeButtonEditCtrl		IAcPeButtonEditCtrl;
typedef IZcPeButtonPicture		IAcPeButtonPicture;
typedef IZcPePick2PointsCtrl	IAcPePick2PointsCtrl;
typedef IZcPeCalculatorCtrl		IAcPeCalculatorCtrl;
#else
typedef IZcPeNumericEditorVtbl						IAcPeNumericEditorVtbl;
typedef IZcPeVariantCtrlVtbl						IAcPeVariantCtrlVtbl;
typedef IZcPeColorCtrlVtbl							IAcPeColorCtrlVtbl;
typedef IZcPeSpinCtrlVtbl							IAcPeSpinCtrlVtbl;
typedef IZcPeNoPickVariantRWVtbl					IAcPeNoPickVariantRWVtbl;
typedef IZcPeButtonEditCtrlVtbl						IAcPeButtonEditCtrlVtbl;
typedef IZcPeButtonPictureVtbl						IAcPeButtonPictureVtbl;
typedef IZcPePick2PointsCtrlVtbl					IAcPePick2PointsCtrlVtbl;
typedef IZcPeCalculatorCtrlVtbl						IAcPeCalculatorCtrlVtbl;
#endif

typedef ZcPePropertyEditorText						AcPePropertyEditorText;
typedef ZcPePropertyEditorLWeight					AcPePropertyEditorLWeight;
typedef ZcPePropertyEditorLayer						AcPePropertyEditorLayer;
typedef ZcPePropertyEditorMaterial					AcPePropertyEditorMaterial;
typedef ZcPePropertyEditorColor						AcPePropertyEditorColor;
typedef ZcPePropertyEditorLType						AcPePropertyEditorLType;
typedef ZcPePropertyEditorNumeric					AcPePropertyEditorNumeric;
typedef ZcPePropertyEditorBool						AcPePropertyEditorBool;
typedef ZcPePropertyEditorZCADNumeric				AcPePropertyEditorACADNumeric;
typedef ZcPePick2PointsCtrl							AcPePick2PointsCtrl;
typedef ZcPePropertyEditorNumericArea				AcPePropertyEditorNumericArea;
typedef ZcPePropertyEditorEllipses					AcPePropertyEditorEllipses;
typedef ZcPePropertyEditorEditButton				AcPePropertyEditorEditButton;
typedef ZcPePropertyEditorEnum						AcPePropertyEditorEnum;
typedef ZcPePropertyEditorHatchEnum					AcPePropertyEditorHatchEnum;
typedef ZcPePropertyEditorMTextDir					AcPePropertyEditorMTextDir;
typedef ZcPePropertyEditorHatchISOPenWidth			AcPePropertyEditorHatchISOPenWidth;
typedef ZcPePropertyEditorHatchPatternName			AcPePropertyEditorHatchPatternName;
typedef ZcPePropertyEditorEllipsisHatchPatternType	AcPePropertyEditorEllipsisHatchPatternType;
typedef ZcPeDlgLaunchCtrl							AcPeDlgLaunchCtrl;
typedef ZcPePropertyEditorVariant					AcPePropertyEditorVariant;
typedef ZcPePropertyEditorEllipsesHyperlinks		AcPePropertyEditorEllipsesHyperlinks;
typedef ZcPePropertyEditorSpin						AcPePropertyEditorSpin;
typedef ZcPePropertyEditorDimArrowHead				AcPePropertyEditorDimArrowHead;
typedef ZcPePropertyEditorGradientPattern			AcPePropertyEditorGradientPattern;
typedef ZcPePropertyEditorPlotStyleName				AcPePropertyEditorPlotStyleName;
typedef ZcPePropertyEditorPlotStyleTable			AcPePropertyEditorPlotStyleTable;
typedef ZcPePropertyEditorNoPickVariant				AcPePropertyEditorNoPickVariant;
typedef ZcPePropertyEditorRasterImageHeight			AcPePropertyEditorRasterImageHeight;
typedef ZcPePropertyEditorRasterImageWidth			AcPePropertyEditorRasterImageWidth;
typedef ZcPePropertyEditorTextJustify				AcPePropertyEditorTextJustify;
typedef ZcPePropertyEditorEllipseEndAngle			AcPePropertyEditorEllipseEndAngle;
typedef ZcPePropertyEditorDimStyle					AcPePropertyEditorDimStyle;
typedef ZcPePropertyEditorTextStyle					AcPePropertyEditorTextStyle;
typedef ZcPePropertyEditorMTextStyle				AcPePropertyEditorMTextStyle;
typedef ZcPePropertyEditorCustomColor				AcPePropertyEditorCustomColor;
typedef ZcPePropertyEditorPwdText					AcPePropertyEditorPwdText;
typedef ZcPePropertyEditorTextEx					AcPePropertyEditorTextEx;
typedef ZcPePropertyEditorVisualStyle				AcPePropertyEditorVisualStyle;
typedef ZcPePropertyEditorLightLampColor			AcPePropertyEditorLightLampColor;
typedef ZcPePropertyEditorLightWebPreview			AcPePropertyEditorLightWebPreview;
typedef ZcPePropertyEditorLightIntensity			AcPePropertyEditorLightIntensity;
typedef ZcPePropertyEditorTableStyle				AcPePropertyEditorTableStyle;
typedef ZcPePropertyEditorAttributeValue			AcPePropertyEditorAttributeValue;
typedef ZcPePropertyEditorPredefBlock				AcPePropertyEditorPredefBlock;
typedef ZcPePropertyEditorMLeaderStyle				AcPePropertyEditorMLeaderStyle;

#define AcPeNumericType								ZcPeNumericType
#define IAcPeNumericEditor_QueryInterface			IZcPeNumericEditor_QueryInterface
#define IAcPeNumericEditor_AddRef					IZcPeNumericEditor_AddRef
#define IAcPeNumericEditor_Release					IZcPeNumericEditor_Release
#define IAcPeNumericEditor_SetNumericDataType		IZcPeNumericEditor_SetNumericDataType
#define IAcPeNumericEditor_SetNumericDataType_Proxy	IZcPeNumericEditor_SetNumericDataType_Proxy
#define IAcPeNumericEditor_SetNumericDataType_Stub	IZcPeNumericEditor_SetNumericDataType_Stub
#define IAcPeVariantCtrl_QueryInterface				IZcPeVariantCtrl_QueryInterface
#define IAcPeVariantCtrl_AddRef						IZcPeVariantCtrl_AddRef
#define IAcPeVariantCtrl_Release					IZcPeVariantCtrl_Release
#define IAcPeVariantCtrl_SetDwCookies				IZcPeVariantCtrl_SetDwCookies
#define IAcPeVariantCtrl_SetGroupOffset				IZcPeVariantCtrl_SetGroupOffset
#define IAcPeVariantCtrl_SetElementCount			IZcPeVariantCtrl_SetElementCount
#define IAcPeVariantCtrl_SetDwCookies_Proxy			IZcPeVariantCtrl_SetDwCookies_Proxy
#define IAcPeVariantCtrl_SetDwCookies_Stub			IZcPeVariantCtrl_SetDwCookies_Stub
#define IAcPeVariantCtrl_SetGroupOffset_Proxy		IZcPeVariantCtrl_SetGroupOffset_Proxy
#define IAcPeVariantCtrl_SetGroupOffset_Stub		IZcPeVariantCtrl_SetGroupOffset_Stub
#define IAcPeVariantCtrl_SetElementCount_Proxy		IZcPeVariantCtrl_SetElementCount_Proxy
#define IAcPeVariantCtrl_SetElementCount_Stub		IZcPeVariantCtrl_SetElementCount_Stub
#define IAcPeColorCtrl_QueryInterface				IZcPeColorCtrl_QueryInterface
#define IAcPeColorCtrl_AddRef						IZcPeColorCtrl_AddRef
#define IAcPeColorCtrl_Release						IZcPeColorCtrl_Release
#define IAcPeColorCtrl_SetNoMetaColor				IZcPeColorCtrl_SetNoMetaColor
#define IAcPeColorCtrl_SetNoMetaColor_Proxy			IZcPeColorCtrl_SetNoMetaColor_Proxy
#define IAcPeColorCtrl_SetNoMetaColor_Stub			IZcPeColorCtrl_SetNoMetaColor_Stub
#define IAcPeSpinCtrl_QueryInterface				IZcPeSpinCtrl_QueryInterface
#define IAcPeSpinCtrl_AddRef						IZcPeSpinCtrl_AddRef
#define IAcPeSpinCtrl_Release						IZcPeSpinCtrl_Release
#define IAcPeSpinCtrl_SetControls					IZcPeSpinCtrl_SetControls
#define IAcPeSpinCtrl_SetControls_Proxy				IZcPeSpinCtrl_SetControls_Proxy
#define IAcPeSpinCtrl_SetControls_Stub				IZcPeSpinCtrl_SetControls_Stub
#define IAcPeNoPickVariantRW_QueryInterface			IZcPeNoPickVariantRW_QueryInterface
#define IAcPeNoPickVariantRW_AddRef					IZcPeNoPickVariantRW_AddRef
#define IAcPeNoPickVariantRW_Release				IZcPeNoPickVariantRW_Release
#define IAcPeNoPickVariantRW_SetAlwaysRW			IZcPeNoPickVariantRW_SetAlwaysRW
#define IAcPeNoPickVariantRW_SetAlwaysRW_Proxy		IZcPeNoPickVariantRW_SetAlwaysRW_Proxy
#define IAcPeNoPickVariantRW_SetAlwaysRW_Stub		IZcPeNoPickVariantRW_SetAlwaysRW_Stub
#define IAcPeButtonEditCtrl_QueryInterface			IZcPeButtonEditCtrl_QueryInterface
#define IAcPeButtonEditCtrl_AddRef					IZcPeButtonEditCtrl_AddRef
#define IAcPeButtonEditCtrl_Release					IZcPeButtonEditCtrl_Release
#define IAcPeButtonEditCtrl_put_DefaultPicture		IZcPeButtonEditCtrl_put_DefaultPicture
#define IAcPeButtonEditCtrl_get_DefaultPicture		IZcPeButtonEditCtrl_get_DefaultPicture
#define IAcPeButtonEditCtrl_put_DisabledPicture		IZcPeButtonEditCtrl_put_DisabledPicture
#define IAcPeButtonEditCtrl_get_DisabledPicture		IZcPeButtonEditCtrl_get_DisabledPicture
#define IAcPeButtonEditCtrl_put_DefaultPicture_Proxy	IZcPeButtonEditCtrl_put_DefaultPicture_Proxy
#define IAcPeButtonEditCtrl_get_DefaultPicture_Proxy	IZcPeButtonEditCtrl_get_DefaultPicture_Proxy
#define IAcPeButtonEditCtrl_get_DefaultPicture_Stub		IZcPeButtonEditCtrl_get_DefaultPicture_Stub
#define IAcPeButtonEditCtrl_put_DisabledPicture_Proxy	IZcPeButtonEditCtrl_put_DisabledPicture_Proxy
#define IAcPeButtonEditCtrl_get_DisabledPicture_Proxy	IZcPeButtonEditCtrl_get_DisabledPicture_Proxy
#define IAcPeButtonEditCtrl_get_DisabledPicture_Stub	IZcPeButtonEditCtrl_get_DisabledPicture_Stub
#define IAcPeButtonPicture_QueryInterface				IZcPeButtonPicture_QueryInterface
#define IAcPeButtonPicture_AddRef						IZcPeButtonPicture_AddRef
#define IAcPeButtonPicture_Release						IZcPeButtonPicture_Release
#define IAcPeButtonPicture_put_DefaultPicture			IZcPeButtonPicture_put_DefaultPicture
#define IAcPeButtonPicture_get_DefaultPicture			IZcPeButtonPicture_get_DefaultPicture
#define IAcPeButtonPicture_put_DisabledPicture			IZcPeButtonPicture_put_DisabledPicture
#define IAcPeButtonPicture_get_DisabledPicture			IZcPeButtonPicture_get_DisabledPicture
#define IAcPeButtonPicture_put_DefaultPicture_Proxy		IZcPeButtonPicture_put_DefaultPicture_Proxy
#define IAcPeButtonPicture_put_DefaultPicture_Stub		IZcPeButtonPicture_put_DefaultPicture_Stub
#define IAcPeButtonPicture_get_DefaultPicture_Proxy		IZcPeButtonPicture_get_DefaultPicture_Proxy
#define IAcPeButtonPicture_get_DefaultPicture_Stub		IZcPeButtonPicture_get_DefaultPicture_Stub
#define IAcPeButtonPicture_put_DisabledPicture_Proxy	IZcPeButtonPicture_put_DisabledPicture_Proxy
#define IAcPeButtonPicture_put_DisabledPicture_Stub		IZcPeButtonPicture_put_DisabledPicture_Stub
#define IAcPeButtonPicture_get_DisabledPicture_Proxy	IZcPeButtonPicture_get_DisabledPicture_Proxy
#define IAcPeButtonPicture_get_DisabledPicture_Stub		IZcPeButtonPicture_get_DisabledPicture_Stub
#define IAcPePick2PointsCtrl_QueryInterface				IZcPePick2PointsCtrl_QueryInterface
#define IAcPePick2PointsCtrl_AddRef						IZcPePick2PointsCtrl_AddRef
#define IAcPePick2PointsCtrl_Release					IZcPePick2PointsCtrl_Release
#define IAcPePick2PointsCtrl_SetPrompts					IZcPePick2PointsCtrl_SetPrompts
#define IAcPePick2PointsCtrl_SetPrompts_Stub			IZcPePick2PointsCtrl_SetPrompts_Stub
#define IAcPeCalculatorCtrl_QueryInterface				IZcPeCalculatorCtrl_QueryInterface
#define IAcPeCalculatorCtrl_AddRef						IZcPeCalculatorCtrl_AddRef
#define IAcPeCalculatorCtrl_Release						IZcPeCalculatorCtrl_Release
#define	IAcPeCalculatorCtrl_SetCalculatorMode			IZcPeCalculatorCtrl_SetCalculatorMode
#define IAcPeCalculatorCtrl_SetCalculatorMode_Stub		IZcPeCalculatorCtrl_SetCalculatorMode_Stub


#endif