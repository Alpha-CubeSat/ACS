//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Plantv41.h
//
// Code generated for Simulink model 'Plantv41'.
//
// Model version                  : 1.68
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Tue Apr 17 15:30:56 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_Plantv41_h_
#define RTW_HEADER_Plantv41_h_
#include <stddef.h>
#include <cmath>
#include <math.h>
#ifndef Plantv41_COMMON_INCLUDES_
# define Plantv41_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // Plantv41_COMMON_INCLUDES_

// Macros for accessing real-time model data structure

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTAT_m[4];// '<S5>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S1>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S1>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S1>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator1_DSTAT_l;// '<S6>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator2_DSTAT_e;// '<S6>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator3_DSTATE;// '<S6>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator4_DSTATE;// '<S6>/Discrete-Time Integrator4'
  real_T DiscreteTimeIntegrator5_DSTATE;// '<S6>/Discrete-Time Integrator5'
  real_T DiscreteTimeIntegrator6_DSTATE;// '<S6>/Discrete-Time Integrator6'
} DW;

// Constant parameters (auto storage)
typedef struct {
  // Expression: starshot.IC.massproperties.I
  //  Referenced by: '<S3>/Constant'

  real_T Constant_Value[9];

  // Expression: starshot.IC.massproperties.Iinv
  //  Referenced by: '<S3>/Constant1'

  real_T Constant1_Value[9];

  // Expression: eye(3,3)
  //  Referenced by: '<S7>/Matrix Gain'

  real_T MatrixGain_Gain[9];
} ConstP;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T current[3];                   // '<Root>/current'
} ExtU;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T angularvelocity[3];           // '<Root>/angular velocity'
  real_T magneticfield[3];             // '<Root>/magnetic field'
  real_T xyzposition[3];               // '<Root>/xyzposition'
  real_T quaternion[4];                // '<Root>/quaternion'
} ExtY;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP rtConstP;

// Class declaration for model Plantv41
class Plantv41ModelClass {
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
  Plantv41ModelClass();

  // Destructor
  ~Plantv41ModelClass();

  // private data and function members
 private:
  // Block signals and states
  DW rtDW;
};

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
//  hilite_system('starshotsimv4p3lqrforautocode/Plantv4')    - opens subsystem starshotsimv4p3lqrforautocode/Plantv4
//  hilite_system('starshotsimv4p3lqrforautocode/Plantv4/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'starshotsimv4p3lqrforautocode'
//  '<S1>'   : 'starshotsimv4p3lqrforautocode/Plantv4'
//  '<S2>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Cross Product'
//  '<S3>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Dynamics'
//  '<S4>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Magnetic Field Model'
//  '<S5>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Quaternion Integration'
//  '<S6>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Tranlational Dynamics'
//  '<S7>'   : 'starshotsimv4p3lqrforautocode/Plantv4/qtoQ'
//  '<S8>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Dynamics/Cross Product'
//  '<S9>'   : 'starshotsimv4p3lqrforautocode/Plantv4/Magnetic Field Model/Dipole->ECI'
//  '<S10>'  : 'starshotsimv4p3lqrforautocode/Plantv4/Quaternion Integration/q_normalize'
//  '<S11>'  : 'starshotsimv4p3lqrforautocode/Plantv4/Quaternion Integration/qderiv'
//  '<S12>'  : 'starshotsimv4p3lqrforautocode/Plantv4/qtoQ/Subsystem'

#endif                                 // RTW_HEADER_Plantv41_h_

//
// File trailer for generated code.
//
// [EOF]
//
