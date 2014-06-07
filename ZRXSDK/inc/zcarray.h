#ifndef ZC_ZCARRAY_H
#define ZC_ZCARRAY_H

#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include "zdesk.h"
#include "assert.h"
#include "zrxAlloc.h" 


#ifdef ASSERT
#define ZC_ARRAY_ASSERT ASSERT
#elif defined assert
#define ZC_ARRAY_ASSERT assert
#elif defined _ASSERTE
#define ZC_ARRAY_ASSERT _ASSERTE
#else
#define ZC_ARRAY_ASSERT(T)
#endif

#ifdef  _ZRX_SUPPORT_
#define ZRX_DLLEXPIMPORT __declspec(dllexport)
#else
#define ZRX_DLLEXPIMPORT __declspec(dllimport)
#endif

#define zcmin(X,Y) ((X) < (Y) ? (X) : (Y))
#define zcmax(X,Y) ((X) > (Y) ? (X) : (Y))

#define ZcArrayObjectCopyReallocator	ZcObjectsAllocator
#define ZcArrayMemCopyReallocator		ZcMemoryAllocator

enum ZcResult
{
	eZcDummyLastError = 0,
	eZcOutOfMemory,
	eZcInvalidIndex,
	eZcInvalidInput,
};


template <class T> class ZcMemoryAllocator
{
public:
  typedef unsigned int size_type;

  static inline void copy(
    T* pDestination, 
    const T* pSource, 
    size_type numElements)
  {
    memcpy(pDestination, pSource, numElements * sizeof(T));
  }

  static inline void move(
    T* pDestination, 
    const T* pSource, 
    size_type numElements)
  {
    memmove(pDestination, pSource, numElements * sizeof(T));
  }

  static inline void construct(
    T* pElement, 
    const T& value = T())
  {
    *pElement = value;
  }


  static inline void constructn(
    T* pDestination, 
    size_type numElements, 
    const T& value)
  {
    while(numElements--)
    {
      pDestination[numElements] = value;
    }
  }
  
  static inline void constructn(
    T* pDestination, 
    const T* pSource, 
    size_type numElements)
  {
    copy(pDestination, pSource, numElements);
  }
  static inline void constructn(
    T*, 
    size_type)
  {

  }

  static inline void destroy(
    T*)
  {

  }
  static inline void destroy(
    T*, 
    size_type )
  {

  }

  static inline bool useRealloc()
  {
    return true;
  }
};



template <class T> class ZcObjectsAllocator
{
public:
  typedef unsigned int size_type;
  

  static inline void copy(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      *pDestination = *pSource;
      pDestination++;
      pSource++;
    }
  }


  static inline void move(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    if (pDestination <= pSource || pDestination >= pSource + numObjects)
    {
      copy(pDestination, pSource, numObjects);
    }
    else
    {
      while(numObjects--)
      {
        pDestination[numObjects] = pSource[numObjects];
      }
    }
  }

  static inline void construct(
    T* pObject)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T;
  }
  static inline void construct(
     T* pObject, 
     const T& value)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T(value);
  }

  static inline void constructn(
    T* pDestination, 
    size_type numObjects, 
    const T& value)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects, value);
    }
  }
  static inline void constructn(
    T* pDestination, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects);
    }
  }
  static inline void constructn(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination, *pSource);
      pDestination++;
      pSource++;
    }
  }

  static inline void destroy(
    T* pObject)
  {
    pObject->~T();
    pObject = 0;
  }
  static inline void destroy(
    T* objects, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      destroy(objects + numObjects);
    }
  }

  static inline bool useRealloc()
  {
    return false;
  }
};


template <class T> class ZcPlainObjectsAllocator
{
public:
  typedef unsigned int size_type;
  

  static inline void copy(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    memcpy(pDestination, pSource, numObjects * sizeof(T));
  }
  

  static inline void move(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    memmove(pDestination, pSource, numObjects * sizeof(T));
  }
  

  static inline void construct(
    T* pObject)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T;
  }
  static inline void construct(
    T* pObject, 
    const T& value)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T(value);
  }
  

  static inline void constructn(
    T* pDestination, 
    size_type numObjects, 
    const T& value)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects, value);
    }
  }
  static inline void constructn(
    T* pDestination, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects);
    }
  }
  static inline void constructn(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination, *pSource);
      pDestination++;
      pSource++;
    }
  }
  

  static inline void destroy(
    T* pObject)
  {
    pObject->~T();
    pObject = 0;
  }
  static inline void destroy(
    T* objects, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      destroy(objects + numObjects);
    }
  }

  static inline bool useRealloc()
  {
    return true;
  }
};



struct  ZcArrayBuffer
{
  typedef unsigned int size_type;

  mutable ZcRefCounter m_nRefCounter;
  int               m_nGrowBy;
  size_type         m_nAllocated;
  size_type         m_nLength;

 ZRX_DLLEXPIMPORT static ZcArrayBuffer  g_empty_array_buffer;
};

template <class T, class A = ZcMemoryAllocator<T> > class ZcArray
{
public:

  typedef typename A::size_type size_type;
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
private:
  struct Buffer : ZcArrayBuffer
  {
    T* data() const { return (T*)(this+1); }

    static Buffer* allocate(size_type nLength2Allocate, int nGrowBy)
    {
      size_type nBytes2Allocate = sizeof(Buffer) + nLength2Allocate * sizeof(T);
      ZC_ARRAY_ASSERT(nBytes2Allocate > nLength2Allocate);
      if(nBytes2Allocate > nLength2Allocate)
      {
        Buffer* pBuffer = (Buffer*)::zcrxAlloc(nBytes2Allocate);
        if (pBuffer)
        {
          pBuffer->m_nRefCounter = 1;
          pBuffer->m_nGrowBy     = nGrowBy;
          pBuffer->m_nAllocated  = nLength2Allocate;
          pBuffer->m_nLength     = 0;
          return pBuffer;
        }
      }
      throw /*ZcError(eZcOutOfMemory)*/;
    }
    static Buffer* _default()
    {
      return (Buffer*)&g_empty_array_buffer;
    }
    void release()
    {
      ZC_ARRAY_ASSERT(m_nRefCounter); 
      if((--m_nRefCounter)==0 && this != _default())
      {
        A::destroy(data(), m_nLength);
        ::zcrxFree(this);
      }
    }
    void addref() const { ++m_nRefCounter; }
  };
  class reallocator
  {
    Buffer* m_pBuffer;
    bool _may_use_realloc;
  public:
    inline reallocator( bool may_use_realloc = false ) : _may_use_realloc(may_use_realloc) 
    {
      if ( !_may_use_realloc )
      {
        m_pBuffer = Buffer::_default();
        m_pBuffer->addref(); 
      }
    }
    inline void reallocate(ZcArray* pArray, size_type nNewLen )
    {
      if(!pArray->referenced())
      {
        if(nNewLen > pArray->physicalLength())
        {
          if ( !_may_use_realloc )
          {
            m_pBuffer->release();
            m_pBuffer = pArray->buffer();
            m_pBuffer->addref(); // save buffer to ensure copy from itself would work (e.g insertAt)
          }
          pArray->copy_buffer(nNewLen, _may_use_realloc);
        }
      }
      else
      {
        pArray->copy_buffer(nNewLen);
      }
    }
    inline ~reallocator() 
    {
      if ( !_may_use_realloc ) m_pBuffer->release();
    }
  };
  friend class reallocator;
  const_iterator begin_const() const { return begin(); }
  iterator begin_non_const() { return begin(); }
  const_iterator end_const() { return end(); }
  iterator end_non_const() { return end(); }
  void copy_before_write(size_type len, bool may_use_realloc = false )
  {
    if( referenced() )
      copy_buffer(len);
    else if ( len > physicalLength() )
      copy_buffer( len, may_use_realloc );
  }
  void copy_if_referenced() { if(referenced()) { copy_buffer(physicalLength()); } }
  void copy_buffer( size_type len, bool may_use_realloc = false, bool force_size = false )
  {
    Buffer* pOldBuffer = buffer();
    int nGrowBy = pOldBuffer->m_nGrowBy;
    size_type len2 = len;
    if ( !force_size )
    {
      if(nGrowBy > 0)
      {
        len2 += nGrowBy;
        len2 = ((--len2) / nGrowBy) * nGrowBy;
      }
      else
      {
        len2 = pOldBuffer->m_nLength;
        len2 = len2 + -nGrowBy * len2 / 100;
        if(len2 < len)
        {
          len2 = len;
        }
      }
    }
    if ( may_use_realloc && A::useRealloc() && !empty() )
    {
      Buffer* pNewBuffer = reinterpret_cast<Buffer*>( ::zcrxRealloc( 
        pOldBuffer, len2 * sizeof(T) + sizeof(Buffer), pOldBuffer->m_nAllocated * sizeof(T) + sizeof(Buffer) ) );
      pNewBuffer->m_nAllocated = len2;
      pNewBuffer->m_nLength = zcmin(pNewBuffer->m_nLength, len);
      m_pData = pNewBuffer->data();
    }
    else 
    {
      Buffer* pNewBuffer = Buffer::allocate(len2, nGrowBy);
      len = zcmin(pOldBuffer->m_nLength, len);
      A::constructn(pNewBuffer->data(), pOldBuffer->data(), len);
      pNewBuffer->m_nLength = len;
      m_pData = pNewBuffer->data();
      pOldBuffer->release();
    }
  }
inline void assertValid(size_type index) const { assert(isValid(index)); } 
static inline void rise_error(ZcResult e){	/*default_err_func(e)*/ assert(0);};
public:

  iterator begin() { if(!empty()) { copy_if_referenced(); return data(); } return 0; }
  const_iterator begin() const { if(!empty()) { return data(); } return 0; }


  iterator end() { if(!empty()) { copy_if_referenced(); return data() + length(); } return 0; }
  const_iterator end() const { if(!empty()) { return data()+length(); } return 0; }
  

  void insert(
    iterator before, 
    const_iterator first, 
    const_iterator afterLast)
  {
    size_type len = length();
    size_type index = (size_type)(before - begin_const());
    if(index <= len && afterLast>=first)
    {
      if(afterLast > first)
      {
        size_type num2copy = (size_type)(afterLast - first);
        reallocator r( first < begin() || first >= end() );
        r.reallocate(this, len + num2copy);
        A::constructn(m_pData + len, first, num2copy);
        buffer()->m_nLength = len + num2copy;
        T* pDestination = m_pData + index;
        if(index != len)
        {
          A::move(pDestination + num2copy, pDestination, len - index);
        }
        A::copy(pDestination, first, (size_type)(afterLast - first));
      }
    }
    else
    {
      rise_error(eZcInvalidInput);
    }
  }

  void resize( 
    size_type logicalLength, 
    const T& value )
  {
    size_type len = length();
    int d = logicalLength - len;
    if ( d > 0 )
    {
      reallocator r( m_pData > &value || &value > (m_pData + len) );
      r.reallocate(this, logicalLength);
      A::constructn(m_pData + len, d, value);
    }
    else if ( d < 0 )
    {
      d=-d;
      if(!referenced())
      {
        A::destroy(m_pData + logicalLength, d);
      }
      else
      {
        copy_buffer(logicalLength);
      }
    }
    buffer()->m_nLength = logicalLength;
  }
  
  void resize( 
    size_type logicalLength )
  {
    size_type len = length();
    int d = logicalLength - len;
    if ( d > 0 )
    {
      copy_before_write( len + d, true );
      A::constructn(m_pData + len, d);
    }
    else if ( d < 0 )
    {
      d = -d;
      if ( !referenced() )
      {
        A::destroy( m_pData + logicalLength, d );
      }
      else
      {
        copy_buffer(logicalLength);
      }
    }
    buffer()->m_nLength = logicalLength;
  }

  size_type *retp_nArrayLength()
  {
	  return &(buffer()->m_nLength);
  }


  size_type size() const { return buffer()->m_nLength; }


  bool empty() const { return size() == 0; }
  

  size_type capacity() const { return buffer()->m_nAllocated; }


  void reserve(
    size_type reserveLength) { if(physicalLength() < reserveLength) { setPhysicalLength(reserveLength); } }


  void assign(
    const_iterator first, 
    const_iterator afterLast)
  { erase(begin_non_const(), end_non_const()); insert(begin_non_const(), first, afterLast); }
  
  iterator erase(
    iterator first, 
    iterator afterLast)
  {
    size_type i = (size_type)(first - begin_const());
    if(first != afterLast)
    {
      removeSubArray(i, (size_type)(afterLast-begin_const()-1));
    }
    return begin_non_const()+i;
  }

  iterator erase(
    iterator where)
  {
    size_type i = where - begin_const();
    removeAt(i);
    return begin_non_const()+i;
  }

  void clear() { erase(begin_non_const(), end_non_const()); }


  void push_back(
    const T& value) { insertAt(length(), value); }
  
  iterator insert(
    iterator before, 
    size_type numElements, 
    const T& value)
  {
    size_type len = length();
    size_type index = before - begin_const();
    reallocator r( m_pData > &value || &value > (m_pData + len) );
    r.reallocate(this, len + numElements);
    A::constructn(m_pData + len, numElements, value);
    buffer()->m_nLength = len + numElements;
    T* pData = data();
    pData += index;
    if(index != len)
    {
      A::move(pData + numElements, pData, len - index);
    }
    while(numElements--)
    {
      pData[numElements] = value;
    }
    return begin_non_const()+index;
  }
  
  iterator insert(
    iterator before, 
    const T& value = T())
  {
    size_type index = before - begin_const();
    insertAt(index, value);
    return (begin_non_const() + index);
  }  


  bool contains(
    const T& value, 
    size_type start = 0) const
  { size_type dummy; return find(value, dummy, start); }
  
  int length() const { return (int)(buffer()->m_nLength); }

  bool isEmpty() const { return length() == 0; }

  int logicalLength() const { return length(); }

  size_type physicalLength() const { return buffer()->m_nAllocated; }

  int growLength() const { return buffer()->m_nGrowBy; }

  const T* asArrayPtr() const { return data(); }

  const T* getPtr() const { return data(); }

  T* asArrayPtr() { copy_if_referenced(); return data(); }

  const T& operator [](
    size_type index) const { assertValid(index); return m_pData[index]; }
  T& operator [](
    size_type index) { assertValid(index); copy_if_referenced(); return m_pData[index]; }

  T& at(
    size_type arrayIndex) { assertValid(arrayIndex); copy_if_referenced(); return *(data() + arrayIndex); }
  const T& at(size_type arrayIndex) const { assertValid(arrayIndex); return *(data() + arrayIndex); }

  ZcArray& setAt(
    size_type arrayIndex, 
    const T& value)
  { assertValid(arrayIndex); copy_if_referenced(); m_pData[arrayIndex] = value; return *this; }

  const T& getAt(
    size_type arrayIndex) const { assertValid(arrayIndex); return *(data() + arrayIndex); }

  T* retp_At(size_type arrayIndex)
  {
	 assertValid(arrayIndex);
	 return data()+arrayIndex;
  }

  T& first() { return *begin(); }
  const T& first() const { return *begin(); }

  T& last() { return at(length()-1); }
  const T& last() const { return at(length()-1); }
  
  size_type append(
    const T& value) { insertAt(length(), value); return length()-1; }
  
  iterator append() { size_type i = append(T()); return begin_non_const() + i; }

  ZcArray& removeFirst() { return removeAt(0); }

  ZcArray& removeLast() { return removeAt(length()-1); }

  ZcArray& setGrowLength(
    int growLength)
  {
    if(growLength != 0)
    {
      copy_if_referenced();
      buffer()->m_nGrowBy = growLength;
    }
    else
    {
      //ODA_FAIL();
    }
    return *this;
  }


  /*explicit*/ ZcArray(
    size_type physicalLength, 
    int growLength = 8) : m_pData(0)
  {
    if(growLength != 0)
    {
      m_pData = Buffer::allocate(physicalLength, growLength)->data();
    }
    else
    {
      //ODA_FAIL();
      *this = ZcArray<T,A>();
    }
  }
  
  ZcArray() : m_pData(Buffer::_default()->data()) { buffer()->addref(); }
  
  ZcArray(const ZcArray& source) : m_pData((T*)source.data()) { buffer()->addref(); }
  
  ~ZcArray() { buffer()->release(); }
  
  ZcArray& operator =(
    const ZcArray& source)
  {
    source.buffer()->addref();
    buffer()->release();
    m_pData = source.m_pData;
    return *this;
  }
  
  bool operator ==(
    const ZcArray& array) const
  {
    if(length() == array.length())
    {
      for(size_type i = 0; i < length(); i++)
      {
        if(at(i) != array[i])
        {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  ZcArray& setAll(
    const T& value)
  {
    copy_if_referenced();
    T* pData = data();
    size_type n = length();
    while(n)
    {
      pData[--n] = value;
    }
    return *this;
  }

  ZcArray& append(
    const ZcArray& otherArray)
  {
    insert(end_non_const(), otherArray.begin(), otherArray.end());
    return *this;
  }

  ZcArray& insertAt(
    size_type arrayIndex, 
    const T& value)
  {
    size_type len = length();
    if( arrayIndex == len )
    {
      resize( len + 1, value );
    }
    else if ( arrayIndex < len )
    {
      reallocator r( m_pData > &value || &value > (m_pData + len) );
      r.reallocate( this, len+1 );
      A::construct( m_pData + len );
      ++(buffer()->m_nLength);
      A::move(m_pData + arrayIndex + 1, m_pData + arrayIndex, len - arrayIndex);
      m_pData[arrayIndex] = value;
    }
    else
    {
      rise_error(eZcInvalidIndex); 
    }
    return *this;
  }
  

  ZcArray& removeAt(
    size_type arrayIndex)
  {
    assertValid(arrayIndex);
    size_type len = length();
    if(arrayIndex < --len)
    {
      copy_if_referenced();
      T* pData = data();
      A::move(pData + arrayIndex, pData + arrayIndex + 1, len - arrayIndex);
    }
    resize(len);
    return *this;
  }
  

  ZcArray& removeSubArray(
    size_type startIndex, 
    size_type endIndex)
  {
    if(!isValid(startIndex) || startIndex > endIndex)
    {
      rise_error(eZcInvalidIndex);
    }

	size_type len = length();

	if (startIndex < 0) 
	{
		startIndex = 0;
	}

	if (endIndex > len-1)
	{
		endIndex = len -1;
	}

	if (startIndex > endIndex)
	{
		startIndex = endIndex;
	}

    copy_if_referenced();
    T* pData = data();
    ++endIndex;
    size_type n2remove = endIndex - startIndex;
    A::move(pData + startIndex, pData + endIndex, len - endIndex);
    A::destroy(pData + len - n2remove, n2remove);
    buffer()->m_nLength -= n2remove;
    return *this;
  }
  

  bool find(
    const T& value, 
    size_type& findIndex, 
    size_type start=0) const
  {
    if(!empty())
    {
      assertValid(start);
      size_type len = length();
      const T* pData = data();
      for(size_type i = start; i<len; ++i)
      {
        if(pData[i] == value)
        {
          findIndex = i;
          return true;
        }
      }
    }
    return false;
  }
  

  ZcArray& setLogicalLength(
    size_type logLength)
  {
    resize(logLength);
    return *this;
  }
  
  ZcArray& setPhysicalLength(
    size_type physLength)
  {
    if(physLength==0)
    {
      *this = ZcArray<T, A>();
    }
    else if(physLength != physicalLength())
    {
      copy_buffer(physLength,true,true);
    }
    return *this;
  }

  ZcArray& reverse()
  {
	  if(!empty())
	  {
		  copy_if_referenced();
		  T tmp;
		  iterator iter1 = begin_non_const();
		  iterator iter2 = end_non_const();
		  --iter2;
		  while(iter1 < iter2)
		  {
			  tmp = *iter1;
			  *iter1 = *iter2;
			  *iter2 = tmp;
			  ++iter1;
			  --iter2;
		  }
	  }
	  return *this;
  }

  ZcArray& swap(size_type firstIndex, size_type secondIndex)
  {
	  if(!isValid(firstIndex) || !isValid(secondIndex))
	  {
		  rise_error(eZcInvalidIndex);
	  }    
	  if(firstIndex != secondIndex)
	  {
		  const T tmp = at(firstIndex);
		  at(firstIndex) = at(secondIndex);
		  at(secondIndex) = tmp;
	  }
	  return *this;
  }

  bool remove(const T& value, size_type start = 0)
  {
	  size_type i = 0;
	  if(find(value, i, start))
	  {
		  removeAt(i);
		  return true;
	  }
	  return false;
  }

  ZcArray<T,A>& removeAll()
  {
	  this->setLogicalLength(0);
	  return *this; 
  }

  bool find (const T& value, int& foundAt, int start = 0) const
  {
	  return find(value, (size_type&)foundAt, start);
  }

  int find(const T& value) const
  {
	  return this->findFrom(value, 0);  
  }

  int findFrom(const T& value, int start) const
  {
	  for (int i = start; i < this->logicalLength(); i++)
	  {
		  if (m_pData[i] == value)
			  return i;
	  }
	  return -1;
  }


private:

  T*    m_pData;

  bool isValid(size_type i) const { return ((int)i < length()); }

  T* data() { return (length() ? m_pData : 0); }

  const T* data() const { return m_pData; }

  Buffer* buffer() const
  {
    return (reinterpret_cast<Buffer*>(const_cast<ZcArray*>(this)->m_pData) - 1);
  }
  bool referenced() const
  {
    return (buffer()->m_nRefCounter>1);
  }
};


#endif //ZC_ZCARRAY_H
