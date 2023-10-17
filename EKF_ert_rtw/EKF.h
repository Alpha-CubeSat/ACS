//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: EKF.h
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
#ifndef RTW_HEADER_EKF_h_
#define RTW_HEADER_EKF_h_
#include "rtwtypes.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Block signals and states (default storage) for system '<Root>'
struct DW {
  real_T UnitDelayX_DSTATE[6];         // '<S3>/Unit Delay - X'
  real_T UnitDelayP_DSTATE[36];        // '<S3>/Unit Delay - P'
  real_T sol_data[6006];
  real_T yout[6006];
};

// Constant parameters (default storage)
struct ConstP {
  // Expression: Hd
  //  Referenced by: '<S3>/Kalman corrector'

  real_T Kalmancorrector_Hd[36];

  // Expression: Q
  //  Referenced by: '<S3>/Kalman predictor'

  real_T Kalmanpredictor_Q[36];

  // Expression: [3.42e-05,-3.0e-06,-9.28e-05,0.06, -0.05, 0.07]'
  //  Referenced by: '<S3>/Unit Delay - X'

  real_T UnitDelayX_InitialCondition[6];
};

// External inputs (root inport signals with default storage)
struct ExtU {
  real_T z[3];                         // '<Root>/raw_w'
  real_T z_a[3];                       // '<Root>/raw_mag'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real_T filter_w[3];                  // '<Root>/filter_w'
  real_T filter_mag[3];                // '<Root>/filter_mag'
};

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

// Constant parameters (default storage)
extern const ConstP rtConstP;

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern real_T R_n[36];                 // Variable: R_n
                                          //  Referenced by:
                                          //    '<S3>/Kalman corrector'
                                          //    '<S3>/Unit Delay - P'
                                          //  (measurement noise variance) Matrices

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  struct BigEndianIEEEDouble {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  };

  struct LittleEndianIEEEDouble {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  };

  struct IEEESingle {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  };
}                                      // extern "C"

// Class declaration for model EKF
class EKF
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  EKF();

  // Destructor
  ~EKF();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<Root>'
  real_T norm(const real_T x[36]);
  void mpower(const real_T a[36], real_T b, real_T c[36]);
  real_T log2_e(real_T x);
  void padeApproximation(const real_T A[36], const real_T A2[36], const real_T
    A4[36], const real_T A6[36], int32_T m, real_T F[36]);
  void recomputeBlockDiag(const real_T A[36], real_T F[36], const int32_T
    blockFormat[5]);
  real_T xnrm2(int32_T n, const real_T x[36], int32_T ix0);
  void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C[36],
              int32_T ic0, real_T work[6]);
  real_T xnrm2_b(int32_T n, const real_T x[3]);
  void xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r, real_T *
               rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);
  void xrot(int32_T n, real_T x[36], int32_T ix0, int32_T iy0, real_T c, real_T
            s);
  int32_T xhseqr(real_T h[36], real_T z[36]);
  void schur(const real_T A[36], real_T V[36], real_T T[36]);
  void expm(real_T A[36], real_T F[36]);

  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Scope' : Unused code path elimination


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
//  hilite_system('starshotsim_dev/EKF')    - opens subsystem starshotsim_dev/EKF
//  hilite_system('starshotsim_dev/EKF/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'starshotsim_dev'
//  '<S1>'   : 'starshotsim_dev/EKF'
//  '<S2>'   : 'starshotsim_dev/EKF/EKF'
//  '<S3>'   : 'starshotsim_dev/EKF/EKF/EKF_Primary'
//  '<S4>'   : 'starshotsim_dev/EKF/EKF/Jacobian'
//  '<S5>'   : 'starshotsim_dev/EKF/EKF/EKF_Primary/Kalman corrector'
//  '<S6>'   : 'starshotsim_dev/EKF/EKF/EKF_Primary/Kalman predictor'
//  '<S7>'   : 'starshotsim_dev/EKF/EKF/EKF_Primary/sqrt(Pii)'

#endif                                 // RTW_HEADER_EKF_h_

//
// File trailer for generated code.
//
// [EOF]
//
