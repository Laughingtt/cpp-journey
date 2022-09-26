#include "iostream"
#include "test.h"
#include "test_gmp.h"

using namespace std;


int main(int argc, char const *argv[]) {
    cout << "main function" << endl;

    Test test;
//    test.test_mod_inv();
//    test.test_ecc_add();
//    test.test_ecc_add2();
//    test.test_ecc_sub();
//    test.test_ecc_mul();
//    test.test_get_key();
//    test.test_key_exchange();
    test.test_encrypt();
//    test.test_hash_curve();
//    test.test_ot();
//    test.test_ecc_serialize();

//    TestGmp tgmp;
//    tgmp.test_gmp();

    return 0;
}
