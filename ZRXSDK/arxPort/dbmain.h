
#ifndef _ARXPORT_AD_DBMAIN_H_
#define _ARXPORT_AD_DBMAIN_H_ 1

#include "gepnt3d.h"
#include "gevec3d.h"
#include "geline3d.h"
#include "AcHeapOpers.h"
#include "adesk.h"
#include "rxobject.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxditer.h"
#include "rxsrvice.h"
#include "dbptrar.h"
#include "dbcolor.h"
#include "dbidar.h"
#include "drawable.h"
#include "dbsecurity.h"

class ZcGeFastTransform;
class ZcCmEntityColor;
class ZcCmColor;
class ZcDbBlockBegin;
class ZcDbBlockEnd;
class ZcDbDatabase;
class ZcDbDatabaseIterator;
class ZcDbDatabaseReactor;
class ZcDbEntity;
class ZcDbEntityReactor;
class ZcDbImpDatabase;
class ZcDbImpObject;
class ZcDbObject;
class ZcDbObjectReactor;
class ZcDbServices;
class ZcDbSpaceIterator;
class ZcDbSystemInternals;
class ZcDbXObject;
class ZcDbBlockReference;
class ZcDbSymbolTable;
class ZcDbBlockTable;
class ZcDbBlockTableRecord;
class ZcDbLayerTable;
class ZcDbTextStyleTable;
class ZcDbLinetypeTable;
class ZcDbAbstractViewTable;
class ZcDbViewTable;
class ZcDbUCSTable;
class ZcDbViewportTable;
class ZcDbRegAppTable;
class ZcDbDimStyleTable;
class ZcDbDimStyleTableRecord;
class ZcDbIdMapping;
class ZcDbDictionary;
class ZcDbDictionaryWithDefault;
class ZcDbMline;
class ZcDbMlineStyle;
class ZcDbCurve;
class ZcDbEllipse;
class ZcDbSpline;
class ZcDbRegion;
class ZcDb3dSolid;
class ZcDbBody;
class ZcDbDate;
class ZcDbExtents;
class ZcDbAuditInfo;
class ZcDbUndoController;
class ZcDbTransactionManager;
class ZcDbSpatialFilter;
class ZcDbLayerFilter;
class ZcGeFastTransform;
class ZcGsNode;
class ZcGsModel;
class ZcGiContext;
class ZcDbObjectIdGraph;
class ZcDbLayerStateManager;
class ZcDwgFileHandle;
class ZcFileDependencyManager;
class ZcDbTableStyle;
class ZcFdFieldValue;
class ZcDbField;
class ZcDbSectionManager;
class ZcDbDataLinkManager;
class ZcGiMapper;
class ZcDbAnnotationScale;


typedef ZcGeFastTransform				AcGeFastTransform;
typedef ZcCmEntityColor					AcCmEntityColor;
typedef ZcCmColor						AcCmColor;
typedef ZcDbBlockBegin					AcDbBlockBegin;
typedef ZcDbBlockEnd					AcDbBlockEnd;
typedef ZcDbDatabase					AcDbDatabase;
typedef ZcDbDatabaseIterator			AcDbDatabaseIterator;
typedef ZcDbDatabaseReactor				AcDbDatabaseReactor;
typedef ZcDbEntity						AcDbEntity;
typedef ZcDbEntityReactor				AcDbEntityReactor;
typedef ZcDbImpDatabase					AcDbImpDatabase;
typedef ZcDbImpObject					AcDbImpObject;
typedef ZcDbObject						AcDbObject;
typedef ZcDbObjectReactor				AcDbObjectReactor;
typedef ZcDbServices					AcDbServices;
typedef ZcDbSpaceIterator				AcDbSpaceIterator;
typedef ZcDbSystemInternals				AcDbSystemInternals;
typedef ZcDbXObject						AcDbXObject;
typedef ZcDbBlockReference				AcDbBlockReference;
typedef ZcDbSymbolTable					AcDbSymbolTable;
typedef ZcDbBlockTable					AcDbBlockTable;
typedef ZcDbBlockTableRecord			AcDbBlockTableRecord;
typedef ZcDbLayerTable					AcDbLayerTable;
typedef ZcDbTextStyleTable				AcDbTextStyleTable;
typedef ZcDbLinetypeTable				AcDbLinetypeTable;
typedef ZcDbAbstractViewTable			AcDbAbstractViewTable;
typedef ZcDbViewTable					AcDbViewTable;
typedef ZcDbUCSTable					AcDbUCSTable;
typedef ZcDbViewportTable				AcDbViewportTable;
typedef ZcDbRegAppTable					AcDbRegAppTable;
typedef ZcDbDimStyleTable				AcDbDimStyleTable;
typedef ZcDbDimStyleTableRecord			AcDbDimStyleTableRecord;
typedef ZcDbIdMapping					AcDbIdMapping;
typedef ZcDbDictionary					AcDbDictionary;
typedef ZcDbDictionaryWithDefault		AcDbDictionaryWithDefault;
typedef ZcDbMline						AcDbMline;
typedef ZcDbMlineStyle					AcDbMlineStyle;
typedef ZcDbCurve						AcDbCurve;
typedef ZcDbEllipse						AcDbEllipse;
typedef ZcDbSpline						AcDbSpline;
typedef ZcDbRegion						AcDbRegion;
typedef ZcDb3dSolid						AcDb3dSolid;
typedef ZcDbBody						AcDbBody;
typedef ZcDbDate						AcDbDate;
typedef ZcDbExtents						AcDbExtents;
typedef ZcDbAuditInfo					AcDbAuditInfo;
typedef ZcDbUndoController				AcDbUndoController;
typedef ZcDbTransactionManager			AcDbTransactionManager;
typedef ZcDbSpatialFilter				AcDbSpatialFilter;
typedef ZcDbLayerFilter					AcDbLayerFilter;
typedef ZcGeFastTransform				AcGeFastTransform;
typedef ZcGsNode						AcGsNode;
typedef ZcGsModel						AcGsModel;
typedef ZcGiContext						AcGiContext;
typedef ZcDbObjectIdGraph				AcDbObjectIdGraph;
typedef ZcDbLayerStateManager			AcDbLayerStateManager;
typedef ZcDwgFileHandle					AcDwgFileHandle;
typedef ZcFileDependencyManager			AcFileDependencyManager;
typedef ZcDbTableStyle					AcDbTableStyle;
typedef ZcFdFieldValue					AcFdFieldValue;
typedef ZcDbField						AcDbField;
typedef ZcDbSectionManager				AcDbSectionManager;
typedef ZcDbDataLinkManager				AcDbDataLinkManager;
typedef ZcGiMapper						AcGiMapper;
typedef ZcDbAnnotationScale				AcDbAnnotationScale;


#include "acdb.h"
#include "dbhandle.h"
#include "dbfiler.h"
#include "ads.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"


class ZcDbGripData;
typedef ZcDbGripData AcDbGripData;


#include "..\inc\zdbmain.h"

#define AcDbGripDataPtrArray       ZcDbGripDataPtrArray
#define AcDbFullSubentPathArray    ZcDbFullSubentPathArray

#define AcDbFullSubentPath  ZcDbFullSubentPath




#define acdbServices						zcdbServices
#define acdbGroupCodeToType					zcdbGroupCodeToType
#define acdbFreeResBufContents				zcdbFreeResBufContents
#define acdbIsPersistentReactor				zcdbIsPersistentReactor
#define acdbPersistentReactorObjectId		zcdbPersistentReactorObjectId
#define acdbDisplayPreviewFromDwg			zcdbDisplayPreviewFromDwg
#define acdbIsCustomObject					zcdbIsCustomObject
#define acdbOpenAcDbObject					zcdbOpenZcDbObject
#define acdbOpenAcDbEntity					zcdbOpenZcDbEntity
#define acdbOpenObject						zcdbOpenObject
#define acdbResurrectMeNow					zcdbResurrectMeNow
#define acdbGetAdsName						zcdbGetZdsName
#define acdbGetObjectId						zcdbGetObjectId
#define acdbSetReferenced					zcdbSetReferenced
#define acdbActiveDatabaseArray				zcdbActiveDatabaseArray
#define acdbLoadMlineStyleFile				zcdbLoadMlineStyleFile
#define acdbLoadLineTypeFile				zcdbLoadLineTypeFile
#define acdbAlloc							zcdbAlloc
#define acdbRealloc							zcdbRealloc
#define acdbAlloc_dbg						zcdbAlloc_dbg
#define acdbRealloc_dbg						zcdbRealloc_dbg
#define acdbFree							zcdbFree
#define acdbValidateSetup					zcdbValidateSetup
#define acdbCleanUp							zcdbCleanUp
#define acdbOriginalXrefFullPathFor			zcdbOriginalXrefFullPathFor
#define acdbSetDefaultAcGiContext			zcdbSetDefaultZcGiContext
#define acdbGetThumbnailBitmapFromDxfFile	zcdbGetThumbnailBitmapFromDxfFile
#define acdbSaveAs2004						zcdbSaveAs2004
#define acdbSaveAs2000						zcdbSaveAs2000
#define acdbDxfOutAs2004					zcdbDxfOutAs2004
#define acdbDxfOutAs2000					zcdbDxfOutAs2000
#define acdbDxfOutAsR12						zcdbDxfOutAsR12
#define acdbSaveAsR14						zcdbSaveAsR14
#define getAcDbHandle						getZcDbHandle 

typedef ZcDbServices						AcDbServices;
typedef ZcDbDatabase						AcDbDatabase;
typedef ZcDbObjectIterator					AcDbObjectIterator;
typedef ZcDbObject							AcDbObject;
typedef ZcDbXObject							AcDbXObject;
typedef ZcCmComplexColor					AcCmComplexColor;
typedef ZcCmColor							AcCmColor;

#define accmGetColorFromACIName				zccmGetColorFromACIName
#define accmGetColorFromRGBName				zccmGetColorFromRGBName
#define accmGetColorFromColorBookName		zccmGetColorFromColorBookName
#define accmGetLocalizedColorNames			zccmGetLocalizedColorNames

typedef ZcDbColor							AcDbColor;
typedef ZcDbEntity							AcDbEntity;
typedef ZcDbObjectReactor					AcDbObjectReactor;
typedef ZcDbEntityReactor					AcDbEntityReactor;
typedef ZcDbDatabaseReactor					AcDbDatabaseReactor;
typedef ZcDbExtents							AcDbExtents;

typedef ZcDbGripDataPtrArray				AcDbGripDataPtrArray;
typedef ZcDbFullSubentPathArray				AcDbFullSubentPathArray;

#define AC_SRCH_BLOCK						ZC_SRCH_BLOCK
#define AC_SRCH_DIM_TEXT					ZC_SRCH_DIM_TEXT
#define AC_SRCH_TEXT						ZC_SRCH_TEXT
#define AC_SRCH_LINK_DESC					ZC_SRCH_LINK_DESC
#define AC_SRCH_LINK_URL					ZC_SRCH_LINK_URL
#define AC_SRCH_MATCH_CASE					ZC_SRCH_MATCH_CASE
#define AC_SRCH_WHOLE_WORD					ZC_SRCH_WHOLE_WORD
#define AC_SRCH_DEFAULT						ZC_SRCH_DEFAULT

#define acdbTextFind						zcdbTextFind

#define addAcDbObject						addZcDbObject

#define getAcDbObjectId						getZcDbObjectId
#define setAcDbObjectIdsInFlux				setZcDbObjectIdsInFlux
#define isAcDbObjectIdsInFlux				isZcDbObjectIdsInFlux


#endif
