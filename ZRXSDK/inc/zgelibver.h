#ifndef ZC_GELIBVERSION_H
#define ZC_GELIBVERSION_H

#include "Zdesk.h"
#include "zgedll.h"
#pragma pack (push, 8)

#define IMAGE_MAJOR_VER          2
#define IMAGE_MINOR_VER          0
#define IMAGE_CORRECTIVE_VER     0
#define IMAGE_INTERNAL_VER       0

class 
GE_DLLEXPIMPORT
ZcGeLibVersion {
public:
    ZcGeLibVersion();
    ZcGeLibVersion(const ZcGeLibVersion&);
    ZcGeLibVersion(Zdesk::UInt8 major, Zdesk::UInt8 minor,
                   Zdesk::UInt8 corrective,
                   Zdesk::UInt8 internal_version);

    Zdesk::UInt8     majorVersion        () const; 
    Zdesk::UInt8     minorVersion        () const; 
    Zdesk::UInt8     correctiveVersion   () const; 
    Zdesk::UInt8     schemaVersion       () const;

    ZcGeLibVersion&     setMajorVersion        (Zdesk::UInt8 val); 
    ZcGeLibVersion&     setMinorVersion        (Zdesk::UInt8 val); 
    ZcGeLibVersion&     setCorrectiveVersion   (Zdesk::UInt8 val); 
    ZcGeLibVersion&     setSchemaVersion       (Zdesk::UInt8 val);

    Zdesk::Boolean operator ==      (const ZcGeLibVersion&) const; 
    Zdesk::Boolean operator !=      (const ZcGeLibVersion&) const; 
    Zdesk::Boolean operator <       (const ZcGeLibVersion&) const; 
    Zdesk::Boolean operator <=      (const ZcGeLibVersion&) const; 
    Zdesk::Boolean operator >       (const ZcGeLibVersion&) const; 
    Zdesk::Boolean operator >=      (const ZcGeLibVersion&) const;

    static const ZcGeLibVersion kRelease0_95;

    static const ZcGeLibVersion kReleaseSed;

    static const ZcGeLibVersion kReleaseTah;

private:
    Zdesk::UInt8   mVersion[10];
};

#pragma pack (pop)
#endif
