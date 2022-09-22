//
// Created by tian on 2022/9/19.
//

#include "ecc_encrypt.h"

vector<string> EccEncrypt::encrypt(const string &msg) {

    vector<mpz_class> msg_point = ecc->hash_to_curve(msg);

    mpz_class mpz_r = 3;

    vector<mpz_class> c1(2);
    vector<mpz_class> c2(2);
    vector<string> RR(4);

    vector<mpz_class> param_g = ecc->get_param_g();
    ecc->ecc_mul(param_g, mpz_r, c1);
//
    ecc->ecc_mul(this->public_key, mpz_r, c2);
    ecc->ecc_add(msg_point, c2, c2);

    RR[0] = c1[0].get_str();
    RR[1] = c1[1].get_str();
    RR[2] = c2[0].get_str();
    RR[3] = c2[1].get_str();

    return RR;
}

void EccEncrypt::generate_key() {
    this->ecc->generate_point();
    public_key = ecc->get_public_key();
    private_key = ecc->get_private_key();
}

string EccEncrypt::decrypt(const vector<string> &enc_v) {
    vector<mpz_class> c1(2);
    vector<mpz_class> c2(2);
    c1[0] = enc_v[0];
    c1[1] = enc_v[1];
    c2[0] = enc_v[2];
    c2[1] = enc_v[3];
    vector<mpz_class> R(2);
    vector<mpz_class> R2(2);
    string dec_res;
    ecc->ecc_mul(c1, this->private_key, R);
    ecc->ecc_sub(c2, R, R2);

    cout << "R2[0]" << R2[0] << endl;
    cout << "R2[1]" << R2[1] << endl;

    dec_res = R2[0].get_str();
    dec_res += R2[1].get_str();
    dec_res = ecc->hash_string->run(dec_res);

    return dec_res;

}
