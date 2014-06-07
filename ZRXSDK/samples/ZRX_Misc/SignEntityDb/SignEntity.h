//----- SignEntity.h : Declaration of the SignEntity

#pragma once

#ifdef SIGNENTITY_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

//-----------------------------------------------------------------------------
#include "zdbmain.h"

//-----------------------------------------------------------------------------
class DLLIMPEXP SignEntity : public ZcDbEntity {

public:
	ZCRX_DECLARE_MEMBERS(SignEntity) ;

protected:
	static Zdesk::UInt32 kCurrentVersionNumber ;

public:
	SignEntity () ;
	virtual ~SignEntity () ;

	//----- ZcDbObject protocols
	//- Dwg Filing protocol
	virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler *pFiler) const ;
	virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler *pFiler) ;
	virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler *pFiler) const ;
	virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler *pFiler) ;

	//----- ZcDbEntity protocols
	//- Graphics protocol
	virtual Zdesk::Boolean worldDraw (ZcGiWorldDraw *mode) ;

	//- Osnap points protocol
	virtual Zcad::ErrorStatus getOsnapPoints (
		ZcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const ZcGePoint3d &pickPoint,
		const ZcGePoint3d &lastPoint,
		const ZcGeMatrix3d &viewXform,
		ZcGePoint3dArray &snapPoints,
		ZcDbIntArray &geomIds) const ;
	virtual Zcad::ErrorStatus getOsnapPoints (
		ZcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const ZcGePoint3d &pickPoint,
		const ZcGePoint3d &lastPoint,
		const ZcGeFastTransform &viewXform,
		ZcGePoint3dArray &snapPoints,
		ZcDbIntArray &geomIds) const ;
	virtual Zcad::ErrorStatus getOsnapPoints (
		ZcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const ZcGePoint3d &pickPoint,
		const ZcGePoint3d &lastPoint,
		const ZcGeMatrix3d &viewXform,
		ZcGePoint3dArray &snapPoints,
		ZcDbIntArray &geomIds,
		const ZcGeMatrix3d &insertionMat) const ;
	virtual Zcad::ErrorStatus getOsnapPoints (
		ZcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const ZcGePoint3d &pickPoint,
		const ZcGePoint3d &lastPoint,
		const ZcGeFastTransform &viewXform,
		ZcGePoint3dArray &snapPoints,
		ZcDbIntArray &geomIds,
		const ZcGeMatrix3d &insertionMat) const ;

	//- Grip points protocol
	virtual Zcad::ErrorStatus getGripPoints (ZcGePoint3dArray &gripPoints, ZcDbIntArray &osnapModes, ZcDbIntArray &geomIds) const ;
	virtual Zcad::ErrorStatus moveGripPointsAt (const ZcDbIntArray &indices, const ZcGeVector3d &offset) ;
	virtual Zcad::ErrorStatus getGripPoints (
		ZcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, 
		const ZcGeVector3d &curViewDir, const int bitflags) const ;
	virtual Zcad::ErrorStatus moveGripPointsAt (const ZcDbVoidPtrArray &gripAppData, const ZcGeVector3d &offset, const int bitflags) ;
	virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus getClassID (CLSID *pClsid) const ;


public:
	void getCenter(ZcGePoint3d& pntCenter);
	void getRadius(double& dblRadius);

	void setCenter(ZcGePoint3d pntCenter);
	void setRadius(double dblRadius);

private:
	ZcGePoint3d m_pntCenter;
	double m_dblRadius;

	CString m_strTextFirst;
	CString m_strTextSecnd;

} ;

#ifdef SIGNENTITY_MODULE
ZCDB_REGISTER_OBJECT_ENTRY_AUTO(SignEntity)
#endif
