//
// Created by tian on 2022/4/15.
//

#include "iostream"
#include "string"
#include "bitset"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vector"
#include "TestFor.h"
#include "Pet.h"


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

void test() {
    int r = 0;
    for (int i = 0; i < 100000000; ++i) {
        r = i + r;
    }
}

vector<int> bit_to_int(string bstr,int bit_length) {
    vector<int> lis;
    int sum;
    for (int i = 0; i < bstr.size(); i += bit_length) {
        sum = 0;
        for (int j = 0; j < bit_length; j++){
            if (bstr[i + j] == '1')
                sum = sum * 2 + 1;
            else
                sum = sum * 2;
        }
        lis.push_back(sum);
    }
    return lis;
}

vector<string> find_position(vector<vector<int>> &v_list,vector<string> &matrix){
    unsigned int sample_length = v_list.size();
    unsigned int param_w = matrix.size();
    vector<string> final_sid(sample_length);
//    cout << "sample_length" << sample_length <<endl;
    for (auto idx = 0; idx < sample_length; ++idx) {
        string temp;
        bitset::bitset<param_w> temp_bit;
        for (int w_idx = 0; w_idx < param_w; ++w_idx) {
            temp+=matrix[w_idx][v_list[idx][w_idx]];
            temp_bit[w_idx] = stoi(matrix[w_idx][v_list[idx][w_idx]]);
        }
        final_sid[idx]=temp;
    }
    return final_sid;

}

PYBIND11_MODULE(algo_lib, m
) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("test", &test, "test");
    m.def("add", &add, "A function that adds two numbers");
    m.def("add_vector", &add_vector, "A function that adds two vector numbers");
    m.def("bit_to_int", &bit_to_int, "bit to int");
    m.def("find_position", &find_position, "find_position");

    py::class_<TestFor>(m, "TestFor")
        .def(py::init<>())
//        .def("add", &TestFor::add)
        .def("sub_vector", &TestFor::sub_vector);


//  类的引用
    py::class_<Pet>(m, "Pet")
        .def(py::init<>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("__repr__",
            [](const Pet &a) {
            return "<example.Pet named '" + a.name + "'>";
            });
}