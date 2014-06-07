
#ifndef _ARXPORT_AD_ACUTADS_H_
#define _ARXPORT_AD_ACUTADS_H_ 1


#ifdef __cplusplus
extern "C" {
#endif

#include "adsdef.h"
#include "AdAChar.h"

#ifdef __cplusplus
}
#endif

#include "..\inc\zcutzds.h"
#include "..\inc\zcutmem.h"

#define acad__assert			zcad__assert
#define acutCvUnit				zcutCvUnit
#define acutWcMatch				zcutWcMatch
#define acutPrintf				zcutPrintf
#define acutSPrintf				zcutSPrintf
#define acutNewRb				zcutNewRb
#define acutRelRb				zcutRelRb
#define acutBuildList			zcutBuildList
#define acutAngle				zcutAngle
#define acutDistance			zcutDistance
#define acutPolar				zcutPolar
#define acutIsAlpha				zcutIsAlpha
#define acutIsUpper				zcutIsUpper
#define acutIsLower				zcutIsLower
#define acutIsDigit				zcutIsDigit
#define acutIsXDigit			zcutIsXDigit
#define acutIsSpace				zcutIsSpace
#define acutIsPunct				zcutIsPunct
#define acutIsAlNum				zcutIsAlNum
#define acutIsPrint				zcutIsPrint
#define acutIsGraph				zcutIsGraph
#define acutIsCntrl				zcutIsCntrl
#define acutToUpper				zcutToUpper
#define acutToLower				zcutToLower

#define acutNewBuffer			zcutNewBuffer
#define acutNewString			zcutNewString
#define acutUpdString			zcutUpdString
#define acutDelBuffer			zcutDelBuffer
#endif