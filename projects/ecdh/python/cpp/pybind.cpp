//
// Created by tian on 2022/4/15.
//

#include "iostream"
#include "string"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vector"
#include "test.h"


using namespace std;
namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

py::list add_vector(py::list &a, py::list &b) {
    for (auto i = 0; i < a.size(); ++i) {
        a[i] = a[i] + b[i];
    }
    return a;
}


PYBIND11_MODULE(_ecdh_lib, m
) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
    m.def("add_vector", &add_vector, "A function that adds two vector numbers");

    //  测试类的引用
    py::class_<Test>(m, "Test")
            .def(py::init<>())
            .def("test_mod_inv", &Test::test_mod_inv)
            .def("test_ecc_add", &Test::test_ecc_add)
            .def("test_ecc_add2", &Test::test_ecc_add2)
            .def("test_ecc_sub", &Test::test_ecc_sub)
            .def("test_ecc_mul", &Test::test_ecc_mul)
            .def("test_get_key", &Test::test_get_key)
            .def("test_key_exchange", &Test::test_key_exchange)
            .def("test_encrypt", &Test::test_encrypt)
            .def("test_hash_curve", &Test::test_hash_curve)
            .def("test_ot", &Test::test_ot);

    // msg - > curve point
    py::class_<EccEncrypt>(m, "EccEncrypt")
            .def(py::init<>())
            .def("encrypt", &EccEncrypt::encrypt)
            .def("decrypt", &EccEncrypt::decrypt);

    // OT
    py::class_<EccObliviousTransfer>(m, "EccObliviousTransfer")
            .def(py::init<>())
            .def("get_public_key", &EccObliviousTransfer::get_public_key)
            .def("receiver_compute_k", &EccObliviousTransfer::receiver_compute_k)
            .def("receiver_compute_secret_key", &EccObliviousTransfer::receiver_compute_secret_key)
            .def("sender_compute_secret_list", &EccObliviousTransfer::sender_compute_secret_list)
            .def("sender_compute_secret_key", &EccObliviousTransfer::sender_compute_secret_key);

    // ECC
    py::class_<ECC>(m, "ECC")
            .def(py::init<>())
            .def("generate_point", &ECC::generate_point)
            .def("hash_to_curve", &ECC::hash_to_curve);

    // msg - > curve point
    py::class_<HashString>(m, "HashString")
            .def(py::init<>())
            .def(py::init<const std::string &>())
            .def("run", &HashString::run);


}