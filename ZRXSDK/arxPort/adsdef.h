
#ifndef _ARXPORT_AD_ADSDEF_H_
#define _ARXPORT_AD_ADSDEF_H_ 1

#include "AdAChar.h"
#include "..\inc\zdsdef.h"

typedef double   ads_real;
typedef ads_real ads_point[3];
#ifndef _WIN64

typedef __w64 long ads_name[2];
typedef __w64 long *ads_namep;
#else
typedef __int64 ads_name[2];
typedef __int64 *ads_namep;
#endif
typedef ads_real ads_matrix[4][4];

typedef ads_real *ads_pointp;

typedef zds_binary ads_binary;
typedef zds_u_val ads_u_val;


#endif
