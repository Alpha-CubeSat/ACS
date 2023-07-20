/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Plantv2.c
 *
 * Code generated for Simulink model 'Plantv2'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Apr 10 17:02:28 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Plantv2.h"
#define NumBitsPerChar                 8U

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_atan2d_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void Plantv2_derivatives(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

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

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
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

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
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

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
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

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
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

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Plantv2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Plantv2_step();
  Plantv2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Plantv2_step();
  Plantv2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
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

    y = atan2(u0_0, u1_0);
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

/* Model step function */
void Plantv2_step(void)
{
  real_T rtb_Product[4];
  real_T rtb_TmpSignalConversionAtMatrix[3];
  real_T rtb_Sqrt;
  real_T rtb_Divide_e;
  real_T rtb_Gain4;
  real_T rtb_Gain6;
  real_T rtb_TrigonometricFunction;
  real_T rtb_Sum6;
  int32_T i;
  real_T rtb_Product_0[9];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T rtb_Elementproduct_idx_3;
  real_T rtb_Elementproduct_idx_4;
  real_T rtb_Elementproduct_idx_5;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  /* Outputs for Atomic SubSystem: '<Root>/Plantv2' */
  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/current'
   */
  rtb_TmpSignalConversionAtMatrix[0] = 5.013759035753394E-5 * rtU.current[0];
  rtb_TmpSignalConversionAtMatrix[1] = 5.013759035753394E-5 * rtU.current[1];
  rtb_TmpSignalConversionAtMatrix[2] = 5.013759035753394E-5 * rtU.current[2];

  /* Outputs for Atomic SubSystem: '<S1>/Tranlational Dynamics' */
  /* Sqrt: '<S6>/Sqrt' incorporates:
   *  DotProduct: '<S6>/Dot Product'
   *  DotProduct: '<S6>/Dot Product1'
   *  DotProduct: '<S6>/Dot Product2'
   *  Integrator: '<S6>/Integrator'
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S6>/Integrator2'
   *  Sum: '<S6>/Sum'
   */
  rtb_Sqrt = sqrt((rtX.Integrator_CSTATE * rtX.Integrator_CSTATE +
                   rtX.Integrator1_CSTATE_c * rtX.Integrator1_CSTATE_c) +
                  rtX.Integrator2_CSTATE * rtX.Integrator2_CSTATE);

  /* Product: '<S6>/Divide' incorporates:
   *  Math: '<S6>/Math Function'
   */
  rtb_Divide_e = 1.0 / (rtb_Sqrt * rtb_Sqrt) * -3.342008836E+14;

  /* DotProduct: '<S6>/Dot Product3' incorporates:
   *  Integrator: '<S6>/Integrator2'
   *  Product: '<S6>/Divide1'
   */
  rtDW.DotProduct3 = 1.0 / rtb_Sqrt * rtX.Integrator2_CSTATE * rtb_Divide_e;

  /* DotProduct: '<S6>/Dot Product4' incorporates:
   *  Integrator: '<S6>/Integrator1'
   *  Product: '<S6>/Divide1'
   */
  rtDW.DotProduct4 = 1.0 / rtb_Sqrt * rtX.Integrator1_CSTATE_c * rtb_Divide_e;

  /* DotProduct: '<S6>/Dot Product5' incorporates:
   *  Integrator: '<S6>/Integrator'
   *  Product: '<S6>/Divide1'
   */
  rtDW.DotProduct5 = 1.0 / rtb_Sqrt * rtX.Integrator_CSTATE * rtb_Divide_e;

  /* Integrator: '<S6>/Integrator3' */
  rtDW.Integrator3 = rtX.Integrator3_CSTATE;

  /* Integrator: '<S6>/Integrator4' */
  rtDW.Integrator4 = rtX.Integrator4_CSTATE;

  /* Integrator: '<S6>/Integrator5' */
  rtDW.Integrator5 = rtX.Integrator5_CSTATE;

  /* Outputs for Atomic SubSystem: '<S1>/Magnetic Field Model' */
  /* Product: '<S4>/Divide2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Integrator: '<S6>/Integrator'
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S6>/Integrator2'
   *  Math: '<S4>/Math Function5'
   *  Math: '<S4>/Math Function6'
   *  Math: '<S4>/Math Function7'
   *  Sqrt: '<S4>/Sqrt3'
   *  Sum: '<S4>/Sum4'
   */
  rtb_Gain4 = 6.378E+6 / sqrt((rtX.Integrator_CSTATE * rtX.Integrator_CSTATE +
    rtX.Integrator1_CSTATE_c * rtX.Integrator1_CSTATE_c) +
    rtX.Integrator2_CSTATE * rtX.Integrator2_CSTATE);

  /* End of Outputs for SubSystem: '<S1>/Tranlational Dynamics' */

  /* Gain: '<S4>/Gain4' incorporates:
   *  Math: '<S4>/Math Function8'
   *  Product: '<S4>/Product'
   */
  rtb_Gain4 = rtb_Gain4 * rtb_Gain4 * rtb_Gain4 * -3.12E-5;

  /* Outputs for Atomic SubSystem: '<S1>/Tranlational Dynamics' */
  /* Sum: '<S4>/Sum5' incorporates:
   *  Constant: '<S4>/Constant8'
   *  Integrator: '<S6>/Integrator'
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S6>/Integrator2'
   *  Math: '<S4>/Math Function3'
   *  Math: '<S4>/Math Function4'
   *  Sqrt: '<S4>/Sqrt2'
   *  Sum: '<S4>/Sum3'
   *  Trigonometry: '<S4>/Trigonometric Function3'
   */
  rtb_Sqrt = 1.5707963267948966 - rt_atan2d_snf(rtX.Integrator2_CSTATE, sqrt
    (rtX.Integrator_CSTATE * rtX.Integrator_CSTATE + rtX.Integrator1_CSTATE_c *
     rtX.Integrator1_CSTATE_c));

  /* End of Outputs for SubSystem: '<S1>/Tranlational Dynamics' */

  /* Product: '<S4>/Divide3' incorporates:
   *  Gain: '<S4>/Gain5'
   *  Trigonometry: '<S4>/Trigonometric Function2'
   */
  rtb_Divide_e = 2.0 * rtb_Gain4 * cos(rtb_Sqrt);

  /* Product: '<S4>/Divide4' incorporates:
   *  Trigonometry: '<S4>/Trigonometric Function4'
   */
  rtb_Gain4 *= sin(rtb_Sqrt);

  /* Gain: '<S4>/Gain6' */
  rtb_Gain6 = -rtb_Sqrt;

  /* Outputs for Atomic SubSystem: '<S4>/Dipole->ECI' */
  /* Sum: '<S9>/Sum6' incorporates:
   *  Gain: '<S4>/Gain6'
   *  Product: '<S9>/Product3'
   *  Product: '<S9>/Product4'
   *  Trigonometry: '<S9>/Trigonometric Function7'
   *  Trigonometry: '<S9>/Trigonometric Function8'
   */
  rtb_Sum6 = cos(-rtb_Sqrt) * rtb_Gain4 + sin(-rtb_Sqrt) * rtb_Divide_e;

  /* Outputs for Atomic SubSystem: '<S1>/Tranlational Dynamics' */
  /* Trigonometry: '<S9>/Trigonometric Function' incorporates:
   *  Integrator: '<S6>/Integrator'
   *  Integrator: '<S6>/Integrator1'
   */
  rtb_TrigonometricFunction = rt_atan2d_snf(rtX.Integrator1_CSTATE_c,
    rtX.Integrator_CSTATE);

  /* End of Outputs for SubSystem: '<S1>/Tranlational Dynamics' */

  /* Product: '<S9>/Divide' incorporates:
   *  Trigonometry: '<S9>/Trigonometric Function2'
   */
  rtb_Sqrt = rtb_Sum6 * sin(rtb_TrigonometricFunction);

  /* Product: '<S9>/Divide1' incorporates:
   *  Trigonometry: '<S9>/Trigonometric Function1'
   */
  rtb_Sum6 *= cos(rtb_TrigonometricFunction);

  /* Sum: '<S9>/Sum5' incorporates:
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   *  Trigonometry: '<S9>/Trigonometric Function5'
   *  Trigonometry: '<S9>/Trigonometric Function6'
   */
  rtb_Divide_e = cos(rtb_Gain6) * rtb_Divide_e - sin(rtb_Gain6) * rtb_Gain4;

  /* End of Outputs for SubSystem: '<S4>/Dipole->ECI' */
  /* End of Outputs for SubSystem: '<S1>/Magnetic Field Model' */

  /* Product: '<S2>/Element product' */
  rtb_Gain4 = rtb_TmpSignalConversionAtMatrix[1] * rtb_Divide_e;
  rtb_Gain6 = rtb_TmpSignalConversionAtMatrix[2] * rtb_Sum6;
  rtb_TrigonometricFunction = rtb_TmpSignalConversionAtMatrix[0] * rtb_Sqrt;
  rtb_Elementproduct_idx_3 = rtb_TmpSignalConversionAtMatrix[2] * rtb_Sqrt;
  rtb_Elementproduct_idx_4 = rtb_TmpSignalConversionAtMatrix[0] * rtb_Divide_e;
  rtb_Elementproduct_idx_5 = rtb_TmpSignalConversionAtMatrix[1] * rtb_Sum6;

  /* Outputs for Atomic SubSystem: '<S1>/Dynamics' */
  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant'
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = rtConstP.Constant_Value[i + 6] *
      rtX.Integrator11_CSTATE + (rtConstP.Constant_Value[i + 3] *
      rtX.Integrator10_CSTATE + rtConstP.Constant_Value[i] *
      rtX.Integrator9_CSTATE);
  }

  /* End of Product: '<S3>/Product' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   *  Product: '<S8>/Element product'
   *  Sum: '<S2>/Add3'
   *  Sum: '<S8>/Add3'
   */
  rtb_Gain4 = (rtb_Gain4 - rtb_Elementproduct_idx_3) - (rtX.Integrator10_CSTATE *
    rtb_TmpSignalConversionAtMatrix[2] - rtX.Integrator11_CSTATE *
    rtb_TmpSignalConversionAtMatrix[1]);
  rtb_Gain6 = (rtb_Gain6 - rtb_Elementproduct_idx_4) - (rtX.Integrator11_CSTATE *
    rtb_TmpSignalConversionAtMatrix[0] - rtX.Integrator9_CSTATE *
    rtb_TmpSignalConversionAtMatrix[2]);
  rtb_TrigonometricFunction = (rtb_TrigonometricFunction -
    rtb_Elementproduct_idx_5) - (rtX.Integrator9_CSTATE *
    rtb_TmpSignalConversionAtMatrix[1] - rtX.Integrator10_CSTATE *
    rtb_TmpSignalConversionAtMatrix[0]);

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  for (i = 0; i < 3; i++) {
    rtDW.Product1[i] = 0.0;
    rtDW.Product1[i] += rtConstP.Constant1_Value[i] * rtb_Gain4;
    rtDW.Product1[i] += rtConstP.Constant1_Value[i + 3] * rtb_Gain6;
    rtDW.Product1[i] += rtConstP.Constant1_Value[i + 6] *
      rtb_TrigonometricFunction;
  }

  /* End of Product: '<S3>/Product1' */
  /* End of Outputs for SubSystem: '<S1>/Dynamics' */

  /* DotProduct: '<S10>/Dot Product' incorporates:
   *  Integrator: '<S5>/Integrator1'
   */
  rtb_Gain4 = ((rtX.Integrator1_CSTATE[0] * rtX.Integrator1_CSTATE[0] +
                rtX.Integrator1_CSTATE[1] * rtX.Integrator1_CSTATE[1]) +
               rtX.Integrator1_CSTATE[2] * rtX.Integrator1_CSTATE[2]) +
    rtX.Integrator1_CSTATE[3] * rtX.Integrator1_CSTATE[3];

  /* Math: '<S10>/Math Function' incorporates:
   *  DotProduct: '<S10>/Dot Product'
   *
   * About '<S10>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Gain4 < 0.0) {
    rtb_Gain4 = -sqrt(fabs(rtb_Gain4));
  } else {
    rtb_Gain4 = sqrt(rtb_Gain4);
  }

  /* End of Math: '<S10>/Math Function' */

  /* Product: '<S10>/Product' incorporates:
   *  Integrator: '<S5>/Integrator1'
   */
  rtb_Product[0] = rtX.Integrator1_CSTATE[0] / rtb_Gain4;
  rtb_Product[1] = rtX.Integrator1_CSTATE[1] / rtb_Gain4;
  rtb_Product[2] = rtX.Integrator1_CSTATE[2] / rtb_Gain4;
  rtb_Product[3] = rtX.Integrator1_CSTATE[3] / rtb_Gain4;

  /* Outputs for Atomic SubSystem: '<S1>/qtoQ' */
  /* Sum: '<S7>/Sum1' incorporates:
   *  Math: '<S7>/T2'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/qTq'
   */
  rtb_Gain4 = rtb_Product[3] * rtb_Product[3] - ((rtb_Product[0] * rtb_Product[0]
    + rtb_Product[1] * rtb_Product[1]) + rtb_Product[2] * rtb_Product[2]);

  /* End of Outputs for SubSystem: '<S1>/qtoQ' */

  /* Fcn: '<S11>/qd1' incorporates:
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   */
  rtDW.qd1 = ((rtb_Product[3] * rtX.Integrator9_CSTATE - rtb_Product[2] *
               rtX.Integrator10_CSTATE) + rtb_Product[1] *
              rtX.Integrator11_CSTATE) / 2.0;

  /* Fcn: '<S11>/qd2' incorporates:
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   */
  rtDW.qd2 = ((rtb_Product[2] * rtX.Integrator9_CSTATE + rtb_Product[3] *
               rtX.Integrator10_CSTATE) - rtb_Product[0] *
              rtX.Integrator11_CSTATE) / 2.0;

  /* Fcn: '<S11>/qd3' incorporates:
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   */
  rtDW.qd3 = ((-rtb_Product[1] * rtX.Integrator9_CSTATE + rtb_Product[0] *
               rtX.Integrator10_CSTATE) + rtb_Product[3] *
              rtX.Integrator11_CSTATE) / 2.0;

  /* Fcn: '<S11>/qd4' incorporates:
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   */
  rtDW.qd4 = ((-rtb_Product[0] * rtX.Integrator9_CSTATE - rtb_Product[1] *
               rtX.Integrator10_CSTATE) - rtb_Product[2] *
              rtX.Integrator11_CSTATE) / 2.0;

  /* Outport: '<Root>/angular velocity' incorporates:
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator9'
   */
  rtY.angularvelocity[0] = rtX.Integrator9_CSTATE;
  rtY.angularvelocity[1] = rtX.Integrator10_CSTATE;
  rtY.angularvelocity[2] = rtX.Integrator11_CSTATE;

  /* Outputs for Atomic SubSystem: '<S1>/qtoQ' */
  /* Product: '<S7>/qqT' incorporates:
   *  Gain: '<S7>/Gain2'
   *  Math: '<S7>/T1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_0[i] = rtb_Product[i] * rtb_Product[0];
    rtb_Product_0[i + 3] = rtb_Product[i] * rtb_Product[1];
    rtb_Product_0[i + 6] = rtb_Product[i] * rtb_Product[2];
  }

  /* End of Product: '<S7>/qqT' */

  /* Reshape: '<S12>/3x3' incorporates:
   *  Constant: '<S12>/diag 0 '
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S12>/Gain2'
   *  Product: '<S7>/Product'
   */
  tmp[0] = 0.0;
  tmp[1] = rtb_Product[2];
  tmp[2] = -rtb_Product[1];
  tmp[3] = -rtb_Product[2];
  tmp[4] = 0.0;
  tmp[5] = rtb_Product[0];
  tmp[6] = rtb_Product[1];
  tmp[7] = -rtb_Product[0];
  tmp[8] = 0.0;

  /* Product: '<S7>/Product' */
  rtb_Gain6 = rtb_Product[3];

  /* Sum: '<S7>/Sum8' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Gain: '<S7>/Matrix Gain'
   *  Product: '<S1>/Matrix Multiply'
   *  Product: '<S7>/Product'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[3 * i] = (rtb_Product_0[3 * i] * 2.0 - tmp[3 * i] * rtb_Gain6 * 2.0) +
      rtConstP.MatrixGain_Gain[3 * i] * rtb_Gain4;
    tmp_0[1 + 3 * i] = (rtb_Product_0[3 * i + 1] * 2.0 - tmp[3 * i + 1] *
                        rtb_Gain6 * 2.0) + rtConstP.MatrixGain_Gain[3 * i + 1] *
      rtb_Gain4;
    tmp_0[2 + 3 * i] = (rtb_Product_0[3 * i + 2] * 2.0 - tmp[3 * i + 2] *
                        rtb_Gain6 * 2.0) + rtConstP.MatrixGain_Gain[3 * i + 2] *
      rtb_Gain4;
  }

  /* End of Sum: '<S7>/Sum8' */
  /* End of Outputs for SubSystem: '<S1>/qtoQ' */
  /* End of Outputs for SubSystem: '<Root>/Plantv2' */

  /* Outport: '<Root>/magnetic field' incorporates:
   *  Product: '<S1>/Matrix Multiply'
   *  SignalConversion: '<S1>/TmpSignal ConversionAtMatrix MultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<Root>/Plantv2' */
    rtY.magneticfield[i] = 0.0;
    rtY.magneticfield[i] += tmp_0[i] * rtb_Sum6;
    rtY.magneticfield[i] += tmp_0[i + 3] * rtb_Sqrt;
    rtY.magneticfield[i] += tmp_0[i + 6] * rtb_Divide_e;

    /* End of Outputs for SubSystem: '<Root>/Plantv2' */
  }

  /* End of Outport: '<Root>/magnetic field' */

  /* Outputs for Atomic SubSystem: '<Root>/Plantv2' */
  /* Outputs for Atomic SubSystem: '<S1>/Tranlational Dynamics' */
  /* Outport: '<Root>/xyzposition' incorporates:
   *  Integrator: '<S6>/Integrator'
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S6>/Integrator2'
   */
  rtY.xyzposition[0] = rtX.Integrator_CSTATE;
  rtY.xyzposition[1] = rtX.Integrator1_CSTATE_c;
  rtY.xyzposition[2] = rtX.Integrator2_CSTATE;

  /* End of Outputs for SubSystem: '<S1>/Tranlational Dynamics' */
  /* End of Outputs for SubSystem: '<Root>/Plantv2' */

  /* Outport: '<Root>/quaternion' */
  rtY.quaternion[0] = rtb_Product[0];
  rtY.quaternion[1] = rtb_Product[1];
  rtY.quaternion[2] = rtb_Product[2];
  rtY.quaternion[3] = rtb_Product[3];
  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Plantv2_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/Plantv2' */
  /* Derivatives for Atomic SubSystem: '<S1>/Tranlational Dynamics' */
  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtDW.Integrator3;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_c = rtDW.Integrator4;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = rtDW.Integrator5;

  /* Derivatives for Integrator: '<S6>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = rtDW.DotProduct5;

  /* Derivatives for Integrator: '<S6>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = rtDW.DotProduct4;

  /* Derivatives for Integrator: '<S6>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = rtDW.DotProduct3;

  /* End of Derivatives for SubSystem: '<S1>/Tranlational Dynamics' */

  /* Derivatives for Integrator: '<S1>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = rtDW.Product1[0];

  /* Derivatives for Integrator: '<S1>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = rtDW.Product1[1];

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = rtDW.Product1[2];

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = rtDW.qd1;
  _rtXdot->Integrator1_CSTATE[1] = rtDW.qd2;
  _rtXdot->Integrator1_CSTATE[2] = rtDW.qd3;
  _rtXdot->Integrator1_CSTATE[3] = rtDW.qd4;

  /* End of Derivatives for SubSystem: '<Root>/Plantv2' */
}

/* Model initialize function */
void Plantv2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.01;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Plantv2' */
  /* InitializeConditions for Integrator: '<S1>/Integrator9' */
  rtX.Integrator9_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator10' */
  rtX.Integrator10_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  rtX.Integrator11_CSTATE = -0.78539816339744828;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  rtX.Integrator1_CSTATE[0] = 0.0;
  rtX.Integrator1_CSTATE[1] = 0.0;
  rtX.Integrator1_CSTATE[2] = 0.15643446504023087;
  rtX.Integrator1_CSTATE[3] = 0.98768834059513777;

  /* SystemInitialize for Atomic SubSystem: '<S1>/Tranlational Dynamics' */
  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  rtX.Integrator_CSTATE = 7.0E+6;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  rtX.Integrator1_CSTATE_c = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  rtX.Integrator2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator3' */
  rtX.Integrator3_CSTATE = 7000.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator4' */
  rtX.Integrator4_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator5' */
  rtX.Integrator5_CSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<S1>/Tranlational Dynamics' */
  /* End of SystemInitialize for SubSystem: '<Root>/Plantv2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
