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
#include "hash.h"

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

    HashString *hash_string = new HashString("sha256");

public:
    ECC();

    ~ECC() {
        delete hash_string;
        cout << "======ecc exit======" << endl;
    };

    vector<mpz_class> get_public_key();

    mpz_class get_private_key();

    vector<mpz_class> get_param_g();

    void generate_point(mpz_class sk = 0);

    void ecc_mul(vector<mpz_class> &P, mpz_class k, vector<mpz_class> &R);

    void ecc_add(vector<mpz_class> &P, vector<mpz_class> &Q, vector<mpz_class> &R);

    void ecc_sub(vector<mpz_class> &P, vector<mpz_class> &Q, vector<mpz_class> &R);

    static mpz_class positive_mod(mpz_class numer, mpz_class p);

    // 1 扩展欧几里得算法
    static mpz_class mod_inv(mpz_class u, mpz_class v);

    static void mod_inv(mpz_class u, mpz_class v, mpz_class &n);

    // 2 费马定理小定理/欧拉定理
    mpz_class mod_inv2(mpz_class u, mpz_class v);

    static void mod_inv2(mpz_class &u, mpz_class &v, mpz_class &n);

    // 3 递推法
    static mpz_class mod_inv3(mpz_class u, mpz_class v);

    vector<mpz_class> ecc_neg(vector<mpz_class> &P);

    bool is_on_curve(vector<mpz_class> &P);

    bool x_is_on_curve(mpz_class &x);

    mpz_class find_y_give_x(mpz_class &x);

    mpz_class power_method(mpz_class a, mpz_class b, mpz_class c);

    static void get_random_mpz(mpz_t mpz_r);

    vector<mpz_class> hash_to_curve(const string &msg);

};


#endif //ECDH_ECC_H
