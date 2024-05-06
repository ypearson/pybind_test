#include <pybind11/pybind11.h>

#include "BackgroundWorker.hpp"

namespace py = pybind11;

PYBIND11_MODULE(worker_module, m) {
  py::class_<BackgroundWorker>(m, "BackgroundWorker")
      .def(py::init<>())
      .def("get_counter", &BackgroundWorker::getCounter);
}
