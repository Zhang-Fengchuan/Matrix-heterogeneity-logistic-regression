//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// pinv.h
//
// Code generation for function 'pinv'
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
namespace coder {
void eml_pinv(const emlrtStack &sp, const ::coder::array<real_T, 2U> &A,
              ::coder::array<real_T, 2U> &X);

}

// End of code generation (pinv.h)
