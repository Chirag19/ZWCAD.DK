
#ifndef _ARXPORT_AD_ACSYMUTL_H_
#define _ARXPORT_AD_ACSYMUTL_H_ 1

#include "acadstrc.h"
#include "dbsymutl.h"

class ZcDbDatabase;

typedef ZcDbDatabase				AcDbDatabase;

#include "..\inc\zcsymutl.h"

namespace AcEdSymbolUtilities = ZcEdSymbolUtilities;
namespace AcEdSymUtil = AcEdSymbolUtilities;

#define ACEDSYMUTIL_SERVICESNAME_WITH_VERSION_1		ZCEDSYMUTIL_SERVICESNAME_WITH_VERSION_1
#define ACEDSYMUTIL_SERVICESNAME_WITH_VERSION		ZCEDSYMUTIL_SERVICESNAME_WITH_VERSION
#define ACEDSYMUTIL_SERVICES_NAME					ZCEDSYMUTIL_SERVICES_NAME

typedef ZcEdSymUtilServices			AcEdSymUtilServices;

#define acedSymUtil					zcedSymUtil

#endif
