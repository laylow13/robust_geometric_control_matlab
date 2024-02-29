/*
 * File: paramEstimator_internal_types.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

#ifndef PARAMESTIMATOR_INTERNAL_TYPES_H
#define PARAMESTIMATOR_INTERNAL_TYPES_H

/* Include Files */
#include "paramEstimator_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_trackingEKF
#define typedef_trackingEKF
typedef struct {
  double pState[6];
  double pSqrtStateCovariance[36];
  double pSqrtStateCovarianceScalar;
  boolean_T pIsSetStateCovariance;
  double pSqrtProcessNoise[36];
  double pSqrtProcessNoiseScalar;
  boolean_T pIsSetProcessNoise;
  double pSqrtMeasurementNoise[9];
  double pSqrtMeasurementNoiseScalar;
  boolean_T pIsSetMeasurementNoise;
  boolean_T pIsValidStateTransitionFcn;
  boolean_T pIsValidMeasurementFcn;
  boolean_T pIsFirstCallPredict;
  boolean_T pIsFirstCallCorrect;
  double pJacobian[36];
  boolean_T pIsDistributionsSetup;
  boolean_T pIsInitialized;
  boolean_T IsLastJacobianInitialized;
} trackingEKF;
#endif /* typedef_trackingEKF */

#endif
/*
 * File trailer for paramEstimator_internal_types.h
 *
 * [EOF]
 */
