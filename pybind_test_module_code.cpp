#include <pybind11/pybind11.h>

int func_no_params() { return 42; }

int func_one_param(int x) { return x * 2; }

int func_two_params(int x, int y) { return x + y; }

PYBIND11_MODULE(pybind_test_module, m) {
  m.doc() = "pybind11 example plugin";  // Optional module docstring

  m.def("func_no_params", &func_no_params,
        "A function that takes no parameters and returns 42.");
  m.def("func_one_param", &func_one_param,
        "A function that takes one integer parameter and returns its double.");
  m.def("func_two_params", &func_two_params,
        "A function that takes two integer parameters and returns their sum.");
}
