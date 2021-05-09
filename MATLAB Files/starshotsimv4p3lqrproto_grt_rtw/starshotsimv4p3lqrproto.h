/*
 * starshotsimv4p3lqrproto.h
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

#ifndef RTW_HEADER_starshotsimv4p3lqrproto_h_
#define RTW_HEADER_starshotsimv4p3lqrproto_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef starshotsimv4p3lqrproto_COMMON_INCLUDES_
# define starshotsimv4p3lqrproto_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* starshotsimv4p3lqrproto_COMMON_INCLUDES_ */

#include "starshotsimv4p3lqrproto_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

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

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain8;                        /* '<S1>/Gain8' */
  real_T Product1[3];                  /* '<S6>/Product1' */
  real_T qd1;                          /* '<S14>/qd1' */
  real_T qd2;                          /* '<S14>/qd2' */
  real_T qd3;                          /* '<S14>/qd3' */
  real_T qd4;                          /* '<S14>/qd4' */
  real_T Gain2;                        /* '<S9>/Gain2' */
  real_T DotProduct3;                  /* '<S9>/Dot Product3' */
  real_T DotProduct4;                  /* '<S9>/Dot Product4' */
  real_T DotProduct5;                  /* '<S9>/Dot Product5' */
  real_T Integrator3;                  /* '<S9>/Integrator3' */
  real_T Integrator4;                  /* '<S9>/Integrator4' */
  real_T Integrator5;                  /* '<S9>/Integrator5' */
} B_starshotsimv4p3lqrproto_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Errorangle_PWORK;                  /* '<S1>/Error angle' */
} DW_starshotsimv4p3lqrproto_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[4];        /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S9>/Integrator' */
  real_T Integrator1_CSTATE_c;         /* '<S9>/Integrator1' */
  real_T Integrator9_CSTATE;           /* '<S2>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<S2>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<S2>/Integrator11' */
  real_T Integrator3_CSTATE;           /* '<S9>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S9>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S9>/Integrator5' */
} X_starshotsimv4p3lqrproto_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[4];        /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S9>/Integrator' */
  real_T Integrator1_CSTATE_c;         /* '<S9>/Integrator1' */
  real_T Integrator9_CSTATE;           /* '<S2>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<S2>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<S2>/Integrator11' */
  real_T Integrator3_CSTATE;           /* '<S9>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S9>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S9>/Integrator5' */
} XDot_starshotsimv4p3lqrproto_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[4];     /* '<S8>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S9>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S9>/Integrator' */
  boolean_T Integrator1_CSTATE_c;      /* '<S9>/Integrator1' */
  boolean_T Integrator9_CSTATE;        /* '<S2>/Integrator9' */
  boolean_T Integrator10_CSTATE;       /* '<S2>/Integrator10' */
  boolean_T Integrator11_CSTATE;       /* '<S2>/Integrator11' */
  boolean_T Integrator3_CSTATE;        /* '<S9>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S9>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S9>/Integrator5' */
} XDis_starshotsimv4p3lqrproto_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_starshotsimv4p3lqrproto_T_ {
  struct_S1AUKyBhnE1vWUrpWsLgyD starshot;/* Variable: starshot
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
  real_T B0;                           /* Variable: B0
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T G;                            /* Variable: G
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Klqr[18];                     /* Variable: Klqr
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T M_Earth;                      /* Variable: M_Earth
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T R_Earth;                      /* Variable: R_Earth
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T q0[4];                        /* Variable: q0
                                        * Referenced by: '<S8>/Integrator1'
                                        */
  real_T Constant_Value[3];            /* Expression: [0,0,1]'
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T diag0_Value;                  /* Expression: 0
                                        * Referenced by: '<S15>/diag 0 '
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T MatrixGain_Gain[9];           /* Expression: eye(3,3)
                                        * Referenced by: '<S10>/Matrix Gain'
                                        */
  real_T Constant8_Value;              /* Expression: pi/2
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Gain6_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<S7>/Gain5'
                                        */
  real_T Gain8_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain8'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1.3
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 1.3
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation5'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1.3
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1.3
                                        * Referenced by: '<S1>/Saturation3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_starshotsimv4p3lqrpro_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_starshotsimv4p3lqrproto_T *contStates;
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_P;

/* Block signals (auto storage) */
extern B_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_B;

/* Continuous states (auto storage) */
extern X_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_X;

/* Block states (auto storage) */
extern DW_starshotsimv4p3lqrproto_T starshotsimv4p3lqrproto_DW;

/* Model entry point functions */
extern void starshotsimv4p3lqrproto_initialize(void);
extern void starshotsimv4p3lqrproto_step(void);
extern void starshotsimv4p3lqrproto_terminate(void);

/* Real-time Model object */
extern RT_MODEL_starshotsimv4p3lqrpr_T *const starshotsimv4p3lqrproto_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'starshotsimv4p3lqrproto'
 * '<S1>'   : 'starshotsimv4p3lqrproto/Controller'
 * '<S2>'   : 'starshotsimv4p3lqrproto/Plant'
 * '<S3>'   : 'starshotsimv4p3lqrproto/Controller/Cross Product'
 * '<S4>'   : 'starshotsimv4p3lqrproto/Controller/Cross Product2'
 * '<S5>'   : 'starshotsimv4p3lqrproto/Controller/Norm3'
 * '<S6>'   : 'starshotsimv4p3lqrproto/Plant/Dynamics'
 * '<S7>'   : 'starshotsimv4p3lqrproto/Plant/Magnetic Field Model'
 * '<S8>'   : 'starshotsimv4p3lqrproto/Plant/Quaternion Integration'
 * '<S9>'   : 'starshotsimv4p3lqrproto/Plant/Tranlational Dynamics'
 * '<S10>'  : 'starshotsimv4p3lqrproto/Plant/quat to DCM'
 * '<S11>'  : 'starshotsimv4p3lqrproto/Plant/Dynamics/Cross Product'
 * '<S12>'  : 'starshotsimv4p3lqrproto/Plant/Magnetic Field Model/Dipole->ECI'
 * '<S13>'  : 'starshotsimv4p3lqrproto/Plant/Quaternion Integration/q_normalize'
 * '<S14>'  : 'starshotsimv4p3lqrproto/Plant/Quaternion Integration/qderiv'
 * '<S15>'  : 'starshotsimv4p3lqrproto/Plant/quat to DCM/Subsystem'
 */
#endif                                 /* RTW_HEADER_starshotsimv4p3lqrproto_h_ */
