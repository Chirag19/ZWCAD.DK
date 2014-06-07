
#ifndef ZD_DBFILER_H
#define ZD_DBFILER_H


#include <stdarg.h>
#include "ZdZChar.h"
#include "zcdb.h"
#include "zgepnt2d.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zgescl3d.h"
#include "zdsdef.h"

#pragma pack (push, 8)

class ZcDbAuditInfo;
class ZcDbFilerController;
class ZcDbHandle;
class ZcDbIdRefQueue;
class ZcString;


class ZDESK_NO_VTABLE ZcDbDwgFiler: public ZcRxObject
{
  public:
    ZCRX_DECLARE_MEMBERS(ZcDbDwgFiler);
    ZcDbDwgFiler();
    virtual ~ZcDbDwgFiler();

    virtual  Zcad::ErrorStatus filerStatus() const = 0;
    virtual  ZcDb::FilerType   filerType() const = 0;
    virtual void               setFilerStatus(Zcad::ErrorStatus) = 0;
    virtual void               resetFilerStatus() = 0;



    virtual  Zcad::ErrorStatus  dwgVersion(ZcDb::ZcDbDwgVersion &,
                                ZcDb::MaintenanceReleaseVersion &) const;

    virtual Zcad::ErrorStatus   readHardOwnershipId(ZcDbHardOwnershipId*) = 0;
    virtual Zcad::ErrorStatus   writeHardOwnershipId(
                                  const ZcDbHardOwnershipId&) = 0;

    virtual Zcad::ErrorStatus   readSoftOwnershipId(ZcDbSoftOwnershipId*) = 0;
    virtual Zcad::ErrorStatus   writeSoftOwnershipId(
                                  const ZcDbSoftOwnershipId&) = 0;

    virtual Zcad::ErrorStatus   readHardPointerId(ZcDbHardPointerId*) = 0;
    virtual Zcad::ErrorStatus   writeHardPointerId(const ZcDbHardPointerId&) = 0;

    virtual Zcad::ErrorStatus   readSoftPointerId(ZcDbSoftPointerId*) = 0;
    virtual Zcad::ErrorStatus   writeSoftPointerId(const ZcDbSoftPointerId&) = 0;

    virtual Zcad::ErrorStatus   readInt8(Zdesk::Int8 *) = 0;
    virtual Zcad::ErrorStatus   writeInt8(Zdesk::Int8 ) = 0;

    inline  Zcad::ErrorStatus   readChar(Zdesk::Int8 *p);
    inline  Zcad::ErrorStatus   writeChar(Zdesk::Int8 c); 

    virtual Zcad::ErrorStatus   readString(ZCHAR **) = 0;
    virtual Zcad::ErrorStatus   writeString(const ZCHAR *) = 0;

    virtual Zcad::ErrorStatus   readString(ZcString &) = 0;
    virtual Zcad::ErrorStatus   writeString(const ZcString &) = 0;

    virtual Zcad::ErrorStatus   readBChunk(zds_binary *) = 0;
    virtual Zcad::ErrorStatus   writeBChunk(const zds_binary&) = 0;

    virtual Zcad::ErrorStatus   readZcDbHandle(ZcDbHandle*) = 0;
    virtual Zcad::ErrorStatus   writeZcDbHandle(const ZcDbHandle&) = 0;

    virtual Zcad::ErrorStatus   readInt32(Zdesk::Int32*) = 0;
    virtual Zcad::ErrorStatus   writeInt32(Zdesk::Int32) = 0;

    virtual Zcad::ErrorStatus   readInt16(Zdesk::Int16*) = 0;
    virtual Zcad::ErrorStatus   writeInt16(Zdesk::Int16) = 0;

    virtual Zcad::ErrorStatus   readUInt32(Zdesk::UInt32*) = 0;
    virtual Zcad::ErrorStatus   writeUInt32(Zdesk::UInt32) = 0;

    virtual Zcad::ErrorStatus   readUInt16(Zdesk::UInt16*) = 0;
    virtual Zcad::ErrorStatus   writeUInt16(Zdesk::UInt16) = 0;

    virtual Zcad::ErrorStatus   readUInt8(Zdesk::UInt8*) = 0;
    virtual Zcad::ErrorStatus   writeUInt8(Zdesk::UInt8) = 0;

#ifdef Zdesk_Boolean_is_bool
    virtual Zcad::ErrorStatus   readInt(int*) = 0;
    virtual Zcad::ErrorStatus   writeInt(int) = 0;
#endif

    virtual Zcad::ErrorStatus   readBoolean(Zdesk::Boolean*) = 0;
    virtual Zcad::ErrorStatus   writeBoolean(Zdesk::Boolean) = 0;

    virtual Zcad::ErrorStatus   readBool(bool*) = 0;
    virtual Zcad::ErrorStatus   writeBool(bool) = 0;

    virtual Zcad::ErrorStatus   readDouble(double*) = 0;
    virtual Zcad::ErrorStatus   writeDouble(double) = 0;

    virtual Zcad::ErrorStatus   readPoint2d(ZcGePoint2d*) = 0;
    virtual Zcad::ErrorStatus   writePoint2d(const ZcGePoint2d&) = 0;

    virtual Zcad::ErrorStatus   readPoint3d(ZcGePoint3d*) = 0;
    virtual Zcad::ErrorStatus   writePoint3d(const ZcGePoint3d&) = 0;

    virtual Zcad::ErrorStatus   readVector2d(ZcGeVector2d*) = 0;
    virtual Zcad::ErrorStatus   writeVector2d(const ZcGeVector2d&) = 0;

    virtual Zcad::ErrorStatus   readVector3d(ZcGeVector3d*) = 0;
    virtual Zcad::ErrorStatus   writeVector3d(const ZcGeVector3d&) = 0;

    virtual Zcad::ErrorStatus   readScale3d(ZcGeScale3d*) = 0;
    virtual Zcad::ErrorStatus   writeScale3d(const ZcGeScale3d&) = 0;

    virtual Zcad::ErrorStatus   readBytes(void *, Zdesk::UInt32) = 0;
    virtual Zcad::ErrorStatus   writeBytes(const void *, Zdesk::UInt32) = 0;

    virtual Zcad::ErrorStatus   readAddress(void **);
    virtual Zcad::ErrorStatus   writeAddress(const void *);

	Zcad::ErrorStatus   readItem(ZcDbHardOwnershipId*);
	Zcad::ErrorStatus   writeItem(const ZcDbHardOwnershipId&);

	Zcad::ErrorStatus   readItem(ZcDbSoftOwnershipId*);
	Zcad::ErrorStatus   writeItem(const ZcDbSoftOwnershipId&);

	Zcad::ErrorStatus   readItem(ZcDbHardPointerId*);
	Zcad::ErrorStatus   writeItem(const ZcDbHardPointerId&);

	Zcad::ErrorStatus   readItem(ZcDbSoftPointerId*);
	Zcad::ErrorStatus   writeItem(const ZcDbSoftPointerId&);


	Zcad::ErrorStatus   readItem(ZCHAR **);
	Zcad::ErrorStatus   writeItem(const ZCHAR *);

	Zcad::ErrorStatus   readItem(zds_binary*);
	Zcad::ErrorStatus   writeItem(const zds_binary&);

	Zcad::ErrorStatus   readItem(ZcDbHandle*);
	Zcad::ErrorStatus   writeItem(const ZcDbHandle&);

	Zcad::ErrorStatus   readItem(Zdesk::Int32*);
	Zcad::ErrorStatus   writeItem(Zdesk::Int32);

	Zcad::ErrorStatus   readItem(Zdesk::Int16*);
	Zcad::ErrorStatus   writeItem(Zdesk::Int16);

	Zcad::ErrorStatus   readItem(Zdesk::Int8 *);
	Zcad::ErrorStatus   writeItem(Zdesk::Int8);

	Zcad::ErrorStatus   readItem(Zdesk::UInt32*);
	Zcad::ErrorStatus   writeItem(Zdesk::UInt32);

	Zcad::ErrorStatus   readItem(Zdesk::UInt16*);
	Zcad::ErrorStatus   writeItem(Zdesk::UInt16);

	Zcad::ErrorStatus   readItem(Zdesk::UInt8*);
	Zcad::ErrorStatus   writeItem(Zdesk::UInt8);

#ifdef Zdesk_Boolean_is_bool
	Zcad::ErrorStatus   readItem(int*);
	Zcad::ErrorStatus   writeItem(int);
#else
	Zcad::ErrorStatus   readItem(Zdesk::Boolean*);
	Zcad::ErrorStatus   writeItem(Zdesk::Boolean);
#endif

	Zcad::ErrorStatus   readItem(bool*);
	Zcad::ErrorStatus   writeItem(bool);

	Zcad::ErrorStatus   readItem(double*);
	Zcad::ErrorStatus   writeItem(double);

	Zcad::ErrorStatus   readItem(ZcGePoint2d*);
	Zcad::ErrorStatus   writeItem(const ZcGePoint2d&);

	Zcad::ErrorStatus   readItem(ZcGePoint3d*);
	Zcad::ErrorStatus   writeItem(const ZcGePoint3d&);

	Zcad::ErrorStatus   readItem(ZcGeVector2d*);
	Zcad::ErrorStatus   writeItem(const ZcGeVector2d&);

	Zcad::ErrorStatus   readItem(ZcGeVector3d*);
	Zcad::ErrorStatus   writeItem(const ZcGeVector3d&);

	Zcad::ErrorStatus   readItem(ZcGeScale3d*);
	Zcad::ErrorStatus   writeItem(const ZcGeScale3d&);

	Zcad::ErrorStatus   readItem(void *, Zdesk::UInt32);
	Zcad::ErrorStatus   writeItem(const void *, Zdesk::UInt32);

	Zcad::ErrorStatus   readItem(void **);
	Zcad::ErrorStatus   writeItem(const void *);


	virtual Zcad::ErrorStatus   seek(long offset, int method) = 0;
	virtual              long   tell() const = 0;
	virtual Zcad::ErrorStatus   addReferences(ZcDbIdRefQueue& /*qToAbsorb*/);
	virtual              bool   usesReferences() const;
	virtual ZcDbAuditInfo *     getAuditInfo() const;

    virtual ZcDbFilerController& controller() const;

private:
    ZcDbFilerController& mController;


public:
	static ZcDbFilerController s_filerController;
	void*						mpImpDwgFiler;	
	mutable Zcad::ErrorStatus	m_FilerStatus;

};

class ZDESK_NO_VTABLE ZcDbDxfFiler: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDxfFiler);

    virtual int               rewindFiler() = 0;

    virtual Zcad::ErrorStatus filerStatus() const = 0;
    virtual void              resetFilerStatus() = 0;

    virtual Zcad::ErrorStatus setError(Zcad::ErrorStatus, const ZCHAR *, ...);
    virtual Zcad::ErrorStatus setError(const ZCHAR *, ...);
    virtual const ZCHAR * errorMessage() const;

    virtual  ZcDb::FilerType filerType() const = 0;


    virtual  ZcDbDatabase*      database() const = 0;



    virtual  Zcad::ErrorStatus  dwgVersion(ZcDb::ZcDbDwgVersion &,
                                ZcDb::MaintenanceReleaseVersion &) const;

    virtual int                 precision() const;
    virtual void                setPrecision(int prec);


    enum { kDfltPrec = -1, kMaxPrec  = 16 };


    virtual Zcad::ErrorStatus readResBuf   (resbuf*);
    virtual Zcad::ErrorStatus writeResBuf  (const resbuf&);
    virtual Zcad::ErrorStatus writeObjectId(ZcDb::DxfCode,
                                            const ZcDbObjectId&) = 0;
    virtual Zcad::ErrorStatus writeInt8    (ZcDb::DxfCode, Zdesk::Int8) = 0;


    inline  Zcad::ErrorStatus writeChar    (ZcDb::DxfCode c, Zdesk::Int8 n);

    virtual Zcad::ErrorStatus writeString  (ZcDb::DxfCode, const ZCHAR *) = 0;
    virtual Zcad::ErrorStatus writeString  (ZcDb::DxfCode, const ZcString &) = 0;
    virtual Zcad::ErrorStatus writeBChunk  (ZcDb::DxfCode, const zds_binary&) = 0;
    virtual Zcad::ErrorStatus writeZcDbHandle(ZcDb::DxfCode,
                                              const ZcDbHandle&) = 0;
    virtual Zcad::ErrorStatus writeInt32   (ZcDb::DxfCode, Zdesk::Int32) = 0;
    virtual Zcad::ErrorStatus writeInt16   (ZcDb::DxfCode, Zdesk::Int16) = 0;
    virtual Zcad::ErrorStatus writeUInt32  (ZcDb::DxfCode, Zdesk::UInt32) = 0;
    virtual Zcad::ErrorStatus writeUInt16  (ZcDb::DxfCode, Zdesk::UInt16) = 0;
    virtual Zcad::ErrorStatus writeUInt8   (ZcDb::DxfCode, Zdesk::UInt8) = 0;
    virtual Zcad::ErrorStatus writeBoolean (ZcDb::DxfCode, Zdesk::Boolean) = 0;
#ifdef Zdesk_Boolean_is_bool
    virtual Zcad::ErrorStatus writeInt     (ZcDb::DxfCode, int) = 0;
#endif
    virtual Zcad::ErrorStatus writeBool    (ZcDb::DxfCode, bool) = 0;
    virtual Zcad::ErrorStatus writeDouble  (ZcDb::DxfCode, double,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writePoint2d (ZcDb::DxfCode, const ZcGePoint2d&,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writePoint3d (ZcDb::DxfCode, const ZcGePoint3d&,
                                               int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writeVector2d(ZcDb::DxfCode, const ZcGeVector2d&,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writeVector3d(ZcDb::DxfCode, const ZcGeVector3d&,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writeScale3d (ZcDb::DxfCode, const ZcGeScale3d&,
                                            int = kDfltPrec) = 0;


    Zcad::ErrorStatus readItem        (resbuf* pItem);
    Zcad::ErrorStatus writeItem (const resbuf& pItem);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcDbObjectId&);

    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZCHAR *);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const zds_binary&);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcDbHandle&);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::Int32);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::Int16);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::Int8);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::UInt32);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::UInt16);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::UInt8);
#ifdef Zdesk_Boolean_is_bool
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, int);
#else
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, Zdesk::Boolean);
#endif
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, bool);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, double, int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGePoint2d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGePoint3d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGeVector2d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGeVector3d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGeScale3d&,
                                 int = kDfltPrec);

    virtual Zcad::ErrorStatus writeXDataStart ();
    virtual bool              includesDefaultValues() const = 0;

    virtual Zcad::ErrorStatus pushBackItem();
    virtual bool              atEOF();
    virtual bool              atSubclassData(const ZCHAR *);
    virtual bool              atExtendedData();
    virtual bool              atEndOfObject();
    virtual void              haltAtClassBoundries(bool);

    virtual Zcad::ErrorStatus writeEmbeddedObjectStart();
    virtual bool              atEmbeddedObjectStart();

    virtual double elevation() const;
    virtual double thickness() const;

    virtual bool isModifyingExistingObject() const;

    ZcDbDxfFiler();
    virtual ~ZcDbDxfFiler();
    ZcDbFilerController& controller() const;

private:
    ZcDbFilerController& mController;
    virtual Zcad::ErrorStatus setVAError(Zcad::ErrorStatus, const ZCHAR *,
                                         va_list);
};




#pragma pack (pop)

#endif