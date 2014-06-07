#pragma once

#ifndef _GE_POLYNOM_
#define _GE_POLYNOM_

#include "ge\gedoublearray.h"

// Polynomial of arbitrary degree with real of koefficients

class ZcGePolynomial : public OdGeDoubleArray
{
public:
  
  double operator() (double arg) const;
  void setToSum(const ZcGePolynomial& first, const ZcGePolynomial& second);
  void setToProduct(const ZcGePolynomial& first, const ZcGePolynomial& second);

  // searches all real roots of polynomial
  void findRoots(OdGeDoubleArray& roots) const;
  
  // if koefficients of polynom near degree-forming members are near to zero,
  // decreases the degree.
  void killDummyDegree(double tolerance);

  void standartize();

  // used to choose more suitable polynom for finding roots
  double norma();
  
  // gets the first derivative
  void getDerivative(ZcGePolynomial& deriv);
};

#endif // _GE_POLYNOM_
