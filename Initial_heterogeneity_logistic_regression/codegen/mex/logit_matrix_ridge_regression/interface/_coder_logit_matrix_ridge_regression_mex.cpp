//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_logit_matrix_ridge_regression_mex.cpp
//
// Code generation for function '_coder_logit_matrix_ridge_regression_mex'
//

// Include files
#include "_coder_logit_matrix_ridge_regression_mex.h"
#include "_coder_logit_matrix_ridge_regression_api.h"
#include "logit_matrix_ridge_regression_data.h"
#include "logit_matrix_ridge_regression_initialize.h"
#include "logit_matrix_ridge_regression_terminate.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void logit_matrix_ridge_regression_mexFunction(int32_T nlhs, mxArray *plhs[5],
                                               int32_T nrhs,
                                               const mxArray *prhs[13])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[5];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 13) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 13, 4,
                        29, "logit_matrix_ridge_regression");
  }
  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 29,
                        "logit_matrix_ridge_regression");
  }
  // Call the function.
  c_logit_matrix_ridge_regression(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&logit_matrix_ridge_regression_atexit);
  // Module initialization.
  logit_matrix_ridge_regression_initialize();
  try {
    // Dispatch the entry-point.
    logit_matrix_ridge_regression_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    logit_matrix_ridge_regression_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "GBK", true);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_logit_matrix_ridge_regression_mex.cpp)
