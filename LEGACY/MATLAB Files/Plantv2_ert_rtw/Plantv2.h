/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Plantv2.h
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

#ifndef RTW_HEADER_Plantv2_h_
#define RTW_HEADER_Plantv2_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef Plantv2_COMMON_INCLUDES_
# define Plantv2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Plantv2_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T Product1[3];                  /* '<S3>/Product1' */
  real_T qd1;                          /* '<S11>/qd1' */
  real_T qd2;                          /* '<S11>/qd2' */
  real_T qd3;                          /* '<S11>/qd3' */
  real_T qd4;                          /* '<S11>/qd4' */
  real_T DotProduct3;                  /* '<S6>/Dot Product3' */
  real_T DotProduct4;                  /* '<S6>/Dot Product4' */
  real_T DotProduct5;                  /* '<S6>/Dot Product5' */
  real_T Integrator3;                  /* '<S6>/Integrator3' */
  real_T Integrator4;                  /* '<S6>/Integrator4' */
  real_T Integrator5;                  /* '<S6>/Integrator5' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator9_CSTATE;           /* '<S1>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<S1>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator1_CSTATE[4];        /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE_c;         /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S6>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S6>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S6>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S6>/Integrator5' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator9_CSTATE;           /* '<S1>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<S1>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator1_CSTATE[4];        /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE_c;         /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S6>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S6>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S6>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S6>/Integrator5' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator9_CSTATE;        /* '<S1>/Integrator9' */
  boolean_T Integrator10_CSTATE;       /* '<S1>/Integrator10' */
  boolean_T Integrator11_CSTATE;       /* '<S1>/Integrator11' */
  boolean_T Integrator1_CSTATE[4];     /* '<S5>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE_c;      /* '<S6>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S6>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<S6>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S6>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S6>/Integrator5' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: starshot.IC.massproperties.I
   * Referenced by: '<S3>/Constant'
   */
  real_T Constant_Value[9];

  /* Expression: starshot.IC.massproperties.Iinv
   * Referenced by: '<S3>/Constant1'
   */
  real_T Constant1_Value[9];

  /* Expression: eye(3,3)
   * Referenced by: '<S7>/Matrix Gain'
   */
  real_T MatrixGain_Gain[9];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T current[3];                   /* '<Root>/current' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T angularvelocity[3];           /* '<Root>/angular velocity' */
  real_T magneticfield[3];             /* '<Root>/magnetic field' */
  real_T xyzposition[3];               /* '<Root>/xyzposition' */
  real_T quaternion[4];                /* '<Root>/quaternion' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[13];
  real_T odeF[3][13];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (auto storage) */
extern X rtX;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Plantv2_initialize(void);
extern void Plantv2_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('starshotsimv4p3lqrforautocode/Plantv2')    - opens subsystem starshotsimv4p3lqrforautocode/Plantv2
 * hilite_system('starshotsimv4p3lqrforautocode/Plantv2/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'starshotsimv4p3lqrforautocode'
 * '<S1>'   : 'starshotsimv4p3lqrforautocode/Plantv2'
 * '<S2>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Cross Product'
 * '<S3>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Dynamics'
 * '<S4>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Magnetic Field Model'
 * '<S5>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Quaternion Integration'
 * '<S6>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Tranlational Dynamics'
 * '<S7>'   : 'starshotsimv4p3lqrforautocode/Plantv2/qtoQ'
 * '<S8>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Dynamics/Cross Product'
 * '<S9>'   : 'starshotsimv4p3lqrforautocode/Plantv2/Magnetic Field Model/Dipole->ECI'
 * '<S10>'  : 'starshotsimv4p3lqrforautocode/Plantv2/Quaternion Integration/q_normalize'
 * '<S11>'  : 'starshotsimv4p3lqrforautocode/Plantv2/Quaternion Integration/qderiv'
 * '<S12>'  : 'starshotsimv4p3lqrforautocode/Plantv2/qtoQ/Subsystem'
 */
#endif                                 /* RTW_HEADER_Plantv2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
