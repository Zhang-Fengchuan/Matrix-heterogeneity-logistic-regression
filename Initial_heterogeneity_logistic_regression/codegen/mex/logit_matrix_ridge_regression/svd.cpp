//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd.cpp
//
// Code generation for function 'svd'
//

// Include files
#include "svd.h"
#include "eml_int_forloop_overflow_check.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo kg_emlrtRSI{
    23,                                                            // lineNo
    "svd",                                                         // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo lg_emlrtRSI{
    52,                                                            // lineNo
    "svd",                                                         // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo mg_emlrtRSI{
    163,                                                           // lineNo
    "getUSVForEmpty",                                              // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo ng_emlrtRSI{
    93,                                                            // lineNo
    "callLAPACK",                                                  // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo og_emlrtRSI{
    89,                                                            // lineNo
    "callLAPACK",                                                  // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo pg_emlrtRSI{
    81,                                                            // lineNo
    "callLAPACK",                                                  // fcnName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo
    qg_emlrtRSI{
        209,      // lineNo
        "xgesdd", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesdd.m" // pathName
    };

static emlrtRSInfo
    rg_emlrtRSI{
        31,       // lineNo
        "xgesvd", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pathName
    };

static emlrtRSInfo
    sg_emlrtRSI{
        197,            // lineNo
        "ceval_xgesvd", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pathName
    };

static emlrtRSInfo
    tg_emlrtRSI{
        195,            // lineNo
        "ceval_xgesvd", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pathName
    };

static emlrtRSInfo
    ug_emlrtRSI{
        212,    // lineNo
        "getv", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pathName
    };

static emlrtRSInfo
    vg_emlrtRSI{
        213,    // lineNo
        "getv", // fcnName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pathName
    };

static emlrtRTEInfo o_emlrtRTEI{
    47,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck."
    "m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    44,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck."
    "m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    111,                                                           // lineNo
    5,                                                             // colNo
    "callLAPACK",                                                  // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo hf_emlrtRTEI{
    57,                                                            // lineNo
    33,                                                            // colNo
    "svd",                                                         // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo if_emlrtRTEI{
    81,                                                            // lineNo
    63,                                                            // colNo
    "svd",                                                         // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo
    jf_emlrtRTEI{
        45,       // lineNo
        24,       // colNo
        "xgesdd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesdd.m" // pName
    };

static emlrtRTEInfo
    kf_emlrtRTEI{
        47,       // lineNo
        25,       // colNo
        "xgesdd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesdd.m" // pName
    };

static emlrtRTEInfo
    lf_emlrtRTEI{
        57,       // lineNo
        20,       // colNo
        "xgesdd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesdd.m" // pName
    };

static emlrtRTEInfo
    mf_emlrtRTEI{
        211,      // lineNo
        24,       // colNo
        "xgesvd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pName
    };

static emlrtRTEInfo
    nf_emlrtRTEI{
        75,       // lineNo
        24,       // colNo
        "xgesvd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pName
    };

static emlrtRTEInfo
    of_emlrtRTEI{
        82,       // lineNo
        25,       // colNo
        "xgesvd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pName
    };

static emlrtRTEInfo
    pf_emlrtRTEI{
        90,       // lineNo
        20,       // colNo
        "xgesvd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pName
    };

static emlrtRTEInfo
    qf_emlrtRTEI{
        123,      // lineNo
        9,        // colNo
        "xgesvd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pName
    };

static emlrtRTEInfo
    rf_emlrtRTEI{
        121,      // lineNo
        33,       // colNo
        "xgesvd", // fName
        "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "lapack\\xgesvd.m" // pName
    };

static emlrtRTEInfo sf_emlrtRTEI{
    162,                                                           // lineNo
    1,                                                             // colNo
    "svd",                                                         // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo tf_emlrtRTEI{
    169,                                                           // lineNo
    9,                                                             // colNo
    "svd",                                                         // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo uf_emlrtRTEI{
    23,                                                            // lineNo
    12,                                                            // colNo
    "svd",                                                         // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void svd(const emlrtStack &sp, const ::coder::array<real_T, 2U> &A,
         ::coder::array<real_T, 2U> &U, ::coder::array<real_T, 1U> &s,
         ::coder::array<real_T, 2U> &V)
{
  static const char_T b_fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                  '_', 'd', 'g', 'e', 's', 'v', 'd'};
  static const char_T fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 's', 'd', 'd'};
  array<real_T, 2U> Vt;
  array<real_T, 2U> b_A;
  array<real_T, 2U> c_A;
  array<real_T, 1U> superb;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    int32_T m;
    int32_T minmn;
    int32_T n;
    st.site = &kg_emlrtRSI;
    n = A.size(0);
    minmn = A.size(1);
    m = muIntScalarMin_sint32(n, minmn);
    U.set_size(&sf_emlrtRTEI, &st, A.size(0), m);
    minmn = A.size(0) * m;
    for (int32_T info{0}; info < minmn; info++) {
      U[info] = 0.0;
    }
    minmn = muIntScalarMin_sint32(n, m);
    b_st.site = &mg_emlrtRSI;
    if (minmn > 2147483646) {
      c_st.site = &ye_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (int32_T i{0}; i < minmn; i++) {
      U[i + U.size(0) * i] = 1.0;
    }
    V.set_size(&tf_emlrtRTEI, &st, A.size(1), m);
    minmn = A.size(1) * m;
    for (int32_T info{0}; info < minmn; info++) {
      V[info] = 0.0;
    }
    s.set_size(&uf_emlrtRTEI, &sp, 0);
  } else {
    ptrdiff_t info_t;
    int32_T info;
    int32_T m;
    int32_T minmn;
    int32_T n;
    st.site = &lg_emlrtRSI;
    b_A.set_size(&hf_emlrtRTEI, &st, A.size(0), A.size(1));
    minmn = A.size(0) * A.size(1);
    for (info = 0; info < minmn; info++) {
      b_A[info] = A[info];
    }
    m = A.size(0);
    n = A.size(1);
    b_st.site = &pg_emlrtRSI;
    c_A.set_size(&if_emlrtRTEI, &b_st, A.size(0), A.size(1));
    for (info = 0; info < minmn; info++) {
      c_A[info] = A[info];
    }
    minmn = muIntScalarMin_sint32(n, m);
    U.set_size(&jf_emlrtRTEI, &b_st, A.size(0), minmn);
    Vt.set_size(&kf_emlrtRTEI, &b_st, minmn, A.size(1));
    s.set_size(&lf_emlrtRTEI, &b_st, minmn);
    info_t = LAPACKE_dgesdd(
        102, 'S', (ptrdiff_t)A.size(0), (ptrdiff_t)A.size(1), &(c_A.data())[0],
        (ptrdiff_t)A.size(0), &(s.data())[0], &(U.data())[0],
        (ptrdiff_t)A.size(0), &(Vt.data())[0], (ptrdiff_t)minmn);
    c_st.site = &qg_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &p_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      14, &fname[0], 12, (int32_T)info_t);
      }
    }
    info = (int32_T)info_t;
    if ((int32_T)info_t > 0) {
      boolean_T overflow;
      b_st.site = &og_emlrtRSI;
      c_st.site = &rg_emlrtRSI;
      m = A.size(0);
      n = A.size(1);
      U.set_size(&nf_emlrtRTEI, &c_st, A.size(0), minmn);
      Vt.set_size(&of_emlrtRTEI, &c_st, minmn, A.size(1));
      s.set_size(&pf_emlrtRTEI, &c_st, minmn);
      if (minmn > 1) {
        superb.set_size(&rf_emlrtRTEI, &c_st, minmn - 1);
      } else {
        superb.set_size(&qf_emlrtRTEI, &c_st, 1);
      }
      info_t = LAPACKE_dgesvd(
          102, 'S', 'S', (ptrdiff_t)A.size(0), (ptrdiff_t)A.size(1),
          &(b_A.data())[0], (ptrdiff_t)A.size(0), &(s.data())[0],
          &(U.data())[0], (ptrdiff_t)A.size(0), &(Vt.data())[0],
          (ptrdiff_t)minmn, &(superb.data())[0]);
      d_st.site = &tg_emlrtRSI;
      minmn = muIntScalarMin_sint32(m, n);
      V.set_size(&mf_emlrtRTEI, &d_st, A.size(1), minmn);
      e_st.site = &ug_emlrtRSI;
      if (minmn > 2147483646) {
        f_st.site = &ye_emlrtRSI;
        check_forloop_overflow_error(f_st);
      }
      overflow = (A.size(1) > 2147483646);
      for (m = 0; m < minmn; m++) {
        e_st.site = &vg_emlrtRSI;
        if (overflow) {
          f_st.site = &ye_emlrtRSI;
          check_forloop_overflow_error(f_st);
        }
        for (int32_T i{0}; i < n; i++) {
          V[i + V.size(0) * m] = Vt[m + Vt.size(0) * i];
        }
      }
      d_st.site = &sg_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &p_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &o_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
              (int32_T)info_t);
        }
      }
      info = (int32_T)info_t;
    } else {
      boolean_T overflow;
      b_st.site = &ng_emlrtRSI;
      minmn = muIntScalarMin_sint32(m, n);
      V.set_size(&mf_emlrtRTEI, &b_st, A.size(1), minmn);
      c_st.site = &ug_emlrtRSI;
      if (minmn > 2147483646) {
        d_st.site = &ye_emlrtRSI;
        check_forloop_overflow_error(d_st);
      }
      overflow = (A.size(1) > 2147483646);
      for (m = 0; m < minmn; m++) {
        c_st.site = &vg_emlrtRSI;
        if (overflow) {
          d_st.site = &ye_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (int32_T i{0}; i < n; i++) {
          V[i + V.size(0) * m] = Vt[m + Vt.size(0) * i];
        }
      }
    }
    if (info > 0) {
      emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace coder

// End of code generation (svd.cpp)
