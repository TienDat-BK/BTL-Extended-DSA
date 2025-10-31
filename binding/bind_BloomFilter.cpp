#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../header/BloomFilter.hpp"

#include "../header/VectorRecord.hpp"
#include "../header/iHash.hpp"

namespace py = pybind11;

void bind_bloomfilter(py::module_ &m) {
  py::class_<BloomFilter, IHash>(m, "BloomFilter")
      .def(py::init<int, int, size_t, double>(), py::arg("InputDim"),
           py::arg("OutputDim"), py::arg("expectedItems"),
           py::arg("falsePositiveRate"))
      .def("hash", &BloomFilter::hash, py::arg("records"))
      .def("possiblyContains", &BloomFilter::possiblyContains,
           py::arg("indices"));
}
