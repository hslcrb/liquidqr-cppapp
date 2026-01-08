#!/bin/bash
# Liquid QR Coder Runner for Linux

# Ensure the script directory is the working directory
cd "$(dirname "$0")"

# Build if not already built
if [ ! -f "build/appLiquidQR" ]; then
    echo "First time setup: Building the application..."
    mkdir -p build && cd build
    cmake .. && make -j$(nproc)
    cd ..
fi

# Run the application
echo "Starting Liquid QR Coder..."
./build/appLiquidQR
