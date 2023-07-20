/*
 * Controller_data.c
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

/* Block parameters (auto storage) */
P_Controller_T Controller_P = {
  /*  Variable: Klqr
   * Referenced by: '<S1>/Gain'
   */
  { 0.99986622525247382, 0.01611183868195919, -0.0028192064664597878,
    -0.016115546703937118, 0.97010354864516823, -0.16974612590544388,
    0.0027980208302554981, -0.17009440175150109, 0.029762663764960819,
    7.6455797544655315, -13.754151965593554, 2.40666474680448,
    12.797913000719351, -7.57736530549481, 1.3258671272508911,
    -2.5547914928439779, 0.38984735976969387, -0.068214448970721153 },

  /*  Expression: [0,0,1]'
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0, 1.0 },
  1.3,                                 /* Expression: 1.3
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  -1.3,                                /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  1.3,                                 /* Expression: 1.3
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  -1.3,                                /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  1.3,                                 /* Expression: 1.3
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  -1.3,                                /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  57.295779513082323                   /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain8'
                                        */
};
