
#ifndef _ARXPORT_AD_DBFIELD_H_
#define _ARXPORT_AD_DBFIELD_H_ 1

#include "AdAChar.h"
#include "AcField.h"
#include "acstring.h"

class ZcDbField;

typedef ZcDbField AcDbField ;

#include "..\inc\zDbField.h"

typedef ZcDbFieldArray					AcDbFieldArray;
typedef ZcFd							AcFd;
typedef ZcHyperlink						AcHyperlink;
typedef ZcDbField						AcDbField;

#define acdbGetFieldEngine				zcdbGetFieldEngine
#define	acdbGetFieldMarkers				zcdbGetFieldMarkers
#define acdbHasFields					zcdbHasFields
#define acdbFindField					zcdbFindField
#define acdbEvaluateFields				zcdbEvaluateFields
#define acdbConvertFieldsToText			zcdbConvertFieldsToText
#define acdbMakeFieldCode				zcdbMakeFieldCode

#endif
