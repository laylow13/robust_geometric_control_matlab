/*
 * File: trackingEKF.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/* Include Files */
#include "trackingEKF.h"
#include "mldivide.h"
#include "paramEstimator_data.h"
#include "paramEstimator_internal_types.h"
#include "paramEstimator_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : trackingEKF *filter
 *                const double varargin_1[4]
 * Return Type  : void
 */
void trackingEKF_predict(trackingEKF *filter, const double varargin_1[4])
{
  double M[72];
  double C[36];
  double inertia[9];
  double imvec[6];
  double work[6];
  double z[6];
  double b_varargin_1[3];
  double y[3];
  double beta1;
  double d;
  double epsilon;
  double s;
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
  if (!filter->IsLastJacobianInitialized) {
    filter->IsLastJacobianInitialized = true;
  }
  if (!filter->pIsDistributionsSetup) {
    filter->pIsDistributionsSetup = true;
  }
  if ((!filter->pIsSetStateCovariance) ||
      (filter->pSqrtStateCovarianceScalar != -1.0)) {
    s = filter->pSqrtStateCovarianceScalar;
    for (i = 0; i < 36; i++) {
      filter->pSqrtStateCovariance[i] = s * (double)iv[i];
    }
  }
  if ((!filter->pIsSetProcessNoise) ||
      (filter->pSqrtProcessNoiseScalar != -1.0)) {
    s = filter->pSqrtProcessNoiseScalar;
    for (i = 0; i < 36; i++) {
      filter->pSqrtProcessNoise[i] = s * (double)iv[i];
    }
    filter->pIsSetProcessNoise = true;
    filter->pSqrtProcessNoiseScalar = -1.0;
  }
  if (filter->pIsFirstCallPredict) {
    if (!filter->pIsValidStateTransitionFcn) {
      filter->pIsValidStateTransitionFcn = true;
    }
    filter->pIsFirstCallPredict = false;
  }
  /*  disp(x); */
  memset(&inertia[0], 0, 9U * sizeof(double));
  inertia[0] = filter->pState[3];
  inertia[4] = filter->pState[4];
  inertia[8] = filter->pState[5];
  d = filter->pState[0];
  s = filter->pState[1];
  beta1 = filter->pState[2];
  for (i = 0; i < 3; i++) {
    y[i] = (inertia[i] * d + inertia[i + 3] * s) + inertia[i + 6] * beta1;
  }
  b_varargin_1[0] =
      varargin_1[0] - (filter->pState[1] * y[2] - y[1] * filter->pState[2]);
  b_varargin_1[1] =
      varargin_1[1] - (y[0] * filter->pState[2] - filter->pState[0] * y[2]);
  b_varargin_1[2] =
      varargin_1[2] - (filter->pState[0] * y[1] - y[0] * filter->pState[1]);
  mldivide(inertia, b_varargin_1, y);
  z[0] = filter->pState[0] + 0.01 * y[0];
  z[3] = filter->pState[3];
  z[1] = filter->pState[1] + 0.01 * y[1];
  z[4] = filter->pState[4];
  z[2] = filter->pState[2] + 0.01 * y[2];
  z[5] = filter->pState[5];
  for (j = 0; j < 6; j++) {
    s = 1.4901161193847656E-8 * fabs(filter->pState[j]);
    if ((s <= 1.4901161193847656E-8) || rtIsNaN(s)) {
      epsilon = 1.4901161193847656E-8;
    } else {
      epsilon = s;
    }
    for (b_i = 0; b_i < 6; b_i++) {
      imvec[b_i] = filter->pState[b_i];
    }
    imvec[j] = filter->pState[j] + epsilon;
    /*  disp(x); */
    memset(&inertia[0], 0, 9U * sizeof(double));
    inertia[0] = imvec[3];
    inertia[4] = imvec[4];
    inertia[8] = imvec[5];
    d = imvec[0];
    s = imvec[1];
    beta1 = imvec[2];
    for (i = 0; i < 3; i++) {
      y[i] = (inertia[i] * d + inertia[i + 3] * s) + inertia[i + 6] * beta1;
    }
    b_varargin_1[0] = varargin_1[0] - (imvec[1] * y[2] - y[1] * imvec[2]);
    b_varargin_1[1] = varargin_1[1] - (y[0] * imvec[2] - imvec[0] * y[2]);
    b_varargin_1[2] = varargin_1[2] - (imvec[0] * y[1] - y[0] * imvec[1]);
    mldivide(inertia, b_varargin_1, y);
    work[0] = imvec[0] + y[0] * varargin_1[3];
    work[3] = imvec[3];
    work[1] = imvec[1] + y[1] * varargin_1[3];
    work[4] = imvec[4];
    work[2] = imvec[2] + y[2] * varargin_1[3];
    work[5] = imvec[5];
    for (i = 0; i < 6; i++) {
      filter->pJacobian[i + 6 * j] = (work[i] - z[i]) / epsilon;
    }
  }
  /*  disp(x); */
  memset(&inertia[0], 0, 9U * sizeof(double));
  inertia[0] = filter->pState[3];
  inertia[4] = filter->pState[4];
  inertia[8] = filter->pState[5];
  d = filter->pState[0];
  s = filter->pState[1];
  beta1 = filter->pState[2];
  for (i = 0; i < 3; i++) {
    y[i] = (inertia[i] * d + inertia[i + 3] * s) + inertia[i + 6] * beta1;
  }
  b_varargin_1[0] =
      varargin_1[0] - (filter->pState[1] * y[2] - y[1] * filter->pState[2]);
  b_varargin_1[1] =
      varargin_1[1] - (y[0] * filter->pState[2] - filter->pState[0] * y[2]);
  b_varargin_1[2] =
      varargin_1[2] - (filter->pState[0] * y[1] - y[0] * filter->pState[1]);
  mldivide(inertia, b_varargin_1, y);
  z[0] = filter->pState[0] + y[0] * varargin_1[3];
  z[3] = filter->pState[3];
  z[1] = filter->pState[1] + y[1] * varargin_1[3];
  z[4] = filter->pState[4];
  z[2] = filter->pState[2] + y[2] * varargin_1[3];
  z[5] = filter->pState[5];
  for (j = 0; j < 6; j++) {
    for (b_i = 0; b_i < 6; b_i++) {
      aoffset = b_i * 6;
      s = 0.0;
      for (k = 0; k < 6; k++) {
        s += filter->pSqrtStateCovariance[aoffset + k] *
             filter->pJacobian[k * 6 + j];
      }
      aoffset = b_i + 12 * j;
      M[aoffset] = s;
      M[aoffset + 6] = filter->pSqrtProcessNoise[j + 6 * b_i];
    }
    imvec[j] = 0.0;
    work[j] = 0.0;
  }
  for (b_i = 0; b_i < 6; b_i++) {
    ii = b_i * 12 + b_i;
    epsilon = M[ii];
    aoffset = ii + 2;
    imvec[b_i] = 0.0;
    s = xnrm2(11 - b_i, M, ii + 2);
    if (s != 0.0) {
      d = M[ii];
      beta1 = rt_hypotd_snf(d, s);
      if (d >= 0.0) {
        beta1 = -beta1;
      }
      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        i = (ii - b_i) + 12;
        do {
          knt++;
          for (k = aoffset; k <= i; k++) {
            M[k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          epsilon *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));
        beta1 = rt_hypotd_snf(epsilon, xnrm2(11 - b_i, M, ii + 2));
        if (epsilon >= 0.0) {
          beta1 = -beta1;
        }
        imvec[b_i] = (beta1 - epsilon) / beta1;
        s = 1.0 / (epsilon - beta1);
        for (k = aoffset; k <= i; k++) {
          M[k - 1] *= s;
        }
        for (k = 0; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        epsilon = beta1;
      } else {
        imvec[b_i] = (beta1 - d) / beta1;
        s = 1.0 / (d - beta1);
        i = (ii - b_i) + 12;
        for (k = aoffset; k <= i; k++) {
          M[k - 1] *= s;
        }
        epsilon = beta1;
      }
    }
    M[ii] = epsilon;
    if (b_i + 1 < 6) {
      M[ii] = 1.0;
      if (imvec[b_i] != 0.0) {
        lastv = 12 - b_i;
        aoffset = (ii - b_i) + 11;
        while ((lastv > 0) && (M[aoffset] == 0.0)) {
          lastv--;
          aoffset--;
        }
        lastc = 4 - b_i;
        exitg2 = false;
        while ((!exitg2) && (lastc + 1 > 0)) {
          aoffset = (ii + lastc * 12) + 12;
          k = aoffset;
          do {
            exitg1 = 0;
            if (k + 1 <= aoffset + lastv) {
              if (M[k] != 0.0) {
                exitg1 = 1;
              } else {
                k++;
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
        knt = ii + 13;
        if (lastc + 1 != 0) {
          memset(&work[0], 0, (unsigned int)(lastc + 1) * sizeof(double));
          i = (ii + 12 * lastc) + 13;
          for (j = knt; j <= i; j += 12) {
            s = 0.0;
            i1 = (j + lastv) - 1;
            for (k = j; k <= i1; k++) {
              s += M[k - 1] * M[(ii + k) - j];
            }
            aoffset = div_nde_s32_floor((j - ii) - 13, 12);
            work[aoffset] += s;
          }
        }
        if (!(-imvec[b_i] == 0.0)) {
          aoffset = ii;
          for (j = 0; j <= lastc; j++) {
            d = work[j];
            if (d != 0.0) {
              s = d * -imvec[b_i];
              i = aoffset + 13;
              i1 = lastv + aoffset;
              for (knt = i; knt <= i1 + 12; knt++) {
                M[knt - 1] += M[((ii + knt) - aoffset) - 13] * s;
              }
            }
            aoffset += 12;
          }
        }
      }
      M[ii] = epsilon;
    }
  }
  for (j = 0; j < 6; j++) {
    for (b_i = 0; b_i <= j; b_i++) {
      C[b_i + 6 * j] = M[b_i + 12 * j];
    }
    i = j + 2;
    if (i <= 6) {
      memset(&C[(j * 6 + i) + -1], 0, (unsigned int)(-i + 7) * sizeof(double));
    }
    filter->pState[j] = z[j];
  }
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      filter->pSqrtStateCovariance[i1 + 6 * i] = C[i + 6 * i1];
    }
  }
  filter->pIsSetStateCovariance = true;
  filter->pSqrtStateCovarianceScalar = -1.0;
}

/*
 * File trailer for trackingEKF.c
 *
 * [EOF]
 */
