#ifndef _ARXPORT_ACFDUTIL_H_
#define _ARXPORT_ACFDUTIL_H_ 1

#include "AdAChar.h"
#include "AcCell.h"


interface IZcSmDatabase;
interface IZcSmSheetSet;
interface IZcSmComponent;
struct ZcHyperlink;

typedef IZcSmDatabase     IAcSmDatabase;
typedef IZcSmSheetSet     IAcSmSheetSet;
typedef IZcSmComponent    IAcSmComponent;
typedef ZcHyperlink       AcHyperlink;


#include "..\inc\ZcFdUtil.h"

typedef  ZcDbEvalNodeId  AcDbEvalNodeId;

#define AcFdEval 			ZcFdEval
#define AcFdMakeFieldCode   ZcFdMakeFieldCode
#define AcFdExtractData     ZcFdExtractData

#endif
