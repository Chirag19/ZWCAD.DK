
#ifndef _ARXPORT_AD_ACGI_H_
#define _ARXPORT_AD_ACGI_H_ 1

#include "rxobject.h"
#include "AdAchar.h"
#include "dbpl.h"
#include "gemat3d.h"
#include "gemat2d.h"
#include "dbcolor.h"
#include "acdb.h"
#include "AcGiStyleAttributes.h"
#include "assert.h"

class ZcGiSubEntityTraits;
class ZcGiDrawableTraits;
class ZcGiSubEntityTraitsImp;
class ZcGiWorldGeometry;
class ZcGiViewport;
class ZcGiViewportGeometry;
class ZcGiImpEdgeData;
class ZcGiImpFaceData;
class ZcGiImpVertexData;
class ZcGiImpTextStyle;
class ZcGiTextStyle;
class ZcGiEdgeData;
class ZcGiFaceData;
class ZcGiVertexData;
class OwnerDraw;
class ZcGiImpVariant;
class ZcGiVariant;
class ZcGiContextImp;
class ZcGiContext;
class ZcGiCommonDraw;
class ZcGiGeometry;
class ZcCmEntityColor;
struct ZTextParams;
struct ZFontInfo;
class ZcGiMapper;
class ZcGiViewportTraits;
class ZcGiVisualStyleTraits;
class ZcGiEdgeStyle;
class ZcGiContextualColors;

typedef ZcGiSubEntityTraitsImp		AcGiSubEntityTraitsImp;
typedef ZcGiImpEdgeData				AcGiImpEdgeData;
typedef ZcGiImpFaceData				AcGiImpFaceData;
typedef ZcGiImpVertexData			AcGiImpVertexData;
typedef ZcGiImpTextStyle			AcGiImpTextStyle;
typedef ZcGiImpVariant				AcGiImpVariant;
typedef ZcGiContextImp				AcGiContextImp;
typedef ZcCmEntityColor				AcCmEntityColor;
typedef ZcGiMapper					AcGiMapper;
typedef ZcGiViewportTraits			AcGiViewportTraits;
typedef ZcGiEdgeStyle				AcGiEdgeStyle;
typedef ZTextParams					TextParams;
typedef ZFontInfo					FontInfo;

#include "..\inc\zcgi.h"

typedef ZcGiRegenType				AcGiRegenType;
typedef ZcGiFillType				AcGiFillType;
typedef ZcGiVisibility				AcGiVisibility;
typedef ZcGiArcType					AcGiArcType;
typedef ZcGiOrientationType			AcGiOrientationType;
typedef ZcGiDeviationType			AcGiDeviationType;
typedef ZcGiImageOrg				AcGiImageOrg;
typedef ZcGiImageOrient				AcGiImageOrient;
typedef ZcGiScaleFilterType			AcGiScaleFilterType;
typedef ZcGiRotationFilterType		AcGiRotationFilterType;
typedef ZcGiScaleType				AcGiScaleType;
typedef ZcGiEdgeStyleMaskValues		AcGiEdgeStyleMaskValues;
typedef ZcGiEdgeStyleMask			AcGiEdgeStyleMask;
typedef ZcGiSentScanLines			AcGiSentScanLines;
typedef ZcGiRequestScanLines		AcGiRequestScanLines;
typedef ZcGiClipBoundary			AcGiClipBoundary;
typedef ZcGiColorIntensity			AcGiColorIntensity;
typedef ZcGiColorRGB				AcGiColorRGB;
typedef ZcGiColorRGBA				AcGiColorRGBA;
typedef ZcGiVariant					AcGiVariant;
typedef ZcGiContext					AcGiContext;
typedef ZcGiCommonDraw				AcGiCommonDraw;
typedef ZcGiWorldDraw				AcGiWorldDraw;
typedef ZcGiViewportDraw			AcGiViewportDraw;
typedef ZcGiViewport				AcGiViewport;
typedef ZcGiContextualColors		AcGiContextualColors;
typedef ZcGiContextualColors2		AcGiContextualColors2;
typedef ZcGiSubEntityTraits			AcGiSubEntityTraits;
typedef ZcGiDrawableTraits			AcGiDrawableTraits;
typedef ZcGiNonEntityTraits			AcGiNonEntityTraits;
typedef ZcGiGeometry				AcGiGeometry;
typedef ZcGiWorldGeometry			AcGiWorldGeometry;
typedef ZcGiViewportGeometry		AcGiViewportGeometry;
typedef ZcGiEdgeData				AcGiEdgeData;
typedef ZcGiFaceData				AcGiFaceData;
typedef ZcGiVertexData				AcGiVertexData;
typedef ZcGiTextStyle				AcGiTextStyle;

#define ACGI_SERVICES								ZCGI_SERVICES
#define kAcGiSaveWorldDrawForR12					kZcGiSaveWorldDrawForR12
#define AcGiWorldSegmentCallback					ZcGiWorldSegmentCallback
#define acgiIsValidClipBoundary						zcgiIsValidClipBoundary
#define AcGiSelectionMarkerZCADReserveStart			ZcGiSelectionMarkerZCADReserveStart
#define AcGiSelectionMarkerZCADReserveEnd			ZcGiSelectionMarkerZCADReserveEnd
#define AcGiSelectionMarkerZCADSelectionPreviewOff	ZcGiSelectionMarkerZCADSelectionPreviewOff
#define AcGiSelectionMarkerZCADSelectionPreviewOn	ZcGiSelectionMarkerZCADSelectionPreviewOn

#define acadWindowId						zcadWindowId

// AcGiRegenType						
#define eAcGiRegenTypeInvalid				eZcGiRegenTypeInvalid
#define kAcGiStandardDisplay				kZcGiStandardDisplay
#define kAcGiHideOrShadeCommand				kZcGiHideOrShadeCommand
#define kAcGiRenderCommand					kZcGiRenderCommand
#define kAcGiShadedDisplay					kZcGiShadedDisplay
#define kAcGiForExplode						kZcGiForExplode
#define kAcGiSaveWorldDrawForProxy			kZcGiSaveWorldDrawForProxy

//  AcGiFillType						
#define  kAcGiFillAlways					kZcGiFillAlways				
#define  kAcGiFillNever						kZcGiFillNever

//  AcGiVisibility						
#define  kAcGiInvisible						kZcGiInvisible
#define  kAcGiVisible						kZcGiVisible
#define  kAcGiSilhouette					kZcGiSilhouette

// AcGiArcType						
#define  kAcGiArcSimple						kZcGiArcSimple						
#define  kAcGiArcSector						kZcGiArcSector					
#define  kAcGiArcChord						kZcGiArcChord

//  AcGiOrientationType				
#define  kAcGiCounterClockwise				kZcGiCounterClockwise
#define  kAcGiNoOrientation					kZcGiNoOrientation
#define  kAcGiClockwise						kZcGiClockwise

// AcGiDeviationType					
#define	 kAcGiMaxDevForCircle				kZcGiMaxDevForCircle
#define	 kAcGiMaxDevForCurve				kZcGiMaxDevForCurve
#define	 kAcGiMaxDevForBoundary				kZcGiMaxDevForBoundary
#define	 kAcGiMaxDevForIsoline				kZcGiMaxDevForIsoline		
#define	 kAcGiMaxDevForFacet				kZcGiMaxDevForFacet

// AcGiImageOrg						
#define  kAcGiBitonal						kZcGiBitonal
#define  kAcGiPalette						kZcGiPalette
#define  kAcGiGray							kZcGiGray
#define  kAcGiRGBA							kZcGiRGBA
#define  kAcGiBGRA							kZcGiBGRA
#define  kAcGiARGB							kZcGiARGB
#define  kAcGiABGR							kZcGiABGR
#define  kAcGiBGR							kZcGiBGR
#define  kAcGiRGB  							kZcGiRGB  

// AcGiImageOrient					
#define  kAcGiXLeftToRightTopFirst			kZcGiXLeftToRightTopFirst
#define  kAcGiXLeftToRightBottomFirst		kZcGiXLeftToRightBottomFirst
#define  kAcGiXRightToLeftTopFirst			kZcGiXRightToLeftTopFirst
#define  kAcGiXRightToLeftBottomFirst		kZcGiXRightToLeftBottomFirst
#define  kAcGiYTopToBottomLeftFirst			kZcGiYTopToBottomLeftFirst
#define  kAcGiYTopToBottomRightFirst		kZcGiYTopToBottomRightFirst
#define  kAcGiYBottomToTopLeftFirst			kZcGiYBottomToTopLeftFirst
#define  kAcGiYBottomToTopRightFirst		kZcGiYBottomToTopRightFirst

// AcGiEdgeStyleMaskValues			
#define  kAcGiNoEdgeStyleMask				kZcGiNoEdgeStyleMask
#define  kAcGiJitterMask					kZcGiJitterMask
#define  kAcGiOverhangMask					kZcGiOverhangMask
#define  kAcGiEdgeColorMask					kZcGiEdgeColorMask

// AcGiColorIntensity					
#define  kAcGiMinColorIntensity				kZcGiMinColorIntensity
#define  kAcGiColorIntensity1				kZcGiColorIntensity1
#define  kAcGiColorIntensity2				kZcGiColorIntensity2
#define  kAcGiColorIntensity3				kZcGiColorIntensity3
#define  kAcGiColorIntensity4				kZcGiColorIntensity4
#define  kAcGiColorIntensity5				kZcGiColorIntensity5
#define  kAcGiColorIntensity6				kZcGiColorIntensity6
#define  kAcGiMaxColorIntensity				kZcGiMaxColorIntensity

#endif