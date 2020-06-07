//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  q2R.cpp
//
//  Code generation for function 'q2R'
//


// Include files
#include "q2R.h"
#include <cmath>
#include <cstring>

// Function Definitions
void q2R(const double q[4], double R[9])
{
  double b;
  double normRowMatrix_idx_0;
  double normRowMatrix_idx_1;
  double normRowMatrix_idx_2;
  double tempR_tmp;
  double b_tempR_tmp;
  double tempR[9];
  double c_tempR_tmp;
  double d_tempR_tmp;
  double e_tempR_tmp;
  double f_tempR_tmp;
  b = 1.0 / std::sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3] * q[3]);
  normRowMatrix_idx_0 = q[0] * b;
  normRowMatrix_idx_1 = q[1] * b;
  normRowMatrix_idx_2 = q[2] * b;
  b *= q[3];
  tempR_tmp = b * b;
  b_tempR_tmp = normRowMatrix_idx_2 * normRowMatrix_idx_2;
  tempR[0] = 1.0 - 2.0 * (b_tempR_tmp + tempR_tmp);
  c_tempR_tmp = normRowMatrix_idx_1 * normRowMatrix_idx_2;
  d_tempR_tmp = normRowMatrix_idx_0 * b;
  tempR[1] = 2.0 * (c_tempR_tmp - d_tempR_tmp);
  e_tempR_tmp = normRowMatrix_idx_1 * b;
  f_tempR_tmp = normRowMatrix_idx_0 * normRowMatrix_idx_2;
  tempR[2] = 2.0 * (e_tempR_tmp + f_tempR_tmp);
  tempR[3] = 2.0 * (c_tempR_tmp + d_tempR_tmp);
  c_tempR_tmp = normRowMatrix_idx_1 * normRowMatrix_idx_1;
  tempR[4] = 1.0 - 2.0 * (c_tempR_tmp + tempR_tmp);
  tempR_tmp = normRowMatrix_idx_2 * b;
  d_tempR_tmp = normRowMatrix_idx_0 * normRowMatrix_idx_1;
  tempR[5] = 2.0 * (tempR_tmp - d_tempR_tmp);
  tempR[6] = 2.0 * (e_tempR_tmp - f_tempR_tmp);
  tempR[7] = 2.0 * (tempR_tmp + d_tempR_tmp);
  tempR[8] = 1.0 - 2.0 * (c_tempR_tmp + b_tempR_tmp);
  std::memcpy(&R[0], &tempR[0], 9U * sizeof(double));
  for (int k = 0; k < 3; k++) {
    int R_tmp;
    R_tmp = 3 * k;
    R[k] = tempR[R_tmp];
    R[k + 3] = tempR[R_tmp + 1];
    R[k + 6] = tempR[R_tmp + 2];
  }
}

// End of code generation (q2R.cpp)
