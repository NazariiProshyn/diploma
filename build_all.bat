@echo off
setlocal

set BUILD_TYPE=Debug
set INSTALL_AFTER_BUILD=0
set RUN_TESTS=0

:: Loop through arguments and process them
:argsloop
if "%~1"=="" goto argsloopend
if /I "%1"=="Release" set BUILD_TYPE=Release
if /I "%1"=="Debug" set BUILD_TYPE=Debug
if /I "%1"=="install" set INSTALL_AFTER_BUILD=1
shift
goto argsloop
:argsloopend

cd build/
cmake ../ -DCMAKE_BUILD_TYPE=%BUILD_TYPE%
cmake --build . --config %BUILD_TYPE%

if %INSTALL_AFTER_BUILD%==1 (
    cmake --install . --prefix "../" --config %BUILD_TYPE%
)

endlocal