#include "iostream"
#include "ecc.h"

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "main function" << endl;

    ECC::print_hello();
    ECC::test_gmp();
    ECC ecc;
    ecc.generate_point();


    return 0;
}
