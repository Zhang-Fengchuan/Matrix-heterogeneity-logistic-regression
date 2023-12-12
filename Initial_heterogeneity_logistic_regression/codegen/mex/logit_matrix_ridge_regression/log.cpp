//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// log.cpp
//
// Code generation for function 'log'
//

// Include files
#include "log.h"
#include "eml_int_forloop_overflow_check.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo tf_emlrtRSI{
    17,                                                        // lineNo
    "log",                                                     // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elfun\\log.m" // pathName
};

static emlrtRTEInfo u_emlrtRTEI{
    14,                                                        // lineNo
    9,                                                         // colNo
    "log",                                                     // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elfun\\log.m" // pName
};

// Function Definitions
namespace coder {
void b_log(const emlrtStack &sp, ::coder::array<real_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T nx;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  p = false;
  nx = x.size(0);
  for (int32_T k{0}; k < nx; k++) {
    if (p || (x[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
  }
  st.site = &tf_emlrtRSI;
  nx = x.size(0);
  b_st.site = &sf_emlrtRSI;
  if (x.size(0) > 2147483646) {
    c_st.site = &ye_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    x[k] = muDoubleScalarLog(x[k]);
  }
}

} // namespace coder

// End of code generation (log.cpp)
