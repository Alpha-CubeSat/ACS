//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test_integrator0.h
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
#ifndef RTW_HEADER_test_integrator0_h_
#define RTW_HEADER_test_integrator0_h_
#ifndef test_integrator0_COMMON_INCLUDES_
# define test_integrator0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // test_integrator0_COMMON_INCLUDES_

// Macros for accessing real-time model data structure

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[3];// '<S1>/Discrete-Time Integrator'
} DW;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T In1[3];                       // '<Root>/In1'
} ExtU;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T Out1[3];                      // '<Root>/Out1'
} ExtY;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model test_integrator0
class test_integrator0ModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  test_integrator0ModelClass();

  // Destructor
  ~test_integrator0ModelClass();

  // private data and function members
 private:
  // Block signals and states
  DW rtDW;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Gain' : Eliminated nontunable gain of 1


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('test/test_integrator ')    - opens subsystem test/test_integrator
//  hilite_system('test/test_integrator /Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'test'
//  '<S1>'   : 'test/test_integrator '

#endif                                 // RTW_HEADER_test_integrator0_h_

//
// File trailer for generated code.
//
// [EOF]
//
