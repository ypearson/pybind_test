#!/bin/bash

# Create build directory
rm -rf build
mkdir -p build
cd build

# Run CMake
cmake ..

# Build the project
make

export PYTHONPATH=$PYTHONPATH:$PWD

# Execute Python script to test the module
echo "Testing the module with pybind_test.py..."
python3 ../test.py
