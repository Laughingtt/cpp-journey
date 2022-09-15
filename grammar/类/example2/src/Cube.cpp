//
// Created by tian on 2022/7/26.
//
#include "iostream"
#include "../include/Cube.h"


void Cube::set(int _length, int _width, int _high) {
    this->length = _length;
    this->width = _width;
    this->high = _high;
}

int Cube::get_tiji() {
    return length * width * high;
}

bool Cube::check_equal(Cube c) {
    if (get_tiji() == c.get_tiji()) {
        std::cout << "体积相等" << std::endl;
        return true;
    } else {
        std::cout << "体积不相等" << std::endl;
        return false;
    }
}