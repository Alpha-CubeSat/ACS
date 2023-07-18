#ifndef RTW_HEADER_starshot_sim_types_h_
#define RTW_HEADER_starshot_sim_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_t1iK3hEY2vfm4NgJptzLGD_
#define DEFINED_TYPEDEF_FOR_struct_t1iK3hEY2vfm4NgJptzLGD_
typedef struct { real_T m ; real_T Ixx ; real_T Ixy ; real_T Ixz ; real_T Iyx
; real_T Iyy ; real_T Iyz ; real_T Izx ; real_T Izy ; real_T Izz ; real_T I [
9 ] ; real_T PI [ 9 ] ; real_T Ip [ 9 ] ; real_T Ixp ; real_T Iyp ; real_T
Izp ; real_T Iinv [ 9 ] ; } struct_t1iK3hEY2vfm4NgJptzLGD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_QWuG7JELzddtnXnwHzvVgD_
#define DEFINED_TYPEDEF_FOR_struct_QWuG7JELzddtnXnwHzvVgD_
typedef struct { real_T x ; real_T y ; real_T z ; real_T xdot ; real_T ydot ;
real_T zdot ; real_T eul [ 3 ] ; real_T w [ 3 ] ;
struct_t1iK3hEY2vfm4NgJptzLGD massproperties ; }
struct_QWuG7JELzddtnXnwHzvVgD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_odTrKlpr9cjuKyVSnQPFXB_
#define DEFINED_TYPEDEF_FOR_struct_odTrKlpr9cjuKyVSnQPFXB_
typedef struct { real_T i ; real_T a ; real_T T ; real_T tp ; real_T ts ;
real_T c ; real_T zeta ; real_T omegan ; real_T Ims ; real_T Res ; creal_T s1
; real_T ang_p ; real_T ang_c ; real_T Td ; real_T Kpd ; real_T Kd ; real_T
Kp ; } struct_odTrKlpr9cjuKyVSnQPFXB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_QFlG4YohdCMTa9HdmDzof_
#define DEFINED_TYPEDEF_FOR_struct_QFlG4YohdCMTa9HdmDzof_
typedef struct { real_T Kp [ 9 ] ; real_T Kd [ 9 ] ; real_T Id ; real_T invId
; real_T c ; real_T w [ 3 ] ; real_T wdb0 [ 3 ] ; }
struct_QFlG4YohdCMTa9HdmDzof ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_BxUlNur38amov8tPqkFMBH_
#define DEFINED_TYPEDEF_FOR_struct_BxUlNur38amov8tPqkFMBH_
typedef struct { real_T h ; real_T T ; real_T P ; real_T p ; real_T cd ;
real_T A ; real_T V ; real_T xag ; real_T Ta ; }
struct_BxUlNur38amov8tPqkFMBH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_rktuLj1kXlz7eaT1szkX5C_
#define DEFINED_TYPEDEF_FOR_struct_rktuLj1kXlz7eaT1szkX5C_
typedef struct { real_T V ; real_T k ; real_T A ; real_T n ; real_T m_max_x ;
real_T m_max_y ; real_T m_max_z ; real_T i_max_x ; real_T i_max_y ; real_T
i_max_z ; } struct_rktuLj1kXlz7eaT1szkX5C ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_AM7n5PowExllItHZCW0ZYH_
#define DEFINED_TYPEDEF_FOR_struct_AM7n5PowExllItHZCW0ZYH_
typedef struct { struct_QWuG7JELzddtnXnwHzvVgD IC ;
struct_odTrKlpr9cjuKyVSnQPFXB controller ; struct_QFlG4YohdCMTa9HdmDzof cmd ;
struct_BxUlNur38amov8tPqkFMBH aerodrag ; struct_rktuLj1kXlz7eaT1szkX5C
magnetorq ; } struct_AM7n5PowExllItHZCW0ZYH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_pRh2I6kb8EpGWYupLmWg4F_
#define DEFINED_TYPEDEF_FOR_struct_pRh2I6kb8EpGWYupLmWg4F_
typedef struct { real_T prodOutputMode ; real_T prodOutputWordLength ; real_T
prodOutputFracLength ; real_T accumMode ; real_T accumWordLength ; real_T
accumFracLength ; real_T outputMode ; real_T outputWordLength ; real_T
outputFracLength ; real_T roundingMode ; real_T overflowMode ; }
struct_pRh2I6kb8EpGWYupLmWg4F ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 25
#endif
#ifndef SS_INT64
#define SS_INT64 26
#endif
typedef struct P_ P ;
#endif
