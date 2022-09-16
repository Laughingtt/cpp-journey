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

        bool is_on_cur = is_on_curve(this->param_G);

        cout << "is on curve " << to_string(is_on_cur) << endl;

        ecc_mul(this->param_G, sk, this->public_key);

        cout << "this->public_key" << this->public_key[0] << " " << this->public_key[1] << endl;
        cout << "this->private_key" << this->private_key << endl;

    }

    void ecc_mul(mpz_class P[], mpz_class k, mpz_class R[]) {
        // R = k * P
        if (k % this->param_n == 0) {
            return;
        }

        if (k < 0) {
            // k * point = -k * (-point)
            mpz_class neg_P[2];
            ecc_neg(P, neg_P);
            ecc_mul(neg_P, -k, R);
            return;
        }
        mpz_class Q[2] = {0, 0};
        mpz_class Q_tmp[2];
        Q_tmp[0] = P[0];
        Q_tmp[1] = P[1];
        while (k > 0) {
            if (k % 2 == 1) {
                ecc_add(Q, Q_tmp, Q);
            }
            ecc_add(Q_tmp, Q_tmp, Q_tmp);
//            cout << "k  " << k << "  Q_tmp " << Q_tmp[0] << "  " << Q_tmp[1] << endl;
            k = k / 2;
        }
        R[0] = Q[0];
        R[1] = Q[1];

    }

    void ecc_add(mpz_class P[], mpz_class Q[], mpz_class R[]) {
        if (P[0] == 0 && P[1] == 0) {
            R[0] = Q[0];
            R[1] = Q[1];
            return;
        }
        if (Q[0] == 0 && Q[1] == 0) {
            R[0] = P[0];
            R[1] = P[1];
            return;
        }
        is_on_curve(P);
        is_on_curve(Q);

        mpz_class x1 = P[0];
        mpz_class y1 = P[1];
        mpz_class x2 = Q[0];
        mpz_class y2 = Q[1];
        mpz_class m;

        if (x1 == x2) {
            m = (3 * x1 * x1 + this->param_a) * mod_inv(2 * y1, this->param_p);
        } else {
            m = (y2 - y1) * mod_inv(x2 - x1, this->param_p);
        }
        mpz_class x3 = m * m - x1 - x2;
        mpz_class y3 = m * (x1 - x3) - y1;
        R[0] = x3 % this->param_p;
        R[1] = y3 % this->param_p;

        if (R[0] < 0) {
            R[0] = R[0] + this->param_p;
        }
        if (R[1] < 0) {
            R[1] = R[1] + this->param_p;
        }
    }

    static mpz_class mod(mpz_class numer, mpz_class p) {
        // 使得取模后的数为正
        mpz_class r_numer = numer % p;
        if (r_numer < 0) {
            r_numer = r_numer + p;
        }
        return r_numer;
    }

    static mpz_class mod_inv(mpz_class u, mpz_class v) {
        mpz_class x = 1;
        mpz_class y = 0;
        mpz_class temp;
        mpz_class k;
        while (v != 0) {
            k = u / v;
            temp = u % v;
            u = v;
            v = temp;

            temp = x - k * y;
            x = y;
            y = temp;
        }
        return x;
    }

    void test_ecc_mul() {
        cout << "=== test_ecc_mul func ===" << endl;
        mpz_class P[2];
        P[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        P[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        mpz_class R[2];
        mpz_class k = 27;
        ecc_mul(P, k, R);
        cout << "R[0] :" << R[0] << endl;
        cout << "R[1] :" << R[1] << endl;

    }

    void test_ecc_add() {
        cout << "=== test_ecc_add func ===" << endl;
        mpz_class P[2];
        P[0] = "55066263022277343669578718895168534326250603453777594175500187360389116729240";
        P[1] = "32670510020758816978083085130507043184471273380659243275938904335757337482424";
        mpz_class Q[2];
        Q[0] = "89565891926547004231252920425935692360644145829622209833684329913297188986597";
        Q[1] = "12158399299693830322967808612713398636155367887041628176798871954788371653930";
        mpz_class R[2];
        ecc_add(P, Q, R);
        cout << "R[0] :" << R[0] << endl;
        cout << "R[1] :" << R[1] << endl;

    }

    void test_mod_inv() {
        mpz_class a, b, rr;
        a = "65341020041517633956166170261014086368942546761318486551877808671514674964848";
        b = "115792089237316195423570985008687907853269984665640564039457584007908834671663";
        rr = "-32617584047406127887053860912668548655625778953140441154984154756096705713545";
        mpz_class r = mod_inv(a, b);
        cout << "a :" << a << endl;
        cout << "b :" << b << endl;
        cout << "r :" << r << endl;
        if (r == rr) {
            cout << "mod_inv true" << endl;
        } else {
            cout << "mod_inv false" << endl;
        }
    }

    void ecc_neg(mpz_class P[], mpz_class neg_P[]) {
        // y - > -y
        neg_P[0] = -P[0];
        neg_P[1] = -P[1] % this->param_p;
    }


    bool is_on_curve(mpz_class P[]) {

        mpz_class x = P[0];
        mpz_class y = P[1];
        mpz_class curve_res = (y * y - x * x * x - this->param_b) % this->param_p;
        cout << "curve_res  " << curve_res << endl;
        if (curve_res == 0) {
            return true;
        }
//        cout << "curve_res P[0]" << P[0] << endl;
//        cout << "curve_res P[1]" << P[1] << endl;
        return false;
    }

    static void test_gmp();

    static void get_random_mpz(mpz_t mpz_r);

    static void print_hello() {
        cout << "hello static fun" << endl;
    }

};


#endif //ECDH_ECC_H
