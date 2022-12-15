#include <iostream>
#include "main/include/master.h"
#include "test.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto t = std::make_shared<test>();
    std::string n = "call your name !!!";
    t->print(n);
    t->print2(n);

    auto m = std::make_shared<master>();
    m->print(n);
    return 0;
}
