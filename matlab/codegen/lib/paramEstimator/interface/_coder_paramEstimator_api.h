/*
 * File: _coder_paramEstimator_api.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

#ifndef _CODER_PARAMESTIMATOR_API_H
#define _CODER_PARAMESTIMATOR_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_param
#define typedef_param
typedef struct {
  real_T Ts;
  real_T gravity;
  real_T mass;
  real_T Jxx;
  real_T Jyy;
  real_T Jzz;
  real_T tau;
} param;
#endif /* typedef_param */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void paramEstimator(real_T u[23], param P[20], real_T out[8]);

void paramEstimator_api(const mxArray *const prhs[2], const mxArray **plhs);

void paramEstimator_atexit(void);

void paramEstimator_initialize(void);

void paramEstimator_terminate(void);

void paramEstimator_xil_shutdown(void);

void paramEstimator_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_paramEstimator_api.h
 *
 * [EOF]
 */
