cmake_minimum_required(VERSION 3.12)
project(example_module)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compiler optimization and warning flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -mtune=native -flto=auto -funroll-loops")

# Add compile options for optimization
# -O3                  # Enable high level of optimization
# -march=native        # Optimize code for the current machine's CPU
# -mtune=native        # Tune the code's performance for the current machine's CPU
# -funroll-loops       # Enable loop unrolling
# -ffast-math          # Enable fast math operations (caution: may alter accuracy)
# -flto=auto           # Enable Link Time Optimization
# -fomit-frame-pointer # Omit the frame pointer

# Find Python and Pybind11 packages
find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Define the module target
pybind11_add_module(pybind_test_module pybind_test_module_code.cpp)

# Link the Python libraries to the module
target_link_libraries(pybind_test_module PRIVATE Python::Python Eigen3::Eigen)

pybind11_add_module(SomeObject_module SomeObject_module_code.cpp)

# Link the Python libraries to the module
target_link_libraries(SomeObject_module PRIVATE Python::Python)

pybind11_add_module(worker_module BackgroundWorker_module_code.cpp)

# Link the Python libraries to the module
target_link_libraries(worker_module PRIVATE Python::Python)

# -Ofast Optimization Level

# -Ofast includes all the optimizations from -O3 and adds optimizations that are not standard-compliant,
# which can break strict IEEE or ISO rules for floating-point arithmetic. The key additional flags activated
# by -Ofast include:

# -ffast-math: This optimization allows the compiler to violate IEEE or ANSI standards.
# Functions such as sin, cos, and sqrt can be significantly faster at the cost of some
# precision and the behavior of edge cases like handling NaN or infinity.

# -fno-protect-parens: This disregards parentheses to allow for more aggressive reassociation
# of floating-point operations.

# -fstack-arrays: Allows automatic arrays to be allocated on the stack instead of the heap,
# which might increase performance.