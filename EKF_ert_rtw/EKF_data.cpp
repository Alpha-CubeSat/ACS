//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: EKF_data.cpp
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

// Constant parameters (default storage)
const ConstP rtConstP = {
  // Expression: Hd
  //  Referenced by: '<S3>/Kalman corrector'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: Q
  //  Referenced by: '<S3>/Kalman predictor'

  { 0.00016, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0014000000000000002, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002 },

  // Expression: [3.42e-05,-3.0e-06,-9.28e-05,0.06, -0.05, 0.07]'
  //  Referenced by: '<S3>/Unit Delay - X'

  { 3.42E-5, -3.0E-6, -9.28E-5, 0.06, -0.05, 0.07 }
};

//
// File trailer for generated code.
//
// [EOF]
//
