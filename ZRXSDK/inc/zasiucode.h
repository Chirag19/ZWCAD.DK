
#ifndef ZASI_ASIUCODE_H
#define ZASI_ASIUCODE_H zasiucodeh

#include <zasisys.h>


#ifndef _MSUC_
#define _MSUC_
#endif  


#define LC_ASCII      0xffffffff

#define ASI_ASCII_CODEPAGE  1252


#define ASI_UNSUPPORTED_CODEPAGE_ID 0xFFFFFFFE

#define ASI_UNSUPPORTED_LOCALE_ID   0xFFFFFFFE

typedef wchar_t             ZsiUcChar;
typedef ZsiUcChar*          ZsiUcStr;
typedef const ZsiUcChar*    ZsiCUcStr;
typedef unsigned long       ZsiUcIdCCT;   
typedef const char*         ZsiUcNmCCT;   
typedef unsigned long       ZsiUcIdCLT;   
                                          
typedef const char*         ZsiUcNmCLT;   

#pragma pack (push, 8)
#if defined(__cplusplus)

class DLLScope ZAsiUcStr;
class DLLScope ZAsiUcChar;

class ZAsiUcStr
{
public:

    ZAsiUcStr();                        
    ZAsiUcStr(const char*,ZsiUcNmCCT);
    ZAsiUcStr(const char*,ZsiUcIdCCT);  
    ZAsiUcStr(const char*);             
    ZAsiUcStr(ZsiCUcStr);              
    ZAsiUcStr(const ZAsiUcStr&);      
    ZAsiUcStr(const ZAsiUcStr*);        

   ~ZAsiUcStr();

    void		   Clear(void);                
    const		   ZsiUcStr UcStr(void) const; 
    int            Size(void) const;     
    int            Length(void) const;   
    int            Chlen(void) const;
    int            Chlen(ZsiUcNmCCT) const;
    int            Chlen(ZsiUcIdCCT) const;
    int            MultibyteLen() const;
    int            MultibyteLen(ZsiUcNmCCT) const;
    int            MultibyteLen(ZsiUcIdCCT) const;
    int            ChlenChk(void) const;
    int            ChlenChk(ZsiUcNmCCT) const;
    int            ChlenChk(ZsiUcIdCCT) const;
    void           Update(int,int);
    void           Update(int,int,ZsiUcNmCCT);
    void           Update(int,int,ZsiUcIdCCT);
    void           Update(int,ZsiUcChar);
    void           Update(int,const ZAsiUcChar&);
    void           Update(int,const ZAsiUcChar*);
    void           toLower(void);        
    void           toUpper(void);        

    double         Atof(void) const;
    int            Atoi(void) const;
    long           Atol(void) const;
    double         Strtod(int*) const;
    long           Strtol(int*,int) const;
    int            Sprintf(const ZsiUcStr,...);

    char*          getToChar(char*,int) const;
    char*          getToChar(char*,int,ZsiUcNmCCT) const;
    char*          getToChar(char*,int,ZsiUcIdCCT) const;
    wchar_t*       getToChar(wchar_t*,int) const;
    wchar_t*       getToChar(wchar_t*,int,ZsiUcNmCCT) const;
    wchar_t*       getToChar(wchar_t*,int,ZsiUcIdCCT) const;
    char*          getToCharChk(char*,int) const;
    char*          getToCharChk(char*,int,ZsiUcNmCCT) const;
    char*          getToCharChk(char*,int,ZsiUcIdCCT) const;
    ZsiUcStr       getToUcChar(ZsiUcStr,int) const;

    void           Append(const char*);
    void           Append(const char*,ZsiUcNmCCT);
    void           Append(const char*,ZsiUcIdCCT);
    void           Append(const wchar_t*,ZsiUcNmCCT);
    void           Append(const wchar_t*,ZsiUcIdCCT);
    void           Append(const ZsiUcStr);
    void           Append(const ZAsiUcStr&);
    void           Append(const ZAsiUcStr*);
    void           Append(const char*,int);
    void           Append(const char*,int,ZsiUcNmCCT);
    void           Append(const char*,int,ZsiUcIdCCT);
    void           Append(const wchar_t*,int,ZsiUcNmCCT);
    void           Append(const wchar_t*,int,ZsiUcIdCCT);
    void           Append(const ZsiUcStr,int);
    void           Append(const ZAsiUcStr&,int);
    void           Append(const ZAsiUcStr*,int);
    void           Append(int);
    void           Append(int,ZsiUcNmCCT);
    void           Append(int,ZsiUcIdCCT);
    void           Append(ZsiUcChar);
    void           Append(const ZAsiUcChar&);
    void           Append(const ZAsiUcChar*);

    int            FindFirst(const char*) const;
    int            FindFirst(const char*,ZsiUcNmCCT) const;
    int            FindFirst(const char*,ZsiUcIdCCT) const;
    int            FindFirst(const ZsiUcStr) const;
    int            FindFirst(const ZAsiUcStr&) const;
    int            FindFirst(const ZAsiUcStr*) const;


    int            FindLast(const char*) const;
    int            FindLast(const char*,ZsiUcNmCCT) const;
    int            FindLast(const char*,ZsiUcIdCCT) const;
    int            FindLast(const ZsiUcStr) const;
    int            FindLast(const ZAsiUcStr&) const;
    int            FindLast(const ZAsiUcStr*) const;


    int            FindFirst(int) const;
    int            FindFirst(int,ZsiUcNmCCT) const;
    int            FindFirst(int,ZsiUcIdCCT) const;
    int            FindFirst(ZsiUcChar) const;
    int            FindFirst(const ZAsiUcChar&) const;
    int            FindFirst(const ZAsiUcChar*) const;


    int            FindLast(int) const;
    int            FindLast(int,ZsiUcNmCCT) const;
    int            FindLast(int,ZsiUcIdCCT) const;
    int            FindLast(ZsiUcChar) const;
    int            FindLast(const ZAsiUcChar&) const;
    int            FindLast(const ZAsiUcChar*) const;

    int            Comp(const char*) const;
    int            Comp(const char*,ZsiUcNmCCT) const;
    int            Comp(const char*,ZsiUcIdCCT) const;
    int            Comp(const ZsiUcStr) const;
    int            Comp(const ZAsiUcStr&) const;
    int            Comp(const ZAsiUcStr*) const;

    int            Comp(const char*,int) const;
    int            Comp(const char*,int,ZsiUcNmCCT) const;
    int            Comp(const char*,int,ZsiUcIdCCT) const;
    int            Comp(const ZsiUcStr,int) const;
    int            Comp(const ZAsiUcStr&,int) const;
    int            Comp(const ZAsiUcStr*,int) const;

    int            Compi(const char*) const;
    int            Compi(const char*,ZsiUcNmCCT) const;
    int            Compi(const char*,ZsiUcIdCCT) const;
    int            Compi(const wchar_t*,ZsiUcNmCCT) const;
    int            Compi(const wchar_t*,ZsiUcIdCCT) const;
    int            Compi(const ZsiUcStr) const;
    int            Compi(const ZAsiUcStr&) const;
    int            Compi(const ZAsiUcStr*) const;

    int            Compi(const char*,int) const;
    int            Compi(const char*,int,ZsiUcNmCCT) const;
    int            Compi(const char*,int,ZsiUcIdCCT) const;
    int            Compi(const wchar_t*,int,ZsiUcNmCCT) const;
    int            Compi(const wchar_t*,int,ZsiUcIdCCT) const;
    int            Compi(const ZsiUcStr,int) const;
    int            Compi(const ZAsiUcStr&,int) const;
    int            Compi(const ZAsiUcStr*,int) const;

    void           Copy(const char*);
    void           Copy(const char*,ZsiUcNmCCT);
    void           Copy(const char*,ZsiUcIdCCT);
    void           Copy(const wchar_t*);
    void           Copy(const wchar_t*,ZsiUcNmCCT);
    void           Copy(const wchar_t*,ZsiUcIdCCT);
    void           Copy(const ZsiUcStr);
    void           Copy(const ZAsiUcStr&);
    void           Copy(const ZAsiUcStr*);

    void           Copy(const char*,int);
    void           Copy(const char*,int,ZsiUcNmCCT);
    void           Copy(const char*,int,ZsiUcIdCCT);
    void           Copy(const wchar_t*,int,ZsiUcNmCCT);
    void           Copy(const wchar_t*,int,ZsiUcIdCCT);
    void           Copy(const ZsiUcStr,int);
    void           Copy(const ZAsiUcStr&,int);
    void           Copy(const ZAsiUcStr*,int);

    const ZAsiUcChar & operator [] (int) const;

    ZAsiUcStr&  operator =  (const char*);
    ZAsiUcStr&  operator =  (const ZsiUcStr);
    ZAsiUcStr&  operator =  (const ZAsiUcStr &);
    ZAsiUcStr&  operator =  (const ZAsiUcStr *);

    friend int DLLScope operator == (const ZAsiUcStr&, const char*);
    friend int DLLScope operator == (const char*, const ZAsiUcStr&);
    friend int DLLScope operator == (const ZAsiUcStr&, const ZAsiUcStr&);
    friend int DLLScope operator == (const ZAsiUcStr*, const ZAsiUcStr&);
    friend int DLLScope operator == (const ZsiUcStr, const ZAsiUcStr&);
    friend int DLLScope operator == (const ZAsiUcStr&, const ZAsiUcStr*);
    friend int DLLScope operator == (const ZAsiUcStr&, const ZsiUcStr);

    friend int DLLScope operator != (const ZAsiUcStr&, const char*);
    friend int DLLScope operator != (const char*, const ZAsiUcStr&);
    friend int DLLScope operator != (const ZAsiUcStr&, const ZAsiUcStr&);
    friend int DLLScope operator != (const ZAsiUcStr*, const ZAsiUcStr&);
    friend int DLLScope operator != (const ZsiUcStr, const ZAsiUcStr&);
    friend int DLLScope operator != (const ZAsiUcStr&, const ZAsiUcStr*);
    friend int DLLScope operator != (const ZAsiUcStr&, const ZsiUcStr);

    friend int DLLScope operator >  (const ZAsiUcStr&, const char*);
    friend int DLLScope operator >  (const char*, const ZAsiUcStr&);
    friend int DLLScope operator >  (const ZAsiUcStr&, const ZAsiUcStr&);
    friend int DLLScope operator >  (const ZAsiUcStr*, const ZAsiUcStr&);
    friend int DLLScope operator >  (const ZsiUcStr, const ZAsiUcStr&);
    friend int DLLScope operator >  (const ZAsiUcStr&, const ZAsiUcStr*);
    friend int DLLScope operator >  (const ZAsiUcStr&, const ZsiUcStr);

    friend int DLLScope operator <  (const ZAsiUcStr&, const char*);
    friend int DLLScope operator <  (const char*, const ZAsiUcStr&);
    friend int DLLScope operator <  (const ZAsiUcStr&, const ZAsiUcStr&);
    friend int DLLScope operator <  (const ZAsiUcStr*, const ZAsiUcStr&);
    friend int DLLScope operator <  (const ZsiUcStr, const ZAsiUcStr&);
    friend int DLLScope operator <  (const ZAsiUcStr&, const ZAsiUcStr*);
    friend int DLLScope operator <  (const ZAsiUcStr&, const ZsiUcStr);

    friend int DLLScope operator >= (const ZAsiUcStr&, const char*);
    friend int DLLScope operator >= (const char*, const ZAsiUcStr&);
    friend int DLLScope operator >= (const ZAsiUcStr&, const ZAsiUcStr&);
    friend int DLLScope operator >= (const ZAsiUcStr*, const ZAsiUcStr&);
    friend int DLLScope operator >= (const ZsiUcStr, const ZAsiUcStr&);
    friend int DLLScope operator >= (const ZAsiUcStr&, const ZAsiUcStr*);
    friend int DLLScope operator >= (const ZAsiUcStr&, const ZsiUcStr);

    friend int DLLScope operator <= (const ZAsiUcStr&, const char*);
    friend int DLLScope operator <= (const char*, const ZAsiUcStr&);
    friend int DLLScope operator <= (const ZAsiUcStr&, const ZAsiUcStr&);
    friend int DLLScope operator <= (const ZAsiUcStr*, const ZAsiUcStr&);
    friend int DLLScope operator <= (const ZsiUcStr, const ZAsiUcStr&);
    friend int DLLScope operator <= (const ZAsiUcStr&, const ZAsiUcStr*);
    friend int DLLScope operator <= (const ZAsiUcStr&, const ZsiUcStr);

#ifdef ibmrs
    void* operator new(unsigned long);
#else
    void* operator new(size_t);
#endif
    void operator delete(void*);
#if defined(__WATCOMC__)
    void* operator new[](unsigned int);
    void operator delete[](void*);
#endif 

private:
    void *pUcStrData;
};

class ZAsiUcChar
{
public:

    ZsiUcChar Symbol;

    int       isUpper(void) const;
    int       isLower(void) const;
    int       isAlpha(void) const;
    int       isDigit(void) const;
    int       isXdigit(void) const;
    int       isSpace(void) const;
    int       isPunct(void) const;
    int       isAlnum(void) const;
    int       isGraph(void) const;
    int       isPrint(void) const;
    int       isCntrl(void) const;

    void      setUpper(void);
    void      setLower(void);
    void      setChar(int,ZsiUcIdCCT);
    void      setChar(int,ZsiUcNmCCT);
    void      setChar(ZsiUcChar);

    int       getChar(void) const;
    int       getChar(ZsiUcIdCCT) const;
    int       getChar(ZsiUcNmCCT) const;
    ZsiUcChar getUcChar(void) const;

    ZAsiUcChar Upper(void) const;
    ZAsiUcChar Lower(void) const;

    int  Comp(int) const;
    int  Comp(int,ZsiUcIdCCT) const;
    int  Comp(int,ZsiUcNmCCT) const;
    int  Comp(ZsiUcChar) const;
    int  Comp(ZAsiUcChar*) const;
    int  Comp(const ZAsiUcChar&) const;
    int  Compi(int) const;
    int  Compi(int,ZsiUcIdCCT) const;
    int  Compi(int,ZsiUcNmCCT) const;
    int  Compi(ZsiUcChar) const;
    int  Compi(ZAsiUcChar*) const;
    int  Compi(const ZAsiUcChar&) const;

    ZAsiUcChar&  operator =  (const char);
    ZAsiUcChar&  operator =  (const ZsiUcChar);
    ZAsiUcChar&  operator =  (const ZAsiUcChar&);

    friend DLLScope int operator == (const ZAsiUcChar&, const char);
    friend DLLScope int operator == (const char, const ZAsiUcChar&);
    friend DLLScope int operator == (const ZAsiUcChar&, const ZsiUcChar);
    friend DLLScope int operator == (const ZsiUcChar, const ZAsiUcChar&);
    friend DLLScope int operator == (const ZAsiUcChar&, const ZAsiUcChar&);
                         
    friend DLLScope int operator != (const ZAsiUcChar&, const char);
    friend DLLScope int operator != (const char, const ZAsiUcChar&);
    friend DLLScope int operator != (const ZAsiUcChar&, const ZsiUcChar);
    friend DLLScope int operator != (const ZsiUcChar, const ZAsiUcChar&);
    friend DLLScope int operator != (const ZAsiUcChar&, const ZAsiUcChar&);
                         
    friend DLLScope int operator >  (const ZAsiUcChar&, const char);
    friend DLLScope int operator >  (const char, const ZAsiUcChar&);
    friend DLLScope int operator >  (const ZAsiUcChar&, const ZsiUcChar);
    friend DLLScope int operator >  (const ZsiUcChar, const ZAsiUcChar&);
    friend DLLScope int operator >  (const ZAsiUcChar&, const ZAsiUcChar&);
                         
    friend DLLScope int operator <  (const ZAsiUcChar&, const char);
    friend DLLScope int operator <  (const char, const ZAsiUcChar&);
    friend DLLScope int operator <  (const ZAsiUcChar&, const ZsiUcChar);
    friend DLLScope int operator <  (const ZsiUcChar, const ZAsiUcChar&);
    friend DLLScope int operator <  (const ZAsiUcChar&, const ZAsiUcChar&);
                         
    friend DLLScope int operator >= (const ZAsiUcChar&, const char);
    friend DLLScope int operator >= (const char, const ZAsiUcChar&);
    friend DLLScope int operator >= (const ZAsiUcChar&, const ZsiUcChar);
    friend DLLScope int operator >= (const ZsiUcChar, const ZAsiUcChar&);
    friend DLLScope int operator >= (const ZAsiUcChar&, const ZAsiUcChar&);
                         
    friend DLLScope int operator <= (const ZAsiUcChar&, const char);
    friend DLLScope int operator <= (const char, const ZAsiUcChar&);
    friend DLLScope int operator <= (const ZAsiUcChar&, const ZsiUcChar);
    friend DLLScope int operator <= (const ZsiUcChar, const ZAsiUcChar&);
    friend DLLScope int operator <= (const ZAsiUcChar&, const ZAsiUcChar&);

#ifdef ibmrs
    void* operator new(unsigned long);
#else
    void* operator new(size_t);
#endif
    void operator delete(void*);
#if defined(__WATCOMC__)
    void* operator new[](unsigned int);
    void operator delete[](void*);
#endif 
};

#endif 


DLLScope int		 AsiUcIsAlnum      (ZsiUcChar);
DLLScope int 	     AsiUcIsAlpha      (ZsiUcChar);
DLLScope int 	     AsiUcIsCntrl      (ZsiUcChar);
DLLScope int 	     AsiUcIsDigit      (ZsiUcChar);
DLLScope int 	     AsiUcIsGraph      (ZsiUcChar);
DLLScope int 	     AsiUcIsLower      (ZsiUcChar);
DLLScope int 	     AsiUcIsPrint      (ZsiUcChar);
DLLScope int 	     AsiUcIsPunct      (ZsiUcChar);
DLLScope int 	     AsiUcIsSpace      (ZsiUcChar);
DLLScope int 	     AsiUcIsUpper      (ZsiUcChar);
DLLScope int 	     AsiUcIsXdigit     (ZsiUcChar);

DLLScope ZsiUcChar  AsiUcToLower      (ZsiUcChar);
DLLScope ZsiUcChar  AsiUcToUpper      (ZsiUcChar);

DLLScope int        AsiUcSprintf      (ZsiUcStr,const ZsiUcStr, ...);

DLLScope double     AsiUcAtof         (const ZsiUcStr);
DLLScope int        AsiUcAtoi         (const ZsiUcStr);
DLLScope long       AsiUcAtol         (const ZsiUcStr);
DLLScope double     AsiUcStrtod       (const ZsiUcStr,ZsiUcStr*);
DLLScope long       AsiUcStrtol       (const ZsiUcStr,ZsiUcStr*,int);

DLLScope ZsiUcStr   AsiUcStrcpy       (ZsiUcStr,const ZsiUcStr);
DLLScope ZsiUcStr   AsiUcStrncpy      (ZsiUcStr,const ZsiUcStr,int);
DLLScope ZsiUcStr   AsiUcStrcat       (ZsiUcStr,const ZsiUcStr);
DLLScope ZsiUcStr   AsiUcStrncat      (ZsiUcStr,const ZsiUcStr,int);

DLLScope int        AsiUcCmpUCandUC   (const ZsiUcStr,const ZsiUcStr);
DLLScope int        AsiUcStrcmp       (const ZsiUcStr,const ZsiUcStr);
DLLScope int        AsiUcStrncmp      (const ZsiUcStr,const ZsiUcStr,int);
DLLScope int        AsiUcStricmp      (const ZsiUcStr,const ZsiUcStr);
DLLScope int        AsiUcStrnicmp     (const ZsiUcStr,const ZsiUcStr,int);

DLLScope ZsiUcStr   AsiUcStrstr       (const ZsiUcStr,const ZsiUcStr);
DLLScope ZsiUcStr   AsiUcStrrstr      (const ZsiUcStr,const ZsiUcStr);
DLLScope ZsiUcStr   AsiUcStrchr       (const ZsiUcStr,ZsiUcChar);
DLLScope ZsiUcStr   AsiUcStrrchr      (const ZsiUcStr,ZsiUcChar);

DLLScope ZsiUcStr   AsiUcStrLower     (ZsiUcStr);
DLLScope ZsiUcStr   AsiUcStrUpper     (ZsiUcStr);


DLLScope char	    *AsiUcStrUc2Ch     (char*,int,const ZsiUcStr,int,ZsiUcNmCCT);
DLLScope ZsiUcStr   AsiUcStrCh2Uc     (ZsiUcStr,int,const char*,int,ZsiUcNmCCT);
DLLScope int        AsiUcUc2ChCCT     (char*,int,const ZsiUcStr,int,ZsiUcIdCCT);
DLLScope int        AsiUcCh2UcCCT     (ZsiUcStr,int,const char*,int,ZsiUcIdCCT);

DLLScope int        AsiUc2Ch          (ZsiUcChar,ZsiUcNmCCT);
DLLScope ZsiUcChar  AsiCh2Uc          (int,ZsiUcNmCCT);

DLLScope int        AsiUcStrlen       (const ZsiUcStr);
DLLScope int        AsiUcStrsize      (const ZsiUcStr);
DLLScope int        AsiUcStrchln      (const ZsiUcStr,ZsiUcNmCCT);
DLLScope int        AsiUcStrchlnIdCCT (const ZsiUcStr,ZsiUcIdCCT);
DLLScope int        AsiChStrUclnIdCCT (const char*,ZsiUcIdCCT);
              
DLLScope ZsiUcIdCCT AsiUcGetIdCCT     (ZsiUcNmCCT);
              
DLLScope ZsiUcNmCCT AsiUcGetNmCCT     (ZsiUcIdCCT);
DLLScope ZsiUcNmCCT AsiUcDefaultCCT   (void);
              
DLLScope ZsiUcIdCLT AsiUcGetIdCLT     (ZsiUcNmCLT);
DLLScope ZsiUcNmCLT AsiUcGetNmCLT     (ZsiUcIdCLT);
DLLScope ZsiUcNmCLT AsiUcDefaultCLT   (void);
              
DLLScope int        AsiUcCnChcmp      (ZsiUcNmCLT,ZsiUcChar,ZsiUcChar);
DLLScope int        AsiUcCnStrcmp     (ZsiUcNmCLT,const ZsiUcStr,const ZsiUcStr);
DLLScope int        AsiUcCnStrncmp    (ZsiUcNmCLT,const ZsiUcStr,const ZsiUcStr,int);
              
DLLScope int        AsiUcCiStrweight  (ZsiUcIdCLT,const ZsiUcStr,unsigned char *,int);
DLLScope int        AsiUcCiChcmp      (ZsiUcIdCLT,ZsiUcChar,ZsiUcChar);
DLLScope int        AsiUcCiStrcmp     (ZsiUcIdCLT,const ZsiUcStr,const ZsiUcStr);
              
DLLScope int        AsiUcCiStrIcmp    (ZsiUcIdCLT,const ZsiUcStr,const ZsiUcStr);
              
DLLScope int        AsiUcCiStrncmp    (ZsiUcIdCLT,const ZsiUcStr,const ZsiUcStr,int);
DLLScope int        AsiUcCiUcChStrcmp (ZsiUcIdCLT,ZsiUcIdCCT,const ZsiUcStr,const char*);
DLLScope int        AsiUcCiStrStrcmpA (ZsiUcIdCLT,ZsiUcIdCCT,const char*,const char*);
DLLScope int        AsiUcCiStrStrIcmpA(ZsiUcIdCLT,ZsiUcIdCCT,const char*,const char*);
DLLScope int        AsiUcCiStrStrcmpW (ZsiUcIdCLT,ZsiUcIdCCT,const wchar_t*,const wchar_t*);
DLLScope int        AsiUcCiStrStrIcmpW(ZsiUcIdCLT,ZsiUcIdCCT,const wchar_t*,const wchar_t*);

#ifndef UNICODE
#define AsiUcCiStrStrcmp    AsiUcCiStrStrcmpA
#else
#define AsiUcCiStrStrcmp    AsiUcCiStrStrcmpW
#endif

#pragma pack (pop)

#endif 

