#ifndef _ARXPORT_AD_ACGS_H_
#define _ARXPORT_AD_ACGS_H_ 1


#include "adesk.h"
#include "stdlib.h"
#include "AdAChar.h"
#include "..\inc\zcgs.h"


#define acgsGetDisplayInfo				zcgsGetDisplayInfo
#define acgsGetViewportInfo				zcgsGetViewportInfo

typedef ZcGsScreenShot				AcGsScreenShot;

#define acgsGetScreenShot			zcgsGetScreenShot
#define acgsSetViewportRenderFlag	zcgsSetViewportRenderFlag
#define acgsDisplayImage			zcgsDisplayImage
#define acgsRemoveAnonymousGraphics	zcgsRemoveAnonymousGraphics
#define acgsSetCustomUpdateMethod	zcgsSetCustomUpdateMethod
#define acgsRedrawShortTermGraphics	zcgsRedrawShortTermGraphics

typedef ZcGs					AcGs;

#define acgsSetHighlightColor			zcgsSetHighlightColor
#define acgsGetHighlightColor			zcgsGetHighlightColor
#define acgsSetHighlightLinePattern		zcgsSetHighlightLinePattern
#define acgsGetHighlightLinePattern		zcgsGetHighlightLinePattern
#define acgsSetHighlightLineWeight		zcgsSetHighlightLineWeight
#define acgsGetHighlightLineWeight		zcgsGetHighlightLineWeight
#define acgsSetViewParameters			zcgsSetViewParameters
#define acgsGetViewParameters			zcgsGetViewParameters
#define acgsSetLensLength				zcgsSetLensLength
#define acgsGetLensLength				zcgsGetLensLength
#define acgsWriteViewToUndoController	zcgsWriteViewToUndoController
#define acgsSetView2D					zcgsSetView2D
#define acgsGetGsView					zcgsGetGsView
#define acgsGetGsManager				zcgsGetGsManager
#define acgsGetOrthoViewParameters		zcgsGetOrthoViewParameters
#define acgsCreate2DViewLimitManager	zcgsCreate2DViewLimitManager
#define acgsDestroy2DViewLimitManager	zcgsDestroy2DViewLimitManager
#define acgsCustomUpdateMethod			zcgsCustomUpdateMethod

typedef ZcGs2DViewLimitManager		AcGs2DViewLimitManager;

#endif 
