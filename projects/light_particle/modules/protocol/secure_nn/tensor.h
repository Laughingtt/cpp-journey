//
// Created by tian on 2023/1/4.
//

#ifndef LIGHT_PARTICLE_TENSOR_H
#define LIGHT_PARTICLE_TENSOR_H

#include "iostream"
#include "fstream"
#include "xtensor/xarray.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xcsv.hpp"

void test01() {
    xt::xarray<double> arr1
            {{1.0, 2.0, 3.0},
             {2.0, 5.0, 7.0},
             {2.0, 5.0, 7.0}};

    xt::xarray<double> arr2
            {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::cout << xt::view(arr1, 1) << std::endl;
    std::cout << res << std::endl;
}

void read_csv(const std::string &file_name) {
    xt::xarray<double> ds;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "open file={} failed" << file_name << std::endl;
        exit(-1);
    }
    ds = xt::load_csv<double>(file, ',', 1);

    std::cout << "row is :" << xt::row(ds, 0) << std::endl;
    std::cout << "col is :" << xt::col(ds, 0) << std::endl;
    std::cout << "ds is :" << ds << std::endl;
}

#endif //LIGHT_PARTICLE_TENSOR_H
