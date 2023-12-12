//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rand.cpp
//
// Code generation for function 'rand'
//

// Include files
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtDCInfo ec_emlrtDCI{
    103,                                                           // lineNo
    30,                                                            // colNo
    "rand",                                                        // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m", // pName
    4                                                              // checkKind
};

static emlrtRTEInfo we_emlrtRTEI{
    103,                                                          // lineNo
    24,                                                           // colNo
    "rand",                                                       // fName
    "D:\\MATLAB2023A\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m" // pName
};

// Function Definitions
namespace coder {
void b_rand(const emlrtStack &sp, real_T varargin_1,
            ::coder::array<real_T, 1U> &r)
{
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &ec_emlrtDCI, (emlrtConstCTX)&sp);
  }
  r.set_size(&we_emlrtRTEI, &sp, static_cast<int32_T>(varargin_1));
  if (static_cast<int32_T>(varargin_1) != 0) {
    emlrtRandu(&(r.data())[0], static_cast<int32_T>(varargin_1));
  }
}

} // namespace coder

// End of code generation (rand.cpp)
