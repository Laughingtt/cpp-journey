//
// Created by tian on 2022/9/20.
//

#ifndef ECDH_TEST_H
#define ECDH_TEST_H

#include "ecc.h"
#include "vector"
#include "ecc_encrypt.h"
#include "ctime"
#include "hash.h"
#include "ecc_oblivious_transfer.h"

class Test {
private:
    ECC *ecc = new ECC();
    ECC *ecc2 = new ECC();
public:
    Test() {
        ecc->generate_point();
        ecc2->generate_point();
    }

    ~Test() {
        delete ecc;
        delete ecc2;
    }

    void test() {};

    void test_get_key();


    void test_ecc_mul();

    void test_ecc_add();
    void test_ecc_add2();

    void test_ecc_sub();

    void test_mod_inv();

    void test_key_exchange();

    void test_encrypt();

    void test_name_encrypt();

    void test_hash();

    void test_hash_curve();

    void test_ot();

};


#endif //ECDH_TEST_H
