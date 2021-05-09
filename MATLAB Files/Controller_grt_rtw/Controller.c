/*
 * Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controller".
 *
 * Model version              : 1.62
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sat Feb 24 19:39:27 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

/* Block states (auto storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Model step function */
void Controller_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain8;
  real_T rtb_Gain[3];
  real_T rtb_Saturation4;
  real_T rtb_Saturation5;
  real_T rtb_Add3_c_0[6];
  int32_T i;
  int32_T i_0;
  real_T rtb_Add3_p;
  real_T rtb_Add3_c_idx_0;
  real_T rtb_Add3_c_idx_1;

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Magnetic Field'
   *  Product: '<S2>/Element product'
   */
  rtb_Add3_p = Controller_P.Constant_Value[1] * Controller_U.MagneticField[2] -
    Controller_P.Constant_Value[2] * Controller_U.MagneticField[1];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Inport: '<Root>/Angular Velocity'
   */
  rtb_Add3_c_0[0] = rtb_Add3_p;
  rtb_Add3_c_0[3] = Controller_U.w[0];

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Magnetic Field'
   *  Product: '<S2>/Element product'
   */
  rtb_Add3_c_idx_0 = rtb_Add3_p;
  rtb_Add3_p = Controller_P.Constant_Value[2] * Controller_U.MagneticField[0] -
    Controller_P.Constant_Value[0] * Controller_U.MagneticField[2];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Inport: '<Root>/Angular Velocity'
   */
  rtb_Add3_c_0[1] = rtb_Add3_p;
  rtb_Add3_c_0[4] = Controller_U.w[1];

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Magnetic Field'
   *  Product: '<S2>/Element product'
   */
  rtb_Add3_c_idx_1 = rtb_Add3_p;
  rtb_Add3_p = Controller_P.Constant_Value[0] * Controller_U.MagneticField[1] -
    Controller_P.Constant_Value[1] * Controller_U.MagneticField[0];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Inport: '<Root>/Angular Velocity'
   */
  rtb_Add3_c_0[2] = rtb_Add3_p;
  rtb_Add3_c_0[5] = Controller_U.w[2];

  /* Gain: '<S1>/Gain' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Gain[i] += Controller_P.Klqr[3 * i_0 + i] * rtb_Add3_c_0[i_0];
    }
  }

  /* End of Gain: '<S1>/Gain' */

  /* Saturate: '<S1>/Saturation4' */
  if (rtb_Gain[1] > Controller_P.Saturation4_UpperSat) {
    rtb_Saturation4 = Controller_P.Saturation4_UpperSat;
  } else if (rtb_Gain[1] < Controller_P.Saturation4_LowerSat) {
    rtb_Saturation4 = Controller_P.Saturation4_LowerSat;
  } else {
    rtb_Saturation4 = rtb_Gain[1];
  }

  /* End of Saturate: '<S1>/Saturation4' */

  /* Saturate: '<S1>/Saturation5' */
  if (rtb_Gain[2] > Controller_P.Saturation5_UpperSat) {
    rtb_Saturation5 = Controller_P.Saturation5_UpperSat;
  } else if (rtb_Gain[2] < Controller_P.Saturation5_LowerSat) {
    rtb_Saturation5 = Controller_P.Saturation5_LowerSat;
  } else {
    rtb_Saturation5 = rtb_Gain[2];
  }

  /* End of Saturate: '<S1>/Saturation5' */

  /* Saturate: '<S1>/Saturation3' */
  if (rtb_Gain[0] > Controller_P.Saturation3_UpperSat) {
    rtb_Gain8 = Controller_P.Saturation3_UpperSat;
  } else if (rtb_Gain[0] < Controller_P.Saturation3_LowerSat) {
    rtb_Gain8 = Controller_P.Saturation3_LowerSat;
  } else {
    rtb_Gain8 = rtb_Gain[0];
  }

  /* End of Saturate: '<S1>/Saturation3' */

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/Magnetic Field'
   *  Product: '<S3>/Element product'
   *  Sum: '<S3>/Add3'
   */
  Controller_Y.Out1[0] = rtb_Saturation4 * Controller_U.MagneticField[2] -
    rtb_Saturation5 * Controller_U.MagneticField[1];
  Controller_Y.Out1[1] = rtb_Saturation5 * Controller_U.MagneticField[0] -
    rtb_Gain8 * Controller_U.MagneticField[2];
  Controller_Y.Out1[2] = rtb_Gain8 * Controller_U.MagneticField[1] -
    rtb_Saturation4 * Controller_U.MagneticField[0];

  /* DotProduct: '<S4>/Dot Product6' */
  rtb_Gain8 = (rtb_Add3_c_idx_0 * rtb_Add3_c_idx_0 + rtb_Add3_c_idx_1 *
               rtb_Add3_c_idx_1) + rtb_Add3_p * rtb_Add3_p;

  /* Sqrt: '<S4>/Sqrt4' */
  rtb_Gain8 = sqrt(rtb_Gain8);

  /* Gain: '<S1>/Gain8' */
  rtb_Gain8 *= Controller_P.Gain8_Gain;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Controller_M->rtwLogInfo, (&Controller_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [200.0s, 0.0s] */
    if ((rtmGetTFinal(Controller_M)!=-1) &&
        !((rtmGetTFinal(Controller_M)-Controller_M->Timing.taskTime0) >
          Controller_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controller_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controller_M->Timing.clockTick0)) {
    ++Controller_M->Timing.clockTickH0;
  }

  Controller_M->Timing.taskTime0 = Controller_M->Timing.clockTick0 *
    Controller_M->Timing.stepSize0 + Controller_M->Timing.clockTickH0 *
    Controller_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Controller_M, 0,
                sizeof(RT_MODEL_Controller_T));
  rtmSetTFinal(Controller_M, 10000.0);
  Controller_M->Timing.stepSize0 = 200.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Controller_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controller_M->rtwLogInfo, "tout");
    rtliSetLogX(Controller_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controller_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controller_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controller_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Controller_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Controller_M->rtwLogInfo, 1);
    rtliSetLogY(Controller_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Controller_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset((void *)&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  (void) memset(&Controller_Y.Out1[0], 0,
                3U*sizeof(real_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Controller_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Controller_M), Controller_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Controller_M)));
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}
