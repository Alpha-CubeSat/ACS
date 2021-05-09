//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Plantv50.cpp
//
// Code generated for Simulink model 'Plantv50'.
//
// Model version                  : 1.75
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Sun May 20 23:26:20 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Plantv50.h"
#define NumBitsPerChar                 8U

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern "C" {
  extern real_T rtGetNaN(void);
  extern real32_T rtGetNaNF(void);
}                                      // extern "C"
  //===========*
  //  Constants *
  // ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   // do nothing
# else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C" {
  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetNaN(void)
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
  real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
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
  boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  boolean_T rtIsNaN(real_T value)
  {
    return (boolean_T)((value!=value) ? 1U : 0U);
  }

  // Test if single-precision value is not a number
  boolean_T rtIsNaNF(real32_T value)
  {
    return (boolean_T)(((value!=value) ? 1U : 0U));
  }
}
  extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetInf(void)
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
  real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetMinusInf(void)
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
  real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void Plantv50ModelClass::step()
{
  real_T rtb_Product[4];
  real_T rtb_magneticmoment[3];
  real_T rtb_MatrixMultiply1[3];
  real_T rtb_DiscreteTimeIntegrator1;
  real_T rtb_DiscreteTimeIntegrator2;
  real_T rtb_DiscreteTimeIntegrator3;
  real_T rtb_DiscreteTimeIntegrator5;
  real_T rtb_DiscreteTimeIntegrator6;
  real_T rtb_Sqrt;
  real_T rtb_Divide_e;
  real_T rtb_Sum8[9];
  real_T rtb_MathFunction_d_0;
  real_T rtb_Product_0[9];
  int32_T i;
  real_T tmp[9];
  real_T rtb_Divide1_e_idx_0;
  real_T rtb_Elementproduct_idx_0;
  real_T rtb_Elementproduct_idx_1;
  real_T rtb_Elementproduct_idx_2;
  real_T rtb_Elementproduct_idx_3;
  real_T rtb_Elementproduct_idx_4;
  real_T rtb_Elementproduct_idx_5;

  // Outputs for Atomic SubSystem: '<Root>/Plantv5'
  // Gain: '<S1>/Gain' incorporates:
  //   Inport: '<Root>/current'

  rtb_magneticmoment[0] = 39.898226700590371 * rtU.current[0];
  rtb_magneticmoment[1] = 39.898226700590371 * rtU.current[1];
  rtb_magneticmoment[2] = 39.898226700590371 * rtU.current[2];

  // DotProduct: '<S10>/Dot Product' incorporates:
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'

  rtb_MathFunction_d_0 = ((rtDW.DiscreteTimeIntegrator1_DSTATE[0] *
    rtDW.DiscreteTimeIntegrator1_DSTATE[0] +
    rtDW.DiscreteTimeIntegrator1_DSTATE[1] *
    rtDW.DiscreteTimeIntegrator1_DSTATE[1]) +
    rtDW.DiscreteTimeIntegrator1_DSTATE[2] *
    rtDW.DiscreteTimeIntegrator1_DSTATE[2]) +
    rtDW.DiscreteTimeIntegrator1_DSTATE[3] *
    rtDW.DiscreteTimeIntegrator1_DSTATE[3];

  // Math: '<S10>/Math Function' incorporates:
  //   DotProduct: '<S10>/Dot Product'
  //
  //  About '<S10>/Math Function':
  //   Operator: sqrt

  if (rtb_MathFunction_d_0 < 0.0) {
    rtb_MathFunction_d_0 = -std::sqrt(std::abs(rtb_MathFunction_d_0));
  } else {
    rtb_MathFunction_d_0 = std::sqrt(rtb_MathFunction_d_0);
  }

  // End of Math: '<S10>/Math Function'

  // Product: '<S10>/Product' incorporates:
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'

  rtb_Product[0] = rtDW.DiscreteTimeIntegrator1_DSTATE[0] / rtb_MathFunction_d_0;
  rtb_Product[1] = rtDW.DiscreteTimeIntegrator1_DSTATE[1] / rtb_MathFunction_d_0;
  rtb_Product[2] = rtDW.DiscreteTimeIntegrator1_DSTATE[2] / rtb_MathFunction_d_0;
  rtb_Product[3] = rtDW.DiscreteTimeIntegrator1_DSTATE[3] / rtb_MathFunction_d_0;

  // Outputs for Atomic SubSystem: '<S1>/qtoQ'
  // Sum: '<S7>/Sum1' incorporates:
  //   Math: '<S7>/T2'
  //   Product: '<S7>/Product1'
  //   Product: '<S7>/qTq'

  rtb_MathFunction_d_0 = rtb_Product[3] * rtb_Product[3] - ((rtb_Product[0] *
    rtb_Product[0] + rtb_Product[1] * rtb_Product[1]) + rtb_Product[2] *
    rtb_Product[2]);

  // Product: '<S7>/qqT' incorporates:
  //   Gain: '<S7>/Gain2'
  //   Math: '<S7>/T1'

  for (i = 0; i < 3; i++) {
    rtb_Product_0[i] = rtb_Product[i] * rtb_Product[0];
    rtb_Product_0[i + 3] = rtb_Product[i] * rtb_Product[1];
    rtb_Product_0[i + 6] = rtb_Product[i] * rtb_Product[2];
  }

  // End of Product: '<S7>/qqT'

  // Reshape: '<S12>/3x3' incorporates:
  //   Constant: '<S12>/diag 0 '
  //   Gain: '<S12>/Gain'
  //   Gain: '<S12>/Gain1'
  //   Gain: '<S12>/Gain2'
  //   Product: '<S7>/Product'

  tmp[0] = 0.0;
  tmp[1] = rtb_Product[2];
  tmp[2] = -rtb_Product[1];
  tmp[3] = -rtb_Product[2];
  tmp[4] = 0.0;
  tmp[5] = rtb_Product[0];
  tmp[6] = rtb_Product[1];
  tmp[7] = -rtb_Product[0];
  tmp[8] = 0.0;

  // Product: '<S7>/Product'
  rtb_DiscreteTimeIntegrator1 = rtb_Product[3];

  // Sum: '<S7>/Sum8' incorporates:
  //   Gain: '<S7>/Gain1'
  //   Gain: '<S7>/Gain2'
  //   Gain: '<S7>/Matrix Gain'
  //   Product: '<S7>/Product'

  for (i = 0; i < 3; i++) {
    rtb_Sum8[3 * i] = (rtb_Product_0[3 * i] * 2.0 - tmp[3 * i] *
                       rtb_DiscreteTimeIntegrator1 * 2.0) +
      rtConstP.MatrixGain_Gain[3 * i] * rtb_MathFunction_d_0;
    rtb_Sum8[1 + 3 * i] = (rtb_Product_0[3 * i + 1] * 2.0 - tmp[3 * i + 1] *
      rtb_DiscreteTimeIntegrator1 * 2.0) + rtConstP.MatrixGain_Gain[3 * i + 1] *
      rtb_MathFunction_d_0;
    rtb_Sum8[2 + 3 * i] = (rtb_Product_0[3 * i + 2] * 2.0 - tmp[3 * i + 2] *
      rtb_DiscreteTimeIntegrator1 * 2.0) + rtConstP.MatrixGain_Gain[3 * i + 2] *
      rtb_MathFunction_d_0;
  }

  // End of Sum: '<S7>/Sum8'
  // End of Outputs for SubSystem: '<S1>/qtoQ'

  // Outputs for Atomic SubSystem: '<S1>/Tranlational Dynamics'
  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator1 = rtDW.DiscreteTimeIntegrator1_DSTA_ls;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator2'
  rtb_DiscreteTimeIntegrator2 = rtDW.DiscreteTimeIntegrator2_DSTAT_e;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator3'
  rtb_DiscreteTimeIntegrator3 = rtDW.DiscreteTimeIntegrator3_DSTATE;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator4'
  rtb_MathFunction_d_0 = rtDW.DiscreteTimeIntegrator4_DSTATE;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator5'
  rtb_DiscreteTimeIntegrator5 = rtDW.DiscreteTimeIntegrator5_DSTATE;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator6'
  rtb_DiscreteTimeIntegrator6 = rtDW.DiscreteTimeIntegrator6_DSTATE;

  // Sqrt: '<S6>/Sqrt' incorporates:
  //   DiscreteIntegrator: '<S6>/Discrete-Time Integrator4'
  //   DiscreteIntegrator: '<S6>/Discrete-Time Integrator5'
  //   DiscreteIntegrator: '<S6>/Discrete-Time Integrator6'
  //   DotProduct: '<S6>/Dot Product'
  //   DotProduct: '<S6>/Dot Product1'
  //   DotProduct: '<S6>/Dot Product2'
  //   Sum: '<S6>/Sum'

  rtb_Sqrt = std::sqrt((rtDW.DiscreteTimeIntegrator4_DSTATE *
                        rtDW.DiscreteTimeIntegrator4_DSTATE +
                        rtDW.DiscreteTimeIntegrator5_DSTATE *
                        rtDW.DiscreteTimeIntegrator5_DSTATE) +
                       rtDW.DiscreteTimeIntegrator6_DSTATE *
                       rtDW.DiscreteTimeIntegrator6_DSTATE);

  // Product: '<S6>/Divide' incorporates:
  //   Math: '<S6>/Math Function'

  rtb_Divide_e = 1.0 / (rtb_Sqrt * rtb_Sqrt) * -3.342008836E+14;

  // Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S6>/Discrete-Time Integrator5'
  //   DotProduct: '<S6>/Dot Product4'
  //   Product: '<S6>/Divide1'

  rtDW.DiscreteTimeIntegrator1_DSTA_ls += 1.0 / rtb_Sqrt *
    rtDW.DiscreteTimeIntegrator5_DSTATE * rtb_Divide_e * 0.01;

  // Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator2' incorporates:
  //   DiscreteIntegrator: '<S6>/Discrete-Time Integrator4'
  //   DotProduct: '<S6>/Dot Product5'
  //   Product: '<S6>/Divide1'

  rtDW.DiscreteTimeIntegrator2_DSTAT_e += 1.0 / rtb_Sqrt *
    rtDW.DiscreteTimeIntegrator4_DSTATE * rtb_Divide_e * 0.01;

  // Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator3' incorporates:
  //   DiscreteIntegrator: '<S6>/Discrete-Time Integrator6'
  //   DotProduct: '<S6>/Dot Product3'
  //   Product: '<S6>/Divide1'

  rtDW.DiscreteTimeIntegrator3_DSTATE += 1.0 / rtb_Sqrt *
    rtDW.DiscreteTimeIntegrator6_DSTATE * rtb_Divide_e * 0.01;

  // Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator4'
  rtDW.DiscreteTimeIntegrator4_DSTATE += 0.01 * rtb_DiscreteTimeIntegrator2;

  // Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator5'
  rtDW.DiscreteTimeIntegrator5_DSTATE += 0.01 * rtb_DiscreteTimeIntegrator1;

  // Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator6'
  rtDW.DiscreteTimeIntegrator6_DSTATE += 0.01 * rtb_DiscreteTimeIntegrator3;

  // End of Outputs for SubSystem: '<S1>/Tranlational Dynamics'

  // Outputs for Atomic SubSystem: '<S1>/Magnetic Field Model'
  // Product: '<S4>/Divide2' incorporates:
  //   Constant: '<S4>/Constant1'
  //   Math: '<S4>/Math Function5'
  //   Math: '<S4>/Math Function6'
  //   Math: '<S4>/Math Function7'
  //   Sqrt: '<S4>/Sqrt3'
  //   Sum: '<S4>/Sum4'

  rtb_DiscreteTimeIntegrator2 = 6.378E+6 / std::sqrt((rtb_MathFunction_d_0 *
    rtb_MathFunction_d_0 + rtb_DiscreteTimeIntegrator5 *
    rtb_DiscreteTimeIntegrator5) + rtb_DiscreteTimeIntegrator6 *
    rtb_DiscreteTimeIntegrator6);

  // Gain: '<S4>/Gain4' incorporates:
  //   Math: '<S4>/Math Function8'
  //   Product: '<S4>/Product'

  rtb_DiscreteTimeIntegrator2 = rtb_DiscreteTimeIntegrator2 *
    rtb_DiscreteTimeIntegrator2 * rtb_DiscreteTimeIntegrator2 * -3.12E-5;

  // Sum: '<S4>/Sum5' incorporates:
  //   Constant: '<S4>/Constant8'
  //   Math: '<S4>/Math Function3'
  //   Math: '<S4>/Math Function4'
  //   Sqrt: '<S4>/Sqrt2'
  //   Sum: '<S4>/Sum3'
  //   Trigonometry: '<S4>/Trigonometric Function3'

  rtb_DiscreteTimeIntegrator3 = 1.5707963267948966 - rt_atan2d_snf
    (rtb_DiscreteTimeIntegrator6, std::sqrt(rtb_MathFunction_d_0 *
      rtb_MathFunction_d_0 + rtb_DiscreteTimeIntegrator5 *
      rtb_DiscreteTimeIntegrator5));

  // Product: '<S4>/Divide3' incorporates:
  //   Gain: '<S4>/Gain5'
  //   Trigonometry: '<S4>/Trigonometric Function2'

  rtb_DiscreteTimeIntegrator1 = 2.0 * rtb_DiscreteTimeIntegrator2 * std::cos
    (rtb_DiscreteTimeIntegrator3);

  // Product: '<S4>/Divide4' incorporates:
  //   Trigonometry: '<S4>/Trigonometric Function4'

  rtb_DiscreteTimeIntegrator2 *= std::sin(rtb_DiscreteTimeIntegrator3);

  // Gain: '<S4>/Gain6'
  rtb_DiscreteTimeIntegrator3 = -rtb_DiscreteTimeIntegrator3;

  // Outputs for Atomic SubSystem: '<S4>/Dipole->ECI'
  // Sum: '<S9>/Sum6' incorporates:
  //   Product: '<S9>/Product3'
  //   Product: '<S9>/Product4'
  //   Trigonometry: '<S9>/Trigonometric Function7'
  //   Trigonometry: '<S9>/Trigonometric Function8'

  rtb_Sqrt = std::cos(rtb_DiscreteTimeIntegrator3) * rtb_DiscreteTimeIntegrator2
    + std::sin(rtb_DiscreteTimeIntegrator3) * rtb_DiscreteTimeIntegrator1;

  // Trigonometry: '<S9>/Trigonometric Function'
  rtb_Divide_e = rt_atan2d_snf(rtb_DiscreteTimeIntegrator5, rtb_MathFunction_d_0);

  // SignalConversion: '<S1>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
  //   Product: '<S9>/Divide'
  //   Product: '<S9>/Divide1'
  //   Product: '<S9>/Product1'
  //   Product: '<S9>/Product2'
  //   Sum: '<S9>/Sum5'
  //   Trigonometry: '<S9>/Trigonometric Function1'
  //   Trigonometry: '<S9>/Trigonometric Function2'
  //   Trigonometry: '<S9>/Trigonometric Function5'
  //   Trigonometry: '<S9>/Trigonometric Function6'

  rtb_Divide1_e_idx_0 = rtb_Sqrt * std::cos(rtb_Divide_e);
  rtb_Sqrt *= std::sin(rtb_Divide_e);
  rtb_Divide_e = std::cos(rtb_DiscreteTimeIntegrator3) *
    rtb_DiscreteTimeIntegrator1 - std::sin(rtb_DiscreteTimeIntegrator3) *
    rtb_DiscreteTimeIntegrator2;

  // End of Outputs for SubSystem: '<S4>/Dipole->ECI'
  // End of Outputs for SubSystem: '<S1>/Magnetic Field Model'

  // Product: '<S1>/Matrix Multiply1'
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply1[i] = rtb_Sum8[i + 6] * rtb_Divide_e + (rtb_Sum8[i + 3] *
      rtb_Sqrt + rtb_Sum8[i] * rtb_Divide1_e_idx_0);
  }

  // End of Product: '<S1>/Matrix Multiply1'

  // Product: '<S2>/Element product'
  rtb_Elementproduct_idx_0 = rtb_magneticmoment[1] * rtb_MatrixMultiply1[2];
  rtb_Elementproduct_idx_1 = rtb_magneticmoment[2] * rtb_MatrixMultiply1[0];
  rtb_Elementproduct_idx_2 = rtb_magneticmoment[0] * rtb_MatrixMultiply1[1];
  rtb_Elementproduct_idx_3 = rtb_magneticmoment[2] * rtb_MatrixMultiply1[1];
  rtb_Elementproduct_idx_4 = rtb_magneticmoment[0] * rtb_MatrixMultiply1[2];
  rtb_Elementproduct_idx_5 = rtb_magneticmoment[1] * rtb_MatrixMultiply1[0];

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtb_DiscreteTimeIntegrator1 = rtDW.DiscreteTimeIntegrator_DSTATE;

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator2 = rtDW.DiscreteTimeIntegrator1_DSTAT_l;

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  rtb_DiscreteTimeIntegrator3 = rtDW.DiscreteTimeIntegrator2_DSTATE;

  // Outputs for Atomic SubSystem: '<S1>/Dynamics'
  // Product: '<S3>/Product' incorporates:
  //   Constant: '<S3>/Constant'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  for (i = 0; i < 3; i++) {
    rtb_magneticmoment[i] = rtConstP.Constant_Value[i + 6] *
      rtDW.DiscreteTimeIntegrator2_DSTATE + (rtConstP.Constant_Value[i + 3] *
      rtDW.DiscreteTimeIntegrator1_DSTAT_l + rtConstP.Constant_Value[i] *
      rtDW.DiscreteTimeIntegrator_DSTATE);
  }

  // End of Product: '<S3>/Product'

  // Sum: '<S3>/Sum' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  //   Product: '<S8>/Element product'
  //   Sum: '<S2>/Add3'
  //   Sum: '<S8>/Add3'

  rtb_Elementproduct_idx_0 = (rtb_Elementproduct_idx_0 -
    rtb_Elementproduct_idx_3) - (rtDW.DiscreteTimeIntegrator1_DSTAT_l *
    rtb_magneticmoment[2] - rtDW.DiscreteTimeIntegrator2_DSTATE *
    rtb_magneticmoment[1]);
  rtb_Elementproduct_idx_1 = (rtb_Elementproduct_idx_1 -
    rtb_Elementproduct_idx_4) - (rtDW.DiscreteTimeIntegrator2_DSTATE *
    rtb_magneticmoment[0] - rtDW.DiscreteTimeIntegrator_DSTATE *
    rtb_magneticmoment[2]);
  rtb_Elementproduct_idx_2 = (rtb_Elementproduct_idx_2 -
    rtb_Elementproduct_idx_5) - (rtDW.DiscreteTimeIntegrator_DSTATE *
    rtb_magneticmoment[1] - rtDW.DiscreteTimeIntegrator1_DSTAT_l *
    rtb_magneticmoment[0]);

  // End of Outputs for SubSystem: '<S1>/Dynamics'

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  //   Fcn: '<S11>/qd1'
  //   Fcn: '<S11>/qd2'
  //   Fcn: '<S11>/qd3'
  //   Fcn: '<S11>/qd4'

  rtDW.DiscreteTimeIntegrator1_DSTATE[0] += ((rtb_Product[3] *
    rtDW.DiscreteTimeIntegrator_DSTATE - rtb_Product[2] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_l) + rtb_Product[1] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0 * 0.01;
  rtDW.DiscreteTimeIntegrator1_DSTATE[1] += ((rtb_Product[2] *
    rtDW.DiscreteTimeIntegrator_DSTATE + rtb_Product[3] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_l) - rtb_Product[0] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0 * 0.01;
  rtDW.DiscreteTimeIntegrator1_DSTATE[2] += ((-rtb_Product[1] *
    rtDW.DiscreteTimeIntegrator_DSTATE + rtb_Product[0] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_l) + rtb_Product[3] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0 * 0.01;
  rtDW.DiscreteTimeIntegrator1_DSTATE[3] += ((-rtb_Product[0] *
    rtDW.DiscreteTimeIntegrator_DSTATE - rtb_Product[1] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_l) - rtb_Product[2] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0 * 0.01;

  // Outputs for Atomic SubSystem: '<S1>/Dynamics'
  for (i = 0; i < 3; i++) {
    // Outport: '<Root>/magnetic field' incorporates:
    //   Product: '<S1>/Matrix Multiply'

    rtY.magneticfield[i] = 0.0;
    rtY.magneticfield[i] += rtb_Sum8[i] * rtb_Divide1_e_idx_0;
    rtY.magneticfield[i] += rtb_Sum8[i + 3] * rtb_Sqrt;
    rtY.magneticfield[i] += rtb_Sum8[i + 6] * rtb_Divide_e;

    // Product: '<S3>/Product1' incorporates:
    //   Constant: '<S3>/Constant1'

    rtb_magneticmoment[i] = rtConstP.Constant1_Value[i + 6] *
      rtb_Elementproduct_idx_2 + (rtConstP.Constant1_Value[i + 3] *
      rtb_Elementproduct_idx_1 + rtConstP.Constant1_Value[i] *
      rtb_Elementproduct_idx_0);
  }

  // End of Outputs for SubSystem: '<S1>/Dynamics'

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.01 * rtb_magneticmoment[0];

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_DSTAT_l += 0.01 * rtb_magneticmoment[1];

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  rtDW.DiscreteTimeIntegrator2_DSTATE += 0.01 * rtb_magneticmoment[2];

  // End of Outputs for SubSystem: '<Root>/Plantv5'

  // Outport: '<Root>/angular velocity'
  rtY.angularvelocity[0] = rtb_DiscreteTimeIntegrator1;
  rtY.angularvelocity[1] = rtb_DiscreteTimeIntegrator2;
  rtY.angularvelocity[2] = rtb_DiscreteTimeIntegrator3;

  // Outport: '<Root>/xyzposition'
  rtY.xyzposition[0] = rtb_MathFunction_d_0;
  rtY.xyzposition[1] = rtb_DiscreteTimeIntegrator5;
  rtY.xyzposition[2] = rtb_DiscreteTimeIntegrator6;

  // Outport: '<Root>/quaternion'
  rtY.quaternion[0] = rtb_Product[0];
  rtY.quaternion[1] = rtb_Product[1];
  rtY.quaternion[2] = rtb_Product[2];
  rtY.quaternion[3] = rtb_Product[3];
}

// Model initialize function
void Plantv50ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // SystemInitialize for Atomic SubSystem: '<Root>/Plantv5'
  // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
  rtDW.DiscreteTimeIntegrator1_DSTATE[0] = 0.20056212114657512;
  rtDW.DiscreteTimeIntegrator1_DSTATE[1] = 0.53197569518216681;
  rtDW.DiscreteTimeIntegrator1_DSTATE[2] = 0.022260026714733816;
  rtDW.DiscreteTimeIntegrator1_DSTATE[3] = 0.82236317190599928;

  // InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_DSTATE = 0.2;

  // InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' 
  rtDW.DiscreteTimeIntegrator1_DSTAT_l = 0.3;

  // InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' 
  rtDW.DiscreteTimeIntegrator2_DSTATE = 0.5;

  // SystemInitialize for Atomic SubSystem: '<S1>/Tranlational Dynamics'
  // InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' 
  rtDW.DiscreteTimeIntegrator1_DSTA_ls = 7000.0;

  // InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator4' 
  rtDW.DiscreteTimeIntegrator4_DSTATE = 7.0E+6;

  // End of SystemInitialize for SubSystem: '<S1>/Tranlational Dynamics'
  // End of SystemInitialize for SubSystem: '<Root>/Plantv5'
}

// Constructor
Plantv50ModelClass::Plantv50ModelClass()
{
}

// Destructor
Plantv50ModelClass::~Plantv50ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * Plantv50ModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
