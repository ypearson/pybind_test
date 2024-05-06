# Pybind Test Module

This repository demonstrates the integration of C++ functions with Python using pybind11. It includes a Python script that tests various C++ functions exposed via the pybind11 module, including functions with no parameters, one parameter, and two parameters.

## Requirements

- Python 3.x
- CMake
- A C++ compiler supporting C++20
- pybind11

## Building the Module

Follow these steps to build the pybind11 module:

1. Clone the repository and navigate to the project directory.
2. Run build script that will also run the test python script:
   ```bash ./build.sh```

3. Observe results
```bash Testing the module with pybind_test.py...
func_no_params: 42
func_one_param(5): 10
func_two_params(3, 4): 7
Average time per function call over 10000 calls: 0.08200949523597956 us
```

## Configuration Notes
* Make sure your PYTHONPATH is set correctly or that the Python script is executed in an
environment where the Python interpreter can locate the pybind11 module.

