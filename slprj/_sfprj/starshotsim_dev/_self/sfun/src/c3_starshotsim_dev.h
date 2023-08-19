#ifndef __c3_starshotsim_dev_h__
#define __c3_starshotsim_dev_h__

/* Forward Declarations */
#ifndef typedef_c3_cell_1
#define typedef_c3_cell_1

typedef struct c3_tag_aj4Ec4OjOa1O8T7BVPzvh c3_cell_1;

#endif                                 /* typedef_c3_cell_1 */

#ifndef typedef_c3_s_PFD6g2i6EkL87TGzFS4l4
#define typedef_c3_s_PFD6g2i6EkL87TGzFS4l4

typedef struct c3_tag_PFD6g2i6EkL87TGzFS4l4 c3_s_PFD6g2i6EkL87TGzFS4l4;

#endif                                 /* typedef_c3_s_PFD6g2i6EkL87TGzFS4l4 */

#ifndef typedef_c3_s_UeWBqJkwkeZ7Z1QCUlMFiF
#define typedef_c3_s_UeWBqJkwkeZ7Z1QCUlMFiF

typedef struct c3_tag_UeWBqJkwkeZ7Z1QCUlMFiF c3_s_UeWBqJkwkeZ7Z1QCUlMFiF;

#endif                                 /* typedef_c3_s_UeWBqJkwkeZ7Z1QCUlMFiF */

struct SFc3_starshotsim_devInstanceStruct;

/* Type Definitions */
#ifndef struct_c3_tag_aj4Ec4OjOa1O8T7BVPzvh
#define struct_c3_tag_aj4Ec4OjOa1O8T7BVPzvh

struct c3_tag_aj4Ec4OjOa1O8T7BVPzvh
{
  char_T f1[11];
  char_T f2[7];
  char_T f3[8];
};

#endif                                 /* struct_c3_tag_aj4Ec4OjOa1O8T7BVPzvh */

#ifndef typedef_c3_cell_1
#define typedef_c3_cell_1

typedef c3_tag_aj4Ec4OjOa1O8T7BVPzvh c3_cell_1;

#endif                                 /* typedef_c3_cell_1 */

#ifndef struct_c3_tag_PFD6g2i6EkL87TGzFS4l4
#define struct_c3_tag_PFD6g2i6EkL87TGzFS4l4

struct c3_tag_PFD6g2i6EkL87TGzFS4l4
{
  c3_cell_1 _data;
};

#endif                                 /* struct_c3_tag_PFD6g2i6EkL87TGzFS4l4 */

#ifndef typedef_c3_s_PFD6g2i6EkL87TGzFS4l4
#define typedef_c3_s_PFD6g2i6EkL87TGzFS4l4

typedef c3_tag_PFD6g2i6EkL87TGzFS4l4 c3_s_PFD6g2i6EkL87TGzFS4l4;

#endif                                 /* typedef_c3_s_PFD6g2i6EkL87TGzFS4l4 */

#ifndef struct_c3_tag_UeWBqJkwkeZ7Z1QCUlMFiF
#define struct_c3_tag_UeWBqJkwkeZ7Z1QCUlMFiF

struct c3_tag_UeWBqJkwkeZ7Z1QCUlMFiF
{
  c3_cell_1 _data;
};

#endif                                 /* struct_c3_tag_UeWBqJkwkeZ7Z1QCUlMFiF */

#ifndef typedef_c3_s_UeWBqJkwkeZ7Z1QCUlMFiF
#define typedef_c3_s_UeWBqJkwkeZ7Z1QCUlMFiF

typedef c3_tag_UeWBqJkwkeZ7Z1QCUlMFiF c3_s_UeWBqJkwkeZ7Z1QCUlMFiF;

#endif                                 /* typedef_c3_s_UeWBqJkwkeZ7Z1QCUlMFiF */

#ifndef typedef_c3_starshotsim_devStackData
#define typedef_c3_starshotsim_devStackData

typedef struct {
} c3_starshotsim_devStackData;

#endif                                 /* typedef_c3_starshotsim_devStackData */

#ifndef struct_SFc3_starshotsim_devInstanceStruct
#define struct_SFc3_starshotsim_devInstanceStruct

struct SFc3_starshotsim_devInstanceStruct
{
  real_T c3_dT;
  real_T c3_Q[36];
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_starshotsim_dev;
  uint8_T c3_JITStateAnimation[1];
  uint8_T c3_JITTransitionAnimation[1];
  int32_T c3_IsDebuggerActive;
  int32_T c3_IsSequenceViewerPresent;
  int32_T c3_SequenceViewerOptimization;
  int32_T c3_IsHeatMapPresent;
  void *c3_RuntimeVar;
  uint32_T c3_mlFcnLineNumber;
  void *c3_fcnDataPtrs[13];
  char_T *c3_dataNames[13];
  uint32_T c3_numFcnVars;
  uint32_T c3_ssIds[13];
  uint32_T c3_statuses[13];
  void *c3_outMexFcns[13];
  void *c3_inMexFcns[13];
  CovrtStateflowInstance *c3_covrtInstance;
  void *c3_fEmlrtCtx;
  real_T (*c3_J_k_k)[36];
  real_T (*c3_X_k1_k)[6];
  real_T (*c3_X_k_k)[6];
  real_T (*c3_P_k_k)[36];
  real_T (*c3_P_k1_k)[36];
};

#endif                                 /* struct_SFc3_starshotsim_devInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_starshotsim_dev_get_eml_resolved_functions_info();

/* Function Definitions */
extern void sf_c3_starshotsim_dev_get_check_sum(mxArray *plhs[]);
extern void c3_starshotsim_dev_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
