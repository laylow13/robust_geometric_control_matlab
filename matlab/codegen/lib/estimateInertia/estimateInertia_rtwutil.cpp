//
// File: estimateInertia_rtwutil.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 29-Feb-2024 17:32:45
//

// Include Files
#include "estimateInertia_rtwutil.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

// Function Definitions
//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
int div_nde_s32_floor(int numerator, int denominator)
{
  int i;
  if (((numerator < 0) != (denominator < 0)) &&
      (numerator % denominator != 0)) {
    i = -1;
  } else {
    i = 0;
  }
  return numerator / denominator + i;
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = rtNaN;
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

//
// File trailer for estimateInertia_rtwutil.cpp
//
// [EOF]
//
