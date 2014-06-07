
#ifndef _ARXPORT_AD_ACPUBLISHREACTORS_H_
#define _ARXPORT_AD_ACPUBLISHREACTORS_H_ 1

#include "rxobject.h"
#include "AcArray.h"
#include "AcPlDSDData.h"
#include "AcPlDSDEntry.h"
#include "AcDMMUtils.h"
#include "AcDMMEPlotProperty.h"
#include "AcPlPlotErrorHandler.h"
#include "AcPlPlotLogger.h"


class ZcPublishReactorManager;
class ZcPublishReactor;
class ZcPublishReactorInfo;
class ZcPublishBeginJobInfo;
class ZcPublishSheetInfo;


typedef ZcPublishReactorManager        AcPublishReactorManager;
typedef ZcPublishReactor               AcPublishReactor;
typedef ZcPublishReactorInfo           AcPublishReactorInfo;
typedef ZcPublishBeginJobInfo          AcPublishBeginJobInfo;
typedef ZcPublishSheetInfo             AcPublishSheetInfo;


#include "..\inc\zcpublishreactors.h"

typedef ZcNameValuePair					AcNameValuePair;
typedef ZcNameValuePairVec				AcNameValuePairVec;
typedef ZcPublishBeforeJobInfo			AcPublishBeforeJobInfo;

typedef ZcPublishBeginJobInfo			AcPublishBeginJobInfo;
typedef ZcPublishSheetInfo				AcPublishSheetInfo;
typedef ZcPublishAggregationInfo		AcPublishAggregationInfo;
typedef ZcPublishReactorInfo			AcPublishReactorInfo;
typedef ZcPublishReactor				AcPublishReactor;


#define AcGlobRemovePublishReactor			ZcGlobRemovePublishReactor
#define AcGlobAddPublishReactor				ZcGlobAddPublishReactor


typedef ZCGLOBADDPUBLISHREACTOR             ACGLOBADDPUBLISHREACTOR;
typedef ZCGLOBREMOVEPUBLISHREACTOR          ACGLOBREMOVEPUBLISHREACTOR;

#endif