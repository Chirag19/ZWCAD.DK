

#ifndef _ZNavDataArray_h
#define _ZNavDataArray_h 1

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
#pragma warning(push)
#pragma warning(disable : 4275)

class ZNAV_PORT CNavDataArray : public CNavArray<CNavData> {
public:
                CNavDataArray ();
virtual         ~CNavDataArray ();
};

#pragma warning(pop)

#endif
