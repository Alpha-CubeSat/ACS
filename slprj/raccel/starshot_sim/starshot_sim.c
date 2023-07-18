#include "starshot_sim.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "starshot_sim_private.h"
#include "rt_logging_mmi.h"
#include "starshot_sim_capi.h"
#include "starshot_sim_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.7 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . ih3kel1khg [ 0 ] = rtP .
starshot . cmd . wdb0 [ 0 ] ; rtX . ih3kel1khg [ 1 ] = rtP . starshot . cmd .
wdb0 [ 1 ] ; rtX . ih3kel1khg [ 2 ] = rtP . starshot . cmd . wdb0 [ 2 ] ; rtX
. coq2qfoyy1 [ 0 ] = rtP . q0 [ 0 ] ; rtX . coq2qfoyy1 [ 1 ] = rtP . q0 [ 1 ]
; rtX . coq2qfoyy1 [ 2 ] = rtP . q0 [ 2 ] ; rtX . coq2qfoyy1 [ 3 ] = rtP . q0
[ 3 ] ; rtX . kiwbiqrd0g = rtP . starshot . IC . z ; rtX . pnyvn52cos = rtP .
starshot . IC . x ; rtX . p0mibproqm = rtP . starshot . IC . y ; rtX .
exlhpb4fq0 [ 0 ] = rtP . starshot . IC . w [ 0 ] ; rtX . exlhpb4fq0 [ 1 ] =
rtP . starshot . IC . w [ 1 ] ; rtX . exlhpb4fq0 [ 2 ] = rtP . starshot . IC
. w [ 2 ] ; rtDW . ogos4ffr2t = ( rtInf ) ; rtDW . ond4jhxyao = ( rtInf ) ;
rtDW . ku5p2ni5nf = ( rtInf ) ; rtDW . cycn54lzew = ( rtInf ) ; rtX .
m2uajr5r0q = rtP . starshot . IC . xdot ; rtX . icdropjsud = rtP . starshot .
IC . ydot ; rtX . pseadm24fx = rtP . starshot . IC . zdot ; } void MdlStart (
void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Gain7" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Gain7" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "starshot_sim/Current/To Workspace7" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Gain7" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ow4wq5w5mm . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "e4b29c83-9c1e-4625-9450-f2860d454584" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . ow4wq5w5mm . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . ow4wq5w5mm . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . ow4wq5w5mm . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . ow4wq5w5mm .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ow4wq5w5mm . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
ow4wq5w5mm . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
ow4wq5w5mm . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . ow4wq5w5mm . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"current" ) ; sdiRegisterWksVariable ( rtDW . ow4wq5w5mm . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Matrix Multiply" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Matrix Multiply" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "starshot_sim/To Workspace4" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"Matrix Multiply" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 3 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. aaja0aysz0 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"019c4c5d-098e-4d98-99f6-515abec494bc" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . aaja0aysz0 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . aaja0aysz0 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . aaja0aysz0 . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
aaja0aysz0 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . aaja0aysz0 .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . aaja0aysz0 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . aaja0aysz0 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . aaja0aysz0 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"b" ) ; sdiRegisterWksVariable ( rtDW . aaja0aysz0 . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Gain8" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Gain8" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "starshot_sim/theta_(omegaB)/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Gain8" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . hzbfcdgqjd . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "851718ac-1089-4160-be06-3828183ff1b3" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . hzbfcdgqjd . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . hzbfcdgqjd . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . hzbfcdgqjd . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . hzbfcdgqjd .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . hzbfcdgqjd . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
hzbfcdgqjd . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
hzbfcdgqjd . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . hzbfcdgqjd . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"real_angle" ) ; sdiRegisterWksVariable ( rtDW . hzbfcdgqjd . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Euler Angles plot" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "Euler Angles plot" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "Euler Angles plot" ) ; sdiLabelU
blockPath = sdiGetLabelFromChars ( "starshot_sim/   /To Workspace2" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Euler Angles plot" ) ; sdiAsyncRepoDataTypeHandle hDT
= sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 3 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. p2iiqtje1q . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"6d8d7e40-871e-43f1-a5d6-0071ea1b34fa" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . p2iiqtje1q . AQHandles , hDT , & srcInfo ) ; if ( rtDW . p2iiqtje1q .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . p2iiqtje1q . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
p2iiqtje1q . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . p2iiqtje1q .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . p2iiqtje1q . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . p2iiqtje1q . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . p2iiqtje1q . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Eul1" ) ; sdiRegisterWksVariable ( rtDW . p2iiqtje1q . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "q^" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "q^" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"q^" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"starshot_sim/   /To Workspace6" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "q^" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 4 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . n4ujbk4ieg . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "29a5ba8c-fcfa-4cfe-ac8d-a04fac37ac7b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "1" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . n4ujbk4ieg . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . n4ujbk4ieg . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . n4ujbk4ieg . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . n4ujbk4ieg .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n4ujbk4ieg . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
n4ujbk4ieg . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
n4ujbk4ieg . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . n4ujbk4ieg . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"q" ) ; sdiRegisterWksVariable ( rtDW . n4ujbk4ieg . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Demux16:1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Demux16:1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "starshot_sim/     /XY Graph" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Demux16:1" )
; sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . egik531awp . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "59952e37-ec26-4392-8486-672f27bbb8b8" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . egik531awp . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . egik531awp . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . egik531awp . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . egik531awp .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . egik531awp . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
egik531awp . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
egik531awp . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . egik531awp . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Demux16:2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Demux16:2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "starshot_sim/     /XY Graph" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Demux16:2" )
; sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 1 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . hnp1vq2ji2 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "8a8fb85f-dfbb-4fa9-b87c-fe486d46a1c4" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . hnp1vq2ji2 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . hnp1vq2ji2 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . hnp1vq2ji2 . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . hnp1vq2ji2 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . hnp1vq2ji2 . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
hnp1vq2ji2 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
hnp1vq2ji2 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . hnp1vq2ji2 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "w" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "w" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"w" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"starshot_sim/     /To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "w" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . c1v41m3tga . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "31589207-3b18-4d82-b0f3-4d4429471126" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . c1v41m3tga . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . c1v41m3tga . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . c1v41m3tga . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . c1v41m3tga .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . c1v41m3tga . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
c1v41m3tga . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
c1v41m3tga . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . c1v41m3tga . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"w" ) ; sdiRegisterWksVariable ( rtDW . c1v41m3tga . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Mux9" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Mux9" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "starshot_sim/Saturation/To Workspace5" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Mux9" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . gsczcuj3aq . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "28424649-1be6-48d9-8f70-f89dd88212e4" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . gsczcuj3aq . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . gsczcuj3aq . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . gsczcuj3aq . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . gsczcuj3aq .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . gsczcuj3aq . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
gsczcuj3aq . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
gsczcuj3aq . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . gsczcuj3aq . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"m_out" ) ; sdiRegisterWksVariable ( rtDW . gsczcuj3aq . AQHandles , varName
, "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } rtDW . b3cxmfme20 = 0
; rtDW . nvceavffbk = 0 ; rtDW . c5ymd2b5xe = 0 ; rtDW . aoua3yfzjz = 0 ;
rtDW . eg24d5fcm1 = 0 ; rtDW . oea32fuhjg = 0 ; rtDW . onplct1sg4 = 0 ; rtDW
. ayifxsfink = 0 ; rtDW . o2dokb32i1 = 0 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . cyspl0m50o = - 1
; rtDW . kf3zmjwqmp = 0 ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid )
{ real_T et1022ev4t [ 9 ] ; real_T fdoargkklx [ 9 ] ; real_T iyoxfd5ewo [ 9 ]
; real_T dayacmogri [ 3 ] ; real_T oxxbxlo3d1 [ 3 ] ; real_T p0fynbca43 [ 3 ]
; real_T ( * lastU_p ) [ 3 ] ; real_T ahljtvkfex ; real_T bj1ibabkpp ; real_T
hnh2rdpps5 ; real_T iwsqgd0fte ; real_T jnieapsesj ; real_T k10lsqikbc ;
real_T psj2kw2sxr_idx_0 ; real_T psj2kw2sxr_idx_1 ; real_T psj2kw2sxr_idx_2 ;
real_T * lastU ; int32_T i ; int8_T rtAction ; int8_T rtPrevAction ;
srClearBC ( rtDW . nekjo4wvrj ) ; srClearBC ( rtDW . f4mltievmu ) ; srClearBC
( rtDW . fuvtfvj1xu ) ; psj2kw2sxr_idx_0 = rtX . ih3kel1khg [ 0 ] ;
psj2kw2sxr_idx_1 = rtX . ih3kel1khg [ 1 ] ; psj2kw2sxr_idx_2 = rtX .
ih3kel1khg [ 2 ] ; ahljtvkfex = ( ( rtX . coq2qfoyy1 [ 0 ] * rtX . coq2qfoyy1
[ 0 ] + rtX . coq2qfoyy1 [ 1 ] * rtX . coq2qfoyy1 [ 1 ] ) + rtX . coq2qfoyy1
[ 2 ] * rtX . coq2qfoyy1 [ 2 ] ) + rtX . coq2qfoyy1 [ 3 ] * rtX . coq2qfoyy1
[ 3 ] ; if ( ahljtvkfex < 0.0 ) { ahljtvkfex = - muDoubleScalarSqrt (
muDoubleScalarAbs ( ahljtvkfex ) ) ; } else { ahljtvkfex = muDoubleScalarSqrt
( ahljtvkfex ) ; } rtB . dl3osgoi5y [ 0 ] = rtX . coq2qfoyy1 [ 0 ] /
ahljtvkfex ; rtB . dl3osgoi5y [ 1 ] = rtX . coq2qfoyy1 [ 1 ] / ahljtvkfex ;
rtB . dl3osgoi5y [ 2 ] = rtX . coq2qfoyy1 [ 2 ] / ahljtvkfex ; rtB .
dl3osgoi5y [ 3 ] = rtX . coq2qfoyy1 [ 3 ] / ahljtvkfex ; iyoxfd5ewo [ 0 ] =
rtP . diag0_Value ; iyoxfd5ewo [ 1 ] = rtB . dl3osgoi5y [ 2 ] ; iyoxfd5ewo [
2 ] = rtP . Gain_Gain * rtB . dl3osgoi5y [ 1 ] ; iyoxfd5ewo [ 3 ] = rtP .
Gain1_Gain_gxm1ihqq0u * rtB . dl3osgoi5y [ 2 ] ; iyoxfd5ewo [ 4 ] = rtP .
diag0_Value ; iyoxfd5ewo [ 5 ] = rtB . dl3osgoi5y [ 0 ] ; iyoxfd5ewo [ 6 ] =
rtB . dl3osgoi5y [ 1 ] ; iyoxfd5ewo [ 7 ] = rtP . Gain2_Gain_dg5gskg1nm * rtB
. dl3osgoi5y [ 0 ] ; iyoxfd5ewo [ 8 ] = rtP . diag0_Value ; k10lsqikbc = 0.0
; for ( i = 0 ; i < 3 ; i ++ ) { ahljtvkfex = rtB . dl3osgoi5y [ i ] ;
k10lsqikbc += ahljtvkfex * ahljtvkfex ; et1022ev4t [ 3 * i ] = rtB .
dl3osgoi5y [ 0 ] * rtB . dl3osgoi5y [ i ] ; et1022ev4t [ 3 * i + 1 ] = rtB .
dl3osgoi5y [ 1 ] * rtB . dl3osgoi5y [ i ] ; et1022ev4t [ 3 * i + 2 ] = rtB .
dl3osgoi5y [ 2 ] * rtB . dl3osgoi5y [ i ] ; } ahljtvkfex = rtB . dl3osgoi5y [
3 ] * rtB . dl3osgoi5y [ 3 ] - k10lsqikbc ; k10lsqikbc = rtB . dl3osgoi5y [ 3
] ; for ( i = 0 ; i < 9 ; i ++ ) { fdoargkklx [ i ] = ( rtP . Gain2_Gain *
et1022ev4t [ i ] - iyoxfd5ewo [ i ] * k10lsqikbc * rtP .
Gain1_Gain_fkz5w2tg5q ) + rtP . MatrixGain_Gain [ i ] * ahljtvkfex ; } rtB .
eies2vobp0 = rtX . kiwbiqrd0g ; rtB . dxtixaknsr = rtX . pnyvn52cos ; rtB .
mh2cw3g21y = rtX . p0mibproqm ; ahljtvkfex = rtB . dxtixaknsr * rtB .
dxtixaknsr + rtB . mh2cw3g21y * rtB . mh2cw3g21y ; if ( ssIsMajorTimeStep (
rtS ) ) { if ( rtDW . b3cxmfme20 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
b3cxmfme20 = 0 ; } hnh2rdpps5 = muDoubleScalarSqrt ( ahljtvkfex ) ; } else if
( ahljtvkfex < 0.0 ) { hnh2rdpps5 = - muDoubleScalarSqrt ( muDoubleScalarAbs
( ahljtvkfex ) ) ; rtDW . b3cxmfme20 = 1 ; } else { hnh2rdpps5 =
muDoubleScalarSqrt ( ahljtvkfex ) ; } hnh2rdpps5 = rtP . Constant8_Value -
muDoubleScalarAtan2 ( rtB . eies2vobp0 , hnh2rdpps5 ) ; ahljtvkfex = rtP .
Gain6_Gain * hnh2rdpps5 ; iwsqgd0fte = ( rtB . dxtixaknsr * rtB . dxtixaknsr
+ rtB . mh2cw3g21y * rtB . mh2cw3g21y ) + rtB . eies2vobp0 * rtB . eies2vobp0
; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . nvceavffbk != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
nvceavffbk = 0 ; } jnieapsesj = muDoubleScalarSqrt ( iwsqgd0fte ) ; } else if
( iwsqgd0fte < 0.0 ) { jnieapsesj = - muDoubleScalarSqrt ( muDoubleScalarAbs
( iwsqgd0fte ) ) ; rtDW . nvceavffbk = 1 ; } else { jnieapsesj =
muDoubleScalarSqrt ( iwsqgd0fte ) ; } iwsqgd0fte = rtP . R_Earth / jnieapsesj
; jnieapsesj = iwsqgd0fte * iwsqgd0fte * iwsqgd0fte * - rtP . B0 ; iwsqgd0fte
= jnieapsesj * muDoubleScalarSin ( hnh2rdpps5 ) ; hnh2rdpps5 = rtP .
Gain5_Gain * jnieapsesj * muDoubleScalarCos ( hnh2rdpps5 ) ; jnieapsesj =
muDoubleScalarCos ( ahljtvkfex ) * iwsqgd0fte + muDoubleScalarSin (
ahljtvkfex ) * hnh2rdpps5 ; bj1ibabkpp = muDoubleScalarAtan2 ( rtB .
mh2cw3g21y , rtB . dxtixaknsr ) ; rtB . fiu0rfsd3a = jnieapsesj *
muDoubleScalarCos ( bj1ibabkpp ) ; rtB . mm0zbnflas = jnieapsesj *
muDoubleScalarSin ( bj1ibabkpp ) ; rtB . hofhehwala = muDoubleScalarCos (
ahljtvkfex ) * hnh2rdpps5 - muDoubleScalarSin ( ahljtvkfex ) * iwsqgd0fte ;
for ( i = 0 ; i < 3 ; i ++ ) { rtB . ol5jg0fvut [ i ] = ( fdoargkklx [ i + 3
] * rtB . mm0zbnflas + fdoargkklx [ i ] * rtB . fiu0rfsd3a ) + fdoargkklx [ i
+ 6 ] * rtB . hofhehwala ; rtB . e3zxffjpma [ i ] = rtX . exlhpb4fq0 [ i ] ;
} hnh2rdpps5 = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) { oxxbxlo3d1 [ i ] = ( rtB
. dwztvfu4wu [ i + 3 ] * rtB . ol5jg0fvut [ 1 ] + rtB . dwztvfu4wu [ i ] *
rtB . ol5jg0fvut [ 0 ] ) + rtB . dwztvfu4wu [ i + 6 ] * rtB . ol5jg0fvut [ 2
] ; ahljtvkfex = rtB . ol5jg0fvut [ i ] ; hnh2rdpps5 += ahljtvkfex *
ahljtvkfex ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . c5ymd2b5xe != 0
) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
c5ymd2b5xe = 0 ; } ahljtvkfex = muDoubleScalarSqrt ( hnh2rdpps5 ) ; } else if
( hnh2rdpps5 < 0.0 ) { ahljtvkfex = - muDoubleScalarSqrt ( muDoubleScalarAbs
( hnh2rdpps5 ) ) ; rtDW . c5ymd2b5xe = 1 ; } else { ahljtvkfex =
muDoubleScalarSqrt ( hnh2rdpps5 ) ; } k10lsqikbc = oxxbxlo3d1 [ 0 ] /
ahljtvkfex ; hnh2rdpps5 = k10lsqikbc * k10lsqikbc ; k10lsqikbc = oxxbxlo3d1 [
1 ] / ahljtvkfex ; hnh2rdpps5 += k10lsqikbc * k10lsqikbc ; k10lsqikbc =
oxxbxlo3d1 [ 2 ] / ahljtvkfex ; hnh2rdpps5 += k10lsqikbc * k10lsqikbc ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . aoua3yfzjz != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
aoua3yfzjz = 0 ; } iwsqgd0fte = muDoubleScalarSqrt ( hnh2rdpps5 ) ; } else if
( hnh2rdpps5 < 0.0 ) { iwsqgd0fte = - muDoubleScalarSqrt ( muDoubleScalarAbs
( hnh2rdpps5 ) ) ; rtDW . aoua3yfzjz = 1 ; } else { iwsqgd0fte =
muDoubleScalarSqrt ( hnh2rdpps5 ) ; } if ( iwsqgd0fte > 1.0 ) { iwsqgd0fte =
1.0 ; } else if ( iwsqgd0fte < - 1.0 ) { iwsqgd0fte = - 1.0 ; } rtB .
fnusqcsyq4 = muDoubleScalarAsin ( iwsqgd0fte ) ; if ( ( rtDW . ogos4ffr2t >=
ssGetT ( rtS ) ) && ( rtDW . ond4jhxyao >= ssGetT ( rtS ) ) ) { hnh2rdpps5 =
0.0 ; } else { hnh2rdpps5 = rtDW . ogos4ffr2t ; lastU = & rtDW . gcvqyir2vi ;
if ( rtDW . ogos4ffr2t < rtDW . ond4jhxyao ) { if ( rtDW . ond4jhxyao <
ssGetT ( rtS ) ) { hnh2rdpps5 = rtDW . ond4jhxyao ; lastU = & rtDW .
jg3q0pzg5o ; } } else if ( rtDW . ogos4ffr2t >= ssGetT ( rtS ) ) { hnh2rdpps5
= rtDW . ond4jhxyao ; lastU = & rtDW . jg3q0pzg5o ; } hnh2rdpps5 = ( rtB .
fnusqcsyq4 - * lastU ) / ( ssGetT ( rtS ) - hnh2rdpps5 ) ; } if ( rtP .
Switch_CurrentSetting == 1 ) { ahljtvkfex = 1.0 / ( ( ( rtB . ol5jg0fvut [ 0
] * rtB . ol5jg0fvut [ 0 ] + rtB . ol5jg0fvut [ 1 ] * rtB . ol5jg0fvut [ 1 ]
) + rtB . ol5jg0fvut [ 2 ] * rtB . ol5jg0fvut [ 2 ] ) + rtP .
Normalization_Bias ) ; dayacmogri [ 0 ] = rtB . ol5jg0fvut [ 0 ] * ahljtvkfex
; p0fynbca43 [ 0 ] = rtP . starshot . cmd . c * psj2kw2sxr_idx_0 * rtP .
Gain1_Gain ; dayacmogri [ 1 ] = rtB . ol5jg0fvut [ 1 ] * ahljtvkfex ;
p0fynbca43 [ 1 ] = rtP . starshot . cmd . c * psj2kw2sxr_idx_1 * rtP .
Gain1_Gain ; dayacmogri [ 2 ] = rtB . ol5jg0fvut [ 2 ] * ahljtvkfex ;
p0fynbca43 [ 2 ] = rtP . starshot . cmd . c * psj2kw2sxr_idx_2 * rtP .
Gain1_Gain ; rtB . femncko0cn [ 0 ] = p0fynbca43 [ 1 ] * dayacmogri [ 2 ] -
dayacmogri [ 1 ] * p0fynbca43 [ 2 ] ; rtB . femncko0cn [ 1 ] = dayacmogri [ 0
] * p0fynbca43 [ 2 ] - p0fynbca43 [ 0 ] * dayacmogri [ 2 ] ; rtB . femncko0cn
[ 2 ] = p0fynbca43 [ 0 ] * dayacmogri [ 1 ] - dayacmogri [ 0 ] * p0fynbca43 [
1 ] ; } else { hnh2rdpps5 = rtP . starshot . controller . Kp * rtB .
fnusqcsyq4 + rtP . starshot . controller . Kd * hnh2rdpps5 ; jnieapsesj = (
rtB . ol5jg0fvut [ 0 ] * rtB . ol5jg0fvut [ 0 ] + rtB . ol5jg0fvut [ 1 ] *
rtB . ol5jg0fvut [ 1 ] ) + rtB . ol5jg0fvut [ 2 ] * rtB . ol5jg0fvut [ 2 ] ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . eg24d5fcm1 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
eg24d5fcm1 = 0 ; } iwsqgd0fte = muDoubleScalarSqrt ( jnieapsesj ) ; } else if
( jnieapsesj < 0.0 ) { iwsqgd0fte = - muDoubleScalarSqrt ( muDoubleScalarAbs
( jnieapsesj ) ) ; rtDW . eg24d5fcm1 = 1 ; } else { iwsqgd0fte =
muDoubleScalarSqrt ( jnieapsesj ) ; } p0fynbca43 [ 0 ] = rtB . e3zxffjpma [ 0
] * rtB . ol5jg0fvut [ 0 ] ; p0fynbca43 [ 1 ] = rtB . e3zxffjpma [ 1 ] * rtB
. ol5jg0fvut [ 1 ] ; p0fynbca43 [ 2 ] = rtB . e3zxffjpma [ 2 ] * rtB .
ol5jg0fvut [ 2 ] ; jnieapsesj = ( rtB . e3zxffjpma [ 0 ] * rtB . e3zxffjpma [
0 ] + rtB . e3zxffjpma [ 1 ] * rtB . e3zxffjpma [ 1 ] ) + rtB . e3zxffjpma [
2 ] * rtB . e3zxffjpma [ 2 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
oea32fuhjg != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
oea32fuhjg = 0 ; } bj1ibabkpp = muDoubleScalarSqrt ( jnieapsesj ) ; } else if
( jnieapsesj < 0.0 ) { bj1ibabkpp = - muDoubleScalarSqrt ( muDoubleScalarAbs
( jnieapsesj ) ) ; rtDW . oea32fuhjg = 1 ; } else { bj1ibabkpp =
muDoubleScalarSqrt ( jnieapsesj ) ; } rtB . femncko0cn [ 0 ] = rtP .
Constant12_Value ; rtB . femncko0cn [ 1 ] = rtP . Constant12_Value ; if ( rtB
. e3zxffjpma [ 2 ] >= rtP . Switch1_Threshold ) { k10lsqikbc = rtP .
Constant9_Value ; } else { k10lsqikbc = rtP . Constant10_Value ; } if ( ( (
p0fynbca43 [ 0 ] + p0fynbca43 [ 1 ] ) + p0fynbca43 [ 2 ] ) * ( 1.0 /
bj1ibabkpp ) / iwsqgd0fte > rtP . Switch_Threshold ) { iwsqgd0fte = rtP .
Constant3_Value_efe2zzothx ; } else { iwsqgd0fte = rtP . Constant4_Value ; }
rtB . femncko0cn [ 2 ] = k10lsqikbc * iwsqgd0fte * hnh2rdpps5 / ahljtvkfex ;
} if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . c0pertugry = rtB .
femncko0cn [ 0 ] >= rtP . starshot . magnetorq . m_max_x ? 1 : rtB .
femncko0cn [ 0 ] > - rtP . starshot . magnetorq . m_max_x ? 0 : - 1 ; } rtB .
fpijzyolrb = rtDW . c0pertugry == 1 ? rtP . starshot . magnetorq . m_max_x :
rtDW . c0pertugry == - 1 ? - rtP . starshot . magnetorq . m_max_x : rtB .
femncko0cn [ 0 ] ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . mjbfo4zbad
= rtB . femncko0cn [ 1 ] >= rtP . starshot . magnetorq . m_max_y ? 1 : rtB .
femncko0cn [ 1 ] > - rtP . starshot . magnetorq . m_max_y ? 0 : - 1 ; } rtB .
mvhur03jr5 = rtDW . mjbfo4zbad == 1 ? rtP . starshot . magnetorq . m_max_y :
rtDW . mjbfo4zbad == - 1 ? - rtP . starshot . magnetorq . m_max_y : rtB .
femncko0cn [ 1 ] ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . fzywhfz1mq
= rtB . femncko0cn [ 2 ] >= rtP . starshot . magnetorq . m_max_z ? 1 : rtB .
femncko0cn [ 2 ] > - rtP . starshot . magnetorq . m_max_z ? 0 : - 1 ; } rtB .
iuda0ybz3k = rtDW . fzywhfz1mq == 1 ? rtP . starshot . magnetorq . m_max_z :
rtDW . fzywhfz1mq == - 1 ? - rtP . starshot . magnetorq . m_max_z : rtB .
femncko0cn [ 2 ] ; p0fynbca43 [ 0 ] = rtB . fpijzyolrb ; p0fynbca43 [ 1 ] =
rtB . mvhur03jr5 ; p0fynbca43 [ 2 ] = rtB . iuda0ybz3k ; ahljtvkfex = 1.0 /
rtP . starshot . magnetorq . k / rtP . starshot . magnetorq . n / rtP .
starshot . magnetorq . A ; rtB . lr40woa5vs [ 0 ] = ahljtvkfex * p0fynbca43 [
0 ] ; rtB . lr40woa5vs [ 1 ] = ahljtvkfex * p0fynbca43 [ 1 ] ; rtB .
lr40woa5vs [ 2 ] = ahljtvkfex * p0fynbca43 [ 2 ] ; { if ( rtDW . ow4wq5w5mm .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . ow4wq5w5mm .
AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . lr40woa5vs [ 0 ] +
0 ) ; } } fdoargkklx [ 0 ] = rtP . Constant3_Value_e341jwrb4z ; fdoargkklx [
1 ] = rtB . iuda0ybz3k ; fdoargkklx [ 2 ] = rtP . Gain_Gain_cmgxch1a1l * rtB
. mvhur03jr5 ; fdoargkklx [ 3 ] = rtP . Gain1_Gain_mqjlhklks4 * rtB .
iuda0ybz3k ; fdoargkklx [ 4 ] = rtP . Constant3_Value_e341jwrb4z ; fdoargkklx
[ 5 ] = rtB . fpijzyolrb ; fdoargkklx [ 6 ] = rtB . mvhur03jr5 ; fdoargkklx [
7 ] = rtP . Gain2_Gain_asqeevkcou * rtB . fpijzyolrb ; fdoargkklx [ 8 ] = rtP
. Constant3_Value_e341jwrb4z ; ahljtvkfex = rtB . ol5jg0fvut [ 1 ] ;
k10lsqikbc = rtB . ol5jg0fvut [ 0 ] ; hnh2rdpps5 = rtB . ol5jg0fvut [ 2 ] ;
for ( i = 0 ; i < 3 ; i ++ ) { rtB . otohkbp3bg [ i ] = ( fdoargkklx [ i + 3
] * ahljtvkfex + fdoargkklx [ i ] * k10lsqikbc ) + fdoargkklx [ i + 6 ] *
hnh2rdpps5 ; } { if ( rtDW . aaja0aysz0 . AQHandles && ssGetLogOutput ( rtS )
) { sdiWriteSignal ( rtDW . aaja0aysz0 . AQHandles , ssGetTaskTime ( rtS , 0
) , ( char * ) & rtB . ol5jg0fvut [ 0 ] + 0 ) ; } } hnh2rdpps5 = ( rtB .
e3zxffjpma [ 0 ] * rtB . e3zxffjpma [ 0 ] + rtB . e3zxffjpma [ 1 ] * rtB .
e3zxffjpma [ 1 ] ) + rtB . e3zxffjpma [ 2 ] * rtB . e3zxffjpma [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . onplct1sg4 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
onplct1sg4 = 0 ; } ahljtvkfex = muDoubleScalarSqrt ( hnh2rdpps5 ) ; } else if
( hnh2rdpps5 < 0.0 ) { ahljtvkfex = - muDoubleScalarSqrt ( muDoubleScalarAbs
( hnh2rdpps5 ) ) ; rtDW . onplct1sg4 = 1 ; } else { ahljtvkfex =
muDoubleScalarSqrt ( hnh2rdpps5 ) ; } oxxbxlo3d1 [ 0 ] = rtB . e3zxffjpma [ 0
] * rtB . ol5jg0fvut [ 0 ] ; oxxbxlo3d1 [ 1 ] = rtB . e3zxffjpma [ 1 ] * rtB
. ol5jg0fvut [ 1 ] ; oxxbxlo3d1 [ 2 ] = rtB . e3zxffjpma [ 2 ] * rtB .
ol5jg0fvut [ 2 ] ; hnh2rdpps5 = ( rtB . ol5jg0fvut [ 0 ] * rtB . ol5jg0fvut [
0 ] + rtB . ol5jg0fvut [ 1 ] * rtB . ol5jg0fvut [ 1 ] ) + rtB . ol5jg0fvut [
2 ] * rtB . ol5jg0fvut [ 2 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
ayifxsfink != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
ayifxsfink = 0 ; } iwsqgd0fte = muDoubleScalarSqrt ( hnh2rdpps5 ) ; } else if
( hnh2rdpps5 < 0.0 ) { iwsqgd0fte = - muDoubleScalarSqrt ( muDoubleScalarAbs
( hnh2rdpps5 ) ) ; rtDW . ayifxsfink = 1 ; } else { iwsqgd0fte =
muDoubleScalarSqrt ( hnh2rdpps5 ) ; } ahljtvkfex = ( ( oxxbxlo3d1 [ 0 ] +
oxxbxlo3d1 [ 1 ] ) + oxxbxlo3d1 [ 2 ] ) * ( 1.0 / ahljtvkfex ) / iwsqgd0fte ;
if ( ahljtvkfex > 1.0 ) { ahljtvkfex = 1.0 ; } else if ( ahljtvkfex < - 1.0 )
{ ahljtvkfex = - 1.0 ; } rtB . oytd10qstc = rtP . Gain8_Gain *
muDoubleScalarAcos ( ahljtvkfex ) ; { if ( rtDW . hzbfcdgqjd . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . hzbfcdgqjd . AQHandles ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . oytd10qstc + 0 ) ; } }
hnh2rdpps5 = ( ( rtB . dl3osgoi5y [ 0 ] * rtB . dl3osgoi5y [ 0 ] + rtB .
dl3osgoi5y [ 1 ] * rtB . dl3osgoi5y [ 1 ] ) + rtB . dl3osgoi5y [ 2 ] * rtB .
dl3osgoi5y [ 2 ] ) + rtB . dl3osgoi5y [ 3 ] * rtB . dl3osgoi5y [ 3 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . o2dokb32i1 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
o2dokb32i1 = 0 ; } ahljtvkfex = muDoubleScalarSqrt ( hnh2rdpps5 ) ; } else if
( hnh2rdpps5 < 0.0 ) { ahljtvkfex = - muDoubleScalarSqrt ( muDoubleScalarAbs
( hnh2rdpps5 ) ) ; rtDW . o2dokb32i1 = 1 ; } else { ahljtvkfex =
muDoubleScalarSqrt ( hnh2rdpps5 ) ; } hnh2rdpps5 = rtB . dl3osgoi5y [ 0 ] /
ahljtvkfex ; iwsqgd0fte = rtB . dl3osgoi5y [ 1 ] / ahljtvkfex ; jnieapsesj =
rtB . dl3osgoi5y [ 2 ] / ahljtvkfex ; ahljtvkfex = rtB . dl3osgoi5y [ 3 ] /
ahljtvkfex ; rtB . ao1jkqsvon = ( iwsqgd0fte * ahljtvkfex - hnh2rdpps5 *
jnieapsesj ) * - 2.0 ; rtPrevAction = rtDW . cyspl0m50o ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtB . ao1jkqsvon > 1.0 ) { rtAction =
0 ; } else if ( rtB . ao1jkqsvon < - 1.0 ) { rtAction = 1 ; } else { rtAction
= 2 ; } rtDW . cyspl0m50o = rtAction ; } else { rtAction = rtDW . cyspl0m50o
; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; switch ( rtPrevAction )
{ case 0 : break ; case 1 : break ; case 2 : break ; } } switch ( rtAction )
{ case 0 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 0 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . crqtrnf4td = rtP .
Constant_Value ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW
. nekjo4wvrj ) ; } break ; case 1 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . crqtrnf4td = rtP . Constant_Value_lprubj2kwa ; } if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . f4mltievmu ) ; } break
; default : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 0 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } } rtB . crqtrnf4td = rtB . ao1jkqsvon ; if ( ssIsModeUpdateTimeStep ( rtS
) ) { srUpdateBC ( rtDW . fuvtfvj1xu ) ; } break ; } rtB . frdvfzrycc [ 0 ] =
muDoubleScalarAtan2 ( ( iwsqgd0fte * jnieapsesj + hnh2rdpps5 * ahljtvkfex ) *
2.0 , ( ( hnh2rdpps5 * hnh2rdpps5 + iwsqgd0fte * iwsqgd0fte ) - jnieapsesj *
jnieapsesj ) - ahljtvkfex * ahljtvkfex ) * rtP . Gain18_Gain ; if ( rtB .
crqtrnf4td > 1.0 ) { k10lsqikbc = 1.0 ; } else if ( rtB . crqtrnf4td < - 1.0
) { k10lsqikbc = - 1.0 ; } else { k10lsqikbc = rtB . crqtrnf4td ; } rtB .
frdvfzrycc [ 1 ] = rtP . Gain18_Gain * muDoubleScalarAsin ( k10lsqikbc ) ;
rtB . frdvfzrycc [ 2 ] = muDoubleScalarAtan2 ( ( jnieapsesj * ahljtvkfex +
hnh2rdpps5 * iwsqgd0fte ) * 2.0 , ( ( hnh2rdpps5 * hnh2rdpps5 - iwsqgd0fte *
iwsqgd0fte ) - jnieapsesj * jnieapsesj ) + ahljtvkfex * ahljtvkfex ) * rtP .
Gain18_Gain ; { if ( rtDW . p2iiqtje1q . AQHandles && ssGetLogOutput ( rtS )
) { sdiWriteSignal ( rtDW . p2iiqtje1q . AQHandles , ssGetTaskTime ( rtS , 0
) , ( char * ) & rtB . frdvfzrycc [ 0 ] + 0 ) ; } } { if ( rtDW . n4ujbk4ieg
. AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . n4ujbk4ieg
. AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . dl3osgoi5y [ 0 ]
+ 0 ) ; } } rtB . jpsplb3g3c [ 0 ] = ( ( rtB . e3zxffjpma [ 0 ] * rtB .
dl3osgoi5y [ 3 ] - rtB . e3zxffjpma [ 1 ] * rtB . dl3osgoi5y [ 2 ] ) + rtB .
dl3osgoi5y [ 1 ] * rtB . e3zxffjpma [ 2 ] ) / 2.0 ; rtB . jpsplb3g3c [ 1 ] =
( ( rtB . e3zxffjpma [ 0 ] * rtB . dl3osgoi5y [ 2 ] + rtB . e3zxffjpma [ 1 ]
* rtB . dl3osgoi5y [ 3 ] ) - rtB . dl3osgoi5y [ 0 ] * rtB . e3zxffjpma [ 2 ]
) / 2.0 ; rtB . jpsplb3g3c [ 2 ] = ( ( - rtB . dl3osgoi5y [ 1 ] * rtB .
e3zxffjpma [ 0 ] + rtB . dl3osgoi5y [ 0 ] * rtB . e3zxffjpma [ 1 ] ) + rtB .
e3zxffjpma [ 2 ] * rtB . dl3osgoi5y [ 3 ] ) / 2.0 ; rtB . jpsplb3g3c [ 3 ] =
( ( - rtB . dl3osgoi5y [ 0 ] * rtB . e3zxffjpma [ 0 ] - rtB . dl3osgoi5y [ 1
] * rtB . e3zxffjpma [ 1 ] ) - rtB . dl3osgoi5y [ 2 ] * rtB . e3zxffjpma [ 2
] ) / 2.0 ; { if ( rtDW . egik531awp . AQHandles && ssGetLogOutput ( rtS ) )
{ sdiWriteSignal ( rtDW . egik531awp . AQHandles , ssGetTaskTime ( rtS , 0 )
, ( char * ) & rtB . e3zxffjpma [ 0 ] + 0 ) ; } } { if ( rtDW . hnp1vq2ji2 .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . hnp1vq2ji2 .
AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . e3zxffjpma [ 1 ] +
0 ) ; } } { if ( rtDW . c1v41m3tga . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . c1v41m3tga . AQHandles , ssGetTaskTime ( rtS , 0 ) ,
( char * ) & rtB . e3zxffjpma [ 0 ] + 0 ) ; } } ahljtvkfex = rtB . e3zxffjpma
[ 1 ] ; k10lsqikbc = rtB . e3zxffjpma [ 0 ] ; hnh2rdpps5 = rtB . e3zxffjpma [
2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { oxxbxlo3d1 [ i ] = ( rtP . starshot . IC
. massproperties . I [ i + 3 ] * ahljtvkfex + rtP . starshot . IC .
massproperties . I [ i ] * k10lsqikbc ) + rtP . starshot . IC .
massproperties . I [ i + 6 ] * hnh2rdpps5 ; } ahljtvkfex = rtB . otohkbp3bg [
0 ] - ( rtB . e3zxffjpma [ 1 ] * oxxbxlo3d1 [ 2 ] - oxxbxlo3d1 [ 1 ] * rtB .
e3zxffjpma [ 2 ] ) ; k10lsqikbc = rtB . otohkbp3bg [ 1 ] - ( oxxbxlo3d1 [ 0 ]
* rtB . e3zxffjpma [ 2 ] - rtB . e3zxffjpma [ 0 ] * oxxbxlo3d1 [ 2 ] ) ;
hnh2rdpps5 = rtB . otohkbp3bg [ 2 ] - ( rtB . e3zxffjpma [ 0 ] * oxxbxlo3d1 [
1 ] - oxxbxlo3d1 [ 0 ] * rtB . e3zxffjpma [ 1 ] ) ; for ( i = 0 ; i < 3 ; i
++ ) { rtB . cek4ch2hyg [ i ] = ( rtP . starshot . IC . massproperties . Iinv
[ i + 3 ] * k10lsqikbc + rtP . starshot . IC . massproperties . Iinv [ i ] *
ahljtvkfex ) + rtP . starshot . IC . massproperties . Iinv [ i + 6 ] *
hnh2rdpps5 ; } if ( ( rtDW . ku5p2ni5nf >= ssGetT ( rtS ) ) && ( rtDW .
cycn54lzew >= ssGetT ( rtS ) ) ) { dayacmogri [ 0 ] = 0.0 ; dayacmogri [ 1 ]
= 0.0 ; dayacmogri [ 2 ] = 0.0 ; } else { hnh2rdpps5 = rtDW . ku5p2ni5nf ;
lastU_p = & rtDW . n1p1mm2auv ; if ( rtDW . ku5p2ni5nf < rtDW . cycn54lzew )
{ if ( rtDW . cycn54lzew < ssGetT ( rtS ) ) { hnh2rdpps5 = rtDW . cycn54lzew
; lastU_p = & rtDW . nfnayvw4de ; } } else if ( rtDW . ku5p2ni5nf >= ssGetT (
rtS ) ) { hnh2rdpps5 = rtDW . cycn54lzew ; lastU_p = & rtDW . nfnayvw4de ; }
ahljtvkfex = ssGetT ( rtS ) - hnh2rdpps5 ; dayacmogri [ 0 ] = ( rtB .
e3zxffjpma [ 0 ] - ( * lastU_p ) [ 0 ] ) / ahljtvkfex ; dayacmogri [ 1 ] = (
rtB . e3zxffjpma [ 1 ] - ( * lastU_p ) [ 1 ] ) / ahljtvkfex ; dayacmogri [ 2
] = ( rtB . e3zxffjpma [ 2 ] - ( * lastU_p ) [ 2 ] ) / ahljtvkfex ; }
iyoxfd5ewo [ 0 ] = rtP . Constant3_Value ; iyoxfd5ewo [ 1 ] = rtB .
e3zxffjpma [ 2 ] ; iyoxfd5ewo [ 2 ] = rtP . Gain_Gain_ityqyfpnsc * rtB .
e3zxffjpma [ 1 ] ; iyoxfd5ewo [ 3 ] = rtP . Gain1_Gain_eeykqncbdx * rtB .
e3zxffjpma [ 2 ] ; iyoxfd5ewo [ 4 ] = rtP . Constant3_Value ; iyoxfd5ewo [ 5
] = rtB . e3zxffjpma [ 0 ] ; iyoxfd5ewo [ 6 ] = rtB . e3zxffjpma [ 1 ] ;
iyoxfd5ewo [ 7 ] = rtP . Gain2_Gain_icunypzv3n * rtB . e3zxffjpma [ 0 ] ;
iyoxfd5ewo [ 8 ] = rtP . Constant3_Value ; for ( i = 0 ; i < 9 ; i ++ ) {
et1022ev4t [ i ] = iyoxfd5ewo [ i ] + rtP . Identitymatrix_Value [ i ] ; }
for ( i = 0 ; i < 3 ; i ++ ) { rtB . eeqjatg1dy [ i ] = ( 0.0 - dayacmogri [
i ] ) - ( ( rtP . starshot . cmd . invId * psj2kw2sxr_idx_0 * rtP . starshot
. cmd . c * et1022ev4t [ i ] + rtP . starshot . cmd . invId *
psj2kw2sxr_idx_1 * rtP . starshot . cmd . c * et1022ev4t [ i + 3 ] ) + rtP .
starshot . cmd . invId * psj2kw2sxr_idx_2 * rtP . starshot . cmd . c *
et1022ev4t [ i + 6 ] ) ; } hnh2rdpps5 = ( rtB . dxtixaknsr * rtB . dxtixaknsr
+ rtB . mh2cw3g21y * rtB . mh2cw3g21y ) + rtB . eies2vobp0 * rtB . eies2vobp0
; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . kf3zmjwqmp != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
kf3zmjwqmp = 0 ; } ahljtvkfex = muDoubleScalarSqrt ( hnh2rdpps5 ) ; } else if
( hnh2rdpps5 < 0.0 ) { ahljtvkfex = - muDoubleScalarSqrt ( muDoubleScalarAbs
( hnh2rdpps5 ) ) ; rtDW . kf3zmjwqmp = 1 ; } else { ahljtvkfex =
muDoubleScalarSqrt ( hnh2rdpps5 ) ; } hnh2rdpps5 = 1.0 / ( ahljtvkfex *
ahljtvkfex ) * rtB . ip5sbal02i ; rtB . maipu1b40a = 1.0 / ahljtvkfex * rtB .
eies2vobp0 * hnh2rdpps5 ; rtB . j2525zxruy = 1.0 / ahljtvkfex * rtB .
mh2cw3g21y * hnh2rdpps5 ; rtB . ghjrhwzi5l = 1.0 / ahljtvkfex * rtB .
dxtixaknsr * hnh2rdpps5 ; rtB . i3p5tajv00 = rtX . m2uajr5r0q ; rtB .
fpzp3jifvq = rtX . icdropjsud ; rtB . kokbtkt104 = rtX . pseadm24fx ; { if (
rtDW . gsczcuj3aq . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . gsczcuj3aq . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) &
p0fynbca43 [ 0 ] + 0 ) ; } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2
( int_T tid ) { rtB . ip5sbal02i = rtP . M_Earth * - rtP . G * rtP . starshot
. IC . massproperties . m ; rtB . dwztvfu4wu [ 0 ] = rtP .
Constant3_Value_egvn5fzjrd ; rtB . dwztvfu4wu [ 1 ] = rtP . e_z_Value [ 2 ] ;
rtB . dwztvfu4wu [ 2 ] = rtP . Gain_Gain_p3pw120zm1 * rtP . e_z_Value [ 1 ] ;
rtB . dwztvfu4wu [ 3 ] = rtP . Gain1_Gain_ees4kdgcpe * rtP . e_z_Value [ 2 ]
; rtB . dwztvfu4wu [ 4 ] = rtP . Constant3_Value_egvn5fzjrd ; rtB .
dwztvfu4wu [ 5 ] = rtP . e_z_Value [ 0 ] ; rtB . dwztvfu4wu [ 6 ] = rtP .
e_z_Value [ 1 ] ; rtB . dwztvfu4wu [ 7 ] = rtP . Gain2_Gain_ed1hn35ith * rtP
. e_z_Value [ 0 ] ; rtB . dwztvfu4wu [ 8 ] = rtP . Constant3_Value_egvn5fzjrd
; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T ( *
lastU_p ) [ 3 ] ; real_T * lastU ; if ( rtDW . ogos4ffr2t == ( rtInf ) ) {
rtDW . ogos4ffr2t = ssGetT ( rtS ) ; lastU = & rtDW . gcvqyir2vi ; } else if
( rtDW . ond4jhxyao == ( rtInf ) ) { rtDW . ond4jhxyao = ssGetT ( rtS ) ;
lastU = & rtDW . jg3q0pzg5o ; } else if ( rtDW . ogos4ffr2t < rtDW .
ond4jhxyao ) { rtDW . ogos4ffr2t = ssGetT ( rtS ) ; lastU = & rtDW .
gcvqyir2vi ; } else { rtDW . ond4jhxyao = ssGetT ( rtS ) ; lastU = & rtDW .
jg3q0pzg5o ; } * lastU = rtB . fnusqcsyq4 ; if ( rtDW . ku5p2ni5nf == ( rtInf
) ) { rtDW . ku5p2ni5nf = ssGetT ( rtS ) ; lastU_p = & rtDW . n1p1mm2auv ; }
else if ( rtDW . cycn54lzew == ( rtInf ) ) { rtDW . cycn54lzew = ssGetT ( rtS
) ; lastU_p = & rtDW . nfnayvw4de ; } else if ( rtDW . ku5p2ni5nf < rtDW .
cycn54lzew ) { rtDW . ku5p2ni5nf = ssGetT ( rtS ) ; lastU_p = & rtDW .
n1p1mm2auv ; } else { rtDW . cycn54lzew = ssGetT ( rtS ) ; lastU_p = & rtDW .
nfnayvw4de ; } ( * lastU_p ) [ 0 ] = rtB . e3zxffjpma [ 0 ] ; ( * lastU_p ) [
1 ] = rtB . e3zxffjpma [ 1 ] ; ( * lastU_p ) [ 2 ] = rtB . e3zxffjpma [ 2 ] ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> ih3kel1khg [ 0 ] = rtB
. eeqjatg1dy [ 0 ] ; _rtXdot -> ih3kel1khg [ 1 ] = rtB . eeqjatg1dy [ 1 ] ;
_rtXdot -> ih3kel1khg [ 2 ] = rtB . eeqjatg1dy [ 2 ] ; _rtXdot -> coq2qfoyy1
[ 0 ] = rtB . jpsplb3g3c [ 0 ] ; _rtXdot -> coq2qfoyy1 [ 1 ] = rtB .
jpsplb3g3c [ 1 ] ; _rtXdot -> coq2qfoyy1 [ 2 ] = rtB . jpsplb3g3c [ 2 ] ;
_rtXdot -> coq2qfoyy1 [ 3 ] = rtB . jpsplb3g3c [ 3 ] ; _rtXdot -> kiwbiqrd0g
= rtB . kokbtkt104 ; _rtXdot -> pnyvn52cos = rtB . i3p5tajv00 ; _rtXdot ->
p0mibproqm = rtB . fpzp3jifvq ; _rtXdot -> exlhpb4fq0 [ 0 ] = rtB .
cek4ch2hyg [ 0 ] ; _rtXdot -> exlhpb4fq0 [ 1 ] = rtB . cek4ch2hyg [ 1 ] ;
_rtXdot -> exlhpb4fq0 [ 2 ] = rtB . cek4ch2hyg [ 2 ] ; _rtXdot -> m2uajr5r0q
= rtB . ghjrhwzi5l ; _rtXdot -> icdropjsud = rtB . j2525zxruy ; _rtXdot ->
pseadm24fx = rtB . maipu1b40a ; } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> hb4rkfuhyw = rtB .
femncko0cn [ 0 ] - rtP . starshot . magnetorq . m_max_x ; _rtZCSV ->
idowipttxg = rtB . femncko0cn [ 0 ] - ( - rtP . starshot . magnetorq .
m_max_x ) ; _rtZCSV -> cg45libmol = rtB . femncko0cn [ 1 ] - rtP . starshot .
magnetorq . m_max_y ; _rtZCSV -> axm3zhwtj4 = rtB . femncko0cn [ 1 ] - ( -
rtP . starshot . magnetorq . m_max_y ) ; _rtZCSV -> mpl0t1ng4h = rtB .
femncko0cn [ 2 ] - rtP . starshot . magnetorq . m_max_z ; _rtZCSV ->
d0vuxnac4h = rtB . femncko0cn [ 2 ] - ( - rtP . starshot . magnetorq .
m_max_z ) ; _rtZCSV -> hfqp4youyi [ 0 ] = 0.0 ; _rtZCSV -> hfqp4youyi [ 1 ] =
0.0 ; if ( rtB . ao1jkqsvon > 1.0 ) { _rtZCSV -> hfqp4youyi [ 0 ] = 1.0 ; }
else if ( rtB . ao1jkqsvon < - 1.0 ) { _rtZCSV -> hfqp4youyi [ 1 ] = 1.0 ; }
} void MdlTerminate ( void ) { { if ( rtDW . ow4wq5w5mm . AQHandles ) {
sdiTerminateStreaming ( & rtDW . ow4wq5w5mm . AQHandles ) ; } } { if ( rtDW .
aaja0aysz0 . AQHandles ) { sdiTerminateStreaming ( & rtDW . aaja0aysz0 .
AQHandles ) ; } } { if ( rtDW . hzbfcdgqjd . AQHandles ) {
sdiTerminateStreaming ( & rtDW . hzbfcdgqjd . AQHandles ) ; } } { if ( rtDW .
p2iiqtje1q . AQHandles ) { sdiTerminateStreaming ( & rtDW . p2iiqtje1q .
AQHandles ) ; } } { if ( rtDW . n4ujbk4ieg . AQHandles ) {
sdiTerminateStreaming ( & rtDW . n4ujbk4ieg . AQHandles ) ; } } { if ( rtDW .
egik531awp . AQHandles ) { sdiTerminateStreaming ( & rtDW . egik531awp .
AQHandles ) ; } } { if ( rtDW . hnp1vq2ji2 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . hnp1vq2ji2 . AQHandles ) ; } } { if ( rtDW .
c1v41m3tga . AQHandles ) { sdiTerminateStreaming ( & rtDW . c1v41m3tga .
AQHandles ) ; } } { if ( rtDW . gsczcuj3aq . AQHandles ) {
sdiTerminateStreaming ( & rtDW . gsczcuj3aq . AQHandles ) ; } } } static void
mr_starshot_sim_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_starshot_sim_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_starshot_sim_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_starshot_sim_restoreDataFromMxArray ( void * destData , const mxArray
* srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_starshot_sim_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_starshot_sim_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_starshot_sim_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_starshot_sim_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_starshot_sim_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_starshot_sim_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_starshot_sim_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_starshot_sim_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_starshot_sim_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_starshot_sim_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray
, mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_starshot_sim_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_starshot_sim_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_starshot_sim_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_starshot_sim_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB
) , sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 26 ] = {
"rtDW.ogos4ffr2t" , "rtDW.gcvqyir2vi" , "rtDW.ond4jhxyao" , "rtDW.jg3q0pzg5o"
, "rtDW.ku5p2ni5nf" , "rtDW.n1p1mm2auv" , "rtDW.cycn54lzew" ,
"rtDW.nfnayvw4de" , "rtDW.c0pertugry" , "rtDW.mjbfo4zbad" , "rtDW.fzywhfz1mq"
, "rtDW.nqpjy1fnao" , "rtDW.b3cxmfme20" , "rtDW.nvceavffbk" ,
"rtDW.c5ymd2b5xe" , "rtDW.aoua3yfzjz" , "rtDW.onplct1sg4" , "rtDW.ayifxsfink"
, "rtDW.o2dokb32i1" , "rtDW.cyspl0m50o" , "rtDW.kf3zmjwqmp" ,
"rtDW.eg24d5fcm1" , "rtDW.oea32fuhjg" , "rtDW.fuvtfvj1xu" , "rtDW.f4mltievmu"
, "rtDW.nekjo4wvrj" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
26 , rtdwDataFieldNames ) ; mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0
, 0 , ( const void * ) & ( rtDW . ogos4ffr2t ) , sizeof ( rtDW . ogos4ffr2t )
) ; mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * )
& ( rtDW . gcvqyir2vi ) , sizeof ( rtDW . gcvqyir2vi ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . ond4jhxyao ) , sizeof ( rtDW . ond4jhxyao ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . jg3q0pzg5o ) , sizeof ( rtDW . jg3q0pzg5o ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . ku5p2ni5nf ) , sizeof ( rtDW . ku5p2ni5nf ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . n1p1mm2auv ) , sizeof ( rtDW . n1p1mm2auv ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . cycn54lzew ) , sizeof ( rtDW . cycn54lzew ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . nfnayvw4de ) , sizeof ( rtDW . nfnayvw4de ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . c0pertugry ) , sizeof ( rtDW . c0pertugry ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . mjbfo4zbad ) , sizeof ( rtDW . mjbfo4zbad ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . fzywhfz1mq ) , sizeof ( rtDW . fzywhfz1mq ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . nqpjy1fnao ) , sizeof ( rtDW . nqpjy1fnao ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . b3cxmfme20 ) , sizeof ( rtDW . b3cxmfme20 ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . nvceavffbk ) , sizeof ( rtDW . nvceavffbk ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & (
rtDW . c5ymd2b5xe ) , sizeof ( rtDW . c5ymd2b5xe ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & (
rtDW . aoua3yfzjz ) , sizeof ( rtDW . aoua3yfzjz ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & (
rtDW . onplct1sg4 ) , sizeof ( rtDW . onplct1sg4 ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & (
rtDW . ayifxsfink ) , sizeof ( rtDW . ayifxsfink ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & (
rtDW . o2dokb32i1 ) , sizeof ( rtDW . o2dokb32i1 ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & (
rtDW . cyspl0m50o ) , sizeof ( rtDW . cyspl0m50o ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & (
rtDW . kf3zmjwqmp ) , sizeof ( rtDW . kf3zmjwqmp ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & (
rtDW . eg24d5fcm1 ) , sizeof ( rtDW . eg24d5fcm1 ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & (
rtDW . oea32fuhjg ) , sizeof ( rtDW . oea32fuhjg ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & (
rtDW . fuvtfvj1xu ) , sizeof ( rtDW . fuvtfvj1xu ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & (
rtDW . f4mltievmu ) , sizeof ( rtDW . f4mltievmu ) ) ;
mr_starshot_sim_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & (
rtDW . nekjo4wvrj ) , sizeof ( rtDW . nekjo4wvrj ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_starshot_sim_SetDWork (
const mxArray * ssDW ) { ( void ) ssDW ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0
, sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW ,
0 , 1 ) ; mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ogos4ffr2t ) , rtdwData , 0 , 0 , sizeof ( rtDW . ogos4ffr2t ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . gcvqyir2vi ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . gcvqyir2vi ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . ond4jhxyao ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . ond4jhxyao ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . jg3q0pzg5o ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . jg3q0pzg5o ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . ku5p2ni5nf ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . ku5p2ni5nf ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . n1p1mm2auv ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . n1p1mm2auv ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . cycn54lzew ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . cycn54lzew ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . nfnayvw4de ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . nfnayvw4de ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . c0pertugry ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . c0pertugry ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . mjbfo4zbad ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . mjbfo4zbad ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . fzywhfz1mq ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . fzywhfz1mq ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . nqpjy1fnao ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . nqpjy1fnao ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . b3cxmfme20 ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . b3cxmfme20 ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . nvceavffbk ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . nvceavffbk ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . c5ymd2b5xe ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . c5ymd2b5xe ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . aoua3yfzjz ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . aoua3yfzjz ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . onplct1sg4 ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . onplct1sg4 ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . ayifxsfink ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . ayifxsfink ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . o2dokb32i1 ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . o2dokb32i1 ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . cyspl0m50o ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . cyspl0m50o ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . kf3zmjwqmp ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . kf3zmjwqmp ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . eg24d5fcm1 ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . eg24d5fcm1 ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . oea32fuhjg ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . oea32fuhjg ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . fuvtfvj1xu ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . fuvtfvj1xu ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . f4mltievmu ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . f4mltievmu ) ) ;
mr_starshot_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . nekjo4wvrj ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . nekjo4wvrj ) ) ; } } mxArray *
mr_starshot_sim_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 10 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope"
, "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , } ; static const char_T *
blockPath [ 10 ] = { "starshot_sim/Current/Current" ,
"starshot_sim/Earth's magnetic field (body)" , "starshot_sim/Scope" ,
"starshot_sim/theta_(omegaB)/Scope1" ,
"starshot_sim/ /Earth's magnetic field (ECI)" ,
"starshot_sim/   /Euler angles" , "starshot_sim/   /Quaternion" ,
"starshot_sim/     /Angular velocity" , "starshot_sim/Orbital Dynamics/Scope"
, "starshot_sim/Saturation/magnetic dipole" , } ; static const int reason [
10 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ;
subs [ 0 ] < 10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 16 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 242 ) ; ssSetNumBlockIO ( rtS , 31 ) ;
ssSetNumBlockParams ( rtS , 65 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 450159784U ) ;
ssSetChecksumVal ( rtS , 1 , 2054323638U ) ; ssSetChecksumVal ( rtS , 2 ,
1979725367U ) ; ssSetChecksumVal ( rtS , 3 , 1508144400U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 31 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
starshot_sim_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "starshot_sim" ) ;
ssSetPath ( rtS , "starshot_sim" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 250000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 4
, 1 , 1 , 1 , 3 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ]
= { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 3 , 4 , 1 , 1 , 1 , 3 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"starshot_sim/Kane Damper_controller/Integrator8" ,
"starshot_sim/   /Integrator7" , "starshot_sim/Orbital Dynamics/Integrator2"
, "starshot_sim/Orbital Dynamics/Integrator" ,
"starshot_sim/Orbital Dynamics/Integrator1" ,
"starshot_sim/     /Integrator6" ,
"starshot_sim/Orbital Dynamics/Integrator3" ,
"starshot_sim/Orbital Dynamics/Integrator4" ,
"starshot_sim/Orbital Dynamics/Integrator5" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0
, SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 ,
6 , 7 , 8 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 9 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 9 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ih3kel1khg [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . coq2qfoyy1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . kiwbiqrd0g ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . pnyvn52cos ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . p0mibproqm ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . exlhpb4fq0 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . m2uajr5r0q ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . icdropjsud ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . pseadm24fx ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 16 ] ;
static real_T absTol [ 16 ] = { 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 ,
1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 ,
1.0E-9 , 1.0E-9 , 1.0E-9 } ; static uint8_T absTolControl [ 16 ] = { 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ;
static real_T contStateJacPerturbBoundMinVec [ 16 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 16 ] ; static uint8_T zcAttributes [ 8 ] = {
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; {
int i ; for ( i = 0 ; i < 16 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ]
= 0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 1.0E-6 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.001 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 4.0 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 8 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 8 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 450159784U ) ; ssSetChecksumVal ( rtS , 1 ,
2054323638U ) ; ssSetChecksumVal ( rtS , 2 , 1979725367U ) ; ssSetChecksumVal
( rtS , 3 , 1508144400U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 6 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . nekjo4wvrj ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW . f4mltievmu ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . fuvtfvj1xu ; systemRan [ 4 ] = &
rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_starshot_sim_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP
( rtS , mr_starshot_sim_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_starshot_sim_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if
( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
