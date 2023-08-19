@echo off
set COMPILER=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\bin\gcc
                set CXXCOMPILER=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\bin\g++
                set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set CXXCOMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set OPTIMFLAGS=-O2 -fwrapv -DNDEBUG
                set DEBUGFLAGS=-g
                set LINKER=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\bin\gcc
                set CXXLINKER=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\bin\g++
                set LINKFLAGS=-m64 -Wl,--no-undefined -shared -static -L"E:\Matlab\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -llibMatlabDataArray -llibMatlabEngine -Wl,"E:\Matlab/extern/lib/win64/mingw64/mexFunction.def"
                set LINKDEBUGFLAGS=-g
                set NAME_OUTPUT= -o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\bin;E:\Matlab\extern\include\win64;E:\Matlab\extern\include;E:\Matlab\simulink\include;E:\Matlab\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\include;C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include\c++;C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include;C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include\c++\x86_64-w64-mingw32;C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include\c++\backward;C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\x86_64-w64-mingw32\include;%INCLUDE%
set LIB=C:\ProgramData\MATLAB\SupportPackages\R2023a\3P.instrset\mingw_w64.instrset\lib;;%LIB%
set LIBPATH=E:\Matlab\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f EKF_sfun.gmk
