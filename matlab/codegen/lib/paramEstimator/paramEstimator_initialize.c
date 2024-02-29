/*
 * File: paramEstimator_initialize.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/* Include Files */
#include "paramEstimator_initialize.h"
#include "paramEstimator.h"
#include "paramEstimator_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void paramEstimator_initialize(void)
{
  rt_InitInfAndNaN();
  paramEstimator_init();
  isInitialized_paramEstimator = true;
}

/*
 * File trailer for paramEstimator_initialize.c
 *
 * [EOF]
 */
