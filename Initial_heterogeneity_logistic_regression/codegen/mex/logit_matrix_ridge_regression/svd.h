//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd.h
//
// Code generation for function 'svd'
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
namespace internal {
void svd(const emlrtStack &sp, const ::coder::array<real_T, 2U> &A,
         ::coder::array<real_T, 2U> &U, ::coder::array<real_T, 1U> &s,
         ::coder::array<real_T, 2U> &V);

}
} // namespace coder

// End of code generation (svd.h)
