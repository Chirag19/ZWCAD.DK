
#ifndef _ZD_DBID_H
#define _ZD_DBID_H 1

#ifdef  _ZRX_SUPPORT_
#define DBIDEXPIMP __declspec(dllexport)
#else
#define DBIDEXPIMP  __declspec(dllimport)
#endif


#include "zdesk.h"
#include "zdbhandle.h"

#pragma pack(push, 8)

class ZcDbDatabase;
class ZcDbStub;

class  DBIDEXPIMP ZcDbObjectId 
{
public:
    ZcDbObjectId();
    ZcDbObjectId(const ZcDbStub*);

    static const   ZcDbObjectId  kNull;

    bool           isNull() const;
    void           setNull();

    Zdesk::IntDbId     asOldId     () const;
    ZcDbObjectId&  setFromOldId(Zdesk::IntDbId oldId);
#ifdef _WIN64
  private:
    ZcDbObjectId&  setFromOldId(long);

  public:

    inline ZcDbObjectId&  setFromOldId(Zdesk::UIntPtr nUnsignedId)
    {
        const Zdesk::IntDbId nSignedId =
                        static_cast<Zdesk::IntDbId>(nUnsignedId);
        return this->setFromOldId(nSignedId);
    }
#endif

    bool           isValid() const;

    ZcDbObjectId&  operator =  (const ZcDbObjectId&);
    ZcDbObjectId&  operator =  (const ZcDbStub*);

    bool           operator <  (const ZcDbObjectId&) const;
    bool           operator >  (const ZcDbObjectId&) const;
    bool           operator >= (const ZcDbObjectId&) const;
    bool           operator <= (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbObjectId&) const;

    bool           operator <  (const ZcDbStub*) const;
    bool           operator >  (const ZcDbStub*) const;
    bool           operator >= (const ZcDbStub*) const;
    bool           operator <= (const ZcDbStub*) const;
    bool           operator == (const ZcDbStub*) const;
    bool           operator != (const ZcDbStub*) const;

    operator       ZcDbStub*   () const;

    ZcDbDatabase* database() const;
    ZcDbDatabase* originalDatabase() const;
    void          convertToRedirectedId();
    bool          isErased() const;
    bool          isEffectivelyErased() const;
    bool          isResident() const;
    bool          objectLeftOnDisk() const;
    ZcDbHandle    handle() const;
    ZcDbHandle    nonForwardedHandle() const;

protected:
    ZcDbStub*  mId;
};

class ZcDbHardOwnershipId : public ZcDbObjectId
{
public:
    ZcDbHardOwnershipId();
    ZcDbHardOwnershipId(const ZcDbObjectId&);
    ZcDbHardOwnershipId(const ZcDbStub*);

    ZcDbHardOwnershipId& operator =(const ZcDbHardOwnershipId&);
    ZcDbHardOwnershipId& operator =(const ZcDbObjectId&);
    ZcDbHardOwnershipId& operator =(const ZcDbStub*);

    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

class ZcDbSoftOwnershipId : public ZcDbObjectId
{
public:
    ZcDbSoftOwnershipId();
    ZcDbSoftOwnershipId(const ZcDbObjectId&);
    ZcDbSoftOwnershipId(const ZcDbStub*);

    ZcDbSoftOwnershipId& operator =(const ZcDbSoftOwnershipId&);
    ZcDbSoftOwnershipId& operator =(const ZcDbObjectId&);
    ZcDbSoftOwnershipId& operator =(const ZcDbStub*);
    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

class ZcDbHardPointerId : public ZcDbObjectId
{
public:
    ZcDbHardPointerId();
    ZcDbHardPointerId(const ZcDbObjectId&);
    ZcDbHardPointerId(const ZcDbStub*);

    ZcDbHardPointerId& operator =(const ZcDbHardPointerId&);
    ZcDbHardPointerId& operator =(const ZcDbObjectId&);
    ZcDbHardPointerId& operator =(const ZcDbStub*);
    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

class ZcDbSoftPointerId : public ZcDbObjectId
{
public:
    ZcDbSoftPointerId();
    ZcDbSoftPointerId(const ZcDbObjectId&);
    ZcDbSoftPointerId(const ZcDbStub*);

    ZcDbSoftPointerId& operator =(const ZcDbSoftPointerId&);
    ZcDbSoftPointerId& operator =(const ZcDbObjectId&);
    ZcDbSoftPointerId& operator =(const ZcDbStub*);
    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};


#pragma pack(pop)

#endif
