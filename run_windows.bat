@echo off
:: Liquid QR Coder Runner for Windows
:: Requires CMake and Qt 6 in PATH

set SCRIPT_DIR=%~dp0
cd /d %SCRIPT_DIR%

if not exist "build\appLiquidQR.exe" (
    echo First time setup: Building the application...
    if not exist build mkdir build
    cd build
    cmake .. -G "MinGW Makefiles"
    cmake --build .
    cd ..
)

echo Starting Liquid QR Coder...
start build\appLiquidQR.exe
