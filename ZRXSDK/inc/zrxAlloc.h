
#ifndef _ZRXALLOC_H_
#define _ZRXALLOC_H_

#pragma once

extern "C"
{

void* zcrxAlloc(size_t s);

void* zcrxRealloc(void* p, size_t new_size, size_t old_size);

void zcrxFree(void* p);


}


inline int ZcInterlockedExchange(volatile int* dest, int val)
{
  __asm
  {
    mov edx, dest
    mov eax, val
    lock xchg [edx], eax
  }
}
inline int ZcInterlockedExchangeAdd(volatile int* dest, int incr)
{
  __asm
  {
    mov edx, dest
    mov eax, incr
    lock xadd [edx], eax
  }
}
inline int ZcInterlockedIncrement(volatile int* dest)
{
  __asm
  {
    mov edx, dest
    mov eax, 1
    lock xadd [edx], eax
    inc eax
  }
}
inline int ZcInterlockedDecrement(volatile int* dest)
{
  __asm
  {
    mov edx, dest
    mov eax, -1
    lock xadd [edx], eax
    dec eax
  }
}

struct ZcRefCounter
{
  typedef int RefCounterType;
  volatile RefCounterType _ref_count;
  ZcRefCounter& operator = (RefCounterType n) { _ref_count = 0; ZcInterlockedExchange(&_ref_count, n); return *this; }
  operator RefCounterType () const { return ZcInterlockedExchangeAdd(const_cast<RefCounterType*>(&_ref_count), 0); }
  RefCounterType operator ++ () { return ZcInterlockedIncrement(&_ref_count); }
  RefCounterType operator -- () { return ZcInterlockedDecrement(&_ref_count); }
};




#endif	//_ZRXALLOC_H_
