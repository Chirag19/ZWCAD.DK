#ifndef ZC_GEKVEC_H
#define ZC_GEKVEC_H

#include "zgegbl.h"
#include "zgedblar.h"
#pragma pack (push, 8)

class ZcGeInterval;

class
GE_DLLEXPIMPORT
ZcGeKnotVector
{
public:
    ZcGeKnotVector(double eps = 1.e-9);
    ZcGeKnotVector(int size, int growSize, double eps = 1.e-9);
    ZcGeKnotVector(int size, const double [], double eps = 1.e-9);
    ZcGeKnotVector(int plusMult, const ZcGeKnotVector& src);
    ZcGeKnotVector(const ZcGeKnotVector& src);
    ZcGeKnotVector(const ZcGeDoubleArray& src, double eps = 1.e-9);

    ~ZcGeKnotVector();

    ZcGeKnotVector&     operator =  (const ZcGeKnotVector& src);
    ZcGeKnotVector&     operator =  (const ZcGeDoubleArray& src);

    double&             operator [] (int);
    const double        operator [] (int) const;

    Zdesk::Boolean      isEqualTo (const ZcGeKnotVector& other) const;

    double              startParam         () const;
    double              endParam           () const;
    int                 multiplicityAt     (int i) const;
    int                 numIntervals       () const;

    int                 getInterval        (int ord, double par,
                                            ZcGeInterval& interval ) const;
    void                getDistinctKnots   (ZcGeDoubleArray& knots) const;
    Zdesk::Boolean      contains           (double param) const;
    Zdesk::Boolean      isOn               (double knot) const;

    ZcGeKnotVector&     reverse            ();
    ZcGeKnotVector&     removeAt           (int);
    ZcGeKnotVector&     removeSubVector    (int startIndex, int endIndex);

    ZcGeKnotVector&     insertAt           (int indx, double u,
                                            int multiplicity = 1);
    ZcGeKnotVector&     insert             (double u);
    int                 append             (double val);
    ZcGeKnotVector&     append             (ZcGeKnotVector& tail,
                                            double knotRatio = 0.);
    int                 split              (double par,
                                            ZcGeKnotVector* pKnot1,
                                            int multLast,
                                            ZcGeKnotVector* pKnot2,
                                            int multFirst ) const;


    ZcGeKnotVector&     setRange           (double lower, double upper);

    double              tolerance          () const;
    ZcGeKnotVector&     setTolerance       (double tol);

    int                 length             () const;
    Zdesk::Boolean      isEmpty            () const;
    int                 logicalLength      () const;
    ZcGeKnotVector&     setLogicalLength   (int);
    int                 physicalLength     () const;
    ZcGeKnotVector&     setPhysicalLength  (int);

    int                 growLength  () const;
    ZcGeKnotVector&     setGrowLength(int);

    const double*       asArrayPtr  () const;
    double*             asArrayPtr  ();

    ZcGeKnotVector&     set (int size, const double [], double eps = 1.e-9);

protected:
    ZcGeDoubleArray    mData;
    double             mTolerance;

    Zdesk::Boolean     isValid (int) const;
};



#pragma pack (pop)
#endif
