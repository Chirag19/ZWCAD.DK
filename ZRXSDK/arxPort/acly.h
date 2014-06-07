#ifndef _ARXPORT_AD_ACLY_H_
#define _ARXPORT_AD_ACLY_H_ 1

#include "AdAChar.h"
#include "acadstrc.h"
#include "acarray.h"
#include "dbsymtb.h"
#include "dbxrecrd.h"
#include "..\inc\zcly.h"


typedef ZcLyRelExpr				AcLyRelExpr;
typedef ZcLyAndExpr				AcLyAndExpr;
typedef ZcLyBoolExpr			AcLyBoolExpr;
typedef ZcLyLayerFilter			AcLyLayerFilter;
typedef ZcLyLayerGroup			AcLyLayerGroup;
typedef ZcLyLayerFilterManager	AcLyLayerFilterManager;

#define aclyGetLayerFilterManager	zclyGetLayerFilterManager

#endif