//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// logit_matrix_ridge_regression_terminate.cpp
//
// Code generation for function 'logit_matrix_ridge_regression_terminate'
//

// Include files
#include "logit_matrix_ridge_regression_terminate.h"
#include "_coder_logit_matrix_ridge_regression_mex.h"
#include "logit_matrix_ridge_regression_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void logit_matrix_ridge_regression_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void logit_matrix_ridge_regression_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (logit_matrix_ridge_regression_terminate.cpp)
