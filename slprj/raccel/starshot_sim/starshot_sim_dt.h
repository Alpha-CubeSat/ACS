#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_t1iK3hEY2vfm4NgJptzLGD" , 17 , 392 } , {
"struct_QWuG7JELzddtnXnwHzvVgD" , 18 , 488 } , {
"struct_odTrKlpr9cjuKyVSnQPFXB" , 19 , 144 } , {
"struct_QFlG4YohdCMTa9HdmDzof" , 20 , 216 } , {
"struct_BxUlNur38amov8tPqkFMBH" , 21 , 72 } , {
"struct_rktuLj1kXlz7eaT1szkX5C" , 22 , 80 } , {
"struct_AM7n5PowExllItHZCW0ZYH" , 23 , 1000 } , {
"struct_pRh2I6kb8EpGWYupLmWg4F" , 24 , 88 } , { "uint64_T" , 25 , 8 } , {
"int64_T" , 26 , 8 } , { "uint_T" , 27 , 32 } , { "char_T" , 28 , 8 } , {
"uchar_T" , 29 , 8 } , { "time_T" , 30 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_t1iK3hEY2vfm4NgJptzLGD ) , sizeof (
struct_QWuG7JELzddtnXnwHzvVgD ) , sizeof ( struct_odTrKlpr9cjuKyVSnQPFXB ) ,
sizeof ( struct_QFlG4YohdCMTa9HdmDzof ) , sizeof (
struct_BxUlNur38amov8tPqkFMBH ) , sizeof ( struct_rktuLj1kXlz7eaT1szkX5C ) ,
sizeof ( struct_AM7n5PowExllItHZCW0ZYH ) , sizeof (
struct_pRh2I6kb8EpGWYupLmWg4F ) , sizeof ( uint64_T ) , sizeof ( int64_T ) ,
sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_t1iK3hEY2vfm4NgJptzLGD" , "struct_QWuG7JELzddtnXnwHzvVgD" ,
"struct_odTrKlpr9cjuKyVSnQPFXB" , "struct_QFlG4YohdCMTa9HdmDzof" ,
"struct_BxUlNur38amov8tPqkFMBH" , "struct_rktuLj1kXlz7eaT1szkX5C" ,
"struct_AM7n5PowExllItHZCW0ZYH" , "struct_pRh2I6kb8EpGWYupLmWg4F" ,
"uint64_T" , "int64_T" , "uint_T" , "char_T" , "uchar_T" , "time_T" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
dl3osgoi5y [ 0 ] ) , 0 , 0 , 61 } , { ( char_T * ) ( & rtDW . ogos4ffr2t ) ,
0 , 0 , 12 } , { ( char_T * ) ( & rtDW . edbxwvz1jp . LoggedData [ 0 ] ) , 11
, 0 , 38 } , { ( char_T * ) ( & rtDW . c0pertugry ) , 10 , 0 , 3 } , { (
char_T * ) ( & rtDW . nqpjy1fnao ) , 2 , 0 , 15 } } ; static
DataTypeTransitionTable rtBTransTable = { 5U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . starshot )
, 23 , 0 , 1 } , { ( char_T * ) ( & rtP . B0 ) , 0 , 0 , 63 } , { ( char_T *
) ( & rtP . Switch_CurrentSetting ) , 3 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 3U , rtPTransitions } ;
