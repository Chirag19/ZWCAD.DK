#ifndef ZC_GEINTRVL_H
#define ZC_GEINTRVL_H

#include "zgegbl.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeInterval
{
public:
    ZcGeInterval(double tol = 1.e-12);
    ZcGeInterval(const ZcGeInterval& src);
    ZcGeInterval(double lower, double upper, double tol = 1.e-12);
    ZcGeInterval(Zdesk::Boolean boundedBelow, double bound,
                 double tol = 1.e-12);
    ~ZcGeInterval();

    ZcGeInterval&  operator =       (const ZcGeInterval& otherInterval);

    double         lowerBound       () const;
    double         upperBound       () const;
    double         element          () const;
    void           getBounds        (double& lower, double& upper) const;
    double         length           () const;
    double         tolerance        () const;

    ZcGeInterval&  set              (double lower, double upper);
    ZcGeInterval&  set              (Zdesk::Boolean boundedBelow, double bound);
    ZcGeInterval&  set              ();
    ZcGeInterval&  setUpper         (double upper);
    ZcGeInterval&  setLower         (double lower);
    ZcGeInterval&  setTolerance     (double tol);

    void           getMerge         (const ZcGeInterval& otherInterval, ZcGeInterval& result) const;
    int            subtract         (const ZcGeInterval& otherInterval,
                                     ZcGeInterval& lInterval,
                                     ZcGeInterval& rInterval) const;
    Zdesk::Boolean intersectWith    (const ZcGeInterval& otherInterval, ZcGeInterval& result) const;

    Zdesk::Boolean isBounded        () const;
    Zdesk::Boolean isBoundedAbove   () const;
    Zdesk::Boolean isBoundedBelow   () const;
    Zdesk::Boolean isUnBounded      () const;
    Zdesk::Boolean isSingleton      () const;

    Zdesk::Boolean isDisjoint       (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean contains         (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean contains         (double val) const;

    Zdesk::Boolean isContinuousAtUpper (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean isOverlapAtUpper    (const ZcGeInterval& otherInterval,
                                        ZcGeInterval& overlap) const;
    Zdesk::Boolean operator ==      (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean operator !=      (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean isEqualAtUpper   (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean isEqualAtUpper   (double value) const;
    Zdesk::Boolean isEqualAtLower   (const ZcGeInterval& otherInterval) const;
    Zdesk::Boolean isEqualAtLower   (double value) const;

    Zdesk::Boolean isPeriodicallyOn (double period, double& val);

    friend
    GE_DLLEXPIMPORT
    Zdesk::Boolean operator >       (double val, const ZcGeInterval& intrvl);
    Zdesk::Boolean operator >       (double val) const;
    Zdesk::Boolean operator >       (const ZcGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    Zdesk::Boolean operator >=      (double val, const ZcGeInterval& intrvl);
    Zdesk::Boolean operator >=      (double val) const;
    Zdesk::Boolean operator >=      (const ZcGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    Zdesk::Boolean operator <       (double val, const ZcGeInterval& intrvl);
    Zdesk::Boolean operator <       (double val) const;
    Zdesk::Boolean operator <       (const ZcGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    Zdesk::Boolean operator <=      (double val, const ZcGeInterval& intrvl);
    Zdesk::Boolean operator <=      (double val) const;
    Zdesk::Boolean operator <=      (const ZcGeInterval& otherInterval) const;

public:
    friend class ZcGeImpInterval;

    ZcGeImpInterval  *mpImpInt;
    int              mDelInt;

    ZcGeInterval (ZcGeImpInterval&, int);
};

#pragma pack (pop)
#endif
