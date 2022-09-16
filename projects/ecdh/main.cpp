#include "iostream"
#include "ecc.h"

using namespace std;

class Test {
public:
    void test() {};
};


int main(int argc, char const *argv[]) {
    cout << "main function" << endl;

    ECC::print_hello();
    ECC::test_gmp();
    ECC ecc;
//    ecc.generate_point();
    ecc.test_mod_inv();
    ecc.test_ecc_add();
    ecc.test_ecc_mul();


    return 0;
}
