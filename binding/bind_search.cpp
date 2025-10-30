#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include "../header/ISearch.hpp"
#include "../header/VectorRecord.hpp"

namespace py = pybind11;
void bind_search(py::module_ &m)
{
    py::class_<Search>(m, "Search")
        .def(py::init<>())
        .def_static("jarcardSimilarity", &Search::jarcardSimilarity)
        .def_static("hammingDistance", &Search::hammingDistance)
        .def("classifyByBand", &Search::classifyByBand)
        .def("classify", &Search::classify)
        .def("setDisFunc", &Search::setDisFunc, py::arg("nameDisFunc"))

        .def_readwrite("disFunc", &Search::disFunc)
        .def_readwrite("num_bands", &Search::num_bands)
        .def_readwrite("threshold", &Search::threshold);
}