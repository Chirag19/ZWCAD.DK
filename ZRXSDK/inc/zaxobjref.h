

#ifndef __ZXOBJREF_H_
#define __ZXOBJREF_H_

#include "zdbobjptr.h"
#pragma pack (push, 8)

#pragma warning (disable : 4786)



class ZcAxObjectRef
{
public:
    ZcAxObjectRef();
    ZcAxObjectRef(ZcDbObjectId objId);
    ZcAxObjectRef(ZcDbObject *&  pObj); 
    ~ZcAxObjectRef();
    
    Zcad::ErrorStatus acquire(ZcDbObjectId objId);
    Zcad::ErrorStatus acquire(ZcDbObject *& pObj);

    Zcad::ErrorStatus release(ZcDbObjectId& objId, ZcDbObject *& pObj);
    
    bool isNull();
    ZcDbObjectId objectId();

private:

    ZcAxObjectRef(ZcAxObjectRef & ref);
    ZcAxObjectRef& operator=(ZcAxObjectRef & ref);

    void internalRelease();

    ZcDbObjectId m_objId;
    ZcDbObject *   m_pObj;
};


        


template<class T_OBJECT>
class ZcAxObjectRefPtr : public ZcDbObjectPointer<T_OBJECT>
{
public:
    ZcAxObjectRefPtr();
    ZcAxObjectRefPtr(ZcAxObjectRef* const pRef,
                     ZcDb::OpenMode mode,
                     bool           openErased = false);
    ~ZcAxObjectRefPtr();

private:
    
    ZcAxObjectRefPtr(ZcAxObjectRefPtr & pObj);
    ZcAxObjectRefPtr& operator=(ZcAxObjectRefPtr & pObj);

    ZcAxObjectRef* const m_pRef;
};

template<class T_OBJECT> inline
ZcAxObjectRefPtr<T_OBJECT>::ZcAxObjectRefPtr()
    : ZcDbObjectPointer<T_OBJECT>(),
      m_pRef(NULL)
{}

template<class T_OBJECT> inline 
ZcAxObjectRefPtr<T_OBJECT>::ZcAxObjectRefPtr(ZcAxObjectRef* const pRef, ZcDb::OpenMode mode, bool openErased)
    : m_pRef(pRef)
{
    
    if (NULL == pRef)
    {
        m_status = Zcad::eNullObjectPointer;
        return;
    }

    
    ZcDbObjectId objId = pRef->objectId();
    
    
    if (!objId.isNull()) 
        m_status = zcdbOpenObject(m_ptr, objId, mode, openErased);

    else 
    {
        ZcDbObject* pTmp = NULL;
        m_pRef->release(objId, pTmp);


        T_OBJECT* pTyped= T_OBJECT::cast(pTmp);
        if (NULL == pTyped) {
            m_ptr = NULL;
            m_pRef->acquire(pTmp);
            m_status = Zcad::eNotThatKindOfClass;
        }
        else
            acquire(pTyped);
    }
}
    
template<class T_OBJECT> inline
ZcAxObjectRefPtr<T_OBJECT>::~ZcAxObjectRefPtr()
{

    if (NULL != m_ptr && m_ptr->objectId().isNull()) {
        T_OBJECT* pTmp;
        release(pTmp);
        m_pRef->acquire(reinterpret_cast<ZcDbObject*&>(pTmp));
    }
}

typedef ZcAxObjectRefPtr<ZcDbObject> ZcDbObjectRefPtr;
typedef ZcAxObjectRefPtr<ZcDbEntity> ZcDbEntityRefPtr;

#pragma pack (pop)
#endif
