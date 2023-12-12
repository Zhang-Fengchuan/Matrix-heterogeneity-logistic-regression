//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo me_emlrtRSI{
    20,                                                          // lineNo
    "sum",                                                       // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo
    ne_emlrtRSI{
        99,        // lineNo
        "sumprod", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod."
        "m" // pathName
    };

static emlrtRSInfo oe_emlrtRSI{
    74,                      // lineNo
    "combineVectorElements", // fcnName
    "D:"
    "\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorE"
    "lements.m" // pathName
};

static emlrtRSInfo pe_emlrtRSI{
    107,                // lineNo
    "blockedSummation", // fcnName
    "D:"
    "\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummati"
    "on.m" // pathName
};

static emlrtRSInfo qe_emlrtRSI{
    22,                    // lineNo
    "sumMatrixIncludeNaN", // fcnName
    "D:"
    "\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixInclu"
    "deNaN.m" // pathName
};

static emlrtRSInfo re_emlrtRSI{
    42,                 // lineNo
    "sumMatrixColumns", // fcnName
    "D:"
    "\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixInclu"
    "deNaN.m" // pathName
};

static emlrtRSInfo se_emlrtRSI{
    57,                 // lineNo
    "sumMatrixColumns", // fcnName
    "D:"
    "\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixInclu"
    "deNaN.m" // pathName
};

// Function Definitions
namespace coder {
real_T sum(const emlrtStack &sp, const ::coder::array<real_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &me_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ne_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    d_st.site = &pe_emlrtRSI;
    e_st.site = &qe_emlrtRSI;
    if (x.size(0) < 4096) {
      f_st.site = &re_emlrtRSI;
      y = sumColumnB(f_st, x, x.size(0));
    } else {
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = static_cast<int32_T>(static_cast<uint32_T>(x.size(0)) >> 12);
      inb = nfb << 12;
      nleft = x.size(0) - inb;
      y = sumColumnB4(x, 1);
      for (int32_T ib{2}; ib <= nfb; ib++) {
        y += sumColumnB4(x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        f_st.site = &se_emlrtRSI;
        y += sumColumnB(f_st, x, nleft, inb + 1);
      }
    }
  }
  return y;
}

} // namespace coder

// End of code generation (sum.cpp)
