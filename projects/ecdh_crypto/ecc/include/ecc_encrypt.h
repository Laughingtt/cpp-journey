//
// Created by tian on 2022/9/19.
//

#ifndef ECDH_ECC_ENCRYPT_H
#define ECDH_ECC_ENCRYPT_H

#include <cstdlib>
#include <ctime>
#include "ecc.h"
#include "hash.h"
#include "proto/include/curve_point.pb.h"

class EccEncrypt {
private:
    vector<mpz_class> public_key = vector<mpz_class>(2);
    mpz_class private_key;

public:
    ECC *ecc;

    EccEncrypt() {
        ecc = new ECC();
        srand((int)time(0));
    }

    EccEncrypt(const string &curve_name) {
        ecc = new ECC(curve_name);
        srand((int)time(0));
    }

    ~EccEncrypt() {
        delete ecc;
    }

    void generate_key();

    vector<string> get_public_key();

    string get_private_key();

    vector<string> encrypt(const string &msg);

    string encrypt_serialize(const string &msg);

    string hash_to_curve(const string &msg);

    string decrypt(const vector<string> &enc_v);

    string decrypt_deserialize(const string &sen);

};


#endif //ECDH_ECC_ENCRYPT_H
