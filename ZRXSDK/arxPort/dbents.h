
#ifndef _ARXPORT_AD_DBENTS_H_
#define _ARXPORT_AD_DBENTS_H_ 1

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "dbmtext.h"
#include "dbbackground.h"
#include "dbdim.h"
#include "gept2dar.h"
#include "gedblar.h"
#include "dbsymtb.h"
#include "gemat3d.h"
#include "acdbxref.h"
#include "acgi.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"

class ZcDbAttribute;
class ZcDbSequenceEnd;
class ZcDb3dPolylineVertex;
class ZcDb2dVertex;
class ZcDbMText;
class ZcDbAnnotationScale;

typedef ZcDbAttribute            AcDbAttribute;
typedef ZcDbSequenceEnd          AcDbSequenceEnd;
typedef ZcDb3dPolylineVertex     AcDb3dPolylineVertex;
typedef ZcDb2dVertex             AcDb2dVertex;
typedef ZcDbMText                AcDbMText;
typedef ZcDbAnnotationScale      AcDbAnnotationScale;



#include "..\inc\zdbents.h"

typedef ZcDbText						AcDbText;
typedef ZcDbAttributeDefinition			AcDbAttributeDefinition;
typedef ZcDbAttribute					AcDbAttribute;
typedef ZcDbBlockReference				AcDbBlockReference;
typedef ZcDbMInsertBlock				AcDbMInsertBlock;
typedef ZcDbBlockBegin					AcDbBlockBegin;
typedef	ZcDbBlockEnd					AcDbBlockEnd;
typedef ZcDbSequenceEnd					AcDbSequenceEnd;
typedef ZcDbVertex						AcDbVertex;
typedef ZcDb2dVertex					AcDb2dVertex;
typedef ZcDb3dPolylineVertex			AcDb3dPolylineVertex;
typedef ZcDbPolygonMeshVertex			AcDbPolygonMeshVertex;
typedef ZcDbPolyFaceMeshVertex			AcDbPolyFaceMeshVertex;
typedef ZcDbFaceRecord					AcDbFaceRecord;
typedef ZcDb2dPolyline					AcDb2dPolyline;
typedef ZcDb3dPolyline					AcDb3dPolyline;
typedef ZcDbArc							AcDbArc;
typedef ZcDbCircle						AcDbCircle;
typedef ZcDbLine						AcDbLine;
typedef ZcDbPoint						AcDbPoint;
typedef ZcDbFace						AcDbFace;
typedef ZcDbPolyFaceMesh				AcDbPolyFaceMesh;
typedef ZcDbPolygonMesh					AcDbPolygonMesh;
typedef ZcDbSolid						AcDbSolid;
typedef ZcDbTrace						AcDbTrace;
typedef ZcDbShape						AcDbShape;
typedef ZcDbViewport					AcDbViewport;

#define treatAsAcDbBlockRefForExplode   treatAsZcDbBlockRefForExplode

#endif
