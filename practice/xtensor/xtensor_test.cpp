//
// Created by tian on 2023/1/3.
//
#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include "xtensor/xarray.hpp"
#include "xtensor/xcsv.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <fstream>
#include "string"


void read_csv(const std::string& file_name) {
    xt::xarray<double> ds;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "open file={} failed" << file_name << std::endl;
        exit(-1);
    }
    ds = xt::load_csv<double>(file, ',', 1);

    std::cout << "row is :" << xt::row(ds,0) << std::endl;
    std::cout << "col is :" << xt::col(ds,0) << std::endl;
    std::cout << "ds is :" << ds << std::endl;
}

void test01(){
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

int main(int argc, char *argv[]) {

    test01();
//    read_csv("/Users/tian/Projects/udaiml/udai_test/data/woe_data_1000/my_data_guest.csv");
    return 0;
}