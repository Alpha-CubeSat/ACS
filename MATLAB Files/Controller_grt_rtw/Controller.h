/*
 * Controller.h
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

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Controller_COMMON_INCLUDES_
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Errorangle_PWORK;                  /* '<S1>/Error angle' */
} DW_Controller_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T w[3];                         /* '<Root>/Angular Velocity' */
  real_T MagneticField[3];             /* '<Root>/Magnetic Field' */
} ExtU_Controller_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[3];                      /* '<Root>/Out1' */
} ExtY_Controller_T;

/* Parameters (auto storage) */
struct P_Controller_T_ {
  real_T Klqr[18];                     /* Variable: Klqr
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant_Value[3];            /* Expression: [0,0,1]'
                                        * Referenced by: '<S1>/Constant'
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
  real_T Gain8_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain8'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Controller_T Controller_P;

/* Block states (auto storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Controller_T Controller_Y;

/* Model entry point functions */
extern void Controller_initialize(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;

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
 * hilite_system('starshotsimv4p3lqr/Controller')    - opens subsystem starshotsimv4p3lqr/Controller
 * hilite_system('starshotsimv4p3lqr/Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'starshotsimv4p3lqr'
 * '<S1>'   : 'starshotsimv4p3lqr/Controller'
 * '<S2>'   : 'starshotsimv4p3lqr/Controller/Cross Product'
 * '<S3>'   : 'starshotsimv4p3lqr/Controller/Cross Product2'
 * '<S4>'   : 'starshotsimv4p3lqr/Controller/Norm3'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */
