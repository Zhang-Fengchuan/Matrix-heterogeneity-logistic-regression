//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// logit_matrix_ridge_regression_initialize.cpp
//
// Code generation for function 'logit_matrix_ridge_regression_initialize'
//

// Include files
#include "logit_matrix_ridge_regression_initialize.h"
#include "_coder_logit_matrix_ridge_regression_mex.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void logit_matrix_ridge_regression_once();

// Function Definitions
static void logit_matrix_ridge_regression_once()
{
  mex_InitInfAndNan();
}

void logit_matrix_ridge_regression_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    logit_matrix_ridge_regression_once();
  }
}

// End of code generation (logit_matrix_ridge_regression_initialize.cpp)
