#ifndef _ZCUTMEM_H
#define _ZCUTMEM_H

#include "zcadstrc.h"
#include "ZdZChar.h"
#include <string.h>

#pragma pack (push, 8)

Zcad::ErrorStatus zcutNewBuffer(void *&pOutput, size_t size);
Zcad::ErrorStatus zcutNewString(ZCHAR *&pOutput, int nNumChars);
Zcad::ErrorStatus zcutNewString(const ZCHAR* pInput, ZCHAR*& pOutput);
Zcad::ErrorStatus zcutUpdString(const ZCHAR* pInput, ZCHAR*& pOutput);
void zcutDelBuffer(void *& pBuffer);

inline Zcad::ErrorStatus zcutNewBuffer(char *&pOutput, size_t size)
{
    return ::zcutNewBuffer((void * &)pOutput, size);
}

inline void zcutDelBuffer(char *& pString)
{
    ::zcutDelBuffer((void * &)pString);
}

inline void zcutDelString(char *& pString)
{
	if (pString == NULL)
	{
		return;
	}
	
	if (strcmp(pString, "") == 0)
	{
		pString = NULL;
		return;
	}
    ::zcutDelBuffer((void * &)pString);
}

#ifdef UNICODE
inline void zcutDelString(wchar_t *& pString)
{
    ::zcutDelBuffer((void * &)pString);
}
#endif

#pragma pack (pop)
#endif