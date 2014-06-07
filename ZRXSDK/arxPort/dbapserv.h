
#ifndef _ARXPORT_AD_DBAPSERVE_H_
#define _ARXPORT_AD_DBAPSERVE_H_ 1

#include "adesk.h"
#include "acdb.h"
#include "acarray.h"
#include "inetstrc.h"
#include "rxdlinkr.h"

class ZcDbAuditInfo;
class ZcDbDatabase;
class ZcDbTransactionManager;
class ZcDbAppSystemVariables;
class ZcDbPlotSettingsValidator;
class ZcDbLayoutManager;
struct _EXCEPTION_POINTERS;


typedef ZcDbAuditInfo				AcDbAuditInfo;
typedef ZcDbDatabase				AcDbDatabase;
typedef ZcDbTransactionManager		AcDbTransactionManager;
typedef ZcDbAppSystemVariables		AcDbAppSystemVariables;
typedef ZcDbPlotSettingsValidator	AcDbPlotSettingsValidator;
typedef ZcDbLayoutManager			AcDbLayoutManager;

#include "..\inc\zdbapserv.h"

typedef ZcDbHostApplicationServices				AcDbHostApplicationServices;
typedef ZcDbHostApplicationProgressMeter		AcDbHostApplicationProgressMeter;
typedef ZcDbPasswordedFile						AcDbPasswordedFile;

#define acdbSetHostApplicationServices			zcdbSetHostApplicationServices
#define acdbHostApplicationServices				zcdbHostApplicationServices
#define acdbSendInitialDwgFileOpenComplete		zcdbSendInitialDwgFileOpenComplete
#define acdbTriggerAcadOctTreeReclassification	zcdbTriggerZcadOctTreeReclassification
#define acdbSetBreak3dQueueForRegen				zcdbSetBreak3dQueueForRegen
#define acdbHostAppMinorVersion				    zcdbHostAppMinorVersion
#define reportUnhandledArxException				reportUnhandledZrxException
#define acadInternalServices					zcadInternalServices
#define acadInternalGetvar						zcadInternalGetvar

#define mapInetStatusToAcadStatus				mapInetStatusToZcadStatus


#define kMDIEnabled				MDIEnabled
#define kSDIUserEnforced		SDIUserEnforced
#define kSDIAppEnforced			SDIAppEnforced
#define kSDIUserAndAppEnforced	SDIUserAndAppEnforced

#define ProdIdCode	ZProdIdCode
#define	kProd_ACAD	Prod_ZCAD
#define	kProd_LT	Prod_LT
#define kProd_OEM	Prod_OEM
#define	kProd_AcDb	Prod_ZcDb





#endif

