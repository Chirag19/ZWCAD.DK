#ifndef ZC_GEFILER_H
#define ZC_GEFILER_H
     
#include "ZdZChar.h"
#include "ZcString.h"
#include "zgegbl.h"
#include "zcdb.h"
#pragma pack (push, 8)
     
     
class ZcDbDwgFiler;
     
class 
GE_DLLEXPIMPORT ZDESK_NO_VTABLE
ZcGeFiler
{
protected:
    ZcGeFiler();
public:
    virtual
    Zcad::ErrorStatus      readBoolean(Zdesk::Boolean*) = 0; 
    virtual
    Zcad::ErrorStatus      writeBoolean(Zdesk::Boolean) = 0;

    virtual
    Zcad::ErrorStatus      readBool(bool*) = 0; 
    virtual
    Zcad::ErrorStatus      writeBool(bool) = 0;

    virtual
    Zcad::ErrorStatus      readSignedByte(char *) = 0; 
    virtual
    Zcad::ErrorStatus      writeSignedByte(char) = 0;
     
    virtual
    Zcad::ErrorStatus      readString(ZcString &) = 0; 
    virtual
    Zcad::ErrorStatus      writeString(const ZcString &) = 0;
     
    virtual
    Zcad::ErrorStatus      readShort(short*) = 0; 
    virtual
    Zcad::ErrorStatus      writeShort(short) = 0;
     
    virtual
    Zcad::ErrorStatus      readLong(long*) = 0; 
    virtual
    Zcad::ErrorStatus      writeLong(long) = 0;
     
    virtual
    Zcad::ErrorStatus      readUChar(unsigned char*) = 0; 
    virtual
    Zcad::ErrorStatus      writeUChar(unsigned char) = 0;
     
    virtual
    Zcad::ErrorStatus      readUShort(unsigned short*) = 0; 
    virtual
    Zcad::ErrorStatus      writeUShort(unsigned short) = 0;
     
    virtual
    Zcad::ErrorStatus      readULong(unsigned long*) = 0; 
    virtual
    Zcad::ErrorStatus      writeULong(unsigned long) = 0;
          
    virtual
    Zcad::ErrorStatus      readDouble(double*) = 0; 
    virtual
    Zcad::ErrorStatus      writeDouble(double) = 0;
     
    virtual
    Zcad::ErrorStatus      readPoint2d(ZcGePoint2d*) = 0; 
    virtual
    Zcad::ErrorStatus      writePoint2d(const ZcGePoint2d&) = 0;
     
    virtual
    Zcad::ErrorStatus      readPoint3d(ZcGePoint3d*) = 0; 
    virtual
    Zcad::ErrorStatus      writePoint3d(const ZcGePoint3d&) = 0;
     
    virtual
    Zcad::ErrorStatus      readVector2d(ZcGeVector2d*) = 0; 
    virtual
    Zcad::ErrorStatus      writeVector2d(const ZcGeVector2d&) = 0;
     
    virtual
    Zcad::ErrorStatus      readVector3d(ZcGeVector3d*) = 0; 
    virtual
    Zcad::ErrorStatus      writeVector3d(const ZcGeVector3d&) = 0;
     
    virtual
    ZcDbDwgFiler*          dwgFiler();

    virtual
    Zcad::ErrorStatus      readBytes(void*, unsigned long) = 0;
    virtual
    Zcad::ErrorStatus      writeBytes(const void*, unsigned long) = 0;
};

     
     
#pragma pack (pop)
#endif
