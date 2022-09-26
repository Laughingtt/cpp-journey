//
// Created by tian on 2022/9/19.
//

#ifndef ECDH_ECC_ENCRYPT_H
#define ECDH_ECC_ENCRYPT_H

#include "ecc.h"
#include "hash.h"

class EccEncrypt {
private:
    vector<mpz_class> public_key = vector<mpz_class>(2);
    mpz_class private_key;

public:
    ECC *ecc;

    EccEncrypt() {
        ecc = new ECC();
    }

    EccEncrypt(const string& curve_name) {
        ecc = new ECC(curve_name);
    }

    ~EccEncrypt() {
        delete ecc;
    }

    void generate_key();

    vector<string> encrypt(const string &msg);

    string decrypt(const vector<string> &enc_v);
};


#endif //ECDH_ECC_ENCRYPT_H
