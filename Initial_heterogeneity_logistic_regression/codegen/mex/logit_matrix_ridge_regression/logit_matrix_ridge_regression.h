//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// logit_matrix_ridge_regression.h
//
// Code generation for function 'logit_matrix_ridge_regression'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void logit_matrix_ridge_regression(
    const emlrtStack *sp, const coder::array<real_T, 3U> &x,
    const coder::array<real_T, 1U> &y, real_T n, real_T row_size,
    real_T col_size, real_T cv_number, coder::array<real_T, 1U> &coefficients0,
    real_T tuning_start, real_T tuning_end, real_T tuning_number,
    real_T eps_initial, real_T iter_max_initial_in, real_T if_fix,
    coder::array<real_T, 1U> &beta_part, coder::array<real_T, 1U> &gamma_part,
    real_T *lambda_best, real_T *iter_initial_in, real_T *diff_loglikelihood);

// End of code generation (logit_matrix_ridge_regression.h)
