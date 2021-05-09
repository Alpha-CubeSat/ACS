//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test_integrator0.cpp
//
// Code generated for Simulink model 'test_integrator0'.
//
// Model version                  : 1.1
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Thu Apr 19 20:49:57 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "test_integrator0.h"

// Model step function
void test_integrator0ModelClass::step()
{
  // Outputs for Atomic SubSystem: '<Root>/test_integrator '
  // Outport: '<Root>/Out1' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

  rtY.Out1[0] = rtDW.DiscreteTimeIntegrator_DSTATE[0];

  // End of Outputs for SubSystem: '<Root>/test_integrator '

  // Update for Atomic SubSystem: '<Root>/test_integrator '
  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
  //   Update for Inport: '<Root>/In1'

  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.01 * rtU.In1[0];

  // End of Update for SubSystem: '<Root>/test_integrator '

  // Outputs for Atomic SubSystem: '<Root>/test_integrator '
  // Outport: '<Root>/Out1' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

  rtY.Out1[1] = rtDW.DiscreteTimeIntegrator_DSTATE[1];

  // Update for Atomic SubSystem: '<Root>/test_integrator '
  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S1>/Gain1'
  //   Inport: '<Root>/In1'

  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 2.0 * rtU.In1[1] * 0.01;

  // End of Update for SubSystem: '<Root>/test_integrator '

  // Outport: '<Root>/Out1' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

  rtY.Out1[2] = rtDW.DiscreteTimeIntegrator_DSTATE[2];

  // Update for Atomic SubSystem: '<Root>/test_integrator '
  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S1>/Gain2'
  //   Inport: '<Root>/In1'

  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 3.0 * rtU.In1[2] * 0.01;

  // End of Update for SubSystem: '<Root>/test_integrator '
  // End of Outputs for SubSystem: '<Root>/test_integrator '
}

// Model initialize function
void test_integrator0ModelClass::initialize()
{
  // (no initialization code required)
}

// Constructor
test_integrator0ModelClass::test_integrator0ModelClass()
{
}

// Destructor
test_integrator0ModelClass::~test_integrator0ModelClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
