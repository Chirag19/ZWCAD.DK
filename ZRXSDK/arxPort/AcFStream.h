#ifndef _ARXPORT_AD_ACFSTREAM_H_
#define _ARXPORT_AD_ACFSTREAM_H_ 1

#include "malloc.h"             
#include "AdAChar.h"
#include "AdCharFmt.h"
#include "..\inc\ZcFStream.h"

#define AcFStream_Assert			ZcFStream_Assert
#define AcFStream_wideToMulti		ZcFStream_wideToMulti
#define AcFStream_curLocale			ZcFStream_curLocale

typedef ZcIfstream					AcIfstream;
typedef ZcOfstream					AcOfstream;

#endif