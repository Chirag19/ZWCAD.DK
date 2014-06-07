#ifndef _ZCUTMIGR_H
#define _ZCUTMIGR_H


#include "zcutmem.h"

#pragma pack (push, 8)


inline Zcad::ErrorStatus newBuffer(char *&pOutput, size_t size)
{
	//[Added by Chinaweal Hongxiaofeng 2009/12/10
	// 增加判断 size 的有效性
	if (size <=0 )
	{
		return Zcad::eInvalidInput;
	}
	//]Added by Chinaweal Hongxiaofeng 2009/12/10

    return ::zcutNewBuffer(pOutput, size);
}

inline Zcad::ErrorStatus newString(const ZCHAR* pInput, ZCHAR*& pOutput)
{
    return ::zcutNewString(pInput, pOutput);
}

inline Zcad::ErrorStatus newString(ZCHAR*& pOutput, int nNumChars)
{
	//[Added by Chinaweal Hongxiaofeng 2009/12/10
	// 增加判断 size 的有效性
	if (nNumChars <=0 )
	{
		return Zcad::eInvalidInput;
	}
	//]Added by Chinaweal Hongxiaofeng 2009/12/10

    return ::zcutNewString(pOutput, nNumChars);
}

inline Zcad::ErrorStatus updString(const ZCHAR* pInput, ZCHAR*& pOutput)
{
    return ::zcutUpdString(pInput, pOutput);
}

inline void delString(ZCHAR*& pString)
{
    ::zcutDelString(pString);
}

inline void delBuffer(char*& pString)
{
    ::zcutDelString(pString);
}

#pragma pack (pop)
#endif 

