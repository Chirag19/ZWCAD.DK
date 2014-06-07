
#ifndef _ARXPORT_AD_ACGIENVIRONMENT_H_
#define _ARXPORT_AD_ACGIENVIRONMENT_H_ 1

#include "acgi.h"
#include "AcGiLightTraits.h"
#include "..\inc\ZcGiEnvironment.h"

#define ACGIENV_IMPEXP		ZCGIENV_IMPEXP

typedef ZcGiSolidBackgroundTraits		AcGiSolidBackgroundTraits;
typedef ZcGiGradientBackgroundTraits	AcGiGradientBackgroundTraits;
typedef ZcGiImageBackgroundTraits		AcGiImageBackgroundTraits;
typedef ZcGiGroundPlaneBackgroundTraits	AcGiGroundPlaneBackgroundTraits;
typedef ZcGiSkyBackgroundTraits			AcGiSkyBackgroundTraits;
typedef ZcGiRenderEnvironmentTraits		AcGiRenderEnvironmentTraits;
typedef ZcGiRenderSettingsTraits		AcGiRenderSettingsTraits;

#define AcGiMrFilter				ZcGiMrFilter
#define AcGiMrShadowMode			ZcGiMrShadowMode
#define AcGiMrDiagnosticMode		ZcGiMrDiagnosticMode
#define AcGiMrDiagnosticGridMode	ZcGiMrDiagnosticGridMode
#define AcGiMrDiagnosticPhotonMode	ZcGiMrDiagnosticPhotonMode
#define AcGiMrDiagnosticBSPMode		ZcGiMrDiagnosticBSPMode
#define AcGiMrTileOrder				ZcGiMrTileOrder
#define AcGiMrExposureType			ZcGiMrExposureType
#define AcGiMrFinalGatheringMode	ZcGiMrFinalGatheringMode

typedef ZcGiMentalRayRenderSettingsTraits	AcGiMentalRayRenderSettingsTraits;
typedef ZcGiMentalRayRenderSettingsTraits2	AcGiMentalRayRenderSettingsTraits2;
typedef ZcGiToneOperatorParameters			AcGiToneOperatorParameters;


#endif