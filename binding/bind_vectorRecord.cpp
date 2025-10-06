#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../header/VectorRecord.hpp"
namespace py = pybind11;

void bind_vectorRecord(py::module_ &m){
    py::class_<VectorRecord>(m, "VectorRecord")
        .def(py::init<>())
        .def(py::init<int, std::vector<double>>(), py::arg("id"), py::arg("vec")) 
        
        .def_readwrite("id", &VectorRecord::id)
        .def_readwrite("vec", &VectorRecord::vec)
        .def("__eq__", &VectorRecord::operator==)
        .def("__ne__", &VectorRecord::operator!=)
        .def("__str__", &VectorRecord::to_string)
        .def("to_string", &VectorRecord::to_string)
        ;
}