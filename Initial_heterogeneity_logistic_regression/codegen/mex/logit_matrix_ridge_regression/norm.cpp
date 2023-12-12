//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// norm.cpp
//
// Code generation for function 'norm'
//

// Include files
#include "norm.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>

// Function Definitions
namespace coder {
real_T b_norm(const ::coder::array<real_T, 1U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T y;
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    n_t = (ptrdiff_t)x.size(0);
    incx_t = (ptrdiff_t)1;
    y = dnrm2(&n_t, &(((::coder::array<real_T, 1U> *)&x)->data())[0], &incx_t);
  }
  return y;
}

} // namespace coder

// End of code generation (norm.cpp)
