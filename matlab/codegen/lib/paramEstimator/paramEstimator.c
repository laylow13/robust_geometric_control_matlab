/*
 * File: paramEstimator.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/* Include Files */
#include "paramEstimator.h"
#include "EKFCorrector.h"
#include "paramEstimator_data.h"
#include "paramEstimator_initialize.h"
#include "paramEstimator_internal_types.h"
#include "paramEstimator_rtwutil.h"
#include "paramEstimator_types.h"
#include "rt_nonfinite.h"
#include "trackingEKF.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static boolean_T dvdt_not_empty;

static double m;

static double var_m;

static double R_m;

static double Q_m;

/* Function Definitions */
/*
 * inputs
 *
 * Arguments    : const double u[23]
 *                const param P[20]
 *                double out[8]
 * Return Type  : void
 */
void paramEstimator(const double u[23], const param P[20], double out[8])
{
  static trackingEKF ekf;
  static const double b_value[36] = {1.000499875062461,
                                     0.00099950037468777317,
                                     0.00099950037468777317,
                                     0.00099950037468777317,
                                     0.00099950037468777317,
                                     0.00099950037468777317,
                                     0.0,
                                     1.0004993758114,
                                     0.00099850237106926133,
                                     0.00099850237106926133,
                                     0.00099850237106926133,
                                     0.00099850237106926133,
                                     0.0,
                                     0.0,
                                     1.0004988775565997,
                                     0.00099750635848115622,
                                     0.00099750635848115622,
                                     0.00099750635848115622,
                                     0.0,
                                     0.0,
                                     0.0,
                                     1.0004983802950811,
                                     0.00099651233097119616,
                                     0.00099651233097119616,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     1.000497884023877,
                                     0.00099552028261082272,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     1.0004973887400315};
  static const double c_value[36] = {
      0.01, 0.0, 0.0,  0.0, 0.0,  0.0, 0.0, 0.01, 0.0, 0.0,  0.0, 0.0,
      0.0,  0.0, 0.01, 0.0, 0.0,  0.0, 0.0, 0.0,  0.0, 0.01, 0.0, 0.0,
      0.0,  0.0, 0.0,  0.0, 0.01, 0.0, 0.0, 0.0,  0.0, 0.0,  0.0, 0.01};
  static const double b_b[18] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  static const double d_value[9] = {0.01, 0.0, 0.0, 0.0, 0.01,
                                    0.0,  0.0, 0.0, 0.01};
  static const signed char b_iv[18] = {1, 0, 0, 0, 1, 0, 0, 0, 1,
                                       0, 0, 0, 0, 0, 0, 0, 0, 0};
  static const signed char iv1[18] = {1, 0, 0, 0, 0, 0, 0, 1, 0,
                                      0, 0, 0, 0, 0, 1, 0, 0, 0};
  static const signed char b[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  double dv[36];
  double M[27];
  double y[18];
  double R[9];
  double b_u[9];
  double c_u[4];
  double body_z[3];
  double work[3];
  double H_m;
  double K_m;
  double atmp;
  double beta1;
  int aoffset;
  int b_i;
  int exitg1;
  int i;
  int i1;
  int ii;
  int j;
  int k;
  int knt;
  int lastc;
  int lastv;
  boolean_T exitg2;
  (void)P;
  if (!isInitialized_paramEstimator) {
    paramEstimator_initialize();
  }
  /*  states */
  if (!dvdt_not_empty) {
    dvdt_not_empty = true;
    /*      dvdt.dot=v; */
    /*  初始化惯性矩阵估计  */
    /*  初始状态和协方差 */
    /*  创建trackingEKF对象 */
    ekf.pIsFirstCallPredict = true;
    ekf.pIsFirstCallCorrect = true;
    for (i = 0; i < 6; i++) {
      ekf.pState[i] = 0.001;
    }
    ekf.pIsSetStateCovariance = true;
    ekf.pSqrtStateCovarianceScalar = -1.0;
    ekf.pIsValidMeasurementFcn = false;
    ekf.pIsValidStateTransitionFcn = false;
    memcpy(&ekf.pSqrtStateCovariance[0], &b_value[0], 36U * sizeof(double));
    memcpy(&ekf.pSqrtProcessNoise[0], &c_value[0], 36U * sizeof(double));
    ekf.pIsSetProcessNoise = true;
    ekf.pSqrtProcessNoiseScalar = -1.0;
    memcpy(&ekf.pSqrtMeasurementNoise[0], &d_value[0], 9U * sizeof(double));
    ekf.pIsSetMeasurementNoise = true;
    ekf.pSqrtMeasurementNoiseScalar = -1.0;
    ekf.IsLastJacobianInitialized = false;
    ekf.pIsDistributionsSetup = false;
    ekf.pIsInitialized = false;
  }
  /*  mass estimate */
  /*  numerical derivatives */
  /*  acc = dvdt.calculate(v); */
  /*  1 predict */
  var_m += R_m;
  /*  2 update */
  memcpy(&b_u[0], &u[10], 9U * sizeof(double));
  for (b_i = 0; b_i < 3; b_i++) {
    body_z[b_i] = (b_u[b_i] * 0.0 + b_u[b_i + 3] * 0.0) + b_u[b_i + 6];
  }
  /*  calculate H */
  H_m = -u[0] * body_z[2] / (m * m);
  /*  calculate K */
  K_m = var_m * H_m;
  K_m /= K_m * H_m + Q_m;
  /*  update */
  m += K_m * (u[9] - (u[0] * body_z[2] / m - 9.81));
  var_m *= 1.0 - K_m * H_m;
  /*  inertia estimate */
  c_u[0] = u[1];
  c_u[1] = u[2];
  c_u[2] = u[3];
  c_u[3] = 0.01;
  trackingEKF_predict(&ekf, c_u);
  /*  预测下一时刻的状态 */
  if ((!ekf.pIsSetStateCovariance) ||
      (ekf.pSqrtStateCovarianceScalar != -1.0)) {
    for (b_i = 0; b_i < 36; b_i++) {
      ekf.pSqrtStateCovariance[b_i] =
          ekf.pSqrtStateCovarianceScalar * (double)iv[b_i];
    }
  }
  if (ekf.pIsFirstCallCorrect) {
    if (!ekf.pIsValidMeasurementFcn) {
      ekf.pIsValidMeasurementFcn = true;
    }
    ekf.pIsFirstCallCorrect = false;
  }
  if ((!ekf.pIsSetMeasurementNoise) ||
      (ekf.pSqrtMeasurementNoiseScalar != -1.0)) {
    for (b_i = 0; b_i < 9; b_i++) {
      ekf.pSqrtMeasurementNoise[b_i] =
          ekf.pSqrtMeasurementNoiseScalar * (double)b[b_i];
    }
    ekf.pIsSetMeasurementNoise = true;
    ekf.pSqrtMeasurementNoiseScalar = -1.0;
  }
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 6; i++) {
      aoffset = i * 6;
      K_m = 0.0;
      for (k = 0; k < 6; k++) {
        K_m += ekf.pSqrtStateCovariance[aoffset + k] * (double)b_iv[k * 3 + j];
      }
      M[i + 9 * j] = K_m;
    }
    M[9 * j + 6] = ekf.pSqrtMeasurementNoise[j];
    M[9 * j + 7] = ekf.pSqrtMeasurementNoise[j + 3];
    M[9 * j + 8] = ekf.pSqrtMeasurementNoise[j + 6];
    body_z[j] = 0.0;
    work[j] = 0.0;
  }
  for (i = 0; i < 3; i++) {
    ii = i * 9 + i;
    atmp = M[ii];
    aoffset = ii + 2;
    body_z[i] = 0.0;
    K_m = b_xnrm2(8 - i, M, ii + 2);
    if (K_m != 0.0) {
      H_m = M[ii];
      beta1 = rt_hypotd_snf(H_m, K_m);
      if (H_m >= 0.0) {
        beta1 = -beta1;
      }
      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        b_i = (ii - i) + 9;
        do {
          knt++;
          for (k = aoffset; k <= b_i; k++) {
            M[k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));
        beta1 = rt_hypotd_snf(atmp, b_xnrm2(8 - i, M, ii + 2));
        if (atmp >= 0.0) {
          beta1 = -beta1;
        }
        body_z[i] = (beta1 - atmp) / beta1;
        K_m = 1.0 / (atmp - beta1);
        for (k = aoffset; k <= b_i; k++) {
          M[k - 1] *= K_m;
        }
        for (k = 0; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        atmp = beta1;
      } else {
        body_z[i] = (beta1 - H_m) / beta1;
        K_m = 1.0 / (H_m - beta1);
        b_i = (ii - i) + 9;
        for (k = aoffset; k <= b_i; k++) {
          M[k - 1] *= K_m;
        }
        atmp = beta1;
      }
    }
    M[ii] = atmp;
    if (i + 1 < 3) {
      M[ii] = 1.0;
      if (body_z[i] != 0.0) {
        lastv = 9 - i;
        aoffset = (ii - i) + 8;
        while ((lastv > 0) && (M[aoffset] == 0.0)) {
          lastv--;
          aoffset--;
        }
        lastc = 1 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc + 1 > 0)) {
          aoffset = (ii + lastc * 9) + 9;
          knt = aoffset;
          do {
            exitg1 = 0;
            if (knt + 1 <= aoffset + lastv) {
              if (M[knt] != 0.0) {
                exitg1 = 1;
              } else {
                knt++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = -1;
      }
      if (lastv > 0) {
        k = ii + 10;
        if (lastc + 1 != 0) {
          memset(&work[0], 0, (unsigned int)(lastc + 1) * sizeof(double));
          b_i = (ii + 9 * lastc) + 10;
          for (j = k; j <= b_i; j += 9) {
            K_m = 0.0;
            i1 = (j + lastv) - 1;
            for (knt = j; knt <= i1; knt++) {
              K_m += M[knt - 1] * M[(ii + knt) - j];
            }
            aoffset = div_nde_s32_floor((j - ii) - 10, 9);
            work[aoffset] += K_m;
          }
        }
        if (!(-body_z[i] == 0.0)) {
          aoffset = ii;
          for (j = 0; j <= lastc; j++) {
            H_m = work[j];
            if (H_m != 0.0) {
              K_m = H_m * -body_z[i];
              b_i = aoffset + 10;
              i1 = lastv + aoffset;
              for (knt = b_i; knt <= i1 + 9; knt++) {
                M[knt - 1] += M[((ii + knt) - aoffset) - 10] * K_m;
              }
            }
            aoffset += 9;
          }
        }
      }
      M[ii] = atmp;
    }
  }
  for (j = 0; j < 3; j++) {
    for (i = 0; i <= j; i++) {
      b_u[i + 3 * j] = M[i + 9 * j];
    }
    b_i = j + 2;
    if (b_i <= 3) {
      memset(&b_u[(j * 3 + b_i) + -1], 0,
             (unsigned int)(-b_i + 4) * sizeof(double));
    }
    body_z[j] = u[j + 19] - ekf.pState[j];
  }
  for (b_i = 0; b_i < 6; b_i++) {
    for (i1 = 0; i1 < 6; i1++) {
      H_m = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        H_m += ekf.pSqrtStateCovariance[b_i + 6 * aoffset] *
               ekf.pSqrtStateCovariance[i1 + 6 * aoffset];
      }
      dv[b_i + 6 * i1] = H_m;
    }
    for (i1 = 0; i1 < 3; i1++) {
      H_m = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        H_m += dv[b_i + 6 * aoffset] * (double)iv1[aoffset + 6 * i1];
      }
      y[b_i + 6 * i1] = H_m;
    }
  }
  for (b_i = 0; b_i < 3; b_i++) {
    R[3 * b_i] = b_u[b_i];
    R[3 * b_i + 1] = b_u[b_i + 3];
    R[3 * b_i + 2] = b_u[b_i + 6];
  }
  c_EKFCorrector_correctStateAndS(ekf.pState, ekf.pSqrtStateCovariance, body_z,
                                  y, R, b_b, ekf.pSqrtMeasurementNoise);
  ekf.pIsSetStateCovariance = true;
  ekf.pSqrtStateCovarianceScalar = -1.0;
  if (!ekf.pIsInitialized) {
    ekf.pIsDistributionsSetup = true;
  }
  /*  根据实际测量值更新状态估计 */
  /*  获取更新后的状态和协方差 */
  /*  output */
  /*  m_err=m-P.mass; */
  /*  jxx_err=jxx-P.Jxx; */
  /*  jyy_err=jyy-P.Jyy; */
  /*  jzz_err=jzz-P.Jzz; */
  out[0] = m;
  out[1] = m;
  out[2] = ekf.pState[3];
  out[3] = ekf.pState[4];
  out[4] = ekf.pState[5];
  out[5] = ekf.pState[3];
  out[6] = ekf.pState[4];
  out[7] = ekf.pState[5];
}

/*
 * inputs
 *
 * Arguments    : void
 * Return Type  : void
 */
void paramEstimator_init(void)
{
  dvdt_not_empty = false;
  m = 0.001;
  var_m = 0.001;
  R_m = 0.001;
  Q_m = 0.01;
}

/*
 * File trailer for paramEstimator.c
 *
 * [EOF]
 */
