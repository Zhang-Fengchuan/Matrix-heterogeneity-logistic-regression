//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_logit_matrix_ridge_regression_api.cpp
//
// Code generation for function '_coder_logit_matrix_ridge_regression_api'
//

// Include files
#include "_coder_logit_matrix_ridge_regression_api.h"
#include "logit_matrix_ridge_regression.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *x,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *y,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &b_y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *n,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{-1, -1, -1};
  int32_T iv[3];
  boolean_T bv[3]{true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1] * iv[2]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1], iv[2]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1),
          ret.size(2));
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.prealloc(i);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, i);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *x,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *y,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &b_y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(y), &thisId, b_y);
  emlrtDestroyArray(&y);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *n,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(n), &thisId);
  emlrtDestroyArray(&n);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void c_logit_matrix_ridge_regression(const mxArray *const prhs[13],
                                     int32_T nlhs, const mxArray *plhs[5])
{
  coder::array<real_T, 3U> x;
  coder::array<real_T, 1U> beta_part;
  coder::array<real_T, 1U> coefficients0;
  coder::array<real_T, 1U> gamma_part;
  coder::array<real_T, 1U> y;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *prhs_copy_idx_6;
  real_T col_size;
  real_T cv_number;
  real_T diff_loglikelihood;
  real_T eps_initial;
  real_T if_fix;
  real_T iter_initial_in;
  real_T iter_max_initial_in;
  real_T lambda_best;
  real_T n;
  real_T row_size;
  real_T tuning_end;
  real_T tuning_number;
  real_T tuning_start;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  prhs_copy_idx_6 = emlrtProtectR2012b(prhs[6], 6, false, -1);
  // Marshall function inputs
  x.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "x", x);
  y.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[1]), "y", y);
  n = emlrt_marshallIn(st, emlrtAliasP(prhs[2]), "n");
  row_size = emlrt_marshallIn(st, emlrtAliasP(prhs[3]), "row_size");
  col_size = emlrt_marshallIn(st, emlrtAliasP(prhs[4]), "col_size");
  cv_number = emlrt_marshallIn(st, emlrtAliasP(prhs[5]), "cv_number");
  coefficients0.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_6), "coefficients0",
                   coefficients0);
  tuning_start = emlrt_marshallIn(st, emlrtAliasP(prhs[7]), "tuning_start");
  tuning_end = emlrt_marshallIn(st, emlrtAliasP(prhs[8]), "tuning_end");
  tuning_number = emlrt_marshallIn(st, emlrtAliasP(prhs[9]), "tuning_number");
  eps_initial = emlrt_marshallIn(st, emlrtAliasP(prhs[10]), "eps_initial");
  iter_max_initial_in =
      emlrt_marshallIn(st, emlrtAliasP(prhs[11]), "iter_max_initial_in");
  if_fix = emlrt_marshallIn(st, emlrtAliasP(prhs[12]), "if_fix");
  // Invoke the target function
  logit_matrix_ridge_regression(&st, x, y, n, row_size, col_size, cv_number,
                                coefficients0, tuning_start, tuning_end,
                                tuning_number, eps_initial, iter_max_initial_in,
                                if_fix, beta_part, gamma_part, &lambda_best,
                                &iter_initial_in, &diff_loglikelihood);
  // Marshall function outputs
  beta_part.no_free();
  plhs[0] = emlrt_marshallOut(beta_part);
  if (nlhs > 1) {
    gamma_part.no_free();
    plhs[1] = emlrt_marshallOut(gamma_part);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(lambda_best);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(iter_initial_in);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(diff_loglikelihood);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_logit_matrix_ridge_regression_api.cpp)
