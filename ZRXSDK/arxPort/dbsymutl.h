
#ifndef _ARXPORT_AD_DBSYMUTL_H_
#define _ARXPORT_AD_DBSYMUTL_H_ 1

#include "dbsymtb.h"
#include "..\inc\zdbsymutl.h"

namespace AcDbSymbolUtilities = ZcDbSymbolUtilities;
namespace AcDbSymUtil = ZcDbSymUtil;

#define ACDBSYMUTIL_SERVICESNAME_WITH_VERSION	ZCDBSYMUTIL_SERVICESNAME_WITH_VERSION
#define ACDBSYMUTIL_SERVICESNAME_WITH_VERSION_1	ZCDBSYMUTIL_SERVICESNAME_WITH_VERSION_1
#define ACDBSYMUTIL_SERVICES_NAME				ZCDBSYMUTIL_SERVICES_NAME
#define ACDBSYMUTIL_SERVICES_CURRENT_VERSION	ZCDBSYMUTIL_SERVICES_CURRENT_VERSION
#define acdbSymUtil								zcdbSymUtil
#define isRegAppAcadName						isRegAppZcadName
#define regAppAcadId							regAppZcadId
#define regAppAcadName							regAppZcadName

typedef ZcDbSymUtilServices			AcDbSymUtilServices;


#endif