#ifndef ZD_DBHANDLE_H
#define ZD_DBHANDLE_H 1


#include "zdesk.h"

#pragma pack (push, 8)

class ZcDbHandle
{
public:

    ZcDbHandle();                
    ZcDbHandle(int lo, int hi);  
    ZcDbHandle(const ZCHAR*);
    ZcDbHandle(const Zdesk::UInt64 &);

    ZcDbHandle& operator=(const ZcDbHandle&);

    ZcDbHandle& operator=(const ZCHAR*);


    void getIntoAsciiBuffer(ZCHAR* pBuf) const;

    bool operator == (const ZcDbHandle&) const;
    bool operator != (const ZcDbHandle&) const;

    bool           isNull() const;
    void           setNull();

    Zdesk::UInt32  low() const;
    Zdesk::UInt32  high() const;
    void           setLow(Zdesk::UInt32 low);
    void           setHigh(Zdesk::UInt32 high);

    bool           isOne(void) const;


    ZcDbHandle& operator++();
    ZcDbHandle operator++(int);
    void increment(void);
    void decrement(void);
    ZcDbHandle operator + (const ZcDbHandle&) const;
    ZcDbHandle slowOperatorPlus(const ZcDbHandle&) const;
    ZcDbHandle& operator += (const ZcDbHandle&);
    ZcDbHandle operator - (const ZcDbHandle&) const;
    ZcDbHandle& operator -= (const ZcDbHandle&);
    bool operator > (const ZcDbHandle&) const;
    bool operator >= (const ZcDbHandle&) const;
    bool operator < (const ZcDbHandle&) const;
    bool operator <= (const ZcDbHandle&) const;
    int compare(const ZcDbHandle&) const;
    void copyToOldType(Zdesk::UInt8 hand[8]) const;
    void copyFromOldType(const Zdesk::UInt8 hand[8]);
    void getValueBytes(Zdesk::UInt8*, Zdesk::UInt8*) const;
    void setValueBytes(Zdesk::UInt8, const Zdesk::UInt8*);
    ZcDbHandle& operator=(Zdesk::UInt32);
    operator Zdesk::UInt32() const;
    ZcDbHandle operator + (Zdesk::ULongPtr) const;
    void print() const;
    enum { kMaxValueBytes = 8 };
    int byte(Zdesk::UInt32 i) const;
    int restZeros(int i) const;
private:
    Zdesk::UInt64 & get64BitVal()
          { return *reinterpret_cast<Zdesk::UInt64 *>(&mLow); }
    const Zdesk::UInt64 & get64BitVal() const
          { return *reinterpret_cast<const Zdesk::UInt64 *>(&mLow); }

    Zdesk::UInt32 mLow;
    Zdesk::UInt32 mHigh;
    friend class ZcDbHandleTable;
    friend class ZHandleDataBase;
};


const Zdesk::UInt32 zBadUInt32Handle = 0xFFFFFFFF;


#pragma pack (pop)

#endif
