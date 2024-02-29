/*
 * File: _coder_paramEstimator_api.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/* Include Files */
#include "_coder_paramEstimator_api.h"
#include "_coder_paramEstimator_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131642U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "paramEstimator",                                     /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[23];

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P,
                               const char_T *identifier, param y[20]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, param y[20]);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const char_T *identifier))[23];

static const mxArray *emlrt_marshallOut(const real_T u[8]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[23];

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[23]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[23]
{
  real_T(*y)[23];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *P
 *                const char_T *identifier
 *                param y[20]
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P,
                               const char_T *identifier, param y[20])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(P), &thisId, y);
  emlrtDestroyArray(&P);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                param y[20]
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, param y[20])
{
  static const int32_T dims[2] = {1, 20};
  static const char_T *fieldNames[7] = {"Ts",  "gravity", "mass", "Jxx",
                                        "Jyy", "Jzz",     "tau"};
  emlrtMsgIdentifier thisId;
  int32_T i;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 2U,
                         (const void *)&dims[0]);
  for (i = 0; i < 20; i++) {
    thisId.fIdentifier = "Ts";
    y[i].Ts = e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "Ts")),
        &thisId);
    thisId.fIdentifier = "gravity";
    y[i].gravity = e_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 1, "gravity")),
        &thisId);
    thisId.fIdentifier = "mass";
    y[i].mass = e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "mass")),
        &thisId);
    thisId.fIdentifier = "Jxx";
    y[i].Jxx = e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 3, "Jxx")),
        &thisId);
    thisId.fIdentifier = "Jyy";
    y[i].Jyy = e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 4, "Jyy")),
        &thisId);
    thisId.fIdentifier = "Jzz";
    y[i].Jzz = e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 5, "Jzz")),
        &thisId);
    thisId.fIdentifier = "tau";
    y[i].tau = e_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 6, "tau")),
        &thisId);
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const char_T *identifier
 * Return Type  : real_T (*)[23]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const char_T *identifier))[23]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[23];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[8]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[8])
{
  static const int32_T i = 0;
  static const int32_T i1 = 8;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[23]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[23]
{
  static const int32_T dims[2] = {1, 23};
  real_T(*ret)[23];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[23])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray **plhs
 * Return Type  : void
 */
void paramEstimator_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  param P[20];
  real_T(*u)[23];
  real_T(*out)[8];
  st.tls = emlrtRootTLSGlobal;
  out = (real_T(*)[8])mxMalloc(sizeof(real_T[8]));
  /* Marshall function inputs */
  u = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "u");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "P", P);
  /* Invoke the target function */
  paramEstimator(*u, P, *out);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*out);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void paramEstimator_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  paramEstimator_xil_terminate();
  paramEstimator_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void paramEstimator_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void paramEstimator_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_paramEstimator_api.c
 *
 * [EOF]
 */
