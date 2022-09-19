//
// Created by tian on 2022/9/14.
//

#ifndef ECDH_ECC_H
#define ECDH_ECC_H

#include "iostream"
#include "gmp.h"
#include <gmpxx.h>
#include <ctime>
#include "string"
#include <cmath>
#include "vector"

using namespace std;


class ECC {
private:
    string name = "secp256k1";
    mpz_class param_a = 0;
    mpz_class param_b = 7;
    mpz_class param_p;
    // base point
    vector<mpz_class> param_G = vector<mpz_class>(2);
    // Subgroup order
    mpz_class param_n;
    //Subgroup cofactor.
    mpz_class param_h = 1;

    vector<mpz_class> public_key = vector<mpz_class>(2); // point(x,y)
    mpz_class private_key; // 大整数

public:
    ECC();

    ~ECC() {
        cout << "======ecc exit======" << endl;
    };

    vector<mpz_class> get_public_key();

    mpz_class get_private_key();

    vector<mpz_class> get_param_g();

    void generate_point(mpz_class sk = 0);

    void ecc_mul(vector<mpz_class> &P, mpz_class k, vector<mpz_class> &R);

    void ecc_add(vector<mpz_class> &P, vector<mpz_class> &Q, vector<mpz_class> &R);

    void ecc_sub(vector<mpz_class> &P, vector<mpz_class> &Q, vector<mpz_class> &R) {
        vector<mpz_class> neg_Q = ecc_neg(Q);
        ecc_add(P, neg_Q, R);
    }

    static mpz_class positive_mod(mpz_class numer, mpz_class p);

    static mpz_class mod_inv(mpz_class u, mpz_class v);

    static void mod_inv(mpz_class u, mpz_class v,mpz_class & n);

    static mpz_class mod_inv2(mpz_class u, mpz_class v);

    static mpz_class mod_inv3(mpz_class u, mpz_class v);

    vector<mpz_class> ecc_neg(vector<mpz_class> &P);

    bool is_on_curve(vector<mpz_class> &P);

    static void test_gmp();

    static void get_random_mpz(mpz_t mpz_r);

};


#endif //ECDH_ECC_H
