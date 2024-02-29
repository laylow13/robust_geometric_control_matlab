/*
 * File: paramEstimator.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

#ifndef PARAMESTIMATOR_H
#define PARAMESTIMATOR_H

/* Include Files */
#include "paramEstimator_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void paramEstimator(const double u[23], const param P[20],
                           double out[8]);

void paramEstimator_init(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for paramEstimator.h
 *
 * [EOF]
 */
