
//-----------------------------------------------------------------------------
//----- SignEntity.cpp : Implementation of SignEntity
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "SignEntity.h"
#include "..\CustomEntComWrap\customEntComWrap_i.c"

//-----------------------------------------------------------------------------
Zdesk::UInt32 SignEntity::kCurrentVersionNumber =1 ;

//-----------------------------------------------------------------------------
ZCRX_DXF_DEFINE_MEMBERS (
						 SignEntity, ZcDbEntity,
						 ZcDb::kDHL_CURRENT, ZcDb::kMReleaseCurrent, 
						 ZcDbProxyEntity::kNoOperation, SIGNENTITY,
						 "SIGNENTITYAPP"
						 "|Product Desc:     A description for your object"
						 "|Company:          Your company name"
						 "|WEB Address:      Your company WEB site address"
						 )

						 //-----------------------------------------------------------------------------
						 SignEntity::SignEntity () : ZcDbEntity ()
{
	m_pntCenter.set(0,0,0);
	m_dblRadius = 10.00;
	m_strTextFirst = "ZWCAD";
	m_strTextSecnd = "2010";
}

SignEntity::~SignEntity () 
{
}


//- Dxf Filing protocol

Zcad::ErrorStatus SignEntity::dxfOutFields(ZcDbDxfFiler* pFiler) const
{
	assertReadEnabled () ;

	Zcad::ErrorStatus es =ZcDbEntity::dxfOutFields (pFiler) ;
	if ( es != Zcad::eOk )
		return (es) ;

	//----- Output params
	//.....
	pFiler->writePoint3d(ZcDb::kDxfXCoord, m_pntCenter);
	pFiler->writeDouble(ZcDb::kDxfReal, m_dblRadius);
	pFiler->writeString(ZcDb::kDxfText, m_strTextFirst);
	pFiler->writeString(ZcDb::kDxfText+1, m_strTextSecnd);

	return (pFiler->filerStatus ()) ;
}

//Sample Code for dxfInFields() with Order Dependence

Zcad::ErrorStatus SignEntity::dxfInFields(ZcDbDxfFiler* pFiler)
{
	assertWriteEnabled();

	Zcad::ErrorStatus es = Zcad::eOk;
	if (Zcad::eOk != ZcDbEntity::dxfInFields(pFiler))
	{
		return es;
	}

	struct resbuf rb;
	pFiler->readItem(&rb);
	if (rb.restype == ZcDb::kDxfXCoord)
	{
		m_pntCenter.set(rb.resval.rpoint[X],rb.resval.rpoint[Y],rb.resval.rpoint[Z]);
	}
	else
	{
		pFiler->pushBackItem();
		es = eInvalidDxfCode;
	}

	pFiler->readItem(&rb);
	if (rb.restype == ZcDb::kDxfReal)
	{
		m_dblRadius = rb.resval.rreal;
	}
	else
	{
		pFiler->pushBackItem();
		es = eInvalidDxfCode;
	}

	pFiler->readItem(&rb);
	if (rb.restype == ZcDb::kDxfText)
	{
		if (m_strTextFirst) delete m_strTextFirst;
		strcpy((char *&)m_strTextFirst, (const char*)rb.resval.rstring);
	}
	else
	{
		pFiler->pushBackItem();
		es = eInvalidDxfCode;
	}

	pFiler->readItem(&rb);
	if (rb.restype == ZcDb::kDxfText+1)
	{
		if (m_strTextSecnd) delete m_strTextSecnd;
		strcpy((char *&)m_strTextSecnd, (const char*)rb.resval.rstring);
	}
	else
	{
		pFiler->pushBackItem();
		es = eInvalidDxfCode;
	}

	return es;
}

//Sample Code for dxfInFields() with Order Independence
/*
Zcad::ErrorStatus SignEntity::dxfInFields(ZcDbDxfFiler* pFiler)
{
	assertWriteEnabled();
	
	resbuf rb;
	ZcGePoint3d p;
	Zdesk::UInt32 fieldsFlags = 0;
	Zcad::ErrorStatus es = Zcad::eOk;
	while ((es==Zcad::eOk) && ((es=pFiler->readResBuf(&rb))==Zcad::eOk))
	{
		switch(rb.restype)
		{
		case ZcDb::kDxfXCoord:
			p=asPnt3d(rb.resval.rpoint);
			fieldsFlags |= 0x1;
			break;
		case ZcDb::kDxfReal:
			m_dblRadius=rb.resval.rreal;
			fieldsFlags |= 0x2;
			break;
		case ZcDb::kDxfText:
			if (!m_strTextFirst)	free(&m_strTextFirst);
			m_strTextFirst = _strdup(rb.resval.rstring);
			fieldsFlags |= 0x3;
			break;
		case ZcDb::kDxfText+1:
			if (!m_strTextSecnd) free(&m_strTextSecnd);
			m_strTextSecnd = _strdup(rb.resval.rstring);
			fieldsFlags |= 0x4;
			break;
			//fall through intentional
		default:
			pFiler->pushBackItem();
			es=Zcad::eEndOfFile;
			break;
		}
	}
	
	if (es != Zcad::eEndOfFile)
	{
		return Zcad::eInvalidResBuf;
	}

	//convert data from old format
	zcdbWcs2Ecs(asDblArray(p), asDblArray(p), asDblArray(ZcGeVector3d(0,0,1)), Zdesk::kFalse);
	m_pntCenter.set(p.x,p.y,p.z);

	return es;
}
*/


//- Dwg Filing protocol

Zcad::ErrorStatus SignEntity::dwgOutFields (ZcDbDwgFiler *pFiler) const 
{
	assertReadEnabled () ;

	Zcad::ErrorStatus es =ZcDbEntity::dwgOutFields (pFiler) ;
	if ( es != Zcad::eOk )
		return (es) ;

	if ( (es =pFiler->writeUInt32 (SignEntity::kCurrentVersionNumber)) != Zcad::eOk )
		return (es) ;
	//----- Output params
	//.....
	pFiler->writePoint3d(m_pntCenter);
	pFiler->writeDouble(m_dblRadius);
	pFiler->writeString(m_strTextFirst);
	pFiler->writeString(m_strTextSecnd);

	return (pFiler->filerStatus ()) ;
}

Zcad::ErrorStatus SignEntity::dwgInFields (ZcDbDwgFiler *pFiler) 
{
	assertWriteEnabled () ;

	Zcad::ErrorStatus es =ZcDbEntity::dwgInFields (pFiler) ;
	if ( es != Zcad::eOk )
		return (es) ;

	Zdesk::UInt32 version =0 ;
	if ( (es =pFiler->readUInt32 (&version)) != Zcad::eOk )
		return (es) ;
	if ( version > SignEntity::kCurrentVersionNumber )
		return (Zcad::eMakeMeProxy) ;

	//if ( version < SignEntity::kCurrentVersionNumber )
	//	return (Zcad::eMakeMeProxy) ;

	//----- Read params
	//.....
	pFiler->readPoint3d(&m_pntCenter);
	pFiler->readDouble(&m_dblRadius);

	TCHAR* pStrTextFirst = NULL;
	pFiler->readString(&pStrTextFirst);
	m_strTextFirst = pStrTextFirst;
	zcutDelString(pStrTextFirst);

	TCHAR* pStrTextSecnd = NULL;
	pFiler->readString(&pStrTextSecnd);
	m_strTextSecnd = pStrTextSecnd;
	zcutDelString(pStrTextSecnd);

	return (pFiler->filerStatus ()) ;
}

//-----------------------------------------------------------------------------
//----- ZcDbEntity protocols
Zdesk::Boolean SignEntity::worldDraw (ZcGiWorldDraw *mode) 
{
	assertReadEnabled () ;

	mode->geometry().circle(m_pntCenter, m_dblRadius, ZcGeVector3d::kZAxis);
	ZcGePoint3dArray arrLinePnts;
	arrLinePnts.append(ZcGePoint3d(m_pntCenter.x-m_dblRadius, m_pntCenter.y, 0));
	arrLinePnts.append(ZcGePoint3d(m_pntCenter.x+m_dblRadius, m_pntCenter.y, 0));
	mode->geometry().polyline(2, arrLinePnts.asArrayPtr());

	ZcGePoint3d pntTextPos;
	double dblTextHeight = m_dblRadius/4.0;

	pntTextPos.set(m_pntCenter.x - m_dblRadius/2, m_pntCenter.y + m_dblRadius/4, 0);	
	mode->geometry().text(pntTextPos,ZcGeVector3d::kZAxis, ZcGeVector3d::kXAxis, dblTextHeight, 1.0, 0, m_strTextFirst);

	pntTextPos.set(m_pntCenter.x - m_dblRadius/2, m_pntCenter.y - m_dblRadius/2, 0);
	mode->geometry().text(pntTextPos,ZcGeVector3d::kZAxis, ZcGeVector3d::kXAxis, dblTextHeight, 1.5, 0, m_strTextSecnd);

	return Zdesk::kTrue;
}

//- Osnap points protocol
Zcad::ErrorStatus SignEntity::getOsnapPoints (
	ZcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const ZcGePoint3d &pickPoint,
	const ZcGePoint3d &lastPoint,
	const ZcGeMatrix3d &viewXform,
	ZcGePoint3dArray &snapPoints,
	ZcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
	return (ZcDbEntity::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds)) ;
}

Zcad::ErrorStatus SignEntity::getOsnapPoints (
	ZcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const ZcGePoint3d &pickPoint,
	const ZcGePoint3d &lastPoint,
	const ZcGeFastTransform &viewXform,
	ZcGePoint3dArray &snapPoints,
	ZcDbIntArray &geomIds) const
{
	assertReadEnabled () ;
	return (ZcDbEntity::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds)) ;
}

Zcad::ErrorStatus SignEntity::getOsnapPoints (
	ZcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const ZcGePoint3d &pickPoint,
	const ZcGePoint3d &lastPoint,
	const ZcGeMatrix3d &viewXform,
	ZcGePoint3dArray &snapPoints,
	ZcDbIntArray &geomIds,
	const ZcGeMatrix3d &insertionMat) const
{
	assertReadEnabled () ;
	return (ZcDbEntity::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat)) ;
}

Zcad::ErrorStatus SignEntity::getOsnapPoints (
	ZcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const ZcGePoint3d & pickPoint,
	const ZcGePoint3d & lastPoint,
	const ZcGeFastTransform & viewXform,
	ZcGePoint3dArray &snapPoints,
	ZcDbIntArray &geomIds,
	const ZcGeMatrix3d &insertionMat) const
{
	assertReadEnabled () ;

	if (osnapMode == ZcDb::kOsModeCen)
	{
		snapPoints.append(m_pntCenter);
	}

	return Zcad::eOk;	
}

//- Grip points protocol
Zcad::ErrorStatus SignEntity::getGripPoints (
	ZcGePoint3dArray &gripPoints, ZcDbIntArray &osnapModes, ZcDbIntArray &geomIds
	) const 
{
	assertReadEnabled () ;

	ZcGePoint3dArray arrGripPnt;
	arrGripPnt.append(m_pntCenter);
	arrGripPnt.append(ZcGePoint3d(m_pntCenter.x-m_dblRadius, m_pntCenter.y, 0));
	arrGripPnt.append(ZcGePoint3d(m_pntCenter.x+m_dblRadius, m_pntCenter.y, 0));
	arrGripPnt.append(ZcGePoint3d(m_pntCenter.x, m_pntCenter.y+m_dblRadius, 0));
	arrGripPnt.append(ZcGePoint3d(m_pntCenter.x, m_pntCenter.y-m_dblRadius, 0));

	gripPoints.append(arrGripPnt);

	return Zcad::eOk;
}

Zcad::ErrorStatus SignEntity::moveGripPointsAt (const ZcDbIntArray &indices, const ZcGeVector3d &offset) 
{
	assertWriteEnabled () ;

	for (int i = 0; i < indices.length(); i++)
	{
		switch (indices[i]) {
		case 0:
			m_pntCenter.transformBy(offset);
			break;
		case 1:
			m_dblRadius -= offset.x;
			break;
		case 2:
			m_dblRadius += offset.x;
			break;
		case 3:
			m_dblRadius += offset.y;
			break;
		case 4:
			m_dblRadius -= offset.y;
			break;
		}

	}

	return Zcad::eOk;
}

Zcad::ErrorStatus SignEntity::getGripPoints (
	ZcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
	const ZcGeVector3d &curViewDir, const int bitflags
	) const 
{
	assertReadEnabled () ;


	return (ZcDbEntity::getGripPoints (grips, curViewUnitSize, gripSize, curViewDir, bitflags)) ;
}

Zcad::ErrorStatus SignEntity::moveGripPointsAt (
	const ZcDbVoidPtrArray &gripAppData, const ZcGeVector3d &offset,
	const int bitflags
	) 
{
	assertWriteEnabled () ;


	return (ZcDbEntity::moveGripPointsAt (gripAppData, offset, bitflags)) ;
}

Zcad::ErrorStatus SignEntity::transformBy(const ZcGeMatrix3d& xform)
{
	assertWriteEnabled();

	m_pntCenter.transformBy(xform);

	return Zcad::eOk;
}

void SignEntity::getCenter(ZcGePoint3d& pntCenter)
{
	pntCenter = m_pntCenter;
}

void SignEntity::getRadius(double& dblRadius)
{
	dblRadius = m_dblRadius;
}

void SignEntity::setCenter(ZcGePoint3d pntCenter)
{
	m_pntCenter = pntCenter;
}

void SignEntity::setRadius(double dblRadius)
{
	m_dblRadius = dblRadius;
}

Zcad::ErrorStatus SignEntity::getClassID(CLSID* pClsid) const
{
	*pClsid=CLSID_SignEntityCom;
	return Zcad::eOk;

}
