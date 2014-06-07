#ifndef _zcdbzds_h
#define _zcdbzds_h 1

#include "zdsdef.h"

#include "zcmem.h"
#include "ZdZChar.h"

#pragma pack (push, 8)

#ifdef __cplusplus
extern "C" {
#endif
void           zcdbFail (const ZCHAR *str);

int            zcdbXdRoom (const zds_name ent, long *result);
int            zcdbXdSize (const struct resbuf *rb, long *result);

int            zcdbHandEnt (const ZCHAR *handle, zds_name entres);

ZCHAR *        zcdbXStrSave (ZCHAR *pSource, ZCHAR **pDest);

int            zcdbXStrCase (ZCHAR *str);
#ifdef __cplusplus
}
#endif

#ifdef __STDC__
#define zcdbNameSet(from, to)  (memcpy(to, from, sizeof(zds_name)))
#define zcdbPointSet(from,to)  (memcpy(to, from, sizeof(zds_point)))
#else
#define zcdbNameSet(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define zcdbPointSet(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif

#define zcdbNameClear(name)    name[0] = name[1] = 0
#define zcdbNameNil(name)      (name[0] == 0 && name[1] == 0)
#define zcdbNameEqual(name1, name2)  (name1[0]==name2[0] \
                                       && name1[1]==name2[1])
#pragma pack (pop)

#endif