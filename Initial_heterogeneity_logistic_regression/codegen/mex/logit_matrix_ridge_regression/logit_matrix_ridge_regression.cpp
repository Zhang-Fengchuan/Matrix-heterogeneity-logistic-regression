//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// logit_matrix_ridge_regression.cpp
//
// Code generation for function 'logit_matrix_ridge_regression'
//

// Include files
#include "logit_matrix_ridge_regression.h"
#include "assertValidSizeArg.h"
#include "diag.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_mtimes_helper.h"
#include "exp.h"
#include "eye.h"
#include "indexShapeCheck.h"
#include "kron.h"
#include "linspace.h"
#include "log.h"
#include "logit_matrix_ridge_regression_data.h"
#include "mod.h"
#include "mtimes.h"
#include "norm.h"
#include "permute.h"
#include "pinv.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sum.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo emlrtRSI{ 14,       // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo b_emlrtRSI{ 15,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo c_emlrtRSI{ 16,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo d_emlrtRSI{ 63,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo e_emlrtRSI{ 64,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo f_emlrtRSI{ 65,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo g_emlrtRSI{ 66,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo h_emlrtRSI{ 67,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo i_emlrtRSI{ 73,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo j_emlrtRSI{ 84,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo k_emlrtRSI{ 93,     // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo l_emlrtRSI{ 100,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo m_emlrtRSI{ 101,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo n_emlrtRSI{ 102,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo o_emlrtRSI{ 103,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo p_emlrtRSI{ 104,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo q_emlrtRSI{ 107,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo r_emlrtRSI{ 146,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo s_emlrtRSI{ 147,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo t_emlrtRSI{ 148,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo u_emlrtRSI{ 149,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo v_emlrtRSI{ 150,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo w_emlrtRSI{ 152,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo x_emlrtRSI{ 153,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo y_emlrtRSI{ 154,    // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ab_emlrtRSI{ 159,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo bb_emlrtRSI{ 160,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo cb_emlrtRSI{ 161,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo db_emlrtRSI{ 162,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo eb_emlrtRSI{ 163,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo fb_emlrtRSI{ 165,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo gb_emlrtRSI{ 166,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo hb_emlrtRSI{ 167,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ib_emlrtRSI{ 172,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo jb_emlrtRSI{ 175,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo kb_emlrtRSI{ 176,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo lb_emlrtRSI{ 177,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo mb_emlrtRSI{ 178,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo nb_emlrtRSI{ 186,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ob_emlrtRSI{ 187,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo pb_emlrtRSI{ 188,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo qb_emlrtRSI{ 190,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo rb_emlrtRSI{ 204,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo sb_emlrtRSI{ 208,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo tb_emlrtRSI{ 209,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ub_emlrtRSI{ 210,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo vb_emlrtRSI{ 211,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo wb_emlrtRSI{ 212,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo xb_emlrtRSI{ 218,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo yb_emlrtRSI{ 229,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ac_emlrtRSI{ 238,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo bc_emlrtRSI{ 244,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo cc_emlrtRSI{ 245,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo dc_emlrtRSI{ 246,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ec_emlrtRSI{ 247,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo fc_emlrtRSI{ 248,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo gc_emlrtRSI{ 251,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo hc_emlrtRSI{ 290,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ic_emlrtRSI{ 291,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo jc_emlrtRSI{ 292,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo kc_emlrtRSI{ 293,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo lc_emlrtRSI{ 294,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo mc_emlrtRSI{ 296,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo nc_emlrtRSI{ 297,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo oc_emlrtRSI{ 298,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo pc_emlrtRSI{ 303,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo qc_emlrtRSI{ 304,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo rc_emlrtRSI{ 305,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo sc_emlrtRSI{ 306,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo tc_emlrtRSI{ 307,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo uc_emlrtRSI{ 309,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo vc_emlrtRSI{ 310,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo wc_emlrtRSI{ 311,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo xc_emlrtRSI{ 316,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo yc_emlrtRSI{ 319,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ad_emlrtRSI{ 320,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo bd_emlrtRSI{ 321,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo cd_emlrtRSI{ 322,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo dd_emlrtRSI{ 330,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ed_emlrtRSI{ 331,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo fd_emlrtRSI{ 332,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo gd_emlrtRSI{ 334,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo hd_emlrtRSI{ 340,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo id_emlrtRSI{ 349,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo jd_emlrtRSI{ 350,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo kd_emlrtRSI{ 351,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ld_emlrtRSI{ 352,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo md_emlrtRSI{ 353,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo nd_emlrtRSI{ 360,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo od_emlrtRSI{ 399,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo pd_emlrtRSI{ 400,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo qd_emlrtRSI{ 401,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo rd_emlrtRSI{ 402,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo sd_emlrtRSI{ 403,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo td_emlrtRSI{ 405,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ud_emlrtRSI{ 406,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo vd_emlrtRSI{ 408,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo wd_emlrtRSI{ 413,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo xd_emlrtRSI{ 414,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo yd_emlrtRSI{ 415,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ae_emlrtRSI{ 416,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo be_emlrtRSI{ 417,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ce_emlrtRSI{ 419,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo de_emlrtRSI{ 420,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ee_emlrtRSI{ 421,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo fe_emlrtRSI{ 426,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ge_emlrtRSI{ 429,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo he_emlrtRSI{ 430,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo ie_emlrtRSI{ 431,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo je_emlrtRSI{ 432,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo le_emlrtRSI{ 71,    // lineNo
  "power",                             // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\ops\\power.m"// pathName
};

static emlrtRSInfo nf_emlrtRSI{ 94,    // lineNo
  "eml_mtimes_helper",                 // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"// pathName
};

static emlrtRSInfo of_emlrtRSI{ 69,    // lineNo
  "eml_mtimes_helper",                 // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"// pathName
};

static emlrtRSInfo yf_emlrtRSI{ 19,    // lineNo
  "pinv",                              // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"// pathName
};

static emlrtRSInfo ag_emlrtRSI{ 21,    // lineNo
  "pinv",                              // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"// pathName
};

static emlrtRSInfo bh_emlrtRSI{ 17,    // lineNo
  "min",                               // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"// pathName
};

static emlrtRSInfo ch_emlrtRSI{ 40,    // lineNo
  "minOrMax",                          // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo dh_emlrtRSI{ 90,    // lineNo
  "minimum",                           // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo eh_emlrtRSI{ 173,   // lineNo
  "unaryMinOrMax",                     // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo fh_emlrtRSI{ 72,    // lineNo
  "vectorMinOrMaxInPlace",             // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"// pathName
};

static emlrtRSInfo gh_emlrtRSI{ 64,    // lineNo
  "vectorMinOrMaxInPlace",             // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"// pathName
};

static emlrtRSInfo hh_emlrtRSI{ 113,   // lineNo
  "findFirst",                         // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"// pathName
};

static emlrtRSInfo ih_emlrtRSI{ 130,   // lineNo
  "minOrMaxRealVectorKernel",          // fcnName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\vectorMinOrMaxInPlace.m"// pathName
};

static emlrtRTEInfo emlrtRTEI{ 134,    // lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pName
};

static emlrtRTEInfo d_emlrtRTEI{ 79,   // lineNo
  23,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"// pName
};

static emlrtECInfo emlrtECI{ 1,        // nDims
  431,                                 // lineNo
  28,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtBCInfo emlrtBCI{ -1,       // iFirst
  -1,                                  // iLast
  426,                                 // lineNo
  29,                                  // colNo
  "gamma_part",                        // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtECInfo b_emlrtECI{ 1,      // nDims
  425,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo c_emlrtECI{ 2,      // nDims
  419,                                 // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo d_emlrtECI{ 1,      // nDims
  419,                                 // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo e_emlrtECI{ 2,      // nDims
  419,                                 // lineNo
  130,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo f_emlrtECI{ 1,      // nDims
  419,                                 // lineNo
  130,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo g_emlrtECI{ 2,      // nDims
  419,                                 // lineNo
  71,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo h_emlrtECI{ 1,      // nDims
  419,                                 // lineNo
  71,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo i_emlrtECI{ 1,      // nDims
  417,                                 // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo j_emlrtECI{ 2,      // nDims
  417,                                 // lineNo
  70,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo k_emlrtECI{ 1,      // nDims
  417,                                 // lineNo
  70,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo l_emlrtECI{ 2,      // nDims
  417,                                 // lineNo
  71,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo m_emlrtECI{ 1,      // nDims
  417,                                 // lineNo
  71,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo n_emlrtECI{ 1,      // nDims
  412,                                 // lineNo
  17,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo o_emlrtECI{ 2,      // nDims
  405,                                 // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo p_emlrtECI{ 1,      // nDims
  405,                                 // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo q_emlrtECI{ 2,      // nDims
  405,                                 // lineNo
  118,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo r_emlrtECI{ 1,      // nDims
  405,                                 // lineNo
  118,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo s_emlrtECI{ 2,      // nDims
  405,                                 // lineNo
  59,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo t_emlrtECI{ 1,      // nDims
  405,                                 // lineNo
  59,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo u_emlrtECI{ 1,      // nDims
  403,                                 // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo v_emlrtECI{ 2,      // nDims
  403,                                 // lineNo
  58,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo w_emlrtECI{ 1,      // nDims
  403,                                 // lineNo
  58,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo x_emlrtECI{ 2,      // nDims
  403,                                 // lineNo
  59,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo y_emlrtECI{ 1,      // nDims
  403,                                 // lineNo
  59,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtDCInfo emlrtDCI{ 357,      // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI{ 357,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo c_emlrtDCI{ 356,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI{ 356,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtECInfo ab_emlrtECI{ 1,     // nDims
  352,                                 // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo bb_emlrtECI{ 1,     // nDims
  334,                                 // lineNo
  53,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo cb_emlrtECI{ 1,     // nDims
  321,                                 // lineNo
  36,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtBCInfo b_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  316,                                 // lineNo
  37,                                  // colNo
  "gamma_part",                        // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtECInfo db_emlrtECI{ 1,     // nDims
  315,                                 // lineNo
  26,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo eb_emlrtECI{ 2,     // nDims
  309,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo fb_emlrtECI{ 1,     // nDims
  309,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo gb_emlrtECI{ 2,     // nDims
  309,                                 // lineNo
  162,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo hb_emlrtECI{ 1,     // nDims
  309,                                 // lineNo
  162,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ib_emlrtECI{ 2,     // nDims
  309,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo jb_emlrtECI{ 1,     // nDims
  309,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo kb_emlrtECI{ 1,     // nDims
  307,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo lb_emlrtECI{ 2,     // nDims
  307,                                 // lineNo
  84,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo mb_emlrtECI{ 1,     // nDims
  307,                                 // lineNo
  84,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo nb_emlrtECI{ 2,     // nDims
  307,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ob_emlrtECI{ 1,     // nDims
  307,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo pb_emlrtECI{ 1,     // nDims
  302,                                 // lineNo
  25,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo qb_emlrtECI{ 2,     // nDims
  296,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo rb_emlrtECI{ 1,     // nDims
  296,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo sb_emlrtECI{ 2,     // nDims
  296,                                 // lineNo
  150,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo tb_emlrtECI{ 1,     // nDims
  296,                                 // lineNo
  150,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ub_emlrtECI{ 2,     // nDims
  296,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo vb_emlrtECI{ 1,     // nDims
  296,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo wb_emlrtECI{ 1,     // nDims
  294,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo xb_emlrtECI{ 2,     // nDims
  294,                                 // lineNo
  72,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo yb_emlrtECI{ 1,     // nDims
  294,                                 // lineNo
  72,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ac_emlrtECI{ 2,     // nDims
  294,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo bc_emlrtECI{ 1,     // nDims
  294,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo cc_emlrtECI{ 1,     // nDims
  247,                                 // lineNo
  32,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtBCInfo c_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  236,                                 // lineNo
  43,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo e_emlrtDCI{ 236,    // lineNo
  43,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  236,                                 // lineNo
  20,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI{ 236,    // lineNo
  20,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  238,                                 // lineNo
  53,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo g_emlrtDCI{ 238,    // lineNo
  53,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  238,                                 // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI{ 238,    // lineNo
  30,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  237,                                 // lineNo
  57,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI{ 237,    // lineNo
  57,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  237,                                 // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI{ 237,    // lineNo
  34,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  227,                                 // lineNo
  42,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  227,                                 // lineNo
  20,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI{ 227,    // lineNo
  20,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  229,                                 // lineNo
  52,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  229,                                 // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI{ 229,    // lineNo
  30,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  228,                                 // lineNo
  56,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo n_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  228,                                 // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI{ 228,    // lineNo
  34,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtRTEInfo f_emlrtRTEI{ 222,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtDCInfo n_emlrtDCI{ 215,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI{ 215,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI{ 214,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI{ 214,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo o_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  212,                                 // lineNo
  39,                                  // colNo
  "tuning_choice",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtECInfo dc_emlrtECI{ 1,     // nDims
  211,                                 // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ec_emlrtECI{ 1,     // nDims
  190,                                 // lineNo
  53,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo fc_emlrtECI{ 1,     // nDims
  177,                                 // lineNo
  36,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtBCInfo p_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  172,                                 // lineNo
  37,                                  // colNo
  "gamma_part",                        // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtECInfo gc_emlrtECI{ 1,     // nDims
  171,                                 // lineNo
  26,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo hc_emlrtECI{ 2,     // nDims
  165,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ic_emlrtECI{ 1,     // nDims
  165,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo jc_emlrtECI{ 2,     // nDims
  165,                                 // lineNo
  162,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo kc_emlrtECI{ 1,     // nDims
  165,                                 // lineNo
  162,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo lc_emlrtECI{ 2,     // nDims
  165,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo mc_emlrtECI{ 1,     // nDims
  165,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo nc_emlrtECI{ 1,     // nDims
  163,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo oc_emlrtECI{ 2,     // nDims
  163,                                 // lineNo
  84,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo pc_emlrtECI{ 1,     // nDims
  163,                                 // lineNo
  84,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo qc_emlrtECI{ 2,     // nDims
  163,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo rc_emlrtECI{ 1,     // nDims
  163,                                 // lineNo
  85,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo sc_emlrtECI{ 1,     // nDims
  158,                                 // lineNo
  25,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo tc_emlrtECI{ 2,     // nDims
  152,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo uc_emlrtECI{ 1,     // nDims
  152,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo vc_emlrtECI{ 2,     // nDims
  152,                                 // lineNo
  150,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo wc_emlrtECI{ 1,     // nDims
  152,                                 // lineNo
  150,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo xc_emlrtECI{ 2,     // nDims
  152,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo yc_emlrtECI{ 1,     // nDims
  152,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ad_emlrtECI{ 1,     // nDims
  150,                                 // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo bd_emlrtECI{ 2,     // nDims
  150,                                 // lineNo
  72,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo cd_emlrtECI{ 1,     // nDims
  150,                                 // lineNo
  72,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo dd_emlrtECI{ 2,     // nDims
  150,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo ed_emlrtECI{ 1,     // nDims
  150,                                 // lineNo
  73,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtECInfo fd_emlrtECI{ 1,     // nDims
  103,                                 // lineNo
  32,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtBCInfo q_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  91,                                  // lineNo
  43,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI{ 91,     // lineNo
  43,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo r_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  91,                                  // lineNo
  20,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI{ 91,     // lineNo
  20,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  53,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo t_emlrtDCI{ 93,     // lineNo
  53,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo t_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo u_emlrtDCI{ 93,     // lineNo
  30,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo u_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  57,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo v_emlrtDCI{ 92,     // lineNo
  57,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo v_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo w_emlrtDCI{ 92,     // lineNo
  34,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo w_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  82,                                  // lineNo
  42,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo x_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  82,                                  // lineNo
  20,                                  // colNo
  "index",                             // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo x_emlrtDCI{ 82,     // lineNo
  20,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo y_emlrtBCI{ -1,     // iFirst
  -1,                                  // iLast
  84,                                  // lineNo
  52,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ab_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  84,                                  // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo y_emlrtDCI{ 84,     // lineNo
  30,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo bb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  56,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI{ 83,    // lineNo
  34,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtRTEInfo g_emlrtRTEI{ 77,   // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtDCInfo bb_emlrtDCI{ 72,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI{ 70,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI{ 70,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI{ 69,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo fb_emlrtDCI{ 69,    // lineNo
  12,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtECInfo gd_emlrtECI{ 1,     // nDims
  66,                                  // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtBCInfo db_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  43,                                  // colNo
  "coefficients0",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  31,                                  // colNo
  "coefficients0",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI{ 50,    // lineNo
  31,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo fb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  31,                                  // colNo
  "coefficients0",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI{ 49,    // lineNo
  31,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo gb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  29,                                  // colNo
  "coefficients0",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo h_emlrtRTEI{ 41,   // lineNo
  9,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtDCInfo ib_emlrtDCI{ 40,    // lineNo
  19,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo jb_emlrtDCI{ 40,    // lineNo
  19,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo hb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  12,                                  // colNo
  "gamma0",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ib_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  45,                                  // lineNo
  20,                                  // colNo
  "pai_gamma",                         // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kb_emlrtDCI{ 45,    // lineNo
  20,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  45,                                  // lineNo
  70,                                  // colNo
  "pai_gamma",                         // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  43,                                  // lineNo
  20,                                  // colNo
  "pai_gamma",                         // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo lb_emlrtDCI{ 43,    // lineNo
  20,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo lb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  43,                                  // lineNo
  72,                                  // colNo
  "pai_gamma",                         // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  220,                                 // lineNo
  35,                                  // colNo
  "tuning_choice",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo mb_emlrtDCI{ 90,    // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo nb_emlrtDCI{ 90,    // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ob_emlrtDCI{ 81,    // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo pb_emlrtDCI{ 81,    // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo qb_emlrtDCI{ 235,   // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo rb_emlrtDCI{ 235,   // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo sb_emlrtDCI{ 226,   // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo tb_emlrtDCI{ 226,   // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo nb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  341,                                 // lineNo
  29,                                  // colNo
  "tuning_choice",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ob_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  85,                                  // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  230,                                 // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  86,                                  // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  231,                                 // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  239,                                 // lineNo
  34,                                  // colNo
  "x_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ub_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  240,                                 // lineNo
  30,                                  // colNo
  "y_part",                            // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ub_emlrtDCI{ 403,   // lineNo
  121,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo vb_emlrtDCI{ 403,   // lineNo
  121,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo wb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  334,                                 // lineNo
  44,                                  // colNo
  "tuning_matrix",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  334,                                 // lineNo
  23,                                  // colNo
  "tuning_matrix",                     // aName
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo wb_emlrtDCI{ 150,   // lineNo
  148,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo xb_emlrtDCI{ 150,   // lineNo
  148,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo yb_emlrtDCI{ 294,   // lineNo
  148,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ac_emlrtDCI{ 294,   // lineNo
  148,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo bc_emlrtDCI{ 417,   // lineNo
  133,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cc_emlrtDCI{ 307,   // lineNo
  160,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo dc_emlrtDCI{ 163,   // lineNo
  160,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m",// pName
  1                                    // checkKind
};

static emlrtRTEInfo v_emlrtRTEI{ 31,   // lineNo
  30,                                  // colNo
  "unsafeSxfun",                       // fName
  "D:\\MATLAB2023A\\toolbox\\eml\\eml\\+coder\\+internal\\unsafeSxfun.m"// pName
};

static emlrtRTEInfo w_emlrtRTEI{ 17,   // lineNo
  5,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo x_emlrtRTEI{ 40,   // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo y_emlrtRTEI{ 48,   // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ab_emlrtRTEI{ 48,  // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo bb_emlrtRTEI{ 49,  // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo cb_emlrtRTEI{ 50,  // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo db_emlrtRTEI{ 51,  // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo eb_emlrtRTEI{ 52,  // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo fb_emlrtRTEI{ 205, // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo gb_emlrtRTEI{ 208, // lineNo
  36,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo hb_emlrtRTEI{ 211, // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ib_emlrtRTEI{ 235, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo jb_emlrtRTEI{ 237, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo kb_emlrtRTEI{ 238, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo lb_emlrtRTEI{ 2,   // lineNo
  44,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo mb_emlrtRTEI{ 239, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo nb_emlrtRTEI{ 240, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ob_emlrtRTEI{ 226, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo pb_emlrtRTEI{ 228, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo qb_emlrtRTEI{ 229, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo rb_emlrtRTEI{ 230, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo sb_emlrtRTEI{ 231, // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo tb_emlrtRTEI{ 242, // lineNo
  9,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ub_emlrtRTEI{ 243, // lineNo
  9,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo vb_emlrtRTEI{ 247, // lineNo
  32,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo wb_emlrtRTEI{ 330, // lineNo
  49,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo xb_emlrtRTEI{ 290, // lineNo
  55,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo yb_emlrtRTEI{ 294, // lineNo
  74,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ac_emlrtRTEI{ 294, // lineNo
  23,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo bc_emlrtRTEI{ 294, // lineNo
  148,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo cc_emlrtRTEI{ 295, // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo dc_emlrtRTEI{ 296, // lineNo
  210,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ec_emlrtRTEI{ 296, // lineNo
  23,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo fc_emlrtRTEI{ 19,  // lineNo
  22,                                  // colNo
  "pinv",                              // fName
  "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"// pName
};

static emlrtRTEInfo gc_emlrtRTEI{ 298, // lineNo
  28,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo hc_emlrtRTEI{ 303, // lineNo
  55,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ic_emlrtRTEI{ 307, // lineNo
  86,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo jc_emlrtRTEI{ 307, // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo kc_emlrtRTEI{ 307, // lineNo
  160,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo lc_emlrtRTEI{ 308, // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo mc_emlrtRTEI{ 309, // lineNo
  223,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo nc_emlrtRTEI{ 309, // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo oc_emlrtRTEI{ 311, // lineNo
  28,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo pc_emlrtRTEI{ 319, // lineNo
  55,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo qc_emlrtRTEI{ 321, // lineNo
  36,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo rc_emlrtRTEI{ 347, // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo sc_emlrtRTEI{ 348, // lineNo
  1,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo tc_emlrtRTEI{ 352, // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo uc_emlrtRTEI{ 399, // lineNo
  40,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo vc_emlrtRTEI{ 403, // lineNo
  60,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo wc_emlrtRTEI{ 403, // lineNo
  15,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo xc_emlrtRTEI{ 403, // lineNo
  121,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo yc_emlrtRTEI{ 404, // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ad_emlrtRTEI{ 405, // lineNo
  166,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo bd_emlrtRTEI{ 405, // lineNo
  15,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo cd_emlrtRTEI{ 408, // lineNo
  14,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo dd_emlrtRTEI{ 413, // lineNo
  40,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ed_emlrtRTEI{ 417, // lineNo
  72,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo fd_emlrtRTEI{ 417, // lineNo
  16,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo gd_emlrtRTEI{ 417, // lineNo
  133,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo hd_emlrtRTEI{ 418, // lineNo
  10,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo id_emlrtRTEI{ 419, // lineNo
  179,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo jd_emlrtRTEI{ 419, // lineNo
  16,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo kd_emlrtRTEI{ 421, // lineNo
  14,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ld_emlrtRTEI{ 429, // lineNo
  40,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo md_emlrtRTEI{ 431, // lineNo
  28,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo nd_emlrtRTEI{ 63,  // lineNo
  36,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo od_emlrtRTEI{ 66,  // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo pd_emlrtRTEI{ 90,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo qd_emlrtRTEI{ 92,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo rd_emlrtRTEI{ 93,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo sd_emlrtRTEI{ 94,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo td_emlrtRTEI{ 95,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ud_emlrtRTEI{ 81,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo vd_emlrtRTEI{ 83,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo wd_emlrtRTEI{ 84,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo xd_emlrtRTEI{ 85,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo yd_emlrtRTEI{ 86,  // lineNo
  13,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ae_emlrtRTEI{ 97,  // lineNo
  9,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo be_emlrtRTEI{ 98,  // lineNo
  9,                                   // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ce_emlrtRTEI{ 103, // lineNo
  32,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo de_emlrtRTEI{ 186, // lineNo
  49,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ee_emlrtRTEI{ 146, // lineNo
  55,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo fe_emlrtRTEI{ 150, // lineNo
  74,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ge_emlrtRTEI{ 150, // lineNo
  23,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo he_emlrtRTEI{ 150, // lineNo
  148,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ie_emlrtRTEI{ 151, // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo je_emlrtRTEI{ 152, // lineNo
  210,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ke_emlrtRTEI{ 152, // lineNo
  23,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo le_emlrtRTEI{ 154, // lineNo
  28,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo me_emlrtRTEI{ 159, // lineNo
  55,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ne_emlrtRTEI{ 163, // lineNo
  86,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo oe_emlrtRTEI{ 163, // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo pe_emlrtRTEI{ 163, // lineNo
  160,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo qe_emlrtRTEI{ 164, // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo re_emlrtRTEI{ 165, // lineNo
  223,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo se_emlrtRTEI{ 165, // lineNo
  24,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo te_emlrtRTEI{ 167, // lineNo
  28,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ue_emlrtRTEI{ 175, // lineNo
  55,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ve_emlrtRTEI{ 177, // lineNo
  36,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo xf_emlrtRTEI{ 171, // lineNo
  26,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo yf_emlrtRTEI{ 165, // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo ag_emlrtRTEI{ 165, // lineNo
  162,                                 // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo bg_emlrtRTEI{ 163, // lineNo
  18,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo cg_emlrtRTEI{ 163, // lineNo
  84,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo dg_emlrtRTEI{ 190, // lineNo
  53,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRTEInfo eg_emlrtRTEI{ 334, // lineNo
  53,                                  // colNo
  "logit_matrix_ridge_regression",     // fName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pName
};

static emlrtRSInfo jh_emlrtRSI{ 302,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo kh_emlrtRSI{ 315,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo lh_emlrtRSI{ 412,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo mh_emlrtRSI{ 425,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo nh_emlrtRSI{ 158,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

static emlrtRSInfo oh_emlrtRSI{ 171,   // lineNo
  "logit_matrix_ridge_regression",     // fcnName
  "D:\\MATLAB_Document2\\ADMM_BCD_new\\\xe5\x88\x9d\xe5\x80\xbc\xe9\x80\xbb\xe8\xbe\x91\\logit_matrix_ridge_regression.m"// pathName
};

// Function Declarations
static void b_times(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                    coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U>
                    &in3);
static real_T binary_expand_op(const emlrtStack &sp, const emlrtRSInfo in1,
  const coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U> &in3,
  real_T in4, real_T in5, real_T in6);
static void binary_expand_op(const emlrtStack &sp, real_T in1[3], int32_T in2,
  const emlrtRSInfo in3, const coder::array<real_T, 1U> &in4, const coder::array<
  real_T, 1U> &in5);
static void binary_expand_op(const emlrtStack &sp, const emlrtRSInfo in1, const
  coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U> &in3);
static void binary_expand_op(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
  int32_T in2, const emlrtRSInfo in3, const coder::array<real_T, 1U> &in4, const
  coder::array<real_T, 1U> &in5);
static void minus(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                  coder::array<real_T, 1U> &in2);
static void minus(const emlrtStack &sp, coder::array<real_T, 2U> &in1, const
                  coder::array<real_T, 2U> &in2);
static void plus(const emlrtStack &sp, coder::array<real_T, 2U> &in1, const
                 coder::array<real_T, 2U> &in2);
static void plus(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                 coder::array<real_T, 1U> &in2);
static void times(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                  coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U>
                  &in3);
static void times(const emlrtStack &sp, coder::array<real_T, 2U> &in1, const
                  coder::array<real_T, 2U> &in2);
static void times(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                  coder::array<real_T, 1U> &in2);

// Function Definitions
static void b_times(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                    coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U>
                    &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }

  in1.set_size(&od_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
  }
}

static real_T binary_expand_op(const emlrtStack &sp, const emlrtRSInfo in1,
  const coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U> &in3,
  real_T in4, real_T in5, real_T in6)
{
  coder::array<real_T, 1U> b_in2;
  emlrtStack st;
  real_T out1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }

  b_in2.set_size(&ve_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
  }

  st.site = const_cast<emlrtRSInfo *>(&in1);
  out1 = -coder::sum(st, b_in2) + 0.5 * in4 * (in5 * in5 + in6 * in6);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return out1;
}

static void binary_expand_op(const emlrtStack &sp, real_T in1[3], int32_T in2,
  const emlrtRSInfo in3, const coder::array<real_T, 1U> &in4, const coder::array<
  real_T, 1U> &in5)
{
  coder::array<real_T, 1U> b_in4;
  emlrtStack st;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }

  b_in4.set_size(&dg_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in4.size(0) != 1);
  stride_1_0 = (in5.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in4[i] = in4[i * stride_0_0] - in5[i * stride_1_0];
  }

  st.site = const_cast<emlrtRSInfo *>(&in3);
  in1[in2] -= coder::sum(st, b_in4);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void binary_expand_op(const emlrtStack &sp, const emlrtRSInfo in1, const
  coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U> &in3)
{
  coder::array<real_T, 1U> b_in2;
  emlrtStack st;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }

  b_in2.set_size(&od_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
  }

  st.site = const_cast<emlrtRSInfo *>(&in1);
  coder::sum(st, b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void binary_expand_op(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
  int32_T in2, const emlrtRSInfo in3, const coder::array<real_T, 1U> &in4, const
  coder::array<real_T, 1U> &in5)
{
  coder::array<real_T, 1U> b_in4;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }

  b_in4.set_size(&eg_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in4.size(0) != 1);
  stride_1_0 = (in5.size(0) != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in4[i] = in4[i * stride_0_0] - in5[i * stride_1_0];
  }

  i = in1.size(0);
  if ((in2 + 1 < 1) || (in2 + 1 > i)) {
    emlrtDynamicBoundsCheckR2012b(in2 + 1, 1, i, &wb_emlrtBCI, (emlrtConstCTX)&
      sp);
  }

  i = in1.size(0);
  if ((in2 + 1 < 1) || (in2 + 1 > i)) {
    emlrtDynamicBoundsCheckR2012b(in2 + 1, 1, i, &xb_emlrtBCI, (emlrtConstCTX)&
      sp);
  }

  st.site = const_cast<emlrtRSInfo *>(&in3);
  in1[in2] = in1[in2] - coder::sum(st, b_in4);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void minus(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                  coder::array<real_T, 1U> &in2)
{
  coder::array<real_T, 1U> b_in1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  b_in1.set_size(&xf_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] - in2[i * stride_1_0];
  }

  in1.set_size(&xf_emlrtRTEI, &sp, b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void minus(const emlrtStack &sp, coder::array<real_T, 2U> &in1, const
                  coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  if (in2.size(1) == 1) {
    b_loop_ub = in1.size(1);
  } else {
    b_loop_ub = in2.size(1);
  }

  b_in1.set_size(&cg_emlrtRTEI, &sp, loop_ub, b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = in1[i1 * stride_0_0 + in1.size(0) *
        aux_0_1] - in2[i1 * stride_1_0 + in2.size(0) * aux_1_1];
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  in1.set_size(&cg_emlrtRTEI, &sp, b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void plus(const emlrtStack &sp, coder::array<real_T, 2U> &in1, const
                 coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  if (in2.size(1) == 1) {
    b_loop_ub = in1.size(1);
  } else {
    b_loop_ub = in2.size(1);
  }

  b_in1.set_size(&yf_emlrtRTEI, &sp, loop_ub, b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = in1[i1 * stride_0_0 + in1.size(0) *
        aux_0_1] + in2[i1 * stride_1_0 + in2.size(0) * aux_1_1];
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  in1.set_size(&yf_emlrtRTEI, &sp, b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void plus(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                 coder::array<real_T, 1U> &in2)
{
  coder::array<real_T, 1U> b_in1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  b_in1.set_size(&bg_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] + in2[i * stride_1_0];
  }

  in1.set_size(&bg_emlrtRTEI, &sp, b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void times(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                  coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U>
                  &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }

  in1.set_size(&ve_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
  }
}

static void times(const emlrtStack &sp, coder::array<real_T, 2U> &in1, const
                  coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  if (in2.size(1) == 1) {
    b_loop_ub = in1.size(1);
  } else {
    b_loop_ub = in2.size(1);
  }

  b_in1.set_size(&ag_emlrtRTEI, &sp, loop_ub, b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = in1[i1 * stride_0_0 + in1.size(0) *
        aux_0_1] * in2[i1 * stride_1_0 + in2.size(0) * aux_1_1];
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  in1.set_size(&ag_emlrtRTEI, &sp, b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void times(const emlrtStack &sp, coder::array<real_T, 1U> &in1, const
                  coder::array<real_T, 1U> &in2)
{
  coder::array<real_T, 1U> b_in1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  b_in1.set_size(&dg_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] * in2[i * stride_1_0];
  }

  in1.set_size(&dg_emlrtRTEI, &sp, b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void logit_matrix_ridge_regression(const emlrtStack *sp, const coder::array<
  real_T, 3U> &x, const coder::array<real_T, 1U> &y, real_T n, real_T row_size,
  real_T col_size, real_T cv_number, coder::array<real_T, 1U> &coefficients0,
  real_T tuning_start, real_T tuning_end, real_T tuning_number, real_T
  eps_initial, real_T iter_max_initial_in, real_T if_fix, coder::array<real_T,
  1U> &beta_part, coder::array<real_T, 1U> &gamma_part, real_T *lambda_best,
  real_T *iter_initial_in, real_T *diff_loglikelihood)
{
  __m128d r;
  __m128d r3;
  coder::array<real_T, 3U> b_x_train;
  coder::array<real_T, 3U> r2;
  coder::array<real_T, 3U> x_test;
  coder::array<real_T, 2U> b;
  coder::array<real_T, 2U> b_a;
  coder::array<real_T, 2U> b_beta_part;
  coder::array<real_T, 2U> b_pai_gamma;
  coder::array<real_T, 2U> b_y;
  coder::array<real_T, 2U> beta_likelihood;
  coder::array<real_T, 2U> eta_likelihood_mat_train;
  coder::array<real_T, 2U> pai_gamma;
  coder::array<real_T, 2U> r1;
  coder::array<real_T, 2U> r8;
  coder::array<real_T, 2U> tuning_choice;
  coder::array<real_T, 2U> x_train;
  coder::array<real_T, 1U> C2;
  coder::array<real_T, 1U> beta0;
  coder::array<real_T, 1U> beta0_part;
  coder::array<real_T, 1U> gamma0;
  coder::array<real_T, 1U> gamma0_part;
  coder::array<real_T, 1U> ph_emlrtRSI;
  coder::array<real_T, 1U> qh_emlrtRSI;
  coder::array<real_T, 1U> rh_emlrtRSI;
  coder::array<real_T, 1U> sh_emlrtRSI;
  coder::array<real_T, 1U> th_emlrtRSI;
  coder::array<real_T, 1U> tuning_matrix;
  coder::array<real_T, 1U> uh_emlrtRSI;
  coder::array<real_T, 1U> y_test;
  coder::array<real_T, 1U> y_train;
  coder::array<int32_T, 1U> r4;
  coder::array<int32_T, 1U> r5;
  coder::array<int32_T, 1U> r6;
  coder::array<int32_T, 1U> r7;
  coder::array<boolean_T, 1U> b_index;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T a;
  real_T b_varargin_1;
  real_T batch_size;
  real_T d_varargin_1;
  real_T guiyi;
  real_T lambda_tuning;
  real_T log_likelihood0;
  real_T n_test;
  real_T n_train;
  real_T varargin_1;
  real_T *b_x;
  int32_T c_varargin_1[2];
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T nx;
  int32_T panduan;
  int32_T varargin_1_tmp;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  boolean_T exitg1;
  boolean_T out;
  st.prev = sp;
  st.tls = sp->tls;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);

  //  [beta_part, gamma_part, lambda_best,...
  //  iter_initial_in, diff_loglikelihood] = logit_matrix_ridge_regression(x_part, y_part, n_part,...
  //                                            row_size, col_size, [], [], [], [], [], [], [])
  if (coefficients0.size(0) == 0) {
    st.site = &emlrtRSI;
    coder::b_rand(st, row_size, beta0);
    st.site = &b_emlrtRSI;
    if (col_size < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    guiyi = 1.0 / muDoubleScalarSqrt(col_size);
    st.site = &b_emlrtRSI;
    coder::b_rand(st, col_size, gamma0);
    loop_ub = gamma0.size(0);
    nx = (gamma0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&gamma0[i]);
      _mm_storeu_pd(&gamma0[i], _mm_mul_pd(_mm_set1_pd(guiyi), r));
    }

    for (i = nx; i < loop_ub; i++) {
      gamma0[i] = guiyi * gamma0[i];
    }

    if (gamma0.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gamma0.size(0), &hb_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &c_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    C2.set_size(&v_emlrtRTEI, sp, gamma0.size(0));
    loop_ub = gamma0.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargin_1 = gamma0[i];
      C2[i] = varargin_1 * varargin_1;
    }

    st.site = &c_emlrtRSI;
    gamma0[0] = 1.0 - coder::sum(st, C2);
    st.site = &c_emlrtRSI;
    b_x = &(gamma0.data())[0];
    if (*b_x < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    *b_x = muDoubleScalarSqrt(*b_x);
    coefficients0.set_size(&w_emlrtRTEI, sp, beta0.size(0) + gamma0.size(0));
    loop_ub = beta0.size(0);
    for (i = 0; i < loop_ub; i++) {
      coefficients0[i] = beta0[i];
    }

    loop_ub = gamma0.size(0);
    for (i = 0; i < loop_ub; i++) {
      coefficients0[i + beta0.size(0)] = gamma0[i];
    }
  }

  if (tuning_end == 0.0) {
    panduan = 0;
    tuning_end = 2.0 * tuning_start;
  } else {
    panduan = 1;
  }

  varargin_1 = row_size * col_size;
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &jb_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (varargin_1 != static_cast<int32_T>(muDoubleScalarFloor(varargin_1))) {
    emlrtIntegerCheckR2012b(varargin_1, &ib_emlrtDCI, (emlrtConstCTX)sp);
  }

  i = static_cast<int32_T>(varargin_1);
  pai_gamma.set_size(&x_emlrtRTEI, sp, i, i);
  loop_ub = static_cast<int32_T>(varargin_1) * static_cast<int32_T>(varargin_1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    pai_gamma[i1] = 0.0;
  }

  emlrtForLoopVectorCheckR2021a(1.0, 1.0, varargin_1, mxDOUBLE_CLASS,
    static_cast<int32_T>(varargin_1), &h_emlrtRTEI, (emlrtConstCTX)sp);
  for (nx = 0; nx < i; nx++) {
    a = coder::b_mod(static_cast<real_T>(nx) + 1.0, row_size);
    if (a != 0.0) {
      a = (muDoubleScalarFloor((static_cast<real_T>(nx) + 1.0) / row_size) + 1.0)
        + (a - 1.0) * col_size;
      if (a != static_cast<int32_T>(muDoubleScalarFloor(a))) {
        emlrtIntegerCheckR2012b(a, &lb_emlrtDCI, (emlrtConstCTX)sp);
      }

      if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
           pai_gamma.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1, pai_gamma.size
          (0), &kb_emlrtBCI, (emlrtConstCTX)sp);
      }

      if ((static_cast<int32_T>(static_cast<uint32_T>(nx) + 1U) < 1) || (
           static_cast<int32_T>(static_cast<uint32_T>(nx) + 1U) > pai_gamma.size
           (1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<uint32_T>
          (nx) + 1U), 1, pai_gamma.size(1), &lb_emlrtBCI, (emlrtConstCTX)sp);
      }

      pai_gamma[(static_cast<int32_T>(a) + pai_gamma.size(0) * nx) - 1] = 1.0;
    } else {
      a = muDoubleScalarFloor((static_cast<real_T>(nx) + 1.0) / row_size) +
        coder::b_mod((static_cast<real_T>(nx) + 1.0) - 1.0, row_size) * col_size;
      if (a != static_cast<int32_T>(muDoubleScalarFloor(a))) {
        emlrtIntegerCheckR2012b(a, &kb_emlrtDCI, (emlrtConstCTX)sp);
      }

      if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
           pai_gamma.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1, pai_gamma.size
          (0), &ib_emlrtBCI, (emlrtConstCTX)sp);
      }

      if ((static_cast<int32_T>(static_cast<uint32_T>(nx) + 1U) < 1) || (
           static_cast<int32_T>(static_cast<uint32_T>(nx) + 1U) > pai_gamma.size
           (1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(static_cast<uint32_T>
          (nx) + 1U), 1, pai_gamma.size(1), &jb_emlrtBCI, (emlrtConstCTX)sp);
      }

      pai_gamma[(static_cast<int32_T>(a) + pai_gamma.size(0) * nx) - 1] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  b_pai_gamma.set_size(&y_emlrtRTEI, sp, pai_gamma.size(1), pai_gamma.size(0));
  loop_ub = pai_gamma.size(0);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = pai_gamma.size(1);
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      b_pai_gamma[i2 + b_pai_gamma.size(0) * i1] = pai_gamma[i1 + pai_gamma.size
        (0) * i2];
    }
  }

  pai_gamma.set_size(&ab_emlrtRTEI, sp, b_pai_gamma.size(0), b_pai_gamma.size(1));
  loop_ub = b_pai_gamma.size(0) * b_pai_gamma.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    pai_gamma[i1] = b_pai_gamma[i1];
  }

  if (row_size < 1.0) {
    loop_ub = 0;
  } else {
    if (coefficients0.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, coefficients0.size(0), &gb_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (row_size != static_cast<int32_T>(muDoubleScalarFloor(row_size))) {
      emlrtIntegerCheckR2012b(row_size, &hb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((static_cast<int32_T>(row_size) < 1) || (static_cast<int32_T>(row_size) >
         coefficients0.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(row_size), 1,
        coefficients0.size(0), &fb_emlrtBCI, (emlrtConstCTX)sp);
    }

    loop_ub = static_cast<int32_T>(row_size);
  }

  beta0_part.set_size(&bb_emlrtRTEI, sp, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    beta0_part[i1] = coefficients0[i1];
  }

  if (row_size + 1.0 > coefficients0.size(0)) {
    i1 = 0;
    i2 = 0;
  } else {
    if (row_size + 1.0 != static_cast<int32_T>(muDoubleScalarFloor(row_size +
          1.0))) {
      emlrtIntegerCheckR2012b(row_size + 1.0, &gb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if ((static_cast<int32_T>(row_size + 1.0) < 1) || (static_cast<int32_T>
         (row_size + 1.0) > coefficients0.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(row_size + 1.0), 1,
        coefficients0.size(0), &eb_emlrtBCI, (emlrtConstCTX)sp);
    }

    i1 = static_cast<int32_T>(row_size + 1.0) - 1;
    if (coefficients0.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(coefficients0.size(0), 1, coefficients0.size
        (0), &db_emlrtBCI, (emlrtConstCTX)sp);
    }

    i2 = coefficients0.size(0);
  }

  b_loop_ub = i2 - i1;
  gamma0_part.set_size(&cb_emlrtRTEI, sp, b_loop_ub);
  for (i2 = 0; i2 < b_loop_ub; i2++) {
    gamma0_part[i2] = coefficients0[i1 + i2];
  }

  beta_part.set_size(&db_emlrtRTEI, sp, loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    beta_part[i2] = coefficients0[i2];
  }

  gamma_part.set_size(&eb_emlrtRTEI, sp, b_loop_ub);
  for (i2 = 0; i2 < b_loop_ub; i2++) {
    gamma_part[i2] = coefficients0[i1 + i2];
  }

  if (panduan == 0) {
    b_varargin_1 = row_size * n;
    i3 = static_cast<int32_T>(muDoubleScalarFloor(col_size));
    batch_size = muDoubleScalarFloor(n / cv_number);
    i4 = static_cast<int32_T>(cv_number);
  }

  while (panduan == 0) {
    real_T b_tuning_choice[3];
    real_T b_tuning_matrix[3];
    tuning_end *= 2.0;
    coder::linspace(tuning_start, tuning_end, b_tuning_choice);
    b_tuning_matrix[0] = 0.0;
    b_tuning_matrix[1] = 0.0;
    b_tuning_matrix[2] = 0.0;
    st.site = &d_emlrtRSI;
    coder::eye(st, n, r1);
    b_beta_part.set_size(&nd_emlrtRTEI, sp, 1, beta_part.size(0));
    c_loop_ub = beta_part.size(0);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      b_beta_part[i2] = beta_part[i2];
    }

    st.site = &d_emlrtRSI;
    coder::kron(st, r1, b_beta_part, beta_likelihood);
    st.site = &e_emlrtRSI;
    coder::permute(st, x, r2);
    st.site = &e_emlrtRSI;
    nx = r2.size(0) * r2.size(1) * r2.size(2);
    b_st.site = &jf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, b_varargin_1);
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, col_size);
    maxdimlen = r2.size(0);
    if (r2.size(1) > r2.size(0)) {
      maxdimlen = r2.size(1);
    }

    if (r2.size(2) > maxdimlen) {
      maxdimlen = r2.size(2);
    }

    maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
    if (static_cast<int32_T>(b_varargin_1) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (static_cast<int32_T>(col_size) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    out = (static_cast<int32_T>(b_varargin_1) >= 0);
    if ((!out) || (static_cast<int32_T>(col_size) < 0)) {
      out = false;
    }

    if (!out) {
      emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (static_cast<int32_T>(b_varargin_1) * static_cast<int32_T>(col_size) !=
        nx) {
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    st.site = &f_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &f_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    if ((y.size(0) != beta0.size(0)) && ((y.size(0) != 1) && (beta0.size(0) != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(y.size(0), beta0.size(0), &gd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (y.size(0) == beta0.size(0)) {
      gamma0.set_size(&od_emlrtRTEI, sp, y.size(0));
      c_loop_ub = y.size(0);
      nx = (y.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&beta0[i2]);
        _mm_storeu_pd(&gamma0[i2], _mm_mul_pd(_mm_loadu_pd(&y[i2]), r));
      }

      for (i2 = nx; i2 < c_loop_ub; i2++) {
        gamma0[i2] = y[i2] * beta0[i2];
      }
    } else {
      st.site = &g_emlrtRSI;
      b_times(st, gamma0, y, beta0);
    }

    st.site = &g_emlrtRSI;
    coder::b_exp(st, beta0);
    c_loop_ub = beta0.size(0);
    nx = (beta0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i2 = 0; i2 <= vectorUB; i2 += 2) {
      r = _mm_loadu_pd(&beta0[i2]);
      _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
    }

    for (i2 = nx; i2 < c_loop_ub; i2++) {
      beta0[i2] = beta0[i2] + 1.0;
    }

    st.site = &g_emlrtRSI;
    coder::b_log(st, beta0);
    if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
         (beta0.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0), &gd_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (gamma0.size(0) == beta0.size(0)) {
      beta0.set_size(&od_emlrtRTEI, sp, gamma0.size(0));
      c_loop_ub = gamma0.size(0);
      nx = (gamma0.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&gamma0[i2]);
        r3 = _mm_loadu_pd(&beta0[i2]);
        _mm_storeu_pd(&beta0[i2], _mm_sub_pd(r, r3));
      }

      for (i2 = nx; i2 < c_loop_ub; i2++) {
        beta0[i2] = gamma0[i2] - beta0[i2];
      }

      st.site = &g_emlrtRSI;
      coder::sum(st, beta0);
    } else {
      st.site = &g_emlrtRSI;
      binary_expand_op(st, g_emlrtRSI, gamma0, beta0);
    }

    st.site = &h_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    st.site = &h_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    if (!(row_size >= 0.0)) {
      emlrtNonNegativeCheckR2012b(row_size, &fb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (row_size != static_cast<int32_T>(muDoubleScalarFloor(row_size))) {
      emlrtIntegerCheckR2012b(row_size, &eb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(col_size >= 0.0)) {
      emlrtNonNegativeCheckR2012b(col_size, &db_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (col_size != i3) {
      emlrtIntegerCheckR2012b(col_size, &cb_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (col_size != i3) {
      emlrtIntegerCheckR2012b(col_size, &bb_emlrtDCI, (emlrtConstCTX)sp);
    }

    st.site = &i_emlrtRSI;
    nx = x.size(0) * x.size(1) * x.size(2);
    b_st.site = &jf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, varargin_1);
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, n);
    maxdimlen = x.size(0);
    if (x.size(1) > x.size(0)) {
      maxdimlen = x.size(1);
    }

    if (x.size(2) > maxdimlen) {
      maxdimlen = x.size(2);
    }

    maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
    if (static_cast<int32_T>(varargin_1) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    out = (static_cast<int32_T>(varargin_1) >= 0);
    if ((!out) || (static_cast<int32_T>(n) < 0)) {
      out = false;
    }

    if (!out) {
      emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (static_cast<int32_T>(varargin_1) * static_cast<int32_T>(n) != nx) {
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    for (int32_T t{0}; t < 3; t++) {
      lambda_tuning = b_tuning_choice[t];
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, cv_number, mxDOUBLE_CLASS,
        static_cast<int32_T>(cv_number), &g_emlrtRTEI, (emlrtConstCTX)sp);
      for (int32_T u{0}; u < i4; u++) {
        if (static_cast<real_T>(u) + 1.0 == cv_number) {
          guiyi = ((static_cast<real_T>(u) + 1.0) - 1.0) * batch_size;
          n_test = n - guiyi;

          // n_batch为测试集样本数
          n_train = n - n_test;
          if (!(n >= 0.0)) {
            emlrtNonNegativeCheckR2012b(n, &pb_emlrtDCI, (emlrtConstCTX)sp);
          }

          a = static_cast<int32_T>(muDoubleScalarFloor(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &ob_emlrtDCI, (emlrtConstCTX)sp);
          }

          b_index.set_size(&ud_emlrtRTEI, sp, static_cast<int32_T>(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &ob_emlrtDCI, (emlrtConstCTX)sp);
          }

          maxdimlen = static_cast<int32_T>(n);
          for (i2 = 0; i2 < maxdimlen; i2++) {
            b_index[i2] = true;
          }

          if (guiyi + 1.0 > static_cast<int32_T>(n)) {
            i2 = 0;
            i5 = 0;
          } else {
            if (guiyi + 1.0 != static_cast<int32_T>(guiyi + 1.0)) {
              emlrtIntegerCheckR2012b(guiyi + 1.0, &x_emlrtDCI, (emlrtConstCTX)
                sp);
            }

            if ((static_cast<int32_T>(guiyi + 1.0) < 1) || (static_cast<int32_T>
                 (guiyi + 1.0) > static_cast<int32_T>(n))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi + 1.0), 1,
                static_cast<int32_T>(n), &x_emlrtBCI, (emlrtConstCTX)sp);
            }

            i2 = static_cast<int32_T>(guiyi + 1.0) - 1;
            if (static_cast<int32_T>(n) < 1) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                static_cast<int32_T>(n), &w_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(n);
          }

          c_loop_ub = i5 - i2;
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_index[i2 + i5] = false;
          }

          if (guiyi + 1.0 > x.size(2)) {
            i2 = 0;
            i5 = 0;
          } else {
            if (guiyi + 1.0 != static_cast<int32_T>(guiyi + 1.0)) {
              emlrtIntegerCheckR2012b(guiyi + 1.0, &ab_emlrtDCI, (emlrtConstCTX)
                sp);
            }

            if ((static_cast<int32_T>(guiyi + 1.0) < 1) || (static_cast<int32_T>
                 (guiyi + 1.0) > x.size(2))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi + 1.0), 1,
                x.size(2), &cb_emlrtBCI, (emlrtConstCTX)sp);
            }

            i2 = static_cast<int32_T>(guiyi + 1.0) - 1;
            if (x.size(2) < 1) {
              emlrtDynamicBoundsCheckR2012b(x.size(2), 1, x.size(2),
                &bb_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = x.size(2);
          }

          c_loop_ub = i5 - i2;
          x_test.set_size(&vd_emlrtRTEI, sp, x.size(0), x.size(1), c_loop_ub);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            nx = x.size(1);
            for (int32_T i6{0}; i6 < nx; i6++) {
              maxdimlen = x.size(0);
              for (vectorUB = 0; vectorUB < maxdimlen; vectorUB++) {
                x_test[(vectorUB + x_test.size(0) * i6) + x_test.size(0) *
                  x_test.size(1) * i5] = x[(vectorUB + x.size(0) * i6) + x.size
                  (0) * x.size(1) * (i2 + i5)];
              }
            }
          }

          if (guiyi + 1.0 > y.size(0)) {
            i2 = 0;
            i5 = 0;
          } else {
            if (guiyi + 1.0 != static_cast<int32_T>(guiyi + 1.0)) {
              emlrtIntegerCheckR2012b(guiyi + 1.0, &y_emlrtDCI, (emlrtConstCTX)
                sp);
            }

            if ((static_cast<int32_T>(guiyi + 1.0) < 1) || (static_cast<int32_T>
                 (guiyi + 1.0) > y.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi + 1.0), 1,
                y.size(0), &ab_emlrtBCI, (emlrtConstCTX)sp);
            }

            i2 = static_cast<int32_T>(guiyi + 1.0) - 1;
            if (y.size(0) < 1) {
              emlrtDynamicBoundsCheckR2012b(y.size(0), 1, y.size(0), &y_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            i5 = y.size(0);
          }

          c_varargin_1[0] = 1;
          varargin_1_tmp = i5 - i2;
          c_varargin_1[1] = varargin_1_tmp;
          st.site = &j_emlrtRSI;
          coder::internal::indexShapeCheck(st, y.size(0), c_varargin_1);
          y_test.set_size(&wd_emlrtRTEI, sp, varargin_1_tmp);
          for (i5 = 0; i5 < varargin_1_tmp; i5++) {
            y_test[i5] = y[i2 + i5];
          }

          vectorUB = b_index.size(0) - 1;
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              maxdimlen++;
            }
          }

          r4.set_size(&lb_emlrtRTEI, sp, maxdimlen);
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              r4[maxdimlen] = nx;
              maxdimlen++;
            }
          }

          c_loop_ub = r4.size(0);
          b_x_train.set_size(&xd_emlrtRTEI, sp, x.size(0), x.size(1), r4.size(0));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            nx = x.size(1);
            for (i5 = 0; i5 < nx; i5++) {
              maxdimlen = x.size(0);
              for (int32_T i6{0}; i6 < maxdimlen; i6++) {
                if (r4[i2] > x.size(2) - 1) {
                  emlrtDynamicBoundsCheckR2012b(r4[i2], 0, x.size(2) - 1,
                    &ob_emlrtBCI, (emlrtConstCTX)sp);
                }

                b_x_train[(i6 + b_x_train.size(0) * i5) + b_x_train.size(0) *
                  b_x_train.size(1) * i2] = x[(i6 + x.size(0) * i5) + x.size(0) *
                  x.size(1) * r4[i2]];
              }
            }
          }

          c_loop_ub = r4.size(0);
          y_train.set_size(&yd_emlrtRTEI, sp, r4.size(0));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            if (r4[i2] > y.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(r4[i2], 0, y.size(0) - 1,
                &qb_emlrtBCI, (emlrtConstCTX)sp);
            }

            y_train[i2] = y[r4[i2]];
          }
        } else {
          n_test = batch_size;

          // n_batch为测试集样本数
          n_train = n - batch_size;
          if (!(n >= 0.0)) {
            emlrtNonNegativeCheckR2012b(n, &nb_emlrtDCI, (emlrtConstCTX)sp);
          }

          a = static_cast<int32_T>(muDoubleScalarFloor(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &mb_emlrtDCI, (emlrtConstCTX)sp);
          }

          b_index.set_size(&pd_emlrtRTEI, sp, static_cast<int32_T>(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &mb_emlrtDCI, (emlrtConstCTX)sp);
          }

          c_loop_ub = static_cast<int32_T>(n);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            b_index[i2] = true;
          }

          a = ((static_cast<real_T>(u) + 1.0) - 1.0) * batch_size + 1.0;
          guiyi = (static_cast<real_T>(u) + 1.0) * batch_size;
          if (a > guiyi) {
            i2 = 0;
            i5 = 0;
          } else {
            if (a != static_cast<int32_T>(a)) {
              emlrtIntegerCheckR2012b(a, &s_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
                 static_cast<int32_T>(n))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1,
                static_cast<int32_T>(n), &r_emlrtBCI, (emlrtConstCTX)sp);
            }

            i2 = static_cast<int32_T>(a) - 1;
            if (guiyi != static_cast<int32_T>(guiyi)) {
              emlrtIntegerCheckR2012b(guiyi, &r_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(guiyi) < 1) || (static_cast<int32_T>(guiyi)
                 > static_cast<int32_T>(n))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi), 1,
                static_cast<int32_T>(n), &q_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(guiyi);
          }

          c_loop_ub = i5 - i2;
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_index[i2 + i5] = false;
          }

          if (a > guiyi) {
            i2 = 0;
            i5 = 0;
          } else {
            if (a != static_cast<int32_T>(a)) {
              emlrtIntegerCheckR2012b(a, &w_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
                 x.size(2))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1, x.size(2),
                &v_emlrtBCI, (emlrtConstCTX)sp);
            }

            i2 = static_cast<int32_T>(a) - 1;
            if (guiyi != static_cast<int32_T>(guiyi)) {
              emlrtIntegerCheckR2012b(guiyi, &v_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(guiyi) < 1) || (static_cast<int32_T>(guiyi)
                 > x.size(2))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi), 1,
                x.size(2), &u_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(guiyi);
          }

          c_loop_ub = i5 - i2;
          x_test.set_size(&qd_emlrtRTEI, sp, x.size(0), x.size(1), c_loop_ub);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            nx = x.size(1);
            for (int32_T i6{0}; i6 < nx; i6++) {
              maxdimlen = x.size(0);
              for (vectorUB = 0; vectorUB < maxdimlen; vectorUB++) {
                x_test[(vectorUB + x_test.size(0) * i6) + x_test.size(0) *
                  x_test.size(1) * i5] = x[(vectorUB + x.size(0) * i6) + x.size
                  (0) * x.size(1) * (i2 + i5)];
              }
            }
          }

          if (a > guiyi) {
            i2 = 0;
            i5 = 0;
          } else {
            if (a != static_cast<int32_T>(a)) {
              emlrtIntegerCheckR2012b(a, &u_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
                 y.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1, y.size(0),
                &t_emlrtBCI, (emlrtConstCTX)sp);
            }

            i2 = static_cast<int32_T>(a) - 1;
            if (guiyi != static_cast<int32_T>(guiyi)) {
              emlrtIntegerCheckR2012b(guiyi, &t_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(guiyi) < 1) || (static_cast<int32_T>(guiyi)
                 > y.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi), 1,
                y.size(0), &s_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(guiyi);
          }

          c_varargin_1[0] = 1;
          varargin_1_tmp = i5 - i2;
          c_varargin_1[1] = varargin_1_tmp;
          st.site = &k_emlrtRSI;
          coder::internal::indexShapeCheck(st, y.size(0), c_varargin_1);
          y_test.set_size(&rd_emlrtRTEI, sp, varargin_1_tmp);
          for (i5 = 0; i5 < varargin_1_tmp; i5++) {
            y_test[i5] = y[i2 + i5];
          }

          vectorUB = b_index.size(0) - 1;
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              maxdimlen++;
            }
          }

          r5.set_size(&lb_emlrtRTEI, sp, maxdimlen);
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              r5[maxdimlen] = nx;
              maxdimlen++;
            }
          }

          c_loop_ub = r5.size(0);
          b_x_train.set_size(&sd_emlrtRTEI, sp, x.size(0), x.size(1), r5.size(0));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            nx = x.size(1);
            for (i5 = 0; i5 < nx; i5++) {
              maxdimlen = x.size(0);
              for (int32_T i6{0}; i6 < maxdimlen; i6++) {
                if (r5[i2] > x.size(2) - 1) {
                  emlrtDynamicBoundsCheckR2012b(r5[i2], 0, x.size(2) - 1,
                    &sb_emlrtBCI, (emlrtConstCTX)sp);
                }

                b_x_train[(i6 + b_x_train.size(0) * i5) + b_x_train.size(0) *
                  b_x_train.size(1) * i2] = x[(i6 + x.size(0) * i5) + x.size(0) *
                  x.size(1) * r5[i2]];
              }
            }
          }

          c_loop_ub = r5.size(0);
          y_train.set_size(&td_emlrtRTEI, sp, r5.size(0));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            if (r5[i2] > y.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(r5[i2], 0, y.size(0) - 1,
                &ub_emlrtBCI, (emlrtConstCTX)sp);
            }

            y_train[i2] = y[r5[i2]];
          }
        }

        beta_part.set_size(&ae_emlrtRTEI, sp, loop_ub);
        for (i2 = 0; i2 < loop_ub; i2++) {
          beta_part[i2] = coefficients0[i2];
        }

        gamma_part.set_size(&be_emlrtRTEI, sp, b_loop_ub);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          gamma_part[i2] = coefficients0[i1 + i2];
        }

        st.site = &l_emlrtRSI;
        coder::eye(st, n_train, r1);
        b_beta_part.set_size(&lb_emlrtRTEI, sp, 1, loop_ub);
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_beta_part[i2] = coefficients0[i2];
        }

        st.site = &l_emlrtRSI;
        coder::kron(st, r1, b_beta_part, beta_likelihood);
        st.site = &m_emlrtRSI;
        coder::permute(st, b_x_train, r2);
        d_varargin_1 = row_size * n_train;
        st.site = &m_emlrtRSI;
        nx = r2.size(0) * r2.size(1) * r2.size(2);
        b_st.site = &jf_emlrtRSI;
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, d_varargin_1);
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, col_size);
        maxdimlen = r2.size(0);
        if (r2.size(1) > r2.size(0)) {
          maxdimlen = r2.size(1);
        }

        if (r2.size(2) > maxdimlen) {
          maxdimlen = r2.size(2);
        }

        maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
        if (static_cast<int32_T>(d_varargin_1) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        if (static_cast<int32_T>(col_size) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        out = (static_cast<int32_T>(d_varargin_1) >= 0);
        if (!out) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:checkDimCommon:nonnegativeSize",
            "MATLAB:checkDimCommon:nonnegativeSize", 0);
        }

        if (static_cast<int32_T>(d_varargin_1) * static_cast<int32_T>(col_size)
            != nx) {
          emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
            "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }

        st.site = &n_emlrtRSI;
        c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
          beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
        c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
          b_pai_gamma);
        st.site = &n_emlrtRSI;
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, b_pai_gamma, gamma0_part,
          b_pai_gamma.size(1), b_loop_ub);
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma0_part, beta0);
        if ((y_train.size(0) != beta0.size(0)) && ((y_train.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(y_train.size(0), beta0.size(0),
            &fd_emlrtECI, (emlrtConstCTX)sp);
        }

        if (y_train.size(0) == beta0.size(0)) {
          gamma0.set_size(&ce_emlrtRTEI, sp, y_train.size(0));
          c_loop_ub = y_train.size(0);
          nx = (y_train.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&y_train[i2]);
            r3 = _mm_loadu_pd(&beta0[i2]);
            _mm_storeu_pd(&gamma0[i2], _mm_mul_pd(r, r3));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            gamma0[i2] = y_train[i2] * beta0[i2];
          }
        } else {
          st.site = &o_emlrtRSI;
          times(st, gamma0, y_train, beta0);
        }

        st.site = &o_emlrtRSI;
        coder::b_exp(st, beta0);
        c_loop_ub = beta0.size(0);
        nx = (beta0.size(0) / 2) << 1;
        vectorUB = nx - 2;
        for (i2 = 0; i2 <= vectorUB; i2 += 2) {
          r = _mm_loadu_pd(&beta0[i2]);
          _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
        }

        for (i2 = nx; i2 < c_loop_ub; i2++) {
          beta0[i2] = beta0[i2] + 1.0;
        }

        st.site = &o_emlrtRSI;
        coder::b_log(st, beta0);
        if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0),
            &fd_emlrtECI, (emlrtConstCTX)sp);
        }

        st.site = &p_emlrtRSI;
        guiyi = coder::b_norm(beta0_part);
        b_st.site = &le_emlrtRSI;
        st.site = &p_emlrtRSI;
        a = coder::b_norm(gamma0_part);
        b_st.site = &le_emlrtRSI;
        if (gamma0.size(0) == beta0.size(0)) {
          beta0.set_size(&ce_emlrtRTEI, sp, gamma0.size(0));
          c_loop_ub = gamma0.size(0);
          nx = (gamma0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&gamma0[i2]);
            r3 = _mm_loadu_pd(&beta0[i2]);
            _mm_storeu_pd(&beta0[i2], _mm_sub_pd(r, r3));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            beta0[i2] = gamma0[i2] - beta0[i2];
          }

          st.site = &o_emlrtRSI;
          log_likelihood0 = -coder::sum(st, beta0) + 0.5 * lambda_tuning *
            (guiyi * guiyi + a * a);
        } else {
          st.site = &o_emlrtRSI;
          log_likelihood0 = binary_expand_op(st, o_emlrtRSI, gamma0, beta0,
            lambda_tuning, guiyi, a);
        }

        *diff_loglikelihood = 1.0;
        st.site = &q_emlrtRSI;
        nx = b_x_train.size(0) * b_x_train.size(1) * b_x_train.size(2);
        b_st.site = &jf_emlrtRSI;
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, varargin_1);
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, n_train);
        maxdimlen = b_x_train.size(0);
        if (b_x_train.size(1) > b_x_train.size(0)) {
          maxdimlen = b_x_train.size(1);
        }

        if (b_x_train.size(2) > maxdimlen) {
          maxdimlen = b_x_train.size(2);
        }

        maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
        if (static_cast<int32_T>(varargin_1) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        if (static_cast<int32_T>(n_train) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        out = (static_cast<int32_T>(varargin_1) >= 0);
        if ((!out) || (static_cast<int32_T>(n_train) < 0)) {
          out = false;
        }

        if (!out) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:checkDimCommon:nonnegativeSize",
            "MATLAB:checkDimCommon:nonnegativeSize", 0);
        }

        if (static_cast<int32_T>(varargin_1) * static_cast<int32_T>(n_train) !=
            nx) {
          emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
            "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }

        *iter_initial_in = 0.0;
        while ((*diff_loglikelihood > eps_initial) && (*iter_initial_in <=
                iter_max_initial_in)) {
          //  beta_likelihood_train = kron(eye(n_train),beta_part');
          //  eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
          //  eta_likelihood_mat_train = diag((1 + exp(beta_likelihood_train*x_likelihood_train*gamma_part)).^(-1));
          //  eta_likelihood_mat2_train = diag(sqrt(exp(beta_likelihood_train*x_likelihood_train*gamma_part)));
          //
          //  grdient_sum_train = [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]*...
          //      [x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)]...
          //      +lambda_tuning*[beta_part;gamma_part];
          //
          //  Hessin_sum_train = [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]*...
          //      (x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))'*...
          //      [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]'+...
          //      [zeros(row_size,col_size),...
          //      reshape([x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)],row_size,col_size);...
          //      reshape([x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)],row_size,col_size)',...
          //      zeros(col_size,row_size)]+...
          //      [lambda_tuning*eye(row_size),zeros(row_size,col_size);zeros(col_size,row_size),lambda_tuning*eye(col_size)];
          //  newton_sum_train = pinv(Hessin_sum_train)*grdient_sum_train;
          //  z = min(eig(Hessin_sum_train));
          //  % % if z>0
          //  sumvec_train = [beta_part;gamma_part]-newton_sum_train;
          //  beta_part = sumvec_train(1:row_size);
          //  gamma_part = sumvec_train((row_size+1):end);
          //  guiyi = sign(gamma_part(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_part)/norm(beta_part)));
          //  gamma_part = gamma_part/guiyi;%拿出来了
          //  beta_part = beta_part*guiyi;%拿出来了
          //  beta_likelihood_train = kron(eye(n_train),beta_part');
          //  eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
          //  log_likelihood  = -sum(y_train.*eta_likelihood_train-log(1+exp(eta_likelihood_train)))+...
          //                      0.5*lambda_tuning*(norm(beta_part).^2+norm(gamma_part).^2);
          //  diff_loglikelihood = abs(log_likelihood-log_likelihood0)
          //  log_likelihood0 = log_likelihood
          //  iter_initial_in = iter_initial_in + 1;
          //  beta_part
          //  disp(1)
          //  % % else
          st.site = &r_emlrtRSI;
          coder::eye(st, n_train, r1);
          b_beta_part.set_size(&ee_emlrtRTEI, sp, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            b_beta_part[i2] = beta_part[i2];
          }

          st.site = &r_emlrtRSI;
          coder::kron(st, r1, b_beta_part, beta_likelihood);
          st.site = &s_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &s_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part,
            qh_emlrtRSI);
          st.site = &t_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &t_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &t_emlrtRSI;
          b_st.site = &t_emlrtRSI;
          coder::b_exp(b_st, beta0);
          c_loop_ub = beta0.size(0);
          nx = (beta0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&beta0[i2]);
            _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            beta0[i2] = beta0[i2] + 1.0;
          }

          b_st.site = &le_emlrtRSI;
          C2.set_size(&v_emlrtRTEI, sp, beta0.size(0));
          c_loop_ub = beta0.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            guiyi = beta0[i2];
            C2[i2] = 1.0 / guiyi;
          }

          st.site = &t_emlrtRSI;
          coder::diag(st, C2, eta_likelihood_mat_train);
          st.site = &u_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &u_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &u_emlrtRSI;
          coder::b_exp(st, beta0);
          st.site = &u_emlrtRSI;
          coder::b_sqrt(st, beta0);
          st.site = &u_emlrtRSI;
          coder::diag(st, beta0, beta_likelihood);
          st.site = &v_emlrtRSI;
          b_st.site = &le_emlrtRSI;
          b.set_size(&fe_emlrtRTEI, &b_st, beta_likelihood.size(0),
                     beta_likelihood.size(1));
          maxdimlen = beta_likelihood.size(0) * beta_likelihood.size(1);
          for (i2 = 0; i2 < maxdimlen; i2++) {
            guiyi = beta_likelihood[i2];
            b[i2] = guiyi * guiyi;
          }

          if ((b.size(0) != eta_likelihood_mat_train.size(0)) && ((b.size(0) !=
                1) && (eta_likelihood_mat_train.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(0), eta_likelihood_mat_train.size
              (0), &ed_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(1) != eta_likelihood_mat_train.size(1)) && ((b.size(1) !=
                1) && (eta_likelihood_mat_train.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(1), eta_likelihood_mat_train.size
              (1), &dd_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(0) == eta_likelihood_mat_train.size(0)) && (b.size(1) ==
               eta_likelihood_mat_train.size(1))) {
            nx = (maxdimlen / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&b[i2]);
              r3 = _mm_loadu_pd(&eta_likelihood_mat_train[i2]);
              _mm_storeu_pd(&b[i2], _mm_mul_pd(r, r3));
            }

            for (i2 = nx; i2 < maxdimlen; i2++) {
              b[i2] = b[i2] * eta_likelihood_mat_train[i2];
            }
          } else {
            st.site = &v_emlrtRSI;
            times(st, b, eta_likelihood_mat_train);
          }

          st.site = &v_emlrtRSI;
          coder::diag(st, y_train, r1);
          if ((b.size(0) != r1.size(0)) && ((b.size(0) != 1) && (r1.size(0) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(0), r1.size(0), &cd_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if ((b.size(1) != r1.size(1)) && ((b.size(1) != 1) && (r1.size(1) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(1), r1.size(1), &bd_emlrtECI,
              (emlrtConstCTX)sp);
          }

          st.site = &v_emlrtRSI;
          b_st.site = &v_emlrtRSI;
          coder::eye(b_st, row_size, r8);
          b_beta_part.set_size(&ge_emlrtRTEI, &st, 1, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            b_beta_part[i2] = gamma_part[i2];
          }

          b_st.site = &v_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          varargin_1_tmp = static_cast<int32_T>(n_train);
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, x_train, b_a.size(1),
            static_cast<int32_T>(varargin_1));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, x_train, b_pai_gamma);
          st.site = &v_emlrtRSI;
          if ((b.size(0) == r1.size(0)) && (b.size(1) == r1.size(1))) {
            c_loop_ub = b.size(0) * b.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&b[i2]);
              r3 = _mm_loadu_pd(&r1[i2]);
              _mm_storeu_pd(&b[i2], _mm_sub_pd(r, r3));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              b[i2] = b[i2] - r1[i2];
            }
          } else {
            b_st.site = &v_emlrtRSI;
            minus(b_st, b, r1);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, b, b_pai_gamma.size(1),
            b.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, b, b_y);
          st.site = &v_emlrtRSI;
          if (!(n_train >= 0.0)) {
            emlrtNonNegativeCheckR2012b(n_train, &xb_emlrtDCI, &st);
          }

          i2 = static_cast<int32_T>(muDoubleScalarFloor(n_train));
          if (n_train != i2) {
            emlrtIntegerCheckR2012b(n_train, &wb_emlrtDCI, &st);
          }

          beta0.set_size(&he_emlrtRTEI, &st, static_cast<int32_T>(n_train));
          if (n_train != i2) {
            emlrtIntegerCheckR2012b(n_train, &wb_emlrtDCI, &st);
          }

          for (i5 = 0; i5 < varargin_1_tmp; i5++) {
            beta0[i5] = 1.0;
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_y, beta0, b_y.size(1), static_cast<
            int32_T>(n_train));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_y, beta0, C2);
          gamma0.set_size(&ie_emlrtRTEI, sp, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          maxdimlen = (beta_part.size(0) / 2) << 1;
          vectorUB_tmp = maxdimlen - 2;
          for (i5 = 0; i5 <= vectorUB_tmp; i5 += 2) {
            r = _mm_loadu_pd(&beta_part[i5]);
            _mm_storeu_pd(&gamma0[i5], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i5 = maxdimlen; i5 < c_loop_ub; i5++) {
            gamma0[i5] = lambda_tuning * beta_part[i5];
          }

          if ((C2.size(0) != gamma0.size(0)) && ((C2.size(0) != 1) &&
               (gamma0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(C2.size(0), gamma0.size(0), &ad_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if (C2.size(0) == gamma0.size(0)) {
            c_loop_ub = C2.size(0);
            nx = (C2.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&C2[i5]);
              r3 = _mm_loadu_pd(&gamma0[i5]);
              _mm_storeu_pd(&C2[i5], _mm_add_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              C2[i5] = C2[i5] + gamma0[i5];
            }
          } else {
            st.site = &v_emlrtRSI;
            plus(st, C2, gamma0);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &yc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &xc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &wc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &vc_emlrtECI, (emlrtConstCTX)sp);
          }

          st.site = &w_emlrtRSI;
          if ((eta_likelihood_mat_train.size(0) == beta_likelihood.size(0)) &&
              (eta_likelihood_mat_train.size(1) == beta_likelihood.size(1))) {
            c_loop_ub = eta_likelihood_mat_train.size(0) *
              eta_likelihood_mat_train.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&eta_likelihood_mat_train[i5]);
              r3 = _mm_loadu_pd(&beta_likelihood[i5]);
              _mm_storeu_pd(&eta_likelihood_mat_train[i5], _mm_mul_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              eta_likelihood_mat_train[i5] = eta_likelihood_mat_train[i5] *
                beta_likelihood[i5];
            }
          } else {
            b_st.site = &w_emlrtRSI;
            times(b_st, eta_likelihood_mat_train, beta_likelihood);
          }

          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            r1);
          st.site = &w_emlrtRSI;
          coder::eye(st, row_size, r8);
          b_beta_part.set_size(&je_emlrtRTEI, sp, 1, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = gamma_part[i5];
          }

          st.site = &w_emlrtRSI;
          coder::b_kron(st, b_beta_part, r8, b);
          st.site = &w_emlrtRSI;
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            b_pai_gamma);
          st.site = &w_emlrtRSI;
          b_st.site = &w_emlrtRSI;
          coder::eye(b_st, row_size, r8);
          b_beta_part.set_size(&ke_emlrtRTEI, &st, 1, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = gamma_part[i5];
          }

          b_st.site = &w_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, b_pai_gamma, b_a.size(1),
            b_pai_gamma.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, b_pai_gamma, b_y);
          st.site = &w_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_y, r1, b_y.size(1), r1.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_y, r1, b_pai_gamma);
          st.site = &w_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, b, b_pai_gamma.size(1),
            b.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_pai_gamma, b, beta_likelihood);
          st.site = &x_emlrtRSI;
          coder::eye(st, row_size, b);
          c_loop_ub = b.size(0) * b.size(1);
          nx = (c_loop_ub / 2) << 1;
          vectorUB = nx - 2;
          for (i5 = 0; i5 <= vectorUB; i5 += 2) {
            r = _mm_loadu_pd(&b[i5]);
            _mm_storeu_pd(&b[i5], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i5 = nx; i5 < c_loop_ub; i5++) {
            b[i5] = lambda_tuning * b[i5];
          }

          if ((beta_likelihood.size(0) != b.size(0)) && ((beta_likelihood.size(0)
                != 1) && (b.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(0), b.size(0),
              &uc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(1) != b.size(1)) && ((beta_likelihood.size(1)
                != 1) && (b.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(1), b.size(1),
              &tc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(0) == b.size(0)) && (beta_likelihood.size(1)
               == b.size(1))) {
            c_loop_ub = beta_likelihood.size(0) * beta_likelihood.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&beta_likelihood[i5]);
              r3 = _mm_loadu_pd(&b[i5]);
              _mm_storeu_pd(&beta_likelihood[i5], _mm_add_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              beta_likelihood[i5] = beta_likelihood[i5] + b[i5];
            }
          } else {
            st.site = &w_emlrtRSI;
            plus(st, beta_likelihood, b);
          }

          st.site = &y_emlrtRSI;
          b_st.site = &y_emlrtRSI;
          if (beta_likelihood.size(0) < beta_likelihood.size(1)) {
            b_pai_gamma.set_size(&fc_emlrtRTEI, &b_st, beta_likelihood.size(1),
                                 beta_likelihood.size(0));
            c_loop_ub = beta_likelihood.size(0);
            for (i5 = 0; i5 < c_loop_ub; i5++) {
              nx = beta_likelihood.size(1);
              for (int32_T i6{0}; i6 < nx; i6++) {
                b_pai_gamma[i6 + b_pai_gamma.size(0) * i5] = beta_likelihood[i5
                  + beta_likelihood.size(0) * i6];
              }
            }

            c_st.site = &yf_emlrtRSI;
            coder::eml_pinv(c_st, b_pai_gamma, r1);
            b_a.set_size(&le_emlrtRTEI, &b_st, r1.size(1), r1.size(0));
            c_loop_ub = r1.size(0);
            for (i5 = 0; i5 < c_loop_ub; i5++) {
              nx = r1.size(1);
              for (int32_T i6{0}; i6 < nx; i6++) {
                b_a[i6 + b_a.size(0) * i5] = r1[i5 + r1.size(0) * i6];
              }
            }
          } else {
            c_st.site = &ag_emlrtRSI;
            coder::eml_pinv(c_st, beta_likelihood, b_a);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, C2, b_a.size(1), C2.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, C2, beta0);
          a = coder::b_norm(beta0);
          if (a > 1.0) {
            c_loop_ub = beta0.size(0);
            nx = (beta0.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&beta0[i5]);
              _mm_storeu_pd(&beta0[i5], _mm_div_pd(r, _mm_set1_pd(a)));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              beta0[i5] = beta0[i5] / a;
            }
          }

          if ((beta_part.size(0) != beta0.size(0)) && ((beta_part.size(0) != 1) &&
               (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_part.size(0), beta0.size(0),
              &sc_emlrtECI, (emlrtConstCTX)sp);
          }

          if (beta_part.size(0) == beta0.size(0)) {
            c_loop_ub = beta_part.size(0);
            for (i5 = 0; i5 <= vectorUB_tmp; i5 += 2) {
              r = _mm_loadu_pd(&beta_part[i5]);
              r3 = _mm_loadu_pd(&beta0[i5]);
              _mm_storeu_pd(&beta_part[i5], _mm_sub_pd(r, r3));
            }

            for (i5 = maxdimlen; i5 < c_loop_ub; i5++) {
              beta_part[i5] = beta_part[i5] - beta0[i5];
            }
          } else {
            st.site = &nh_emlrtRSI;
            minus(st, beta_part, beta0);
          }

          st.site = &ab_emlrtRSI;
          coder::eye(st, n_train, r1);
          b_beta_part.set_size(&me_emlrtRTEI, sp, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = beta_part[i5];
          }

          st.site = &ab_emlrtRSI;
          coder::kron(st, r1, b_beta_part, beta_likelihood);
          st.site = &bb_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &bb_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part,
            th_emlrtRSI);
          st.site = &cb_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &cb_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &cb_emlrtRSI;
          b_st.site = &cb_emlrtRSI;
          coder::b_exp(b_st, beta0);
          c_loop_ub = beta0.size(0);
          nx = (beta0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i5 = 0; i5 <= vectorUB; i5 += 2) {
            r = _mm_loadu_pd(&beta0[i5]);
            _mm_storeu_pd(&beta0[i5], _mm_add_pd(r, _mm_set1_pd(1.0)));
          }

          for (i5 = nx; i5 < c_loop_ub; i5++) {
            beta0[i5] = beta0[i5] + 1.0;
          }

          b_st.site = &le_emlrtRSI;
          C2.set_size(&v_emlrtRTEI, sp, beta0.size(0));
          c_loop_ub = beta0.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            guiyi = beta0[i5];
            C2[i5] = 1.0 / guiyi;
          }

          st.site = &cb_emlrtRSI;
          coder::diag(st, C2, eta_likelihood_mat_train);
          st.site = &db_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &db_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &db_emlrtRSI;
          coder::b_exp(st, beta0);
          st.site = &db_emlrtRSI;
          coder::b_sqrt(st, beta0);
          st.site = &db_emlrtRSI;
          coder::diag(st, beta0, beta_likelihood);
          st.site = &eb_emlrtRSI;
          b_st.site = &le_emlrtRSI;
          b.set_size(&ne_emlrtRTEI, &b_st, beta_likelihood.size(0),
                     beta_likelihood.size(1));
          maxdimlen = beta_likelihood.size(0) * beta_likelihood.size(1);
          for (i5 = 0; i5 < maxdimlen; i5++) {
            guiyi = beta_likelihood[i5];
            b[i5] = guiyi * guiyi;
          }

          if ((b.size(0) != eta_likelihood_mat_train.size(0)) && ((b.size(0) !=
                1) && (eta_likelihood_mat_train.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(0), eta_likelihood_mat_train.size
              (0), &rc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(1) != eta_likelihood_mat_train.size(1)) && ((b.size(1) !=
                1) && (eta_likelihood_mat_train.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(1), eta_likelihood_mat_train.size
              (1), &qc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(0) == eta_likelihood_mat_train.size(0)) && (b.size(1) ==
               eta_likelihood_mat_train.size(1))) {
            nx = (maxdimlen / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&b[i5]);
              r3 = _mm_loadu_pd(&eta_likelihood_mat_train[i5]);
              _mm_storeu_pd(&b[i5], _mm_mul_pd(r, r3));
            }

            for (i5 = nx; i5 < maxdimlen; i5++) {
              b[i5] = b[i5] * eta_likelihood_mat_train[i5];
            }
          } else {
            st.site = &eb_emlrtRSI;
            times(st, b, eta_likelihood_mat_train);
          }

          st.site = &eb_emlrtRSI;
          coder::diag(st, y_train, r1);
          if ((b.size(0) != r1.size(0)) && ((b.size(0) != 1) && (r1.size(0) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(0), r1.size(0), &pc_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if ((b.size(1) != r1.size(1)) && ((b.size(1) != 1) && (r1.size(1) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(1), r1.size(1), &oc_emlrtECI,
              (emlrtConstCTX)sp);
          }

          st.site = &eb_emlrtRSI;
          b_st.site = &eb_emlrtRSI;
          coder::eye(b_st, col_size, r8);
          b_beta_part.set_size(&oe_emlrtRTEI, &st, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = beta_part[i5];
          }

          b_st.site = &eb_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1),
            pai_gamma.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, b_pai_gamma);
          st.site = &eb_emlrtRSI;
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, x_train,
            b_pai_gamma.size(1), static_cast<int32_T>(varargin_1));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, x_train, b_y);
          st.site = &eb_emlrtRSI;
          if ((b.size(0) == r1.size(0)) && (b.size(1) == r1.size(1))) {
            c_loop_ub = b.size(0) * b.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&b[i5]);
              r3 = _mm_loadu_pd(&r1[i5]);
              _mm_storeu_pd(&b[i5], _mm_sub_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              b[i5] = b[i5] - r1[i5];
            }
          } else {
            b_st.site = &eb_emlrtRSI;
            minus(b_st, b, r1);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_y, b, b_y.size(1), b.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_y, b, b_pai_gamma);
          st.site = &eb_emlrtRSI;
          if (static_cast<int32_T>(n_train) != i2) {
            emlrtIntegerCheckR2012b(n_train, &dc_emlrtDCI, &st);
          }

          beta0.set_size(&pe_emlrtRTEI, &st, static_cast<int32_T>(n_train));
          if (static_cast<int32_T>(n_train) != i2) {
            emlrtIntegerCheckR2012b(n_train, &dc_emlrtDCI, &st);
          }

          for (i2 = 0; i2 < varargin_1_tmp; i2++) {
            beta0[i2] = 1.0;
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, beta0, b_pai_gamma.size
            (1), static_cast<int32_T>(n_train));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, beta0, C2);
          gamma0.set_size(&qe_emlrtRTEI, sp, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          maxdimlen = (gamma_part.size(0) / 2) << 1;
          vectorUB_tmp = maxdimlen - 2;
          for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
            r = _mm_loadu_pd(&gamma_part[i2]);
            _mm_storeu_pd(&gamma0[i2], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i2 = maxdimlen; i2 < c_loop_ub; i2++) {
            gamma0[i2] = lambda_tuning * gamma_part[i2];
          }

          if ((C2.size(0) != gamma0.size(0)) && ((C2.size(0) != 1) &&
               (gamma0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(C2.size(0), gamma0.size(0), &nc_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if (C2.size(0) == gamma0.size(0)) {
            c_loop_ub = C2.size(0);
            nx = (C2.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&C2[i2]);
              r3 = _mm_loadu_pd(&gamma0[i2]);
              _mm_storeu_pd(&C2[i2], _mm_add_pd(r, r3));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              C2[i2] = C2[i2] + gamma0[i2];
            }
          } else {
            st.site = &eb_emlrtRSI;
            plus(st, C2, gamma0);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &mc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &lc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &kc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &jc_emlrtECI, (emlrtConstCTX)sp);
          }

          st.site = &fb_emlrtRSI;
          if ((eta_likelihood_mat_train.size(0) == beta_likelihood.size(0)) &&
              (eta_likelihood_mat_train.size(1) == beta_likelihood.size(1))) {
            c_loop_ub = eta_likelihood_mat_train.size(0) *
              eta_likelihood_mat_train.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&eta_likelihood_mat_train[i2]);
              r3 = _mm_loadu_pd(&beta_likelihood[i2]);
              _mm_storeu_pd(&eta_likelihood_mat_train[i2], _mm_mul_pd(r, r3));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              eta_likelihood_mat_train[i2] = eta_likelihood_mat_train[i2] *
                beta_likelihood[i2];
            }
          } else {
            b_st.site = &fb_emlrtRSI;
            times(b_st, eta_likelihood_mat_train, beta_likelihood);
          }

          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            r1);
          st.site = &fb_emlrtRSI;
          b_st.site = &fb_emlrtRSI;
          coder::eye(b_st, col_size, r8);
          b_beta_part.set_size(&re_emlrtRTEI, &st, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            b_beta_part[i2] = beta_part[i2];
          }

          b_st.site = &fb_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1),
            pai_gamma.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, r8);
          st.site = &fb_emlrtRSI;
          b_st.site = &fb_emlrtRSI;
          coder::eye(b_st, col_size, b);
          b_beta_part.set_size(&se_emlrtRTEI, &st, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            b_beta_part[i2] = beta_part[i2];
          }

          b_st.site = &fb_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, b, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1),
            pai_gamma.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, b_pai_gamma);
          st.site = &fb_emlrtRSI;
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            b_y);
          st.site = &fb_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, b_y, b_pai_gamma.size(1),
            b_y.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, b_y, beta_likelihood);
          st.site = &fb_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, r1,
            beta_likelihood.size(1), r1.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, beta_likelihood, r1, b_pai_gamma);
          st.site = &fb_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, r8, b_pai_gamma.size(1),
            r8.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_pai_gamma, r8, beta_likelihood);
          st.site = &gb_emlrtRSI;
          coder::eye(st, col_size, b);
          c_loop_ub = b.size(0) * b.size(1);
          nx = (c_loop_ub / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&b[i2]);
            _mm_storeu_pd(&b[i2], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            b[i2] = lambda_tuning * b[i2];
          }

          if ((beta_likelihood.size(0) != b.size(0)) && ((beta_likelihood.size(0)
                != 1) && (b.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(0), b.size(0),
              &ic_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(1) != b.size(1)) && ((beta_likelihood.size(1)
                != 1) && (b.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(1), b.size(1),
              &hc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(0) == b.size(0)) && (beta_likelihood.size(1)
               == b.size(1))) {
            c_loop_ub = beta_likelihood.size(0) * beta_likelihood.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&beta_likelihood[i2]);
              r3 = _mm_loadu_pd(&b[i2]);
              _mm_storeu_pd(&beta_likelihood[i2], _mm_add_pd(r, r3));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              beta_likelihood[i2] = beta_likelihood[i2] + b[i2];
            }
          } else {
            st.site = &fb_emlrtRSI;
            plus(st, beta_likelihood, b);
          }

          st.site = &hb_emlrtRSI;
          b_st.site = &hb_emlrtRSI;
          if (beta_likelihood.size(0) < beta_likelihood.size(1)) {
            b_pai_gamma.set_size(&fc_emlrtRTEI, &b_st, beta_likelihood.size(1),
                                 beta_likelihood.size(0));
            c_loop_ub = beta_likelihood.size(0);
            for (i2 = 0; i2 < c_loop_ub; i2++) {
              nx = beta_likelihood.size(1);
              for (i5 = 0; i5 < nx; i5++) {
                b_pai_gamma[i5 + b_pai_gamma.size(0) * i2] = beta_likelihood[i2
                  + beta_likelihood.size(0) * i5];
              }
            }

            c_st.site = &yf_emlrtRSI;
            coder::eml_pinv(c_st, b_pai_gamma, r1);
            b_a.set_size(&te_emlrtRTEI, &b_st, r1.size(1), r1.size(0));
            c_loop_ub = r1.size(0);
            for (i2 = 0; i2 < c_loop_ub; i2++) {
              nx = r1.size(1);
              for (i5 = 0; i5 < nx; i5++) {
                b_a[i5 + b_a.size(0) * i2] = r1[i2 + r1.size(0) * i5];
              }
            }
          } else {
            c_st.site = &ag_emlrtRSI;
            coder::eml_pinv(c_st, beta_likelihood, b_a);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, C2, b_a.size(1), C2.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, C2, beta0);
          a = coder::b_norm(beta0);
          if (a > 1.0) {
            c_loop_ub = beta0.size(0);
            nx = (beta0.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&beta0[i2]);
              _mm_storeu_pd(&beta0[i2], _mm_div_pd(r, _mm_set1_pd(a)));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              beta0[i2] = beta0[i2] / a;
            }
          }

          if ((gamma_part.size(0) != beta0.size(0)) && ((gamma_part.size(0) != 1)
               && (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(gamma_part.size(0), beta0.size(0),
              &gc_emlrtECI, (emlrtConstCTX)sp);
          }

          if (gamma_part.size(0) == beta0.size(0)) {
            c_loop_ub = gamma_part.size(0);
            for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
              r = _mm_loadu_pd(&gamma_part[i2]);
              r3 = _mm_loadu_pd(&beta0[i2]);
              _mm_storeu_pd(&gamma_part[i2], _mm_sub_pd(r, r3));
            }

            for (i2 = maxdimlen; i2 < c_loop_ub; i2++) {
              gamma_part[i2] = gamma_part[i2] - beta0[i2];
            }
          } else {
            st.site = &oh_emlrtRSI;
            minus(st, gamma_part, beta0);
          }

          if (gamma_part.size(0) < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, gamma_part.size(0), &p_emlrtBCI,
              (emlrtConstCTX)sp);
          }

          st.site = &ib_emlrtRSI;
          if (row_size < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          st.site = &ib_emlrtRSI;
          if (col_size < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          a = muDoubleScalarSqrt(row_size) / muDoubleScalarSqrt(col_size) *
            (coder::b_norm(gamma_part) / coder::b_norm(beta_part));
          st.site = &ib_emlrtRSI;
          if (a < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          a = muDoubleScalarSqrt(a);
          guiyi = muDoubleScalarSign(gamma_part[0]) * a;
          c_loop_ub = gamma_part.size(0);
          nx = (gamma_part.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&gamma_part[i2]);
            _mm_storeu_pd(&gamma_part[i2], _mm_div_pd(r, _mm_set1_pd(guiyi)));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            gamma_part[i2] = gamma_part[i2] / guiyi;
          }

          c_loop_ub = beta_part.size(0);
          nx = (beta_part.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&beta_part[i2]);
            _mm_storeu_pd(&beta_part[i2], _mm_mul_pd(r, _mm_set1_pd(guiyi)));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            beta_part[i2] = beta_part[i2] * guiyi;
          }

          st.site = &jb_emlrtRSI;
          coder::eye(st, n_train, r1);
          b_beta_part.set_size(&ue_emlrtRTEI, sp, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            b_beta_part[i2] = beta_part[i2];
          }

          st.site = &jb_emlrtRSI;
          coder::kron(st, r1, b_beta_part, beta_likelihood);
          st.site = &kb_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &kb_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          if ((y_train.size(0) != beta0.size(0)) && ((y_train.size(0) != 1) &&
               (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(y_train.size(0), beta0.size(0),
              &fc_emlrtECI, (emlrtConstCTX)sp);
          }

          if (y_train.size(0) == beta0.size(0)) {
            gamma0.set_size(&ve_emlrtRTEI, sp, y_train.size(0));
            c_loop_ub = y_train.size(0);
            nx = (y_train.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&y_train[i2]);
              r3 = _mm_loadu_pd(&beta0[i2]);
              _mm_storeu_pd(&gamma0[i2], _mm_mul_pd(r, r3));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              gamma0[i2] = y_train[i2] * beta0[i2];
            }
          } else {
            st.site = &lb_emlrtRSI;
            times(st, gamma0, y_train, beta0);
          }

          st.site = &lb_emlrtRSI;
          coder::b_exp(st, beta0);
          c_loop_ub = beta0.size(0);
          nx = (beta0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&beta0[i2]);
            _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            beta0[i2] = beta0[i2] + 1.0;
          }

          st.site = &lb_emlrtRSI;
          coder::b_log(st, beta0);
          if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
               (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0),
              &fc_emlrtECI, (emlrtConstCTX)sp);
          }

          st.site = &mb_emlrtRSI;
          guiyi = coder::b_norm(beta_part);
          b_st.site = &le_emlrtRSI;
          st.site = &mb_emlrtRSI;
          a = coder::b_norm(gamma_part);
          b_st.site = &le_emlrtRSI;
          if (gamma0.size(0) == beta0.size(0)) {
            beta0.set_size(&ve_emlrtRTEI, sp, gamma0.size(0));
            c_loop_ub = gamma0.size(0);
            nx = (gamma0.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i2 = 0; i2 <= vectorUB; i2 += 2) {
              r = _mm_loadu_pd(&gamma0[i2]);
              r3 = _mm_loadu_pd(&beta0[i2]);
              _mm_storeu_pd(&beta0[i2], _mm_sub_pd(r, r3));
            }

            for (i2 = nx; i2 < c_loop_ub; i2++) {
              beta0[i2] = gamma0[i2] - beta0[i2];
            }

            st.site = &lb_emlrtRSI;
            guiyi = -coder::sum(st, beta0) + 0.5 * lambda_tuning * (guiyi *
              guiyi + a * a);
          } else {
            st.site = &lb_emlrtRSI;
            guiyi = binary_expand_op(st, lb_emlrtRSI, gamma0, beta0,
              lambda_tuning, guiyi, a);
          }

          *diff_loglikelihood = muDoubleScalarAbs(guiyi - log_likelihood0);
          log_likelihood0 = guiyi;
          (*iter_initial_in)++;

          // disp(2)
          //  % % end
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }

        st.site = &nb_emlrtRSI;
        coder::eye(st, n_test, r1);
        b_beta_part.set_size(&de_emlrtRTEI, sp, 1, beta_part.size(0));
        c_loop_ub = beta_part.size(0);
        for (i2 = 0; i2 < c_loop_ub; i2++) {
          b_beta_part[i2] = beta_part[i2];
        }

        st.site = &nb_emlrtRSI;
        coder::kron(st, r1, b_beta_part, beta_likelihood);
        st.site = &ob_emlrtRSI;
        coder::permute(st, x_test, r2);
        d_varargin_1 = row_size * n_test;
        st.site = &ob_emlrtRSI;
        nx = r2.size(0) * r2.size(1) * r2.size(2);
        b_st.site = &jf_emlrtRSI;
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, d_varargin_1);
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, col_size);
        maxdimlen = r2.size(0);
        if (r2.size(1) > r2.size(0)) {
          maxdimlen = r2.size(1);
        }

        if (r2.size(2) > maxdimlen) {
          maxdimlen = r2.size(2);
        }

        maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
        if (static_cast<int32_T>(d_varargin_1) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        if (static_cast<int32_T>(col_size) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        out = (static_cast<int32_T>(d_varargin_1) >= 0);
        if (!out) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:checkDimCommon:nonnegativeSize",
            "MATLAB:checkDimCommon:nonnegativeSize", 0);
        }

        if (static_cast<int32_T>(d_varargin_1) * static_cast<int32_T>(col_size)
            != nx) {
          emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
            "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }

        st.site = &pb_emlrtRSI;
        c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
          beta_likelihood.size(1), static_cast<int32_T>(d_varargin_1));
        c_varargin_1[0] = static_cast<int32_T>(d_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
          b_pai_gamma);
        st.site = &pb_emlrtRSI;
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
          b_pai_gamma.size(1), gamma_part.size(0));
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);

        // log_likelihood0 = -sum(y_test.*eta_likelihood_test-log(1+exp(eta_likelihood_test)));
        if ((y_test.size(0) != beta0.size(0)) && ((y_test.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(y_test.size(0), beta0.size(0),
            &ec_emlrtECI, (emlrtConstCTX)sp);
        }

        if (y_test.size(0) == beta0.size(0)) {
          c_loop_ub = y_test.size(0);
          nx = (y_test.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&y_test[i2]);
            r3 = _mm_loadu_pd(&beta0[i2]);
            _mm_storeu_pd(&y_test[i2], _mm_mul_pd(r, r3));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            y_test[i2] = y_test[i2] * beta0[i2];
          }
        } else {
          st.site = &qb_emlrtRSI;
          times(st, y_test, beta0);
        }

        st.site = &qb_emlrtRSI;
        coder::b_exp(st, beta0);
        c_loop_ub = beta0.size(0);
        nx = (beta0.size(0) / 2) << 1;
        vectorUB = nx - 2;
        for (i2 = 0; i2 <= vectorUB; i2 += 2) {
          r = _mm_loadu_pd(&beta0[i2]);
          _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
        }

        for (i2 = nx; i2 < c_loop_ub; i2++) {
          beta0[i2] = beta0[i2] + 1.0;
        }

        st.site = &qb_emlrtRSI;
        coder::b_log(st, beta0);
        if ((y_test.size(0) != beta0.size(0)) && ((y_test.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(y_test.size(0), beta0.size(0),
            &ec_emlrtECI, (emlrtConstCTX)sp);
        }

        if (y_test.size(0) == beta0.size(0)) {
          c_loop_ub = y_test.size(0);
          nx = (y_test.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i2 = 0; i2 <= vectorUB; i2 += 2) {
            r = _mm_loadu_pd(&y_test[i2]);
            r3 = _mm_loadu_pd(&beta0[i2]);
            _mm_storeu_pd(&y_test[i2], _mm_sub_pd(r, r3));
          }

          for (i2 = nx; i2 < c_loop_ub; i2++) {
            y_test[i2] = y_test[i2] - beta0[i2];
          }

          st.site = &qb_emlrtRSI;
          b_tuning_matrix[t] -= coder::sum(st, y_test);
        } else {
          st.site = &qb_emlrtRSI;
          binary_expand_op(st, b_tuning_matrix, t, qb_emlrtRSI, y_test, beta0);
        }

        // tuning_result(:,t,u) = [beta_part;gamma_part];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    if (!muDoubleScalarIsNaN(b_tuning_matrix[0])) {
      vectorUB = 1;
    } else {
      vectorUB = 0;
      vectorUB_tmp = 2;
      exitg1 = false;
      while ((!exitg1) && (vectorUB_tmp < 4)) {
        if (!muDoubleScalarIsNaN(b_tuning_matrix[vectorUB_tmp - 1])) {
          vectorUB = vectorUB_tmp;
          exitg1 = true;
        } else {
          vectorUB_tmp++;
        }
      }
    }

    if (vectorUB == 0) {
      vectorUB = 1;
    } else {
      guiyi = b_tuning_matrix[vectorUB - 1];
      i2 = vectorUB + 1;
      for (vectorUB_tmp = i2; vectorUB_tmp < 4; vectorUB_tmp++) {
        a = b_tuning_matrix[vectorUB_tmp - 1];
        if (guiyi > a) {
          guiyi = a;
          vectorUB = vectorUB_tmp;
        }
      }
    }

    if (vectorUB != 3) {
      panduan = 1;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  if (if_fix == 0.0) {
    st.site = &rb_emlrtRSI;
    coder::linspace(st, tuning_start, tuning_end, tuning_number, tuning_choice);
    tuning_matrix.set_size(&fb_emlrtRTEI, sp, tuning_choice.size(1));
    c_loop_ub = tuning_choice.size(1);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      tuning_matrix[i2] = 0.0;
    }

    st.site = &sb_emlrtRSI;
    coder::eye(st, n, r1);
    b_beta_part.set_size(&gb_emlrtRTEI, sp, 1, beta_part.size(0));
    c_loop_ub = beta_part.size(0);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      b_beta_part[i2] = beta_part[i2];
    }

    st.site = &sb_emlrtRSI;
    coder::kron(st, r1, b_beta_part, beta_likelihood);
    st.site = &tb_emlrtRSI;
    coder::permute(st, x, r2);
    b_varargin_1 = row_size * n;
    st.site = &tb_emlrtRSI;
    nx = r2.size(0) * r2.size(1) * r2.size(2);
    b_st.site = &jf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, b_varargin_1);
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, col_size);
    maxdimlen = r2.size(0);
    if (r2.size(1) > r2.size(0)) {
      maxdimlen = r2.size(1);
    }

    if (r2.size(2) > maxdimlen) {
      maxdimlen = r2.size(2);
    }

    maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
    if (static_cast<int32_T>(b_varargin_1) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (static_cast<int32_T>(col_size) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    out = (static_cast<int32_T>(b_varargin_1) >= 0);
    if ((!out) || (static_cast<int32_T>(col_size) < 0)) {
      out = false;
    }

    if (!out) {
      emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (static_cast<int32_T>(b_varargin_1) * static_cast<int32_T>(col_size) !=
        nx) {
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    st.site = &ub_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &ub_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    if ((y.size(0) != beta0.size(0)) && ((y.size(0) != 1) && (beta0.size(0) != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(y.size(0), beta0.size(0), &dc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (y.size(0) == beta0.size(0)) {
      gamma0.set_size(&hb_emlrtRTEI, sp, y.size(0));
      c_loop_ub = y.size(0);
      nx = (y.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&beta0[i2]);
        _mm_storeu_pd(&gamma0[i2], _mm_mul_pd(_mm_loadu_pd(&y[i2]), r));
      }

      for (i2 = nx; i2 < c_loop_ub; i2++) {
        gamma0[i2] = y[i2] * beta0[i2];
      }
    } else {
      st.site = &vb_emlrtRSI;
      b_times(st, gamma0, y, beta0);
    }

    st.site = &vb_emlrtRSI;
    coder::b_exp(st, beta0);
    c_loop_ub = beta0.size(0);
    nx = (beta0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i2 = 0; i2 <= vectorUB; i2 += 2) {
      r = _mm_loadu_pd(&beta0[i2]);
      _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
    }

    for (i2 = nx; i2 < c_loop_ub; i2++) {
      beta0[i2] = beta0[i2] + 1.0;
    }

    st.site = &vb_emlrtRSI;
    coder::b_log(st, beta0);
    if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
         (beta0.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0), &dc_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (tuning_choice.size(1) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, tuning_choice.size(1), &o_emlrtBCI,
        (emlrtConstCTX)sp);
    }

    if (gamma0.size(0) == beta0.size(0)) {
      beta0.set_size(&hb_emlrtRTEI, sp, gamma0.size(0));
      c_loop_ub = gamma0.size(0);
      nx = (gamma0.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&gamma0[i2]);
        r3 = _mm_loadu_pd(&beta0[i2]);
        _mm_storeu_pd(&beta0[i2], _mm_sub_pd(r, r3));
      }

      for (i2 = nx; i2 < c_loop_ub; i2++) {
        beta0[i2] = gamma0[i2] - beta0[i2];
      }

      st.site = &vb_emlrtRSI;
      coder::sum(st, beta0);
    } else {
      st.site = &vb_emlrtRSI;
      binary_expand_op(st, vb_emlrtRSI, gamma0, beta0);
    }

    st.site = &wb_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    st.site = &wb_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    if (!(row_size >= 0.0)) {
      emlrtNonNegativeCheckR2012b(row_size, &q_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (row_size != static_cast<int32_T>(muDoubleScalarFloor(row_size))) {
      emlrtIntegerCheckR2012b(row_size, &p_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (!(col_size >= 0.0)) {
      emlrtNonNegativeCheckR2012b(col_size, &o_emlrtDCI, (emlrtConstCTX)sp);
    }

    if (col_size != static_cast<int32_T>(muDoubleScalarFloor(col_size))) {
      emlrtIntegerCheckR2012b(col_size, &n_emlrtDCI, (emlrtConstCTX)sp);
    }

    st.site = &xb_emlrtRSI;
    nx = x.size(0) * x.size(1) * x.size(2);
    b_st.site = &jf_emlrtRSI;
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, varargin_1);
    c_st.site = &kf_emlrtRSI;
    coder::internal::assertValidSizeArg(c_st, n);
    maxdimlen = x.size(0);
    if (x.size(1) > x.size(0)) {
      maxdimlen = x.size(1);
    }

    if (x.size(2) > maxdimlen) {
      maxdimlen = x.size(2);
    }

    maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
    if (static_cast<int32_T>(varargin_1) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    out = (static_cast<int32_T>(varargin_1) >= 0);
    if ((!out) || (static_cast<int32_T>(n) < 0)) {
      out = false;
    }

    if (!out) {
      emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (static_cast<int32_T>(varargin_1) * static_cast<int32_T>(n) != nx) {
      emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    i2 = tuning_choice.size(1);
    for (int32_T t{0}; t < i2; t++) {
      if (t + 1 > tuning_choice.size(1)) {
        emlrtDynamicBoundsCheckR2012b(t + 1, 1, tuning_choice.size(1),
          &mb_emlrtBCI, (emlrtConstCTX)sp);
      }

      lambda_tuning = tuning_choice[t];
      batch_size = muDoubleScalarFloor(n / cv_number);
      i3 = static_cast<int32_T>(cv_number);
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, cv_number, mxDOUBLE_CLASS,
        static_cast<int32_T>(cv_number), &f_emlrtRTEI, (emlrtConstCTX)sp);
      for (int32_T u{0}; u < i3; u++) {
        if (static_cast<real_T>(u) + 1.0 == cv_number) {
          guiyi = ((static_cast<real_T>(u) + 1.0) - 1.0) * batch_size;
          n_test = n - guiyi;

          // n_batch为测试集样本数
          n_train = n - n_test;
          if (!(n >= 0.0)) {
            emlrtNonNegativeCheckR2012b(n, &tb_emlrtDCI, (emlrtConstCTX)sp);
          }

          a = static_cast<int32_T>(muDoubleScalarFloor(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &sb_emlrtDCI, (emlrtConstCTX)sp);
          }

          b_index.set_size(&ob_emlrtRTEI, sp, static_cast<int32_T>(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &sb_emlrtDCI, (emlrtConstCTX)sp);
          }

          maxdimlen = static_cast<int32_T>(n);
          for (i4 = 0; i4 < maxdimlen; i4++) {
            b_index[i4] = true;
          }

          if (guiyi + 1.0 > static_cast<int32_T>(n)) {
            i4 = 0;
            i5 = 0;
          } else {
            if (guiyi + 1.0 != static_cast<int32_T>(guiyi + 1.0)) {
              emlrtIntegerCheckR2012b(guiyi + 1.0, &k_emlrtDCI, (emlrtConstCTX)
                sp);
            }

            if ((static_cast<int32_T>(guiyi + 1.0) < 1) || (static_cast<int32_T>
                 (guiyi + 1.0) > static_cast<int32_T>(n))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi + 1.0), 1,
                static_cast<int32_T>(n), &j_emlrtBCI, (emlrtConstCTX)sp);
            }

            i4 = static_cast<int32_T>(guiyi + 1.0) - 1;
            if (static_cast<int32_T>(n) < 1) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                static_cast<int32_T>(n), &i_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(n);
          }

          c_loop_ub = i5 - i4;
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_index[i4 + i5] = false;
          }

          if (guiyi + 1.0 > x.size(2)) {
            i4 = 0;
            i5 = 0;
          } else {
            if (guiyi + 1.0 != static_cast<int32_T>(guiyi + 1.0)) {
              emlrtIntegerCheckR2012b(guiyi + 1.0, &m_emlrtDCI, (emlrtConstCTX)
                sp);
            }

            if ((static_cast<int32_T>(guiyi + 1.0) < 1) || (static_cast<int32_T>
                 (guiyi + 1.0) > x.size(2))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi + 1.0), 1,
                x.size(2), &n_emlrtBCI, (emlrtConstCTX)sp);
            }

            i4 = static_cast<int32_T>(guiyi + 1.0) - 1;
            if (x.size(2) < 1) {
              emlrtDynamicBoundsCheckR2012b(x.size(2), 1, x.size(2), &m_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            i5 = x.size(2);
          }

          c_loop_ub = i5 - i4;
          x_test.set_size(&pb_emlrtRTEI, sp, x.size(0), x.size(1), c_loop_ub);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            nx = x.size(1);
            for (int32_T i6{0}; i6 < nx; i6++) {
              maxdimlen = x.size(0);
              for (vectorUB = 0; vectorUB < maxdimlen; vectorUB++) {
                x_test[(vectorUB + x_test.size(0) * i6) + x_test.size(0) *
                  x_test.size(1) * i5] = x[(vectorUB + x.size(0) * i6) + x.size
                  (0) * x.size(1) * (i4 + i5)];
              }
            }
          }

          if (guiyi + 1.0 > y.size(0)) {
            i4 = 0;
            i5 = 0;
          } else {
            if (guiyi + 1.0 != static_cast<int32_T>(guiyi + 1.0)) {
              emlrtIntegerCheckR2012b(guiyi + 1.0, &l_emlrtDCI, (emlrtConstCTX)
                sp);
            }

            if ((static_cast<int32_T>(guiyi + 1.0) < 1) || (static_cast<int32_T>
                 (guiyi + 1.0) > y.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi + 1.0), 1,
                y.size(0), &l_emlrtBCI, (emlrtConstCTX)sp);
            }

            i4 = static_cast<int32_T>(guiyi + 1.0) - 1;
            if (y.size(0) < 1) {
              emlrtDynamicBoundsCheckR2012b(y.size(0), 1, y.size(0), &k_emlrtBCI,
                (emlrtConstCTX)sp);
            }

            i5 = y.size(0);
          }

          c_varargin_1[0] = 1;
          varargin_1_tmp = i5 - i4;
          c_varargin_1[1] = varargin_1_tmp;
          st.site = &yb_emlrtRSI;
          coder::internal::indexShapeCheck(st, y.size(0), c_varargin_1);
          y_test.set_size(&qb_emlrtRTEI, sp, varargin_1_tmp);
          for (i5 = 0; i5 < varargin_1_tmp; i5++) {
            y_test[i5] = y[i4 + i5];
          }

          vectorUB = b_index.size(0) - 1;
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              maxdimlen++;
            }
          }

          r6.set_size(&lb_emlrtRTEI, sp, maxdimlen);
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              r6[maxdimlen] = nx;
              maxdimlen++;
            }
          }

          c_loop_ub = r6.size(0);
          b_x_train.set_size(&rb_emlrtRTEI, sp, x.size(0), x.size(1), r6.size(0));
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            nx = x.size(1);
            for (i5 = 0; i5 < nx; i5++) {
              maxdimlen = x.size(0);
              for (int32_T i6{0}; i6 < maxdimlen; i6++) {
                if (r6[i4] > x.size(2) - 1) {
                  emlrtDynamicBoundsCheckR2012b(r6[i4], 0, x.size(2) - 1,
                    &pb_emlrtBCI, (emlrtConstCTX)sp);
                }

                b_x_train[(i6 + b_x_train.size(0) * i5) + b_x_train.size(0) *
                  b_x_train.size(1) * i4] = x[(i6 + x.size(0) * i5) + x.size(0) *
                  x.size(1) * r6[i4]];
              }
            }
          }

          c_loop_ub = r6.size(0);
          y_train.set_size(&sb_emlrtRTEI, sp, r6.size(0));
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            if (r6[i4] > y.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(r6[i4], 0, y.size(0) - 1,
                &rb_emlrtBCI, (emlrtConstCTX)sp);
            }

            y_train[i4] = y[r6[i4]];
          }
        } else {
          n_test = batch_size;

          // n_batch为测试集样本数
          n_train = n - batch_size;
          if (!(n >= 0.0)) {
            emlrtNonNegativeCheckR2012b(n, &rb_emlrtDCI, (emlrtConstCTX)sp);
          }

          a = static_cast<int32_T>(muDoubleScalarFloor(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &qb_emlrtDCI, (emlrtConstCTX)sp);
          }

          b_index.set_size(&ib_emlrtRTEI, sp, static_cast<int32_T>(n));
          if (n != a) {
            emlrtIntegerCheckR2012b(n, &qb_emlrtDCI, (emlrtConstCTX)sp);
          }

          c_loop_ub = static_cast<int32_T>(n);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            b_index[i4] = true;
          }

          a = ((static_cast<real_T>(u) + 1.0) - 1.0) * batch_size + 1.0;
          guiyi = (static_cast<real_T>(u) + 1.0) * batch_size;
          if (a > guiyi) {
            i4 = 0;
            i5 = 0;
          } else {
            if (a != static_cast<int32_T>(a)) {
              emlrtIntegerCheckR2012b(a, &f_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
                 static_cast<int32_T>(n))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1,
                static_cast<int32_T>(n), &d_emlrtBCI, (emlrtConstCTX)sp);
            }

            i4 = static_cast<int32_T>(a) - 1;
            if (guiyi != static_cast<int32_T>(guiyi)) {
              emlrtIntegerCheckR2012b(guiyi, &e_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(guiyi) < 1) || (static_cast<int32_T>(guiyi)
                 > static_cast<int32_T>(n))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi), 1,
                static_cast<int32_T>(n), &c_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(guiyi);
          }

          c_loop_ub = i5 - i4;
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_index[i4 + i5] = false;
          }

          if (a > guiyi) {
            i4 = 0;
            i5 = 0;
          } else {
            if (a != static_cast<int32_T>(a)) {
              emlrtIntegerCheckR2012b(a, &j_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
                 x.size(2))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1, x.size(2),
                &h_emlrtBCI, (emlrtConstCTX)sp);
            }

            i4 = static_cast<int32_T>(a) - 1;
            if (guiyi != static_cast<int32_T>(guiyi)) {
              emlrtIntegerCheckR2012b(guiyi, &i_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(guiyi) < 1) || (static_cast<int32_T>(guiyi)
                 > x.size(2))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi), 1,
                x.size(2), &g_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(guiyi);
          }

          c_loop_ub = i5 - i4;
          x_test.set_size(&jb_emlrtRTEI, sp, x.size(0), x.size(1), c_loop_ub);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            nx = x.size(1);
            for (int32_T i6{0}; i6 < nx; i6++) {
              maxdimlen = x.size(0);
              for (vectorUB = 0; vectorUB < maxdimlen; vectorUB++) {
                x_test[(vectorUB + x_test.size(0) * i6) + x_test.size(0) *
                  x_test.size(1) * i5] = x[(vectorUB + x.size(0) * i6) + x.size
                  (0) * x.size(1) * (i4 + i5)];
              }
            }
          }

          if (a > guiyi) {
            i4 = 0;
            i5 = 0;
          } else {
            if (a != static_cast<int32_T>(a)) {
              emlrtIntegerCheckR2012b(a, &h_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(a) < 1) || (static_cast<int32_T>(a) >
                 y.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a), 1, y.size(0),
                &f_emlrtBCI, (emlrtConstCTX)sp);
            }

            i4 = static_cast<int32_T>(a) - 1;
            if (guiyi != static_cast<int32_T>(guiyi)) {
              emlrtIntegerCheckR2012b(guiyi, &g_emlrtDCI, (emlrtConstCTX)sp);
            }

            if ((static_cast<int32_T>(guiyi) < 1) || (static_cast<int32_T>(guiyi)
                 > y.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(guiyi), 1,
                y.size(0), &e_emlrtBCI, (emlrtConstCTX)sp);
            }

            i5 = static_cast<int32_T>(guiyi);
          }

          c_varargin_1[0] = 1;
          varargin_1_tmp = i5 - i4;
          c_varargin_1[1] = varargin_1_tmp;
          st.site = &ac_emlrtRSI;
          coder::internal::indexShapeCheck(st, y.size(0), c_varargin_1);
          y_test.set_size(&kb_emlrtRTEI, sp, varargin_1_tmp);
          for (i5 = 0; i5 < varargin_1_tmp; i5++) {
            y_test[i5] = y[i4 + i5];
          }

          vectorUB = b_index.size(0) - 1;
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              maxdimlen++;
            }
          }

          r7.set_size(&lb_emlrtRTEI, sp, maxdimlen);
          maxdimlen = 0;
          for (nx = 0; nx <= vectorUB; nx++) {
            if (b_index[nx]) {
              r7[maxdimlen] = nx;
              maxdimlen++;
            }
          }

          c_loop_ub = r7.size(0);
          b_x_train.set_size(&mb_emlrtRTEI, sp, x.size(0), x.size(1), r7.size(0));
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            nx = x.size(1);
            for (i5 = 0; i5 < nx; i5++) {
              maxdimlen = x.size(0);
              for (int32_T i6{0}; i6 < maxdimlen; i6++) {
                if (r7[i4] > x.size(2) - 1) {
                  emlrtDynamicBoundsCheckR2012b(r7[i4], 0, x.size(2) - 1,
                    &tb_emlrtBCI, (emlrtConstCTX)sp);
                }

                b_x_train[(i6 + b_x_train.size(0) * i5) + b_x_train.size(0) *
                  b_x_train.size(1) * i4] = x[(i6 + x.size(0) * i5) + x.size(0) *
                  x.size(1) * r7[i4]];
              }
            }
          }

          c_loop_ub = r7.size(0);
          y_train.set_size(&nb_emlrtRTEI, sp, r7.size(0));
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            if (r7[i4] > y.size(0) - 1) {
              emlrtDynamicBoundsCheckR2012b(r7[i4], 0, y.size(0) - 1,
                &vb_emlrtBCI, (emlrtConstCTX)sp);
            }

            y_train[i4] = y[r7[i4]];
          }
        }

        beta_part.set_size(&tb_emlrtRTEI, sp, loop_ub);
        for (i4 = 0; i4 < loop_ub; i4++) {
          beta_part[i4] = coefficients0[i4];
        }

        gamma_part.set_size(&ub_emlrtRTEI, sp, b_loop_ub);
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          gamma_part[i4] = coefficients0[i1 + i4];
        }

        st.site = &bc_emlrtRSI;
        coder::eye(st, n_train, r1);
        b_beta_part.set_size(&lb_emlrtRTEI, sp, 1, loop_ub);
        for (i4 = 0; i4 < loop_ub; i4++) {
          b_beta_part[i4] = coefficients0[i4];
        }

        st.site = &bc_emlrtRSI;
        coder::kron(st, r1, b_beta_part, beta_likelihood);
        st.site = &cc_emlrtRSI;
        coder::permute(st, b_x_train, r2);
        b_varargin_1 = row_size * n_train;
        st.site = &cc_emlrtRSI;
        nx = r2.size(0) * r2.size(1) * r2.size(2);
        b_st.site = &jf_emlrtRSI;
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, b_varargin_1);
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, col_size);
        maxdimlen = r2.size(0);
        if (r2.size(1) > r2.size(0)) {
          maxdimlen = r2.size(1);
        }

        if (r2.size(2) > maxdimlen) {
          maxdimlen = r2.size(2);
        }

        maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
        if (static_cast<int32_T>(b_varargin_1) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        if (static_cast<int32_T>(col_size) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        out = (static_cast<int32_T>(b_varargin_1) >= 0);
        if (!out) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:checkDimCommon:nonnegativeSize",
            "MATLAB:checkDimCommon:nonnegativeSize", 0);
        }

        if (static_cast<int32_T>(b_varargin_1) * static_cast<int32_T>(col_size)
            != nx) {
          emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
            "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }

        st.site = &dc_emlrtRSI;
        c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
          beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
        c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
          b_pai_gamma);
        st.site = &dc_emlrtRSI;
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, b_pai_gamma, gamma0_part,
          b_pai_gamma.size(1), b_loop_ub);
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma0_part, beta0);
        if ((y_train.size(0) != beta0.size(0)) && ((y_train.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(y_train.size(0), beta0.size(0),
            &cc_emlrtECI, (emlrtConstCTX)sp);
        }

        if (y_train.size(0) == beta0.size(0)) {
          gamma0.set_size(&vb_emlrtRTEI, sp, y_train.size(0));
          c_loop_ub = y_train.size(0);
          nx = (y_train.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&y_train[i4]);
            r3 = _mm_loadu_pd(&beta0[i4]);
            _mm_storeu_pd(&gamma0[i4], _mm_mul_pd(r, r3));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            gamma0[i4] = y_train[i4] * beta0[i4];
          }
        } else {
          st.site = &ec_emlrtRSI;
          times(st, gamma0, y_train, beta0);
        }

        st.site = &ec_emlrtRSI;
        coder::b_exp(st, beta0);
        c_loop_ub = beta0.size(0);
        nx = (beta0.size(0) / 2) << 1;
        vectorUB = nx - 2;
        for (i4 = 0; i4 <= vectorUB; i4 += 2) {
          r = _mm_loadu_pd(&beta0[i4]);
          _mm_storeu_pd(&beta0[i4], _mm_add_pd(r, _mm_set1_pd(1.0)));
        }

        for (i4 = nx; i4 < c_loop_ub; i4++) {
          beta0[i4] = beta0[i4] + 1.0;
        }

        st.site = &ec_emlrtRSI;
        coder::b_log(st, beta0);
        if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0),
            &cc_emlrtECI, (emlrtConstCTX)sp);
        }

        st.site = &fc_emlrtRSI;
        guiyi = coder::b_norm(beta0_part);
        b_st.site = &le_emlrtRSI;
        st.site = &fc_emlrtRSI;
        a = coder::b_norm(gamma0_part);
        b_st.site = &le_emlrtRSI;
        if (gamma0.size(0) == beta0.size(0)) {
          beta0.set_size(&vb_emlrtRTEI, sp, gamma0.size(0));
          c_loop_ub = gamma0.size(0);
          nx = (gamma0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&gamma0[i4]);
            r3 = _mm_loadu_pd(&beta0[i4]);
            _mm_storeu_pd(&beta0[i4], _mm_sub_pd(r, r3));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            beta0[i4] = gamma0[i4] - beta0[i4];
          }

          st.site = &ec_emlrtRSI;
          log_likelihood0 = -coder::sum(st, beta0) + 0.5 * lambda_tuning *
            (guiyi * guiyi + a * a);
        } else {
          st.site = &ec_emlrtRSI;
          log_likelihood0 = binary_expand_op(st, ec_emlrtRSI, gamma0, beta0,
            lambda_tuning, guiyi, a);
        }

        *diff_loglikelihood = 1.0;
        st.site = &gc_emlrtRSI;
        nx = b_x_train.size(0) * b_x_train.size(1) * b_x_train.size(2);
        b_st.site = &jf_emlrtRSI;
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, varargin_1);
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, n_train);
        maxdimlen = b_x_train.size(0);
        if (b_x_train.size(1) > b_x_train.size(0)) {
          maxdimlen = b_x_train.size(1);
        }

        if (b_x_train.size(2) > maxdimlen) {
          maxdimlen = b_x_train.size(2);
        }

        maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
        if (static_cast<int32_T>(varargin_1) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        if (static_cast<int32_T>(n_train) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        out = (static_cast<int32_T>(varargin_1) >= 0);
        if ((!out) || (static_cast<int32_T>(n_train) < 0)) {
          out = false;
        }

        if (!out) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:checkDimCommon:nonnegativeSize",
            "MATLAB:checkDimCommon:nonnegativeSize", 0);
        }

        if (static_cast<int32_T>(varargin_1) * static_cast<int32_T>(n_train) !=
            nx) {
          emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
            "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }

        *iter_initial_in = 0.0;
        while ((*diff_loglikelihood > eps_initial) && (*iter_initial_in <=
                iter_max_initial_in)) {
          //  beta_likelihood_train = kron(eye(n_train),beta_part');
          //  eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
          //  eta_likelihood_mat_train = diag((1 + exp(beta_likelihood_train*x_likelihood_train*gamma_part)).^(-1));
          //  eta_likelihood_mat2_train = diag(sqrt(exp(beta_likelihood_train*x_likelihood_train*gamma_part)));
          //
          //  grdient_sum_train = [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]*...
          //      [x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)]...
          //      +lambda_tuning*[beta_part;gamma_part];
          //
          //  Hessin_sum_train = [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]*...
          //      (x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))'*...
          //      [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]'+...
          //      [zeros(row_size,col_size),...
          //      reshape([x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)],row_size,col_size);...
          //      reshape([x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)],row_size,col_size)',...
          //      zeros(col_size,row_size)]+...
          //      [lambda_tuning*eye(row_size),zeros(row_size,col_size);zeros(col_size,row_size),lambda_tuning*eye(col_size)];
          //  newton_sum_train = pinv(Hessin_sum_train)*grdient_sum_train;
          //  z = min(eig(Hessin_sum_train));
          //  % % if z>0
          //  sumvec_train = [beta_part;gamma_part]-newton_sum_train;
          //  beta_part = sumvec_train(1:row_size);
          //  gamma_part = sumvec_train((row_size+1):end);
          //  guiyi = sign(gamma_part(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_part)/norm(beta_part)));
          //  gamma_part = gamma_part/guiyi;%拿出来了
          //  beta_part = beta_part*guiyi;%拿出来了
          //  beta_likelihood_train = kron(eye(n_train),beta_part');
          //  eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
          //  log_likelihood  = -sum(y_train.*eta_likelihood_train-log(1+exp(eta_likelihood_train)))+...
          //                      0.5*lambda_tuning*(norm(beta_part).^2+norm(gamma_part).^2);
          //  diff_loglikelihood = abs(log_likelihood-log_likelihood0)
          //  log_likelihood0 = log_likelihood
          //  iter_initial_in = iter_initial_in + 1;
          //  beta_part
          //  disp(1)
          //  % % else
          st.site = &hc_emlrtRSI;
          coder::eye(st, n_train, r1);
          b_beta_part.set_size(&xb_emlrtRTEI, sp, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            b_beta_part[i4] = beta_part[i4];
          }

          st.site = &hc_emlrtRSI;
          coder::kron(st, r1, b_beta_part, beta_likelihood);
          st.site = &ic_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &ic_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part,
            rh_emlrtRSI);
          st.site = &jc_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &jc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &jc_emlrtRSI;
          b_st.site = &jc_emlrtRSI;
          coder::b_exp(b_st, beta0);
          c_loop_ub = beta0.size(0);
          nx = (beta0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&beta0[i4]);
            _mm_storeu_pd(&beta0[i4], _mm_add_pd(r, _mm_set1_pd(1.0)));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            beta0[i4] = beta0[i4] + 1.0;
          }

          b_st.site = &le_emlrtRSI;
          C2.set_size(&v_emlrtRTEI, sp, beta0.size(0));
          c_loop_ub = beta0.size(0);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            d_varargin_1 = beta0[i4];
            C2[i4] = 1.0 / d_varargin_1;
          }

          st.site = &jc_emlrtRSI;
          coder::diag(st, C2, eta_likelihood_mat_train);
          st.site = &kc_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &kc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &kc_emlrtRSI;
          coder::b_exp(st, beta0);
          st.site = &kc_emlrtRSI;
          coder::b_sqrt(st, beta0);
          st.site = &kc_emlrtRSI;
          coder::diag(st, beta0, beta_likelihood);
          st.site = &lc_emlrtRSI;
          b_st.site = &le_emlrtRSI;
          b.set_size(&yb_emlrtRTEI, &b_st, beta_likelihood.size(0),
                     beta_likelihood.size(1));
          maxdimlen = beta_likelihood.size(0) * beta_likelihood.size(1);
          for (i4 = 0; i4 < maxdimlen; i4++) {
            d_varargin_1 = beta_likelihood[i4];
            b[i4] = d_varargin_1 * d_varargin_1;
          }

          if ((b.size(0) != eta_likelihood_mat_train.size(0)) && ((b.size(0) !=
                1) && (eta_likelihood_mat_train.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(0), eta_likelihood_mat_train.size
              (0), &bc_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(1) != eta_likelihood_mat_train.size(1)) && ((b.size(1) !=
                1) && (eta_likelihood_mat_train.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(1), eta_likelihood_mat_train.size
              (1), &ac_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(0) == eta_likelihood_mat_train.size(0)) && (b.size(1) ==
               eta_likelihood_mat_train.size(1))) {
            nx = (maxdimlen / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&b[i4]);
              r3 = _mm_loadu_pd(&eta_likelihood_mat_train[i4]);
              _mm_storeu_pd(&b[i4], _mm_mul_pd(r, r3));
            }

            for (i4 = nx; i4 < maxdimlen; i4++) {
              b[i4] = b[i4] * eta_likelihood_mat_train[i4];
            }
          } else {
            st.site = &lc_emlrtRSI;
            times(st, b, eta_likelihood_mat_train);
          }

          st.site = &lc_emlrtRSI;
          coder::diag(st, y_train, r1);
          if ((b.size(0) != r1.size(0)) && ((b.size(0) != 1) && (r1.size(0) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(0), r1.size(0), &yb_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if ((b.size(1) != r1.size(1)) && ((b.size(1) != 1) && (r1.size(1) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(1), r1.size(1), &xb_emlrtECI,
              (emlrtConstCTX)sp);
          }

          st.site = &lc_emlrtRSI;
          b_st.site = &lc_emlrtRSI;
          coder::eye(b_st, row_size, r8);
          b_beta_part.set_size(&ac_emlrtRTEI, &st, 1, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            b_beta_part[i4] = gamma_part[i4];
          }

          b_st.site = &lc_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          varargin_1_tmp = static_cast<int32_T>(n_train);
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, x_train, b_a.size(1),
            static_cast<int32_T>(varargin_1));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, x_train, b_pai_gamma);
          st.site = &lc_emlrtRSI;
          if ((b.size(0) == r1.size(0)) && (b.size(1) == r1.size(1))) {
            c_loop_ub = b.size(0) * b.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&b[i4]);
              r3 = _mm_loadu_pd(&r1[i4]);
              _mm_storeu_pd(&b[i4], _mm_sub_pd(r, r3));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              b[i4] = b[i4] - r1[i4];
            }
          } else {
            b_st.site = &lc_emlrtRSI;
            minus(b_st, b, r1);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, b, b_pai_gamma.size(1),
            b.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, b, b_y);
          st.site = &lc_emlrtRSI;
          if (!(n_train >= 0.0)) {
            emlrtNonNegativeCheckR2012b(n_train, &ac_emlrtDCI, &st);
          }

          i4 = static_cast<int32_T>(muDoubleScalarFloor(n_train));
          if (n_train != i4) {
            emlrtIntegerCheckR2012b(n_train, &yb_emlrtDCI, &st);
          }

          beta0.set_size(&bc_emlrtRTEI, &st, static_cast<int32_T>(n_train));
          if (n_train != i4) {
            emlrtIntegerCheckR2012b(n_train, &yb_emlrtDCI, &st);
          }

          for (i5 = 0; i5 < varargin_1_tmp; i5++) {
            beta0[i5] = 1.0;
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_y, beta0, b_y.size(1), static_cast<
            int32_T>(n_train));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_y, beta0, C2);
          gamma0.set_size(&cc_emlrtRTEI, sp, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          maxdimlen = (beta_part.size(0) / 2) << 1;
          vectorUB_tmp = maxdimlen - 2;
          for (i5 = 0; i5 <= vectorUB_tmp; i5 += 2) {
            r = _mm_loadu_pd(&beta_part[i5]);
            _mm_storeu_pd(&gamma0[i5], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i5 = maxdimlen; i5 < c_loop_ub; i5++) {
            gamma0[i5] = lambda_tuning * beta_part[i5];
          }

          if ((C2.size(0) != gamma0.size(0)) && ((C2.size(0) != 1) &&
               (gamma0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(C2.size(0), gamma0.size(0), &wb_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if (C2.size(0) == gamma0.size(0)) {
            c_loop_ub = C2.size(0);
            nx = (C2.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&C2[i5]);
              r3 = _mm_loadu_pd(&gamma0[i5]);
              _mm_storeu_pd(&C2[i5], _mm_add_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              C2[i5] = C2[i5] + gamma0[i5];
            }
          } else {
            st.site = &lc_emlrtRSI;
            plus(st, C2, gamma0);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &vb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &ub_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &tb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &sb_emlrtECI, (emlrtConstCTX)sp);
          }

          st.site = &mc_emlrtRSI;
          if ((eta_likelihood_mat_train.size(0) == beta_likelihood.size(0)) &&
              (eta_likelihood_mat_train.size(1) == beta_likelihood.size(1))) {
            c_loop_ub = eta_likelihood_mat_train.size(0) *
              eta_likelihood_mat_train.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&eta_likelihood_mat_train[i5]);
              r3 = _mm_loadu_pd(&beta_likelihood[i5]);
              _mm_storeu_pd(&eta_likelihood_mat_train[i5], _mm_mul_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              eta_likelihood_mat_train[i5] = eta_likelihood_mat_train[i5] *
                beta_likelihood[i5];
            }
          } else {
            b_st.site = &mc_emlrtRSI;
            times(b_st, eta_likelihood_mat_train, beta_likelihood);
          }

          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            r1);
          st.site = &mc_emlrtRSI;
          coder::eye(st, row_size, r8);
          b_beta_part.set_size(&dc_emlrtRTEI, sp, 1, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = gamma_part[i5];
          }

          st.site = &mc_emlrtRSI;
          coder::b_kron(st, b_beta_part, r8, b);
          st.site = &mc_emlrtRSI;
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            b_pai_gamma);
          st.site = &mc_emlrtRSI;
          b_st.site = &mc_emlrtRSI;
          coder::eye(b_st, row_size, r8);
          b_beta_part.set_size(&ec_emlrtRTEI, &st, 1, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = gamma_part[i5];
          }

          b_st.site = &mc_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, b_pai_gamma, b_a.size(1),
            b_pai_gamma.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, b_pai_gamma, b_y);
          st.site = &mc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_y, r1, b_y.size(1), r1.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_y, r1, b_pai_gamma);
          st.site = &mc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, b, b_pai_gamma.size(1),
            b.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_pai_gamma, b, beta_likelihood);
          st.site = &nc_emlrtRSI;
          coder::eye(st, row_size, b);
          c_loop_ub = b.size(0) * b.size(1);
          nx = (c_loop_ub / 2) << 1;
          vectorUB = nx - 2;
          for (i5 = 0; i5 <= vectorUB; i5 += 2) {
            r = _mm_loadu_pd(&b[i5]);
            _mm_storeu_pd(&b[i5], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i5 = nx; i5 < c_loop_ub; i5++) {
            b[i5] = lambda_tuning * b[i5];
          }

          if ((beta_likelihood.size(0) != b.size(0)) && ((beta_likelihood.size(0)
                != 1) && (b.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(0), b.size(0),
              &rb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(1) != b.size(1)) && ((beta_likelihood.size(1)
                != 1) && (b.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(1), b.size(1),
              &qb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(0) == b.size(0)) && (beta_likelihood.size(1)
               == b.size(1))) {
            c_loop_ub = beta_likelihood.size(0) * beta_likelihood.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&beta_likelihood[i5]);
              r3 = _mm_loadu_pd(&b[i5]);
              _mm_storeu_pd(&beta_likelihood[i5], _mm_add_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              beta_likelihood[i5] = beta_likelihood[i5] + b[i5];
            }
          } else {
            st.site = &mc_emlrtRSI;
            plus(st, beta_likelihood, b);
          }

          st.site = &oc_emlrtRSI;
          b_st.site = &oc_emlrtRSI;
          if (beta_likelihood.size(0) < beta_likelihood.size(1)) {
            b_pai_gamma.set_size(&fc_emlrtRTEI, &b_st, beta_likelihood.size(1),
                                 beta_likelihood.size(0));
            c_loop_ub = beta_likelihood.size(0);
            for (i5 = 0; i5 < c_loop_ub; i5++) {
              nx = beta_likelihood.size(1);
              for (int32_T i6{0}; i6 < nx; i6++) {
                b_pai_gamma[i6 + b_pai_gamma.size(0) * i5] = beta_likelihood[i5
                  + beta_likelihood.size(0) * i6];
              }
            }

            c_st.site = &yf_emlrtRSI;
            coder::eml_pinv(c_st, b_pai_gamma, r1);
            b_a.set_size(&gc_emlrtRTEI, &b_st, r1.size(1), r1.size(0));
            c_loop_ub = r1.size(0);
            for (i5 = 0; i5 < c_loop_ub; i5++) {
              nx = r1.size(1);
              for (int32_T i6{0}; i6 < nx; i6++) {
                b_a[i6 + b_a.size(0) * i5] = r1[i5 + r1.size(0) * i6];
              }
            }
          } else {
            c_st.site = &ag_emlrtRSI;
            coder::eml_pinv(c_st, beta_likelihood, b_a);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, C2, b_a.size(1), C2.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, C2, beta0);
          a = coder::b_norm(beta0);
          if (a > 1.0) {
            c_loop_ub = beta0.size(0);
            nx = (beta0.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&beta0[i5]);
              _mm_storeu_pd(&beta0[i5], _mm_div_pd(r, _mm_set1_pd(a)));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              beta0[i5] = beta0[i5] / a;
            }
          }

          if ((beta_part.size(0) != beta0.size(0)) && ((beta_part.size(0) != 1) &&
               (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_part.size(0), beta0.size(0),
              &pb_emlrtECI, (emlrtConstCTX)sp);
          }

          if (beta_part.size(0) == beta0.size(0)) {
            c_loop_ub = beta_part.size(0);
            for (i5 = 0; i5 <= vectorUB_tmp; i5 += 2) {
              r = _mm_loadu_pd(&beta_part[i5]);
              r3 = _mm_loadu_pd(&beta0[i5]);
              _mm_storeu_pd(&beta_part[i5], _mm_sub_pd(r, r3));
            }

            for (i5 = maxdimlen; i5 < c_loop_ub; i5++) {
              beta_part[i5] = beta_part[i5] - beta0[i5];
            }
          } else {
            st.site = &jh_emlrtRSI;
            minus(st, beta_part, beta0);
          }

          st.site = &pc_emlrtRSI;
          coder::eye(st, n_train, r1);
          b_beta_part.set_size(&hc_emlrtRTEI, sp, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = beta_part[i5];
          }

          st.site = &pc_emlrtRSI;
          coder::kron(st, r1, b_beta_part, beta_likelihood);
          st.site = &qc_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &qc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part,
            uh_emlrtRSI);
          st.site = &rc_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &rc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &rc_emlrtRSI;
          b_st.site = &rc_emlrtRSI;
          coder::b_exp(b_st, beta0);
          c_loop_ub = beta0.size(0);
          nx = (beta0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i5 = 0; i5 <= vectorUB; i5 += 2) {
            r = _mm_loadu_pd(&beta0[i5]);
            _mm_storeu_pd(&beta0[i5], _mm_add_pd(r, _mm_set1_pd(1.0)));
          }

          for (i5 = nx; i5 < c_loop_ub; i5++) {
            beta0[i5] = beta0[i5] + 1.0;
          }

          b_st.site = &le_emlrtRSI;
          C2.set_size(&v_emlrtRTEI, sp, beta0.size(0));
          c_loop_ub = beta0.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            d_varargin_1 = beta0[i5];
            C2[i5] = 1.0 / d_varargin_1;
          }

          st.site = &rc_emlrtRSI;
          coder::diag(st, C2, eta_likelihood_mat_train);
          st.site = &sc_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &sc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          st.site = &sc_emlrtRSI;
          coder::b_exp(st, beta0);
          st.site = &sc_emlrtRSI;
          coder::b_sqrt(st, beta0);
          st.site = &sc_emlrtRSI;
          coder::diag(st, beta0, beta_likelihood);
          st.site = &tc_emlrtRSI;
          b_st.site = &le_emlrtRSI;
          b.set_size(&ic_emlrtRTEI, &b_st, beta_likelihood.size(0),
                     beta_likelihood.size(1));
          maxdimlen = beta_likelihood.size(0) * beta_likelihood.size(1);
          for (i5 = 0; i5 < maxdimlen; i5++) {
            d_varargin_1 = beta_likelihood[i5];
            b[i5] = d_varargin_1 * d_varargin_1;
          }

          if ((b.size(0) != eta_likelihood_mat_train.size(0)) && ((b.size(0) !=
                1) && (eta_likelihood_mat_train.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(0), eta_likelihood_mat_train.size
              (0), &ob_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(1) != eta_likelihood_mat_train.size(1)) && ((b.size(1) !=
                1) && (eta_likelihood_mat_train.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(b.size(1), eta_likelihood_mat_train.size
              (1), &nb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((b.size(0) == eta_likelihood_mat_train.size(0)) && (b.size(1) ==
               eta_likelihood_mat_train.size(1))) {
            nx = (maxdimlen / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&b[i5]);
              r3 = _mm_loadu_pd(&eta_likelihood_mat_train[i5]);
              _mm_storeu_pd(&b[i5], _mm_mul_pd(r, r3));
            }

            for (i5 = nx; i5 < maxdimlen; i5++) {
              b[i5] = b[i5] * eta_likelihood_mat_train[i5];
            }
          } else {
            st.site = &tc_emlrtRSI;
            times(st, b, eta_likelihood_mat_train);
          }

          st.site = &tc_emlrtRSI;
          coder::diag(st, y_train, r1);
          if ((b.size(0) != r1.size(0)) && ((b.size(0) != 1) && (r1.size(0) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(0), r1.size(0), &mb_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if ((b.size(1) != r1.size(1)) && ((b.size(1) != 1) && (r1.size(1) != 1)))
          {
            emlrtDimSizeImpxCheckR2021b(b.size(1), r1.size(1), &lb_emlrtECI,
              (emlrtConstCTX)sp);
          }

          st.site = &tc_emlrtRSI;
          b_st.site = &tc_emlrtRSI;
          coder::eye(b_st, col_size, r8);
          b_beta_part.set_size(&jc_emlrtRTEI, &st, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i5 = 0; i5 < c_loop_ub; i5++) {
            b_beta_part[i5] = beta_part[i5];
          }

          b_st.site = &tc_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1),
            pai_gamma.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, b_pai_gamma);
          st.site = &tc_emlrtRSI;
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, x_train,
            b_pai_gamma.size(1), static_cast<int32_T>(varargin_1));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, x_train, b_y);
          st.site = &tc_emlrtRSI;
          if ((b.size(0) == r1.size(0)) && (b.size(1) == r1.size(1))) {
            c_loop_ub = b.size(0) * b.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i5 = 0; i5 <= vectorUB; i5 += 2) {
              r = _mm_loadu_pd(&b[i5]);
              r3 = _mm_loadu_pd(&r1[i5]);
              _mm_storeu_pd(&b[i5], _mm_sub_pd(r, r3));
            }

            for (i5 = nx; i5 < c_loop_ub; i5++) {
              b[i5] = b[i5] - r1[i5];
            }
          } else {
            b_st.site = &tc_emlrtRSI;
            minus(b_st, b, r1);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_y, b, b_y.size(1), b.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_y, b, b_pai_gamma);
          st.site = &tc_emlrtRSI;
          if (static_cast<int32_T>(n_train) != i4) {
            emlrtIntegerCheckR2012b(n_train, &cc_emlrtDCI, &st);
          }

          beta0.set_size(&kc_emlrtRTEI, &st, static_cast<int32_T>(n_train));
          if (static_cast<int32_T>(n_train) != i4) {
            emlrtIntegerCheckR2012b(n_train, &cc_emlrtDCI, &st);
          }

          for (i4 = 0; i4 < varargin_1_tmp; i4++) {
            beta0[i4] = 1.0;
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, beta0, b_pai_gamma.size
            (1), static_cast<int32_T>(n_train));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, beta0, C2);
          gamma0.set_size(&lc_emlrtRTEI, sp, gamma_part.size(0));
          c_loop_ub = gamma_part.size(0);
          maxdimlen = (gamma_part.size(0) / 2) << 1;
          vectorUB_tmp = maxdimlen - 2;
          for (i4 = 0; i4 <= vectorUB_tmp; i4 += 2) {
            r = _mm_loadu_pd(&gamma_part[i4]);
            _mm_storeu_pd(&gamma0[i4], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i4 = maxdimlen; i4 < c_loop_ub; i4++) {
            gamma0[i4] = lambda_tuning * gamma_part[i4];
          }

          if ((C2.size(0) != gamma0.size(0)) && ((C2.size(0) != 1) &&
               (gamma0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(C2.size(0), gamma0.size(0), &kb_emlrtECI,
              (emlrtConstCTX)sp);
          }

          if (C2.size(0) == gamma0.size(0)) {
            c_loop_ub = C2.size(0);
            nx = (C2.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&C2[i4]);
              r3 = _mm_loadu_pd(&gamma0[i4]);
              _mm_storeu_pd(&C2[i4], _mm_add_pd(r, r3));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              C2[i4] = C2[i4] + gamma0[i4];
            }
          } else {
            st.site = &tc_emlrtRSI;
            plus(st, C2, gamma0);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &jb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &ib_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
              ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size
                (0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
              beta_likelihood.size(0), &hb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
              ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size
                (1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
              beta_likelihood.size(1), &gb_emlrtECI, (emlrtConstCTX)sp);
          }

          st.site = &uc_emlrtRSI;
          if ((eta_likelihood_mat_train.size(0) == beta_likelihood.size(0)) &&
              (eta_likelihood_mat_train.size(1) == beta_likelihood.size(1))) {
            c_loop_ub = eta_likelihood_mat_train.size(0) *
              eta_likelihood_mat_train.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&eta_likelihood_mat_train[i4]);
              r3 = _mm_loadu_pd(&beta_likelihood[i4]);
              _mm_storeu_pd(&eta_likelihood_mat_train[i4], _mm_mul_pd(r, r3));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              eta_likelihood_mat_train[i4] = eta_likelihood_mat_train[i4] *
                beta_likelihood[i4];
            }
          } else {
            b_st.site = &uc_emlrtRSI;
            times(b_st, eta_likelihood_mat_train, beta_likelihood);
          }

          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            r1);
          st.site = &uc_emlrtRSI;
          b_st.site = &uc_emlrtRSI;
          coder::eye(b_st, col_size, r8);
          b_beta_part.set_size(&mc_emlrtRTEI, &st, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            b_beta_part[i4] = beta_part[i4];
          }

          b_st.site = &uc_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, r8, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1),
            pai_gamma.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, r8);
          st.site = &uc_emlrtRSI;
          b_st.site = &uc_emlrtRSI;
          coder::eye(b_st, col_size, b);
          b_beta_part.set_size(&nc_emlrtRTEI, &st, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            b_beta_part[i4] = beta_part[i4];
          }

          b_st.site = &uc_emlrtRSI;
          coder::b_kron(b_st, b_beta_part, b, b_a);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1),
            pai_gamma.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, b_pai_gamma);
          st.site = &uc_emlrtRSI;
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
            static_cast<int32_T>(n_train), eta_likelihood_mat_train.size(0));
          c_varargin_1[1] = static_cast<int32_T>(n_train);
          x_train = b_x_train.reshape(i, c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
            b_y);
          st.site = &uc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, b_y, b_pai_gamma.size(1),
            b_y.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, b_y, beta_likelihood);
          st.site = &uc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, r1,
            beta_likelihood.size(1), r1.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, beta_likelihood, r1, b_pai_gamma);
          st.site = &uc_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, r8, b_pai_gamma.size(1),
            r8.size(1));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::b_mtimes(b_st, b_pai_gamma, r8, beta_likelihood);
          st.site = &vc_emlrtRSI;
          coder::eye(st, col_size, b);
          c_loop_ub = b.size(0) * b.size(1);
          nx = (c_loop_ub / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&b[i4]);
            _mm_storeu_pd(&b[i4], _mm_mul_pd(_mm_set1_pd(lambda_tuning), r));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            b[i4] = lambda_tuning * b[i4];
          }

          if ((beta_likelihood.size(0) != b.size(0)) && ((beta_likelihood.size(0)
                != 1) && (b.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(0), b.size(0),
              &fb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(1) != b.size(1)) && ((beta_likelihood.size(1)
                != 1) && (b.size(1) != 1))) {
            emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(1), b.size(1),
              &eb_emlrtECI, (emlrtConstCTX)sp);
          }

          if ((beta_likelihood.size(0) == b.size(0)) && (beta_likelihood.size(1)
               == b.size(1))) {
            c_loop_ub = beta_likelihood.size(0) * beta_likelihood.size(1);
            nx = (c_loop_ub / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&beta_likelihood[i4]);
              r3 = _mm_loadu_pd(&b[i4]);
              _mm_storeu_pd(&beta_likelihood[i4], _mm_add_pd(r, r3));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              beta_likelihood[i4] = beta_likelihood[i4] + b[i4];
            }
          } else {
            st.site = &uc_emlrtRSI;
            plus(st, beta_likelihood, b);
          }

          st.site = &wc_emlrtRSI;
          b_st.site = &wc_emlrtRSI;
          if (beta_likelihood.size(0) < beta_likelihood.size(1)) {
            b_pai_gamma.set_size(&fc_emlrtRTEI, &b_st, beta_likelihood.size(1),
                                 beta_likelihood.size(0));
            c_loop_ub = beta_likelihood.size(0);
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              nx = beta_likelihood.size(1);
              for (i5 = 0; i5 < nx; i5++) {
                b_pai_gamma[i5 + b_pai_gamma.size(0) * i4] = beta_likelihood[i4
                  + beta_likelihood.size(0) * i5];
              }
            }

            c_st.site = &yf_emlrtRSI;
            coder::eml_pinv(c_st, b_pai_gamma, r1);
            b_a.set_size(&oc_emlrtRTEI, &b_st, r1.size(1), r1.size(0));
            c_loop_ub = r1.size(0);
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              nx = r1.size(1);
              for (i5 = 0; i5 < nx; i5++) {
                b_a[i5 + b_a.size(0) * i4] = r1[i4 + r1.size(0) * i5];
              }
            }
          } else {
            c_st.site = &ag_emlrtRSI;
            coder::eml_pinv(c_st, beta_likelihood, b_a);
          }

          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_a, C2, b_a.size(1), C2.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_a, C2, beta0);
          a = coder::b_norm(beta0);
          if (a > 1.0) {
            c_loop_ub = beta0.size(0);
            nx = (beta0.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&beta0[i4]);
              _mm_storeu_pd(&beta0[i4], _mm_div_pd(r, _mm_set1_pd(a)));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              beta0[i4] = beta0[i4] / a;
            }
          }

          if ((gamma_part.size(0) != beta0.size(0)) && ((gamma_part.size(0) != 1)
               && (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(gamma_part.size(0), beta0.size(0),
              &db_emlrtECI, (emlrtConstCTX)sp);
          }

          if (gamma_part.size(0) == beta0.size(0)) {
            c_loop_ub = gamma_part.size(0);
            for (i4 = 0; i4 <= vectorUB_tmp; i4 += 2) {
              r = _mm_loadu_pd(&gamma_part[i4]);
              r3 = _mm_loadu_pd(&beta0[i4]);
              _mm_storeu_pd(&gamma_part[i4], _mm_sub_pd(r, r3));
            }

            for (i4 = maxdimlen; i4 < c_loop_ub; i4++) {
              gamma_part[i4] = gamma_part[i4] - beta0[i4];
            }
          } else {
            st.site = &kh_emlrtRSI;
            minus(st, gamma_part, beta0);
          }

          if (gamma_part.size(0) < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, gamma_part.size(0), &b_emlrtBCI,
              (emlrtConstCTX)sp);
          }

          st.site = &xc_emlrtRSI;
          if (row_size < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          st.site = &xc_emlrtRSI;
          if (col_size < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          a = muDoubleScalarSqrt(row_size) / muDoubleScalarSqrt(col_size) *
            (coder::b_norm(gamma_part) / coder::b_norm(beta_part));
          st.site = &xc_emlrtRSI;
          if (a < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          a = muDoubleScalarSqrt(a);
          guiyi = muDoubleScalarSign(gamma_part[0]) * a;
          c_loop_ub = gamma_part.size(0);
          nx = (gamma_part.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&gamma_part[i4]);
            _mm_storeu_pd(&gamma_part[i4], _mm_div_pd(r, _mm_set1_pd(guiyi)));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            gamma_part[i4] = gamma_part[i4] / guiyi;
          }

          c_loop_ub = beta_part.size(0);
          nx = (beta_part.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&beta_part[i4]);
            _mm_storeu_pd(&beta_part[i4], _mm_mul_pd(r, _mm_set1_pd(guiyi)));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            beta_part[i4] = beta_part[i4] * guiyi;
          }

          st.site = &yc_emlrtRSI;
          coder::eye(st, n_train, r1);
          b_beta_part.set_size(&pc_emlrtRTEI, sp, 1, beta_part.size(0));
          c_loop_ub = beta_part.size(0);
          for (i4 = 0; i4 < c_loop_ub; i4++) {
            b_beta_part[i4] = beta_part[i4];
          }

          st.site = &yc_emlrtRSI;
          coder::kron(st, r1, b_beta_part, beta_likelihood);
          st.site = &ad_emlrtRSI;
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
            beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
          c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
          c_varargin_1[1] = static_cast<int32_T>(col_size);
          x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
            b_pai_gamma);
          st.site = &ad_emlrtRSI;
          b_st.site = &of_emlrtRSI;
          coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
            b_pai_gamma.size(1), gamma_part.size(0));
          b_st.site = &nf_emlrtRSI;
          coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
          if ((y_train.size(0) != beta0.size(0)) && ((y_train.size(0) != 1) &&
               (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(y_train.size(0), beta0.size(0),
              &cb_emlrtECI, (emlrtConstCTX)sp);
          }

          if (y_train.size(0) == beta0.size(0)) {
            gamma0.set_size(&qc_emlrtRTEI, sp, y_train.size(0));
            c_loop_ub = y_train.size(0);
            nx = (y_train.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&y_train[i4]);
              r3 = _mm_loadu_pd(&beta0[i4]);
              _mm_storeu_pd(&gamma0[i4], _mm_mul_pd(r, r3));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              gamma0[i4] = y_train[i4] * beta0[i4];
            }
          } else {
            st.site = &bd_emlrtRSI;
            times(st, gamma0, y_train, beta0);
          }

          st.site = &bd_emlrtRSI;
          coder::b_exp(st, beta0);
          c_loop_ub = beta0.size(0);
          nx = (beta0.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&beta0[i4]);
            _mm_storeu_pd(&beta0[i4], _mm_add_pd(r, _mm_set1_pd(1.0)));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            beta0[i4] = beta0[i4] + 1.0;
          }

          st.site = &bd_emlrtRSI;
          coder::b_log(st, beta0);
          if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
               (beta0.size(0) != 1))) {
            emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0),
              &cb_emlrtECI, (emlrtConstCTX)sp);
          }

          st.site = &cd_emlrtRSI;
          guiyi = coder::b_norm(beta_part);
          b_st.site = &le_emlrtRSI;
          st.site = &cd_emlrtRSI;
          a = coder::b_norm(gamma_part);
          b_st.site = &le_emlrtRSI;
          if (gamma0.size(0) == beta0.size(0)) {
            beta0.set_size(&qc_emlrtRTEI, sp, gamma0.size(0));
            c_loop_ub = gamma0.size(0);
            nx = (gamma0.size(0) / 2) << 1;
            vectorUB = nx - 2;
            for (i4 = 0; i4 <= vectorUB; i4 += 2) {
              r = _mm_loadu_pd(&gamma0[i4]);
              r3 = _mm_loadu_pd(&beta0[i4]);
              _mm_storeu_pd(&beta0[i4], _mm_sub_pd(r, r3));
            }

            for (i4 = nx; i4 < c_loop_ub; i4++) {
              beta0[i4] = gamma0[i4] - beta0[i4];
            }

            st.site = &bd_emlrtRSI;
            guiyi = -coder::sum(st, beta0) + 0.5 * lambda_tuning * (guiyi *
              guiyi + a * a);
          } else {
            st.site = &bd_emlrtRSI;
            guiyi = binary_expand_op(st, bd_emlrtRSI, gamma0, beta0,
              lambda_tuning, guiyi, a);
          }

          *diff_loglikelihood = muDoubleScalarAbs(guiyi - log_likelihood0);
          log_likelihood0 = guiyi;
          (*iter_initial_in)++;

          // beta_part;
          // disp(2)
          //  % % end
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }

        st.site = &dd_emlrtRSI;
        coder::eye(st, n_test, r1);
        b_beta_part.set_size(&wb_emlrtRTEI, sp, 1, beta_part.size(0));
        c_loop_ub = beta_part.size(0);
        for (i4 = 0; i4 < c_loop_ub; i4++) {
          b_beta_part[i4] = beta_part[i4];
        }

        st.site = &dd_emlrtRSI;
        coder::kron(st, r1, b_beta_part, beta_likelihood);
        st.site = &ed_emlrtRSI;
        coder::permute(st, x_test, r2);
        b_varargin_1 = row_size * n_test;
        st.site = &ed_emlrtRSI;
        nx = r2.size(0) * r2.size(1) * r2.size(2);
        b_st.site = &jf_emlrtRSI;
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, b_varargin_1);
        c_st.site = &kf_emlrtRSI;
        coder::internal::assertValidSizeArg(c_st, col_size);
        maxdimlen = r2.size(0);
        if (r2.size(1) > r2.size(0)) {
          maxdimlen = r2.size(1);
        }

        if (r2.size(2) > maxdimlen) {
          maxdimlen = r2.size(2);
        }

        maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
        if (static_cast<int32_T>(b_varargin_1) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        if (static_cast<int32_T>(col_size) > maxdimlen) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
            "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }

        out = (static_cast<int32_T>(b_varargin_1) >= 0);
        if (!out) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:checkDimCommon:nonnegativeSize",
            "MATLAB:checkDimCommon:nonnegativeSize", 0);
        }

        if (static_cast<int32_T>(b_varargin_1) * static_cast<int32_T>(col_size)
            != nx) {
          emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
            "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }

        st.site = &fd_emlrtRSI;
        c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
          beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
        c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
        c_varargin_1[1] = static_cast<int32_T>(col_size);
        x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, beta_likelihood, x_train,
          b_pai_gamma);
        st.site = &fd_emlrtRSI;
        b_st.site = &of_emlrtRSI;
        coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part,
          b_pai_gamma.size(1), gamma_part.size(0));
        b_st.site = &nf_emlrtRSI;
        coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);

        // log_likelihood0 = -sum(y_test.*eta_likelihood_test-log(1+exp(eta_likelihood_test)));
        if ((y_test.size(0) != beta0.size(0)) && ((y_test.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(y_test.size(0), beta0.size(0),
            &bb_emlrtECI, (emlrtConstCTX)sp);
        }

        if (y_test.size(0) == beta0.size(0)) {
          c_loop_ub = y_test.size(0);
          nx = (y_test.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&y_test[i4]);
            r3 = _mm_loadu_pd(&beta0[i4]);
            _mm_storeu_pd(&y_test[i4], _mm_mul_pd(r, r3));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            y_test[i4] = y_test[i4] * beta0[i4];
          }
        } else {
          st.site = &gd_emlrtRSI;
          times(st, y_test, beta0);
        }

        st.site = &gd_emlrtRSI;
        coder::b_exp(st, beta0);
        c_loop_ub = beta0.size(0);
        nx = (beta0.size(0) / 2) << 1;
        vectorUB = nx - 2;
        for (i4 = 0; i4 <= vectorUB; i4 += 2) {
          r = _mm_loadu_pd(&beta0[i4]);
          _mm_storeu_pd(&beta0[i4], _mm_add_pd(r, _mm_set1_pd(1.0)));
        }

        for (i4 = nx; i4 < c_loop_ub; i4++) {
          beta0[i4] = beta0[i4] + 1.0;
        }

        st.site = &gd_emlrtRSI;
        coder::b_log(st, beta0);
        if ((y_test.size(0) != beta0.size(0)) && ((y_test.size(0) != 1) &&
             (beta0.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(y_test.size(0), beta0.size(0),
            &bb_emlrtECI, (emlrtConstCTX)sp);
        }

        if (y_test.size(0) == beta0.size(0)) {
          c_loop_ub = y_test.size(0);
          nx = (y_test.size(0) / 2) << 1;
          vectorUB = nx - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            r = _mm_loadu_pd(&y_test[i4]);
            r3 = _mm_loadu_pd(&beta0[i4]);
            _mm_storeu_pd(&y_test[i4], _mm_sub_pd(r, r3));
          }

          for (i4 = nx; i4 < c_loop_ub; i4++) {
            y_test[i4] = y_test[i4] - beta0[i4];
          }

          if (t + 1 > tuning_matrix.size(0)) {
            emlrtDynamicBoundsCheckR2012b(t + 1, 1, tuning_matrix.size(0),
              &wb_emlrtBCI, (emlrtConstCTX)sp);
          }

          st.site = &gd_emlrtRSI;
          tuning_matrix[t] = tuning_matrix[t] - coder::sum(st, y_test);
        } else {
          st.site = &gd_emlrtRSI;
          binary_expand_op(st, tuning_matrix, t, gd_emlrtRSI, y_test, beta0);
        }

        // tuning_result(:,t,u) = [beta_part;gamma_part];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }

    st.site = &hd_emlrtRSI;
    b_st.site = &bh_emlrtRSI;
    c_st.site = &ch_emlrtRSI;
    d_st.site = &dh_emlrtRSI;
    if (tuning_matrix.size(0) < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &eh_emlrtRSI;
    maxdimlen = tuning_matrix.size(0);
    if (tuning_matrix.size(0) <= 2) {
      if (tuning_matrix.size(0) == 1) {
        vectorUB = 1;
      } else if ((tuning_matrix[0] > tuning_matrix[1]) || (muDoubleScalarIsNaN
                  (tuning_matrix[0]) && (!muDoubleScalarIsNaN(tuning_matrix[1]))))
      {
        vectorUB = 2;
      } else {
        vectorUB = 1;
      }
    } else {
      f_st.site = &gh_emlrtRSI;
      if (!muDoubleScalarIsNaN(tuning_matrix[0])) {
        vectorUB = 1;
      } else {
        vectorUB = 0;
        g_st.site = &hh_emlrtRSI;
        if (tuning_matrix.size(0) > 2147483646) {
          h_st.site = &ye_emlrtRSI;
          coder::check_forloop_overflow_error(h_st);
        }

        vectorUB_tmp = 2;
        exitg1 = false;
        while ((!exitg1) && (vectorUB_tmp <= maxdimlen)) {
          if (!muDoubleScalarIsNaN(tuning_matrix[vectorUB_tmp - 1])) {
            vectorUB = vectorUB_tmp;
            exitg1 = true;
          } else {
            vectorUB_tmp++;
          }
        }
      }

      if (vectorUB == 0) {
        vectorUB = 1;
      } else {
        f_st.site = &fh_emlrtRSI;
        guiyi = tuning_matrix[vectorUB - 1];
        nx = vectorUB + 1;
        g_st.site = &ih_emlrtRSI;
        if ((vectorUB + 1 <= tuning_matrix.size(0)) && (tuning_matrix.size(0) >
             2147483646)) {
          h_st.site = &ye_emlrtRSI;
          coder::check_forloop_overflow_error(h_st);
        }

        for (vectorUB_tmp = nx; vectorUB_tmp <= maxdimlen; vectorUB_tmp++) {
          a = tuning_matrix[vectorUB_tmp - 1];
          if (guiyi > a) {
            guiyi = a;
            vectorUB = vectorUB_tmp;
          }
        }
      }
    }

    if ((vectorUB < 1) || (vectorUB > tuning_choice.size(1))) {
      emlrtDynamicBoundsCheckR2012b(vectorUB, 1, tuning_choice.size(1),
        &nb_emlrtBCI, (emlrtConstCTX)sp);
    }

    *lambda_best = tuning_choice[vectorUB - 1];
  } else {
    *lambda_best = tuning_end;
  }

  *iter_initial_in = 0.0;
  beta_part.set_size(&rc_emlrtRTEI, sp, loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    beta_part[i2] = coefficients0[i2];
  }

  gamma_part.set_size(&sc_emlrtRTEI, sp, b_loop_ub);
  for (i2 = 0; i2 < b_loop_ub; i2++) {
    gamma_part[i2] = coefficients0[i1 + i2];
  }

  st.site = &id_emlrtRSI;
  coder::eye(st, n, r1);
  b_beta_part.set_size(&lb_emlrtRTEI, sp, 1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_beta_part[i1] = coefficients0[i1];
  }

  st.site = &id_emlrtRSI;
  coder::kron(st, r1, b_beta_part, beta_likelihood);
  st.site = &jd_emlrtRSI;
  coder::permute(st, x, r2);
  b_varargin_1 = row_size * n;
  st.site = &jd_emlrtRSI;
  nx = r2.size(0) * r2.size(1) * r2.size(2);
  b_st.site = &jf_emlrtRSI;
  c_st.site = &kf_emlrtRSI;
  coder::internal::assertValidSizeArg(c_st, b_varargin_1);
  c_st.site = &kf_emlrtRSI;
  coder::internal::assertValidSizeArg(c_st, col_size);
  maxdimlen = r2.size(0);
  if (r2.size(1) > r2.size(0)) {
    maxdimlen = r2.size(1);
  }

  if (r2.size(2) > maxdimlen) {
    maxdimlen = r2.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
  if (static_cast<int32_T>(b_varargin_1) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(col_size) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = (static_cast<int32_T>(b_varargin_1) >= 0);
  if ((!out) || (static_cast<int32_T>(col_size) < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (static_cast<int32_T>(b_varargin_1) * static_cast<int32_T>(col_size) != nx)
  {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  st.site = &kd_emlrtRSI;
  c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
  c_varargin_1[1] = static_cast<int32_T>(col_size);
  x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
  b_st.site = &of_emlrtRSI;
  coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
    beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
  c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
  c_varargin_1[1] = static_cast<int32_T>(col_size);
  x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
  b_st.site = &nf_emlrtRSI;
  coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
  st.site = &kd_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  coder::dynamic_size_checks(b_st, b_pai_gamma, gamma0_part, b_pai_gamma.size(1),
    b_loop_ub);
  b_st.site = &nf_emlrtRSI;
  coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma0_part, beta0);
  if ((y.size(0) != beta0.size(0)) && ((y.size(0) != 1) && (beta0.size(0) != 1)))
  {
    emlrtDimSizeImpxCheckR2021b(y.size(0), beta0.size(0), &ab_emlrtECI,
      (emlrtConstCTX)sp);
  }

  if (y.size(0) == beta0.size(0)) {
    gamma0.set_size(&tc_emlrtRTEI, sp, y.size(0));
    loop_ub = y.size(0);
    nx = (y.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&beta0[i1]);
      _mm_storeu_pd(&gamma0[i1], _mm_mul_pd(_mm_loadu_pd(&y[i1]), r));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      gamma0[i1] = y[i1] * beta0[i1];
    }
  } else {
    st.site = &ld_emlrtRSI;
    b_times(st, gamma0, y, beta0);
  }

  st.site = &ld_emlrtRSI;
  coder::b_exp(st, beta0);
  loop_ub = beta0.size(0);
  nx = (beta0.size(0) / 2) << 1;
  vectorUB = nx - 2;
  for (i1 = 0; i1 <= vectorUB; i1 += 2) {
    r = _mm_loadu_pd(&beta0[i1]);
    _mm_storeu_pd(&beta0[i1], _mm_add_pd(r, _mm_set1_pd(1.0)));
  }

  for (i1 = nx; i1 < loop_ub; i1++) {
    beta0[i1] = beta0[i1] + 1.0;
  }

  st.site = &ld_emlrtRSI;
  coder::b_log(st, beta0);
  if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) && (beta0.size
        (0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0), &ab_emlrtECI,
      (emlrtConstCTX)sp);
  }

  st.site = &md_emlrtRSI;
  guiyi = coder::b_norm(beta0_part);
  b_st.site = &le_emlrtRSI;
  st.site = &md_emlrtRSI;
  a = coder::b_norm(gamma0_part);
  b_st.site = &le_emlrtRSI;
  if (gamma0.size(0) == beta0.size(0)) {
    loop_ub = gamma0.size(0);
    nx = (gamma0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&gamma0[i1]);
      r3 = _mm_loadu_pd(&beta0[i1]);
      _mm_storeu_pd(&gamma0[i1], _mm_sub_pd(r, r3));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      gamma0[i1] = gamma0[i1] - beta0[i1];
    }

    st.site = &ld_emlrtRSI;
    log_likelihood0 = -coder::sum(st, gamma0) + 0.5 * *lambda_best * (guiyi *
      guiyi + a * a);
  } else {
    st.site = &ld_emlrtRSI;
    log_likelihood0 = binary_expand_op(st, ld_emlrtRSI, gamma0, beta0,
      *lambda_best, guiyi, a);
  }

  *diff_loglikelihood = 1.0;
  if (!(row_size >= 0.0)) {
    emlrtNonNegativeCheckR2012b(row_size, &d_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (row_size != static_cast<int32_T>(muDoubleScalarFloor(row_size))) {
    emlrtIntegerCheckR2012b(row_size, &c_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (!(col_size >= 0.0)) {
    emlrtNonNegativeCheckR2012b(col_size, &b_emlrtDCI, (emlrtConstCTX)sp);
  }

  if (col_size != static_cast<int32_T>(muDoubleScalarFloor(col_size))) {
    emlrtIntegerCheckR2012b(col_size, &emlrtDCI, (emlrtConstCTX)sp);
  }

  st.site = &nd_emlrtRSI;
  nx = x.size(0) * x.size(1) * x.size(2);
  b_st.site = &jf_emlrtRSI;
  c_st.site = &kf_emlrtRSI;
  coder::internal::assertValidSizeArg(c_st, varargin_1);
  c_st.site = &kf_emlrtRSI;
  coder::internal::assertValidSizeArg(c_st, n);
  maxdimlen = x.size(0);
  if (x.size(1) > x.size(0)) {
    maxdimlen = x.size(1);
  }

  if (x.size(2) > maxdimlen) {
    maxdimlen = x.size(2);
  }

  maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
  if (static_cast<int32_T>(varargin_1) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (static_cast<int32_T>(n) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  out = (static_cast<int32_T>(varargin_1) >= 0);
  if ((!out) || (static_cast<int32_T>(n) < 0)) {
    out = false;
  }

  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "MATLAB:checkDimCommon:nonnegativeSize",
      "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }

  if (static_cast<int32_T>(varargin_1) * static_cast<int32_T>(n) != nx) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  while ((*diff_loglikelihood > eps_initial) && (*iter_initial_in <=
          iter_max_initial_in)) {
    //  beta_likelihood = kron(eye(n_part),beta_part');
    //  eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
    //  eta_likelihood_mat = diag((1 + exp(beta_likelihood*x_likelihood*gamma_part)).^(-1));
    //  eta_likelihood_mat2 = diag(sqrt(exp(beta_likelihood*x_likelihood*gamma_part)));
    //
    //  grdient_sum = [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]*...
    //                  [x_part_reshape*(((eta_likelihood_mat2.^2).*eta_likelihood_mat) - diag(y_part))*ones(n_part,1)]...
    //                  +lambda_best*[beta_part;gamma_part];
    //  Hessin_sum = [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]*...
    //                  (x_part_reshape*(eta_likelihood_mat.*eta_likelihood_mat2))*(x_part_reshape*(eta_likelihood_mat.*eta_likelihood_mat2))'*...
    //                  [kron(gamma_part',eye(row_size));(kron(beta_part',eye(col_size))*pai_gamma')]'+...
    //                  [zeros(row_size,col_size),...
    //                  reshape([x_part_reshape*(((eta_likelihood_mat2.^2).*eta_likelihood_mat) - diag(y_part))*ones(n_part,1)],row_size,col_size);...
    //                  reshape([x_part_reshape*(((eta_likelihood_mat2.^2).*eta_likelihood_mat) - diag(y_part))*ones(n_part,1)],row_size,col_size)',...
    //                  zeros(col_size,row_size)]+...
    //              [lambda_best*eye(row_size),zeros(row_size,col_size);zeros(col_size,row_size),lambda_best*eye(col_size)];
    //  newton_sum = pinv(Hessin_sum)*grdient_sum;
    //  z = min(eig(Hessin_sum));
    //  % % if z>0
    //  sumvec = [beta_part;gamma_part]-newton_sum;
    //  beta_part = sumvec(1:row_size);
    //  gamma_part = sumvec((row_size+1):end);
    //  guiyi = sign(gamma_part(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_part)/norm(beta_part)));
    //  %guiyi = gamma_part(1);
    //  gamma_part = gamma_part/guiyi;%拿出来了
    //  beta_part = beta_part*guiyi;%拿出来了
    //  beta_likelihood = kron(eye(n_part),beta_part');
    //  eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
    //  log_likelihood  = -sum(y_part.*eta_likelihood-log(1+exp(eta_likelihood)))+...
    //                      0.5*lambda_best*(norm(beta_part).^2+norm(gamma_part).^2);
    //  diff_loglikelihood = abs(log_likelihood-log_likelihood0);
    //  log_likelihood0 = log_likelihood;
    //  iter_initial_in = iter_initial_in + 1;
    //  %[[beta_real_part1(1:row_size);gamma_real_part1(1:col_size)],[beta_real_part2(1:row_size);gamma_real_part2(1:col_size)],[beta_real_part3(1:row_size);gamma_real_part3(1:col_size)]]
    //  %beta_part;
    //  %disp(1)
    //  % % else
    st.site = &od_emlrtRSI;
    coder::eye(st, n, r1);
    b_beta_part.set_size(&uc_emlrtRTEI, sp, 1, beta_part.size(0));
    loop_ub = beta_part.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_beta_part[i1] = beta_part[i1];
    }

    st.site = &od_emlrtRSI;
    coder::kron(st, r1, b_beta_part, beta_likelihood);
    st.site = &pd_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &pd_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, ph_emlrtRSI);
    st.site = &qd_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &qd_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    st.site = &qd_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    coder::b_exp(b_st, beta0);
    loop_ub = beta0.size(0);
    nx = (beta0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&beta0[i1]);
      _mm_storeu_pd(&beta0[i1], _mm_add_pd(r, _mm_set1_pd(1.0)));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      beta0[i1] = beta0[i1] + 1.0;
    }

    b_st.site = &le_emlrtRSI;
    C2.set_size(&v_emlrtRTEI, sp, beta0.size(0));
    loop_ub = beta0.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      d_varargin_1 = beta0[i1];
      C2[i1] = 1.0 / d_varargin_1;
    }

    st.site = &qd_emlrtRSI;
    coder::diag(st, C2, eta_likelihood_mat_train);
    st.site = &rd_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &rd_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    st.site = &rd_emlrtRSI;
    coder::b_exp(st, beta0);
    st.site = &rd_emlrtRSI;
    coder::b_sqrt(st, beta0);
    st.site = &rd_emlrtRSI;
    coder::diag(st, beta0, beta_likelihood);
    st.site = &sd_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    b.set_size(&vc_emlrtRTEI, &b_st, beta_likelihood.size(0),
               beta_likelihood.size(1));
    maxdimlen = beta_likelihood.size(0) * beta_likelihood.size(1);
    for (i1 = 0; i1 < maxdimlen; i1++) {
      d_varargin_1 = beta_likelihood[i1];
      b[i1] = d_varargin_1 * d_varargin_1;
    }

    if ((b.size(0) != eta_likelihood_mat_train.size(0)) && ((b.size(0) != 1) &&
         (eta_likelihood_mat_train.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(0), eta_likelihood_mat_train.size(0),
        &y_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((b.size(1) != eta_likelihood_mat_train.size(1)) && ((b.size(1) != 1) &&
         (eta_likelihood_mat_train.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(1), eta_likelihood_mat_train.size(1),
        &x_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((b.size(0) == eta_likelihood_mat_train.size(0)) && (b.size(1) ==
         eta_likelihood_mat_train.size(1))) {
      nx = (maxdimlen / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&b[i1]);
        r3 = _mm_loadu_pd(&eta_likelihood_mat_train[i1]);
        _mm_storeu_pd(&b[i1], _mm_mul_pd(r, r3));
      }

      for (i1 = nx; i1 < maxdimlen; i1++) {
        b[i1] = b[i1] * eta_likelihood_mat_train[i1];
      }
    } else {
      st.site = &sd_emlrtRSI;
      times(st, b, eta_likelihood_mat_train);
    }

    st.site = &sd_emlrtRSI;
    coder::diag(st, y, r1);
    if ((b.size(0) != r1.size(0)) && ((b.size(0) != 1) && (r1.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(0), r1.size(0), &w_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((b.size(1) != r1.size(1)) && ((b.size(1) != 1) && (r1.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(1), r1.size(1), &v_emlrtECI,
        (emlrtConstCTX)sp);
    }

    st.site = &sd_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    coder::eye(b_st, row_size, r8);
    b_beta_part.set_size(&wc_emlrtRTEI, &st, 1, gamma_part.size(0));
    loop_ub = gamma_part.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_beta_part[i1] = gamma_part[i1];
    }

    b_st.site = &sd_emlrtRSI;
    coder::b_kron(b_st, b_beta_part, r8, b_a);
    varargin_1_tmp = static_cast<int32_T>(n);
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, x_train, b_a.size(1),
      static_cast<int32_T>(varargin_1));
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_a, x_train, b_pai_gamma);
    st.site = &sd_emlrtRSI;
    if ((b.size(0) == r1.size(0)) && (b.size(1) == r1.size(1))) {
      loop_ub = b.size(0) * b.size(1);
      nx = (loop_ub / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&b[i1]);
        r3 = _mm_loadu_pd(&r1[i1]);
        _mm_storeu_pd(&b[i1], _mm_sub_pd(r, r3));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        b[i1] = b[i1] - r1[i1];
      }
    } else {
      b_st.site = &sd_emlrtRSI;
      minus(b_st, b, r1);
    }

    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, b, b_pai_gamma.size(1), b.size
      (0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, b, b_y);
    st.site = &sd_emlrtRSI;
    if (!(n >= 0.0)) {
      emlrtNonNegativeCheckR2012b(n, &vb_emlrtDCI, &st);
    }

    if (n != static_cast<int32_T>(muDoubleScalarFloor(n))) {
      emlrtIntegerCheckR2012b(n, &ub_emlrtDCI, &st);
    }

    beta0.set_size(&xc_emlrtRTEI, &st, static_cast<int32_T>(n));
    i1 = static_cast<int32_T>(muDoubleScalarFloor(n));
    if (n != i1) {
      emlrtIntegerCheckR2012b(n, &ub_emlrtDCI, &st);
    }

    for (i2 = 0; i2 < varargin_1_tmp; i2++) {
      beta0[i2] = 1.0;
    }

    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_y, beta0, b_y.size(1),
      static_cast<int32_T>(n));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_y, beta0, C2);
    gamma0.set_size(&yc_emlrtRTEI, sp, beta_part.size(0));
    loop_ub = beta_part.size(0);
    maxdimlen = (beta_part.size(0) / 2) << 1;
    vectorUB_tmp = maxdimlen - 2;
    for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
      r = _mm_loadu_pd(&beta_part[i2]);
      _mm_storeu_pd(&gamma0[i2], _mm_mul_pd(_mm_set1_pd(*lambda_best), r));
    }

    for (i2 = maxdimlen; i2 < loop_ub; i2++) {
      gamma0[i2] = *lambda_best * beta_part[i2];
    }

    if ((C2.size(0) != gamma0.size(0)) && ((C2.size(0) != 1) && (gamma0.size(0)
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(C2.size(0), gamma0.size(0), &u_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (C2.size(0) == gamma0.size(0)) {
      loop_ub = C2.size(0);
      nx = (C2.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&C2[i2]);
        r3 = _mm_loadu_pd(&gamma0[i2]);
        _mm_storeu_pd(&C2[i2], _mm_add_pd(r, r3));
      }

      for (i2 = nx; i2 < loop_ub; i2++) {
        C2[i2] = C2[i2] + gamma0[i2];
      }
    } else {
      st.site = &sd_emlrtRSI;
      plus(st, C2, gamma0);
    }

    if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
        ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size(0) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
        beta_likelihood.size(0), &t_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
        ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size(1) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
        beta_likelihood.size(1), &s_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
        ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size(0) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
        beta_likelihood.size(0), &r_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
        ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size(1) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
        beta_likelihood.size(1), &q_emlrtECI, (emlrtConstCTX)sp);
    }

    st.site = &td_emlrtRSI;
    if ((eta_likelihood_mat_train.size(0) == beta_likelihood.size(0)) &&
        (eta_likelihood_mat_train.size(1) == beta_likelihood.size(1))) {
      loop_ub = eta_likelihood_mat_train.size(0) * eta_likelihood_mat_train.size
        (1);
      nx = (loop_ub / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&eta_likelihood_mat_train[i2]);
        r3 = _mm_loadu_pd(&beta_likelihood[i2]);
        _mm_storeu_pd(&eta_likelihood_mat_train[i2], _mm_mul_pd(r, r3));
      }

      for (i2 = nx; i2 < loop_ub; i2++) {
        eta_likelihood_mat_train[i2] = eta_likelihood_mat_train[i2] *
          beta_likelihood[i2];
      }
    } else {
      b_st.site = &td_emlrtRSI;
      times(b_st, eta_likelihood_mat_train, beta_likelihood);
    }

    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
      static_cast<int32_T>(n), eta_likelihood_mat_train.size(0));
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train, r1);
    st.site = &td_emlrtRSI;
    coder::eye(st, row_size, r8);
    b_beta_part.set_size(&ad_emlrtRTEI, sp, 1, gamma_part.size(0));
    loop_ub = gamma_part.size(0);
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_beta_part[i2] = gamma_part[i2];
    }

    st.site = &td_emlrtRSI;
    coder::b_kron(st, b_beta_part, r8, b);
    st.site = &td_emlrtRSI;
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
      static_cast<int32_T>(n), eta_likelihood_mat_train.size(0));
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train,
      b_pai_gamma);
    st.site = &td_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    coder::eye(b_st, row_size, r8);
    b_beta_part.set_size(&bd_emlrtRTEI, &st, 1, gamma_part.size(0));
    loop_ub = gamma_part.size(0);
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_beta_part[i2] = gamma_part[i2];
    }

    b_st.site = &td_emlrtRSI;
    coder::b_kron(b_st, b_beta_part, r8, b_a);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, b_pai_gamma, b_a.size(1),
      b_pai_gamma.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_a, b_pai_gamma, b_y);
    st.site = &td_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_y, r1, b_y.size(1), r1.size(1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, b_y, r1, b_pai_gamma);
    st.site = &td_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, b, b_pai_gamma.size(1), b.size
      (1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, b_pai_gamma, b, beta_likelihood);
    st.site = &ud_emlrtRSI;
    coder::eye(st, row_size, b);
    loop_ub = b.size(0) * b.size(1);
    nx = (loop_ub / 2) << 1;
    vectorUB = nx - 2;
    for (i2 = 0; i2 <= vectorUB; i2 += 2) {
      r = _mm_loadu_pd(&b[i2]);
      _mm_storeu_pd(&b[i2], _mm_mul_pd(_mm_set1_pd(*lambda_best), r));
    }

    for (i2 = nx; i2 < loop_ub; i2++) {
      b[i2] = *lambda_best * b[i2];
    }

    if ((beta_likelihood.size(0) != b.size(0)) && ((beta_likelihood.size(0) != 1)
         && (b.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(0), b.size(0),
        &p_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((beta_likelihood.size(1) != b.size(1)) && ((beta_likelihood.size(1) != 1)
         && (b.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(1), b.size(1),
        &o_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((beta_likelihood.size(0) == b.size(0)) && (beta_likelihood.size(1) ==
         b.size(1))) {
      loop_ub = beta_likelihood.size(0) * beta_likelihood.size(1);
      nx = (loop_ub / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&beta_likelihood[i2]);
        r3 = _mm_loadu_pd(&b[i2]);
        _mm_storeu_pd(&beta_likelihood[i2], _mm_add_pd(r, r3));
      }

      for (i2 = nx; i2 < loop_ub; i2++) {
        beta_likelihood[i2] = beta_likelihood[i2] + b[i2];
      }
    } else {
      st.site = &td_emlrtRSI;
      plus(st, beta_likelihood, b);
    }

    // min(eig(M2))
    st.site = &vd_emlrtRSI;
    b_st.site = &vd_emlrtRSI;
    if (beta_likelihood.size(0) < beta_likelihood.size(1)) {
      b_pai_gamma.set_size(&fc_emlrtRTEI, &b_st, beta_likelihood.size(1),
                           beta_likelihood.size(0));
      loop_ub = beta_likelihood.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_loop_ub = beta_likelihood.size(1);
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_pai_gamma[i3 + b_pai_gamma.size(0) * i2] = beta_likelihood[i2 +
            beta_likelihood.size(0) * i3];
        }
      }

      c_st.site = &yf_emlrtRSI;
      coder::eml_pinv(c_st, b_pai_gamma, r1);
      b_a.set_size(&cd_emlrtRTEI, &b_st, r1.size(1), r1.size(0));
      loop_ub = r1.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_loop_ub = r1.size(1);
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          b_a[i3 + b_a.size(0) * i2] = r1[i2 + r1.size(0) * i3];
        }
      }
    } else {
      c_st.site = &ag_emlrtRSI;
      coder::eml_pinv(c_st, beta_likelihood, b_a);
    }

    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, C2, b_a.size(1), C2.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_a, C2, beta0);
    a = coder::b_norm(beta0);
    if (a > 1.0) {
      loop_ub = beta0.size(0);
      nx = (beta0.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&beta0[i2]);
        _mm_storeu_pd(&beta0[i2], _mm_div_pd(r, _mm_set1_pd(a)));
      }

      for (i2 = nx; i2 < loop_ub; i2++) {
        beta0[i2] = beta0[i2] / a;
      }
    }

    if ((beta_part.size(0) != beta0.size(0)) && ((beta_part.size(0) != 1) &&
         (beta0.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(beta_part.size(0), beta0.size(0), &n_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (beta_part.size(0) == beta0.size(0)) {
      loop_ub = beta_part.size(0);
      for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
        r = _mm_loadu_pd(&beta_part[i2]);
        r3 = _mm_loadu_pd(&beta0[i2]);
        _mm_storeu_pd(&beta_part[i2], _mm_sub_pd(r, r3));
      }

      for (i2 = maxdimlen; i2 < loop_ub; i2++) {
        beta_part[i2] = beta_part[i2] - beta0[i2];
      }
    } else {
      st.site = &lh_emlrtRSI;
      minus(st, beta_part, beta0);
    }

    st.site = &wd_emlrtRSI;
    coder::eye(st, n, r1);
    b_beta_part.set_size(&dd_emlrtRTEI, sp, 1, beta_part.size(0));
    loop_ub = beta_part.size(0);
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_beta_part[i2] = beta_part[i2];
    }

    st.site = &wd_emlrtRSI;
    coder::kron(st, r1, b_beta_part, beta_likelihood);
    st.site = &xd_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &xd_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, sh_emlrtRSI);
    st.site = &yd_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &yd_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    st.site = &yd_emlrtRSI;
    b_st.site = &yd_emlrtRSI;
    coder::b_exp(b_st, beta0);
    loop_ub = beta0.size(0);
    nx = (beta0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i2 = 0; i2 <= vectorUB; i2 += 2) {
      r = _mm_loadu_pd(&beta0[i2]);
      _mm_storeu_pd(&beta0[i2], _mm_add_pd(r, _mm_set1_pd(1.0)));
    }

    for (i2 = nx; i2 < loop_ub; i2++) {
      beta0[i2] = beta0[i2] + 1.0;
    }

    b_st.site = &le_emlrtRSI;
    C2.set_size(&v_emlrtRTEI, sp, beta0.size(0));
    loop_ub = beta0.size(0);
    for (i2 = 0; i2 < loop_ub; i2++) {
      d_varargin_1 = beta0[i2];
      C2[i2] = 1.0 / d_varargin_1;
    }

    st.site = &yd_emlrtRSI;
    coder::diag(st, C2, eta_likelihood_mat_train);
    st.site = &ae_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &ae_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    st.site = &ae_emlrtRSI;
    coder::b_exp(st, beta0);
    st.site = &ae_emlrtRSI;
    coder::b_sqrt(st, beta0);
    st.site = &ae_emlrtRSI;
    coder::diag(st, beta0, beta_likelihood);
    st.site = &be_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    b.set_size(&ed_emlrtRTEI, &b_st, beta_likelihood.size(0),
               beta_likelihood.size(1));
    maxdimlen = beta_likelihood.size(0) * beta_likelihood.size(1);
    for (i2 = 0; i2 < maxdimlen; i2++) {
      d_varargin_1 = beta_likelihood[i2];
      b[i2] = d_varargin_1 * d_varargin_1;
    }

    if ((b.size(0) != eta_likelihood_mat_train.size(0)) && ((b.size(0) != 1) &&
         (eta_likelihood_mat_train.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(0), eta_likelihood_mat_train.size(0),
        &m_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((b.size(1) != eta_likelihood_mat_train.size(1)) && ((b.size(1) != 1) &&
         (eta_likelihood_mat_train.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(1), eta_likelihood_mat_train.size(1),
        &l_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((b.size(0) == eta_likelihood_mat_train.size(0)) && (b.size(1) ==
         eta_likelihood_mat_train.size(1))) {
      nx = (maxdimlen / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&b[i2]);
        r3 = _mm_loadu_pd(&eta_likelihood_mat_train[i2]);
        _mm_storeu_pd(&b[i2], _mm_mul_pd(r, r3));
      }

      for (i2 = nx; i2 < maxdimlen; i2++) {
        b[i2] = b[i2] * eta_likelihood_mat_train[i2];
      }
    } else {
      st.site = &be_emlrtRSI;
      times(st, b, eta_likelihood_mat_train);
    }

    st.site = &be_emlrtRSI;
    coder::diag(st, y, r1);
    if ((b.size(0) != r1.size(0)) && ((b.size(0) != 1) && (r1.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(0), r1.size(0), &k_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if ((b.size(1) != r1.size(1)) && ((b.size(1) != 1) && (r1.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b.size(1), r1.size(1), &j_emlrtECI,
        (emlrtConstCTX)sp);
    }

    st.site = &be_emlrtRSI;
    b_st.site = &be_emlrtRSI;
    coder::eye(b_st, col_size, r8);
    b_beta_part.set_size(&fd_emlrtRTEI, &st, 1, beta_part.size(0));
    loop_ub = beta_part.size(0);
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_beta_part[i2] = beta_part[i2];
    }

    b_st.site = &be_emlrtRSI;
    coder::b_kron(b_st, b_beta_part, r8, b_a);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1), pai_gamma.size
      (1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, b_pai_gamma);
    st.site = &be_emlrtRSI;
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, x_train, b_pai_gamma.size(1),
      static_cast<int32_T>(varargin_1));
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, x_train, b_y);
    st.site = &be_emlrtRSI;
    if ((b.size(0) == r1.size(0)) && (b.size(1) == r1.size(1))) {
      loop_ub = b.size(0) * b.size(1);
      nx = (loop_ub / 2) << 1;
      vectorUB = nx - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&b[i2]);
        r3 = _mm_loadu_pd(&r1[i2]);
        _mm_storeu_pd(&b[i2], _mm_sub_pd(r, r3));
      }

      for (i2 = nx; i2 < loop_ub; i2++) {
        b[i2] = b[i2] - r1[i2];
      }
    } else {
      b_st.site = &be_emlrtRSI;
      minus(b_st, b, r1);
    }

    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_y, b, b_y.size(1), b.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_y, b, b_pai_gamma);
    st.site = &be_emlrtRSI;
    if (static_cast<int32_T>(n) != i1) {
      emlrtIntegerCheckR2012b(n, &bc_emlrtDCI, &st);
    }

    beta0.set_size(&gd_emlrtRTEI, &st, static_cast<int32_T>(n));
    if (static_cast<int32_T>(n) != i1) {
      emlrtIntegerCheckR2012b(n, &bc_emlrtDCI, &st);
    }

    for (i1 = 0; i1 < varargin_1_tmp; i1++) {
      beta0[i1] = 1.0;
    }

    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, beta0, b_pai_gamma.size(1),
      static_cast<int32_T>(n));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, beta0, C2);
    gamma0.set_size(&hd_emlrtRTEI, sp, gamma_part.size(0));
    loop_ub = gamma_part.size(0);
    maxdimlen = (gamma_part.size(0) / 2) << 1;
    vectorUB_tmp = maxdimlen - 2;
    for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
      r = _mm_loadu_pd(&gamma_part[i1]);
      _mm_storeu_pd(&gamma0[i1], _mm_mul_pd(_mm_set1_pd(*lambda_best), r));
    }

    for (i1 = maxdimlen; i1 < loop_ub; i1++) {
      gamma0[i1] = *lambda_best * gamma_part[i1];
    }

    if ((C2.size(0) != gamma0.size(0)) && ((C2.size(0) != 1) && (gamma0.size(0)
          != 1))) {
      emlrtDimSizeImpxCheckR2021b(C2.size(0), gamma0.size(0), &i_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (C2.size(0) == gamma0.size(0)) {
      loop_ub = C2.size(0);
      nx = (C2.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&C2[i1]);
        r3 = _mm_loadu_pd(&gamma0[i1]);
        _mm_storeu_pd(&C2[i1], _mm_add_pd(r, r3));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        C2[i1] = C2[i1] + gamma0[i1];
      }
    } else {
      st.site = &be_emlrtRSI;
      plus(st, C2, gamma0);
    }

    if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
        ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size(0) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
        beta_likelihood.size(0), &h_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
        ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size(1) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
        beta_likelihood.size(1), &g_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((eta_likelihood_mat_train.size(0) != beta_likelihood.size(0)) &&
        ((eta_likelihood_mat_train.size(0) != 1) && (beta_likelihood.size(0) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(0),
        beta_likelihood.size(0), &f_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((eta_likelihood_mat_train.size(1) != beta_likelihood.size(1)) &&
        ((eta_likelihood_mat_train.size(1) != 1) && (beta_likelihood.size(1) !=
          1))) {
      emlrtDimSizeImpxCheckR2021b(eta_likelihood_mat_train.size(1),
        beta_likelihood.size(1), &e_emlrtECI, (emlrtConstCTX)sp);
    }

    st.site = &ce_emlrtRSI;
    if ((eta_likelihood_mat_train.size(0) == beta_likelihood.size(0)) &&
        (eta_likelihood_mat_train.size(1) == beta_likelihood.size(1))) {
      loop_ub = eta_likelihood_mat_train.size(0) * eta_likelihood_mat_train.size
        (1);
      nx = (loop_ub / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&eta_likelihood_mat_train[i1]);
        r3 = _mm_loadu_pd(&beta_likelihood[i1]);
        _mm_storeu_pd(&eta_likelihood_mat_train[i1], _mm_mul_pd(r, r3));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        eta_likelihood_mat_train[i1] = eta_likelihood_mat_train[i1] *
          beta_likelihood[i1];
      }
    } else {
      b_st.site = &ce_emlrtRSI;
      times(b_st, eta_likelihood_mat_train, beta_likelihood);
    }

    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
      static_cast<int32_T>(n), eta_likelihood_mat_train.size(0));
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train, r1);
    st.site = &ce_emlrtRSI;
    b_st.site = &ce_emlrtRSI;
    coder::eye(b_st, col_size, r8);
    b_beta_part.set_size(&id_emlrtRTEI, &st, 1, beta_part.size(0));
    loop_ub = beta_part.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_beta_part[i1] = beta_part[i1];
    }

    b_st.site = &ce_emlrtRSI;
    coder::b_kron(b_st, b_beta_part, r8, b_a);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1), pai_gamma.size
      (1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, r8);
    st.site = &ce_emlrtRSI;
    b_st.site = &ce_emlrtRSI;
    coder::eye(b_st, col_size, b);
    b_beta_part.set_size(&jd_emlrtRTEI, &st, 1, beta_part.size(0));
    loop_ub = beta_part.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_beta_part[i1] = beta_part[i1];
    }

    b_st.site = &ce_emlrtRSI;
    coder::b_kron(b_st, b_beta_part, b, b_a);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, pai_gamma, b_a.size(1), pai_gamma.size
      (1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, b_a, pai_gamma, b_pai_gamma);
    st.site = &ce_emlrtRSI;
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, x_train, eta_likelihood_mat_train,
      static_cast<int32_T>(n), eta_likelihood_mat_train.size(0));
    c_varargin_1[1] = static_cast<int32_T>(n);
    x_train = x.reshape(i, c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, x_train, eta_likelihood_mat_train, b_y);
    st.site = &ce_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, b_y, b_pai_gamma.size(1),
      b_y.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, b_y, beta_likelihood);
    st.site = &ce_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, r1, beta_likelihood.size(1),
      r1.size(1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, beta_likelihood, r1, b_pai_gamma);
    st.site = &ce_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, r8, b_pai_gamma.size(1),
      r8.size(1));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::b_mtimes(b_st, b_pai_gamma, r8, beta_likelihood);
    st.site = &de_emlrtRSI;
    coder::eye(st, col_size, b);
    loop_ub = b.size(0) * b.size(1);
    nx = (loop_ub / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&b[i1]);
      _mm_storeu_pd(&b[i1], _mm_mul_pd(_mm_set1_pd(*lambda_best), r));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      b[i1] = *lambda_best * b[i1];
    }

    if ((beta_likelihood.size(0) != b.size(0)) && ((beta_likelihood.size(0) != 1)
         && (b.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(0), b.size(0),
        &d_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((beta_likelihood.size(1) != b.size(1)) && ((beta_likelihood.size(1) != 1)
         && (b.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(beta_likelihood.size(1), b.size(1),
        &c_emlrtECI, (emlrtConstCTX)sp);
    }

    if ((beta_likelihood.size(0) == b.size(0)) && (beta_likelihood.size(1) ==
         b.size(1))) {
      loop_ub = beta_likelihood.size(0) * beta_likelihood.size(1);
      nx = (loop_ub / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&beta_likelihood[i1]);
        r3 = _mm_loadu_pd(&b[i1]);
        _mm_storeu_pd(&beta_likelihood[i1], _mm_add_pd(r, r3));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        beta_likelihood[i1] = beta_likelihood[i1] + b[i1];
      }
    } else {
      st.site = &ce_emlrtRSI;
      plus(st, beta_likelihood, b);
    }

    st.site = &ee_emlrtRSI;
    b_st.site = &ee_emlrtRSI;
    if (beta_likelihood.size(0) < beta_likelihood.size(1)) {
      b_pai_gamma.set_size(&fc_emlrtRTEI, &b_st, beta_likelihood.size(1),
                           beta_likelihood.size(0));
      loop_ub = beta_likelihood.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = beta_likelihood.size(1);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_pai_gamma[i2 + b_pai_gamma.size(0) * i1] = beta_likelihood[i1 +
            beta_likelihood.size(0) * i2];
        }
      }

      c_st.site = &yf_emlrtRSI;
      coder::eml_pinv(c_st, b_pai_gamma, r1);
      b_a.set_size(&kd_emlrtRTEI, &b_st, r1.size(1), r1.size(0));
      loop_ub = r1.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = r1.size(1);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_a[i2 + b_a.size(0) * i1] = r1[i1 + r1.size(0) * i2];
        }
      }
    } else {
      c_st.site = &ag_emlrtRSI;
      coder::eml_pinv(c_st, beta_likelihood, b_a);
    }

    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_a, C2, b_a.size(1), C2.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_a, C2, beta0);
    a = coder::b_norm(beta0);
    if (a > 1.0) {
      loop_ub = beta0.size(0);
      nx = (beta0.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&beta0[i1]);
        _mm_storeu_pd(&beta0[i1], _mm_div_pd(r, _mm_set1_pd(a)));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        beta0[i1] = beta0[i1] / a;
      }
    }

    if ((gamma_part.size(0) != beta0.size(0)) && ((gamma_part.size(0) != 1) &&
         (beta0.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(gamma_part.size(0), beta0.size(0), &b_emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (gamma_part.size(0) == beta0.size(0)) {
      loop_ub = gamma_part.size(0);
      for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
        r = _mm_loadu_pd(&gamma_part[i1]);
        r3 = _mm_loadu_pd(&beta0[i1]);
        _mm_storeu_pd(&gamma_part[i1], _mm_sub_pd(r, r3));
      }

      for (i1 = maxdimlen; i1 < loop_ub; i1++) {
        gamma_part[i1] = gamma_part[i1] - beta0[i1];
      }
    } else {
      st.site = &mh_emlrtRSI;
      minus(st, gamma_part, beta0);
    }

    if (gamma_part.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gamma_part.size(0), &emlrtBCI,
        (emlrtConstCTX)sp);
    }

    st.site = &fe_emlrtRSI;
    if (row_size < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    st.site = &fe_emlrtRSI;
    if (col_size < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    a = muDoubleScalarSqrt(row_size) / muDoubleScalarSqrt(col_size) * (coder::
      b_norm(gamma_part) / coder::b_norm(beta_part));
    st.site = &fe_emlrtRSI;
    if (a < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    a = muDoubleScalarSqrt(a);
    guiyi = muDoubleScalarSign(gamma_part[0]) * a;
    loop_ub = gamma_part.size(0);
    nx = (gamma_part.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&gamma_part[i1]);
      _mm_storeu_pd(&gamma_part[i1], _mm_div_pd(r, _mm_set1_pd(guiyi)));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      gamma_part[i1] = gamma_part[i1] / guiyi;
    }

    loop_ub = beta_part.size(0);
    nx = (beta_part.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&beta_part[i1]);
      _mm_storeu_pd(&beta_part[i1], _mm_mul_pd(r, _mm_set1_pd(guiyi)));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      beta_part[i1] = beta_part[i1] * guiyi;
    }

    st.site = &ge_emlrtRSI;
    coder::eye(st, n, r1);
    b_beta_part.set_size(&ld_emlrtRTEI, sp, 1, beta_part.size(0));
    loop_ub = beta_part.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_beta_part[i1] = beta_part[i1];
    }

    st.site = &ge_emlrtRSI;
    coder::kron(st, r1, b_beta_part, beta_likelihood);
    st.site = &he_emlrtRSI;
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, beta_likelihood, x_train,
      beta_likelihood.size(1), static_cast<int32_T>(b_varargin_1));
    c_varargin_1[0] = static_cast<int32_T>(b_varargin_1);
    c_varargin_1[1] = static_cast<int32_T>(col_size);
    x_train = r2.reshape(c_varargin_1[0], c_varargin_1[1]);
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, beta_likelihood, x_train, b_pai_gamma);
    st.site = &he_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    coder::dynamic_size_checks(b_st, b_pai_gamma, gamma_part, b_pai_gamma.size(1),
      gamma_part.size(0));
    b_st.site = &nf_emlrtRSI;
    coder::internal::blas::mtimes(b_st, b_pai_gamma, gamma_part, beta0);
    if ((y.size(0) != beta0.size(0)) && ((y.size(0) != 1) && (beta0.size(0) != 1)))
    {
      emlrtDimSizeImpxCheckR2021b(y.size(0), beta0.size(0), &emlrtECI,
        (emlrtConstCTX)sp);
    }

    if (y.size(0) == beta0.size(0)) {
      gamma0.set_size(&md_emlrtRTEI, sp, y.size(0));
      loop_ub = y.size(0);
      nx = (y.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&beta0[i1]);
        _mm_storeu_pd(&gamma0[i1], _mm_mul_pd(_mm_loadu_pd(&y[i1]), r));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        gamma0[i1] = y[i1] * beta0[i1];
      }
    } else {
      st.site = &ie_emlrtRSI;
      b_times(st, gamma0, y, beta0);
    }

    st.site = &ie_emlrtRSI;
    coder::b_exp(st, beta0);
    loop_ub = beta0.size(0);
    nx = (beta0.size(0) / 2) << 1;
    vectorUB = nx - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&beta0[i1]);
      _mm_storeu_pd(&beta0[i1], _mm_add_pd(r, _mm_set1_pd(1.0)));
    }

    for (i1 = nx; i1 < loop_ub; i1++) {
      beta0[i1] = beta0[i1] + 1.0;
    }

    st.site = &ie_emlrtRSI;
    coder::b_log(st, beta0);
    if ((gamma0.size(0) != beta0.size(0)) && ((gamma0.size(0) != 1) &&
         (beta0.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(gamma0.size(0), beta0.size(0), &emlrtECI,
        (emlrtConstCTX)sp);
    }

    st.site = &je_emlrtRSI;
    guiyi = coder::b_norm(beta_part);
    b_st.site = &le_emlrtRSI;
    st.site = &je_emlrtRSI;
    a = coder::b_norm(gamma_part);
    b_st.site = &le_emlrtRSI;
    if (gamma0.size(0) == beta0.size(0)) {
      loop_ub = gamma0.size(0);
      nx = (gamma0.size(0) / 2) << 1;
      vectorUB = nx - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&gamma0[i1]);
        r3 = _mm_loadu_pd(&beta0[i1]);
        _mm_storeu_pd(&gamma0[i1], _mm_sub_pd(r, r3));
      }

      for (i1 = nx; i1 < loop_ub; i1++) {
        gamma0[i1] = gamma0[i1] - beta0[i1];
      }

      st.site = &ie_emlrtRSI;
      guiyi = -coder::sum(st, gamma0) + 0.5 * *lambda_best * (guiyi * guiyi + a *
        a);
    } else {
      st.site = &ie_emlrtRSI;
      guiyi = binary_expand_op(st, ie_emlrtRSI, gamma0, beta0, *lambda_best,
        guiyi, a);
    }

    *diff_loglikelihood = muDoubleScalarAbs(guiyi - log_likelihood0);
    log_likelihood0 = guiyi;
    (*iter_initial_in)++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (logit_matrix_ridge_regression.cpp)
