#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../header/IHash.hpp"
#include "../header/VectorRecord.hpp"

namespace py = pybind11;

class PyIHash : public IHash {
public:
    using IHash::IHash;
    std::vector<VectorRecord> hash(const std::vector<VectorRecord> &input) override {
        PYBIND11_OVERRIDE_PURE(
            std::vector<VectorRecord>,  // return type
            IHash,                      // parent class
            hash,                       // name of the function
            input                       // argument
        );
    }
};

void bind_ihash(py::module_ &m) {
    py::class_<IHash, PyIHash>(m, "IHash")
        .def(py::init<int, int>())
        .def("hash", &IHash::hash);
}
