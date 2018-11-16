#include "example.h"

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

namespace py = pybind11;

PYBIND11_MODULE(examplebind, m) {
  m.doc() = "pybind11 wrapper for some example functions";

  py::class_<Complex>(m, "Complex")
    .def(py::init<const double, const double>())
    .def(py::self += py::self)
    .def(py::self -= py::self)
    .def(py::self *= py::self)
    .def(py::self /= py::self)
    .def("realPart", &Complex::realPart)
    .def("imagPart", &Complex::imagPart)
    .def("setReal", &Complex::setReal)
    .def("setImag", &Complex::setImag)
    .def("norm", &Complex::norm)
    .def("conj", &Complex::conj)
    .def("__repr__", &Complex::toString);

  m.def("add", &add, "add two Complex numbers");
  m.def("subtract", &subtract, "subtract two Complex numbers");
  m.def("multiply", &multiply, "multiply two Complex numbers");
  m.def("divide", &divide, "divide two Complex numbers");

}
