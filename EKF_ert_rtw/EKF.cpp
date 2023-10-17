//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: EKF.cpp
//
// Code generated for Simulink model 'EKF'.
//
// Model version                  : 13.7
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri Aug 18 20:35:06 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "EKF.h"
#include "rtwtypes.h"
#include <cstring>
#include <cmath>
#include <stddef.h>
#define NumBitsPerChar                 8U

// Exported block parameters
real_T R_n[36] = { 0.20255922, 0.00517515015, -0.0316669361, -0.000176503506,
  -3.74891174E-5, -7.75657503E-5, 0.00517515015, 0.155389381, 0.0107780468,
  -2.90511952E-5, -8.02931174E-6, -1.26277622E-5, -0.0316669361, 0.0107780468,
  0.393162684, 9.29630074E-5, 1.22496815E-5, 5.67092127E-5, -0.000176503506,
  -2.90511952E-5, 9.29630074E-5, 1.80161545E-5, -2.27002599E-9, -6.07376965E-7,
  -3.74891174E-5, -8.02931174E-6, 1.22496815E-5, -2.27002599E-9, 6.7014406E-6,
  2.97298687E-8, -7.75657503E-5, -1.26277622E-5, 5.67092127E-5, -6.07376965E-7,
  2.97298687E-8, 8.52192033E-6 } ;     // Variable: R_n
                                          //  Referenced by:
                                          //    '<S3>/Kalman corrector'
                                          //    '<S3>/Unit Delay - P'
                                          //  (measurement noise variance) Matrices


extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0.0F } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result = (boolean_T) 0;
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
real_T EKF::norm(const real_T x[36])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 6)) {
    real_T s;
    s = 0.0;
    for (int32_T i = 0; i < 6; i++) {
      s += std::abs(x[6 * j + i]);
    }

    if (rtIsNaN(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::mpower(const real_T a[36], real_T b, real_T c[36])
{
  real_T aBuffer[36];
  real_T b_a[36];
  real_T cBuffer[36];
  real_T cBuffer_0[36];
  real_T cBuffer_1[36];
  real_T e;
  e = std::abs(b);
  if (e <= 2.147483647E+9) {
    int32_T b_n;
    int32_T n;
    int32_T nb;
    int32_T nbitson;
    std::memcpy(&b_a[0], &a[0], 36U * sizeof(real_T));
    n = static_cast<int32_T>(e);
    b_n = static_cast<int32_T>(e);
    nbitson = 0;
    nb = -2;
    while (b_n > 0) {
      nb++;
      if ((static_cast<uint32_T>(b_n) & 1U) != 0U) {
        nbitson++;
      }

      b_n >>= 1;
    }

    if (static_cast<int32_T>(e) <= 2) {
      if (b == 2.0) {
        for (b_n = 0; b_n < 6; b_n++) {
          for (int32_T i = 0; i < 6; i++) {
            e = 0.0;
            for (int32_T i_0 = 0; i_0 < 6; i_0++) {
              e += a[6 * i_0 + i] * a[6 * b_n + i_0];
            }

            c[i + 6 * b_n] = e;
          }
        }
      } else {
        boolean_T firstmult;
        firstmult = false;
        for (n = 0; n < 36; n++) {
          if (!firstmult) {
            firstmult = rtIsNaN(a[n]);
          }
        }

        if (firstmult) {
          for (b_n = 0; b_n < 36; b_n++) {
            c[b_n] = (rtNaN);
          }
        } else {
          std::memset(&c[0], 0, 36U * sizeof(real_T));
          for (n = 0; n < 6; n++) {
            c[n + 6 * n] = 1.0;
          }
        }
      }
    } else {
      real_T ed2;
      boolean_T aBufferInUse;
      boolean_T cBufferInUse;
      boolean_T firstmult;
      firstmult = true;
      aBufferInUse = false;
      cBufferInUse = ((static_cast<uint32_T>(nbitson) & 1U) == 0U);
      for (nbitson = 0; nbitson <= nb; nbitson++) {
        if ((static_cast<uint32_T>(n) & 1U) != 0U) {
          if (firstmult) {
            firstmult = false;
            if (cBufferInUse) {
              if (aBufferInUse) {
                std::memcpy(&cBuffer[0], &aBuffer[0], 36U * sizeof(real_T));
              } else {
                std::memcpy(&cBuffer[0], &b_a[0], 36U * sizeof(real_T));
              }
            } else if (aBufferInUse) {
              std::memcpy(&c[0], &aBuffer[0], 36U * sizeof(real_T));
            } else {
              std::memcpy(&c[0], &b_a[0], 36U * sizeof(real_T));
            }
          } else {
            if (aBufferInUse) {
              if (cBufferInUse) {
                for (b_n = 0; b_n < 6; b_n++) {
                  for (int32_T i = 0; i < 6; i++) {
                    e = 0.0;
                    for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                      e += cBuffer[6 * i_0 + b_n] * aBuffer[6 * i + i_0];
                    }

                    c[b_n + 6 * i] = e;
                  }
                }
              } else {
                for (b_n = 0; b_n < 6; b_n++) {
                  for (int32_T i = 0; i < 6; i++) {
                    e = 0.0;
                    for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                      e += c[6 * i_0 + b_n] * aBuffer[6 * i + i_0];
                    }

                    cBuffer[b_n + 6 * i] = e;
                  }
                }
              }
            } else if (cBufferInUse) {
              for (b_n = 0; b_n < 6; b_n++) {
                for (int32_T i = 0; i < 6; i++) {
                  e = 0.0;
                  for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                    e += cBuffer[6 * i_0 + b_n] * b_a[6 * i + i_0];
                  }

                  c[b_n + 6 * i] = e;
                }
              }
            } else {
              for (b_n = 0; b_n < 6; b_n++) {
                for (int32_T i = 0; i < 6; i++) {
                  e = 0.0;
                  for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                    e += c[6 * i_0 + b_n] * b_a[6 * i + i_0];
                  }

                  cBuffer[b_n + 6 * i] = e;
                }
              }
            }

            cBufferInUse = !cBufferInUse;
          }
        }

        n >>= 1;
        if (aBufferInUse) {
          for (b_n = 0; b_n < 6; b_n++) {
            for (int32_T i = 0; i < 6; i++) {
              ed2 = 0.0;
              for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                ed2 += aBuffer[6 * i_0 + b_n] * aBuffer[6 * i + i_0];
              }

              b_a[b_n + 6 * i] = ed2;
            }
          }
        } else {
          for (b_n = 0; b_n < 6; b_n++) {
            for (int32_T i = 0; i < 6; i++) {
              e = 0.0;
              for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                e += b_a[6 * i_0 + b_n] * b_a[6 * i + i_0];
              }

              aBuffer[b_n + 6 * i] = e;
            }
          }
        }

        aBufferInUse = !aBufferInUse;
      }

      for (b_n = 0; b_n < 6; b_n++) {
        for (int32_T i = 0; i < 6; i++) {
          e = 0.0;
          ed2 = 0.0;
          for (int32_T i_0 = 0; i_0 < 6; i_0++) {
            real_T cBuffer_2;
            cBuffer_2 = cBuffer[6 * i_0 + i];
            n = 6 * b_n + i_0;
            e += aBuffer[n] * cBuffer_2;
            ed2 += b_a[n] * cBuffer_2;
          }

          n = 6 * b_n + i;
          cBuffer_1[n] = ed2;
          cBuffer_0[n] = e;
        }
      }

      for (b_n = 0; b_n < 36; b_n++) {
        if (firstmult) {
          if (aBufferInUse) {
            c[b_n] = aBuffer[b_n];
          } else {
            c[b_n] = b_a[b_n];
          }
        } else if (aBufferInUse) {
          c[b_n] = cBuffer_0[b_n];
        } else {
          c[b_n] = cBuffer_1[b_n];
        }
      }
    }
  } else {
    std::memcpy(&b_a[0], &a[0], 36U * sizeof(real_T));
    if ((!rtIsInf(b)) && (!rtIsNaN(b))) {
      boolean_T firstmult;
      firstmult = true;
      real_T ed2;
      int32_T exitg1;
      do {
        exitg1 = 0;
        ed2 = std::floor(e / 2.0);
        if (2.0 * ed2 != e) {
          if (firstmult) {
            std::memcpy(&c[0], &b_a[0], 36U * sizeof(real_T));
            firstmult = false;
          } else {
            for (int32_T b_n = 0; b_n < 6; b_n++) {
              for (int32_T i = 0; i < 6; i++) {
                e = 0.0;
                for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                  e += c[6 * i_0 + b_n] * b_a[6 * i + i_0];
                }

                cBuffer[b_n + 6 * i] = e;
              }
            }

            std::memcpy(&c[0], &cBuffer[0], 36U * sizeof(real_T));
          }
        }

        if (ed2 == 0.0) {
          exitg1 = 1;
        } else {
          e = ed2;
          for (int32_T b_n = 0; b_n < 6; b_n++) {
            for (int32_T i = 0; i < 6; i++) {
              ed2 = 0.0;
              for (int32_T i_0 = 0; i_0 < 6; i_0++) {
                ed2 += b_a[6 * i_0 + b_n] * b_a[6 * i + i_0];
              }

              cBuffer[b_n + 6 * i] = ed2;
            }
          }

          std::memcpy(&b_a[0], &cBuffer[0], 36U * sizeof(real_T));
        }
      } while (exitg1 == 0);
    } else {
      for (int32_T b_n = 0; b_n < 36; b_n++) {
        c[b_n] = (rtNaN);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
real_T EKF::log2_e(real_T x)
{
  real_T f;
  int32_T inte;
  if (x == 0.0) {
    f = (rtMinusInf);
  } else if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    real_T t;
    t = std::frexp(x, &inte);
    if (t == 0.5) {
      f = static_cast<real_T>(inte) - 1.0;
    } else if ((inte == 1) && (t < 0.75)) {
      f = std::log(2.0 * t) / 0.69314718055994529;
    } else {
      f = std::log(t) / 0.69314718055994529 + static_cast<real_T>(inte);
    }
  } else {
    f = x;
  }

  return f;
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::padeApproximation(const real_T A[36], const real_T A2[36], const
  real_T A4[36], const real_T A6[36], int32_T m, real_T F[36])
{
  real_T A6_0[36];
  real_T V[36];
  real_T d;
  int32_T F_tmp;
  int32_T b_ix;
  int32_T d_tmp;
  int32_T ix;
  int32_T iy;
  int32_T jj;
  int8_T ipiv[6];
  switch (m) {
   case 3:
    std::memcpy(&F[0], &A2[0], 36U * sizeof(real_T));
    for (int32_T e_k = 0; e_k < 6; e_k++) {
      F_tmp = 6 * e_k + e_k;
      F[F_tmp] += 60.0;
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A[6 * jj + e_k] * F[6 * d_tmp + jj];
        }

        A6_0[e_k + 6 * d_tmp] = d;
      }
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = A6_0[d_tmp];
      V[d_tmp] = 12.0 * A2[d_tmp];
    }

    d = 120.0;
    break;

   case 5:
    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = 420.0 * A2[d_tmp] + A4[d_tmp];
    }

    for (int32_T e_k = 0; e_k < 6; e_k++) {
      F_tmp = 6 * e_k + e_k;
      F[F_tmp] += 15120.0;
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A[6 * jj + e_k] * F[6 * d_tmp + jj];
        }

        A6_0[e_k + 6 * d_tmp] = d;
      }
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = A6_0[d_tmp];
      V[d_tmp] = 30.0 * A4[d_tmp] + 3360.0 * A2[d_tmp];
    }

    d = 30240.0;
    break;

   case 7:
    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = (1512.0 * A4[d_tmp] + A6[d_tmp]) + 277200.0 * A2[d_tmp];
    }

    for (int32_T e_k = 0; e_k < 6; e_k++) {
      F_tmp = 6 * e_k + e_k;
      F[F_tmp] += 8.64864E+6;
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A[6 * jj + e_k] * F[6 * d_tmp + jj];
        }

        A6_0[e_k + 6 * d_tmp] = d;
      }
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = A6_0[d_tmp];
      V[d_tmp] = (56.0 * A6[d_tmp] + 25200.0 * A4[d_tmp]) + 1.99584E+6 *
        A2[d_tmp];
    }

    d = 1.729728E+7;
    break;

   case 9:
    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A6[6 * jj + e_k] * A2[6 * d_tmp + jj];
        }

        V[e_k + 6 * d_tmp] = d;
      }
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = ((3960.0 * A6[d_tmp] + V[d_tmp]) + 2.16216E+6 * A4[d_tmp]) +
        3.027024E+8 * A2[d_tmp];
    }

    for (int32_T e_k = 0; e_k < 6; e_k++) {
      F_tmp = 6 * e_k + e_k;
      F[F_tmp] += 8.8216128E+9;
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A[6 * jj + e_k] * F[6 * d_tmp + jj];
        }

        A6_0[e_k + 6 * d_tmp] = d;
      }
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = A6_0[d_tmp];
      V[d_tmp] = ((90.0 * V[d_tmp] + 110880.0 * A6[d_tmp]) + 3.027024E+7 *
                  A4[d_tmp]) + 2.0756736E+9 * A2[d_tmp];
    }

    d = 1.76432256E+10;
    break;

   default:
    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      F[d_tmp] = (3.352212864E+10 * A6[d_tmp] + 1.05594705216E+13 * A4[d_tmp]) +
        1.1873537964288E+15 * A2[d_tmp];
    }

    for (int32_T e_k = 0; e_k < 6; e_k++) {
      F_tmp = 6 * e_k + e_k;
      F[F_tmp] += 3.238237626624E+16;
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      V[d_tmp] = (16380.0 * A4[d_tmp] + A6[d_tmp]) + 4.08408E+7 * A2[d_tmp];
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A6[6 * jj + d_tmp] * V[6 * e_k + jj];
        }

        jj = 6 * e_k + d_tmp;
        A6_0[jj] = F[jj] + d;
      }
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A[6 * jj + e_k] * A6_0[6 * d_tmp + jj];
        }

        F[e_k + 6 * d_tmp] = d;
      }
    }

    for (d_tmp = 0; d_tmp < 36; d_tmp++) {
      A6_0[d_tmp] = (182.0 * A6[d_tmp] + 960960.0 * A4[d_tmp]) + 1.32324192E+9 *
        A2[d_tmp];
    }

    for (d_tmp = 0; d_tmp < 6; d_tmp++) {
      for (int32_T e_k = 0; e_k < 6; e_k++) {
        d = 0.0;
        for (jj = 0; jj < 6; jj++) {
          d += A6[6 * jj + d_tmp] * A6_0[6 * e_k + jj];
        }

        jj = 6 * e_k + d_tmp;
        V[jj] = ((A6[jj] * 6.704425728E+11 + d) + A4[jj] * 1.29060195264E+14) +
          A2[jj] * 7.7717703038976E+15;
      }
    }

    d = 6.476475253248E+16;
    break;
  }

  for (int32_T e_k = 0; e_k < 6; e_k++) {
    jj = 6 * e_k + e_k;
    V[jj] += d;
  }

  for (int32_T e_k = 0; e_k < 36; e_k++) {
    d = F[e_k];
    V[e_k] -= d;
    F[e_k] = 2.0 * d;
  }

  for (d_tmp = 0; d_tmp < 6; d_tmp++) {
    ipiv[d_tmp] = static_cast<int8_T>(d_tmp + 1);
  }

  for (int32_T e_k = 0; e_k < 5; e_k++) {
    jj = e_k * 7;
    iy = 6 - e_k;
    b_ix = 0;
    ix = jj;
    d = std::abs(V[jj]);
    for (int32_T k_k = 2; k_k <= iy; k_k++) {
      real_T s;
      ix++;
      s = std::abs(V[ix]);
      if (s > d) {
        b_ix = k_k - 1;
        d = s;
      }
    }

    if (V[jj + b_ix] != 0.0) {
      if (b_ix != 0) {
        iy = e_k + b_ix;
        ipiv[e_k] = static_cast<int8_T>(iy + 1);
        for (ix = 0; ix < 6; ix++) {
          d_tmp = ix * 6 + e_k;
          d = V[d_tmp];
          V[d_tmp] = V[iy];
          V[iy] = d;
          iy += 6;
        }
      }

      iy = (jj - e_k) + 6;
      for (b_ix = jj + 2; b_ix <= iy; b_ix++) {
        V[b_ix - 1] /= V[jj];
      }
    }

    iy = jj + 6;
    b_ix = jj + 8;
    ix = 4 - e_k;
    for (int32_T k_k = 0; k_k <= ix; k_k++) {
      d = V[iy];
      if (V[iy] != 0.0) {
        d_tmp = (b_ix - e_k) + 4;
        for (F_tmp = b_ix; F_tmp <= d_tmp; F_tmp++) {
          V[F_tmp - 1] += V[((jj + F_tmp) - b_ix) + 1] * -d;
        }
      }

      iy += 6;
      b_ix += 6;
    }
  }

  for (int32_T e_k = 0; e_k < 5; e_k++) {
    int8_T ipiv_0;
    ipiv_0 = ipiv[e_k];
    if (e_k + 1 != ipiv_0) {
      for (iy = 0; iy < 6; iy++) {
        d_tmp = 6 * iy + e_k;
        d = F[d_tmp];
        F_tmp = (6 * iy + ipiv_0) - 1;
        F[d_tmp] = F[F_tmp];
        F[F_tmp] = d;
      }
    }
  }

  for (int32_T e_k = 0; e_k < 6; e_k++) {
    jj = 6 * e_k;
    for (iy = 0; iy < 6; iy++) {
      b_ix = 6 * iy;
      d_tmp = iy + jj;
      if (F[d_tmp] != 0.0) {
        for (ix = iy + 2; ix < 7; ix++) {
          F_tmp = (ix + jj) - 1;
          F[F_tmp] -= V[(ix + b_ix) - 1] * F[d_tmp];
        }
      }
    }
  }

  for (int32_T e_k = 0; e_k < 6; e_k++) {
    jj = 6 * e_k;
    for (iy = 5; iy >= 0; iy--) {
      b_ix = 6 * iy;
      d_tmp = iy + jj;
      d = F[d_tmp];
      if (d != 0.0) {
        F[d_tmp] = d / V[iy + b_ix];
        for (int32_T k_k = 0; k_k < iy; k_k++) {
          F_tmp = k_k + jj;
          F[F_tmp] -= V[k_k + b_ix] * F[d_tmp];
        }
      }
    }
  }

  for (int32_T e_k = 0; e_k < 6; e_k++) {
    F_tmp = 6 * e_k + e_k;
    F[F_tmp]++;
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::recomputeBlockDiag(const real_T A[36], real_T F[36], const int32_T
  blockFormat[5])
{
  for (int32_T j = 0; j < 5; j++) {
    switch (blockFormat[j]) {
     case 0:
      break;

     case 1:
      {
        real_T A_0;
        real_T A_1;
        real_T delta;
        real_T expa;
        real_T sinchdelta;
        real_T u1;
        int32_T A_tmp;
        int32_T A_tmp_0;
        A_tmp_0 = 6 * j + j;
        A_0 = A[A_tmp_0];
        delta = std::exp(A_0);
        A_tmp = (j + 1) * 6 + j;
        A_1 = A[A_tmp + 1];
        expa = std::exp(A_1);
        sinchdelta = (A_1 + A_0) / 2.0;
        u1 = std::abs(A_0 - A_1) / 2.0;
        if ((sinchdelta >= u1) || rtIsNaN(u1)) {
          u1 = sinchdelta;
        }

        if (u1 < 709.782712893384) {
          A_0 = (A_1 - A_0) / 2.0;
          if (A_0 == 0.0) {
            A_0 = 1.0;
          } else {
            A_0 = std::sinh(A_0) / A_0;
          }

          sinchdelta = A[A_tmp] * std::exp(sinchdelta) * A_0;
        } else {
          sinchdelta = (expa - delta) * A[A_tmp] / (A_1 - A_0);
        }

        F[A_tmp_0] = delta;
        F[A_tmp] = sinchdelta;
        F[A_tmp + 1] = expa;
      }
      break;

     default:
      {
        real_T A_0;
        real_T A_1;
        real_T delta;
        real_T expa;
        real_T sinchdelta;
        int32_T A_tmp;
        int32_T A_tmp_0;
        A_tmp_0 = (j + 1) * 6 + j;
        A_0 = A[A_tmp_0];
        A_tmp = 6 * j + j;
        A_1 = A[A_tmp + 1];
        delta = std::sqrt(std::abs(A_0 * A_1));
        expa = std::exp(A[A_tmp]);
        if (delta == 0.0) {
          sinchdelta = 1.0;
        } else {
          sinchdelta = std::sin(delta) / delta;
        }

        delta = expa * std::cos(delta);
        F[A_tmp] = delta;
        F[A_tmp + 1] = A_1 * expa * sinchdelta;
        F[A_tmp_0] = A_0 * expa * sinchdelta;
        F[A_tmp_0 + 1] = delta;
      }
      break;
    }
  }

  if (blockFormat[4] == 0) {
    F[35] = std::exp(A[35]);
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
real_T EKF::xnrm2(int32_T n, const real_T x[36], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C[36],
                 int32_T ic0, real_T work[6])
{
  int32_T coltop;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = (lastc - 1) * 6 + ic0;
      jA = coltop;
      do {
        exitg1 = 0;
        if (jA <= (coltop + lastv) - 1) {
          if (C[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T e;
    if (lastc != 0) {
      std::memset(&work[0], 0, static_cast<uint8_T>(lastc) * sizeof(real_T));
      d = (lastc - 1) * 6 + ic0;
      for (coltop = ic0; coltop <= d; coltop += 6) {
        c = 0.0;
        e = coltop + lastv;
        for (jA = coltop; jA < e; jA++) {
          c += C[((iv0 + jA) - coltop) - 1] * C[jA - 1];
        }

        jA = div_nde_s32_floor(coltop - ic0, 6);
        work[jA] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = static_cast<uint8_T>(lastc);
      for (lastc = 0; lastc < d; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          e = lastv + jA;
          for (coltop = jA; coltop < e; coltop++) {
            C[coltop - 1] += C[((iv0 + coltop) - jA) - 1] * c;
          }
        }

        jA += 6;
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
real_T EKF::xnrm2_b(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[1]);
    } else {
      real_T absxk;
      real_T scale;
      real_T t;
      scale = 3.3121686421112381E-170;
      absxk = std::abs(x[1]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }

      absxk = std::abs(x[2]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r,
                  real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T
                  *sn)
{
  real_T bcmax;
  real_T bcmis;
  real_T p;
  real_T scale;
  real_T temp;
  real_T z;
  int32_T count;
  int32_T tmp;
  boolean_T tmp_0;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    temp = *d;
    *d = *a;
    *a = temp;
    *b = -*c;
    *c = 0.0;
  } else {
    temp = *a - *d;
    if ((temp == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * temp;
      bcmis = std::abs(*b);
      scale = std::abs(*c);
      tmp_0 = rtIsNaN(scale);
      if ((bcmis >= scale) || tmp_0) {
        bcmax = bcmis;
      } else {
        bcmax = scale;
      }

      if ((bcmis <= scale) || tmp_0) {
        scale = bcmis;
      }

      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }

      if (!(*c < 0.0)) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      bcmis = scale * static_cast<real_T>(count) * static_cast<real_T>(tmp);
      scale = std::abs(p);
      if ((!(scale >= bcmax)) && (!rtIsNaN(bcmax))) {
        scale = bcmax;
      }

      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        if (!(p < 0.0)) {
          temp = std::sqrt(scale) * std::sqrt(z);
        } else {
          temp = -(std::sqrt(scale) * std::sqrt(z));
        }

        z = p + temp;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        bcmax = rt_hypotd_snf(*c, z);
        *cs = z / bcmax;
        *sn = *c / bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        p = *b + *c;
        bcmis = std::abs(temp);
        scale = std::abs(p);
        if ((bcmis >= scale) || rtIsNaN(scale)) {
          scale = bcmis;
        }

        count = 0;
        while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
          p *= 1.3435752215134178E-138;
          temp *= 1.3435752215134178E-138;
          bcmis = std::abs(temp);
          scale = std::abs(p);
          if ((bcmis >= scale) || rtIsNaN(scale)) {
            scale = bcmis;
          }

          count++;
        }

        while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
          p *= 7.4428285367870146E+137;
          temp *= 7.4428285367870146E+137;
          bcmis = std::abs(temp);
          scale = std::abs(p);
          if ((bcmis >= scale) || rtIsNaN(scale)) {
            scale = bcmis;
          }

          count++;
        }

        bcmax = rt_hypotd_snf(p, temp);
        *cs = std::sqrt((std::abs(p) / bcmax + 1.0) * 0.5);
        if (!(p < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }

        *sn = -(0.5 * temp / (bcmax * *cs)) * static_cast<real_T>(count);
        temp = *a * *cs + *b * *sn;
        p = -*a * *sn + *b * *cs;
        bcmax = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = p * *cs + bcmis * *sn;
        *c = -temp * *sn + bcmax * *cs;
        temp = ((temp * *cs + bcmax * *sn) + (-p * *sn + bcmis * *cs)) * 0.5;
        *a = temp;
        *d = temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              scale = std::sqrt(std::abs(*b));
              bcmis = std::sqrt(std::abs(*c));
              p = scale * bcmis;
              if (*c < 0.0) {
                p = -p;
              }

              bcmax = 1.0 / std::sqrt(std::abs(*b + *c));
              *a = temp + p;
              *d = temp - p;
              *b -= *c;
              *c = 0.0;
              p = scale * bcmax;
              bcmax *= bcmis;
              temp = *cs * p - *sn * bcmax;
              *sn = *cs * bcmax + *sn * p;
              *cs = temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            temp = *cs;
            *cs = -*sn;
            *sn = temp;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = std::sqrt(std::abs(*b)) * std::sqrt(std::abs(*c));
    *rt2i = -*rt1i;
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::xrot(int32_T n, real_T x[36], int32_T ix0, int32_T iy0, real_T c,
               real_T s)
{
  if (n >= 1) {
    int32_T b;
    b = static_cast<uint8_T>(n);
    for (int32_T k = 0; k < b; k++) {
      real_T temp_tmp;
      real_T temp_tmp_0;
      int32_T temp_tmp_tmp;
      int32_T temp_tmp_tmp_0;
      temp_tmp_tmp = (iy0 + k) - 1;
      temp_tmp = x[temp_tmp_tmp];
      temp_tmp_tmp_0 = (ix0 + k) - 1;
      temp_tmp_0 = x[temp_tmp_tmp_0];
      x[temp_tmp_tmp] = temp_tmp * c - temp_tmp_0 * s;
      x[temp_tmp_tmp_0] = temp_tmp_0 * c + temp_tmp * s;
    }
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
int32_T EKF::xhseqr(real_T h[36], real_T z[36])
{
  real_T v[3];
  real_T aa;
  real_T bb;
  real_T h11;
  real_T h12;
  real_T h21;
  real_T tst;
  real_T tst_tmp_0;
  real_T tst_tmp_1;
  real_T tst_tmp_tmp;
  int32_T b_j;
  int32_T h_tmp;
  int32_T h_tmp_0;
  int32_T info;
  int32_T ix0;
  int32_T iy;
  int32_T k;
  int32_T kdefl;
  int32_T knt;
  int32_T l;
  int32_T m;
  int32_T nr;
  int32_T tst_tmp;
  boolean_T converged;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T tmp;
  info = 0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[9] = 0.0;
  h[10] = 0.0;
  h[16] = 0.0;
  h[17] = 0.0;
  h[23] = 0.0;
  kdefl = 0;
  b_j = 5;
  exitg1 = false;
  while ((!exitg1) && (b_j + 1 >= 1)) {
    l = 1;
    converged = false;
    iy = 0;
    exitg2 = false;
    while ((!exitg2) && (iy < 301)) {
      k = b_j;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > l)) {
        knt = (k - 1) * 6 + k;
        h12 = std::abs(h[knt]);
        if (h12 <= 6.0125050800269183E-292) {
          exitg3 = true;
        } else {
          tst_tmp = 6 * k + k;
          tst_tmp_tmp = h[tst_tmp];
          tst_tmp_0 = std::abs(tst_tmp_tmp);
          tst_tmp_1 = h[knt - 1];
          tst = std::abs(tst_tmp_1) + tst_tmp_0;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = std::abs(h[((k - 2) * 6 + k) - 1]);
            }

            if (k + 2 <= 6) {
              tst += std::abs(h[tst_tmp + 1]);
            }
          }

          if (h12 <= 2.2204460492503131E-16 * tst) {
            bb = std::abs(tst_tmp_1 - tst_tmp_tmp);
            tmp = rtIsNaN(bb);
            if ((tst_tmp_0 >= bb) || tmp) {
              aa = tst_tmp_0;
            } else {
              aa = bb;
            }

            if ((tst_tmp_0 <= bb) || tmp) {
              bb = tst_tmp_0;
            }

            tst = aa + bb;
            h21 = std::abs(h[tst_tmp - 1]);
            bb = aa / tst * bb * 2.2204460492503131E-16;
            tmp = rtIsNaN(h21);
            if ((h12 <= h21) || tmp) {
              aa = h12;
            } else {
              aa = h21;
            }

            if ((h12 >= h21) || tmp) {
              h21 = h12;
            }

            if ((bb <= 6.0125050800269183E-292) || rtIsNaN(bb)) {
              bb = 6.0125050800269183E-292;
            }

            if (h21 / tst * aa <= bb) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      l = k + 1;
      if (k + 1 > 1) {
        h[k + 6 * (k - 1)] = 0.0;
      }

      if (k + 1 >= b_j) {
        converged = true;
        exitg2 = true;
      } else {
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          tst = std::abs(h[((b_j - 2) * 6 + b_j) - 1]) + std::abs(h[(b_j - 1) *
            6 + b_j]);
          h11 = h[6 * b_j + b_j] + 0.75 * tst;
          h12 = -0.4375 * tst;
          h21 = tst;
          aa = h11;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          tst_tmp = 6 * k + k;
          tst = std::abs(h[((k + 1) * 6 + k) + 2]) + std::abs(h[tst_tmp + 1]);
          h11 = 0.75 * tst + h[tst_tmp];
          h12 = -0.4375 * tst;
          h21 = tst;
          aa = h11;
        } else {
          tst_tmp = (b_j - 1) * 6 + b_j;
          h11 = h[tst_tmp - 1];
          h21 = h[tst_tmp];
          tst_tmp = 6 * b_j + b_j;
          h12 = h[tst_tmp - 1];
          aa = h[tst_tmp];
        }

        tst = ((std::abs(h11) + std::abs(h12)) + std::abs(h21)) + std::abs(aa);
        if (tst == 0.0) {
          h11 = 0.0;
          aa = 0.0;
          bb = 0.0;
          h21 = 0.0;
        } else {
          h11 /= tst;
          aa /= tst;
          bb = (h11 + aa) / 2.0;
          h11 = (h11 - bb) * (aa - bb) - h12 / tst * (h21 / tst);
          h21 = std::sqrt(std::abs(h11));
          if (h11 >= 0.0) {
            h11 = bb * tst;
            bb = h11;
            aa = h21 * tst;
            h21 = -aa;
          } else {
            h11 = bb + h21;
            bb -= h21;
            if (std::abs(h11 - aa) <= std::abs(bb - aa)) {
              h11 *= tst;
              bb = h11;
            } else {
              bb *= tst;
              h11 = bb;
            }

            aa = 0.0;
            h21 = 0.0;
          }
        }

        m = b_j - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          tst_tmp = (m - 1) * 6 + m;
          tst_tmp_0 = h[tst_tmp];
          tst_tmp_tmp = h[tst_tmp - 1];
          tst_tmp_1 = tst_tmp_tmp - bb;
          tst = (std::abs(tst_tmp_1) + std::abs(h21)) + std::abs(tst_tmp_0);
          h12 = tst_tmp_0 / tst;
          tst_tmp = 6 * m + m;
          v[0] = (tst_tmp_1 / tst * tst_tmp_1 + h[tst_tmp - 1] * h12) - h21 /
            tst * aa;
          tst_tmp_1 = h[tst_tmp];
          v[1] = (((tst_tmp_tmp + tst_tmp_1) - h11) - bb) * h12;
          v[2] = h[tst_tmp + 1] * h12;
          tst = (std::abs(v[0]) + std::abs(v[1])) + std::abs(v[2]);
          v[0] /= tst;
          v[1] /= tst;
          v[2] /= tst;
          if (k + 1 == m) {
            exitg3 = true;
          } else {
            knt = (m - 2) * 6 + m;
            if (std::abs(h[knt - 1]) * (std::abs(v[1]) + std::abs(v[2])) <=
                ((std::abs(h[knt - 2]) + std::abs(tst_tmp_tmp)) + std::abs
                 (tst_tmp_1)) * (2.2204460492503131E-16 * std::abs(v[0]))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }

        for (tst_tmp = m; tst_tmp <= b_j; tst_tmp++) {
          nr = (b_j - tst_tmp) + 2;
          if (nr >= 3) {
            nr = 3;
          }

          if (tst_tmp > m) {
            ix0 = ((tst_tmp - 2) * 6 + tst_tmp) - 1;
            for (knt = 0; knt < nr; knt++) {
              v[knt] = h[ix0 + knt];
            }
          }

          bb = v[0];
          tst = 0.0;
          if (nr > 0) {
            h12 = xnrm2_b(nr - 1, v);
            if (h12 != 0.0) {
              aa = rt_hypotd_snf(v[0], h12);
              if (v[0] >= 0.0) {
                aa = -aa;
              }

              if (std::abs(aa) < 1.0020841800044864E-292) {
                knt = 0;
                do {
                  knt++;
                  for (ix0 = 2; ix0 <= nr; ix0++) {
                    v[ix0 - 1] *= 9.9792015476736E+291;
                  }

                  aa *= 9.9792015476736E+291;
                  bb *= 9.9792015476736E+291;
                } while ((std::abs(aa) < 1.0020841800044864E-292) && (knt < 20));

                aa = rt_hypotd_snf(bb, xnrm2_b(nr - 1, v));
                if (bb >= 0.0) {
                  aa = -aa;
                }

                tst = (aa - bb) / aa;
                bb = 1.0 / (bb - aa);
                for (ix0 = 2; ix0 <= nr; ix0++) {
                  v[ix0 - 1] *= bb;
                }

                for (ix0 = 0; ix0 < knt; ix0++) {
                  aa *= 1.0020841800044864E-292;
                }

                bb = aa;
              } else {
                tst = (aa - v[0]) / aa;
                bb = 1.0 / (v[0] - aa);
                for (knt = 2; knt <= nr; knt++) {
                  v[knt - 1] *= bb;
                }

                bb = aa;
              }
            }
          }

          if (tst_tmp > m) {
            knt = (tst_tmp - 2) * 6 + tst_tmp;
            h[knt - 1] = bb;
            h[knt] = 0.0;
            if (tst_tmp < b_j) {
              h[knt + 1] = 0.0;
            }
          } else if (m > k + 1) {
            knt = ((tst_tmp - 2) * 6 + tst_tmp) - 1;
            h[knt] *= 1.0 - tst;
          }

          aa = v[1];
          bb = tst * v[1];
          switch (nr) {
           case 3:
            h11 = v[2];
            h21 = tst * v[2];
            for (nr = tst_tmp; nr < 7; nr++) {
              ix0 = (nr - 1) * 6 + tst_tmp;
              tst_tmp_tmp = h[ix0 - 1];
              tst_tmp_1 = h[ix0];
              tst_tmp_0 = h[ix0 + 1];
              h12 = (aa * tst_tmp_1 + tst_tmp_tmp) + h11 * tst_tmp_0;
              h[ix0 - 1] = tst_tmp_tmp - h12 * tst;
              h[ix0] = tst_tmp_1 - h12 * bb;
              h[ix0 + 1] = tst_tmp_0 - h12 * h21;
            }

            if (tst_tmp + 3 <= b_j + 1) {
              knt = tst_tmp + 3;
            } else {
              knt = b_j + 1;
            }

            for (nr = 0; nr < knt; nr++) {
              ix0 = (tst_tmp - 1) * 6 + nr;
              tst_tmp_tmp = h[ix0];
              h_tmp = 6 * tst_tmp + nr;
              tst_tmp_1 = h[h_tmp];
              h_tmp_0 = (tst_tmp + 1) * 6 + nr;
              tst_tmp_0 = h[h_tmp_0];
              h12 = (aa * tst_tmp_1 + tst_tmp_tmp) + h11 * tst_tmp_0;
              h[ix0] = tst_tmp_tmp - h12 * tst;
              h[h_tmp] = tst_tmp_1 - h12 * bb;
              h[h_tmp_0] = tst_tmp_0 - h12 * h21;
            }

            for (nr = 0; nr < 6; nr++) {
              knt = (tst_tmp - 1) * 6 + nr;
              tst_tmp_tmp = z[knt];
              ix0 = 6 * tst_tmp + nr;
              tst_tmp_1 = z[ix0];
              h_tmp = (tst_tmp + 1) * 6 + nr;
              tst_tmp_0 = z[h_tmp];
              h12 = (aa * tst_tmp_1 + tst_tmp_tmp) + h11 * tst_tmp_0;
              z[knt] = tst_tmp_tmp - h12 * tst;
              z[ix0] = tst_tmp_1 - h12 * bb;
              z[h_tmp] = tst_tmp_0 - h12 * h21;
            }
            break;

           case 2:
            for (nr = tst_tmp; nr < 7; nr++) {
              ix0 = (nr - 1) * 6 + tst_tmp;
              tst_tmp_tmp = h[ix0 - 1];
              tst_tmp_1 = h[ix0];
              h12 = aa * tst_tmp_1 + tst_tmp_tmp;
              h[ix0 - 1] = tst_tmp_tmp - h12 * tst;
              h[ix0] = tst_tmp_1 - h12 * bb;
            }

            for (nr = 0; nr <= b_j; nr++) {
              ix0 = (tst_tmp - 1) * 6 + nr;
              tst_tmp_tmp = h[ix0];
              h_tmp = 6 * tst_tmp + nr;
              tst_tmp_1 = h[h_tmp];
              h12 = aa * tst_tmp_1 + tst_tmp_tmp;
              h[ix0] = tst_tmp_tmp - h12 * tst;
              h[h_tmp] = tst_tmp_1 - h12 * bb;
            }

            for (nr = 0; nr < 6; nr++) {
              knt = (tst_tmp - 1) * 6 + nr;
              tst_tmp_tmp = z[knt];
              ix0 = 6 * tst_tmp + nr;
              tst_tmp_1 = z[ix0];
              h12 = aa * tst_tmp_1 + tst_tmp_tmp;
              z[knt] = tst_tmp_tmp - h12 * tst;
              z[ix0] = tst_tmp_1 - h12 * bb;
            }
            break;
          }
        }

        iy++;
      }
    }

    if (!converged) {
      info = b_j + 1;
      exitg1 = true;
    } else {
      if ((b_j + 1 != l) && (l == b_j)) {
        k = 6 * b_j + b_j;
        bb = h[k - 1];
        kdefl = (b_j - 1) * 6;
        tst_tmp = kdefl + b_j;
        h11 = h[tst_tmp];
        h21 = h[k];
        xdlanv2(&h[tst_tmp - 1], &bb, &h11, &h21, &h12, &tst_tmp_tmp, &tst_tmp_1,
                &tst_tmp_0, &tst, &aa);
        h[k - 1] = bb;
        h[tst_tmp] = h11;
        h[k] = h21;
        if (b_j + 1 < 6) {
          iy = (b_j + 1) * 6 + b_j;
          k = 5 - b_j;
          for (tst_tmp = 0; tst_tmp < k; tst_tmp++) {
            knt = tst_tmp * 6 + iy;
            h21 = h[knt];
            bb = h[knt - 1];
            h[knt] = h21 * tst - bb * aa;
            h[knt - 1] = bb * tst + h21 * aa;
          }
        }

        knt = b_j * 6 + 1;
        xrot(b_j - 1, h, kdefl + 1, knt, tst, aa);
        xrot(6, z, kdefl + 1, knt, tst, aa);
      }

      kdefl = 0;
      b_j = l - 2;
    }
  }

  for (b_j = 0; b_j < 4; b_j++) {
    for (l = b_j + 3; l < 7; l++) {
      h[(l + 6 * b_j) - 1] = 0.0;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::schur(const real_T A[36], real_T V[36], real_T T[36])
{
  real_T work[6];
  real_T tau[5];
  real_T A_0;
  real_T beta1;
  int32_T b_ia;
  int32_T b_ix;
  int32_T c_ia;
  int32_T exitg1;
  int32_T im1n;
  int32_T in;
  int32_T itau;
  int32_T jy;
  int32_T knt;
  int32_T l;
  int32_T lastc;
  int32_T rowleft;
  int32_T work_tmp;
  boolean_T exitg2;
  boolean_T p;
  p = true;
  for (itau = 0; itau < 36; itau++) {
    if (p) {
      A_0 = A[itau];
      if (rtIsInf(A_0) || rtIsNaN(A_0)) {
        p = false;
      }
    }
  }

  if (!p) {
    for (lastc = 0; lastc < 36; lastc++) {
      V[lastc] = (rtNaN);
    }

    itau = 2;
    for (im1n = 0; im1n < 5; im1n++) {
      if (itau <= 6) {
        std::memset(&V[(im1n * 6 + itau) + -1], 0, static_cast<uint32_T>(-itau +
          7) * sizeof(real_T));
      }

      itau++;
    }

    for (lastc = 0; lastc < 36; lastc++) {
      T[lastc] = (rtNaN);
    }
  } else {
    std::memcpy(&T[0], &A[0], 36U * sizeof(real_T));
    for (itau = 0; itau < 6; itau++) {
      work[itau] = 0.0;
    }

    for (itau = 0; itau < 5; itau++) {
      in = (itau + 1) * 6;
      im1n = 6 * itau + itau;
      A_0 = T[im1n + 1];
      if (itau + 3 <= 6) {
        lastc = itau + 3;
      } else {
        lastc = 6;
      }

      lastc += itau * 6;
      tau[itau] = 0.0;
      beta1 = xnrm2(4 - itau, T, lastc);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(A_0, beta1);
        if (A_0 >= 0.0) {
          beta1 = -beta1;
        }

        if (std::abs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          jy = (lastc - itau) + 3;
          do {
            knt++;
            for (rowleft = lastc; rowleft <= jy; rowleft++) {
              T[rowleft - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            A_0 *= 9.9792015476736E+291;
          } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt < 20));

          beta1 = rt_hypotd_snf(A_0, xnrm2(4 - itau, T, lastc));
          if (A_0 >= 0.0) {
            beta1 = -beta1;
          }

          tau[itau] = (beta1 - A_0) / beta1;
          A_0 = 1.0 / (A_0 - beta1);
          for (rowleft = lastc; rowleft <= jy; rowleft++) {
            T[rowleft - 1] *= A_0;
          }

          for (lastc = 0; lastc < knt; lastc++) {
            beta1 *= 1.0020841800044864E-292;
          }

          A_0 = beta1;
        } else {
          tau[itau] = (beta1 - A_0) / beta1;
          A_0 = 1.0 / (A_0 - beta1);
          knt = (lastc - itau) + 3;
          for (jy = lastc; jy <= knt; jy++) {
            T[jy - 1] *= A_0;
          }

          A_0 = beta1;
        }
      }

      T[im1n + 1] = 1.0;
      jy = im1n + 1;
      if (tau[itau] != 0.0) {
        knt = 4 - itau;
        lastc = (im1n - itau) + 5;
        while ((knt + 1 > 0) && (T[lastc] == 0.0)) {
          knt--;
          lastc--;
        }

        lastc = 6;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          rowleft = in + lastc;
          c_ia = rowleft;
          do {
            exitg1 = 0;
            if (c_ia <= knt * 6 + rowleft) {
              if (T[c_ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                c_ia += 6;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = -1;
        lastc = 0;
      }

      if (knt + 1 > 0) {
        if (lastc != 0) {
          std::memset(&work[0], 0, static_cast<uint32_T>(lastc) * sizeof(real_T));
          rowleft = im1n + 1;
          c_ia = (6 * knt + in) + 1;
          for (b_ix = in + 1; b_ix <= c_ia; b_ix += 6) {
            l = b_ix + lastc;
            for (b_ia = b_ix; b_ia < l; b_ia++) {
              work_tmp = b_ia - b_ix;
              work[work_tmp] += T[b_ia - 1] * T[rowleft];
            }

            rowleft++;
          }
        }

        if (!(-tau[itau] == 0.0)) {
          rowleft = in;
          for (c_ia = 0; c_ia <= knt; c_ia++) {
            if (T[jy] != 0.0) {
              beta1 = T[jy] * -tau[itau];
              b_ix = lastc + rowleft;
              for (l = rowleft + 1; l <= b_ix; l++) {
                T[l - 1] += work[(l - rowleft) - 1] * beta1;
              }
            }

            jy++;
            rowleft += 6;
          }
        }
      }

      xzlarf(5 - itau, 5 - itau, im1n + 2, tau[itau], T, (itau + in) + 2, work);
      T[im1n + 1] = A_0;
    }

    std::memcpy(&V[0], &T[0], 36U * sizeof(real_T));
    for (itau = 4; itau >= 0; itau--) {
      im1n = (itau + 1) * 6;
      for (in = 0; in <= itau; in++) {
        V[im1n + in] = 0.0;
      }

      for (in = itau + 3; in < 7; in++) {
        lastc = im1n + in;
        V[lastc - 1] = V[lastc - 7];
      }
    }

    for (im1n = 0; im1n < 6; im1n++) {
      V[im1n] = 0.0;
      work[im1n] = 0.0;
    }

    V[0] = 1.0;
    for (im1n = 4; im1n >= 0; im1n--) {
      in = (im1n * 6 + im1n) + 7;
      if (im1n + 1 < 5) {
        V[in] = 1.0;
        xzlarf(5 - im1n, 4 - im1n, in + 1, tau[im1n], V, in + 7, work);
        lastc = (in - im1n) + 5;
        for (knt = in + 2; knt <= lastc; knt++) {
          V[knt - 1] *= -tau[im1n];
        }
      }

      V[in] = 1.0 - tau[im1n];
      for (knt = 0; knt < im1n; knt++) {
        V[(in - knt) - 1] = 0.0;
      }
    }

    xhseqr(T, V);
  }
}

// Function for MATLAB Function: '<S3>/Kalman predictor'
void EKF::expm(real_T A[36], real_T F[36])
{
  real_T A2[36];
  real_T A4[36];
  real_T A4_0[36];
  real_T A6[36];
  real_T tmp[36];
  real_T tmp_0[36];
  real_T A4_1;
  real_T d6;
  real_T eta1;
  real_T exptj;
  int32_T blockFormat[5];
  int32_T b_s;
  int32_T e_i;
  int32_T e_j;
  int32_T exitg1;
  int32_T i;
  int32_T i_0;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  for (e_j = 0; e_j < 36; e_j++) {
    if (recomputeDiags) {
      exptj = A[e_j];
      if (rtIsInf(exptj) || rtIsNaN(exptj)) {
        recomputeDiags = false;
      }
    }
  }

  if (!recomputeDiags) {
    for (e_i = 0; e_i < 36; e_i++) {
      F[e_i] = (rtNaN);
    }
  } else {
    e_j = 0;
    exitg2 = false;
    while ((!exitg2) && (e_j < 6)) {
      e_i = 0;
      do {
        exitg1 = 0;
        if (e_i < 6) {
          if ((e_i != e_j) && (!(A[6 * e_j + e_i] == 0.0))) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            e_i++;
          }
        } else {
          e_j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (recomputeDiags) {
      std::memset(&F[0], 0, 36U * sizeof(real_T));
      for (b_s = 0; b_s < 6; b_s++) {
        e_j = 6 * b_s + b_s;
        F[e_j] = std::exp(A[e_j]);
      }
    } else {
      recomputeDiags = true;
      e_j = 0;
      exitg2 = false;
      while ((!exitg2) && (e_j < 6)) {
        e_i = 0;
        do {
          exitg1 = 0;
          if (e_i <= e_j) {
            if (!(A[6 * e_j + e_i] == A[6 * e_i + e_j])) {
              recomputeDiags = false;
              exitg1 = 1;
            } else {
              e_i++;
            }
          } else {
            e_j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (recomputeDiags) {
        schur(A, A2, A4_0);
        for (b_s = 0; b_s < 6; b_s++) {
          exptj = std::exp(A4_0[6 * b_s + b_s]);
          for (e_j = 0; e_j < 6; e_j++) {
            e_i = 6 * b_s + e_j;
            A4[e_i] = A2[e_i] * exptj;
          }
        }

        for (e_i = 0; e_i < 6; e_i++) {
          for (i_0 = 0; i_0 < 6; i_0++) {
            exptj = 0.0;
            for (i = 0; i < 6; i++) {
              exptj += A4[6 * i + e_i] * A2[6 * i + i_0];
            }

            F[e_i + 6 * i_0] = exptj;
          }
        }

        for (e_i = 0; e_i < 6; e_i++) {
          for (i_0 = 0; i_0 < 6; i_0++) {
            e_j = 6 * e_i + i_0;
            A2[e_j] = (F[6 * i_0 + e_i] + F[e_j]) / 2.0;
          }
        }

        std::memcpy(&F[0], &A2[0], 36U * sizeof(real_T));
      } else {
        recomputeDiags = true;
        e_j = 3;
        while (recomputeDiags && (e_j <= 6)) {
          e_i = e_j;
          while (recomputeDiags && (e_i <= 6)) {
            recomputeDiags = (A[((e_j - 3) * 6 + e_i) - 1] == 0.0);
            e_i++;
          }

          e_j++;
        }

        if (recomputeDiags) {
          e_j = 1;
          exitg2 = false;
          while ((!exitg2) && (e_j - 1 < 5)) {
            e_i = (e_j - 1) * 6 + e_j;
            d6 = A[e_i];
            if (d6 != 0.0) {
              if ((e_j != 5) && (A[(6 * e_j + e_j) + 1] != 0.0)) {
                recomputeDiags = false;
                exitg2 = true;
              } else {
                i_0 = 6 * e_j + e_j;
                if (A[e_i - 1] != A[i_0]) {
                  recomputeDiags = false;
                  exitg2 = true;
                } else {
                  exptj = A[i_0 - 1];
                  if (rtIsNaN(d6)) {
                    d6 = (rtNaN);
                  } else if (d6 < 0.0) {
                    d6 = -1.0;
                  } else {
                    d6 = (d6 > 0.0);
                  }

                  if (rtIsNaN(exptj)) {
                    exptj = (rtNaN);
                  } else if (exptj < 0.0) {
                    exptj = -1.0;
                  } else {
                    exptj = (exptj > 0.0);
                  }

                  if (d6 * exptj != -1.0) {
                    recomputeDiags = false;
                    exitg2 = true;
                  } else {
                    e_j++;
                  }
                }
              }
            } else {
              e_j++;
            }
          }
        }

        exptj = 0.0;
        for (e_i = 0; e_i < 6; e_i++) {
          for (i_0 = 0; i_0 < 6; i_0++) {
            d6 = 0.0;
            for (i = 0; i < 6; i++) {
              d6 += A[6 * i + i_0] * A[6 * e_i + i];
            }

            A2[i_0 + 6 * e_i] = d6;
          }
        }

        for (e_i = 0; e_i < 6; e_i++) {
          for (i_0 = 0; i_0 < 6; i_0++) {
            A4_1 = 0.0;
            for (i = 0; i < 6; i++) {
              A4_1 += A2[6 * i + e_i] * A2[6 * i_0 + i];
            }

            A4[e_i + 6 * i_0] = A4_1;
          }

          for (i_0 = 0; i_0 < 6; i_0++) {
            d6 = 0.0;
            for (i = 0; i < 6; i++) {
              d6 += A4[6 * i + e_i] * A2[6 * i_0 + i];
            }

            A6[e_i + 6 * i_0] = d6;
          }
        }

        d6 = rt_powd_snf(norm(A6), 0.16666666666666666);
        eta1 = rt_powd_snf(norm(A4), 0.25);
        if ((!(eta1 >= d6)) && (!rtIsNaN(d6))) {
          eta1 = d6;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        if (eta1 <= 0.01495585217958292) {
          for (e_j = 0; e_j < 36; e_j++) {
            tmp[e_j] = 0.19285012468241128 * std::abs(A[e_j]);
          }

          mpower(tmp, 7.0, tmp_0);
          A4_1 = std::ceil(log2_e(norm(tmp_0) / norm(A) * 2.0 /
            2.2204460492503131E-16) / 6.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          if (A4_1 == 0.0) {
            b_s = 3;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4) {
          if (eta1 <= 0.253939833006323) {
            for (e_j = 0; e_j < 36; e_j++) {
              tmp[e_j] = 0.12321872304378752 * std::abs(A[e_j]);
            }

            mpower(tmp, 11.0, tmp_0);
            A4_1 = std::ceil(log2_e(norm(tmp_0) / norm(A) * 2.0 /
              2.2204460492503131E-16) / 10.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 5;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3) {
          mpower(A4, 2.0, tmp);
          eta1 = rt_powd_snf(norm(tmp), 0.125);
          if ((!(d6 >= eta1)) && (!rtIsNaN(eta1))) {
            d6 = eta1;
          }

          if (d6 <= 0.95041789961629319) {
            for (e_j = 0; e_j < 36; e_j++) {
              tmp[e_j] = 0.090475336558796943 * std::abs(A[e_j]);
            }

            mpower(tmp, 15.0, tmp_0);
            A4_1 = std::ceil(log2_e(norm(tmp_0) / norm(A) * 2.0 /
              2.2204460492503131E-16) / 14.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 7;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          if (d6 <= 2.097847961257068) {
            for (e_j = 0; e_j < 36; e_j++) {
              tmp[e_j] = 0.071467735648795785 * std::abs(A[e_j]);
            }

            mpower(tmp, 19.0, tmp_0);
            A4_1 = std::ceil(log2_e(norm(tmp_0) / norm(A) * 2.0 /
              2.2204460492503131E-16) / 18.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 9;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          for (e_i = 0; e_i < 6; e_i++) {
            for (i_0 = 0; i_0 < 6; i_0++) {
              A4_1 = 0.0;
              for (i = 0; i < 6; i++) {
                A4_1 += A4[6 * i + i_0] * A6[6 * e_i + i];
              }

              A4_0[i_0 + 6 * e_i] = A4_1;
            }
          }

          A4_1 = rt_powd_snf(norm(A4_0), 0.1);
          if ((eta1 >= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = eta1;
          }

          if ((d6 <= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = d6;
          }

          A4_1 = std::ceil(log2_e(A4_1 / 5.3719203511481517));
          if (A4_1 >= 0.0) {
            exptj = A4_1;
          }

          d6 = rt_powd_snf(2.0, exptj);
          for (e_j = 0; e_j < 36; e_j++) {
            eta1 = A[e_j] / d6;
            A4_0[e_j] = eta1;
            tmp[e_j] = 0.05031554467093536 * std::abs(eta1);
          }

          mpower(tmp, 27.0, tmp_0);
          A4_1 = std::ceil(log2_e(norm(tmp_0) / norm(A4_0) * 2.0 /
            2.2204460492503131E-16) / 26.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          exptj += A4_1;
          if (rtIsInf(exptj)) {
            d6 = norm(A) / 5.3719203511481517;
            if ((!rtIsInf(d6)) && (!rtIsNaN(d6))) {
              d6 = std::frexp(d6, &b_s);
            } else {
              b_s = 0;
            }

            exptj = b_s;
            if (d6 == 0.5) {
              exptj = static_cast<real_T>(b_s) - 1.0;
            }
          }

          b_s = 13;
        }

        if (exptj != 0.0) {
          d6 = rt_powd_snf(2.0, exptj);
          for (e_i = 0; e_i < 36; e_i++) {
            A[e_i] /= d6;
          }

          d6 = rt_powd_snf(2.0, 2.0 * exptj);
          for (e_i = 0; e_i < 36; e_i++) {
            A2[e_i] /= d6;
          }

          d6 = rt_powd_snf(2.0, 4.0 * exptj);
          for (e_i = 0; e_i < 36; e_i++) {
            A4[e_i] /= d6;
          }

          d6 = rt_powd_snf(2.0, 6.0 * exptj);
          for (e_i = 0; e_i < 36; e_i++) {
            A6[e_i] /= d6;
          }
        }

        if (recomputeDiags) {
          for (e_j = 0; e_j < 5; e_j++) {
            blockFormat[e_j] = 0;
          }

          e_j = 1;
          while (e_j < 5) {
            d6 = A[(e_j - 1) * 6 + e_j];
            if (d6 != 0.0) {
              blockFormat[e_j - 1] = 2;
              blockFormat[e_j] = 0;
              e_j += 2;
            } else if ((d6 == 0.0) && (A[(6 * e_j + e_j) + 1] == 0.0)) {
              blockFormat[e_j - 1] = 1;
              e_j++;
            } else {
              blockFormat[e_j - 1] = 0;
              e_j++;
            }
          }

          if (A[29] != 0.0) {
            blockFormat[4] = 2;
          } else {
            switch (blockFormat[3]) {
             case 0:
              blockFormat[4] = 1;
              break;

             case 1:
              blockFormat[4] = 1;
              break;
            }
          }
        }

        padeApproximation(A, A2, A4, A6, b_s, F);
        if (recomputeDiags) {
          recomputeBlockDiag(A, F, blockFormat);
        }

        b_s = static_cast<int32_T>(exptj);
        for (e_j = 0; e_j < b_s; e_j++) {
          for (e_i = 0; e_i < 6; e_i++) {
            for (i_0 = 0; i_0 < 6; i_0++) {
              exptj = 0.0;
              for (i = 0; i < 6; i++) {
                exptj += F[6 * i + e_i] * F[6 * i_0 + i];
              }

              A2[e_i + 6 * i_0] = exptj;
            }
          }

          std::memcpy(&F[0], &A2[0], 36U * sizeof(real_T));
          if (recomputeDiags) {
            for (e_i = 0; e_i < 36; e_i++) {
              A[e_i] *= 2.0;
            }

            recomputeBlockDiag(A, F, blockFormat);
          }
        }
      }
    }
  }
}

// Model step function
void EKF::step()
{
  real_T f[42];
  real_T Ad[36];
  real_T Ad_0[36];
  real_T K_k1[36];
  real_T b[36];
  real_T rtb_P_k1_k[36];
  real_T rtb_P_k1_k_0[36];
  real_T f0[6];
  real_T rtb_VectorConcatenate[6];
  real_T y[6];
  real_T ynew[6];
  real_T absh;
  real_T b_absx;
  real_T b_c;
  real_T c;
  real_T d1;
  real_T d2;
  real_T f_0;
  real_T hmin;
  real_T num;
  real_T rh;
  int32_T Bcolidx;
  int32_T b_iac;
  int32_T i;
  int32_T iy;
  int32_T jj;
  int32_T next;
  int32_T nout;
  int32_T noutnew;
  int32_T ystage_tmp;
  int8_T ipiv[6];
  int8_T p[6];
  int8_T ipiv_0;
  boolean_T Done;
  boolean_T MinStepExit;
  boolean_T NoFailedAttempts;
  static const real_T x[21] = { 0.2, 0.075, 0.225, 0.97777777777777775,
    -3.7333333333333334, 3.5555555555555554, 2.9525986892242035,
    -11.595793324188385, 9.8228928516994358, -0.29080932784636487,
    2.8462752525252526, -10.757575757575758, 8.9064227177434727,
    0.27840909090909088, -0.2735313036020583, 0.091145833333333329, 0.0,
    0.44923629829290207, 0.65104166666666663, -0.322376179245283,
    0.13095238095238096 };

  static const real_T b_b[7] = { 0.0012326388888888888, 0.0,
    -0.0042527702905061394, 0.036979166666666667, -0.05086379716981132,
    0.0419047619047619, -0.025 };

  static const real_T d[1001] = { 0.0, 0.0001, 0.0002, 0.00030000000000000003,
    0.0004, 0.0005, 0.00060000000000000006, 0.0007, 0.0008,
    0.00090000000000000008, 0.001, 0.0011, 0.0012000000000000001,
    0.0013000000000000002, 0.0014, 0.0015, 0.0016, 0.0017000000000000001,
    0.0018000000000000002, 0.0019, 0.002, 0.0021000000000000003, 0.0022, 0.0023,
    0.0024000000000000002, 0.0025, 0.0026000000000000003, 0.0027, 0.0028,
    0.0029000000000000002, 0.003, 0.0031000000000000003, 0.0032, 0.0033,
    0.0034000000000000002, 0.0035, 0.0036000000000000003, 0.0037, 0.0038,
    0.0039000000000000003, 0.004, 0.0041, 0.0042000000000000006, 0.0043, 0.0044,
    0.0045000000000000005, 0.0046, 0.0047, 0.0048000000000000004, 0.0049, 0.005,
    0.0051, 0.0052000000000000006, 0.0053, 0.0054, 0.0055000000000000005, 0.0056,
    0.0057, 0.0058000000000000005, 0.0059, 0.006, 0.0061, 0.0062000000000000006,
    0.0063, 0.0064, 0.0065000000000000006, 0.0066, 0.0067, 0.0068000000000000005,
    0.0069000000000000008, 0.007, 0.0071, 0.0072000000000000007, 0.0073, 0.0074,
    0.0075000000000000006, 0.0076, 0.0077, 0.0078000000000000005, 0.0079, 0.008,
    0.0081, 0.0082, 0.0083, 0.0084000000000000012, 0.0085, 0.0086,
    0.0087000000000000011, 0.0088, 0.0089, 0.0090000000000000011, 0.0091, 0.0092,
    0.009300000000000001, 0.0094, 0.0095, 0.0096000000000000009, 0.0097, 0.0098,
    0.0099, 0.01, 0.010100000000000001, 0.0102, 0.0103, 0.010400000000000001,
    0.0105, 0.0106, 0.010700000000000001, 0.0108, 0.0109, 0.011000000000000001,
    0.0111, 0.0112, 0.011300000000000001, 0.0114, 0.0115, 0.011600000000000001,
    0.0117, 0.0118, 0.0119, 0.012, 0.012100000000000001, 0.0122, 0.0123,
    0.012400000000000001, 0.0125, 0.0126, 0.012700000000000001, 0.0128, 0.0129,
    0.013000000000000001, 0.0131, 0.0132, 0.013300000000000001, 0.0134, 0.0135,
    0.013600000000000001, 0.0137, 0.013800000000000002, 0.013900000000000001,
    0.014, 0.014100000000000001, 0.0142, 0.0143, 0.014400000000000001, 0.0145,
    0.0146, 0.014700000000000001, 0.0148, 0.0149, 0.015000000000000001, 0.0151,
    0.0152, 0.015300000000000001, 0.0154, 0.0155, 0.015600000000000001,
    0.015700000000000002, 0.0158, 0.0159, 0.016, 0.0161, 0.0162,
    0.016300000000000002, 0.0164, 0.0165, 0.0166, 0.0167, 0.016800000000000002,
    0.016900000000000002, 0.017, 0.0171, 0.0172, 0.0173, 0.017400000000000002,
    0.0175, 0.0176, 0.0177, 0.0178, 0.0179, 0.018000000000000002, 0.0181, 0.0182,
    0.0183, 0.0184, 0.018500000000000003, 0.018600000000000002, 0.0187, 0.0188,
    0.0189, 0.019, 0.019100000000000002, 0.019200000000000002, 0.0193, 0.0194,
    0.0195, 0.0196, 0.019700000000000002, 0.0198, 0.0199, 0.02, 0.0201,
    0.020200000000000003, 0.020300000000000002, 0.0204, 0.0205, 0.0206, 0.0207,
    0.020800000000000003, 0.020900000000000002, 0.021, 0.0211, 0.0212, 0.0213,
    0.021400000000000002, 0.021500000000000002, 0.0216, 0.0217, 0.0218, 0.0219,
    0.022000000000000002, 0.0221, 0.0222, 0.0223, 0.0224, 0.022500000000000003,
    0.022600000000000002, 0.0227, 0.0228, 0.0229, 0.023, 0.023100000000000002,
    0.023200000000000002, 0.0233, 0.0234, 0.0235, 0.0236, 0.023700000000000002,
    0.0238, 0.0239, 0.024, 0.0241, 0.024200000000000003, 0.024300000000000002,
    0.0244, 0.0245, 0.0246, 0.0247, 0.024800000000000003, 0.024900000000000002,
    0.025, 0.0251, 0.0252, 0.0253, 0.025400000000000002, 0.025500000000000002,
    0.0256, 0.0257, 0.0258, 0.025900000000000003, 0.026000000000000002, 0.0261,
    0.0262, 0.0263, 0.0264, 0.026500000000000003, 0.026600000000000002, 0.0267,
    0.0268, 0.0269, 0.027, 0.027100000000000003, 0.027200000000000002, 0.0273,
    0.0274, 0.0275, 0.027600000000000003, 0.027700000000000002,
    0.027800000000000002, 0.0279, 0.028, 0.0281, 0.028200000000000003,
    0.028300000000000002, 0.0284, 0.0285, 0.0286, 0.0287, 0.028800000000000003,
    0.028900000000000002, 0.029, 0.0291, 0.0292, 0.029300000000000003,
    0.029400000000000003, 0.029500000000000002, 0.0296, 0.0297, 0.0298,
    0.029900000000000003, 0.030000000000000002, 0.030100000000000002, 0.0302,
    0.0303, 0.0304, 0.030500000000000003, 0.030600000000000002, 0.0307, 0.0308,
    0.0309, 0.031, 0.031100000000000003, 0.031200000000000002, 0.0313,
    0.031400000000000004, 0.0315, 0.0316, 0.0317, 0.0318, 0.031900000000000005,
    0.032, 0.032100000000000004, 0.0322, 0.0323, 0.0324, 0.0325,
    0.032600000000000004, 0.0327, 0.0328, 0.0329, 0.033, 0.033100000000000004,
    0.0332, 0.0333, 0.0334, 0.0335, 0.033600000000000005, 0.0337,
    0.033800000000000004, 0.0339, 0.034, 0.0341, 0.0342, 0.034300000000000004,
    0.0344, 0.0345, 0.0346, 0.0347, 0.034800000000000005, 0.0349, 0.035, 0.0351,
    0.0352, 0.035300000000000005, 0.0354, 0.035500000000000004, 0.0356, 0.0357,
    0.0358, 0.0359, 0.036000000000000004, 0.0361, 0.0362, 0.0363, 0.0364,
    0.036500000000000005, 0.0366, 0.0367, 0.0368, 0.0369, 0.037000000000000005,
    0.0371, 0.037200000000000004, 0.0373, 0.0374, 0.0375, 0.0376,
    0.037700000000000004, 0.0378, 0.0379, 0.038, 0.0381, 0.038200000000000005,
    0.0383, 0.038400000000000004, 0.0385, 0.0386, 0.038700000000000005, 0.0388,
    0.038900000000000004, 0.039, 0.0391, 0.0392, 0.0393, 0.039400000000000004,
    0.0395, 0.0396, 0.0397, 0.0398, 0.039900000000000005, 0.04,
    0.040100000000000004, 0.0402, 0.0403, 0.040400000000000005, 0.0405,
    0.040600000000000004, 0.0407, 0.0408, 0.0409, 0.041, 0.041100000000000005,
    0.0412, 0.0413, 0.0414, 0.0415, 0.041600000000000005, 0.0417,
    0.041800000000000004, 0.0419, 0.042, 0.042100000000000005, 0.0422,
    0.042300000000000004, 0.0424, 0.0425, 0.0426, 0.0427, 0.042800000000000005,
    0.0429, 0.043000000000000003, 0.0431, 0.0432, 0.043300000000000005, 0.0434,
    0.043500000000000004, 0.0436, 0.0437, 0.0438, 0.0439, 0.044000000000000004,
    0.0441, 0.0442, 0.0443, 0.0444, 0.044500000000000005, 0.0446,
    0.044700000000000004, 0.0448, 0.0449, 0.045000000000000005, 0.0451,
    0.045200000000000004, 0.0453, 0.0454, 0.0455, 0.0456, 0.045700000000000005,
    0.0458, 0.0459, 0.046, 0.0461, 0.046200000000000005, 0.0463,
    0.046400000000000004, 0.0465, 0.0466, 0.046700000000000005, 0.0468,
    0.046900000000000004, 0.047, 0.0471, 0.0472, 0.0473, 0.047400000000000005,
    0.0475, 0.0476, 0.0477, 0.0478, 0.047900000000000005, 0.048,
    0.048100000000000004, 0.0482, 0.0483, 0.048400000000000006, 0.0485,
    0.048600000000000004, 0.0487, 0.0488, 0.0489, 0.049, 0.049100000000000005,
    0.0492, 0.049300000000000004, 0.0494, 0.0495, 0.049600000000000005, 0.0497,
    0.049800000000000004, 0.0499, 0.05, 0.050100000000000006, 0.0502,
    0.050300000000000004, 0.0504, 0.0505, 0.050600000000000006, 0.0507,
    0.050800000000000005, 0.0509, 0.051000000000000004, 0.051100000000000007,
    0.0512, 0.051300000000000005, 0.0514, 0.051500000000000004, 0.0516, 0.0517,
    0.051800000000000006, 0.0519, 0.052000000000000005, 0.0521, 0.0522,
    0.052300000000000006, 0.0524, 0.052500000000000005, 0.0526,
    0.052700000000000004, 0.052800000000000007, 0.0529, 0.053000000000000005,
    0.0531, 0.053200000000000004, 0.0533, 0.0534, 0.053500000000000006, 0.0536,
    0.053700000000000005, 0.0538, 0.0539, 0.054000000000000006, 0.0541,
    0.054200000000000005, 0.0543, 0.054400000000000004, 0.054500000000000007,
    0.0546, 0.054700000000000006, 0.0548, 0.054900000000000004, 0.055, 0.0551,
    0.055200000000000006, 0.0553, 0.055400000000000005, 0.0555,
    0.055600000000000004, 0.055700000000000006, 0.0558, 0.055900000000000005,
    0.056, 0.056100000000000004, 0.056200000000000007, 0.0563,
    0.056400000000000006, 0.0565, 0.056600000000000004, 0.0567, 0.0568,
    0.056900000000000006, 0.057, 0.057100000000000005, 0.0572,
    0.057300000000000004, 0.057400000000000007, 0.0575, 0.057600000000000005,
    0.0577, 0.057800000000000004, 0.0579, 0.058, 0.058100000000000006, 0.0582,
    0.058300000000000005, 0.0584, 0.0585, 0.058600000000000006, 0.0587,
    0.058800000000000005, 0.0589, 0.059000000000000004, 0.059100000000000007,
    0.0592, 0.059300000000000005, 0.0594, 0.059500000000000004, 0.0596, 0.0597,
    0.059800000000000006, 0.0599, 0.060000000000000005, 0.0601,
    0.060200000000000004, 0.060300000000000006, 0.0604, 0.060500000000000005,
    0.0606, 0.060700000000000004, 0.060800000000000007, 0.0609,
    0.061000000000000006, 0.0611, 0.061200000000000004, 0.0613, 0.0614,
    0.061500000000000006, 0.0616, 0.061700000000000005, 0.0618,
    0.061900000000000004, 0.062000000000000006, 0.0621, 0.062200000000000005,
    0.0623, 0.062400000000000004, 0.0625, 0.0626, 0.0627, 0.0628,
    0.062900000000000011, 0.063, 0.0631, 0.0632, 0.0633, 0.063400000000000012,
    0.0635, 0.0636, 0.0637, 0.0638, 0.063900000000000012, 0.064, 0.0641,
    0.064200000000000007, 0.0643, 0.064400000000000013, 0.0645, 0.0646,
    0.064700000000000008, 0.0648, 0.064900000000000013, 0.065, 0.0651,
    0.065200000000000008, 0.0653, 0.065400000000000014, 0.0655, 0.0656,
    0.065700000000000008, 0.0658, 0.065900000000000014, 0.066, 0.0661,
    0.066200000000000009, 0.0663, 0.0664, 0.0665, 0.0666, 0.066700000000000009,
    0.0668, 0.0669, 0.067, 0.0671, 0.06720000000000001, 0.0673, 0.0674, 0.0675,
    0.067600000000000007, 0.06770000000000001, 0.0678, 0.0679, 0.068, 0.0681,
    0.068200000000000011, 0.0683, 0.0684, 0.0685, 0.0686, 0.068700000000000011,
    0.0688, 0.0689, 0.069, 0.069100000000000009, 0.069200000000000012, 0.0693,
    0.0694, 0.0695, 0.069600000000000009, 0.069700000000000012, 0.0698, 0.0699,
    0.07, 0.0701, 0.070200000000000012, 0.0703, 0.0704, 0.070500000000000007,
    0.0706, 0.0707, 0.0708, 0.0709, 0.071000000000000008, 0.0711, 0.0712, 0.0713,
    0.0714, 0.071500000000000008, 0.0716, 0.0717, 0.0718, 0.0719,
    0.072000000000000008, 0.0721, 0.0722, 0.0723, 0.0724, 0.072500000000000009,
    0.0726, 0.0727, 0.0728, 0.0729, 0.073000000000000009, 0.0731, 0.0732, 0.0733,
    0.0734, 0.07350000000000001, 0.0736, 0.0737, 0.0738, 0.073900000000000007,
    0.07400000000000001, 0.0741, 0.0742, 0.0743, 0.074400000000000008,
    0.074500000000000011, 0.0746, 0.0747, 0.0748, 0.074900000000000008,
    0.075000000000000011, 0.0751, 0.0752, 0.0753, 0.075400000000000009,
    0.075500000000000012, 0.0756, 0.0757, 0.0758, 0.075900000000000009,
    0.076000000000000012, 0.0761, 0.0762, 0.0763, 0.07640000000000001,
    0.076500000000000012, 0.0766, 0.0767, 0.076800000000000007, 0.0769,
    0.077000000000000013, 0.0771, 0.0772, 0.077300000000000008, 0.0774, 0.0775,
    0.0776, 0.0777, 0.077800000000000008, 0.0779, 0.078, 0.0781, 0.0782,
    0.078300000000000008, 0.0784, 0.0785, 0.0786, 0.0787, 0.078800000000000009,
    0.0789, 0.079, 0.0791, 0.0792, 0.079300000000000009, 0.0794, 0.0795, 0.0796,
    0.079700000000000007, 0.07980000000000001, 0.0799, 0.08, 0.0801,
    0.080200000000000007, 0.08030000000000001, 0.0804, 0.0805, 0.0806,
    0.080700000000000008, 0.080800000000000011, 0.0809, 0.081, 0.0811,
    0.081200000000000008, 0.081300000000000011, 0.0814, 0.0815, 0.0816,
    0.081700000000000009, 0.081800000000000012, 0.0819, 0.082, 0.0821,
    0.082200000000000009, 0.082300000000000012, 0.0824, 0.0825, 0.0826,
    0.08270000000000001, 0.082800000000000012, 0.0829, 0.083,
    0.083100000000000007, 0.0832, 0.083300000000000013, 0.0834, 0.0835,
    0.083600000000000008, 0.0837, 0.083800000000000013, 0.0839, 0.084,
    0.084100000000000008, 0.0842, 0.0843, 0.0844, 0.0845, 0.084600000000000009,
    0.0847, 0.0848, 0.0849, 0.085, 0.085100000000000009, 0.0852, 0.0853, 0.0854,
    0.0855, 0.085600000000000009, 0.0857, 0.0858, 0.0859, 0.086000000000000007,
    0.08610000000000001, 0.0862, 0.0863, 0.0864, 0.086500000000000007,
    0.08660000000000001, 0.0867, 0.0868, 0.0869, 0.087000000000000008,
    0.087100000000000011, 0.0872, 0.0873, 0.0874, 0.087500000000000008,
    0.087600000000000011, 0.0877, 0.0878, 0.0879, 0.088000000000000009,
    0.088100000000000012, 0.0882, 0.0883, 0.0884, 0.088500000000000009,
    0.088600000000000012, 0.0887, 0.0888, 0.0889, 0.08900000000000001,
    0.089100000000000013, 0.0892, 0.0893, 0.089400000000000007,
    0.08950000000000001, 0.0896, 0.0897, 0.0898, 0.089900000000000008,
    0.090000000000000011, 0.0901, 0.0902, 0.0903, 0.090400000000000008,
    0.090500000000000011, 0.0906, 0.0907, 0.0908, 0.090900000000000009, 0.091,
    0.0911, 0.0912, 0.0913, 0.091400000000000009, 0.0915, 0.0916, 0.0917, 0.0918,
    0.091900000000000009, 0.092, 0.0921, 0.0922, 0.092300000000000007,
    0.09240000000000001, 0.0925, 0.0926, 0.0927, 0.092800000000000007,
    0.09290000000000001, 0.093, 0.0931, 0.0932, 0.093300000000000008,
    0.093400000000000011, 0.0935, 0.0936, 0.0937, 0.093800000000000008,
    0.093900000000000011, 0.094, 0.0941, 0.0942, 0.094300000000000009,
    0.094400000000000012, 0.0945, 0.0946, 0.0947, 0.094800000000000009,
    0.094900000000000012, 0.095, 0.0951, 0.0952, 0.09530000000000001,
    0.095400000000000013, 0.0955, 0.0956, 0.095700000000000007,
    0.09580000000000001, 0.0959, 0.096, 0.0961, 0.096200000000000008,
    0.096300000000000011, 0.0964, 0.0965, 0.0966, 0.096700000000000008,
    0.096800000000000011, 0.0969, 0.097, 0.0971, 0.097200000000000009,
    0.097300000000000011, 0.0974, 0.0975, 0.0976, 0.097700000000000009,
    0.097800000000000012, 0.0979, 0.098, 0.0981, 0.09820000000000001, 0.0983,
    0.0984, 0.0985, 0.098600000000000007, 0.09870000000000001, 0.0988, 0.0989,
    0.099, 0.099100000000000008, 0.09920000000000001, 0.0993, 0.0994, 0.0995,
    0.099600000000000008, 0.099700000000000011, 0.0998, 0.0999, 0.1 };

  static const real_T c_b[7] = { -2.859375, 0.0, 4.0431266846361185, -3.90625,
    2.7939268867924527, -1.5714285714285714, 1.5 };

  static const real_T d_b[7] = { 3.0833333333333335, 0.0, -6.2893081761006293,
    10.416666666666666, -6.8773584905660377, 3.6666666666666665, -4.0 };

  static const real_T e_b[7] = { -1.1328125, 0.0, 2.6954177897574123, -5.859375,
    3.7610554245283021, -1.9642857142857142, 2.5 };

  int32_T exitg1;
  int32_T exitg2;

  // Outputs for Atomic SubSystem: '<Root>/EKF'
  // Outputs for Atomic SubSystem: '<S1>/EKF'
  // SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/raw_mag'

  rtb_VectorConcatenate[0] = rtU.z_a[0];

  // SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/raw_w'

  rtb_VectorConcatenate[3] = rtU.z[0];

  // SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/raw_mag'

  rtb_VectorConcatenate[1] = rtU.z_a[1];

  // SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/raw_w'

  rtb_VectorConcatenate[4] = rtU.z[1];

  // SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/raw_mag'

  rtb_VectorConcatenate[2] = rtU.z_a[2];

  // SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/raw_w'

  rtb_VectorConcatenate[5] = rtU.z[2];

  // MATLAB Function: '<S3>/Kalman predictor' incorporates:
  //   UnitDelay: '<S3>/Unit Delay - X'

  f0[0] = -rtDW.UnitDelayX_DSTATE[2] * rtDW.UnitDelayX_DSTATE[4] +
    rtDW.UnitDelayX_DSTATE[1] * rtDW.UnitDelayX_DSTATE[5];
  f0[1] = rtDW.UnitDelayX_DSTATE[2] * rtDW.UnitDelayX_DSTATE[3] -
    rtDW.UnitDelayX_DSTATE[0] * rtDW.UnitDelayX_DSTATE[5];
  f0[2] = -rtDW.UnitDelayX_DSTATE[1] * rtDW.UnitDelayX_DSTATE[3] +
    rtDW.UnitDelayX_DSTATE[0] * rtDW.UnitDelayX_DSTATE[4];
  f0[3] = -rtDW.UnitDelayX_DSTATE[4] * rtDW.UnitDelayX_DSTATE[5];
  f0[4] = rtDW.UnitDelayX_DSTATE[3] * rtDW.UnitDelayX_DSTATE[5];
  f0[5] = -rtDW.UnitDelayX_DSTATE[3] * rtDW.UnitDelayX_DSTATE[4] / 3.0;
  std::memset(&rtDW.yout[0], 0, 6006U * sizeof(real_T));
  nout = 1;
  absh = 0.0001;
  rh = 0.0;
  for (next = 0; next < 6; next++) {
    rtDW.yout[next] = rtDW.UnitDelayX_DSTATE[next];
    num = std::abs(rtDW.UnitDelayX_DSTATE[next]);
    if (!(num >= 0.001)) {
      num = 0.001;
    }

    b_absx = std::abs(f0[next] / num);
    if (rtIsNaN(b_absx)) {
      rh = (rtNaN);
    } else if (b_absx > rh) {
      rh = b_absx;
    }
  }

  rh /= 0.20095091452076641;
  if (0.0001 * rh > 1.0) {
    absh = 1.0 / rh;
  }

  if (!(absh >= 7.90505033345994E-323)) {
    absh = 7.90505033345994E-323;
  }

  rh = 0.0;
  for (i = 0; i < 6; i++) {
    y[i] = rtDW.UnitDelayX_DSTATE[i];
  }

  std::memset(&f[0], 0, 42U * sizeof(real_T));
  for (b_iac = 0; b_iac < 6; b_iac++) {
    f[b_iac] = f0[b_iac];
  }

  next = 0;
  MinStepExit = false;
  Done = false;
  do {
    exitg1 = 0;
    b_absx = std::abs(rh);
    if (rtIsInf(b_absx) || rtIsNaN(b_absx)) {
      b_absx = (rtNaN);
    } else if (b_absx < 4.4501477170144028E-308) {
      b_absx = 4.94065645841247E-324;
    } else {
      std::frexp(b_absx, &jj);
      b_absx = std::ldexp(1.0, jj - 53);
    }

    hmin = 16.0 * b_absx;
    if ((hmin >= absh) || rtIsNaN(absh)) {
      absh = hmin;
    }

    if ((absh >= 0.010000000000000002) || rtIsNaN(absh)) {
      absh = 0.010000000000000002;
    }

    b_absx = absh;
    b_c = std::abs(0.1 - rh);
    if (1.1 * absh >= b_c) {
      b_absx = 0.1 - rh;
      absh = b_c;
      Done = true;
    }

    NoFailedAttempts = true;
    do {
      exitg2 = 0;
      Bcolidx = 0;
      for (iy = 0; iy < 5; iy++) {
        Bcolidx += iy;
        for (i = 0; i < 6; i++) {
          f0[i] = y[i];
        }

        if (!(b_absx == 0.0)) {
          noutnew = 6 * iy + 1;
          for (b_iac = 1; b_iac <= noutnew; b_iac += 6) {
            b_c = x[div_nde_s32_floor(b_iac - 1, 6) + Bcolidx] * b_absx;
            for (i = b_iac; i <= b_iac + 5; i++) {
              ystage_tmp = i - b_iac;
              f0[ystage_tmp] += f[i - 1] * b_c;
            }
          }
        }

        b_iac = (iy + 1) * 6;
        f[b_iac] = -f0[2] * f0[4] + f0[1] * f0[5];
        f[b_iac + 1] = f0[2] * f0[3] - f0[0] * f0[5];
        f[b_iac + 2] = -f0[1] * f0[3] + f0[0] * f0[4];
        f[b_iac + 3] = -f0[4] * f0[5];
        f[b_iac + 4] = f0[3] * f0[5];
        f[b_iac + 5] = -f0[3] * f0[4] / 3.0;
      }

      b_c = rh + b_absx;
      for (i = 0; i < 6; i++) {
        ynew[i] = y[i];
      }

      if (!(b_absx == 0.0)) {
        i = Bcolidx;
        for (Bcolidx = 0; Bcolidx <= 30; Bcolidx += 6) {
          c = x[(i + div_nde_s32_floor(Bcolidx, 6)) + 5] * b_absx;
          for (noutnew = Bcolidx + 1; noutnew <= Bcolidx + 6; noutnew++) {
            b_iac = (noutnew - Bcolidx) - 1;
            ynew[b_iac] += f[noutnew - 1] * c;
          }
        }
      }

      f[36] = -ynew[2] * ynew[4] + ynew[1] * ynew[5];
      f[37] = ynew[2] * ynew[3] - ynew[0] * ynew[5];
      f[38] = -ynew[1] * ynew[3] + ynew[0] * ynew[4];
      f[39] = -ynew[4] * ynew[5];
      f[40] = ynew[3] * ynew[5];
      f[41] = -ynew[3] * ynew[4] / 3.0;
      for (b_iac = 0; b_iac < 6; b_iac++) {
        b_absx = 0.0;
        for (Bcolidx = 0; Bcolidx < 7; Bcolidx++) {
          b_absx += f[6 * Bcolidx + b_iac] * b_b[Bcolidx];
        }

        f0[b_iac] = b_absx;
      }

      if (Done) {
        b_c = 0.1;
      }

      b_absx = b_c - rh;
      c = 0.0;
      for (iy = 0; iy < 6; iy++) {
        num = std::abs(f0[iy]);
        d1 = std::abs(y[iy]);
        d2 = std::abs(ynew[iy]);
        if ((d1 > d2) || rtIsNaN(d2)) {
          if (d1 > 0.001) {
            num /= d1;
          } else {
            num /= 0.001;
          }
        } else if (d2 > 0.001) {
          num /= d2;
        } else {
          num /= 0.001;
        }

        if (num > c) {
          c = num;
        } else if (rtIsNaN(num)) {
          c = (rtNaN);
        }
      }

      c *= absh;
      if (!(c <= 0.001)) {
        if (absh <= hmin) {
          MinStepExit = true;
          exitg2 = 1;
        } else {
          if (NoFailedAttempts) {
            NoFailedAttempts = false;
            b_c = rt_powd_snf(0.001 / c, 0.2) * 0.8;
            if ((b_c <= 0.1) || rtIsNaN(b_c)) {
              b_c = 0.1;
            }

            absh *= b_c;
            if ((hmin >= absh) || rtIsNaN(absh)) {
              absh = hmin;
            }
          } else {
            absh *= 0.5;
            if ((hmin >= absh) || rtIsNaN(absh)) {
              absh = hmin;
            }
          }

          b_absx = absh;
          Done = false;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (MinStepExit) {
      exitg1 = 1;
    } else {
      iy = next;
      while ((iy + 2 <= 1001) && (b_c - d[iy + 1] >= 0.0)) {
        iy++;
      }

      noutnew = iy - next;
      if (noutnew > 0) {
        for (i = next + 2; i <= iy; i++) {
          hmin = (d[i - 1] - rh) / b_absx;
          for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
            num = 0.0;
            d1 = 0.0;
            d2 = 0.0;
            for (b_iac = 0; b_iac < 7; b_iac++) {
              f_0 = f[6 * b_iac + Bcolidx];
              num += b_absx * c_b[b_iac] * f_0;
              d1 += b_absx * d_b[b_iac] * f_0;
              d2 += b_absx * e_b[b_iac] * f_0;
            }

            rtDW.yout[Bcolidx + 6 * (i - 1)] = (((d2 * hmin + d1) * hmin + num) *
              hmin + f[Bcolidx] * b_absx) * hmin + y[Bcolidx];
          }
        }

        if (d[iy] == b_c) {
          for (b_iac = 0; b_iac < 6; b_iac++) {
            rtDW.yout[b_iac + 6 * iy] = ynew[b_iac];
          }
        } else {
          rh = (d[iy] - rh) / b_absx;
          for (next = 0; next < 6; next++) {
            num = 0.0;
            d1 = 0.0;
            d2 = 0.0;
            for (b_iac = 0; b_iac < 7; b_iac++) {
              f_0 = f[6 * b_iac + next];
              num += b_absx * c_b[b_iac] * f_0;
              d1 += b_absx * d_b[b_iac] * f_0;
              d2 += b_absx * e_b[b_iac] * f_0;
            }

            rtDW.yout[next + 6 * iy] = (((d2 * rh + d1) * rh + num) * rh +
              f[next] * b_absx) * rh + y[next];
          }
        }

        nout += noutnew;
        next = iy;
      }

      if (Done) {
        exitg1 = 1;
      } else {
        if (NoFailedAttempts) {
          rh = rt_powd_snf(c / 0.001, 0.2) * 1.25;
          if (rh > 0.2) {
            absh /= rh;
          } else {
            absh *= 5.0;
          }
        }

        rh = b_c;
        for (i = 0; i < 6; i++) {
          y[i] = ynew[i];
          f[i] = f[i + 36];
        }
      }
    }
  } while (exitg1 == 0);

  ystage_tmp = nout;
  for (b_iac = 0; b_iac < 6; b_iac++) {
    for (Bcolidx = 0; Bcolidx < nout; Bcolidx++) {
      rtDW.sol_data[Bcolidx + nout * b_iac] = rtDW.yout[6 * Bcolidx + b_iac];
    }
  }

  // MATLAB Function: '<S2>/Jacobian' incorporates:
  //   Inport: '<Root>/raw_w'
  //   MATLAB Function: '<S3>/Kalman predictor'

  K_k1[0] = 0.0;
  K_k1[6] = rtU.z[2] * 0.2;

  // MATLAB Function: '<S3>/Kalman predictor' incorporates:
  //   Inport: '<Root>/raw_w'
  //   MATLAB Function: '<S2>/Jacobian'

  absh = -rtU.z[1] * 0.2;

  // MATLAB Function: '<S2>/Jacobian' incorporates:
  //   Inport: '<Root>/raw_mag'
  //   MATLAB Function: '<S3>/Kalman predictor'

  K_k1[12] = absh;
  K_k1[18] = 0.0;
  K_k1[24] = -rtU.z_a[2] * 0.2;
  K_k1[30] = rtU.z_a[1] * 0.2;

  // MATLAB Function: '<S3>/Kalman predictor' incorporates:
  //   Inport: '<Root>/raw_w'
  //   MATLAB Function: '<S2>/Jacobian'

  rh = -rtU.z[2] * 0.2;

  // MATLAB Function: '<S2>/Jacobian' incorporates:
  //   Inport: '<Root>/raw_mag'
  //   Inport: '<Root>/raw_w'
  //   MATLAB Function: '<S3>/Kalman predictor'

  K_k1[1] = rh;
  K_k1[7] = 0.0;
  K_k1[13] = rtU.z[0] * 0.2;
  K_k1[19] = rtU.z_a[2] * 0.2;
  K_k1[25] = 0.0;
  K_k1[31] = -rtU.z_a[0] * 0.2;
  K_k1[2] = rtU.z[1] * 0.2;
  K_k1[8] = -rtU.z[0] * 0.2;
  K_k1[14] = 0.0;
  K_k1[20] = -rtU.z_a[1] * 0.2;
  K_k1[26] = rtU.z_a[0] * 0.2;
  K_k1[32] = 0.0;
  K_k1[3] = 0.0;
  K_k1[9] = 0.0;
  K_k1[15] = 0.0;
  K_k1[21] = 0.0;
  K_k1[27] = rh;
  K_k1[33] = absh;
  K_k1[4] = 0.0;
  K_k1[10] = 0.0;
  K_k1[16] = 0.0;
  K_k1[22] = rtU.z[2] * 0.2;
  K_k1[28] = 0.0;
  K_k1[34] = rtU.z[0] * 0.2;
  K_k1[5] = 0.0;
  K_k1[11] = 0.0;
  K_k1[17] = 0.0;
  K_k1[23] = -rtU.z[0] / 3.0 * 0.2;
  K_k1[29] = -rtU.z[1] / 3.0 * 0.2;
  K_k1[35] = 0.0;

  // MATLAB Function: '<S3>/Kalman predictor' incorporates:
  //   UnitDelay: '<S3>/Unit Delay - P'

  expm(K_k1, Ad);
  for (b_iac = 0; b_iac < 6; b_iac++) {
    for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
      absh = 0.0;
      for (nout = 0; nout < 6; nout++) {
        absh += Ad[6 * nout + b_iac] * rtDW.UnitDelayP_DSTATE[6 * Bcolidx + nout];
      }

      Ad_0[b_iac + 6 * Bcolidx] = absh;
    }

    for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
      absh = 0.0;
      for (nout = 0; nout < 6; nout++) {
        absh += Ad_0[6 * nout + b_iac] * Ad[6 * nout + Bcolidx];
      }

      jj = 6 * Bcolidx + b_iac;
      rtb_P_k1_k[jj] = rtConstP.Kalmanpredictor_Q[jj] + absh;
    }
  }

  // MATLAB Function: '<S3>/Kalman corrector' incorporates:
  //   MATLAB Function: '<S3>/Kalman predictor'

  for (b_iac = 0; b_iac < 6; b_iac++) {
    for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
      jj = 6 * Bcolidx + b_iac;
      Ad[Bcolidx + 6 * b_iac] = rtConstP.Kalmancorrector_Hd[jj];
      absh = 0.0;
      for (nout = 0; nout < 6; nout++) {
        absh += rtConstP.Kalmancorrector_Hd[6 * nout + b_iac] * rtb_P_k1_k[6 *
          Bcolidx + nout];
      }

      K_k1[jj] = absh;
    }
  }

  for (b_iac = 0; b_iac < 6; b_iac++) {
    for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
      absh = 0.0;
      for (nout = 0; nout < 6; nout++) {
        absh += K_k1[6 * nout + b_iac] * Ad[6 * Bcolidx + nout];
      }

      jj = 6 * Bcolidx + b_iac;
      Ad_0[jj] = R_n[jj] + absh;
    }
  }

  for (b_iac = 0; b_iac < 36; b_iac++) {
    K_k1[b_iac] = Ad_0[b_iac];
    b[b_iac] = 0.0;
  }

  for (b_iac = 0; b_iac < 6; b_iac++) {
    ipiv[b_iac] = static_cast<int8_T>(b_iac + 1);
  }

  for (nout = 0; nout < 5; nout++) {
    jj = nout * 7;
    next = 6 - nout;
    Bcolidx = 0;
    absh = std::abs(K_k1[jj]);
    for (iy = 2; iy <= next; iy++) {
      hmin = std::abs(K_k1[(jj + iy) - 1]);
      if (hmin > absh) {
        Bcolidx = iy - 1;
        absh = hmin;
      }
    }

    if (K_k1[jj + Bcolidx] != 0.0) {
      if (Bcolidx != 0) {
        b_iac = nout + Bcolidx;
        ipiv[nout] = static_cast<int8_T>(b_iac + 1);
        for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
          iy = Bcolidx * 6 + nout;
          rh = K_k1[iy];
          next = Bcolidx * 6 + b_iac;
          K_k1[iy] = K_k1[next];
          K_k1[next] = rh;
        }
      }

      next = (jj - nout) + 6;
      for (i = jj + 2; i <= next; i++) {
        K_k1[i - 1] /= K_k1[jj];
      }
    }

    next = 4 - nout;
    i = jj + 8;
    for (Bcolidx = 0; Bcolidx <= next; Bcolidx++) {
      absh = K_k1[(Bcolidx * 6 + jj) + 6];
      if (absh != 0.0) {
        b_iac = (i - nout) + 4;
        for (iy = i; iy <= b_iac; iy++) {
          K_k1[iy - 1] += K_k1[((jj + iy) - i) + 1] * -absh;
        }
      }

      i += 6;
    }
  }

  for (b_iac = 0; b_iac < 6; b_iac++) {
    p[b_iac] = static_cast<int8_T>(b_iac + 1);
  }

  for (next = 0; next < 5; next++) {
    ipiv_0 = ipiv[next];
    if (ipiv_0 > next + 1) {
      nout = p[ipiv_0 - 1];
      p[ipiv_0 - 1] = p[next];
      p[next] = static_cast<int8_T>(nout);
    }
  }

  for (i = 0; i < 6; i++) {
    noutnew = (p[i] - 1) * 6;
    b[i + noutnew] = 1.0;
    for (iy = i + 1; iy < 7; iy++) {
      b_iac = (noutnew + iy) - 1;
      if (b[b_iac] != 0.0) {
        for (jj = iy + 1; jj < 7; jj++) {
          nout = (noutnew + jj) - 1;
          b[nout] -= K_k1[((iy - 1) * 6 + jj) - 1] * b[b_iac];
        }
      }
    }
  }

  for (nout = 0; nout < 6; nout++) {
    jj = 6 * nout;
    for (next = 5; next >= 0; next--) {
      i = 6 * next;
      b_iac = next + jj;
      absh = b[b_iac];
      if (absh != 0.0) {
        b[b_iac] = absh / K_k1[next + i];
        for (Bcolidx = 0; Bcolidx < next; Bcolidx++) {
          noutnew = Bcolidx + jj;
          b[noutnew] -= K_k1[Bcolidx + i] * b[b_iac];
        }
      }
    }

    for (b_iac = 0; b_iac < 6; b_iac++) {
      absh = 0.0;
      for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
        absh += rtb_P_k1_k[6 * Bcolidx + nout] * Ad[6 * b_iac + Bcolidx];
      }

      rtb_P_k1_k_0[nout + 6 * b_iac] = absh;
    }
  }

  for (b_iac = 0; b_iac < 6; b_iac++) {
    absh = 0.0;
    for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
      rh = 0.0;
      for (nout = 0; nout < 6; nout++) {
        rh += rtb_P_k1_k_0[6 * nout + b_iac] * b[6 * Bcolidx + nout];
      }

      next = 6 * Bcolidx + b_iac;
      K_k1[next] = rh;
      absh += rtDW.sol_data[(ystage_tmp * Bcolidx + ystage_tmp) - 1] *
        rtConstP.Kalmancorrector_Hd[next];
    }

    y[b_iac] = rtb_VectorConcatenate[b_iac] - absh;
  }

  for (i = 0; i < 6; i++) {
    absh = 0.0;
    for (b_iac = 0; b_iac < 6; b_iac++) {
      Bcolidx = 6 * b_iac + i;
      absh += K_k1[Bcolidx] * y[b_iac];
      rh = 0.0;
      for (nout = 0; nout < 6; nout++) {
        rh += K_k1[6 * nout + i] * Ad_0[6 * b_iac + nout];
      }

      Ad[Bcolidx] = rh;
    }

    d1 = rtDW.sol_data[(ystage_tmp * i + ystage_tmp) - 1] + absh;
    f0[i] = d1;

    // Update for UnitDelay: '<S3>/Unit Delay - X' incorporates:
    //   MATLAB Function: '<S3>/Kalman predictor'

    rtDW.UnitDelayX_DSTATE[i] = d1;

    // Update for UnitDelay: '<S3>/Unit Delay - P'
    for (b_iac = 0; b_iac < 6; b_iac++) {
      absh = 0.0;
      for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
        absh += Ad[6 * Bcolidx + i] * K_k1[6 * Bcolidx + b_iac];
      }

      nout = 6 * b_iac + i;
      rtDW.UnitDelayP_DSTATE[nout] = rtb_P_k1_k[nout] - absh;
    }

    // End of Update for UnitDelay: '<S3>/Unit Delay - P'
  }

  // End of MATLAB Function: '<S3>/Kalman corrector'
  // End of Outputs for SubSystem: '<S1>/EKF'
  // End of Outputs for SubSystem: '<Root>/EKF'

  // Outport: '<Root>/filter_w'
  rtY.filter_w[0] = f0[3];

  // Outport: '<Root>/filter_mag'
  rtY.filter_mag[0] = f0[0];

  // Outport: '<Root>/filter_w'
  rtY.filter_w[1] = f0[4];

  // Outport: '<Root>/filter_mag'
  rtY.filter_mag[1] = f0[1];

  // Outport: '<Root>/filter_w'
  rtY.filter_w[2] = f0[5];

  // Outport: '<Root>/filter_mag'
  rtY.filter_mag[2] = f0[2];
}

// Model initialize function
void EKF::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;

    // SystemInitialize for Atomic SubSystem: '<Root>/EKF'
    // SystemInitialize for Atomic SubSystem: '<S1>/EKF'
    // InitializeConditions for UnitDelay: '<S3>/Unit Delay - X'
    for (i = 0; i < 6; i++) {
      rtDW.UnitDelayX_DSTATE[i] = rtConstP.UnitDelayX_InitialCondition[i];
    }

    // End of InitializeConditions for UnitDelay: '<S3>/Unit Delay - X'

    // InitializeConditions for UnitDelay: '<S3>/Unit Delay - P'
    std::memcpy(&rtDW.UnitDelayP_DSTATE[0], &R_n[0], 36U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S1>/EKF'
    // End of SystemInitialize for SubSystem: '<Root>/EKF'
  }
}

// Constructor
EKF::EKF() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
EKF::~EKF()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * EKF::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
