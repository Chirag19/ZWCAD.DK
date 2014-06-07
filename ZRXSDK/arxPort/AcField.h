#ifndef _ARXPORT_AD_ACFIELD_H_
#define _ARXPORT_AD_ACFIELD_H_ 1

#include "AdAChar.h"
#include "AcValue.h"

class ZcDbField;
class ZcDbFieldCache;
class ZcFdFieldResult;
class ZcFdFieldEvaluator;
class ZcFdFieldEvaluatorLoader;
class ZcFdFieldEngine;
class ZcFdFieldValue;
class ZcFdImpFieldFormat;
class ZcDbEvalVariant;

typedef ZcDbField							AcDbField;
typedef ZcDbFieldCache						AcDbFieldCache;
typedef ZcFdImpFieldFormat					AcFdImpFieldFormat;
typedef ZcDbEvalVariant						AcDbEvalVariant;

#include "..\inc\ZcField.h"


typedef ZcFdFieldEvaluator					AcFdFieldEvaluator;
typedef ZcFdFieldEvaluatorLoader			AcFdFieldEvaluatorLoader;
typedef ZcFdFieldEngine						AcFdFieldEngine;
typedef ZcFdFieldResult						AcFdFieldResult;
typedef ZcFdFieldValue						AcFdFieldValue;
typedef ZcFdFieldReactor					AcFdFieldReactor;

#define acdbAddFieldReactor			zcdbAddFieldReactor
#define acdbRemoveFieldReactor		zcdbRemoveFieldReactor

#endif