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
    string curve_name = "secp128r1";
    string name;
    int hex_len;
    mpz_class param_a;
    mpz_class param_b;
    mpz_class param_p;
    // base point
    vector<mpz_class> param_G = vector<mpz_class>(2);
    // Subgroup order
    mpz_class param_n;
    //Subgroup cofactor.
    mpz_class param_h = 1;

    void view_param();

public:

    int bit_len;
    gmp_randstate_t random_state;

    vector<mpz_class> public_key = vector<mpz_class>(2); // point(x,y)
    mpz_class private_key; // 大整数

    HashString *hash_string = new HashString("sha256");

    ECC(const string &_curve_name);

    ECC();

    ~ECC() {
        delete hash_string;
        cout << "======ecc exit======" << endl;
    };

    void set_curve_value();

    vector<mpz_class> get_public_key();

    mpz_class get_private_key();

    vector<mpz_class> get_param_g();

    void generate_point(mpz_class sk = 0);

    void ecc_mul(const vector<mpz_class> &P, const mpz_class &k, vector<mpz_class> &R);

    void ecc_add(const vector<mpz_class> &P, const vector<mpz_class> &Q, vector<mpz_class> &R);

    void ecc_sub(const vector<mpz_class> &P, const vector<mpz_class> &Q, vector<mpz_class> &R);

    vector<mpz_class> ecc_neg(const vector<mpz_class> &P);

    bool is_on_curve(const vector<mpz_class> &P);

    bool x_is_on_curve(const mpz_class &x);

    mpz_class find_y_give_x(const mpz_class &x);

    void find_x_y_point(mpz_class &x, mpz_class &y);

    static void get_random_mpz(mpz_t mpz_r, int &bit_length);

    void get_random_mpz2(mpz_t mpz_r, int &bit_length);

    vector<mpz_class> hash_to_curve(const string &msg);

    static mpz_class positive_mod(mpz_class &numer, mpz_class &p);

    mpz_class power_method(mpz_class a, mpz_class b, mpz_class c);

    // 1 扩展欧几里得算法
    static mpz_class mod_inv(mpz_class u, mpz_class v);

    static void mod_inv(mpz_class u, mpz_class v, mpz_class &n);

    // 2 费马定理小定理/欧拉定理
    mpz_class mod_inv2(mpz_class u, mpz_class v);

    static void mod_inv2(const mpz_class &u, const mpz_class &v, mpz_class &n);

    // 3 递推法
    static mpz_class mod_inv3(mpz_class u, mpz_class v);

    static void mpz_to_string(vector<mpz_class> &vec1, vector<string> &vec2);

    static void string_to_mpz(vector<string> &vec1, vector<mpz_class> &vec2);

};


#endif //ECDH_ECC_H
