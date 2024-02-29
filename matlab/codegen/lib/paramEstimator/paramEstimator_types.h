/*
 * File: paramEstimator_types.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

#ifndef PARAMESTIMATOR_TYPES_H
#define PARAMESTIMATOR_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_param
#define typedef_param
typedef struct {
  double Ts;
  double gravity;
  double mass;
  double Jxx;
  double Jyy;
  double Jzz;
  double tau;
} param;
#endif /* typedef_param */

#endif
/*
 * File trailer for paramEstimator_types.h
 *
 * [EOF]
 */
