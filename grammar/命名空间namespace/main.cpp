#include <iostream>
#include "Name.h"
#include "Name2.h"
#include "clal.h"
#include "library.h"

using namespace PSI;
using namespace PSI2;

int main() {
    std::cout << PSI::a << std::endl;
    std::cout << PSI2::a << std::endl;
    std::cout << "Hello, World!" << std::endl;
    std::cout << add_values(1, 2) << std::endl;
    hello();
    return 0;
}
