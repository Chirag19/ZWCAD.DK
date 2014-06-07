
#ifndef _ARXPORT_AD_AXTEMPL_H_
#define _ARXPORT_AD_AXTEMPL_H_ 1

#include "adesk.h"
#include "axobjref.h"
#include "axboiler.h"
#include "oleaprot.h"

#include "opmext.h"
#include "opmimp.h"
#include "dbobjptr.h"
#include "rxregsvc.h"
#include "..\inc\zaxtempl.h"

#define ACAX_VARIANT_TRUE     ZCAX_VARIANT_TRUE
#define ACAX_VARIANT_FALSE    ZCAX_VARIANT_FALSE

#define IAcadBaseObjectImpl					IZcadBaseObjectImpl
#define IAcadBaseObject2Impl				IZcadBaseObject2Impl
#define IAcadObjectDispatchImpl				IZcadObjectDispatchImpl
#define IAcadEntityDispatchImpl				IZcadEntityDispatchImpl
#define IAcadBaseDatabaseImpl				IZcadBaseDatabaseImpl
#define IAcadBaseSubEntityImpl				IZcadBaseSubEntityImpl





#define	IAcPiPropertyDisplayImpl			IZcPiPropertyDisplayImpl
#define IAcPiCategorizePropertiesImpl		IZcPiCategorizePropertiesImpl
#define IAcadShadowDisplayImpl				IZcadShadowDisplayImpl
#endif
