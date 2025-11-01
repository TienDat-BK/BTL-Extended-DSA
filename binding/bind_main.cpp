#include <pybind11/pybind11.h>
namespace py = pybind11;

// Khai báo các hàm bind con
void bind_minhash(py::module_ &m);
void bind_simhash(py::module_ &m);
void bind_vectorRecord(py::module_ &m);
void bind_ihash(py::module_ &m);
void bind_search(py::module_ &m);
void bind_bloomfilter(py::module_ &m);
void bind_DSU(py::module_ &m);

PYBIND11_MODULE(HSmodule, m) {
  m.doc() = "Hash bindings module";
  bind_vectorRecord(m);
  bind_ihash(m);
  bind_minhash(m);
  bind_simhash(m);
  bind_search(m);
  bind_bloomfilter(m);
  bind_DSU(m);
}
