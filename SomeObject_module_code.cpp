#include <pybind11/pybind11.h>

#include "SomeObject.hpp"

namespace py = pybind11;

PYBIND11_MODULE(SomeObject_module, m) {
  py::class_<SomeObject>(m, "SomeObject")
      .def(py::init<const std::string &, const std::string &>())
      .def("set_name", &SomeObject::setName)
      .def("get_name", &SomeObject::getName)
      .def("set_type", &SomeObject::setType)
      .def("get_type", &SomeObject::getType);
}
