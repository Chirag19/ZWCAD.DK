#ifndef _ARXPORT_AD_DBEVAL_H_
#define _ARXPORT_AD_DBEVAL_H_ 1

#include "dbmain.h"
#include "dbents.h"
#include "acstring.h"
#include "adscodes.h"
#include "adsdef.h"

class  ZcDbEvalGraph;
class  ZcDbEvalEdgeInfo;
class  ZcDbEvalExpr;
class  ZcDbEvalConnectable;
class  ZcDbEvalContext;
class  ZcDbEvalContextPair;
class  ZcDbEvalContextIterator;
class  ZcDbEvalVariant;
class  ZcDbImpEvalContext;
class  ZcDbImpEvalContextIterator;



typedef  ZcDbEvalGraph					AcDbEvalGraph;
typedef  ZcDbEvalEdgeInfo				AcDbEvalEdgeInfo;
typedef  ZcDbEvalExpr					AcDbEvalExpr;
typedef  ZcDbEvalConnectable			AcDbEvalConnectable;
typedef  ZcDbEvalContext				AcDbEvalContext;
typedef  ZcDbEvalContextPair			AcDbEvalContextPair;
typedef  ZcDbEvalContextIterator		AcDbEvalContextIterator;
typedef  ZcDbEvalVariant				AcDbEvalVariant;
typedef  ZcDbImpEvalContext				AcDbImpEvalContext;
typedef  ZcDbImpEvalContextIterator		AcDbImpEvalContextIterator;

#include "..\inc\zdbeval.h"

typedef ZcDbEvalNodeId				AcDbEvalNodeId;
typedef ZcDbEvalNodeIdArray			AcDbEvalNodeIdArray;
typedef ZcDbEvalEdgeInfoArray		AcDbEvalEdgeInfoArray;
typedef ZcDbEvalExprPtrArray		AcDbEvalExprPtrArray;
typedef ZcDbEvalVariantArray		AcDbEvalVariantArray;
typedef ZcDbEvalVariant				AcDbEvalVariant;
typedef ZcDbEvalIdMap				AcDbEvalIdMap;
typedef ZcDbEvalGraph				AcDbEvalGraph;
typedef ZcDbEvalEdgeInfo			AcDbEvalEdgeInfo;
typedef ZcDbEvalExpr				AcDbEvalExpr;
typedef ZcDbEvalConnectable			AcDbEvalConnectable;
typedef ZcDbEvalContext				AcDbEvalContext;
typedef ZcDbEvalContextPair			AcDbEvalContextPair;
typedef ZcDbEvalContextIterator		AcDbEvalContextIterator;
#endif