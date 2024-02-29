/*
 * File: EKFCorrector.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

#ifndef EKFCORRECTOR_H
#define EKFCORRECTOR_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_EKFCorrector_correctStateAndS(double x[6], double S[36],
                                     const double residue[3],
                                     const double Pxy[18], const double Sy[9],
                                     const double H[18], const double Rsqrt[9]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for EKFCorrector.h
 *
 * [EOF]
 */
