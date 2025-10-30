#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../header/MinHash.hpp"
#include "../header/iHash.hpp"
#include "../header/VectorRecord.hpp"
namespace py = pybind11;

void bind_minhash(py::module_ &m){
    py::class_<MinHash, IHash>(m, "MinHash")
        .def(py::init<int, int>(), py::arg("InputDim"), py::arg("OutputDim"))
        .def("hash_1", &MinHash::hash_1, py::arg("record"))
        .def("hash", &MinHash::hash, py::arg("list of record"))
    ;   
}