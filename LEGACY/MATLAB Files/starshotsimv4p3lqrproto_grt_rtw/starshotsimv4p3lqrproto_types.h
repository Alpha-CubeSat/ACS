/*
 * starshotsimv4p3lqrproto_types.h
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

#ifndef RTW_HEADER_starshotsimv4p3lqrproto_types_h_
#define RTW_HEADER_starshotsimv4p3lqrproto_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_GtlCpZ9fRHWdDsH83y8zsD_
#define DEFINED_TYPEDEF_FOR_struct_GtlCpZ9fRHWdDsH83y8zsD_

typedef struct {
  real_T m;
  real_T Ixx;
  real_T Ixy;
  real_T Ixz;
  real_T Iyx;
  real_T Iyy;
  real_T Iyz;
  real_T Izx;
  real_T Izy;
  real_T Izz;
  real_T I[9];
  real_T Iinv[9];
} struct_GtlCpZ9fRHWdDsH83y8zsD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DAIwQUSTGC7Xz09bPbYDzB_
#define DEFINED_TYPEDEF_FOR_struct_DAIwQUSTGC7Xz09bPbYDzB_

typedef struct {
  real_T x;
  real_T y;
  real_T z;
  real_T xdot;
  real_T ydot;
  real_T zdot;
  real_T phi;
  real_T theta;
  real_T psi;
  real_T p;
  real_T q;
  real_T r;
  struct_GtlCpZ9fRHWdDsH83y8zsD massproperties;
} struct_DAIwQUSTGC7Xz09bPbYDzB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WS86OIz13p2EM7bqESYoS_
#define DEFINED_TYPEDEF_FOR_struct_WS86OIz13p2EM7bqESYoS_

typedef struct {
  real_T Kd[3];
  real_T Kp[3];
  real_T p;
  real_T q;
  real_T r;
} struct_WS86OIz13p2EM7bqESYoS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_S1AUKyBhnE1vWUrpWsLgyD_
#define DEFINED_TYPEDEF_FOR_struct_S1AUKyBhnE1vWUrpWsLgyD_

typedef struct {
  struct_DAIwQUSTGC7Xz09bPbYDzB IC;
  struct_WS86OIz13p2EM7bqESYoS cmd;
} struct_S1AUKyBhnE1vWUrpWsLgyD;

#endif

/* Parameters (auto storage) */
typedef struct P_starshotsimv4p3lqrproto_T_ P_starshotsimv4p3lqrproto_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_starshotsimv4p3lqrpro_T RT_MODEL_starshotsimv4p3lqrpr_T;

#endif                                 /* RTW_HEADER_starshotsimv4p3lqrproto_types_h_ */
