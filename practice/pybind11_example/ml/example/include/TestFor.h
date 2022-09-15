//
// Created by tian on 2022/7/12.
//

#ifndef PYBIND_EXAMPLE_TESTFOR_H
#define PYBIND_EXAMPLE_TESTFOR_H
#include "vector"
#include "iostream"

using namespace std;

class TestFor {
public:
    vector<int> sub_vector(vector<int> a ,vector<int>b){
        for (auto i = 0; i < a.size(); ++i) {
            a[i] = a[i] - b[i];
        }
        return a;
    };

// 目前没法在cpp中实现引用，会报错flat namespace
    int add(int &i, int &j);

};


#endif //PYBIND_EXAMPLE_TESTFOR_H
