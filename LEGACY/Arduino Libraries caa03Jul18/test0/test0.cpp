//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test0.cpp
//
// Code generated for Simulink model 'test0'.
//
// Model version                  : 1.0
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Wed Apr 18 16:55:16 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "test0.h"

// Model step function
void test0ModelClass::step()
{
  // Outputs for Atomic SubSystem: '<Root>/test '
  // Outport: '<Root>/Out1' incorporates:
  //   Gain: '<S1>/Gain1'
  //   Gain: '<S1>/Gain2'
  //   Inport: '<Root>/In1'
  //   SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'

  rtY.Out1[0] = rtU.In1[0];
  rtY.Out1[1] = 2.0 * rtU.In1[1];
  rtY.Out1[2] = 3.0 * rtU.In1[2];

  // End of Outputs for SubSystem: '<Root>/test '
}

// Model initialize function
void test0ModelClass::initialize()
{
  // (no initialization code required)
}

// Constructor
test0ModelClass::test0ModelClass()
{
}

// Destructor
test0ModelClass::~test0ModelClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
