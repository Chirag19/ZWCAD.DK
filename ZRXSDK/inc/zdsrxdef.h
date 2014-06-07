#ifndef   _ZDSRXDEF_H_
#define   _ZDSRXDEF_H_ 1

#pragma pack (push, 8)
typedef struct zfchnd {             
        struct zfchnd *next;        
        int fcode;                  
        int (*fhdl)();              
} ZFunHandList;
 
class ZcRxGenHand;


class RxZDSAppTableEntryType {
  public:
    int    lflag;
    ZCHAR* appname;
    LONG_PTR  apphandle;
    int    zds_fcode;
    int    zds_invkcnt;
    struct resbuf* zds_argl;
    ZFunHandList* zds_fhdl;
    ZcRxGenHand * modhandle;
    resbuf *zds_ret;
    int    zds_rettype;
};

#pragma pack (pop)
#endif
