/*
 * starshotsimv4p3lqrproto.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "starshotsimv4p3lqrproto".
 *
 * Model version              : 1.64
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Mar 01 12:33:26 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "starshotsimv4p3lqrproto.h"
#include "starshotsimv4p3lqrproto_private.h"

/* Block signals (auto storage) */
B_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_B;

/* Continuous states */
X_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_X;

/* Block states (auto storage) */
DW_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_DW;

/* Real-time model */
RT_MODEL_starshotsimv4p3lqrpr_T starshotsimv4p3lqrproto_M_;
RT_MODEL_starshotsimv4p3lqrpr_T *const starshotsimv4p3lqrproto_M =
  &starshotsimv4p3lqrproto_M_;

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
  starshotsimv4p3lqrproto_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  starshotsimv4p3lqrproto_step();
  starshotsimv4p3lqrproto_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  starshotsimv4p3lqrproto_step();
  starshotsimv4p3lqrproto_derivatives();

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
void starshotsimv4p3lqrproto_step(void)
{
  real_T rtb_Product_l[4];
  real_T rtb_Saturation3;
  real_T rtb_Saturation5;
  real_T rtb_Saturation4;
  real_T rtb_DotProduct2;
  real_T rtb_Divide;
  real_T rtb_Sqrt;
  real_T rtb_Product_l2[3];
  real_T rtb_Divide1[3];
  real_T rtb_Elementproduct[6];
  int32_T i;
  real_T rtb_Integrator1_0;
  real_T rtb_Product_g[9];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T rtb_Product_b[6];
  int32_T i_0;
  if (rtmIsMajorTimeStep(starshotsimv4p3lqrproto_M)) {
    /* set solver stop time */
    if (!(starshotsimv4p3lqrproto_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&starshotsimv4p3lqrproto_M->solverInfo,
                            ((starshotsimv4p3lqrproto_M->Timing.clockTickH0 + 1)
        * starshotsimv4p3lqrproto_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&starshotsimv4p3lqrproto_M->solverInfo,
                            ((starshotsimv4p3lqrproto_M->Timing.clockTick0 + 1) *
        starshotsimv4p3lqrproto_M->Timing.stepSize0 +
        starshotsimv4p3lqrproto_M->Timing.clockTickH0 *
        starshotsimv4p3lqrproto_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(starshotsimv4p3lqrproto_M)) {
    starshotsimv4p3lqrproto_M->Timing.t[0] = rtsiGetT
      (&starshotsimv4p3lqrproto_M->solverInfo);
  }

  /* DotProduct: '<S13>/Dot Product' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  rtb_Integrator1_0 = ((starshotsimv4p3lqrproto_X.Integrator1_CSTATE[0] *
                        starshotsimv4p3lqrproto_X.Integrator1_CSTATE[0] +
                        starshotsimv4p3lqrproto_X.Integrator1_CSTATE[1] *
                        starshotsimv4p3lqrproto_X.Integrator1_CSTATE[1]) +
                       starshotsimv4p3lqrproto_X.Integrator1_CSTATE[2] *
                       starshotsimv4p3lqrproto_X.Integrator1_CSTATE[2]) +
    starshotsimv4p3lqrproto_X.Integrator1_CSTATE[3] *
    starshotsimv4p3lqrproto_X.Integrator1_CSTATE[3];

  /* Math: '<S13>/Math Function' incorporates:
   *  DotProduct: '<S13>/Dot Product'
   *
   * About '<S13>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Integrator1_0 < 0.0) {
    rtb_Integrator1_0 = -sqrt(fabs(rtb_Integrator1_0));
  } else {
    rtb_Integrator1_0 = sqrt(rtb_Integrator1_0);
  }

  /* End of Math: '<S13>/Math Function' */

  /* Product: '<S13>/Product' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  rtb_Product_l[0] = starshotsimv4p3lqrproto_X.Integrator1_CSTATE[0] /
    rtb_Integrator1_0;
  rtb_Product_l[1] = starshotsimv4p3lqrproto_X.Integrator1_CSTATE[1] /
    rtb_Integrator1_0;
  rtb_Product_l[2] = starshotsimv4p3lqrproto_X.Integrator1_CSTATE[2] /
    rtb_Integrator1_0;
  rtb_Product_l[3] = starshotsimv4p3lqrproto_X.Integrator1_CSTATE[3] /
    rtb_Integrator1_0;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Math: '<S10>/T2'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/qTq'
   */
  rtb_Integrator1_0 = rtb_Product_l[3] * rtb_Product_l[3] - ((rtb_Product_l[0] *
    rtb_Product_l[0] + rtb_Product_l[1] * rtb_Product_l[1]) + rtb_Product_l[2] *
    rtb_Product_l[2]);

  /* Sum: '<S7>/Sum5' incorporates:
   *  Constant: '<S7>/Constant8'
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator1'
   *  Integrator: '<S9>/Integrator2'
   *  Math: '<S7>/Math Function3'
   *  Math: '<S7>/Math Function4'
   *  Sqrt: '<S7>/Sqrt2'
   *  Sum: '<S7>/Sum3'
   *  Trigonometry: '<S7>/Trigonometric Function3'
   */
  rtb_Saturation3 = starshotsimv4p3lqrproto_P.Constant8_Value - rt_atan2d_snf
    (starshotsimv4p3lqrproto_X.Integrator2_CSTATE, sqrt
     (starshotsimv4p3lqrproto_X.Integrator_CSTATE *
      starshotsimv4p3lqrproto_X.Integrator_CSTATE +
      starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c *
      starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c));

  /* Gain: '<S7>/Gain6' */
  rtb_Saturation5 = starshotsimv4p3lqrproto_P.Gain6_Gain * rtb_Saturation3;

  /* Product: '<S7>/Divide2' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator1'
   *  Integrator: '<S9>/Integrator2'
   *  Math: '<S7>/Math Function5'
   *  Math: '<S7>/Math Function6'
   *  Math: '<S7>/Math Function7'
   *  Sqrt: '<S7>/Sqrt3'
   *  Sum: '<S7>/Sum4'
   */
  rtb_Saturation4 = starshotsimv4p3lqrproto_P.R_Earth / sqrt
    ((starshotsimv4p3lqrproto_X.Integrator_CSTATE *
      starshotsimv4p3lqrproto_X.Integrator_CSTATE +
      starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c *
      starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c) +
     starshotsimv4p3lqrproto_X.Integrator2_CSTATE *
     starshotsimv4p3lqrproto_X.Integrator2_CSTATE);

  /* Gain: '<S7>/Gain4' incorporates:
   *  Math: '<S7>/Math Function8'
   *  Product: '<S7>/Product'
   */
  rtb_Saturation4 = rtb_Saturation4 * rtb_Saturation4 * rtb_Saturation4 *
    -starshotsimv4p3lqrproto_P.B0;

  /* Product: '<S7>/Divide4' incorporates:
   *  Trigonometry: '<S7>/Trigonometric Function4'
   */
  rtb_DotProduct2 = rtb_Saturation4 * sin(rtb_Saturation3);

  /* Product: '<S7>/Divide3' incorporates:
   *  Gain: '<S7>/Gain5'
   *  Trigonometry: '<S7>/Trigonometric Function2'
   */
  rtb_Saturation4 = starshotsimv4p3lqrproto_P.Gain5_Gain * rtb_Saturation4 * cos
    (rtb_Saturation3);

  /* Sum: '<S12>/Sum6' incorporates:
   *  Product: '<S12>/Product3'
   *  Product: '<S12>/Product4'
   *  Trigonometry: '<S12>/Trigonometric Function7'
   *  Trigonometry: '<S12>/Trigonometric Function8'
   */
  rtb_Saturation3 = cos(rtb_Saturation5) * rtb_DotProduct2 + sin(rtb_Saturation5)
    * rtb_Saturation4;

  /* Trigonometry: '<S12>/Trigonometric Function' incorporates:
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator1'
   */
  rtb_Divide = rt_atan2d_snf(starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c,
    starshotsimv4p3lqrproto_X.Integrator_CSTATE);

  /* Product: '<S12>/Divide1' incorporates:
   *  Trigonometry: '<S12>/Trigonometric Function1'
   */
  rtb_Sqrt = rtb_Saturation3 * cos(rtb_Divide);

  /* Product: '<S12>/Divide' incorporates:
   *  Trigonometry: '<S12>/Trigonometric Function2'
   */
  rtb_Saturation3 *= sin(rtb_Divide);

  /* Product: '<S10>/qqT' incorporates:
   *  Gain: '<S10>/Gain2'
   *  Math: '<S10>/T1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_g[i] = rtb_Product_l[i] * rtb_Product_l[0];
    rtb_Product_g[i + 3] = rtb_Product_l[i] * rtb_Product_l[1];
    rtb_Product_g[i + 6] = rtb_Product_l[i] * rtb_Product_l[2];
  }

  /* End of Product: '<S10>/qqT' */

  /* Reshape: '<S15>/3x3' incorporates:
   *  Constant: '<S15>/diag 0 '
   *  Gain: '<S15>/Gain'
   *  Gain: '<S15>/Gain1'
   *  Gain: '<S15>/Gain2'
   *  Product: '<S10>/Product'
   */
  tmp[0] = starshotsimv4p3lqrproto_P.diag0_Value;
  tmp[1] = rtb_Product_l[2];
  tmp[2] = starshotsimv4p3lqrproto_P.Gain_Gain * rtb_Product_l[1];
  tmp[3] = starshotsimv4p3lqrproto_P.Gain1_Gain * rtb_Product_l[2];
  tmp[4] = starshotsimv4p3lqrproto_P.diag0_Value;
  tmp[5] = rtb_Product_l[0];
  tmp[6] = rtb_Product_l[1];
  tmp[7] = starshotsimv4p3lqrproto_P.Gain2_Gain_d * rtb_Product_l[0];
  tmp[8] = starshotsimv4p3lqrproto_P.diag0_Value;

  /* Product: '<S10>/Product' */
  rtb_Divide = rtb_Product_l[3];

  /* Sum: '<S10>/Sum8' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Matrix Gain'
   *  Product: '<S10>/Product'
   *  Product: '<S2>/Matrix Multiply'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[3 * i] = (rtb_Product_g[3 * i] * starshotsimv4p3lqrproto_P.Gain2_Gain
                    - tmp[3 * i] * rtb_Divide *
                    starshotsimv4p3lqrproto_P.Gain1_Gain_f) +
      starshotsimv4p3lqrproto_P.MatrixGain_Gain[3 * i] * rtb_Integrator1_0;
    tmp_0[1 + 3 * i] = (rtb_Product_g[3 * i + 1] *
                        starshotsimv4p3lqrproto_P.Gain2_Gain - tmp[3 * i + 1] *
                        rtb_Divide * starshotsimv4p3lqrproto_P.Gain1_Gain_f) +
      starshotsimv4p3lqrproto_P.MatrixGain_Gain[3 * i + 1] * rtb_Integrator1_0;
    tmp_0[2 + 3 * i] = (rtb_Product_g[3 * i + 2] *
                        starshotsimv4p3lqrproto_P.Gain2_Gain - tmp[3 * i + 2] *
                        rtb_Divide * starshotsimv4p3lqrproto_P.Gain1_Gain_f) +
      starshotsimv4p3lqrproto_P.MatrixGain_Gain[3 * i + 2] * rtb_Integrator1_0;
  }

  /* End of Sum: '<S10>/Sum8' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Product: '<S12>/Product1'
   *  Product: '<S12>/Product2'
   *  Sum: '<S12>/Sum5'
   *  Trigonometry: '<S12>/Trigonometric Function5'
   *  Trigonometry: '<S12>/Trigonometric Function6'
   */
  rtb_Integrator1_0 = cos(rtb_Saturation5) * rtb_Saturation4 - sin
    (rtb_Saturation5) * rtb_DotProduct2;

  /* Product: '<S2>/Matrix Multiply' incorporates:
   *  SignalConversion: '<S2>/TmpSignal ConversionAtMatrix MultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Divide1[i] = tmp_0[i + 6] * rtb_Integrator1_0 + (tmp_0[i + 3] *
      rtb_Saturation3 + tmp_0[i] * rtb_Sqrt);
  }

  /* Sum: '<S3>/Add3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<S3>/Element product'
   */
  rtb_Saturation3 = starshotsimv4p3lqrproto_P.Constant_Value[1] * rtb_Divide1[2]
    - starshotsimv4p3lqrproto_P.Constant_Value[2] * rtb_Divide1[1];

  /* DotProduct: '<S5>/Dot Product6' */
  rtb_Sqrt = rtb_Saturation3 * rtb_Saturation3;

  /* Sum: '<S3>/Add3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<S3>/Element product'
   */
  rtb_Product_l2[0] = rtb_Saturation3;
  rtb_Saturation3 = starshotsimv4p3lqrproto_P.Constant_Value[2] * rtb_Divide1[0]
    - starshotsimv4p3lqrproto_P.Constant_Value[0] * rtb_Divide1[2];

  /* DotProduct: '<S5>/Dot Product6' */
  rtb_Sqrt += rtb_Saturation3 * rtb_Saturation3;

  /* Sum: '<S3>/Add3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<S3>/Element product'
   */
  rtb_Product_l2[1] = rtb_Saturation3;
  rtb_Saturation3 = starshotsimv4p3lqrproto_P.Constant_Value[0] * rtb_Divide1[1]
    - starshotsimv4p3lqrproto_P.Constant_Value[1] * rtb_Divide1[0];

  /* DotProduct: '<S5>/Dot Product6' */
  rtb_Sqrt += rtb_Saturation3 * rtb_Saturation3;

  /* Sum: '<S3>/Add3' */
  rtb_Product_l2[2] = rtb_Saturation3;

  /* Gain: '<S1>/Gain8' incorporates:
   *  DotProduct: '<S5>/Dot Product6'
   *  Sqrt: '<S5>/Sqrt4'
   */
  starshotsimv4p3lqrproto_B.Gain8 = starshotsimv4p3lqrproto_P.Gain8_Gain * sqrt
    (rtb_Sqrt);
  if (rtmIsMajorTimeStep(starshotsimv4p3lqrproto_M)) {
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator9'
   */
  rtb_Product_b[0] = rtb_Product_l2[0];
  rtb_Product_b[1] = rtb_Product_l2[1];
  rtb_Product_b[2] = rtb_Saturation3;
  rtb_Product_b[3] = starshotsimv4p3lqrproto_X.Integrator9_CSTATE;
  rtb_Product_b[4] = starshotsimv4p3lqrproto_X.Integrator10_CSTATE;
  rtb_Product_b[5] = starshotsimv4p3lqrproto_X.Integrator11_CSTATE;

  /* Gain: '<S1>/Gain' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_l2[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product_l2[i] += starshotsimv4p3lqrproto_P.Klqr[3 * i_0 + i] *
        rtb_Product_b[i_0];
    }
  }

  /* End of Gain: '<S1>/Gain' */

  /* Saturate: '<S1>/Saturation4' */
  if (rtb_Product_l2[1] > starshotsimv4p3lqrproto_P.Saturation4_UpperSat) {
    rtb_Saturation4 = starshotsimv4p3lqrproto_P.Saturation4_UpperSat;
  } else if (rtb_Product_l2[1] < starshotsimv4p3lqrproto_P.Saturation4_LowerSat)
  {
    rtb_Saturation4 = starshotsimv4p3lqrproto_P.Saturation4_LowerSat;
  } else {
    rtb_Saturation4 = rtb_Product_l2[1];
  }

  /* End of Saturate: '<S1>/Saturation4' */

  /* Saturate: '<S1>/Saturation5' */
  if (rtb_Product_l2[2] > starshotsimv4p3lqrproto_P.Saturation5_UpperSat) {
    rtb_Saturation5 = starshotsimv4p3lqrproto_P.Saturation5_UpperSat;
  } else if (rtb_Product_l2[2] < starshotsimv4p3lqrproto_P.Saturation5_LowerSat)
  {
    rtb_Saturation5 = starshotsimv4p3lqrproto_P.Saturation5_LowerSat;
  } else {
    rtb_Saturation5 = rtb_Product_l2[2];
  }

  /* End of Saturate: '<S1>/Saturation5' */

  /* Saturate: '<S1>/Saturation3' */
  if (rtb_Product_l2[0] > starshotsimv4p3lqrproto_P.Saturation3_UpperSat) {
    rtb_Saturation3 = starshotsimv4p3lqrproto_P.Saturation3_UpperSat;
  } else if (rtb_Product_l2[0] < starshotsimv4p3lqrproto_P.Saturation3_LowerSat)
  {
    rtb_Saturation3 = starshotsimv4p3lqrproto_P.Saturation3_LowerSat;
  } else {
    rtb_Saturation3 = rtb_Product_l2[0];
  }

  /* End of Saturate: '<S1>/Saturation3' */

  /* Product: '<S4>/Element product' */
  rtb_Elementproduct[0] = rtb_Saturation4 * rtb_Divide1[2];
  rtb_Elementproduct[1] = rtb_Saturation5 * rtb_Divide1[0];
  rtb_Elementproduct[2] = rtb_Saturation3 * rtb_Divide1[1];
  rtb_Elementproduct[3] = rtb_Saturation5 * rtb_Divide1[1];
  rtb_Elementproduct[4] = rtb_Saturation3 * rtb_Divide1[2];
  rtb_Elementproduct[5] = rtb_Saturation4 * rtb_Divide1[0];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S4>/Add3' */
    rtb_Divide1[i] = rtb_Elementproduct[i] - rtb_Elementproduct[i + 3];

    /* Product: '<S6>/Product' incorporates:
     *  Constant: '<S6>/Constant'
     *  Integrator: '<S2>/Integrator10'
     *  Integrator: '<S2>/Integrator11'
     *  Integrator: '<S2>/Integrator9'
     */
    rtb_Product_l2[i] = starshotsimv4p3lqrproto_P.starshot.IC.massproperties.I[i
      + 6] * starshotsimv4p3lqrproto_X.Integrator11_CSTATE +
      (starshotsimv4p3lqrproto_P.starshot.IC.massproperties.I[i + 3] *
       starshotsimv4p3lqrproto_X.Integrator10_CSTATE +
       starshotsimv4p3lqrproto_P.starshot.IC.massproperties.I[i] *
       starshotsimv4p3lqrproto_X.Integrator9_CSTATE);
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator9'
   *  Product: '<S11>/Element product'
   *  Product: '<S6>/Product1'
   *  Sum: '<S11>/Add3'
   */
  rtb_Saturation3 = rtb_Divide1[0] -
    (starshotsimv4p3lqrproto_X.Integrator10_CSTATE * rtb_Product_l2[2] -
     starshotsimv4p3lqrproto_X.Integrator11_CSTATE * rtb_Product_l2[1]);
  rtb_Sqrt = rtb_Divide1[1] - (starshotsimv4p3lqrproto_X.Integrator11_CSTATE *
    rtb_Product_l2[0] - starshotsimv4p3lqrproto_X.Integrator9_CSTATE *
    rtb_Product_l2[2]);
  rtb_Integrator1_0 = rtb_Divide1[2] -
    (starshotsimv4p3lqrproto_X.Integrator9_CSTATE * rtb_Product_l2[1] -
     starshotsimv4p3lqrproto_X.Integrator10_CSTATE * rtb_Product_l2[0]);

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  for (i = 0; i < 3; i++) {
    starshotsimv4p3lqrproto_B.Product1[i] = 0.0;
    starshotsimv4p3lqrproto_B.Product1[i] +=
      starshotsimv4p3lqrproto_P.starshot.IC.massproperties.Iinv[i] *
      rtb_Saturation3;
    starshotsimv4p3lqrproto_B.Product1[i] +=
      starshotsimv4p3lqrproto_P.starshot.IC.massproperties.Iinv[i + 3] *
      rtb_Sqrt;
    starshotsimv4p3lqrproto_B.Product1[i] +=
      starshotsimv4p3lqrproto_P.starshot.IC.massproperties.Iinv[i + 6] *
      rtb_Integrator1_0;
  }

  /* Fcn: '<S14>/qd1' incorporates:
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator9'
   */
  starshotsimv4p3lqrproto_B.qd1 = ((rtb_Product_l[3] *
    starshotsimv4p3lqrproto_X.Integrator9_CSTATE - rtb_Product_l[2] *
    starshotsimv4p3lqrproto_X.Integrator10_CSTATE) + rtb_Product_l[1] *
    starshotsimv4p3lqrproto_X.Integrator11_CSTATE) / 2.0;

  /* Fcn: '<S14>/qd2' incorporates:
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator9'
   */
  starshotsimv4p3lqrproto_B.qd2 = ((rtb_Product_l[2] *
    starshotsimv4p3lqrproto_X.Integrator9_CSTATE + rtb_Product_l[3] *
    starshotsimv4p3lqrproto_X.Integrator10_CSTATE) - rtb_Product_l[0] *
    starshotsimv4p3lqrproto_X.Integrator11_CSTATE) / 2.0;

  /* Fcn: '<S14>/qd3' incorporates:
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator9'
   */
  starshotsimv4p3lqrproto_B.qd3 = ((-rtb_Product_l[1] *
    starshotsimv4p3lqrproto_X.Integrator9_CSTATE + rtb_Product_l[0] *
    starshotsimv4p3lqrproto_X.Integrator10_CSTATE) + rtb_Product_l[3] *
    starshotsimv4p3lqrproto_X.Integrator11_CSTATE) / 2.0;

  /* Fcn: '<S14>/qd4' incorporates:
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator9'
   */
  starshotsimv4p3lqrproto_B.qd4 = ((-rtb_Product_l[0] *
    starshotsimv4p3lqrproto_X.Integrator9_CSTATE - rtb_Product_l[1] *
    starshotsimv4p3lqrproto_X.Integrator10_CSTATE) - rtb_Product_l[2] *
    starshotsimv4p3lqrproto_X.Integrator11_CSTATE) / 2.0;

  /* Sqrt: '<S9>/Sqrt' incorporates:
   *  DotProduct: '<S9>/Dot Product'
   *  DotProduct: '<S9>/Dot Product1'
   *  DotProduct: '<S9>/Dot Product2'
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator1'
   *  Integrator: '<S9>/Integrator2'
   *  Sum: '<S9>/Sum'
   */
  rtb_Sqrt = sqrt((starshotsimv4p3lqrproto_X.Integrator_CSTATE *
                   starshotsimv4p3lqrproto_X.Integrator_CSTATE +
                   starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c *
                   starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c) +
                  starshotsimv4p3lqrproto_X.Integrator2_CSTATE *
                  starshotsimv4p3lqrproto_X.Integrator2_CSTATE);
  if (rtmIsMajorTimeStep(starshotsimv4p3lqrproto_M)) {
    /* Gain: '<S9>/Gain2' incorporates:
     *  Constant: '<S9>/Constant'
     *  Gain: '<S9>/Gain1'
     */
    starshotsimv4p3lqrproto_B.Gain2 = starshotsimv4p3lqrproto_P.M_Earth *
      -starshotsimv4p3lqrproto_P.G *
      starshotsimv4p3lqrproto_P.starshot.IC.massproperties.m;
  }

  /* Product: '<S9>/Divide' incorporates:
   *  Math: '<S9>/Math Function'
   */
  rtb_Divide = 1.0 / (rtb_Sqrt * rtb_Sqrt) * starshotsimv4p3lqrproto_B.Gain2;

  /* DotProduct: '<S9>/Dot Product3' incorporates:
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Divide1'
   */
  starshotsimv4p3lqrproto_B.DotProduct3 = 1.0 / rtb_Sqrt *
    starshotsimv4p3lqrproto_X.Integrator2_CSTATE * rtb_Divide;

  /* DotProduct: '<S9>/Dot Product4' incorporates:
   *  Integrator: '<S9>/Integrator1'
   *  Product: '<S9>/Divide1'
   */
  starshotsimv4p3lqrproto_B.DotProduct4 = 1.0 / rtb_Sqrt *
    starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c * rtb_Divide;

  /* DotProduct: '<S9>/Dot Product5' incorporates:
   *  Integrator: '<S9>/Integrator'
   *  Product: '<S9>/Divide1'
   */
  starshotsimv4p3lqrproto_B.DotProduct5 = 1.0 / rtb_Sqrt *
    starshotsimv4p3lqrproto_X.Integrator_CSTATE * rtb_Divide;

  /* Integrator: '<S9>/Integrator3' */
  starshotsimv4p3lqrproto_B.Integrator3 =
    starshotsimv4p3lqrproto_X.Integrator3_CSTATE;

  /* Integrator: '<S9>/Integrator4' */
  starshotsimv4p3lqrproto_B.Integrator4 =
    starshotsimv4p3lqrproto_X.Integrator4_CSTATE;

  /* Integrator: '<S9>/Integrator5' */
  starshotsimv4p3lqrproto_B.Integrator5 =
    starshotsimv4p3lqrproto_X.Integrator5_CSTATE;
  if (rtmIsMajorTimeStep(starshotsimv4p3lqrproto_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(starshotsimv4p3lqrproto_M->rtwLogInfo,
                        (starshotsimv4p3lqrproto_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(starshotsimv4p3lqrproto_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(starshotsimv4p3lqrproto_M)!=-1) &&
          !((rtmGetTFinal(starshotsimv4p3lqrproto_M)-
             (((starshotsimv4p3lqrproto_M->Timing.clockTick1+
                starshotsimv4p3lqrproto_M->Timing.clockTickH1* 4294967296.0)) *
              200.0)) > (((starshotsimv4p3lqrproto_M->Timing.clockTick1+
                           starshotsimv4p3lqrproto_M->Timing.clockTickH1*
                           4294967296.0)) * 200.0) * (DBL_EPSILON))) {
        rtmSetErrorStatus(starshotsimv4p3lqrproto_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&starshotsimv4p3lqrproto_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++starshotsimv4p3lqrproto_M->Timing.clockTick0)) {
      ++starshotsimv4p3lqrproto_M->Timing.clockTickH0;
    }

    starshotsimv4p3lqrproto_M->Timing.t[0] = rtsiGetSolverStopTime
      (&starshotsimv4p3lqrproto_M->solverInfo);

    {
      /* Update absolute timer for sample time: [200.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 200.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      starshotsimv4p3lqrproto_M->Timing.clockTick1++;
      if (!starshotsimv4p3lqrproto_M->Timing.clockTick1) {
        starshotsimv4p3lqrproto_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void starshotsimv4p3lqrproto_derivatives(void)
{
  XDot_starshotsimv4p3lqrproto_T *_rtXdot;
  _rtXdot = ((XDot_starshotsimv4p3lqrproto_T *)
             starshotsimv4p3lqrproto_M->derivs);

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = starshotsimv4p3lqrproto_B.qd1;
  _rtXdot->Integrator1_CSTATE[1] = starshotsimv4p3lqrproto_B.qd2;
  _rtXdot->Integrator1_CSTATE[2] = starshotsimv4p3lqrproto_B.qd3;
  _rtXdot->Integrator1_CSTATE[3] = starshotsimv4p3lqrproto_B.qd4;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = starshotsimv4p3lqrproto_B.Integrator5;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE = starshotsimv4p3lqrproto_B.Integrator3;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_c = starshotsimv4p3lqrproto_B.Integrator4;

  /* Derivatives for Integrator: '<S2>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = starshotsimv4p3lqrproto_B.Product1[0];

  /* Derivatives for Integrator: '<S2>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = starshotsimv4p3lqrproto_B.Product1[1];

  /* Derivatives for Integrator: '<S2>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = starshotsimv4p3lqrproto_B.Product1[2];

  /* Derivatives for Integrator: '<S9>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = starshotsimv4p3lqrproto_B.DotProduct5;

  /* Derivatives for Integrator: '<S9>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = starshotsimv4p3lqrproto_B.DotProduct4;

  /* Derivatives for Integrator: '<S9>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = starshotsimv4p3lqrproto_B.DotProduct3;
}

/* Model initialize function */
void starshotsimv4p3lqrproto_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)starshotsimv4p3lqrproto_M, 0,
                sizeof(RT_MODEL_starshotsimv4p3lqrpr_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&starshotsimv4p3lqrproto_M->solverInfo,
                          &starshotsimv4p3lqrproto_M->Timing.simTimeStep);
    rtsiSetTPtr(&starshotsimv4p3lqrproto_M->solverInfo, &rtmGetTPtr
                (starshotsimv4p3lqrproto_M));
    rtsiSetStepSizePtr(&starshotsimv4p3lqrproto_M->solverInfo,
                       &starshotsimv4p3lqrproto_M->Timing.stepSize0);
    rtsiSetdXPtr(&starshotsimv4p3lqrproto_M->solverInfo,
                 &starshotsimv4p3lqrproto_M->derivs);
    rtsiSetContStatesPtr(&starshotsimv4p3lqrproto_M->solverInfo, (real_T **)
                         &starshotsimv4p3lqrproto_M->contStates);
    rtsiSetNumContStatesPtr(&starshotsimv4p3lqrproto_M->solverInfo,
      &starshotsimv4p3lqrproto_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&starshotsimv4p3lqrproto_M->solverInfo,
      &starshotsimv4p3lqrproto_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&starshotsimv4p3lqrproto_M->solverInfo,
      &starshotsimv4p3lqrproto_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&starshotsimv4p3lqrproto_M->solverInfo,
      &starshotsimv4p3lqrproto_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&starshotsimv4p3lqrproto_M->solverInfo,
                          (&rtmGetErrorStatus(starshotsimv4p3lqrproto_M)));
    rtsiSetRTModelPtr(&starshotsimv4p3lqrproto_M->solverInfo,
                      starshotsimv4p3lqrproto_M);
  }

  rtsiSetSimTimeStep(&starshotsimv4p3lqrproto_M->solverInfo, MAJOR_TIME_STEP);
  starshotsimv4p3lqrproto_M->intgData.y = starshotsimv4p3lqrproto_M->odeY;
  starshotsimv4p3lqrproto_M->intgData.f[0] = starshotsimv4p3lqrproto_M->odeF[0];
  starshotsimv4p3lqrproto_M->intgData.f[1] = starshotsimv4p3lqrproto_M->odeF[1];
  starshotsimv4p3lqrproto_M->intgData.f[2] = starshotsimv4p3lqrproto_M->odeF[2];
  starshotsimv4p3lqrproto_M->contStates = ((X_starshotsimv4p3lqrproto_T *)
    &starshotsimv4p3lqrproto_X);
  rtsiSetSolverData(&starshotsimv4p3lqrproto_M->solverInfo, (void *)
                    &starshotsimv4p3lqrproto_M->intgData);
  rtsiSetSolverName(&starshotsimv4p3lqrproto_M->solverInfo,"ode3");
  rtmSetTPtr(starshotsimv4p3lqrproto_M,
             &starshotsimv4p3lqrproto_M->Timing.tArray[0]);
  rtmSetTFinal(starshotsimv4p3lqrproto_M, 10000.0);
  starshotsimv4p3lqrproto_M->Timing.stepSize0 = 200.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    starshotsimv4p3lqrproto_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(starshotsimv4p3lqrproto_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(starshotsimv4p3lqrproto_M->rtwLogInfo, (NULL));
    rtliSetLogT(starshotsimv4p3lqrproto_M->rtwLogInfo, "tout");
    rtliSetLogX(starshotsimv4p3lqrproto_M->rtwLogInfo, "");
    rtliSetLogXFinal(starshotsimv4p3lqrproto_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(starshotsimv4p3lqrproto_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(starshotsimv4p3lqrproto_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(starshotsimv4p3lqrproto_M->rtwLogInfo, 0);
    rtliSetLogDecimation(starshotsimv4p3lqrproto_M->rtwLogInfo, 1);
    rtliSetLogY(starshotsimv4p3lqrproto_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(starshotsimv4p3lqrproto_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(starshotsimv4p3lqrproto_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &starshotsimv4p3lqrproto_B), 0,
                sizeof(B_starshotsimv4p3lqrproto_T));

  /* states (continuous) */
  {
    (void) memset((void *)&starshotsimv4p3lqrproto_X, 0,
                  sizeof(X_starshotsimv4p3lqrproto_T));
  }

  /* states (dwork) */
  (void) memset((void *)&starshotsimv4p3lqrproto_DW, 0,
                sizeof(DW_starshotsimv4p3lqrproto_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(starshotsimv4p3lqrproto_M->rtwLogInfo, 0.0,
    rtmGetTFinal(starshotsimv4p3lqrproto_M),
    starshotsimv4p3lqrproto_M->Timing.stepSize0, (&rtmGetErrorStatus
    (starshotsimv4p3lqrproto_M)));

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  starshotsimv4p3lqrproto_X.Integrator1_CSTATE[0] =
    starshotsimv4p3lqrproto_P.q0[0];
  starshotsimv4p3lqrproto_X.Integrator1_CSTATE[1] =
    starshotsimv4p3lqrproto_P.q0[1];
  starshotsimv4p3lqrproto_X.Integrator1_CSTATE[2] =
    starshotsimv4p3lqrproto_P.q0[2];
  starshotsimv4p3lqrproto_X.Integrator1_CSTATE[3] =
    starshotsimv4p3lqrproto_P.q0[3];

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  starshotsimv4p3lqrproto_X.Integrator2_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.z;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  starshotsimv4p3lqrproto_X.Integrator_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.x;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  starshotsimv4p3lqrproto_X.Integrator1_CSTATE_c =
    starshotsimv4p3lqrproto_P.starshot.IC.y;

  /* InitializeConditions for Integrator: '<S2>/Integrator9' */
  starshotsimv4p3lqrproto_X.Integrator9_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.p;

  /* InitializeConditions for Integrator: '<S2>/Integrator10' */
  starshotsimv4p3lqrproto_X.Integrator10_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.q;

  /* InitializeConditions for Integrator: '<S2>/Integrator11' */
  starshotsimv4p3lqrproto_X.Integrator11_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.r;

  /* InitializeConditions for Integrator: '<S9>/Integrator3' */
  starshotsimv4p3lqrproto_X.Integrator3_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.xdot;

  /* InitializeConditions for Integrator: '<S9>/Integrator4' */
  starshotsimv4p3lqrproto_X.Integrator4_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.ydot;

  /* InitializeConditions for Integrator: '<S9>/Integrator5' */
  starshotsimv4p3lqrproto_X.Integrator5_CSTATE =
    starshotsimv4p3lqrproto_P.starshot.IC.zdot;
}

/* Model terminate function */
void starshotsimv4p3lqrproto_terminate(void)
{
  /* (no terminate code required) */
}
