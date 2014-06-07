#ifndef ASI_SDATA_HH
#define ASI_SDATA_HH zasisdata.hh

#include <oledb.h>

#if _MSC_VER < 1300
  #include <largeint.h>
#else
  #include <winnt.h>
#endif

#include "zasisys.h"


class DLLScope ZAsiObject;                   
    class DLLScope ZAsiIdent;                
    class DLLScope ZAsiData;                 
        class DLLScope ZAsiNum;              
            class DLLScope ZAsiExactNum;     
                class DLLScope ZAsiSmallInt; 
                class DLLScope ZAsiInt;      
                class DLLScope ZAsiNumeric;  
                class DLLScope ZAsiDecimal;  
            class DLLScope ZAsiApproxNum;    
                class DLLScope ZAsiFloat;    
                class DLLScope ZAsiReal;     
                class DLLScope ZAsiDouble;   
        class DLLScope ZAsiChar;             
        class DLLScope ZAsiBinary;           
        class DLLScope ZAsiIQualifier;       
            class DLLScope ZAsiInterval;     
                class DLLScope ZAsiYM;       
                class DLLScope ZAsiDT;       
        class DLLScope ZAsiDatetime;         
            class DLLScope ZAsiDate;         
            class DLLScope ZAsiTime;         
            class DLLScope ZAsiTimeStamp;    
        class DLLScope ZAsiBlob;             

    class DLLScope ZAsiColumn;               
    class DLLScope ZAsiRow;                  
    class DLLScope ZAsiHostBuffer;           
        class DLLScope ZAsiParameter;        
    class DLLScope ZAsiImplDefFunc;          

    class DLLScope ZAsiIRow;                 
    class DLLScope ZAsiList;                 

    class DLLScope ZAsiUcStr;                
    class DLLScope ZAsiUcChar;               

    class DLLScope ZAsiObjPack;              

typedef char ASIBCD [34]; 


#include "zasiconst.h"
#include "zasiucode.h"

#pragma pack (push, 8)

class ZAsiObject
{
public:
            ZAsiObject                (void);
    virtual ~ZAsiObject               (void);

            void*         operator new    (size_t);
            void          operator delete (void*);
#if defined(__WATCOMC__)
            void*         operator new[]    (unsigned int);
            void          operator delete[] (void*);
#endif

     virtual ZAsiObject  * duplicate  (void) const;

     virtual void          Clear      (void);

     virtual unsigned long packSize        (void) const;
     virtual unsigned long packTo          (ZAsiObjPack *) const;
     virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

     virtual unsigned long packValueSize   (void) const;
     virtual unsigned long packValueTo     (ZAsiObjPack *) const;
     virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);
};



class ZAsiIdent : public ZAsiObject
{
public:
  
                            ZAsiIdent       (void);
                            ZAsiIdent       (const char *);
                            ZAsiIdent       (const ZsiUcStr);
                            ZAsiIdent       (const ZAsiUcStr &);
                            ZAsiIdent       (const ZAsiUcStr &, const ZAsiUcStr &);
                            ZAsiIdent       (const ZAsiIdent &);
    virtual                 ~ZAsiIdent      (void);

    
    void                    set             (EAsiBoolean,
                                            const ZAsiUcStr &,
                                            const ZAsiUcStr &);

    void                    setDelimited    (EAsiBoolean);
    void                    setDelimited    (void);
    void                    setCharSet      (const ZAsiUcStr &);

    void                    setBody         (const ZAsiUcStr &, EAsiBoolean fParse = kAsiTrue);

    EAsiBoolean             isDelimited     (void) const;
    const ZAsiUcStr         & CharSet       (void) const;
    const ZAsiUcStr         & Body          (void) const;

    int                     Length          (void) const;

    
    virtual void            Clear           (void);


   
    ZAsiIdent       &       operator=       (const ZAsiIdent &);  
    ZAsiIdent       &       operator=       (const ZAsiUcStr &);  

    int                     operator==      (const ZAsiIdent &) const;

   
    void                    ToString        (ZAsiUcStr *) const;

   
    virtual ZAsiObject   *  duplicate       (void) const;

   
    virtual unsigned long   packSize        (void) const;
    virtual unsigned long   packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean     unpackFrom      (ZAsiObjPack *);

private:
    EAsiBoolean             isDelim;      
    ZAsiUcStr               charset;     
    ZAsiUcStr               ident;      
};



class ZAsiData : public ZAsiObject
{
friend class ZAsiColumn;

public:


            ZAsiData  (void);
    virtual ~ZAsiData (void);

 
    virtual EAsiDataType    Type                (void) const = 0; 
    virtual EAsiDTType      DateTimeType        (void) const; 
    virtual EAsiIType       IntervalType        (void) const; 
    virtual int             ImplDataType        (void) const; 
    virtual uint            Length              (void) const; 
    virtual uint            Precision           (void) const; 
    virtual uint            Scale               (void) const; 
    virtual uint            TimePrec            (void) const; 
    virtual uint            TimeStampPrec       (void) const; 
    virtual uint            LeadFieldPrec       (void) const; 
    virtual uint            FracSecPrec         (void) const; 
    virtual uint            ReturnLength        (void) const;

   
    virtual EAsiBoolean     is_numeric          (void) const;
    virtual EAsiBoolean     is_exactnumeric     (void) const;
    virtual EAsiBoolean     is_approxnumeric    (void) const;
    virtual EAsiBoolean     is_character        (void) const;
    virtual EAsiBoolean     is_binary           (void) const;
    virtual EAsiBoolean     is_datetime         (void) const;
    virtual EAsiBoolean     is_interval         (void) const;
    virtual EAsiBoolean     is_yminterval       (void) const;
    virtual EAsiBoolean     is_dtinterval       (void) const;
    virtual EAsiBoolean     is_implement        (void) const;

    virtual EAsiBoolean     is_comparable       (const ZAsiData *) const;
    virtual EAsiBoolean     is_storable         (const ZAsiData *) const;
    virtual EAsiBoolean     is_castable         (const ZAsiData *) const;

    virtual ZAsiData *      checkAdd            (const ZAsiData *) const;
    virtual ZAsiData *      checkSub            (const ZAsiData *) const;
    virtual ZAsiData *      checkMul            (const ZAsiData *) const;
    virtual ZAsiData *      checkDiv            (const ZAsiData *) const;
    virtual ZAsiData *      checkCat            (const ZAsiData *) const;
    virtual ZAsiData *      checkSet            (const ZAsiData *) const;

    virtual EAsiBoolean     isEqualTo           (const ZAsiData &) const;
    virtual EAsiBoolean     isGreaterThan       (const ZAsiData &) const;

    virtual ZAsiImplDefFunc *  getFuncDsc       (const ZAsiIdent &, const ZAsiRow &) const;


    
    virtual void            setNull             (void); 
    virtual EAsiBoolean     isNull              (void) const; 
  
    virtual EAsiBoolean     storeValue          (real);                 
    virtual EAsiBoolean     storeValue          (integer);              
    virtual EAsiBoolean     storeValue          (smallint);             
    virtual EAsiBoolean     storeValue          (char *, uint);         
    virtual EAsiBoolean     storeValue          (const ZAsiUcStr &);    
    virtual EAsiBoolean     storeValue          (char *, uint, uint *); 
    virtual EAsiBoolean     storeValue          (const ZAsiData &);     
    virtual EAsiBoolean     storeValue          (const ZsiUcStr);       
    virtual EAsiBoolean		storeValue			(const DECIMAL &);
    virtual EAsiBoolean		storeValue			(const DB_NUMERIC *);
    virtual EAsiBoolean		storeValue			(const DBDATE *);
    virtual EAsiBoolean		storeValue			(const DBTIME *);
    virtual EAsiBoolean		storeValue			(const DBTIMESTAMP *);



    virtual EAsiBoolean     getValue            (real *) const;               
    virtual EAsiBoolean     getValue            (integer *) const;            
    virtual EAsiBoolean     getValue            (smallint *) const;           
    virtual EAsiBoolean     getValue            (char *, uint) const;         
    virtual EAsiBoolean     getValue            (ZAsiUcStr *) const;          
    virtual EAsiBoolean     getValue            (char *, uint, uint *) const; 
    virtual EAsiBoolean     getValue            (ZsiUcStr, uint) const;       
    virtual EAsiBoolean     getValue            (ZAsiData &) const;           
    virtual EAsiBoolean		getValue			(DECIMAL *) const;
    virtual EAsiBoolean		getValue			(DB_NUMERIC *) const;
    virtual EAsiBoolean		getValue			(DBDATE *) const;
    virtual EAsiBoolean		getValue			(DBTIME *) const;
    virtual EAsiBoolean		getValue			(DBTIMESTAMP *) const;


    virtual EAsiBoolean     SQLType             (ZAsiUcStr *) const = 0;    
    virtual EAsiBoolean     SQLLiteral          (ZAsiUcStr *) const = 0;    


   
    static ZAsiData *       MapColumnInfoToAsi  (DBCOLUMNINFO * pColumnInfo);
    static ZAsiData *       MapParamInfoToAsi	(DBPARAMINFO * pParamInfo);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    
    virtual ZAsiObject*     duplicate           (void) const = 0;

  

    virtual void            Clear               (void);

protected:
    EAsiBoolean             isnull; 
};



class ZAsiNum : public ZAsiData
{
friend class ZAsiLex;
protected:
                                ZAsiNum ();           
public:
    virtual						~ZAsiNum ();          

   
    virtual uint                Precision       (void) const;
    virtual uint                Scale           (void) const;

  
    virtual EAsiBoolean     is_numeric      (void) const;
    virtual EAsiBoolean         is_exactnumeric (void) const;
    virtual EAsiBoolean         is_approxnumeric(void) const;
    virtual EAsiBoolean         is_comparable   (const ZAsiData *) const;
    virtual EAsiBoolean         is_storable     (const ZAsiData *) const;
    virtual EAsiBoolean         is_castable     (const ZAsiData *) const;

    virtual ZAsiData    *       checkAdd        (const ZAsiData *) const;
    virtual ZAsiData    *       checkSub        (const ZAsiData *) const;
    virtual ZAsiData    *       checkMul        (const ZAsiData *) const;
    virtual ZAsiData    *       checkDiv        (const ZAsiData *) const;


    
    virtual integer             intValue        (void) const;
    virtual real                realValue       (void) const;


   
    virtual int                 operator>  (const ZAsiSmallInt &) const;
    virtual int                 operator>  (const ZAsiInt &)      const;
    virtual int                 operator>  (const ZAsiNumeric &)  const;
    virtual int                 operator>  (const ZAsiDecimal &)  const;
    virtual int                 operator>  (const ZAsiFloat &)    const;
    virtual int                 operator>  (const ZAsiReal &)     const;
    virtual int                 operator>  (const ZAsiDouble &)   const;
    virtual int                 operator>  (const smallint)       const;
    virtual int                 operator>  (const integer)        const;
    virtual int                 operator>  (const real)           const;
    virtual int                 operator>  (const int)            const;

    virtual int                 operator>= (const ZAsiSmallInt &) const;
    virtual int                 operator>= (const ZAsiInt &)      const;
    virtual int                 operator>= (const ZAsiNumeric &)  const;
    virtual int                 operator>= (const ZAsiDecimal &)  const;
    virtual int                 operator>= (const ZAsiFloat &)    const;
    virtual int                 operator>= (const ZAsiReal &)     const;
    virtual int                 operator>= (const ZAsiDouble &)   const;
    virtual int                 operator>= (const smallint)       const;
    virtual int                 operator>= (const integer)        const;
    virtual int                 operator>= (const real)           const;
    virtual int                 operator>= (const int)            const;

    virtual int                 operator== (const ZAsiSmallInt &) const;
    virtual int                 operator== (const ZAsiInt &)      const;
    virtual int                 operator== (const ZAsiNumeric &)  const;
    virtual int                 operator== (const ZAsiDecimal &)  const;
    virtual int                 operator== (const ZAsiFloat &)    const;
    virtual int                 operator== (const ZAsiReal &)     const;
    virtual int                 operator== (const ZAsiDouble &)   const;
    virtual int                 operator== (const smallint)       const;
    virtual int                 operator== (const integer)        const;
    virtual int                 operator== (const real)           const;
    virtual int                 operator== (const int)            const;

    virtual int                 operator<= (const ZAsiSmallInt &) const;
    virtual int                 operator<= (const ZAsiInt &)      const;
    virtual int                 operator<= (const ZAsiNumeric &)  const;
    virtual int                 operator<= (const ZAsiDecimal &)  const;
    virtual int                 operator<= (const ZAsiFloat &)    const;
    virtual int                 operator<= (const ZAsiReal &)     const;
    virtual int                 operator<= (const ZAsiDouble &)   const;
    virtual int                 operator<= (const smallint)       const;
    virtual int                 operator<= (const integer)        const;
    virtual int                 operator<= (const real)           const;
    virtual int                 operator<= (const int)            const;

    virtual int                 operator<  (const ZAsiSmallInt &) const;
    virtual int                 operator<  (const ZAsiInt &)      const;
    virtual int                 operator<  (const ZAsiNumeric &)  const;
    virtual int                 operator<  (const ZAsiDecimal &)  const;
    virtual int                 operator<  (const ZAsiFloat &)    const;
    virtual int                 operator<  (const ZAsiReal &)     const;
    virtual int                 operator<  (const ZAsiDouble &)   const;
    virtual int                 operator<  (const smallint)       const;
    virtual int                 operator<  (const integer)        const;
    virtual int                 operator<  (const real)           const;
    virtual int                 operator<  (const int)            const;

    virtual int                 operator!= (const ZAsiSmallInt &) const;
    virtual int                 operator!= (const ZAsiInt &)      const;
    virtual int                 operator!= (const ZAsiNumeric &)  const;
    virtual int                 operator!= (const ZAsiDecimal &)  const;
    virtual int                 operator!= (const ZAsiFloat &)    const;
    virtual int                 operator!= (const ZAsiReal &)     const;
    virtual int                 operator!= (const ZAsiDouble &)   const;
    virtual int                 operator!= (const smallint)       const;
    virtual int                 operator!= (const integer)        const;
    virtual int                 operator!= (const real)           const;
    virtual int                 operator!= (const int)            const;


protected:
    uint        precision;
    uint        scale;

};



class ZAsiExactNum : public ZAsiNum
{
protected:
                            ZAsiExactNum ();
public:
    virtual					~ZAsiExactNum ();

   
    virtual EAsiBoolean		is_exactnumeric       (void) const;
    ZAsiData              * checkAdd                      (const ZAsiData *) const;


   
    virtual int         operator>  (const ZAsiSmallInt &) const;
    virtual int         operator>  (const ZAsiInt &)      const;
    virtual int         operator>  (const ZAsiNumeric &)  const;
    virtual int         operator>  (const ZAsiDecimal &)  const;
    virtual int         operator>  (const ZAsiFloat &)    const;
    virtual int         operator>  (const ZAsiReal &)     const;
    virtual int         operator>  (const ZAsiDouble &)   const;
    virtual int         operator>  (const smallint)       const;
    virtual int         operator>  (const integer)        const;
    virtual int         operator>  (const real)           const;
    virtual int         operator>  (const int)            const;

    virtual int         operator>= (const ZAsiSmallInt &) const;
    virtual int         operator>= (const ZAsiInt &)      const;
    virtual int         operator>= (const ZAsiNumeric &)  const;
    virtual int         operator>= (const ZAsiDecimal &)  const;
    virtual int         operator>= (const ZAsiFloat &)    const;
    virtual int         operator>= (const ZAsiReal &)     const;
    virtual int         operator>= (const ZAsiDouble &)   const;
    virtual int         operator>= (const smallint)       const;
    virtual int         operator>= (const integer)        const;
    virtual int         operator>= (const real)           const;
    virtual int         operator>= (const int)            const;

    virtual int         operator== (const ZAsiSmallInt &) const;
    virtual int         operator== (const ZAsiInt &)      const;
    virtual int         operator== (const ZAsiNumeric &)  const;
    virtual int         operator== (const ZAsiDecimal &)  const;
    virtual int         operator== (const ZAsiFloat &)    const;
    virtual int         operator== (const ZAsiReal &)     const;
    virtual int         operator== (const ZAsiDouble &)   const;
    virtual int         operator== (const smallint)       const;
    virtual int         operator== (const integer)        const;
    virtual int         operator== (const real)           const;
    virtual int         operator== (const int)            const;

    virtual int         operator<= (const ZAsiSmallInt &) const;
    virtual int         operator<= (const ZAsiInt &)      const;
    virtual int         operator<= (const ZAsiNumeric &)  const;
    virtual int         operator<= (const ZAsiDecimal &)  const;
    virtual int         operator<= (const ZAsiFloat &)    const;
    virtual int         operator<= (const ZAsiReal &)     const;
    virtual int         operator<= (const ZAsiDouble &)   const;
    virtual int         operator<= (const smallint)       const;
    virtual int         operator<= (const integer)        const;
    virtual int         operator<= (const real)           const;
    virtual int         operator<= (const int)            const;

    virtual int         operator<  (const ZAsiSmallInt &) const;
    virtual int         operator<  (const ZAsiInt &)      const;
    virtual int         operator<  (const ZAsiNumeric &)  const;
    virtual int         operator<  (const ZAsiDecimal &)  const;
    virtual int         operator<  (const ZAsiFloat &)    const;
    virtual int         operator<  (const ZAsiReal &)     const;
    virtual int         operator<  (const ZAsiDouble &)   const;
    virtual int         operator<  (const smallint)       const;
    virtual int         operator<  (const integer)        const;
    virtual int         operator<  (const real)           const;
    virtual int         operator<  (const int)            const;

    virtual int         operator!= (const ZAsiSmallInt &) const;
    virtual int         operator!= (const ZAsiInt &)      const;
    virtual int         operator!= (const ZAsiNumeric &)  const;
    virtual int         operator!= (const ZAsiDecimal &)  const;
    virtual int         operator!= (const ZAsiFloat &)    const;
    virtual int         operator!= (const ZAsiReal &)     const;
    virtual int         operator!= (const ZAsiDouble &)   const;
    virtual int         operator!= (const smallint)       const;
    virtual int         operator!= (const integer)        const;
    virtual int         operator!= (const real)           const;
    virtual int         operator!= (const int)            const;



protected:
            int         cmpeqlen(const  ZAsiExactNum *)   const;
            int         cmpeqlan(const  ZAsiNum *)        const;
            int         cmpeqlenC(const real)             const;
            int         cmpneqen(const  ZAsiExactNum *)   const;
            int         cmpneqan(const  ZAsiNum *)        const;
            int         cmpneqenC(const real)             const;
            int         cmpltren(const  ZAsiExactNum *)   const;
            int         cmpltran(const  ZAsiNum *)        const;
            int         cmpltrenC(const real)             const;
            int         cmplteen(const  ZAsiExactNum *)   const;
            int         cmpltean(const  ZAsiNum *)        const;
            int         cmplteenC(const real)             const;
            int         cmpgtren(const  ZAsiExactNum *)   const;
            int         cmpgtran(const  ZAsiNum *)        const;
            int         cmpgtrenC(const real)             const;
            int         cmpgteen(const  ZAsiExactNum *)   const;
            int         cmpgtean(const  ZAsiNum *)        const;
            int         cmpgteenC(const real)             const;

};



class ZAsiApproxNum : public ZAsiNum
{
protected:
                        ZAsiApproxNum ();     
public:
    virtual				~ZAsiApproxNum ();    

 
    virtual EAsiBoolean is_approxnumeric    (void) const;


 
    virtual int         operator>  (const ZAsiSmallInt &) const;
    virtual int         operator>  (const ZAsiInt &)      const;
    virtual int         operator>  (const ZAsiNumeric &)  const;
    virtual int         operator>  (const ZAsiDecimal &)  const;
    virtual int         operator>  (const ZAsiFloat &)    const;
    virtual int         operator>  (const ZAsiReal &)     const;
    virtual int         operator>  (const ZAsiDouble &)   const;
    virtual int         operator>  (const smallint)       const;
    virtual int         operator>  (const integer)        const;
    virtual int         operator>  (const real)           const;
    virtual int         operator>  (const int)            const;

    virtual int         operator>= (const ZAsiSmallInt &) const;
    virtual int         operator>= (const ZAsiInt &)      const;
    virtual int         operator>= (const ZAsiNumeric &)  const;
    virtual int         operator>= (const ZAsiDecimal &)  const;
    virtual int         operator>= (const ZAsiFloat &)    const;
    virtual int         operator>= (const ZAsiReal &)     const;
    virtual int         operator>= (const ZAsiDouble &)   const;
    virtual int         operator>= (const smallint)       const;
    virtual int         operator>= (const integer)        const;
    virtual int         operator>= (const real)           const;
    virtual int         operator>= (const int)            const;

    virtual int         operator== (const ZAsiSmallInt &) const;
    virtual int         operator== (const ZAsiInt &)      const;
    virtual int         operator== (const ZAsiNumeric &)  const;
    virtual int         operator== (const ZAsiDecimal &)  const;
    virtual int         operator== (const ZAsiFloat &)    const;
    virtual int         operator== (const ZAsiReal &)     const;
    virtual int         operator== (const ZAsiDouble &)   const;
    virtual int         operator== (const smallint)       const;
    virtual int         operator== (const integer)        const;
    virtual int         operator== (const real)           const;
    virtual int         operator== (const int)            const;

    virtual int         operator<= (const ZAsiSmallInt &) const;
    virtual int         operator<= (const ZAsiInt &)      const;
    virtual int         operator<= (const ZAsiNumeric &)  const;
    virtual int         operator<= (const ZAsiDecimal &)  const;
    virtual int         operator<= (const ZAsiFloat &)    const;
    virtual int         operator<= (const ZAsiReal &)     const;
    virtual int         operator<= (const ZAsiDouble &)   const;
    virtual int         operator<= (const smallint)       const;
    virtual int         operator<= (const integer)        const;
    virtual int         operator<= (const real)           const;
    virtual int         operator<= (const int)            const;

    virtual int         operator<  (const ZAsiSmallInt &) const;
    virtual int         operator<  (const ZAsiInt &)      const;
    virtual int         operator<  (const ZAsiNumeric &)  const;
    virtual int         operator<  (const ZAsiDecimal &)  const;
    virtual int         operator<  (const ZAsiFloat &)    const;
    virtual int         operator<  (const ZAsiReal &)     const;
    virtual int         operator<  (const ZAsiDouble &)   const;
    virtual int         operator<  (const smallint)       const;
    virtual int         operator<  (const integer)        const;
    virtual int         operator<  (const real)           const;
    virtual int         operator<  (const int)            const;

    virtual int         operator!= (const ZAsiSmallInt &) const;
    virtual int         operator!= (const ZAsiInt &)      const;
    virtual int         operator!= (const ZAsiNumeric &)  const;
    virtual int         operator!= (const ZAsiDecimal &)  const;
    virtual int         operator!= (const ZAsiFloat &)    const;
    virtual int         operator!= (const ZAsiReal &)     const;
    virtual int         operator!= (const ZAsiDouble &)   const;
    virtual int         operator!= (const smallint)       const;
    virtual int         operator!= (const integer)        const;
    virtual int         operator!= (const real)           const;
    virtual int         operator!= (const int)            const;



protected:

};





class ZAsiSmallInt : public ZAsiExactNum
{
public:
                        ZAsiSmallInt (void);
                        ZAsiSmallInt (const ZAsiSmallInt &);
    virtual				~ZAsiSmallInt (void);


   
    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual EAsiBoolean  isEqualTo      (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const ZAsiData &) const;


    virtual ZAsiData *   checkAdd       (const ZAsiData *) const;
    virtual ZAsiData *   checkSub       (const ZAsiData *) const;
    virtual ZAsiData *   checkMul       (const ZAsiData *) const;
    virtual ZAsiData *   checkDiv       (const ZAsiData *) const;
    virtual ZAsiData *   checkSet       (const ZAsiData *) const;

   
    virtual EAsiBoolean   storeValue (real) ;
    virtual EAsiBoolean   storeValue (integer) ;
    virtual EAsiBoolean   storeValue (smallint) ;
    virtual EAsiBoolean   storeValue (char *, uint) ;
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &) ;
    virtual EAsiBoolean   storeValue (const ZAsiData &);

   
    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZAsiUcStr);


   
    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (ZAsiUcStr *) const;

   
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (ZAsiUcStr, uint) const;
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (ZAsiUcStr *) const;
    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const;


   
    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *) ;


   
    virtual ZAsiObject   *duplicate (void) const;

   
            ZAsiSmallInt &operator= (const ZAsiSmallInt &);
            ZAsiSmallInt &operator= (const ZAsiInt &);
            ZAsiSmallInt &operator= (const ZAsiNumeric &);
            ZAsiSmallInt &operator= (const ZAsiDecimal &);
            ZAsiSmallInt &operator= (const ZAsiFloat &);
            ZAsiSmallInt &operator= (const ZAsiReal &);
            ZAsiSmallInt &operator= (const ZAsiDouble &);
            ZAsiSmallInt &operator= (const smallint);
            ZAsiSmallInt &operator= (const integer);
            ZAsiSmallInt &operator= (const real);
            ZAsiSmallInt &operator= (const int);


            ZAsiSmallInt &operator+= (const ZAsiSmallInt &);
            ZAsiSmallInt &operator+= (const ZAsiInt &);
            ZAsiSmallInt &operator+= (const ZAsiNumeric &);
            ZAsiSmallInt &operator+= (const ZAsiDecimal &);
            ZAsiSmallInt &operator+= (const ZAsiFloat &);
            ZAsiSmallInt &operator+= (const ZAsiReal &);
            ZAsiSmallInt &operator+= (const ZAsiDouble &);
            ZAsiSmallInt &operator+= (const smallint);
            ZAsiSmallInt &operator+= (const integer);
            ZAsiSmallInt &operator+= (const real);
            ZAsiSmallInt &operator+= (const int);

            ZAsiSmallInt &operator-= (const ZAsiSmallInt &);
            ZAsiSmallInt &operator-= (const ZAsiInt &);
            ZAsiSmallInt &operator-= (const ZAsiNumeric &);
            ZAsiSmallInt &operator-= (const ZAsiDecimal &);
            ZAsiSmallInt &operator-= (const ZAsiFloat &);
            ZAsiSmallInt &operator-= (const ZAsiReal &);
            ZAsiSmallInt &operator-= (const ZAsiDouble &);
            ZAsiSmallInt &operator-= (const smallint);
            ZAsiSmallInt &operator-= (const integer);
            ZAsiSmallInt &operator-= (const real);
            ZAsiSmallInt &operator-= (const int);

            ZAsiSmallInt &operator*= (const ZAsiSmallInt &);
            ZAsiSmallInt &operator*= (const ZAsiInt &);
            ZAsiSmallInt &operator*= (const ZAsiNumeric &);
            ZAsiSmallInt &operator*= (const ZAsiDecimal &);
            ZAsiSmallInt &operator*= (const ZAsiFloat &);
            ZAsiSmallInt &operator*= (const ZAsiReal &);
            ZAsiSmallInt &operator*= (const ZAsiDouble &);
            ZAsiSmallInt &operator*= (const smallint);
            ZAsiSmallInt &operator*= (const integer);
            ZAsiSmallInt &operator*= (const real);
            ZAsiSmallInt &operator*= (const int);

            ZAsiSmallInt &operator/= (const ZAsiSmallInt &);
            ZAsiSmallInt &operator/= (const ZAsiInt &);
            ZAsiSmallInt &operator/= (const ZAsiNumeric &);
            ZAsiSmallInt &operator/= (const ZAsiDecimal &);
            ZAsiSmallInt &operator/= (const ZAsiFloat &);
            ZAsiSmallInt &operator/= (const ZAsiReal &);
            ZAsiSmallInt &operator/= (const ZAsiDouble &);
            ZAsiSmallInt &operator/= (const smallint);
            ZAsiSmallInt &operator/= (const integer);
            ZAsiSmallInt &operator/= (const real);
            ZAsiSmallInt &operator/= (const int);

            ZAsiDouble operator+ (const ZAsiSmallInt &) const;
            ZAsiDouble operator+ (const smallint)       const;
            ZAsiDouble operator+ (const integer)        const;
            ZAsiDouble operator+ (const real)           const;
            ZAsiDouble operator+ (const int)            const;
     friend ZAsiDouble DLLScope operator+ (const smallint, const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator+ (const integer,  const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator+ (const real,     const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator+ (const int,      const ZAsiSmallInt &);

            ZAsiDouble operator- (const ZAsiSmallInt &) const;
            ZAsiDouble operator- (const smallint)       const;
            ZAsiDouble operator- (const integer)        const;
            ZAsiDouble operator- (const real)           const;
            ZAsiDouble operator- (const int)            const;
     friend ZAsiDouble DLLScope operator- (const smallint, const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator- (const integer,  const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator- (const real,     const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator- (const int,      const ZAsiSmallInt &);


            ZAsiDouble operator* (const ZAsiSmallInt &) const;
            ZAsiDouble operator* (const smallint)       const;
            ZAsiDouble operator* (const integer)        const;
            ZAsiDouble operator* (const real)           const;
            ZAsiDouble operator* (const int)            const;
     friend ZAsiDouble DLLScope operator* (const smallint, const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator* (const integer,  const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator* (const real,     const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator* (const int,      const ZAsiSmallInt &);



            ZAsiDouble operator/ (const ZAsiSmallInt &) const;
            ZAsiDouble operator/ (const smallint)  const;
            ZAsiDouble operator/ (const integer)   const;
            ZAsiDouble operator/ (const real)      const;
            ZAsiDouble operator/ (const int)       const;
     friend ZAsiDouble DLLScope operator/ (const smallint, const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator/ (const integer,  const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator/ (const real,     const ZAsiSmallInt &);
     friend ZAsiDouble DLLScope operator/ (const int,      const ZAsiSmallInt &);


            ZAsiSmallInt &operator-- (void);
            ZAsiSmallInt &operator++ (void);

            ZAsiSmallInt &operator-  (void);

private:
    smallint sivalue;
};


class ZAsiInt : public ZAsiExactNum
{
public:
                        ZAsiInt ();
                        ZAsiInt (const ZAsiInt &);
    virtual				~ZAsiInt ();

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual ZAsiData *   checkAdd       (const ZAsiData *) const;
    virtual ZAsiData *   checkSub       (const ZAsiData *) const;
    virtual ZAsiData *   checkMul       (const ZAsiData *) const;
    virtual ZAsiData *   checkDiv       (const ZAsiData *) const;
    virtual ZAsiData *   checkSet       (const ZAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const ZAsiData &) const;

    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue (const ZAsiData &);


    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);



    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (ZAsiUcStr *) const;

    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (ZAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const;        

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *) ;

    virtual ZAsiObject   *duplicate (void) const;

            ZAsiInt &operator= (const ZAsiSmallInt &);
            ZAsiInt &operator= (const ZAsiInt &);
            ZAsiInt &operator= (const ZAsiNumeric &);
            ZAsiInt &operator= (const ZAsiDecimal &);
            ZAsiInt &operator= (const ZAsiFloat &);
            ZAsiInt &operator= (const ZAsiReal &);
            ZAsiInt &operator= (const ZAsiDouble &);
            ZAsiInt &operator= (const smallint);
            ZAsiInt &operator= (const integer);
            ZAsiInt &operator= (const real);
            ZAsiInt &operator= (const int);



            ZAsiInt &operator+= (const ZAsiSmallInt &);
            ZAsiInt &operator+= (const ZAsiInt &);
            ZAsiInt &operator+= (const ZAsiNumeric &);
            ZAsiInt &operator+= (const ZAsiDecimal &);
            ZAsiInt &operator+= (const ZAsiFloat &);
            ZAsiInt &operator+= (const ZAsiReal &);
            ZAsiInt &operator+= (const ZAsiDouble &);
            ZAsiInt &operator+= (const smallint);
            ZAsiInt &operator+= (const integer);
            ZAsiInt &operator+= (const real);
            ZAsiInt &operator+= (const int);

            ZAsiInt &operator-= (const ZAsiSmallInt &);
            ZAsiInt &operator-= (const ZAsiInt &);
            ZAsiInt &operator-= (const ZAsiNumeric &);
            ZAsiInt &operator-= (const ZAsiDecimal &);
            ZAsiInt &operator-= (const ZAsiFloat &);
            ZAsiInt &operator-= (const ZAsiReal &);
            ZAsiInt &operator-= (const ZAsiDouble &);
            ZAsiInt &operator-= (const smallint);
            ZAsiInt &operator-= (const integer);
            ZAsiInt &operator-= (const real);
            ZAsiInt &operator-= (const int);

            ZAsiInt &operator*= (const ZAsiSmallInt &);
            ZAsiInt &operator*= (const ZAsiInt &);
            ZAsiInt &operator*= (const ZAsiNumeric &);
            ZAsiInt &operator*= (const ZAsiDecimal &);
            ZAsiInt &operator*= (const ZAsiFloat &);
            ZAsiInt &operator*= (const ZAsiReal &);
            ZAsiInt &operator*= (const ZAsiDouble &);
            ZAsiInt &operator*= (const smallint);
            ZAsiInt &operator*= (const integer);
            ZAsiInt &operator*= (const real);
            ZAsiInt &operator*= (const int);

            ZAsiInt &operator/= (const ZAsiSmallInt &);
            ZAsiInt &operator/= (const ZAsiInt &);
            ZAsiInt &operator/= (const ZAsiNumeric &);
            ZAsiInt &operator/= (const ZAsiDecimal &);
            ZAsiInt &operator/= (const ZAsiFloat &);
            ZAsiInt &operator/= (const ZAsiReal &);
            ZAsiInt &operator/= (const ZAsiDouble &);
            ZAsiInt &operator/= (const smallint);
            ZAsiInt &operator/= (const integer);
            ZAsiInt &operator/= (const real);
            ZAsiInt &operator/= (const int);

            ZAsiDouble operator+ (const ZAsiSmallInt &) const;
     friend ZAsiDouble DLLScope operator+ (const ZAsiSmallInt &, const ZAsiInt &);
            ZAsiDouble operator+ (const ZAsiInt &) const;
            ZAsiDouble operator+ (const smallint)  const;
     friend ZAsiDouble DLLScope operator+ (const smallint, const ZAsiInt &);
            ZAsiDouble operator+ (const integer) const;
     friend ZAsiDouble DLLScope operator+ (const integer, const ZAsiInt &);
            ZAsiDouble operator+ (const real) const;
     friend ZAsiDouble DLLScope operator+ (const real, const ZAsiInt &);
            ZAsiDouble operator+ (const int) const;
     friend ZAsiDouble DLLScope operator+ (const int, const ZAsiInt &);


            ZAsiDouble operator- (const ZAsiSmallInt &) const;
     friend ZAsiDouble DLLScope operator- (const ZAsiSmallInt &, const ZAsiInt &);
            ZAsiDouble operator- (const ZAsiInt &) const;
            ZAsiDouble operator- (const smallint)  const;
     friend ZAsiDouble DLLScope operator- (const smallint, const ZAsiInt &);
            ZAsiDouble operator- (const integer) const;
     friend ZAsiDouble DLLScope operator- (const integer, const ZAsiInt &);
            ZAsiDouble operator- (const real) const;
     friend ZAsiDouble DLLScope operator- (const real, const ZAsiInt &);
            ZAsiDouble operator- (const int) const;
     friend ZAsiDouble DLLScope operator- (const int, const ZAsiInt &);

            ZAsiDouble operator* (const ZAsiSmallInt &) const;
     friend ZAsiDouble DLLScope operator* (const ZAsiSmallInt &, const ZAsiInt &);
            ZAsiDouble operator* (const ZAsiInt &) const;
            ZAsiDouble operator* (const smallint)  const;
     friend ZAsiDouble DLLScope operator* (const smallint, const ZAsiInt &);
            ZAsiDouble operator* (const integer) const;
     friend ZAsiDouble DLLScope operator* (const integer, const ZAsiInt &);
            ZAsiDouble operator* (const real) const;
     friend ZAsiDouble DLLScope operator* (const real, const ZAsiInt &);
            ZAsiDouble operator* (const int) const;
     friend ZAsiDouble DLLScope operator* (const int, const ZAsiInt &);

            ZAsiDouble operator/ (const ZAsiSmallInt &) const;
     friend ZAsiDouble DLLScope operator/ (const ZAsiSmallInt &, const ZAsiInt &);
            ZAsiDouble operator/ (const ZAsiInt &) const;
            ZAsiDouble operator/ (const smallint) const;
     friend ZAsiDouble DLLScope operator/ (const smallint, const ZAsiInt &);
            ZAsiDouble operator/ (const integer) const;
     friend ZAsiDouble DLLScope operator/ (const integer, const ZAsiInt &);
            ZAsiDouble operator/ (const real) const;
     friend ZAsiDouble DLLScope operator/ (const real, const ZAsiInt &);
            ZAsiDouble operator/ (const int) const;
     friend ZAsiDouble DLLScope operator/ (const int, const ZAsiInt &);

            ZAsiInt &operator-- (void);
            ZAsiInt &operator++ (void);

            ZAsiInt &operator-  (void);

private:
    integer ivalue;
};


class ZAsiNumeric: public ZAsiExactNum
{
friend class ZAsiDecimal;
private:
            EAsiBoolean SetNumeric (real);

public:
                                ZAsiNumeric     (uint, uint);
                                ZAsiNumeric     (uint);
                                ZAsiNumeric     (const ZAsiNumeric &);
                                ZAsiNumeric     (void);
    virtual                     ~ZAsiNumeric    (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual ZAsiData *   checkAdd       (const ZAsiData *) const;
    virtual ZAsiData *   checkSub       (const ZAsiData *) const;
    virtual ZAsiData *   checkMul       (const ZAsiData *) const;
    virtual ZAsiData *   checkDiv       (const ZAsiData *) const;
    virtual ZAsiData *   checkSet       (const ZAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const ZAsiData &) const;



    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue (const ZAsiData &);
    virtual EAsiBoolean   storeValue (const DB_NUMERIC *);

    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (ZAsiUcStr *) const;
    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const;

   
    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (ZAsiUcStr *) const;
    virtual EAsiBoolean   getValue (DB_NUMERIC *) const;

    virtual EAsiBoolean   getValue (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    
    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *) ;

 
    virtual ZAsiObject     *duplicate (void) const;

  
            ZAsiNumeric &operator= (const ZAsiSmallInt &);
            ZAsiNumeric &operator= (const ZAsiInt &);
            ZAsiNumeric &operator= (const ZAsiNumeric &);
            ZAsiNumeric &operator= (const ZAsiDecimal &);
            ZAsiNumeric &operator= (const ZAsiFloat &);
            ZAsiNumeric &operator= (const ZAsiReal &);
            ZAsiNumeric &operator= (const ZAsiDouble &);
            ZAsiNumeric &operator= (const smallint);
            ZAsiNumeric &operator= (const integer);
            ZAsiNumeric &operator= (const real);
            ZAsiNumeric &operator= (const int);


            ZAsiNumeric &operator+= (const ZAsiSmallInt &);
            ZAsiNumeric &operator+= (const ZAsiInt &);
            ZAsiNumeric &operator+= (const ZAsiNumeric &);
            ZAsiNumeric &operator+= (const ZAsiDecimal &);
            ZAsiNumeric &operator+= (const ZAsiFloat &);
            ZAsiNumeric &operator+= (const ZAsiReal &);
            ZAsiNumeric &operator+= (const ZAsiDouble &);
            ZAsiNumeric &operator+= (const smallint);
            ZAsiNumeric &operator+= (const integer);
            ZAsiNumeric &operator+= (const real);
            ZAsiNumeric &operator+= (const int);

            ZAsiNumeric &operator-= (const ZAsiSmallInt &);
            ZAsiNumeric &operator-= (const ZAsiInt &);
            ZAsiNumeric &operator-= (const ZAsiNumeric &);
            ZAsiNumeric &operator-= (const ZAsiDecimal &);
            ZAsiNumeric &operator-= (const ZAsiFloat &);
            ZAsiNumeric &operator-= (const ZAsiReal &);
            ZAsiNumeric &operator-= (const ZAsiDouble &);
            ZAsiNumeric &operator-= (const smallint);
            ZAsiNumeric &operator-= (const integer);
            ZAsiNumeric &operator-= (const real);
            ZAsiNumeric &operator-= (const int);

            ZAsiNumeric &operator*= (const ZAsiSmallInt &);
            ZAsiNumeric &operator*= (const ZAsiInt &);
            ZAsiNumeric &operator*= (const ZAsiNumeric &);
            ZAsiNumeric &operator*= (const ZAsiDecimal &);
            ZAsiNumeric &operator*= (const ZAsiFloat &);
            ZAsiNumeric &operator*= (const ZAsiReal &);
            ZAsiNumeric &operator*= (const ZAsiDouble &);
            ZAsiNumeric &operator*= (const smallint);
            ZAsiNumeric &operator*= (const integer);
            ZAsiNumeric &operator*= (const real);
            ZAsiNumeric &operator*= (const int);

            ZAsiNumeric &operator/= (const ZAsiSmallInt &);
            ZAsiNumeric &operator/= (const ZAsiInt &);
            ZAsiNumeric &operator/= (const ZAsiNumeric &);
            ZAsiNumeric &operator/= (const ZAsiDecimal &);
            ZAsiNumeric &operator/= (const ZAsiFloat &);
            ZAsiNumeric &operator/= (const ZAsiReal &);
            ZAsiNumeric &operator/= (const ZAsiDouble &);
            ZAsiNumeric &operator/= (const smallint);
            ZAsiNumeric &operator/= (const integer);
            ZAsiNumeric &operator/= (const real);
            ZAsiNumeric &operator/= (const int);

            ZAsiDouble operator+ (const ZAsiSmallInt &) const;
            ZAsiDouble operator+ (const ZAsiInt &)      const;
            ZAsiDouble operator+ (const ZAsiNumeric &)  const;
     friend ZAsiDouble DLLScope operator+ (const ZAsiSmallInt &, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiInt &, const ZAsiNumeric &);
            ZAsiDouble operator+ (const smallint) const;
            ZAsiDouble operator+ (const integer)  const;
            ZAsiDouble operator+ (const real)     const;
            ZAsiDouble operator+ (const int)      const;
     friend ZAsiDouble DLLScope operator+ (const smallint, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator+ (const integer, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator+ (const real, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator+ (const int, const ZAsiNumeric &);

            ZAsiDouble operator- (const ZAsiSmallInt &) const;
            ZAsiDouble operator- (const ZAsiInt &)      const;
            ZAsiDouble operator- (const ZAsiNumeric &)  const;
     friend ZAsiDouble DLLScope operator- (const ZAsiSmallInt &, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator- (const ZAsiInt &, const ZAsiNumeric &);
            ZAsiDouble operator- (const smallint) const;
            ZAsiDouble operator- (const integer)  const;
            ZAsiDouble operator- (const real)     const;
            ZAsiDouble operator- (const int)      const;
     friend ZAsiDouble DLLScope operator- (const smallint, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator- (const integer, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator- (const real, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator- (const int, const ZAsiNumeric &) ;

            ZAsiDouble operator* (const ZAsiSmallInt &) const;
            ZAsiDouble operator* (const ZAsiInt &)      const;
            ZAsiDouble operator* (const ZAsiNumeric &)  const;
     friend ZAsiDouble DLLScope operator* (const ZAsiSmallInt &, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator* (const ZAsiInt &, const ZAsiNumeric &);
            ZAsiDouble operator* (const smallint) const;
            ZAsiDouble operator* (const integer)  const;
            ZAsiDouble operator* (const real)     const;
            ZAsiDouble operator* (const int)      const;
     friend ZAsiDouble DLLScope operator* (const smallint, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator* (const integer, const ZAsiNumeric &) ;
     friend ZAsiDouble DLLScope operator* (const real, const ZAsiNumeric &)    ;
     friend ZAsiDouble DLLScope operator* (const int, const ZAsiNumeric &)     ;

            ZAsiDouble operator/ (const ZAsiSmallInt &) const;
            ZAsiDouble operator/ (const ZAsiInt &)      const;
            ZAsiDouble operator/ (const ZAsiNumeric &)  const;
     friend ZAsiDouble DLLScope operator/ (const ZAsiSmallInt &, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiInt &, const ZAsiNumeric &)     ;
            ZAsiDouble operator/ (const smallint) const;
            ZAsiDouble operator/ (const integer)  const;
            ZAsiDouble operator/ (const real)     const;
            ZAsiDouble operator/ (const int)      const;
     friend ZAsiDouble DLLScope operator/ (const smallint, const ZAsiNumeric &);
     friend ZAsiDouble DLLScope operator/ (const integer, const ZAsiNumeric &) ;
     friend ZAsiDouble DLLScope operator/ (const real, const ZAsiNumeric &)    ;
     friend ZAsiDouble DLLScope operator/ (const int, const ZAsiNumeric &)     ;

            ZAsiNumeric &operator++ (void);
            ZAsiNumeric &operator-- (void);

            ZAsiNumeric &operator- (void);

private:
        ASIBCD  bcdvalue;

};


class ZAsiDecimal: public ZAsiExactNum
{
friend class ZAsiNumeric;
private:

            EAsiBoolean SetDecimal (real);

public:
            ZAsiDecimal  (uint, uint);
            ZAsiDecimal  (uint);
            ZAsiDecimal  (const ZAsiDecimal &);
            ZAsiDecimal  (void);
    virtual ~ZAsiDecimal (void);


    virtual EAsiDataType Type          (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual ZAsiData *   checkAdd      (const ZAsiData *) const;
    virtual ZAsiData *   checkSub      (const ZAsiData *) const;
    virtual ZAsiData *   checkMul      (const ZAsiData *) const;
    virtual ZAsiData *   checkDiv      (const ZAsiData *) const;
    virtual ZAsiData *   checkSet      (const ZAsiData *) const;

    virtual EAsiBoolean  isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan (const ZAsiData &) const;


    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue (const ZAsiData &);
    virtual EAsiBoolean   storeValue (LARGE_INTEGER);
    virtual EAsiBoolean   storeValue (ULARGE_INTEGER);
    virtual EAsiBoolean   storeValue (const DECIMAL &);


    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (ZAsiUcStr *) const; 
    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const; 

    
    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (ZAsiUcStr *) const;
    virtual EAsiBoolean   getValue (LARGE_INTEGER *) const;
    virtual EAsiBoolean   getValue (ULARGE_INTEGER *) const;
    virtual EAsiBoolean   getValue (DECIMAL *) const;


    virtual EAsiBoolean   getValue (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue (ZAsiData &) const;


    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject   *duplicate (void) const;

            ZAsiDecimal &operator= (const ZAsiSmallInt &);
            ZAsiDecimal &operator= (const ZAsiInt &);
            ZAsiDecimal &operator= (const ZAsiNumeric &);
            ZAsiDecimal &operator= (const ZAsiDecimal &);
            ZAsiDecimal &operator= (const ZAsiFloat &);
            ZAsiDecimal &operator= (const ZAsiReal &);
            ZAsiDecimal &operator= (const ZAsiDouble &);
            ZAsiDecimal &operator= (const smallint);
            ZAsiDecimal &operator= (const integer);
            ZAsiDecimal &operator= (const real);
            ZAsiDecimal &operator= (const int);



            ZAsiDecimal &operator+= (const ZAsiSmallInt &);
            ZAsiDecimal &operator+= (const ZAsiInt &);
            ZAsiDecimal &operator+= (const ZAsiNumeric &);
            ZAsiDecimal &operator+= (const ZAsiDecimal &);
            ZAsiDecimal &operator+= (const ZAsiFloat &);
            ZAsiDecimal &operator+= (const ZAsiReal &);
            ZAsiDecimal &operator+= (const ZAsiDouble &);
            ZAsiDecimal &operator+= (const smallint);
            ZAsiDecimal &operator+= (const integer);
            ZAsiDecimal &operator+= (const real);
            ZAsiDecimal &operator+= (const int);

            ZAsiDecimal &operator-= (const ZAsiSmallInt &);
            ZAsiDecimal &operator-= (const ZAsiInt &);
            ZAsiDecimal &operator-= (const ZAsiNumeric &);
            ZAsiDecimal &operator-= (const ZAsiDecimal &);
            ZAsiDecimal &operator-= (const ZAsiFloat &);
            ZAsiDecimal &operator-= (const ZAsiReal &);
            ZAsiDecimal &operator-= (const ZAsiDouble &);
            ZAsiDecimal &operator-= (const smallint);
            ZAsiDecimal &operator-= (const integer);
            ZAsiDecimal &operator-= (const real);
            ZAsiDecimal &operator-= (const int);

            ZAsiDecimal &operator*= (const ZAsiSmallInt &);
            ZAsiDecimal &operator*= (const ZAsiInt &);
            ZAsiDecimal &operator*= (const ZAsiNumeric &);
            ZAsiDecimal &operator*= (const ZAsiDecimal &);
            ZAsiDecimal &operator*= (const ZAsiFloat &);
            ZAsiDecimal &operator*= (const ZAsiReal &);
            ZAsiDecimal &operator*= (const ZAsiDouble &);
            ZAsiDecimal &operator*= (const smallint);
            ZAsiDecimal &operator*= (const integer);
            ZAsiDecimal &operator*= (const real);
            ZAsiDecimal &operator*= (const int);

            ZAsiDecimal &operator/= (const ZAsiSmallInt &);
            ZAsiDecimal &operator/= (const ZAsiInt &);
            ZAsiDecimal &operator/= (const ZAsiNumeric &);
            ZAsiDecimal &operator/= (const ZAsiDecimal &);
            ZAsiDecimal &operator/= (const ZAsiFloat &);
            ZAsiDecimal &operator/= (const ZAsiReal &);
            ZAsiDecimal &operator/= (const ZAsiDouble &);
            ZAsiDecimal &operator/= (const smallint);
            ZAsiDecimal &operator/= (const integer);
            ZAsiDecimal &operator/= (const real);
            ZAsiDecimal &operator/= (const int);

            ZAsiDouble operator+ (const ZAsiSmallInt &) const;
            ZAsiDouble operator+ (const ZAsiInt &)      const;
            ZAsiDouble operator+ (const ZAsiNumeric &)  const;
            ZAsiDouble operator+ (const ZAsiDecimal &)  const;
     friend ZAsiDouble DLLScope operator+ (const ZAsiSmallInt &, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiInt &, const ZAsiDecimal &)     ;
     friend ZAsiDouble DLLScope operator+ (const ZAsiNumeric &, const ZAsiDecimal &) ;
            ZAsiDouble operator+ (const smallint) const;
            ZAsiDouble operator+ (const integer)  const;
            ZAsiDouble operator+ (const real)     const;
     friend ZAsiDouble DLLScope operator+ (const smallint, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator+ (const integer, const ZAsiDecimal &) ;
     friend ZAsiDouble DLLScope operator+ (const real, const ZAsiDecimal &)    ;
            ZAsiDouble operator+ (const int) const;
     friend ZAsiDouble operator+ (const int, const ZAsiDecimal &);


            ZAsiDouble operator- (const ZAsiSmallInt &) const;
            ZAsiDouble operator- (const ZAsiInt &)      const;
            ZAsiDouble operator- (const ZAsiNumeric &)  const;
            ZAsiDouble operator- (const ZAsiDecimal &)  const;
     friend ZAsiDouble DLLScope operator- (const ZAsiSmallInt &, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator- (const ZAsiInt &, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator- (const ZAsiNumeric &, const ZAsiDecimal &);
            ZAsiDouble operator- (const smallint) const;
            ZAsiDouble operator- (const integer)  const;
            ZAsiDouble operator- (const real)     const;
     friend ZAsiDouble DLLScope operator- (const smallint, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator- (const integer, const ZAsiDecimal &) ;
     friend ZAsiDouble DLLScope operator- (const real, const ZAsiDecimal &)    ;
            ZAsiDouble operator- (const int) const;
     friend ZAsiDouble DLLScope operator- (const int, const ZAsiDecimal &);

            ZAsiDouble operator* (const ZAsiSmallInt &) const;
            ZAsiDouble operator* (const ZAsiInt &)      const;
            ZAsiDouble operator* (const ZAsiNumeric &)  const;
            ZAsiDouble operator* (const ZAsiDecimal &)  const;
     friend ZAsiDouble DLLScope operator* (const ZAsiSmallInt &, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator* (const ZAsiInt &, const ZAsiDecimal &)     ;
     friend ZAsiDouble DLLScope operator* (const ZAsiNumeric &, const ZAsiDecimal &) ;
            ZAsiDouble operator* (const smallint) const;
            ZAsiDouble operator* (const integer)  const;
            ZAsiDouble operator* (const real)     const;
     friend ZAsiDouble DLLScope operator* (const smallint, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator* (const integer, const ZAsiDecimal &) ;
     friend ZAsiDouble DLLScope operator* (const real, const ZAsiDecimal &)    ;
            ZAsiDouble operator* (const int) const                         ;
     friend ZAsiDouble DLLScope operator* (const int, const ZAsiDecimal &)     ;

            ZAsiDouble operator/ (const ZAsiSmallInt &) const;
            ZAsiDouble operator/ (const ZAsiInt &)      const;
            ZAsiDouble operator/ (const ZAsiNumeric &)  const;
            ZAsiDouble operator/ (const ZAsiDecimal &)  const;
     friend ZAsiDouble DLLScope operator/ (const ZAsiSmallInt &, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiInt &, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiNumeric &, const ZAsiDecimal &);
            ZAsiDouble operator/ (const smallint) const;
            ZAsiDouble operator/ (const integer)  const;
            ZAsiDouble operator/ (const real)     const;
     friend ZAsiDouble DLLScope operator/ (const smallint, const ZAsiDecimal &);
     friend ZAsiDouble DLLScope operator/ (const integer, const ZAsiDecimal &) ;
     friend ZAsiDouble DLLScope operator/ (const real, const ZAsiDecimal &)    ;
            ZAsiDouble operator/ (const int) const;
     friend ZAsiDouble DLLScope operator/ (const int, const ZAsiDecimal &);

            ZAsiDecimal &operator++ (void);
            ZAsiDecimal &operator-- (void);
            ZAsiDecimal &operator- (void);

private:
    EAsiBoolean fmt;
    ASIBCD      bcdvalue;
    double      realvalue;

};



class ZAsiFloat: public ZAsiApproxNum
{
public:
                                ZAsiFloat               (void);
                                ZAsiFloat               (uint);
                                ZAsiFloat               (const ZAsiFloat &);
    virtual                     ~ZAsiFloat              (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual ZAsiData *   checkAdd       (const ZAsiData *) const;
    virtual ZAsiData *   checkSub       (const ZAsiData *) const;
    virtual ZAsiData *   checkMul       (const ZAsiData *) const;
    virtual ZAsiData *   checkDiv       (const ZAsiData *) const;
    virtual ZAsiData *   checkSet       (const ZAsiData *) const;


    virtual EAsiBoolean  isEqualTo      (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const ZAsiData &) const;


    virtual EAsiBoolean   storeValue    (real);
    virtual EAsiBoolean   storeValue    (integer);
    virtual EAsiBoolean   storeValue    (smallint);
    virtual EAsiBoolean   storeValue    (char *, uint);
    virtual EAsiBoolean   storeValue    (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue    (const ZAsiData &);


    virtual EAsiBoolean   storeValue    (char *, uint, uint *);
    virtual EAsiBoolean   storeValue    (const ZsiUcStr);

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType       (ZAsiUcStr *) const;
    virtual EAsiBoolean   SQLLiteral    (ZAsiUcStr *) const;

    virtual integer       intValue      (void) const;
    virtual real          realValue     (void) const;

    virtual EAsiBoolean   getValue              (real *) const;
    virtual EAsiBoolean   getValue              (integer *) const;
    virtual EAsiBoolean   getValue              (smallint *) const;
    virtual EAsiBoolean   getValue              (char *, uint) const;
    virtual EAsiBoolean   getValue              (ZAsiUcStr *) const;


    virtual EAsiBoolean   getValue              (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue              (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue              (ZAsiData &) const;

    virtual unsigned long packSize      (void) const;
    virtual unsigned long packTo        (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom    (ZAsiObjPack *);

    virtual unsigned long packValueSize (void)  const;
    virtual unsigned long packValueTo   (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);


    virtual ZAsiObject   *duplicate     (void) const;

            ZAsiFloat &operator= (const ZAsiSmallInt &);
            ZAsiFloat &operator= (const ZAsiInt &);
            ZAsiFloat &operator= (const ZAsiNumeric &);
            ZAsiFloat &operator= (const ZAsiDecimal &);
            ZAsiFloat &operator= (const ZAsiFloat &);
            ZAsiFloat &operator= (const ZAsiReal &);
            ZAsiFloat &operator= (const ZAsiDouble &);
            ZAsiFloat &operator= (const smallint);
            ZAsiFloat &operator= (const integer);
            ZAsiFloat &operator= (const real);
            ZAsiFloat &operator= (const int);


            ZAsiFloat &operator+= (const ZAsiSmallInt &);
            ZAsiFloat &operator+= (const ZAsiInt &);
            ZAsiFloat &operator+= (const ZAsiNumeric &);
            ZAsiFloat &operator+= (const ZAsiDecimal &);
            ZAsiFloat &operator+= (const ZAsiFloat &);
            ZAsiFloat &operator+= (const ZAsiReal &);
            ZAsiFloat &operator+= (const ZAsiDouble &);
            ZAsiFloat &operator+= (const smallint);
            ZAsiFloat &operator+= (const integer);
            ZAsiFloat &operator+= (const real);
            ZAsiFloat &operator+= (const int);

            ZAsiFloat &operator-= (const ZAsiSmallInt &);
            ZAsiFloat &operator-= (const ZAsiInt &);
            ZAsiFloat &operator-= (const ZAsiNumeric &);
            ZAsiFloat &operator-= (const ZAsiDecimal &);
            ZAsiFloat &operator-= (const ZAsiFloat &);
            ZAsiFloat &operator-= (const ZAsiReal &);
            ZAsiFloat &operator-= (const ZAsiDouble &);
            ZAsiFloat &operator-= (const smallint);
            ZAsiFloat &operator-= (const integer);
            ZAsiFloat &operator-= (const real);
            ZAsiFloat &operator-= (const int);

            ZAsiFloat &operator*= (const ZAsiSmallInt &);
            ZAsiFloat &operator*= (const ZAsiInt &);
            ZAsiFloat &operator*= (const ZAsiNumeric &);
            ZAsiFloat &operator*= (const ZAsiDecimal &);
            ZAsiFloat &operator*= (const ZAsiFloat &);
            ZAsiFloat &operator*= (const ZAsiReal &);
            ZAsiFloat &operator*= (const ZAsiDouble &);
            ZAsiFloat &operator*= (const smallint);
            ZAsiFloat &operator*= (const integer);
            ZAsiFloat &operator*= (const real);
            ZAsiFloat &operator*= (const int);

            ZAsiFloat &operator/= (const ZAsiSmallInt &);
            ZAsiFloat &operator/= (const ZAsiInt &);
            ZAsiFloat &operator/= (const ZAsiNumeric &);
            ZAsiFloat &operator/= (const ZAsiDecimal &);
            ZAsiFloat &operator/= (const ZAsiFloat &);
            ZAsiFloat &operator/= (const ZAsiReal &);
            ZAsiFloat &operator/= (const ZAsiDouble &);
            ZAsiFloat &operator/= (const smallint);
            ZAsiFloat &operator/= (const integer);
            ZAsiFloat &operator/= (const real);
            ZAsiFloat &operator/= (const int);

            ZAsiFloat operator+ (const ZAsiSmallInt &) const;
            ZAsiFloat operator+ (const ZAsiInt &)      const;
            ZAsiFloat operator+ (const ZAsiNumeric &)  const;
            ZAsiFloat operator+ (const ZAsiDecimal &)  const;
            ZAsiFloat operator+ (const ZAsiFloat &)    const;
     friend ZAsiFloat DLLScope operator+ (const ZAsiSmallInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator+ (const ZAsiInt &, const ZAsiFloat &)     ;
     friend ZAsiFloat DLLScope operator+ (const ZAsiNumeric &, const ZAsiFloat &) ;
     friend ZAsiFloat DLLScope operator+ (const ZAsiDecimal &, const ZAsiFloat &) ;
            ZAsiFloat operator+ (const smallint) const;
            ZAsiFloat operator+ (const integer)  const;
            ZAsiFloat operator+ (const real)     const;
     friend ZAsiFloat DLLScope operator+ (const smallint, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator+ (const integer, const ZAsiFloat &) ;
     friend ZAsiFloat DLLScope operator+ (const real, const ZAsiFloat &)    ;
            ZAsiFloat operator+ (const int) const;
     friend ZAsiFloat DLLScope operator+ (const int, const ZAsiFloat &);

            ZAsiFloat operator- (const ZAsiSmallInt &) const;
            ZAsiFloat operator- (const ZAsiInt &)      const;
            ZAsiFloat operator- (const ZAsiNumeric &)  const;
            ZAsiFloat operator- (const ZAsiDecimal &)  const;
            ZAsiFloat operator- (const ZAsiFloat &)    const;
     friend ZAsiFloat DLLScope operator- (const ZAsiSmallInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator- (const ZAsiInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator- (const ZAsiNumeric &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator- (const ZAsiDecimal &, const ZAsiFloat &);
            ZAsiFloat operator- (const smallint) const;
            ZAsiFloat operator- (const integer)  const;
            ZAsiFloat operator- (const real)     const;
     friend ZAsiFloat DLLScope operator- (const smallint, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator- (const integer, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator- (const real, const ZAsiFloat &);
            ZAsiFloat operator- (const int) const;
     friend ZAsiFloat DLLScope operator- (const int, const ZAsiFloat &);

            ZAsiFloat operator* (const ZAsiSmallInt &) const;
            ZAsiFloat operator* (const ZAsiInt &)      const;
            ZAsiFloat operator* (const ZAsiNumeric &)  const;
            ZAsiFloat operator* (const ZAsiDecimal &)  const;
            ZAsiFloat operator* (const ZAsiFloat &)    const;
     friend ZAsiFloat DLLScope operator* (const ZAsiSmallInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator* (const ZAsiInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator* (const ZAsiNumeric &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator* (const ZAsiDecimal &, const ZAsiFloat &);
            ZAsiFloat operator* (const smallint) const;
            ZAsiFloat operator* (const integer)  const;
            ZAsiFloat operator* (const real)     const;
     friend ZAsiFloat DLLScope operator* (const smallint, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator* (const integer, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator* (const real, const ZAsiFloat &);
            ZAsiFloat operator* (const int) const;
     friend ZAsiFloat DLLScope operator* (const int, const ZAsiFloat &);

            ZAsiFloat operator/ (const ZAsiSmallInt &) const;
            ZAsiFloat operator/ (const ZAsiInt &)      const;
            ZAsiFloat operator/ (const ZAsiNumeric &)  const;
            ZAsiFloat operator/ (const ZAsiDecimal &)  const;
            ZAsiFloat operator/ (const ZAsiFloat &)    const;
     friend ZAsiFloat DLLScope operator/ (const ZAsiSmallInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator/ (const ZAsiInt &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator/ (const ZAsiNumeric &, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator/ (const ZAsiDecimal &, const ZAsiFloat &);
            ZAsiFloat operator/ (const smallint) const;
            ZAsiFloat operator/ (const integer)  const;
            ZAsiFloat operator/ (const real)     const;
     friend ZAsiFloat DLLScope operator/ (const smallint, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator/ (const integer, const ZAsiFloat &);
     friend ZAsiFloat DLLScope operator/ (const real, const ZAsiFloat &)   ;
            ZAsiFloat operator/ (const int) const;
     friend ZAsiFloat DLLScope operator/ (const int, const ZAsiFloat &);

            ZAsiFloat &operator++ (void);
            ZAsiFloat &operator-- (void);
            ZAsiFloat &operator- (void);

private:
    real fvalue;
};



class ZAsiReal: public ZAsiApproxNum
{
public:
                                ZAsiReal                (void);
                                ZAsiReal                (const ZAsiReal &);
        virtual                 ~ZAsiReal               (void);

    virtual EAsiDataType        Type                    (void) const;
    virtual uint                ReturnLength    (void) const;

    virtual ZAsiData *          checkAdd        (const ZAsiData *) const;
    virtual ZAsiData *          checkSub        (const ZAsiData *) const;
    virtual ZAsiData *          checkMul        (const ZAsiData *) const;
    virtual ZAsiData *          checkDiv        (const ZAsiData *) const;
    virtual ZAsiData *          checkSet        (const ZAsiData *) const;

    virtual EAsiBoolean         isEqualTo       (const ZAsiData &) const;
    virtual EAsiBoolean         isGreaterThan   (const ZAsiData &) const;

    virtual EAsiBoolean         storeValue              (real);
    virtual EAsiBoolean         storeValue              (integer);
    virtual EAsiBoolean         storeValue              (smallint);
    virtual EAsiBoolean         storeValue              (char *, uint);
    virtual EAsiBoolean         storeValue              (const ZAsiUcStr &);
    virtual EAsiBoolean         storeValue              (const ZAsiData &);


    virtual EAsiBoolean         storeValue              (char *, uint, uint *);
    virtual EAsiBoolean         storeValue              (const ZAsiUcStr);

    virtual EAsiBoolean         SQLType                 (ZAsiUcStr *) const;
    virtual EAsiBoolean         SQLLiteral              (ZAsiUcStr *) const;

    
    virtual integer             intValue                (void) const;
    virtual real                realValue               (void) const;

    virtual EAsiBoolean         getValue                (real *) const;
    virtual EAsiBoolean         getValue                (integer *) const;
    virtual EAsiBoolean         getValue                (smallint *) const;
    virtual EAsiBoolean         getValue                (char *, uint) const;
    virtual EAsiBoolean         getValue                (ZAsiUcStr *) const;


    virtual EAsiBoolean         getValue                (char *, uint, uint *) const;
    virtual EAsiBoolean         getValue                (ZsiUcStr, uint) const;
    virtual EAsiBoolean         getValue                (ZAsiData &) const;

    virtual DBCOLUMNINFO *		MapAsiToColumnInfo		(DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *		MapAsiToParamInfo		(DBPARAMINFO *) const;




    virtual unsigned long       packSize        (void) const;
    virtual unsigned long       packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean         unpackFrom      (ZAsiObjPack *);

    virtual unsigned long       packValueSize   (void)  const;
    virtual unsigned long       packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean         unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject   *      duplicate               (void) const;

            ZAsiReal &operator= (const ZAsiSmallInt &);
            ZAsiReal &operator= (const ZAsiInt &);
            ZAsiReal &operator= (const ZAsiNumeric &);
            ZAsiReal &operator= (const ZAsiDecimal &);
            ZAsiReal &operator= (const ZAsiFloat &);
            ZAsiReal &operator= (const ZAsiReal &);
            ZAsiReal &operator= (const ZAsiDouble &);
            ZAsiReal &operator= (const smallint);
            ZAsiReal &operator= (const integer);
            ZAsiReal &operator= (const real);
            ZAsiReal &operator= (const int);


            ZAsiReal &operator+= (const ZAsiSmallInt &);
            ZAsiReal &operator+= (const ZAsiInt &);
            ZAsiReal &operator+= (const ZAsiNumeric &);
            ZAsiReal &operator+= (const ZAsiDecimal &);
            ZAsiReal &operator+= (const ZAsiFloat &);
            ZAsiReal &operator+= (const ZAsiReal &);
            ZAsiReal &operator+= (const ZAsiDouble &);
            ZAsiReal &operator+= (const smallint);
            ZAsiReal &operator+= (const integer);
            ZAsiReal &operator+= (const real);
            ZAsiReal &operator+= (const int);

            ZAsiReal &operator-= (const ZAsiSmallInt &);
            ZAsiReal &operator-= (const ZAsiInt &);
            ZAsiReal &operator-= (const ZAsiNumeric &);
            ZAsiReal &operator-= (const ZAsiDecimal &);
            ZAsiReal &operator-= (const ZAsiFloat &);
            ZAsiReal &operator-= (const ZAsiReal &);
            ZAsiReal &operator-= (const ZAsiDouble &);
            ZAsiReal &operator-= (const smallint);
            ZAsiReal &operator-= (const integer);
            ZAsiReal &operator-= (const real);
            ZAsiReal &operator-= (const int);

            ZAsiReal &operator*= (const ZAsiSmallInt &);
            ZAsiReal &operator*= (const ZAsiInt &);
            ZAsiReal &operator*= (const ZAsiNumeric &);
            ZAsiReal &operator*= (const ZAsiDecimal &);
            ZAsiReal &operator*= (const ZAsiFloat &);
            ZAsiReal &operator*= (const ZAsiReal &);
            ZAsiReal &operator*= (const ZAsiDouble &);
            ZAsiReal &operator*= (const smallint);
            ZAsiReal &operator*= (const integer);
            ZAsiReal &operator*= (const real);
            ZAsiReal &operator*= (const int);

            ZAsiReal &operator/= (const ZAsiSmallInt &);
            ZAsiReal &operator/= (const ZAsiInt &);
            ZAsiReal &operator/= (const ZAsiNumeric &);
            ZAsiReal &operator/= (const ZAsiDecimal &);
            ZAsiReal &operator/= (const ZAsiFloat &);
            ZAsiReal &operator/= (const ZAsiReal &);
            ZAsiReal &operator/= (const ZAsiDouble &);
            ZAsiReal &operator/= (const smallint);
            ZAsiReal &operator/= (const integer);
            ZAsiReal &operator/= (const real);
            ZAsiReal &operator/= (const int);

            ZAsiReal operator+ (const ZAsiSmallInt &) const;
            ZAsiReal operator+ (const ZAsiInt &)      const;
            ZAsiReal operator+ (const ZAsiNumeric &)  const;
            ZAsiReal operator+ (const ZAsiDecimal &)  const;
            ZAsiReal operator+ (const ZAsiFloat &)    const;
            ZAsiReal operator+ (const ZAsiReal &)     const;
     friend ZAsiReal DLLScope operator+ (const ZAsiSmallInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator+ (const ZAsiInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator+ (const ZAsiNumeric &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator+ (const ZAsiDecimal &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator+ (const ZAsiFloat &, const ZAsiReal &)  ;
            ZAsiReal operator+ (const smallint) const;
            ZAsiReal operator+ (const integer)  const;
            ZAsiReal operator+ (const real)     const;
     friend ZAsiReal DLLScope operator+ (const smallint, const ZAsiReal &);
     friend ZAsiReal DLLScope operator+ (const integer, const ZAsiReal &) ;
     friend ZAsiReal DLLScope operator+ (const real, const ZAsiReal &)    ;
            ZAsiReal operator+ (const int) const;
     friend ZAsiReal DLLScope operator+ (const int, const ZAsiReal &);

            ZAsiReal operator- (const ZAsiSmallInt &) const;
            ZAsiReal operator- (const ZAsiInt &)      const;
            ZAsiReal operator- (const ZAsiNumeric &)  const;
            ZAsiReal operator- (const ZAsiDecimal &)  const;
            ZAsiReal operator- (const ZAsiFloat &)    const;
            ZAsiReal operator- (const ZAsiReal &)     const;
     friend ZAsiReal DLLScope operator- (const ZAsiSmallInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator- (const ZAsiInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator- (const ZAsiNumeric &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator- (const ZAsiDecimal &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator- (const ZAsiFloat &, const ZAsiReal &)  ;
            ZAsiReal operator- (const smallint) const;
            ZAsiReal operator- (const integer)  const;
            ZAsiReal operator- (const real)     const;
     friend ZAsiReal DLLScope operator- (const smallint, const ZAsiReal &);
     friend ZAsiReal DLLScope operator- (const integer, const ZAsiReal &);
     friend ZAsiReal DLLScope operator- (const real, const ZAsiReal &);
            ZAsiReal operator- (const int) const;
     friend ZAsiReal DLLScope operator- (const int, const ZAsiReal &);

            ZAsiReal operator* (const ZAsiSmallInt &) const;
            ZAsiReal operator* (const ZAsiInt &)      const;
            ZAsiReal operator* (const ZAsiNumeric &)  const;
            ZAsiReal operator* (const ZAsiDecimal &)  const;
            ZAsiReal operator* (const ZAsiFloat &)    const;
            ZAsiReal operator* (const ZAsiReal &)     const;
     friend ZAsiReal DLLScope operator* (const ZAsiSmallInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator* (const ZAsiInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator* (const ZAsiNumeric &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator* (const ZAsiDecimal &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator* (const ZAsiFloat &, const ZAsiReal &)  ;
            ZAsiReal operator* (const smallint) const;
            ZAsiReal operator* (const integer)  const;
            ZAsiReal operator* (const real)     const;
     friend ZAsiReal DLLScope operator* (const smallint, const ZAsiReal &);
     friend ZAsiReal DLLScope operator* (const integer, const ZAsiReal &) ;
     friend ZAsiReal DLLScope operator* (const real, const ZAsiReal &)    ;
            ZAsiReal operator* (const int) const;
     friend ZAsiReal DLLScope operator* (const int, const ZAsiReal &);

            ZAsiReal operator/ (const ZAsiSmallInt &) const;
            ZAsiReal operator/ (const ZAsiInt &)      const;
            ZAsiReal operator/ (const ZAsiNumeric &)  const;
            ZAsiReal operator/ (const ZAsiDecimal &)  const;
            ZAsiReal operator/ (const ZAsiFloat &)    const;
            ZAsiReal operator/ (const ZAsiReal &)     const;
     friend ZAsiReal DLLScope operator/ (const ZAsiSmallInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator/ (const ZAsiInt &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator/ (const ZAsiNumeric &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator/ (const ZAsiDecimal &, const ZAsiReal &);
     friend ZAsiReal DLLScope operator/ (const ZAsiFloat &, const ZAsiReal &)  ;
            ZAsiReal operator/ (const smallint) const;
            ZAsiReal operator/ (const integer)  const;
            ZAsiReal operator/ (const real)     const;
     friend ZAsiReal DLLScope operator/ (const smallint, const ZAsiReal &);
     friend ZAsiReal DLLScope operator/ (const integer, const ZAsiReal &) ;
     friend ZAsiReal DLLScope operator/ (const real, const ZAsiReal &);
            ZAsiReal operator/ (const int) const;
     friend ZAsiReal DLLScope operator/ (const int, const ZAsiReal &);

            ZAsiReal &operator++ (void);
            ZAsiReal &operator-- (void);
            ZAsiReal &operator- (void);

private:
    real rvalue;
};



class ZAsiDouble: public ZAsiApproxNum
{
public:
                                ZAsiDouble              (void);
                                ZAsiDouble              (const ZAsiDouble &);
    virtual                     ~ZAsiDouble     (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual ZAsiData *   checkAdd       (const ZAsiData *) const;
    virtual ZAsiData *   checkSub       (const ZAsiData *) const;
    virtual ZAsiData *   checkMul       (const ZAsiData *) const;
    virtual ZAsiData *   checkDiv       (const ZAsiData *) const;
    virtual ZAsiData *   checkSet       (const ZAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const ZAsiData &) const;

    virtual EAsiBoolean   storeValue    (real);
    virtual EAsiBoolean   storeValue    (integer);
    virtual EAsiBoolean   storeValue    (smallint);
    virtual EAsiBoolean   storeValue    (char *, uint);
    virtual EAsiBoolean   storeValue    (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue    (const ZAsiData &);


    virtual EAsiBoolean   storeValue    (char *, uint, uint *);
    virtual EAsiBoolean   storeValue    (const ZsiUcStr);

    virtual integer       intValue      (void) const;
    virtual real          realValue     (void) const;

    virtual EAsiBoolean   getValue              (real *) const;
    virtual EAsiBoolean   getValue              (integer *) const;
    virtual EAsiBoolean   getValue              (smallint *) const;
    virtual EAsiBoolean   getValue              (char *, uint) const;
    virtual EAsiBoolean   getValue              (ZAsiUcStr *) const;


    virtual EAsiBoolean   getValue              (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue              (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue              (ZAsiData &) const;

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean   SQLType       (ZAsiUcStr *) const;
    virtual EAsiBoolean   SQLLiteral    (ZAsiUcStr *) const;


    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject   *duplicate (void) const;

            ZAsiDouble &operator= (const ZAsiSmallInt &);
            ZAsiDouble &operator= (const ZAsiInt &);
            ZAsiDouble &operator= (const ZAsiNumeric &);
            ZAsiDouble &operator= (const ZAsiDecimal &);
            ZAsiDouble &operator= (const ZAsiFloat &);
            ZAsiDouble &operator= (const ZAsiReal &);
            ZAsiDouble &operator= (const ZAsiDouble &);
            ZAsiDouble &operator= (const smallint);
            ZAsiDouble &operator= (const integer);
            ZAsiDouble &operator= (const real);
            ZAsiDouble &operator= (const int);


            ZAsiDouble &operator+= (const ZAsiSmallInt &);
            ZAsiDouble &operator+= (const ZAsiInt &);
            ZAsiDouble &operator+= (const ZAsiNumeric &);
            ZAsiDouble &operator+= (const ZAsiDecimal &);
            ZAsiDouble &operator+= (const ZAsiFloat &);
            ZAsiDouble &operator+= (const ZAsiReal &);
            ZAsiDouble &operator+= (const ZAsiDouble &);
            ZAsiDouble &operator+= (const smallint);
            ZAsiDouble &operator+= (const integer);
            ZAsiDouble &operator+= (const real);
            ZAsiDouble &operator+= (const int);

            ZAsiDouble &operator-= (const ZAsiSmallInt &);
            ZAsiDouble &operator-= (const ZAsiInt &);
            ZAsiDouble &operator-= (const ZAsiNumeric &);
            ZAsiDouble &operator-= (const ZAsiDecimal &);
            ZAsiDouble &operator-= (const ZAsiFloat &);
            ZAsiDouble &operator-= (const ZAsiReal &);
            ZAsiDouble &operator-= (const ZAsiDouble &);
            ZAsiDouble &operator-= (const smallint);
            ZAsiDouble &operator-= (const integer);
            ZAsiDouble &operator-= (const real);
            ZAsiDouble &operator-= (const int);

            ZAsiDouble &operator*= (const ZAsiSmallInt &);
            ZAsiDouble &operator*= (const ZAsiInt &);
            ZAsiDouble &operator*= (const ZAsiNumeric &);
            ZAsiDouble &operator*= (const ZAsiDecimal &);
            ZAsiDouble &operator*= (const ZAsiFloat &);
            ZAsiDouble &operator*= (const ZAsiReal &);
            ZAsiDouble &operator*= (const ZAsiDouble &);
            ZAsiDouble &operator*= (const smallint);
            ZAsiDouble &operator*= (const integer);
            ZAsiDouble &operator*= (const real);
            ZAsiDouble &operator*= (const int);

            ZAsiDouble &operator/= (const ZAsiSmallInt &);
            ZAsiDouble &operator/= (const ZAsiInt &);
            ZAsiDouble &operator/= (const ZAsiNumeric &);
            ZAsiDouble &operator/= (const ZAsiDecimal &);
            ZAsiDouble &operator/= (const ZAsiFloat &);
            ZAsiDouble &operator/= (const ZAsiReal &);
            ZAsiDouble &operator/= (const ZAsiDouble &);
            ZAsiDouble &operator/= (const smallint);
            ZAsiDouble &operator/= (const integer);
            ZAsiDouble &operator/= (const real);
            ZAsiDouble &operator/= (const int);

            ZAsiDouble operator+ (const ZAsiSmallInt &) const;
            ZAsiDouble operator+ (const ZAsiInt &)      const;
            ZAsiDouble operator+ (const ZAsiNumeric &)  const;
            ZAsiDouble operator+ (const ZAsiDecimal &)  const;
            ZAsiDouble operator+ (const ZAsiFloat &)    const;
            ZAsiDouble operator+ (const ZAsiReal &)     const;
            ZAsiDouble operator+ (const ZAsiDouble &)   const;
     friend ZAsiDouble DLLScope operator+ (const ZAsiSmallInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiNumeric &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiDecimal &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiFloat &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator+ (const ZAsiReal &, const ZAsiDouble &);
            ZAsiDouble operator+ (const smallint) const;
            ZAsiDouble operator+ (const integer)  const;
            ZAsiDouble operator+ (const real)     const;
     friend ZAsiDouble DLLScope operator+ (const smallint, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator+ (const integer, const ZAsiDouble &) ;
     friend ZAsiDouble DLLScope operator+ (const real, const ZAsiDouble &)    ;
            ZAsiDouble operator+ (const int) const;
     friend ZAsiDouble DLLScope operator+ (const int, const ZAsiDouble &);

            ZAsiDouble operator- (const ZAsiSmallInt &) const;
            ZAsiDouble operator- (const ZAsiInt &)      const;
            ZAsiDouble operator- (const ZAsiNumeric &)  const;
            ZAsiDouble operator- (const ZAsiDecimal &)  const;
            ZAsiDouble operator- (const ZAsiFloat &)    const;
            ZAsiDouble operator- (const ZAsiReal &)     const;
            ZAsiDouble operator- (const ZAsiDouble &)   const;
     friend ZAsiDouble DLLScope operator- (const ZAsiSmallInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator- (const ZAsiInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator- (const ZAsiNumeric &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator- (const ZAsiDecimal &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator- (const ZAsiFloat &, const ZAsiDouble &)  ;
     friend ZAsiDouble DLLScope operator- (const ZAsiReal &, const ZAsiDouble &);
            ZAsiDouble operator- (const smallint) const;
            ZAsiDouble operator- (const integer)  const;
            ZAsiDouble operator- (const real)     const;
     friend ZAsiDouble DLLScope operator- (const smallint, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator- (const integer, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator- (const real, const ZAsiDouble &);
            ZAsiDouble operator- (const int) const;
     friend ZAsiDouble DLLScope operator- (const int, const ZAsiDouble &);

            ZAsiDouble operator* (const ZAsiSmallInt &) const;
            ZAsiDouble operator* (const ZAsiInt &)      const;
            ZAsiDouble operator* (const ZAsiNumeric &)  const;
            ZAsiDouble operator* (const ZAsiDecimal &)  const;
            ZAsiDouble operator* (const ZAsiFloat &)    const;
            ZAsiDouble operator* (const ZAsiReal &)     const;
            ZAsiDouble operator* (const ZAsiDouble &)   const;
     friend ZAsiDouble DLLScope operator* (const ZAsiSmallInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const ZAsiInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const ZAsiNumeric &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const ZAsiDecimal &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const ZAsiFloat &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const ZAsiReal &, const ZAsiDouble &);
            ZAsiDouble operator* (const smallint) const;
            ZAsiDouble operator* (const integer) const;
            ZAsiDouble operator* (const real) const;
     friend ZAsiDouble DLLScope operator* (const smallint, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const integer, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator* (const real, const ZAsiDouble &);
            ZAsiDouble operator* (const int) const;
     friend ZAsiDouble DLLScope operator* (const int, const ZAsiDouble &);

            ZAsiDouble operator/ (const ZAsiSmallInt &) const;
            ZAsiDouble operator/ (const ZAsiInt &)      const;
            ZAsiDouble operator/ (const ZAsiNumeric &)  const;
            ZAsiDouble operator/ (const ZAsiDecimal &)  const;
            ZAsiDouble operator/ (const ZAsiFloat &)    const;
            ZAsiDouble operator/ (const ZAsiReal &)     const;
            ZAsiDouble operator/ (const ZAsiDouble &)   const;
     friend ZAsiDouble DLLScope operator/ (const ZAsiSmallInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiInt &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiNumeric &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiDecimal &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiFloat &, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const ZAsiReal &, const ZAsiDouble &);
            ZAsiDouble operator/ (const smallint) const;
            ZAsiDouble operator/ (const integer)  const;
            ZAsiDouble operator/ (const real)     const;
     friend ZAsiDouble DLLScope operator/ (const smallint, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const integer, const ZAsiDouble &);
     friend ZAsiDouble DLLScope operator/ (const real, const ZAsiDouble &);
            ZAsiDouble operator/ (const int) const;
     friend ZAsiDouble DLLScope operator/ (const int, const ZAsiDouble &);

            ZAsiDouble &operator++ (void);
            ZAsiDouble &operator-- (void);
            ZAsiDouble &operator- (void);


private:
    real dvalue;
};



class ZAsiChar: public ZAsiData
{
friend class ZAsiTempTable;
public:
                                        ZAsiChar                ();
                                        ZAsiChar                (uint);
                                        ZAsiChar                (const ZAsiChar &);
        virtual                                 ~ZAsiChar               ();



    void                                setVarying      (void);
    void                                setNational     (void);
    void                                setCharSet      (const ZAsiUcStr &);
    void                                setDefCharSet   (void);
    void                                setCollName     (const ZAsiUcStr &);
    void                                setCollIdent    (ZsiUcIdCLT);
    void                                setCoerc        (EAsiCAttr);


    virtual EAsiDataType    Type                (void) const;
    virtual uint            Length              (void) const;
    virtual uint            ReturnLength        (void) const;

    uint                        ByteSize        (void) const;
    const ZAsiUcStr   &         CollName        (void) const;
    const ZAsiUcStr   &         CharSetName     (void) const;
    ZsiUcIdCLT                  CollIdent       (void) const;
    ZsiUcIdCCT                  CharSetIdent    (void) const;
    EAsiCAttr                   Coercibility    (void) const;

    virtual EAsiBoolean         is_character    (void) const;
    virtual EAsiBoolean         is_comparable   (const ZAsiData *) const;
    virtual EAsiBoolean         is_storable     (const ZAsiData *) const;
    virtual EAsiBoolean         is_castable     (const ZAsiData *) const;
            EAsiBoolean         is_national     (void) const;

    virtual ZAsiData *          checkCat        (const ZAsiData *) const;
    virtual ZAsiData *          checkSet        (const ZAsiData *) const;

    virtual EAsiBoolean         isEqualTo       (const ZAsiData &) const;
    virtual EAsiBoolean         isGreaterThan   (const ZAsiData &) const;


    virtual EAsiBoolean         storeValue              (real);
    virtual EAsiBoolean         storeValue              (integer);
    virtual EAsiBoolean         storeValue              (smallint);
    virtual EAsiBoolean         storeValue              (char *, uint);
            EAsiBoolean         storeValue              (char *, uint, ZsiUcIdCCT);
    virtual EAsiBoolean         storeValue              (const ZAsiUcStr &);
    virtual EAsiBoolean         storeValue              (const ZAsiData &);
    virtual EAsiBoolean         storeValue              (const ZsiUcStr);
            EAsiBoolean         storeValue              (GUID *);
    virtual EAsiBoolean         storeValue              (char *, uint, uint *);

    const ZAsiUcStr  &      charValue (void) const;

    virtual EAsiBoolean         getValue                (real *) const;
    virtual EAsiBoolean         getValue                (integer *) const;
    virtual EAsiBoolean         getValue                (smallint *) const;
    virtual EAsiBoolean         getValue                (char *, uint) const;
    virtual EAsiBoolean         getValue                (ZAsiUcStr *) const;
    virtual EAsiBoolean         getValue                (char *, uint, uint *) const; 
    virtual EAsiBoolean         getValue                (ZsiUcStr, uint) const;
    virtual EAsiBoolean         getValue                (ZAsiData &) const;
            EAsiBoolean         getValue                (GUID *) const;

    virtual DBCOLUMNINFO *		MapAsiToColumnInfo		(DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *		MapAsiToParamInfo		(DBPARAMINFO *) const;


    virtual EAsiBoolean         SQLType                 (ZAsiUcStr *) const;
    virtual EAsiBoolean         SQLLiteral              (ZAsiUcStr *) const;

    
    
    virtual unsigned long       packSize        (void)  const;
    virtual unsigned long       packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean         unpackFrom      (ZAsiObjPack *);

    virtual unsigned long       packValueSize   (void)  const;
    virtual unsigned long       packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean         unpackValueFrom (ZAsiObjPack *);


   
    virtual ZAsiObject   *      duplicate               (void) const;

   

    virtual void                Clear                   (void);

   
    EAsiBoolean                         Like                    (const ZAsiChar &, const ZAsiChar &) const;
    ZAsiChar                            Substring               (uint) const;
    ZAsiChar                            Substring               (uint, uint) const;
    ZAsiChar                            Upper                   (void) const;
    ZAsiChar                            Lower                   (void) const;
    ZAsiChar                            Trim                    (EAsiTrimSpec, const ZAsiChar &) const;
    ZAsiNumeric                         Position                (const ZAsiChar &) const;

   
            ZAsiChar  & operator=  (const ZAsiChar &);
            ZAsiChar  & operator=  (const ZAsiUcStr &);

            ZAsiChar    operator+  (const ZAsiChar &) const;
            ZAsiChar    operator+  (const ZAsiUcStr &) const;

            int         operator>  (const ZAsiChar &) const;
            int         operator>  (const ZAsiUcStr &) const;
     friend int         DLLScope operator>  (const ZAsiUcStr &, const ZAsiChar &);

            int         operator>=  (const ZAsiChar &) const;
            int         operator>=  (const ZAsiUcStr &) const;
     friend int         DLLScope operator>=  (const ZAsiUcStr &, const ZAsiChar &);

            int         operator==  (const ZAsiChar &) const;
            int         operator==  (const ZAsiUcStr &) const;
     friend int         DLLScope operator==  (const ZAsiUcStr &, const ZAsiChar &);

            int         operator<=  (const ZAsiChar &) const;
            int         operator<=  (const ZAsiUcStr &) const;
     friend int         DLLScope operator<=  (const ZAsiUcStr &, const ZAsiChar &);

            int         operator<  (const ZAsiChar &) const;
            int         operator<  (const ZAsiUcStr &) const;
     friend int         DLLScope operator<  (const ZAsiUcStr &, const ZAsiChar &);

            int         operator!=  (const ZAsiChar &) const;
            int         operator!=  (const ZAsiUcStr &) const;
     friend int         DLLScope operator!=  (const ZAsiUcStr &, const ZAsiChar &);

private:

    EAsiBoolean     isCompColSet(const ZsiUcIdCLT, EAsiCAttr) const;
    ZsiUcIdCLT      CompColSet(const ZsiUcIdCLT, EAsiCAttr) const;
    EAsiBoolean     isDyadicOpColSet(const ZsiUcIdCLT, EAsiCAttr) const;
    ZsiUcIdCLT      DyadicOpColSet(const ZsiUcIdCLT, EAsiCAttr *, EAsiCAttr) const;

private:

    uint                maxlength;
    uint                retlength;
    ZAsiUcStr           chvalue;  

    short           mod;                
    ZsiUcIdCCT      CharSetId;          
    ZAsiUcStr       CharSet;            
    ZsiUcIdCLT      ColId;              
    ZAsiUcStr       CName;              
    EAsiCAttr       coercibility;      
};


class ZAsiBinary: public ZAsiData
{
friend class ZAsiTempTable;
public:
            ZAsiBinary  ();
            ZAsiBinary  (uint);
            ZAsiBinary  (const ZAsiBinary &);
    virtual ~ZAsiBinary ();



    void          setVarying    (void);

    virtual EAsiDataType Type         (void) const;
    virtual uint         Length       (void) const;
    virtual uint         ReturnLength (void) const;


   
    virtual EAsiBoolean   is_binary     (void) const;
    virtual EAsiBoolean   is_comparable (const ZAsiData *) const;
    virtual EAsiBoolean   is_storable   (const ZAsiData *) const;
    virtual EAsiBoolean   is_castable   (const ZAsiData *) const;

    virtual ZAsiData *    checkCat      (const ZAsiData *) const;
    virtual ZAsiData *    checkSet      (const ZAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const ZAsiData &) const;

   
            EAsiBoolean   storeHexValue (char *, uint, uint *);
            EAsiBoolean   storeHexValue (const ZAsiUcStr &);
            EAsiBoolean   storeBinValue (char *, uint, uint *);
            EAsiBoolean   storeBinValue (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue    (char *, uint);
    virtual EAsiBoolean   storeValue    (char *, uint, uint *);
    virtual EAsiBoolean   storeValue    (const ZAsiData &);


    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (integer);              
    virtual EAsiBoolean   storeValue (smallint);             
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &);    
    virtual EAsiBoolean   storeValue (const ZsiUcStr);       


   
            EAsiBoolean   getHexValue (char *, uint, uint *) const;
            EAsiBoolean   getHexValue (ZAsiUcStr *) const;
            EAsiBoolean   getBinValue (char *, uint, uint *) const;
            EAsiBoolean   getBinValue (ZAsiUcStr *) const;
    virtual EAsiBoolean   getValue    (char *, uint) const;
    virtual EAsiBoolean   getValue    (char *, uint, uint *) const;


    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (integer *) const;            
    virtual EAsiBoolean   getValue (smallint *) const;           
    virtual EAsiBoolean   getValue (ZAsiUcStr *) const;          
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean   SQLType    (ZAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const;        


   
    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);




   
    virtual ZAsiObject   *duplicate(void) const;

   

    virtual void          Clear     (void);

   
    ZAsiBinary Substring(uint);
    ZAsiBinary Substring(uint,uint);

   
            ZAsiBinary   &operator= (const ZAsiBinary &);

      
            ZAsiBinary  operator+  (const ZAsiBinary &) const;

            int         operator>  (const ZAsiBinary &) const;
            int         operator>= (const ZAsiBinary &) const;
            int         operator== (const ZAsiBinary &) const;
            int         operator<= (const ZAsiBinary &) const;
            int         operator<  (const ZAsiBinary &) const;
            int         operator!= (const ZAsiBinary &) const;


private:
    uint       blength;   
    uint       alength;   
    uint       buflen;    
    uchar    * value;     
    short      mod;       
};


class ZAsiIQualifier : public ZAsiData
{
friend class ZAsiInterval;
friend class ZAsiDatetime;

public:
                ZAsiIQualifier (void);
               ZAsiIQualifier (EAsiIType);
               ZAsiIQualifier (EAsiIType, uint);
               ZAsiIQualifier (EAsiIType, uint, uint);
               ZAsiIQualifier (const ZAsiIQualifier &);
    virtual   ~ZAsiIQualifier (void);

 
    virtual EAsiBoolean  setIType         (EAsiIType);
            void         setLeadFieldPrec (uint);       
            void         setFracSecPrec   (uint);       

 
    virtual EAsiDataType Type          (void) const;
    virtual EAsiIType    IntervalType  (void) const;
    virtual uint         LeadFieldPrec (void) const;
    virtual uint         FracSecPrec   (void) const;
    virtual uint         ReturnLength  (void) const;


    virtual EAsiBoolean  is_interval     (void) const;
    virtual EAsiBoolean  is_yminterval   (void) const;
    virtual EAsiBoolean  is_dtinterval   (void) const;
    virtual EAsiBoolean  is_storable     (const ZAsiData *) const;
    virtual EAsiBoolean  is_comparable   (const ZAsiData *) const;
            EAsiBoolean  is_moreaccurate (const ZAsiIQualifier *) const;

    virtual EAsiBoolean  SQLType       (ZAsiUcStr *) const; 

private:
    virtual EAsiBoolean  SQLLiteral    (ZAsiUcStr *) const; 

public:
	ZAsiIQualifier &operator= (const ZAsiIQualifier &);

    virtual ZAsiObject   *duplicate(void) const;

protected:
    EAsiIType itype;
    uint lfp;
    uint fsp;
};



class ZAsiInterval : public ZAsiIQualifier
{
friend class ZAsiDate;
friend class ZAsiTime;
friend class ZAsiTimeStamp;

public:
  
            ZAsiInterval                (void);
    virtual ~ZAsiInterval               (void);

    virtual EAsiBoolean   SQLType       (ZAsiUcStr *)      const;

    virtual ZAsiData *    checkAdd      (const ZAsiData *) const;
    virtual ZAsiData *    checkSub      (const ZAsiData *) const;
    virtual ZAsiData *    checkMul      (const ZAsiData *) const;
    virtual ZAsiData *    checkDiv      (const ZAsiData *) const;
    virtual ZAsiData *    checkSet      (const ZAsiData *) const;


            void          setSign  (EAsiBoolean);
            EAsiBoolean   Sign          (void)             const;


protected:
    EAsiBoolean sign;
};



class ZAsiYM : public ZAsiInterval
{
friend class ZAsiDate;
friend class ZAsiTime;
friend class ZAsiTimeStamp;
friend class ZAsiTempTable;

public:

            ZAsiYM (void);
            ZAsiYM (EAsiIType);
            ZAsiYM (EAsiIType, uint);
            ZAsiYM (const ZAsiYM &);
    virtual ~ZAsiYM (void);

    virtual EAsiBoolean   setIType      (EAsiIType);    

    virtual EAsiBoolean   is_castable   (const ZAsiData *) const;


    virtual EAsiBoolean   isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const ZAsiData &) const;


    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue (const ZAsiData &);

    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);

       EAsiBoolean   set       (ASI_IYEAR *);
       EAsiBoolean   set       (ASI_IYEARTOMONTH *);
       EAsiBoolean   set       (ASI_IMONTH *);
       EAsiBoolean   set       (EAsiBoolean, uint, uint);
       EAsiBoolean   setYears  (uint);
       EAsiBoolean   setMonths (uint);

   
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (ZAsiUcStr *) const;

    
    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const;        

            EAsiBoolean   get       (ASI_IYEAR *)        const;
            EAsiBoolean   get       (ASI_IYEARTOMONTH *) const;
            EAsiBoolean   get       (ASI_IMONTH *)       const;
            EAsiBoolean   get       (EAsiBoolean *, uint *, uint *) const;
            EAsiBoolean   getYears  (uint *) const;
            EAsiBoolean   getMonths (uint *) const;


    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject   *duplicate (void) const;


        ZAsiYM       &operator=  (const ZAsiYM &);
        ZAsiYM       &operator=  (const ZAsiSmallInt &);
        ZAsiYM       &operator=  (const ZAsiInt &);
        ZAsiYM       &operator=  (const ZAsiNumeric &);
        ZAsiYM       &operator=  (const ZAsiDecimal &);
        ZAsiYM       &operator=  (integer);

        ZAsiYM       operator+  (const ZAsiYM &) const;
friend  ZAsiDate DLLScope operator+  (const ZAsiYM &, const ZAsiDate &);
        ZAsiYM       operator-  (const ZAsiYM &) const;

       ZAsiYM       operator*  (const ZAsiSmallInt &) const;
       ZAsiYM       operator*  (const ZAsiInt &) const;
       ZAsiYM       operator*  (const ZAsiNumeric &) const;
       ZAsiYM       operator*  (const ZAsiDecimal &) const;
       ZAsiYM       operator*  (integer) const;
friend ZAsiYM DLLScope operator*  (const ZAsiSmallInt &,const ZAsiYM &);
friend ZAsiYM DLLScope operator*  (const ZAsiInt &,     const ZAsiYM &);
friend ZAsiYM DLLScope operator*  (const ZAsiNumeric &, const ZAsiYM &);
friend ZAsiYM DLLScope operator*  (const ZAsiDecimal &, const ZAsiYM &);
friend ZAsiYM DLLScope operator*  (integer,             const ZAsiYM &);

        ZAsiYM       operator/  (const ZAsiSmallInt &) const;
        ZAsiYM       operator/  (const ZAsiInt &)      const;
        ZAsiYM       operator/  (const ZAsiNumeric &)  const;
        ZAsiYM       operator/  (const ZAsiDecimal &)  const;
        ZAsiYM       operator/  (integer)              const;

        ZAsiYM       &operator-  (void);

       int           operator>  (const ZAsiYM &) const;
       int           operator>= (const ZAsiYM &) const;
       int           operator== (const ZAsiYM &) const;
       int           operator<= (const ZAsiYM &) const;
       int           operator<  (const ZAsiYM &) const;
       int           operator!= (const ZAsiYM &) const;
private:
       char *        getYMString (char *) const;

protected:
    ulong ivalue;         

};


class ZAsiDT : public ZAsiInterval
{
friend class ZAsiDate;
friend class ZAsiTime;
friend class ZAsiTimeStamp;
friend class ZAsiTempTable;

private:
                void        ChkMul     (real);
                void        ChkDiv     (real);
                int         cmpDTI     (const ZAsiDT&) const;
                EAsiBoolean ChkSet     (double);
                void        ChkSet2    (double);
                double      LocalToUTC (double) const;
                double      UTCToLocal (double) const;

public:

            ZAsiDT (void);
            ZAsiDT (EAsiIType);
            ZAsiDT (EAsiIType, uint);
            ZAsiDT (EAsiIType, uint, uint);
            ZAsiDT (const ZAsiDT &);
    virtual ~ZAsiDT (void);

    virtual EAsiBoolean   setIType      (EAsiIType);    

    virtual EAsiBoolean   is_castable   (const ZAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const ZAsiData &) const;

    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const ZAsiUcStr &);
    virtual EAsiBoolean   storeValue (const ZAsiData &);


    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (char *, uint, uint *); 
    virtual EAsiBoolean   storeValue (const ZsiUcStr);       

            EAsiBoolean   set        (ASI_IDAY *);
            EAsiBoolean   set        (ASI_IHOUR *);
            EAsiBoolean   set        (ASI_IMINUTE *);
            EAsiBoolean   set        (ASI_ISECOND *);
            EAsiBoolean   set        (ASI_IDAYTOHOUR *);
            EAsiBoolean   set        (ASI_IDAYTOMINUTE *);
            EAsiBoolean   set        (ASI_IDAYTOSECOND *);
            EAsiBoolean   set        (ASI_IHOURTOMINUTE *);
            EAsiBoolean   set        (ASI_IHOURTOSECOND *);
            EAsiBoolean   set        (ASI_IMINUTETOSECOND *);
            EAsiBoolean   set        (EAsiBoolean, uint, uint, uint, double);
            EAsiBoolean   setDays    (uint);
            EAsiBoolean   setHours   (uint);
            EAsiBoolean   setMinutes (uint);
            EAsiBoolean   setSeconds (double);


    virtual EAsiBoolean   getValue   (integer *)      const;
    virtual EAsiBoolean   getValue   (smallint *)     const;
    virtual EAsiBoolean   getValue   (char *, uint)   const;
    virtual EAsiBoolean   getValue   (ZAsiUcStr *)    const;


    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean   SQLLiteral (ZAsiUcStr *) const;        

            EAsiBoolean   get        (ASI_IDAY *)            const;
            EAsiBoolean   get        (ASI_IHOUR *)           const;
            EAsiBoolean   get        (ASI_IMINUTE *)         const;
            EAsiBoolean   get        (ASI_ISECOND *)         const;
            EAsiBoolean   get        (ASI_IDAYTOHOUR *)      const;
            EAsiBoolean   get        (ASI_IDAYTOMINUTE *)    const;
            EAsiBoolean   get        (ASI_IDAYTOSECOND *)    const;
            EAsiBoolean   get        (ASI_IHOURTOMINUTE *)   const;
            EAsiBoolean   get        (ASI_IHOURTOSECOND *)   const;
            EAsiBoolean   get        (ASI_IMINUTETOSECOND *) const;
            EAsiBoolean   get        (EAsiBoolean *, uint *, uint *, uint *,
                                      double *) const;
            EAsiBoolean   getDays    (uint *) const;
            EAsiBoolean   getHours   (uint *) const;
            EAsiBoolean   getMinutes (uint *) const;
            EAsiBoolean   getSeconds (double *) const;


    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);
    virtual ZAsiObject   *duplicate (void) const;


            ZAsiDT       &operator=  (const ZAsiDT &);

            ZAsiDT       &operator=  (const ZAsiSmallInt &);
            ZAsiDT       &operator=  (const ZAsiInt &);
            ZAsiDT       &operator=  (const ZAsiNumeric &);
            ZAsiDT       &operator=  (const ZAsiDecimal &);
            ZAsiDT       &operator=  (integer);

            ZAsiDT       operator+  (const ZAsiDT &) const;
            ZAsiDT       operator-  (const ZAsiDT &) const;
            ZAsiDT       operator*  (const ZAsiSmallInt &) const;
            ZAsiDT       operator*  (const ZAsiInt &)      const;
            ZAsiDT       operator*  (const ZAsiNumeric &)  const;
            ZAsiDT       operator*  (const ZAsiDecimal &)  const;
            ZAsiDT       operator*  (integer)              const;
     friend ZAsiDT DLLScope operator*  (const ZAsiSmallInt &,const ZAsiDT &);
     friend ZAsiDT DLLScope operator*  (const ZAsiInt &,     const ZAsiDT &);
     friend ZAsiDT DLLScope operator*  (const ZAsiNumeric &, const ZAsiDT &);
     friend ZAsiDT DLLScope operator*  (const ZAsiDecimal &, const ZAsiDT &);
     friend ZAsiDT DLLScope operator*  (integer,             const ZAsiDT &);

            ZAsiDT       operator/  (const ZAsiSmallInt &) const;
            ZAsiDT       operator/  (const ZAsiInt &)      const;
            ZAsiDT       operator/  (const ZAsiNumeric &)  const;
            ZAsiDT       operator/  (const ZAsiDecimal &)  const;
            ZAsiDT       operator/  (integer)              const;

            ZAsiDT       &operator-  (void);

            int           operator>  (const ZAsiDT &) const;
            int           operator>= (const ZAsiDT &) const;
            int           operator== (const ZAsiDT &) const;
            int           operator<= (const ZAsiDT &) const;
            int           operator<  (const ZAsiDT &) const;
            int           operator!= (const ZAsiDT &) const;

private:
            char        * getDTString (char *) const;


protected:
    double ivalue;        

};


class ZAsiDatetime : public ZAsiData
{
public:
            ZAsiDatetime ();
    virtual ~ZAsiDatetime ();

    virtual EAsiDataType Type          (void) const;

    virtual EAsiBoolean   is_datetime   (void) const;
    virtual EAsiBoolean   is_comparable (const ZAsiData *) const;

    virtual ZAsiData *    checkAdd      (const ZAsiData *) const;
    virtual ZAsiData *    checkSub      (const ZAsiData *) const;
    virtual ZAsiData  *   checkSet      (const ZAsiData *) const;

    virtual ushort Year                 (void) const = 0;
    virtual ushort Month                (void) const = 0;
    virtual ushort Day                  (void) const = 0;
    virtual ushort Hour                 (void) const = 0;
    virtual ushort Minute               (void) const = 0;
    virtual double Second               (void) const = 0;

protected:

};


class ZAsiDate: public ZAsiDatetime
{
friend class ZAsiTimeStamp;
friend class ZAsiTempTable;

public:

            ZAsiDate ();
            ZAsiDate (const ZAsiDate &);
    virtual ~ZAsiDate (void);

    virtual EAsiDTType   DateTimeType  (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual EAsiBoolean  is_storable   (const ZAsiData *) const;
    virtual EAsiBoolean  is_castable   (const ZAsiData *) const;


    virtual EAsiBoolean   isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const ZAsiData &) const;

    virtual EAsiBoolean  storeValue (char *, uint);
    virtual EAsiBoolean  storeValue (const ZAsiUcStr &);
    virtual EAsiBoolean  storeValue (const ZAsiData &);
    virtual EAsiBoolean  storeValue (const DBDATE *);
    virtual EAsiBoolean  storeValue (DATE);

    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);

            EAsiBoolean  set      (ASI_DTDATE *);
            EAsiBoolean  set      (const DBDATE *);
            EAsiBoolean  set      (ushort, ushort, ushort);
            EAsiBoolean  setYear  (ushort);
            EAsiBoolean  setMonth (ushort);
            EAsiBoolean  setDay   (ushort);

            EAsiBoolean  get      (ASI_DTDATE *)  const;
            EAsiBoolean  get      (DBDATE *)      const;
    virtual EAsiBoolean  getValue (char *, uint)  const;
    virtual EAsiBoolean  getValue (ZAsiUcStr *)   const;
    virtual EAsiBoolean  getValue (DBDATE *)      const;
    virtual EAsiBoolean  getValue (DATE *)        const;

    
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean  SQLType    (ZAsiUcStr *) const; 
    virtual EAsiBoolean  SQLLiteral (ZAsiUcStr *) const;

    virtual ushort       Year      (void) const;
    virtual ushort       Month     (void) const;
    virtual ushort       Day       (void) const;
    virtual ushort       Hour      (void) const;
    virtual ushort       Minute    (void) const;
    virtual double       Second    (void) const;

  
    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);

   
    virtual ZAsiObject   *duplicate (void) const;

    ZAsiDate    &operator=     (const ZAsiDate &);

    ZAsiDate     operator+     (const ZAsiYM &) const;
	ZAsiDate     operator+     (const ZAsiDT &) const;

     friend ZAsiDate DLLScope operator+     (const ZAsiYM &, const ZAsiDate &);
     friend ZAsiDate DLLScope operator+     (const ZAsiDT &, const ZAsiDate &);

            ZAsiDate     operator-     (const ZAsiYM &) const;
            ZAsiDate     operator-     (const ZAsiDT &) const;

            

            ZAsiYM YMDiff (const ZAsiDate &, const ZAsiYM &)   const;
            ZAsiDT DTDiff (const ZAsiDate &, const ZAsiDT &)   const;

     
            int          operator>     (const ZAsiDate &)      const;
            int          operator>=    (const ZAsiDate &)      const;
            int          operator==    (const ZAsiDate &)      const;
            int          operator<=    (const ZAsiDate &)      const;
            int          operator<     (const ZAsiDate &)      const;
            int          operator!=    (const ZAsiDate &)      const;


protected:
    ulong month;
    ushort day;

};

class ZAsiTime : public ZAsiDatetime
{
friend class ZAsiTimeStamp;
friend class ZAsiTempTable;

public:

            ZAsiTime  (void);
            ZAsiTime  (const ZAsiDT&);
            ZAsiTime  (uint);
            ZAsiTime  (uint, const ZAsiDT&);
            ZAsiTime  (const ZAsiTime &);
    virtual ~ZAsiTime (void);


    void         setWithTimeZone (EAsiBoolean f = kAsiTrue );

    virtual EAsiDTType    DateTimeType  (void) const;
    virtual uint          TimePrec      (void) const;
    virtual uint          ReturnLength  (void) const;


    virtual EAsiBoolean   is_storable   (const ZAsiData *) const;
    virtual EAsiBoolean   is_castable   (const ZAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const ZAsiData &) const;

    virtual EAsiBoolean  storeValue   (char *, uint);
    virtual EAsiBoolean  storeValue   (const ZAsiUcStr &);
    virtual EAsiBoolean  storeValue   (const ZAsiData &);
    virtual EAsiBoolean  storeValue   (const DBTIME *);


    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);


            EAsiBoolean  set           (ASI_DTTIME *);
            EAsiBoolean  set           (const DBTIME *);
            EAsiBoolean  set           (ushort, ushort, double);
            EAsiBoolean  setHour       (ushort);
            EAsiBoolean  setMinute     (ushort);
            EAsiBoolean  setSecond     (double);
            EAsiBoolean  setTimeZone   (const ZAsiDT &);

    
    
            EAsiBoolean  get          (ASI_DTTIME *) const;
            EAsiBoolean  get          (DBTIME *)     const;
    virtual EAsiBoolean  getValue     (char *, uint) const;
    virtual EAsiBoolean  getValue     (ZAsiUcStr *)  const;
    virtual EAsiBoolean  getValue     (DBTIME *)     const;

    
    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean  SQLType      (ZAsiUcStr *) const;
    virtual EAsiBoolean  SQLLiteral   (ZAsiUcStr *) const;

    virtual ushort       Year         (void) const {return 0;};
    virtual ushort       Month        (void) const {return 0;};
    virtual ushort       Day          (void) const {return 0;};
    virtual ushort       Hour         (void) const;
    virtual ushort       Minute       (void) const;
    virtual double       Second       (void) const;
    const ZAsiDT      &TimeZone     (void) const;

    
    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject  *duplicate (void) const;

    ZAsiTime    &operator=     (const ZAsiTime &);

    ZAsiTime     operator+     (const ZAsiDT &) const;
    friend ZAsiTime DLLScope operator+     (const ZAsiDT &, const ZAsiTime &);
    ZAsiTime     operator-     (const ZAsiDT &) const;


    ZAsiDT       DTDiff        (const ZAsiTime &,const ZAsiDT &) const;


    int          operator>     (const ZAsiTime &) const;
    int          operator>=    (const ZAsiTime &) const;
    int          operator==    (const ZAsiTime &) const;
    int          operator<=    (const ZAsiTime &) const;
    int          operator<     (const ZAsiTime &) const;
    int          operator!=    (const ZAsiTime &) const;
private:
    ushort timeprec;
    double seconds;
    short  mod;
    ZAsiDT timezone;
};

class ZAsiTimeStamp: public ZAsiDatetime
{
friend class ZAsiDate;
friend class ZAsiTime;
friend class ZAsiTempTable;
public:

                        ZAsiTimeStamp ();
                        ZAsiTimeStamp (uint);
                        ZAsiTimeStamp (const ZAsiDT &);
                        ZAsiTimeStamp (uint, const ZAsiDT &);
                        ZAsiTimeStamp (const ZAsiTimeStamp &);
    virtual				~ZAsiTimeStamp (void);

    virtual void         setNull         (void);
            void         setWithTimeZone (EAsiBoolean f = kAsiTrue );

    virtual EAsiDTType   DateTimeType  (void) const;
    virtual uint         TimeStampPrec (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual EAsiBoolean  is_storable   (const ZAsiData *) const;
    virtual EAsiBoolean  is_castable   (const ZAsiData *) const;

    virtual EAsiBoolean  isEqualTo     (const ZAsiData &) const;
    virtual EAsiBoolean  isGreaterThan (const ZAsiData &) const;



    virtual EAsiBoolean  storeValue  (char *, uint);
    virtual EAsiBoolean  storeValue  (const ZAsiUcStr &);
    virtual EAsiBoolean  storeValue  (const ZAsiData &);
    virtual EAsiBoolean  storeValue  (const DBTIMESTAMP *);


    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const ZsiUcStr);

            EAsiBoolean  set         (ASI_DTTIMESTAMP *);
            EAsiBoolean  set         (const DBTIMESTAMP *);
            EAsiBoolean  set         (const ZAsiDate &, const ZAsiTime &);
            EAsiBoolean  set         (ushort, ushort, ushort, ushort,
                                      ushort, double);
            EAsiBoolean  setYear     (ushort);
            EAsiBoolean  setMonth    (ushort);
            EAsiBoolean  setDay      (ushort);
            EAsiBoolean  setHour     (ushort);
            EAsiBoolean  setMinute   (ushort);
            EAsiBoolean  setSecond   (double);
            EAsiBoolean  setTimeZone (const ZAsiDT &);

            EAsiBoolean  get           (ASI_DTTIMESTAMP *) const;
            EAsiBoolean  get           (DBTIMESTAMP *)     const;
    virtual EAsiBoolean  getValue      (char *, uint)      const;
    virtual EAsiBoolean  getValue      (ZAsiUcStr *)       const;
    virtual EAsiBoolean  getValue      (DBTIMESTAMP *)     const;


    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint, uint *) const;
    virtual EAsiBoolean   getValue (ZsiUcStr, uint) const;
    virtual EAsiBoolean   getValue (ZAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean  SQLType       (ZAsiUcStr *) const;
    virtual EAsiBoolean  SQLLiteral    (ZAsiUcStr *) const;

    virtual ushort       Year          (void) const;
    virtual ushort       Month         (void) const;
    virtual ushort       Day           (void) const;
    virtual ushort       Hour          (void) const;
    virtual ushort       Minute        (void) const;
    virtual double       Second        (void) const;
      const ZAsiDT      &TimeZone      (void) const;


    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (ZAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject  *duplicate (void) const;

    ZAsiTimeStamp    &operator=     (const ZAsiTimeStamp &);
    ZAsiTimeStamp    &operator=     (const ZAsiDate &);
    ZAsiTimeStamp    &operator=     (const ZAsiTime &);


    ZAsiTimeStamp    operator+     (const ZAsiYM &) const;
    ZAsiTimeStamp    operator+     (const ZAsiDT &) const;
    friend ZAsiTimeStamp DLLScope operator+     (const ZAsiYM &, ZAsiTimeStamp &);
    friend ZAsiTimeStamp DLLScope operator+     (const ZAsiDT &, ZAsiTimeStamp &);

    ZAsiTimeStamp    operator-     (const ZAsiYM &) const;
    ZAsiTimeStamp    operator-     (const ZAsiDT &) const;


    ZAsiYM    YMDiff (const ZAsiTimeStamp &, const ZAsiYM &) const;
    ZAsiDT    DTDiff (const ZAsiTimeStamp &, const ZAsiDT &) const;


    int               operator>     (const ZAsiTimeStamp &) const;
    int               operator>=    (const ZAsiTimeStamp &) const;
    int               operator==    (const ZAsiTimeStamp &) const;
    int               operator<=    (const ZAsiTimeStamp &) const;
    int               operator<     (const ZAsiTimeStamp &) const;
    int               operator!=    (const ZAsiTimeStamp &) const;

private:
    ZAsiTime time;
    ZAsiDate date;
};

class ZAsiBlob : public ZAsiData
{
public:
    typedef enum {
        kUnknown        = 0,
        kBlob,
        kIPersist,
        kNonIPersist,
        kADT
    } ZEBlobType;


    typedef enum {
        kUnk            = 0,
        kHex,
        kDec,
        kChr,
        kOct,
        kBin
    } ZEBlobFormat;

                            ZAsiBlob        ();
                            ZAsiBlob        (const ZAsiBlob &);
    virtual                 ~ZAsiBlob       ();

            void            SetType         (ZEBlobType);
            ZEBlobType       GetType         ()                      const;


    virtual EAsiDataType    Type            ()                      const;
    virtual uint            Length          ()                      const;
    virtual uint            ReturnLength    ()                      const;

    virtual EAsiBoolean     storeValue      (real);
    virtual EAsiBoolean     storeValue      (integer);
    virtual EAsiBoolean     storeValue      (smallint);
    virtual EAsiBoolean     storeValue      (char *, uint);
    virtual EAsiBoolean     storeValue      (const ZAsiUcStr &);
    virtual EAsiBoolean     storeValue      (const ZAsiData &);
    virtual EAsiBoolean     storeValue      (char *, uint, uint *); 

            EAsiBoolean     set             (IUnknown *);


    virtual EAsiBoolean     getValue        (real *)                const;
    virtual EAsiBoolean     getValue        (integer *)             const;
    virtual EAsiBoolean     getValue        (smallint *)            const;
    virtual EAsiBoolean     getValue        (char *, uint)          const;
    virtual EAsiBoolean     getValue        (ZAsiUcStr *)           const;
    virtual EAsiBoolean     getValue        (ZAsiData &)            const;
            EAsiBoolean     get             (IUnknown **);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;


    virtual EAsiBoolean     SQLType         (ZAsiUcStr *)           const;  
    virtual EAsiBoolean     SQLLiteral      (ZAsiUcStr *)           const;



    virtual unsigned long   packSize        (void)                  const;
    virtual unsigned long   packTo          (ZAsiObjPack *)         const;
    virtual EAsiBoolean     unpackFrom      (ZAsiObjPack *);
    virtual unsigned long   packValueSize   ()                      const;
    virtual unsigned long   packValueTo     (ZAsiObjPack *)         const;
    virtual EAsiBoolean     unpackValueFrom (ZAsiObjPack *);


    virtual ZAsiObject  *   duplicate       ()                      const;

    virtual void            Clear           ();

    HRESULT         Read            (void *, ulong, ulong *);
    HRESULT         Write           (void *, ulong, ulong *);

    void            SetFormat       (ZEBlobFormat);
    void            SetPrintLen     (int);
    HRESULT         ReadHead        ();

private:
    IUnknown            *   m_pIUnknown;

    ZEBlobType               m_eBlobType;
    ZEBlobFormat             m_eBlobFormat;
    int                     m_iHeadLen;
    char                    m_cBlobHead[MaxCharLength];
};


class ZAsiColumn : public ZAsiObject
{
public:
                            ZAsiColumn      (void);
                            ZAsiColumn      (const ZAsiIdent &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiSmallInt &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiInt &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiNumeric &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiDecimal &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiFloat &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiReal &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiDouble &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiChar &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiBinary &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiDate &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiTime &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiTimeStamp &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiYM &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiDT &);
                            ZAsiColumn      (const ZAsiIdent &, const ZAsiIdent &);
                            ZAsiColumn      (const ZAsiIdent &, ZAsiData *);
                            ZAsiColumn      (const ZAsiColumn &);
                            ZAsiColumn      (const DBCOLUMNINFO *);

    virtual                 ~ZAsiColumn     ();
    
    void                    setName         (const ZAsiIdent &);
    void                    setNullable     (EAsiBoolean);
    void                    setNative       (EAsiBoolean);
    void                    setCollation    (const ZAsiUcStr &);
    void                    setDefault      (ZAsiData *);
    void                    setDomain       (const ZAsiIdent &);
    void                    setDataDsc      (ZAsiData *);
    void                    setOffset       (uint);

    const ZAsiIdent     &   Name            (void) const;
    EAsiBoolean             Nullable        (void) const;
    EAsiBoolean             Native          (void) const;
    const ZAsiUcStr     *   Collation       (void) const;
    ZAsiData            *   Default         (void) const;
    const ZAsiIdent     &   Domain          (void) const;
    uint                    Offset          (void) const;
    EAsiBoolean             IsBookmark      (void) const;
    unsigned long           ColumnFlags     (void) const;
    const DBCOLUMNINFO	&	ColumnInfo		(void) const;


    ZAsiData          *     getData         (void) const;


    ZAsiColumn      &       operator=       (const ZAsiColumn &);
    ZAsiColumn      &       operator=       (ZAsiData *);

    virtual unsigned long   packSize        (void) const;
    virtual unsigned long   packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean     unpackFrom      (ZAsiObjPack *);

    virtual unsigned long   packValueSize   (void)  const;
    virtual unsigned long   packValueTo     (ZAsiObjPack *) const;
    virtual EAsiBoolean     unpackValueFrom (ZAsiObjPack *);

    virtual ZAsiObject  *   duplicate       (void) const;

    virtual void            Clear           (void);

private:
    static void				setColumn		(ZAsiColumn * t, const ZAsiIdent & colname,
                                             ZAsiData *   datadsc);

protected:
    ZAsiIdent               m_idName;           
    ZAsiData            *   m_pData;

    EAsiBoolean             m_fNullable;
    EAsiBoolean             m_fNative;
    ZAsiData            *   m_pDefval;
    ZAsiIdent               m_idDomain;
    uint                    m_uiOffset;
    unsigned long           m_dwColFlags;
    DBCOLUMNINFO			m_sColumnInfo;
};



class ZAsiRow : public ZAsiObject
{
public:
							ZAsiRow			(int ColNum);
                            ZAsiRow			(const ZAsiRow &);
    virtual					~ZAsiRow		();

    int						ColNum			(void) const;
    ZAsiColumn			&	operator []		(int) const;
    int						findCol			(const ZAsiIdent &) const;
    EAsiBoolean				isDistinct		(void) const;

    virtual ZAsiObject	*	duplicate		(void) const;
    virtual void			Clear			(void);

private:
    ZAsiColumn			*	m_pColumns;
    int						m_iColnum;
};



class ZAsiHostBuffer: public ZAsiObject
{
friend class ZAsiCsr;
friend class ZAsiStm;

public:
                        ZAsiHostBuffer ();
    virtual				~ZAsiHostBuffer ();

    virtual EAsiBoolean getBind (ZAsiData **) const;


protected:
    virtual EAsiBoolean setBind (ZAsiData *);


protected:
    ZAsiData *pData;
};


class ZAsiParameter: public ZAsiHostBuffer
{
friend class ZAsiParser;
friend class ZAsiStm;
friend class ZAsiDDAParams;
friend class ZAsiHostLink;
friend class ZAsiInterDBCursor;
friend class ZAsiEmulCursor;
friend class ZAsiEmulTable;

public:
                            ZAsiParameter ();
                            ZAsiParameter (const DBPARAMINFO *);

    virtual					~ZAsiParameter ();

protected:
    virtual EAsiBoolean		setBind     (ZAsiData *);

public:
    void					setName     (const ZAsiIdent &);  
    void					setNullable (EAsiBoolean);        
    void					setDsc      (ZAsiData*);          

    const ZAsiIdent  &		Name        (void) const;
    EAsiBoolean				isNullable  (void) const;
    ZAsiData		*		Dsc         (void) const;


    virtual unsigned long	packSize        (void) const;
    virtual unsigned long	packTo          (ZAsiObjPack *) const;
    virtual EAsiBoolean		unpackFrom      (ZAsiObjPack *);

private:
    virtual ZAsiObject *	duplicate   (void) const;

    virtual void			Clear        (void);

private:
    ZAsiIdent				ucParName;       
    ZAsiData			*	pDataDescriptor; 
    EAsiBoolean				eNul;          
};





struct ZListItem {
  struct ZListItem *next;
  ZAsiObject *item;
};


typedef ULONG_PTR ASILISTPOS;   


class ZAsiList: public ZAsiObject
{
public:

                            ZAsiList ();
     virtual              ~ ZAsiList ();


             EAsiBoolean    addFirst (ZAsiObject *);    
             EAsiBoolean    addLast  (ZAsiObject *);    

     
             EAsiBoolean    del         (ZAsiObject *); 
             EAsiBoolean    del         (int);          
             EAsiBoolean    detach      (ZAsiObject *); 
             EAsiBoolean    detach      (int);          
             EAsiBoolean    delFirst    (void);         
             EAsiBoolean    delLast     (void);         
             EAsiBoolean    delTail     (int);          
             EAsiBoolean    detachFirst (void);         
             EAsiBoolean    detachLast  (void);         
             EAsiBoolean    detachTail  (int);          


             EAsiBoolean    replace     (int,           
                                         ZAsiObject *); 
             EAsiBoolean    overwrite   (int,           
                                         ZAsiObject *); 



             ZAsiObject   * first      (void);          
             ZAsiObject   * next       (void);          
             ZAsiObject   * next       (ASILISTPOS);    
             ZAsiObject   * last       (void);          
             int            qnty       (void) const;    
             void           detachAll  (void);          
             ASILISTPOS     position   (void) const;    
             ZAsiObject   * getCurrent (void) const;    
             ZAsiObject   * getAt      (ASILISTPOS) const; 


             ZAsiObject    *operator [] (int);         

     
     virtual  ZAsiObject   *duplicate () const;
     virtual  void          Clear     (void);          

private:
     struct ZListItem *head;
     struct ZListItem *tail;
     struct ZListItem *current;

};


class ZAsiIRow : public ZAsiObject
{
public:
                            ZAsiIRow    (void);
                            ZAsiIRow    (const int);
                            ZAsiIRow    (const ZAsiIRow &);
    virtual                 ~ZAsiIRow   (void);

    int                     Quantity    (void) const;       

    EAsiBoolean             setItem     (int, ZAsiData *);  


            ZAsiData    *   operator [] (const int item) const;



    virtual ZAsiObject  *   duplicate (void) const;
    virtual void            Clear (void);


private:
    ZAsiData **values;      
    int        items;       
};

#pragma pack (pop)

#endif 
