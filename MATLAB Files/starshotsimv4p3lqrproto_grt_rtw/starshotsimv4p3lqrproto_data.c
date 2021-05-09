/*
 * starshotsimv4p3lqrproto_data.c
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

/* Block parameters (auto storage) */
P_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_P = {
  {
    {
      7000000.0,
      0.0,
      0.0,
      7000.0,
      0.0,
      0.0,
      0.31415926535897931,
      0.0,
      0.0,
      0.0,
      0.0,
      -0.78539816339744828,

      {
        0.839,
        0.00194043705021,
        -6.531882269e-5,
        6.04720293e-6,
        -6.531882269e-5,
        0.00194997902076,
        -3.70369791e-6,
        6.04720293e-6,
        -3.70369791e-6,
        0.00205652954813,

        { 0.00194043705021, -6.531882269e-5, 6.04720293e-6, -6.531882269e-5,
          0.00194997902076, -3.70369791e-6, 6.04720293e-6, -3.70369791e-6,
          0.00205652954813 },

        { 515.93411078855968, 17.279521843841334, -1.4859792023350551,
          17.279521843841334, 513.40650524039756, 0.87380695645740059,
          -1.4859792023350551, 0.87380695645740059, 486.26202489728132 }
      }
    },

    {
      { 7.502e-6, 8.703e-6, 9.2290000000000009e-6 },

      { 5.7169999999999995e-8, 6.633e-8, 7.0339999999999993e-8 },
      0.0,
      0.0,
      0.31415926535897931
    }
  },                                   /* Variable: starshot
                                        * Referenced by:
                                        *   '<S2>/Integrator10'
                                        *   '<S2>/Integrator11'
                                        *   '<S2>/Integrator9'
                                        *   '<S6>/Constant'
                                        *   '<S6>/Constant1'
                                        *   '<S9>/Gain2'
                                        *   '<S9>/Integrator'
                                        *   '<S9>/Integrator1'
                                        *   '<S9>/Integrator2'
                                        *   '<S9>/Integrator3'
                                        *   '<S9>/Integrator4'
                                        *   '<S9>/Integrator5'
                                        */
  3.12E-5,                             /* Variable: B0
                                        * Referenced by: '<S7>/Gain4'
                                        */
  6.67E-11,                            /* Variable: G
                                        * Referenced by: '<S9>/Constant'
                                        */

  /*  Variable: Klqr
   * Referenced by: '<S1>/Gain'
   */
  { 0.99986622525247382, 0.01611183868195919, -0.0028192064664597878,
    -0.016115546703937118, 0.97010354864516823, -0.16974612590544388,
    0.0027980208302554981, -0.17009440175150109, 0.029762663764960819,
    7.6455797544655315, -13.754151965593554, 2.40666474680448,
    12.797913000719351, -7.57736530549481, 1.3258671272508911,
    -2.5547914928439779, 0.38984735976969387, -0.068214448970721153 },
  5.972E+24,                           /* Variable: M_Earth
                                        * Referenced by: '<S9>/Gain1'
                                        */
  6.378E+6,                            /* Variable: R_Earth
                                        * Referenced by: '<S7>/Constant1'
                                        */

  /*  Variable: q0
   * Referenced by: '<S8>/Integrator1'
   */
  { 0.0, 0.0, 0.15643446504023087, 0.98768834059513777 },

  /*  Expression: [0,0,1]'
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0, 1.0 },
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S10>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/diag 0 '
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S15>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S15>/Gain2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S10>/Gain1'
                                        */

  /*  Expression: eye(3,3)
   * Referenced by: '<S10>/Matrix Gain'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<S7>/Constant8'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Gain6'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S7>/Gain5'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain8'
                                        */
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
  -1.3                                 /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation3'
                                        */
};
