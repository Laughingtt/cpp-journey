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

using namespace std;


class ECC {
private:
    string name = "secp256k1";
    mpz_class param_a = 0;
    mpz_class param_b = 7;
    mpz_class param_p;
    // base point
    mpz_class param_G[2];
    // Subgroup order
    mpz_class param_n;
    //Subgroup cofactor.
    mpz_class param_h = 1;

    mpz_class public_key[2]; // point(x,y)
    mpz_class private_key; // 大整数




public:
    ECC() {
        // set mpz value
        param_p = "115792089237316195423570985008687907853269984665640564039457584007908834671663";
        param_G[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        param_G[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        param_n = "115792089237316195423570985008687907852837564279074904382605163141518161494337";

        cout << "======ecc" << this->name << "init param is :======" << endl;
        cout << "param_a : " << param_a << endl;
        cout << "param_b : " << param_b << endl;
        cout << "param_p : " << param_p << endl;
        cout << "param_G[0] : " << param_G[0] << endl;
        cout << "param_G[1] : " << param_G[1] << endl;
        cout << "param_n : " << param_n << endl;
        cout << "param_h : " << param_h << endl;
        cout << "==================================================" << endl;

    };

    ~ECC() {
        cout << "======ecc exit======" << endl;
    };

    void generate_point(mpz_class sk = 0) {
        while (sk == 0) {
            ECC::get_random_mpz(sk.get_mpz_t());
            cout << "sk is :" << sk << endl;
        }

        this->private_key = sk;
        this->public_key[0] = 0;
        this->public_key[1] = 1;

        bool is_on_cur = is_on_curve(this->param_G);

        cout << "is on curve " << to_string(is_on_cur) << endl;


    }

    void ecc_mul(mpz_class P[], const mpz_class &k) {
        // Q = k * P
        if (k % this->param_n == 0) {
            return;
        }

        if (k < 0) {
            // k * point = -k * (-point)
            ecc_neg(P);
            ecc_mul(P, -k);
        }

    }

    void ecc_add(mpz_class P[], mpz_class Q[]) {
        is_on_curve(P);
        is_on_curve(Q);

        mpz_class x1 = P[0];
        mpz_class x2 = P[1];
        mpz_class y1 = Q[0];
        mpz_class y2 = Q[1];

        if (x1 == x2){
            mpz_class m = (3 * x1 * x1 + this->param_a) * self.mod_inv(2 * y1, self.p)
        }
    }

    void ecc_neg(mpz_class P[]) {
        // y - > -y
        P[1] = -P[1] % this->param_p;
    }


    bool is_on_curve(mpz_class P[]) {

        mpz_class x = P[0];
        mpz_class y = P[1];
        mpz_class curve_res = (y * y - x * x * x - this->param_a * x - this->param_b) % this->param_p;
        cout << "curve_res  " << curve_res << endl;
        if (curve_res == 0) {
            return true;
        }
        return false;
    }

    static void test_gmp();

    static void get_random_mpz(mpz_t mpz_r);

    static void print_hello() {
        cout << "hello static fun" << endl;
    }


};


#endif //ECDH_ECC_H
