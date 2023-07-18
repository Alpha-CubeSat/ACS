#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "starshot_sim_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 25
#endif
#ifndef SS_INT64
#define SS_INT64 26
#endif
#else
#include "builtin_typeid_types.h"
#include "starshot_sim.h"
#include "starshot_sim_capi.h"
#include "starshot_sim_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"starshot_sim/Matrix Multiply" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 1 , 0 , TARGET_STRING ( "starshot_sim/Switch" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "starshot_sim/   /Gain18" ) ,
TARGET_STRING ( "Euler Angles plot" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 ,
TARGET_STRING ( "starshot_sim/     /Inv(I)" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING ( "starshot_sim/     /Integrator6" )
, TARGET_STRING ( "w" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"starshot_sim/Current/Gain7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 6 , 0 , TARGET_STRING ( "starshot_sim/Kane Damper_controller/Sum8" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 1 } , { 8 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 ,
1 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Integrator1" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Integrator2" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Integrator3" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Integrator4" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Integrator5" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Dot Product3" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Dot Product4" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"starshot_sim/Orbital Dynamics/Dot Product5" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"starshot_sim/Orientation controller/Trigonometric Function5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"starshot_sim/Saturation/Product2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 19 , 0 , TARGET_STRING ( "starshot_sim/Saturation/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"starshot_sim/Saturation/Saturation1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 21 , 0 , TARGET_STRING ( "starshot_sim/Saturation/Saturation2" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"starshot_sim/theta_(omegaB)/Gain8" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 0 } , { 23 , 0 , TARGET_STRING ( "starshot_sim/ /Dipole->ECI/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"starshot_sim/ /Dipole->ECI/Divide1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 0 } , { 25 , 0 , TARGET_STRING ( "starshot_sim/ /Dipole->ECI/Sum5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"starshot_sim/   /Normalized quat/Product2" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"starshot_sim/   /Quaternions to Rotation Angles/fcn3" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"starshot_sim/Orientation controller/Skew matrix/Vector Concatenate" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/Merge"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem/Constant"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1/Constant"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2/In"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 36 , TARGET_STRING ( "starshot_sim/Switch" ) ,
TARGET_STRING ( "CurrentSetting" ) , 1 , 1 , 0 } , { 37 , TARGET_STRING (
"starshot_sim/ /Constant8" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 38
, TARGET_STRING ( "starshot_sim/ /Gain5" ) , TARGET_STRING ( "Gain" ) , 0 , 1
, 0 } , { 39 , TARGET_STRING ( "starshot_sim/ /Gain6" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 40 , TARGET_STRING ( "starshot_sim/   /Gain18" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 41 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Identity matrix" ) , TARGET_STRING (
"Value" ) , 0 , 3 , 0 } , { 42 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Gain 1" ) , TARGET_STRING ( "Gain" ) , 0
, 1 , 0 } , { 43 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Normalization" ) , TARGET_STRING (
"Bias" ) , 0 , 1 , 0 } , { 44 , TARGET_STRING (
"starshot_sim/Orientation controller/Constant12" ) , TARGET_STRING ( "Value"
) , 0 , 1 , 0 } , { 45 , TARGET_STRING (
"starshot_sim/Orientation controller/e_z" ) , TARGET_STRING ( "Value" ) , 0 ,
4 , 0 } , { 46 , TARGET_STRING ( "starshot_sim/quat to DCM/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 47 , TARGET_STRING (
"starshot_sim/quat to DCM/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } ,
{ 48 , TARGET_STRING ( "starshot_sim/quat to DCM/Matrix Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 49 , TARGET_STRING (
"starshot_sim/theta_(omegaB)/Gain8" ) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0
} , { 50 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Skew matrix S(m)1/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 51 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Skew matrix S(m)1/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 52 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Skew matrix S(m)1/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 53 , TARGET_STRING (
"starshot_sim/Kane Damper_controller/Skew matrix S(m)1/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 54 , TARGET_STRING (
"starshot_sim/Orientation controller/Skew matrix/Constant3" ) , TARGET_STRING
( "Value" ) , 0 , 1 , 0 } , { 55 , TARGET_STRING (
"starshot_sim/Orientation controller/Skew matrix/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 56 , TARGET_STRING (
"starshot_sim/Orientation controller/Skew matrix/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 57 , TARGET_STRING (
"starshot_sim/Orientation controller/Skew matrix/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING (
"starshot_sim/Orientation controller/sign(cos_omegaB)/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 59 , TARGET_STRING (
"starshot_sim/Orientation controller/sign(cos_omegaB)/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 60 , TARGET_STRING (
"starshot_sim/Orientation controller/sign(cos_omegaB)/Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 1 , 0 } , { 61 , TARGET_STRING (
"starshot_sim/Orientation controller/sign_function1/Constant10" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 62 , TARGET_STRING (
"starshot_sim/Orientation controller/sign_function1/Constant9" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 63 , TARGET_STRING (
"starshot_sim/Orientation controller/sign_function1/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 1 , 0 } , { 64 , TARGET_STRING (
"starshot_sim/Saturation/Skew matrix S(m)/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 65 , TARGET_STRING (
"starshot_sim/Saturation/Skew matrix S(m)/Gain" ) , TARGET_STRING ( "Gain" )
, 0 , 1 , 0 } , { 66 , TARGET_STRING (
"starshot_sim/Saturation/Skew matrix S(m)/Gain1" ) , TARGET_STRING ( "Gain" )
, 0 , 1 , 0 } , { 67 , TARGET_STRING (
"starshot_sim/Saturation/Skew matrix S(m)/Gain2" ) , TARGET_STRING ( "Gain" )
, 0 , 1 , 0 } , { 68 , TARGET_STRING (
"starshot_sim/quat to DCM/Subsystem/diag 0 " ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 69 , TARGET_STRING (
"starshot_sim/quat to DCM/Subsystem/Gain" ) , TARGET_STRING ( "Gain" ) , 0 ,
1 , 0 } , { 70 , TARGET_STRING ( "starshot_sim/quat to DCM/Subsystem/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 71 , TARGET_STRING (
"starshot_sim/quat to DCM/Subsystem/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
1 , 0 } , { 72 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 73 , TARGET_STRING (
 "starshot_sim/   /Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 74 , TARGET_STRING (
"starshot" ) , 9 , 1 , 0 } , { 75 , TARGET_STRING ( "B0" ) , 0 , 1 , 0 } , {
76 , TARGET_STRING ( "G" ) , 0 , 1 , 0 } , { 77 , TARGET_STRING ( "M_Earth" )
, 0 , 1 , 0 } , { 78 , TARGET_STRING ( "R_Earth" ) , 0 , 1 , 0 } , { 79 ,
TARGET_STRING ( "q0" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ol5jg0fvut [ 0 ] , & rtB .
femncko0cn [ 0 ] , & rtB . frdvfzrycc [ 0 ] , & rtB . cek4ch2hyg [ 0 ] , &
rtB . e3zxffjpma [ 0 ] , & rtB . lr40woa5vs [ 0 ] , & rtB . eeqjatg1dy [ 0 ]
, & rtB . ip5sbal02i , & rtB . dxtixaknsr , & rtB . mh2cw3g21y , & rtB .
eies2vobp0 , & rtB . i3p5tajv00 , & rtB . fpzp3jifvq , & rtB . kokbtkt104 , &
rtB . maipu1b40a , & rtB . j2525zxruy , & rtB . ghjrhwzi5l , & rtB .
fnusqcsyq4 , & rtB . otohkbp3bg [ 0 ] , & rtB . fpijzyolrb , & rtB .
mvhur03jr5 , & rtB . iuda0ybz3k , & rtB . oytd10qstc , & rtB . mm0zbnflas , &
rtB . fiu0rfsd3a , & rtB . hofhehwala , & rtB . dl3osgoi5y [ 0 ] , & rtB .
ao1jkqsvon , & rtB . dwztvfu4wu [ 0 ] , & rtB . crqtrnf4td , & rtB .
crqtrnf4td , & rtB . crqtrnf4td , & rtB . crqtrnf4td , & rtB . crqtrnf4td , &
rtB . crqtrnf4td , & rtB . crqtrnf4td , & rtP . Switch_CurrentSetting , & rtP
. Constant8_Value , & rtP . Gain5_Gain , & rtP . Gain6_Gain , & rtP .
Gain18_Gain , & rtP . Identitymatrix_Value [ 0 ] , & rtP . Gain1_Gain , & rtP
. Normalization_Bias , & rtP . Constant12_Value , & rtP . e_z_Value [ 0 ] , &
rtP . Gain1_Gain_fkz5w2tg5q , & rtP . Gain2_Gain , & rtP . MatrixGain_Gain [
0 ] , & rtP . Gain8_Gain , & rtP . Constant3_Value , & rtP .
Gain_Gain_ityqyfpnsc , & rtP . Gain1_Gain_eeykqncbdx , & rtP .
Gain2_Gain_icunypzv3n , & rtP . Constant3_Value_egvn5fzjrd , & rtP .
Gain_Gain_p3pw120zm1 , & rtP . Gain1_Gain_ees4kdgcpe , & rtP .
Gain2_Gain_ed1hn35ith , & rtP . Constant3_Value_efe2zzothx , & rtP .
Constant4_Value , & rtP . Switch_Threshold , & rtP . Constant10_Value , & rtP
. Constant9_Value , & rtP . Switch1_Threshold , & rtP .
Constant3_Value_e341jwrb4z , & rtP . Gain_Gain_cmgxch1a1l , & rtP .
Gain1_Gain_mqjlhklks4 , & rtP . Gain2_Gain_asqeevkcou , & rtP . diag0_Value ,
& rtP . Gain_Gain , & rtP . Gain1_Gain_gxm1ihqq0u , & rtP .
Gain2_Gain_dg5gskg1nm , & rtP . Constant_Value , & rtP .
Constant_Value_lprubj2kwa , & rtP . starshot , & rtP . B0 , & rtP . G , & rtP
. M_Earth , & rtP . R_Earth , & rtP . q0 [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } , { "struct" , "struct_t1iK3hEY2vfm4NgJptzLGD" , 17 ,
1 , sizeof ( struct_t1iK3hEY2vfm4NgJptzLGD ) , ( uint8_T ) SS_STRUCT , 0 , 0
, 0 } , { "struct" , "struct_QWuG7JELzddtnXnwHzvVgD" , 9 , 18 , sizeof (
struct_QWuG7JELzddtnXnwHzvVgD ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "creal_T" , 0 , 0 , sizeof ( creal_T ) , ( uint8_T ) SS_DOUBLE , 1
, 0 , 0 } , { "struct" , "struct_odTrKlpr9cjuKyVSnQPFXB" , 17 , 27 , sizeof (
struct_odTrKlpr9cjuKyVSnQPFXB ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_QFlG4YohdCMTa9HdmDzof" , 7 , 44 , sizeof (
struct_QFlG4YohdCMTa9HdmDzof ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_BxUlNur38amov8tPqkFMBH" , 9 , 51 , sizeof (
struct_BxUlNur38amov8tPqkFMBH ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_rktuLj1kXlz7eaT1szkX5C" , 10 , 60 , sizeof (
struct_rktuLj1kXlz7eaT1szkX5C ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_AM7n5PowExllItHZCW0ZYH" , 5 , 70 , sizeof (
struct_AM7n5PowExllItHZCW0ZYH ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , { "m" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , m ) , 0 ,
5 , 0 } , { "Ixx" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Ixx ) , 0 ,
5 , 0 } , { "Ixy" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Ixy ) , 0 ,
5 , 0 } , { "Ixz" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Ixz ) , 0 ,
5 , 0 } , { "Iyx" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Iyx ) , 0 ,
5 , 0 } , { "Iyy" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Iyy ) , 0 ,
5 , 0 } , { "Iyz" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Iyz ) , 0 ,
5 , 0 } , { "Izx" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Izx ) , 0 ,
5 , 0 } , { "Izy" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Izy ) , 0 ,
5 , 0 } , { "Izz" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Izz ) , 0 ,
5 , 0 } , { "I" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , I ) , 0 , 3 ,
0 } , { "PI" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , PI ) , 0 , 3 , 0
} , { "Ip" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Ip ) , 0 , 3 , 0 }
, { "Ixp" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Ixp ) , 0 , 5 , 0 }
, { "Iyp" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Iyp ) , 0 , 5 , 0 }
, { "Izp" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Izp ) , 0 , 5 , 0 }
, { "Iinv" , rt_offsetof ( struct_t1iK3hEY2vfm4NgJptzLGD , Iinv ) , 0 , 3 , 0
} , { "x" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , x ) , 0 , 5 , 0 } ,
{ "y" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , y ) , 0 , 5 , 0 } , {
"z" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , z ) , 0 , 5 , 0 } , {
"xdot" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , xdot ) , 0 , 5 , 0 } ,
{ "ydot" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , ydot ) , 0 , 5 , 0 }
, { "zdot" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , zdot ) , 0 , 5 , 0
} , { "eul" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , eul ) , 0 , 6 , 0
} , { "w" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD , w ) , 0 , 6 , 0 } ,
{ "massproperties" , rt_offsetof ( struct_QWuG7JELzddtnXnwHzvVgD ,
massproperties ) , 2 , 5 , 0 } , { "i" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , i ) , 0 , 5 , 0 } , { "a" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , a ) , 0 , 5 , 0 } , { "T" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , T ) , 0 , 5 , 0 } , { "tp" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , tp ) , 0 , 5 , 0 } , { "ts" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , ts ) , 0 , 5 , 0 } , { "c" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , c ) , 0 , 5 , 0 } , { "zeta" , rt_offsetof (
struct_odTrKlpr9cjuKyVSnQPFXB , zeta ) , 0 , 5 , 0 } , { "omegan" ,
rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , omegan ) , 0 , 5 , 0 } , {
"Ims" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , Ims ) , 0 , 5 , 0 } , {
"Res" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , Res ) , 0 , 5 , 0 } , {
"s1" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , s1 ) , 4 , 5 , 0 } , {
"ang_p" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , ang_p ) , 0 , 5 , 0 }
, { "ang_c" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , ang_c ) , 0 , 5 ,
0 } , { "Td" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , Td ) , 0 , 5 , 0
} , { "Kpd" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , Kpd ) , 0 , 5 , 0
} , { "Kd" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , Kd ) , 0 , 5 , 0 }
, { "Kp" , rt_offsetof ( struct_odTrKlpr9cjuKyVSnQPFXB , Kp ) , 0 , 5 , 0 } ,
{ "Kp" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , Kp ) , 0 , 3 , 0 } , {
"Kd" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , Kd ) , 0 , 3 , 0 } , {
"Id" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , Id ) , 0 , 5 , 0 } , {
"invId" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , invId ) , 0 , 5 , 0 }
, { "c" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , c ) , 0 , 5 , 0 } , {
"w" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , w ) , 0 , 7 , 0 } , {
"wdb0" , rt_offsetof ( struct_QFlG4YohdCMTa9HdmDzof , wdb0 ) , 0 , 7 , 0 } ,
{ "h" , rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , h ) , 0 , 5 , 0 } , {
"T" , rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , T ) , 0 , 5 , 0 } , { "P"
, rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , P ) , 0 , 5 , 0 } , { "p" ,
rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , p ) , 0 , 5 , 0 } , { "cd" ,
rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , cd ) , 0 , 5 , 0 } , { "A" ,
rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , A ) , 0 , 5 , 0 } , { "V" ,
rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , V ) , 0 , 5 , 0 } , { "xag" ,
rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , xag ) , 0 , 5 , 0 } , { "Ta" ,
rt_offsetof ( struct_BxUlNur38amov8tPqkFMBH , Ta ) , 0 , 5 , 0 } , { "V" ,
rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , V ) , 0 , 5 , 0 } , { "k" ,
rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , k ) , 0 , 5 , 0 } , { "A" ,
rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , A ) , 0 , 5 , 0 } , { "n" ,
rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , n ) , 0 , 5 , 0 } , { "m_max_x"
, rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , m_max_x ) , 0 , 5 , 0 } , {
"m_max_y" , rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , m_max_y ) , 0 , 5 ,
0 } , { "m_max_z" , rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , m_max_z ) ,
0 , 5 , 0 } , { "i_max_x" , rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C ,
i_max_x ) , 0 , 5 , 0 } , { "i_max_y" , rt_offsetof (
struct_rktuLj1kXlz7eaT1szkX5C , i_max_y ) , 0 , 5 , 0 } , { "i_max_z" ,
rt_offsetof ( struct_rktuLj1kXlz7eaT1szkX5C , i_max_z ) , 0 , 5 , 0 } , {
"IC" , rt_offsetof ( struct_AM7n5PowExllItHZCW0ZYH , IC ) , 3 , 5 , 0 } , {
"controller" , rt_offsetof ( struct_AM7n5PowExllItHZCW0ZYH , controller ) , 5
, 5 , 0 } , { "cmd" , rt_offsetof ( struct_AM7n5PowExllItHZCW0ZYH , cmd ) , 6
, 5 , 0 } , { "aerodrag" , rt_offsetof ( struct_AM7n5PowExllItHZCW0ZYH ,
aerodrag ) , 7 , 5 , 0 } , { "magnetorq" , rt_offsetof (
struct_AM7n5PowExllItHZCW0ZYH , magnetorq ) , 8 , 5 , 0 } } ; static const
rtwCAPI_DimensionMap rtDimensionMap [ ] = { { rtwCAPI_VECTOR , 0 , 2 , 0 } ,
{ rtwCAPI_SCALAR , 2 , 2 , 0 } , { rtwCAPI_VECTOR , 4 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 8 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 ,
0 } , { rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 4 , 1 , 3 , 3 , 1 , 3 } ; static
const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , (
NULL ) , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 36 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 38 , rtModelParameters , 6 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 450159784U , 2054323638U , 1979725367U ,
1508144400U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * starshot_sim_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void starshot_sim_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void starshot_sim_host_InitializeDataMapInfo (
starshot_sim_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
