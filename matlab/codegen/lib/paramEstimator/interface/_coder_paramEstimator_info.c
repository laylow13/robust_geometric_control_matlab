/*
 * File: _coder_paramEstimator_info.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Feb-2024 16:44:30
 */

/* Include Files */
#include "_coder_paramEstimator_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
      "789cc553cd4ac340109e4a2d5eaa15c1930fa01711aa170f1e6c551414a5b508ad609a4c"
      "cdd26c12936d688f9e3c78f0253cf80c3e80f80c3e8d936493fec092"
      "426b5dd87cf3edc7eeb733b381dcf9650e0056211e1f85188b9297242ec1f898d4730a4c"
      "c632e4c7f625fa9b44ddb105f6454c6c8d63bad37038b3355bd4072e",
      "8287be630568444a875958671c6ba3e42a64fc74444a49288571c544bd5beb71f04c7f78"
      "436b94a4f5f856e49b9fb21e65453dd625762436e104ee691e420b3e"
      "5f5fb0053a38600012afd1fa369db443b14f2b6578821e68a4b680130ab0e8db26e6127a"
      "3439edf0699d49dda1d55d8a8779b933e6b5a6c8ab34a15799270655",
      "f458a0091660eaff30a37f41e91f2b86d36b5b38bf3eee2bfc923e9a129b5099431fabd4"
      "398ff880227af4c482480f11a34e66d531a97f565eaaffb5082b11be"
      "1ffd44d2a2fcb6be9e3716e9978cfff2eb2bce9bf65d6e2afc4a13fa5ec36d3cb25bbd2b"
      "1ae2f8eee2a02d84797336bcc775864fd63d40c1fffafc5f329d6c81",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1728U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum",    "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "PropertyList"};
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("paramEstimator"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString("E:\\\xe8\xae\xba\xe6\x96\x87\\code\\SE(3)"
                                    "\\se3quad\\matlab\\paramEstimator.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739311.68660879624));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2206163 (R2023a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("1o1Vy7zrvSCzjEn94KNbGF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_paramEstimator_info.c
 *
 * [EOF]
 */
