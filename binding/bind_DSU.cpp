#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../header/DSU.hpp"
#include "../header/STL.hpp"
#include "../header/VectorRecord.hpp"

namespace py = pybind11;

void bind_DSU(py::module_ &m) {
  py::class_<DSU>(m, "DSU")
      .def(py::init<int>(), py::arg("n"))
      .def("getGroups", &DSU::getGroups)
      .def("unionSet", &DSU::unionSet, py::arg("u"), py::arg("v"));
}