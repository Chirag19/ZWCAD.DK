
#pragma once

#define ZD_UNICODE 1
#if defined(__cplusplus) && !defined(_NATIVE_WCHAR_T_DEFINED)
#endif

#ifdef UNICODE
typedef wchar_t ZCHAR;
#else
typedef char    ZCHAR;
#endif 

#ifdef UNICODE
#define _ZCRX_T(x)      L ## x
#else
#define _ZCRX_T(x)      x
#endif

#define ZCRX_T(x)      _ZCRX_T(x)

