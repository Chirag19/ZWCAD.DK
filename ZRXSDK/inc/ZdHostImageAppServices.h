
#pragma once

#include "ZdZChar.h"

namespace Atil {
    class ImageFormatCodec;
    class ProgressCallbackInterface;
};

class ZdHostImageAppServices;

class __declspec(novtable) ZdHostImageAppServices
{
public:

    virtual const ZCHAR* imageFileExtensions (bool bRefresh = false) = 0;

    virtual const ZCHAR* imageFilterString (bool bRefresh = false) = 0;

    virtual bool registerFormatCodec (Atil::ImageFormatCodec& codec) = 0;

    virtual bool formatCodecRegistered (Atil::ImageFormatCodec& codec) = 0;

    virtual bool reRegisterFormatCodec (Atil::ImageFormatCodec& codec) = 0;

    virtual bool unRegisterFormatCodec (Atil::ImageFormatCodec& codec) = 0;

    virtual Atil::ProgressCallbackInterface* registerProgressCallback (Atil::ProgressCallbackInterface* pCallback ) = 0;
};

ZdHostImageAppServices* getZdHostImageAppServices();
