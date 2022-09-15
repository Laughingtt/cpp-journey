#include <iostream>
#include "Cube.h"
#include "ThreadTest.h"
#include "ForkTest.h"

using namespace std;

void test01() {
    Cube c;
    c.set(3, 4, 5);
    std::cout << "体积为:" << c.get_tiji() << std::endl;

    Cube c2;
    c2.set(4, 3, 5);
    std::cout << "体积为:" << c2.get_tiji() << std::endl;

    bool r = c.check_equal(c2);

}

void test02(){
    ThreadTest tt;
    tt.test();
}


void test03(){
    ForkTest ft;
    ft.test();
}

int main() {
    test03();
    return 0;
}