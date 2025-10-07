#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../header/SimHash.hpp"
#include "../header/iHash.hpp"
#include "../header/VectorRecord.hpp"
namespace py = pybind11;

void bind_simhash(py::module_ &m){
    py::class_<SimHash, IHash>(m, "MinHash")
        .def(py::init<int, int>(), py::arg("InputDim"), py::arg("OutputDim"))
        .def("hash_1", &SimHash::hash_1, py::arg("record"))
        .def("hash", &SimHash::hash, py::arg("list of record"))
    ;   
}