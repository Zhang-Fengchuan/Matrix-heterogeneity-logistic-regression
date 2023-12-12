//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// permute.cpp
//
// Code generation for function 'permute'
//

// Include files
#include "permute.h"
#include "eml_int_forloop_overflow_check.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo gf_emlrtRSI{
    44,                                                            // lineNo
    "permute",                                                     // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    47,                                                            // lineNo
    "permute",                                                     // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

static emlrtRSInfo if_emlrtRSI{
    53,                                                            // lineNo
    "permute",                                                     // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

static emlrtRSInfo lf_emlrtRSI{
    71,                                                            // lineNo
    "looper",                                                      // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

static emlrtRSInfo mf_emlrtRSI{
    72,                                                            // lineNo
    "looper",                                                      // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

static emlrtRTEInfo af_emlrtRTEI{
    47,                                                            // lineNo
    20,                                                            // colNo
    "permute",                                                     // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pName
};

static emlrtRTEInfo bf_emlrtRTEI{
    44,                                                            // lineNo
    5,                                                             // colNo
    "permute",                                                     // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pName
};

// Function Definitions
namespace coder {
void permute(const emlrtStack &sp, const ::coder::array<real_T, 3U> &a,
             ::coder::array<real_T, 3U> &b)
{
  static const int8_T iv[3]{1, 3, 2};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k;
  int32_T plast;
  int32_T subsa_idx_1;
  int32_T subsa_idx_2;
  boolean_T b_b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_b = true;
  if ((a.size(0) != 0) && (a.size(1) != 0) && (a.size(2) != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (a.size(iv[k] - 1) != 1) {
        if (plast > iv[k]) {
          b_b = false;
          exitg1 = true;
        } else {
          plast = iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b_b) {
    int32_T nx;
    st.site = &gf_emlrtRSI;
    nx = a.size(0) * a.size(1) * a.size(2);
    b_st.site = &jf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    plast = a.size(0);
    if (a.size(1) > a.size(0)) {
      plast = a.size(1);
    }
    if (a.size(2) > plast) {
      plast = a.size(2);
    }
    plast = muIntScalarMax_sint32(nx, plast);
    if (a.size(0) > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a.size(2) > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a.size(1) > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    plast = a.size(0) * a.size(2) * a.size(1);
    if (plast != nx) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b.set_size(&bf_emlrtRTEI, &sp, a.size(0), a.size(2), a.size(1));
    for (nx = 0; nx < plast; nx++) {
      b[nx] = a[nx];
    }
  } else {
    int32_T nx;
    st.site = &hf_emlrtRSI;
    nx = a.size(0) * a.size(1) * a.size(2);
    b_st.site = &jf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    plast = a.size(0);
    if (a.size(1) > a.size(0)) {
      plast = a.size(1);
    }
    if (a.size(2) > plast) {
      plast = a.size(2);
    }
    plast = muIntScalarMax_sint32(nx, plast);
    if (a.size(0) > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a.size(2) > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a.size(1) > plast) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (a.size(0) * a.size(2) * a.size(1) != nx) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b.set_size(&af_emlrtRTEI, &sp, a.size(0), a.size(2), a.size(1));
    st.site = &if_emlrtRSI;
    plast = a.size(2);
    b_st.site = &lf_emlrtRSI;
    if (a.size(2) > 2147483646) {
      c_st.site = &ye_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (k = 0; k < plast; k++) {
      b_st.site = &mf_emlrtRSI;
      nx = a.size(1);
      c_st.site = &lf_emlrtRSI;
      if (a.size(1) > 2147483646) {
        d_st.site = &ye_emlrtRSI;
        check_forloop_overflow_error(d_st);
      }
      for (int32_T b_k{0}; b_k < nx; b_k++) {
        int32_T c_b;
        c_st.site = &mf_emlrtRSI;
        c_b = a.size(0);
        d_st.site = &lf_emlrtRSI;
        if (a.size(0) > 2147483646) {
          e_st.site = &ye_emlrtRSI;
          check_forloop_overflow_error(e_st);
        }
        if (a.size(0) - 1 >= 0) {
          subsa_idx_1 = b_k + 1;
          subsa_idx_2 = k + 1;
        }
        for (int32_T c_k{0}; c_k < c_b; c_k++) {
          b[(c_k + b.size(0) * (subsa_idx_2 - 1)) +
            b.size(0) * b.size(1) * (subsa_idx_1 - 1)] =
              a[(c_k + a.size(0) * (subsa_idx_1 - 1)) +
                a.size(0) * a.size(1) * (subsa_idx_2 - 1)];
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (permute.cpp)
