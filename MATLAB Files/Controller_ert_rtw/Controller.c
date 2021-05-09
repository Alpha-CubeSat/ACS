/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Mar 01 12:57:57 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Controller.h"

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Controller_step(void)
{
  real_T rtb_Gain[3];
  real_T rtb_Saturation4;
  real_T rtb_Saturation5;
  real_T rtb_Saturation3;
  real_T rtb_Elementproduct_0[6];
  int32_T i;
  int32_T i_0;

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Inport: '<Root>/Angular Velocity'
   *  Inport: '<Root>/Magnetic Field'
   *  Product: '<S2>/Element product'
   *  Sum: '<S2>/Add3'
   */
  rtb_Elementproduct_0[0] = 0.0 * rtU.MagneticField[2] - rtU.MagneticField[1];
  rtb_Elementproduct_0[3] = rtU.w[0];
  rtb_Elementproduct_0[1] = rtU.MagneticField[0] - 0.0 * rtU.MagneticField[2];
  rtb_Elementproduct_0[4] = rtU.w[1];
  rtb_Elementproduct_0[2] = 0.0 * rtU.MagneticField[1] - 0.0 *
    rtU.MagneticField[0];
  rtb_Elementproduct_0[5] = rtU.w[2];

  /* Gain: '<S1>/Gain' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Gain[i] += rtConstP.Gain_Gain[3 * i_0 + i] * rtb_Elementproduct_0[i_0];
    }
  }

  /* End of Gain: '<S1>/Gain' */

  /* Saturate: '<S1>/Saturation4' */
  if (rtb_Gain[1] > 1.3) {
    rtb_Saturation4 = 1.3;
  } else if (rtb_Gain[1] < -1.3) {
    rtb_Saturation4 = -1.3;
  } else {
    rtb_Saturation4 = rtb_Gain[1];
  }

  /* End of Saturate: '<S1>/Saturation4' */

  /* Saturate: '<S1>/Saturation5' */
  if (rtb_Gain[2] > 1.3) {
    rtb_Saturation5 = 1.3;
  } else if (rtb_Gain[2] < -1.3) {
    rtb_Saturation5 = -1.3;
  } else {
    rtb_Saturation5 = rtb_Gain[2];
  }

  /* End of Saturate: '<S1>/Saturation5' */

  /* Saturate: '<S1>/Saturation3' */
  if (rtb_Gain[0] > 1.3) {
    rtb_Saturation3 = 1.3;
  } else if (rtb_Gain[0] < -1.3) {
    rtb_Saturation3 = -1.3;
  } else {
    rtb_Saturation3 = rtb_Gain[0];
  }

  /* End of Saturate: '<S1>/Saturation3' */

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/Magnetic Field'
   *  Product: '<S3>/Element product'
   *  Sum: '<S3>/Add3'
   */
  rtY.Out1[0] = rtb_Saturation4 * rtU.MagneticField[2] - rtb_Saturation5 *
    rtU.MagneticField[1];
  rtY.Out1[1] = rtb_Saturation5 * rtU.MagneticField[0] - rtb_Saturation3 *
    rtU.MagneticField[2];
  rtY.Out1[2] = rtb_Saturation3 * rtU.MagneticField[1] - rtb_Saturation4 *
    rtU.MagneticField[0];
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
