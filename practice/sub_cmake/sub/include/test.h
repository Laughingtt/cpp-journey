//
// Created by tian on 2022/12/13.
//

#ifndef CMAKE_DIR_TEST_H
#define CMAKE_DIR_TEST_H

#include "string"
#include "iostream"
#include "main/include/master.h"

class test {
public:
    static void print(std::string &str);

    void print2(std::string &str) {
        auto m = std::make_shared<master>();
        m->print(str);
    }
};


#endif //CMAKE_DIR_TEST_H
