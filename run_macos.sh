#!/bin/bash
# Liquid QR Coder Runner for macOS
# Requires CMake and Qt 6 (via Brew)

cd "$(dirname "$0")"

if [ ! -d "build/appLiquidQR.app" ]; then
    echo "First time setup: Building the application..."
    mkdir -p build && cd build
    cmake ..
    make -j$(sysctl -n hw.ncpu)
    cd ..
fi

echo "Starting Liquid QR Coder..."
open build/appLiquidQR.app
