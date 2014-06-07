#ifndef _ARXPORT_ADUIVOLUMEDESCRIPTROR_H_
#define _ARXPORT_ADUIVOLUMEDESCRIPTROR_H_

#include "AdAChar.h"

#ifdef ACUTIL_INTERNAL
#include <tchar.h>
#include <afx.h>
#ifdef ADUI_PORT
#undef ADUI_PORT
#endif
#define ADUI_PORT
#endif

#include "aduipathenums.h"

#include "..\inc\zduiVolumeDescriptor.h"

typedef CZdUiVolumeDescriptor      CAdUiVolumeDescriptor;
typedef CZdUiNTFSVolumeDescriptor  CAdUiNTFSVolumeDescriptor;
typedef CZdUiVFATVolumeDescriptor  CAdUiVFATVolumeDescriptor;
typedef CZdUiHPFSVolumeDescriptor  CAdUiHPFSVolumeDescriptor;
typedef CZdUiCDFSVolumeDescriptor  CAdUiCDFSVolumeDescriptor;
typedef CZdUiFATVolumeDescriptor   CAdUiFATVolumeDescriptor;
typedef CZdUiUFSVolumeDescriptor   CAdUiUFSVolumeDescriptor;
typedef CZdUiNOFSVolumeDescriptor  CAdUiNOFSVolumeDescriptor;
#endif

