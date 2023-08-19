######################################################################
# CMakeLists.txt generated for component EKF
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(EKF)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT E:/Matlab CACHE PATH "")
if(${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(BUILDING_IN_SOURCE_DIR TRUE)
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BUILDING_IN_SOURCE_DIR FALSE)
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(WIN32 AND NOT MINGW)
    set(SYSLIB_PREFIX "lib")
else()
    set(SYSLIB_PREFIX "")
endif()

######################################################################
## System libraries
######################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES}
    ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

######################################################################
## Target definition and commands
######################################################################
add_executable(EKF  ${START_DIR}/EKF_ert_rtw/EKF.cpp
    ${START_DIR}/EKF_ert_rtw/EKF_data.cpp
    ${START_DIR}/EKF_ert_rtw/ert_main.cpp)
set_target_properties(EKF PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")
target_compile_definitions(EKF PRIVATE -DMODEL=EKF
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=0
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0)
target_include_directories(EKF PRIVATE ${START_DIR}
    ${START_DIR}/EKF_ert_rtw
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert)
target_link_libraries(EKF PRIVATE $<$<BOOL:${FOUND_LIBM}>:m>)
if(WIN32)
   target_link_libraries(EKF PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()

######################################################################
## Extract debug symbols
######################################################################
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:EKF>;--flat,"
                "true"
        >)
    add_custom_command(TARGET EKF
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS EKF.dwarf)
endif()


######################################################################
## Build success message
######################################################################
add_custom_command(TARGET EKF POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:EKF>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(EKF)
endif()
