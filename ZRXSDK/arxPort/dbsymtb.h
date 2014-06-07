
#ifndef _ARXPORT_AD_DBSYMTB_H_
#define _ARXPORT_AD_DBSYMTB_H_ 1

#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbbackground.h"
#include "gevec2d.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"
#include "..\inc\zdbsymtb.h"


typedef ZcDbSymbolTable					AcDbSymbolTable;
typedef ZcDbBlockTable					AcDbBlockTable;
typedef ZcDbLayerTable					AcDbLayerTable;
typedef ZcDbTextStyleTable				AcDbTextStyleTable;
typedef ZcDbLinetypeTable				AcDbLinetypeTable;
typedef ZcDbAbstractViewTable			AcDbAbstractViewTable;
typedef ZcDbViewTable					AcDbViewTable;
typedef ZcDbUCSTable					AcDbUCSTable;
typedef ZcDbViewportTable				AcDbViewportTable;
typedef ZcDbRegAppTable					AcDbRegAppTable;
typedef ZcDbDimStyleTable				AcDbDimStyleTable;
typedef ZcDbSymbolTableIterator			AcDbSymbolTableIterator;
typedef ZcDbBlockTableIterator			AcDbBlockTableIterator;
typedef ZcDbLayerTableIterator			AcDbLayerTableIterator;
typedef ZcDbTextStyleTableIterator		AcDbTextStyleTableIterator;
typedef ZcDbLinetypeTableIterator		AcDbLinetypeTableIterator;
typedef ZcDbAbstractViewTableIterator	AcDbAbstractViewTableIterator;
typedef ZcDbViewTableIterator			AcDbViewTableIterator;
typedef ZcDbUCSTableIterator			AcDbUCSTableIterator;
typedef ZcDbViewportTableIterator		AcDbViewportTableIterator;
typedef ZcDbRegAppTableIterator			AcDbRegAppTableIterator;
typedef ZcDbDimStyleTableIterator		AcDbDimStyleTableIterator;
typedef ZcDbSymbolTableRecord			AcDbSymbolTableRecord;
typedef ZcDbBlockTableRecordIterator	AcDbBlockTableRecordIterator;
typedef ZcDbBlockReferenceIdIterator	AcDbBlockReferenceIdIterator;
typedef ZcDbBlockTableRecord			AcDbBlockTableRecord;
typedef ZcDbLayerTableRecord			AcDbLayerTableRecord;
typedef ZcDbTextStyleTableRecord		AcDbTextStyleTableRecord;
typedef ZcDbLinetypeTableRecord			AcDbLinetypeTableRecord;
typedef ZcDbAbstractViewTableRecord		AcDbAbstractViewTableRecord;
typedef ZcDbViewTableRecord				AcDbViewTableRecord;
typedef ZcDbUCSTableRecord				AcDbUCSTableRecord;
typedef ZcDbViewportTableRecord			AcDbViewportTableRecord;
typedef ZcDbRegAppTableRecord			AcDbRegAppTableRecord;
typedef ZcDbDimStyleTableRecord			AcDbDimStyleTableRecord;

#define appendAcDbEntity				appendZcDbEntity

#endif
