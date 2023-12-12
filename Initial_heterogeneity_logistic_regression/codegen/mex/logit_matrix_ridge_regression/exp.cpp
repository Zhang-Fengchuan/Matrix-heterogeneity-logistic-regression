//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// exp.cpp
//
// Code generation for function 'exp'
//

// Include files
#include "exp.h"
#include "eml_int_forloop_overflow_check.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo rf_emlrtRSI{
    10,                                                        // lineNo
    "exp",                                                     // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" // pathName
};

// Function Definitions
namespace coder {
void b_exp(const emlrtStack &sp, ::coder::array<real_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &rf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(0);
  b_st.site = &sf_emlrtRSI;
  if (x.size(0) > 2147483646) {
    c_st.site = &ye_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    x[k] = muDoubleScalarExp(x[k]);
  }
}

} // namespace coder

// End of code generation (exp.cpp)
