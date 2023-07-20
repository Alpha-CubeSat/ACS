//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Plantv41.cpp
//
// Code generated for Simulink model 'Plantv41'.
//
// Model version                  : 1.68
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Tue Apr 17 15:30:56 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Arduino.h"
#include "Plantv41.h"
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
void Plantv41ModelClass::stepfwd()
{
  real_T rtb_TmpSignalConversionAtMatrix[3];
  real_T rtb_DiscreteTimeIntegrator1;
  real_T rtb_DiscreteTimeIntegrator2;
  real_T rtb_DiscreteTimeIntegrator3;
  real_T rtb_DiscreteTimeIntegrator4;
  real_T rtb_DiscreteTimeIntegrator5;
  real_T rtb_DiscreteTimeIntegrator6;
  real_T rtb_Sqrt;
  real_T rtb_Divide_e;
  real_T rtb_TrigonometricFunction;
  int32_T i;
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T rtb_Elementproduct_idx_0;
  real_T rtb_Elementproduct_idx_1;
  real_T rtb_Elementproduct_idx_2;
  real_T rtb_Elementproduct_idx_3;
  real_T rtb_Elementproduct_idx_4;
  real_T rtb_Elementproduct_idx_5;

  // Outputs for Atomic SubSystem: '<Root>/Plantv4'
  // Gain: '<S1>/Gain' incorporates:
  //   Inport: '<Root>/current'

  rtb_TmpSignalConversionAtMatrix[0] = 5.013759035753394E-5 * rtU.current[0];
  rtb_TmpSignalConversionAtMatrix[1] = 5.013759035753394E-5 * rtU.current[1];
  rtb_TmpSignalConversionAtMatrix[2] = 5.013759035753394E-5 * rtU.current[2];

  // Outputs for Atomic SubSystem: '<S1>/Tranlational Dynamics'
  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator1 = rtDW.DiscreteTimeIntegrator1_DSTAT_l;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator2'
  rtb_DiscreteTimeIntegrator2 = rtDW.DiscreteTimeIntegrator2_DSTAT_e;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator3'
  rtb_DiscreteTimeIntegrator3 = rtDW.DiscreteTimeIntegrator3_DSTATE;

  // DiscreteIntegrator: '<S6>/Discrete-Time Integrator4'
  rtb_DiscreteTimeIntegrator4 = rtDW.DiscreteTimeIntegrator4_DSTATE;
  //Serial.println("Checks");
  //Serial.println(rtDW.DiscreteTimeIntegrator4_DSTATE);
  //Serial.println(rtb_DiscreteTimeIntegrator4);
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

  rtDW.DiscreteTimeIntegrator1_DSTAT_l += 1.0 / rtb_Sqrt *
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

  rtb_DiscreteTimeIntegrator1 = 6.378E+6 / std::sqrt
    ((rtb_DiscreteTimeIntegrator4 * rtb_DiscreteTimeIntegrator4 +
      rtb_DiscreteTimeIntegrator5 * rtb_DiscreteTimeIntegrator5) +
     rtb_DiscreteTimeIntegrator6 * rtb_DiscreteTimeIntegrator6);

  // Gain: '<S4>/Gain4' incorporates:
  //   Math: '<S4>/Math Function8'
  //   Product: '<S4>/Product'

  rtb_DiscreteTimeIntegrator1 = rtb_DiscreteTimeIntegrator1 *
    rtb_DiscreteTimeIntegrator1 * rtb_DiscreteTimeIntegrator1 * -3.12E-5;

  // Sum: '<S4>/Sum5' incorporates:
  //   Constant: '<S4>/Constant8'
  //   Math: '<S4>/Math Function3'
  //   Math: '<S4>/Math Function4'
  //   Sqrt: '<S4>/Sqrt2'
  //   Sum: '<S4>/Sum3'
  //   Trigonometry: '<S4>/Trigonometric Function3'

  rtb_DiscreteTimeIntegrator3 = 1.5707963267948966 - rt_atan2d_snf
    (rtb_DiscreteTimeIntegrator6, std::sqrt(rtb_DiscreteTimeIntegrator4 *
      rtb_DiscreteTimeIntegrator4 + rtb_DiscreteTimeIntegrator5 *
      rtb_DiscreteTimeIntegrator5));

  // Product: '<S4>/Divide3' incorporates:
  //   Gain: '<S4>/Gain5'
  //   Trigonometry: '<S4>/Trigonometric Function2'

  rtb_Sqrt = 2.0 * rtb_DiscreteTimeIntegrator1 * std::cos
    (rtb_DiscreteTimeIntegrator3);

  // Product: '<S4>/Divide4' incorporates:
  //   Trigonometry: '<S4>/Trigonometric Function4'

  rtb_Divide_e = rtb_DiscreteTimeIntegrator1 * std::sin
    (rtb_DiscreteTimeIntegrator3);

  // Outputs for Atomic SubSystem: '<S4>/Dipole->ECI'
  // Sum: '<S9>/Sum6' incorporates:
  //   Gain: '<S4>/Gain6'
  //   Product: '<S9>/Product3'
  //   Product: '<S9>/Product4'
  //   Trigonometry: '<S9>/Trigonometric Function7'
  //   Trigonometry: '<S9>/Trigonometric Function8'

  rtb_DiscreteTimeIntegrator2 = std::cos(-rtb_DiscreteTimeIntegrator3) *
    rtb_Divide_e + std::sin(-rtb_DiscreteTimeIntegrator3) * rtb_Sqrt;

  // Trigonometry: '<S9>/Trigonometric Function'
  rtb_TrigonometricFunction = rt_atan2d_snf(rtb_DiscreteTimeIntegrator5,
    rtb_DiscreteTimeIntegrator4);

  // Product: '<S9>/Divide' incorporates:
  //   Trigonometry: '<S9>/Trigonometric Function2'

  rtb_DiscreteTimeIntegrator1 = rtb_DiscreteTimeIntegrator2 * std::sin
    (rtb_TrigonometricFunction);

  // Product: '<S9>/Divide1' incorporates:
  //   Trigonometry: '<S9>/Trigonometric Function1'

  rtb_DiscreteTimeIntegrator2 *= std::cos(rtb_TrigonometricFunction);

  // Sum: '<S9>/Sum5' incorporates:
  //   Gain: '<S4>/Gain6'
  //   Product: '<S9>/Product1'
  //   Product: '<S9>/Product2'
  //   Trigonometry: '<S9>/Trigonometric Function5'
  //   Trigonometry: '<S9>/Trigonometric Function6'

  rtb_DiscreteTimeIntegrator3 = std::cos(-rtb_DiscreteTimeIntegrator3) *
    rtb_Sqrt - std::sin(-rtb_DiscreteTimeIntegrator3) * rtb_Divide_e;

  // End of Outputs for SubSystem: '<S4>/Dipole->ECI'
  // End of Outputs for SubSystem: '<S1>/Magnetic Field Model'

  // Product: '<S2>/Element product'
  rtb_Elementproduct_idx_0 = rtb_TmpSignalConversionAtMatrix[1] *
    rtb_DiscreteTimeIntegrator3;
  rtb_Elementproduct_idx_1 = rtb_TmpSignalConversionAtMatrix[2] *
    rtb_DiscreteTimeIntegrator2;
  rtb_Elementproduct_idx_2 = rtb_TmpSignalConversionAtMatrix[0] *
    rtb_DiscreteTimeIntegrator1;
  rtb_Elementproduct_idx_3 = rtb_TmpSignalConversionAtMatrix[2] *
    rtb_DiscreteTimeIntegrator1;
  rtb_Elementproduct_idx_4 = rtb_TmpSignalConversionAtMatrix[0] *
    rtb_DiscreteTimeIntegrator3;
  rtb_Elementproduct_idx_5 = rtb_TmpSignalConversionAtMatrix[1] *
    rtb_DiscreteTimeIntegrator2;

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtb_Sqrt = rtDW.DiscreteTimeIntegrator_DSTATE;

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtb_Divide_e = rtDW.DiscreteTimeIntegrator1_DSTATE;

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  rtb_TrigonometricFunction = rtDW.DiscreteTimeIntegrator2_DSTATE;

  // Outputs for Atomic SubSystem: '<S1>/Dynamics'
  // Product: '<S3>/Product' incorporates:
  //   Constant: '<S3>/Constant'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = rtConstP.Constant_Value[i + 6] *
      rtDW.DiscreteTimeIntegrator2_DSTATE + (rtConstP.Constant_Value[i + 3] *
      rtDW.DiscreteTimeIntegrator1_DSTATE + rtConstP.Constant_Value[i] *
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
    rtb_Elementproduct_idx_3) - (rtDW.DiscreteTimeIntegrator1_DSTATE *
    rtb_TmpSignalConversionAtMatrix[2] - rtDW.DiscreteTimeIntegrator2_DSTATE *
    rtb_TmpSignalConversionAtMatrix[1]);
  rtb_Elementproduct_idx_1 = (rtb_Elementproduct_idx_1 -
    rtb_Elementproduct_idx_4) - (rtDW.DiscreteTimeIntegrator2_DSTATE *
    rtb_TmpSignalConversionAtMatrix[0] - rtDW.DiscreteTimeIntegrator_DSTATE *
    rtb_TmpSignalConversionAtMatrix[2]);
  rtb_Elementproduct_idx_2 = (rtb_Elementproduct_idx_2 -
    rtb_Elementproduct_idx_5) - (rtDW.DiscreteTimeIntegrator_DSTATE *
    rtb_TmpSignalConversionAtMatrix[1] - rtDW.DiscreteTimeIntegrator1_DSTATE *
    rtb_TmpSignalConversionAtMatrix[0]);

  // Product: '<S3>/Product1' incorporates:
  //   Constant: '<S3>/Constant1'

  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = rtConstP.Constant1_Value[i + 6] *
      rtb_Elementproduct_idx_2 + (rtConstP.Constant1_Value[i + 3] *
      rtb_Elementproduct_idx_1 + rtConstP.Constant1_Value[i] *
      rtb_Elementproduct_idx_0);
  }

  // End of Product: '<S3>/Product1'
  // End of Outputs for SubSystem: '<S1>/Dynamics'

  // DotProduct: '<S10>/Dot Product' incorporates:
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'

  rtb_Elementproduct_idx_0 = ((rtDW.DiscreteTimeIntegrator1_DSTAT_m[0] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[0] +
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[1] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[1]) +
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[2] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[2]) +
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[3] *
    rtDW.DiscreteTimeIntegrator1_DSTAT_m[3];

  // Math: '<S10>/Math Function' incorporates:
  //   DotProduct: '<S10>/Dot Product'
  //
  //  About '<S10>/Math Function':
  //   Operator: sqrt

  if (rtb_Elementproduct_idx_0 < 0.0) {
    rtb_Elementproduct_idx_0 = -std::sqrt(std::abs(rtb_Elementproduct_idx_0));
  } else {
    rtb_Elementproduct_idx_0 = std::sqrt(rtb_Elementproduct_idx_0);
  }

  // End of Math: '<S10>/Math Function'

  // Product: '<S10>/Product' incorporates:
  //   DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'

  rtY.quaternion[0] = rtDW.DiscreteTimeIntegrator1_DSTAT_m[0] /
    rtb_Elementproduct_idx_0;
  rtY.quaternion[1] = rtDW.DiscreteTimeIntegrator1_DSTAT_m[1] /
    rtb_Elementproduct_idx_0;
  rtY.quaternion[2] = rtDW.DiscreteTimeIntegrator1_DSTAT_m[2] /
    rtb_Elementproduct_idx_0;
  rtY.quaternion[3] = rtDW.DiscreteTimeIntegrator1_DSTAT_m[3] /
    rtb_Elementproduct_idx_0;

  // Outputs for Atomic SubSystem: '<S1>/qtoQ'
  // Sum: '<S7>/Sum1' incorporates:
  //   Math: '<S7>/T2'
  //   Product: '<S7>/Product1'
  //   Product: '<S7>/qTq'

  rtb_Elementproduct_idx_0 = rtY.quaternion[3] * rtY.quaternion[3] -
    ((rtY.quaternion[0] * rtY.quaternion[0] + rtY.quaternion[1] *
      rtY.quaternion[1]) + rtY.quaternion[2] * rtY.quaternion[2]);

  // End of Outputs for SubSystem: '<S1>/qtoQ'

  // Fcn: '<S11>/qd1' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtb_Elementproduct_idx_1 = ((rtY.quaternion[3] *
    rtDW.DiscreteTimeIntegrator_DSTATE - rtY.quaternion[2] *
    rtDW.DiscreteTimeIntegrator1_DSTATE) + rtY.quaternion[1] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0;

  // Fcn: '<S11>/qd2' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtb_Elementproduct_idx_2 = ((rtY.quaternion[2] *
    rtDW.DiscreteTimeIntegrator_DSTATE + rtY.quaternion[3] *
    rtDW.DiscreteTimeIntegrator1_DSTATE) - rtY.quaternion[0] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0;

  // Fcn: '<S11>/qd3' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtb_Elementproduct_idx_3 = ((-rtY.quaternion[1] *
    rtDW.DiscreteTimeIntegrator_DSTATE + rtY.quaternion[0] *
    rtDW.DiscreteTimeIntegrator1_DSTATE) + rtY.quaternion[3] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0;

  // Fcn: '<S11>/qd4' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtb_Elementproduct_idx_4 = ((-rtY.quaternion[0] *
    rtDW.DiscreteTimeIntegrator_DSTATE - rtY.quaternion[1] *
    rtDW.DiscreteTimeIntegrator1_DSTATE) - rtY.quaternion[2] *
    rtDW.DiscreteTimeIntegrator2_DSTATE) / 2.0;

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.01 * rtb_TmpSignalConversionAtMatrix[0];

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_DSTATE += 0.01 * rtb_TmpSignalConversionAtMatrix
    [1];

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  rtDW.DiscreteTimeIntegrator2_DSTATE += 0.01 * rtb_TmpSignalConversionAtMatrix
    [2];

  // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.01 * rtb_Elementproduct_idx_1;
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.01 * rtb_Elementproduct_idx_2;
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[2] += 0.01 * rtb_Elementproduct_idx_3;
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[3] += 0.01 * rtb_Elementproduct_idx_4;

  // End of Outputs for SubSystem: '<Root>/Plantv4'

  // Outport: '<Root>/angular velocity'
  rtY.angularvelocity[0] = rtb_Sqrt;
  rtY.angularvelocity[1] = rtb_Divide_e;
  rtY.angularvelocity[2] = rtb_TrigonometricFunction;

  // Outputs for Atomic SubSystem: '<Root>/Plantv4'
  // Outputs for Atomic SubSystem: '<S1>/qtoQ'
  // Product: '<S7>/qqT' incorporates:
  //   Gain: '<S7>/Gain2'
  //   Math: '<S7>/T1'

  for (i = 0; i < 3; i++) {
    tmp[i] = rtY.quaternion[i] * rtY.quaternion[0];
    tmp[i + 3] = rtY.quaternion[i] * rtY.quaternion[1];
    tmp[i + 6] = rtY.quaternion[i] * rtY.quaternion[2];
  }

  // End of Product: '<S7>/qqT'

  // Reshape: '<S12>/3x3' incorporates:
  //   Constant: '<S12>/diag 0 '
  //   Gain: '<S12>/Gain'
  //   Gain: '<S12>/Gain1'
  //   Gain: '<S12>/Gain2'
  //   Product: '<S7>/Product'

  tmp_0[0] = 0.0;
  tmp_0[1] = rtY.quaternion[2];
  tmp_0[2] = -rtY.quaternion[1];
  tmp_0[3] = -rtY.quaternion[2];
  tmp_0[4] = 0.0;
  tmp_0[5] = rtY.quaternion[0];
  tmp_0[6] = rtY.quaternion[1];
  tmp_0[7] = -rtY.quaternion[0];
  tmp_0[8] = 0.0;

  // Product: '<S7>/Product'
  rtb_Sqrt = rtY.quaternion[3];

  // Sum: '<S7>/Sum8' incorporates:
  //   Gain: '<S7>/Gain1'
  //   Gain: '<S7>/Gain2'
  //   Gain: '<S7>/Matrix Gain'
  //   Product: '<S1>/Matrix Multiply'
  //   Product: '<S7>/Product'

  for (i = 0; i < 3; i++) {
    tmp_1[3 * i] = (tmp[3 * i] * 2.0 - tmp_0[3 * i] * rtb_Sqrt * 2.0) +
      rtConstP.MatrixGain_Gain[3 * i] * rtb_Elementproduct_idx_0;
    tmp_1[1 + 3 * i] = (tmp[3 * i + 1] * 2.0 - tmp_0[3 * i + 1] * rtb_Sqrt * 2.0)
      + rtConstP.MatrixGain_Gain[3 * i + 1] * rtb_Elementproduct_idx_0;
    tmp_1[2 + 3 * i] = (tmp[3 * i + 2] * 2.0 - tmp_0[3 * i + 2] * rtb_Sqrt * 2.0)
      + rtConstP.MatrixGain_Gain[3 * i + 2] * rtb_Elementproduct_idx_0;
  }

  // End of Sum: '<S7>/Sum8'
  // End of Outputs for SubSystem: '<S1>/qtoQ'
  // End of Outputs for SubSystem: '<Root>/Plantv4'

  // Outport: '<Root>/magnetic field' incorporates:
  //   Product: '<S1>/Matrix Multiply'
  //   SignalConversion: '<S1>/TmpSignal ConversionAtMatrix MultiplyInport2'

  for (i = 0; i < 3; i++) {
    // Outputs for Atomic SubSystem: '<Root>/Plantv4'
    rtY.magneticfield[i] = 0.0;
    rtY.magneticfield[i] += tmp_1[i] * rtb_DiscreteTimeIntegrator2;
    rtY.magneticfield[i] += tmp_1[i + 3] * rtb_DiscreteTimeIntegrator1;
    rtY.magneticfield[i] += tmp_1[i + 6] * rtb_DiscreteTimeIntegrator3;

    // End of Outputs for SubSystem: '<Root>/Plantv4'
  }
	//Serial.println("MAGNETIC FIELD");
	//Serial.println(rtY.magneticfield[0]);
	//Serial.println(rtY.magneticfield[1]);
	//Serial.println(rtY.magneticfield[2]);
  // End of Outport: '<Root>/magnetic field'

  // Outport: '<Root>/xyzposition'
  rtY.xyzposition[0] = rtb_DiscreteTimeIntegrator4;
  rtY.xyzposition[1] = rtb_DiscreteTimeIntegrator5;
  rtY.xyzposition[2] = rtb_DiscreteTimeIntegrator6;
  //Serial.println("XYZ POSITION");
  //Serial.println(rtY.xyzposition[0]);
  //Serial.println(rtY.xyzposition[1]);
  //Serial.println(rtY.xyzposition[2]);
}

// Model initialize function
void Plantv41ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // SystemInitialize for Atomic SubSystem: '<Root>/Plantv4'
  // InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' 
  rtDW.DiscreteTimeIntegrator2_DSTATE = -0.78539816339744828;

  // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[0] = 0.0;
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[1] = 0.0;
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[2] = 0.15643446504023087;
  rtDW.DiscreteTimeIntegrator1_DSTAT_m[3] = 0.98768834059513777;

  // SystemInitialize for Atomic SubSystem: '<S1>/Tranlational Dynamics'
  // InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator2' 
  rtDW.DiscreteTimeIntegrator2_DSTAT_e = 7000.0;
  
  // InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator4' 
  rtDW.DiscreteTimeIntegrator4_DSTATE = 7.0E+6;
  //Serial.println("Does this shit even work?");
  //Serial.println(rtDW.DiscreteTimeIntegrator4_DSTATE);
  // End of SystemInitialize for SubSystem: '<S1>/Tranlational Dynamics'
  // End of SystemInitialize for SubSystem: '<Root>/Plantv4'
  //Serial.println("INITIALIZING");
}

// Constructor
Plantv41ModelClass::Plantv41ModelClass()
{
}

// Destructor
Plantv41ModelClass::~Plantv41ModelClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
