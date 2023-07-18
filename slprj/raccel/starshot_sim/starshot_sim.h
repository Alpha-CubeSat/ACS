#ifndef RTW_HEADER_starshot_sim_h_
#define RTW_HEADER_starshot_sim_h_
#ifndef starshot_sim_COMMON_INCLUDES_
#define starshot_sim_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "starshot_sim_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME starshot_sim
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (31) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (16)   
#elif NCSTATES != 16
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T dl3osgoi5y [ 4 ] ; real_T eies2vobp0 ; real_T
dxtixaknsr ; real_T mh2cw3g21y ; real_T fiu0rfsd3a ; real_T mm0zbnflas ;
real_T hofhehwala ; real_T ol5jg0fvut [ 3 ] ; real_T e3zxffjpma [ 3 ] ;
real_T fnusqcsyq4 ; real_T femncko0cn [ 3 ] ; real_T fpijzyolrb ; real_T
mvhur03jr5 ; real_T iuda0ybz3k ; real_T lr40woa5vs [ 3 ] ; real_T otohkbp3bg
[ 3 ] ; real_T oytd10qstc ; real_T ao1jkqsvon ; real_T crqtrnf4td ; real_T
frdvfzrycc [ 3 ] ; real_T jpsplb3g3c [ 4 ] ; real_T cek4ch2hyg [ 3 ] ; real_T
eeqjatg1dy [ 3 ] ; real_T maipu1b40a ; real_T j2525zxruy ; real_T ghjrhwzi5l
; real_T i3p5tajv00 ; real_T fpzp3jifvq ; real_T kokbtkt104 ; real_T
ip5sbal02i ; real_T dwztvfu4wu [ 9 ] ; } B ; typedef struct { real_T
ogos4ffr2t ; real_T gcvqyir2vi ; real_T ond4jhxyao ; real_T jg3q0pzg5o ;
real_T ku5p2ni5nf ; real_T n1p1mm2auv [ 3 ] ; real_T cycn54lzew ; real_T
nfnayvw4de [ 3 ] ; struct { void * LoggedData [ 3 ] ; } edbxwvz1jp ; struct {
void * AQHandles ; } ow4wq5w5mm ; struct { void * LoggedData [ 3 ] ; }
iqwe4azqcv ; struct { void * LoggedData [ 3 ] ; } kmajz0sfwj ; struct { void
* AQHandles ; } aaja0aysz0 ; struct { void * LoggedData ; } mnlqyxwck2 ;
struct { void * AQHandles ; } hzbfcdgqjd ; struct { void * LoggedData [ 3 ] ;
} h30c31f5ui ; struct { void * LoggedData [ 3 ] ; } nkyfajxfft ; struct {
void * LoggedData [ 4 ] ; } mi1tlyzydp ; struct { void * AQHandles ; }
p2iiqtje1q ; struct { void * AQHandles ; } n4ujbk4ieg ; struct { void *
LoggedData [ 3 ] ; } fsavadaoi0 ; struct { void * AQHandles ; } egik531awp ;
struct { void * AQHandles ; } hnp1vq2ji2 ; struct { void * AQHandles ; }
c1v41m3tga ; struct { void * LoggedData [ 3 ] ; } hs1apb1hkv ; struct { void
* AQHandles ; } gsczcuj3aq ; struct { void * LoggedData [ 3 ] ; } mgo3q33zw1
; int_T c0pertugry ; int_T mjbfo4zbad ; int_T fzywhfz1mq ; int8_T nqpjy1fnao
; int8_T b3cxmfme20 ; int8_T nvceavffbk ; int8_T c5ymd2b5xe ; int8_T
aoua3yfzjz ; int8_T onplct1sg4 ; int8_T ayifxsfink ; int8_T o2dokb32i1 ;
int8_T cyspl0m50o ; int8_T kf3zmjwqmp ; int8_T eg24d5fcm1 ; int8_T oea32fuhjg
; int8_T fuvtfvj1xu ; int8_T f4mltievmu ; int8_T nekjo4wvrj ; } DW ; typedef
struct { real_T ih3kel1khg [ 3 ] ; real_T coq2qfoyy1 [ 4 ] ; real_T
kiwbiqrd0g ; real_T pnyvn52cos ; real_T p0mibproqm ; real_T exlhpb4fq0 [ 3 ]
; real_T m2uajr5r0q ; real_T icdropjsud ; real_T pseadm24fx ; } X ; typedef
struct { real_T ih3kel1khg [ 3 ] ; real_T coq2qfoyy1 [ 4 ] ; real_T
kiwbiqrd0g ; real_T pnyvn52cos ; real_T p0mibproqm ; real_T exlhpb4fq0 [ 3 ]
; real_T m2uajr5r0q ; real_T icdropjsud ; real_T pseadm24fx ; } XDot ;
typedef struct { boolean_T ih3kel1khg [ 3 ] ; boolean_T coq2qfoyy1 [ 4 ] ;
boolean_T kiwbiqrd0g ; boolean_T pnyvn52cos ; boolean_T p0mibproqm ;
boolean_T exlhpb4fq0 [ 3 ] ; boolean_T m2uajr5r0q ; boolean_T icdropjsud ;
boolean_T pseadm24fx ; } XDis ; typedef struct { real_T ih3kel1khg [ 3 ] ;
real_T coq2qfoyy1 [ 4 ] ; real_T kiwbiqrd0g ; real_T pnyvn52cos ; real_T
p0mibproqm ; real_T exlhpb4fq0 [ 3 ] ; real_T m2uajr5r0q ; real_T icdropjsud
; real_T pseadm24fx ; } CStateAbsTol ; typedef struct { real_T ih3kel1khg [ 3
] ; real_T coq2qfoyy1 [ 4 ] ; real_T kiwbiqrd0g ; real_T pnyvn52cos ; real_T
p0mibproqm ; real_T exlhpb4fq0 [ 3 ] ; real_T m2uajr5r0q ; real_T icdropjsud
; real_T pseadm24fx ; } CXPtMin ; typedef struct { real_T ih3kel1khg [ 3 ] ;
real_T coq2qfoyy1 [ 4 ] ; real_T kiwbiqrd0g ; real_T pnyvn52cos ; real_T
p0mibproqm ; real_T exlhpb4fq0 [ 3 ] ; real_T m2uajr5r0q ; real_T icdropjsud
; real_T pseadm24fx ; } CXPtMax ; typedef struct { real_T hb4rkfuhyw ; real_T
idowipttxg ; real_T cg45libmol ; real_T axm3zhwtj4 ; real_T mpl0t1ng4h ;
real_T d0vuxnac4h ; real_T hfqp4youyi [ 2 ] ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
struct_AM7n5PowExllItHZCW0ZYH starshot ; real_T B0 ; real_T G ; real_T
M_Earth ; real_T R_Earth ; real_T q0 [ 4 ] ; real_T Normalization_Bias ;
real_T Constant_Value ; real_T Constant_Value_lprubj2kwa ; real_T Gain1_Gain
; real_T Switch_Threshold ; real_T Switch1_Threshold ; real_T Gain2_Gain ;
real_T Gain_Gain ; real_T Gain1_Gain_gxm1ihqq0u ; real_T
Gain2_Gain_dg5gskg1nm ; real_T Gain1_Gain_fkz5w2tg5q ; real_T MatrixGain_Gain
[ 9 ] ; real_T Gain6_Gain ; real_T Gain5_Gain ; real_T Gain_Gain_cmgxch1a1l ;
real_T Gain1_Gain_mqjlhklks4 ; real_T Gain2_Gain_asqeevkcou ; real_T
Gain8_Gain ; real_T Gain18_Gain ; real_T Gain_Gain_ityqyfpnsc ; real_T
Gain1_Gain_eeykqncbdx ; real_T Gain2_Gain_icunypzv3n ; real_T Constant8_Value
; real_T Identitymatrix_Value [ 9 ] ; real_T Constant3_Value ; real_T
Constant12_Value ; real_T Constant3_Value_egvn5fzjrd ; real_T e_z_Value [ 3 ]
; real_T Gain_Gain_p3pw120zm1 ; real_T Gain1_Gain_ees4kdgcpe ; real_T
Gain2_Gain_ed1hn35ith ; real_T Constant3_Value_efe2zzothx ; real_T
Constant4_Value ; real_T Constant10_Value ; real_T Constant9_Value ; real_T
Constant3_Value_e341jwrb4z ; real_T diag0_Value ; uint8_T
Switch_CurrentSetting ; } ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR
; extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern
mxArray * mr_starshot_sim_GetDWork ( ) ; extern void mr_starshot_sim_SetDWork
( const mxArray * ssDW ) ; extern mxArray *
mr_starshot_sim_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * starshot_sim_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
