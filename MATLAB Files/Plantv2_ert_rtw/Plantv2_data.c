/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Plantv2_data.c
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

/* Constant parameters (auto storage) */
const ConstP rtConstP = {
  /* Expression: starshot.IC.massproperties.I
   * Referenced by: '<S3>/Constant'
   */
  { 0.00194043705021, -6.531882269E-5, 6.04720293E-6, -6.531882269E-5,
    0.00194997902076, -3.70369791E-6, 6.04720293E-6, -3.70369791E-6,
    0.00205652954813 },

  /* Expression: starshot.IC.massproperties.Iinv
   * Referenced by: '<S3>/Constant1'
   */
  { 515.93411078855968, 17.279521843841334, -1.4859792023350551,
    17.279521843841334, 513.40650524039756, 0.87380695645740059,
    -1.4859792023350551, 0.87380695645740059, 486.26202489728132 },

  /* Expression: eye(3,3)
   * Referenced by: '<S7>/Matrix Gain'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
