//
// Created by tian on 2022/9/19.
//

#ifndef ECDH_ECCENCRYPT_H
#define ECDH_ECCENCRYPT_H

#include "ecc.h"

class EccEncrypt {
private:
    ECC *ecc = new ECC();
    vector<mpz_class> public_key = vector<mpz_class>(2);
    mpz_class private_key;

public:
    EccEncrypt() {

    }

    ~EccEncrypt() {
        delete ecc;
    }

    void generate_key() {
        this->ecc->generate_point();
        public_key = ecc->get_public_key();
        private_key = ecc->get_private_key();
    }

    vector<mpz_class> encrypt() {
        vector<mpz_class> msg_point(2);
        msg_point[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        msg_point[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";

        mpz_class mpz_r = 3;

        vector<mpz_class> c1(2);
        vector<mpz_class> c2(2);
        vector<mpz_class> RR(4);

        vector<mpz_class> param_g = ecc->get_param_g();
        ecc->ecc_mul(param_g, mpz_r, c1);
//
        ecc->ecc_mul(this->public_key, mpz_r, c2);
        ecc->ecc_add(msg_point, c2, c2);

        RR[0] = c1[0];
        RR[1] = c1[1];
        RR[2] = c2[0];
        RR[3] = c2[1];

        return RR;
    }

    void decrypt(vector<mpz_class> &enc_v) {
        vector<mpz_class> c1(2);
        vector<mpz_class> c2(2);
        c1[0] = enc_v[0];
        c1[1] = enc_v[1];
        c2[0] = enc_v[2];
        c2[1] = enc_v[3];
        vector<mpz_class> R(2);
        vector<mpz_class> R2(2);
        ecc->ecc_mul(c1, this->private_key, R);
        ecc->ecc_sub(c2, R, R2);

        cout << "R2[0]" << R2[0] << endl;
        cout << "R2[1]" << R2[1] << endl;

    }
};


#endif //ECDH_ECCENCRYPT_H
