/*
 * File: trisolve.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/* Include Files */
#include "trisolve.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double A[9]
 *                double B[18]
 * Return Type  : void
 */
void b_trisolve(const double A[9], double B[18])
{
  double d;
  int b_i;
  int i;
  int i1;
  int j;
  int jBcol;
  int k;
  int kAcol;
  for (j = 0; j < 6; j++) {
    jBcol = 3 * j;
    for (k = 2; k >= 0; k--) {
      kAcol = 3 * k;
      i = k + jBcol;
      d = B[i];
      if (d != 0.0) {
        B[i] = d / A[k + kAcol];
        for (b_i = 0; b_i < k; b_i++) {
          i1 = b_i + jBcol;
          B[i1] -= B[i] * A[b_i + kAcol];
        }
      }
    }
  }
}

/*
 * Arguments    : const double A[9]
 *                double B[18]
 * Return Type  : void
 */
void trisolve(const double A[9], double B[18])
{
  double d;
  int b_i;
  int i;
  int i1;
  int i2;
  int j;
  int jBcol;
  int k;
  int kAcol;
  for (j = 0; j < 6; j++) {
    jBcol = 3 * j - 1;
    for (k = 0; k < 3; k++) {
      kAcol = 3 * k - 1;
      i = (k + jBcol) + 1;
      d = B[i];
      if (d != 0.0) {
        B[i] = d / A[(k + kAcol) + 1];
        i1 = k + 2;
        for (b_i = i1; b_i < 4; b_i++) {
          i2 = b_i + jBcol;
          B[i2] -= B[i] * A[b_i + kAcol];
        }
      }
    }
  }
}

/*
 * File trailer for trisolve.c
 *
 * [EOF]
 */
