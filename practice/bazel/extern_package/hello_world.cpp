#include "my_lib.h"
#include <iostream>

int main()
{
	std::cout << "Hello world " << my_lib::sum(40, 2) << std::endl;
	std::cout << "Hello world " << my_lib::sum(41, 2) << std::endl;
	std::cout << "Hello world " << my_lib::sum(42, 2) << std::endl;
}
