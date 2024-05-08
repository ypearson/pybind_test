#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <Eigen/Dense>
#include <chrono>
#include <cmath>

namespace py = pybind11;
using namespace Eigen;

Eigen::Matrix4d se3_random() {
  Eigen::Matrix4d T =
      Eigen::Matrix4d::Random();  // Generates a random 4x4 matrix
  // Normally, you would ensure the matrix is a valid SE3 transformation
  return T;
}

Matrix4d computeTransform(const Matrix4d& common_node_t_object,
                          const Matrix4d& common_node_t_reference) {
  Matrix4d reference_inv = common_node_t_reference.inverse();
  return reference_inv * common_node_t_object;
}

namespace py = pybind11;

void square_array(py::array_t<double> input) {
  py::buffer_info buf = input.request();
  double* ptr = static_cast<double*>(buf.ptr);

  int num_elements = 1;
  for (auto r : buf.shape) {
    num_elements *= r;
  }

  for (int i = 0; i < num_elements; i++) {
    ptr[i] = std::pow(ptr[i], 2);
  }
}

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
  m.def("square_array", &square_array,
        "A function which squares each element of a NumPy array");
  m.def("se3_random", &se3_random,
        "Generates a random SE3 transformation matrix");
  m.def("compute_transform", &computeTransform,
        "Compute the transform of reference_t_object");
}
