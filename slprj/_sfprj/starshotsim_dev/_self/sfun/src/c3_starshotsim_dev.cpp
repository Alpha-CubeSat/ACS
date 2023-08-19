/* Include files */

#include "starshotsim_dev_sfun.h"
#include "c3_starshotsim_dev.h"
#include <math.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
const int32_T CALL_EVENT = -1;

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c3_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c3_b_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c3_c_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c3_d_emlrtMCI = { 44,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtMCInfo c3_e_emlrtMCI = { 47,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtMCInfo c3_f_emlrtMCI = { 25,/* lineNo */
  13,                                  /* colNo */
  "log2",                              /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\log2.m"/* pName */
};

static emlrtMCInfo c3_g_emlrtMCI = { 14,/* lineNo */
  9,                                   /* colNo */
  "log",                               /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static emlrtRSInfo c3_emlrtRSI = { 17, /* lineNo */
  "ode45",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\ode45.m"/* pathName */
};

static emlrtRSInfo c3_b_emlrtRSI = { 90,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_c_emlrtRSI = { 367,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_d_emlrtRSI = { 369,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_e_emlrtRSI = { 374,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_f_emlrtRSI = { 376,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_g_emlrtRSI = { 429,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_h_emlrtRSI = { 418,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_i_emlrtRSI = { 419,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_j_emlrtRSI = { 416,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_k_emlrtRSI = { 587,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_m_emlrtRSI = { 631,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_o_emlrtRSI = { 63,/* lineNo */
  "function_handle",                   /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"/* pathName */
};

static emlrtRSInfo c3_p_emlrtRSI = { 89,/* lineNo */
  "explicitRungeKutta",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pathName */
};

static emlrtRSInfo c3_q_emlrtRSI = { 11,/* lineNo */
  "callODEFunctionNSM",                /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\callODEFunctionNSM.m"/* pathName */
};

static emlrtRSInfo c3_r_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c3_s_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c3_t_emlrtRSI = { 64,/* lineNo */
  "xgemv",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c3_u_emlrtRSI = { 58,/* lineNo */
  "xgemv",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c3_v_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c3_w_emlrtRSI = { 15,/* lineNo */
  "num2str",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\num2str.m"/* pathName */
};

static emlrtRSInfo c3_x_emlrtRSI = { 53,/* lineNo */
  "flt2str",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pathName */
};

static emlrtRSInfo c3_y_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "E:\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c3_ab_emlrtRSI = { 14,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_bb_emlrtRSI = { 34,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_cb_emlrtRSI = { 36,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_db_emlrtRSI = { 37,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_eb_emlrtRSI = { 38,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_fb_emlrtRSI = { 39,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_gb_emlrtRSI = { 46,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_hb_emlrtRSI = { 48,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_ib_emlrtRSI = { 55,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_jb_emlrtRSI = { 22,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_kb_emlrtRSI = { 29,/* lineNo */
  "anyNonFinite",                      /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite.m"/* pathName */
};

static emlrtRSInfo c3_mb_emlrtRSI = { 44,/* lineNo */
  "vAllOrAny",                         /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo c3_ob_emlrtRSI = { 103,/* lineNo */
  "vAllOrAny",                         /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo c3_pb_emlrtRSI = { 35,/* lineNo */
  "schur",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo c3_qb_emlrtRSI = { 66,/* lineNo */
  "schur",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo c3_rb_emlrtRSI = { 69,/* lineNo */
  "schur",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo c3_sb_emlrtRSI = { 70,/* lineNo */
  "schur",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo c3_tb_emlrtRSI = { 83,/* lineNo */
  "schur",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo c3_ub_emlrtRSI = { 18,/* lineNo */
  "xgehrd",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgehrd.m"/* pathName */
};

static emlrtRSInfo c3_vb_emlrtRSI = { 46,/* lineNo */
  "xzgehrd",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo c3_wb_emlrtRSI = { 50,/* lineNo */
  "xzgehrd",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo c3_xb_emlrtRSI = { 58,/* lineNo */
  "xzgehrd",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo c3_yb_emlrtRSI = { 20,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c3_ac_emlrtRSI = { 81,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c3_bc_emlrtRSI = { 41,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c3_cc_emlrtRSI = { 53,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c3_dc_emlrtRSI = { 68,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c3_ec_emlrtRSI = { 71,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c3_fc_emlrtRSI = { 23,/* lineNo */
  "xnrm2",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo c3_gc_emlrtRSI = { 38,/* lineNo */
  "xnrm2",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo c3_hc_emlrtRSI = { 31,/* lineNo */
  "xscal",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo c3_ic_emlrtRSI = { 18,/* lineNo */
  "xscal",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

static emlrtRSInfo c3_jc_emlrtRSI = { 84,/* lineNo */
  "xzlarf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c3_kc_emlrtRSI = { 91,/* lineNo */
  "xzlarf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c3_mc_emlrtRSI = { 37,/* lineNo */
  "xgemv",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c3_oc_emlrtRSI = { 45,/* lineNo */
  "xgerc",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

static emlrtRSInfo c3_pc_emlrtRSI = { 45,/* lineNo */
  "xger",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c3_qc_emlrtRSI = { 15,/* lineNo */
  "xger",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo c3_rc_emlrtRSI = { 41,/* lineNo */
  "xgerx",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c3_sc_emlrtRSI = { 54,/* lineNo */
  "xgerx",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c3_tc_emlrtRSI = { 50,/* lineNo */
  "xzlarf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c3_uc_emlrtRSI = { 68,/* lineNo */
  "xzlarf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c3_vc_emlrtRSI = { 75,/* lineNo */
  "xzlarf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c3_wc_emlrtRSI = { 103,/* lineNo */
  "xzlarf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c3_xc_emlrtRSI = { 74,/* lineNo */
  "xgemv",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c3_yc_emlrtRSI = { 11,/* lineNo */
  "xungorghr",                         /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

static emlrtRSInfo c3_ad_emlrtRSI = { 69,/* lineNo */
  "xungorghr",                         /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

static emlrtRSInfo c3_bd_emlrtRSI = { 13,/* lineNo */
  "xzunghr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunghr.m"/* pathName */
};

static emlrtRSInfo c3_cd_emlrtRSI = { 29,/* lineNo */
  "xzunghr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunghr.m"/* pathName */
};

static emlrtRSInfo c3_dd_emlrtRSI = { 38,/* lineNo */
  "xzunghr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunghr.m"/* pathName */
};

static emlrtRSInfo c3_ed_emlrtRSI = { 53,/* lineNo */
  "xzunghr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunghr.m"/* pathName */
};

static emlrtRSInfo c3_fd_emlrtRSI = { 16,/* lineNo */
  "xzungqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzungqr.m"/* pathName */
};

static emlrtRSInfo c3_gd_emlrtRSI = { 34,/* lineNo */
  "xzungqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzungqr.m"/* pathName */
};

static emlrtRSInfo c3_hd_emlrtRSI = { 41,/* lineNo */
  "xzungqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzungqr.m"/* pathName */
};

static emlrtRSInfo c3_id_emlrtRSI = { 46,/* lineNo */
  "xzungqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzungqr.m"/* pathName */
};

static emlrtRSInfo c3_jd_emlrtRSI = { 21,/* lineNo */
  "xhseqr",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo c3_kd_emlrtRSI = { 16,/* lineNo */
  "xdhseqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo c3_md_emlrtRSI = { 16,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_od_emlrtRSI = { 33,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_pd_emlrtRSI = { 172,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_qd_emlrtRSI = { 226,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_rd_emlrtRSI = { 240,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_sd_emlrtRSI = { 243,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_td_emlrtRSI = { 301,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_ud_emlrtRSI = { 309,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_vd_emlrtRSI = { 273,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_wd_emlrtRSI = { 281,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_xd_emlrtRSI = { 337,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_yd_emlrtRSI = { 342,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_ae_emlrtRSI = { 345,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_be_emlrtRSI = { 349,/* lineNo */
  "xdlahqr",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlahqr.m"/* pathName */
};

static emlrtRSInfo c3_ce_emlrtRSI = { 69,/* lineNo */
  "xcopy",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xcopy.m"/* pathName */
};

static emlrtRSInfo c3_de_emlrtRSI = { 81,/* lineNo */
  "xdlanv2",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

static emlrtRSInfo c3_ee_emlrtRSI = { 102,/* lineNo */
  "xdlanv2",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

static emlrtRSInfo c3_fe_emlrtRSI = { 103,/* lineNo */
  "xdlanv2",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

static emlrtRSInfo c3_ge_emlrtRSI = { 105,/* lineNo */
  "xdlanv2",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

static emlrtRSInfo c3_he_emlrtRSI = { 52,/* lineNo */
  "xdlanv2",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

static emlrtRSInfo c3_ie_emlrtRSI = { 133,/* lineNo */
  "xdlanv2",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

static emlrtRSInfo c3_je_emlrtRSI = { 32,/* lineNo */
  "xrot",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrot.m"/* pathName */
};

static emlrtRSInfo c3_ke_emlrtRSI = { 24,/* lineNo */
  "xrot",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xrot.m"/* pathName */
};

static emlrtRSInfo c3_me_emlrtRSI = { 89,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_oe_emlrtRSI = { 90,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_pe_emlrtRSI = { 92,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_qe_emlrtRSI = { 97,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_re_emlrtRSI = { 102,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_se_emlrtRSI = { 105,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_te_emlrtRSI = { 110,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_ue_emlrtRSI = { 115,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_ve_emlrtRSI = { 118,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_we_emlrtRSI = { 119,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_xe_emlrtRSI = { 281,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_ye_emlrtRSI = { 282,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_af_emlrtRSI = { 283,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_bf_emlrtRSI = { 286,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_cf_emlrtRSI = { 46,/* lineNo */
  "mpower",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c3_df_emlrtRSI = { 101,/* lineNo */
  "mpower",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c3_ef_emlrtRSI = { 13,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c3_ff_emlrtRSI = { 115,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c3_gf_emlrtRSI = { 95,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c3_hf_emlrtRSI = { 21,/* lineNo */
  "inv",                               /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c3_if_emlrtRSI = { 22,/* lineNo */
  "inv",                               /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c3_jf_emlrtRSI = { 173,/* lineNo */
  "inv",                               /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c3_kf_emlrtRSI = { 190,/* lineNo */
  "inv",                               /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c3_mf_emlrtRSI = { 31,/* lineNo */
  "xgetrf",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c3_of_emlrtRSI = { 50,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c3_pf_emlrtRSI = { 58,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c3_qf_emlrtRSI = { 45,/* lineNo */
  "xgeru",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo c3_rf_emlrtRSI = { 59,/* lineNo */
  "xtrsm",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c3_sf_emlrtRSI = { 51,/* lineNo */
  "xtrsm",                             /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c3_tf_emlrtRSI = { 46,/* lineNo */
  "inv",                               /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c3_uf_emlrtRSI = { 42,/* lineNo */
  "inv",                               /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c3_vf_emlrtRSI = { 225,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_wf_emlrtRSI = { 67,/* lineNo */
  "lusolve",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c3_xf_emlrtRSI = { 109,/* lineNo */
  "lusolve",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c3_yf_emlrtRSI = { 112,/* lineNo */
  "lusolve",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c3_ag_emlrtRSI = { 124,/* lineNo */
  "lusolve",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c3_bg_emlrtRSI = { 26,/* lineNo */
  "xgetrfs",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrfs.m"/* pathName */
};

static emlrtRSInfo c3_cg_emlrtRSI = { 27,/* lineNo */
  "xgetrfs",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrfs.m"/* pathName */
};

static emlrtRSInfo c3_dg_emlrtRSI = { 18,/* lineNo */
  "xgetrs",                            /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrs.m"/* pathName */
};

static emlrtRSInfo c3_eg_emlrtRSI = { 36,/* lineNo */
  "xzgetrs",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrs.m"/* pathName */
};

static emlrtRSInfo c3_fg_emlrtRSI = { 90,/* lineNo */
  "lusolve",                           /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo c3_gg_emlrtRSI = { 263,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_hg_emlrtRSI = { 244,/* lineNo */
  "expm",                              /* fcnName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pathName */
};

static emlrtRSInfo c3_ig_emlrtRSI = { 9,/* lineNo */
  "EKF/EKF/EKF_Primary/Kalman predictor",/* fcnName */
  "#starshotsim_dev:1877"              /* pathName */
};

static emlrtRSInfo c3_jg_emlrtRSI = { 15,/* lineNo */
  "EKF/EKF/EKF_Primary/Kalman predictor",/* fcnName */
  "#starshotsim_dev:1877"              /* pathName */
};

static emlrtRTEInfo c3_emlrtRTEI = { 656,/* lineNo */
  1,                                   /* colNo */
  "explicitRungeKutta",                /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pName */
};

static emlrtRTEInfo c3_b_emlrtRTEI = { 657,/* lineNo */
  1,                                   /* colNo */
  "explicitRungeKutta",                /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\funfun\\private\\explicitRungeKutta.m"/* pName */
};

static emlrtRTEInfo c3_c_emlrtRTEI = { 44,/* lineNo */
  34,                                  /* colNo */
  "vAllOrAny",                         /* fName */
  "E:\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pName */
};

static emlrtBCInfo c3_emlrtBCI = { 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  19,                                  /* lineNo */
  14,                                  /* colNo */
  "sol(end,1:end)",                    /* aName */
  "EKF/EKF/EKF_Primary/Kalman predictor",/* fName */
  "#starshotsim_dev:1877",             /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c3_emlrtDCI = { 19, /* lineNo */
  14,                                  /* colNo */
  "EKF/EKF/EKF_Primary/Kalman predictor",/* fName */
  "#starshotsim_dev:1877",             /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c3_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  14,                                  /* colNo */
  "sol",                               /* aName */
  "EKF/EKF/EKF_Primary/Kalman predictor",/* fName */
  "#starshotsim_dev:1877",             /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 51,/* lineNo */
  13,                                  /* colNo */
  "expm",                              /* fName */
  "E:\\Matlab\\toolbox\\eml\\lib\\matlab\\matfun\\expm.m"/* pName */
};

static real_T c3_dv[21] = { 0.2, 0.075, 0.225, 0.97777777777777775,
  -3.7333333333333334, 3.5555555555555554, 2.9525986892242035,
  -11.595793324188385, 9.8228928516994358, -0.29080932784636487,
  2.8462752525252526, -10.757575757575758, 8.9064227177434727,
  0.27840909090909088, -0.2735313036020583, 0.091145833333333329, 0.0,
  0.44923629829290207, 0.65104166666666663, -0.322376179245283,
  0.13095238095238096 };

static char_T c3_cv[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i', 'n',
  'E', 'r', 'r', 'o', 'r' };

/* Function Declarations */
static void initialize_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance);
static void initialize_params_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void mdl_start_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance);
static void mdl_terminate_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance);
static void mdl_setup_runtime_resources_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void enable_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance);
static void disable_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance);
static void sf_gateway_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance);
static void c3_update_jit_animation_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void c3_do_animation_call_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void set_sim_state_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance, const mxArray *c3_st);
static void initSimStructsc3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance);
static void initSubchartIOPointersc3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void c3_ode45(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_y0[6], real_T
                     c3_varargout_1_data[], int32_T c3_varargout_1_size[1],
                     real_T c3_varargout_2_data[], int32_T c3_varargout_2_size[2]);
static void c3_check_forloop_overflow_error(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp);
static void c3_xgemv(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_alpha1, real_T c3_ib_A[42],
                     int32_T c3_ix0, real_T c3_y[6], real_T c3_b_y[6]);
static void c3_warning(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, char_T c3_varargin_1[23], char_T c3_varargin_2[23]);
static boolean_T c3_anyNonFinite(SFc3_starshotsim_devInstanceStruct
  *chartInstance, real_T c3_x[36]);
static void c3_schur(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_ib_A[36], real_T c3_V[36],
                     real_T c3_e_T[36]);
static real_T c3_xnrm2(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36], int32_T c3_ix0);
static real_T c3_sqrt(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
                      c3_x);
static void c3_xscal(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_a, real_T
                     c3_x[36], int32_T c3_ix0, real_T c3_b_x[36]);
static void c3_xzlarf(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_m, int32_T c3_b_n, int32_T
                      c3_iv0, real_T c3_tau, real_T c3_u_C[36], int32_T c3_ic0,
                      real_T c3_work[6], real_T c3_v_C[36], real_T c3_b_work[6]);
static void c3_xhseqr(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_h[36], real_T c3_z[36],
                      real_T c3_d_h[36], int32_T *c3_info, real_T c3_b_z[36]);
static void c3_xzlarfg(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_alpha1, real_T c3_x[3], real_T
  *c3_b_alpha1, real_T c3_b_x[3], real_T *c3_tau);
static real_T c3_b_xnrm2(SFc3_starshotsim_devInstanceStruct *chartInstance,
  int32_T c3_b_n, real_T c3_x[3]);
static void c3_xdlanv2(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
  c3_a, real_T c3_b, real_T c3_c, real_T c3_d, real_T *c3_rt1r, real_T *c3_rt1i,
  real_T *c3_rt2r, real_T *c3_rt2i, real_T *c3_b_a, real_T *c3_b_b, real_T
  *c3_b_c, real_T *c3_b_d, real_T *c3_cs, real_T *c3_sn);
static void c3_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36], int32_T
                    c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s, real_T
                    c3_b_x[36]);
static void c3_b_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36],
                      int32_T c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s,
                      real_T c3_b_x[36]);
static void c3_b_warning(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp);
static void c3_getExpmParams(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_ib_A[36], real_T c3_A2[36], real_T c3_A4[36],
  real_T c3_A6[36], int32_T *c3_m, real_T *c3_s);
static real_T c3_norm(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
                      c3_x[36]);
static void c3_mpower(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_a[36], real_T c3_b, real_T
                      c3_c[36]);
static void c3_c_warning(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp);
static real_T c3_log2(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
                      c3_x);
static void c3_padeApproximation(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_ib_A[36], real_T c3_A2[36],
  real_T c3_A4[36], real_T c3_A6[36], int32_T c3_m, real_T c3_d_F[36]);
static void c3_recomputeBlockDiag(SFc3_starshotsim_devInstanceStruct
  *chartInstance, real_T c3_ib_A[36], real_T c3_d_F[36], int32_T c3_blockFormat
  [5], real_T c3_e_F[36]);
static void c3_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_sprintf_, const char_T
  *c3_identifier, char_T c3_y[23]);
static void c3_b_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[23]);
static void c3_c_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_b_P_k1_k, const char_T *c3_identifier,
  real_T c3_y[36]);
static void c3_d_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[36]);
static void c3_e_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_b_X_k1_k, const char_T *c3_identifier,
  real_T c3_y[6]);
static void c3_f_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[6]);
static uint8_T c3_g_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_starshotsim_dev, const char_T
  *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers
  (SFc3_starshotsim_devInstanceStruct *chartInstance);
static void c3_chart_data_browse_helper(SFc3_starshotsim_devInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static const mxArray *c3_sprintf(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1);
static const mxArray *c3_feval(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1,
  const mxArray *c3_input2, const mxArray *c3_input3);
static void c3_b_feval(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1);
static const mxArray *c3_c_feval(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1);
static void c3_d_feval(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1);
static const mxArray *c3_e_feval(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1);
static void c3_f_feval(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1);
static void c3_b_xgemv(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_alpha1, real_T c3_ib_A[42], int32_T c3_ix0,
  real_T c3_y[6]);
static void c3_b_sqrt(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T *
                      c3_x);
static void c3_b_xscal(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_a, real_T c3_x[36], int32_T
  c3_ix0);
static void c3_b_xzlarf(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_m, int32_T c3_b_n, int32_T c3_iv0, real_T c3_tau,
  real_T c3_u_C[36], int32_T c3_ic0, real_T c3_work[6]);
static int32_T c3_b_xhseqr(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_h[36], real_T c3_z[36]);
static real_T c3_b_xzlarfg(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_b_n, real_T *c3_alpha1, real_T c3_x[3]);
static void c3_b_xdlanv2(SFc3_starshotsim_devInstanceStruct *chartInstance,
  real_T *c3_a, real_T *c3_b, real_T *c3_c, real_T *c3_d, real_T *c3_rt1r,
  real_T *c3_rt1i, real_T *c3_rt2r, real_T *c3_rt2i, real_T *c3_cs, real_T
  *c3_sn);
static void c3_c_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36],
                      int32_T c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s);
static void c3_d_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36],
                      int32_T c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s);
static void c3_b_recomputeBlockDiag(SFc3_starshotsim_devInstanceStruct
  *chartInstance, real_T c3_ib_A[36], real_T c3_d_F[36], int32_T c3_blockFormat
  [5]);
static int32_T c3_div_nzp_s32(SFc3_starshotsim_devInstanceStruct *chartInstance,
  int32_T c3_numerator, int32_T c3_denominator, int32_T c3_EMLOvCount_src_loc,
  uint32_T c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc);
static void init_dsm_address_info(SFc3_starshotsim_devInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_starshotsim_devInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_starshotsim_dev = 0U;
}

static void initialize_params_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
  real_T c3_b_dv[36];
  real_T c3_d;
  int32_T c3_i;
  sf_mex_import_named("dT", sf_mex_get_sfun_param(chartInstance->S, 1U, 0U),
                      &c3_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_dT = c3_d;
  sf_mex_import_named("Q", sf_mex_get_sfun_param(chartInstance->S, 0U, 0U),
                      c3_b_dv, 0, 0, 0U, 1, 0U, 2, 6, 6);
  for (c3_i = 0; c3_i < 36; c3_i++) {
    chartInstance->c3_Q[c3_i] = c3_b_dv[c3_i];
  }
}

static void mdl_start_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance)
{
}

static void mdl_setup_runtime_resources_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c3_chart_data_browse_helper);
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c3_RuntimeVar,
    &chartInstance->c3_IsDebuggerActive,
    &chartInstance->c3_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c3_mlFcnLineNumber, &chartInstance->c3_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c3_covrtInstance, 1U, 0U, 1U,
    26U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 2U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 400);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 1U,
                     "eML_blk_kernel_anonFcn1", 80, -1, 185);
}

static void mdl_cleanup_runtime_resources_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c3_sol_data[6006];
  real_T c3_a__1_data[1001];
  real_T c3_A2[36];
  real_T c3_A4[36];
  real_T c3_A6[36];
  real_T c3_Ad[36];
  real_T c3_b_Ad[36];
  real_T c3_c_y[36];
  real_T c3_e_y[36];
  real_T c3_y[36];
  real_T c3_b_dv[6];
  real_T c3_b;
  real_T c3_b_dT;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_b;
  real_T c3_c_x;
  real_T c3_d;
  real_T c3_d_b;
  real_T c3_d_j;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_b;
  real_T c3_e_x;
  real_T c3_exptj;
  real_T c3_f_b;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_g_b;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_h_b;
  real_T c3_h_i;
  real_T c3_j_b;
  real_T c3_k_b;
  real_T c3_m_b;
  real_T c3_o_b;
  real_T c3_p_b;
  real_T c3_q_b;
  real_T c3_r_b;
  real_T c3_s;
  real_T c3_s_b;
  real_T c3_t_b;
  real_T c3_u_b;
  real_T c3_x;
  int32_T c3_b_blockFormat[5];
  int32_T c3_blockFormat[5];
  int32_T c3_c_blockFormat[5];
  int32_T c3_sol_size[2];
  int32_T c3_a__1_size[1];
  int32_T c3_b_i;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_c_i;
  int32_T c3_c_j;
  int32_T c3_c_k;
  int32_T c3_d_i;
  int32_T c3_e_i;
  int32_T c3_e_j;
  int32_T c3_exitg1;
  int32_T c3_f_i;
  int32_T c3_f_j;
  int32_T c3_g_i;
  int32_T c3_g_j;
  int32_T c3_h_j;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_j;
  int32_T c3_j_i;
  int32_T c3_k;
  int32_T c3_m;
  int32_T c3_sol;
  boolean_T c3_b_b;
  boolean_T c3_b_p;
  boolean_T c3_exitg2;
  boolean_T c3_p;
  boolean_T c3_recomputeDiags;
  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c3_i = 0; c3_i < 36; c3_i++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U,
                      (*chartInstance->c3_P_k_k)[c3_i]);
  }

  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U,
                      (*chartInstance->c3_X_k_k)[c3_i1]);
  }

  for (c3_i2 = 0; c3_i2 < 36; c3_i2++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U,
                      (*chartInstance->c3_J_k_k)[c3_i2]);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_b_dT = chartInstance->c3_dT;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  c3_b_st.site = &c3_ig_emlrtRSI;
  for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
    c3_b_dv[c3_i3] = (*chartInstance->c3_X_k_k)[c3_i3];
  }

  c3_ode45(chartInstance, &c3_b_st, c3_b_dv, c3_a__1_data, c3_a__1_size,
           c3_sol_data, c3_sol_size);
  c3_b = c3_b_dT;
  for (c3_i4 = 0; c3_i4 < 36; c3_i4++) {
    c3_y[c3_i4] = (*chartInstance->c3_J_k_k)[c3_i4] * c3_b;
  }

  c3_b_st.site = &c3_jg_emlrtRSI;
  c3_c_st.site = &c3_ab_emlrtRSI;
  if (c3_anyNonFinite(chartInstance, c3_y)) {
    for (c3_i5 = 0; c3_i5 < 36; c3_i5++) {
      c3_Ad[c3_i5] = rtNaN;
    }
  } else {
    c3_p = true;
    c3_j = 1;
    c3_exitg2 = false;
    while ((!c3_exitg2) && (c3_j - 1 < 6)) {
      c3_b_j = c3_j;
      c3_b_i = 1;
      do {
        c3_exitg1 = 0;
        if (c3_b_i - 1 < 6) {
          c3_e_i = c3_b_i;
          if ((c3_e_i != c3_b_j) && (!(c3_y[(c3_e_i + 6 * (c3_b_j - 1)) - 1] ==
                0.0))) {
            c3_p = false;
            c3_exitg1 = 1;
          } else {
            c3_b_i++;
          }
        } else {
          c3_j++;
          c3_exitg1 = 2;
        }
      } while (c3_exitg1 == 0);

      if (c3_exitg1 == 1) {
        c3_exitg2 = true;
      }
    }

    if (c3_p) {
      for (c3_i6 = 0; c3_i6 < 36; c3_i6++) {
        c3_Ad[c3_i6] = 0.0;
      }

      for (c3_c_i = 0; c3_c_i < 6; c3_c_i++) {
        c3_d_i = c3_c_i;
        c3_x = c3_y[c3_d_i + 6 * c3_d_i];
        c3_b_x = c3_x;
        c3_b_x = muDoubleScalarExp(c3_b_x);
        c3_Ad[c3_d_i + 6 * c3_d_i] = c3_b_x;
      }
    } else {
      c3_b_p = true;
      c3_c_j = 0;
      c3_exitg2 = false;
      while ((!c3_exitg2) && (c3_c_j < 6)) {
        c3_d_j = static_cast<real_T>(c3_c_j) + 1.0;
        c3_i8 = static_cast<int32_T>(c3_d_j) - 1;
        c3_f_i = 0;
        do {
          c3_exitg1 = 0;
          if (c3_f_i <= c3_i8) {
            c3_h_i = static_cast<real_T>(c3_f_i) + 1.0;
            if (!(c3_y[(static_cast<int32_T>(c3_h_i) + 6 * (static_cast<int32_T>
                   (c3_d_j) - 1)) - 1] == c3_y[(static_cast<int32_T>(c3_d_j) + 6
                  * (static_cast<int32_T>(c3_h_i) - 1)) - 1])) {
              c3_b_p = false;
              c3_exitg1 = 1;
            } else {
              c3_f_i++;
            }
          } else {
            c3_c_j++;
            c3_exitg1 = 2;
          }
        } while (c3_exitg1 == 0);

        if (c3_exitg1 == 1) {
          c3_exitg2 = true;
        }
      }

      if (c3_b_p) {
        c3_c_st.site = &c3_jb_emlrtRSI;
        c3_schur(chartInstance, &c3_c_st, c3_y, c3_A2, c3_A4);
        for (c3_f_j = 0; c3_f_j < 6; c3_f_j++) {
          c3_g_j = c3_f_j;
          c3_c_x = c3_A4[c3_g_j + 6 * c3_g_j];
          c3_exptj = c3_c_x;
          c3_exptj = muDoubleScalarExp(c3_exptj);
          for (c3_j_i = 0; c3_j_i < 6; c3_j_i++) {
            c3_d_i = c3_j_i;
            c3_Ad[c3_d_i + 6 * c3_g_j] = c3_A2[c3_d_i + 6 * c3_g_j] * c3_exptj;
          }
        }

        for (c3_i11 = 0; c3_i11 < 36; c3_i11++) {
          c3_y[c3_i11] = c3_Ad[c3_i11];
        }

        for (c3_i15 = 0; c3_i15 < 6; c3_i15++) {
          c3_i20 = 0;
          for (c3_i23 = 0; c3_i23 < 6; c3_i23++) {
            c3_Ad[c3_i20 + c3_i15] = 0.0;
            c3_i33 = 0;
            for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
              c3_Ad[c3_i20 + c3_i15] += c3_y[c3_i33 + c3_i15] * c3_A2[c3_i33 +
                c3_i23];
              c3_i33 += 6;
            }

            c3_i20 += 6;
          }
        }

        c3_i19 = 0;
        for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
          c3_i29 = 0;
          for (c3_i32 = 0; c3_i32 < 6; c3_i32++) {
            c3_b_Ad[c3_i32 + c3_i19] = (c3_Ad[c3_i32 + c3_i19] + c3_Ad[c3_i29 +
              c3_i22]) / 2.0;
            c3_i29 += 6;
          }

          c3_i19 += 6;
        }

        for (c3_i28 = 0; c3_i28 < 36; c3_i28++) {
          c3_Ad[c3_i28] = c3_b_Ad[c3_i28];
        }
      } else {
        c3_recomputeDiags = true;
        c3_e_j = 3;
        while (c3_recomputeDiags && (c3_e_j <= 6)) {
          c3_g_i = c3_e_j;
          while (c3_recomputeDiags && (c3_g_i <= 6)) {
            c3_b_b = (c3_y[(c3_g_i + 6 * (c3_e_j - 3)) - 1] == 0.0);
            c3_recomputeDiags = c3_b_b;
            c3_g_i++;
          }

          c3_e_j++;
        }

        if (c3_recomputeDiags) {
          c3_k = 1;
          c3_exitg2 = false;
          while ((!c3_exitg2) && (c3_k - 1 < 5)) {
            c3_b_k = c3_k;
            if (c3_y[c3_b_k + 6 * (c3_b_k - 1)] != 0.0) {
              if ((c3_b_k != 5) && (c3_y[(c3_b_k + 6 * c3_b_k) + 1] != 0.0)) {
                c3_recomputeDiags = false;
                c3_exitg2 = true;
              } else if (c3_y[(c3_b_k + 6 * (c3_b_k - 1)) - 1] != c3_y[c3_b_k +
                         6 * c3_b_k]) {
                c3_recomputeDiags = false;
                c3_exitg2 = true;
              } else {
                c3_d_x = c3_y[c3_b_k + 6 * (c3_b_k - 1)];
                c3_e_x = c3_d_x;
                c3_e_x = muDoubleScalarSign(c3_e_x);
                c3_f_x = c3_y[(c3_b_k + 6 * c3_b_k) - 1];
                c3_g_x = c3_f_x;
                c3_g_x = muDoubleScalarSign(c3_g_x);
                if (c3_e_x * c3_g_x != -1.0) {
                  c3_recomputeDiags = false;
                  c3_exitg2 = true;
                } else {
                  c3_k++;
                }
              }
            } else {
              c3_k++;
            }
          }
        }

        c3_c_st.site = &c3_bb_emlrtRSI;
        c3_getExpmParams(chartInstance, &c3_c_st, c3_y, c3_A2, c3_A4, c3_A6,
                         &c3_m, &c3_s);
        if (c3_s != 0.0) {
          c3_c_st.site = &c3_cb_emlrtRSI;
          c3_c_b = c3_s;
          c3_d_b = c3_c_b;
          c3_e_b = c3_d_b;
          c3_f_b = c3_e_b;
          c3_b_y = muDoubleScalarPower(2.0, c3_f_b);
          for (c3_i36 = 0; c3_i36 < 36; c3_i36++) {
            c3_y[c3_i36] /= c3_b_y;
          }

          c3_c_st.site = &c3_db_emlrtRSI;
          c3_g_b = 2.0 * c3_s;
          c3_h_b = c3_g_b;
          c3_j_b = c3_h_b;
          c3_k_b = c3_j_b;
          c3_d_y = muDoubleScalarPower(2.0, c3_k_b);
          for (c3_i42 = 0; c3_i42 < 36; c3_i42++) {
            c3_A2[c3_i42] /= c3_d_y;
          }

          c3_c_st.site = &c3_eb_emlrtRSI;
          c3_m_b = 4.0 * c3_s;
          c3_o_b = c3_m_b;
          c3_p_b = c3_o_b;
          c3_q_b = c3_p_b;
          c3_f_y = muDoubleScalarPower(2.0, c3_q_b);
          for (c3_i50 = 0; c3_i50 < 36; c3_i50++) {
            c3_A4[c3_i50] /= c3_f_y;
          }

          c3_c_st.site = &c3_fb_emlrtRSI;
          c3_r_b = 6.0 * c3_s;
          c3_s_b = c3_r_b;
          c3_t_b = c3_s_b;
          c3_u_b = c3_t_b;
          c3_g_y = muDoubleScalarPower(2.0, c3_u_b);
          for (c3_i51 = 0; c3_i51 < 36; c3_i51++) {
            c3_A6[c3_i51] /= c3_g_y;
          }
        }

        if (c3_recomputeDiags) {
          for (c3_i27 = 0; c3_i27 < 5; c3_i27++) {
            c3_blockFormat[c3_i27] = 0;
          }

          c3_h_j = 0;
          while (c3_h_j + 1 < 5) {
            if (c3_y[(c3_h_j + 6 * c3_h_j) + 1] != 0.0) {
              for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
                c3_blockFormat[c3_i39 + c3_h_j] = 2 + -2 * c3_i39;
              }

              c3_h_j += 2;
            } else if ((c3_y[(c3_h_j + 6 * c3_h_j) + 1] == 0.0) && (c3_y[(c3_h_j
              + 6 * (c3_h_j + 1)) + 2] == 0.0)) {
              c3_blockFormat[c3_h_j] = 1;
              c3_h_j++;
            } else {
              c3_blockFormat[c3_h_j] = 0;
              c3_h_j++;
            }
          }

          if (c3_y[29] != 0.0) {
            c3_blockFormat[4] = 2;
          } else if ((c3_blockFormat[3] == 0) || (c3_blockFormat[3] == 1)) {
            c3_blockFormat[4] = 1;
          }
        }

        c3_c_st.site = &c3_gb_emlrtRSI;
        c3_padeApproximation(chartInstance, &c3_c_st, c3_y, c3_A2, c3_A4, c3_A6,
                             c3_m, c3_Ad);
        if (c3_recomputeDiags) {
          for (c3_i35 = 0; c3_i35 < 36; c3_i35++) {
            c3_c_y[c3_i35] = c3_y[c3_i35];
          }

          for (c3_i38 = 0; c3_i38 < 5; c3_i38++) {
            c3_b_blockFormat[c3_i38] = c3_blockFormat[c3_i38];
          }

          c3_b_recomputeBlockDiag(chartInstance, c3_c_y, c3_Ad, c3_b_blockFormat);
        }

        c3_i37 = static_cast<int32_T>(c3_s);
        emlrtForLoopVectorCheckR2021a(1.0, 1.0, c3_s, mxDOUBLE_CLASS, c3_i37,
          &c3_d_emlrtRTEI, &c3_b_st);
        for (c3_c_k = 0; c3_c_k < c3_i37; c3_c_k++) {
          for (c3_i40 = 0; c3_i40 < 36; c3_i40++) {
            c3_A2[c3_i40] = c3_Ad[c3_i40];
          }

          for (c3_i41 = 0; c3_i41 < 6; c3_i41++) {
            c3_i43 = 0;
            for (c3_i45 = 0; c3_i45 < 6; c3_i45++) {
              c3_Ad[c3_i43 + c3_i41] = 0.0;
              c3_i47 = 0;
              for (c3_i49 = 0; c3_i49 < 6; c3_i49++) {
                c3_Ad[c3_i43 + c3_i41] += c3_A2[c3_i47 + c3_i41] * c3_A2[c3_i49
                  + c3_i43];
                c3_i47 += 6;
              }

              c3_i43 += 6;
            }
          }

          if (c3_recomputeDiags) {
            for (c3_i44 = 0; c3_i44 < 36; c3_i44++) {
              c3_y[c3_i44] *= 2.0;
            }

            for (c3_i46 = 0; c3_i46 < 36; c3_i46++) {
              c3_e_y[c3_i46] = c3_y[c3_i46];
            }

            for (c3_i48 = 0; c3_i48 < 5; c3_i48++) {
              c3_c_blockFormat[c3_i48] = c3_blockFormat[c3_i48];
            }

            c3_b_recomputeBlockDiag(chartInstance, c3_e_y, c3_Ad,
              c3_c_blockFormat);
          }
        }
      }
    }
  }

  if (c3_sol_size[0] < 0) {
    emlrtDynamicBoundsCheckR2012b(c3_sol_size[0], 0, MAX_int32_T, &c3_emlrtBCI,
      &c3_st);
  }

  c3_d = static_cast<real_T>(c3_sol_size[0]);
  if (c3_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor(c3_d))))
  {
    emlrtIntegerCheckR2012b(c3_d, &c3_emlrtDCI, &c3_st);
  }

  c3_i7 = static_cast<int32_T>(c3_d);
  if ((c3_i7 < 1) || (c3_i7 > c3_sol_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c3_i7, 1, c3_sol_size[0], &c3_b_emlrtBCI,
      &c3_st);
  }

  c3_sol = c3_i7 - 1;
  for (c3_i9 = 0; c3_i9 < 6; c3_i9++) {
    (*chartInstance->c3_X_k1_k)[c3_i9] = c3_sol_data[c3_sol + c3_sol_size[0] *
      c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 6; c3_i10++) {
    c3_i13 = 0;
    for (c3_i14 = 0; c3_i14 < 6; c3_i14++) {
      c3_y[c3_i13 + c3_i10] = 0.0;
      c3_i21 = 0;
      for (c3_i25 = 0; c3_i25 < 6; c3_i25++) {
        c3_y[c3_i13 + c3_i10] += c3_Ad[c3_i21 + c3_i10] *
          (*chartInstance->c3_P_k_k)[c3_i25 + c3_i13];
        c3_i21 += 6;
      }

      c3_i13 += 6;
    }
  }

  for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
    c3_i17 = 0;
    for (c3_i18 = 0; c3_i18 < 6; c3_i18++) {
      (*chartInstance->c3_P_k1_k)[c3_i17 + c3_i12] = 0.0;
      c3_i26 = 0;
      for (c3_i31 = 0; c3_i31 < 6; c3_i31++) {
        (*chartInstance->c3_P_k1_k)[c3_i17 + c3_i12] += c3_y[c3_i26 + c3_i12] *
          c3_Ad[c3_i26 + c3_i18];
        c3_i26 += 6;
      }

      c3_i17 += 6;
    }
  }

  for (c3_i16 = 0; c3_i16 < 36; c3_i16++) {
    (*chartInstance->c3_P_k1_k)[c3_i16] += chartInstance->c3_Q[c3_i16];
  }

  c3_do_animation_call_c3_starshotsim_dev(chartInstance);
  for (c3_i24 = 0; c3_i24 < 6; c3_i24++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 3U,
                      (*chartInstance->c3_X_k1_k)[c3_i24]);
  }

  for (c3_i30 = 0; c3_i30 < 36; c3_i30++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                      (*chartInstance->c3_P_k1_k)[c3_i30]);
  }
}

static void ext_mode_exec_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance)
{
}

static void c3_update_jit_animation_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
}

static void c3_do_animation_call_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(3, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_P_k1_k, 0, 0U, 1U,
    0U, 2, 6, 6), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", *chartInstance->c3_X_k1_k, 0, 0U, 1U,
    0U, 1, 6), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_starshotsim_dev, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_b_dv[36];
  real_T c3_dv1[6];
  int32_T c3_i;
  int32_T c3_i1;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "P_k1_k", c3_b_dv);
  for (c3_i = 0; c3_i < 36; c3_i++) {
    (*chartInstance->c3_P_k1_k)[c3_i] = c3_b_dv[c3_i];
  }

  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "X_k1_k", c3_dv1);
  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    (*chartInstance->c3_X_k1_k)[c3_i1] = c3_dv1[c3_i1];
  }

  chartInstance->c3_is_active_c3_starshotsim_dev = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_starshotsim_dev");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void initSimStructsc3_starshotsim_dev(SFc3_starshotsim_devInstanceStruct *
  chartInstance)
{
}

static void initSubchartIOPointersc3_starshotsim_dev
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
}

static void c3_ode45(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_y0[6], real_T
                     c3_varargout_1_data[], int32_T c3_varargout_1_size[1],
                     real_T c3_varargout_2_data[], int32_T c3_varargout_2_size[2])
{
  static real_T c3_b_dv[1001] = { 0.0, 0.0001, 0.0002, 0.00030000000000000003,
    0.0004, 0.0005, 0.00060000000000000006, 0.0007, 0.0008,
    0.00090000000000000008, 0.001, 0.0011, 0.0012000000000000001,
    0.0013000000000000002, 0.0014, 0.0015, 0.0016, 0.0017000000000000001,
    0.0018000000000000002, 0.0019, 0.002, 0.0021000000000000003, 0.0022, 0.0023,
    0.0024000000000000002, 0.0025, 0.0026000000000000003, 0.0027, 0.0028,
    0.0029000000000000002, 0.003, 0.0031000000000000003, 0.0032, 0.0033,
    0.0034000000000000002, 0.0035, 0.0036000000000000003, 0.0037, 0.0038,
    0.0039000000000000003, 0.004, 0.0041, 0.0042000000000000006, 0.0043, 0.0044,
    0.0045000000000000005, 0.0046, 0.0047, 0.0048000000000000004, 0.0049, 0.005,
    0.0051, 0.0052000000000000006, 0.0053, 0.0054, 0.0055000000000000005, 0.0056,
    0.0057, 0.0058000000000000005, 0.0059, 0.006, 0.0061, 0.0062000000000000006,
    0.0063, 0.0064, 0.0065000000000000006, 0.0066, 0.0067, 0.0068000000000000005,
    0.0069000000000000008, 0.007, 0.0071, 0.0072000000000000007, 0.0073, 0.0074,
    0.0075000000000000006, 0.0076, 0.0077, 0.0078000000000000005, 0.0079, 0.008,
    0.0081, 0.0082, 0.0083, 0.0084000000000000012, 0.0085, 0.0086,
    0.0087000000000000011, 0.0088, 0.0089, 0.0090000000000000011, 0.0091, 0.0092,
    0.009300000000000001, 0.0094, 0.0095, 0.0096000000000000009, 0.0097, 0.0098,
    0.0099, 0.01, 0.010100000000000001, 0.0102, 0.0103, 0.010400000000000001,
    0.0105, 0.0106, 0.010700000000000001, 0.0108, 0.0109, 0.011000000000000001,
    0.0111, 0.0112, 0.011300000000000001, 0.0114, 0.0115, 0.011600000000000001,
    0.0117, 0.0118, 0.0119, 0.012, 0.012100000000000001, 0.0122, 0.0123,
    0.012400000000000001, 0.0125, 0.0126, 0.012700000000000001, 0.0128, 0.0129,
    0.013000000000000001, 0.0131, 0.0132, 0.013300000000000001, 0.0134, 0.0135,
    0.013600000000000001, 0.0137, 0.013800000000000002, 0.013900000000000001,
    0.014, 0.014100000000000001, 0.0142, 0.0143, 0.014400000000000001, 0.0145,
    0.0146, 0.014700000000000001, 0.0148, 0.0149, 0.015000000000000001, 0.0151,
    0.0152, 0.015300000000000001, 0.0154, 0.0155, 0.015600000000000001,
    0.015700000000000002, 0.0158, 0.0159, 0.016, 0.0161, 0.0162,
    0.016300000000000002, 0.0164, 0.0165, 0.0166, 0.0167, 0.016800000000000002,
    0.016900000000000002, 0.017, 0.0171, 0.0172, 0.0173, 0.017400000000000002,
    0.0175, 0.0176, 0.0177, 0.0178, 0.0179, 0.018000000000000002, 0.0181, 0.0182,
    0.0183, 0.0184, 0.018500000000000003, 0.018600000000000002, 0.0187, 0.0188,
    0.0189, 0.019, 0.019100000000000002, 0.019200000000000002, 0.0193, 0.0194,
    0.0195, 0.0196, 0.019700000000000002, 0.0198, 0.0199, 0.02, 0.0201,
    0.020200000000000003, 0.020300000000000002, 0.0204, 0.0205, 0.0206, 0.0207,
    0.020800000000000003, 0.020900000000000002, 0.021, 0.0211, 0.0212, 0.0213,
    0.021400000000000002, 0.021500000000000002, 0.0216, 0.0217, 0.0218, 0.0219,
    0.022000000000000002, 0.0221, 0.0222, 0.0223, 0.0224, 0.022500000000000003,
    0.022600000000000002, 0.0227, 0.0228, 0.0229, 0.023, 0.023100000000000002,
    0.023200000000000002, 0.0233, 0.0234, 0.0235, 0.0236, 0.023700000000000002,
    0.0238, 0.0239, 0.024, 0.0241, 0.024200000000000003, 0.024300000000000002,
    0.0244, 0.0245, 0.0246, 0.0247, 0.024800000000000003, 0.024900000000000002,
    0.025, 0.0251, 0.0252, 0.0253, 0.025400000000000002, 0.025500000000000002,
    0.0256, 0.0257, 0.0258, 0.025900000000000003, 0.026000000000000002, 0.0261,
    0.0262, 0.0263, 0.0264, 0.026500000000000003, 0.026600000000000002, 0.0267,
    0.0268, 0.0269, 0.027, 0.027100000000000003, 0.027200000000000002, 0.0273,
    0.0274, 0.0275, 0.027600000000000003, 0.027700000000000002,
    0.027800000000000002, 0.0279, 0.028, 0.0281, 0.028200000000000003,
    0.028300000000000002, 0.0284, 0.0285, 0.0286, 0.0287, 0.028800000000000003,
    0.028900000000000002, 0.029, 0.0291, 0.0292, 0.029300000000000003,
    0.029400000000000003, 0.029500000000000002, 0.0296, 0.0297, 0.0298,
    0.029900000000000003, 0.030000000000000002, 0.030100000000000002, 0.0302,
    0.0303, 0.0304, 0.030500000000000003, 0.030600000000000002, 0.0307, 0.0308,
    0.0309, 0.031, 0.031100000000000003, 0.031200000000000002, 0.0313,
    0.031400000000000004, 0.0315, 0.0316, 0.0317, 0.0318, 0.031900000000000005,
    0.032, 0.032100000000000004, 0.0322, 0.0323, 0.0324, 0.0325,
    0.032600000000000004, 0.0327, 0.0328, 0.0329, 0.033, 0.033100000000000004,
    0.0332, 0.0333, 0.0334, 0.0335, 0.033600000000000005, 0.0337,
    0.033800000000000004, 0.0339, 0.034, 0.0341, 0.0342, 0.034300000000000004,
    0.0344, 0.0345, 0.0346, 0.0347, 0.034800000000000005, 0.0349, 0.035, 0.0351,
    0.0352, 0.035300000000000005, 0.0354, 0.035500000000000004, 0.0356, 0.0357,
    0.0358, 0.0359, 0.036000000000000004, 0.0361, 0.0362, 0.0363, 0.0364,
    0.036500000000000005, 0.0366, 0.0367, 0.0368, 0.0369, 0.037000000000000005,
    0.0371, 0.037200000000000004, 0.0373, 0.0374, 0.0375, 0.0376,
    0.037700000000000004, 0.0378, 0.0379, 0.038, 0.0381, 0.038200000000000005,
    0.0383, 0.038400000000000004, 0.0385, 0.0386, 0.038700000000000005, 0.0388,
    0.038900000000000004, 0.039, 0.0391, 0.0392, 0.0393, 0.039400000000000004,
    0.0395, 0.0396, 0.0397, 0.0398, 0.039900000000000005, 0.04,
    0.040100000000000004, 0.0402, 0.0403, 0.040400000000000005, 0.0405,
    0.040600000000000004, 0.0407, 0.0408, 0.0409, 0.041, 0.041100000000000005,
    0.0412, 0.0413, 0.0414, 0.0415, 0.041600000000000005, 0.0417,
    0.041800000000000004, 0.0419, 0.042, 0.042100000000000005, 0.0422,
    0.042300000000000004, 0.0424, 0.0425, 0.0426, 0.0427, 0.042800000000000005,
    0.0429, 0.043000000000000003, 0.0431, 0.0432, 0.043300000000000005, 0.0434,
    0.043500000000000004, 0.0436, 0.0437, 0.0438, 0.0439, 0.044000000000000004,
    0.0441, 0.0442, 0.0443, 0.0444, 0.044500000000000005, 0.0446,
    0.044700000000000004, 0.0448, 0.0449, 0.045000000000000005, 0.0451,
    0.045200000000000004, 0.0453, 0.0454, 0.0455, 0.0456, 0.045700000000000005,
    0.0458, 0.0459, 0.046, 0.0461, 0.046200000000000005, 0.0463,
    0.046400000000000004, 0.0465, 0.0466, 0.046700000000000005, 0.0468,
    0.046900000000000004, 0.047, 0.0471, 0.0472, 0.0473, 0.047400000000000005,
    0.0475, 0.0476, 0.0477, 0.0478, 0.047900000000000005, 0.048,
    0.048100000000000004, 0.0482, 0.0483, 0.048400000000000006, 0.0485,
    0.048600000000000004, 0.0487, 0.0488, 0.0489, 0.049, 0.049100000000000005,
    0.0492, 0.049300000000000004, 0.0494, 0.0495, 0.049600000000000005, 0.0497,
    0.049800000000000004, 0.0499, 0.05, 0.050100000000000006, 0.0502,
    0.050300000000000004, 0.0504, 0.0505, 0.050600000000000006, 0.0507,
    0.050800000000000005, 0.0509, 0.051000000000000004, 0.051100000000000007,
    0.0512, 0.051300000000000005, 0.0514, 0.051500000000000004, 0.0516, 0.0517,
    0.051800000000000006, 0.0519, 0.052000000000000005, 0.0521, 0.0522,
    0.052300000000000006, 0.0524, 0.052500000000000005, 0.0526,
    0.052700000000000004, 0.052800000000000007, 0.0529, 0.053000000000000005,
    0.0531, 0.053200000000000004, 0.0533, 0.0534, 0.053500000000000006, 0.0536,
    0.053700000000000005, 0.0538, 0.0539, 0.054000000000000006, 0.0541,
    0.054200000000000005, 0.0543, 0.054400000000000004, 0.054500000000000007,
    0.0546, 0.054700000000000006, 0.0548, 0.054900000000000004, 0.055, 0.0551,
    0.055200000000000006, 0.0553, 0.055400000000000005, 0.0555,
    0.055600000000000004, 0.055700000000000006, 0.0558, 0.055900000000000005,
    0.056, 0.056100000000000004, 0.056200000000000007, 0.0563,
    0.056400000000000006, 0.0565, 0.056600000000000004, 0.0567, 0.0568,
    0.056900000000000006, 0.057, 0.057100000000000005, 0.0572,
    0.057300000000000004, 0.057400000000000007, 0.0575, 0.057600000000000005,
    0.0577, 0.057800000000000004, 0.0579, 0.058, 0.058100000000000006, 0.0582,
    0.058300000000000005, 0.0584, 0.0585, 0.058600000000000006, 0.0587,
    0.058800000000000005, 0.0589, 0.059000000000000004, 0.059100000000000007,
    0.0592, 0.059300000000000005, 0.0594, 0.059500000000000004, 0.0596, 0.0597,
    0.059800000000000006, 0.0599, 0.060000000000000005, 0.0601,
    0.060200000000000004, 0.060300000000000006, 0.0604, 0.060500000000000005,
    0.0606, 0.060700000000000004, 0.060800000000000007, 0.0609,
    0.061000000000000006, 0.0611, 0.061200000000000004, 0.0613, 0.0614,
    0.061500000000000006, 0.0616, 0.061700000000000005, 0.0618,
    0.061900000000000004, 0.062000000000000006, 0.0621, 0.062200000000000005,
    0.0623, 0.062400000000000004, 0.0625, 0.0626, 0.0627, 0.0628,
    0.062900000000000011, 0.063, 0.0631, 0.0632, 0.0633, 0.063400000000000012,
    0.0635, 0.0636, 0.0637, 0.0638, 0.063900000000000012, 0.064, 0.0641,
    0.064200000000000007, 0.0643, 0.064400000000000013, 0.0645, 0.0646,
    0.064700000000000008, 0.0648, 0.064900000000000013, 0.065, 0.0651,
    0.065200000000000008, 0.0653, 0.065400000000000014, 0.0655, 0.0656,
    0.065700000000000008, 0.0658, 0.065900000000000014, 0.066, 0.0661,
    0.066200000000000009, 0.0663, 0.0664, 0.0665, 0.0666, 0.066700000000000009,
    0.0668, 0.0669, 0.067, 0.0671, 0.06720000000000001, 0.0673, 0.0674, 0.0675,
    0.067600000000000007, 0.06770000000000001, 0.0678, 0.0679, 0.068, 0.0681,
    0.068200000000000011, 0.0683, 0.0684, 0.0685, 0.0686, 0.068700000000000011,
    0.0688, 0.0689, 0.069, 0.069100000000000009, 0.069200000000000012, 0.0693,
    0.0694, 0.0695, 0.069600000000000009, 0.069700000000000012, 0.0698, 0.0699,
    0.07, 0.0701, 0.070200000000000012, 0.0703, 0.0704, 0.070500000000000007,
    0.0706, 0.0707, 0.0708, 0.0709, 0.071000000000000008, 0.0711, 0.0712, 0.0713,
    0.0714, 0.071500000000000008, 0.0716, 0.0717, 0.0718, 0.0719,
    0.072000000000000008, 0.0721, 0.0722, 0.0723, 0.0724, 0.072500000000000009,
    0.0726, 0.0727, 0.0728, 0.0729, 0.073000000000000009, 0.0731, 0.0732, 0.0733,
    0.0734, 0.07350000000000001, 0.0736, 0.0737, 0.0738, 0.073900000000000007,
    0.07400000000000001, 0.0741, 0.0742, 0.0743, 0.074400000000000008,
    0.074500000000000011, 0.0746, 0.0747, 0.0748, 0.074900000000000008,
    0.075000000000000011, 0.0751, 0.0752, 0.0753, 0.075400000000000009,
    0.075500000000000012, 0.0756, 0.0757, 0.0758, 0.075900000000000009,
    0.076000000000000012, 0.0761, 0.0762, 0.0763, 0.07640000000000001,
    0.076500000000000012, 0.0766, 0.0767, 0.076800000000000007, 0.0769,
    0.077000000000000013, 0.0771, 0.0772, 0.077300000000000008, 0.0774, 0.0775,
    0.0776, 0.0777, 0.077800000000000008, 0.0779, 0.078, 0.0781, 0.0782,
    0.078300000000000008, 0.0784, 0.0785, 0.0786, 0.0787, 0.078800000000000009,
    0.0789, 0.079, 0.0791, 0.0792, 0.079300000000000009, 0.0794, 0.0795, 0.0796,
    0.079700000000000007, 0.07980000000000001, 0.0799, 0.08, 0.0801,
    0.080200000000000007, 0.08030000000000001, 0.0804, 0.0805, 0.0806,
    0.080700000000000008, 0.080800000000000011, 0.0809, 0.081, 0.0811,
    0.081200000000000008, 0.081300000000000011, 0.0814, 0.0815, 0.0816,
    0.081700000000000009, 0.081800000000000012, 0.0819, 0.082, 0.0821,
    0.082200000000000009, 0.082300000000000012, 0.0824, 0.0825, 0.0826,
    0.08270000000000001, 0.082800000000000012, 0.0829, 0.083,
    0.083100000000000007, 0.0832, 0.083300000000000013, 0.0834, 0.0835,
    0.083600000000000008, 0.0837, 0.083800000000000013, 0.0839, 0.084,
    0.084100000000000008, 0.0842, 0.0843, 0.0844, 0.0845, 0.084600000000000009,
    0.0847, 0.0848, 0.0849, 0.085, 0.085100000000000009, 0.0852, 0.0853, 0.0854,
    0.0855, 0.085600000000000009, 0.0857, 0.0858, 0.0859, 0.086000000000000007,
    0.08610000000000001, 0.0862, 0.0863, 0.0864, 0.086500000000000007,
    0.08660000000000001, 0.0867, 0.0868, 0.0869, 0.087000000000000008,
    0.087100000000000011, 0.0872, 0.0873, 0.0874, 0.087500000000000008,
    0.087600000000000011, 0.0877, 0.0878, 0.0879, 0.088000000000000009,
    0.088100000000000012, 0.0882, 0.0883, 0.0884, 0.088500000000000009,
    0.088600000000000012, 0.0887, 0.0888, 0.0889, 0.08900000000000001,
    0.089100000000000013, 0.0892, 0.0893, 0.089400000000000007,
    0.08950000000000001, 0.0896, 0.0897, 0.0898, 0.089900000000000008,
    0.090000000000000011, 0.0901, 0.0902, 0.0903, 0.090400000000000008,
    0.090500000000000011, 0.0906, 0.0907, 0.0908, 0.090900000000000009, 0.091,
    0.0911, 0.0912, 0.0913, 0.091400000000000009, 0.0915, 0.0916, 0.0917, 0.0918,
    0.091900000000000009, 0.092, 0.0921, 0.0922, 0.092300000000000007,
    0.09240000000000001, 0.0925, 0.0926, 0.0927, 0.092800000000000007,
    0.09290000000000001, 0.093, 0.0931, 0.0932, 0.093300000000000008,
    0.093400000000000011, 0.0935, 0.0936, 0.0937, 0.093800000000000008,
    0.093900000000000011, 0.094, 0.0941, 0.0942, 0.094300000000000009,
    0.094400000000000012, 0.0945, 0.0946, 0.0947, 0.094800000000000009,
    0.094900000000000012, 0.095, 0.0951, 0.0952, 0.09530000000000001,
    0.095400000000000013, 0.0955, 0.0956, 0.095700000000000007,
    0.09580000000000001, 0.0959, 0.096, 0.0961, 0.096200000000000008,
    0.096300000000000011, 0.0964, 0.0965, 0.0966, 0.096700000000000008,
    0.096800000000000011, 0.0969, 0.097, 0.0971, 0.097200000000000009,
    0.097300000000000011, 0.0974, 0.0975, 0.0976, 0.097700000000000009,
    0.097800000000000012, 0.0979, 0.098, 0.0981, 0.09820000000000001, 0.0983,
    0.0984, 0.0985, 0.098600000000000007, 0.09870000000000001, 0.0988, 0.0989,
    0.099, 0.099100000000000008, 0.09920000000000001, 0.0993, 0.0994, 0.0995,
    0.099600000000000008, 0.099700000000000011, 0.0998, 0.0999, 0.1 };

  static real_T c3_h_b[7] = { 0.0012326388888888888, 0.0, -0.0042527702905061394,
    0.036979166666666667, -0.05086379716981132, 0.0419047619047619, -0.025 };

  static real_T c3_t_b[7] = { -2.859375, 0.0, 4.0431266846361185, -3.90625,
    2.7939268867924527, -1.5714285714285714, 1.5 };

  static real_T c3_u_b[7] = { 3.0833333333333335, 0.0, -6.2893081761006293,
    10.416666666666666, -6.8773584905660377, 3.6666666666666665, -4.0 };

  static real_T c3_v_b[7] = { -1.1328125, 0.0, 2.6954177897574123, -5.859375,
    3.7610554245283021, -1.9642857142857142, 2.5 };

  static char_T c3_rfmt[7] = { '%', '2', '3', '.', '1', '5', 'e' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_st;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_m_y = NULL;
  const mxArray *c3_o_y = NULL;
  real_T c3_yout[6006];
  real_T c3_tout[1001];
  real_T c3_b_f[42];
  real_T c3_f[42];
  real_T c3_p_y[7];
  real_T c3_c_f[6];
  real_T c3_c_y[6];
  real_T c3_f0[6];
  real_T c3_fhBI2[6];
  real_T c3_fhBI4[6];
  real_T c3_ynew[6];
  real_T c3_ystage[6];
  real_T c3_ab_a;
  real_T c3_ab_x;
  real_T c3_absh;
  real_T c3_absx;
  real_T c3_alpha1;
  real_T c3_b_absx;
  real_T c3_b_alpha1;
  real_T c3_b_c;
  real_T c3_b_d1;
  real_T c3_b_ex;
  real_T c3_b_rh;
  real_T c3_b_s;
  real_T c3_b_t;
  real_T c3_b_t0;
  real_T c3_b_tnew;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_bb_a;
  real_T c3_bb_x;
  real_T c3_c_c;
  real_T c3_c_t;
  real_T c3_c_x;
  real_T c3_cb_a;
  real_T c3_cb_x;
  real_T c3_d2;
  real_T c3_d_c;
  real_T c3_d_h;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_db_a;
  real_T c3_db_x;
  real_T c3_e_a;
  real_T c3_e_h;
  real_T c3_e_x;
  real_T c3_eb_a;
  real_T c3_eb_x;
  real_T c3_err;
  real_T c3_errk;
  real_T c3_f_a;
  real_T c3_f_k;
  real_T c3_f_x;
  real_T c3_fb_a;
  real_T c3_fb_x;
  real_T c3_g_a;
  real_T c3_g_x;
  real_T c3_gb_a;
  real_T c3_gb_x;
  real_T c3_h;
  real_T c3_h_x;
  real_T c3_hb_a;
  real_T c3_hb_x;
  real_T c3_hmin;
  real_T c3_i_x;
  real_T c3_ib_x;
  real_T c3_j_a;
  real_T c3_j_x;
  real_T c3_jb_x;
  real_T c3_k_x;
  real_T c3_kb_x;
  real_T c3_m_a;
  real_T c3_m_x;
  real_T c3_mb_x;
  real_T c3_mxerr;
  real_T c3_num;
  real_T c3_o_a;
  real_T c3_o_x;
  real_T c3_ob_x;
  real_T c3_p_x;
  real_T c3_q_a;
  real_T c3_q_x;
  real_T c3_r;
  real_T c3_r_b;
  real_T c3_r_x;
  real_T c3_s;
  real_T c3_s_a;
  real_T c3_s_b;
  real_T c3_s_x;
  real_T c3_t;
  real_T c3_t0;
  real_T c3_t_a;
  real_T c3_t_x;
  real_T c3_temp;
  real_T c3_tnew;
  real_T c3_u_a;
  real_T c3_u_x;
  real_T c3_v_a;
  real_T c3_v_x;
  real_T c3_w_a;
  real_T c3_w_x;
  real_T c3_x;
  real_T c3_x_a;
  real_T c3_x_x;
  real_T c3_y;
  real_T c3_y_a;
  real_T c3_y_x;
  int32_T c3_Bcolidx;
  int32_T c3_a;
  int32_T c3_b_a;
  int32_T c3_b_exponent;
  int32_T c3_b_i2;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_n;
  int32_T c3_b_next;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_k;
  int32_T c3_c_n;
  int32_T c3_d_a;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_exitg1;
  int32_T c3_exitg2;
  int32_T c3_exponent;
  int32_T c3_f_b;
  int32_T c3_g_b;
  int32_T c3_g_k;
  int32_T c3_h_a;
  int32_T c3_h_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i_k;
  int32_T c3_ia;
  int32_T c3_iac;
  int32_T c3_ix0;
  int32_T c3_iy;
  int32_T c3_j;
  int32_T c3_j_b;
  int32_T c3_j_k;
  int32_T c3_k;
  int32_T c3_k_a;
  int32_T c3_k_b;
  int32_T c3_k_k;
  int32_T c3_loop_ub;
  int32_T c3_m_k;
  int32_T c3_next;
  int32_T c3_nm1;
  int32_T c3_nnxt;
  int32_T c3_nout;
  int32_T c3_noutnew;
  int32_T c3_o_b;
  int32_T c3_o_k;
  int32_T c3_p_a;
  int32_T c3_p_b;
  int32_T c3_p_k;
  int32_T c3_r_a;
  char_T c3_b_str[23];
  char_T c3_str[23];
  boolean_T c3_Done;
  boolean_T c3_MinStepExit;
  boolean_T c3_NoFailedAttempts;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_b_b1;
  boolean_T c3_b_overflow;
  boolean_T c3_b_p;
  boolean_T c3_c_b;
  boolean_T c3_c_p;
  boolean_T c3_d_b;
  boolean_T c3_d_p;
  boolean_T c3_e_b;
  boolean_T c3_e_p;
  boolean_T c3_f_p;
  boolean_T c3_guard1;
  boolean_T c3_m_b;
  boolean_T c3_overflow;
  boolean_T c3_p;
  boolean_T c3_q_b;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_st.site = &c3_emlrtRSI;
  c3_b_st.site = &c3_b_emlrtRSI;
  c3_c_st.site = &c3_o_emlrtRSI;
  c3_d_st.site = &c3_p_emlrtRSI;
  c3_e_st.site = &c3_q_emlrtRSI;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 1);
  c3_f0[0] = -c3_y0[2] * c3_y0[4] + c3_y0[1] * c3_y0[5];
  c3_f0[1] = c3_y0[2] * c3_y0[3] - c3_y0[0] * c3_y0[5];
  c3_f0[2] = -c3_y0[1] * c3_y0[3] + c3_y0[0] * c3_y0[4];
  c3_f0[3] = -c3_y0[4] * c3_y0[5];
  c3_f0[4] = c3_y0[3] * c3_y0[5];
  c3_f0[5] = -c3_y0[3] * c3_y0[4] / 3.0;
  for (c3_i = 0; c3_i < 1001; c3_i++) {
    c3_tout[c3_i] = 0.0;
  }

  for (c3_i1 = 0; c3_i1 < 6006; c3_i1++) {
    c3_yout[c3_i1] = 0.0;
  }

  c3_nout = 0;
  c3_tout[0] = 0.0;
  for (c3_i2 = 0; c3_i2 < 6; c3_i2++) {
    c3_yout[c3_i2] = c3_y0[c3_i2];
  }

  c3_absh = 0.0001;
  for (c3_k = 0; c3_k < 6; c3_k++) {
    c3_c_k = c3_k;
    c3_x = c3_y0[c3_c_k];
    c3_y = muDoubleScalarAbs(c3_x);
    c3_fhBI2[c3_c_k] = c3_y;
  }

  for (c3_b_k = 0; c3_b_k < 6; c3_b_k++) {
    c3_d_k = c3_b_k;
    c3_b_x = c3_fhBI2[c3_d_k];
    c3_c_x = c3_b_x;
    c3_b_ex = muDoubleScalarMax(c3_c_x, 0.001);
    c3_ystage[c3_d_k] = c3_b_ex;
  }

  for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
    c3_ystage[c3_i3] = c3_f0[c3_i3] / c3_ystage[c3_i3];
  }

  c3_b_y = 0.0;
  for (c3_e_k = 0; c3_e_k < 6; c3_e_k++) {
    c3_f_k = static_cast<real_T>(c3_e_k) + 1.0;
    c3_d_x = c3_ystage[static_cast<int32_T>(c3_f_k) - 1];
    c3_e_x = c3_d_x;
    c3_f_x = c3_e_x;
    c3_absx = muDoubleScalarAbs(c3_f_x);
    c3_g_x = c3_absx;
    c3_b = muDoubleScalarIsNaN(c3_g_x);
    if (c3_b || (c3_absx > c3_b_y)) {
      c3_b_y = c3_absx;
    }
  }

  c3_b_rh = c3_b_y / 0.20095091452076641;
  if (0.0001 * c3_b_rh > 1.0) {
    c3_absh = 1.0 / c3_b_rh;
  }

  c3_absh = muDoubleScalarMax(c3_absh, 7.90505033345994E-323);
  c3_t = 0.0;
  for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
    c3_c_y[c3_i4] = c3_y0[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 42; c3_i5++) {
    c3_f[c3_i5] = 0.0;
  }

  for (c3_i6 = 0; c3_i6 < 6; c3_i6++) {
    c3_f[c3_i6] = c3_f0[c3_i6];
  }

  c3_next = 2;
  c3_MinStepExit = false;
  c3_Done = false;
  do {
    c3_exitg1 = 0;
    c3_h_x = c3_t;
    c3_i_x = c3_h_x;
    c3_j_x = c3_i_x;
    c3_k_x = c3_j_x;
    c3_m_x = c3_k_x;
    c3_b_absx = muDoubleScalarAbs(c3_m_x);
    c3_o_x = c3_b_absx;
    c3_p_x = c3_o_x;
    c3_b_b = muDoubleScalarIsInf(c3_p_x);
    c3_c_b = !c3_b_b;
    c3_q_x = c3_o_x;
    c3_d_b = muDoubleScalarIsNaN(c3_q_x);
    c3_b_b1 = !c3_d_b;
    c3_e_b = (c3_c_b && c3_b_b1);
    if (!c3_e_b) {
      c3_r = rtNaN;
    } else if (c3_b_absx < 4.4501477170144028E-308) {
      c3_r = 4.94065645841247E-324;
    } else {
      frexp(c3_b_absx, &c3_exponent);
      c3_b_exponent = c3_exponent;
      c3_r = ldexp(1.0, c3_b_exponent - 53);
    }

    c3_hmin = 16.0 * c3_r;
    c3_absh = muDoubleScalarMin(0.010000000000000002, muDoubleScalarMax(c3_hmin,
      c3_absh));
    c3_h = c3_absh;
    c3_r_x = 0.1 - c3_t;
    c3_s_x = c3_r_x;
    c3_t_x = c3_s_x;
    c3_d_y = muDoubleScalarAbs(c3_t_x);
    if (1.1 * c3_absh >= c3_d_y) {
      c3_h = 0.1 - c3_t;
      c3_u_x = c3_h;
      c3_v_x = c3_u_x;
      c3_w_x = c3_v_x;
      c3_absh = muDoubleScalarAbs(c3_w_x);
      c3_Done = true;
    }

    c3_NoFailedAttempts = true;
    do {
      c3_exitg2 = 0;
      c3_Bcolidx = 6;
      for (c3_j = 0; c3_j < 5; c3_j++) {
        c3_b_j = c3_j + 1;
        c3_Bcolidx = (c3_Bcolidx + c3_b_j) - 1;
        c3_b_st.site = &c3_c_emlrtRSI;
        c3_b_n = c3_b_j;
        c3_alpha1 = c3_h;
        c3_ix0 = c3_Bcolidx - 5;
        for (c3_i9 = 0; c3_i9 < 6; c3_i9++) {
          c3_ystage[c3_i9] = c3_c_y[c3_i9];
        }

        c3_c_st.site = &c3_t_emlrtRSI;
        c3_c_n = c3_b_n;
        c3_b_alpha1 = c3_alpha1;
        c3_b_ix0 = c3_ix0;
        c3_a = c3_c_n - 1;
        c3_nm1 = c3_a;
        if (!(c3_b_alpha1 == 0.0)) {
          c3_b_ix = c3_b_ix0 - 1;
          c3_f_b = c3_nm1;
          c3_c = 6 * c3_f_b;
          c3_g_b = c3_c + 1;
          c3_i11 = c3_g_b;
          for (c3_iac = 1; c3_iac <= c3_i11; c3_iac += 6) {
            c3_b_c = c3_b_alpha1 * c3_dv[c3_b_ix];
            c3_iy = 0;
            c3_b_a = c3_iac + 5;
            c3_i15 = c3_b_a;
            c3_d_st.site = &c3_u_emlrtRSI;
            c3_c_a = c3_iac;
            c3_j_b = c3_i15;
            c3_d_a = c3_c_a;
            c3_k_b = c3_j_b;
            if (c3_d_a > c3_k_b) {
              c3_overflow = false;
            } else {
              c3_overflow = (c3_k_b > 2147483646);
            }

            if (c3_overflow) {
              c3_e_st.site = &c3_v_emlrtRSI;
              c3_check_forloop_overflow_error(chartInstance, &c3_e_st);
            }

            for (c3_ia = c3_iac; c3_ia <= c3_i15; c3_ia++) {
              c3_ystage[c3_iy] += c3_f[c3_ia - 1] * c3_b_c;
              c3_k_a = c3_iy + 1;
              c3_iy = c3_k_a;
            }

            c3_h_a = c3_b_ix + 1;
            c3_b_ix = c3_h_a;
          }
        }

        c3_b_st.site = &c3_d_emlrtRSI;
        c3_c_st.site = &c3_o_emlrtRSI;
        c3_d_st.site = &c3_p_emlrtRSI;
        c3_e_st.site = &c3_q_emlrtRSI;
        covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 1);
        c3_f[6 * c3_b_j] = -c3_ystage[2] * c3_ystage[4] + c3_ystage[1] *
          c3_ystage[5];
        c3_f[1 + 6 * c3_b_j] = c3_ystage[2] * c3_ystage[3] - c3_ystage[0] *
          c3_ystage[5];
        c3_f[2 + 6 * c3_b_j] = -c3_ystage[1] * c3_ystage[3] + c3_ystage[0] *
          c3_ystage[4];
        c3_f[3 + 6 * c3_b_j] = -c3_ystage[4] * c3_ystage[5];
        c3_f[4 + 6 * c3_b_j] = c3_ystage[3] * c3_ystage[5];
        c3_f[5 + 6 * c3_b_j] = -c3_ystage[3] * c3_ystage[4] / 3.0;
        for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
          c3_ystage[c3_i16] = c3_f[c3_i16 + 6 * c3_b_j];
        }

        for (c3_i17 = 0; c3_i17 < 6; c3_i17++) {
          c3_f[c3_i17 + 6 * c3_b_j] = c3_ystage[c3_i17];
        }

        for (c3_i18 = 0; c3_i18 < 6; c3_i18++) {
          c3_ystage[c3_i18] = c3_f[c3_i18 + 6 * c3_b_j];
        }

        for (c3_i19 = 0; c3_i19 < 6; c3_i19++) {
          c3_f[c3_i19 + 6 * c3_b_j] = c3_ystage[c3_i19];
        }
      }

      c3_tnew = c3_t + c3_h;
      for (c3_i7 = 0; c3_i7 < 6; c3_i7++) {
        c3_ynew[c3_i7] = c3_c_y[c3_i7];
      }

      c3_b_st.site = &c3_e_emlrtRSI;
      for (c3_i8 = 0; c3_i8 < 42; c3_i8++) {
        c3_b_f[c3_i8] = c3_f[c3_i8];
      }

      c3_b_xgemv(chartInstance, &c3_b_st, c3_h, c3_b_f, c3_Bcolidx, c3_ynew);
      c3_b_st.site = &c3_f_emlrtRSI;
      c3_c_st.site = &c3_o_emlrtRSI;
      c3_d_st.site = &c3_p_emlrtRSI;
      c3_e_st.site = &c3_q_emlrtRSI;
      covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 1);
      c3_ystage[0] = -c3_ynew[2] * c3_ynew[4] + c3_ynew[1] * c3_ynew[5];
      c3_ystage[1] = c3_ynew[2] * c3_ynew[3] - c3_ynew[0] * c3_ynew[5];
      c3_ystage[2] = -c3_ynew[1] * c3_ynew[3] + c3_ynew[0] * c3_ynew[4];
      c3_ystage[3] = -c3_ynew[4] * c3_ynew[5];
      c3_ystage[4] = c3_ynew[3] * c3_ynew[5];
      c3_ystage[5] = -c3_ynew[3] * c3_ynew[4] / 3.0;
      for (c3_i10 = 0; c3_i10 < 6; c3_i10++) {
        c3_f[c3_i10 + 36] = c3_ystage[c3_i10];
      }

      for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
        c3_ystage[c3_i12] = 0.0;
        c3_i13 = 0;
        for (c3_i14 = 0; c3_i14 < 7; c3_i14++) {
          c3_ystage[c3_i12] += c3_f[c3_i13 + c3_i12] * c3_h_b[c3_i14];
          c3_i13 += 6;
        }
      }

      if (c3_Done) {
        c3_tnew = 0.1;
      }

      c3_h = c3_tnew - c3_t;
      c3_mxerr = 0.0;
      for (c3_g_k = 0; c3_g_k < 6; c3_g_k++) {
        c3_h_k = c3_g_k;
        c3_x_x = c3_ystage[c3_h_k];
        c3_y_x = c3_x_x;
        c3_ab_x = c3_y_x;
        c3_num = muDoubleScalarAbs(c3_ab_x);
        c3_cb_x = c3_c_y[c3_h_k];
        c3_eb_x = c3_cb_x;
        c3_fb_x = c3_eb_x;
        c3_b_d1 = muDoubleScalarAbs(c3_fb_x);
        c3_gb_x = c3_ynew[c3_h_k];
        c3_hb_x = c3_gb_x;
        c3_ib_x = c3_hb_x;
        c3_d2 = muDoubleScalarAbs(c3_ib_x);
        c3_guard1 = false;
        if (c3_b_d1 > c3_d2) {
          c3_guard1 = true;
        } else {
          c3_kb_x = c3_d2;
          c3_m_b = muDoubleScalarIsNaN(c3_kb_x);
          if (c3_m_b) {
            c3_guard1 = true;
          } else if (c3_d2 > 0.001) {
            c3_errk = c3_num / c3_d2;
          } else {
            c3_errk = c3_num / 0.001;
          }
        }

        if (c3_guard1) {
          if (c3_b_d1 > 0.001) {
            c3_errk = c3_num / c3_b_d1;
          } else {
            c3_errk = c3_num / 0.001;
          }
        }

        if (c3_errk > c3_mxerr) {
          c3_mxerr = c3_errk;
        } else {
          c3_ob_x = c3_errk;
          c3_q_b = muDoubleScalarIsNaN(c3_ob_x);
          if (c3_q_b) {
            c3_mxerr = c3_errk;
          }
        }
      }

      c3_err = c3_absh * c3_mxerr;
      if (!(c3_err <= 0.001)) {
        if (c3_absh <= c3_hmin) {
          c3_b_st.site = &c3_h_emlrtRSI;
          c3_bb_x = c3_t;
          c3_c_st.site = &c3_w_emlrtRSI;
          c3_db_x = c3_bb_x;
          c3_e_y = NULL;
          sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_rfmt, 10, 0U, 1U, 0U, 2,
            1, 7), false);
          c3_f_y = NULL;
          sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_db_x, 0, 0U, 0U, 0U, 0),
                        false);
          c3_d_st.site = &c3_x_emlrtRSI;
          c3_emlrt_marshallIn(chartInstance, c3_sprintf(chartInstance, &c3_d_st,
            c3_e_y, c3_f_y), "<output of sprintf>", c3_str);
          c3_b_st.site = &c3_i_emlrtRSI;
          c3_jb_x = c3_hmin;
          c3_c_st.site = &c3_w_emlrtRSI;
          c3_mb_x = c3_jb_x;
          c3_g_y = NULL;
          sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_rfmt, 10, 0U, 1U, 0U, 2,
            1, 7), false);
          c3_h_y = NULL;
          sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_mb_x, 0, 0U, 0U, 0U, 0),
                        false);
          c3_d_st.site = &c3_x_emlrtRSI;
          c3_emlrt_marshallIn(chartInstance, c3_sprintf(chartInstance, &c3_d_st,
            c3_g_y, c3_h_y), "<output of sprintf>", c3_b_str);
          c3_b_st.site = &c3_j_emlrtRSI;
          c3_warning(chartInstance, &c3_b_st, c3_str, c3_b_str);
          c3_MinStepExit = true;
          c3_exitg2 = 1;
        } else {
          if (c3_NoFailedAttempts) {
            c3_NoFailedAttempts = false;
            c3_b_st.site = &c3_g_emlrtRSI;
            c3_e_a = 0.001 / c3_err;
            c3_c_st.site = &c3_r_emlrtRSI;
            c3_f_a = c3_e_a;
            c3_d_st.site = &c3_s_emlrtRSI;
            c3_g_a = c3_f_a;
            c3_j_a = c3_g_a;
            c3_m_a = c3_j_a;
            c3_o_a = c3_m_a;
            c3_p = (c3_o_a < 0.0);
            if (c3_p) {
              c3_b_p = true;
            } else {
              c3_b_p = false;
            }

            c3_c_p = c3_b_p;
            if (c3_c_p) {
              c3_j_y = NULL;
              sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2,
                1, 31), false);
              c3_k_y = NULL;
              sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2,
                1, 31), false);
              sf_mex_call(&c3_d_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_j_y,
                          14, sf_mex_call(&c3_d_st, NULL, "getString", 1U, 1U,
                14, sf_mex_call(&c3_d_st, NULL, "message", 1U, 1U, 14, c3_k_y)));
            }

            c3_u_a = c3_g_a;
            c3_w_a = c3_u_a;
            c3_c_c = muDoubleScalarPower(c3_w_a, 0.2);
            c3_absh = muDoubleScalarMax(c3_hmin, c3_absh * muDoubleScalarMax(0.1,
              0.8 * c3_c_c));
          } else {
            c3_absh = muDoubleScalarMax(c3_hmin, 0.5 * c3_absh);
          }

          c3_h = c3_absh;
          c3_Done = false;
        }
      } else {
        c3_exitg2 = 1;
      }
    } while (c3_exitg2 == 0);

    if (c3_MinStepExit) {
      c3_exitg1 = 1;
    } else {
      c3_b_next = c3_next;
      c3_b_tnew = c3_tnew;
      c3_nnxt = c3_b_next;
      while ((static_cast<real_T>(c3_nnxt) <= 1001.0) && (c3_b_tnew -
              c3_b_dv[c3_nnxt - 1] >= 0.0)) {
        c3_nnxt++;
      }

      c3_noutnew = c3_nnxt - c3_next;
      if (c3_noutnew > 0) {
        c3_b_i2 = c3_nnxt - 2;
        c3_i21 = c3_b_i2;
        c3_b_st.site = &c3_k_emlrtRSI;
        c3_p_a = c3_next;
        c3_o_b = c3_i21;
        c3_r_a = c3_p_a;
        c3_p_b = c3_o_b;
        if (c3_r_a > c3_p_b) {
          c3_b_overflow = false;
        } else {
          c3_b_overflow = (c3_p_b > 2147483646);
        }

        if (c3_b_overflow) {
          c3_c_st.site = &c3_v_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
        }

        for (c3_i_k = c3_next; c3_i_k <= c3_i21; c3_i_k++) {
          c3_tout[c3_i_k - 1] = c3_b_dv[c3_i_k - 1];
          c3_b_t = c3_b_dv[c3_i_k - 1];
          c3_t0 = c3_t;
          c3_d_h = c3_h;
          for (c3_i28 = 0; c3_i28 < 6; c3_i28++) {
            c3_ystage[c3_i28] = c3_f[c3_i28];
          }

          c3_r_b = c3_d_h;
          for (c3_i30 = 0; c3_i30 < 6; c3_i30++) {
            c3_ystage[c3_i30] *= c3_r_b;
          }

          c3_cb_a = c3_d_h;
          for (c3_i32 = 0; c3_i32 < 7; c3_i32++) {
            c3_p_y[c3_i32] = c3_cb_a * c3_t_b[c3_i32];
          }

          for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
            c3_fhBI2[c3_i34] = 0.0;
            c3_i37 = 0;
            for (c3_i40 = 0; c3_i40 < 7; c3_i40++) {
              c3_fhBI2[c3_i34] += c3_f[c3_i37 + c3_i34] * c3_p_y[c3_i40];
              c3_i37 += 6;
            }
          }

          c3_eb_a = c3_d_h;
          for (c3_i36 = 0; c3_i36 < 7; c3_i36++) {
            c3_p_y[c3_i36] = c3_eb_a * c3_u_b[c3_i36];
          }

          for (c3_i42 = 0; c3_i42 < 6; c3_i42++) {
            c3_f0[c3_i42] = 0.0;
            c3_i45 = 0;
            for (c3_i48 = 0; c3_i48 < 7; c3_i48++) {
              c3_f0[c3_i42] += c3_f[c3_i45 + c3_i42] * c3_p_y[c3_i48];
              c3_i45 += 6;
            }
          }

          c3_gb_a = c3_d_h;
          for (c3_i44 = 0; c3_i44 < 7; c3_i44++) {
            c3_p_y[c3_i44] = c3_gb_a * c3_v_b[c3_i44];
          }

          for (c3_i50 = 0; c3_i50 < 6; c3_i50++) {
            c3_fhBI4[c3_i50] = 0.0;
            c3_i52 = 0;
            for (c3_i54 = 0; c3_i54 < 7; c3_i54++) {
              c3_fhBI4[c3_i50] += c3_f[c3_i52 + c3_i50] * c3_p_y[c3_i54];
              c3_i52 += 6;
            }
          }

          c3_s = (c3_b_t - c3_t0) / c3_d_h;
          for (c3_j_k = 0; c3_j_k < 6; c3_j_k++) {
            c3_m_k = c3_j_k;
            c3_p_k = c3_i_k - 1;
            c3_yout[c3_m_k + 6 * c3_p_k] = (((c3_fhBI4[c3_m_k] * c3_s +
              c3_f0[c3_m_k]) * c3_s + c3_fhBI2[c3_m_k]) * c3_s +
              c3_ystage[c3_m_k]) * c3_s + c3_c_y[c3_m_k];
          }
        }

        c3_tout[c3_b_i2] = c3_b_dv[c3_b_i2];
        if (c3_b_dv[c3_b_i2] == c3_tnew) {
          for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
            c3_yout[c3_i27 + 6 * c3_b_i2] = c3_ynew[c3_i27];
          }
        } else {
          c3_c_t = c3_b_dv[c3_b_i2];
          c3_b_t0 = c3_t;
          c3_e_h = c3_h;
          for (c3_i29 = 0; c3_i29 < 6; c3_i29++) {
            c3_ystage[c3_i29] = c3_f[c3_i29];
          }

          c3_s_b = c3_e_h;
          for (c3_i31 = 0; c3_i31 < 6; c3_i31++) {
            c3_ystage[c3_i31] *= c3_s_b;
          }

          c3_db_a = c3_e_h;
          for (c3_i33 = 0; c3_i33 < 7; c3_i33++) {
            c3_p_y[c3_i33] = c3_db_a * c3_t_b[c3_i33];
          }

          for (c3_i35 = 0; c3_i35 < 6; c3_i35++) {
            c3_fhBI2[c3_i35] = 0.0;
            c3_i39 = 0;
            for (c3_i41 = 0; c3_i41 < 7; c3_i41++) {
              c3_fhBI2[c3_i35] += c3_f[c3_i39 + c3_i35] * c3_p_y[c3_i41];
              c3_i39 += 6;
            }
          }

          c3_fb_a = c3_e_h;
          for (c3_i38 = 0; c3_i38 < 7; c3_i38++) {
            c3_p_y[c3_i38] = c3_fb_a * c3_u_b[c3_i38];
          }

          for (c3_i43 = 0; c3_i43 < 6; c3_i43++) {
            c3_f0[c3_i43] = 0.0;
            c3_i47 = 0;
            for (c3_i49 = 0; c3_i49 < 7; c3_i49++) {
              c3_f0[c3_i43] += c3_f[c3_i47 + c3_i43] * c3_p_y[c3_i49];
              c3_i47 += 6;
            }
          }

          c3_hb_a = c3_e_h;
          for (c3_i46 = 0; c3_i46 < 7; c3_i46++) {
            c3_p_y[c3_i46] = c3_hb_a * c3_v_b[c3_i46];
          }

          for (c3_i51 = 0; c3_i51 < 6; c3_i51++) {
            c3_fhBI4[c3_i51] = 0.0;
            c3_i53 = 0;
            for (c3_i55 = 0; c3_i55 < 7; c3_i55++) {
              c3_fhBI4[c3_i51] += c3_f[c3_i53 + c3_i51] * c3_p_y[c3_i55];
              c3_i53 += 6;
            }
          }

          c3_b_s = (c3_c_t - c3_b_t0) / c3_e_h;
          for (c3_k_k = 0; c3_k_k < 6; c3_k_k++) {
            c3_o_k = c3_k_k;
            c3_yout[c3_o_k + 6 * c3_b_i2] = (((c3_fhBI4[c3_o_k] * c3_b_s +
              c3_f0[c3_o_k]) * c3_b_s + c3_fhBI2[c3_o_k]) * c3_b_s +
              c3_ystage[c3_o_k]) * c3_b_s + c3_c_y[c3_o_k];
          }
        }

        c3_nout += c3_noutnew;
        c3_next = c3_nnxt;
      }

      if (c3_Done) {
        c3_exitg1 = 1;
      } else {
        if (c3_NoFailedAttempts) {
          c3_b_st.site = &c3_m_emlrtRSI;
          c3_q_a = c3_err / 0.001;
          c3_c_st.site = &c3_r_emlrtRSI;
          c3_s_a = c3_q_a;
          c3_d_st.site = &c3_s_emlrtRSI;
          c3_t_a = c3_s_a;
          c3_v_a = c3_t_a;
          c3_x_a = c3_v_a;
          c3_y_a = c3_x_a;
          c3_d_p = (c3_y_a < 0.0);
          if (c3_d_p) {
            c3_e_p = true;
          } else {
            c3_e_p = false;
          }

          c3_f_p = c3_e_p;
          if (c3_f_p) {
            c3_m_y = NULL;
            sf_mex_assign(&c3_m_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2,
              1, 31), false);
            c3_o_y = NULL;
            sf_mex_assign(&c3_o_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2,
              1, 31), false);
            sf_mex_call(&c3_d_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_m_y, 14,
                        sf_mex_call(&c3_d_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c3_d_st, NULL, "message", 1U, 1U, 14, c3_o_y)));
          }

          c3_ab_a = c3_t_a;
          c3_bb_a = c3_ab_a;
          c3_d_c = muDoubleScalarPower(c3_bb_a, 0.2);
          c3_temp = 1.25 * c3_d_c;
          if (c3_temp > 0.2) {
            c3_absh /= c3_temp;
          } else {
            c3_absh *= 5.0;
          }
        }

        c3_t = c3_tnew;
        for (c3_i23 = 0; c3_i23 < 6; c3_i23++) {
          c3_c_y[c3_i23] = c3_ynew[c3_i23];
        }

        for (c3_i25 = 0; c3_i25 < 6; c3_i25++) {
          c3_c_f[c3_i25] = c3_f[c3_i25 + 36];
        }

        for (c3_i26 = 0; c3_i26 < 6; c3_i26++) {
          c3_f[c3_i26] = c3_c_f[c3_i26];
        }
      }
    }
  } while (c3_exitg1 == 0);

  c3_varargout_1_size[0] = c3_nout + 1;
  c3_loop_ub = c3_nout;
  for (c3_i20 = 0; c3_i20 <= c3_loop_ub; c3_i20++) {
    c3_varargout_1_data[c3_i20] = c3_tout[c3_i20];
  }

  c3_varargout_2_size[0] = c3_nout + 1;
  c3_varargout_2_size[1] = 6;
  for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
    c3_b_loop_ub = c3_nout;
    for (c3_i24 = 0; c3_i24 <= c3_b_loop_ub; c3_i24++) {
      c3_varargout_2_data[c3_i24 + c3_varargout_2_size[0] * c3_i22] =
        c3_yout[c3_i22 + 6 * c3_i24];
    }
  }
}

static void c3_check_forloop_overflow_error(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp)
{
  static char_T c3_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c3_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c3_sp, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14, sf_mex_call
              (c3_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c3_sp, NULL,
    "message", 1U, 2U, 14, c3_b_y, 14, c3_c_y)));
}

static void c3_xgemv(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_alpha1, real_T c3_ib_A[42],
                     int32_T c3_ix0, real_T c3_y[6], real_T c3_b_y[6])
{
  real_T c3_jb_A[42];
  int32_T c3_i;
  int32_T c3_i1;
  for (c3_i = 0; c3_i < 6; c3_i++) {
    c3_b_y[c3_i] = c3_y[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 42; c3_i1++) {
    c3_jb_A[c3_i1] = c3_ib_A[c3_i1];
  }

  c3_b_xgemv(chartInstance, c3_sp, c3_alpha1, c3_jb_A, c3_ix0, c3_b_y);
}

static void c3_warning(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, char_T c3_varargin_1[23], char_T c3_varargin_2[23])
{
  static char_T c3_msgID[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 'd',
    'e', '4', '5', ':', 'I', 'n', 't', 'e', 'g', 'r', 'a', 't', 'i', 'o', 'n',
    'T', 'o', 'l', 'N', 'o', 't', 'M', 'e', 't' };

  static char_T c3_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c3_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_y = NULL;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_msgID, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    23), false);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_varargin_2, 10, 0U, 1U, 0U, 2, 1,
    23), false);
  c3_st.site = &c3_y_emlrtRSI;
  c3_b_feval(chartInstance, &c3_st, c3_y, c3_feval(chartInstance, &c3_st, c3_b_y,
              c3_c_y, c3_d_y, c3_e_y));
}

static boolean_T c3_anyNonFinite(SFc3_starshotsim_devInstanceStruct
  *chartInstance, real_T c3_x[36])
{
  real_T c3_x_data[36];
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  int32_T c3_b_k;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_b;
  boolean_T c3_b_b;
  boolean_T c3_b_b1;
  boolean_T c3_b_p;
  boolean_T c3_c_b;
  boolean_T c3_c_p;
  boolean_T c3_d_b;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_x_data[c3_i] = c3_x[c3_i];
  }

  c3_b_p = true;
  for (c3_k = 0; c3_k < 36; c3_k++) {
    c3_b_k = c3_k;
    if (c3_b_p) {
      c3_b_x = c3_x_data[c3_b_k];
      c3_c_x = c3_b_x;
      c3_b = muDoubleScalarIsInf(c3_c_x);
      c3_b_b = !c3_b;
      c3_d_x = c3_b_x;
      c3_c_b = muDoubleScalarIsNaN(c3_d_x);
      c3_b_b1 = !c3_c_b;
      c3_d_b = (c3_b_b && c3_b_b1);
      if (c3_d_b) {
        c3_c_p = true;
      } else {
        c3_c_p = false;
      }
    } else {
      c3_c_p = false;
    }

    c3_b_p = c3_c_p;
  }

  return !c3_b_p;
}

static void c3_schur(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, real_T c3_ib_A[36], real_T c3_V[36],
                     real_T c3_e_T[36])
{
  static char_T c3_b_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c3_cv2[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'o',
    'r', 'g', 'h', 'r' };

  static char_T c3_cv1[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  ptrdiff_t c3_ihi_t;
  ptrdiff_t c3_ilo_t;
  ptrdiff_t c3_info_t;
  ptrdiff_t c3_lda_t;
  ptrdiff_t c3_n_t;
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_f_st;
  emlrtStack c3_g_st;
  emlrtStack c3_h_st;
  emlrtStack c3_i_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_work[6];
  real_T c3_tau[5];
  real_T c3_alpha1;
  real_T c3_b_alpha1;
  real_T c3_b_tau;
  real_T c3_b_x;
  real_T c3_b_x1;
  real_T c3_b_x2;
  real_T c3_beta1;
  real_T c3_c_alpha1;
  real_T c3_c_x;
  real_T c3_d;
  real_T c3_d_alpha1;
  real_T c3_d_b;
  real_T c3_d_x;
  real_T c3_e_alpha1;
  real_T c3_e_x;
  real_T c3_f_alpha1;
  real_T c3_f_x;
  real_T c3_g_alpha1;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_j_a;
  real_T c3_j_y;
  real_T c3_k_y;
  real_T c3_m_y;
  real_T c3_o_y;
  real_T c3_p_b;
  real_T c3_t_c;
  real_T c3_temp;
  real_T c3_x;
  real_T c3_x1;
  real_T c3_x2;
  real_T c3_x_a;
  real_T c3_xnorm;
  real_T c3_yjy;
  int32_T c3_a;
  int32_T c3_ab_a;
  int32_T c3_ab_b;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_c;
  int32_T c3_b_i;
  int32_T c3_b_ia;
  int32_T c3_b_ia0;
  int32_T c3_b_info;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_b_iy;
  int32_T c3_b_iy0;
  int32_T c3_b_j;
  int32_T c3_b_jA;
  int32_T c3_b_jy;
  int32_T c3_b_lastc;
  int32_T c3_b_n;
  int32_T c3_b_nm1;
  int32_T c3_bb_a;
  int32_T c3_bb_b;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_c;
  int32_T c3_c_i;
  int32_T c3_c_ia0;
  int32_T c3_c_info;
  int32_T c3_c_ix;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_c_j;
  int32_T c3_c_m;
  int32_T c3_c_n;
  int32_T c3_cb_a;
  int32_T c3_cb_b;
  int32_T c3_d_a;
  int32_T c3_d_c;
  int32_T c3_d_i;
  int32_T c3_d_ia0;
  int32_T c3_d_info;
  int32_T c3_d_iy0;
  int32_T c3_d_m;
  int32_T c3_db_a;
  int32_T c3_db_b;
  int32_T c3_e_a;
  int32_T c3_e_b;
  int32_T c3_e_c;
  int32_T c3_e_i;
  int32_T c3_e_ia0;
  int32_T c3_e_m;
  int32_T c3_eb_a;
  int32_T c3_eb_b;
  int32_T c3_exitg1;
  int32_T c3_f_a;
  int32_T c3_f_b;
  int32_T c3_f_c;
  int32_T c3_f_ia0;
  int32_T c3_f_m;
  int32_T c3_f_n;
  int32_T c3_fb_a;
  int32_T c3_fb_b;
  int32_T c3_g_a;
  int32_T c3_g_b;
  int32_T c3_g_c;
  int32_T c3_g_ia0;
  int32_T c3_g_m;
  int32_T c3_g_n;
  int32_T c3_gb_a;
  int32_T c3_gb_b;
  int32_T c3_h_a;
  int32_T c3_h_b;
  int32_T c3_h_c;
  int32_T c3_h_ia0;
  int32_T c3_h_n;
  int32_T c3_hb_a;
  int32_T c3_hb_b;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i_c;
  int32_T c3_ia;
  int32_T c3_ia0;
  int32_T c3_iac;
  int32_T c3_ib_b;
  int32_T c3_ic0;
  int32_T c3_ijA;
  int32_T c3_im1;
  int32_T c3_im1n;
  int32_T c3_in;
  int32_T c3_info;
  int32_T c3_ip1;
  int32_T c3_istart;
  int32_T c3_iv0;
  int32_T c3_ix0;
  int32_T c3_iy;
  int32_T c3_iy0;
  int32_T c3_iyend;
  int32_T c3_j;
  int32_T c3_j_b;
  int32_T c3_j_c;
  int32_T c3_j_n;
  int32_T c3_jb_b;
  int32_T c3_k;
  int32_T c3_k_a;
  int32_T c3_k_c;
  int32_T c3_k_n;
  int32_T c3_kb_a;
  int32_T c3_knt;
  int32_T c3_lastc;
  int32_T c3_lastv;
  int32_T c3_m;
  int32_T c3_m_a;
  int32_T c3_m_b;
  int32_T c3_m_c;
  int32_T c3_m_n;
  int32_T c3_mb_a;
  int32_T c3_mm1;
  int32_T c3_nm1;
  int32_T c3_o_a;
  int32_T c3_o_b;
  int32_T c3_o_c;
  int32_T c3_o_n;
  int32_T c3_ob_a;
  int32_T c3_p_a;
  int32_T c3_p_c;
  int32_T c3_pb_a;
  int32_T c3_q_a;
  int32_T c3_q_b;
  int32_T c3_q_c;
  int32_T c3_qb_a;
  int32_T c3_r_a;
  int32_T c3_r_b;
  int32_T c3_r_c;
  int32_T c3_rb_a;
  int32_T c3_rowleft;
  int32_T c3_rowright;
  int32_T c3_s_a;
  int32_T c3_s_b;
  int32_T c3_s_c;
  int32_T c3_sb_a;
  int32_T c3_t_a;
  int32_T c3_t_b;
  int32_T c3_tb_a;
  int32_T c3_u_a;
  int32_T c3_u_b;
  int32_T c3_ub_a;
  int32_T c3_v_a;
  int32_T c3_v_b;
  int32_T c3_val;
  int32_T c3_vb_a;
  int32_T c3_w_a;
  int32_T c3_w_b;
  int32_T c3_x_b;
  int32_T c3_y_a;
  int32_T c3_y_b;
  boolean_T c3_b_overflow;
  boolean_T c3_b_p;
  boolean_T c3_c_overflow;
  boolean_T c3_c_p;
  boolean_T c3_d_overflow;
  boolean_T c3_e_overflow;
  boolean_T c3_exitg2;
  boolean_T c3_k_b;
  boolean_T c3_overflow;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_f_st.prev = &c3_e_st;
  c3_f_st.tls = c3_e_st.tls;
  c3_g_st.prev = &c3_f_st;
  c3_g_st.tls = c3_f_st.tls;
  c3_h_st.prev = &c3_g_st;
  c3_h_st.tls = c3_g_st.tls;
  c3_i_st.prev = &c3_h_st;
  c3_i_st.tls = c3_h_st.tls;
  c3_st.site = &c3_pb_emlrtRSI;
  if (c3_anyNonFinite(chartInstance, c3_ib_A)) {
    for (c3_i = 0; c3_i < 36; c3_i++) {
      c3_V[c3_i] = rtNaN;
    }

    c3_istart = 2;
    for (c3_j = 0; c3_j < 5; c3_j++) {
      c3_b_j = c3_j;
      for (c3_c_i = c3_istart; c3_c_i < 7; c3_c_i++) {
        c3_V[(c3_c_i + 6 * c3_b_j) - 1] = 0.0;
      }

      c3_a = c3_istart + 1;
      c3_istart = c3_a;
    }

    for (c3_i3 = 0; c3_i3 < 36; c3_i3++) {
      c3_e_T[c3_i3] = rtNaN;
    }
  } else {
    c3_st.site = &c3_qb_emlrtRSI;
    for (c3_i1 = 0; c3_i1 < 36; c3_i1++) {
      c3_e_T[c3_i1] = c3_ib_A[c3_i1];
    }

    c3_b_st.site = &c3_ub_emlrtRSI;
    for (c3_i2 = 0; c3_i2 < 6; c3_i2++) {
      c3_work[c3_i2] = 0.0;
    }

    for (c3_b_i = 0; c3_b_i < 5; c3_b_i++) {
      c3_d_i = c3_b_i + 1;
      c3_b_a = c3_d_i - 1;
      c3_im1 = c3_b_a;
      c3_c_a = c3_d_i + 1;
      c3_ip1 = c3_c_a;
      c3_d_a = c3_im1;
      c3_im1n = c3_d_a * 6;
      c3_e_a = c3_d_i;
      c3_in = c3_e_a * 6;
      c3_alpha1 = c3_e_T[(c3_ip1 + 6 * (c3_d_i - 1)) - 1];
      c3_f_a = c3_d_i + 2;
      c3_c = c3_f_a;
      c3_g_a = c3_im1;
      c3_b_c = c3_g_a * 6;
      c3_h_a = muIntScalarMin_sint32(c3_c, 6);
      c3_b = c3_b_c;
      c3_ia0 = c3_h_a + c3_b;
      c3_b_b = c3_d_i;
      c3_c_c = 6 - c3_b_b;
      c3_c_st.site = &c3_vb_emlrtRSI;
      c3_b_n = c3_c_c - 1;
      c3_b_alpha1 = c3_alpha1;
      c3_ix0 = c3_ia0;
      c3_c_alpha1 = c3_b_alpha1;
      c3_d = 0.0;
      c3_nm1 = c3_b_n;
      c3_d_st.site = &c3_yb_emlrtRSI;
      c3_xnorm = c3_xnrm2(chartInstance, &c3_d_st, c3_nm1, c3_e_T, c3_ix0);
      if (c3_xnorm != 0.0) {
        c3_x1 = c3_c_alpha1;
        c3_x2 = c3_xnorm;
        c3_j_a = c3_x1;
        c3_d_b = c3_x2;
        c3_beta1 = muDoubleScalarHypot(c3_j_a, c3_d_b);
        if (c3_c_alpha1 >= 0.0) {
          c3_beta1 = -c3_beta1;
        }

        c3_x = c3_beta1;
        c3_b_x = c3_x;
        c3_c_x = c3_b_x;
        c3_g_y = muDoubleScalarAbs(c3_c_x);
        if (c3_g_y < 1.0020841800044864E-292) {
          c3_knt = 0;
          do {
            c3_o_a = c3_knt + 1;
            c3_knt = c3_o_a;
            c3_d_st.site = &c3_bc_emlrtRSI;
            c3_b_xscal(chartInstance, &c3_d_st, c3_nm1, 9.9792015476736E+291,
                       c3_e_T, c3_ix0);
            c3_beta1 *= 9.9792015476736E+291;
            c3_c_alpha1 *= 9.9792015476736E+291;
            c3_e_x = c3_beta1;
            c3_f_x = c3_e_x;
            c3_g_x = c3_f_x;
            c3_k_y = muDoubleScalarAbs(c3_g_x);
            if ((c3_k_y < 1.0020841800044864E-292) && (c3_knt < 20)) {
              c3_k_b = true;
            } else {
              c3_k_b = false;
            }
          } while (!!c3_k_b);

          c3_d_st.site = &c3_cc_emlrtRSI;
          c3_xnorm = c3_xnrm2(chartInstance, &c3_d_st, c3_nm1, c3_e_T, c3_ix0);
          c3_b_x1 = c3_c_alpha1;
          c3_b_x2 = c3_xnorm;
          c3_x_a = c3_b_x1;
          c3_p_b = c3_b_x2;
          c3_beta1 = muDoubleScalarHypot(c3_x_a, c3_p_b);
          if (c3_c_alpha1 >= 0.0) {
            c3_beta1 = -c3_beta1;
          }

          c3_h_x = c3_beta1 - c3_c_alpha1;
          c3_m_y = c3_beta1;
          c3_d = c3_h_x / c3_m_y;
          c3_o_y = c3_c_alpha1 - c3_beta1;
          c3_c_alpha1 = 1.0 / c3_o_y;
          c3_d_st.site = &c3_dc_emlrtRSI;
          c3_b_xscal(chartInstance, &c3_d_st, c3_nm1, c3_c_alpha1, c3_e_T,
                     c3_ix0);
          c3_d_st.site = &c3_ec_emlrtRSI;
          c3_w_b = c3_knt;
          c3_x_b = c3_w_b;
          if (c3_x_b < 1) {
            c3_b_overflow = false;
          } else {
            c3_b_overflow = (c3_x_b > 2147483646);
          }

          if (c3_b_overflow) {
            c3_e_st.site = &c3_v_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_e_st);
          }

          for (c3_k = 0; c3_k < c3_knt; c3_k++) {
            c3_beta1 *= 1.0020841800044864E-292;
          }

          c3_c_alpha1 = c3_beta1;
        } else {
          c3_d_x = c3_beta1 - c3_c_alpha1;
          c3_h_y = c3_beta1;
          c3_d = c3_d_x / c3_h_y;
          c3_j_y = c3_c_alpha1 - c3_beta1;
          c3_c_alpha1 = 1.0 / c3_j_y;
          c3_d_st.site = &c3_ac_emlrtRSI;
          c3_b_xscal(chartInstance, &c3_d_st, c3_nm1, c3_c_alpha1, c3_e_T,
                     c3_ix0);
          c3_c_alpha1 = c3_beta1;
        }
      }

      c3_tau[c3_d_i - 1] = c3_d;
      c3_e_T[(c3_ip1 + 6 * (c3_d_i - 1)) - 1] = 1.0;
      c3_c_b = c3_d_i;
      c3_d_c = 6 - c3_c_b;
      c3_k_a = c3_ip1;
      c3_e_b = c3_im1n;
      c3_e_c = c3_k_a + c3_e_b;
      c3_m_a = c3_in + 1;
      c3_f_c = c3_m_a;
      c3_c_st.site = &c3_wb_emlrtRSI;
      c3_c_n = c3_d_c;
      c3_iv0 = c3_e_c;
      c3_b_tau = c3_tau[c3_d_i - 1];
      c3_ic0 = c3_f_c;
      if (c3_b_tau != 0.0) {
        c3_lastv = c3_c_n;
        c3_p_a = c3_c_n - 1;
        c3_g_c = c3_p_a;
        c3_f_b = c3_g_c;
        c3_h_c = c3_f_b;
        c3_q_a = c3_iv0;
        c3_h_b = c3_h_c;
        c3_e_i = c3_q_a + c3_h_b;
        while ((c3_lastv > 0) && (c3_e_T[c3_e_i - 1] == 0.0)) {
          c3_s_a = c3_lastv - 1;
          c3_lastv = c3_s_a;
          c3_u_a = c3_e_i - 1;
          c3_e_i = c3_u_a;
        }

        c3_g_n = c3_lastv;
        c3_c_ia0 = c3_ic0;
        c3_b_lastc = 6;
        c3_exitg2 = false;
        while ((!c3_exitg2) && (c3_b_lastc > 0)) {
          c3_w_a = c3_b_lastc - 1;
          c3_o_c = c3_w_a;
          c3_ab_a = c3_c_ia0;
          c3_r_b = c3_o_c;
          c3_rowleft = c3_ab_a + c3_r_b;
          c3_bb_a = c3_g_n - 1;
          c3_q_c = c3_bb_a;
          c3_cb_a = c3_q_c;
          c3_r_c = c3_cb_a * 6;
          c3_db_a = c3_rowleft;
          c3_v_b = c3_r_c;
          c3_rowright = c3_db_a + c3_v_b;
          c3_ia = c3_rowleft;
          do {
            c3_exitg1 = 0;
            if (c3_ia <= c3_rowright) {
              if (c3_e_T[c3_ia - 1] != 0.0) {
                c3_exitg1 = 1;
              } else {
                c3_ia += 6;
              }
            } else {
              c3_eb_a = c3_b_lastc - 1;
              c3_b_lastc = c3_eb_a;
              c3_exitg1 = 2;
            }
          } while (c3_exitg1 == 0);

          if (c3_exitg1 == 1) {
            c3_exitg2 = true;
          }
        }

        c3_lastc = c3_b_lastc;
      } else {
        c3_lastv = 0;
        c3_lastc = 0;
      }

      if (c3_lastv > 0) {
        c3_d_st.site = &c3_jc_emlrtRSI;
        c3_m = c3_lastc;
        c3_f_n = c3_lastv;
        c3_b_ia0 = c3_ic0;
        c3_b_ix0 = c3_iv0;
        c3_e_st.site = &c3_t_emlrtRSI;
        c3_c_m = c3_m;
        c3_h_n = c3_f_n;
        c3_d_ia0 = c3_b_ia0;
        c3_c_ix0 = c3_b_ix0;
        if (c3_c_m != 0) {
          c3_v_a = c3_c_m - 1;
          c3_mm1 = c3_v_a;
          c3_y_a = c3_h_n - 1;
          c3_b_nm1 = c3_y_a;
          c3_q_b = c3_mm1;
          c3_p_c = c3_q_b;
          c3_s_b = c3_p_c + 1;
          c3_iyend = c3_s_b;
          c3_f_st.site = &c3_mc_emlrtRSI;
          c3_t_b = c3_iyend;
          c3_u_b = c3_t_b;
          if (c3_u_b < 1) {
            c3_overflow = false;
          } else {
            c3_overflow = (c3_u_b > 2147483646);
          }

          if (c3_overflow) {
            c3_g_st.site = &c3_v_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_g_st);
          }

          c3_i6 = static_cast<uint8_T>(c3_iyend) - 1;
          for (c3_iy = 0; c3_iy <= c3_i6; c3_iy++) {
            c3_b_iy = c3_iy;
            c3_work[c3_b_iy] = 0.0;
          }

          c3_b_ix = c3_c_ix0 - 1;
          c3_y_b = c3_b_nm1;
          c3_s_c = 6 * c3_y_b;
          c3_fb_a = c3_d_ia0;
          c3_ab_b = c3_s_c;
          c3_i7 = c3_fb_a + c3_ab_b;
          for (c3_iac = c3_d_ia0; c3_iac <= c3_i7; c3_iac += 6) {
            c3_t_c = c3_e_T[c3_b_ix];
            c3_b_iy = 0;
            c3_hb_a = c3_iac;
            c3_cb_b = c3_mm1;
            c3_i8 = c3_hb_a + c3_cb_b;
            c3_f_st.site = &c3_u_emlrtRSI;
            c3_kb_a = c3_iac;
            c3_eb_b = c3_i8;
            c3_mb_a = c3_kb_a;
            c3_fb_b = c3_eb_b;
            if (c3_mb_a > c3_fb_b) {
              c3_d_overflow = false;
            } else {
              c3_d_overflow = (c3_fb_b > 2147483646);
            }

            if (c3_d_overflow) {
              c3_g_st.site = &c3_v_emlrtRSI;
              c3_check_forloop_overflow_error(chartInstance, &c3_g_st);
            }

            for (c3_b_ia = c3_iac; c3_b_ia <= c3_i8; c3_b_ia++) {
              c3_work[c3_b_iy] += c3_e_T[c3_b_ia - 1] * c3_t_c;
              c3_rb_a = c3_b_iy + 1;
              c3_b_iy = c3_rb_a;
            }

            c3_pb_a = c3_b_ix + 1;
            c3_b_ix = c3_pb_a;
          }
        }

        c3_d_st.site = &c3_kc_emlrtRSI;
        c3_d_m = c3_lastc;
        c3_j_n = c3_lastv;
        c3_d_alpha1 = -c3_b_tau;
        c3_iy0 = c3_iv0;
        c3_e_ia0 = c3_ic0;
        c3_e_st.site = &c3_oc_emlrtRSI;
        c3_e_m = c3_d_m;
        c3_k_n = c3_j_n;
        c3_e_alpha1 = c3_d_alpha1;
        c3_b_iy0 = c3_iy0;
        c3_f_ia0 = c3_e_ia0;
        c3_f_st.site = &c3_pc_emlrtRSI;
        c3_f_m = c3_e_m;
        c3_m_n = c3_k_n;
        c3_f_alpha1 = c3_e_alpha1;
        c3_c_iy0 = c3_b_iy0;
        c3_g_ia0 = c3_f_ia0;
        c3_g_st.site = &c3_qc_emlrtRSI;
        c3_g_m = c3_f_m;
        c3_o_n = c3_m_n;
        c3_g_alpha1 = c3_f_alpha1;
        c3_d_iy0 = c3_c_iy0;
        c3_h_ia0 = c3_g_ia0;
        if (!(c3_g_alpha1 == 0.0)) {
          c3_gb_a = c3_h_ia0 - 1;
          c3_b_jA = c3_gb_a;
          c3_b_jy = c3_d_iy0 - 1;
          c3_h_st.site = &c3_rc_emlrtRSI;
          c3_bb_b = c3_o_n;
          c3_db_b = c3_bb_b;
          if (c3_db_b < 1) {
            c3_c_overflow = false;
          } else {
            c3_c_overflow = (c3_db_b > 2147483646);
          }

          if (c3_c_overflow) {
            c3_i_st.site = &c3_v_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_i_st);
          }

          c3_i9 = static_cast<uint8_T>(c3_o_n) - 1;
          for (c3_c_j = 0; c3_c_j <= c3_i9; c3_c_j++) {
            c3_yjy = c3_e_T[c3_b_jy];
            if (c3_yjy != 0.0) {
              c3_temp = c3_yjy * c3_g_alpha1;
              c3_c_ix = 0;
              c3_gb_b = c3_b_jA + 1;
              c3_i10 = c3_gb_b;
              c3_sb_a = c3_g_m;
              c3_hb_b = c3_b_jA;
              c3_i11 = c3_sb_a + c3_hb_b;
              c3_h_st.site = &c3_sc_emlrtRSI;
              c3_tb_a = c3_i10;
              c3_ib_b = c3_i11;
              c3_ub_a = c3_tb_a;
              c3_jb_b = c3_ib_b;
              if (c3_ub_a > c3_jb_b) {
                c3_e_overflow = false;
              } else {
                c3_e_overflow = (c3_jb_b > 2147483646);
              }

              if (c3_e_overflow) {
                c3_i_st.site = &c3_v_emlrtRSI;
                c3_check_forloop_overflow_error(chartInstance, &c3_i_st);
              }

              for (c3_ijA = c3_i10; c3_ijA <= c3_i11; c3_ijA++) {
                c3_e_T[c3_ijA - 1] += c3_work[c3_c_ix] * c3_temp;
                c3_vb_a = c3_c_ix + 1;
                c3_c_ix = c3_vb_a;
              }
            }

            c3_ob_a = c3_b_jy + 1;
            c3_b_jy = c3_ob_a;
            c3_qb_a = c3_b_jA + 6;
            c3_b_jA = c3_qb_a;
          }
        }
      }

      c3_g_b = c3_d_i;
      c3_i_c = 6 - c3_g_b;
      c3_j_b = c3_d_i;
      c3_j_c = 6 - c3_j_b;
      c3_r_a = c3_ip1;
      c3_m_b = c3_im1n;
      c3_k_c = c3_r_a + c3_m_b;
      c3_t_a = c3_ip1;
      c3_o_b = c3_in;
      c3_m_c = c3_t_a + c3_o_b;
      c3_c_st.site = &c3_xb_emlrtRSI;
      c3_b_xzlarf(chartInstance, &c3_c_st, c3_i_c, c3_j_c, c3_k_c, c3_tau[c3_d_i
                  - 1], c3_e_T, c3_m_c, c3_work);
      c3_e_T[(c3_ip1 + 6 * (c3_d_i - 1)) - 1] = c3_c_alpha1;
    }

    c3_st.site = &c3_rb_emlrtRSI;
    for (c3_i4 = 0; c3_i4 < 36; c3_i4++) {
      c3_V[c3_i4] = c3_e_T[c3_i4];
    }

    c3_b_st.site = &c3_yc_emlrtRSI;
    c3_n_t = (ptrdiff_t)6;
    c3_ilo_t = (ptrdiff_t)1;
    c3_ihi_t = (ptrdiff_t)6;
    c3_lda_t = (ptrdiff_t)6;
    c3_info_t = LAPACKE_dorghr(102, c3_n_t, c3_ilo_t, c3_ihi_t, &c3_V[0],
      c3_lda_t, &c3_tau[0]);
    c3_info = (int32_T)c3_info_t;
    c3_c_st.site = &c3_ad_emlrtRSI;
    c3_b_info = c3_info;
    c3_c_info = c3_b_info;
    c3_p = (c3_c_info != 0);
    if (c3_p) {
      c3_b_p = true;
      c3_val = c3_b_info;
      c3_c_p = false;
      if (c3_val == -5) {
        c3_c_p = true;
      } else if (c3_val == -7) {
        c3_c_p = true;
      }

      if (!c3_c_p) {
        if (c3_b_info == -1010) {
          c3_b_y = NULL;
          sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          c3_d_y = NULL;
          sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1,
            12), false);
          sf_mex_call(&c3_c_st, &c3_d_emlrtMCI, "error", 0U, 2U, 14, c3_b_y, 14,
                      sf_mex_call(&c3_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c3_c_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
        } else {
          c3_y = NULL;
          sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1,
            33), false);
          c3_c_y = NULL;
          sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2,
            1, 33), false);
          c3_e_y = NULL;
          sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1,
            14), false);
          c3_f_y = NULL;
          sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_b_info, 6, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call(&c3_c_st, &c3_e_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                      sf_mex_call(&c3_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c3_c_st, NULL, "message", 1U, 3U, 14, c3_c_y, 14,
                        c3_e_y, 14, c3_f_y)));
        }
      }
    } else {
      c3_b_p = false;
    }

    if (c3_b_p) {
      for (c3_i5 = 0; c3_i5 < 36; c3_i5++) {
        c3_V[c3_i5] = rtNaN;
      }
    }

    c3_st.site = &c3_sb_emlrtRSI;
    c3_d_info = c3_b_xhseqr(chartInstance, &c3_st, c3_e_T, c3_V);
    if (static_cast<real_T>(c3_d_info) != 0.0) {
      c3_st.site = &c3_tb_emlrtRSI;
      c3_b_warning(chartInstance, &c3_st);
    }
  }
}

static real_T c3_xnrm2(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36], int32_T c3_ix0)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_absxk;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_scale;
  real_T c3_t;
  real_T c3_y;
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_c;
  int32_T c3_b_ix0;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_n;
  int32_T c3_d_a;
  int32_T c3_e_a;
  int32_T c3_k;
  int32_T c3_kend;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_fc_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_c_n = c3_b_n;
  c3_b_ix0 = c3_ix0;
  c3_y = 0.0;
  if (c3_c_n < 1) {
  } else if (c3_c_n == 1) {
    c3_b_x = c3_x[c3_b_ix0 - 1];
    c3_c_x = c3_b_x;
    c3_d_x = c3_c_x;
    c3_y = muDoubleScalarAbs(c3_d_x);
  } else {
    c3_scale = 3.3121686421112381E-170;
    c3_a = c3_c_n - 1;
    c3_c = c3_a;
    c3_b_a = c3_c;
    c3_b_c = c3_b_a;
    c3_c_a = c3_b_ix0;
    c3_b = c3_b_c;
    c3_kend = c3_c_a + c3_b;
    c3_b_st.site = &c3_gc_emlrtRSI;
    c3_d_a = c3_b_ix0;
    c3_b_b = c3_kend;
    c3_e_a = c3_d_a;
    c3_c_b = c3_b_b;
    if (c3_e_a > c3_c_b) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_c_b > 2147483646);
    }

    if (c3_overflow) {
      c3_c_st.site = &c3_v_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
    }

    for (c3_k = c3_b_ix0; c3_k <= c3_kend; c3_k++) {
      c3_e_x = c3_x[c3_k - 1];
      c3_f_x = c3_e_x;
      c3_g_x = c3_f_x;
      c3_absxk = muDoubleScalarAbs(c3_g_x);
      if (c3_absxk > c3_scale) {
        c3_t = c3_scale / c3_absxk;
        c3_y = 1.0 + c3_y * c3_t * c3_t;
        c3_scale = c3_absxk;
      } else {
        c3_t = c3_absxk / c3_scale;
        c3_y += c3_t * c3_t;
      }
    }

    c3_y = c3_scale * muDoubleScalarSqrt(c3_y);
  }

  return c3_y;
}

static real_T c3_sqrt(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
                      c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_sqrt(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_xscal(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                     emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_a, real_T
                     c3_x[36], int32_T c3_ix0, real_T c3_b_x[36])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_b_xscal(chartInstance, c3_sp, c3_b_n, c3_a, c3_b_x, c3_ix0);
}

static void c3_xzlarf(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_m, int32_T c3_b_n, int32_T
                      c3_iv0, real_T c3_tau, real_T c3_u_C[36], int32_T c3_ic0,
                      real_T c3_work[6], real_T c3_v_C[36], real_T c3_b_work[6])
{
  int32_T c3_i;
  int32_T c3_i1;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_v_C[c3_i] = c3_u_C[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    c3_b_work[c3_i1] = c3_work[c3_i1];
  }

  c3_b_xzlarf(chartInstance, c3_sp, c3_m, c3_b_n, c3_iv0, c3_tau, c3_v_C, c3_ic0,
              c3_b_work);
}

static void c3_xhseqr(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_h[36], real_T c3_z[36],
                      real_T c3_d_h[36], int32_T *c3_info, real_T c3_b_z[36])
{
  int32_T c3_i;
  int32_T c3_i1;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_d_h[c3_i] = c3_h[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 36; c3_i1++) {
    c3_b_z[c3_i1] = c3_z[c3_i1];
  }

  *c3_info = c3_b_xhseqr(chartInstance, c3_sp, c3_d_h, c3_b_z);
}

static void c3_xzlarfg(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_alpha1, real_T c3_x[3], real_T
  *c3_b_alpha1, real_T c3_b_x[3], real_T *c3_tau)
{
  int32_T c3_i;
  *c3_b_alpha1 = c3_alpha1;
  for (c3_i = 0; c3_i < 3; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  *c3_tau = c3_b_xzlarfg(chartInstance, c3_sp, c3_b_n, c3_b_alpha1, c3_b_x);
}

static real_T c3_b_xnrm2(SFc3_starshotsim_devInstanceStruct *chartInstance,
  int32_T c3_b_n, real_T c3_x[3])
{
  real_T c3_absxk;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_scale;
  real_T c3_t;
  real_T c3_y;
  int32_T c3_c_n;
  int32_T c3_k;
  c3_c_n = c3_b_n;
  c3_y = 0.0;
  if (c3_c_n < 1) {
  } else if (c3_c_n == 1) {
    c3_b_x = c3_x[1];
    c3_c_x = c3_b_x;
    c3_d_x = c3_c_x;
    c3_y = muDoubleScalarAbs(c3_d_x);
  } else {
    c3_scale = 3.3121686421112381E-170;
    for (c3_k = 0; c3_k < 2; c3_k++) {
      c3_e_x = c3_x[c3_k + 1];
      c3_f_x = c3_e_x;
      c3_g_x = c3_f_x;
      c3_absxk = muDoubleScalarAbs(c3_g_x);
      if (c3_absxk > c3_scale) {
        c3_t = c3_scale / c3_absxk;
        c3_y = 1.0 + c3_y * c3_t * c3_t;
        c3_scale = c3_absxk;
      } else {
        c3_t = c3_absxk / c3_scale;
        c3_y += c3_t * c3_t;
      }
    }

    c3_y = c3_scale * muDoubleScalarSqrt(c3_y);
  }

  return c3_y;
}

static void c3_xdlanv2(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
  c3_a, real_T c3_b, real_T c3_c, real_T c3_d, real_T *c3_rt1r, real_T *c3_rt1i,
  real_T *c3_rt2r, real_T *c3_rt2i, real_T *c3_b_a, real_T *c3_b_b, real_T
  *c3_b_c, real_T *c3_b_d, real_T *c3_cs, real_T *c3_sn)
{
  real_T c3_b_d1;
  real_T c3_c_d;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  *c3_b_a = c3_a;
  *c3_b_b = c3_b;
  *c3_b_c = c3_c;
  *c3_b_d = c3_d;
  c3_b_xdlanv2(chartInstance, c3_b_a, c3_b_b, c3_b_c, c3_b_d, &c3_c_d, &c3_b_d1,
               &c3_d2, &c3_d3, &c3_d4, &c3_d5);
  *c3_sn = c3_d5;
  *c3_cs = c3_d4;
  *c3_rt2i = c3_d3;
  *c3_rt2r = c3_d2;
  *c3_rt1i = c3_b_d1;
  *c3_rt1r = c3_c_d;
}

static void c3_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                    emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36], int32_T
                    c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s, real_T
                    c3_b_x[36])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_c_xrot(chartInstance, c3_sp, c3_b_n, c3_b_x, c3_ix0, c3_iy0, c3_c, c3_s);
}

static void c3_b_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36],
                      int32_T c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s,
                      real_T c3_b_x[36])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_b_x[c3_i] = c3_x[c3_i];
  }

  c3_d_xrot(chartInstance, c3_sp, c3_b_n, c3_b_x, c3_ix0, c3_iy0, c3_c, c3_s);
}

static void c3_b_warning(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp)
{
  static char_T c3_msgID[26] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 's', 'c', 'h', 'u', 'r', '_', 'f', 'a', 'i', 'l',
    'e', 'd' };

  static char_T c3_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c3_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_msgID, 10, 0U, 1U, 0U, 2, 1, 26),
                false);
  c3_st.site = &c3_y_emlrtRSI;
  c3_d_feval(chartInstance, &c3_st, c3_y, c3_c_feval(chartInstance, &c3_st,
              c3_b_y, c3_c_y));
}

static void c3_getExpmParams(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_ib_A[36], real_T c3_A2[36], real_T c3_A4[36],
  real_T c3_A6[36], int32_T *c3_m, real_T *c3_s)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_s_y = NULL;
  const mxArray *c3_t_y = NULL;
  const mxArray *c3_u_y = NULL;
  const mxArray *c3_v_y = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_b_dv[36];
  real_T c3_e_T[36];
  real_T c3_scaledT[36];
  real_T c3_a;
  real_T c3_ab_a;
  real_T c3_ab_x;
  real_T c3_ab_y;
  real_T c3_ac_x;
  real_T c3_ad_x;
  real_T c3_alpha;
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_alpha;
  real_T c3_b_b;
  real_T c3_b_d1;
  real_T c3_b_d8;
  real_T c3_b_e;
  real_T c3_b_f;
  real_T c3_b_s;
  real_T c3_b_t;
  real_T c3_b_varargin_1;
  real_T c3_b_varargin_2;
  real_T c3_b_x;
  real_T c3_bb_a;
  real_T c3_bb_x;
  real_T c3_bb_y;
  real_T c3_bc_x;
  real_T c3_bd_x;
  real_T c3_c;
  real_T c3_c_a;
  real_T c3_c_alpha;
  real_T c3_c_b;
  real_T c3_c_t;
  real_T c3_c_varargin_1;
  real_T c3_c_varargin_2;
  real_T c3_c_x;
  real_T c3_cb_a;
  real_T c3_cb_x;
  real_T c3_cb_y;
  real_T c3_cc_x;
  real_T c3_cd_x;
  real_T c3_d;
  real_T c3_d10;
  real_T c3_d4;
  real_T c3_d6;
  real_T c3_d_a;
  real_T c3_d_alpha;
  real_T c3_d_b;
  real_T c3_d_varargin_1;
  real_T c3_d_varargin_2;
  real_T c3_d_x;
  real_T c3_db_a;
  real_T c3_db_x;
  real_T c3_db_y;
  real_T c3_dc_x;
  real_T c3_dd_x;
  real_T c3_e;
  real_T c3_e_a;
  real_T c3_e_alpha;
  real_T c3_e_b;
  real_T c3_e_varargin_1;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_eb_a;
  real_T c3_eb_x;
  real_T c3_eb_y;
  real_T c3_ec_x;
  real_T c3_ed_x;
  real_T c3_eta1;
  real_T c3_eta3;
  real_T c3_eta4;
  real_T c3_eta5;
  real_T c3_f;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_f_t;
  real_T c3_f_varargin_1;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_fb_a;
  real_T c3_fb_x;
  real_T c3_fb_y;
  real_T c3_fc_x;
  real_T c3_fd_x;
  real_T c3_fdbl;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_g_t;
  real_T c3_g_varargin_1;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_gb_a;
  real_T c3_gb_x;
  real_T c3_gb_y;
  real_T c3_gc_x;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_h_varargin_1;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_hb_a;
  real_T c3_hb_x;
  real_T c3_hb_y;
  real_T c3_hc_x;
  real_T c3_i_t;
  real_T c3_i_varargin_1;
  real_T c3_i_x;
  real_T c3_ib_x;
  real_T c3_ib_y;
  real_T c3_ic_x;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_j_varargin_1;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_jb_x;
  real_T c3_jb_y;
  real_T c3_jc_x;
  real_T c3_k_a;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_kb_a;
  real_T c3_kb_x;
  real_T c3_kb_y;
  real_T c3_kc_x;
  real_T c3_m_a;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_mb_a;
  real_T c3_mb_x;
  real_T c3_mb_y;
  real_T c3_mc_x;
  real_T c3_o_a;
  real_T c3_o_x;
  real_T c3_o_y;
  real_T c3_ob_a;
  real_T c3_ob_x;
  real_T c3_ob_y;
  real_T c3_oc_x;
  real_T c3_p_a;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_pb_a;
  real_T c3_pb_x;
  real_T c3_pb_y;
  real_T c3_pc_x;
  real_T c3_q_a;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_qb_a;
  real_T c3_qb_x;
  real_T c3_qb_y;
  real_T c3_qc_x;
  real_T c3_r_a;
  real_T c3_r_x;
  real_T c3_r_y;
  real_T c3_rb_a;
  real_T c3_rb_x;
  real_T c3_rb_y;
  real_T c3_rc_x;
  real_T c3_s_a;
  real_T c3_s_x;
  real_T c3_sb_a;
  real_T c3_sb_x;
  real_T c3_sc_x;
  real_T c3_t;
  real_T c3_t_a;
  real_T c3_t_x;
  real_T c3_tb_a;
  real_T c3_tb_x;
  real_T c3_tc_x;
  real_T c3_u_a;
  real_T c3_u_x;
  real_T c3_ub_x;
  real_T c3_uc_x;
  real_T c3_v_a;
  real_T c3_v_x;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_vb_x;
  real_T c3_vc_x;
  real_T c3_w_a;
  real_T c3_w_x;
  real_T c3_w_y;
  real_T c3_wb_x;
  real_T c3_wc_x;
  real_T c3_x;
  real_T c3_x_a;
  real_T c3_x_x;
  real_T c3_x_y;
  real_T c3_xb_x;
  real_T c3_xc_x;
  real_T c3_y_a;
  real_T c3_y_x;
  real_T c3_y_y;
  real_T c3_yb_x;
  real_T c3_yc_x;
  int32_T c3_b_k;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_eint;
  int32_T c3_f_k;
  int32_T c3_g_k;
  int32_T c3_h_k;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i_k;
  int32_T c3_j_k;
  int32_T c3_k;
  boolean_T c3_b_b1;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_f_p;
  boolean_T c3_g_p;
  boolean_T c3_guard1;
  boolean_T c3_guard2;
  boolean_T c3_guard3;
  boolean_T c3_guard4;
  boolean_T c3_h_p;
  boolean_T c3_i_p;
  boolean_T c3_j_p;
  boolean_T c3_k_b;
  boolean_T c3_k_p;
  boolean_T c3_m_b;
  boolean_T c3_m_p;
  boolean_T c3_o_b;
  boolean_T c3_p;
  boolean_T c3_p_b;
  boolean_T c3_q_b;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  *c3_s = 0.0;
  for (c3_i = 0; c3_i < 6; c3_i++) {
    c3_i2 = 0;
    for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
      c3_A2[c3_i2 + c3_i] = 0.0;
      c3_i8 = 0;
      for (c3_i10 = 0; c3_i10 < 6; c3_i10++) {
        c3_A2[c3_i2 + c3_i] += c3_ib_A[c3_i8 + c3_i] * c3_ib_A[c3_i10 + c3_i2];
        c3_i8 += 6;
      }

      c3_i2 += 6;
    }
  }

  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    c3_i5 = 0;
    for (c3_i6 = 0; c3_i6 < 6; c3_i6++) {
      c3_A4[c3_i5 + c3_i1] = 0.0;
      c3_i11 = 0;
      for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
        c3_A4[c3_i5 + c3_i1] += c3_A2[c3_i11 + c3_i1] * c3_A2[c3_i12 + c3_i5];
        c3_i11 += 6;
      }

      c3_i5 += 6;
    }
  }

  for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
    c3_i7 = 0;
    for (c3_i9 = 0; c3_i9 < 6; c3_i9++) {
      c3_A6[c3_i7 + c3_i4] = 0.0;
      c3_i13 = 0;
      for (c3_i14 = 0; c3_i14 < 6; c3_i14++) {
        c3_A6[c3_i7 + c3_i4] += c3_A4[c3_i13 + c3_i4] * c3_A2[c3_i14 + c3_i7];
        c3_i13 += 6;
      }

      c3_i7 += 6;
    }
  }

  c3_st.site = &c3_me_emlrtRSI;
  c3_a = c3_norm(chartInstance, c3_A4);
  c3_b_st.site = &c3_s_emlrtRSI;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_d_a = c3_c_a;
  c3_e_a = c3_d_a;
  c3_p = (c3_e_a < 0.0);
  if (c3_p) {
    c3_b_p = true;
  } else {
    c3_b_p = false;
  }

  c3_c_p = c3_b_p;
  if (c3_c_p) {
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_b_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_y, 14,
                sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_b_st, NULL, "message", 1U, 1U, 14, c3_b_y)));
  }

  c3_f_a = c3_b_a;
  c3_g_a = c3_f_a;
  c3_d4 = muDoubleScalarPower(c3_g_a, 0.25);
  c3_st.site = &c3_oe_emlrtRSI;
  c3_h_a = c3_norm(chartInstance, c3_A6);
  c3_b_st.site = &c3_s_emlrtRSI;
  c3_j_a = c3_h_a;
  c3_k_a = c3_j_a;
  c3_m_a = c3_k_a;
  c3_o_a = c3_m_a;
  c3_d_p = (c3_o_a < 0.0);
  if (c3_d_p) {
    c3_e_p = true;
  } else {
    c3_e_p = false;
  }

  c3_f_p = c3_e_p;
  if (c3_f_p) {
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_b_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_c_y, 14,
                sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_b_st, NULL, "message", 1U, 1U, 14, c3_d_y)));
  }

  c3_p_a = c3_j_a;
  c3_q_a = c3_p_a;
  c3_d6 = muDoubleScalarPower(c3_q_a, 0.16666666666666666);
  c3_varargin_1 = c3_d4;
  c3_varargin_2 = c3_d6;
  c3_x = c3_varargin_1;
  c3_e_y = c3_varargin_2;
  c3_b_x = c3_x;
  c3_f_y = c3_e_y;
  c3_c_x = c3_b_x;
  c3_g_y = c3_f_y;
  c3_r_a = c3_c_x;
  c3_b = c3_g_y;
  c3_d_x = c3_r_a;
  c3_h_y = c3_b;
  c3_e_x = c3_d_x;
  c3_j_y = c3_h_y;
  c3_eta1 = muDoubleScalarMax(c3_e_x, c3_j_y);
  c3_guard1 = false;
  c3_guard2 = false;
  c3_guard3 = false;
  c3_guard4 = false;
  if (c3_eta1 <= 0.01495585217958292) {
    c3_st.site = &c3_pe_emlrtRSI;
    c3_b_st.site = &c3_xe_emlrtRSI;
    c3_c_st.site = &c3_s_emlrtRSI;
    for (c3_k = 0; c3_k < 36; c3_k++) {
      c3_b_k = c3_k;
      c3_f_x = c3_ib_A[c3_b_k];
      c3_k_y = muDoubleScalarAbs(c3_f_x);
      c3_scaledT[c3_b_k] = c3_k_y;
    }

    for (c3_i15 = 0; c3_i15 < 36; c3_i15++) {
      c3_scaledT[c3_i15] *= 0.19285012468241128;
    }

    c3_b_st.site = &c3_ye_emlrtRSI;
    c3_c_st.site = &c3_bf_emlrtRSI;
    c3_mpower(chartInstance, &c3_c_st, c3_scaledT, 7.0, c3_b_dv);
    c3_m_y = c3_norm(chartInstance, c3_b_dv);
    c3_alpha = c3_m_y / c3_norm(chartInstance, c3_ib_A);
    c3_b_st.site = &c3_af_emlrtRSI;
    c3_h_x = c3_log2(chartInstance, 2.0 * c3_alpha / 2.2204460492503131E-16) /
      6.0;
    c3_j_x = c3_h_x;
    c3_b_varargin_1 = c3_j_x;
    c3_b_varargin_1 = muDoubleScalarCeil(c3_b_varargin_1);
    c3_m_x = c3_b_varargin_1;
    c3_p_x = c3_m_x;
    c3_q_x = c3_p_x;
    c3_db_a = c3_q_x;
    c3_t_x = c3_db_a;
    c3_w_x = c3_t_x;
    c3_t = muDoubleScalarMax(c3_w_x, 0.0);
    if (c3_t == 0.0) {
      *c3_m = 3;
    } else {
      c3_guard4 = true;
    }
  } else {
    c3_guard4 = true;
  }

  if (c3_guard4) {
    if (c3_eta1 <= 0.253939833006323) {
      c3_st.site = &c3_qe_emlrtRSI;
      c3_b_st.site = &c3_xe_emlrtRSI;
      c3_c_st.site = &c3_s_emlrtRSI;
      for (c3_c_k = 0; c3_c_k < 36; c3_c_k++) {
        c3_d_k = c3_c_k;
        c3_g_x = c3_ib_A[c3_d_k];
        c3_o_y = muDoubleScalarAbs(c3_g_x);
        c3_scaledT[c3_d_k] = c3_o_y;
      }

      for (c3_i17 = 0; c3_i17 < 36; c3_i17++) {
        c3_scaledT[c3_i17] *= 0.12321872304378752;
      }

      c3_b_st.site = &c3_ye_emlrtRSI;
      c3_c_st.site = &c3_bf_emlrtRSI;
      c3_mpower(chartInstance, &c3_c_st, c3_scaledT, 11.0, c3_b_dv);
      c3_p_y = c3_norm(chartInstance, c3_b_dv);
      c3_b_alpha = c3_p_y / c3_norm(chartInstance, c3_ib_A);
      c3_b_st.site = &c3_af_emlrtRSI;
      c3_k_x = c3_log2(chartInstance, 2.0 * c3_b_alpha / 2.2204460492503131E-16)
        / 10.0;
      c3_o_x = c3_k_x;
      c3_c_varargin_1 = c3_o_x;
      c3_c_varargin_1 = muDoubleScalarCeil(c3_c_varargin_1);
      c3_s_x = c3_c_varargin_1;
      c3_v_x = c3_s_x;
      c3_x_x = c3_v_x;
      c3_gb_a = c3_x_x;
      c3_ab_x = c3_gb_a;
      c3_cb_x = c3_ab_x;
      c3_b_t = muDoubleScalarMax(c3_cb_x, 0.0);
      if (c3_b_t == 0.0) {
        *c3_m = 5;
      } else {
        c3_guard3 = true;
      }
    } else {
      c3_guard3 = true;
    }
  }

  if (c3_guard3) {
    c3_st.site = &c3_re_emlrtRSI;
    c3_b_st.site = &c3_re_emlrtRSI;
    c3_c_st.site = &c3_bf_emlrtRSI;
    c3_mpower(chartInstance, &c3_c_st, c3_A4, 2.0, c3_b_dv);
    c3_s_a = c3_norm(chartInstance, c3_b_dv);
    c3_b_st.site = &c3_s_emlrtRSI;
    c3_t_a = c3_s_a;
    c3_v_a = c3_t_a;
    c3_w_a = c3_v_a;
    c3_y_a = c3_w_a;
    c3_g_p = (c3_y_a < 0.0);
    if (c3_g_p) {
      c3_h_p = true;
    } else {
      c3_h_p = false;
    }

    c3_j_p = c3_h_p;
    if (c3_j_p) {
      c3_s_y = NULL;
      sf_mex_assign(&c3_s_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                    false);
      c3_t_y = NULL;
      sf_mex_assign(&c3_t_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                    false);
      sf_mex_call(&c3_b_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_s_y, 14,
                  sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c3_b_st, NULL, "message", 1U, 1U, 14, c3_t_y)));
    }

    c3_eb_a = c3_t_a;
    c3_fb_a = c3_eb_a;
    c3_b_d8 = muDoubleScalarPower(c3_fb_a, 0.125);
    c3_e_varargin_1 = c3_d6;
    c3_b_varargin_2 = c3_b_d8;
    c3_eb_x = c3_e_varargin_1;
    c3_w_y = c3_b_varargin_2;
    c3_gb_x = c3_eb_x;
    c3_x_y = c3_w_y;
    c3_jb_x = c3_gb_x;
    c3_ab_y = c3_x_y;
    c3_ob_a = c3_jb_x;
    c3_b_b = c3_ab_y;
    c3_ob_x = c3_ob_a;
    c3_db_y = c3_b_b;
    c3_pb_x = c3_ob_x;
    c3_eb_y = c3_db_y;
    c3_eta3 = muDoubleScalarMax(c3_pb_x, c3_eb_y);
    if (c3_eta3 <= 0.95041789961629319) {
      c3_st.site = &c3_se_emlrtRSI;
      c3_b_st.site = &c3_xe_emlrtRSI;
      c3_c_st.site = &c3_s_emlrtRSI;
      for (c3_g_k = 0; c3_g_k < 36; c3_g_k++) {
        c3_h_k = c3_g_k;
        c3_ub_x = c3_ib_A[c3_h_k];
        c3_jb_y = muDoubleScalarAbs(c3_ub_x);
        c3_scaledT[c3_h_k] = c3_jb_y;
      }

      for (c3_i23 = 0; c3_i23 < 36; c3_i23++) {
        c3_scaledT[c3_i23] *= 0.090475336558796943;
      }

      c3_b_st.site = &c3_ye_emlrtRSI;
      c3_c_st.site = &c3_bf_emlrtRSI;
      c3_mpower(chartInstance, &c3_c_st, c3_scaledT, 15.0, c3_b_dv);
      c3_mb_y = c3_norm(chartInstance, c3_b_dv);
      c3_d_alpha = c3_mb_y / c3_norm(chartInstance, c3_ib_A);
      c3_b_st.site = &c3_af_emlrtRSI;
      c3_xb_x = c3_log2(chartInstance, 2.0 * c3_d_alpha / 2.2204460492503131E-16)
        / 14.0;
      c3_ac_x = c3_xb_x;
      c3_h_varargin_1 = c3_ac_x;
      c3_h_varargin_1 = muDoubleScalarCeil(c3_h_varargin_1);
      c3_bc_x = c3_h_varargin_1;
      c3_dc_x = c3_bc_x;
      c3_fc_x = c3_dc_x;
      c3_rb_a = c3_fc_x;
      c3_gc_x = c3_rb_a;
      c3_ic_x = c3_gc_x;
      c3_f_t = muDoubleScalarMax(c3_ic_x, 0.0);
      if (c3_f_t == 0.0) {
        *c3_m = 7;
      } else {
        c3_guard2 = true;
      }
    } else {
      c3_guard2 = true;
    }
  }

  if (c3_guard2) {
    if (c3_eta3 <= 2.097847961257068) {
      c3_st.site = &c3_te_emlrtRSI;
      c3_b_st.site = &c3_xe_emlrtRSI;
      c3_c_st.site = &c3_s_emlrtRSI;
      for (c3_e_k = 0; c3_e_k < 36; c3_e_k++) {
        c3_f_k = c3_e_k;
        c3_i_x = c3_ib_A[c3_f_k];
        c3_q_y = muDoubleScalarAbs(c3_i_x);
        c3_scaledT[c3_f_k] = c3_q_y;
      }

      for (c3_i20 = 0; c3_i20 < 36; c3_i20++) {
        c3_scaledT[c3_i20] *= 0.071467735648795785;
      }

      c3_b_st.site = &c3_ye_emlrtRSI;
      c3_c_st.site = &c3_bf_emlrtRSI;
      c3_mpower(chartInstance, &c3_c_st, c3_scaledT, 19.0, c3_b_dv);
      c3_r_y = c3_norm(chartInstance, c3_b_dv);
      c3_c_alpha = c3_r_y / c3_norm(chartInstance, c3_ib_A);
      c3_b_st.site = &c3_af_emlrtRSI;
      c3_r_x = c3_log2(chartInstance, 2.0 * c3_c_alpha / 2.2204460492503131E-16)
        / 18.0;
      c3_u_x = c3_r_x;
      c3_d_varargin_1 = c3_u_x;
      c3_d_varargin_1 = muDoubleScalarCeil(c3_d_varargin_1);
      c3_y_x = c3_d_varargin_1;
      c3_bb_x = c3_y_x;
      c3_db_x = c3_bb_x;
      c3_mb_a = c3_db_x;
      c3_fb_x = c3_mb_a;
      c3_ib_x = c3_fb_x;
      c3_c_t = muDoubleScalarMax(c3_ib_x, 0.0);
      if (c3_c_t == 0.0) {
        *c3_m = 9;
      } else {
        c3_guard1 = true;
      }
    } else {
      c3_guard1 = true;
    }
  }

  if (c3_guard1) {
    for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
      c3_i18 = 0;
      for (c3_i19 = 0; c3_i19 < 6; c3_i19++) {
        c3_scaledT[c3_i18 + c3_i16] = 0.0;
        c3_i21 = 0;
        for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
          c3_scaledT[c3_i18 + c3_i16] += c3_A4[c3_i21 + c3_i16] * c3_A6[c3_i22 +
            c3_i18];
          c3_i21 += 6;
        }

        c3_i18 += 6;
      }
    }

    c3_st.site = &c3_ue_emlrtRSI;
    c3_u_a = c3_norm(chartInstance, c3_scaledT);
    c3_b_st.site = &c3_s_emlrtRSI;
    c3_x_a = c3_u_a;
    c3_ab_a = c3_x_a;
    c3_bb_a = c3_ab_a;
    c3_cb_a = c3_bb_a;
    c3_i_p = (c3_cb_a < 0.0);
    if (c3_i_p) {
      c3_k_p = true;
    } else {
      c3_k_p = false;
    }

    c3_m_p = c3_k_p;
    if (c3_m_p) {
      c3_u_y = NULL;
      sf_mex_assign(&c3_u_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                    false);
      c3_v_y = NULL;
      sf_mex_assign(&c3_v_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                    false);
      sf_mex_call(&c3_b_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_u_y, 14,
                  sf_mex_call(&c3_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c3_b_st, NULL, "message", 1U, 1U, 14, c3_v_y)));
    }

    c3_hb_a = c3_x_a;
    c3_kb_a = c3_hb_a;
    c3_d10 = muDoubleScalarPower(c3_kb_a, 0.1);
    c3_f_varargin_1 = c3_b_d8;
    c3_c_varargin_2 = c3_d10;
    c3_hb_x = c3_f_varargin_1;
    c3_y_y = c3_c_varargin_2;
    c3_kb_x = c3_hb_x;
    c3_bb_y = c3_y_y;
    c3_mb_x = c3_kb_x;
    c3_cb_y = c3_bb_y;
    c3_pb_a = c3_mb_x;
    c3_c_b = c3_cb_y;
    c3_qb_x = c3_pb_a;
    c3_fb_y = c3_c_b;
    c3_rb_x = c3_qb_x;
    c3_gb_y = c3_fb_y;
    c3_eta4 = muDoubleScalarMax(c3_rb_x, c3_gb_y);
    c3_g_varargin_1 = c3_eta3;
    c3_d_varargin_2 = c3_eta4;
    c3_sb_x = c3_g_varargin_1;
    c3_hb_y = c3_d_varargin_2;
    c3_tb_x = c3_sb_x;
    c3_ib_y = c3_hb_y;
    c3_vb_x = c3_tb_x;
    c3_kb_y = c3_ib_y;
    c3_qb_a = c3_vb_x;
    c3_d_b = c3_kb_y;
    c3_wb_x = c3_qb_a;
    c3_ob_y = c3_d_b;
    c3_yb_x = c3_wb_x;
    c3_pb_y = c3_ob_y;
    c3_eta5 = muDoubleScalarMin(c3_yb_x, c3_pb_y);
    c3_st.site = &c3_ve_emlrtRSI;
    c3_cc_x = c3_log2(chartInstance, c3_eta5 / 5.3719203511481517);
    c3_ec_x = c3_cc_x;
    c3_i_varargin_1 = c3_ec_x;
    c3_i_varargin_1 = muDoubleScalarCeil(c3_i_varargin_1);
    c3_hc_x = c3_i_varargin_1;
    c3_jc_x = c3_hc_x;
    c3_kc_x = c3_jc_x;
    c3_sb_a = c3_kc_x;
    c3_mc_x = c3_sb_a;
    c3_oc_x = c3_mc_x;
    *c3_s = muDoubleScalarMax(c3_oc_x, 0.0);
    c3_st.site = &c3_we_emlrtRSI;
    c3_e_b = *c3_s;
    c3_b_st.site = &c3_r_emlrtRSI;
    c3_f_b = c3_e_b;
    c3_c_st.site = &c3_s_emlrtRSI;
    c3_g_b = c3_f_b;
    c3_h_b = c3_g_b;
    c3_j_b = c3_h_b;
    c3_c = muDoubleScalarPower(2.0, c3_j_b);
    c3_st.site = &c3_we_emlrtRSI;
    for (c3_i24 = 0; c3_i24 < 36; c3_i24++) {
      c3_e_T[c3_i24] = c3_ib_A[c3_i24] / c3_c;
    }

    c3_b_st.site = &c3_xe_emlrtRSI;
    c3_c_st.site = &c3_s_emlrtRSI;
    for (c3_i_k = 0; c3_i_k < 36; c3_i_k++) {
      c3_j_k = c3_i_k;
      c3_pc_x = c3_e_T[c3_j_k];
      c3_qb_y = muDoubleScalarAbs(c3_pc_x);
      c3_scaledT[c3_j_k] = c3_qb_y;
    }

    for (c3_i25 = 0; c3_i25 < 36; c3_i25++) {
      c3_scaledT[c3_i25] *= 0.05031554467093536;
    }

    c3_b_st.site = &c3_ye_emlrtRSI;
    c3_c_st.site = &c3_bf_emlrtRSI;
    c3_mpower(chartInstance, &c3_c_st, c3_scaledT, 27.0, c3_b_dv);
    c3_rb_y = c3_norm(chartInstance, c3_b_dv);
    c3_e_alpha = c3_rb_y / c3_norm(chartInstance, c3_e_T);
    c3_b_st.site = &c3_af_emlrtRSI;
    c3_qc_x = c3_log2(chartInstance, 2.0 * c3_e_alpha / 2.2204460492503131E-16) /
      26.0;
    c3_rc_x = c3_qc_x;
    c3_j_varargin_1 = c3_rc_x;
    c3_j_varargin_1 = muDoubleScalarCeil(c3_j_varargin_1);
    c3_sc_x = c3_j_varargin_1;
    c3_tc_x = c3_sc_x;
    c3_uc_x = c3_tc_x;
    c3_tb_a = c3_uc_x;
    c3_vc_x = c3_tb_a;
    c3_wc_x = c3_vc_x;
    c3_g_t = muDoubleScalarMax(c3_wc_x, 0.0);
    *c3_s += c3_g_t;
    c3_xc_x = *c3_s;
    c3_k_b = muDoubleScalarIsInf(c3_xc_x);
    if (c3_k_b) {
      c3_yc_x = c3_norm(chartInstance, c3_ib_A) / 5.3719203511481517;
      c3_ad_x = c3_yc_x;
      c3_bd_x = c3_ad_x;
      c3_cd_x = c3_bd_x;
      c3_dd_x = c3_cd_x;
      c3_ed_x = c3_dd_x;
      c3_m_b = muDoubleScalarIsInf(c3_ed_x);
      c3_o_b = !c3_m_b;
      c3_fd_x = c3_dd_x;
      c3_p_b = muDoubleScalarIsNaN(c3_fd_x);
      c3_b_b1 = !c3_p_b;
      c3_q_b = (c3_o_b && c3_b_b1);
      if (c3_q_b) {
        c3_fdbl = frexp(c3_cd_x, &c3_eint);
        c3_f = c3_fdbl;
        c3_e = static_cast<real_T>(c3_eint);
      } else {
        c3_f = c3_cd_x;
        c3_e = 0.0;
      }

      c3_d = c3_f;
      c3_b_d1 = c3_e;
      c3_b_f = c3_d;
      c3_b_e = c3_b_d1;
      c3_i_t = c3_b_f;
      c3_b_s = c3_b_e;
      *c3_s = c3_b_s;
      if (c3_i_t == 0.5) {
        *c3_s = c3_b_s - 1.0;
      }
    }

    *c3_m = 13;
  }
}

static real_T c3_norm(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
                      c3_x[36])
{
  real_T c3_b_i;
  real_T c3_b_j;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_s;
  real_T c3_y;
  int32_T c3_i;
  int32_T c3_j;
  boolean_T c3_b;
  boolean_T c3_exitg1;
  c3_y = 0.0;
  c3_j = 0;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_j < 6)) {
    c3_b_j = static_cast<real_T>(c3_j) + 1.0;
    c3_s = 0.0;
    for (c3_i = 0; c3_i < 6; c3_i++) {
      c3_b_i = static_cast<real_T>(c3_i) + 1.0;
      c3_c_x = c3_x[(static_cast<int32_T>(c3_b_i) + 6 * (static_cast<int32_T>
        (c3_b_j) - 1)) - 1];
      c3_d_x = c3_c_x;
      c3_e_x = c3_d_x;
      c3_b_y = muDoubleScalarAbs(c3_e_x);
      c3_s += c3_b_y;
    }

    c3_b_x = c3_s;
    c3_b = muDoubleScalarIsNaN(c3_b_x);
    if (c3_b) {
      c3_y = rtNaN;
      c3_exitg1 = true;
    } else {
      if (c3_s > c3_y) {
        c3_y = c3_s;
      }

      c3_j++;
    }
  }

  return c3_y;
}

static void c3_mpower(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, real_T c3_a[36], real_T c3_b, real_T
                      c3_c[36])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_st;
  real_T c3_aBuffer[36];
  real_T c3_b_a[36];
  real_T c3_cBuffer[36];
  real_T c3_x_data[36];
  real_T c3_b_b;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_b;
  real_T c3_c_x;
  real_T c3_d_b;
  real_T c3_d_x;
  real_T c3_e;
  real_T c3_e_b;
  real_T c3_e_x;
  real_T c3_ed2;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_m_x;
  real_T c3_o_x;
  real_T c3_x;
  real_T c3_y;
  int32_T c3_b_i58;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_b_n;
  int32_T c3_b_nb;
  int32_T c3_c_k;
  int32_T c3_c_n;
  int32_T c3_exitg1;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i59;
  int32_T c3_i6;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i7;
  int32_T c3_i70;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_k_b;
  int32_T c3_m_b;
  int32_T c3_nbitson;
  boolean_T c3_aBufferInUse;
  boolean_T c3_assignToBuffer;
  boolean_T c3_b_aBufferInUse;
  boolean_T c3_b_b1;
  boolean_T c3_b_cBufferInUse;
  boolean_T c3_b_p;
  boolean_T c3_cBufferInUse;
  boolean_T c3_c_aBufferInUse;
  boolean_T c3_c_cBufferInUse;
  boolean_T c3_d_aBufferInUse;
  boolean_T c3_d_cBufferInUse;
  boolean_T c3_e_aBufferInUse;
  boolean_T c3_f_aBufferInUse;
  boolean_T c3_f_b;
  boolean_T c3_first;
  boolean_T c3_firstmult;
  boolean_T c3_g_b;
  boolean_T c3_h_b;
  boolean_T c3_j_b;
  boolean_T c3_lsb;
  boolean_T c3_o_b;
  boolean_T c3_overflow;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_cf_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_b_b = c3_b;
  c3_b_st.site = &c3_df_emlrtRSI;
  c3_c_b = c3_b_b;
  c3_x = c3_c_b;
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  c3_y = muDoubleScalarAbs(c3_c_x);
  if (c3_y <= 2.147483647E+9) {
    c3_c_st.site = &c3_ef_emlrtRSI;
    for (c3_i1 = 0; c3_i1 < 36; c3_i1++) {
      c3_b_a[c3_i1] = c3_a[c3_i1];
    }

    c3_e_b = c3_c_b;
    c3_f_x = c3_e_b;
    c3_g_x = c3_f_x;
    c3_h_x = c3_g_x;
    c3_b_y = muDoubleScalarAbs(c3_h_x);
    c3_b_n = static_cast<int32_T>(c3_b_y);
    c3_c_n = c3_b_n;
    c3_nbitson = 0;
    c3_b_nb = -1;
    while (c3_c_n > 0) {
      c3_b_nb++;
      if ((c3_c_n & 1) != 0) {
        c3_nbitson++;
      }

      c3_c_n >>= 1;
    }

    if (c3_b_n <= 2) {
      if (c3_e_b == 2.0) {
        for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
          c3_i5 = 0;
          for (c3_i6 = 0; c3_i6 < 6; c3_i6++) {
            c3_c[c3_i5 + c3_i3] = 0.0;
            c3_i10 = 0;
            for (c3_i13 = 0; c3_i13 < 6; c3_i13++) {
              c3_c[c3_i5 + c3_i3] += c3_b_a[c3_i10 + c3_i3] * c3_b_a[c3_i13 +
                c3_i5];
              c3_i10 += 6;
            }

            c3_i5 += 6;
          }
        }
      } else {
        c3_d_st.site = &c3_gf_emlrtRSI;
        for (c3_i4 = 0; c3_i4 < 36; c3_i4++) {
          c3_x_data[c3_i4] = c3_b_a[c3_i4];
        }

        c3_p = false;
        for (c3_k = 0; c3_k < 36; c3_k++) {
          c3_b_k = c3_k;
          if (c3_p) {
            c3_b_p = true;
          } else {
            c3_o_x = c3_x_data[c3_b_k];
            c3_o_b = muDoubleScalarIsNaN(c3_o_x);
            if (c3_o_b) {
              c3_b_p = true;
            } else {
              c3_b_p = false;
            }
          }

          c3_p = c3_b_p;
        }

        if (c3_p) {
          for (c3_i12 = 0; c3_i12 < 36; c3_i12++) {
            c3_c[c3_i12] = rtNaN;
          }
        } else {
          for (c3_i11 = 0; c3_i11 < 36; c3_i11++) {
            c3_c[c3_i11] = 0.0;
          }

          for (c3_j = 0; c3_j < 6; c3_j++) {
            c3_b_j = c3_j;
            c3_c[c3_b_j + 6 * c3_b_j] = 1.0;
          }
        }
      }
    } else {
      c3_first = true;
      c3_aBufferInUse = false;
      c3_lsb = ((c3_nbitson & 1) != 0);
      if (!c3_lsb) {
        c3_cBufferInUse = true;
      } else {
        c3_cBufferInUse = false;
      }

      c3_b_cBufferInUse = c3_cBufferInUse;
      c3_i9 = c3_b_nb;
      c3_d_st.site = &c3_ff_emlrtRSI;
      c3_k_b = c3_i9;
      c3_m_b = c3_k_b;
      if (c3_m_b < 1) {
        c3_overflow = false;
      } else {
        c3_overflow = (c3_m_b > 2147483646);
      }

      if (c3_overflow) {
        c3_e_st.site = &c3_v_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_e_st);
      }

      for (c3_c_k = 0; c3_c_k < c3_i9; c3_c_k++) {
        if ((c3_b_n & 1) != 0) {
          if (c3_first) {
            c3_first = false;
            c3_assignToBuffer = c3_b_cBufferInUse;
            c3_f_aBufferInUse = c3_aBufferInUse;
            if (c3_assignToBuffer) {
              if (c3_f_aBufferInUse) {
                for (c3_i42 = 0; c3_i42 < 36; c3_i42++) {
                  c3_cBuffer[c3_i42] = c3_aBuffer[c3_i42];
                }
              } else {
                for (c3_i41 = 0; c3_i41 < 36; c3_i41++) {
                  c3_cBuffer[c3_i41] = c3_b_a[c3_i41];
                }
              }
            } else if (c3_f_aBufferInUse) {
              for (c3_i40 = 0; c3_i40 < 36; c3_i40++) {
                c3_c[c3_i40] = c3_aBuffer[c3_i40];
              }
            } else {
              for (c3_i39 = 0; c3_i39 < 36; c3_i39++) {
                c3_c[c3_i39] = c3_b_a[c3_i39];
              }
            }
          } else {
            c3_c_cBufferInUse = c3_b_cBufferInUse;
            c3_d_aBufferInUse = c3_aBufferInUse;
            c3_d_cBufferInUse = c3_c_cBufferInUse;
            if (c3_d_aBufferInUse) {
              if (c3_d_cBufferInUse) {
                for (c3_i38 = 0; c3_i38 < 6; c3_i38++) {
                  c3_i52 = 0;
                  for (c3_b_i58 = 0; c3_b_i58 < 6; c3_b_i58++) {
                    c3_c[c3_i52 + c3_i38] = 0.0;
                    c3_i66 = 0;
                    for (c3_i70 = 0; c3_i70 < 6; c3_i70++) {
                      c3_c[c3_i52 + c3_i38] += c3_cBuffer[c3_i66 + c3_i38] *
                        c3_aBuffer[c3_i70 + c3_i52];
                      c3_i66 += 6;
                    }

                    c3_i52 += 6;
                  }
                }
              } else {
                for (c3_i37 = 0; c3_i37 < 6; c3_i37++) {
                  c3_i51 = 0;
                  for (c3_i57 = 0; c3_i57 < 6; c3_i57++) {
                    c3_cBuffer[c3_i51 + c3_i37] = 0.0;
                    c3_i65 = 0;
                    for (c3_i69 = 0; c3_i69 < 6; c3_i69++) {
                      c3_cBuffer[c3_i51 + c3_i37] += c3_c[c3_i65 + c3_i37] *
                        c3_aBuffer[c3_i69 + c3_i51];
                      c3_i65 += 6;
                    }

                    c3_i51 += 6;
                  }
                }
              }
            } else if (c3_d_cBufferInUse) {
              for (c3_i36 = 0; c3_i36 < 6; c3_i36++) {
                c3_i50 = 0;
                for (c3_i56 = 0; c3_i56 < 6; c3_i56++) {
                  c3_c[c3_i50 + c3_i36] = 0.0;
                  c3_i64 = 0;
                  for (c3_i68 = 0; c3_i68 < 6; c3_i68++) {
                    c3_c[c3_i50 + c3_i36] += c3_cBuffer[c3_i64 + c3_i36] *
                      c3_b_a[c3_i68 + c3_i50];
                    c3_i64 += 6;
                  }

                  c3_i50 += 6;
                }
              }
            } else {
              for (c3_i35 = 0; c3_i35 < 6; c3_i35++) {
                c3_i49 = 0;
                for (c3_i55 = 0; c3_i55 < 6; c3_i55++) {
                  c3_cBuffer[c3_i49 + c3_i35] = 0.0;
                  c3_i63 = 0;
                  for (c3_i67 = 0; c3_i67 < 6; c3_i67++) {
                    c3_cBuffer[c3_i49 + c3_i35] += c3_c[c3_i63 + c3_i35] *
                      c3_b_a[c3_i67 + c3_i49];
                    c3_i63 += 6;
                  }

                  c3_i49 += 6;
                }
              }
            }

            c3_d_cBufferInUse = !c3_d_cBufferInUse;
            c3_b_cBufferInUse = c3_d_cBufferInUse;
          }
        }

        c3_b_n >>= 1;
        c3_c_aBufferInUse = c3_aBufferInUse;
        c3_e_aBufferInUse = c3_c_aBufferInUse;
        if (c3_e_aBufferInUse) {
          for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
            c3_i44 = 0;
            for (c3_i48 = 0; c3_i48 < 6; c3_i48++) {
              c3_b_a[c3_i44 + c3_i34] = 0.0;
              c3_i60 = 0;
              for (c3_i62 = 0; c3_i62 < 6; c3_i62++) {
                c3_b_a[c3_i44 + c3_i34] += c3_aBuffer[c3_i60 + c3_i34] *
                  c3_aBuffer[c3_i62 + c3_i44];
                c3_i60 += 6;
              }

              c3_i44 += 6;
            }
          }
        } else {
          for (c3_i33 = 0; c3_i33 < 6; c3_i33++) {
            c3_i43 = 0;
            for (c3_i47 = 0; c3_i47 < 6; c3_i47++) {
              c3_aBuffer[c3_i43 + c3_i33] = 0.0;
              c3_i59 = 0;
              for (c3_i61 = 0; c3_i61 < 6; c3_i61++) {
                c3_aBuffer[c3_i43 + c3_i33] += c3_b_a[c3_i59 + c3_i33] *
                  c3_b_a[c3_i61 + c3_i43];
                c3_i59 += 6;
              }

              c3_i43 += 6;
            }
          }
        }

        c3_e_aBufferInUse = !c3_e_aBufferInUse;
        c3_aBufferInUse = c3_e_aBufferInUse;
      }

      if (c3_first) {
        if (c3_aBufferInUse) {
          for (c3_i26 = 0; c3_i26 < 36; c3_i26++) {
            c3_c[c3_i26] = c3_aBuffer[c3_i26];
          }
        } else {
          for (c3_i25 = 0; c3_i25 < 36; c3_i25++) {
            c3_c[c3_i25] = c3_b_a[c3_i25];
          }
        }
      } else {
        c3_b_aBufferInUse = c3_aBufferInUse;
        if (c3_b_aBufferInUse) {
          for (c3_i28 = 0; c3_i28 < 6; c3_i28++) {
            c3_i30 = 0;
            for (c3_i32 = 0; c3_i32 < 6; c3_i32++) {
              c3_c[c3_i30 + c3_i28] = 0.0;
              c3_i46 = 0;
              for (c3_i54 = 0; c3_i54 < 6; c3_i54++) {
                c3_c[c3_i30 + c3_i28] += c3_cBuffer[c3_i46 + c3_i28] *
                  c3_aBuffer[c3_i54 + c3_i30];
                c3_i46 += 6;
              }

              c3_i30 += 6;
            }
          }
        } else {
          for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
            c3_i29 = 0;
            for (c3_i31 = 0; c3_i31 < 6; c3_i31++) {
              c3_c[c3_i29 + c3_i27] = 0.0;
              c3_i45 = 0;
              for (c3_i53 = 0; c3_i53 < 6; c3_i53++) {
                c3_c[c3_i29 + c3_i27] += c3_cBuffer[c3_i45 + c3_i27] *
                  c3_b_a[c3_i53 + c3_i29];
                c3_i45 += 6;
              }

              c3_i29 += 6;
            }
          }
        }
      }
    }
  } else {
    for (c3_i = 0; c3_i < 36; c3_i++) {
      c3_b_a[c3_i] = c3_a[c3_i];
    }

    c3_d_b = c3_c_b;
    c3_d_x = c3_d_b;
    c3_e_x = c3_d_x;
    c3_f_b = muDoubleScalarIsInf(c3_e_x);
    c3_g_b = !c3_f_b;
    c3_i_x = c3_d_x;
    c3_h_b = muDoubleScalarIsNaN(c3_i_x);
    c3_b_b1 = !c3_h_b;
    c3_j_b = (c3_g_b && c3_b_b1);
    if (c3_j_b) {
      c3_j_x = c3_d_b;
      c3_k_x = c3_j_x;
      c3_m_x = c3_k_x;
      c3_e = muDoubleScalarAbs(c3_m_x);
      c3_firstmult = true;
      do {
        c3_exitg1 = 0;
        c3_ed2 = muDoubleScalarFloor(c3_e / 2.0);
        if (2.0 * c3_ed2 != c3_e) {
          if (c3_firstmult) {
            for (c3_i8 = 0; c3_i8 < 36; c3_i8++) {
              c3_c[c3_i8] = c3_b_a[c3_i8];
            }

            c3_firstmult = false;
          } else {
            for (c3_i7 = 0; c3_i7 < 36; c3_i7++) {
              c3_cBuffer[c3_i7] = c3_c[c3_i7];
            }

            for (c3_i15 = 0; c3_i15 < 6; c3_i15++) {
              c3_i17 = 0;
              for (c3_i18 = 0; c3_i18 < 6; c3_i18++) {
                c3_c[c3_i17 + c3_i15] = 0.0;
                c3_i21 = 0;
                for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
                  c3_c[c3_i17 + c3_i15] += c3_cBuffer[c3_i21 + c3_i15] *
                    c3_b_a[c3_i22 + c3_i17];
                  c3_i21 += 6;
                }

                c3_i17 += 6;
              }
            }
          }
        }

        if (c3_ed2 == 0.0) {
          c3_exitg1 = 1;
        } else {
          c3_e = c3_ed2;
          for (c3_i14 = 0; c3_i14 < 36; c3_i14++) {
            c3_cBuffer[c3_i14] = c3_b_a[c3_i14];
          }

          for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
            c3_i19 = 0;
            for (c3_i20 = 0; c3_i20 < 6; c3_i20++) {
              c3_b_a[c3_i19 + c3_i16] = 0.0;
              c3_i23 = 0;
              for (c3_i24 = 0; c3_i24 < 6; c3_i24++) {
                c3_b_a[c3_i19 + c3_i16] += c3_cBuffer[c3_i23 + c3_i16] *
                  c3_cBuffer[c3_i24 + c3_i19];
                c3_i23 += 6;
              }

              c3_i19 += 6;
            }
          }
        }
      } while (c3_exitg1 == 0);
    } else {
      for (c3_i2 = 0; c3_i2 < 36; c3_i2++) {
        c3_c[c3_i2] = rtNaN;
      }
    }
  }
}

static void c3_c_warning(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp)
{
  static char_T c3_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c3_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c3_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_y = NULL;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_msgID, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  c3_st.site = &c3_y_emlrtRSI;
  c3_f_feval(chartInstance, &c3_st, c3_y, c3_e_feval(chartInstance, &c3_st,
              c3_b_y, c3_c_y));
}

static real_T c3_log2(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T
                      c3_x)
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f;
  real_T c3_f_x;
  real_T c3_fdbl;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_inte;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_t;
  int32_T c3_eint;
  boolean_T c3_b;
  boolean_T c3_b3;
  boolean_T c3_b_b;
  boolean_T c3_b_b1;
  boolean_T c3_b_b2;
  boolean_T c3_c_b;
  boolean_T c3_d_b;
  boolean_T c3_e_b;
  boolean_T c3_f_b;
  boolean_T c3_g_b;
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  c3_d_x = c3_c_x;
  if (c3_d_x == 0.0) {
    c3_f = rtMinusInf;
  } else {
    c3_e_x = c3_d_x;
    c3_f_x = c3_e_x;
    c3_b = muDoubleScalarIsInf(c3_f_x);
    c3_b_b = !c3_b;
    c3_g_x = c3_e_x;
    c3_c_b = muDoubleScalarIsNaN(c3_g_x);
    c3_b_b1 = !c3_c_b;
    c3_d_b = (c3_b_b && c3_b_b1);
    if (c3_d_b) {
      c3_h_x = c3_d_x;
      c3_i_x = c3_h_x;
      c3_j_x = c3_i_x;
      c3_e_b = muDoubleScalarIsInf(c3_j_x);
      c3_b_b2 = !c3_e_b;
      c3_k_x = c3_i_x;
      c3_f_b = muDoubleScalarIsNaN(c3_k_x);
      c3_b3 = !c3_f_b;
      c3_g_b = (c3_b_b2 && c3_b3);
      if (c3_g_b) {
        c3_fdbl = frexp(c3_h_x, &c3_eint);
        c3_t = c3_fdbl;
        c3_inte = static_cast<real_T>(c3_eint);
      } else {
        c3_t = c3_h_x;
        c3_inte = 0.0;
      }

      if (c3_t == 0.5) {
        c3_f = c3_inte - 1.0;
      } else if ((c3_inte == 1.0) && (c3_t < 0.75)) {
        c3_f = muDoubleScalarLog(2.0 * c3_t) / 0.69314718055994529;
      } else {
        c3_f = muDoubleScalarLog(c3_t) / 0.69314718055994529 + c3_inte;
      }
    } else {
      c3_f = c3_d_x;
    }
  }

  return c3_f;
}

static void c3_padeApproximation(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_ib_A[36], real_T c3_A2[36],
  real_T c3_A4[36], real_T c3_A6[36], int32_T c3_m, real_T c3_d_F[36])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_f_st;
  emlrtStack c3_g_st;
  emlrtStack c3_h_st;
  emlrtStack c3_i_st;
  emlrtStack c3_j_st;
  emlrtStack c3_k_st;
  emlrtStack c3_m_st;
  emlrtStack c3_st;
  real_T c3_V[36];
  real_T c3_b_y[36];
  real_T c3_c_y[36];
  real_T c3_y[36];
  real_T c3_b_temp;
  real_T c3_b_x;
  real_T c3_c_temp;
  real_T c3_c_x;
  real_T c3_d;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_k;
  real_T c3_i_x;
  real_T c3_s;
  real_T c3_smax;
  real_T c3_temp;
  real_T c3_x;
  real_T c3_yjy;
  real_T c3_z;
  int32_T c3_ipiv[6];
  int32_T c3_a;
  int32_T c3_ab_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_c;
  int32_T c3_b_i;
  int32_T c3_b_i58;
  int32_T c3_b_i88;
  int32_T c3_b_ia0;
  int32_T c3_b_info;
  int32_T c3_b_ip;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_b_j;
  int32_T c3_b_jA;
  int32_T c3_b_jBcol;
  int32_T c3_b_jy;
  int32_T c3_b_k;
  int32_T c3_b_kAcol;
  int32_T c3_b_n;
  int32_T c3_bb_a;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_c;
  int32_T c3_c_i;
  int32_T c3_c_ia0;
  int32_T c3_c_info;
  int32_T c3_c_ix;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_c_j;
  int32_T c3_c_k;
  int32_T c3_c_m;
  int32_T c3_c_n;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_d_c;
  int32_T c3_d_i;
  int32_T c3_d_ia0;
  int32_T c3_d_info;
  int32_T c3_d_ix;
  int32_T c3_d_ix0;
  int32_T c3_d_iy0;
  int32_T c3_d_j;
  int32_T c3_d_k;
  int32_T c3_d_m;
  int32_T c3_e_a;
  int32_T c3_e_b;
  int32_T c3_e_c;
  int32_T c3_e_i;
  int32_T c3_e_ix0;
  int32_T c3_e_iy0;
  int32_T c3_e_j;
  int32_T c3_e_k;
  int32_T c3_e_m;
  int32_T c3_f_a;
  int32_T c3_f_b;
  int32_T c3_f_c;
  int32_T c3_f_i;
  int32_T c3_f_ix0;
  int32_T c3_f_iy0;
  int32_T c3_f_j;
  int32_T c3_f_k;
  int32_T c3_f_m;
  int32_T c3_f_n;
  int32_T c3_g_a;
  int32_T c3_g_b;
  int32_T c3_g_c;
  int32_T c3_g_i;
  int32_T c3_g_ix0;
  int32_T c3_g_j;
  int32_T c3_g_k;
  int32_T c3_g_n;
  int32_T c3_h_a;
  int32_T c3_h_b;
  int32_T c3_h_ix0;
  int32_T c3_h_j;
  int32_T c3_h_k;
  int32_T c3_h_n;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i4;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i5;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i59;
  int32_T c3_i6;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i7;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i8;
  int32_T c3_i80;
  int32_T c3_i81;
  int32_T c3_i82;
  int32_T c3_i83;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i89;
  int32_T c3_i9;
  int32_T c3_i90;
  int32_T c3_i_j;
  int32_T c3_ia0;
  int32_T c3_ijA;
  int32_T c3_info;
  int32_T c3_ix0;
  int32_T c3_iy;
  int32_T c3_iy0;
  int32_T c3_j;
  int32_T c3_jBcol;
  int32_T c3_j_a;
  int32_T c3_j_b;
  int32_T c3_j_k;
  int32_T c3_j_n;
  int32_T c3_jj;
  int32_T c3_jm1;
  int32_T c3_jp1j;
  int32_T c3_jpiv;
  int32_T c3_jpiv_offset;
  int32_T c3_jprow;
  int32_T c3_jrow;
  int32_T c3_k;
  int32_T c3_kAcol;
  int32_T c3_k_a;
  int32_T c3_k_b;
  int32_T c3_k_k;
  int32_T c3_m_a;
  int32_T c3_m_b;
  int32_T c3_m_k;
  int32_T c3_mmj;
  int32_T c3_o_a;
  int32_T c3_o_b;
  int32_T c3_o_k;
  int32_T c3_p_a;
  int32_T c3_p_b;
  int32_T c3_p_k;
  int32_T c3_q_a;
  int32_T c3_q_b;
  int32_T c3_q_k;
  int32_T c3_r_a;
  int32_T c3_r_b;
  int32_T c3_s_a;
  int32_T c3_s_b;
  int32_T c3_t_a;
  int32_T c3_t_b;
  int32_T c3_u_a;
  int32_T c3_u_b;
  int32_T c3_v_a;
  int32_T c3_w_a;
  int32_T c3_x_a;
  int32_T c3_y_a;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_d_overflow;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_f_st.prev = &c3_e_st;
  c3_f_st.tls = c3_e_st.tls;
  c3_g_st.prev = &c3_f_st;
  c3_g_st.tls = c3_f_st.tls;
  c3_h_st.prev = &c3_g_st;
  c3_h_st.tls = c3_g_st.tls;
  c3_i_st.prev = &c3_h_st;
  c3_i_st.tls = c3_h_st.tls;
  c3_j_st.prev = &c3_i_st;
  c3_j_st.tls = c3_i_st.tls;
  c3_k_st.prev = &c3_j_st;
  c3_k_st.tls = c3_j_st.tls;
  c3_m_st.prev = &c3_k_st;
  c3_m_st.tls = c3_k_st.tls;
  if (c3_m == 3) {
    for (c3_i = 0; c3_i < 36; c3_i++) {
      c3_d_F[c3_i] = c3_A2[c3_i];
    }

    for (c3_k = 0; c3_k < 6; c3_k++) {
      c3_b_k = c3_k;
      c3_d_F[c3_b_k + 6 * c3_b_k] += 60.0;
    }

    for (c3_i7 = 0; c3_i7 < 36; c3_i7++) {
      c3_y[c3_i7] = c3_d_F[c3_i7];
    }

    for (c3_i13 = 0; c3_i13 < 6; c3_i13++) {
      c3_i18 = 0;
      for (c3_i23 = 0; c3_i23 < 6; c3_i23++) {
        c3_d_F[c3_i18 + c3_i13] = 0.0;
        c3_i31 = 0;
        for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
          c3_d_F[c3_i18 + c3_i13] += c3_ib_A[c3_i31 + c3_i13] * c3_y[c3_i34 +
            c3_i18];
          c3_i31 += 6;
        }

        c3_i18 += 6;
      }
    }

    for (c3_i17 = 0; c3_i17 < 36; c3_i17++) {
      c3_V[c3_i17] = 12.0 * c3_A2[c3_i17];
    }

    c3_d = 120.0;
  } else if (c3_m == 5) {
    for (c3_i1 = 0; c3_i1 < 36; c3_i1++) {
      c3_d_F[c3_i1] = 420.0 * c3_A2[c3_i1];
    }

    for (c3_i5 = 0; c3_i5 < 36; c3_i5++) {
      c3_d_F[c3_i5] += c3_A4[c3_i5];
    }

    for (c3_c_k = 0; c3_c_k < 6; c3_c_k++) {
      c3_b_k = c3_c_k;
      c3_d_F[c3_b_k + 6 * c3_b_k] += 15120.0;
    }

    for (c3_i16 = 0; c3_i16 < 36; c3_i16++) {
      c3_y[c3_i16] = c3_d_F[c3_i16];
    }

    for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
      c3_i28 = 0;
      for (c3_i30 = 0; c3_i30 < 6; c3_i30++) {
        c3_d_F[c3_i28 + c3_i22] = 0.0;
        c3_i41 = 0;
        for (c3_i43 = 0; c3_i43 < 6; c3_i43++) {
          c3_d_F[c3_i28 + c3_i22] += c3_ib_A[c3_i41 + c3_i22] * c3_y[c3_i43 +
            c3_i28];
          c3_i41 += 6;
        }

        c3_i28 += 6;
      }
    }

    for (c3_i27 = 0; c3_i27 < 36; c3_i27++) {
      c3_V[c3_i27] = 30.0 * c3_A4[c3_i27];
    }

    for (c3_i33 = 0; c3_i33 < 36; c3_i33++) {
      c3_y[c3_i33] = 3360.0 * c3_A2[c3_i33];
    }

    for (c3_i40 = 0; c3_i40 < 36; c3_i40++) {
      c3_V[c3_i40] += c3_y[c3_i40];
    }

    c3_d = 30240.0;
  } else if (c3_m == 7) {
    for (c3_i2 = 0; c3_i2 < 36; c3_i2++) {
      c3_d_F[c3_i2] = 1512.0 * c3_A4[c3_i2];
    }

    for (c3_i6 = 0; c3_i6 < 36; c3_i6++) {
      c3_y[c3_i6] = 277200.0 * c3_A2[c3_i6];
    }

    for (c3_i12 = 0; c3_i12 < 36; c3_i12++) {
      c3_d_F[c3_i12] = (c3_A6[c3_i12] + c3_d_F[c3_i12]) + c3_y[c3_i12];
    }

    for (c3_d_k = 0; c3_d_k < 6; c3_d_k++) {
      c3_b_k = c3_d_k;
      c3_d_F[c3_b_k + 6 * c3_b_k] += 8.64864E+6;
    }

    for (c3_i25 = 0; c3_i25 < 36; c3_i25++) {
      c3_y[c3_i25] = c3_d_F[c3_i25];
    }

    for (c3_i29 = 0; c3_i29 < 6; c3_i29++) {
      c3_i36 = 0;
      for (c3_i39 = 0; c3_i39 < 6; c3_i39++) {
        c3_d_F[c3_i36 + c3_i29] = 0.0;
        c3_i47 = 0;
        for (c3_i51 = 0; c3_i51 < 6; c3_i51++) {
          c3_d_F[c3_i36 + c3_i29] += c3_ib_A[c3_i47 + c3_i29] * c3_y[c3_i51 +
            c3_i36];
          c3_i47 += 6;
        }

        c3_i36 += 6;
      }
    }

    for (c3_i35 = 0; c3_i35 < 36; c3_i35++) {
      c3_V[c3_i35] = 56.0 * c3_A6[c3_i35];
    }

    for (c3_i42 = 0; c3_i42 < 36; c3_i42++) {
      c3_y[c3_i42] = 25200.0 * c3_A4[c3_i42];
    }

    for (c3_i46 = 0; c3_i46 < 36; c3_i46++) {
      c3_b_y[c3_i46] = 1.99584E+6 * c3_A2[c3_i46];
    }

    for (c3_i53 = 0; c3_i53 < 36; c3_i53++) {
      c3_V[c3_i53] = (c3_V[c3_i53] + c3_y[c3_i53]) + c3_b_y[c3_i53];
    }

    c3_d = 1.729728E+7;
  } else if (c3_m == 9) {
    for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
      c3_i10 = 0;
      for (c3_i11 = 0; c3_i11 < 6; c3_i11++) {
        c3_V[c3_i10 + c3_i4] = 0.0;
        c3_i21 = 0;
        for (c3_i24 = 0; c3_i24 < 6; c3_i24++) {
          c3_V[c3_i10 + c3_i4] += c3_A6[c3_i21 + c3_i4] * c3_A2[c3_i24 + c3_i10];
          c3_i21 += 6;
        }

        c3_i10 += 6;
      }
    }

    for (c3_i9 = 0; c3_i9 < 36; c3_i9++) {
      c3_d_F[c3_i9] = 3960.0 * c3_A6[c3_i9];
    }

    for (c3_i15 = 0; c3_i15 < 36; c3_i15++) {
      c3_y[c3_i15] = 2.16216E+6 * c3_A4[c3_i15];
    }

    for (c3_i20 = 0; c3_i20 < 36; c3_i20++) {
      c3_b_y[c3_i20] = 3.027024E+8 * c3_A2[c3_i20];
    }

    for (c3_i26 = 0; c3_i26 < 36; c3_i26++) {
      c3_d_F[c3_i26] = ((c3_V[c3_i26] + c3_d_F[c3_i26]) + c3_y[c3_i26]) +
        c3_b_y[c3_i26];
    }

    for (c3_g_k = 0; c3_g_k < 6; c3_g_k++) {
      c3_b_k = c3_g_k;
      c3_d_F[c3_b_k + 6 * c3_b_k] += 8.8216128E+9;
    }

    for (c3_i38 = 0; c3_i38 < 36; c3_i38++) {
      c3_y[c3_i38] = c3_d_F[c3_i38];
    }

    for (c3_i45 = 0; c3_i45 < 6; c3_i45++) {
      c3_i50 = 0;
      for (c3_i52 = 0; c3_i52 < 6; c3_i52++) {
        c3_d_F[c3_i50 + c3_i45] = 0.0;
        c3_i61 = 0;
        for (c3_i62 = 0; c3_i62 < 6; c3_i62++) {
          c3_d_F[c3_i50 + c3_i45] += c3_ib_A[c3_i61 + c3_i45] * c3_y[c3_i62 +
            c3_i50];
          c3_i61 += 6;
        }

        c3_i50 += 6;
      }
    }

    for (c3_i49 = 0; c3_i49 < 36; c3_i49++) {
      c3_V[c3_i49] *= 90.0;
    }

    for (c3_i56 = 0; c3_i56 < 36; c3_i56++) {
      c3_y[c3_i56] = 110880.0 * c3_A6[c3_i56];
    }

    for (c3_i60 = 0; c3_i60 < 36; c3_i60++) {
      c3_b_y[c3_i60] = 3.027024E+7 * c3_A4[c3_i60];
    }

    for (c3_i66 = 0; c3_i66 < 36; c3_i66++) {
      c3_c_y[c3_i66] = 2.0756736E+9 * c3_A2[c3_i66];
    }

    for (c3_i70 = 0; c3_i70 < 36; c3_i70++) {
      c3_V[c3_i70] = ((c3_V[c3_i70] + c3_y[c3_i70]) + c3_b_y[c3_i70]) +
        c3_c_y[c3_i70];
    }

    c3_d = 1.76432256E+10;
  } else {
    for (c3_i3 = 0; c3_i3 < 36; c3_i3++) {
      c3_d_F[c3_i3] = 3.352212864E+10 * c3_A6[c3_i3];
    }

    for (c3_i8 = 0; c3_i8 < 36; c3_i8++) {
      c3_y[c3_i8] = 1.05594705216E+13 * c3_A4[c3_i8];
    }

    for (c3_i14 = 0; c3_i14 < 36; c3_i14++) {
      c3_b_y[c3_i14] = 1.1873537964288E+15 * c3_A2[c3_i14];
    }

    for (c3_i19 = 0; c3_i19 < 36; c3_i19++) {
      c3_d_F[c3_i19] = (c3_d_F[c3_i19] + c3_y[c3_i19]) + c3_b_y[c3_i19];
    }

    for (c3_e_k = 0; c3_e_k < 6; c3_e_k++) {
      c3_b_k = c3_e_k;
      c3_d_F[c3_b_k + 6 * c3_b_k] += 3.238237626624E+16;
    }

    for (c3_i32 = 0; c3_i32 < 36; c3_i32++) {
      c3_y[c3_i32] = 16380.0 * c3_A4[c3_i32];
    }

    for (c3_i37 = 0; c3_i37 < 36; c3_i37++) {
      c3_b_y[c3_i37] = 4.08408E+7 * c3_A2[c3_i37];
    }

    for (c3_i44 = 0; c3_i44 < 36; c3_i44++) {
      c3_y[c3_i44] = (c3_A6[c3_i44] + c3_y[c3_i44]) + c3_b_y[c3_i44];
    }

    for (c3_i48 = 0; c3_i48 < 6; c3_i48++) {
      c3_i55 = 0;
      for (c3_i57 = 0; c3_i57 < 6; c3_i57++) {
        c3_b_y[c3_i55 + c3_i48] = 0.0;
        c3_i65 = 0;
        for (c3_i68 = 0; c3_i68 < 6; c3_i68++) {
          c3_b_y[c3_i55 + c3_i48] += c3_A6[c3_i65 + c3_i48] * c3_y[c3_i68 +
            c3_i55];
          c3_i65 += 6;
        }

        c3_i55 += 6;
      }
    }

    for (c3_i54 = 0; c3_i54 < 36; c3_i54++) {
      c3_b_y[c3_i54] += c3_d_F[c3_i54];
    }

    for (c3_i59 = 0; c3_i59 < 6; c3_i59++) {
      c3_i64 = 0;
      for (c3_i67 = 0; c3_i67 < 6; c3_i67++) {
        c3_d_F[c3_i64 + c3_i59] = 0.0;
        c3_i72 = 0;
        for (c3_i73 = 0; c3_i73 < 6; c3_i73++) {
          c3_d_F[c3_i64 + c3_i59] += c3_ib_A[c3_i72 + c3_i59] * c3_b_y[c3_i73 +
            c3_i64];
          c3_i72 += 6;
        }

        c3_i64 += 6;
      }
    }

    for (c3_i63 = 0; c3_i63 < 36; c3_i63++) {
      c3_y[c3_i63] = 182.0 * c3_A6[c3_i63];
    }

    for (c3_i69 = 0; c3_i69 < 36; c3_i69++) {
      c3_b_y[c3_i69] = 960960.0 * c3_A4[c3_i69];
    }

    for (c3_i71 = 0; c3_i71 < 36; c3_i71++) {
      c3_c_y[c3_i71] = 1.32324192E+9 * c3_A2[c3_i71];
    }

    for (c3_i74 = 0; c3_i74 < 36; c3_i74++) {
      c3_y[c3_i74] = (c3_y[c3_i74] + c3_b_y[c3_i74]) + c3_c_y[c3_i74];
    }

    for (c3_i75 = 0; c3_i75 < 6; c3_i75++) {
      c3_i77 = 0;
      for (c3_i78 = 0; c3_i78 < 6; c3_i78++) {
        c3_V[c3_i77 + c3_i75] = 0.0;
        c3_i81 = 0;
        for (c3_i82 = 0; c3_i82 < 6; c3_i82++) {
          c3_V[c3_i77 + c3_i75] += c3_A6[c3_i81 + c3_i75] * c3_y[c3_i82 + c3_i77];
          c3_i81 += 6;
        }

        c3_i77 += 6;
      }
    }

    for (c3_i76 = 0; c3_i76 < 36; c3_i76++) {
      c3_y[c3_i76] = 6.704425728E+11 * c3_A6[c3_i76];
    }

    for (c3_i79 = 0; c3_i79 < 36; c3_i79++) {
      c3_b_y[c3_i79] = 1.29060195264E+14 * c3_A4[c3_i79];
    }

    for (c3_i80 = 0; c3_i80 < 36; c3_i80++) {
      c3_c_y[c3_i80] = 7.7717703038976E+15 * c3_A2[c3_i80];
    }

    for (c3_i83 = 0; c3_i83 < 36; c3_i83++) {
      c3_V[c3_i83] = ((c3_V[c3_i83] + c3_y[c3_i83]) + c3_b_y[c3_i83]) +
        c3_c_y[c3_i83];
    }

    c3_d = 6.476475253248E+16;
  }

  for (c3_f_k = 0; c3_f_k < 6; c3_f_k++) {
    c3_b_k = c3_f_k;
    c3_V[c3_b_k + 6 * c3_b_k] += c3_d;
  }

  for (c3_h_k = 0; c3_h_k < 36; c3_h_k++) {
    c3_i_k = static_cast<real_T>(c3_h_k) + 1.0;
    c3_V[static_cast<int32_T>(c3_i_k) - 1] -= c3_d_F[static_cast<int32_T>(c3_i_k)
      - 1];
    c3_d_F[static_cast<int32_T>(c3_i_k) - 1] *= 2.0;
  }

  c3_st.site = &c3_vf_emlrtRSI;
  c3_b_st.site = &c3_wf_emlrtRSI;
  c3_c_st.site = &c3_xf_emlrtRSI;
  c3_d_st.site = &c3_ag_emlrtRSI;
  c3_e_st.site = &c3_bg_emlrtRSI;
  c3_f_st.site = &c3_mf_emlrtRSI;
  for (c3_b_i58 = 0; c3_b_i58 < 6; c3_b_i58++) {
    c3_ipiv[c3_b_i58] = 1 + c3_b_i58;
  }

  c3_info = 0;
  for (c3_j = 0; c3_j < 5; c3_j++) {
    c3_b_j = c3_j + 1;
    c3_a = c3_b_j - 1;
    c3_jm1 = c3_a;
    c3_b = c3_b_j;
    c3_mmj = 6 - c3_b;
    c3_b_a = c3_jm1;
    c3_c = c3_b_a * 7;
    c3_b_b = c3_c + 1;
    c3_jj = c3_b_b;
    c3_c_a = c3_jj + 1;
    c3_jp1j = c3_c_a;
    c3_d_a = c3_mmj + 1;
    c3_b_c = c3_d_a;
    c3_b_n = c3_b_c;
    c3_ix0 = c3_jj;
    c3_c_n = c3_b_n;
    c3_b_ix0 = c3_ix0;
    c3_e_a = 0;
    c3_b_ix = c3_b_ix0 - 1;
    c3_x = c3_V[c3_b_ix0 - 1];
    c3_b_x = c3_x;
    c3_c_x = c3_b_x;
    c3_d_x = c3_c_x;
    c3_d_y = muDoubleScalarAbs(c3_d_x);
    c3_smax = c3_d_y;
    for (c3_p_k = 2; c3_p_k <= c3_c_n; c3_p_k++) {
      c3_f_a = c3_b_ix + 1;
      c3_b_ix = c3_f_a;
      c3_e_x = c3_V[c3_b_ix];
      c3_f_x = c3_e_x;
      c3_g_x = c3_f_x;
      c3_h_x = c3_g_x;
      c3_e_y = muDoubleScalarAbs(c3_h_x);
      c3_s = c3_e_y;
      if (c3_s > c3_smax) {
        c3_e_a = c3_p_k - 1;
        c3_smax = c3_s;
      }
    }

    c3_jpiv_offset = c3_e_a;
    c3_g_a = c3_jj;
    c3_e_b = c3_jpiv_offset;
    c3_jpiv = (c3_g_a + c3_e_b) - 1;
    if (c3_V[c3_jpiv] != 0.0) {
      if (c3_jpiv_offset != 0) {
        c3_h_a = c3_b_j;
        c3_g_b = c3_jpiv_offset;
        c3_e_c = c3_h_a + c3_g_b;
        c3_ipiv[c3_b_j - 1] = c3_e_c;
        c3_j_b = c3_jm1 + 1;
        c3_jrow = c3_j_b;
        c3_p_a = c3_jrow;
        c3_k_b = c3_jpiv_offset;
        c3_jprow = c3_p_a + c3_k_b;
        c3_c_ix0 = c3_jrow;
        c3_iy0 = c3_jprow;
        c3_e_ix0 = c3_c_ix0;
        c3_c_iy0 = c3_iy0;
        c3_c_ix = c3_e_ix0 - 1;
        c3_iy = c3_c_iy0 - 1;
        for (c3_q_k = 0; c3_q_k < 6; c3_q_k++) {
          c3_b_temp = c3_V[c3_c_ix];
          c3_V[c3_c_ix] = c3_V[c3_iy];
          c3_V[c3_iy] = c3_b_temp;
          c3_s_a = c3_c_ix + 6;
          c3_c_ix = c3_s_a;
          c3_t_a = c3_iy + 6;
          c3_iy = c3_t_a;
        }
      }

      c3_j_a = c3_mmj - 1;
      c3_d_c = c3_j_a;
      c3_m_a = c3_jp1j;
      c3_h_b = c3_d_c;
      c3_i87 = c3_m_a + c3_h_b;
      c3_g_st.site = &c3_of_emlrtRSI;
      c3_q_a = c3_jp1j;
      c3_m_b = c3_i87;
      c3_r_a = c3_q_a;
      c3_o_b = c3_m_b;
      if (c3_r_a > c3_o_b) {
        c3_b_overflow = false;
      } else {
        c3_b_overflow = (c3_o_b > 2147483646);
      }

      if (c3_b_overflow) {
        c3_h_st.site = &c3_v_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_h_st);
      }

      for (c3_g_i = c3_jp1j; c3_g_i <= c3_i87; c3_g_i++) {
        c3_i_x = c3_V[c3_g_i - 1];
        c3_f_y = c3_V[c3_jj - 1];
        c3_z = c3_i_x / c3_f_y;
        c3_V[c3_g_i - 1] = c3_z;
      }
    } else {
      c3_info = c3_b_j;
    }

    c3_f_b = c3_b_j;
    c3_c_c = 6 - c3_f_b;
    c3_k_a = c3_jj + 6;
    c3_f_c = c3_k_a;
    c3_o_a = c3_jj + 7;
    c3_g_c = c3_o_a;
    c3_g_st.site = &c3_pf_emlrtRSI;
    c3_c_m = c3_mmj;
    c3_f_n = c3_c_c;
    c3_d_ix0 = c3_jp1j;
    c3_b_iy0 = c3_f_c;
    c3_ia0 = c3_g_c;
    c3_h_st.site = &c3_qf_emlrtRSI;
    c3_d_m = c3_c_m;
    c3_g_n = c3_f_n;
    c3_f_ix0 = c3_d_ix0;
    c3_d_iy0 = c3_b_iy0;
    c3_b_ia0 = c3_ia0;
    c3_i_st.site = &c3_pc_emlrtRSI;
    c3_e_m = c3_d_m;
    c3_h_n = c3_g_n;
    c3_g_ix0 = c3_f_ix0;
    c3_e_iy0 = c3_d_iy0;
    c3_c_ia0 = c3_b_ia0;
    c3_j_st.site = &c3_qc_emlrtRSI;
    c3_f_m = c3_e_m;
    c3_j_n = c3_h_n;
    c3_h_ix0 = c3_g_ix0;
    c3_f_iy0 = c3_e_iy0;
    c3_d_ia0 = c3_c_ia0;
    c3_u_a = c3_d_ia0 - 1;
    c3_b_jA = c3_u_a;
    c3_b_jy = c3_f_iy0;
    c3_k_st.site = &c3_rc_emlrtRSI;
    c3_p_b = c3_j_n;
    c3_q_b = c3_p_b;
    if (c3_q_b < 1) {
      c3_c_overflow = false;
    } else {
      c3_c_overflow = (c3_q_b > 2147483646);
    }

    if (c3_c_overflow) {
      c3_m_st.site = &c3_v_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_m_st);
    }

    c3_b_i88 = static_cast<uint8_T>(c3_j_n) - 1;
    for (c3_i_j = 0; c3_i_j <= c3_b_i88; c3_i_j++) {
      c3_yjy = c3_V[c3_b_jy - 1];
      if (c3_yjy != 0.0) {
        c3_c_temp = -c3_yjy;
        c3_d_ix = c3_h_ix0 - 1;
        c3_r_b = c3_b_jA + 1;
        c3_i89 = c3_r_b;
        c3_x_a = c3_f_m;
        c3_s_b = c3_b_jA;
        c3_i90 = c3_x_a + c3_s_b;
        c3_k_st.site = &c3_sc_emlrtRSI;
        c3_y_a = c3_i89;
        c3_t_b = c3_i90;
        c3_ab_a = c3_y_a;
        c3_u_b = c3_t_b;
        if (c3_ab_a > c3_u_b) {
          c3_d_overflow = false;
        } else {
          c3_d_overflow = (c3_u_b > 2147483646);
        }

        if (c3_d_overflow) {
          c3_m_st.site = &c3_v_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_m_st);
        }

        for (c3_ijA = c3_i89; c3_ijA <= c3_i90; c3_ijA++) {
          c3_V[c3_ijA - 1] += c3_V[c3_d_ix] * c3_c_temp;
          c3_bb_a = c3_d_ix + 1;
          c3_d_ix = c3_bb_a;
        }
      }

      c3_v_a = c3_b_jy + 6;
      c3_b_jy = c3_v_a;
      c3_w_a = c3_b_jA + 6;
      c3_b_jA = c3_w_a;
    }
  }

  if ((static_cast<real_T>(c3_info) == 0.0) && (!(c3_V[35] != 0.0))) {
    c3_info = 6;
  }

  c3_b_info = c3_info;
  c3_c_info = c3_b_info;
  c3_e_st.site = &c3_cg_emlrtRSI;
  c3_f_st.site = &c3_dg_emlrtRSI;
  for (c3_b_i = 0; c3_b_i < 5; c3_b_i++) {
    c3_c_i = c3_b_i;
    if (c3_ipiv[c3_c_i] != c3_c_i + 1) {
      c3_b_ip = c3_ipiv[c3_c_i] - 1;
      for (c3_e_j = 0; c3_e_j < 6; c3_e_j++) {
        c3_g_j = c3_e_j;
        c3_temp = c3_d_F[c3_c_i + 6 * c3_g_j];
        c3_d_F[c3_c_i + 6 * c3_g_j] = c3_d_F[c3_b_ip + 6 * c3_g_j];
        c3_d_F[c3_b_ip + 6 * c3_g_j] = c3_temp;
      }
    }
  }

  for (c3_c_j = 0; c3_c_j < 6; c3_c_j++) {
    c3_d_j = c3_c_j;
    c3_jBcol = 6 * c3_d_j - 1;
    for (c3_j_k = 0; c3_j_k < 6; c3_j_k++) {
      c3_k_k = c3_j_k;
      c3_kAcol = 6 * c3_k_k - 1;
      if (c3_d_F[(c3_k_k + c3_jBcol) + 1] != 0.0) {
        c3_i84 = c3_k_k;
        for (c3_d_i = c3_i84 + 2; c3_d_i < 7; c3_d_i++) {
          c3_d_F[c3_d_i + c3_jBcol] -= c3_d_F[(c3_k_k + c3_jBcol) + 1] *
            c3_V[c3_d_i + c3_kAcol];
        }
      }
    }
  }

  c3_g_st.site = &c3_eg_emlrtRSI;
  c3_h_st.site = &c3_rf_emlrtRSI;
  for (c3_f_j = 0; c3_f_j < 6; c3_f_j++) {
    c3_h_j = c3_f_j;
    c3_b_jBcol = 6 * c3_h_j;
    for (c3_m_k = 5; c3_m_k >= 0; c3_m_k--) {
      c3_b_kAcol = 6 * c3_m_k;
      if (c3_d_F[c3_m_k + c3_b_jBcol] != 0.0) {
        c3_d_F[c3_m_k + c3_b_jBcol] /= c3_V[c3_m_k + c3_b_kAcol];
        c3_i85 = c3_m_k;
        c3_i_st.site = &c3_sf_emlrtRSI;
        c3_c_b = c3_i85;
        c3_d_b = c3_c_b;
        if (c3_d_b < 1) {
          c3_overflow = false;
        } else {
          c3_overflow = (c3_d_b > 2147483646);
        }

        if (c3_overflow) {
          c3_j_st.site = &c3_v_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_j_st);
        }

        c3_i86 = static_cast<uint8_T>(c3_i85) - 1;
        for (c3_e_i = 0; c3_e_i <= c3_i86; c3_e_i++) {
          c3_f_i = c3_e_i;
          c3_d_F[c3_f_i + c3_b_jBcol] -= c3_d_F[c3_m_k + c3_b_jBcol] *
            c3_V[c3_f_i + c3_b_kAcol];
        }
      }
    }
  }

  c3_d_info = c3_c_info;
  if (static_cast<real_T>(c3_d_info) > 0.0) {
    c3_c_st.site = &c3_yf_emlrtRSI;
    c3_d_st.site = &c3_fg_emlrtRSI;
    c3_c_warning(chartInstance, &c3_d_st);
  }

  for (c3_o_k = 0; c3_o_k < 6; c3_o_k++) {
    c3_b_k = c3_o_k;
    c3_d_F[c3_b_k + 6 * c3_b_k]++;
  }
}

static void c3_recomputeBlockDiag(SFc3_starshotsim_devInstanceStruct
  *chartInstance, real_T c3_ib_A[36], real_T c3_d_F[36], int32_T c3_blockFormat
  [5], real_T c3_e_F[36])
{
  real_T c3_jb_A[36];
  int32_T c3_b_blockFormat[5];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_e_F[c3_i] = c3_d_F[c3_i];
  }

  for (c3_i1 = 0; c3_i1 < 36; c3_i1++) {
    c3_jb_A[c3_i1] = c3_ib_A[c3_i1];
  }

  for (c3_i2 = 0; c3_i2 < 5; c3_i2++) {
    c3_b_blockFormat[c3_i2] = c3_blockFormat[c3_i2];
  }

  c3_b_recomputeBlockDiag(chartInstance, c3_jb_A, c3_e_F, c3_b_blockFormat);
}

const mxArray *sf_c3_starshotsim_dev_get_eml_resolved_functions_info()
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_a__output_of_sprintf_, const char_T
  *c3_identifier, char_T c3_y[23])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_a__output_of_sprintf_),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_a__output_of_sprintf_);
}

static void c3_b_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[23])
{
  int32_T c3_i;
  char_T c3_b_cv[23];
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_b_cv, 1, 10, 0U, 1, 0U, 2, 1,
                23);
  for (c3_i = 0; c3_i < 23; c3_i++) {
    c3_y[c3_i] = c3_b_cv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_b_P_k1_k, const char_T *c3_identifier,
  real_T c3_y[36])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_P_k1_k), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_P_k1_k);
}

static void c3_d_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[36])
{
  real_T c3_b_dv[36];
  int32_T c3_i;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_b_dv, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c3_i = 0; c3_i < 36; c3_i++) {
    c3_y[c3_i] = c3_b_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_b_X_k1_k, const char_T *c3_identifier,
  real_T c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_X_k1_k), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_X_k1_k);
}

static void c3_f_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[6])
{
  real_T c3_b_dv[6];
  int32_T c3_i;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_b_dv, 1, 0, 0U, 1, 0U, 1, 6);
  for (c3_i = 0; c3_i < 6; c3_i++) {
    c3_y[c3_i] = c3_b_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_starshotsim_dev, const char_T
  *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_starshotsim_dev), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_starshotsim_dev);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_u;
  uint8_T c3_y;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_slStringInitializeDynamicBuffers
  (SFc3_starshotsim_devInstanceStruct *chartInstance)
{
}

static void c3_chart_data_browse_helper(SFc3_starshotsim_devInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig)
{
  *c3_mxData = NULL;
  *c3_mxData = NULL;
  *c3_isValueTooBig = 0U;
  switch (c3_ssIdNumber) {
   case 4U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_J_k_k, 0,
      0U, 1U, 0U, 2, 6, 6), false);
    break;

   case 5U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_X_k1_k,
      0, 0U, 1U, 0U, 1, 6), false);
    break;

   case 6U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_X_k_k, 0,
      0U, 1U, 0U, 1, 6), false);
    break;

   case 7U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_P_k_k, 0,
      0U, 1U, 0U, 2, 6, 6), false);
    break;

   case 11U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_P_k1_k,
      0, 0U, 1U, 0U, 2, 6, 6), false);
    break;

   case 12U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_dT, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 13U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", chartInstance->c3_Q, 0, 0U,
      1U, 0U, 2, 6, 6), false);
    break;
  }
}

static const mxArray *c3_sprintf(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1)
{
  const mxArray *c3_m = NULL;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "sprintf", 1U, 2U, 14,
    sf_mex_dup(c3_input0), 14, sf_mex_dup(c3_input1)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  return c3_m;
}

static const mxArray *c3_feval(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1,
  const mxArray *c3_input2, const mxArray *c3_input3)
{
  const mxArray *c3_m = NULL;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1), 14, sf_mex_dup(c3_input2), 14,
    sf_mex_dup(c3_input3)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  sf_mex_destroy(&c3_input2);
  sf_mex_destroy(&c3_input3);
  return c3_m;
}

static void c3_b_feval(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1)
{
  sf_mex_call(c3_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c3_input0), 14,
              sf_mex_dup(c3_input1));
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
}

static const mxArray *c3_c_feval(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1)
{
  const mxArray *c3_m = NULL;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  return c3_m;
}

static void c3_d_feval(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1)
{
  sf_mex_call(c3_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c3_input0), 14,
              sf_mex_dup(c3_input1));
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
}

static const mxArray *c3_e_feval(SFc3_starshotsim_devInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, const mxArray *c3_input0, const
  mxArray *c3_input1)
{
  const mxArray *c3_m = NULL;
  c3_m = NULL;
  sf_mex_assign(&c3_m, sf_mex_call(c3_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c3_input0), 14, sf_mex_dup(c3_input1)), false);
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
  return c3_m;
}

static void c3_f_feval(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, const mxArray *c3_input0, const mxArray *c3_input1)
{
  sf_mex_call(c3_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c3_input0), 14,
              sf_mex_dup(c3_input1));
  sf_mex_destroy(&c3_input0);
  sf_mex_destroy(&c3_input1);
}

static void c3_b_xgemv(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, real_T c3_alpha1, real_T c3_ib_A[42], int32_T c3_ix0,
  real_T c3_y[6])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_b_alpha1;
  real_T c3_c;
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_c_a;
  int32_T c3_d_a;
  int32_T c3_e_a;
  int32_T c3_i;
  int32_T c3_ia;
  int32_T c3_iac;
  int32_T c3_iy;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_t_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_b_alpha1 = c3_alpha1;
  c3_b_ix0 = c3_ix0;
  if (!(c3_b_alpha1 == 0.0)) {
    c3_b_ix = c3_b_ix0 - 1;
    for (c3_iac = 0; c3_iac <= 30; c3_iac += 6) {
      c3_c = c3_b_alpha1 * c3_dv[c3_b_ix];
      c3_iy = 0;
      c3_a = c3_iac + 6;
      c3_i = c3_a;
      c3_b_st.site = &c3_u_emlrtRSI;
      c3_b_a = c3_iac + 1;
      c3_b = c3_i;
      c3_c_a = c3_b_a;
      c3_b_b = c3_b;
      if (c3_c_a > c3_b_b) {
        c3_overflow = false;
      } else {
        c3_overflow = (c3_b_b > 2147483646);
      }

      if (c3_overflow) {
        c3_c_st.site = &c3_v_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
      }

      for (c3_ia = c3_iac + 1; c3_ia <= c3_i; c3_ia++) {
        c3_y[c3_iy] += c3_ib_A[c3_ia - 1] * c3_c;
        c3_e_a = c3_iy + 1;
        c3_iy = c3_e_a;
      }

      c3_d_a = c3_b_ix + 1;
      c3_b_ix = c3_d_a;
    }
  }
}

static void c3_b_sqrt(SFc3_starshotsim_devInstanceStruct *chartInstance, real_T *
                      c3_x)
{
  *c3_x = muDoubleScalarSqrt(*c3_x);
}

static void c3_b_xscal(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_a, real_T c3_x[36], int32_T
  c3_ix0)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_b_a;
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_c;
  int32_T c3_b_ix0;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_n;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_e_a;
  int32_T c3_f_a;
  int32_T c3_i;
  int32_T c3_k;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_hc_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_c_n = c3_b_n;
  c3_b_a = c3_a;
  c3_b_ix0 = c3_ix0;
  c3_c_a = c3_c_n - 1;
  c3_c = c3_c_a;
  c3_b = c3_c;
  c3_b_c = c3_b;
  c3_d_a = c3_b_ix0;
  c3_b_b = c3_b_c;
  c3_i = c3_d_a + c3_b_b;
  c3_b_st.site = &c3_ic_emlrtRSI;
  c3_e_a = c3_b_ix0;
  c3_c_b = c3_i;
  c3_f_a = c3_e_a;
  c3_d_b = c3_c_b;
  if (c3_f_a > c3_d_b) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_d_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_v_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  for (c3_k = c3_b_ix0; c3_k <= c3_i; c3_k++) {
    c3_x[c3_k - 1] *= c3_b_a;
  }
}

static void c3_b_xzlarf(SFc3_starshotsim_devInstanceStruct *chartInstance, const
  emlrtStack *c3_sp, int32_T c3_m, int32_T c3_b_n, int32_T c3_iv0, real_T c3_tau,
  real_T c3_u_C[36], int32_T c3_ic0, real_T c3_work[6])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_f_st;
  emlrtStack c3_st;
  real_T c3_ib_A[36];
  real_T c3_y[6];
  real_T c3_alpha1;
  real_T c3_b_alpha1;
  real_T c3_c_alpha1;
  real_T c3_d_alpha1;
  real_T c3_h_c;
  real_T c3_temp;
  real_T c3_u_b;
  real_T c3_w_a;
  real_T c3_yjy;
  real_T c3_z;
  int32_T c3_a;
  int32_T c3_ab_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_c;
  int32_T c3_b_i;
  int32_T c3_b_ia;
  int32_T c3_b_ia0;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_b_iy;
  int32_T c3_b_jA;
  int32_T c3_b_jy;
  int32_T c3_b_lastc;
  int32_T c3_bb_a;
  int32_T c3_c;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_c;
  int32_T c3_c_ia0;
  int32_T c3_c_ix;
  int32_T c3_c_ix0;
  int32_T c3_c_m;
  int32_T c3_c_n;
  int32_T c3_cb_a;
  int32_T c3_colbottom;
  int32_T c3_coltop;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_d_c;
  int32_T c3_d_ia0;
  int32_T c3_d_ix0;
  int32_T c3_d_m;
  int32_T c3_db_a;
  int32_T c3_e_a;
  int32_T c3_e_b;
  int32_T c3_e_c;
  int32_T c3_e_ia0;
  int32_T c3_e_ix0;
  int32_T c3_e_m;
  int32_T c3_eb_a;
  int32_T c3_exitg1;
  int32_T c3_f_a;
  int32_T c3_f_b;
  int32_T c3_f_c;
  int32_T c3_f_ia0;
  int32_T c3_f_ix0;
  int32_T c3_f_m;
  int32_T c3_f_n;
  int32_T c3_fb_a;
  int32_T c3_g_a;
  int32_T c3_g_b;
  int32_T c3_g_c;
  int32_T c3_g_ia0;
  int32_T c3_g_m;
  int32_T c3_g_n;
  int32_T c3_h_a;
  int32_T c3_h_b;
  int32_T c3_h_m;
  int32_T c3_h_n;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i_m;
  int32_T c3_ia;
  int32_T c3_ia0;
  int32_T c3_iac;
  int32_T c3_ijA;
  int32_T c3_ix0;
  int32_T c3_iy;
  int32_T c3_iyend;
  int32_T c3_j;
  int32_T c3_j_a;
  int32_T c3_j_b;
  int32_T c3_j_n;
  int32_T c3_k_a;
  int32_T c3_k_b;
  int32_T c3_k_n;
  int32_T c3_lastc;
  int32_T c3_lastv;
  int32_T c3_m_a;
  int32_T c3_m_b;
  int32_T c3_m_n;
  int32_T c3_mm1;
  int32_T c3_nm1;
  int32_T c3_o_a;
  int32_T c3_o_b;
  int32_T c3_p_a;
  int32_T c3_p_b;
  int32_T c3_q_a;
  int32_T c3_q_b;
  int32_T c3_r_a;
  int32_T c3_r_b;
  int32_T c3_s_a;
  int32_T c3_s_b;
  int32_T c3_t_a;
  int32_T c3_t_b;
  int32_T c3_u_a;
  int32_T c3_v_a;
  int32_T c3_v_b;
  int32_T c3_w_b;
  int32_T c3_x_a;
  int32_T c3_x_b;
  int32_T c3_y_a;
  int32_T c3_y_b;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_d_overflow;
  boolean_T c3_e_overflow;
  boolean_T c3_exitg2;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_f_st.prev = &c3_e_st;
  c3_f_st.tls = c3_e_st.tls;
  if (c3_tau != 0.0) {
    c3_lastv = c3_m;
    c3_a = c3_m - 1;
    c3_c = c3_a;
    c3_b = c3_c;
    c3_b_c = c3_b;
    c3_b_a = c3_iv0;
    c3_b_b = c3_b_c;
    c3_b_i = c3_b_a + c3_b_b;
    while ((c3_lastv > 0) && (c3_u_C[c3_b_i - 1] == 0.0)) {
      c3_c_a = c3_lastv - 1;
      c3_lastv = c3_c_a;
      c3_d_a = c3_b_i - 1;
      c3_b_i = c3_d_a;
    }

    c3_st.site = &c3_tc_emlrtRSI;
    c3_d_m = c3_lastv;
    c3_f_n = c3_b_n;
    c3_b_ia0 = c3_ic0;
    c3_b_lastc = c3_f_n;
    c3_exitg2 = false;
    while ((!c3_exitg2) && (c3_b_lastc > 0)) {
      c3_f_a = c3_b_lastc - 1;
      c3_c_c = c3_f_a;
      c3_h_a = c3_c_c;
      c3_d_c = c3_h_a * 6;
      c3_j_a = c3_b_ia0;
      c3_e_b = c3_d_c;
      c3_coltop = c3_j_a + c3_e_b;
      c3_k_a = c3_d_m - 1;
      c3_f_c = c3_k_a;
      c3_m_a = c3_coltop;
      c3_h_b = c3_f_c;
      c3_colbottom = c3_m_a + c3_h_b;
      c3_b_st.site = &c3_wc_emlrtRSI;
      c3_o_a = c3_coltop;
      c3_j_b = c3_colbottom;
      c3_p_a = c3_o_a;
      c3_k_b = c3_j_b;
      if (c3_p_a > c3_k_b) {
        c3_b_overflow = false;
      } else {
        c3_b_overflow = (c3_k_b > 2147483646);
      }

      if (c3_b_overflow) {
        c3_c_st.site = &c3_v_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
      }

      c3_ia = c3_coltop;
      do {
        c3_exitg1 = 0;
        if (c3_ia <= c3_colbottom) {
          if (c3_u_C[c3_ia - 1] != 0.0) {
            c3_exitg1 = 1;
          } else {
            c3_ia++;
          }
        } else {
          c3_r_a = c3_b_lastc - 1;
          c3_b_lastc = c3_r_a;
          c3_exitg1 = 2;
        }
      } while (c3_exitg1 == 0);

      if (c3_exitg1 == 1) {
        c3_exitg2 = true;
      }
    }

    c3_lastc = c3_b_lastc;
  } else {
    c3_lastv = 0;
    c3_lastc = 0;
  }

  if (c3_lastv > 0) {
    c3_st.site = &c3_uc_emlrtRSI;
    c3_c_m = c3_lastv;
    c3_c_n = c3_lastc;
    for (c3_i = 0; c3_i < 36; c3_i++) {
      c3_ib_A[c3_i] = c3_u_C[c3_i];
    }

    c3_ia0 = c3_ic0;
    c3_ix0 = c3_iv0;
    c3_b_st.site = &c3_t_emlrtRSI;
    c3_e_m = c3_c_m;
    c3_g_n = c3_c_n;
    c3_c_ia0 = c3_ia0;
    c3_b_ix0 = c3_ix0;
    if (c3_g_n != 0) {
      c3_e_a = c3_e_m - 1;
      c3_mm1 = c3_e_a;
      c3_g_a = c3_g_n - 1;
      c3_nm1 = c3_g_a;
      c3_c_b = c3_nm1;
      c3_e_c = c3_c_b;
      c3_d_b = c3_e_c + 1;
      c3_iyend = c3_d_b;
      c3_c_st.site = &c3_mc_emlrtRSI;
      c3_f_b = c3_iyend;
      c3_g_b = c3_f_b;
      if (c3_g_b < 1) {
        c3_overflow = false;
      } else {
        c3_overflow = (c3_g_b > 2147483646);
      }

      if (c3_overflow) {
        c3_d_st.site = &c3_v_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
      }

      c3_i2 = static_cast<uint8_T>(c3_iyend) - 1;
      for (c3_iy = 0; c3_iy <= c3_i2; c3_iy++) {
        c3_b_iy = c3_iy;
        c3_work[c3_b_iy] = 0.0;
      }

      c3_b_iy = 0;
      c3_m_b = c3_nm1;
      c3_g_c = 6 * c3_m_b;
      c3_q_a = c3_c_ia0;
      c3_o_b = c3_g_c;
      c3_i3 = c3_q_a + c3_o_b;
      for (c3_iac = c3_c_ia0; c3_iac <= c3_i3; c3_iac += 6) {
        c3_b_ix = c3_b_ix0 - 1;
        c3_h_c = 0.0;
        c3_t_a = c3_iac;
        c3_p_b = c3_mm1;
        c3_i4 = c3_t_a + c3_p_b;
        c3_c_st.site = &c3_xc_emlrtRSI;
        c3_u_a = c3_iac;
        c3_s_b = c3_i4;
        c3_v_a = c3_u_a;
        c3_t_b = c3_s_b;
        if (c3_v_a > c3_t_b) {
          c3_d_overflow = false;
        } else {
          c3_d_overflow = (c3_t_b > 2147483646);
        }

        if (c3_d_overflow) {
          c3_d_st.site = &c3_v_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
        }

        for (c3_b_ia = c3_iac; c3_b_ia <= c3_i4; c3_b_ia++) {
          c3_w_a = c3_ib_A[c3_b_ia - 1];
          c3_u_b = c3_ib_A[c3_b_ix];
          c3_z = c3_w_a * c3_u_b;
          c3_h_c += c3_z;
          c3_cb_a = c3_b_ix + 1;
          c3_b_ix = c3_cb_a;
        }

        c3_work[c3_b_iy] += c3_h_c;
        c3_y_a = c3_b_iy + 1;
        c3_b_iy = c3_y_a;
      }
    }

    c3_st.site = &c3_vc_emlrtRSI;
    c3_f_m = c3_lastv;
    c3_h_n = c3_lastc;
    c3_alpha1 = -c3_tau;
    c3_c_ix0 = c3_iv0;
    for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
      c3_y[c3_i1] = c3_work[c3_i1];
    }

    c3_d_ia0 = c3_ic0;
    c3_b_st.site = &c3_oc_emlrtRSI;
    c3_g_m = c3_f_m;
    c3_j_n = c3_h_n;
    c3_b_alpha1 = c3_alpha1;
    c3_d_ix0 = c3_c_ix0;
    c3_e_ia0 = c3_d_ia0;
    c3_c_st.site = &c3_pc_emlrtRSI;
    c3_h_m = c3_g_m;
    c3_k_n = c3_j_n;
    c3_c_alpha1 = c3_b_alpha1;
    c3_e_ix0 = c3_d_ix0;
    c3_f_ia0 = c3_e_ia0;
    c3_d_st.site = &c3_qc_emlrtRSI;
    c3_i_m = c3_h_m;
    c3_m_n = c3_k_n;
    c3_d_alpha1 = c3_c_alpha1;
    c3_f_ix0 = c3_e_ix0;
    c3_g_ia0 = c3_f_ia0;
    if (!(c3_d_alpha1 == 0.0)) {
      c3_s_a = c3_g_ia0 - 1;
      c3_b_jA = c3_s_a;
      c3_b_jy = 0;
      c3_e_st.site = &c3_rc_emlrtRSI;
      c3_q_b = c3_m_n;
      c3_r_b = c3_q_b;
      if (c3_r_b < 1) {
        c3_c_overflow = false;
      } else {
        c3_c_overflow = (c3_r_b > 2147483646);
      }

      if (c3_c_overflow) {
        c3_f_st.site = &c3_v_emlrtRSI;
        c3_check_forloop_overflow_error(chartInstance, &c3_f_st);
      }

      c3_i5 = static_cast<uint8_T>(c3_m_n) - 1;
      for (c3_j = 0; c3_j <= c3_i5; c3_j++) {
        c3_yjy = c3_y[c3_b_jy];
        if (c3_yjy != 0.0) {
          c3_temp = c3_yjy * c3_d_alpha1;
          c3_c_ix = c3_f_ix0 - 1;
          c3_v_b = c3_b_jA + 1;
          c3_i6 = c3_v_b;
          c3_bb_a = c3_i_m;
          c3_w_b = c3_b_jA;
          c3_i7 = c3_bb_a + c3_w_b;
          c3_e_st.site = &c3_sc_emlrtRSI;
          c3_db_a = c3_i6;
          c3_x_b = c3_i7;
          c3_eb_a = c3_db_a;
          c3_y_b = c3_x_b;
          if (c3_eb_a > c3_y_b) {
            c3_e_overflow = false;
          } else {
            c3_e_overflow = (c3_y_b > 2147483646);
          }

          if (c3_e_overflow) {
            c3_f_st.site = &c3_v_emlrtRSI;
            c3_check_forloop_overflow_error(chartInstance, &c3_f_st);
          }

          for (c3_ijA = c3_i6; c3_ijA <= c3_i7; c3_ijA++) {
            c3_u_C[c3_ijA - 1] += c3_u_C[c3_c_ix] * c3_temp;
            c3_fb_a = c3_c_ix + 1;
            c3_c_ix = c3_fb_a;
          }
        }

        c3_x_a = c3_b_jy + 1;
        c3_b_jy = c3_x_a;
        c3_ab_a = c3_b_jA + 6;
        c3_b_jA = c3_ab_a;
      }
    }
  }
}

static int32_T c3_b_xhseqr(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, real_T c3_h[36], real_T c3_z[36])
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_st;
  real_T c3_b_v[3];
  real_T c3_aa;
  real_T c3_ab;
  real_T c3_ab_x;
  real_T c3_ab_y;
  real_T c3_ac_x;
  real_T c3_ad_x;
  real_T c3_ae_x;
  real_T c3_af_x;
  real_T c3_alpha;
  real_T c3_b_alpha;
  real_T c3_b_d1;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_bb_x;
  real_T c3_bb_y;
  real_T c3_bc_x;
  real_T c3_bd_x;
  real_T c3_bf_x;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_cb_x;
  real_T c3_cb_y;
  real_T c3_cc_x;
  real_T c3_cd_x;
  real_T c3_ce_x;
  real_T c3_cf_x;
  real_T c3_cs;
  real_T c3_d;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d_y;
  real_T c3_db_x;
  real_T c3_db_y;
  real_T c3_dc_x;
  real_T c3_dd_x;
  real_T c3_de_x;
  real_T c3_det;
  real_T c3_df_x;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_eb_x;
  real_T c3_eb_y;
  real_T c3_ec_x;
  real_T c3_ed_x;
  real_T c3_ee_x;
  real_T c3_ef_x;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_fb_x;
  real_T c3_fb_y;
  real_T c3_fc_x;
  real_T c3_fd_x;
  real_T c3_fe_x;
  real_T c3_ff_x;
  real_T c3_g_y;
  real_T c3_gb_x;
  real_T c3_gb_y;
  real_T c3_gc_x;
  real_T c3_gd_x;
  real_T c3_ge_x;
  real_T c3_h11;
  real_T c3_h12;
  real_T c3_h21;
  real_T c3_h21s;
  real_T c3_h22;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_hb_x;
  real_T c3_hb_y;
  real_T c3_hc_x;
  real_T c3_hd_x;
  real_T c3_he_x;
  real_T c3_ib_x;
  real_T c3_ib_y;
  real_T c3_ic_x;
  real_T c3_id_x;
  real_T c3_ie_x;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_jb_x;
  real_T c3_jb_y;
  real_T c3_jc_x;
  real_T c3_jd_x;
  real_T c3_je_x;
  real_T c3_k_bb;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_kb_x;
  real_T c3_kb_y;
  real_T c3_kc_x;
  real_T c3_kd_x;
  real_T c3_ke_x;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_mb_x;
  real_T c3_mb_y;
  real_T c3_mc_x;
  real_T c3_md_x;
  real_T c3_me_x;
  real_T c3_o_y;
  real_T c3_ob_x;
  real_T c3_ob_y;
  real_T c3_oc_x;
  real_T c3_od_x;
  real_T c3_oe_x;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_pb_x;
  real_T c3_pb_y;
  real_T c3_pc_x;
  real_T c3_pd_x;
  real_T c3_pe_x;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_qb_x;
  real_T c3_qb_y;
  real_T c3_qc_x;
  real_T c3_qd_x;
  real_T c3_qe_x;
  real_T c3_r_y;
  real_T c3_rb_x;
  real_T c3_rc_x;
  real_T c3_rd_x;
  real_T c3_re_x;
  real_T c3_rt1i;
  real_T c3_rt1r;
  real_T c3_rt2i;
  real_T c3_rt2r;
  real_T c3_rtdisc;
  real_T c3_s;
  real_T c3_s_x;
  real_T c3_s_y;
  real_T c3_sb_x;
  real_T c3_sc_x;
  real_T c3_sd_x;
  real_T c3_se_x;
  real_T c3_sn;
  real_T c3_sum;
  real_T c3_t1;
  real_T c3_t2;
  real_T c3_t3;
  real_T c3_t_y;
  real_T c3_tb_x;
  real_T c3_tc_x;
  real_T c3_td_x;
  real_T c3_te_x;
  real_T c3_tr;
  real_T c3_tst;
  real_T c3_u_x;
  real_T c3_u_y;
  real_T c3_ub_x;
  real_T c3_uc_x;
  real_T c3_ud_x;
  real_T c3_ue_x;
  real_T c3_v2;
  real_T c3_v3;
  real_T c3_v_x;
  real_T c3_v_y;
  real_T c3_vb_x;
  real_T c3_vc_x;
  real_T c3_vd_x;
  real_T c3_ve_x;
  real_T c3_w_ba;
  real_T c3_w_x;
  real_T c3_w_y;
  real_T c3_wb_x;
  real_T c3_wc_x;
  real_T c3_wd_x;
  real_T c3_we_x;
  real_T c3_x;
  real_T c3_x_x;
  real_T c3_x_y;
  real_T c3_xb_x;
  real_T c3_xc_x;
  real_T c3_xd_x;
  real_T c3_xe_x;
  real_T c3_y;
  real_T c3_y_x;
  real_T c3_y_y;
  real_T c3_yb_x;
  real_T c3_yc_x;
  real_T c3_yd_x;
  real_T c3_ye_x;
  int32_T c3_a;
  int32_T c3_b;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_i;
  int32_T c3_b_ih;
  int32_T c3_b_info;
  int32_T c3_b_j;
  int32_T c3_b_k;
  int32_T c3_b_n;
  int32_T c3_b_r;
  int32_T c3_b_t;
  int32_T c3_c_a;
  int32_T c3_c_b;
  int32_T c3_c_i;
  int32_T c3_c_info;
  int32_T c3_c_j;
  int32_T c3_c_k;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_d_j;
  int32_T c3_d_k;
  int32_T c3_d_x;
  int32_T c3_e_b;
  int32_T c3_e_j;
  int32_T c3_f_b;
  int32_T c3_f_j;
  int32_T c3_g_b;
  int32_T c3_g_j;
  int32_T c3_g_x;
  int32_T c3_h_b;
  int32_T c3_h_j;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i_j;
  int32_T c3_i_x;
  int32_T c3_im1;
  int32_T c3_its;
  int32_T c3_ix0;
  int32_T c3_j;
  int32_T c3_k;
  int32_T c3_k_j;
  int32_T c3_k_l;
  int32_T c3_kdefl;
  int32_T c3_m;
  int32_T c3_m_j;
  int32_T c3_nr;
  int32_T c3_o_x;
  int32_T c3_r;
  int32_T c3_r_x;
  int32_T c3_t;
  int32_T c3_t_x;
  boolean_T c3_b_overflow;
  boolean_T c3_c_overflow;
  boolean_T c3_converged;
  boolean_T c3_d_overflow;
  boolean_T c3_exitg1;
  boolean_T c3_exitg2;
  boolean_T c3_exitg3;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_jd_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  c3_b_st.site = &c3_kd_emlrtRSI;
  c3_b_info = 0;
  c3_c_st.site = &c3_md_emlrtRSI;
  c3_c_st.site = &c3_od_emlrtRSI;
  c3_j = 0;
  for (c3_b_j = 0; c3_b_j < 3; c3_b_j++) {
    c3_h[c3_j + 2] = 0.0;
    c3_h[c3_j + 3] = 0.0;
    c3_j += 7;
  }

  c3_h[23] = 0.0;
  c3_kdefl = 0;
  c3_i = 5;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_i + 1 >= 1)) {
    c3_k_l = 1;
    c3_converged = false;
    c3_its = 0;
    c3_exitg2 = false;
    while ((!c3_exitg2) && (c3_its < 301)) {
      c3_k = c3_i;
      c3_exitg3 = false;
      while ((!c3_exitg3) && (c3_k + 1 > c3_k_l)) {
        c3_x = c3_h[c3_k + 6 * (c3_k - 1)];
        c3_b_x = c3_x;
        c3_c_x = c3_b_x;
        c3_y = muDoubleScalarAbs(c3_c_x);
        if (c3_y <= 6.0125050800269183E-292) {
          c3_exitg3 = true;
        } else {
          c3_e_x = c3_h[(c3_k + 6 * (c3_k - 1)) - 1];
          c3_f_x = c3_e_x;
          c3_h_x = c3_f_x;
          c3_b_y = muDoubleScalarAbs(c3_h_x);
          c3_j_x = c3_h[c3_k + 6 * c3_k];
          c3_k_x = c3_j_x;
          c3_m_x = c3_k_x;
          c3_c_y = muDoubleScalarAbs(c3_m_x);
          c3_tst = c3_b_y + c3_c_y;
          if (c3_tst == 0.0) {
            if (c3_k - 1 >= 1) {
              c3_v_x = c3_h[(c3_k + 6 * (c3_k - 2)) - 1];
              c3_y_x = c3_v_x;
              c3_db_x = c3_y_x;
              c3_tst = muDoubleScalarAbs(c3_db_x);
            }

            if (c3_k + 2 <= 6) {
              c3_cb_x = c3_h[(c3_k + 6 * c3_k) + 1];
              c3_fb_x = c3_cb_x;
              c3_gb_x = c3_fb_x;
              c3_g_y = muDoubleScalarAbs(c3_gb_x);
              c3_tst += c3_g_y;
            }
          }

          c3_u_x = c3_h[c3_k + 6 * (c3_k - 1)];
          c3_x_x = c3_u_x;
          c3_bb_x = c3_x_x;
          c3_e_y = muDoubleScalarAbs(c3_bb_x);
          if (c3_e_y <= 2.2204460492503131E-16 * c3_tst) {
            c3_ib_x = c3_h[c3_k + 6 * (c3_k - 1)];
            c3_kb_x = c3_ib_x;
            c3_ob_x = c3_kb_x;
            c3_j_y = muDoubleScalarAbs(c3_ob_x);
            c3_qb_x = c3_h[(c3_k + 6 * c3_k) - 1];
            c3_sb_x = c3_qb_x;
            c3_vb_x = c3_sb_x;
            c3_m_y = muDoubleScalarAbs(c3_vb_x);
            c3_ab = muDoubleScalarMax(c3_j_y, c3_m_y);
            c3_yb_x = c3_h[c3_k + 6 * (c3_k - 1)];
            c3_bc_x = c3_yb_x;
            c3_dc_x = c3_bc_x;
            c3_p_y = muDoubleScalarAbs(c3_dc_x);
            c3_fc_x = c3_h[(c3_k + 6 * c3_k) - 1];
            c3_hc_x = c3_fc_x;
            c3_jc_x = c3_hc_x;
            c3_r_y = muDoubleScalarAbs(c3_jc_x);
            c3_w_ba = muDoubleScalarMin(c3_p_y, c3_r_y);
            c3_oc_x = c3_h[c3_k + 6 * c3_k];
            c3_qc_x = c3_oc_x;
            c3_sc_x = c3_qc_x;
            c3_u_y = muDoubleScalarAbs(c3_sc_x);
            c3_tc_x = c3_h[(c3_k + 6 * (c3_k - 1)) - 1] - c3_h[c3_k + 6 * c3_k];
            c3_uc_x = c3_tc_x;
            c3_vc_x = c3_uc_x;
            c3_v_y = muDoubleScalarAbs(c3_vc_x);
            c3_aa = muDoubleScalarMax(c3_u_y, c3_v_y);
            c3_wc_x = c3_h[c3_k + 6 * c3_k];
            c3_xc_x = c3_wc_x;
            c3_yc_x = c3_xc_x;
            c3_w_y = muDoubleScalarAbs(c3_yc_x);
            c3_cd_x = c3_h[(c3_k + 6 * (c3_k - 1)) - 1] - c3_h[c3_k + 6 * c3_k];
            c3_ed_x = c3_cd_x;
            c3_fd_x = c3_ed_x;
            c3_y_y = muDoubleScalarAbs(c3_fd_x);
            c3_k_bb = muDoubleScalarMin(c3_w_y, c3_y_y);
            c3_s = c3_aa + c3_k_bb;
            if (c3_w_ba * (c3_ab / c3_s) <= muDoubleScalarMax
                (6.0125050800269183E-292, 2.2204460492503131E-16 * (c3_k_bb *
                  (c3_aa / c3_s)))) {
              c3_exitg3 = true;
            } else {
              c3_k--;
            }
          } else {
            c3_k--;
          }
        }
      }

      c3_k_l = c3_k + 1;
      if (c3_k + 1 > 1) {
        c3_h[c3_k + 6 * (c3_k - 1)] = 0.0;
      }

      if (c3_k + 1 >= c3_i) {
        c3_converged = true;
        c3_exitg2 = true;
      } else {
        c3_kdefl++;
        c3_d_x = c3_kdefl;
        c3_a = c3_d_x;
        c3_g_x = c3_a;
        c3_i_x = c3_g_x;
        c3_t = c3_div_nzp_s32(chartInstance, c3_i_x, 20, 0, 0U, 0, 0);
        c3_t *= 20;
        c3_r = c3_i_x - c3_t;
        if (c3_r == 0) {
          c3_p_x = c3_h[c3_i + 6 * (c3_i - 1)];
          c3_q_x = c3_p_x;
          c3_s_x = c3_q_x;
          c3_d_y = muDoubleScalarAbs(c3_s_x);
          c3_w_x = c3_h[(c3_i + 6 * (c3_i - 2)) - 1];
          c3_ab_x = c3_w_x;
          c3_eb_x = c3_ab_x;
          c3_f_y = muDoubleScalarAbs(c3_eb_x);
          c3_s = c3_d_y + c3_f_y;
          c3_h11 = 0.75 * c3_s + c3_h[c3_i + 6 * c3_i];
          c3_h12 = -0.4375 * c3_s;
          c3_h21 = c3_s;
          c3_h22 = c3_h11;
        } else {
          c3_o_x = c3_kdefl;
          c3_b_a = c3_o_x;
          c3_r_x = c3_b_a;
          c3_t_x = c3_r_x;
          c3_b_t = c3_div_nzp_s32(chartInstance, c3_t_x, 10, 0, 0U, 0, 0);
          c3_b_t *= 10;
          c3_b_r = c3_t_x - c3_b_t;
          if (c3_b_r == 0) {
            c3_hb_x = c3_h[(c3_k + 6 * c3_k) + 1];
            c3_jb_x = c3_hb_x;
            c3_mb_x = c3_jb_x;
            c3_h_y = muDoubleScalarAbs(c3_mb_x);
            c3_pb_x = c3_h[(c3_k + 6 * (c3_k + 1)) + 2];
            c3_rb_x = c3_pb_x;
            c3_ub_x = c3_rb_x;
            c3_k_y = muDoubleScalarAbs(c3_ub_x);
            c3_s = c3_h_y + c3_k_y;
            c3_h11 = 0.75 * c3_s + c3_h[c3_k + 6 * c3_k];
            c3_h12 = -0.4375 * c3_s;
            c3_h21 = c3_s;
            c3_h22 = c3_h11;
          } else {
            c3_h11 = c3_h[(c3_i + 6 * (c3_i - 1)) - 1];
            c3_h21 = c3_h[c3_i + 6 * (c3_i - 1)];
            c3_h12 = c3_h[(c3_i + 6 * c3_i) - 1];
            c3_h22 = c3_h[c3_i + 6 * c3_i];
          }
        }

        c3_tb_x = c3_h11;
        c3_wb_x = c3_tb_x;
        c3_xb_x = c3_wb_x;
        c3_o_y = muDoubleScalarAbs(c3_xb_x);
        c3_ac_x = c3_h12;
        c3_cc_x = c3_ac_x;
        c3_ec_x = c3_cc_x;
        c3_q_y = muDoubleScalarAbs(c3_ec_x);
        c3_gc_x = c3_h21;
        c3_ic_x = c3_gc_x;
        c3_kc_x = c3_ic_x;
        c3_s_y = muDoubleScalarAbs(c3_kc_x);
        c3_mc_x = c3_h22;
        c3_pc_x = c3_mc_x;
        c3_rc_x = c3_pc_x;
        c3_t_y = muDoubleScalarAbs(c3_rc_x);
        c3_s = ((c3_o_y + c3_q_y) + c3_s_y) + c3_t_y;
        if (c3_s == 0.0) {
          c3_rt1r = 0.0;
          c3_rt1i = 0.0;
          c3_rt2r = 0.0;
          c3_rt2i = 0.0;
        } else {
          c3_h11 /= c3_s;
          c3_h21 /= c3_s;
          c3_h12 /= c3_s;
          c3_h22 /= c3_s;
          c3_tr = (c3_h11 + c3_h22) / 2.0;
          c3_det = (c3_h11 - c3_tr) * (c3_h22 - c3_tr) - c3_h12 * c3_h21;
          c3_ad_x = c3_det;
          c3_bd_x = c3_ad_x;
          c3_dd_x = c3_bd_x;
          c3_x_y = muDoubleScalarAbs(c3_dd_x);
          c3_rtdisc = c3_x_y;
          c3_c_st.site = &c3_pd_emlrtRSI;
          c3_b_sqrt(chartInstance, &c3_rtdisc);
          if (c3_det >= 0.0) {
            c3_rt1r = c3_tr * c3_s;
            c3_rt2r = c3_rt1r;
            c3_rt1i = c3_rtdisc * c3_s;
            c3_rt2i = -c3_rt1i;
          } else {
            c3_rt1r = c3_tr + c3_rtdisc;
            c3_rt2r = c3_tr - c3_rtdisc;
            c3_md_x = c3_rt1r - c3_h22;
            c3_pd_x = c3_md_x;
            c3_qd_x = c3_pd_x;
            c3_cb_y = muDoubleScalarAbs(c3_qd_x);
            c3_td_x = c3_rt2r - c3_h22;
            c3_vd_x = c3_td_x;
            c3_wd_x = c3_vd_x;
            c3_eb_y = muDoubleScalarAbs(c3_wd_x);
            if (c3_cb_y <= c3_eb_y) {
              c3_rt1r *= c3_s;
              c3_rt2r = c3_rt1r;
            } else {
              c3_rt2r *= c3_s;
              c3_rt1r = c3_rt2r;
            }

            c3_rt1i = 0.0;
            c3_rt2i = 0.0;
          }
        }

        c3_m = c3_i - 1;
        c3_exitg3 = false;
        while ((!c3_exitg3) && (c3_m >= c3_k + 1)) {
          c3_h21s = c3_h[c3_m + 6 * (c3_m - 1)];
          c3_gd_x = c3_h[(c3_m + 6 * (c3_m - 1)) - 1] - c3_rt2r;
          c3_hd_x = c3_gd_x;
          c3_id_x = c3_hd_x;
          c3_ab_y = muDoubleScalarAbs(c3_id_x);
          c3_jd_x = c3_rt2i;
          c3_kd_x = c3_jd_x;
          c3_od_x = c3_kd_x;
          c3_bb_y = muDoubleScalarAbs(c3_od_x);
          c3_rd_x = c3_h21s;
          c3_sd_x = c3_rd_x;
          c3_ud_x = c3_sd_x;
          c3_db_y = muDoubleScalarAbs(c3_ud_x);
          c3_s = (c3_ab_y + c3_bb_y) + c3_db_y;
          c3_h21s = c3_h[c3_m + 6 * (c3_m - 1)] / c3_s;
          c3_b_v[0] = (c3_h21s * c3_h[(c3_m + 6 * c3_m) - 1] + (c3_h[(c3_m + 6 *
            (c3_m - 1)) - 1] - c3_rt1r) * ((c3_h[(c3_m + 6 * (c3_m - 1)) - 1] -
            c3_rt2r) / c3_s)) - c3_rt1i * (c3_rt2i / c3_s);
          c3_b_v[1] = c3_h21s * (((c3_h[(c3_m + 6 * (c3_m - 1)) - 1] + c3_h[c3_m
            + 6 * c3_m]) - c3_rt1r) - c3_rt2r);
          c3_b_v[2] = c3_h21s * c3_h[(c3_m + 6 * c3_m) + 1];
          c3_xd_x = c3_b_v[0];
          c3_yd_x = c3_xd_x;
          c3_ae_x = c3_yd_x;
          c3_fb_y = muDoubleScalarAbs(c3_ae_x);
          c3_ce_x = c3_b_v[1];
          c3_de_x = c3_ce_x;
          c3_ee_x = c3_de_x;
          c3_gb_y = muDoubleScalarAbs(c3_ee_x);
          c3_fe_x = c3_b_v[2];
          c3_ge_x = c3_fe_x;
          c3_he_x = c3_ge_x;
          c3_hb_y = muDoubleScalarAbs(c3_he_x);
          c3_s = (c3_fb_y + c3_gb_y) + c3_hb_y;
          for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
            c3_b_v[c3_i2] /= c3_s;
          }

          if (c3_m == c3_k + 1) {
            c3_exitg3 = true;
          } else {
            c3_ie_x = c3_h[(c3_m + 6 * (c3_m - 2)) - 1];
            c3_je_x = c3_ie_x;
            c3_ke_x = c3_je_x;
            c3_ib_y = muDoubleScalarAbs(c3_ke_x);
            c3_me_x = c3_b_v[1];
            c3_oe_x = c3_me_x;
            c3_pe_x = c3_oe_x;
            c3_jb_y = muDoubleScalarAbs(c3_pe_x);
            c3_qe_x = c3_b_v[2];
            c3_re_x = c3_qe_x;
            c3_se_x = c3_re_x;
            c3_kb_y = muDoubleScalarAbs(c3_se_x);
            c3_te_x = c3_b_v[0];
            c3_ue_x = c3_te_x;
            c3_ve_x = c3_ue_x;
            c3_mb_y = muDoubleScalarAbs(c3_ve_x);
            c3_we_x = c3_h[(c3_m + 6 * (c3_m - 2)) - 2];
            c3_xe_x = c3_we_x;
            c3_ye_x = c3_xe_x;
            c3_ob_y = muDoubleScalarAbs(c3_ye_x);
            c3_af_x = c3_h[(c3_m + 6 * (c3_m - 1)) - 1];
            c3_bf_x = c3_af_x;
            c3_cf_x = c3_bf_x;
            c3_pb_y = muDoubleScalarAbs(c3_cf_x);
            c3_df_x = c3_h[c3_m + 6 * c3_m];
            c3_ef_x = c3_df_x;
            c3_ff_x = c3_ef_x;
            c3_qb_y = muDoubleScalarAbs(c3_ff_x);
            if (c3_ib_y * (c3_jb_y + c3_kb_y) <= 2.2204460492503131E-16 *
                c3_mb_y * ((c3_ob_y + c3_pb_y) + c3_qb_y)) {
              c3_exitg3 = true;
            } else {
              c3_m--;
            }
          }
        }

        c3_c_i = c3_i;
        c3_c_st.site = &c3_qd_emlrtRSI;
        c3_c_a = c3_m;
        c3_b = c3_c_i;
        c3_d_a = c3_c_a;
        c3_b_b = c3_b;
        if (c3_d_a > c3_b_b) {
          c3_overflow = false;
        } else {
          c3_overflow = (c3_b_b > 2147483646);
        }

        if (c3_overflow) {
          c3_d_st.site = &c3_v_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
        }

        for (c3_b_k = c3_m; c3_b_k <= c3_c_i; c3_b_k++) {
          c3_i1 = (c3_i - c3_b_k) + 2;
          c3_nr = muIntScalarMin_sint32(3, c3_i1);
          if (c3_b_k > c3_m) {
            c3_b_ih = (c3_b_k - 2) * 6 + c3_b_k;
            c3_c_st.site = &c3_rd_emlrtRSI;
            c3_b_n = c3_nr;
            c3_ix0 = c3_b_ih - 2;
            c3_d_st.site = &c3_ce_emlrtRSI;
            c3_c_b = c3_b_n;
            c3_d_b = c3_c_b;
            if (c3_d_b < 1) {
              c3_b_overflow = false;
            } else {
              c3_b_overflow = (c3_d_b > 2147483646);
            }

            if (c3_b_overflow) {
              c3_e_st.site = &c3_v_emlrtRSI;
              c3_check_forloop_overflow_error(chartInstance, &c3_e_st);
            }

            for (c3_c_k = 0; c3_c_k < c3_b_n; c3_c_k++) {
              c3_d_k = c3_c_k;
              c3_b_v[c3_d_k] = c3_h[(c3_ix0 + c3_d_k) + 1];
            }
          }

          c3_alpha = c3_b_v[0];
          c3_b_alpha = c3_alpha;
          c3_c_st.site = &c3_sd_emlrtRSI;
          c3_t1 = c3_b_xzlarfg(chartInstance, &c3_c_st, c3_nr, &c3_b_alpha,
                               c3_b_v);
          if (c3_b_k > c3_m) {
            c3_h[(c3_b_k + 6 * (c3_b_k - 2)) - 1] = c3_b_alpha;
            c3_h[c3_b_k + 6 * (c3_b_k - 2)] = 0.0;
            if (c3_b_k < c3_i) {
              c3_h[(c3_b_k + 6 * (c3_b_k - 2)) + 1] = 0.0;
            }
          } else if (c3_m > c3_k_l) {
            c3_h[(c3_b_k + 6 * (c3_b_k - 2)) - 1] *= 1.0 - c3_t1;
          }

          c3_v2 = c3_b_v[1];
          c3_t2 = c3_t1 * c3_v2;
          if (c3_nr == 3) {
            c3_v3 = c3_b_v[2];
            c3_t3 = c3_t1 * c3_v3;
            for (c3_f_j = c3_b_k; c3_f_j < 7; c3_f_j++) {
              c3_sum = (c3_h[(c3_b_k + 6 * (c3_f_j - 1)) - 1] + c3_v2 *
                        c3_h[c3_b_k + 6 * (c3_f_j - 1)]) + c3_v3 * c3_h[(c3_b_k
                + 6 * (c3_f_j - 1)) + 1];
              c3_h[(c3_b_k + 6 * (c3_f_j - 1)) - 1] -= c3_sum * c3_t1;
              c3_h[c3_b_k + 6 * (c3_f_j - 1)] -= c3_sum * c3_t2;
              c3_h[(c3_b_k + 6 * (c3_f_j - 1)) + 1] -= c3_sum * c3_t3;
            }

            c3_i3 = c3_b_k + 3;
            c3_i4 = c3_i + 1;
            c3_i5 = muIntScalarMin_sint32(c3_i3, c3_i4);
            c3_c_st.site = &c3_vd_emlrtRSI;
            c3_g_b = c3_i5;
            c3_h_b = c3_g_b;
            if (c3_h_b < 1) {
              c3_d_overflow = false;
            } else {
              c3_d_overflow = (c3_h_b > 2147483646);
            }

            if (c3_d_overflow) {
              c3_d_st.site = &c3_v_emlrtRSI;
              c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
            }

            c3_i7 = static_cast<uint8_T>(c3_i5) - 1;
            for (c3_k_j = 0; c3_k_j <= c3_i7; c3_k_j++) {
              c3_h_j = c3_k_j;
              c3_sum = (c3_h[c3_h_j + 6 * (c3_b_k - 1)] + c3_v2 * c3_h[c3_h_j +
                        6 * c3_b_k]) + c3_v3 * c3_h[c3_h_j + 6 * (c3_b_k + 1)];
              c3_h[c3_h_j + 6 * (c3_b_k - 1)] -= c3_sum * c3_t1;
              c3_h[c3_h_j + 6 * c3_b_k] -= c3_sum * c3_t2;
              c3_h[c3_h_j + 6 * (c3_b_k + 1)] -= c3_sum * c3_t3;
            }

            c3_c_st.site = &c3_wd_emlrtRSI;
            for (c3_m_j = 0; c3_m_j < 6; c3_m_j++) {
              c3_sum = (c3_z[c3_m_j + 6 * (c3_b_k - 1)] + c3_v2 * c3_z[c3_m_j +
                        6 * c3_b_k]) + c3_v3 * c3_z[c3_m_j + 6 * (c3_b_k + 1)];
              c3_z[c3_m_j + 6 * (c3_b_k - 1)] -= c3_sum * c3_t1;
              c3_z[c3_m_j + 6 * c3_b_k] -= c3_sum * c3_t2;
              c3_z[c3_m_j + 6 * (c3_b_k + 1)] -= c3_sum * c3_t3;
            }
          } else if (c3_nr == 2) {
            for (c3_e_j = c3_b_k; c3_e_j < 7; c3_e_j++) {
              c3_sum = c3_h[(c3_b_k + 6 * (c3_e_j - 1)) - 1] + c3_v2 *
                c3_h[c3_b_k + 6 * (c3_e_j - 1)];
              c3_h[(c3_b_k + 6 * (c3_e_j - 1)) - 1] -= c3_sum * c3_t1;
              c3_h[c3_b_k + 6 * (c3_e_j - 1)] -= c3_sum * c3_t2;
            }

            c3_c_st.site = &c3_td_emlrtRSI;
            c3_e_b = c3_i + 1;
            c3_f_b = c3_e_b;
            if (c3_f_b < 1) {
              c3_c_overflow = false;
            } else {
              c3_c_overflow = (c3_f_b > 2147483646);
            }

            if (c3_c_overflow) {
              c3_d_st.site = &c3_v_emlrtRSI;
              c3_check_forloop_overflow_error(chartInstance, &c3_d_st);
            }

            c3_i6 = static_cast<uint8_T>(c3_i + 1) - 1;
            for (c3_g_j = 0; c3_g_j <= c3_i6; c3_g_j++) {
              c3_h_j = c3_g_j;
              c3_sum = c3_h[c3_h_j + 6 * (c3_b_k - 1)] + c3_v2 * c3_h[c3_h_j + 6
                * c3_b_k];
              c3_h[c3_h_j + 6 * (c3_b_k - 1)] -= c3_sum * c3_t1;
              c3_h[c3_h_j + 6 * c3_b_k] -= c3_sum * c3_t2;
            }

            c3_c_st.site = &c3_ud_emlrtRSI;
            for (c3_i_j = 0; c3_i_j < 6; c3_i_j++) {
              c3_sum = c3_z[c3_i_j + 6 * (c3_b_k - 1)] + c3_v2 * c3_z[c3_i_j + 6
                * c3_b_k];
              c3_z[c3_i_j + 6 * (c3_b_k - 1)] -= c3_sum * c3_t1;
              c3_z[c3_i_j + 6 * c3_b_k] -= c3_sum * c3_t2;
            }
          }
        }

        c3_its++;
      }
    }

    if (!c3_converged) {
      c3_b_info = c3_i + 1;
      c3_exitg1 = true;
    } else {
      if ((c3_k_l != c3_i + 1) && (c3_k_l == c3_i)) {
        c3_im1 = c3_i - 1;
        c3_d = c3_h[c3_im1 + 6 * c3_im1];
        c3_b_d1 = c3_h[c3_im1 + 6 * c3_i];
        c3_d2 = c3_h[c3_i + 6 * c3_im1];
        c3_d3 = c3_h[c3_i + 6 * c3_i];
        c3_c_st.site = &c3_xd_emlrtRSI;
        c3_b_xdlanv2(chartInstance, &c3_d, &c3_b_d1, &c3_d2, &c3_d3, &c3_d4,
                     &c3_d5, &c3_d6, &c3_d7, &c3_cs, &c3_sn);
        c3_h[c3_im1 + 6 * c3_im1] = c3_d;
        c3_h[c3_im1 + 6 * c3_i] = c3_b_d1;
        c3_h[c3_i + 6 * c3_im1] = c3_d2;
        c3_h[c3_i + 6 * c3_i] = c3_d3;
        if (c3_i + 1 < 6) {
          c3_c_st.site = &c3_yd_emlrtRSI;
          c3_c_xrot(chartInstance, &c3_c_st, 5 - c3_i, c3_h, ((c3_i + 1) * 6 +
                     c3_im1) + 1, ((c3_i + 1) * 6 + c3_i) + 1, c3_cs, c3_sn);
        }

        c3_c_st.site = &c3_ae_emlrtRSI;
        c3_d_xrot(chartInstance, &c3_c_st, c3_im1, c3_h, (c3_i - 1) * 6 + 1,
                  (c3_im1 + 1) * 6 + 1, c3_cs, c3_sn);
        c3_c_st.site = &c3_be_emlrtRSI;
        c3_d_xrot(chartInstance, &c3_c_st, 6, c3_z, (c3_i - 1) * 6 + 1, (c3_im1
                   + 1) * 6 + 1, c3_cs, c3_sn);
      }

      c3_kdefl = 0;
      c3_i = c3_k_l - 2;
    }
  }

  c3_c_j = 0;
  for (c3_d_j = 0; c3_d_j < 4; c3_d_j++) {
    for (c3_b_i = c3_d_j + 3; c3_b_i < 7; c3_b_i++) {
      c3_h[(c3_b_i + c3_c_j) - 1] = 0.0;
    }

    c3_c_j += 6;
  }

  c3_c_info = c3_b_info;
  return c3_c_info;
}

static real_T c3_b_xzlarfg(SFc3_starshotsim_devInstanceStruct *chartInstance,
  const emlrtStack *c3_sp, int32_T c3_b_n, real_T *c3_alpha1, real_T c3_x[3])
{
  emlrtStack c3_b_st;
  emlrtStack c3_st;
  real_T c3_a;
  real_T c3_b;
  real_T c3_b_x;
  real_T c3_b_x1;
  real_T c3_b_x2;
  real_T c3_b_y;
  real_T c3_beta1;
  real_T c3_c_a;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_a;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_g_x;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_a;
  real_T c3_tau;
  real_T c3_x1;
  real_T c3_x2;
  real_T c3_xnorm;
  real_T c3_y;
  int32_T c3_b_a;
  int32_T c3_b_b;
  int32_T c3_b_c;
  int32_T c3_b_k;
  int32_T c3_c;
  int32_T c3_c_b;
  int32_T c3_c_c;
  int32_T c3_c_k;
  int32_T c3_c_n;
  int32_T c3_d_a;
  int32_T c3_d_b;
  int32_T c3_d_c;
  int32_T c3_d_k;
  int32_T c3_e_b;
  int32_T c3_e_c;
  int32_T c3_f_a;
  int32_T c3_f_c;
  int32_T c3_f_n;
  int32_T c3_g_n;
  int32_T c3_h_b;
  int32_T c3_h_n;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_j_b;
  int32_T c3_j_n;
  int32_T c3_k;
  int32_T c3_k_a;
  int32_T c3_k_b;
  int32_T c3_k_n;
  int32_T c3_knt;
  int32_T c3_m_b;
  int32_T c3_nm1;
  boolean_T c3_f_b;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_tau = 0.0;
  if (!(c3_b_n <= 0)) {
    c3_nm1 = c3_b_n - 1;
    c3_xnorm = c3_b_xnrm2(chartInstance, c3_nm1, c3_x);
    if (c3_xnorm != 0.0) {
      c3_x1 = *c3_alpha1;
      c3_x2 = c3_xnorm;
      c3_a = c3_x1;
      c3_b = c3_x2;
      c3_beta1 = muDoubleScalarHypot(c3_a, c3_b);
      if (*c3_alpha1 >= 0.0) {
        c3_beta1 = -c3_beta1;
      }

      c3_b_x = c3_beta1;
      c3_c_x = c3_b_x;
      c3_d_x = c3_c_x;
      c3_y = muDoubleScalarAbs(c3_d_x);
      if (c3_y < 1.0020841800044864E-292) {
        c3_knt = 0;
        do {
          c3_b_a = c3_knt + 1;
          c3_knt = c3_b_a;
          c3_c_n = c3_nm1;
          c3_g_n = c3_c_n;
          c3_d_a = c3_g_n - 1;
          c3_c = c3_d_a;
          c3_b_b = c3_c;
          c3_b_c = c3_b_b;
          c3_c_b = c3_b_c + 2;
          c3_i = c3_c_b;
          for (c3_k = 2; c3_k <= c3_i; c3_k++) {
            c3_x[c3_k - 1] *= 9.9792015476736E+291;
          }

          c3_beta1 *= 9.9792015476736E+291;
          *c3_alpha1 *= 9.9792015476736E+291;
          c3_f_x = c3_beta1;
          c3_g_x = c3_f_x;
          c3_h_x = c3_g_x;
          c3_d_y = muDoubleScalarAbs(c3_h_x);
          if ((c3_d_y < 1.0020841800044864E-292) && (c3_knt < 20)) {
            c3_f_b = true;
          } else {
            c3_f_b = false;
          }
        } while (!!c3_f_b);

        c3_xnorm = c3_b_xnrm2(chartInstance, c3_nm1, c3_x);
        c3_b_x1 = *c3_alpha1;
        c3_b_x2 = c3_xnorm;
        c3_g_a = c3_b_x1;
        c3_g_b = c3_b_x2;
        c3_beta1 = muDoubleScalarHypot(c3_g_a, c3_g_b);
        if (*c3_alpha1 >= 0.0) {
          c3_beta1 = -c3_beta1;
        }

        c3_i_x = c3_beta1 - *c3_alpha1;
        c3_e_y = c3_beta1;
        c3_tau = c3_i_x / c3_e_y;
        c3_f_y = *c3_alpha1 - c3_beta1;
        *c3_alpha1 = 1.0 / c3_f_y;
        c3_j_n = c3_nm1;
        c3_h_a = *c3_alpha1;
        c3_k_n = c3_j_n;
        c3_j_a = c3_h_a;
        c3_k_a = c3_k_n - 1;
        c3_e_c = c3_k_a;
        c3_h_b = c3_e_c;
        c3_f_c = c3_h_b;
        c3_j_b = c3_f_c + 2;
        c3_i2 = c3_j_b;
        for (c3_c_k = 2; c3_c_k <= c3_i2; c3_c_k++) {
          c3_x[c3_c_k - 1] *= c3_j_a;
        }

        c3_st.site = &c3_ec_emlrtRSI;
        c3_k_b = c3_knt;
        c3_m_b = c3_k_b;
        if (c3_m_b < 1) {
          c3_overflow = false;
        } else {
          c3_overflow = (c3_m_b > 2147483646);
        }

        if (c3_overflow) {
          c3_b_st.site = &c3_v_emlrtRSI;
          c3_check_forloop_overflow_error(chartInstance, &c3_b_st);
        }

        for (c3_d_k = 0; c3_d_k < c3_knt; c3_d_k++) {
          c3_beta1 *= 1.0020841800044864E-292;
        }

        *c3_alpha1 = c3_beta1;
      } else {
        c3_e_x = c3_beta1 - *c3_alpha1;
        c3_b_y = c3_beta1;
        c3_tau = c3_e_x / c3_b_y;
        c3_c_y = *c3_alpha1 - c3_beta1;
        *c3_alpha1 = 1.0 / c3_c_y;
        c3_f_n = c3_nm1;
        c3_c_a = *c3_alpha1;
        c3_h_n = c3_f_n;
        c3_e_a = c3_c_a;
        c3_f_a = c3_h_n - 1;
        c3_c_c = c3_f_a;
        c3_d_b = c3_c_c;
        c3_d_c = c3_d_b;
        c3_e_b = c3_d_c + 2;
        c3_i1 = c3_e_b;
        for (c3_b_k = 2; c3_b_k <= c3_i1; c3_b_k++) {
          c3_x[c3_b_k - 1] *= c3_e_a;
        }

        *c3_alpha1 = c3_beta1;
      }
    }
  }

  return c3_tau;
}

static void c3_b_xdlanv2(SFc3_starshotsim_devInstanceStruct *chartInstance,
  real_T *c3_a, real_T *c3_b, real_T *c3_c, real_T *c3_d, real_T *c3_rt1r,
  real_T *c3_rt1i, real_T *c3_rt2r, real_T *c3_rt2i, real_T *c3_cs, real_T
  *c3_sn)
{
  real_T c3_aa;
  real_T c3_ab_x;
  real_T c3_ac_x;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_cc;
  real_T c3_b_x;
  real_T c3_b_x1;
  real_T c3_b_x2;
  real_T c3_b_y;
  real_T c3_bb_x;
  real_T c3_bc_x;
  real_T c3_bcmax;
  real_T c3_bcmis;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_cb_x;
  real_T c3_cc_x;
  real_T c3_cs1;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_db_x;
  real_T c3_dc_x;
  real_T c3_dd;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_eb_x;
  real_T c3_ec_x;
  real_T c3_f_b;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_fb_x;
  real_T c3_fc_x;
  real_T c3_g_b;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_gb_x;
  real_T c3_gc_x;
  real_T c3_h_b;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_hb_x;
  real_T c3_hc_x;
  real_T c3_i_x;
  real_T c3_ib_x;
  real_T c3_ic_x;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_jb_x;
  real_T c3_jc_x;
  real_T c3_k_bb;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_kb_x;
  real_T c3_kc_x;
  real_T c3_m_x;
  real_T c3_m_y;
  real_T c3_mb_x;
  real_T c3_mc_x;
  real_T c3_o_x;
  real_T c3_o_y;
  real_T c3_ob_x;
  real_T c3_oc_x;
  real_T c3_p;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_pb_x;
  real_T c3_pc_x;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_qb_x;
  real_T c3_qc_x;
  real_T c3_r_x;
  real_T c3_r_y;
  real_T c3_rb_x;
  real_T c3_rc_x;
  real_T c3_s_x;
  real_T c3_s_y;
  real_T c3_sab;
  real_T c3_sac;
  real_T c3_sb_x;
  real_T c3_sc_x;
  real_T c3_scale;
  real_T c3_sigma;
  real_T c3_sn1;
  real_T c3_t_x;
  real_T c3_t_y;
  real_T c3_tau;
  real_T c3_tb_x;
  real_T c3_tc_x;
  real_T c3_temp;
  real_T c3_u_x;
  real_T c3_u_y;
  real_T c3_ub_x;
  real_T c3_v_x;
  real_T c3_v_y;
  real_T c3_vb_x;
  real_T c3_w_x;
  real_T c3_w_y;
  real_T c3_wb_x;
  real_T c3_x;
  real_T c3_x1;
  real_T c3_x2;
  real_T c3_x_x;
  real_T c3_x_y;
  real_T c3_xb_x;
  real_T c3_y;
  real_T c3_y_x;
  real_T c3_yb_x;
  real_T c3_z;
  int32_T c3_count;
  if (*c3_c == 0.0) {
    *c3_cs = 1.0;
    *c3_sn = 0.0;
  } else if (*c3_b == 0.0) {
    *c3_cs = 0.0;
    *c3_sn = 1.0;
    c3_temp = *c3_d;
    *c3_d = *c3_a;
    *c3_a = c3_temp;
    *c3_b = -*c3_c;
    *c3_c = 0.0;
  } else if ((*c3_a - *c3_d == 0.0) && (static_cast<int32_T>(*c3_b < 0.0) !=
              static_cast<int32_T>(*c3_c < 0.0))) {
    *c3_cs = 1.0;
    *c3_sn = 0.0;
  } else {
    c3_temp = *c3_a - *c3_d;
    c3_p = 0.5 * c3_temp;
    c3_x = *c3_b;
    c3_b_x = c3_x;
    c3_c_x = c3_b_x;
    c3_y = muDoubleScalarAbs(c3_c_x);
    c3_f_x = *c3_c;
    c3_h_x = c3_f_x;
    c3_i_x = c3_h_x;
    c3_c_y = muDoubleScalarAbs(c3_i_x);
    c3_bcmax = muDoubleScalarMax(c3_y, c3_c_y);
    c3_b_b = *c3_b;
    if (!(c3_b_b < 0.0)) {
      c3_d_y = 1.0;
    } else {
      c3_d_y = -1.0;
    }

    c3_c_b = *c3_c;
    if (!(c3_c_b < 0.0)) {
      c3_f_y = 1.0;
    } else {
      c3_f_y = -1.0;
    }

    c3_s_x = *c3_b;
    c3_t_x = c3_s_x;
    c3_u_x = c3_t_x;
    c3_g_y = muDoubleScalarAbs(c3_u_x);
    c3_v_x = *c3_c;
    c3_w_x = c3_v_x;
    c3_x_x = c3_w_x;
    c3_h_y = muDoubleScalarAbs(c3_x_x);
    c3_bcmis = muDoubleScalarMin(c3_g_y, c3_h_y) * c3_d_y * c3_f_y;
    c3_y_x = c3_p;
    c3_ab_x = c3_y_x;
    c3_bb_x = c3_ab_x;
    c3_j_y = muDoubleScalarAbs(c3_bb_x);
    c3_scale = muDoubleScalarMax(c3_j_y, c3_bcmax);
    c3_z = c3_p / c3_scale * c3_p + c3_bcmax / c3_scale * c3_bcmis;
    if (c3_z >= 8.8817841970012523E-16) {
      c3_cb_x = c3_scale;
      c3_eb_x = c3_cb_x;
      c3_eb_x = muDoubleScalarSqrt(c3_eb_x);
      c3_hb_x = c3_z;
      c3_ib_x = c3_hb_x;
      c3_ib_x = muDoubleScalarSqrt(c3_ib_x);
      c3_b_a = c3_eb_x * c3_ib_x;
      c3_d_b = c3_p;
      if (!(c3_d_b < 0.0)) {
        c3_o_y = c3_b_a;
      } else {
        c3_o_y = -c3_b_a;
      }

      c3_z = c3_p + c3_o_y;
      *c3_a = *c3_d + c3_z;
      *c3_d -= c3_bcmax / c3_z * c3_bcmis;
      c3_x1 = *c3_c;
      c3_x2 = c3_z;
      c3_c_a = c3_x1;
      c3_e_b = c3_x2;
      c3_tau = muDoubleScalarHypot(c3_c_a, c3_e_b);
      *c3_cs = c3_z / c3_tau;
      *c3_sn = *c3_c / c3_tau;
      *c3_b -= *c3_c;
      *c3_c = 0.0;
    } else {
      c3_sigma = *c3_b + *c3_c;
      c3_db_x = c3_temp;
      c3_fb_x = c3_db_x;
      c3_gb_x = c3_fb_x;
      c3_k_y = muDoubleScalarAbs(c3_gb_x);
      c3_jb_x = c3_sigma;
      c3_kb_x = c3_jb_x;
      c3_mb_x = c3_kb_x;
      c3_m_y = muDoubleScalarAbs(c3_mb_x);
      c3_scale = muDoubleScalarMax(c3_k_y, c3_m_y);
      c3_count = 0;
      while ((c3_scale >= 7.4428285367870146E+137) && (c3_count <= 20)) {
        c3_sigma *= 1.3435752215134178E-138;
        c3_temp *= 1.3435752215134178E-138;
        c3_ob_x = c3_temp;
        c3_pb_x = c3_ob_x;
        c3_rb_x = c3_pb_x;
        c3_p_y = muDoubleScalarAbs(c3_rb_x);
        c3_ub_x = c3_sigma;
        c3_vb_x = c3_ub_x;
        c3_yb_x = c3_vb_x;
        c3_r_y = muDoubleScalarAbs(c3_yb_x);
        c3_scale = muDoubleScalarMax(c3_p_y, c3_r_y);
        c3_count++;
      }

      while ((c3_scale <= 1.3435752215134178E-138) && (c3_count <= 20)) {
        c3_sigma *= 7.4428285367870146E+137;
        c3_temp *= 7.4428285367870146E+137;
        c3_qb_x = c3_temp;
        c3_sb_x = c3_qb_x;
        c3_tb_x = c3_sb_x;
        c3_q_y = muDoubleScalarAbs(c3_tb_x);
        c3_xb_x = c3_sigma;
        c3_bc_x = c3_xb_x;
        c3_dc_x = c3_bc_x;
        c3_t_y = muDoubleScalarAbs(c3_dc_x);
        c3_scale = muDoubleScalarMax(c3_q_y, c3_t_y);
        c3_count++;
      }

      c3_p = 0.5 * c3_temp;
      c3_b_x1 = c3_sigma;
      c3_b_x2 = c3_temp;
      c3_d_a = c3_b_x1;
      c3_f_b = c3_b_x2;
      c3_tau = muDoubleScalarHypot(c3_d_a, c3_f_b);
      c3_wb_x = c3_sigma;
      c3_ac_x = c3_wb_x;
      c3_cc_x = c3_ac_x;
      c3_s_y = muDoubleScalarAbs(c3_cc_x);
      c3_ec_x = 0.5 * (1.0 + c3_s_y / c3_tau);
      *c3_cs = c3_ec_x;
      *c3_cs = muDoubleScalarSqrt(*c3_cs);
      c3_g_b = c3_sigma;
      if (!(c3_g_b < 0.0)) {
        c3_u_y = 1.0;
      } else {
        c3_u_y = -1.0;
      }

      *c3_sn = -(c3_p / (c3_tau * *c3_cs)) * c3_u_y;
      c3_aa = *c3_a * *c3_cs + *c3_b * *c3_sn;
      c3_k_bb = -*c3_a * *c3_sn + *c3_b * *c3_cs;
      c3_b_cc = *c3_c * *c3_cs + *c3_d * *c3_sn;
      c3_dd = -*c3_c * *c3_sn + *c3_d * *c3_cs;
      *c3_a = c3_aa * *c3_cs + c3_b_cc * *c3_sn;
      *c3_b = c3_k_bb * *c3_cs + c3_dd * *c3_sn;
      *c3_c = -c3_aa * *c3_sn + c3_b_cc * *c3_cs;
      *c3_d = -c3_k_bb * *c3_sn + c3_dd * *c3_cs;
      c3_temp = 0.5 * (*c3_a + *c3_d);
      *c3_a = c3_temp;
      *c3_d = c3_temp;
      if (*c3_c != 0.0) {
        if (*c3_b != 0.0) {
          if (static_cast<int32_T>(*c3_b < 0.0) == static_cast<int32_T>(*c3_c <
               0.0)) {
            c3_fc_x = *c3_b;
            c3_gc_x = c3_fc_x;
            c3_hc_x = c3_gc_x;
            c3_v_y = muDoubleScalarAbs(c3_hc_x);
            c3_ic_x = c3_v_y;
            c3_sab = c3_ic_x;
            c3_sab = muDoubleScalarSqrt(c3_sab);
            c3_jc_x = *c3_c;
            c3_kc_x = c3_jc_x;
            c3_mc_x = c3_kc_x;
            c3_w_y = muDoubleScalarAbs(c3_mc_x);
            c3_oc_x = c3_w_y;
            c3_sac = c3_oc_x;
            c3_sac = muDoubleScalarSqrt(c3_sac);
            c3_e_a = c3_sab * c3_sac;
            c3_h_b = *c3_c;
            if (!(c3_h_b < 0.0)) {
              c3_p = c3_e_a;
            } else {
              c3_p = -c3_e_a;
            }

            c3_pc_x = *c3_b + *c3_c;
            c3_qc_x = c3_pc_x;
            c3_rc_x = c3_qc_x;
            c3_x_y = muDoubleScalarAbs(c3_rc_x);
            c3_sc_x = c3_x_y;
            c3_tc_x = c3_sc_x;
            c3_tc_x = muDoubleScalarSqrt(c3_tc_x);
            c3_tau = 1.0 / c3_tc_x;
            *c3_a = c3_temp + c3_p;
            *c3_d = c3_temp - c3_p;
            *c3_b -= *c3_c;
            *c3_c = 0.0;
            c3_cs1 = c3_sab * c3_tau;
            c3_sn1 = c3_sac * c3_tau;
            c3_temp = *c3_cs * c3_cs1 - *c3_sn * c3_sn1;
            *c3_sn = *c3_cs * c3_sn1 + *c3_sn * c3_cs1;
            *c3_cs = c3_temp;
          }
        } else {
          *c3_b = -*c3_c;
          *c3_c = 0.0;
          c3_temp = *c3_cs;
          *c3_cs = -*c3_sn;
          *c3_sn = c3_temp;
        }
      }
    }
  }

  *c3_rt1r = *c3_a;
  *c3_rt2r = *c3_d;
  if (*c3_c == 0.0) {
    *c3_rt1i = 0.0;
    *c3_rt2i = 0.0;
  } else {
    c3_d_x = *c3_b;
    c3_e_x = c3_d_x;
    c3_g_x = c3_e_x;
    c3_b_y = muDoubleScalarAbs(c3_g_x);
    c3_j_x = c3_b_y;
    c3_k_x = c3_j_x;
    c3_k_x = muDoubleScalarSqrt(c3_k_x);
    c3_m_x = *c3_c;
    c3_o_x = c3_m_x;
    c3_p_x = c3_o_x;
    c3_e_y = muDoubleScalarAbs(c3_p_x);
    c3_q_x = c3_e_y;
    c3_r_x = c3_q_x;
    c3_r_x = muDoubleScalarSqrt(c3_r_x);
    *c3_rt1i = c3_k_x * c3_r_x;
    *c3_rt2i = -*c3_rt1i;
  }
}

static void c3_c_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36],
                      int32_T c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_b_c;
  real_T c3_b_s;
  real_T c3_temp;
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_c_n;
  int32_T c3_i;
  int32_T c3_iy;
  int32_T c3_k;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_je_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_c_n = c3_b_n;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_b_c = c3_c;
  c3_b_s = c3_s;
  c3_b_ix = c3_b_ix0 - 1;
  c3_iy = c3_b_iy0 - 1;
  c3_b_st.site = &c3_ke_emlrtRSI;
  c3_b = c3_c_n;
  c3_b_b = c3_b;
  if (c3_b_b < 1) {
    c3_overflow = false;
  } else {
    c3_overflow = (c3_b_b > 2147483646);
  }

  if (c3_overflow) {
    c3_c_st.site = &c3_v_emlrtRSI;
    c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
  }

  c3_i = static_cast<uint8_T>(c3_c_n) - 1;
  for (c3_k = 0; c3_k <= c3_i; c3_k++) {
    c3_temp = c3_b_c * c3_x[c3_b_ix] + c3_b_s * c3_x[c3_iy];
    c3_x[c3_iy] = c3_b_c * c3_x[c3_iy] - c3_b_s * c3_x[c3_b_ix];
    c3_x[c3_b_ix] = c3_temp;
    c3_iy += 6;
    c3_b_ix += 6;
  }
}

static void c3_d_xrot(SFc3_starshotsim_devInstanceStruct *chartInstance, const
                      emlrtStack *c3_sp, int32_T c3_b_n, real_T c3_x[36],
                      int32_T c3_ix0, int32_T c3_iy0, real_T c3_c, real_T c3_s)
{
  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_st;
  real_T c3_b_c;
  real_T c3_b_s;
  real_T c3_temp;
  int32_T c3_b;
  int32_T c3_b_b;
  int32_T c3_b_ix;
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_c_n;
  int32_T c3_i;
  int32_T c3_iy;
  int32_T c3_k;
  boolean_T c3_overflow;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_st.site = &c3_je_emlrtRSI;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_c_n = c3_b_n;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_b_c = c3_c;
  c3_b_s = c3_s;
  if (!(c3_c_n < 1)) {
    c3_b_ix = c3_b_ix0 - 1;
    c3_iy = c3_b_iy0 - 1;
    c3_b_st.site = &c3_ke_emlrtRSI;
    c3_b = c3_c_n;
    c3_b_b = c3_b;
    if (c3_b_b < 1) {
      c3_overflow = false;
    } else {
      c3_overflow = (c3_b_b > 2147483646);
    }

    if (c3_overflow) {
      c3_c_st.site = &c3_v_emlrtRSI;
      c3_check_forloop_overflow_error(chartInstance, &c3_c_st);
    }

    c3_i = static_cast<uint8_T>(c3_c_n) - 1;
    for (c3_k = 0; c3_k <= c3_i; c3_k++) {
      c3_temp = c3_b_c * c3_x[c3_b_ix] + c3_b_s * c3_x[c3_iy];
      c3_x[c3_iy] = c3_b_c * c3_x[c3_iy] - c3_b_s * c3_x[c3_b_ix];
      c3_x[c3_b_ix] = c3_temp;
      c3_iy++;
      c3_b_ix++;
    }
  }
}

static void c3_b_recomputeBlockDiag(SFc3_starshotsim_devInstanceStruct
  *chartInstance, real_T c3_ib_A[36], real_T c3_d_F[36], int32_T c3_blockFormat
  [5])
{
  real_T c3_a;
  real_T c3_a11;
  real_T c3_a22;
  real_T c3_ab_x;
  real_T c3_avg;
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_df;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_bb_x;
  real_T c3_c;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_cb_x;
  real_T c3_coshdelta;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_delta;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_expa;
  real_T c3_expa11;
  real_T c3_expa22;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_m_x;
  real_T c3_maxval;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_sinchdelta;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_w_x;
  real_T c3_x;
  real_T c3_x12;
  real_T c3_x_x;
  real_T c3_y;
  real_T c3_y_x;
  int32_T c3_b_j;
  int32_T c3_blockType;
  int32_T c3_j;
  for (c3_j = 0; c3_j < 5; c3_j++) {
    c3_b_j = c3_j;
    c3_blockType = c3_blockFormat[c3_b_j];
    if (c3_blockType != 0) {
      if (c3_blockType == 1) {
        c3_a11 = c3_ib_A[c3_b_j + 6 * c3_b_j];
        c3_a22 = c3_ib_A[(c3_b_j + 6 * (c3_b_j + 1)) + 1];
        c3_c_x = c3_a11;
        c3_expa11 = c3_c_x;
        c3_expa11 = muDoubleScalarExp(c3_expa11);
        c3_g_x = c3_a22;
        c3_expa22 = c3_g_x;
        c3_expa22 = muDoubleScalarExp(c3_expa22);
        c3_avg = (c3_a11 + c3_a22) / 2.0;
        c3_i_x = c3_a11 - c3_a22;
        c3_k_x = c3_i_x;
        c3_m_x = c3_k_x;
        c3_b_y = muDoubleScalarAbs(c3_m_x);
        c3_b_df = c3_b_y / 2.0;
        c3_varargin_1 = c3_avg;
        c3_varargin_2 = c3_b_df;
        c3_q_x = c3_varargin_1;
        c3_c_y = c3_varargin_2;
        c3_s_x = c3_q_x;
        c3_d_y = c3_c_y;
        c3_u_x = c3_s_x;
        c3_e_y = c3_d_y;
        c3_b_a = c3_u_x;
        c3_b_b = c3_e_y;
        c3_v_x = c3_b_a;
        c3_f_y = c3_b_b;
        c3_w_x = c3_v_x;
        c3_g_y = c3_f_y;
        c3_maxval = muDoubleScalarMax(c3_w_x, c3_g_y);
        if (c3_maxval < 709.782712893384) {
          c3_x_x = c3_avg;
          c3_y_x = c3_x_x;
          c3_y_x = muDoubleScalarExp(c3_y_x);
          c3_ab_x = (c3_a22 - c3_a11) / 2.0;
          if (c3_ab_x == 0.0) {
            c3_h_y = 1.0;
          } else {
            c3_bb_x = c3_ab_x;
            c3_cb_x = c3_bb_x;
            c3_cb_x = muDoubleScalarSinh(c3_cb_x);
            c3_h_y = c3_cb_x / c3_ab_x;
          }

          c3_x12 = c3_ib_A[c3_b_j + 6 * (c3_b_j + 1)] * c3_y_x * c3_h_y;
        } else {
          c3_x12 = c3_ib_A[c3_b_j + 6 * (c3_b_j + 1)] * (c3_expa22 - c3_expa11) /
            (c3_a22 - c3_a11);
        }

        c3_d_F[c3_b_j + 6 * c3_b_j] = c3_expa11;
        c3_d_F[c3_b_j + 6 * (c3_b_j + 1)] = c3_x12;
        c3_d_F[(c3_b_j + 6 * (c3_b_j + 1)) + 1] = c3_expa22;
      } else {
        c3_a = c3_ib_A[c3_b_j + 6 * c3_b_j];
        c3_b = c3_ib_A[c3_b_j + 6 * (c3_b_j + 1)];
        c3_c = c3_ib_A[(c3_b_j + 6 * c3_b_j) + 1];
        c3_d_x = c3_b * c3_c;
        c3_e_x = c3_d_x;
        c3_f_x = c3_e_x;
        c3_y = muDoubleScalarAbs(c3_f_x);
        c3_h_x = c3_y;
        c3_delta = c3_h_x;
        c3_delta = muDoubleScalarSqrt(c3_delta);
        c3_j_x = c3_a;
        c3_expa = c3_j_x;
        c3_expa = muDoubleScalarExp(c3_expa);
        c3_o_x = c3_delta;
        c3_coshdelta = c3_o_x;
        c3_coshdelta = muDoubleScalarCos(c3_coshdelta);
        c3_p_x = c3_delta;
        if (c3_p_x == 0.0) {
          c3_sinchdelta = 1.0;
        } else {
          c3_r_x = c3_p_x;
          c3_t_x = c3_r_x;
          c3_t_x = muDoubleScalarSin(c3_t_x);
          c3_sinchdelta = c3_t_x / c3_p_x;
        }

        c3_d_F[c3_b_j + 6 * c3_b_j] = c3_expa * c3_coshdelta;
        c3_d_F[(c3_b_j + 6 * c3_b_j) + 1] = c3_expa * c3_c * c3_sinchdelta;
        c3_d_F[c3_b_j + 6 * (c3_b_j + 1)] = c3_expa * c3_b * c3_sinchdelta;
        c3_d_F[(c3_b_j + 6 * (c3_b_j + 1)) + 1] = c3_d_F[c3_b_j + 6 * c3_b_j];
      }
    }
  }

  if (c3_blockFormat[4] == 0) {
    c3_x = c3_ib_A[35];
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarExp(c3_b_x);
    c3_d_F[35] = c3_b_x;
  }
}

static int32_T c3_div_nzp_s32(SFc3_starshotsim_devInstanceStruct *chartInstance,
  int32_T c3_numerator, int32_T c3_denominator, int32_T c3_EMLOvCount_src_loc,
  uint32_T c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T c3_length_src_loc)
{
  int32_T c3_quotient;
  uint32_T c3_absDenominator;
  uint32_T c3_absNumerator;
  uint32_T c3_tempAbsQuotient;
  boolean_T c3_quotientNeedsNegation;
  if (c3_numerator < 0) {
    c3_absNumerator = ~static_cast<uint32_T>(c3_numerator) + 1U;
  } else {
    c3_absNumerator = static_cast<uint32_T>(c3_numerator);
  }

  if (c3_denominator < 0) {
    c3_absDenominator = ~static_cast<uint32_T>(c3_denominator) + 1U;
  } else {
    c3_absDenominator = static_cast<uint32_T>(c3_denominator);
  }

  c3_quotientNeedsNegation = (static_cast<int32_T>(c3_numerator < 0) !=
    static_cast<int32_T>(c3_denominator < 0));
  c3_tempAbsQuotient = c3_absNumerator / c3_absDenominator;
  if (c3_quotientNeedsNegation) {
    c3_quotient = -static_cast<int32_T>(c3_tempAbsQuotient);
  } else {
    c3_quotient = static_cast<int32_T>(c3_tempAbsQuotient);
  }

  return c3_quotient;
}

static void init_dsm_address_info(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
}

static void init_simulink_io_address(SFc3_starshotsim_devInstanceStruct
  *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_J_k_k = (real_T (*)[36])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_X_k1_k = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_X_k_k = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_P_k_k = (real_T (*)[36])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_P_k1_k = (real_T (*)[36])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_starshotsim_dev_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3672563540U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3758139045U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1284126497U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1188502010U);
}

mxArray *sf_c3_starshotsim_dev_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c3_starshotsim_dev_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("varargout_1");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_starshotsim_dev_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_starshotsim_dev(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiA+wcTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Ks5oOtnwaKfDUm/AJQfEJ9tGJ8NCR9YOA2cP0"
    "TI9kcEVf2h4ECZfoj9AQT8IYPmDxA/szg+Mbkksyw1Ptk4vrgksag4I7+kODM3PiW1DGYuCAAA7"
    "AAh4w=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_starshotsim_dev_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sZdCm62Fx9mFuXCqtSP2VbC";
}

static void sf_opaque_initialize_c3_starshotsim_dev(void *chartInstanceVar)
{
  initialize_params_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
  initialize_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_starshotsim_dev(void *chartInstanceVar)
{
  enable_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_starshotsim_dev(void *chartInstanceVar)
{
  disable_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_starshotsim_dev(void *chartInstanceVar)
{
  sf_gateway_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_starshotsim_dev(SimStruct* S)
{
  return get_sim_state_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_starshotsim_dev(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_starshotsim_dev(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_starshotsim_devInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_starshotsim_dev_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_starshotsim_dev
      ((SFc3_starshotsim_devInstanceStruct*) chartInstanceVar);
    ((SFc3_starshotsim_devInstanceStruct*) chartInstanceVar)->
      ~SFc3_starshotsim_devInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_starshotsim_dev(void *chartInstanceVar)
{
  mdl_start_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc3_starshotsim_devInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c3_starshotsim_dev(void *chartInstanceVar)
{
  mdl_terminate_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_starshotsim_dev(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc3_starshotsim_dev((SFc3_starshotsim_devInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_starshotsim_dev_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWN1u40QUnrSl2hVQVQhpJVRp9wpxWXYlBBKCNk6yRLQ0wmlZ7U00sU/iUcZjd37SZMV78Er",
    "wBjwA3K/EBVxyxnHTrBvSmZT9Q1hK3bH9ne+c4/M3JrX2McFjB3+djwjZxvMd/G2Q2fFOua4t/G",
    "bXt8iX5frHdwmJshiGIEIzGLAJ8TuESTtU0lQR/0PQFL4HlXGjWSbaYpC5Y5kYgAQRoYA8k9qLV",
    "7HUcCZGLSMiy6x+SFiUhElmeFxHgTQ+EXz6T7y50R1kbDAJkW4BxDqRmRkmLU6Hq70g9UWQQDRS",
    "JvX2lQIdmtyaqo4N1yzn0JxA1BZKU/SCusHeUFMNgZ74Odnaq8JLdJbmnFHh7uuEqhByjA4Np3m",
    "Mf0+MRu85YaOESl2HhI5BHbFRwZ4JcGJnCp/uM0F1JhnlzZQHVpqjvR2ONh5jSnDfd4T21iXQUZ",
    "4xoT0TImyhn5uC9jk0oG+GnrwhnBubDWcMLkD6vd9BkI1B0iGcCD+di3fUnBRBOc8lR6xmKZxRe",
    "Rhh7CqI/eoGJp0KKYYjdFGMFxYKF7dVV7IxxoZvrWvb9F+r1pl0Fv1qLWzB2xyDd1zNeVuRCCjn",
    "yg/bzfIjGAMv+BtU0zWwM34PsFIs7mYYHbbaeFYsIxhmQokNMhEz96gcV1BFY/sOm5QDnKU2DSB",
    "GN89Vnwu6KY+M0lkaYMlpHB058l3HtoUGOaAROPcYSZkCVLiIK0/emCmbSIhGL+nCSmcJsxxcC0",
    "rUwIjGRSZH6GPfZnblK5sJfmiIh1iYNRRFronRfUa5cdQ5VUPMHwyPU4VV1o8XsTZ/1gJHNEogt",
    "p2TcTjGOosCXF+xsi3/EK0dMz1tgIoky10zyWBBx6ZrvdSd5nAqRiK7EC2ZpWE5ea2IKwCsGlQK",
    "JoZ1bOFy2kLl3bSWcN4tqrvvkGP9TDWnfRsbj0FgN7S22qmBRphVTYEjMip0G2zInuEQIxRTGhv",
    "1dNbqZ33Pzu/fkKv5fWvJ/P7Bwvy+W66jRz18TVIlmcYRrxfDmMzl7S/Ie89hP7DhgCPXcFd8l+",
    "dPFvC1Jbxk4Vzlu7vx4vObFb4NvFKr1QrcwQLu/QrPVgW3Xfqs/3tYfz7+o//bT3/u/7J9595N/",
    "LVr/LXif4ubbPrtt3bK9d7l3DSv0uNrhcwlHu5V4sGu1dM4SD972Jp8kbbMk+Bch52HZ/2gkPfz",
    "xmp9Nyv6Xl5/YGc1TOKiJsioHZf7NrumZrafsPI/X9B3+wZ/3F2IJ0Kef307/McHVfwyf21X/GX",
    "Xnd7o097oxfh9fXZ8uLYdT/5VOx4c3A5ffo+4wY69ih17xV6kR23Hgd7yyrbjWDdW5a0vjrxi3N",
    "ui5/9+efn2ufTtzZfY75fhyCvG3dY+33nkbX9+f0XdJZXnd99gO1bVe5+59E2z61fiNzfeL9dfz",
    "b+LBAnj8ZKdWXkbN0+DZXf/I/H9l6f/LufkpvVf+QH96aNDQfkUt2KzrW55uSPtd9D5LQlULd/v",
    "vo5+4pLf1Tl+F1eP69+u3Y/+BhhiHvQ=",
    ""
  };

  static char newstr [1533] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_starshotsim_dev(SimStruct *S)
{
  const char* newstr = sf_c3_starshotsim_dev_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1112794466U));
  ssSetChecksum1(S,(1660122864U));
  ssSetChecksum2(S,(821532644U));
  ssSetChecksum3(S,(386401993U));
}

static void mdlRTW_c3_starshotsim_dev(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_starshotsim_dev(SimStruct *S)
{
  SFc3_starshotsim_devInstanceStruct *chartInstance;
  chartInstance = (SFc3_starshotsim_devInstanceStruct *)utMalloc(sizeof
    (SFc3_starshotsim_devInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_starshotsim_devInstanceStruct));
  chartInstance = new (chartInstance) SFc3_starshotsim_devInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_starshotsim_dev;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_starshotsim_dev;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_starshotsim_dev;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c3_starshotsim_dev;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_starshotsim_dev;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_starshotsim_dev;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_starshotsim_dev;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_starshotsim_dev;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_starshotsim_dev;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_starshotsim_dev;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_starshotsim_dev;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_starshotsim_dev;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c3_JITStateAnimation,
    chartInstance->c3_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c3_starshotsim_dev(chartInstance);
}

void c3_starshotsim_dev_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_starshotsim_dev(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_starshotsim_dev(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_starshotsim_dev(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_starshotsim_dev_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
