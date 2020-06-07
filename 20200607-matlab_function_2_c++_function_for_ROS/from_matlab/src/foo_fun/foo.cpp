//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  foo.cpp
//
//  Code generation for function 'foo'
//


// Include files
#include "foo.h"

// Function Definitions
void foo(const coder::array<double, 2U> &a, const coder::array<double, 2U> &b,
         coder::array<double, 2U> &c)
{
  int mc;
  int inner;
  int nc;
  mc = a.size(0);
  inner = a.size(1);
  nc = b.size(1);
  c.set_size(a.size(0), b.size(1));
  for (int j = 0; j < nc; j++) {
    int coffset;
    int boffset;
    int i;
    coffset = j * mc;
    boffset = j * b.size(0);
    for (i = 0; i < mc; i++) {
      c[coffset + i] = 0.0;
    }

    for (int k = 0; k < inner; k++) {
      int aoffset;
      double bkj;
      aoffset = k * a.size(0);
      bkj = b[boffset + k];
      for (i = 0; i < mc; i++) {
        int b_i;
        b_i = coffset + i;
        c[b_i] = c[b_i] + a[aoffset + i] * bkj;
      }
    }
  }
}

// End of code generation (foo.cpp)
